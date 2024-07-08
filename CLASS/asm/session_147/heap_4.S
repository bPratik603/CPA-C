.equ    CAP, 50     #   #define CAP 50 
.section .rodata 
	msg_err_1: 
	.string	"Error in allocating memory for structure" 

	msg_err_2: 
	.string	"Bad size of array" 

	msg_err_3: 
	.string	"Error in allocating memory for array" 

	msg_p1: 
	.string	"Enter sizeof array:" 

	msg_p2: 
	.string	"psa->p_arr[%d]:%d\n", 

	msg_p3: 
	.string	"Sum = %d\n"
	
	msg_s1: 
	.string	"%d" 

	asm_proof:
	.string	"End of program [THROUGH ASSEMBLY]" 

.section .text 
.globl  main 
.type   main, @function 

main: 
    pushl   %ebp 
    movl    %esp, %ebp
    # two local variables are allocated 
    # local variable 1: struct sum_of_array* psa: Offset: -4
    # local variable 2: int i: offset: -8 
    subl    $8, %esp 
    
    pushl   $12     # sizeof(struct sum_of_array) == 12 
    call    malloc 
    addl    $4, %esp 
    cmpl    $0, %eax 
    je      mn_struct_memory_allocation_error 
    movl    %eax, -4(%ebp) # psa = malloc(sizeof(struct)) done
    
    pushl   $msg_p1 
    call    printf
    addl    $4, %esp 
    
    movl    -4(%ebp), %eax  # eax <- psa 
    leal    4(%eax), %edx   # edx <- &psa->N 
    
    pushl   %edx    # &psa->N on stack 
    pushl   $msg_s1 
    call    scanf 
    addl    $8, %esp 
    
    movl    -4(%ebp), %eax  # eax <- psa 
    movl    4(%eax), %edx   # edx <- psa->N 
    cmpl    $0, %edx 
    jle     mn_bad_array_size_error 
    
    pushl   $4      # sizeof(int) on stack 
    pushl   %edx    # psa->N on stack 
    call    calloc  
    cmpl    $0, %eax 
    je      mn_array_memory_allocation_error 
    
    movl    -4(%ebp), %ebx  # ebx <- psa  
    movl    %eax, (%ebx)    # psa->p_arr <- calloc() 
    
    pushl   $0  
    call    time 
    addl    $4, %esp  
    # eax == time(0)
    pushl   %eax     
    call    srand 
    addl    $4, %esp 
    
    movl    $0, -8(%ebp)    # i <- 0 
    jmp     mn_cond_1 
mn_for_1: 
    call    rand        # eax == random number return by rand() 
    movl    $CAP, %ebx  # ebx == 50 == $CAP 
    movl    $0, %edx    
    divl    %ebx        # edx == remainder, eax == quotient 
    
    movl    -4(%ebp), %ebx  # ebx == psa == base addr of structure instance 
    movl    (%ebx), %ebx    # ebx == psa->p_arr 
    movl    -8(%ebp), %eax  # eax == i 
    movl    %edx, (%ebx, %eax, 4) # psa->p_arr[i] = rand() % CAP 
                                  # edx == rand() % CAP 
                                  # ebx == psa->parr 
	addl	$1, -8(%ebp) 
mn_cond_1: 
    movl    -4(%ebp), %ebx  # ebx == psa  
    movl    4(%ebx),  %edx  # edx == psa->N 
    movl    -8(%ebp), %eax  # eax == i 
    cmpl    %edx, %eax 
    jl      mn_for_1 

    movl    -4(%ebp), %ebx 
    movl    $0, 8(%ebx) 
    
    movl    $0, -8(%ebp) 
    jmp     mn_cond_2
mn_for_2: 
    movl    -4(%ebp), %ebx  # ebx == psa 
    movl    (%ebx), %ebx    # ebx == psa->p_arr 
    movl    -8(%ebp), %eax  # eax == i 
    movl    (%ebx, %eax, 4), %edx # edx == psa->p_arr[i] 
	movl	-4(%ebp), %ebx 
    movl    8(%ebx), %ecx   # ecx == psa->sum 
    addl    %ecx, %edx      # edx == psa->sum + psa->p_arr[i] 
    movl    %edx, 8(%ebx)   # psa->sum <- edx == (psa->sum+psa->p_arr[i]) 
    addl    $1, -8(%ebp) 
mn_cond_2: 
    movl    -4(%ebp), %ebx  # ebx == psa 
    movl    4(%ebx), %edx   # edx == psa->N 
    movl    -8(%ebp), %eax  # eax == i 
    cmpl    %edx, %eax 
    jl      mn_for_2
    
	movl 	$0, -8(%ebp) 	# i == 0 
	jmp 	mn_cond_3 
mn_for_3: 
	movl 	(%ebx), %ebx 	# ebx == psa->p_arr 
	movl 	(%ebx, %eax, 4), %edx 	# edx == psa->p_arr[i] 
	pushl	%edx 
	pushl	%eax 
	pushl	$msg_p2 
	call	printf
	addl	$12, %esp 

	addl	$1, -8(%ebp) 
mn_cond_3: 
	movl 	-4(%ebp), %ebx 	# ebx == psa 
	movl 	4(%ebx), %edx 	# edx == psa->N 
	movl	-8(%ebp), %eax 	# eax == i 
	cmpl	%edx, %eax 		# i is compared with psa->N 
	jl 		mn_for_3 

	movl	-4(%ebp), %ebx 	# ebx == psa 
	movl 	8(%ebx), %edx 	# edx == psa->sum 
	pushl	%edx 
	pushl	$msg_p3 
	call	printf
	addl	$12, %esp 

	movl 	(%ebx), %ebx 	# ebx == psa->p_arr 
	pushl	%ebx 
	call	free 
	addl	$4, %esp 

	movl 	-4(%ebp), %ebx 	# ebx == psa 
	pushl	%ebx 
	call	free 
	addl	$4, %esp 

	movl	$0, -4(%ebp) 
	
	pushl	$asm_proof 
	call	puts 
	addl	$4, %esp 

    jmp         mn_exit_with_success 
mn_struct_memory_allocation_error: 
    pushl   $msg_err_1 
    call    puts 
    addl    $4, %esp 
    jmp     mn_exit_with_failure
    
mn_bad_array_size_error: 
    pushl   $msg_err_2 
    call    puts 
    addl    $4, %esp 
    jmp     mn_exit_with_failure 
    
mn_array_memory_allocation_error: 
    pushl   $msg_err_3 
    call    puts 
    addl    $4, %esp 
    jmp     mn_exit_with_failure 
    
mn_exit_with_failure: 
    pushl   $-1 
    call    exit 
    
mn_exit_with_success: 
    pushl   $0 
    call    exit 
    
