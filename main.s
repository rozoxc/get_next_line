	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 10, 15	sdk_version 10, 15, 6
	.globl	_main                   ## -- Begin function main
	.p2align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	xorl	%esi, %esi
	movl	$0, -4(%rbp)
	leaq	L_.str(%rip), %rdi
	movb	$0, %al
	callq	_open
	movl	%eax, -8(%rbp)
	cmpl	$0, -8(%rbp)
	jge	LBB0_2
## %bb.1:
	leaq	L_.str.1(%rip), %rdi
	callq	_perror
LBB0_2:
	jmp	LBB0_3
LBB0_3:                                 ## =>This Inner Loop Header: Depth=1
	movl	-8(%rbp), %edi
	callq	_get_next_line
	movq	%rax, -16(%rbp)
	cmpq	$0, %rax
	je	LBB0_5
## %bb.4:                               ##   in Loop: Header=BB0_3 Depth=1
	movq	-16(%rbp), %rsi
	leaq	L_.str.2(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movq	-16(%rbp), %rdi
	movl	%eax, -20(%rbp)         ## 4-byte Spill
	callq	_free
	jmp	LBB0_3
LBB0_5:
	xorl	%eax, %eax
	addq	$32, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"file.txt"

L_.str.1:                               ## @.str.1
	.asciz	"error!!"

L_.str.2:                               ## @.str.2
	.asciz	"%s"

.subsections_via_symbols
