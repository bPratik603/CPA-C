.section .rodata 
	msg_err_1: 
	.string	"Error in allocating memory" 

	msg_p1: 
	.string	"pA->m = %d, pA->c = %c, pA->n = %d\n" 

	proof_str:	
	.string	"End of program THROUGH ASSMEBLY" 

.section .text 
.globl	main 
.type 	main, @function 
main: 
	pushl	%ebp 
	movl	%esp, %ebp 
	subl	$4, %esp 	# allocate memory for struct A* pA; 

	pushl	$12 		# sizeof(struct A) == 12 bytes 
	call	malloc 
	cmpl	$0, %eax 
	je 		mn_memory_allocation_error 

	movl	%eax, -4(%ebp) 

	movl	$100, (%eax) 	# pA->m = 100 
	movl	$0, 4(%eax) 	# storage of member 'c' and padded bytes 
							# are initialized to zero 
	movb	$'A', 4(%eax) 	# storage of member 'c' is assigned to 
							# ascii code of 'A', padded bytes remain
							# zero 
	movl	$200, 8(%eax) 

	movl	(%eax), %ebx 	# ebx == pA->m 
	movl	$0, %ecx 
	movb 	4(%eax), %cl 	# cl == pA->c 
	movl 	8(%eax), %edx 	# edx == pA->n 

	pushl	%edx 
	pushl	%ecx 
	pushl	%ebx 
	pushl	$msg_p1
	call	printf
	addl	$12, %esp 

	movl	-4(%ebp), %eax 
	pushl	%eax 
	call	free 
	addl	$4, %esp 
	movl	$0, -4(%ebp) 

	pushl	$proof_str 
	call	puts 
	addl	$4, %esp 

	jmp		mn_exit_with_success
		
mn_memory_allocation_error: 
	pushl	$msg_err_1 
	call	puts 
	addl	$4, %esp 
	jmp		mn_exit_with_failure 

mn_exit_with_failure: 
	pushl	$-1 
	call	exit 

mn_exit_with_success: 
	pushl	$0 
	call	exit 
