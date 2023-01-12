.data

	sir: .space 101
	res: .space 4
	zece: .long 10
	lungime: .space 4
	index_stiva: .long 0
	
	a: .long 97
	b: .long 98
	c: .long 99
	d: .long 100
	e: .long 101
	f: .long 102
	g: .long 103
	h: .long 104
	i: .long 105
	j: .long 106
	k: .long 107
	l: .long 108
	m: .long 109
	n: .long 110
	o: .long 111
	p: .long 112
	q: .long 113
	r: .long 114
	s: .long 115
	t: .long 116
	u: .long 117
	v: .long 118
	w: .long 119
	x: .long 120
	y: .long 121
	z: .long 122
	
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
	jae et_strlen
	
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
	
et_strlen:
	pushl %edx
	
	pushl res
	call strlen
	popl %ebx
	
	popl %edx
	movl %eax,lungime
	xorl %eax,%eax
	
	cmp $1,lungime
	je et_variabila
	jmp et_operatie
	
et_variabila:
	cmp $97,%dl
	je als_a
	cmp $98,%dl
	je als_b
	cmp $99,%dl
	je als_c
	cmp $100,%dl
	je als_d
	cmp $101,%dl
	je als_e
	cmp $102,%dl
	je als_f
	cmp $103,%dl
	je als_g
	cmp $104,%dl
	je als_h
	cmp $105,%dl
	je als_i
	cmp $106,%dl
	je als_j
	cmp $107,%dl
	je als_k
	cmp $108,%dl
	je als_l
	cmp $109,%dl
	je als_m
	cmp $110,%dl
	je als_n
	cmp $111,%dl
	je als_o
	cmp $112,%dl
	je als_p
	cmp $113,%dl
	je als_q
	cmp $114,%dl
	je als_r
	cmp $115,%dl
	je als_s
	cmp $116,%dl
	je als_t
	cmp $117,%dl
	je als_u
	cmp $118,%dl
	je als_v
	cmp $119,%dl
	je als_w
	cmp $120,%dl
	je als_x
	cmp $121,%dl
	je als_y
	cmp $122,%dl
	je als_z

als_a:
	pushl a
	incl index_stiva
	jmp et_strtok
als_b:
	pushl b
	incl index_stiva
	jmp et_strtok
als_c:
	pushl c
	incl index_stiva
	jmp et_strtok
als_d:
	pushl d
	incl index_stiva
	jmp et_strtok
als_e:
	pushl e
	incl index_stiva
	jmp et_strtok
als_f:
	pushl f
	incl index_stiva
	jmp et_strtok
als_g:
	pushl g
	incl index_stiva
	jmp et_strtok
als_h:
	pushl h
	incl index_stiva
	jmp et_strtok
als_i:
	pushl i
	incl index_stiva
	jmp et_strtok
als_j:
	pushl j
	incl index_stiva
	jmp et_strtok	
als_k:
	pushl k
	incl index_stiva
	jmp et_strtok
als_l:
	pushl l
	incl index_stiva
	jmp et_strtok
als_m:
	pushl m
	incl index_stiva
	jmp et_strtok
als_n:
	pushl n
	incl index_stiva
	jmp et_strtok
als_o:
	pushl o
	incl index_stiva
	jmp et_strtok
als_p:
	pushl p
	incl index_stiva
	jmp et_strtok
als_q:
	pushl q
	incl index_stiva
	jmp et_strtok
als_r:
	pushl r
	incl index_stiva
	jmp et_strtok
als_s:
	pushl s
	incl index_stiva
	jmp et_strtok
als_t:
	pushl t
	incl index_stiva
	jmp et_strtok
als_u:
	pushl u
	incl index_stiva
	jmp et_strtok
als_v:
	pushl v
	incl index_stiva
	jmp et_strtok
als_w:
	pushl w
	incl index_stiva
	jmp et_strtok
als_x:
	pushl x
	incl index_stiva
	jmp et_strtok
als_y:
	pushl y
	incl index_stiva
	jmp et_strtok
als_z:
	pushl z
	incl index_stiva
	jmp et_strtok
	
et_operatie:
	cmp $97,%dl
	je et_add
	
	cmp $100,%dl
	je et_div
	
	cmp $108,%dl
	je et_let
	
	cmp $109,%dl
	je et_mul
	
	cmp $115,%dl
	je et_sub
	
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
	
et_let:
	popl %ebx
	popl %eax
	sub $2,index_stiva
	
	cmp $97,%eax
	je init_a
	cmp $98,%eax
	je init_b
	cmp $99,%eax
	je init_c
	cmp $100,%eax
	je init_d
	cmp $101,%eax
	je init_e
	cmp $102,%eax
	je init_f
	cmp $103,%eax
	je init_g
	cmp $104,%eax
	je init_h
	cmp $105,%eax
	je init_i
	cmp $106,%eax
	je init_j
	cmp $107,%eax
	je init_k
	cmp $108,%eax
	je init_l
	cmp $109,%eax
	je init_m
	cmp $110,%eax
	je init_n
	cmp $111,%eax
	je init_o
	cmp $112,%eax
	je init_p
	cmp $113,%eax
	je init_q
	cmp $114,%eax
	je init_r
	cmp $115,%eax
	je init_s
	cmp $116,%eax
	je init_t
	cmp $117,%eax
	je init_u
	cmp $118,%eax
	je init_v
	cmp $119,%eax
	je init_w
	cmp $120,%eax
	je init_x
	cmp $120,%eax
	je init_x
	cmp $121,%eax
	je init_y
	cmp $122,%eax
	je init_z
	
init_a:
	movl %ebx,a
	jmp et_strtok
init_b:
	movl %ebx,b
	jmp et_strtok
init_c:
	movl %ebx,c
	jmp et_strtok
init_d:
	movl %ebx,d
	jmp et_strtok
init_e:
	movl %ebx,e
	jmp et_strtok
init_f:
	movl %ebx,f
	jmp et_strtok
init_g:
	movl %ebx,g
	jmp et_strtok
init_h:
	movl %ebx,h
	jmp et_strtok
init_i:
	movl %ebx,i
	jmp et_strtok
init_j:
	movl %ebx,j
	jmp et_strtok
init_k:
	movl %ebx,k
	jmp et_strtok
init_l:
	movl %ebx,l
	jmp et_strtok
init_m:
	movl %ebx,m
	jmp et_strtok
init_n:
	movl %ebx,n
	jmp et_strtok
init_o:
	movl %ebx,o
	jmp et_strtok
init_p:
	movl %ebx,p
	jmp et_strtok
init_q:
	movl %ebx,q
	jmp et_strtok
init_r:
	movl %ebx,r
	jmp et_strtok
init_s:
	movl %ebx,s
	jmp et_strtok
init_t:
	movl %ebx,t
	jmp et_strtok
init_u:
	movl %ebx,u
	jmp et_strtok
init_v:
	movl %ebx,v
	jmp et_strtok
init_w:
	movl %ebx,w
	jmp et_strtok
init_x:
	movl %ebx,x
	jmp et_strtok
init_y:
	movl %ebx,y
	jmp et_strtok
init_z:
	movl %ebx,z
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