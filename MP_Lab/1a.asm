;In this program you need to find the key element using binary search

;TIPS and Doubts
;Why i used mov ah,9. I could have used mov ah,2
; Thing is mov ah,2 is for character display and mov ah,9 is for string display and it prints till it gets the "$" sign


assume cs:code,ds:data
data segment
    arr db 05h,20h,40h,60h,70h  ;to perform binary search we need to have a sorted array
    n db n-arr  ;n=5
    key db 20h  ;key to be found
    msg1 db "Could not find the element$"
    msg2 db "Key found at position: "
    pos db ?,"$" ;contains position of the key if found
data ends
code segment
start:
    mov ax,data
    mov ds,ax
    mov al,0  ;stores the index 0
    mov dl,n  ;dl=n
    dec dl    ;since the last index is n-1 , we decrease the value of dl
again:
    cmp al,dl  ;compares first and last position
    ja failed  ;if there are no elements in the array
    
    mov cl,al  ;store a copy of al value as we will be using it later for getting the original al value before the loop
    add al,dl  ;add first and last positions of the array
    shr al,1   ;reduces al to half its value
    
    mov ah,00h ; this is done because si in the next line is a 16 bit register and if we use al instead of ax we will get a warning
    
    mov si,ax  ;stores ax value(mid position) into si
    mov bl,[si] ;stores the contents of si in bl
    cmp bl,key ;compares mid value with key to be found
    jae loc1 ;if bl is greater than or equal to the key value
    inc al  ;else increment mid position as we will be working on the right subarray 
    jmp again 

loc1:
    je success ;if mid value is equal to key value
    dec al ;else decrement mid position as key value is less than mid value
    
    mov dl,al ;store in dl ,now we will be working on the left subarray
    mov al,cl ;copy the stored cl value in al
    
    jmp again


failed:

    lea dx,msg1 ;load the msg1 offset address into dx
    jmp display

success:
    inc al ;increment the position where key is found
    add al,30h ;convert binary to ascii value by adding 30h to it 
    mov pos,al
    lea dx,msg2 ;load the effective address of msg2
    
    
display:
    mov ah,09h ;to print the string msg
    int 21h
    
    
    mov ah,4ch ;to exit the program
    int 21h
    
    
code ends
end start
