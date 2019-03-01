assume cs:code,ds:data
data segment
    a db 10h,20h,30h,40h,50h
    n db n-a
    key db 20h
    msg1 db "Key not found $"
    msg2 db "key found at position:"
    pos db ?,"$"
data ends
code segment
start:
    mov ax,data
    mov ds,ax

    mov al,0
    mov dl,n
    dec dl

again:
    cmp al,dl
    ja failed
    mov cl,al
    add al,dl
    shr al,1
    
    mov ah,00h
    mov si,ax
    mov bl,[si]
    cmp bl,key
    jae loc1
    inc al
    jmp again

loc1:
    je success
    dec al
    mov al,cl
    jmp again

failed:
    lea dx,msg1
    jmp display

success:
    inc al
    add al,30h
    mov pos,al
    lea dx,msg2

display:
    mov ah,9
    int 21h
    mov ah,4ch
    int 21h

code ends
end start
