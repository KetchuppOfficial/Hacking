;---------------------------------------------------------------------;
;  Password: "It will be legen ... wait for it ... dary! Legendary!"  ;
;---------------------------------------------------------------------;

.model tiny
.code
.386
org 100h

New_Line        macro

        mov ax, 0900h
        mov dx, offset new_line
        int 21h

endm

Start:

        mov ax, 0900h                   ;
        mov dx, offset greeting         ; prints greeting
        int 21h                         ;

        mov ah, 3Dh                     ;
        xor al, al                      ; Open
        mov dx, offset File_Name        ; File
        int 21h                         ;

        mov di, offset buffer + 1
        mov bx, ax
        xor si, si

@@new_char:

        mov ah, 3Fh
        mov cx, 1
        mov dx, di
        int 21h

        cmp ax, 0
        je @@close_file

        inc di
        inc si
        jmp @@new_char


@@close_file:

        mov ah, 3Eh                     ; Close file
        int 21h                         ;

        mov ax, si
        xor ah, ah
        mov [buffer], al

        New_Line

        call Bug

        mov ax, 4C00h
        int 21h

        Hello   db      "Hi, dear stranger! Try to hack this piece of code. With best regards!"

        File_Name        db "key.txt", 00h

locals @@

;/////////////////////////////////////////////////////////////////////////////////////////////////////////////
;/ F R A M E / F R A M E / F R A M E / F R A M E / F R A M E / F R A M E / F R A M E / F R A M E / F R A M E /
;/////////////////////////////////////////////////////////////////////////////////////////////////////////////

;-------------------------------------------------------------------------------------------
;	AH - colour of line
;	AL - any symbol
;	CX - counter
;	DI - number of symbol counting from the beginning of the line
;	ES - address of a videosegment (0b800h)
;-------------------------------------------------------------------------------------------

VIDEOSEG	equ 0b800h

COLOUR          equ 08Ch

PUTCHAR		macro

                nop
                lodsb
                stosw
                nop	

                endm

;-------------------------------------------------------------------------------------------
New_Line_Frame  proc

                xor dx, dx
                mov ax, di
                mov cx, 0A0h
                div cx
                inc ax
                mul cx
                mov di, ax
                mov ah, [bp + 4]

                ret

New_Line_Frame	endp
;-------------------------------------------------------------------------------------------
;--------------------------------------
Check_3 proc

        mov dx, hash_buff[6]
        mov bp, hash_3
        cmp dx, bp
        je @@return

        inc di

@@return:
        ret

Check_3 endp
;--------------------------------------
;-------------------------------------------------------------------------------------------
Draw_Line	proc

                mov cx, 72
                
                PUTCHAR

                lodsb
@@next_symb:
                stosw
                loop @@next_symb
                
                PUTCHAR
                
                call New_Line_Frame

                ret

Draw_Line	endp
;-------------------------------------------------------------------------------------------

;-------------------------------------------------------------------------------------------
Draw_Middle	proc

                mov si, offset frame_symbs
                add si, 3

                call Draw_Line

                ret

Draw_Middle	endp
;-------------------------------------------------------------------------------------------

;-------------------------------------------------------------------------------------------
Draw_Text	proc

                mov si, offset frame_symbs
                add si, 3

                PUTCHAR
                PUTCHAR
                
                mov si, bx

@@next_symb:
                PUTCHAR

                mov cl, '$'
                cmp [si], cl
                jne @@next_symb	

                mov si, offset frame_symbs
                add si, 4

                PUTCHAR
                PUTCHAR

                call New_Line_Frame

                ret

Draw_Text	endp
;-------------------------------------------------------------------------------------------

;--------------------------------------
Check_1 proc

        mov dx, hash_buff[4]
        mov ax, hash_2
        cmp ax, dx
        jne @@incorrect

        call Check_2
        jmp @@return

@@incorrect:
        inc di

@@return:
        ret

Check_1 endp
;--------------------------------------

;-------------------------------------------------------------------------------------------
Draw_Frame	proc

		mov si, offset frame_symbs
		call Draw_Line

		call Draw_Text
		
		mov si, offset frame_symbs
		add si, 6
		call Draw_Line

                ret

Draw_Frame	endp
;-------------------------------------------------------------------------------------------

;-------------------------------------------------------------------------------------------
Frame   proc

        push bp
        mov bp, sp

        mov ax, VIDEOSEG
        mov es, ax
        mov ah, [bp + 4]        ; colour
        mov di, 3360
        mov bx, [bp + 6]        ; string

        call Draw_Frame
        New_Line

        pop bp

        ret

Frame   endp

;-------------------------------------------------------------------------------------------
looser          db "Hi, loser))) It seems you haven't hacked me yet. Well, keep trying :-)", '$'
winner          db "Hi, champion! Good job! Ded32 will be proud of you! With best regards!", '$'
frame_symbs     db  0C9h, 0CDh, 0BBh, 0BAh, 020h,   0BAh, 0C8h, 0CDh, 0BCh
;                   LT    T     RT    Vert  inside  Vert  LB    B     RB
;-------------------------------------------------------------------------------------------

;--------------------------------------
Check_4 proc
if 0
        mov dx, hash_buff[2]
        mov cx, hash_1
        cmp dx, cx
        je @@return

        inc di
endif
@@return:

        ret

Check_4 endp
;--------------------------------------

;///////////////////////////////////////////////////////////////////////////////////////////////////////////////
;/ H A C K / H A C K / H A C K / H A C K / H A C K / H A C K / H A C K / H A C K / H A C K / H A C K / H A C K /
;///////////////////////////////////////////////////////////////////////////////////////////////////////////////

hash_0  dw 0AF38h

;--------------------------------------------------------------------
Calc_Hash       proc

                mov di, offset buffer + 1               ; forward: 3DA3h
                xor ax, ax
                mov al, buffer[0]
                mov si, ax
                xor bx, bx
                call hash
                mov hash_buff[4], ax

                mov di, offset buffer                  ; backward: AF38h
                xor ax, ax
                mov al, buffer[0]
                mov si, ax
                add di, si
                mov bx, 1
                call hash
                mov hash_buff[0], ax

                mov di, offset buffer + 1               ; even (first one is 0): 143Dh
                xor ax, ax
                mov al, buffer[0]
                mov si, ax
                mov bx, 2
                call hash
                mov hash_buff[6], ax

                ret

Calc_Hash       endp
;--------------------------------------------------------------------

hash_3  dw 143Dh     

;--------------------------------------------------------------------
;hash:                                                              ;
;~~~~~                                                              ;
;   Input:                                                          ;
;   ~~~~~~                                                          ;
;       di - data                                                   ;
;       si - data length                                            ;
;       bx - mode                                                   ;
;                                                                   ;
;   Output:                                                         ;
;   ~~~~~~~                                                         ;
;       ax - hash                                                   ;
;                                                                   ;
;   Registers that change values:                                   ;
;   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~                                   ;
;       ax - contains hash                                          ;
;       cx - symbols counter                                        ;
;       dx - is used for intermediate calculations                  ;
;       di - offest of the string                                   ;
;--------------------------------------------------------------------
hash    proc

        xor ax, ax
        xor cx, cx

        jmp @@condition
@@while:
        add al, byte ptr [di]

        mov dx, ax
        shl dx, 10
        add ax, dx

        mov dx, ax
        shr dx, 6
        xor ax, dx

        mov bp, offset modes
        add bp, bx
        add bp, bx
        mov bp, [bp]
        jmp bp

@@condition:

        cmp cx, si
        jb @@while

        mov dx, ax
        shl dx, 3
        add ax, dx

        mov dx, ax
        shr dx, 11
        xor ax, dx

        mov dx, ax
        shl dx, 15
        add ax, dx

        ret

modes   dw      @@forward
        dw      @@backward
        dw      2 dup (@@even_odd)

hash_buff       dw  4 dup (0)

@@forward:
        inc di
        inc cx
        jmp @@condition 

@@backward:
        dec di
        inc cx
        jmp @@condition

@@even_odd:
        add di, 2
        add cx, 2
        jmp @@condition

joke            db "Hash here ---->>>"  
hash_buFF       dw 0D341h, 0B8D0h, 3AD3h, 83FAh

hash    endp
;--------------------------------------------------------------------

;--------------------------------------
Check_2 proc

        mov dx, hash_buff[0]
        mov ax, hash_0
        cmp dx, ax
        jne @@incorrect

        call Check_3
        jmp @@return

@@incorrect:
        inc di

@@return:
        ret

Check_2 endp
;--------------------------------------
;--------------------------------------
Guessed proc

        push offset winner
        push 002Bh
        call Frame
        pop cx
        pop cx

        ret

Guessed endp
;--------------------------------------
Not_Guessed     proc

                push offset looser
                push 008Ch
                call Frame
                pop cx
                pop cx

                ret

Not_Guessed     endp
;--------------------------------------
;--------------------------------------------------------------------------

;--------------------------------------------------------------------------
buffer          db  55 dup (0)

greeting        db  "Write the password", 0Dh, 0Ah, '$'

;-------------
Bug     proc

        call Calc_Hash

        xor di, di
        call Check_1
        cmp di, 0
        jne @@incorrect

        call Guessed
        ret

        hash_2  dw      3DA3h

@@incorrect:
        
        call Not_Guessed
        ret

Bug     endp
;-------------

Few_Words       db "Hi! It's you again. Have you already hacked my program? No? Oh please, don't cry. Water is bad for my processor", 01h

new_line        db  0Dh, 0Ah, '$'

Crap            db "jknfnaslfh WH FNCJASDJFVJASDLJHGAJSDKFLJADVNXMCe uty        45J;KCNVXNVNMsberhBKDKXNNM Bnpeig DJ /x", 08h, 28h, 10h, 0ABh, 0FFh

end		Start
