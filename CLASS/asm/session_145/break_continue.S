.section .rodata 
    msg_p1: 
    .string "arr[%d]==%d\n" 

    msg_p2: 
    .string "End of loop containing break"

    msg_end: 
    .string "End of program [ THROUGH ASSEMBLY ]"

.section .data 
    .globl arr 
    .type  arr, @object 
    .size  arr, 32 
    .align 4 
    arr: 
    .int    4, 7, 1, 5, 8, 10, 15, 11 

.section .bss 
    .comm   i, 4, 4 

.section .text 
.globl main 
.type   main, @function 

main: 
    pushl   %ebp 
    movl    %esp, %ebp 

    movl    $0, i 
    jmp     mn_cond1 
mn_for1: 
    movl    %eax, %esi  # save i in esi 
    movl    arr(, %eax, 4), %eax 
    movl    %eax, %ecx  # save arr[i] in ecx 
   
    movl    $5, %ebx 
    movl    $0, %edx 
    divl    %ebx 
    cmpl    $0, %edx 
    je      mn_out      # == break 

    pushl   %ecx    # ecx == arr[i]
    pushl   %esi    # esi == i 
    pushl   $msg_p1 
    call    printf 
    addl    $12, %esp 

    addl    $1, i 
mn_cond1: 
    movl    i, %eax 
    cmpl    $8, %eax 
    jl      mn_for1 

mn_out:     
    pushl   $msg_p2 
    call    puts 
    addl    $4, %esp 

    movl    $0, i 
    jmp     mn_cond2 
mn_for2: 
    movl    %eax, %esi  # save i in esi 
    movl    arr(, %eax, 4), %eax  
    movl    %eax, %ecx  # save arr[i] in ecx 
    movl    $5, %ebx 
    movl    $0, %edx 
    divl    %ebx 
    cmpl    $0, %edx 
    je      mn_incr     # je    mn_for2 (had it been while loop in C)

    pushl   %ecx 
    pushl   %esi 
    pushl   $msg_p1 
    call    printf 
    addl    $12, %esp 
mn_incr: 
    addl    $1, i 
mn_cond2: 
    movl    i, %eax 
    cmpl    $8, %eax 
    jl      mn_for2 

    pushl   $msg_end  
    call    puts 
    addl    $4, %esp 

    pushl   $0 
    call    exit 
