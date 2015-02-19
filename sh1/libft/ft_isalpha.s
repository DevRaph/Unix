global _ft_isalpha

section .text

_ft_isalpha:
	xor			rax, rax

	cmp			rdi, 'A'
	jl			exit
	cmp			rdi, 'Z'
	jg			min
	inc			rax
	jmp			exit

min:
	cmp			rdi, 'a'
	jl			exit
	cmp			rdi, 'z'
	jg			exit
	inc			rax

exit:
	ret