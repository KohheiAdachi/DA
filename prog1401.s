	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 10, 14
	.globl	_init                   ## -- Begin function init
	.p2align	4, 0x90
_init:                                  ## @init
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	movq	_root@GOTPCREL(%rip), %rax
	movq	$0, (%rax)
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_add_tree               ## -- Begin function add_tree
	.p2align	4, 0x90
_add_tree:                              ## @add_tree
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movl	$24, %eax
	movl	%eax, %ecx
	movl	%edi, -4(%rbp)
	movq	%rcx, %rdi
	callq	_malloc
	movq	_root@GOTPCREL(%rip), %rcx
	movq	%rax, -16(%rbp)
	movl	-4(%rbp), %edx
	movq	-16(%rbp), %rax
	movl	%edx, (%rax)
	movq	-16(%rbp), %rax
	movq	$0, 8(%rax)
	movq	-16(%rbp), %rax
	movq	$0, 16(%rax)
	cmpq	$0, (%rcx)
	jne	LBB1_2
## %bb.1:
	movq	_root@GOTPCREL(%rip), %rax
	movq	-16(%rbp), %rcx
	movq	%rcx, (%rax)
	jmp	LBB1_15
LBB1_2:
	movq	_root@GOTPCREL(%rip), %rax
	movq	(%rax), %rax
	movq	%rax, -24(%rbp)
LBB1_3:                                 ## =>This Inner Loop Header: Depth=1
	cmpq	$0, -24(%rbp)
	je	LBB1_14
## %bb.4:                               ##   in Loop: Header=BB1_3 Depth=1
	movl	-4(%rbp), %eax
	movq	-24(%rbp), %rcx
	cmpl	(%rcx), %eax
	jge	LBB1_9
## %bb.5:                               ##   in Loop: Header=BB1_3 Depth=1
	movq	-24(%rbp), %rax
	cmpq	$0, 8(%rax)
	jne	LBB1_7
## %bb.6:
	movq	-16(%rbp), %rax
	movq	-24(%rbp), %rcx
	movq	%rax, 8(%rcx)
	jmp	LBB1_15
LBB1_7:                                 ##   in Loop: Header=BB1_3 Depth=1
	movq	-24(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -24(%rbp)
## %bb.8:                               ##   in Loop: Header=BB1_3 Depth=1
	jmp	LBB1_13
LBB1_9:                                 ##   in Loop: Header=BB1_3 Depth=1
	movq	-24(%rbp), %rax
	cmpq	$0, 16(%rax)
	jne	LBB1_11
## %bb.10:
	movq	-16(%rbp), %rax
	movq	-24(%rbp), %rcx
	movq	%rax, 16(%rcx)
	jmp	LBB1_15
LBB1_11:                                ##   in Loop: Header=BB1_3 Depth=1
	movq	-24(%rbp), %rax
	movq	16(%rax), %rax
	movq	%rax, -24(%rbp)
## %bb.12:                              ##   in Loop: Header=BB1_3 Depth=1
	jmp	LBB1_13
LBB1_13:                                ##   in Loop: Header=BB1_3 Depth=1
	jmp	LBB1_3
LBB1_14:
	jmp	LBB1_15
LBB1_15:
	addq	$32, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_search_max             ## -- Begin function search_max
	.p2align	4, 0x90
_search_max:                            ## @search_max
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	movq	%rdi, -16(%rbp)
	movq	-16(%rbp), %rdi
	movq	%rdi, -24(%rbp)
LBB2_1:                                 ## =>This Inner Loop Header: Depth=1
	cmpq	$0, -24(%rbp)
	je	LBB2_6
## %bb.2:                               ##   in Loop: Header=BB2_1 Depth=1
	movq	-24(%rbp), %rax
	cmpq	$0, 16(%rax)
	jne	LBB2_4
## %bb.3:
	movq	-24(%rbp), %rax
	movl	(%rax), %ecx
	movl	%ecx, -4(%rbp)
	jmp	LBB2_7
LBB2_4:                                 ##   in Loop: Header=BB2_1 Depth=1
	movq	-24(%rbp), %rax
	movq	16(%rax), %rax
	movq	%rax, -24(%rbp)
## %bb.5:                               ##   in Loop: Header=BB2_1 Depth=1
	jmp	LBB2_1
LBB2_6:
	movl	$0, -4(%rbp)
LBB2_7:
	movl	-4(%rbp), %eax
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_delete_node            ## -- Begin function delete_node
	.p2align	4, 0x90
_delete_node:                           ## @delete_node
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$48, %rsp
	movl	%edi, -4(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-16(%rbp), %rsi
	movq	%rsi, -24(%rbp)
LBB3_1:                                 ## =>This Inner Loop Header: Depth=1
	movq	-24(%rbp), %rax
	cmpq	$0, (%rax)
	je	LBB3_19
## %bb.2:                               ##   in Loop: Header=BB3_1 Depth=1
	movq	-24(%rbp), %rax
	movq	(%rax), %rax
	movl	(%rax), %ecx
	cmpl	-4(%rbp), %ecx
	jne	LBB3_14
## %bb.3:
	movq	-24(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, -32(%rbp)
	movq	-24(%rbp), %rax
	movq	(%rax), %rax
	cmpq	$0, 8(%rax)
	jne	LBB3_6
## %bb.4:
	movq	-24(%rbp), %rax
	movq	(%rax), %rax
	cmpq	$0, 16(%rax)
	jne	LBB3_6
## %bb.5:
	movq	-24(%rbp), %rax
	movq	$0, (%rax)
	movq	-32(%rbp), %rax
	movq	%rax, %rdi
	callq	_free
	jmp	LBB3_13
LBB3_6:
	movq	-24(%rbp), %rax
	movq	(%rax), %rax
	cmpq	$0, 8(%rax)
	jne	LBB3_8
## %bb.7:
	movq	-24(%rbp), %rax
	movq	(%rax), %rax
	movq	16(%rax), %rax
	movq	-24(%rbp), %rcx
	movq	%rax, (%rcx)
	movq	-32(%rbp), %rax
	movq	%rax, %rdi
	callq	_free
	jmp	LBB3_12
LBB3_8:
	movq	-24(%rbp), %rax
	movq	(%rax), %rax
	cmpq	$0, 16(%rax)
	jne	LBB3_10
## %bb.9:
	movq	-24(%rbp), %rax
	movq	(%rax), %rax
	movq	8(%rax), %rax
	movq	-24(%rbp), %rcx
	movq	%rax, (%rcx)
	movq	-32(%rbp), %rax
	movq	%rax, %rdi
	callq	_free
	jmp	LBB3_11
LBB3_10:
	movq	-24(%rbp), %rax
	movq	(%rax), %rax
	movq	8(%rax), %rdi
	callq	_search_max
	movl	%eax, -36(%rbp)
	movl	-36(%rbp), %edi
	movq	-24(%rbp), %rsi
	callq	_delete_node
	movl	-36(%rbp), %eax
	movq	-24(%rbp), %rsi
	movq	(%rsi), %rsi
	movl	%eax, (%rsi)
LBB3_11:
	jmp	LBB3_12
LBB3_12:
	jmp	LBB3_13
LBB3_13:
	jmp	LBB3_19
LBB3_14:                                ##   in Loop: Header=BB3_1 Depth=1
	movl	-4(%rbp), %eax
	movq	-24(%rbp), %rcx
	movq	(%rcx), %rcx
	cmpl	(%rcx), %eax
	jge	LBB3_16
## %bb.15:                              ##   in Loop: Header=BB3_1 Depth=1
	movq	-24(%rbp), %rax
	movq	(%rax), %rax
	addq	$8, %rax
	movq	%rax, -24(%rbp)
	jmp	LBB3_17
LBB3_16:                                ##   in Loop: Header=BB3_1 Depth=1
	movq	-24(%rbp), %rax
	movq	(%rax), %rax
	addq	$16, %rax
	movq	%rax, -24(%rbp)
LBB3_17:                                ##   in Loop: Header=BB3_1 Depth=1
	jmp	LBB3_18
LBB3_18:                                ##   in Loop: Header=BB3_1 Depth=1
	jmp	LBB3_1
LBB3_19:
	addq	$48, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_print_tree             ## -- Begin function print_tree
	.p2align	4, 0x90
_print_tree:                            ## @print_tree
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	cmpq	$0, -8(%rbp)
	je	LBB4_2
## %bb.1:
	movq	-8(%rbp), %rax
	movq	8(%rax), %rdi
	callq	_print_tree
	leaq	L_.str(%rip), %rdi
	movq	-8(%rbp), %rax
	movl	(%rax), %esi
	movb	$0, %al
	callq	_printf
	movq	-8(%rbp), %rdi
	movq	16(%rdi), %rdi
	movl	%eax, -12(%rbp)         ## 4-byte Spill
	callq	_print_tree
LBB4_2:
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_display_tree           ## -- Begin function display_tree
	.p2align	4, 0x90
_display_tree:                          ## @display_tree
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	leaq	L_.str.1(%rip), %rax
	leaq	L_.str.2(%rip), %rdx
	movq	%rdi, -8(%rbp)
	movl	_display_tree.depth(%rip), %ecx
	addl	$3, %ecx
	movq	%rax, %rdi
	movl	%ecx, %esi
	movb	$0, %al
	callq	_printf
	leaq	L_.str.3(%rip), %rdi
	movq	-8(%rbp), %rdx
	movl	(%rdx), %esi
	movl	%eax, -12(%rbp)         ## 4-byte Spill
	movb	$0, %al
	callq	_printf
	movq	-8(%rbp), %rdx
	cmpq	$0, 8(%rdx)
	movl	%eax, -16(%rbp)         ## 4-byte Spill
	je	LBB5_2
## %bb.1:
	movl	_display_tree.depth(%rip), %eax
	addl	$1, %eax
	movl	%eax, _display_tree.depth(%rip)
	movq	-8(%rbp), %rcx
	movq	8(%rcx), %rdi
	callq	_display_tree
	movl	_display_tree.depth(%rip), %eax
	addl	$-1, %eax
	movl	%eax, _display_tree.depth(%rip)
LBB5_2:
	movq	-8(%rbp), %rax
	cmpq	$0, 16(%rax)
	je	LBB5_4
## %bb.3:
	movl	_display_tree.depth(%rip), %eax
	addl	$1, %eax
	movl	%eax, _display_tree.depth(%rip)
	movq	-8(%rbp), %rcx
	movq	16(%rcx), %rdi
	callq	_display_tree
	movl	_display_tree.depth(%rip), %eax
	addl	$-1, %eax
	movl	%eax, _display_tree.depth(%rip)
LBB5_4:
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
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
	movl	$0, -4(%rbp)
	callq	_init
	movl	$7, %edi
	callq	_add_tree
	movl	$3, %edi
	callq	_add_tree
	movl	$9, %edi
	callq	_add_tree
	movl	$4, %edi
	callq	_add_tree
	movl	$5, %edi
	callq	_add_tree
	movl	$8, %edi
	callq	_add_tree
	movq	_root@GOTPCREL(%rip), %rax
	movq	(%rax), %rdi
	callq	_display_tree
	leaq	L_.str.4(%rip), %rdi
	movb	$0, %al
	callq	_printf
	leaq	L_.str.5(%rip), %rdi
	leaq	-8(%rbp), %rsi
	movl	%eax, -12(%rbp)         ## 4-byte Spill
	movb	$0, %al
	callq	_scanf
	movq	_root@GOTPCREL(%rip), %rsi
	movl	-8(%rbp), %edi
	movl	%eax, -16(%rbp)         ## 4-byte Spill
	callq	_delete_node
	movq	_root@GOTPCREL(%rip), %rsi
	movq	(%rsi), %rdi
	callq	_display_tree
	movq	_root@GOTPCREL(%rip), %rsi
	movq	(%rsi), %rdi
	callq	_print_tree
	leaq	L_.str.6(%rip), %rdi
	movb	$0, %al
	callq	_printf
	xorl	%ecx, %ecx
	movl	%eax, -20(%rbp)         ## 4-byte Spill
	movl	%ecx, %eax
	addq	$32, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.comm	_root,8,3               ## @root
	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"%d "

.zerofill __DATA,__bss,_display_tree.depth,4,2 ## @display_tree.depth
L_.str.1:                               ## @.str.1
	.asciz	"%*s"

L_.str.2:                               ## @.str.2
	.asciz	"-"

L_.str.3:                               ## @.str.3
	.asciz	"{\"%d\"}\n"

L_.str.4:                               ## @.str.4
	.asciz	"Input n: "

L_.str.5:                               ## @.str.5
	.asciz	"%d"

L_.str.6:                               ## @.str.6
	.asciz	"\n"


.subsections_via_symbols
