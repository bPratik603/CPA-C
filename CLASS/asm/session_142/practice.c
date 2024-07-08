unsigned int compute_1(unsigned int n1, unsigned int n2, unsigned int n3){
	unsigned int result = (n1 + n2 - n3) / n1; 
	return (result); 
}

/* 
.globl	compute_1 
.type 	compte_1, @function 
compute_1: 
	pushl	%ebp 
	movl	%esp, %ebp 
	subl	$4, %esp 
	
	movl	8(%ebp), %eax	# eax == n1  
	movl	12(%ebp), %edx 	# edx == n2 
	addl	%edx, %eax 		# eax == n1 + n2 
	movl	16(%ebp), %edx 	# edx == n3 
	subl	%edx, %eax 		# eax == (n1+n2)-n3
	movl	8(%ebp), %ebx 	# ebx == n1 
	divl	%ebx 			# eax==QUOTIENT((n1+n2-n3)/n1)
							# edx==REMAINDER((n1+n2-n3)/n1) 
	movl	%eax, -4(%ebp) 
	movl	%ebp, %esp 
	popl	%ebp 
	ret 
*/ 

unsigned int compute_2(unsigned int n1, unsigned int n2, unsigned int n3, unsigned int n4){
	unsigned int tmp1, tmp2, result; 

	tmp1 = (n1 + n2) * n3; 
	tmp2 = (n2 + n3) * n4; 
	result = (tmp1 + tmp2)/2; 
	return (result); 
}

/* 
.globl 	compute_2 
.type 	compute_2, @function 
compute_2: 
	pushl	%ebp 
	movl	%esp, %ebp 
	subl	$12, %esp 
	
	movl	8(%ebp), %eax 	# eax == n1 
	movl	12(%ebp), %edx 	# edx == n2 
	addl	%edx, %eax 		# eax == n1 + n2 
	movl	16(%ebp), %ebx 	# ebx == n3 
	mull	%ebx 			# eax=LOWER 4 BYTES of MULTIPLICATION 
							# edx=UPPER 4 BYTES of MULTIPLICATION 
	movl	%eax, -4(%ebp)  # tmp1 == (n1+n2)*n3 

	movl	12(%ebp), %eax 	# eax == n2 
	movl	16(%ebp), %edx  # edx == n3 
	addl	%edx, %eax 		# eax == n2 + n3 
	movl	20(%ebp), %ebx 	# ebx == n4 
	mull	%ebx 			# eax == LOWER 4 BYTES of MULTIPLICATION 
							# edx == UPPER 4 BYTES of MULTIPLICATION 
	movl	%eax, -8(%ebp)  # tmp2 == (n2 + n3) * n4 
	movl	-4(%ebp), %eax 	# eax == tmp1 
	movl	-8(%ebp), %edx 	# edx == tmp2 
	addl	%edx, %eax 		# eax == tmp1 + tmp2 
	movl	$2, %ebx 		
	movl	$0, %edx 
	divl	%ebx 			# eax == QUOTIENT((tmp1+tmp2)/2) 
							# edx == REMAINDER((tmp1+tmp2)/2) 
	movl	%eax, -12(%ebp) 
		
	movl	%ebp, %esp 
	popl	%ebp 
	ret 
*/ 
 
