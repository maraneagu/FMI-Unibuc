.data
	zece: .long 10
	negativ: .long 0
	sir: .space 101
	matrix: .space 1600
	n: .space 4
	m: .space 4
	elem: .space 4
	i: .space 4
	j: .space 4
	r: .space 4
	
	x: .space 1
	numar: .space 4
	res: .space 4
	
	formatScanfNume: .asciz "%s"
	formatScanfSir: .asciz "%101[A-Za-z0-9-\ ]"
	formatScanfLinCol: .asciz "%d"
	formatPrintfElem: .asciz "%d "
	newLine: .asciz "\n"
	chdelim: .asciz " "
	
.text
.global main
main:
	pushl $x
	pushl $formatScanfNume
	call scanf
	popl %ebx
	popl %ebx
		
	pushl $n
	pushl $formatScanfLinCol
	call scanf
	popl %ebx
	popl %ebx
	
	pushl $m
	pushl $formatScanfLinCol
	call scanf
	popl %ebx
	popl %ebx
	
movl $0,i
et_for_i:
	movl i,%ebx
	cmp %ebx,n
	je cont_citire
	
	movl $0,j
	et_for_j:
		movl j,%ebx
		cmp %ebx,m
		je cont_et_for_i
		
		pushl $elem
		pushl $formatScanfLinCol
		call scanf
		popl %ebx
		popl %ebx
		
		movl elem,%ebx
		
		movl i,%eax
		xorl %edx,%edx
		mull m
		addl j,%eax
		
		lea matrix,%edi
		movl %ebx, (%edi,%eax,4)
		
		incl j
		jmp et_for_j
		
cont_et_for_i:	
	incl i
	jmp et_for_i
	
cont_citire:
	pushl $sir
	pushl $formatScanfSir
	call scanf
	popl %ebx
	popl %ebx
	
	pushl $chdelim
	pushl $sir
	call strtok
	popl %ebx
	popl %ebx
	
	movl %eax,res
	movl res,%edi
	xorl %ecx,%ecx
	
	xorl %eax,%eax
	jmp et_ver
	
et_strtok:
	pushl $chdelim
	pushl $0
	call strtok
	popl %ebx
	popl %ebx
	
	cmp $0,%eax
	je et_afis_matrix
	
	movl %eax,res
	movl res,%edi
	xorl %ecx,%ecx
	
	xorl %eax,%eax
	jmp et_ver
	
et_ver:
	movb (%edi,%ecx,1),%dl
	
	cmp $97,%dl
	jae et_operatie
	
	cmp $45,%dl
	je et_negativ
	
	jmp et_pozitiv
	
et_pozitiv:
	jmp et_x
	
cont_y:
	incl %ecx
	movb (%edi,%ecx,1),%dl
	
	cmp $0,%dl
	je et_numar
	jmp et_y
	
cont_z:
	incl %ecx
	movb (%edi,%ecx,1),%dl
	
	cmp $0,%dl
	je et_numar
	jmp et_z
	
et_numar:
	movl negativ,%ebx
	cmp $1,%ebx
	je et_minus

	movl %eax,numar
	jmp et_strtok
	
et_x:
	cmp $48,%dl
	je et_x_0
	cmp $49,%dl
	je et_x_1
	cmp $50,%dl
	je et_x_2
	cmp $51,%dl
	je et_x_3
	cmp $52,%dl
	je et_x_4
	cmp $53,%dl
	je et_x_5
	cmp $54,%dl
	je et_x_6
	cmp $55,%dl
	je et_x_7
	cmp $56,%dl
	je et_x_8
	cmp $57,%dl
	je et_x_9
	
et_x_0:
	movl $0,%eax
	jmp cont_y
et_x_1:
	movl $1,%eax
	jmp cont_y
et_x_2:
	movl $2,%eax
	jmp cont_y
et_x_3:
	movl $3,%eax
	jmp cont_y
et_x_4:
	movl $4,%eax
	jmp cont_y
et_x_5:
	movl $5,%eax
	jmp cont_y
et_x_6:
	movl $6,%eax
	jmp cont_y
et_x_7:
	movl $7,%eax
	jmp cont_y
et_x_8:
	movl $8,%eax
	jmp cont_y
et_x_9:
	movl $9,%eax
	jmp cont_y
	
et_y:
	cmp $48,%dl
	je et_y_0
	cmp $49,%dl
	je et_y_1
	cmp $50,%dl
	je et_y_2
	cmp $51,%dl
	je et_y_3
	cmp $52,%dl
	je et_y_4
	cmp $53,%dl
	je et_y_5
	cmp $54,%dl
	je et_y_6
	cmp $55,%dl
	je et_y_7
	cmp $56,%dl
	je et_y_8
	cmp $57,%dl
	je et_y_9

et_y_0:
	mull zece
	addl $0,%eax
	jmp cont_z
et_y_1:
	mull zece
	addl $1,%eax
	jmp cont_z
et_y_2:
	mull zece
	addl $2,%eax
	jmp cont_z
et_y_3:
	mull zece
	addl $3,%eax
	jmp cont_z
et_y_4:
	mull zece
	addl $4,%eax
	jmp cont_z
et_y_5:
	mull zece
	addl $5,%eax
	jmp cont_z
et_y_6:
	mull zece
	addl $6,%eax
	jmp cont_z
et_y_7:
	mull zece
	addl $7,%eax
	jmp cont_z
et_y_8:
	mull zece
	addl $8,%eax
	jmp cont_z
et_y_9:
	mull zece
	addl $9,%eax
	jmp cont_z
	
et_z:
	cmp $48,%dl
	je et_z_0
	cmp $49,%dl
	je et_z_1
	cmp $50,%dl
	je et_z_2
	cmp $51,%dl
	je et_z_3
	cmp $52,%dl
	je et_z_4
	cmp $53,%dl
	je et_z_5
	cmp $54,%dl
	je et_z_6
	cmp $55,%dl
	je et_z_7
	cmp $56,%dl
	je et_z_8
	cmp $57,%dl
	je et_z_9
	
et_z_0:
	mull zece
	addl $0,%eax
	jmp et_numar
et_z_1:
	mull zece
	addl $1,%eax
	jmp et_numar
et_z_2:
	mull zece
	addl $2,%eax
	jmp et_numar
et_z_3:
	mull zece
	addl $3,%eax
	jmp et_numar
et_z_4:
	mull zece
	addl $4,%eax
	jmp et_numar
et_z_5:
	mull zece
	addl $5,%eax
	jmp et_numar
et_z_6:
	mull zece
	addl $6,%eax
	jmp et_numar
et_z_7:
	mull zece
	addl $7,%eax
	jmp et_numar
et_z_8:
	mull zece
	addl $8,%eax
	jmp et_numar
et_z_9:
	mull zece
	addl $9,%eax
	jmp et_numar
	
et_negativ:
	movl $1,negativ
	incl %ecx
	movb (%edi,%ecx,1),%dl
	jmp et_pozitiv
	
et_minus:
	movl %eax,%ebx
	subl %ebx,%eax
	subl %ebx,%eax
	movl %eax,numar
	jmp et_strtok
	
et_operatie:
	cmp $97,%dl
	je et_add
	
	cmp $114,%dl
	je et_rot90d
	
	cmp $108,%dl
	je et_strtok
	
	cmp $100,%dl
	je et_div
	
	cmp $109,%dl
	je et_mul
	
	cmp $115,%dl
	je et_sub
	
et_add:
	movl $0,i
	et_for_i_add:
		movl i,%ebx
		cmp %ebx,n
		je et_strtok
		
		movl $0,j
		et_for_j_add:
			movl j,%ebx
			cmp %ebx,m
			je cont_et_for_i_add
			
			movl i,%eax
			xorl %edx,%edx
			mull m
			addl j,%eax
			
			lea matrix,%edi
			movl (%edi,%eax,4),%ebx
			addl numar,%ebx
			movl %ebx, (%edi,%eax,4)
			
			incl j
			jmp et_for_j_add
			
	cont_et_for_i_add:	
		incl i
		jmp et_for_i_add
		
et_mul:
	movl $0,i
	et_for_i_mul:
		movl i,%ebx
		cmp %ebx,n
		je et_strtok
		
		movl $0,j
		et_for_j_mul:
			movl j,%ebx
			cmp %ebx,m
			je cont_et_for_i_mul
			
			movl i,%eax
			xorl %edx,%edx
			mull m
			addl j,%eax
			
			movl %eax,%ebx
			
			lea matrix,%edi
			movl (%edi,%ebx,4),%eax
			
			imull numar
			movl %eax, (%edi,%ebx,4)
			
			incl j
			jmp et_for_j_mul
			
	cont_et_for_i_mul:	
		incl i
		jmp et_for_i_mul
		
et_div:
	movl $0,i
	et_for_i_div:
		movl i,%ebx
		cmp %ebx,n
		je et_strtok
		
		movl $0,j
		et_for_j_div:
			movl j,%ebx
			cmp %ebx,m
			je cont_et_for_i_div
			
			movl i,%eax
			xorl %edx,%edx
			mull m
			addl j,%eax
			
			movl %eax,%ebx
			
			lea matrix,%edi
			movl (%edi,%ebx,4),%eax
			
			cmp $0,%eax
			jl et_div_negativ
			
			pushl %edx
			xorl %edx,%edx
			idivl numar
			popl %edx
			
		cont_et_for_j_div:	
			movl %eax, (%edi,%ebx,4)
			
			incl j
			jmp et_for_j_div
			
	cont_et_for_i_div:	
		incl i
		jmp et_for_i_div
		
et_div_negativ:
	pushl %ebx
	
	movl %eax,%ebx
	subl %ebx,%eax
	subl %ebx,%eax
	
	xorl %edx,%edx
	idivl numar
	
	movl %eax,%ebx
	subl %ebx,%eax
	subl %ebx,%eax
	
	popl %ebx
	jmp cont_et_for_j_div
		
et_sub:
	movl $0,i
	et_for_i_sub:
		movl i,%ebx
		cmp %ebx,n
		je et_strtok
		
		movl $0,j
		et_for_j_sub:
			movl j,%ebx
			cmp %ebx,m
			je cont_et_for_i_sub
			
			movl i,%eax
			xorl %edx,%edx
			mull m
			addl j,%eax
			
			lea matrix,%edi
			movl (%edi,%eax,4),%ebx
			subl numar,%ebx
			movl %ebx, (%edi,%eax,4)
			
			incl j
			jmp et_for_j_sub
			
	cont_et_for_i_sub:	
		incl i
		jmp et_for_i_sub
		
et_rot90d:
	pushl m
	pushl $formatPrintfElem
	call printf
	popl %ebx
	popl %ebx
	
	pushl $0
	call fflush
	popl %ebx
	
	pushl n
	pushl $formatPrintfElem
	call printf
	popl %ebx
	popl %ebx
	
	pushl $0
	call fflush
	popl %ebx

	movl $0,j
	for_j_rot:
		movl j,%ebx
		cmp %ebx,m
		je et_exit
		
		movl $0,i
		for_i_rot:
			movl i,%ebx
			cmp %ebx,n
			je cont_for_j_rot
			
			movl n,%ebx
			subl i,%ebx
			subl $1,%ebx
			movl %ebx,r
			
			movl r,%eax
			xorl %edx,%edx
			mull m
			addl j,%eax
			
			lea matrix,%edi
			movl (%edi,%eax,4),%ebx
			
			pushl %ebx
			pushl $formatPrintfElem
			call printf
			popl %ebx
			popl %ebx
			
			incl i
			jmp for_i_rot
			
	cont_for_j_rot:
		incl j
		jmp for_j_rot
		
et_afis_matrix:
	pushl n
	pushl $formatPrintfElem
	call printf
	popl %ebx
	popl %ebx
	
	pushl $0
	call fflush
	popl %ebx
	
	pushl m
	pushl $formatPrintfElem
	call printf
	popl %ebx
	popl %ebx
	
	pushl $0
	call fflush
	popl %ebx

	movl $0,i
	for_i:
		movl i,%ebx
		cmp %ebx,n
		je et_exit
		
		movl $0,j
		for_j:
			movl j,%ebx
			cmp %ebx,m
			je cont_for_i
			
			movl i,%eax
			xorl %edx,%edx
			mull m
			addl j,%eax
			
			lea matrix,%edi
			movl (%edi,%eax,4),%ebx
			
			pushl %ebx
			pushl $formatPrintfElem
			call printf
			popl %ebx
			popl %ebx
			
			pushl $0
			call fflush
			popl %ebx
				
			incl j
			jmp for_j
		
	cont_for_i:
		incl i
		jmp for_i
	
et_exit:
	pushl $newLine
	call printf
	popl %ebx

	movl $1,%eax
	xorl %ebx,%ebx
	int $0x80