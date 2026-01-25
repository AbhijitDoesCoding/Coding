ORG 0000H    

IR_SENSOR    EQU P0           ; Port for Infrared sensor 
ULS_SENSOR   EQU P1           ; Port for Ultrasonic sensor 
LEFT_MOTOR   EQU P2           ; Port for Left motor
RIGHT_MOTOR  EQU P3           ; Port for Right motor

START:
    MOV A, ULS_SENSOR         ; Read ultrasonic sensor data
    CJNE A, #0FFh, OBSTACLE_DETECTED  ; Obstacle detection and transfer of control
    
    MOV A, IR_SENSOR          ; Read infrared sensor data
    CJNE A, #0FFh, NO_FLOOR    ; Floor detection and transfer of control

    MOV LEFT_MOTOR, #001h     ; Move forward
    MOV RIGHT_MOTOR, #001h    
    SJMP WAIT_RESTART
           
OBSTACLE_DETECTED:
    ; Obstacle detected, turn right for 50 ms
    MOV LEFT_MOTOR, #001h     ; Turn right by running left motor only
    MOV RIGHT_MOTOR, #000h
    
    ; 50 ms delay using Timer 1
    ACALL DELAY_50MS         

    SJMP START                ; After delay, check again for obstacles

NO_FLOOR:
    ; No floor detected, turn right for 50 ms
    MOV LEFT_MOTOR, #001h     ; Turn right by running left motor only
    MOV RIGHT_MOTOR, #000h

    ; 50 ms delay using Timer 1
    ACALL DELAY_50MS         

    SJMP START                ; After delay, check again for floor

WAIT_RESTART:
    ; 50 ms delay before restarting the main loop
    ACALL DELAY_50MS         

    SJMP START                ; Return to START after 50 ms delay

DELAY_50MS:
    ; Set up Timer 1 in Mode 1 (16-bit timer mode) for 50 ms delay
    MOV TMOD, #010H            ; Configure Timer 1 as 16-bit timer
    MOV TH1, #03CH             ; Load high byte for 50 ms delay (TH1=0x3C)
    MOV TL1, #0B0H             ; Load low byte for 50 ms delay (TL1=0xB0)
    
    SETB TR1                  ; Start Timer 1
    
WAIT_FOR_TIMER:
    JNB TF1, WAIT_FOR_TIMER   ; Wait until Timer 1 overflows (TF1=1)
    
    CLR TR1                   ; Stop Timer 1
    CLR TF1                   ; Clear Timer 1 overflow flag for next use

    RET                       ; Return from delay subroutine

END