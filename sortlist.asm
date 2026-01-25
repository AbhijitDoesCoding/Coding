section .data
msg db "Sorted array: "
msglen equ $-msg
arr db 05h,09h,75h,03h,12h

%macro operate 4
mov rax,%1
mov rdi,%2
mov rsi,%3
mov rdx,%4
syscall
%endmacro

section .bss
result resb 15

section .text
global _start
     _start:
     
     mov bl,5
     loop_outer:mov cl,4
           mov rsi,arr
           
 up:      mov al,byte[rsi]
           cmp al,byte[rsi+1]
           jbe only_inc
           xchg al,byte[rsi+1]
           mov byte[rsi],al
 only_inc:inc rsi
           dec cl
           jnz up
           
           dec bl
           jnz loop_outer
           operate 1,1,msg,msglen
           
           mov rdi,arr
           mov rsi,result
           mov dl,5
           
           disp_loop1:
           mov cl,2
           mov al,[rdi]
           
           againx:
           
           rol al,4
           mov bl,al
           and al,0FH
           cmp al,09H
           jbe downx
           add al,07H
           downx:
           add al,30H
           mov byte[rsi],al
           mov al,bl
           inc rsi
           dec cl
           jnz againx
           
          mov byte[rsi]," "
          inc rsi
          inc rdi
          dec dl
          jnz disp_loop1
          operate 1,1,result,15
          
          operate 60,0,0,0