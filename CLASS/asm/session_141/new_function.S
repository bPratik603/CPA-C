.section .text 

.globl 	my_function 
.type	my_function, @function 
my_function: 
	# PROLOGUE 
	pushl	%ebp 
	movl	%esp, %ebp 
	# END OF PROLOGUE 

	# BODY OF FUNCTION TRANSLATION 

	# EPILOGUE 
	movl	%ebp, %esp 
	popl	%ebp 
	# END OF EPILOGUE 
	# Return to the caller 
	ret 

#--------------------------------
# Without commenting 

.globl	my_function 
.type	my_function, @function 
my_function: 
	pushl	%ebp 
	movl	%esp, %ebp 
	# BODY 
	movl	%ebp, %esp 
	popl	%ebp 
	ret 

	:wq

