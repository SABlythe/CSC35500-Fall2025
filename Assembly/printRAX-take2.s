	section .text
	extern	printDigit
	global	printRAX
printRAX:
	push	rax
	push	rbx
	push	rcx
	push	rdx

	mov	rcx, 0		; no digits seen yet
doDigit:	
	mov	rbx, 0xa	;0xa = 10
	mov	rdx, 0x0	;make sure rdx is empty before division
	div	rbx		;divide rax by 10 ... remainder is in rdx

;;instead of immediately printing digit, push onto stack for later
	push	rdx
	inc	rcx		; one more digit seen
	
	cmp	rax, 0
	jne	doDigit

;; here's the "later" part: pop each digit from stack and print. 
printNextDigit:
	pop	rax
	call	printDigit

	dec	rcx		;one less digit to process
	cmp	rcx,0
	jne	printNextDigit


	
	pop	rdx
	pop	rcx
	pop	rbx
	pop	rax
	
	ret
