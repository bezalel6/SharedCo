.MODEL small
.STACK 100h
.DATA
    arr dw 8 dup(2000,1125,5867,11777,76,31,67,121)
    res dw 0
.CODE
start:
    mov ax, @data
    mov ds, ax
    mov di, offset arr
    mov cx, length arr
sum:
    mov ax, [di]
    add res,ax
    add di,2
    loop sum
divide:
    xor dx,dx
    mov ax, res
    mov bx, length arr
    div bx
    mov res, ax
exit:
    mov ah, 4ch
    int 21h
END start