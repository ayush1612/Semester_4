
;Used INTERRUPTS
;AH=2CH  //Gets the system date
;AH=02h // Displays the ascii value in DOS Prompt
;For 2CH
; Hours is in CH
; Minutes is in CL
; Seconds is in DH


;Declaration Part
ASSUME CS:CODE
CODE SEGMENT

START: 
    ;Hour Part
HOUR:
    MOV AH,2CH    ; To get System Time
    INT 21H
    MOV AL,CH     ; Hour is in CH
    AAM            ;ASCII adjust after multiplication, it helps in getting the individual values like in 1234 it makes 12 34 
    MOV BX,AX
    CALL DISP

    MOV DL,':'
    MOV AH,02H    ; To Print : in DOS
    INT 21H

    ;Minutes Part
MINUTES:
    MOV AH,2CH    ; To get System Time
    INT 21H
    MOV AL,CL     ; Minutes is in CL
    AAM
    MOV BX,AX
    CALL DISP

    ;To terminate the Program

    MOV AH,4CH     ; To Terminate the Program
    INT 21H

    ;Display Part
DISP PROC
    ;this prints the upper nibble value
    MOV DL,BH      ; Since the values are in BX, BH Part
    ADD DL,30H     ; ASCII Adjustment
    MOV AH,02H     ; To Print in DOS
    INT 21H
    
    ;this stores the lower nibble value
    MOV DL,BL      ; BL Part 
    ADD DL,30H     ; ASCII Adjustment
    MOV AH,02H     ; To Print in DOS
    INT 21H
    RET
DISP ENDP      ; End Disp Procedure

CODE ENDS
END START      ; End of MAIN
      
       
    
