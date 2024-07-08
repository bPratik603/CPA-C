#include<Windows.h>
#include "SYSMETS_1.H"

#pragma comment(lib, "user32.lib")
#pragma comment(lib, "gdi32.lib")
#pragma comment(lib, "kernel32.lib")

#define ERRORBOX1(szMessage,szCaption)    {\
                                             MessageBox((HWND)NULL,TEXT(szMessage),TEXT(szCaption),MB_ICONERROR);\
                                             ExitProcess(EXIT_FAILURE);\
                                          }

#define ERRORBOX2(hWnd,szMessage,szCaption)  {\
                                                MessageBox((HWND)NULL,TEXT(szMessage),TEXT(szCaption),MB_ICONERROR);\
                                                DestroyWindow(hWnd);\
                                                ExitProcess(EXIT_FAILURE);\
                                            }

LRESULT CALLBACK WndProc(HWND hWnd,UINT uMsg,WPARAM wParam,LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nShowCmd)
{
    static TCHAR szAppName[] = TEXT("Basic Scroll Bar");

    HWND hWnd = NULL;
    HBRUSH hBrush  = NULL;
    HCURSOR hCursor = NULL;
    HICON hIcon = NULL;
    HICON hIconSm = NULL;
    WNDCLASSEX wndEx;
    MSG msg;

     ZeroMemory(&wndEx,sizeof(WNDCLASSEX));
     ZeroMemory(&msg,sizeof(MSG));

    hBrush = (HBRUSH)GetStockObject(WHITE_BRUSH);
    if(!hBrush)
       ERRORBOX1("Failed to get brush","GetStockObject Error");

    hCursor = LoadCursor((HINSTANCE)NULL,IDC_ARROW);
      if(!hCursor)
         ERRORBOX1("Failed to get Cursor","LoadCursor Error");

    hIcon = LoadIcon((HINSTANCE)NULL,IDI_APPLICATION);
    if(!hIcon)
        ERRORBOX1("failed to get Icon","LoadIcon Error");

    hIconSm= LoadIcon((HINSTANCE)NULL,IDI_APPLICATION);
     if(!hIconSm)
        ERRORBOX1("Failed to get small Icon","LoadIcon Error");

    wndEx.cbSize = sizeof(WNDCLASSEX);
    wndEx.cbClsExtra = 0;
    wndEx.cbWndExtra= 0;
    wndEx.hbrBackground = hBrush;
    wndEx.hCursor = hCursor;
    wndEx.hIcon = hIcon;
    wndEx.hIconSm = hIconSm;
    wndEx.hInstance = hInstance;
    wndEx.lpfnWndProc = WndProc;
    wndEx.lpszClassName = (LPCSTR)szAppName;
    wndEx.lpszMenuName = (LPCSTR)NULL;
    wndEx.style = CS_VREDRAW | CS_HREDRAW;

   if(!RegisterClassEx(&wndEx))
      ERRORBOX1("Failed to Register Window","RegisterClassEx");

    hWnd = CreateWindowEx(WS_EX_APPWINDOW,
                          szAppName,
                          szAppName,
                          WS_OVERLAPPEDWINDOW | WS_HSCROLL | WS_VSCROLL,
                          CW_USEDEFAULT,
                          CW_USEDEFAULT,
                          CW_USEDEFAULT,
                          CW_USEDEFAULT,
                          (HWND)NULL,
                          (HMENU)NULL,
                          hInstance,
                          (LPVOID)NULL);

  if(!hWnd)
     ERRORBOX1("Failed to create Window","CreateWindowEx");

    ShowWindow(hWnd,nShowCmd);
    UpdateWindow(hWnd);

    while(GetMessage(&msg,(HWND)NULL,0,0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return((int)msg.wParam);
}

LRESULT CALLBACK WndProc(HWND hWnd,UINT uMsg,WPARAM wParam,LPARAM lParam)
{
    #define  BUFFER_SIZE   16
    #define  MAX_NAME_LEN  5
    #define  MAX_ATTENDANCE_LEN   7
    #define  MAX_CITY_LEN         15

    static int cxClient;
    static int cyClient;
    static int cxChar;
    static int cyChar;
    static int cxCaps;
    static int iMaxWidth;
    
    static int iVertPos;
    static int iHorzPos;
    static int iLength;
    static int iPaintBegin;
    static int iPaintEnd;
    static int i;
    static int x;
    static int y;

    HDC hdc;
    SCROLLINFO si;
    PAINTSTRUCT ps;
    TEXTMETRIC tm;

     TCHAR szRollBuffer[BUFFER_SIZE];
     TCHAR szAttendance[BUFFER_SIZE];

    switch(uMsg)
    {
        case WM_CREATE:
          hdc = GetDC(hWnd);
          if(!hdc)
             ERRORBOX2(hWnd,"Failed to get Divice context","GetDC Error");

         ZeroMemory(&tm,sizeof(TEXTMETRIC));
         GetTextMetrics(hdc,&tm);
         cxChar = tm.tmAveCharWidth;
         cyChar = tm.tmHeight + tm.tmExternalLeading;
         cxCaps = (tm.tmPitchAndFamily & 1 ? 3 : 2) * cxChar;
         ReleaseDC(hWnd,hdc); 

         iMaxWidth = MAX_NAME_LEN * cxChar + MAX_CITY_LEN * cxChar + MAX_ATTENDANCE_LEN * cxCaps;
         break;

        case WM_SIZE:
           cxClient = LOWORD(lParam);
           cyClient = HIWORD(lParam);

           si.cbSize = sizeof(SCROLLINFO);
           si.fMask  = SIF_RANGE | SIF_PAGE;
           si.nMin = 0;
           si.nMax = NUMLINES - 1;
           si.nPage = cyClient / cyChar;
           SetScrollInfo(hWnd,SB_VERT,&si,TRUE);

           si.cbSize = sizeof(SCROLLINFO);
           si.fMask = SIF_RANGE;
           si.nMin = 0;
           si.nMax = 2 + (iMaxWidth / cxChar);
           SetScrollInfo(hWnd,SB_HORZ,&si,TRUE);

           break;

        case WM_VSCROLL:
          si.cbSize = sizeof(si);
          si.fMask = SIF_ALL;

          GetScrollInfo(hWnd,SB_VERT,&si);
          iVertPos = si.nPos;

          switch(LOWORD(wParam))
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
                  break;

                case SB_PAGEUP:
                  si.nPos -= si.nPage;
                  break;

                case SB_PAGEDOWN:
                  si.nPos += si.nPage;
                  break;

                case SB_THUMBPOSITION:
                   si.nPos = si.nTrackPos;
                   break;

                default:
                  break;
          }
          si.fMask = SIF_POS;
          SetScrollInfo(hWnd,SB_VERT,&si,TRUE);
          GetScrollInfo(hWnd,SB_VERT,&si);

          if(si.nPos != iVertPos)
          {
             ScrollWindow(hWnd,0,cyChar * (iVertPos - si.nPos),NULL,NULL);
              UpdateWindow(hWnd);
          }
          break;

        case WM_HSCROLL:
          si.cbSize = sizeof(SCROLLINFO);
          si.fMask = SIF_ALL;

          GetScrollInfo(hWnd,SB_HORZ,&si);
          iHorzPos = si.nPos;

          switch(LOWORD(wParam))
          {
            case SB_LINELEFT:
               si.nPos -= 1;
               break;
            
            case SB_LINERIGHT:
              si.nPos += 1;
              break;

            case SB_PAGELEFT:
              si.nPos -= si.nPage;
              break;

            case SB_PAGERIGHT:
              si.nPos += si.nPage;
              break;

            case SB_THUMBPOSITION:
              si.nPos = si.nTrackPos;
              break;

            default:
              break;
          }
          si.fMask = SIF_POS;
          SetScrollInfo(hWnd,SB_HORZ,&si,TRUE);
          GetScrollInfo;(hWnd,SB_HORZ,&si);

          if(si.nPos != iHorzPos)
          {
            ScrollWindow(hWnd,cxChar * (iHorzPos - si.nPos),0,NULL,NULL);
            UpdateWindow(hWnd);
          }
        break;

        case WM_PAINT:
          hdc = BeginPaint(hWnd,&ps);
           if(!hdc)
             ERRORBOX2(hWnd,"Failed to get Paint","BeginPaint Error");

          ZeroMemory(&si,sizeof(SCROLLINFO));
          si.cbSize = sizeof(SCROLLINFO);
          si.fMask = SIF_POS;

          GetScrollInfo(hWnd,SB_VERT,&si);
          iVertPos = si.nPos;
          GetScrollInfo(hWnd,SB_HORZ,&si);
          iHorzPos = si.nPos;

          iPaintBegin = max(0,iVertPos + ps.rcPaint.top / cyChar);
          iPaintEnd = min(NUMLINES - 1,iVertPos + ps.rcPaint.bottom / cyChar);

          for(i = iPaintBegin;i<=iPaintEnd;i++)
          {
              x = cxChar * ( 1 - iHorzPos);
              y = cyChar * (i - iVertPos);

              ZeroMemory(szRollBuffer,BUFFER_SIZE);
              iLength = snprintf(szRollBuffer,BUFFER_SIZE,TEXT("%d"),sysmets[i].iRollNumber);
              TextOut(hdc,x,y,szRollBuffer,iLength);
              TextOut(hdc,x + MAX_NAME_LEN * cxChar,y,sysmets[i].szName,lstrlen(sysmets[i].szName));
              ZeroMemory(szAttendance,BUFFER_SIZE);
              iLength = snprintf(szAttendance,BUFFER_SIZE,TEXT("%.1f"),sysmets[i].fAttendance);
              TextOut(hdc,x + MAX_NAME_LEN * cxChar + MAX_ATTENDANCE_LEN * cxCaps,y,szAttendance,iLength);
              TextOut(hdc,x + MAX_NAME_LEN * cxChar + MAX_CITY_LEN * cxChar + MAX_ATTENDANCE_LEN * cxCaps,y,sysmets[i].szCity,lstrlen(sysmets[i].szCity));

          }
          EndPaint(hWnd,&ps);
          break;

        case WM_DESTROY:
          PostQuitMessage(EXIT_SUCCESS);
          break;
    }
    return(DefWindowProc(hWnd,uMsg,wParam,lParam));

}