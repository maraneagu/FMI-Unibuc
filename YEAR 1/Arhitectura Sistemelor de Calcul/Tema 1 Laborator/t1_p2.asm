.data
	
	sir: .space 101
	res: .space 4
	zece: .long 10
	index_stiva: .long 0
	
	chdelim: .asciz " "
	formatScanf: .asciz "%101[A-Za-z0-9\- ]"
	formatPrintf: .asciz "%d\n"
	
.text
.global main
main:

	pushl $sir
	pushl $formatScanf
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
	je et_exit
	
	movl %eax,res
	movl res,%edi
	xorl %ecx,%ecx
	
	xorl %eax,%eax
	jmp et_ver
	
et_ver:
	movb (%edi,%ecx,1),%dl
	
	cmp $97,%dl
	je et_add
	
	cmp $100,%dl
	je et_div
	
	cmp $109,%dl
	je et_mul
	
	cmp $115,%dl
	je et_sub
	
	jmp et_x

cont_y:
	incl %ecx
	movb (%edi,%ecx,1),%dl
	
	cmp $0,%dl
	je adaug_la_stiva
	jmp et_y
	
cont_z:
	incl %ecx
	movb (%edi,%ecx,1),%dl
	
	cmp $0,%dl
	je adaug_la_stiva
	jmp et_z
	
adaug_la_stiva:
	pushl %eax
	incl index_stiva
	jmp et_strtok
	
et_add:
	popl %eax
	popl %ebx
	addl %ebx,%eax
	pushl %eax
	sub $1,index_stiva
	jmp et_strtok
	
et_mul:
	popl %eax
	popl %ebx
	mull %ebx
	pushl %eax
	sub $1,index_stiva	
	jmp et_strtok
	
et_div:
	popl %ebx
	popl %eax
	
	pushl %edx
	xorl %edx,%edx
	div %ebx
	popl %edx
	
	pushl %eax
	sub $1,index_stiva		
	jmp et_strtok
	
et_sub:
	popl %ebx
	popl %eax
	subl %ebx,%eax
	pushl %eax
	sub $1,index_stiva
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
	jmp adaug_la_stiva
et_z_1:
	mull zece
	addl $1,%eax
	jmp adaug_la_stiva
et_z_2:
	mull zece
	addl $2,%eax
	jmp adaug_la_stiva
et_z_3:
	mull zece
	addl $3,%eax
	jmp adaug_la_stiva
et_z_4:
	mull zece
	addl $4,%eax
	jmp adaug_la_stiva
et_z_5:
	mull zece
	addl $5,%eax
	jmp adaug_la_stiva
et_z_6:
	mull zece
	addl $6,%eax
	jmp adaug_la_stiva
et_z_7:
	mull zece
	addl $7,%eax
	jmp adaug_la_stiva
et_z_8:
	mull zece
	addl $8,%eax
	jmp adaug_la_stiva
et_z_9:
	mull zece
	addl $9,%eax
	jmp adaug_la_stiva			
	
et_exit:
	xorl %eax,%eax
	popl %eax
	
	pushl %eax
	pushl $formatPrintf
	call printf
	popl %ebx
	popl %ebx
	
	movl $1,%eax
	xorl %ebx,%ebx
	int $0x80