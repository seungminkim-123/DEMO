		section .text
		global _ft_strlen

_ft_strlen:
					xor		rax, rax		; i = 0
					jmp		compare			; jmp명령어 compare로 이동
increse:
					inc		rax				; rax 값 1상승
compare:
					cmp		BYTE [rdi + rax], 0			;비교
					jne		increse			; 같지않으면 점프
done:
					ret						; return i
