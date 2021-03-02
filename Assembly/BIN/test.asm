cr equ 13
.MODEL small
.STACK 100h
.DATA

.CODE
start:
    mov ax, @data
    mov ds, ax
    inc bp
exit:
    mov ah, 4ch
    int 21h
END start