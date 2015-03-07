	.file	"planet.c"
	.local	year
	.comm	year,4,4
	.local	day
	.comm	day,4,4
	.text
	.globl	init
	.type	init, @function
init:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	xorps	%xmm3, %xmm3
	xorps	%xmm2, %xmm2
	xorps	%xmm1, %xmm1
	xorps	%xmm0, %xmm0
	call	glClearColor
	movl	$7424, %edi
	call	glShadeModel
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	init, .-init
	.globl	display
	.type	display, @function
display:
.LFB3:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	$16384, %edi
	call	glClear
	movss	.LC1(%rip), %xmm2
	movss	.LC1(%rip), %xmm1
	movss	.LC1(%rip), %xmm0
	call	glColor3f
	call	glPushMatrix
	movl	$16, %esi
	movl	$20, %edi
	movsd	.LC2(%rip), %xmm0
	call	glutWireSphere
	movl	year(%rip), %eax
	cvtsi2ss	%eax, %xmm0
	xorps	%xmm3, %xmm3
	movss	.LC1(%rip), %xmm2
	xorps	%xmm1, %xmm1
	call	glRotatef
	xorps	%xmm2, %xmm2
	xorps	%xmm1, %xmm1
	movss	.LC3(%rip), %xmm0
	call	glTranslatef
	movl	day(%rip), %eax
	cvtsi2ss	%eax, %xmm0
	xorps	%xmm3, %xmm3
	movss	.LC1(%rip), %xmm2
	xorps	%xmm1, %xmm1
	call	glRotatef
	movabsq	$4596373779694328218, %rax
	movl	$8, %esi
	movl	$10, %edi
	movq	%rax, -8(%rbp)
	movsd	-8(%rbp), %xmm0
	call	glutWireSphere
	call	glPopMatrix
	call	glutSwapBuffers
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3:
	.size	display, .-display
	.globl	reshape
	.type	reshape, @function
reshape:
.LFB4:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	movl	-8(%rbp), %edx
	movl	-4(%rbp), %eax
	movl	%edx, %ecx
	movl	%eax, %edx
	movl	$0, %esi
	movl	$0, %edi
	call	glViewport
	movl	$5889, %edi
	call	glMatrixMode
	call	glLoadIdentity
	cvtsi2ss	-4(%rbp), %xmm0
	cvtsi2ss	-8(%rbp), %xmm1
	divss	%xmm1, %xmm0
	unpcklps	%xmm0, %xmm0
	cvtps2pd	%xmm0, %xmm0
	movabsq	$4626322717216342016, %rdx
	movabsq	$4633641066610819072, %rax
	movq	%rdx, -16(%rbp)
	movsd	-16(%rbp), %xmm3
	movsd	.LC2(%rip), %xmm2
	movapd	%xmm0, %xmm1
	movq	%rax, -16(%rbp)
	movsd	-16(%rbp), %xmm0
	call	gluPerspective
	movl	$5888, %edi
	call	glMatrixMode
	call	glLoadIdentity
	movabsq	$4617315517961601024, %rax
	movl	$0, %edx
	movq	%rdx, (%rsp)
	movsd	.LC2(%rip), %xmm7
	xorpd	%xmm6, %xmm6
	xorpd	%xmm5, %xmm5
	xorpd	%xmm4, %xmm4
	xorpd	%xmm3, %xmm3
	movq	%rax, -16(%rbp)
	movsd	-16(%rbp), %xmm2
	movsd	.LC2(%rip), %xmm1
	xorpd	%xmm0, %xmm0
	call	gluLookAt
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4:
	.size	reshape, .-reshape
	.globl	keyboard
	.type	keyboard, @function
keyboard:
.LFB5:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	%edi, %eax
	movl	%esi, -8(%rbp)
	movl	%edx, -12(%rbp)
	movb	%al, -4(%rbp)
	movzbl	-4(%rbp), %eax
	cmpl	$89, %eax
	je	.L6
	cmpl	$89, %eax
	jg	.L7
	cmpl	$68, %eax
	je	.L8
	jmp	.L11
.L7:
	cmpl	$100, %eax
	je	.L9
	cmpl	$121, %eax
	je	.L10
	jmp	.L11
.L9:
	movl	day(%rip), %eax
	leal	10(%rax), %ecx
	movl	$-1240768329, %edx
	movl	%ecx, %eax
	imull	%edx
	leal	(%rdx,%rcx), %eax
	sarl	$8, %eax
	movl	%eax, %edx
	movl	%ecx, %eax
	sarl	$31, %eax
	subl	%eax, %edx
	movl	%edx, %eax
	imull	$360, %eax, %eax
	subl	%eax, %ecx
	movl	%ecx, %eax
	movl	%eax, day(%rip)
	jmp	.L11
.L8:
	movl	day(%rip), %eax
	leal	-10(%rax), %ecx
	movl	$-1240768329, %edx
	movl	%ecx, %eax
	imull	%edx
	leal	(%rdx,%rcx), %eax
	sarl	$8, %eax
	movl	%eax, %edx
	movl	%ecx, %eax
	sarl	$31, %eax
	subl	%eax, %edx
	movl	%edx, %eax
	imull	$360, %eax, %eax
	subl	%eax, %ecx
	movl	%ecx, %eax
	movl	%eax, day(%rip)
	jmp	.L11
.L10:
	movl	year(%rip), %eax
	leal	5(%rax), %ecx
	movl	$-1240768329, %edx
	movl	%ecx, %eax
	imull	%edx
	leal	(%rdx,%rcx), %eax
	sarl	$8, %eax
	movl	%eax, %edx
	movl	%ecx, %eax
	sarl	$31, %eax
	subl	%eax, %edx
	movl	%edx, %eax
	imull	$360, %eax, %eax
	subl	%eax, %ecx
	movl	%ecx, %eax
	movl	%eax, year(%rip)
	jmp	.L11
.L6:
	movl	year(%rip), %eax
	leal	-5(%rax), %ecx
	movl	$-1240768329, %edx
	movl	%ecx, %eax
	imull	%edx
	leal	(%rdx,%rcx), %eax
	sarl	$8, %eax
	movl	%eax, %edx
	movl	%ecx, %eax
	sarl	$31, %eax
	subl	%eax, %edx
	movl	%edx, %eax
	imull	$360, %eax, %eax
	subl	%eax, %ecx
	movl	%ecx, %eax
	movl	%eax, year(%rip)
	nop
.L11:
	call	glutPostRedisplay
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE5:
	.size	keyboard, .-keyboard
	.globl	main
	.type	main, @function
main:
.LFB6:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	%edi, -4(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-16(%rbp), %rdx
	leaq	-4(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	glutInit
	movl	$2, %edi
	call	glutInitDisplayMode
	movl	$400, %esi
	movl	$400, %edi
	call	glutInitWindowSize
	movl	$100, %esi
	movl	$100, %edi
	call	glutInitWindowPosition
	movq	-16(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, %rdi
	call	glutCreateWindow
	movl	$0, %eax
	call	init
	movl	$display, %edi
	call	glutDisplayFunc
	movl	$reshape, %edi
	call	glutReshapeFunc
	movl	$keyboard, %edi
	call	glutKeyboardFunc
	call	glutMainLoop
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	main, .-main
	.section	.rodata
	.align 4
.LC1:
	.long	1065353216
	.align 8
.LC2:
	.long	0
	.long	1072693248
	.align 4
.LC3:
	.long	1073741824
	.ident	"GCC: (Ubuntu 4.8.2-19ubuntu1) 4.8.2"
	.section	.note.GNU-stack,"",@progbits
