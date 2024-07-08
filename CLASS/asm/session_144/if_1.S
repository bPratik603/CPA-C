.section .rodata 
	msg_p1: 
	.string	"Enter n1:" 

	msg_p2:
	.string	"Enter n2:" 

	msg_s1: 
	.string	"%d" 

	msg_p3: 
	.string	"%d > %d\n" 

	msg_p4: 
	.string	"end of program" 

.section .bss 
	.comm	n1, 4, 4 
	.comm	n2, 4, 4 

.section .text 
.globl main 
.type main, @function 

main: 
	pushl	%ebp 
	movl	%esp, %ebp 

	pushl	$msg_p1
	call	printf
	addl	$4, %esp 

	pushl	$n1 
	pushl	$msg_s1 
	call	scanf 
	addl	$8, %esp 

	pushl	$msg_p2 
	call	printf 
	addl	$4, %esp 

	pushl	$n2 
	pushl	$msg_s1 
	call	scanf 
	addl	$8, %esp 

	movl 	n1, %eax 
	movl	n2, %edx 
	cmpl	%edx, %eax 
	jng 	main_out 
	
	pushl	n2 
	pushl	n1 
	pushl	$msg_p3 
	call	printf
	addl	$12, %esp

main_out: 
	pushl	$msg_p4 
	call	puts 
	addl	$4, %esp 
	
	pushl	$0 
	call	exit 
