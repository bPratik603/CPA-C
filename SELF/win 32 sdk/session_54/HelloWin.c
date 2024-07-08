#include<Windows.h>

#pragma comment(lib, "kernel32.lib")
#pragma comment(lib, "user32.lib")
#pragma comment(lib, "gdi32.lib")

LRESULT CALLBACK WndProc(HWND hWnd,UINT uMsg,WPARAM wParam,LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nShowCmd)
{
  static TCHAR  szClassName[] = TEXT("The statndard Window");
  static TCHAR  szTitleOfWindow[] = TEXT("Hello Window");

  HWND hWnd = NULL;

  WNDCLASSEX wnd;
  MSG msg;

  ZeroMemory(&wnd,sizeof(WNDCLASSEX));
  ZeroMemory(&msg,sizeof(MSG));

  wnd.cbSize = sizeof(WNDCLASSEX);
  wnd.cbClsExtra  = 0;
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
    MessageBox(NULL, TEXT("Failed to Register Window"),
                     TEXT("RegiserClassEx"), MB_ICONERROR | MB_TOPMOST);
                ExitProcess(EXIT_FAILURE);
  }

  hWnd = CreateWindowEx(WS_EX_APPWINDOW,
                        szClassName,
                        szTitleOfWindow,
                        WS_OVERLAPPEDWINDOW,
                        CW_USEDEFAULT,
                        CW_USEDEFAULT,
                        CW_USEDEFAULT,
                        CW_USEDEFAULT,
                        NULL,
                        NULL,
                        hInstance,
                        NULL);

    if(hWnd == NULL)
    {
      MessageBox(NULL, TEXT("Failed to create window"), 
                        TEXT("CreateWindowEx"), MB_ICONERROR | MB_TOPMOST);
            ExitProcess(EXIT_FAILURE);
    }

    ShowWindow(hWnd,nShowCmd);
    UpdateWindow(hWnd);

    while(GetMessage(&msg,NULL,0,0))
    {
      TranslateMessage(&msg);
      DispatchMessage(&msg);
    }
    return(msg.wParam);
}

LRESULT CALLBACK WndProc(HWND hWnd,UINT uMsg,WPARAM wParam ,LPARAM lParam)
{
  static int cxClient;
  static int cyClient;
  static int iLen;
  static int iRollNumber = 12;

  HDC hdc;
  PAINTSTRUCT ps;

   static TCHAR szClgName[] = TEXT("Shivraj College");
   static TCHAR szStudentName[] = TEXT("Pratik Bhosale");

 switch(uMsg)
 {
    case WM_SIZE:
      cxClient = LOWORD(lParam);
      cyClient = HIWORD(lParam);
      break;

    case WM_PAINT:
      hdc = BeginPaint(hWnd,&ps);

      iLen = lstrlen(szClgName);
      SetTextAlign(hdc, TA_CENTER);
      TextOut(hdc,cxClient/2,cyClient/2,szClgName,iLen);
      iLen = lstrlen(szStudentName);
      TextOut(hdc,cxClient /4,cyClient / 4,szStudentName,iLen);
      TextOut(hdc,cxClient / 4 + 50,cyClient/4+ 50,szStudentName,iLen);
    EndPaint(hWnd,&ps);
     break;

      case WM_DESTROY:
         PostQuitMessage(EXIT_SUCCESS);
         break;
 }
 return(DefWindowProc(hWnd,uMsg,wParam,lParam));
     
     
}