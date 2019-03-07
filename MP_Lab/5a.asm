assume cs:code,ds:data
data segment
    n db 5
    res db ?
data ends

code segment
start:
    mov ax,data
    mov ds,ax

    mov al,n
    call fact
    
    mov ah,4ch
    int 21h

fact proc
    cmp al,00
    je cal
    push ax
    dec al
    call fact
    pop ax

program:
    mul res
    mov res,al
    ret

cal:mov res,01
ret
fact endp
code ends
end start