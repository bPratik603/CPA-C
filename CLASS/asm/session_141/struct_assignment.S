.section .rodata 
	fmt: 
	.string "inA2.c=%c, inA2.snum=%hd, iA2.inum=%d\n" 

.section .data 
	.globl	inA1 
	.type	inA1, @object 
	.size 	inA1, 8 
	.align	4 
	inA1: 
	.ascii	"A" 
	.zero 	1 
	.value 	100 
	.int 	-100 

.section .bss 
	.comm	inA2, 8, 4 

.section .text 
.globl	main 
.type	main, @function 

main: 
	pushl	%ebp 
	movl	%esp, %ebp 

	movl	$inA1, %eax 
	movl	$inA2, %ebx 

	movb	(%eax), %dl 
	movb	%dl, (%ebx) 

	movw	2(%eax), %dx 
	movw	%dx, 2(%ebx) 
	
	movl	4(%eax), %edx 
	movl	%edx, 4(%ebx) 

	movl	$0, %edx 
	movb	(%ebx), %dl  # dl == inA2.c, rest 3 bytes of edx 
						 # are zero 

	movl	$0, %ecx 
	movw	2(%ebx), %cx  # cx == inA2.snum. rest of the 2 bytes 
						  # of ecx are zero 

	movl	4(%ebx), %esi # esi == inA2.inum 

	pushl	%esi 	# pushing inA2.inum 
	pushl	%ecx 	# pushing inA2.snum 
	pushl	%edx 	# pushing inA2.c 
	pushl	$fmt 	# pushing base addr of format string 
	call 	printf  # invoking printf() 
	addl	$16, %esp 	# clearing the argument storage 

	pushl	$0 
	call	exit 



