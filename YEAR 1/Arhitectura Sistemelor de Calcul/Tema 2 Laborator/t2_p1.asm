.data
	trei: .long 3

	n: .space 4
	a: .space 4
	
	m: .space 4
	
	l: .space 4
	b: .space 4
	
	e: .space 4
	
	k: .space 4
	i: .space 4
	iv: .space 4
	jv: .space 4
	ia: .space 4
	
	str: .space 400
	
	ap: .space 121
	ip: .space 361
	r: .space 361
	
	minus: .asciz "-1"
	formatPrintfm: .asciz "%s\n"
	
	chdelim: .asciz " "
	formatScanf: .asciz "%400[A-Za-z0-9\- ]"
	formatPrintf: .asciz "%d "
	newLine: .asciz "\n"

.text

afis:
	pushl %ebp
	movl %esp,%ebp

	movl $0,ia
	
f_a:
	movl ia,%ebx
	cmp %ebx,l
	je s_afis
	
	lea r,%esi
	movl (%esi,%ebx,4),%eax
	movl %eax,e
	
	pushl e
	pushl $formatPrintf
	call printf
	popl %ebx
	popl %ebx
	
	incl ia
	jmp f_a	
	
s_afis:
	pushl $newLine
	call printf
	popl %ebx
	
	popl %ebp
	ret

valid:
	pushl %ebp
	movl %esp,%ebp
	
	movl k,%ecx

f_ma:
	lea ap,%edx
	movl (%edx,%ebx,4),%eax
	
	cmp $3,%eax
	je s_valid_0
	
f_de:
	movl k,%eax
	subl $1,%eax
	movl %eax,iv
	
	subl m,%eax
	movl %eax,jv

f_de_s:
	movl iv,%ecx
	cmp $0,%ecx
	jl c_f_de
	
	cmp jv,%ecx
	je c_f_de
	
	lea r,%esi
	movl (%esi,%ecx,4),%eax
	movl k,%ecx
	movl (%esi,%ecx,4),%ebx
	
	cmp %eax,%ebx
	je s_valid_0 
	
	decl iv
	jmp f_de_s
	
c_f_de:
	movl k,%eax
	addl $1,%eax
	movl %eax,iv
	
	addl m,%eax
	movl %eax,jv
	
f_de_d:
	movl iv,%ecx
	cmp l,%ecx
	je s_valid_1
	
	cmp jv,%ecx
	je s_valid_1
	
	lea r,%esi
	movl (%esi,%ecx,4),%eax
	movl k,%ecx
	movl (%esi,%ecx,4),%ebx
	
	cmp %eax,%ebx
	je s_valid_0 
	
	incl iv
	jmp f_de_d	

s_valid_0:
	movl $0,%eax
	popl %ebp
	ret

s_valid_1:
	movl $1,%eax
	popl %ebp
	ret

back:
	pushl %ebp
	movl %esp,%ebp
	
	movl k,%ecx
	
	movl $1,i
f_b:
	movl i,%ebx
	cmp %ebx,a
	je s_back
	
	lea ip,%edi
	movl (%edi,%ecx,4),%eax
	
	cmp $0,%eax
	je init_rk
	
	jmp v_final

a_valid:
	call valid
	cmp $0,%eax
	je c_f_b
	
	jmp contor_rk
	
v_final:
	movl k,%ecx
	cmp %ecx,b
	je a_afis
	
	incl k
	call back
	
	jmp egal_rk

b_back:
	decl k
	jmp minus_ap
	
c_f_b:
	incl i
	jmp f_b	
	
init_rk:
	lea r,%esi
	
	movl %ebx, (%esi,%ecx,4)
	jmp a_valid
	
egal_rk:
	movl k,%ecx
	
	lea ip,%edi
	movl (%edi,%ecx,4),%eax
	
	lea r,%esi
	movl (%esi,%ecx,4),%ebx
	
	cmp %eax,%ebx
	jne null_rk
	
	jmp b_back
	
null_rk:
	movl k,%ecx
	
	lea r,%esi
	movl $0, (%esi,%ecx,4)
	
	jmp b_back
	
contor_rk:
	movl k,%ecx
	
	lea r,%esi
	movl (%esi,%ecx,4),%ebx
	
	lea ap,%edx
	
	movl (%edx,%ebx,4),%eax
	addl $1,%eax
	movl %eax, (%edx,%ebx,4)
	jmp v_final

minus_ap:
	movl k,%ecx
	
	lea ip,%edi
	movl (%edi,%ecx,4),%eax
	
	lea r,%esi
	movl (%esi,%ecx,4),%ebx
	
	cmp %eax,%ebx
	jne _contor_rk
	
	jmp s_back
	
_contor_rk:
	lea ap,%edx
	
	movl (%edx,%ebx,4),%eax
	subl $1,%eax
	movl %eax, (%edx,%ebx,4)
	jmp track_b
	
track_b:
	movl k,%ecx
		
	lea r,%esi
	
	movl (%esi,%ecx,4),%ebx
	movl %ebx,i
	jmp c_f_b
	
a_afis:
	call afis
	
	pushl $newLine
	pushl $formatPrintfm
	call printf
	popl %ebx
	popl %ebx
	
	movl $1,%eax
	xorl %ebx,%ebx
	int $0x80
	
s_back:
	popl %ebp
	ret

.global main
main:
	pushl $str
	pushl $formatScanf
	call scanf
	popl %ebx
	popl %ebx

	pushl $chdelim
	pushl $str
	call strtok
	popl %ebx
	popl %ebx
	
	pushl %eax
	
	popl %eax

	pushl %eax
	call atoi
	popl %ebx
	
	movl %eax,n
	
	movl %eax,a
	incl a
	
	mull trei
	movl %eax,l
	
	movl %eax,b
	decl b
	
	pushl $chdelim
	pushl $0
	call strtok
	popl %ebx
	popl %ebx

	pushl %eax
	call atoi
	popl %ebx
	
	movl %eax,m
	
	movl $1,i
	
f_ap:
	movl i,%ebx
	cmp %ebx,a
	je f_e
	
	lea ap,%edx
	movl $0, (%edx,%ebx,4)
	
	incl i
	jmp f_ap

f_e:
	movl $0,i
	
f_tok:
	pushl $chdelim
	pushl $0
	call strtok
	popl %ebx
	popl %ebx
	
	cmp $0,%eax
	je a_back
	
	pushl %eax
	call atoi
	popl %ebx
		
	movl i,%ebx
		
	lea ip,%edi
	movl %eax, (%edi,%ebx,4)
		
	lea r,%esi
	movl %eax, (%esi,%ebx,4)
		
	lea ap,%edx
	movl (%edx,%eax,4),%ebx
	addl $1,%ebx
	movl %ebx, (%edx,%eax,4)
		
	incl i
	jmp f_tok
	
a_back:	
	movl $0,k
	call back	
	
m_exit:
	pushl $minus
	pushl $formatPrintfm
	call printf
	popl %ebx
	popl %ebx
	
	movl $1,%eax
	xorl %ebx,%ebx
	int $0x80