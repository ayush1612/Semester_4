assume cs:code,ds:data

data segment
  pa equ 20a0h  ;address of port A
  pb equ 20a1h  ;address of port B
  pc equ 20a2h  ;adddress of port C
  cr equ 20a3h  ;address of control register
data ends

code segment
  start:
  
    mov ax,data
    mov ds,ax
  
    mov dx,cr
    mov al,80h ;code word to set the ports as outputs
    out dx,al ;to send the control word to cr
    
    ;rotation angle can be 64h or 100d (180/1.8 = 100)
    ;rotation angle can be 32h or 50d  (90/1.8 = 50)
    
    mov cx,32h ;to set the rotation angle to 90 degrees
    mov al,80h ;to load the sequence into al
    mov dx,pa ;to copy the address of port A
  
  
  rotate:
  
    out dx,al ;to send the sequence to port A
    ror al,1 ;to rotate it in clockwise direction 
    call delay ;call the procedure
    loop rotate
    ;for anti-clockwise u can change ROR to ROL
    
    mov ah,4ch ;to exit the program
    int 21h
    
  delay proc ;procedure to generate the delay
    mov bx,02fffh
    l2: mov di,0ffffh
    l1: dec di
    jnz l1
    dec bx
    jnz l2
    ret
  delay endp ;end of procedure
  
code ends
end start
