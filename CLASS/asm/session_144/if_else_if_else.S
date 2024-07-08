.section .rodata 
	msg_a: 
	.string	"Enter a:" 

	msg_b: 
	.string	"Enter b:" 

	msg_m: 
	.string	"Enter m:" 

	msg_n: 
	.string	"Enter n:" 

	msg_x: 
	.string	"Enter x:" 

	msg_y: 
	.string	"Enter y:" 

	msg_s: 
	.string	"%d" 

	msg_if: 
	.string	"a >= b" 

	msg_else_if_1: 
	.string	"a < b and m < n" 

	msg_else_if_2: 
	.string	"a < b and m >= n and x == y" 

	msg_else: 
	.string	"a < b and m >= n and x != y" 

	msg_end: 
	.string	"End of program" 

.section .bss
	.comm	a, 4, 4 
	.comm	b, 4, 4 
	.comm	m, 4, 4 
	.comm	n, 4, 4 
	.comm	x, 4, 4 
	.comm	y, 4, 4 

.section .text 
.globl 	main 
.type	main, @function 

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

	pushl	$msg_m 
	call	printf
	addl	$4, %esp 

	pushl	$m 
	pushl	$msg_s 
	call	scanf 
	addl	$8, %esp 

	pushl	$msg_n 
	call	printf
	addl	$4, %esp 

	pushl	$n 
	pushl	$msg_s 
	call	scanf 
	addl	$8, %esp 

	pushl	$msg_x 
	call	printf
	addl	$4, %esp 

	pushl	$x 
	pushl	$msg_s 
	call	scanf 
	addl	$8, %esp 

	pushl	$msg_y 
	call	printf
	addl	$4, %esp 

	pushl	$y 
	pushl	$msg_s 
	call	scanf 
	addl	$8, %esp 

	movl	a, %eax 
	movl	b, %edx 
	cmpl	%edx, %eax 
	jnge 	main_else_if_1_cond 
	
	pushl	$msg_if 
	call	puts 
	addl	$4, %esp 

	jmp		main_out_block 

main_else_if_1_cond: 
	
	movl	m, %eax 
	movl	n, %edx 
	cmpl	%edx, %eax 
	jnl 	main_else_if_2_cond 

	pushl	$msg_else_if_1 
	call	puts 
	addl	$4, %esp 

	jmp		main_out_block 

main_else_if_2_cond: 

	movl	x, %eax 
	movl	y, %edx 
	cmpl	%edx, %eax 
	jne 	main_else_block 
	
	pushl	$msg_else_if_2 
	call	puts 
	addl	$4, %esp 

	jmp		main_out_block 

main_else_block: 
	
	pushl	$msg_else 
	call	puts 
	addl	$4, %esp 

main_out_block: 
	
	pushl	$msg_end 
	call	puts 
	addl	$4, %esp 

	pushl	$0 
	call	exit 

