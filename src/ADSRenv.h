#ifndef ADSRENV_H
#define ADSRENV_H


class ADSRenv
{
	public:
		ADSRenv();
		virtual ~ADSRenv();

		void setAttack(double v) { if(v<0.005) v= 0.005; attack= v; attackInv= 1.0/v; }
		double getAttack() { return attack; }
		void setDecay(double v) { decay= v; decayInv= 1.0/v; }
		double getDecay() { return decay; }
		void setSustain(double v) { sustain= v; }
		double getSustain() { return sustain; }
		void setRelease(double v) { if(v<0.005) v= 0.005; release= v; releaseInv= 1.0/v; }
		double getRelease() { return release; }

		void advance(double seconds, bool noteIsOn);
		double getValue() { return curValue; }
		void resetTime() { curTime= curValue= 0.0; noteReleased= false; }

		bool isFinished() { return bool(noteReleased && (curTime-noteReleaseTime>release)); }

	protected:
		double attack, attackInv, decay, decayInv, sustain, release, releaseInv;
		double curTime;
		bool noteReleased;
		double noteReleaseTime;
		double noteReleaseValue;
		double curValue;
};

#endif // ADSRENV_H

