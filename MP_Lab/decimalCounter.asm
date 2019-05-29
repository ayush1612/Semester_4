;TIP:
;If you are using a DOS box and you find the counter is not increasing and your program is correct
;Believe me it's correct ;-) 
;Just change the counter delay as mentioned below;
You will get the results


ASSUME CS:CODE
CODE SEGMENT


START:
	MOV CX,100D		;we are going to make the counter count upto 99 and since we are starting from 0 we need 100 as the counter
	MOV BL,00		;starting from 0

NEXT:
		MOV AL,BL	; we are storing the value of bl in al
		AAM		; ASCII adjust after multiplication .... works to get like BCD values Ex:1234 turns 12 and 34
		ADD AX,3030H	; getting the digits to print as 0 to 9 is 30h to 39h in 8086

		MOV DL,AH	;printing the upper nibble
		MOV AH,2
		 
		 PUSH AX	;pushing the value of ax in the stack to preserve its original value
		INT 21H
		POP AX

		MOV DL,AL
		MOV AH,2
		INT 21H

		MOV DL,0DH	
		MOV AH,2
		INT 21H
		
		CALL DELAY	;calling delay so that we can see the counting otherwise you will need a slow motion camera to see ;-)
		INC BL
		LOOP NEXT

		MOV AH,4CH
		INT 21H

DELAY PROC
		MOV SI,02FFFH	;if you are working on DOS box then change this to MOV SI,0009h
		L2:MOV DI,0FFFFH
		L1:DEC DI
		JNZ L1
		DEC SI
		JNZ L2
		RET
DELAY ENDP 
CODE ENDS 
END START
