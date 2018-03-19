#ifndef __wtypes_h__
#include <wtypes.h>
#endif

#ifndef __WINDEF_
#include <windef.h>
#endif

#ifndef _WINUSER_
#include <winuser.h>
#endif

#ifndef __RPC_H__
#include <rpc.h>
#endif

#pragma once
#include "..\FastTacticsLibrary\TwoDCoordinate.h"
#include "..\FastTacticsLibrary\ThreeDCoordinate.h"
#include <time.h>
#include <windef.h>

class Contact :
	public ThreeDCoordinate
{
public:
	Contact(PolarCoordinate pcPos, float const fAltitude, float const fSpeed, float const fHeading, ContactPersonality const cpThreat, ContactMission const cmType);
	bool ProcessMovement();
	bool ChangeSpeed(float const fSpeed);
	bool ChangeHeading(float const fHeading);
	bool ChangeThreat(ContactPersonality cpThreat);
	void ChangeInRangeState(bool const rangeState);
	float getSpeed() const;
	float getHeading() const;
	ContactPersonality getThreat() const;
	ContactMission getType() const;
	~Contact();
	void Draw(HWND hWnd, TwoDCoordinate size);
protected:
	bool _inRange = true;
	float _speed;
	float _heading;
	bool _timerStarted = false;
	ContactPersonality _personality;
	ContactMission _mission;
	clock_t _ptmMark;
	bool CheckForTimerStart();
	bool DrawVelocityVector(HDC hdc, TwoDCoordinate currentPos, COLORREF cColor, TwoDCoordinate size);
	void DrawVisibleContact(HDC hdc, TwoDCoordinate coordAbs);
	void DrawAngleArc(HDC hdc, TwoDCoordinate &coordAbs, float startAngle, float endAngle);
	void DrawCarat(HDC hdc, TwoDCoordinate coordAbs, float rotateAngle);
	float _distanceMoved = 0.0F;
};

