.section .rodata 
	msg_p1: 
	.string	"Enter size of array:" 

	msg_p2: 
	.string	"*(p + %d) == %d\n" 
	
	msg_s1: 
	.string	"%d" 

	msg_err_1: 
	.string	"Bad size for array" 

	msg_err_2: 
	.string	"Error in allocating memory" 

	msg_end: 
	.string	"End of Program. Through Assembly" 

.section .text 
.globl 	main 
.type 	main, @function 

main: 
	pushl	%ebp 
	movl 	%esp, %ebp 
	subl 	$12, %esp 

	pushl	$msg_p1 
	call	printf
	addl	$4, %esp 

	leal	-8(%ebp), %eax 
	pushl	%eax 
	pushl	$msg_s1 
	call	scanf 
	addl	$8, %esp 

	movl 	-8(%ebp), %eax 
	cmpl	$0, %eax 
	jle 	mn_array_size_error 

	movl 	-8(%ebp), %eax 
	movl	$4, %ebx 
	movl	$0, %edx 
	mull	%ebx 
	
	pushl	%eax 
	call	malloc 
	addl	$4, %esp 
	cmpl	$0, %eax 
	je 		mn_memory_allocation_error 
	movl	%eax, -4(%ebp) 

	movl	$0, -12(%ebp) 
	jmp		mn_cond_1 
mn_for_1: 
	addl	$1, %eax 
	movl 	$100, %ebx 
	movl	$0, %edx 
	mull	%ebx 
	movl	%eax, %edx 
	movl 	-12(%ebp), %eax 
	movl 	-4(%ebp), %ebx 
	movl	%edx, (%ebx, %eax, 4)

	addl	$1, -12(%ebp) 
mn_cond_1: 
	movl	-12(%ebp), %eax 
	cmpl	-8(%ebp), %eax 
	jl 		mn_for_1
	

	movl 	$0, -12(%ebp) 
	jmp		mn_cond_2 
mn_for_2: 
	movl	-4(%ebp), %ebx 
	movl	(%ebx, %eax, 4), %edx 
	pushl	%edx 
	pushl	%eax 
	pushl	$msg_p2 
	call	printf
	addl	$12, %esp 

	addl	$1, -12(%ebp) 
mn_cond_2: 
	movl	-12(%ebp), %eax 
	cmpl	-8(%ebp), %eax 
	jl 		mn_for_2 
	
	movl 	-4(%ebp), %eax 
	pushl	%eax 
	call	free 
	addl	$4, %esp 
	movl 	$0, -4(%ebp) 

	pushl	$msg_end 
	call	puts 
	addl	$4, %esp 

	jmp		mn_exit_with_success 

mn_array_size_error: 
	pushl	$msg_err_1 
	call	puts 
	addl	$4, %esp 
	jmp		mn_exit_with_failure 

mn_memory_allocation_error: 
	pushl	$msg_err_2 
	call	puts 
	addl	$4, %esp 
	jmp		mn_exit_with_failure

mn_exit_with_failure: 
	pushl	$-1 
	call	exit 

mn_exit_with_success: 
	pushl	$0 
	call	exit 

# leal (%r1), %r2 
# leal n(%r1), %r2 
# leal v_name(%r1, %r2, c), %r3 
# leal v_name(, %r2, c), %r3 

