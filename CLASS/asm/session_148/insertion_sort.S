.include "../include/offsets.S" 

.equ	EXIT_SUCCESS, 	0 
.equ	EXIT_FAILURE, 	-1 
.equ	SIZE_OF_INT, 	4 
.equ	NULL, 			0
.equ	CAP, 			50000

.section .rodata 
	usage_error: 
	.string	"%s number_of_elements\n" 

	invalid_size_error: 
	.string	"Bad value on commandline for array size" 

	memory_allocation_error: 
	.string	"calloc:fatal:out of virtual address space" 
	
	msg_before_sort: 
	.string	"Before sort:" 

	msg_after_sort: 
	.string	"After sort:" 

	msg_arr: 
	.string	"arr[%d]:%d\n" 

.section .text 
.globl 	main 
.type 	main, @function 

.equ	argc, p1 
.equ	argv, p2 

.equ	arr, loc1 
.equ	N, loc2 

.equ	MAIN_LOCAL_STORAGE, 8 

main: 
	pushl	%ebp 
	movl	%esp, %ebp 
	subl	$MAIN_LOCAL_STORAGE, %esp 
	
	cmpl	$2, argc(%ebp) 
	jne 	mn_usage_error

	movl	argv(%ebp), %ebx 
	movl	$1, %eax 
	movl	(%ebx, %eax, 4), %edx	# edx == argv[1] 
	
	pushl	%edx 
	call	atoi 
	addl	$4, %esp 

	cmpl	$0, %eax 
	jle 	mn_invalid_array_size_error

	movl	%eax, N(%ebp) 

	pushl	$SIZE_OF_INT 
	pushl	%eax 
	call	calloc 
	addl	$8, %esp 
	cmpl	$NULL, %eax 
	je 		mn_memory_allocation_error 
	movl 	%eax, arr(%ebp) 

	movl	arr(%ebp), %eax 
	movl	N(%ebp), %edx 
# input(arr, N); 

	pushl	%edx 
	pushl	%eax 
	call	input 
	addl	$8, %esp 

# show(arr, N, "Before sort:"); 
	movl	arr(%ebp), %eax 
	movl	N(%ebp), %edx 
	
	pushl	$msg_before_sort 
	pushl	%edx 
	pushl	%eax 
	call	show 
	addl	$12, %esp 

# sort(arr, N); 
	movl	arr(%ebp), %eax 
	movl	N(%ebp), %edx 

	pushl	%edx 
	pushl	%eax 
	call	insertion_sort 
	addl	$12, %esp 

# show(arr, N, "after sort:"); 
	movl	arr(%ebp), %eax 
	movl	N(%ebp), %edx 
	
	pushl	$msg_after_sort 
	pushl	%edx 
	pushl	%eax 
	call	show 
	addl	$12, %esp 

	movl	arr(%ebp), %eax 
	pushl	%eax 
	call	free 
	addl	$4, %esp 

	movl	$NULL, arr(%ebp)
	
	jmp		mn_exit_with_success 
	
mn_usage_error: 
	
	movl 	argv(%ebp), %ebx 
	movl	$0, %eax 
	movl	(%ebx, %eax, 4), %edx

	pushl	%edx 
	pushl	$usage_error 
	call	printf
	addl	$8, %esp 
	jmp		mn_exit_with_failure

mn_invalid_array_size_error: 
	
	pushl	$invalid_size_error 
	call	puts 
	addl	$4, %esp 
	jmp		mn_exit_with_failure

mn_memory_allocation_error: 
	
	pushl	$memory_allocation_error 
	call	puts 
	addl	$4, %esp 
	
	jmp		mn_exit_with_failure

mn_exit_with_failure: 
	pushl	$EXIT_FAILURE 
	call	exit 

mn_exit_with_success: 
	pushl	$EXIT_SUCCESS 
	call	exit 

.globl	insertion_sort 
.type	insertion_sort, @function 

.equ	arr, p1 
.equ	N, p2 

.equ	i, loc1 
.equ	j, loc2 
.equ	key, loc3 

.equ	INSERTION_SORT_LOCAL_STORAGE, 12 

insertion_sort:

	pushl	%ebp 
	movl	%esp, %ebp 
	subl	$INSERTION_SORT_LOCAL_STORAGE, %esp 
	
	movl	$1, j(%ebp) 
	jmp		ins_sort_outer_cond 
ins_sort_outer_body: 
	movl	arr(%ebp), %ebx 
	movl	(%ebx, %eax, 4), %edx 
	movl	%edx, key(%ebp) 
	subl	$1, %eax 
	movl	%eax, i(%ebp) 
	jmp 	ins_sort_inner_cond 

ins_sort_inner_body: 
	movl	i(%ebp), %eax 
	addl	$1, %eax 
	movl	%edx, (%ebx, %eax, 4) 
	
	subl	$1, i(%ebp) 

ins_sort_inner_cond: 
	movl	i(%ebp), %eax 
	cmpl	$-1, %eax 
	jng 	ins_sort_inner_out 
	movl	arr(%ebp), %ebx 
	movl	(%ebx, %eax, 4), %edx 
	cmpl	key(%ebp), %edx 
	jg 		ins_sort_inner_body 


ins_sort_inner_out: 
	movl	key(%ebp), %edx 
	movl	arr(%ebp), %ebx 
	movl	i(%ebp), %eax 
	addl	$1, %eax 
	movl	%edx, (%ebx, %eax, 4) 

	addl	$1, j(%ebp) 
ins_sort_outer_cond: 
	movl	j(%ebp), %eax 
	cmpl	N(%ebp), %eax 
	jl 		ins_sort_outer_body 


	movl	%ebp, %esp 
	popl	%ebp 
	ret 

.globl 	input 
.type 	input, @function 

.equ	arr, p1 
.equ	N, p2

.equ 	i, loc1 

.equ	INPUT_LOCAL_STORAGE, 4 
.equ	NOW, 0 

input: 
	pushl	%ebp 
	movl	%esp, %ebp 
	subl	$INPUT_LOCAL_STORAGE, %esp 
	
	pushl	$NOW 
	call	time 
	addl	$4, %esp 

	pushl	%eax 
	call	srand 
	addl	$4, %esp 

	movl	$0, i(%ebp) 
	jmp		input_cond_1 
input_for_1: 
	call	rand 
	movl	$CAP, %ebx 
	movl	$0, %edx 
	divl	%ebx 

	movl	arr(%ebp), %ebx 
	movl	i(%ebp), %eax 
	movl	%edx, (%ebx, %eax, 4) 

	addl	$1, i(%ebp) 
input_cond_1: 
	movl	i(%ebp), %eax 
	cmpl	N(%ebp), %eax 
	jl 		input_for_1

	movl	%ebp, %esp 
	popl	%ebp 
	ret 

.globl	show 
.type	show, @function 

.equ	arr, p1 
.equ	N, p2 
.equ	msg, p3 

.equ	i, loc1 

.equ	SHOW_LOCAL_STORAGE, 4 

show: 
	
	pushl	%ebp 
	movl	%esp, %ebp 
	subl	$SHOW_LOCAL_STORAGE, %esp 

	movl	msg(%ebp), %eax 
	cmpl	$NULL, %eax 
	je 		show_array_branch
		
	pushl	%eax 
	call	puts 
	addl	$4, %esp 

show_array_branch: 
	movl	$0, i(%ebp) 
	jmp		show_cond_1 
show_for_1: 
	movl	arr(%ebp), %ebx 
	movl	(%ebx, %eax, 4), %edx 

	pushl	%edx 
	pushl	%eax 
	pushl	$msg_arr 
	call	printf
	addl	$12, %esp 

	addl	$1, i(%ebp) 
show_cond_1: 
	movl	i(%ebp), %eax 
	cmpl	N(%ebp), %eax 
	jl 		show_for_1 

	movl	%ebp, %esp 
	popl	%ebp 
	ret

