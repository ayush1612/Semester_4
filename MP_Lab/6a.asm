assume cs:code
code segment
start:
    mov ah,00h
    mov al,02h
    int 10h

    mov ah,02
    mov dh,12d
    mov dl,40d
    int 10h

    mov al,'X'
    mov bl,8ch
    mov cl,1
    mov ah,9
    int 10h

    mov ah,7
    int 21h

    mov ah,4ch
    int 21h

code ends
end start