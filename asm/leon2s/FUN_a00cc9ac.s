# leon2s FUN_a00cc9ac 0xa00cc9ac-0xa00cc9f8 (76 bytes)
a00cc9ac:  9d e3 bf 90  save  %sp, -112, %sp
a00cc9b0:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00cc9b4:  c0 37 bf f0  clrh  [ %fp + -16 ]
a00cc9b8:  90 10 00 18  mov  %i0, %o0
a00cc9bc:  92 10 20 00  clr  %o1
a00cc9c0:  40 3b ad 86  call  0xa0fb7fd8
a00cc9c4:  94 10 20 09  mov  9, %o2
a00cc9c8:  82 07 bf f8  add  %fp, -8, %g1
a00cc9cc:  80 8a 20 04  btst  4, %o0
a00cc9d0:  02 80 00 05  be  0xa00cc9e4
a00cc9d4:  9a 00 40 18  add  %g1, %i0, %o5
a00cc9d8:  82 10 20 01  mov  1, %g1
a00cc9dc:  10 80 00 03  b  0xa00cc9e8
a00cc9e0:  c2 2b 7f f8  stb  %g1, [ %o5 + -8 ]
a00cc9e4:  c0 2b 7f f8  clrb  [ %o5 + -8 ]
a00cc9e8:  82 07 80 18  add  %fp, %i0, %g1
a00cc9ec:  f0 08 7f f0  ldub  [ %g1 + -16 ], %i0
a00cc9f0:  81 c7 e0 08  ret
a00cc9f4:  81 e8 00 00  restore
