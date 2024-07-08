	.file	"struct_assignment.c"
	.globl	inA1
	.data
	.align 4
	.type	inA1, @object
	.size	inA1, 8
inA1:
	.byte	65
	.zero	1
	.value	100
	.long	-100
	.comm	inA2,8,4
	.section	.rodata
	.align 4
.LC0:
	.string	"inA2.c=%c, inA2.snum=%hd, inA2.inum=%d\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB2:
	.cfi_startproc
	leal	4(%esp), %ecx
	.cfi_def_cfa 1, 0
	andl	$-16, %esp
	pushl	-4(%ecx)
	pushl	%ebp
	.cfi_escape 0x10,0x5,0x2,0x75,0
	movl	%esp, %ebp
	pushl	%ecx
	.cfi_escape 0xf,0x3,0x75,0x7c,0x6
	subl	$4, %esp
	movzbl	inA1, %eax
	movb	%al, inA2
	movzwl	inA1+2, %eax
	movw	%ax, inA2+2
	movl	inA1+4, %eax
	movl	%eax, inA2+4
	movl	inA2+4, %ecx
	movzwl	inA2+2, %eax
	movswl	%ax, %edx
	movzbl	inA2, %eax
	movsbl	%al, %eax
	pushl	%ecx
	pushl	%edx
	pushl	%eax
	pushl	$.LC0
	call	printf
	addl	$16, %esp
	subl	$12, %esp
	pushl	$0
	call	exit
	.cfi_endproc
.LFE2:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.12) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
