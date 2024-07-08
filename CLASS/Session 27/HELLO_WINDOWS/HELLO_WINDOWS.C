/*
 @NAME: PRATIK BHOSALE
 @DATE: 27-11-2022
 @GOAL: TO DISPALY GREETINGS MESSAGEBOX
*/

#include<windows.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR IpCmdline, int nShowCmd)
{
	MessageBox(NULL, TEXT("Greetings!"), TEXT("Masterclass in C Batch 3!"), MB_OK);
	return(0);
}