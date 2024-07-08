.section .rodata 
	msg_p1: 
	.string	"Before sort:" 

	msg_p2: 
	.string	"arr[%d]=%d\n" 

	msg_p3: 
	.string	"After sort:" 

	msg_end: 
	.string	"End of program [THROUGH ASSEMBLY]" 

.section .data 
	.globl 	arr 
	.type 	arr, @object 
	.size	arr, 32 
	.align 	4 
	arr: 
	.int 	100, 50, 3, 10, 200, 150, 75, 1 

.section .text 
.globl main 
.type main, @function 

main: 
	pushl 	%ebp 
	movl 	%esp, %ebp 

	subl 	$12, %esp 	# for three local variables 
						# -4(%ebp)==i, -8(%ebp)==j, -12(%ebp)==key 
	
	pushl	$msg_p1 
	call	puts 
	addl	$4, %esp 

	movl 	$0, -4(%ebp) 	# i == 0 
	jmp		main_show_cond_1 

main_show_for_1: 

	movl 	arr(, %eax, 4), %edx 
	pushl	%edx 
	pushl	%eax 
	pushl	$msg_p2 
	call	printf
	addl	$12, %esp 

	addl	$1, -4(%ebp) 

main_show_cond_1: 
	movl 	-4(%ebp), %eax 
	cmpl	$8, %eax 
	jl 		main_show_for_1

	movl 	$1, -8(%ebp) 		# j == 1 
	jmp 	main_outer_loop_cond 

main_outer_loop_body: 

	movl 	arr(, %eax, 4), %edx 	# edx == arr[j] 
	movl 	%edx, -12(%ebp) 		# key == edx == arr[j] 
	subl 	$1, %eax 				# eax <- eax - 1 
	movl 	%eax, -4(%ebp) 			# i == eax == j - 1
	jmp 	main_inner_loop_cond 

	main_inner_loop_body: 
		
		addl	$1, %eax 				# eax <- eax + 1 (== i+1) 
		movl	%edx, arr(, %eax, 4) 	# arr[i+1] <- arr[i]
		subl	$1, -4(%ebp) 			# i = i - 1 

	main_inner_loop_cond: 
		movl 	-4(%ebp), %eax 	
		cmpl	$-1, %eax 
		jng 	main_inner_loop_out 
		movl 	arr(, %eax, 4), %edx 	# edx == arr[i] 
		cmpl	-12(%ebp), %edx 
		jg 		main_inner_loop_body 

main_inner_loop_out: 
	movl 	-12(%ebp), %edx 	# edx == key 
	movl 	-4(%ebp), %eax 		# eax == i 
	addl	$1, %eax 
	movl	%edx, arr(, %eax, 4) # arr[i+1] == key 
	
	addl	$1, -8(%ebp) 

main_outer_loop_cond: 
	
	movl 	-8(%ebp), %eax 		 # eax == j 
	cmpl	$8, %eax 			 # eax < 8 
	jl 		main_outer_loop_body # jump to body if less 

	pushl	$msg_p3 
	call	puts 
	addl	$4, %esp 

	movl 	$0, -4(%ebp) 	# i == 0 
	jmp		main_show_cond_2 

main_show_for_2: 

	movl 	arr(, %eax, 4), %edx 
	pushl	%edx 
	pushl	%eax 
	pushl	$msg_p2 
	call	printf
	addl	$12, %esp 

	addl	$1, -4(%ebp) 

main_show_cond_2: 
	movl 	-4(%ebp), %eax 
	cmpl	$8, %eax 
	jl 		main_show_for_2

	pushl	$msg_end 
	call	puts 
	addl	$4, %esp 

	pushl 	$0 
	call	exit 
