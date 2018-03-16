#pragma once
#include "ThreeDCoordinate.h"
#include <time.h>

class DllExport Contact :
	public ThreeDCoordinate
{
public:
	Contact(PolarCoordinate const pcPos, float const fAltitude, float const fSpeed, float const fHeading, ContactPersonality const cpThreat, ContactMission const cmType);
	bool ProcessMovement();
	bool ChangeSpeed(float const fSpeed);
	bool ChangeHeading(float const fHeading);
	bool ChangeThreat(ContactPersonality cpThreat);
	float getSpeed() const;
	float getHeading() const;
	ContactPersonality getThreat() const;
	ContactMission getType() const;
	~Contact();

protected:
	float _speed;
	float _heading;
	bool _timerStarted = false;
	ContactPersonality _personality;
	ContactMission _mission;
	clock_t _ptmMark;

	bool CheckForTimerStart();

};

