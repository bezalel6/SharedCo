cr equ 13
.MODEL small
.STACK 100h
.DATA
    num DW 0
.CODE
start:
    mov ax, @data
    mov ds, ax
    mov cx,16
    mov ah,1
next:
    int 21h
    cmp al,cr
    je disp
    cmp al,'1'
    je one
    stc
    jmp go
one:
    clc
go:
    rcl num,1
    loop next
disp:
    xor cx,cx
    mov ax,num
    mov bx,10
again:
    xor dx,dx
    div bx
    push dx
    inc cx
    or ax,ax
    jnz again
    mov ah,2
    mov dx,0a0dh
    int 21h
    xchg dl,dh
    int 21h
n_digit:
    pop dx
    add dl,'0'
    int 21h
    loop n_digit
exit:
    mov ah, 4ch
    int 21h
END start