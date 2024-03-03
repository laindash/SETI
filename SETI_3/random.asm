.686
.MODEL FLAT, C

INCLUDE C:\masm32\include\msvcrt.inc
INCLUDELIB C:\masm32\lib\msvcrt.lib


.DATA
    K DWORD 0

.CODE

MODIFY_ARRAY PROC C X: DWORD, N: DWORD
	type_X = TYPE X
	MOV EBX, X
	MOV ECX, [N]
L01:
	MOV EAX, [EBX]
	CMP EAX, 0
	JGE L02
	MUL EAX
	INC K
	MOV [EBX], EAX
L02 :
	ADD EBX, type_X
	LOOP L01
	MOV EAX, K
	RET
MODIFY_ARRAY ENDP


RANDOM_FILL_ARRAY PROC C X: DWORD, N: DWORD
    SUB ESP, 8

    MOV DWORD PTR [esp], 0
    CALL crt_time                       ; EAX = time(0)
    MOV [esp], eax
    CALL crt_srand                      ; srand (EAX)

    type_X = TYPE X
    MOV EBX, N
    MOV ESI, X
L01:
    CALL crt_rand                       ; EAX = rand()

    MOV ECX, 101
    XOR EDX, EDX
    DIV ECX                        
    MOV EAX, EDX
    SUB EAX, 50

    MOV [ESI], EAX
    ADD ESI, type_X

    DEC EBX
    JNE L01

    RET
RANDOM_FILL_ARRAY ENDP

END