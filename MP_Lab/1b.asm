assume cs:code,ds:data
data segment

  pa equ 20a0h ;address of port A
  pb equ 20a1h ;address of port B
  pc equ 20a2h ;address of port C
  cr equ 20a3h ;address of control register
  
  msg db "No. of 1's present are: "
  one db ?,"$" ;holds the number of 1's

data ends

code segment
  start:

    mov ax,data
    mov ds,ax
    
    ;now we need to activate AL
    mov dx,cr
    mov al,82h ;control word to set port A: output, port B: input
    out dx,al ;to send control word to cr
    
    
    ;now we are going to take the input in port B
    ;Basically the led you switch on will be taken as an input which we are going to scan below to count how many LEDs are glowing
    ;then we see if odd number are glowing all the 8 LEDs above remain OFF
    ;if we find that there are even number of LEDs glowing all the above LEDs start glowing
    
    mov dx,pb ;to copy port B's address
    in al,dx ;to read input
    
    
    mov cx,8 ;to loop 8 times to check the 8 LEds ...which one is glowing 
    mov ah,0 ;ah = 0
    
    
  rotate:
  ;here we will scan which of the LEDs are glowing and we will increment the value of AH as per we find the LED is glowing 
  ;then we print the value of AH
  
    ror al,1 ;to rotate the bits once to the right to store the rightmost bit as carry
    jnc next ;jump if carry is 0
    inc ah ;else increment ah
    
    
  next:
    
    loop rotate ;loops 8 times
    mov bl,ah ;to copy ah value into bl
    add ah,30h ;to convert binary into ascii
    
    mov one,ah ;to copy ascii value into one
    lea dx,msg ;to point to msg
    mov ah,09h ;to display msg
    int 21h
    
    ;this code below checks if odd or even number of LEDs are glowing
    ;if it will be odd basically bl will be having the bit pattern as "xxx1" (Ex: 3 LEDs ->bl=3 -> 0011)
    ;if it will be even the last bit will be 0 (Ex: 4 LEDs means bl=4 -> 0100)
    ; so if we rotate bl for once in right we will get to know if there is a 1 or a 0 in the last
    ; 1 means odd thus carry is generated
    ; 0 means even thus no carry generated
    
    mov al,00h
    ror bl,1
    jc next
    mov al,0ffh
  
 next:
    mov dx,pa ;to copy address of port A
    out dx,al ;to move 8 bit data to port A
    
    mov ah,4ch ;to exit the program 
    int 21h
code ends
end start
