.section .rodata 
	fmt: 
	.string	"%d-%d-%d\n" 

.section .data 
	.globl	myDate
	.type	myDate, @object 
	.size	myDate, 12 
	.align	4 
	myDate: 
	.int	1
	.int 	1 
	.int 	1970 

.section .bss 
	.comm	dd, 4, 4 
	.comm	mm, 4, 4 
	.comm	yy, 4, 4 

.section .text 
.globl	main 
.type	main, @function 
main: 
	pushl	%ebp 
	movl	%esp, %ebp 

	movl	$myDate, %eax 
	movl	(%eax), %edx 
	movl	%edx, dd 
	movl	4(%eax), %edx 
	movl	%edx, mm 
	movl	8(%eax), %edx 
	movl	%edx, yy 

	pushl	yy 
	pushl	mm 
	pushl	dd 
	pushl	$fmt 
	call	printf
	addl	$16, %esp 

	movl	$myDate, %eax
	movl	$2, (%eax) 
	movl	$9, 4(%eax) 
	movl	$1997, 8(%eax) 
	
	movl	(%eax), %edx 
	movl	%edx, dd 
	movl	4(%eax), %edx 
	movl	%edx, mm 
	movl	8(%eax), %edx 
	movl	%edx, yy 

	pushl	yy 
	pushl	mm 
	pushl	dd 
	pushl	$fmt 
	call	printf
	addl	$16, %esp 

	pushl	$0 
	call	exit 

