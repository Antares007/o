	.text
	.intel_syntax noprefix
	.file	"cmp.c"
	.globl	t                               # -- Begin function t
	.p2align	4, 0x90
	.type	t,@function
t:                                      # @t
	.cfi_startproc
# %bb.0:
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset rbp, -16
	mov	rbp, rsp
	.cfi_def_cfa_register rbp
	xor	eax, eax
	pop	rbp
	.cfi_def_cfa rsp, 8
	ret
.Lfunc_end0:
	.size	t, .Lfunc_end0-t
	.cfi_endproc
                                        # -- End function
	.ident	"clang version 11.0.0"
	.section	".note.GNU-stack","",@progbits
	.addrsig
