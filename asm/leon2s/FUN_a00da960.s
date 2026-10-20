# leon2s FUN_a00da960 0xa00da960-0xa00da9e8 (136 bytes)
a00da960:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a00da964:  da 08 63 fc  ldub  [ %g1 + 0x3fc ], %o5	! 0xa80787fc
a00da968:  03 2a 01 e7  sethi  %hi(0xa8079c00), %g1
a00da96c:  82 10 60 50  or  %g1, 0x50, %g1	! 0xa8079c50
a00da970:  9a 03 40 01  add  %o5, %g1, %o5
a00da974:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a00da978:  c2 08 60 3b  ldub  [ %g1 + 0x3b ], %g1	! 0xa807883b
a00da97c:  80 a0 60 00  cmp  %g1, 0
a00da980:  d8 0b 7f ff  ldub  [ %o5 + -1 ], %o4
a00da984:  17 2a 01 d8  sethi  %hi(0xa8076000), %o3
a00da988:  12 80 00 05  bne  0xa00da99c
a00da98c:  13 2a 01 e2  sethi  %hi(0xa8078800), %o1
a00da990:  9a 10 20 01  mov  1, %o5
a00da994:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a00da998:  da 28 60 3c  stb  %o5, [ %g1 + 0x3c ]	! 0xa807883c
a00da99c:  80 8a 20 ff  btst  0xff, %o0
a00da9a0:  02 80 00 10  be  0xa00da9e0
a00da9a4:  80 a3 20 00  cmp  %o4, 0
a00da9a8:  12 80 00 08  bne  0xa00da9c8
a00da9ac:  94 12 e0 a4  or  %o3, 0xa4, %o2
a00da9b0:  c2 0a 60 32  ldub  [ %o1 + 0x32 ], %g1
a00da9b4:  83 28 60 02  sll  %g1, 2, %g1
a00da9b8:  da 02 80 01  ld  [ %o2 + %g1 ], %o5
a00da9bc:  c2 03 6c cc  ld  [ %o5 + 0xccc ], %g1
a00da9c0:  10 80 00 07  b  0xa00da9dc
a00da9c4:  82 08 7f ef  and  %g1, -17, %g1
a00da9c8:  c2 0a 60 32  ldub  [ %o1 + 0x32 ], %g1
a00da9cc:  83 28 60 02  sll  %g1, 2, %g1
a00da9d0:  da 02 80 01  ld  [ %o2 + %g1 ], %o5
a00da9d4:  c2 03 6c cc  ld  [ %o5 + 0xccc ], %g1
a00da9d8:  82 08 7f df  and  %g1, -33, %g1
a00da9dc:  c2 23 6c cc  st  %g1, [ %o5 + 0xccc ]
a00da9e0:  81 c3 e0 08  retl
a00da9e4:  01 00 00 00  nop
