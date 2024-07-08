#include <Windows.h> 

// misnomer 

void Test_1(void)
{
    LRESULT x1; 
    LONG_PTR x2; 
    long long x3; 
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam); 

long long CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam); 

void Test_2(void)
{
    HWND x1; 
    struct HWND__* x2; 
}

long long CALLBACK WndProc(struct HWND__* hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam); 

long long CALLBACK WndProc(struct HWND__* hwnd, unsigned int uMsg, WPARAM wParam, LPARAM lParam);

void Test_3(void)
{
    WPARAM x1; 
    UINT_PTR x2; 
    unsigned long long x3;

    LONG_PTR lParam; 
    long long x4;

}

long long CALLBACK WndProc(struct HWND__* hwnd, unsigned int uMsg, unsigned long long wParam, 
                            long long lParam); 


long long __stdcall WndProc(struct HWND__* hwnd, unsigned int uMsg, unsigned long long wParam, 
                            long long lParam); 

LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam); 

