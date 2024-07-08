.section .text 
.globl main 
.type main, @function 

main: 
	movl	$10, %eax 
	movl	$200, (%eax) 
	pushl	$0 
	call	exit 
