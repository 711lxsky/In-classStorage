_STACK	SEGMENT STACK
	DW	100 DUP(2)
_STACK	ENDS	
data segment
    info1 db 'this is task1$'
    info2 db 'input name and student_number:$'
    info3 db 'input student_number$'
    info4 db 'input one char$'
    buffer db '$'
data ends

code segment
assume cs:code,ds:data

start:
	;gave address address to AX
	mov ax, data
	; gave AX to DS
	mov ds,ax
	; gave AX to ES
	mov es,ax
	; try to move it
	
	; print info1
	lea dx, ds:info1
	mov ah, 9
	; have a interrupt
	int 21h
	; have a enter
	mov dl, 0Dh
	mov ah, 2
	int 21h
	mov dl, 0Ah
	mov ah, 2
	int 21h
	
	;name and number
	lea dx,ds:info2
	mov ah, 9
	int 21h
	; input
	lea dx, buffer
	mov ah, 0Ah
	mov al, 00h
	int 21h
	; clear cache
	xor bx,bx
	mov bl,[ds:buffer+1]
	mov buffer[bx+2], '$'
	;enter
	mov dl, 0Dh
	mov ah, 2
	int 21h
	mov dl, 0Ah
	mov ah, 2
	int 21h
	; print
	lea dx, [ds:buffer+2]
	mov ah, 09h
	int 21h
	;enter
	mov dl, 0Dh
	mov ah, 2
	int 21h
	mov dl, 0Ah
	mov ah, 2
	int 21h
	

cmpq:
	; enter
	mov dl, 0Dh
	mov ah, 2
	int 21h
	mov dl, 0Ah
	mov ah, 2
	int 21h
	; char
	lea dx, info4
	mov ah, 9
	int 21h
	; enter
	mov dl, 0Dh
	mov ah, 2
	int 21h
	mov dl, 0Ah
	mov ah, 2
	int 21h
	; input and print
	mov ah, 1
	int 21h
	
	cmp al, 'q'
	je ending
	cmp al, 'Q'
	je ending
	; low8 to bl
	mov bl, al
	; high8 to bh
	mov bh, al
	;enter
	; enter
	mov dl, 0Dh
	mov ah, 2
	int 21h
	mov dl, 0Ah
	mov ah, 2
	int 21h
	mov dl, 9
	mov ah, 2
	and bl, 0F0h
	mov cl, 4
	; right move
	shr bl, cl
	cmp bl, 9
	ja alph1
numb1:
	add bl, '0'
	mov dl, bl
	mov ah, 2
	int 21h
	jmp low4
alph1:
;to ascii
	add bl, 37h
	mov dl, bl
	mov ah, 2
	int 21h
low4:
	and bh, 0Fh
	cmp bh, 9
	ja alph2
numb2:
	add bh, '0'
	mov dl, bh
	mov ah, 2
	int 21h
	jmp cmpq
alph2:
	add bh, 37h
	mov dl, bh
	mov ah, 2
	int 21h
	jmp cmpq
ending:
	;enter
	; enter
	mov dl, 0Dh
	mov ah, 2
	int 21h
	mov dl, 0Ah
	mov ah, 2
	int 21h
	; puase
	mov ax, 4c00h
	int 21h
	
code ends
end start
