			section .text
			global _ft_strcpy

_ft_strcpy:										; dst = rdi , src = rsi
					xor		rcx, rcx			; i = 0
					xor		rdx, rdx			; tmp = 0
					cmp		rsi, 0
					jz		return
					jmp		copy
incrememt:
					inc		rcx
copy:
					mov		dl, BYTE[rsi + rcx]
					mov		BYTE[rdi + rcx], dl
					cmp		dl, 0
					jnz		incrememt
return:
					mov		rax, rdi
					ret
