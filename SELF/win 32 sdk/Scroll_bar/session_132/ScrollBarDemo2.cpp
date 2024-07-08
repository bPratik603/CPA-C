#include <Windows.h>
#include "SYSMETS.H"

#pragma comment(lib, "user32.lib")
#pragma comment(lib, "gdi32.lib")
#pragma comment(lib, "kernel32.lib")

#define ERRORBOX1(szMessage, szCaption)   {
                                                MessageBox((HWND)NULL, TEXT(szMessage),TEXT(szCaption), MB_ICONERROR);
												ExitProcess(EXIT_FAILURE);
                                          }

#define ERRORBOX2(hwnd,szMessage,szCaption) {
	                                            MessageBox((HWND)NULL, TEXT(szMessage), TEXT(szCaption), MB_ICONERROR);
												DestroyWindow(hwnd);
												ExitProcess(EXIT_FAILURE);
                                             }

LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
	static TCHAR szAppName[] = TEXT("BASIC SCROLL BAR DEMO");
	HWND hwnd = NULL;
	HBRUSH hBrush = NULL;
	HCURSOR hCursor = NULL;
	HICON hIcon = NULL;
	HICON hIconSm = NULL;
	WNDCLASSEX wndEx;
	MSG msg;

	ZeroMemory(&wndEx,sizeof(WNDCLASSEX));
	ZeroMemory(&msg,sizeof(MSG));

	hBrush = (HBRUSH)GetStockObject(WHITE_BRUSH);
	if(!hBrush)
	   ERRORBOX1("ERROR in obtaining brush", "GetStockObject Error");

	hCursor = LoadCursor((HINSTANCE)NULL, IDC_ARROW);
	if(!hCursor)
      ERRORBOX1("Error in obtating icon","LoadIcon Error");

	hIcon = LoadIcon((HINSTANCE)NULL, IDI_APPLICATION);
	 if(!hIcon)
	    ERRORBOX1("Error in obtaining icon", "LoadIcon Error");

	hIconSm = LoadIcon((HINSTANCE)NULL, IDI_APPLICATION);
	  if(!hIconSm)
	    ERRORBOX1("Error in obtaining small icon", "LoadIcon Error");

	wndEx.cbClsExtra = 0;
	wndEx.cbWndExtra = 0;
	wndEx.cbSize = sizeof(WNDCLASSEX);
	wndEx.hbrBackground = hBrush;
	wndEx.hCursor = hCursor;
	wndEx.hIcon = hIcon;
	wndEx.hIconSm = hIconSm;
	wndEx.hInstance = hInstance;
	wndEx.lpfnWndProc = WndProc;
	wndEx.lpszClassName = (LPCSTR)szAppName;
	wndEx.lpszMenuName = (LPCSTR)NULL;
	wndEx.style = CS_HREDRAW | CS_VREDRAW;

	if(!RegisterClassEx(&wndEx))
	{
		ERRORBOX1("Error in registering a window class", "RegisterClassEx Error ");
	}

	hwnd = CreateWindowEx(WS_EX_APPWINDOW,
	                      szAppName,
						  szAppName,
						  WS_OVERLAPPEDWINDOW | WS_VSCROLL | WS_HSCROLL,
						  CW_USEDEFAULT,
						  CW_USEDEFAULT,
						  CW_USEDEFAULT,
						  CW_USEDEFAULT,
						  (HWND)NULL,
						  (HMENU)NULL,
						   hInstance,
						   (LPVOID)NULL);

if(!hwnd)
  ERRORBOX1("Error in creating window in memory", " CreateWindowEx Error");

  ShowWindow(hwnd, nShowCmd);
  UpdateWindow(hwnd);

  while(GetMessage(&msg, (HWND)NULL,0,0))
  {
	TranslateMessage(&msg);
	DispatchMessage(&msg);
  }

  return ((int)msg.wParam);
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	#define BUFFER_LEN            16
	#define MAX_LABEL_LENGTH      22
	#define MAX_DESC_LENGTH       40

   static int cxChar;
   static int cxCaps;
   static int cyChar;
   static int cxClient;
   static int cyClient;
   static int iMaxWidth;

   int iVertPos;
   int iHorzPos;
   int iPaintBegin;
   int iPaintEnd;
   int iLength;
   int i;
   int x;
   int y;

   HDC hdc;

   PAINTSTRUCT ps;
   SCROLLINFO si;
   TEXTMETRIC tm;
   TCHAR szBuffer[BUFFER_LEN];

   switch(uMsg)
   {
	 case WM_CREATE:
	   hdc = GetDC(hwnd);
	   if(!hdc)
	      ERRORBOX2(hwnd,"Error in getting a device context", "GetDC Error");

	   ZeroMemory(&tm,sizeof(TEXTMETRIC));
        GetTextMetrics(hdc,&tm);

		cxChar = tm.tmAveCharWidth;
		cxCaps = (tm.tmPitchAndFamily & 1 ? 3 : 2) * cxChar;
		cyChar = tm.tmHeight + tm.tmExternalLeading;

		ReleaseDC(hwnd,hdc);
		iMaxWidth = MAX_LABEL_LENGTH * cxCaps + MAX_DESC_LENGTH * cxChar;
		break;

		case WM_SIZE:
		  cxClient = LOWORD(lParam);
		  cyClient = HIWORD(lParam);

		  si.cbSize = sizeof(SCROLLINFO);
		  si.fMask = SIF_RANGE | SIF_PAGE;
		  si.nMin = 0;
		  si.nMax = NUMLINES -1;
		  si.nPage = cyClient / cyChar;
		  SetScrollInfo(hwnd,
		                 SB_VERT,
						 &si,
						 TRUE);

		si.cbSize = sizeof(SCROLLINFO);
		si.fMask = SIF_RANGE;
		si.nMin = 0;
		si.nMax = 2 + (iMaxwidth / cxChar);
		SetScrollInfo(hwnd,
		        SB_HORZ,
				&si,
				TRUE);

		break;

		case WM_VSCROLL:
		   si.cbSize = sizeof(si);
		   si.fMask = SIF_ALL;
		   GetScrollInfo(hwnd,
		            SB_VERT,
					&si);

	    iVertPos = si.nPos;

		switch (LOWORD(wParam))
		{
			case SB_TOP:
			   si.nPos = si.nMin;
			   break;

			case SB_BOTTOM:
			   si.nPos = si.nMax;
			   break;

			case SB_LINEUP:
			   si.nPos -= 1;
			   break;

			case SB_LINEDOWN:
			    si.nPos += 1;

			case SB_PAGEUP:
			    si.nPos -= si.nPage;
				break;

			case SB_THUMBTRACK:
			   si.nPos = si.nTrackPos;
			   break;

			default:
			   break;
		}

		si.fMask = SIF_POS;
		SetScrollInfo(hwnd,
		          SB_VERT,
				  &si,
				  TRUE);
		GetScrollInfo(hwnd,SB_VERT,
		&si);

		if(si.nPos != iVertPos)
		{
			ScrollWindow(hwnd,
			     0,
				 cyChar * (iVertPos - si.nPos),
				 NULL,
				 NULL);

			UpdateWindow(hwnd);
		}

		break;

	  case WM_HSCROLL:
	     si.cbSize = sizeof(SCROLLINFO);
		 si.fMask = SIF_ALL;

		 GetScrollInfo(hwnd, SB_HORZ, &si);

		 iHorzPos = si.nPos;

		 switch(LOWORD(wParam))
		 {
			case SB_LINELEFT:
			   si.nPos -= 1;
			   break;

			case SB_LINERIGHT:
			   si.nPos += 1;
			   break;

			case SB_THUMBPOSITION:
			   si.nPos = si.nTrackPos;
			   break;

			default:
			   break;
		 }

		 si.fMask = SIF_POS;
		 SetScrollInfo(hwnd,
		       SB_HORZ,
			   &si,
			   TRUE);
		GetScrollInfo(hwnd,
		       SB_HORZ,
			   &si);

		if(si.nPos != iHorzPos)
		{
			ScrollWindow(hwnd,
			     cxChar * (iHorzPos - si.nPos),
				 0,
				 NULL,
				 NULL);
		}

		break;

	  case WM_PAINT:
	      hdc = BeginPaint(hwnd,&ps);
		  if(!hdc)
		     ERRORBOX2(hwnd,"Error in getting device context", " BeginPaint Error ");

		ZeroMemory(&si,sizeof(SCROLLINFO));
		si.cbSize = sizeof(SCROLLINFO);
		si.fMask = SIF_POS;
		GetScrollInfo(hwnd,SB_VERT,&si);
		iHorzPos = si.nPos;


		iPaintBegin = max(0,iVerPos + ps.rcPaint.top / cyChar);
		iPaintEnd = min(NUMLINES - 1, iVertPos + ps.rcPaint.bottom / cyChar);

		for(i = iPaintBegin; i <= iPaintEnd; i++)
		{
			x = cxChar * (1 - iHorzPos);
			y = cyChar * (i - iVertPos);

			TextOut(hdc,x,y,sysmets[i].szLabel,lstrlen(sysmets[i].szLabel));
			TextOut(hdc,x + MAX_LABEL_LENGTH * cxCaps, y, sysmets[i].szDesc,lstrlen(sysmets[i].szDesc));
			SetTextAlign(hdc, TA_TOP | TA_RIGHT);
			ZeroMemory(szBuffer,BUFFER_LEN);
			iLenght = wsprintf(szBuffer,TEXT("%5d"), GetSystemMetrics(sysmets[i].iIndex));
			TextOut(hdc, x + MAX_LABEL_LENGTH * cxCaps + MAX_DESC_LENGTH * cxChar,y , szBuffer, iLenght);
			SetTextAlign(hdc,TA_TOP | TA_LEFT);

		}

		EndPaint(hwnd, &ps);
		break;

		case WM_DESTROY:
		   PostQuitMessage(0);
		   break;
   }

   return (DefWindowProc(hwnd,uMsg,wParam,lParam));
}