* C-Minus to TM Code (Stack Machine)
* File: output/input_1765078328802.tm
  0:    LDC  6,1023(0)    initialize Stack Pointer
  1:    LDC  5,0(0)    initialize Global Pointer
  2:     ST  0,0(0)    clear location 0
  3:    LDC  0,5(0)    load main return addr
  5:   HALT  0,0,0    END OF PROGRAM
* -> Inicio Funcao
* fatorial
  6:     ST  0,-1(6)    store return address
* -> If
  7:     LD  0,-2(6)    load local
  8:     ST  0,-20(6)    op: push left
  9:    LDC  0,1(0)    load const
 10:     LD  1,-20(6)    op: load left
 11:    SUB  0,1,0    op default
* -> Return
 13:    LDC  0,1(0)    load const
 14:     LD  7,-1(6)    return to caller
* <- Return
 12:    JEQ  0,3(7)    if: jump false
* -> Return
 16:     LD  0,-2(6)    load local
 17:     ST  0,-20(6)    op: push left
* -> Chamada
 18:     LD  0,-2(6)    load local
 19:     ST  0,-21(6)    op: push left
 20:    LDC  0,1(0)    load const
 21:     LD  1,-21(6)    op: load left
 22:    SUB  0,1,0    op -
 23:     ST  0,-23(6)    push argument
 24:     ST  6,-21(6)    store old MP
 25:    LDA  6,-21(6)    push new frame
 26:    LDC  0,28(0)    load return address
 28:     LD  6,0(6)    pop frame
* <- Chamada
 29:     LD  1,-20(6)    op: load left
 30:    MUL  0,1,0    op *
 31:     LD  7,-1(6)    return to caller
* <- Return
 15:    LDA  7,16(7)    if: jump end
* <- If
 32:     LD  7,-1(6)    return to caller
* <- Fim Funcao
* -> Inicio Funcao
* main
 33:     ST  0,-1(6)    store return address
* -> Atrib
* -> Chamada
 34:     IN  0,0,0    read integer
* <- Chamada
 35:     ST  0,-2(6)    store local
* <- Atrib
* -> Chamada
* -> Chamada
 36:     LD  0,-2(6)    load local
 37:     ST  0,-22(6)    push argument
 38:     ST  6,-20(6)    store old MP
 39:    LDA  6,-20(6)    push new frame
 40:    LDC  0,42(0)    load return address
 42:     LD  6,0(6)    pop frame
* <- Chamada
 43:    OUT  0,0,0    write integer
* <- Chamada
 44:     LD  7,-1(6)    return to caller
* <- Fim Funcao
  4:    LDC  7,33(0)    jump to main
 41:    LDC  7,6(0)    jump to func
 27:    LDC  7,6(0)    jump to func
