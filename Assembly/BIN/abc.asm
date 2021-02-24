MODEL small
STACK 100h
.DATA
    num db 123
    temp db ?
    tempW dw ?
.CODE
start:
    mov ax, @data
    mov ds, ax
    mov bl, 10
    xor cx,cx
    mov al, num
    mov temp, al
setCx:
    xor ax,ax
    inc cx
    mov al,temp
    div bl
    mov temp,al
    cmp temp,0
    JNE setCx

print:
    xor ax,ax
    xor bx,bx
    
    mov ax,10
    mov tempW,cx
    call pow
    mov cx,tempW

    xor bh,bh

    mov bx, ax

    mov al,num
    div bx
    mov num, ah
    mov dl,al
    add dl, '0'    
    mov ah, 2
    int 21h
    loop print
pow: 
    mov bx,10
    mul bx
    cmp ax,1000
    JE zeroCx
    loop pow
    ret
zeroCx:
    xor cx,cx
exit:
    mov ax, 4c00h
    int 21h
END start

