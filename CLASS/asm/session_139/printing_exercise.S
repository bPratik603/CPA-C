.section .rodata 
	msg_1:
	.string	"Hello,World\n" 

	msg_2:
	.string	"num = %d\n" 

.section .data 
	.globl	num 
	.type	num, @object 
	.size	num, 4 
	.align	4 
	num: 
	.int	10 

.section .text 
.globl	main 
.type	main, @function 

main:
	# PROLOGUE 
	pushl	%ebp 
	movl	%esp, %ebp
	# END OF PROLOGUE 

	pushl	$msg_1 
	call	printf
	addl	$4, %esp 

	pushl	num 
	pushl	$msg_2
	call	printf
	addl	$8, %esp 

	pushl	$0 
	call 	exit 


