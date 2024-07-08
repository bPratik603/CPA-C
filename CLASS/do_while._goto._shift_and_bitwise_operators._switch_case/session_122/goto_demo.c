#include <stdio.h> 
#include <stdlib.h> 

void test_1(void); 
void test_2(void); 

int main(void)
{
    test_1(); 
    test_2(); 
    return (0); 
}

void test_1(void)
{
    int i, j, k; 

    for(i = 0; i < 100; ++i)
    {
        for(j = 0; j < 100; ++j)
        {
            for(k = 0; k < 100; ++k)
            {
                if(COND)
                    break; 
            }
        }
    }
    #define TRUE 1 
    #define FALSE 0 
    int flag_total_out = FALSE; 

    for(i = 0; i < 100; ++i)
    {
        for(j = 0; j < 100; ++j)
        {
            for(k = 0; k < 100; ++k)
            {
                if(COND)
                {
                    flag_total_out = TRUE; 
                    break;
                } 
            }
            if(flag_total_out == TRUE)
            {
                break; 
            }
        }
        if(flag_total_out == TRUE)
            break; 
    }

    for(i = 0; i < 100; ++i)
    {
        for(j = 0; j < 100; ++j)
        {
            for(k = 0; k < 100; ++k)
            {
                if(COND)
                    goto out; 
            }
        }
    }

    out: 
        // C code 

}

void test_2(void)
{
    for(i = 0; i < N1; ++i)
        for(j = 0; j < N2; ++j)
        {
            if(cond)
            {
                goto err_2; 

                if(cond2)
                    goto err_5; 
            }
        }


    err_1: 
        HANDLER 
        goto out; 
    err_2: 
        HANDLER 
        goto out; 
    err_3:
        HANDLER 
        goto out; 

    err_N: 
        HANDLER: 
        goto out; 
    out: 
        SOME CODE  
}   
