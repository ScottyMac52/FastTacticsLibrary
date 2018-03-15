// TestWindow.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "TestWindow.h"
#include "..\FastTacticsLibrary\TwoDCoordinate.h"
#include "..\FastTacticsLibrary\PolarCoordinate.h"
#include "..\FastTacticsLibrary\CoordinateConverter.h"

#define RED RGB(0xFF, 0x00, 0x00)
#define GREEN RGB(0x00, 0xFF, 0x00)
#define BLUE RGB(0x00, 0x00, 0xFF)
#define YELLOW RGB(0xFF, 0xFF, 0x00)

#define NORTH 0.0F
#define EAST 90.0F
#define SOUTH 180.0F
#define WEST 270.0F
#define NORTH_PRIME 360.0F

struct VisibleTarget
{
	COLORREF paintColor;
	float polarPosition;
	float distance;
};

void DrawTarget(HDC, COLORREF, float, float, TwoDCoordinate *, TwoDCoordinate *);
VisibleTarget GetVisibleTarget(float);


#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

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

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);
   SetWindowPos(hWnd, HWND_TOPMOST, 0, 0, 800, 800, SWP_NOMOVE);

   return TRUE;
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
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Parse the menu selections:
            switch (wmId)
            {
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
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
			// Create a Green Brush
			HPEN hPen = CreatePen(PS_DOT, 1, RGB(0x00, 0xFF, 0x00));
			// Select the Green Pen and save the old pen			
			HPEN oldPen = (HPEN)SelectObject(hdc, hPen);

			RECT lpRect;
			GetClientRect(hWnd, &lpRect);

			TwoDCoordinate *noOffset = new TwoDCoordinate(0.0F, 0.0F);
			TwoDCoordinate *size = new TwoDCoordinate(500.0F, 500.0F);
			Ellipse(hdc, 0, 0, size->getX(), size->getX());
			SelectObject(hdc, oldPen);
			DeleteObject(hPen);
			float increment = 0.5F;

			for(float currentAngle = NORTH; currentAngle<NORTH_PRIME; currentAngle += increment)
			{
				VisibleTarget currentTarget = GetVisibleTarget(currentAngle);
				DrawTarget(hdc, currentTarget.paintColor, currentTarget.polarPosition, currentTarget.distance, noOffset, size);
			}

			delete(size);
			delete(noOffset);
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
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
	PolarCoordinate pc = PolarCoordinate(degrees, distance);
	TwoDCoordinate *pos = &CoordinateConverter::ConvertFromPolarTo2D(pc, *offset).getAbsolutePosition(size);
	HPEN hPen = CreatePen(PS_SOLID, 1, color);
	HPEN oldPen = (HPEN)SelectObject(hdc, hPen);
	SetPixel(hdc, pos->getX(), pos->getY(), color);
	SelectObject(hdc, oldPen);
	DeleteObject(hPen);
}

//************************************
// Method:    GetVisibleTarget
// FullName:  GetVisibleTarget
// Access:    public 
// Returns:   VisibleTarget
// Qualifier:
// Parameter: float currentAngle
//************************************
VisibleTarget GetVisibleTarget(float currentAngle)
{
	VisibleTarget target;
	target.polarPosition = currentAngle;
	if (currentAngle >= NORTH && currentAngle < EAST)
	{
		target.paintColor = RED;
		target.distance = 25.0F;
	}
	else if (currentAngle >= EAST && currentAngle < SOUTH)
	{
		target.paintColor = GREEN;
		target.distance = 50.0F;
	}
	else if (currentAngle >= SOUTH && currentAngle < WEST)
	{
		target.paintColor = BLUE;
		target.distance = 75.0F;
	}
	else
	{
		target.paintColor = YELLOW;
		target.distance = 100.0F;
	}
	return target;
}
