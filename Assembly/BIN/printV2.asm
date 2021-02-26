.MODEL small
.STACK 100h
.DATA
    num dw 1;max = 65535
    temp dw ?
    num db 6 dup (-1)
.CODE
start:
    mov ax, @data
    mov ds, ax
    xor dx,dx
    mov bx, 10
    mov ax, num
    mov temp, ax
    mov di, offset num
pushDigits:
    xor dx,dx
    mov ax,temp
    div bx
    mov temp, ax
    mov [di],dl
    inc di
    cmp temp,0
    JNE pushDigits
    dec di
print:
    mov dl, [di]
    add dl, '0'    
    mov ah, 2
    int 21h
    dec di
    cmp di, offset num-1
    jne checkMinus
    jmp exit
checkMinus:
    cmp [di],BYTE PTR -1
    jne print
exit:
    mov ax, 4c00h
    int 21h
END start