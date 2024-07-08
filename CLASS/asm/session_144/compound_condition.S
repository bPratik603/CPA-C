.section .rodata 
	msg_a: 
	.string 	"Enter a:" 

	msg_b: 
	.string		"Enter b:" 

	msg_c: 
	.string 	"Enter c:" 

	msg_d: 
	.string		"Enter d:" 

	msg_s: 
	.string		"%d" 

	msg_and: 
	.string		"a >= b and c < d" 

	msg_or: 
	.string		"a >= b or c < d or both" 

	msg_end: 
	.string		"End of program" 

.section .bss 
	.comm	a, 4, 4 
	.comm	b, 4, 4 
	.comm	c, 4, 4 
	.comm	d, 4, 4 

.section .text 
.globl	main 
.type 	main, @function 

main: 
	pushl	%ebp 
	movl	%esp, %ebp 
	
	pushl	$msg_a 
	call	printf
	addl	$4, %esp 

	pushl	$a 
	pushl	$msg_s 
	call	scanf 
	addl	$8, %esp 

	pushl	$msg_b 
	call	printf
	addl	$4, %esp 

	pushl	$b 
	pushl	$msg_s 
	call	scanf 
	addl	$8, %esp 

	pushl	$msg_c 
	call	printf
	addl	$4, %esp 

	pushl	$c 
	pushl	$msg_s 
	call	scanf 
	addl	$8, %esp 

	pushl	$msg_d 
	call	printf
	addl	$4, %esp 

	pushl	$d 
	pushl	$msg_s 
	call	scanf 
	addl	$8, %esp 

	movl	a, %eax 
	movl	b, %edx 
	cmpl	%edx, %eax 
	jnge 	main_next 

	movl	c, %eax 
	movl	d, %edx 
	cmpl	%edx, %eax 
	jnl 	main_next 

	pushl	$msg_and 
	call	puts
	addl	$4, %esp 

main_next: 

	movl	a, %eax 
	movl	b, %edx 
	cmpl	%edx, %eax 
	jge 	main_or_print 

	movl	c, %eax 
	movl	d, %edx 
	cmpl	%edx, %eax 
	jl 		main_or_print 

	jmp		main_out 

main_or_print: 
	pushl	$msg_or 
	call	puts
	addl	$4, %esp 

main_out: 
	pushl	$msg_end 
	call	puts
	addl	$4, %esp 

	pushl	$0 
	call	exit 
