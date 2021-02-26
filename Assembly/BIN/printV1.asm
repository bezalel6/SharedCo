.MODEL small
.STACK 100h
.DATA
    num dw 65535;max = 65535
    temp dw ?
.CODE
start:
    mov ax, @data
    mov ds, ax
    xor cx,cx
    xor dx,dx
    mov bx, 10
    mov ax, num
    mov temp, ax
pushDigits:
    inc cx
    mov ax,temp
    div bx
    mov temp, ax
    cmp temp,0
    JNE pushDigits
print:
    xor ax,ax
    xor bx,bx
    mov ax,1
    mov temp,cx
    call pow
    mov bx,10
    div bx
    mov cx,temp
    mov bx, ax
    xor ax,ax
    mov ax,num
    div bx
    mov num, dx
    mov dl,al
    add dl, '0'    
    mov ah, 2
    int 21h
    loop print
    jmp exit
pow: 
    mov bx,10
    mul bx
    loop pow
    ret
exit:
    mov ax, 4c00h
    int 21h
END start