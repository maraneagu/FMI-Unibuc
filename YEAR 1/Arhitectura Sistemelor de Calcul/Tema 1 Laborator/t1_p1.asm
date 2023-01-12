.data
	sir: .space 101
	x: .space 4
	y: .space 4
	xy: .space 4
	hexa: .long 16
	variabila: .long 0
	negativ: .long 0
	
	minus: .asciz "-"
	space: .asciz " "
	
	let: .asciz "let "
	add: .asciz "add "
	sub: .asciz "sub "
	mul: .asciz "mul "
	div: .asciz "div "
	
	formatScanf: .asciz "%s"
	
	formatVar: .asciz "%s "
	formatOp: .asciz "%s"
	formatNr: .asciz "%d "
	newLine: .asciz "\n"

.text
.global main
main:
	pushl $sir
	pushl $formatScanf
	call scanf
	popl %ebx
	popl %ebx
	
	movl $sir,%edi
	xorl %ecx,%ecx
	
et_for:
	movb (%edi,%ecx,1),%al
	
	cmp $0,%al
	je et_exit
	
	cmp $56,%al
	je et_8_pozitiv
	
	cmp $57,%al
	je et_9_negativ
	
	cmp $65,%al
	je et_A_variabila
	
	cmp $67,%al
	je et_C_operatie
	
cont:
	addl $3,%ecx
	jmp et_for
	
et_8_pozitiv:
	pushl %ecx
	
	incl %ecx
	movb (%edi,%ecx,1),%al
	movl %eax,x
	
	cmp $65,x
	jae et_A_F_x
	jmp et_0_9_x
	
cont_8:
	incl %ecx
	movb (%edi,%ecx,1),%al
	movl %eax,y
	
	cmp $65,y
	jae et_A_F_y
	jmp et_0_9_y	
	
et_0_9_x:
	subl $48,x
	
	movl x,%eax
	xorl %edx,%edx
	mull hexa
	movl %eax,x
	jmp cont_8
	
et_A_F_x:
	subl $55,x
	
	movl x,%eax
	xorl %edx,%edx
	mull hexa
	movl %eax,x
	jmp cont_8
	
et_0_9_y:
	subl $48,y
	
	movl x,%eax
	movl y,%ebx
	addl %ebx,%eax
	movl %eax,xy
	jmp et_afisare
	
et_A_F_y:
	subl $55,y
	
	movl x,%eax
	movl y,%ebx
	addl %ebx,%eax
	movl %eax,xy
	jmp et_afisare
		
et_9_negativ:
	movl $1,negativ
	jmp et_8_pozitiv
	
et_A_variabila:
	movl $1,variabila
	jmp et_8_pozitiv
	
et_C_operatie:
	pushl %ecx
	
	addl $2,%ecx
	movb (%edi,%ecx,1),%al
	
	cmp $48,%al
	je et_C_let
	
	cmp $49,%al
	je et_C_add
	
	cmp $50,%al
	je et_C_sub
	
	cmp $51,%al
	je et_C_mul
	
	cmp $52,%al
	je et_C_div
	
et_C_let:
	pushl $let
	pushl $formatOp
	call printf
	popl %ebx
	popl %ebx
	
	pushl $0
	call fflush
	popl %ebx
	
	popl %ecx
	jmp cont
	
et_C_add:
	pushl $add
	pushl $formatOp
	call printf
	popl %ebx
	popl %ebx
	
	pushl $0
	call fflush
	popl %ebx
	
	popl %ecx
	jmp cont
	
et_C_sub:
	pushl $sub
	pushl $formatOp
	call printf
	popl %ebx
	popl %ebx
	
	pushl $0
	call fflush
	popl %ebx
	
	popl %ecx
	jmp cont
	
et_C_mul:
	pushl $mul
	pushl $formatOp
	call printf
	popl %ebx
	popl %ebx
	
	pushl $0
	call fflush
	popl %ebx
	
	popl %ecx
	jmp cont
	
et_C_div:
	pushl $div
	pushl $formatOp
	call printf
	popl %ebx
	popl %ebx
	
	pushl $0
	call fflush
	popl %ebx
	
	popl %ecx
	jmp cont
	
et_afisare:
	cmp $1,variabila
	je afis_variabila

	cmp $0,negativ
	je afis_nr_pozitiv
	jmp afis_nr_negativ	
	
afis_nr_pozitiv:
	pushl xy
	pushl $formatNr
	call printf
	popl %ebx
	popl %ebx
	
	pushl $0
	call fflush
	popl %ebx
	
	popl %ecx
	jmp cont
	
afis_nr_negativ:
	pushl $minus
	pushl $formatOp
	call printf
	popl %ebx
	popl %ebx

	pushl xy
	pushl $formatNr
	call printf
	popl %ebx
	popl %ebx
	
	pushl $0
	call fflush
	popl %ebx
	
	movl $0,negativ
	popl %ecx
	jmp cont
	
afis_variabila:
	pushl $xy
	pushl $formatVar
	call printf
	popl %ebx
	popl %ebx
	
	pushl $0
	call fflush
	popl %ebx
	
	movl $0,variabila
	popl %ecx
	jmp cont
	
et_exit:
	pushl $newLine
	call printf
	popl %ebx

	movl $1,%eax
	xorl %ebx,%ebx
	int $0x80