.section .rodata 
	msg_p1: 
	.string	"arr[%d]:%d\n" 

	msg_end: 
	.string	"End of program[THROUGH ASSEMBLY]" 

.section .data 
	.globl	arr 
	.type 	arr, @object 
	.size 	arr, 20 
	.align 	4 
	arr: 
	.int 	10, 20, 30, 40, 50

.section .bss 	
	.comm	cnt, 4, 4 

.section .text 
.globl	main 
.type	main, @function 

main: 
	pushl	%ebp 
	movl	%esp, %ebp 

	movl	$0, cnt 
	jmp		mn_cond_1 
mn_for_1: 
	movl	cnt, %eax 
	movl	arr(, %eax, 4), %edx # edx == arr[cnt] 
	
	pushl	%edx 
	push	%eax 
	pushl	$msg_p1 
	call	printf
	addl	$12, %esp 

	addl	$1, cnt 
mn_cond_1: 
	movl	cnt, %eax 
	cmpl	$5, %eax 
	jl 		mn_for_1

	pushl	$msg_end 
	call	puts 
	addl	$4, %esp 

	pushl	$0 
	call	exit 
