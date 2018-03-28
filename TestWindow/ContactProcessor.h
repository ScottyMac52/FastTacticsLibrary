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

#include <map>
#include "..\FastTacticsLibrary\TwoDCoordinate.h"
#include "Contact.h"

using namespace std;
#pragma once
class ContactProcessor
{
public:
	ContactProcessor();
	ContactProcessor(int iFloatPrecision);
	void AddContact(Contact);
	void RemoveContact(int);
	map<int, Contact> ProcessAndReturnMap();
	void SetSize(TwoDCoordinate);
	void DrawContacts(HWND hWnd);
	bool CreateRandomContacts(int iMin, int iMax);
	ContactPersonality GetARandomPersonality();
	ContactMission GetARandomContactMission(float & speed, float & altitude);
	Contact CreateContact(float randomDegrees, float randomRange, float heading, float speed, float altitude, ContactPersonality cpThreat, ContactMission cmType);
	Contact * FindContact(int xPos, int yPos);
	int GetRandomNumber(int iFloor, int iCeiling);
	float GetRandomNumber(float fFloor, float fCeiling);
	~ContactProcessor();
protected:
	map<int, Contact> contactMap;
	TwoDCoordinate _size;
private:
	int _iFloatPrecision;
private:
};

