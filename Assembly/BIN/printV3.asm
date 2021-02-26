.MODEL small
.STACK 100h
.DATA
    num dw 1234;max = 65535
    temp dw ?
.CODE
start:
    mov ax, @data
    mov ds, ax
    mov bx, 10
    mov ax, num
    mov temp, ax
    push -1
pushDigits:
    xor dx,dx
    mov ax,temp
    div bx
    mov temp, ax
    push dx
    cmp temp,0
    JNE pushDigits
print:
    pop bx
    cmp bx,-1
    je exit
    mov dx, bx
    add dl, '0'    
    mov ah, 2
    int 21h
    jmp print
exit:
    mov ax, 4c00h
    int 21h
END start