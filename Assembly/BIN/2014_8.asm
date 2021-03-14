.MODEL small
.STACK 100h
.DATA
    A db 5,8,9
    LEN=$-A
    P DW A,LEN
.CODE
start:s
    mov ax, @data
    mov ds, ax
    push P
    push P+2
    call trouble
    mov ah, 2
    mov di, offset A
    mov cx, LEN
print:
    mov dl, [di]
    add dl,'0'
    int 21h
    inc di
    loop print
sof:
    mov ah,4ch
    int 21h
trouble:
    push bp
    mov bp,sp
chazor:
    mov cx,[bp+4]
    dec cx
    xor si,si
    mov bx,[bp+6]
again:
    mov al,[bx]
    cmp al,[bx+1]
    jbe con
    xchg al,[bx+1]
    mov [bx],al
    inc si
con:
    inc bx
    loop again
    or si,si
    jne chazor
    pop bp
    ret 4
END start