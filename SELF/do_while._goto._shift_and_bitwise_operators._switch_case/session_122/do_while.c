#include <stdio.h> 
#include <stdlib.h> 

int main(void){
    
    do{

    }while(COND); 
}

#define MACRO(PARAMS)   do{\
                        Line 1 \
                        Line 2 \
                        Line 3 \

                        .....\

                        Line n\
                    }while(0)


int main(void)
{
    MACRO(PARAMS);
    == 
     do{\
                        Line 1 \
                        Line 2 \
                        Line 3 \

                        .....\

                        Line n\
                    }while(0); 
}