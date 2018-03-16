#include "stdafx.h"
#include "Contact.h"

//************************************
// Method:    Contact
// FullName:  Contact::Contact
// Access:    public 
// Returns:   
// Qualifier: : ThreeDCoordinate(pcPos, fAltitude)
// Parameter: PolarCoordinate const pcPos
// Parameter: float const fAltitude
// Parameter: float const fSpeed
// Parameter: float const fHeading
// Parameter: ContactPersonality const cpThreat
// Parameter: ContactMission const cmType
//************************************
Contact::Contact(PolarCoordinate const pcPos, float const fAltitude, float const fSpeed, float const fHeading, ContactPersonality const cpThreat, ContactMission const cmType) : ThreeDCoordinate(pcPos, fAltitude)
{
	_speed = fSpeed;
	_heading = fHeading;
	_personality = cpThreat;
	_mission = cmType;
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
	if(CheckForTimerStart())
	{
		// The timer is running so now we use the speed and heading to figure out 
		// where the contact is
		if(_speed > 0.0F)
		{
			// Speed is greater than zero so we will automatically notify the caller
			// that the position is going to change

			// Get the Mark time since the last process


			clock_t current = clock() - _ptmMark;
			float durationSeconds = current / CLOCKS_PER_SEC;
			// Make sure that the mark time is recorded
			_ptmMark = clock();

			float distance = durationSeconds * (_speed / 3600.0F);

			/*

			// Now calculate the contacts movement in that timespan
			var distance = timeSinceLastUpdate.TotalSeconds * (Speed / SECONDS_PER_HOUR);
			// Get the new position based on course and distance traveled
			var newPos = CoordinateConverter.CalculatePointFromDegrees(RelativePosition, new PolarCoordinate(Heading, distance), CoordinateConverter.ROUND_DIGITS);
			var newAbsPos = newPos.GetAbsolutePosition(DetectedBy.ViewPortExtent);


			*/

			// Calculate the future position of the contact

			// Update the position of the contact

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
	if(_speed != fSpeed)
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
	if(_heading != fHeading)
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
	if(_personality != cpThreat)
	{
		_personality = cpThreat;
		return true;
	}
	return false;
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


