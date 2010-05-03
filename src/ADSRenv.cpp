#include "ADSRenv.h"

ADSRenv::ADSRenv():
	curTime(0.0),
	noteReleased(false),
	curValue(0.0)
{
	setAttack(0.5);
	setDecay(0.5);
	setSustain(0.5);
	setRelease(0.5);
}

ADSRenv::~ADSRenv()
{
}

void ADSRenv::advance(double seconds, bool noteIsOn)
{
	if(!noteIsOn && !noteReleased)
	{
		noteReleased= true;
		noteReleaseTime= curTime;
		noteReleaseValue= curValue;
	}

	if(noteReleased)
	{
		curValue= noteReleaseValue - (curTime-noteReleaseTime)*releaseInv;
		if(curValue<0.0) curValue= 0.0;
	}
	else
	{
		if(curTime<attack)
			curValue= curTime*attackInv;
		else
		{
			if(curTime>attack+decay)
				curValue= sustain;
			else
				curValue= 1.0 - (curTime-attack)*decayInv*(1.0-sustain);
		}
	}

	curTime+= seconds;
}

