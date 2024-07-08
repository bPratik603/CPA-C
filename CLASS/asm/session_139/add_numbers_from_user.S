.section .rodata 
	fmt_1:
	.string	"Enter num1:" 

	fmt_2:
	.string	"%d" 

	fmt_3: 
	.string	"Enter num2:" 

	fmt_4: 
	.string	"Summation = %d\n" 

.section .bss 
	.comm	num1, 4, 4
	.comm	num2, 4, 4 
	.comm	summation, 4, 4 

.section .text
.globl main 
.type main, @function 

main: 
	pushl	%ebp 
	movl	%esp, %ebp 

	pushl	$fmt_1 
	call	printf
	addl	$4, %esp 

	pushl	$num1 
	pushl	$fmt_2 
	call	scanf 
	addl	$8, %esp 

	pushl	$fmt_3 
	call	printf
	addl	$4, %esp 

	pushl	$num2 
	pushl	$fmt_2 
	call	scanf 
	addl	$8, %esp 

	movl	num1, %eax
	movl	num2, %edx 
	addl	%edx, %eax
	movl	%eax, summation 

	pushl	summation 
	pushl	$fmt_4 
	call	printf
	addl	$8, %esp 

	pushl	$0 
	call	exit 

