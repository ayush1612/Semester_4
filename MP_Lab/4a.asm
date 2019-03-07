assume cs:code,ds:data
data segment
    str1 db "madam"
    n dw n-str1
    str2 db 5dup(?)
    msg1 db "Palindrome$"
    msg2 db "Not a palindrome$"
data ends
code segment
start:
    mov ax,data
    mov ds,ax
    mov cs,ax
    mov cx,n
    dec si
    lea di,str2

nextchar:
    mov al,[si]
    mov [di],al
    dec si
    inc di
    loop nextchar
    lea si,str1
    lea di,str2
    cld
    mov cx,n
    repe cmpsb
    jnz unsuccess
    lea dx,msg1
unsuccess:
    lea dx,msg2

disp:
    mov ah,9h
    int 21h
    mov ah,04ch
    int 21h

code ends
end start
