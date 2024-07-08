.section .rodata 
	msg_err_1: 
	.string	"Error in allocating memory" 

	msg_p1: 
	.string	"*p = %d\n" 

.section .text 
.globl	main 
.type main, @function 

main: 
	pushl	%ebp 
	movl	%esp, %ebp 
	subl	$4, %esp 

	pushl	$4 
	call	malloc 
	addl	$4, %esp 
	cmpl	$0, %eax 
	je 		main_memory_allocation_error 
	
	movl 	%eax, -4(%ebp) 

	movl	-4(%ebp), %eax 
	movl	$500, (%eax) 

	movl	-4(%ebp), %eax 
	movl	(%eax), %edx 

	pushl	%edx 
	pushl	$msg_p1 
	call	printf
	addl	$8, %esp 

	movl	-4(%ebp), %eax 
	pushl	%eax 
	call	free 
	addl	$4, %esp 

	movl	$0, -4(%ebp) 
	jmp		main_exit_with_success 

main_memory_allocation_error: 
	pushl	$msg_err_1 
	call	puts
	addl	$4, %esp

	pushl	$-1
	call	exit 

main_exit_with_success: 
	pushl	$0 
	call	exit 

