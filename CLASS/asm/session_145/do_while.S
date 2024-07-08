.section .rodata 
	msg_p1: 
	.string	"Enter i:" 

	msg_s1: 
	.string	"%d" 

	msg_p2: 
	.string	"i = %d\n" 

	msg_end: 
	.string	"End of program [THROUGH ASSEMBLY]" 

.section .bss 
	.comm	i, 4, 4 

.section .text 
.globl main 
.type main, @function 

main: 
	pushl	%ebp 
	movl	%esp, %ebp 

	pushl	$msg_p1 
	call	printf
	addl	$4, %esp 

	pushl	$i 
	pushl	$msg_s1 
	call	scanf
	addl	$8, %esp 

main_for: 
	pushl	i 
	pushl	$msg_p2 
	call	printf
	addl	$8, %esp 

	addl	$1, i 
	
main_cond: 
	movl	i, %eax 
	cmpl	$5, %eax 
	jl 		main_for

	pushl	$msg_end 
	call	puts 
	addl	$4, %esp 

	pushl	$0 
	call	exit 
