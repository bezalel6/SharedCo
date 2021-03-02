.MODEL small
.STACK 100h
.DATA
    scanned db 0
    negativeStr db 13, 10, 'Your number is negative',13,10,'$'
    positiveStr db 13, 10, 'Your number is positive. its negative is: $'
    firstStr db 13,10, 'THIS PROGRAM CONVERTS TO NEGATIVE.',13,10,'Please enter binary number:',13,10,'$'
.CODE
start:
    mov ax, @data
    mov ds, ax
    mov dx, offset firstStr
    mov ah, 9
    int 21h
    mov cx,4
    xor ax,ax
    mov ah, 1
    call scan
    mov al, scanned
    shl al,5
    jc negative
    jmp positive
    jmp exit
scan:;קליטת המספר והמרתו למספר בינארי
    int 21h
    sub al, '0'
    add scanned, al
    rol scanned, 1
    loop scan
    ror scanned,1
    ret
positive:
    not scanned
    shl scanned, 4
    shr scanned,4
    inc scanned
    mov cx, 4
    shl scanned,4;על מנת להגיע למספר עצמו
    mov ah, 9
    mov dx, offset positiveStr
    int 21h
    mov ah,2

printPos:;נסובב כל פעם שמאלה ונדפיס את מה שיש בCF
    shl scanned,1
    call checkCarry
    int 21h
    loop printPos
    jmp exit

checkCarry:
    jc printO
    jnc printZ

printO:
    mov dl, '1'
    ret
printZ:
    mov dl, '0'
    ret
negative:
    mov dx, offset negativeStr
    mov ah, 9
    int 21h
exit:
    mov ah, 4ch
    int 21h
END start