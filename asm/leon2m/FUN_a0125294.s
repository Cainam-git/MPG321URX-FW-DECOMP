# leon2m FUN_a0125294 0xa0125294-0xa01252c4 (48 bytes)
a0125294:  1b 00 06 90  sethi  %hi(0x1a4000), %o5
a0125298:  90 0a 20 ff  and  %o0, 0xff, %o0
a012529c:  82 13 62 a8  or  %o5, 0x2a8, %g1
a01252a0:  90 5a 20 16  smul  %o0, 0x16, %o0
a01252a4:  90 02 00 01  add  %o0, %g1, %o0
a01252a8:  da 0a 20 01  ldub  [ %o0 + 1 ], %o5
a01252ac:  80 a3 60 02  cmp  %o5, 2
a01252b0:  12 80 00 03  bne  0xa01252bc
a01252b4:  82 10 20 0f  mov  0xf, %g1
a01252b8:  c2 0a 20 12  ldub  [ %o0 + 0x12 ], %g1
a01252bc:  81 c3 e0 08  retl
a01252c0:  90 10 00 01  mov  %g1, %o0
