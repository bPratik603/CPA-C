.section .rodata 
	msg_p1: 
	.string	"i = %d\n" 

	msg_end: 
	.string	"End or program -> [Through Assembly]" 

.section .bss 
	.comm	i, 4, 4 

.section .text 
.globl	main 
.type	main, @function 

main: 
	pushl	%ebp 
	movl	%esp, %ebp 

	# i = 0; loop variable initialization 
	movl 	$0, i 
	jmp		main_cond_1 
main_for_1: 
	# Body of for loop 
	
	pushl	i 
	pushl	$msg_p1 
	call	printf
	addl	$8, %esp 

	
	# i = i + 1; loop variable modification 
	addl	$1, i 
main_cond_1: 
	# loop variable condition 
	# i < 5 : True : Go in loop, False: Go out of loop 
	movl 	i, %eax 
	cmpl	$5, %eax 
	jl		main_for_1
	
# Out statement assembly - Start
	pushl	$msg_end 
	call	puts 
	addl	$4, %esp 

	pushl	$0 
	call	exit 

