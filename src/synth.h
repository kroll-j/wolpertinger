#ifndef SYNTH_H
#define SYNTH_H

#include "juce.h"
#include "filters.h"
#include "ADSRenv.h"


template<typename T> T sqr(T v) { return v*v; }



class wolpSound: public SynthesiserSound
{
	public:
		bool appliesToNote(const int midiNoteNumber) { return true; }
		bool appliesToChannel(const int midiChannel) { return true; }
};

class WaveGenerator
{
	public:
		enum { oversampling = 16 };

		WaveGenerator():
			phase(0.0), cyclecount(0)
		{
			memset(xv, 0, sizeof(xv));
			memset(yv, 0, sizeof(xv));
		}

		~WaveGenerator()
		{ }

		double getNextSample()
		{
			double s= 0;
			for(int i= 0; i<oversampling; i++)
			{
				if(oversampling>1)
//					s= filter.run(getNextRawSample());
//					s= butterworth_lp(getNextRawSample());
					s= chebyshev_lp.run(getNextRawSample());
				else
					s= getNextRawSample();
			}
			return s;
		}

		void setFrequency(double sampleRate, double noteFrequency)
		{
			sampleStep= noteFrequency / (sampleRate*oversampling);
			filter[0].calc_filter_coeffs(0, sampleRate*0.3, sampleRate*oversampling, 0.6, 0, false);
			filter.updateparams();
		}

		void setMultipliers(double mSaw, double mRect, double mTri)
		{
			float div= mSaw+mRect+mTri;
			if(div==0.0f) mSaw= div= 1.0;
			div= 1.0/div;
			sawFactor= mSaw*div;
			rectFactor= mRect*div;
			triFactor= mTri*div;
		}

	private:
		double sawFactor, rectFactor, triFactor, sampleStep, phase;
		int cyclecount;

		multifilter<CFxRbjFilter, 4> filter;

		double getNextRawSample()
		{
			double saw= phase,
				   rect= (phase<0.5? -1: 1),
				   tri= (cyclecount&1? 2-(phase+1)-1: phase);

			double val= saw*sawFactor+ rect*rectFactor + tri*triFactor;

			phase+= sampleStep;
			if (phase > 1)
				cyclecount++,
				phase -= 2;

			return val;
		}

		#define NZEROS 8
		#define NPOLES 8
		#define GAIN   1.664669804e+09

		double xv[NZEROS+1], yv[NPOLES+1];

		double butterworth_lp(double nextval)
			  { xv[0] = xv[1]; xv[1] = xv[2]; xv[2] = xv[3]; xv[3] = xv[4]; xv[4] = xv[5]; xv[5] = xv[6]; xv[6] = xv[7]; xv[7] = xv[8];
				xv[8] = nextval / GAIN;
				yv[0] = yv[1]; yv[1] = yv[2]; yv[2] = yv[3]; yv[3] = yv[4]; yv[4] = yv[5]; yv[5] = yv[6]; yv[6] = yv[7]; yv[7] = yv[8];
				yv[8] =   (xv[0] + xv[8]) + 8 * (xv[1] + xv[7]) + 28 * (xv[2] + xv[6])
							 + 56 * (xv[3] + xv[5]) + 70 * xv[4]
							 + ( -0.4696688419 * yv[0]) + (  4.1118419128 * yv[1])
							 + (-15.7672926090 * yv[2]) + ( 34.5903197920 * yv[3])
							 + (-47.4859069880 * yv[4]) + ( 41.7740652050 * yv[5])
							 + (-22.9985902730 * yv[6]) + (  7.2452316476 * yv[7]);
				return yv[8];
			  }
		#undef NZEROS
		#undef NPOLES
		#undef GAIN

		class chebyshev_7pole
		{
			/* Digital filter designed by mkfilter/mkshape/gencode   A.J. Fisher
			   Command line: /www/usr/fisher/helpers/mkfilter -Ch -5.0000000000e-02 -Lp -o 7 -a 2.2786458333e-02 0.0000000000e+00 -l */

			#define NZEROS 7
			#define NPOLES 7
			#define GAIN   8.185223519e+08

			public:

			chebyshev_7pole() { memset(xv, 0, sizeof(xv)); memset(yv, 0, sizeof(yv)); }

			double xv[NZEROS+1], yv[NPOLES+1];

			double run(double nextvalue)
			{
				xv[0] = xv[1]; xv[1] = xv[2]; xv[2] = xv[3]; xv[3] = xv[4]; xv[4] = xv[5]; xv[5] = xv[6]; xv[6] = xv[7];
				xv[7] = nextvalue / GAIN;
				yv[0] = yv[1]; yv[1] = yv[2]; yv[2] = yv[3]; yv[3] = yv[4]; yv[4] = yv[5]; yv[5] = yv[6]; yv[6] = yv[7];
				yv[7] =   (xv[0] + xv[7]) + 7 * (xv[1] + xv[6]) + 21 * (xv[2] + xv[5])
							 + 35 * (xv[3] + xv[4])
							 + (  0.7582559865 * yv[0]) + ( -5.4896632588 * yv[1])
							 + ( 17.0657116090 * yv[2]) + (-29.5302444680 * yv[3])
							 + ( 30.7191651920 * yv[4]) + (-19.2116577140 * yv[5])
							 + (  6.6884324971 * yv[6]);
				return yv[7];
			}

//			void filterloop()
//			  { for (;;)
//				  { xv[0] = xv[1]; xv[1] = xv[2]; xv[2] = xv[3]; xv[3] = xv[4]; xv[4] = xv[5]; xv[5] = xv[6]; xv[6] = xv[7];
//					xv[7] = `next input value' / GAIN;
//					yv[0] = yv[1]; yv[1] = yv[2]; yv[2] = yv[3]; yv[3] = yv[4]; yv[4] = yv[5]; yv[5] = yv[6]; yv[6] = yv[7];
//					yv[7] =   (xv[0] + xv[7]) + 7 * (xv[1] + xv[6]) + 21 * (xv[2] + xv[5])
//								 + 35 * (xv[3] + xv[4])
//								 + (  0.7582559865 * yv[0]) + ( -5.4896632588 * yv[1])
//								 + ( 17.0657116090 * yv[2]) + (-29.5302444680 * yv[3])
//								 + ( 30.7191651920 * yv[4]) + (-19.2116577140 * yv[5])
//								 + (  6.6884324971 * yv[6]);
//					`next output value' = yv[7];
//				  }
//			  }
		};

		chebyshev_7pole chebyshev_lp;
};

class wolpVoice: public SynthesiserVoice
{
	public:
		wolpVoice(class wolp *s): synth(s)
		{
		}

		//==============================================================================
		bool canPlaySound (SynthesiserSound* sound) { return true; }

		void startNote (const int midiNoteNumber,
						const float velocity,
						SynthesiserSound* sound,
						const int currentPitchWheelPosition);

		void stopNote (const bool allowTailOff);

		void pitchWheelMoved (const int newValue) { }

		void controllerMoved (const int controllerNumber,
							  const int newValue) { }

		//==============================================================================
		void renderNextBlock (AudioSampleBuffer& outputBuffer, int startSample, int numSamples);

		void setvolume(double v) { vol= v; }
		void setfreq(double f) { freq= f; }

	protected:
		void process(float* p1, float* p2, int samples);

		double phase, low, band, high, vol, freq;
//		double curvol;
		bool playing;
		int cyclecount;

		WaveGenerator generator;
		bandpass<8> filter;
		ADSRenv env;

		class wolp *synth;
};



class wolp:	public AudioProcessor,
            public Synthesiser,
            public ChangeBroadcaster,
            public MidiKeyboardStateListener
{
	public:
		enum params
		{
			gain= 0,
			clip,
			gsaw,
			grect,
			gtri,
			tune,
			cutoff,
			resonance,
			bandwidth,
			velocity,
			inertia,
			nfilters,
			curcutoff,
			attack,
			decay,
			sustain,
			release,
			filtermin,
			filtermax,
			filterspeed,
			param_size
		};

		struct paraminfo
		{
			const char *internalname;
			const char *label;
			double min, max, defval;
			bool dirty;		// parameter has changed, GUI must be updated
		};
		static paraminfo paraminfos[param_size];


		wolp();
		~wolp();

		const String getName() const { return "wolp"; }
		void prepareToPlay (double sampleRate, int estimatedSamplesPerBlock)
		{
			setCurrentPlaybackSampleRate(sampleRate);
		}
		void releaseResources() { }
		void processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages);
		const String getInputChannelName (const int channelIndex) const { return String("In") + String(channelIndex); }
		const String getOutputChannelName (const int channelIndex) const { return String("Out") + String(channelIndex); }
		bool isInputChannelStereoPair (int index) const { return true; }
		bool isOutputChannelStereoPair (int index) const { return true; }
		bool acceptsMidi() const  { return true; }
		bool producesMidi() const { return false; }
		AudioProcessorEditor* createEditor();
		int getNumParameters() { return param_size; }
		const String getParameterName (int idx) { return String(paraminfos[idx].label); }
		float getParameter (int idx)
		{
			return params[idx];
		}
		const String getParameterText (int idx)
		{
			switch(idx)
			{
				default:
					return String(getparam(idx), 2);
			}
		}
		void setParameter (int idx, float value);

		//==============================================================================
		int getNumPrograms() { return 1; };
		int getCurrentProgram() { return 0; };
		void setCurrentProgram (int index) { };
		const String getProgramName (int index) { return "Default"; };
		void changeProgramName (int index, const String& newName) {}

		//==============================================================================
		void getStateInformation (JUCE_NAMESPACE::MemoryBlock& destData);
		void setStateInformation (const void* data, int sizeInBytes);

		//==============================================================================
		double getnotefreq (int noteNumber)
		{
			noteNumber -= 12 * 6 + 9; // now 0 = A440
			return getparam(tune) * pow (2.0, noteNumber / 12.0);
		}

		float getparam(int idx);

        void loaddefaultparams();

		void renderNextBlock (AudioSampleBuffer& outputAudio,
							  const MidiBuffer& inputMidi,
							  int startSample,
							  int numSamples);

		//==============================================================================
		/** Called when one of the MidiKeyboardState's keys is pressed.

			This will be called synchronously when the state is either processing a
			buffer in its MidiKeyboardState::processNextMidiBuffer() method, or
			when a note is being played with its MidiKeyboardState::noteOn() method.

			Note that this callback could happen from an audio callback thread, so be
			careful not to block, and avoid any UI activity in the callback.
		*/
		virtual void handleNoteOn (MidiKeyboardState* source,
								   int midiChannel, int midiNoteNumber, float velocity)
		{
//			printf("MidiKeyboard noteOn isProcessing=%s\n", isProcessing? "true": "false");
			noteOn(midiChannel, midiNoteNumber, velocity);
		}

		/** Called when one of the MidiKeyboardState's keys is released.

			This will be called synchronously when the state is either processing a
			buffer in its MidiKeyboardState::processNextMidiBuffer() method, or
			when a note is being played with its MidiKeyboardState::noteOff() method.

			Note that this callback could happen from an audio callback thread, so be
			careful not to block, and avoid any UI activity in the callback.
		*/
		virtual void handleNoteOff (MidiKeyboardState* source,
									int midiChannel, int midiNoteNumber)
		{
//			printf("MidiKeyboard noteOff isProcessing=%s\n", isProcessing? "true": "false");
			noteOff(midiChannel, midiNoteNumber, velocity);
		}

	protected:

	private:
		double params[param_size];

		velocityfilter <double> cutoff_filter;

		unsigned long samples_synthesized;

		bool isProcessing;	// whether we are in the processBlock callback

		friend class wolpVoice;
		friend class editor;
};


#endif // SYNTH_H
