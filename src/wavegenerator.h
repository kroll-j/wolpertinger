#ifndef WAVEGENERATOR_H_INCLUDED
#define WAVEGENERATOR_H_INCLUDED

/*
template<int oversampling>
class chebyshev_downsampling_lp
{
	public:
		double xv[3+1]; double yv[3+1];

		chebyshev_downsampling_lp() { memset(xv, 0, sizeof(xv)); memset(yv, 0, sizeof(yv)); }

		double run(double nextvalue);
};

template<>
inline double chebyshev_downsampling_lp<16>::run(double nextvalue)
{
//		mkfilter/mkshape/gencode   A.J. Fisher
//		parameters:
//
//		filtertype 	= 	Chebyshev
//		passtype 	= 	Lowpass
//		ripple 		= 	-1
//		order 		= 	3
//		samplerate 	= 	768000
//		corner1 	= 	18000

template<>
inline double chebyshev_downsampling_lp<8>::run(double nextvalue)
{
//		mkfilter/mkshape/gencode   A.J. Fisher
//		parameters:
//
//		filtertype 	= 	Chebyshev
//		passtype 	= 	Lowpass
//		ripple 		= 	-1
//		order 		= 	3
//		samplerate 	= 	768000
//		corner1 	= 	18000

template<>
inline double chebyshev_downsampling_lp<1>::run(double nextvalue)
{
	return nextvalue;
}
*/

template<int oversampling>
class __OldWaveGenerator
{
	public:
		__OldWaveGenerator():
			phase(0.0), cyclecount(0)
		{ }

		~__OldWaveGenerator()
		{ }

		double getNextSample()
		{
			double s= 0;
			for(int i= 0; i<oversampling; i++)
			{
				if(oversampling>1)
					s= chebyshev_lp.run(getNextRawSample());
				else
					s= getNextRawSample();
			}
			return s;
		}

		void setFrequency(double sampleRate, double noteFrequency)
		{
			sampleStep= noteFrequency / (sampleRate*oversampling);
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

		float *generateSamples(int nSamples)
		{
			if(sampleBuffer.size()<nSamples)
				sampleBuffer.resize(nSamples);
			double s;
			for(int i= 0; i<nSamples; i++)
			{
				for(int k= oversampling; k; k--)
					s= chebyshev_lp.run(getNextRawSample());
				sampleBuffer[i]= s;
			}
			return &sampleBuffer[0];
		}

	private:
		double sawFactor, rectFactor, triFactor, sampleStep, phase;
		int cyclecount;
		std::vector<float> rawSampleBuffer;
		std::vector<float> sampleBuffer;
		chebyshev_downsampling_lp<oversampling> chebyshev_lp;

		void generateRawSampleChunk(float *buffer, int nSamples)
		{
			double saw, rect, tri;
			for(int i= 0; i<nSamples; i++)
			{
				saw= phase;
				rect= (phase<0.5? -1: 1);
				tri= (cyclecount&1? 2-(phase+1)-1: phase);
				phase+= sampleStep;
				buffer[i]= saw*sawFactor + rect*rectFactor + tri*triFactor;
			}
		}

		void generateRawSamples(float *buffer, int nSamples)
		{
			while(phase>1.0) phase-= 2.0;
			for(int i= 0; i<nSamples; )
			{
				int chunkSize= (2 - (phase+1)) / sampleStep;
				if(chunkSize>nSamples-i) chunkSize= nSamples-i;
				generateRawSampleChunk(buffer+i, chunkSize);
				i+= chunkSize;
				if(i<nSamples) phase-= 2, cyclecount++;
			}
		}

		double getNextRawSample()
		{
			double saw= phase,
				   rect= (phase<0.5? -1: 1),
				   tri= (cyclecount&1? 2-(phase+1)-1: phase);

			double val= saw*sawFactor + rect*rectFactor + tri*triFactor;

			phase+= sampleStep;
			if (phase > 1)
				cyclecount++,
				phase -= 2;

			return val;
		}
};



template<int oversampling>
class NewWaveGenerator;


template<int oversampling>
class RawWaveGenerator
{
	public:
		RawWaveGenerator(): phase(0.0), cyclecount(0)
		{ }

		void setFrequency(double sampleRate, double noteFreq)
		{
			noteFrequency= noteFreq;
			sampleStep= noteFrequency / (sampleRate*oversampling);
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

		double getNextRawSample()
		{
			double saw, rect, tri;
			saw= phase;
			rect= (phase<0? -1: 1);
			tri= (phase<0? (phase+0.5)*2: 1-phase*2);

			double val= saw*sawFactor + rect*rectFactor + tri*triFactor;

			phase+= sampleStep;
			if (phase > 1)
				cyclecount++,
				phase -= 2;

			return val;
		}

		double getNextRawSample(double step, double phaseMod= 0.0)
		{
			double saw, rect, tri;
			double p= phase + phaseMod;
//			while(p<-1) p+= 2;
//			while(p>1) p-= 2;
			saw= p;
			rect= (p<0? -1: 1);
			tri= (p<0? p*2+1: 1-p*2);

			double val= saw*sawFactor + rect*rectFactor + tri*triFactor;

			phase+= step;
			if(step>0)
			{
#define PHASEMODULO
#ifdef PHASEMODULO
				while(phase >= 1.0)
					cyclecount++,
					phase -= 2;
#else
				if(phase >= 1.0)
					cyclecount++,
					phase= -1.0;
#endif
					// TODO: Check whether resetting the phase instead of subtracting
					// gives better spectral results.
					// ausserdem: integer-zähler ausprobieren
			}
			else
			{
#ifdef PHASEMODULO
				while(phase <= -1)
					cyclecount++,
					phase += 2;
#else
				if(phase <= -1.0)
					cyclecount++,
					phase= 1.0;
#endif
			}

			nSamples++;
			return val;
		}

	private:
		double sawFactor, rectFactor, triFactor, sampleStep, phase, noteFrequency;
		int cyclecount;
		uint32_t nSamples;

		friend class NewWaveGenerator<oversampling>;
};


template<int oversampling>
class NewWaveGenerator
{
	public:
		NewWaveGenerator(): overflow(0)
		{ }

		void beginNote()
		{
			overflow= 0;
			masterWaveGenerator.phase= slaveWaveGenerator.phase= -1;
			nSamplesGenerated= 0;
		}

		void setFrequency(double sampleRate, double noteFrequency)
		{
//			noteFrequency= noteFrequency * 1.99 + rand()*0.02/RAND_MAX;
			masterWaveGenerator.setFrequency(sampleRate, noteFrequency);
			slaveWaveGenerator.setFrequency(sampleRate, noteFrequency*1.7);
			samplingRate= sampleRate;
		}

		void setMultipliers(double mSaw, double mRect, double mTri)
		{
			masterWaveGenerator.setMultipliers(mSaw, mRect, mTri);
			slaveWaveGenerator.setMultipliers(mSaw, mRect, mTri);
		}

		float *generateSamples(int nSamples)
		{
			if(sampleBuffer.size()<nSamples)
				sampleBuffer.resize(nSamples);
			double s, masterSample, slaveSample;
			double phaseMod= sin( nSamplesGenerated*(1.0/48000)*M_PI*5 );
			double phaseMod2= sin( nSamplesGenerated*(1.0/48000)*M_PI*3 );
			for(int i= 0; i<nSamples; i++)
			{
					float lastPhase= masterWaveGenerator.phase;
				for(int k= oversampling; k; k--)
				{

					double phaseDiff= (masterWaveGenerator.phase-slaveWaveGenerator.phase);
					masterSample= masterWaveGenerator.getNextRawSample(masterWaveGenerator.sampleStep +
																	   masterWaveGenerator.sampleStep*slaveSample*0,//.9999);
																	   phaseMod)*.01;
					slaveSample= slaveWaveGenerator.getNextRawSample(slaveWaveGenerator.sampleStep +
																	 slaveWaveGenerator.sampleStep*masterSample*5 +
																	 slaveWaveGenerator.sampleStep*(masterSample-slaveSample)*0 +
																	 slaveWaveGenerator.sampleStep*phaseDiff*-1,
																	 -phaseMod2*1);

					s= downsamplingFilter.run(masterSample + slaveSample);
				}

					if(masterWaveGenerator.phase < lastPhase)
					{
						// phase reset
						phaseCount++;
						overflow+= masterWaveGenerator.phase - masterWaveGenerator.sampleStep*oversampling + 1;
						if(  (phaseCount>3) ) //&& (rand()%1000<500) )
						{
							// phase angleichen?
//							slaveWaveGenerator.phase= overflow*slaveWaveGenerator.sampleStep; //*oversampling;
//							slaveWaveGenerator.sampleStep= -slaveWaveGenerator.sampleStep;
							slaveWaveGenerator.phase= (slaveWaveGenerator.sampleStep>0? -1: 1);
//							slaveWaveGenerator.phase= -1;
							overflow= 0;
							phaseCount= 0;
//							slaveSample= masterSample= -100;
						}
					}

				sampleBuffer[i]= s;
				nSamplesGenerated++;
			}
			return &sampleBuffer[0];
		}

	private:
		RawWaveGenerator<oversampling> masterWaveGenerator, slaveWaveGenerator;
		std::vector<float> sampleBuffer;
		chebyshev_downsampling_lp<oversampling> downsamplingFilter;
		int phaseCount;
		uint32_t nSamplesGenerated;
		double samplingRate;
		double overflow;
};


#endif // WAVEGENERATOR_H_INCLUDED

