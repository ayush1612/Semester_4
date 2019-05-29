;Bubble sort on an array
;Tips and Doubts



assume cs:code,ds:data
data segment
x db 10h,05h,03h,15h,01h    ;the array on which we are going to work

n dw n-x                    ;n=5
data ends

code segment
start:
    mov ax,data
    mov ds,ax

    mov bx,n        ;this is to store the counter for the outer loop
    dec  bx         ;decrementing since if we compare the bubble sort algorithm we will find the outer loop runs from 0 to n-1

next_pass:
    mov cx,bx       ; since the inner loop's iterations depend on the number outer value of the loop variable

that_pass:  
    mov ah,00       ; since in the next line we are working on si which is a 16 bit register
    lea si,x

next_cmp:
    mov al,[si]     ;storing the value of [si] in al
    cmp al,[si+1]    ; comparing it with the next value   
    jle do_nothing      ;if less than or equal to we don't need to do any change 
    xchg al,[si+1]      ;otherwise we need to swap
    mov [si],al             
    mov ah,1            ;this checks whether the array is sorted

do_nothing:
    inc si              ; increment si 
    loop next_cmp       ; go for the next comparison
    cmp ah,0            ;if found 0 it means the array is already sorted now no more executions required
    je finish           ;jump to finish if ah=0

    dec bx              ;otherwise decrement bx
    jnz next_pass       ;let's go for next iteration
finish:
    mov ah,4ch          ;exit
    int 21h
code ends
end start
