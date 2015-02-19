global	_ft_bzero

section .text

_ft_bzero
	mov			rcx, rsi

loop:
	dec			rcx
	cmp			rcx, 0
	jl			exit
	mov			byte[rdi + rcx], 0
	jmp			loop
	
exit:
	ret

	