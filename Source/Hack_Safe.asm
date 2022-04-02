;---------------------------------------------------------------------;
;  Password: "It will be legen ... wait for it ... dary! Legendary!"  ;
;---------------------------------------------------------------------;

.model tiny
.code
org 100h

New_Line        macro

        mov ax, 0900h
        mov dx, offset new_line
        int 21h

endm

Start:

        mov bx, offset buffer
        mov al, 254
        mov [bx], al
    
        jmp main

locals @@

;--------------------------------------------------------------------
;hash:                                                              ;
;~~~~~                                                              ;
;   Input:                                                          ;
;   ~~~~~~                                                          ;
;       di - data                                                   ;
;       si - data length                                            ;
;                                                                   ;
;   Output:                                                         ;
;   ~~~~~~~                                                         ;
;       ax - hash                                                   ;
;                                                                   ;
;   Registers that change values:                                   ;
;   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~                                   ;
;       ax - contains hash                                          ;
;       bx - is used for intermediate calculations                  ;
;       cx - symbols counter                                        ;
;       di - offest of the string                                   ;
;--------------------------------------------------------------------
hash    proc

        xor ax, ax
        xor cx, cx

        jmp @@condition
@@while:
        add al, byte ptr [di]

        mov bx, ax
        shl bx, 10
        add ax, bx

        mov bx, ax
        shr bx, 6
        xor ax, bx

        inc di
        inc cx

@@condition:

        cmp cx, si
        jb @@while

        mov bx, ax
        shl bx, 3
        add ax, bx

        mov bx, ax
        shr bx, 11
        xor ax, bx

        mov bx, ax
        shl bx, 15
        add ax, bx

        ret

hash    endp
;--------------------------------------------------------------------

main:

        mov ax, 0900h                   ;
        mov dx, offset greeting         ; prints greeting
        int 21h                         ;

        mov ah, 0Ah                     ;
        mov dx, offset buffer           ; reads from input
        int 21h                         ;

        New_Line

        mov di, offset buffer + 2
        xor ax, ax
        mov al, buffer[1]
        mov si, ax
        call hash

        mov dx, 3DA3h                   ; password hash
        cmp ax, dx
        je @@correct

        mov ax, 0900h
        mov dx, offset wrong
        int 21h
        jmp @@exit

@@correct:
        
        mov ax, 0900h
        mov dx, offset correct
        int 21h

@@exit:
        mov ax, 4C00h
        int 21h

;--------------------------------------------------------------------------
greeting        db  "Write the password", 0Dh, 0Ah, '$'
correct         db  "Access granted",     0Dh, 0Ah, '$'
wrong           db  "Access denied",      0Dh, 0Ah, '$'
               
                ; You can get access if you change "access denied" into "access granted" by buffer overflow

new_line        db  0Dh, 0Ah, '$'

buffer          db  255 dup (0)

end     Start
