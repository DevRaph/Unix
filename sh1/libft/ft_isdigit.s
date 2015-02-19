
global _ft_isdigit

section .text

_ft_isdigit:
	cmp		rdi, '0'
	jl		setfalse
	cmp		rdi, '9'
	jg		setfalse

settrue:
	mov		rax, 1
	jmp		exit

setfalse:
	mov		rax, 0

exit:
	ret
