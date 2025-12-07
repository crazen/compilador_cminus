* C-Minus to TM Code (Stack Machine)
* File: output/input_1765080378042.tm
  0:    LDC  6,1023(0)    initialize Stack Pointer
  1:    LDC  5,0(0)    initialize Global Pointer
  2:     ST  0,0(0)    clear location 0
  3:    LDC  0,5(0)    load main return addr
  5:   HALT  0,0,0    END OF PROGRAM
* -> Inicio Funcao
* main
  6:     ST  0,-1(6)    store return address
* -> Atrib
  7:    LDC  0,5(0)    load const
  8:     ST  0,-2(6)    store local
* <- Atrib
* -> Chamada
  9:     LD  0,-2(6)    load local
 10:    OUT  0,0,0    write integer
* <- Chamada
 11:     LD  7,-1(6)    return to caller
* <- Fim Funcao
  4:    LDC  7,6(0)    jump to main
