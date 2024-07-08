.section .rodata 
	msg_p1: 
	.string	"n = %d\n" 

	msg_end: 
	.string	"End of program [THROUGH ASSEMBLY]" 

.section .data 
	.globl	inA
	.type	inA, @object 
	.size	inA, 36 
	.align	4 
	inA: 
	.int 	0xa0b0c0d0, 0x10203040	# inA.n1 
	.int 	0xffc0ffd0, 0xffa0ffb0	# inA.n2 
	.int 	10, 20, 30, 40, 50		# inA.arr[5] 

.section .bss 
	.comm	i, 4, 4 
	.comm	n, 4, 4 

.section .text 
.globl 	main 
.type	main, @function 

main: 
	pushl	%ebp 
	movl	%esp, %ebp 
	movl	$16, %ebx 	# ebx == 16 == offset of arr w.r.t. struct A 
	movl	$0, i # i = 0 
	jmp		mn_cond1 
mn_for1: 
	movl	inA(%ebx, %eax, 4), %edx # edx == inA.arr[i] 
	movl	%edx, n 
	
	pushl	n 
	pushl	$msg_p1 
	call	printf
	addl	$8, %esp 

	addl	$1, i 	# ++i 
mn_cond1: 
	movl	i, %eax  	# eax == i 
	cmpl	$5, %eax 
	jl		mn_for1

	pushl	$msg_end 
	call	puts 
	addl	$4, %esp 

	pushl	$0 
	call	exit 

