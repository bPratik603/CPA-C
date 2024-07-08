.section .rodata 
	msg:
	.string	"num = %d\n" 

.section .data 
	.globl	num 
	.type 	num, @object 
	.size	num, 4 
	.align	4 
	num: 
	.int 	100 

.section .text 
.globl	main 
.type	main, @function 

main: 
	pushl	%ebp 
	movl	%esp, %ebp 

	pushl	num 
	pushl	$msg 
	call	printf
	addl	$8, %esp 

	movl	$num, %eax
	movl	$200, (%eax) 

	pushl	num
	pushl	$msg 
	call	printf
	addl	$8, %esp 

	pushl	$0 
	call	exit 
