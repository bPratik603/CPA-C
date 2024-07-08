#include<Windows.h>
#pragma comment(lib,"user32.lib")
#pragma comment(lib,"gdi32.lib")
#pragma comment(lib,"kernel32.lib")


LRESULT CALLBACK WndProc(HWND hWnd,UINT uMsg,WPARAM wParam,LPARAM lParam);
VOID GetHFont(HFONT *pHfont,PSTR faceName);

int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nShowCmd)
{
	static TCHAR szClassName[]=TEXT("The Standard Window");
	static TCHAR szTitleOfWindow[]=TEXT("CPA Font Toggle");

	WNDCLASSEX wnd;
	MSG msg;

	HWND hWnd;

	ZeroMemory(&wnd,sizeof(WNDCLASSEX));
	ZeroMemory(&msg,sizeof(MSG));

	wnd.cbSize=sizeof(WNDCLASSEX);
	wnd.cbClsExtra=0;
	wnd.cbWndExtra=0;
	wnd.hbrBackground=(HBRUSH)GetStockObject(WHITE_BRUSH);
	wnd.hCursor=LoadCursor(NULL, IDC_ARROW);
	wnd.hIcon=LoadIcon(NULL, IDI_APPLICATION);
	wnd.hIconSm=LoadIcon(NULL, IDI_APPLICATION);
	wnd.hInstance=hInstance;
	wnd.lpfnWndProc=WndProc;
	wnd.lpszClassName=szClassName;
	wnd.lpszMenuName=NULL;
	wnd.style=CS_HREDRAW | CS_VREDRAW;

	if(!RegisterClassEx(&wnd))
	{
		MessageBox(NULL,
			TEXT("Error in Registering Window"),
			TEXT("RegisterClassEx"),
			MB_ICONERROR|MB_TOPMOST);
		ExitProcess(EXIT_FAILURE);
	}

	hWnd=CreateWindowEx(
		WS_EX_APPWINDOW,
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
	if(NULL == hWnd)
	{
		MessageBox(NULL,
			TEXT("Error in creating Window"),
			TEXT("CreateWindowEx"),
			MB_ICONERROR|MB_TOPMOST);
		ExitProcess(EXIT_FAILURE);
	}

	ShowWindow(hWnd,nShowCmd);
	UpdateWindow(hWnd);

	while(GetMessage(&msg,NULL,0,0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return (msg.wParam);
}

LRESULT CALLBACK WndProc(HWND hWnd,UINT uMsg,WPARAM wParam,LPARAM lParam)
{
	#define TOTALFONTS 7
	#define TOTALCOLORS 4
	static HFONT hfonts[TOTALFONTS];
	static COLORREF colors[TOTALCOLORS]={
		0x00000000,
		0x000000ff,
		0x0000ff00,
		0x00ff0000,
	};
	static TCHAR *szPrompt[3]={
		TEXT("Core   Code   Programming   Academy"),
		TEXT("Font   Toggle"),
		TEXT("BY   VIVEK   RAUT")
	};
	static int cxScreen,cyScreen;
	int cxChar,cyChar,cxCaps;
	static int hFontIdx=0,colorIdx=0;
	int i=0;

	PAINTSTRUCT ps;
	HDC hdc;
	TEXTMETRIC tm;

	switch(uMsg)
	{
	case WM_CREATE:
		GetHFont(&hfonts[0],TEXT("Times New Roman"));
		GetHFont(&hfonts[1],TEXT("Impact"));
		GetHFont(&hfonts[2],TEXT("Courier"));
		GetHFont(&hfonts[3],TEXT("Arial"));
		GetHFont(&hfonts[4],TEXT("Calibri"));
		GetHFont(&hfonts[5],TEXT("Georgia"));
		GetHFont(&hfonts[6],TEXT("Century Gothic"));
		return(0);
	case WM_SIZE:
		cxScreen=LOWORD(lParam);
		cyScreen=HIWORD(lParam);
		return(0);
	case WM_PAINT:
		hdc=BeginPaint(hWnd,&ps);
		SelectObject(hdc,hfonts[hFontIdx]);
		GetTextMetrics(hdc,&tm);
		cxChar=tm.tmAveCharWidth;
		cyChar=tm.tmHeight+tm.tmExternalLeading+5;
		cxCaps=(tm.tmPitchAndFamily&1?3:2)*(cxChar/2);
		SetTextAlign(hdc,TA_CENTER);
		SetTextColor(hdc,colors[colorIdx]);
		SetTextCharacterExtra(hdc,5);
		TextOut(hdc,cxScreen/2,cyScreen/4,szPrompt[0],lstrlen(szPrompt[0]));
		TextOut(hdc,cxScreen/2,(cyScreen/4)+cyChar,szPrompt[1],lstrlen(szPrompt[1]));
		TextOut(hdc,cxScreen/2,(cyScreen/4)+2*cyChar,szPrompt[2],lstrlen(szPrompt[2]));
		EndPaint(hWnd,&ps);
		return(0);
	case WM_KEYDOWN:
		switch(wParam)
		{
		 	case VK_UP:
				hFontIdx=max(0,min(hFontIdx+1,TOTALFONTS-1));
				InvalidateRect(hWnd,NULL,TRUE);
				return(0);
		 	case VK_DOWN:
				hFontIdx=max(0,min(hFontIdx-1,TOTALFONTS-1));
				InvalidateRect(hWnd,NULL,TRUE);
				return(0);
			case VK_RIGHT:
				colorIdx=max(0,min(colorIdx+1,TOTALCOLORS-1));
				InvalidateRect(hWnd,NULL,TRUE);
				return(0);
			case VK_LEFT:
				colorIdx=max(0,min(colorIdx-1,TOTALCOLORS-1));
				InvalidateRect(hWnd,NULL,TRUE);
				return(0);
		}
		break;
	case WM_DESTROY:
		for(i=0;i<TOTALFONTS;++i)
			DeleteObject(hfonts[i]);
		PostQuitMessage(0);
		return(0);
	}

	return (DefWindowProc(hWnd,uMsg,wParam,lParam));
}

VOID GetHFont(HFONT *pHfont,PSTR FaceName)
{
	HFONT hfont=CreateFont(32,
			0,
			0,
			0,
			FW_DONTCARE,
			FALSE,
			FALSE,
			FALSE,
			DEFAULT_CHARSET,
			OUT_DEFAULT_PRECIS,
			CLIP_DEFAULT_PRECIS,
			DEFAULT_QUALITY,
			DEFAULT_PITCH | FF_DONTCARE,
			FaceName);
	*pHfont=hfont;
}