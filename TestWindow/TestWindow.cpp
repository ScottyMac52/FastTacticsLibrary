// TestWindow.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include <map>
#include <string>
#include <exception>
#include "TestWindow.h"
#include "globals.h"
#include "..\FastTacticsLibrary\globals.h"
#include "..\FastTacticsLibrary\TwoDCoordinate.h"
#include "..\FastTacticsLibrary\PolarCoordinate.h"
#include "..\FastTacticsLibrary\CoordinateConverter.h"
#include "ContactProcessor.h"
#include "..\FastTacticsLibrary\ErrorProcesser.h"
#include "windowsx.h"

using namespace std;

void DrawTarget(HDC, COLORREF, float, float, TwoDCoordinate *, TwoDCoordinate *);
void DrawRadials(HDC hdc, COLORREF crColor, float fStep, int iLineStyle, float fRange, float fStart, float fEnd, TwoDCoordinate *offSet, TwoDCoordinate *size);

#define MAX_LOADSTRING 100
#define UPDATE_SPEED 1.0F

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name
TwoDCoordinate *tdSize;
ContactProcessor processor(0);
TwoDCoordinate * scopeSize;
bool bshowRadials = true;
bool bshowTest = false;
bool bshowContacts = true;

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Place code here.

    // Initialize global strings
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_TESTWINDOW, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_TESTWINDOW));

    MSG msg;

    // Main message loop:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_TESTWINDOW));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_TESTWINDOW);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

void CALLBACK f(HWND hwnd, UINT uMsg, UINT timerId, DWORD dwTime)
{
	RECT clientRect;

	processor.ProcessAndReturnMap();
	GetClientRect(hwnd, &clientRect);
	InvalidateRect(hwnd, &clientRect, true);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Store instance handle in our global variable

   tdSize = new TwoDCoordinate(800.0F, 800.0F, FLOAT_PRECISION);
   
   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);
   SetWindowPos(hWnd, 0, 0, 0, (int) tdSize->getX(), (int) tdSize->getY(), SWP_NOMOVE);
   return TRUE;
}

void SetMenuState(HWND hWnd, int imenuItemId, bool bState)
{
	HMENU currentMenu = GetMenu(hWnd);
	MENUITEMINFO info;
	memset(&info, 0, sizeof(MENUITEMINFO));
	info.cbSize = sizeof(MENUITEMINFO);
	info.fState = bState ? MFS_CHECKED : MFS_UNCHECKED;
	SetMenuItemInfo(currentMenu, imenuItemId, false, &info);
	!DrawMenuBar(hWnd);
}

void OnCreate(HWND hWnd)
{
	scopeSize = new TwoDCoordinate(500.0F, 500.0F, FLOAT_PRECISION);
	processor.SetSize(*scopeSize);
	//processor.CreateContact(PolarCoordinate(90.0F, 100.0F), 315.0F, 6000.0F, 20000.0F, Enemy, Surface);
	processor.CreateRandomContacts(0, 20);
	processor.ProcessAndReturnMap();
	SetTimer(hWnd, 0, 1000 * UPDATE_SPEED, (TIMERPROC)&f);
}

LRESULT CALLBACK OnWMCommand(WPARAM wParam, HWND hWnd, UINT message, LPARAM lParam)
{
	RECT clientRect;
	int wmId = LOWORD(wParam);
	// Parse the menu selections:
	switch (wmId)
	{
	case ID_RADAR_SHOWCONTACTS:
		bshowContacts = !bshowContacts;
		GetClientRect(hWnd, &clientRect);
		InvalidateRect(hWnd, &clientRect, true);
		SetMenuState(hWnd, ID_RADAR_SHOWCONTACTS, bshowContacts);
		break;
	case ID_RADAR_SHOWRADIALS:
		bshowRadials = !bshowRadials;
		GetClientRect(hWnd, &clientRect);
		InvalidateRect(hWnd, &clientRect, true);
		SetMenuState(hWnd, ID_RADAR_SHOWRADIALS, bshowContacts);
		break;
	case IDM_ABOUT:
		DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
		break;
	case IDM_EXIT:
		DestroyWindow(hWnd);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
}

void OnWMPaint(HWND hWnd)
{
	PAINTSTRUCT ps;
	HDC hdc = BeginPaint(hWnd, &ps);
	// Create a Green Brush
	HPEN hPen = CreatePen(PS_SOLID, 2, RGB(0x00, 0xFF, 0x00));
	// Select the Green Pen and save the old pen			
	HPEN oldPen = (HPEN)SelectObject(hdc, hPen);

	RECT lpRect;
	GetClientRect(hWnd, &lpRect);

	TwoDCoordinate *noOffset = new TwoDCoordinate(0.0F, 0.0F, FLOAT_PRECISION);
	Ellipse(hdc, 0, 0, (int)scopeSize->getX(), (int)scopeSize->getX());
	SelectObject(hdc, oldPen);
	DeleteObject(hPen);
	if (bshowRadials)
	{
		DrawRadials(hdc, GREEN, 45.0F, PS_DASHDOTDOT, 250.0F, NORTH_PRIME, NORTH, new TwoDCoordinate(0.0F, 0.0F, FLOAT_PRECISION), scopeSize);
	}

	if (bshowContacts)
	{
		processor.DrawContacts(hWnd);
	}
	delete(noOffset);
	EndPaint(hWnd, &ps);
}

LRESULT OnLeftButtonDblClick(WPARAM wParam, int xPos, int yPos)
{
	return 0;
}

LRESULT OnLeftButtonDown(HWND hWnd, WPARAM wParam, int xPos, int yPos)
{
	Contact *foundContact = processor.FindContact(xPos, yPos);
	if(foundContact != NULL)
	{
		MessageBox(hWnd, foundContact->toString().c_str(), L"Find Contact", MB_OK);
	}
	return 0;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND  - process the application menu
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
    {
	case WM_LBUTTONDOWN:
		{
			int xPos = GET_X_LPARAM(lParam);
			int yPos = GET_Y_LPARAM(lParam);
			return OnLeftButtonDown(hWnd, wParam, xPos, yPos);
		}
		break;
	case WM_LBUTTONDBLCLK:
		{
			int xPos = GET_X_LPARAM(lParam);
			int yPos = GET_Y_LPARAM(lParam);
			return OnLeftButtonDblClick(wParam, xPos, yPos);
		}
		break;
	case WM_CREATE:
		{
			OnCreate(hWnd);
			SetCapture(hWnd);
		}
		break;
    case WM_COMMAND:
        {
		return OnWMCommand(wParam, hWnd, message, lParam);
	}
        break;
    case WM_PAINT:
        {
            
			OnWMPaint(hWnd);

        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
		delete(tdSize);
		delete(scopeSize);
		break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}

//************************************
// Method:    DrawTarget
// FullName:  DrawTarget
// Access:    public 
// Returns:   void
// Qualifier:
// Parameter: HDC hdc
// Parameter: COLORREF color
// Parameter: float degrees
// Parameter: float distance
// Parameter: TwoDCoordinate * offset
// Parameter: TwoDCoordinate * size
//************************************
void DrawTarget(HDC hdc, COLORREF color, float degrees, float distance, TwoDCoordinate *offset, TwoDCoordinate *size)
{
	PolarCoordinate pc = PolarCoordinate(degrees, distance, FLOAT_PRECISION);
	TwoDCoordinate *pos = &CoordinateConverter::ConvertFromPolarTo2D(pc, *offset).getAbsolutePosition(size);
	HPEN hPen = CreatePen(PS_SOLID, 1, color);
	HPEN oldPen = (HPEN)SelectObject(hdc, hPen);
	SetPixel(hdc, (int) pos->getX(), (int) pos->getY(), color);
	SelectObject(hdc, oldPen);
	DeleteObject(hPen);
}

//************************************
// Method:    DrawRadials
// FullName:  DrawRadials
// Access:    public 
// Returns:   void
// Qualifier:
// Parameter: HDC hdc
// Parameter: COLORREF crColor
// Parameter: float fStep
// Parameter: int iLineStyle
// Parameter: float fRange
// Parameter: float fStart
// Parameter: float fEnd
// Parameter: TwoDCoordinate * offSet
// Parameter: TwoDCoordinate * size
//************************************
void DrawRadials(HDC hdc, COLORREF crColor, float fStep, int iLineStyle, float fRange, float fStart, float fEnd, TwoDCoordinate *offSet, TwoDCoordinate *size)
{
	bool initialized = false;

	POINT center;

	HPEN hPen = CreatePen(iLineStyle, 1, crColor);
	HPEN oldPen = (HPEN) SelectObject(hdc, hPen);

	for (float fCurrentAngle = fStart; fCurrentAngle < fEnd; fCurrentAngle += fStep)
	{
		if(!initialized)
		{
			center.x = size->getX() / 2.0F;
			center.y = size->getY() / 2.0F;
		}
		MoveToEx(hdc, center.x, center.y, nullptr);
		PolarCoordinate pc = PolarCoordinate(fCurrentAngle, fRange, FLOAT_PRECISION);
		TwoDCoordinate *pos = &CoordinateConverter::ConvertFromPolarTo2D(pc, *offSet).getAbsolutePosition(size);
		LineTo(hdc, pos->getX(), pos->getY());
	}

	SelectObject(hdc, oldPen);
	DeleteObject(hPen);

}
