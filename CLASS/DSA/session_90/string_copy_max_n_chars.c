#include <stdio.h> 
#include <stdlib.h> 

int main(void)
{
    int N = 30; 
    const char* src = "Core Programming Academy"; 
    char* dest = NULL; 
    int i; 
    /* 
        Danger in cpa_strcpy()? 
        src string not delimited by '\0' 

        So we introduce a limit in terms N. 
        Let N be some integer value. 

        We must keep on copying chars from src 
        string to dest string until 
        (i) We hit the end of src string 
        OR 
        (ii) Total number of copied chars become equal to N

        WHICHEVER IS EARLIER! 
    */

   dest = (char*)malloc(N); 
   if(dest == NULL)
   {
        puts("Error in allocating memory"); 
        exit(EXIT_FAILURE); 
   }

    /* 
        Start copying source string into destination string. 
        Note that you are allowed to copy at most N characters. 
        So stop either after copying N chars or after the end of 
        src string (whichever event occurs earlier)
    */

   i = 0; 
   while(src[i] != '\0' && i < N)
   {
        dest[i] = src[i]; 
        i = i + 1; 
   }

   dest[i] = '\0'; 

    printf("dest = %s\n", dest); 

    free(dest); 
    dest = NULL; 

    return (EXIT_SUCCESS); 
}
