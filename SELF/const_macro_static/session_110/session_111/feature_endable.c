#include <stdio.h> 
#include <stdlib.h> 

/* File system code: 
    JOURNALING 
    BACKUP 
*/

#ifdef FS_JOURNALLED

void jrnl_1(void)
{

}

void jrnl_2(void)
{

}

void jrnl_3(void)
{

}

#endif 

#ifdef FS_BACKUP 
void bkp_1(void)
{

}

void bkp_2(void)
{

}

void bkp_3(void)
{

}

#endif 

/* 
    ./configure --target=arm64 
    Linux Kernel in Nutshell. 
    
   
*/