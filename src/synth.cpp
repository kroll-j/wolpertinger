#include "synth.h"
#include "tabbed-editor.h"
#include "about.h"


/*
Versions
0.4	ADSR Envelope

0.3 Virtual Keyboard Component, GUI niceties
	Changed back to Juce
0.2 MIDI parameter changes now update the GUI
    Binaries no longer linked to OpenGL
    Debug and Release binaries included
0.1 initial release
*/



AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new wolp();
}

AudioProcessor* JUCE_CALLTYPE createPluginFilter(const String& commandLine)
{
    return new wolp();
}


// ------------------------- SynthVoice -------------------------

void wolpVoice::startNote(const int midiNoteNumber,
							 const float velocity,
							 SynthesiserSound* sound,
							 const int currentPitchWheelPosition)
{
	phase= low= band= high= 0;
	freq= synth->getnotefreq(midiNoteNumber);
	vol= velocity;
//	curvol= 0.0f;
	cyclecount= 0;
	playing= true;
	env.setAttack(synth->getparam(wolp::attack));
	env.setDecay(synth->getparam(wolp::decay));
	env.setSustain(synth->getparam(wolp::sustain));
	env.setRelease(synth->getparam(wolp::release));
	env.resetTime();
}

void wolpVoice::stopNote(const bool allowTailOff)
{
	printf("stopNote %d\n", allowTailOff);
	//if(!allowTailOff) clearCurrentNote();
	playing= false;
}



void wolpVoice::process(float* p1, float* p2, int samples)
{
	float param_cutoff= synth->getparam(wolp::cutoff);
	float cutoff= param_cutoff * freq;
//	float step= freq / getSampleRate();
	float vol= this->vol * synth->getparam(wolp::gain);
	int nfilters= int(synth->getparam(wolp::nfilters));

//	float msaw= synth->getparam(wolp::gsaw),
//		  mrect= synth->getparam(wolp::grect),
//		  mtri= synth->getparam(wolp::gtri);
//	float div= msaw+mrect+mtri;
//	if(div==0.0f) msaw= div= 1.0;
//	div= 1.0/div;
//	msaw*= div;
//	mrect*= div;
//	mtri*= div;

	generator.setFrequency(getSampleRate(), freq);
	generator.setMultipliers(synth->getparam(wolp::gsaw), synth->getparam(wolp::grect), synth->getparam(wolp::gtri));

//	double volstep= playing? (vol>curvol? 100: -100)*vol/getSampleRate(): -50.0/getSampleRate();
//	double volstep= (vol>curvol? 100: -100)*vol/getSampleRate();
	double sampleStep= 1.0/getSampleRate();

	for(int i= 0; i<samples; i++)
	{
//		double vsaw= phase,
//			   vrect= (phase<0.5? -1: 1),
//			   vtri= (cyclecount&1? 2-(phase+1)-1: phase);
//
//		double val= vsaw*msaw + vrect*mrect + vtri*mtri;
//
//		phase+= step;
//		if (phase > 1)
//			cyclecount++,
//			phase -= 2;

		double val= generator.getNextSample();

		double envVol= env.getValue();

		val= filter.run(val, nfilters);

//		curvol+= volstep;
//		if(curvol<=0.0f) { clearCurrentNote(); curvol= 0; break; }
//		if( (curvol>vol && volstep>0) || (curvol<vol && volstep<0) ) curvol= vol;

//		curvol+= (vol-curvol)*1000.0/getSampleRate();
//		if(curvol<0.001f && !playing) { clearCurrentNote(); curvol= 0; break; }

		p1[i]+= val*vol*envVol;
		p2[i]+= val*vol*envVol;

		if( !((++synth->samples_synthesized) & 31) )
		{
			synth->cutoff_filter.setparams(synth->getparam(wolp::velocity) * 10000,
										   synth->getparam(wolp::inertia) * 100);

			float cut= synth->cutoff_filter.run(cutoff, this->vol*envVol * 32.0f/getSampleRate());

			float fmax= synth->getparam(wolp::filtermax);
			float fmin= synth->getparam(wolp::filtermin);
			if(cut > fmax) cut= fmax;
			if(cut < fmin) cut= fmin;

			filter.setparams(getSampleRate(), cut,
							 synth->params[wolp::bandwidth]*cut, synth->params[wolp::resonance] * 2);

			synth->setParameterNotifyingHost(wolp::curcutoff, sqrt(cut/20000));
//			synth->setParameterNotifyingHost(wolp::filterspeed,
//						synth->cutoff_filter.getspeed()/(getSampleRate()*freq*300/**param_cutoff*100*/));
		}

		env.advance(sampleStep, playing);
		if(env.isFinished()) { clearCurrentNote(); break; }
	}
}

void wolpVoice::renderNextBlock (AudioSampleBuffer& outputBuffer, int startSample, int numSamples)
{
	if(getCurrentlyPlayingNote()>=0)
	{
		float **outbuf= outputBuffer.getArrayOfChannels();
		process(outbuf[0]+startSample, outbuf[1]+startSample, numSamples);
	}
}




// ------------------------- Synth -------------------------


void wolp::getStateInformation (JUCE_NAMESPACE::MemoryBlock& destData)
{
	printf("getStateInformation()\n");
	XmlElement *doc= new XmlElement(String("synth"));
	for(int i= 0; i<param_size; i++)
	{
		XmlElement *p= new XmlElement("param");
		p->setAttribute(T("name"), String(paraminfos[i].internalname));
		p->setAttribute(T("val"), params[i]);
		doc->addChildElement(p);
	}
	copyXmlToBinary(*doc, destData);
	delete doc;
}

void wolp::setStateInformation (const void* data, int sizeInBytes)
{
	XmlElement *xml= getXmlFromBinary(data, sizeInBytes);
	String errorstring;

	if(xml && xml->getTagName() == String("synth"))
	{
		loaddefaultparams();
		forEachXmlChildElementWithTagName(*xml, param, T("param"))
		{
			const char *name= param->getStringAttribute(T("name")).toUTF8();
			const double val= param->getDoubleAttribute(T("val"));
			int i;
			for(i= 0; i<param_size; i++)
			{
				if( !strcmp(name, paraminfos[i].internalname) )
				{
					params[i]= val;
					break;
				}
			}
			if(i==param_size) errorstring+= String("Unknown parameter '") + name + "'\n";
		}
	}
	else errorstring= T("XML data corrupt\n");

	if(errorstring.length())
		AlertWindow::showMessageBox(AlertWindow::WarningIcon, String("Wolpertinger"), errorstring);

	if(xml) delete xml;
}



float wolp::getparam(int idx)
{
	float v;
	switch(idx)
	{
		case gain:
			v= sqr(sqr(params[idx]));
			break;
		case clip:
			v= sqr(params[idx]);
			break;
		case gsaw:
		case grect:
		case gtri:
			v= sqr(params[idx]);
			break;
		case cutoff:
			v= sqr(params[idx]);
			break;
		case velocity:
		case inertia:
			v= sqr(params[idx]);
			break;
		case nfilters:
			return float(int(params[idx]*paraminfos[idx].max));
		case tune:
		{
			float p= params[idx]-0.5;
			return 440.0f + (p<0? -sqr(p)*220: sqr(p)*440);
		}
		case curcutoff:
		case filtermin:
		case filtermax:
			v= sqr(params[idx]);
			break;
		case attack:
		case decay:
		case sustain:
		case release:
			v= sqr(params[idx]);
			break;
		default:
			v= params[idx];
			break;
	}

	const wolp::paraminfo &i= paraminfos[idx];
	return v * (i.max-i.min); // + i.min;
}

void wolp::setParameter (int idx, float value)
{
	params[idx]= value;
	switch(idx)
	{
		case curcutoff:
		{
			float cut= params[idx];
			if(cut<params[filtermin]) cut= params[filtermin];
			if(cut>params[filtermax]) cut= params[filtermax];
			cutoff_filter.setvalue(getparam(idx));
			break;
		}
		case tune:
		{
			for(int i= voices.size(); --i>=0; )
			{
				wolpVoice *voice= (wolpVoice*)voices.getUnchecked(i);
				int note= voice->getCurrentlyPlayingNote();
				if(note>=0) voice->setfreq(getnotefreq(note));
			}
			break;
		}
		case filterspeed:
		{
//			double f= cutoff_filter.getspeed()/cutoff_filter.getvalue();
//			double filterspd= sqrt(fabs(f)) * (f<0? -0.000002: 0.000002);

			if(!cutoff_filter.getvalue()) break;

			double newspeed= sqr(value)*(1.0/0.000002) * cutoff_filter.getvalue() * (value<0? -1: 1);

			printf(" %.2f -> %.2f\n", cutoff_filter.getspeed(), newspeed);

			cutoff_filter.setspeed(newspeed);

			break;
		}
	}

/*
	tabbed_editor *e= (tabbed_editor*)getActiveEditor();
	if(e)
	{
		//if(idx!=12) printf("non-gui param change, setParameter %d %.2f\n", idx, value);
		// no way to check if this change was caused by the GUI, so it's updated needlessly when it was.
		sendChangeMessage((void*)idx);
	}
*/
	paraminfos[idx].dirty= true;
}



wolp::paraminfo wolp::paraminfos[]=
{
	{ "gain", 				"Gain",		 	0.0,	4.0,	0.3 },
	{ "clip", 				"Clip",		 	0.0,	5.0,	1.0 },
	{ "saw", 				"Saw",		 	0.0,	1.0,	1.0 },
	{ "rect", 				"Rect",		 	0.0,	1.0,	0.0 },
	{ "tri", 				"Tri",		 	0.0,	1.0,	0.0 },
	{ "tune", 				"Tune",		 	0.0, 	1.0,	0.5 },
	{ "filter_cutoff", 		"Filter X",	 	0.0, 	32.0,	0.5 },
	{ "filter_reso", 		"Resonance",	0.0,	1.0,	0.4 },
	{ "filter_bandwidth", 	"Bandwidth",	0.0,	1.0,	0.4 },
	{ "filter_velocity", 	"Velocity",	 	0.0,	1.0,	0.25 },
	{ "filter_inertia", 	"Inertia",	 	0.0,	1.0,	0.25 },
	{ "filter_passes", 		"Passes",	 	0.0,	8.0,	0.5 },
	{ "filter_curcutoff", 	"Filter Freq",	0.0,	20000,	0.25 },
	{ "env_attack", 		"Attack",		0.0,	3.0,	0.25 },
	{ "env_decay", 			"Decay",		0.0,	3.0,	0.25 },
	{ "env_sustain", 		"Sustain",		0.0,	1.0,	0.5 },
	{ "env_release", 		"Release",		0.0,	4.0,	0.5 },
	{ "filter_minfreq", 	"Filter Min",	0.0,	20000,	0.1 },
	{ "filter_maxfreq", 	"Filter Max",	0.0,	20000,	1.0 },
	{ "filter_speed", 		"Filter Speed",	-4.0,	4.0,	0.0 },
};

void wolp::loaddefaultparams()
{
	for(int i= 0; i<param_size; i++) params[i]= paraminfos[i].defval;
}


wolp::wolp()
{
	jassert(sizeof(paraminfos)/sizeof(paraminfos[0])==param_size);
	loaddefaultparams();

	samples_synthesized= 0;

	for(int i= 0; i<16 ; i++)
		addVoice(new wolpVoice(this));

	addSound(new wolpSound());

	setNoteStealingEnabled(true);
}

wolp::~wolp()
{
}


void wolp::processBlock(AudioSampleBuffer& buffer, MidiBuffer& midiMessages)
{
	float **outbuf= buffer.getArrayOfChannels();
	int size= buffer.getNumSamples();

	memset(outbuf[0], 0, size*sizeof(float));
	memset(outbuf[1], 0, size*sizeof(float));

	renderNextBlock(buffer, midiMessages, 0, size);

	float clp= getparam(clip);
	float *out0= outbuf[0], *out1= outbuf[1];
	for(int i= 0; i<size; i++)
	{
//		float val= filter.run(out0[i], int(params[nfilters]));
//		out0[i]= out1[i]= val;
		if(out0[i]<-clp) out0[i]= -clp; else if(out0[i]>clp) out0[i]= clp;
		if(out1[i]<-clp) out1[i]= -clp; else if(out1[i]>clp) out1[i]= clp;
	}

	double f= cutoff_filter.getspeed()/cutoff_filter.getvalue();
	double filterspd= sqrt(fabs(f)) * (f<0? -0.000002: 0.000002);
	if(filterspd!=params[filterspeed])
		params[filterspeed]= filterspd,
		paraminfos[filterspeed].dirty= true;

	if(getActiveEditor())
	{
		for(int i= 0; i<param_size; i++)
		{
			if(paraminfos[i].dirty)
			{
				sendChangeMessage((void*)i);
				paraminfos[i].dirty= false;
			}
		}
	}

//    editor *e= (editor*)getActiveEditor();
//    if(e) e->updateparams();
}


void wolp::renderNextBlock (AudioSampleBuffer& outputBuffer,
                                   const MidiBuffer& midiData,
                                   int startSample,
                                   int numSamples)
{
    const ScopedLock sl (lock);

    MidiBuffer::Iterator midiIterator (midiData);
    midiIterator.setNextSamplePosition (startSample);
    MidiMessage m (0xf4, 0.0);

    while (numSamples > 0)
    {
        int midiEventPos;
        const bool useEvent = midiIterator.getNextEvent (m, midiEventPos)
                                && midiEventPos < startSample + numSamples;

        const int numThisTime = useEvent ? midiEventPos - startSample
                                         : numSamples;

        if (numThisTime > 0)
        {
            for (int i = voices.size(); --i >= 0;)
                voices.getUnchecked (i)->renderNextBlock (outputBuffer, startSample, numThisTime);
        }

        if (useEvent)
        {
            if (m.isNoteOn())
            {
                const int channel = m.getChannel();

                noteOn (channel,
                        m.getNoteNumber(),
                        m.getFloatVelocity());
            }
            else if (m.isNoteOff())
            {
                noteOff (m.getChannel(),
                         m.getNoteNumber(),
                         true);
            }
            else if (m.isAllNotesOff() || m.isAllSoundOff())
            {
                allNotesOff (m.getChannel(), true);
            }
            else if (m.isPitchWheel())
            {
                const int channel = m.getChannel();
                const int wheelPos = m.getPitchWheelValue();
                lastPitchWheelValues [channel - 1] = wheelPos;

                handlePitchWheel (channel, wheelPos);
            }
            else if (m.isController())
            {
                handleController (m.getChannel(),
                                  m.getControllerNumber(),
                                  m.getControllerValue());
                printf("controller: %s\n", MidiMessage::getControllerName(m.getControllerNumber()).toUTF8());
            }
            else if(m.isAftertouch())
            {
				int chan= m.getChannel();
				int note= m.getNoteNumber();
				for(int i= voices.size(); --i>=0; )
				{
					wolpVoice *v= (wolpVoice *)voices.getUnchecked(i);
					if(v->isPlayingChannel(chan) && v->getCurrentlyPlayingNote()==note)
					{
						v->setvolume(m.getAfterTouchValue()*(1.0/0x7F));
					}
				}
            }

            else
                puts("unknown message");
        }

        startSample += numThisTime;
        numSamples -= numThisTime;
    }
}


AudioProcessorEditor* wolp::createEditor()
{
    printf("wolp::createEditor() thread=%08X\n", Thread::getCurrentThreadId());
	tabbed_editor *e= new tabbed_editor(this);
    printf("wolp::createEditor() done\n");

	return e;
}

