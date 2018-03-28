#include "stdafx.h"
#include <process.h>
#include <random>
#include <string>
#include "..\FastTacticsLibrary\TwoDCoordinate.h"
#include "Contact.h"
#include "ContactProcessor.h"
#include "..\FastTacticsLibrary\globals.h"
#include "..\FastTacticsLibrary\CoordinateConverter.h"

using namespace std;

ContactProcessor::ContactProcessor(int iFloatPrecision)
{
	_iFloatPrecision = iFloatPrecision;
}

//************************************
// Method:    AddContact
// FullName:  ContactProcessor::AddContact
// Access:    public 
// Returns:   void
// Qualifier:
// Parameter: Contact cNewContact
//************************************
void ContactProcessor::AddContact(Contact cNewContact)
{
	int lLength = (int) contactMap.size();
	contactMap._Insert_or_assign(lLength, cNewContact);
}

//************************************
// Method:    RemoveContact
// FullName:  ContactProcessor::RemoveContact
// Access:    public 
// Returns:   void
// Qualifier:
// Parameter: int index
//************************************
void ContactProcessor::RemoveContact(int index)
{
	contactMap.erase(index);
}

//************************************
// Method:    ProcessAndReturnMap
// FullName:  ContactProcessor::ProcessAndReturnMap
// Access:    public 
// Returns:   std::map<int, Contact>
// Qualifier:
//************************************
map<int, Contact> ContactProcessor::ProcessAndReturnMap()
{
	int randNum = GetRandomNumber(0, contactMap.size() - 1);
	std::map<int, Contact>::iterator it = contactMap.begin();
	while (it != contactMap.end())
	{
		// One has been picked to be changed
		if(it->first == randNum)
		{
			float fMin = (it->second.getHeading() - 30.0F) < 0.0F ? 0.0F : it->second.getHeading() - 30.0F;
			float fMax = (it->second.getHeading() + 30.0F) > 360.F ? 0.0F : it->second.getHeading() + 30.0F;
			float newHeading = GetRandomNumber(fMin, fMax);
			it->second.ChangeHeading(newHeading);
		}
		it->second.ProcessMovement();
		if(it->second.getRange() > max(_size.getX(), _size.getY())/2)
		{
			it->second.ChangeInRangeState(false);
		}
		it++;
	}

	return contactMap;
}

//************************************
// Method:    SetSize
// FullName:  ContactProcessor::SetSize
// Access:    public 
// Returns:   void
// Qualifier:
// Parameter: TwoDCoordinate size
//************************************
void ContactProcessor::SetSize(TwoDCoordinate size)
{
	_size = size;
}

//************************************
// Method:    DrawContacts
// FullName:  ContactProcessor::DrawContacts
// Access:    public 
// Returns:   void
// Qualifier:
// Parameter: HWND hWnd
//************************************
void ContactProcessor::DrawContacts(HWND hWnd)
{
	std::map<int, Contact>::iterator it = contactMap.begin();
	while (it != contactMap.end())
	{
		it->second.Draw(hWnd, _size);
		it++;
	}
}

//************************************
// Method:    CreateRandomContacts
// FullName:  ContactProcessor::CreateRandomContacts
// Access:    public 
// Returns:   bool
// Qualifier:
// Parameter: int iMin
// Parameter: int iMax
//************************************
bool ContactProcessor::CreateRandomContacts(int iMin, int iMax)
{
	srand(time(NULL));

	int randNum = GetRandomNumber(iMin, iMax);
	for (int i = 0; i < randNum; ++i) {

		float randomSpeed = 0.0F;
		float randomAltitude = 0.0F;
		float randomDegrees = GetRandomNumber(0.0F, 360.0F);
		float randomHeading = GetRandomNumber(0.0F, 360.0F);
		float randomRange = GetRandomNumber(0, max((int)_size.getX() / 2, (int)_size.getY() / 2));
		ContactPersonality randomPers = GetARandomPersonality();
		ContactMission randomMission = GetARandomContactMission(randomSpeed, randomAltitude);
		CreateContact(randomDegrees, randomRange, randomHeading, randomSpeed, randomAltitude, randomPers, randomMission);
	}

	return true;
}

//************************************
// Method:    GetARandomPersonality
// FullName:  ContactProcessor::GetARandomPersonality
// Access:    public 
// Returns:   ContactPersonality
// Qualifier:
//************************************
ContactPersonality ContactProcessor::GetARandomPersonality()
{
	return static_cast<ContactPersonality>(GetRandomNumber(ContactPersonality::Unknown, ContactPersonality::None));
}

//************************************
// Method:    GetARandomContactMission
// FullName:  ContactProcessor::GetARandomContactMission
// Access:    public 
// Returns:   ContactMission
// Qualifier:
// Parameter: float & speed
// Parameter: float & altitude
//************************************
ContactMission ContactProcessor::GetARandomContactMission(float &speed, float &altitude)
{
	ContactMission selectedMission = static_cast<ContactMission>(GetRandomNumber(ContactMission::Air, ContactMission::Sub));
	switch (selectedMission)
	{
	case Air:
		speed = GetRandomNumber(450.0F, 10000.0F);
		altitude = GetRandomNumber(5.0F, 72000.0F);
		break;
	case Surface:
		speed = GetRandomNumber(0.0F, 78.0F);
		altitude = 0.0F;
		break;
	case Sub:
		speed = GetRandomNumber(0.0F, 65.0F);
		altitude = 0.0F;
		break;
	case AAM:
	case SAM:
	case CM:
	default:
		break;
	}
	return selectedMission;
}

//************************************
// Method:    CreateContact
// FullName:  ContactProcessor::CreateContact
// Access:    public 
// Returns:   Contact
// Qualifier:
// Parameter: PolarCoordinate pcCoord
// Parameter: float heading
// Parameter: float speed
// Parameter: float altitude
// Parameter: ContactPersonality cpThreat
// Parameter: ContactMission cmType
//************************************
Contact ContactProcessor::CreateContact(float randomDegrees, float randomRange, float heading, float speed, float altitude, ContactPersonality cpThreat, ContactMission cmType)
{
	Contact newContact = Contact(randomDegrees, randomRange, altitude, speed, heading, cpThreat, cmType, _iFloatPrecision);
	AddContact(newContact);
	return newContact;
}

//************************************
// Method:    FindContact
// FullName:  ContactProcessor::FindContact
// Access:    public 
// Returns:   Contact *
// Qualifier:
// Parameter: int xPos
// Parameter: int yPos
//************************************
Contact * ContactProcessor::FindContact(int xPos, int yPos)
{
	RECT dest;
	RECT contact;

	RECT search = RECT();
	search.left = xPos - 10;
	search.top = yPos - 10;
	search.bottom = yPos + 10;
	search.right = xPos + 10;

	std::map<int, Contact>::iterator it = contactMap.begin();
	while (it != contactMap.end())
	{
		PolarCoordinate pc = it->second.getPolarCoordinate();
		TwoDCoordinate relPos = CoordinateConverter::ConvertFromPolarTo2D(pc.getDegrees(), pc.getRange(), _iFloatPrecision, TwoDCoordinate(0.0F, 0.0F));
		TwoDCoordinate absPos = relPos.getAbsolutePosition(&_size);
		contact.left = absPos.getX() - 10;
		contact.top = absPos.getY() - 10;
		contact.bottom = absPos.getY() + 10;
		contact.right = absPos.getX() + 10;

		if(IntersectRect(&dest, &search, &contact))
		{
			return &it->second;
		}
		it++;
	}
	return NULL;
}

//************************************
// Method:    GetRandomNumber
// FullName:  ContactProcessor::GetRandomNumber
// Access:    public 
// Returns:   int
// Qualifier:
// Parameter: int iFloor
// Parameter: int iCeiling
//************************************
int ContactProcessor::GetRandomNumber(int iFloor, int iCeiling)
{
	return rand() % (iCeiling - iFloor + 1) + iFloor;

}

float ContactProcessor::GetRandomNumber(float fFloor, float fCeiling)
{
	return rand() % (int) (fCeiling - fFloor + 1) + fFloor;
}


ContactProcessor::~ContactProcessor()
{
}
