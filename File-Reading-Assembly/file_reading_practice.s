	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 15, 0	sdk_version 15, 4
	.globl	_main                           ; -- Begin function main
	.p2align	2
_main:                                  ; @main
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #64
	stp	x29, x30, [sp, #48]             ; 16-byte Folded Spill
	add	x29, sp, #48
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	stur	wzr, [x29, #-4]
	stur	w0, [x29, #-8]
	stur	x1, [x29, #-16]
	ldur	w8, [x29, #-8]
	subs	w8, w8, #2
	b.eq	LBB0_2
	b	LBB0_1
LBB0_1:
	adrp	x0, l_.str@PAGE
	add	x0, x0, l_.str@PAGEOFF
	bl	_printf
	ldur	x8, [x29, #-16]
	ldr	x8, [x8]
	mov	x9, sp
	str	x8, [x9]
	adrp	x0, l_.str.1@PAGE
	add	x0, x0, l_.str.1@PAGEOFF
	bl	_printf
	mov	w8, #1                          ; =0x1
	stur	w8, [x29, #-4]
	b	LBB0_8
LBB0_2:
	ldur	x8, [x29, #-16]
	ldr	x0, [x8, #8]
	adrp	x1, l_.str.2@PAGE
	add	x1, x1, l_.str.2@PAGEOFF
	bl	_fopen
	str	x0, [sp, #24]
	ldr	x8, [sp, #24]
	cbnz	x8, LBB0_4
	b	LBB0_3
LBB0_3:
	adrp	x0, l_.str.3@PAGE
	add	x0, x0, l_.str.3@PAGEOFF
	bl	_printf
	mov	w0, #1                          ; =0x1
	bl	_exit
LBB0_4:
	mov	x0, #1024                       ; =0x400
	bl	_malloc
	str	x0, [sp, #16]
	b	LBB0_5
LBB0_5:                                 ; =>This Inner Loop Header: Depth=1
	ldr	x0, [sp, #16]
	ldr	x2, [sp, #24]
	mov	w1, #1024                       ; =0x400
	bl	_fgets
	cbz	x0, LBB0_7
	b	LBB0_6
LBB0_6:                                 ;   in Loop: Header=BB0_5 Depth=1
	ldr	x8, [sp, #16]
	mov	x9, sp
	str	x8, [x9]
	adrp	x0, l_.str.4@PAGE
	add	x0, x0, l_.str.4@PAGEOFF
	bl	_printf
	b	LBB0_5
LBB0_7:
	ldr	x0, [sp, #16]
	bl	_free
	ldr	x0, [sp, #24]
	bl	_fclose
	stur	wzr, [x29, #-4]
	b	LBB0_8
LBB0_8:
	ldur	w0, [x29, #-4]
	ldp	x29, x30, [sp, #48]             ; 16-byte Folded Reload
	add	sp, sp, #64
	ret
	.cfi_endproc
                                        ; -- End function
	.section	__TEXT,__cstring,cstring_literals
l_.str:                                 ; @.str
	.asciz	"You must pass in at least one argument\n"

l_.str.1:                               ; @.str.1
	.asciz	"Example: %s file_name\n"

l_.str.2:                               ; @.str.2
	.asciz	"r"

l_.str.3:                               ; @.str.3
	.asciz	"Error opening file\n"

l_.str.4:                               ; @.str.4
	.asciz	"%s"

.subsections_via_symbols
