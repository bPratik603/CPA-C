#include <stdio.h> 
#include <stdlib.h> 

int main(void){
    int n; 

    printf("Enter n[1-5]:"); 
    scanf("%d", &n); 

    switch(n)
    {
        case 1: 
            puts("Entered 1"); 
            break; 

        case 2: 
            puts("Entered 2"); 
            break; 

        case 3: 
            puts("Entered 3"); 
            break; 

        case 4: 
            puts("Entered 4"); 
            L: 
                // some code 
                goto L1; 
            break; 

        case 5: 
            puts("Entered 5"); 
            goto L; 
        L1: 

            break; 

        default: 
            puts("n is out of range. Range[1-5]"); 
    }

    return (0); 
}

/* 
    if(n == 1){

    }else if(n == 2){

    }else if(n == 3){

    }else if(n == 4){

    }else if(n == 5){

    }else{

    }

*/

/* 
    PRECONDITION FOR USING SWITCH TABLE TECHNIQUE
        1) Total number of cases > 5 
        (limit 5 is compiler specific. It is not standardized by 
        C language. Some compiler may require fewer or more cases 
        to use switch table technique)

        2) integer expressions after case statement ARE CONTIGUOUS
        and SORTED IN INCREASING ORDER.  
*/

/* 
    switch(n){
        case 0: 
                break; 
        case 1: 
                break; 
        case 2: 
                break; 


        case 6: 
                break; 
        
    }

    switch_table: 
    .long   case0_addr, ...., case6_addr 

    jmp switch_table[n]

        switch(n){
        case 7: 
                break; 
        case 8: 
                break; 
        case 9: 
                break; 
        .
        .
        .
        case 13: 
                break; 
        
    }

    switch_table: 
    .long   case7_addr, ..., case13_addr

    movl    n, %eax 
    subl    $7, %eax 
    7 <= eax <= 13 

    jmp     switch_table[eax]

##############################################

.section .data 
    .globl  main_switch_1 
    .type   main_switch_1, @object 
    .size   main_switch_1, 28 
    .align  5 
    main_switch_1:
    .long   L0, L1, L2, L3, L4, L5, L6

    movl    n, %eax 
    cmpl    $0, %eax 
    jl      default 
    cmpl    $6, %eax 
    jg      default 

    movl    main_switch_1(, %eax, 4), %edx 
    jmp     *%edx 

    call    *%eax


L0: 
    # case 0 handler instruction 
    jmp     out     # break translation 

L1: 
    # case 1 handler instruction 
    jmp     out 

L2: 
.
.
.
L6: 
    #case 6 handler instructions 
    jmp out 

default: 
    # default handler instructions 

out: 
*/