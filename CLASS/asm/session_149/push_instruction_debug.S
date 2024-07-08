.section .text 
.globl	main 
.type	main, @function 

main: 
	pushl	%ebp 
	movl	%esp, %ebp 
	

	pushl	$0x64 	# $0x 00 00 00 64 

	pushl	$0x13BF3 	# 0x 00 01 3B F3 

	pushl	$0xa0b0c0d0 # 0x a0 b0 c0 d0 

	popl	%eax 
	popl	%ebx 
	popl	%ecx 

	pushl	$0 			# 0x 00 00 00 00 
	call	exit 

