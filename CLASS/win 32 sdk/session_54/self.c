#include<Windows.h>

#pragma comment(lib, "kernel32.lib")
#pragma comment(lib, "gdi32.lib")
#pragma comment(lib, "user32.lib")

LRESULT CALLBACK WndProc(HINSTANCE hInstance,HINSTANCE hPrevInstance,WPARAM wPram,LPARAM lParam);

int WINAPI WinMain(HWND hWnd,UINT uMsg,LPSTR lpCmdLine,int nShowCmd)
{
    TCHAR szClassName[] = TEXT("The Standard Window");
    TCHAR szTitleOfWindow[] = TEXT("Hello Window");

    HWND hWnd = NULL;

    WNDCLASSEX wnd;
    MSG msg;

    ZeroMemory(&wnd,sizeof(WNDCLASSEX));
    ZeroMemory(&msg,sizeof(MSG));

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
    wnd.style = CS_VREDRAW | CS_HREDRAW;

    if(!RegisterClassEx(&wnd))
    {
        MessageBox(NULL, TEXT("Failed to Register Window"),TEXT("RegisterClassEx"),MB_ICONERROR | MB_TOPMOST);
        ExitProcess(EXIT_FAILURE);
    }

    hWnd = CreateWindowEx(WS_EX_APPWINDOW,
                          szClassName,
                          szTitleOfWindow,
                          WS_OVERLAPPEDWINDOW | WS_HSCROLL | WS_VSCROLL,
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
        MessageBox(NULL, TEXT("Failed to Create window"),TEXT("CreateWindowEx"),MB_ICONERROR | MB_TOPMOST);
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

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg,WPARAM wParam,LPARAM lParam)
{
     static TCHAR szName[] = TEXT("Pratik Bhosale  MSTC 3   CorePrograminAcadmy");
     static int len;

     static int cxClient;
     static int cyClient;
     static int iRollNumber = 12;

     HDC hdc;
     PAINTSTRUCT ps;

     switch(uMsg)
     {
        case WM_SIZE:
           cxClient = HIWORD(lParam);
           cyClient = LOWORD(lParam);
           break;

        case WM_PAINT:
          hdc = GetDc(hWnd,&ps);

          len = lstrlen(szName);
          SetTextAlign(hdc,TA_CENTER);
          TextOut(hdc,cxClient/2,cyClient/2,szName,len);
          EndPaint(hWnd,&ps);
          break;

        case WM_DESTROY:
          PostQuitMessage(EXIT_SUCCESS);
          break;
     }

     return(DefWindowProc(hWnd,uMsg,wParam,lParam));

}