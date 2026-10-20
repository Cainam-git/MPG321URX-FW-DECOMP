# leon2s FUN_a00b15ac 0xa00b15ac-0xa00b15d8 (44 bytes)
a00b15ac:  94 02 bf ff  add  %o2, -1, %o2
a00b15b0:  80 a2 bf ff  cmp  %o2, -1
a00b15b4:  02 80 00 07  be  0xa00b15d0
a00b15b8:  82 10 00 08  mov  %o0, %g1
a00b15bc:  d2 28 40 00  stb  %o1, [ %g1 ]
a00b15c0:  94 02 bf ff  add  %o2, -1, %o2
a00b15c4:  80 a2 bf ff  cmp  %o2, -1
a00b15c8:  12 bf ff fd  bne  0xa00b15bc
a00b15cc:  82 00 60 01  inc  %g1
a00b15d0:  81 c3 e0 08  retl
a00b15d4:  01 00 00 00  nop
