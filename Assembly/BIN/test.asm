.MODEL small
.STACK 100h
.DATA
    arr1 db 4 dup(0)
    arr2 db 4 dup(0)
    negativeStr db 13, 10, 'Your number is negative$',13,10
    positiveStr db 13, 10, 'Your number is positive. its negative is: $'
    null db '$'
    temp dw ?
    num db ?
    mask db 1
    carry db 0
.CODE
start:
    mov ax, @data
    mov ds, ax
    mov cx,4
    xor ax,ax
    mov ah, 1
    mov di,offset arr1
    call scan
    call newDigit
    jmp exit
scan:
    int 21h
    mov [di],al
    inc di
    loop scan
    ret
newDigit:
    cmp [arr1], '1'
    je printNegative
    mov cx, 4
    mov di, offset arr1
    mov bx, offset arr2
    jne computePositive
    ret
computePositive:
    mov al, [di]
    sub al,'0'
    xor al, mask
    add al, '0'
    mov [bx], al
    inc di
    inc bx
    loop computePositive
    dec bx
    call add1
    jmp exit
add1:
    cmp [bx], '0'
    je foundZ
    dec bx
    cmp bx, offset arr2
    jne add1
    ret
printNegative:
    call newLine
    call print
    mov ah, 9
    mov dx, offset negativeStr
    int 21h
    jmp exit
print:
    mov dx, offset arr1
    mov ah, 9
    int 21h
    ret 
newLine:
    mov dl, 10
    mov ah, 02h
    int 21h
    mov dl, 13
    mov ah, 02h
    int 21h
    ret
exit:
    mov ax, 4c00h
    int 21h
END start