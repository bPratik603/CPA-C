.section .rodata 
	msg_p1: 
	.string	"Enter n1:" 

	msg_p2: 
	.string	"Enter n2:" 

	msg_add: 
	.string	"%d + %d == %d\n" 

	msg_sub: 
	.string	"%d - %d == %d\n" 

	msg_mul: 
	.string	"%d * %d == %d\n" 

	msg_quotient: 
	.string	"%d / %d == %d\n" 

	msg_remainder: 
	.string	"%d %% %d == %d\n" 

	msg_s1: 
	.string	"%d" 

	asm_proof:
	.string	"This program was coded in GNU 32 assembly for i686 architecture"

.section .bss 
	.comm	n1, 4, 4 
	.comm	n2, 4, 4 
	.comm	result, 4, 4 

.section .text 
.globl 	main 
.type	main, @function 
main: 
	pushl	%ebp 
	movl	%esp, %ebp 

	pushl	$msg_p1 
	call	printf
	addl	$4, %esp 

	pushl	$n1 
	pushl	$msg_s1 
	call	scanf 
	addl	$8, %esp 

	pushl	$msg_p2 
	call	printf
	addl	$4, %esp 

	pushl	$n2 
	pushl	$msg_s1 
	call	scanf 
	addl	$8, %esp 

	pushl	n2 
	pushl	n1 
	call	cpa_add 
	addl	$8, %esp 
	movl	%eax, result 

	pushl	result 
	pushl	n2 
	pushl	n1 
	pushl	$msg_add 
	call	printf
	addl	$16, %esp 

	pushl	n2 
	pushl	n1 
	call	cpa_sub 
	addl	$8, %esp 
	movl	%eax, result 

	pushl	result 
	pushl	n2 
	pushl	n1 
	pushl	$msg_sub 
	call	printf
	addl	$16, %esp 

	pushl	n2 
	pushl 	n1 
	call	cpa_mul 
	addl	$8, %esp 
	movl	%eax, result

	pushl	result 
	pushl	n2 
	pushl	n1 
	pushl	$msg_mul 
	call	printf
	addl	$16, %esp 

	pushl	n2 
	pushl	n1 
	call	cpa_quotient
	addl	$8, %esp 
	movl	%eax, result 

	pushl	result 
	pushl	n2 
	pushl	n1 
	pushl	$msg_quotient 
	call	printf
	addl	$16, %esp 

	pushl	n2 
	pushl	n1 
	call	cpa_remainder 
	addl	$8, %esp 
	movl	%eax, result 

	pushl	result 
	pushl	n2 
	pushl	n1 
	pushl	$msg_remainder 
	call	printf
	addl	$16, %esp 

	pushl	$asm_proof 
	call	puts 
	addl	$4, %esp 

	pushl	$0 
	call	exit 

.globl cpa_add 
.type  cpa_add, @function 
cpa_add: 
	pushl	%ebp 
	movl	%esp, %ebp 
	subl	$4, %esp 

	movl	8(%ebp), %eax 	# eax == n1 
	movl	12(%ebp), %edx 	# edx == n2 
	addl	%edx, %eax 		# eax == eax + edx 
	movl	%eax, -4(%ebp) 

	movl	%ebp, %esp 
	popl	%ebp 
	ret 

.globl 	cpa_sub 
.type 	cpa_sub, @function 
cpa_sub: 
	pushl	%ebp 
	movl	%esp, %ebp 
	subl	$4, %esp 

	movl	8(%ebp), %eax	# eax == n1  
	movl	12(%ebp), %edx 	# edx == n2 
	subl 	%edx, %eax 		# eax <- eax - edx 
	movl	%eax, -4(%ebp) 
	
	movl	%ebp, %esp 
	popl	%ebp 
	ret 

.globl	cpa_mul 
.type 	cpa_mul, @function 
cpa_mul: 
	pushl	%ebp 
	movl	%esp, %ebp 	
	subl	$4, %esp 
	movl	8(%ebp), %eax 
	movl	12(%ebp), %ebx 
	movl	$0, %edx 
	imull 	%ebx 
	# edx:HIGHER 4 bytes of multiplcation  
	# eax:LOWER 4 bytes of multiplication 
	movl	%eax, -4(%ebp) 

	movl	%ebp, %esp 
	popl	%ebp 
	ret 

.globl 	cpa_quotient 
.type 	cpa_quotient, @function 
cpa_quotient: 
	pushl	%ebp 
	movl	%esp, %ebp 
	subl	$4, %esp 

	movl	8(%ebp), %eax 
	movl	12(%ebp), %ebx 
	movl	$0, %edx 
	idivl	%ebx 
	# eax == Quotient 
	# edx == Remainder 
	movl	%eax, -4(%ebp) 

	movl 	%ebp, %esp 
	popl	%ebp 
	ret 

.globl 	cpa_remainder 
.type 	cpa_remainder, @function 
cpa_remainder: 
	pushl	%ebp 
	movl	%esp, %ebp 
	subl	$4, %esp 

	movl	8(%ebp), %eax 
	movl	12(%ebp), %ebx 
	movl	$0, %edx 
	idivl 	%ebx 
	movl	%edx, -4(%ebp) 
	movl	%edx, %eax 

	movl	%ebp, %esp 
	popl	%ebp 
	ret 

