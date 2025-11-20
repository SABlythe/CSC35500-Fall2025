	section .data
_newline:db	0xA

	section .text
	global	printNL
printNL:
	push	rax
	push	rbx
	push	rcx
	push	rdx

	mov	rax, 4		; write a string
	mov	rbx, 1		; write to stdout
	mov	rcx, _newline 
	mov	rdx, 1
	int 	0x80

	pop	rdx
	pop	rcx
	pop	rbx
	pop	rax
	
	ret
