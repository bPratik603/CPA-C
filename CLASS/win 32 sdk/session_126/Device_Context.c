#include <Windows.h> 

LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    HDC hdc; 

    switch(uMsg)
    {
        case WM_CREATE: 
            hdc = GetDC(hwnd); 

            ReleaseDC(hwnd, hdc);         
            break; 
    }
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    HDC hdc; 

    switch(uMsg)
    {
        case WM_CREATE: 
            hdc = GetDC(hwnd); 

            ReleaseDC(hwnd, hdc); 

            break; 
    }
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    HDC hdc = NULL; 

    switch(uMsg)
    {
        case WM_CREATE: 
            hdc = GetDC(hwnd); 
            ReleaseDC(hwnd, hdc); 
            break; 
    }
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    HDC hdc; 
    PAINTSTRUCT ps; 

    switch(uMsg)
    {
        case WM_PAINT: 
            hdc = BeginPaint(hwnd, &ps); 

            EndPaint(hwnd, &ps); 
            break;     
    }
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    HDC hdc; 
    PAINTSTRUCT ps; 

    switch(uMsg)
    {
        case WM_PAINT: 
            hdc = BeginPaint(hwnd, &ps); 

            EndPaint(hwnd, &ps); 
            break; 
    }
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    HDC hdc; 
    PAINTSTRUCT ps; 

    switch(uMsg)
    {
        case WM_PAINT: 
            hdc = BeginPaint(hwnd, &ps); 
            EndPaint(hwnd, &ps); 
            break;
    }
}

