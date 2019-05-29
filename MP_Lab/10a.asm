assume cs:code,ds:data
data segment
	fname db "testf.txt"        ;name of the file to work upon
	buff db 100 dup(0)           ;buffer where the read data is stored into and we take it as 100 spaces
	errmsg db 0ah,0dh,"File not found$" ;message to print if no file is found 
	closmsg db 0ah,0dh,"File closed successfully$"      ;message to print after doing the operation to make the user known that the file is closed succesfully
data ends

code segment
	start:
		mov ax,data
		mov ds,ax
        
        
		mov ah,3dh ;to open the file
		lea dx,fname ;the file to be opened
		mov al,0       
		int 21h ;if successful, CF is cleared and ax is set to file handle
        
		jnc next ;jmp to next if CF is cleared or not
		
        ;display the error meassage
        lea dx,errmsg 
		mov ah,9 
		int 21h
        
        ;no more operations required ... exit the program
		jmp finish
        
        
	next:
		
        mov bx,ax       ;to set bx to file handle
		mov ah,3fh      ;to read the file
		mov cx,100d     ;100 characters to be read
		lea dx,buff     ;buffer for the read characters
		int 21h
        
        ;now we need to print the content of the file 
        ;so we take the counter as 100(as the buffer holds only 100characters)
        
		mov cx,100d 
		lea si,buff     ;pointing to the starting character of the characters stored in the buffer
        
        
	repeat:
		;taking one character at a time as input and then printing it 
        mov dl,[si]
		mov ah,2
		int 21h
		
        ;incrementing the value of si to traverse through the contents
        inc si
		loop repeat

		mov ah,3eh ;to close the file
		int 21h
		lea dx,closmsg
		mov ah,9
		int 21h
	finish:
		mov ah,4ch ;to exit the program
		int 21h
code ends
end start
