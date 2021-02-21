MODEL small
STACK 100h
DATASEG
    char db 'A'
    
CODESEG
start:
    mov ax, @data
    mov ds, ax
    mov ah, 2
    mov cx, 26
testL:
    mov dl, [char]
    int 21h
    inc [char]
    loop testL
exit:
    mov ax, 4c00h
    int 21h
END start



