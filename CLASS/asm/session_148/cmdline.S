.include	"../include/offsets.S" 

.section .rodata 
	msg_p: 
	.string	"argv[%d]:%s\n" 

.section .text 
.globl main 
.type main, @function 

.equ	argc, p1 
.equ	argv, p2 

.equ	i, loc1 

main: 

	pushl	%ebp 
	movl	%esp, %ebp 
	subl	$4, %esp 

	movl 	$0, i(%ebp) 
	jmp		mn_cond1 
mn_for1: 
	movl	argv(%ebp), %ebx 		# ebx == argv 
	movl	(%ebx, %eax, 4), %edx 	# edx == argv[i] 
	
	pushl	%edx 
	pushl	%eax 
	pushl	$msg_p 
	call	printf
	addl	$12, %esp
	
	addl	$1, i(%ebp) 
mn_cond1: 
	movl	i(%ebp), %eax			# eax == i  
	cmpl	argc(%ebp), %eax 
	jl 		mn_for1

	movl 	%ebp, %esp 
	popl	%ebp 
	ret 

