# leon2m FUN_a008a210 0xa008a210-0xa008a2d8 (200 bytes)
a008a210:  9d e3 bf 98  save  %sp, -104, %sp
a008a214:  25 2a 00 ab  sethi  %hi(0xa802ac00), %l2
a008a218:  23 2a 00 ab  sethi  %hi(0xa802ac00), %l1
a008a21c:  c0 2c 63 a0  clrb  [ %l1 + 0x3a0 ]	! 0xa802afa0
a008a220:  7f ff da 7c  call  0xa0080c10
a008a224:  c0 2c a3 a1  clrb  [ %l2 + 0x3a1 ]
a008a228:  40 00 57 c1  call  0xa00a012c
a008a22c:  01 00 00 00  nop
a008a230:  40 00 11 60  call  0xa008e7b0
a008a234:  01 00 00 00  nop
a008a238:  7f ff ff 99  call  0xa008a09c
a008a23c:  01 00 00 00  nop
a008a240:  c2 0c a3 a1  ldub  [ %l2 + 0x3a1 ], %g1
a008a244:  80 a0 60 00  cmp  %g1, 0
a008a248:  02 80 00 22  be  0xa008a2d0
a008a24c:  d0 0c 63 a0  ldub  [ %l1 + 0x3a0 ], %o0
a008a250:  80 a2 20 09  cmp  %o0, 9
a008a254:  18 80 00 1f  bgu  0xa008a2d0
a008a258:  13 2a 00 ab  sethi  %hi(0xa802ac00), %o1
a008a25c:  a8 12 63 a8  or  %o1, 0x3a8, %l4	! 0xa802afa8
a008a260:  aa 10 00 11  mov  %l1, %l5
a008a264:  a6 10 00 12  mov  %l2, %l3
a008a268:  de 0c 63 a0  ldub  [ %l1 + 0x3a0 ], %o7
a008a26c:  da 0c a3 a1  ldub  [ %l2 + 0x3a1 ], %o5
a008a270:  d4 0d 00 0f  ldub  [ %l4 + %o7 ], %o2
a008a274:  96 03 e0 01  add  %o7, 1, %o3
a008a278:  80 a3 60 00  cmp  %o5, 0
a008a27c:  a0 0a a0 ff  and  %o2, 0xff, %l0
a008a280:  d6 2c 63 a0  stb  %o3, [ %l1 + 0x3a0 ]
a008a284:  90 10 00 10  mov  %l0, %o0
a008a288:  02 80 00 03  be  0xa008a294
a008a28c:  9a 03 7f ff  add  %o5, -1, %o5
a008a290:  da 2c a3 a1  stb  %o5, [ %l2 + 0x3a1 ]
a008a294:  7f ff e8 ae  call  0xa008454c
a008a298:  01 00 00 00  nop
a008a29c:  40 00 52 27  call  0xa009eb38
a008a2a0:  90 10 00 10  mov  %l0, %o0
a008a2a4:  40 00 11 41  call  0xa008e7a8
a008a2a8:  90 10 00 10  mov  %l0, %o0
a008a2ac:  7f ff ff 62  call  0xa008a034
a008a2b0:  90 10 00 10  mov  %l0, %o0
a008a2b4:  e0 0c e3 a1  ldub  [ %l3 + 0x3a1 ], %l0
a008a2b8:  80 a4 20 00  cmp  %l0, 0
a008a2bc:  02 80 00 05  be  0xa008a2d0
a008a2c0:  c2 0d 63 a0  ldub  [ %l5 + 0x3a0 ], %g1
a008a2c4:  80 a0 60 09  cmp  %g1, 9
a008a2c8:  08 bf ff e9  bleu  0xa008a26c
a008a2cc:  de 0c 63 a0  ldub  [ %l1 + 0x3a0 ], %o7
a008a2d0:  81 c7 e0 08  ret
a008a2d4:  81 e8 00 00  restore
