assume cs:code,ds:data

data segment
    fibo db 10 dup(?) ;to store first 10 fibonacci numbers
    n db 0ah          ;n=10 (10 = A in hexadecimal)
data ends

code segment
    start:
    
        mov ax,data
        mov ds,ax
        
        lea si,fibo ;to point to the first position in fibo
        
        mov al,00h ;first fibonacci number
        
        mov [si],al ;at first position of array
        inc si ;to point to next position
        
        mov bl,01h ;second fibonacci number
        
        mov [si],bl ;at second position of array
        inc si ;to point to next position
        
        mov cl,n ;to loop 'n' times
        sub cl,2 ;because first 2 elements are already stored
        
        mov ch,00 ;to clear ch
        
    next:
        add al,bl        ;add al and bl to get the next value
        mov [si],al       ;store the new value at next position
        inc si            ;to point to next position
          
        xchg al,bl      ;exchanging the values of al and bl
        loop next       ;loop until we get the next 8 fibonacci series numbers
        
        
       ; if you are having doubt that in the C programming or any other high level language programming
       ;we used to put a=b and then b= res(i.e a+b) but here we exchanged a and b
       ; thing is al stores the result so we are wxchanging result and b finally
        
        mov ah,4ch ;to exit the program
        int 21h
code ends
end start
