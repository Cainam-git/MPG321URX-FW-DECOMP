# leon2m FUN_a01391a8 0xa01391a8-0xa013923c (148 bytes)
a01391a8:  9d e3 bf 90  save  %sp, -112, %sp
a01391ac:  b0 0e 20 ff  and  %i0, 0xff, %i0
a01391b0:  80 a6 20 01  cmp  %i0, 1
a01391b4:  02 80 00 0b  be  0xa01391e0
a01391b8:  c0 27 bf f0  clr  [ %fp + -16 ]
a01391bc:  80 a6 20 01  cmp  %i0, 1
a01391c0:  04 80 00 0e  ble  0xa01391f8
a01391c4:  80 a6 20 02  cmp  %i0, 2
a01391c8:  02 80 00 09  be  0xa01391ec
a01391cc:  80 a6 20 03  cmp  %i0, 3
a01391d0:  32 80 00 11  bne,a   0xa0139214
a01391d4:  90 10 20 a4  mov  0xa4, %o0
a01391d8:  10 80 00 0d  b  0xa013920c
a01391dc:  82 10 20 05  mov  5, %g1
a01391e0:  82 10 20 03  mov  3, %g1
a01391e4:  10 80 00 0b  b  0xa0139210
a01391e8:  c2 2f bf f0  stb  %g1, [ %fp + -16 ]
a01391ec:  82 10 20 04  mov  4, %g1
a01391f0:  10 80 00 08  b  0xa0139210
a01391f4:  c2 2f bf f0  stb  %g1, [ %fp + -16 ]
a01391f8:  80 a6 20 00  cmp  %i0, 0
a01391fc:  02 bf ff fa  be  0xa01391e4
a0139200:  82 10 20 02  mov  2, %g1
a0139204:  10 80 00 04  b  0xa0139214
a0139208:  90 10 20 a4  mov  0xa4, %o0
a013920c:  c2 2f bf f0  stb  %g1, [ %fp + -16 ]
a0139210:  90 10 20 a4  mov  0xa4, %o0
a0139214:  92 10 20 04  mov  4, %o1
a0139218:  94 07 bf f0  add  %fp, -16, %o2
a013921c:  7f ff f7 b0  call  0xa01370dc
a0139220:  96 10 20 00  clr  %o3
a0139224:  7f ff f8 48  call  0xa0137344
a0139228:  90 10 20 01  mov  1, %o0
a013922c:  03 2a 00 b2  sethi  %hi(0xa802c800), %g1
a0139230:  f0 08 63 a3  ldub  [ %g1 + 0x3a3 ], %i0	! 0xa802cba3
a0139234:  81 c7 e0 08  ret
a0139238:  81 e8 00 00  restore
