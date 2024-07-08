#include <Windows.h> 

#pragma comment(lib, "user32.lib")
#pragma comment(lib, "gdi32.lib")
#pragma comment(lib, "kernel32.lib")

#define NUMLINES ((int) (sizeof(devcaps) / sizeof (devcaps [0])))

struct
{
     int     iIndex ;
     TCHAR * szLabel ;
     TCHAR * szDesc ;
}
devcaps [] =
{
     HORZSIZE,      TEXT ("HORZSIZE"),     TEXT ("Width in millimeters:"),
     VERTSIZE,      TEXT ("VERTSIZE"),     TEXT ("Height in millimeters:"),
     HORZRES,       TEXT ("HORZRES"),      TEXT ("Width in pixels:"),
     VERTRES,       TEXT ("VERTRES"),      TEXT ("Height in raster lines:"),
     BITSPIXEL,     TEXT ("BITSPIXEL"),    TEXT ("Color bits per pixel:"),
     PLANES,        TEXT ("PLANES"),       TEXT ("Number of color planes:"),
     NUMBRUSHES,    TEXT ("NUMBRUSHES"),   TEXT ("Number of device brushes:"),
     NUMPENS,       TEXT ("NUMPENS"),      TEXT ("Number of device pens:"),
     NUMMARKERS,    TEXT ("NUMMARKERS"),   TEXT ("Number of device markers:"),
     NUMFONTS,      TEXT ("NUMFONTS"),     TEXT ("Number of device fonts:"),
     NUMCOLORS,     TEXT ("NUMCOLORS"),    TEXT ("Number of device colors:"),
     PDEVICESIZE,   TEXT ("PDEVICESIZE"),  TEXT ("Size of device structure:"),
     ASPECTX,       TEXT ("ASPECTX"),      TEXT ("Relative width of pixel:"),
     ASPECTY,       TEXT ("ASPECTY"),      TEXT ("Relative height of pixel:"),
     ASPECTXY,      TEXT ("ASPECTXY"),     TEXT ("Relative diagonal of pixel:"),
     LOGPIXELSX,    TEXT ("LOGPIXELSX"),   TEXT ("Horizontal dots per inch:"),
     LOGPIXELSY,    TEXT ("LOGPIXELSY"),   TEXT ("Vertical dots per inch:"),
     SIZEPALETTE,   TEXT ("SIZEPALETTE"),  TEXT ("Number of palette entries:"),
     NUMRESERVED,   TEXT ("NUMRESERVED"),  TEXT ("Reserved palette entries:"),
     COLORRES,      TEXT ("COLORRES"),     TEXT ("Actual color resolution:")
};

LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam); 

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
     static TCHAR szClassName[] = TEXT("The Standard Window"); 
     static TCHAR szWindowName[] = TEXT("VIDEO DISPLAY DEVICE CAPABILITIES"); 
     HWND hwnd = NULL; 
     WNDCLASSEX wnd; 
     MSG msg; 

     ZeroMemory(&wnd, sizeof(WNDCLASSEX)); 
     ZeroMemory(&msg, sizeof(MSG)); 

     wnd.cbSize = sizeof(WNDCLASSEX); 
     wnd.cbClsExtra = 0; 
     wnd.cbWndExtra = 0; 
     wnd.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH); 
     wnd.hCursor = LoadCursor(NULL, IDC_ARROW); 
     wnd.hIcon = LoadIcon(NULL, IDI_APPLICATION); 
     wnd.hIconSm = LoadIcon(NULL, IDI_APPLICATION); 
     wnd.hInstance = hInstance; 
     wnd.lpfnWndProc = WndProc; 
     wnd.lpszClassName = szClassName; 
     wnd.lpszMenuName = NULL; 
     wnd.style = CS_HREDRAW | CS_VREDRAW; 

     if(!RegisterClassEx(&wnd))
     {
          MessageBox(NULL, TEXT("Error in registering a window class"), 
                         TEXT("RegisterClassEx"), MB_ICONERROR | MB_TOPMOST);
          ExitProcess(EXIT_FAILURE);  
     }

     hwnd = CreateWindowEx(
               WS_EX_APPWINDOW, 
               szClassName, 
               szWindowName, 
               WS_OVERLAPPEDWINDOW, 
               CW_USEDEFAULT, 
               CW_USEDEFAULT, 
               CW_USEDEFAULT, 
               CW_USEDEFAULT, 
               NULL, 
               NULL, 
               hInstance, 
               NULL
          );

     if(hwnd == NULL)
     {
          MessageBox(NULL, TEXT("Error in creating a window"), TEXT("CreateWindowEx"), 
               MB_ICONERROR | MB_TOPMOST); 
          ExitProcess(EXIT_FAILURE); 
     }

     ShowWindow(hwnd, nShowCmd); 
     UpdateWindow(hwnd); 

     while(GetMessage(&msg, NULL, 0, 0))
     {
          TranslateMessage(&msg); 
          DispatchMessage(&msg); 
     }

     return (msg.wParam); 
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
     #define NR_MAX_DESC_LEN  14 
     #define NR_MAX_LABEL_LEN 35
     #define DEVCAP_BUFFER_LEN 16

     static int cxChar, cyChar, cxCaps; 
     static TCHAR szBuffer[DEVCAP_BUFFER_LEN];
     int i, iDevcapstrLen; 
     PAINTSTRUCT ps; 
     TEXTMETRIC tm; 
     HDC hdc; 

     switch(uMsg)
     {
          case WM_CREATE: 
               hdc = GetDC(hwnd); 
               GetTextMetrics(hdc, &tm); 
               cxChar = tm.tmAveCharWidth; 
               cyChar = tm.tmHeight + tm.tmExternalLeading; 
               cxCaps = (tm.tmPitchAndFamily & 1 ? 3 : 2) * cxChar/2; 
               ReleaseDC(hwnd, hdc); 
               break; 

          case WM_PAINT: 
               hdc = BeginPaint(hwnd, &ps); 
               for(i = 0; i < NUMLINES; ++i)
               {
                    TextOut(
                         hdc, 
                         0, 
                         i * cyChar, 
                         devcaps[i].szLabel, 
                         lstrlen(devcaps[i].szLabel)
                    ); 

                    TextOut(
                         hdc, 
                         NR_MAX_DESC_LEN * cxCaps, 
                         i * cyChar, 
                         devcaps[i].szDesc, 
                         lstrlen(devcaps[i].szDesc)
                    ); 

                    SetTextAlign(hdc, TA_RIGHT | TA_TOP); 
                    ZeroMemory(szBuffer, DEVCAP_BUFFER_LEN); 
                    iDevcapstrLen = wsprintf(                       
                                        szBuffer,       
                                        TEXT("%5d"), 
                                        GetDeviceCaps(hdc, devcaps[i].iIndex) 
                                   ); //int to string conversion ,string stored in szBuffer it return to iDevcapstrlen
                    TextOut(
                         hdc, 
                         NR_MAX_DESC_LEN * cxCaps + NR_MAX_LABEL_LEN * cxChar, 
                         i * cyChar, 
                         szBuffer, 
                         iDevcapstrLen
                    ); 
                    SetTextAlign(hdc, TA_LEFT | TA_TOP); 
               }
               EndPaint(hwnd, &ps); 
               break; 

          case WM_DESTROY: 
               PostQuitMessage(EXIT_SUCCESS); 
               break; 
     }

     return (DefWindowProc(hwnd, uMsg, wParam, lParam)); 
}