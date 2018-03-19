#include "stdafx.h"
#include "globals.h"
#include "Contact.h"
#include <exception>
#include <iostream>
#include <map>

#include "..\FastTacticsLibrary\TwoDCoordinate.h"
#include "..\FastTacticsLibrary\CoordinateConverter.h"
#include "..\FastTacticsLibrary\PolarCoordinate.h"
#include "..\FastTacticsLibrary\ErrorProcesser.h"

#define CONTACT_SIZE 10
#define VELOCITY_VECTOR_MAGNITUDE 20

using namespace std;

//************************************
// Method:    Contact
// FullName:  Contact::Contact
// Access:    public 
// Returns:   
// Qualifier:
// Parameter: PolarCoordinate pcPos
// Parameter: float const fAltitude
// Parameter: float const fSpeed
// Parameter: float const fHeading
// Parameter: ContactPersonality const cpThreat
// Parameter: ContactMission const cmType
//************************************
Contact::Contact(PolarCoordinate pcPos, float const fAltitude, float const fSpeed, float const fHeading, ContactPersonality const cpThreat, ContactMission const cmType)
{
	_range = pcPos.getRange();
	_degrees = pcPos.getDegrees();
	_speed = fSpeed;
	_heading = fHeading;
	_personality = cpThreat;
	_mission = cmType;
	_altitude = fAltitude;
	ProcessMovement();
}

//************************************
// Method:    ProcessMovement
// FullName:  Contact::ProcessMovement
// Access:    public 
// Returns:   bool
// Qualifier:
//************************************
bool Contact::ProcessMovement()
{
	if (CheckForTimerStart() && _inRange)
	{
		// The timer is running so now we use the speed and heading to figure out 
		// where the contact is
		if (_speed > 0.0F)
		{
			// Speed is greater than zero so we will automatically notify the caller
			// that the position is going to change

			// Get the Mark time since the last process
			clock_t current = clock() - _ptmMark;
			float durationSeconds = current / CLOCKS_PER_SEC;
			// Make sure that the mark time is recorded
			_ptmMark = clock();

			_distanceMoved = durationSeconds * (_speed / 3600.0F);
			TwoDCoordinate tDCurrent = CoordinateConverter::ConvertFromPolarTo2D(this->getPolarCoordinate());
			TwoDCoordinate tDCoord = CoordinateConverter::CalculatePointFromDegrees(tDCurrent, _heading, _distanceMoved);
			PolarCoordinate newPos = CoordinateConverter::ConvertFrom2DToPolar(tDCoord);
			_degrees = newPos.getDegrees();
			_range = newPos.getRange();
			return true;
		}
	}
	return false;
}

//************************************
// Method:    ChangeSpeed
// FullName:  Contact::ChangeSpeed
// Access:    public 
// Returns:   bool
// Qualifier:
// Parameter: float const fSpeed
//************************************
bool Contact::ChangeSpeed(float const fSpeed)
{
	if (_speed != fSpeed)
	{
		_speed = fSpeed;
		ProcessMovement();
		return true;
	}

	return false;
}

//************************************
// Method:    ChangeHeading
// FullName:  Contact::ChangeHeading
// Access:    public 
// Returns:   bool
// Qualifier:
// Parameter: float const fHeading
//************************************
bool Contact::ChangeHeading(float const fHeading)
{
	if (_heading != fHeading)
	{
		_heading = fHeading;
		ProcessMovement();
		return true;
	}
	return false;
}

//************************************
// Method:    ChangeThreat
// FullName:  Contact::ChangeThreat
// Access:    public 
// Returns:   bool
// Qualifier:
// Parameter: ContactPersonality cpThreat
//************************************
bool Contact::ChangeThreat(ContactPersonality cpThreat)
{
	if (_personality != cpThreat)
	{
		_personality = cpThreat;
		return true;
	}
	return false;
}

void Contact::ChangeInRangeState(bool const rangeState)
{
	_inRange = rangeState;
}

//************************************
// Method:    getSpeed
// FullName:  Contact::getSpeed
// Access:    public 
// Returns:   float
// Qualifier: const
//************************************
float Contact::getSpeed() const
{
	return _speed;
}

//************************************
// Method:    getHeading
// FullName:  Contact::getHeading
// Access:    public 
// Returns:   float
// Qualifier: const
//************************************
float Contact::getHeading() const
{
	return _heading;
}

//************************************
// Method:    getThreat
// FullName:  Contact::getThreat
// Access:    public 
// Returns:   ContactPersonality
// Qualifier: const
//************************************
ContactPersonality Contact::getThreat() const
{
	return _personality;
}

//************************************
// Method:    getType
// FullName:  Contact::getType
// Access:    public 
// Returns:   ContactMission
// Qualifier: const
//************************************
ContactMission Contact::getType() const
{
	return _mission;
}

//************************************
// Method:    ~Contact
// FullName:  Contact::~Contact
// Access:    public 
// Returns:   
// Qualifier:
//************************************
Contact::~Contact()
{
}

//************************************
// Method:    Draw
// FullName:  Contact::Draw
// Access:    public 
// Returns:   void
// Qualifier:
// Parameter: HWND hWnd
// Parameter: TwoDCoordinate size
//************************************
void Contact::Draw(HWND hWnd, TwoDCoordinate size)
{
	if(!_inRange)
	{
		return;
	}

	TwoDCoordinate coord = CoordinateConverter::ConvertFromPolarTo2D(getPolarCoordinate(), TwoDCoordinate(0.0F, 0.0F));
	TwoDCoordinate coordAbs = coord.getAbsolutePosition(&size);

	COLORREF defaultColor = YELLOW;
	switch (_personality)
	{
	case Enemy:
		defaultColor = RED;
		break;
	case Friendly:
		defaultColor = GREEN;
		break;
	default:
		break;
	}

	HPEN hPen = CreatePen(PS_SOLID, 1, defaultColor);
	HDC hdc = GetDC(hWnd);
	HPEN oldPen = (HPEN)SelectObject(hdc, hPen);
	DrawVisibleContact(hdc, coordAbs);
	SetPixel(hdc, coordAbs.getX(), coordAbs.getY(), defaultColor);
	DrawVelocityVector(hdc, coordAbs, defaultColor, size);
	SelectObject(hdc, oldPen);
	DeleteObject(hPen);
	ReleaseDC(hWnd, hdc);
}

//************************************
// Method:    CheckForTimerStart
// FullName:  Contact::CheckForTimerStart
// Access:    protected 
// Returns:   bool
// Qualifier:
//************************************
bool Contact::CheckForTimerStart()
{
	if (!_timerStarted)
	{
		_ptmMark = clock();
		_timerStarted = true;
		return false;
	}
	return true;
}

//************************************
// Method:    DrawVelocityVector
// FullName:  Contact::DrawVelocityVector
// Access:    protected 
// Returns:   bool
// Qualifier:
// Parameter: HDC hdc
// Parameter: TwoDCoordinate currentPos
// Parameter: COLORREF cColor
// Parameter: TwoDCoordinate size
//************************************
bool Contact::DrawVelocityVector(HDC hdc, TwoDCoordinate currentPos, COLORREF cColor, TwoDCoordinate size)
{
	DWORD lastError = 0;
		
	float distanceMoved = VELOCITY_VECTOR_MAGNITUDE * (_speed / 3600.0F);
	TwoDCoordinate relativePos = currentPos.getRelativePosition(&size);
	TwoDCoordinate futurePoint = CoordinateConverter::CalculatePointFromDegrees(relativePos, _heading, distanceMoved);
	TwoDCoordinate futureCoordAbs = futurePoint.getAbsolutePosition(&size);

	HPEN hPen = CreatePen(PS_SOLID, 1, cColor);
	HPEN oldPen = (HPEN) SelectObject(hdc, hPen);
	MoveToEx(hdc, currentPos.getX(), currentPos.getY(), nullptr);
	LineTo(hdc, futureCoordAbs.getX(), futureCoordAbs.getY());
	SelectObject(hdc, oldPen);
	DeleteObject(hPen);
	return lastError == 0 ? true : false;
}

//************************************
// Method:    DrawVisibleContact
// FullName:  Contact::DrawVisibleContact
// Access:    protected 
// Returns:   void
// Qualifier:
// Parameter: HDC hdc
// Parameter: TwoDCoordinate coordAbs
//************************************
void Contact::DrawVisibleContact(HDC hdc, TwoDCoordinate coordAbs)
{
	std::map<int, POINT> drawPoints;

	switch(_mission)
	{
	case AAM:
		break;
	case SAM:
		break;
	case CM:
		break;
	case Air:
		switch(_personality)
		{
		case Unknown:
		case Friendly:
			DrawAngleArc(hdc, coordAbs, 0.0F, 180.0F);
			break;
		case Enemy:
			DrawCarat(hdc, coordAbs, 180.0F);
			break;
		default:
			break;
		}
		break;
	case Surface:
		switch (_personality)
		{
		case Unknown:
		case Friendly:
			DrawAngleArc(hdc, coordAbs, 0.0F, 180.0F);
			DrawAngleArc(hdc, coordAbs, 180.0F, 180.0F);
			break;
		case Enemy:
			DrawCarat(hdc, coordAbs, 180.0F);
			DrawCarat(hdc, coordAbs, 0.0F);
			break;
		default:
			break;
		}
		break;
	case Sub:
		switch (_personality)
		{
		case Unknown:
		case Friendly:
			DrawAngleArc(hdc, coordAbs, 180.0F, 180.0F);
			break;
		case Enemy:
			DrawCarat(hdc, coordAbs, 0.0F);
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}

}

//************************************
// Method:    DrawAngleArc
// FullName:  Contact::DrawAngleArc
// Access:    protected 
// Returns:   void
// Qualifier:
// Parameter: HDC hdc
// Parameter: TwoDCoordinate & coordAbs
// Parameter: float startAngle
// Parameter: float endAngle
//************************************
void Contact::DrawAngleArc(HDC hdc, TwoDCoordinate &coordAbs, float startAngle, float endAngle)
{
	POINT prevPos;
	MoveToEx(hdc, coordAbs.getX(), coordAbs.getY(), &prevPos);
	AngleArc(hdc, coordAbs.getX() + CONTACT_SIZE, coordAbs.getY(), CONTACT_SIZE, startAngle, endAngle);
	MoveToEx(hdc, prevPos.x, prevPos.y, nullptr);
}

//************************************
// Method:    DrawCarat
// FullName:  Contact::DrawCarat
// Access:    protected 
// Returns:   void
// Qualifier:
// Parameter: HDC hdc
// Parameter: TwoDCoordinate coordAbs
// Parameter: float rotateAngle
//************************************
void Contact::DrawCarat(HDC hdc, TwoDCoordinate coordAbs, float rotateAngle)
{
	POINT prevPos;
	MoveToEx(hdc, coordAbs.getX() - CONTACT_SIZE, coordAbs.getY(), &prevPos);
	TwoDCoordinate caratTip = CoordinateConverter::CalculatePointFromDegrees(coordAbs, rotateAngle, CONTACT_SIZE);
	LineTo(hdc, caratTip.getX(), caratTip.getY());
	LineTo(hdc, coordAbs.getX() + CONTACT_SIZE, coordAbs.getY());
	MoveToEx(hdc, prevPos.x, prevPos.y, nullptr);
}

