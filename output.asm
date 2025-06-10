; Fichier généré automatiquement par le compilateur
; Code compatible avec EMU8086

.MODEL SMALL
.STACK 100h

.DATA
    ERR_UNDERFLOW_MSG DB 'Erreur: indice inferieur a 0$'
    ERR_OVERFLOW_MSG DB 'Erreur: indice superieur a la taille$'
    DIV_ZERO_MSG DB 'Erreur: Division par zero$'
    MSG_RESULT DB 'Resultat: $'
    BUFFER DB 10 DUP('$')
    ; Variables pour la partie entière et décimale
    INT_PART DW ?
    DEC_PART DB ?
    NEWLINE DB 13,10,'$'
    FLOAT_POINT DB '.','$'
    MSG_ADD_INT DB 'INT ADD: $'
    MSG_SUB_INT DB 'INT SUB: $'
    MSG_MUL_INT DB 'INT MUL: $'
    MSG_DIV_INT DB 'INT DIV: $'
    MSG_ADD_FLOAT DB 'FLOAT ADD: $'
    MSG_SUB_FLOAT DB 'FLOAT SUB: $'
    MSG_MUL_FLOAT DB 'FLOAT MUL: $'
    MSG_DIV_FLOAT DB 'FLOAT DIV: $'
    TRUE DW 1
    FALSE DW 0
    operationscomplexes DW 0
    main_var DW 0
    resultatfloat1 DW 0
    mixte1 DW 0
    resultatfloat2 DW 0
    mixte2 DW 0
    resultatint1 DW 0
    resultatint2 DW 0
    a DW 0
    b DW 0
    c DW 0
    e DW 0
    f DW 0
    g DW 0
    i DW 0
    j DW 0
    r DW 0
    t DW 0
    u DW 0
    w DW 0
    x DW 0
    y DW 0
    z DW 0
    t0 DW 0 ; Variable temporaire

.CODE

MAIN PROC FAR
    ; Initialisation des segments de données
    MOV AX, @DATA
    MOV DS, AX

    ; Quadruplet 0: (=, 4.000000, vide, g)
    MOV AX, 4
    MOV g, AX
    LEA DX, MSG_RESULT
    MOV AH, 09h
    INT 21h
    MOV AX, g
    CALL PRINT_NUM
    CALL PRINT_NEWLINE

    ; Quadruplet 1: (+, 4.000000, 4.000000, T0)
    ; Addition entière
    MOV DX, OFFSET MSG_ADD_INT
    CALL PRINT_MSG
    MOV AX, 4
    ADD AX, 4
    MOV T0, AX
    MOV AX, T0
    CALL PRINT_NUM
    CALL PRINT_NEWLINE

    ; Quadruplet 2: (=, T0, vide, g)
    MOV AX, T0
    MOV g, AX
    LEA DX, MSG_RESULT
    MOV AH, 09h
    INT 21h
    MOV AX, g
    CALL PRINT_NUM
    CALL PRINT_NEWLINE

    ; Quadruplet 3: (=, 6.000000, vide, r)
    MOV AX, 6
    MOV r, AX
    LEA DX, MSG_RESULT
    MOV AH, 09h
    INT 21h
    MOV AX, r
    CALL PRINT_NUM
    CALL PRINT_NEWLINE

    ; Quadruplet 4: (=, 44.000000, vide, f)
    MOV AX, 44
    MOV f, AX
    LEA DX, MSG_RESULT
    MOV AH, 09h
    INT 21h
    MOV AX, f
    CALL PRINT_NUM
    CALL PRINT_NEWLINE

    ; Quadruplet 5: (=, 0.000000, vide, e)
    MOV AX, 0
    MOV e, AX
    LEA DX, MSG_RESULT
    MOV AH, 09h
    INT 21h
    MOV AX, e
    CALL PRINT_NUM
    CALL PRINT_NEWLINE

    ; Quadruplet 6: (=, 1.000000, vide, f)
    MOV AX, 1
    MOV f, AX
    LEA DX, MSG_RESULT
    MOV AH, 09h
    INT 21h
    MOV AX, f
    CALL PRINT_NUM
    CALL PRINT_NEWLINE

    ; Quadruplet 7: (=, 8.000000, vide, a)
    MOV AX, 8
    MOV a, AX
    LEA DX, MSG_RESULT
    MOV AH, 09h
    INT 21h
    MOV AX, a
    CALL PRINT_NUM
    CALL PRINT_NEWLINE

    ; Quadruplet 8: (=, 3.000000, vide, b)
    MOV AX, 3
    MOV b, AX
    LEA DX, MSG_RESULT
    MOV AH, 09h
    INT 21h
    MOV AX, b
    CALL PRINT_NUM
    CALL PRINT_NEWLINE

    ; Quadruplet 9: (=, 11.000000, vide, w)
    MOV AX, 11
    MOV w, AX
    LEA DX, MSG_RESULT
    MOV AH, 09h
    INT 21h
    MOV AX, w
    CALL PRINT_NUM
    CALL PRINT_NEWLINE

    ; Quadruplet 10: (=, 2.000000, vide, c)
    MOV AX, 2
    MOV c, AX
    LEA DX, MSG_RESULT
    MOV AH, 09h
    INT 21h
    MOV AX, c
    CALL PRINT_NUM
    CALL PRINT_NEWLINE

    ; Quadruplet 11: (=, 5.500000, vide, x)
    MOV AX, 55     ; 5.5 ×10
    MOV x, AX
    LEA DX, MSG_RESULT
    MOV AH, 09h
    INT 21h
    MOV AX, x
    CALL PRINT_FLOAT
    CALL PRINT_NEWLINE

    ; Quadruplet 12: (=, 2.300000, vide, y)
    MOV AX, 23     ; 2.3 ×10
    MOV y, AX
    LEA DX, MSG_RESULT
    MOV AH, 09h
    INT 21h
    MOV AX, y
    CALL PRINT_FLOAT
    CALL PRINT_NEWLINE

    ; Quadruplet 13: (=, 22.000000, vide, resultatInt1)
    MOV AX, 22
    MOV resultatInt1, AX
    LEA DX, MSG_RESULT
    MOV AH, 09h
    INT 21h
    MOV AX, resultatInt1
    CALL PRINT_NUM
    CALL PRINT_NEWLINE

    ; Quadruplet 14: (=, 14.000000, vide, resultatInt2)
    MOV AX, 14
    MOV resultatInt2, AX
    LEA DX, MSG_RESULT
    MOV AH, 09h
    INT 21h
    MOV AX, resultatInt2
    CALL PRINT_NUM
    CALL PRINT_NEWLINE

    ; Quadruplet 15: (=, 3.900000, vide, resultatFloat1)
    MOV AX, 39     ; 3.9 ×10
    MOV resultatFloat1, AX
    LEA DX, MSG_RESULT
    MOV AH, 09h
    INT 21h
    MOV AX, resultatFloat1
    CALL PRINT_FLOAT
    CALL PRINT_NEWLINE

    ; Quadruplet 16: (=, 15.041304, vide, resultatFloat2)
    MOV AX, 150     ; 15.0 ×10
    MOV resultatFloat2, AX
    LEA DX, MSG_RESULT
    MOV AH, 09h
    INT 21h
    MOV AX, resultatFloat2
    CALL PRINT_FLOAT
    CALL PRINT_NEWLINE

    ; Quadruplet 17: (=, 24.500000, vide, mixte1)
    MOV AX, 245     ; 24.5 ×10
    MOV mixte1, AX
    LEA DX, MSG_RESULT
    MOV AH, 09h
    INT 21h
    MOV AX, mixte1
    CALL PRINT_FLOAT
    CALL PRINT_NEWLINE

    ; Quadruplet 18: (=, 4.782609, vide, mixte2)
    MOV AX, 48     ; 4.8 ×10
    MOV mixte2, AX
    LEA DX, MSG_RESULT
    MOV AH, 09h
    INT 21h
    MOV AX, mixte2
    CALL PRINT_FLOAT
    CALL PRINT_NEWLINE

    ; Quadruplet 19: (=, 0, vide, i)
    MOV AX, 0
    MOV i, AX
    LEA DX, MSG_RESULT
    MOV AH, 09h
    INT 21h
    MOV AX, i
    CALL PRINT_NUM
    CALL PRINT_NEWLINE

LABEL_20:
    ; Quadruplet 20: (BG, 27, i, 3.000000)
    MOV AX, i
    MOV BX, 3
    CMP AX, BX
    JG LABEL_27

    ; Quadruplet 21: (+, 1.000000, i, i)
    ; Addition entière
    MOV DX, OFFSET MSG_ADD_INT
    CALL PRINT_MSG
    MOV AX, i
    ADD AX, 1
    MOV i, AX
    MOV AX, i
    CALL PRINT_NUM
    CALL PRINT_NEWLINE

    ; Quadruplet 22: (=, 8.000000, vide, j)
    MOV AX, 8
    MOV j, AX
    LEA DX, MSG_RESULT
    MOV AH, 09h
    INT 21h
    MOV AX, j
    CALL PRINT_NUM
    CALL PRINT_NEWLINE

LABEL_23:
    ; Quadruplet 23: (BE, 26, j, 10)
    MOV AX, j
    MOV BX, 10
    CMP AX, BX
    JE LABEL_26

    ; Quadruplet 24: (+, 1, j, j)
    ; Addition entière
    MOV DX, OFFSET MSG_ADD_INT
    CALL PRINT_MSG
    MOV AX, j
    ADD AX, 1
    MOV j, AX
    MOV AX, j
    CALL PRINT_NUM
    CALL PRINT_NEWLINE

    ; Quadruplet 25: (BR, 23, vide, vide)
    JMP LABEL_23

LABEL_26:
    ; Quadruplet 26: (BR, 20, vide, vide)
    JMP LABEL_20

LABEL_27:
    ; Quadruplet 27: (vide, vide, vide, vide)

    JMP FIN

ERR_UNDERFLOW:
    LEA DX, ERR_UNDERFLOW_MSG
    MOV AH, 09h
    INT 21h
    JMP FIN
ERR_OVERFLOW:
    LEA DX, ERR_OVERFLOW_MSG
    MOV AH, 09h
    INT 21h
    JMP FIN
DIV_ZERO:
    LEA DX, DIV_ZERO_MSG
    MOV AH, 09h
    INT 21h
    JMP FIN
FIN:
    MOV AH, 4Ch
    INT 21h
MAIN ENDP


; ======================================
; SOUS-PROGRAMMES D'AFFICHAGE
; ======================================
PRINT_MSG PROC NEAR
    MOV AH, 09h
    INT 21h
    RET
PRINT_MSG ENDP

PRINT_NUM PROC NEAR
    PUSH BX
    PUSH CX
    PUSH DX
    MOV BX, 10
    XOR CX, CX
    TEST AX, AX
    JNZ CONVERT_LOOP
    MOV DL, '0'
    MOV AH, 02h
    INT 21h
    JMP END_PRINT
CONVERT_LOOP:
    XOR DX, DX
    DIV BX
    PUSH DX
    INC CX
    TEST AX, AX
    JNZ CONVERT_LOOP
PRINT_LOOP:
    POP DX
    ADD DL, '0'
    MOV AH, 02h
    INT 21h
    LOOP PRINT_LOOP
END_PRINT:
    POP DX
    POP CX
    POP BX
    RET
PRINT_NUM ENDP

PRINT_FLOAT PROC NEAR
    PUSH BX
    PUSH CX
    PUSH DX
    ; Diviser par 10 pour séparer partie entière et décimale
    MOV BX, 10
    XOR DX, DX        ; Clear DX for division
    DIV BX            ; AX = partie entière, DX = partie décimale
    MOV INT_PART, AX  ; Stocke la partie entière (16 bits)
    MOV DEC_PART, DL  ; Stocke la partie décimale
    ; Afficher partie entière (16 bits)
    MOV AX, INT_PART
    CALL PRINT_NUM
    ; Afficher point décimal
    MOV DL, '.'
    MOV AH, 02h
    INT 21h
    ; Afficher partie décimale
    MOV AL, DEC_PART
    CALL PRINT_SINGLE_DIGIT
    POP DX
    POP CX
    POP BX
    RET
PRINT_FLOAT ENDP

PRINT_SINGLE_DIGIT PROC NEAR
    ADD AL, '0'
    MOV DL, AL
    MOV AH, 02h
    INT 21h
    RET
PRINT_SINGLE_DIGIT ENDP

PRINT_NEWLINE PROC NEAR
    PUSH AX
    PUSH DX
    LEA DX, NEWLINE
    MOV AH, 09h
    INT 21h
    POP DX
    POP AX
    RET
PRINT_NEWLINE ENDP

PRINT_RESULT PROC NEAR
    PUSH AX
    PUSH DX
    LEA DX, MSG_RESULT
    MOV AH, 09h
    INT 21h
    POP DX
    POP AX
    ; Détection automatique du type
    CMP DX, 0
    JE PRINT_INT
    CALL PRINT_FLOAT
    JMP PRINT_END
PRINT_INT:
    CALL PRINT_NUM
PRINT_END:
    CALL PRINT_NEWLINE
    RET
PRINT_RESULT ENDP

END MAIN
