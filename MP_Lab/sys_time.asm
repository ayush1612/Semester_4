DATA SEGMENT 
    
     MSG1 DB 'CURRENT TIME IS : $'
    HR DB ?
    MIN DB ?
    SEC DB ?
    MSEC DB ?
DATA ENDS
CODE SEGMENT
ASSUME CS:CODE, DS:DATA
   START:        MOV AX, DATA
        MOV DS, AX
        MOV AH,2CH    	 	; TO GET SYSTEM TIME
        INT 21H
        MOV HR, CH     	 	; CH -> HOUR
        MOV MIN, CL   	  	; CL -> MINUTES
        MOV SEC, DH     		; DH -> SECONDS
        MOV MSEC, DL   	 	; DL -> 1/100TH SECOND
        LEA DX, MSG1    		; DISPLAY MSG1
        MOV AH, 09H
        INT 21H
        MOV AL, HR    		; IF AL=0D AAM WILL SPLIT THE NIBBLES INTO AH AND AL
        AAM        			; SO AH=01 AND AL=03
        MOV BX, AX
        CALL DISPLAY    		; DISPLAY HOURS
        MOV DL, ':'    		 ; DISPLAY ':' AFTER DISPLAYING HOUR
        MOV AH, 02H
        INT 21H
        MOV AL, MIN      
        AAM     
        MOV BX, AX
        CALL DISPLAY    		; DISPLAY MINUTES
        MOV DL, ':'    	 	; DISPLAY ':' AFTER DISPLAYING MINUTES
        MOV AH, 02H
        INT 21H
        MOV AL, SEC    
        AAM                   
        MOV BX, AX
        CALL DISPLAY   	 	; DISPLAY SECONDS
        MOV DL, '.'     		; DISPLAY '.' AFTER DISPLAYING SECONDS
        MOV AH, 02H
        INT 21H
        MOV AL, MSEC   
        AAM                     
        MOV BX, AX
        CALL DISPLAY    		; DISPLAY 1/100TH SECONDS
        MOV AH, 4CH
        INT 21H
        DISPLAY PROC NEAR
                MOV DL, BH
                ADD DL, 30H    		; DISPLAY BH VALUE
                MOV AH, 02H
                INT 21H
                MOV DL, BL
                ADD DL, 30H    		; DISPLAY BL VALUE
                MOV AH, 02H
                INT 21H
                RET
      DISPLAY ENDP
CODE ENDS
END START
