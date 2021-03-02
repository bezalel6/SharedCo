cr equ 13
.MODEL small
.STACK 100h
.DATA
    A db 7,3,4,5,6,2
    LEN=$-A
    P DW A,LEN
    B DW LEN
.CODE
start:
    mov ax, @data
    mov ds, ax

exit:
    mov ah, 4ch
    int 21h
END start