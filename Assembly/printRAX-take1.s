	section .text
	extern	printDigit
	global	printRAX
printRAX:
	push	rax
	push	rbx
	push	rdx

doDigit:	
	mov	rbx, 0xa	;0xa = 10
	mov	rdx, 0x0	;make sure rdx is empty before division
	div	rbx		;divide rax by 10 ... remainder is in rdx

	push	rax		; remeber rax value for next pass
	mov	rax,rdx
	call	printDigit
	pop	rax		; recall rax value for next pass
	
	cmp	rax, 0
	jne	doDigit

	pop	rdx
	pop	rbx
	pop	rax
	
	ret
