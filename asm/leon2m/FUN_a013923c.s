# leon2m FUN_a013923c 0xa013923c-0xa01392d0 (148 bytes)
a013923c:  9d e3 bf 90  save  %sp, -112, %sp
a0139240:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0139244:  80 a6 20 01  cmp  %i0, 1
a0139248:  02 80 00 0b  be  0xa0139274
a013924c:  c0 27 bf f0  clr  [ %fp + -16 ]
a0139250:  80 a6 20 01  cmp  %i0, 1
a0139254:  04 80 00 0e  ble  0xa013928c
a0139258:  80 a6 20 02  cmp  %i0, 2
a013925c:  02 80 00 09  be  0xa0139280
a0139260:  80 a6 20 03  cmp  %i0, 3
a0139264:  32 80 00 11  bne,a   0xa01392a8
a0139268:  90 10 20 a1  mov  0xa1, %o0
a013926c:  10 80 00 0d  b  0xa01392a0
a0139270:  82 10 20 05  mov  5, %g1
a0139274:  82 10 20 03  mov  3, %g1
a0139278:  10 80 00 0b  b  0xa01392a4
a013927c:  c2 2f bf f0  stb  %g1, [ %fp + -16 ]
a0139280:  82 10 20 04  mov  4, %g1
a0139284:  10 80 00 08  b  0xa01392a4
a0139288:  c2 2f bf f0  stb  %g1, [ %fp + -16 ]
a013928c:  80 a6 20 00  cmp  %i0, 0
a0139290:  02 bf ff fa  be  0xa0139278
a0139294:  82 10 20 02  mov  2, %g1
a0139298:  10 80 00 04  b  0xa01392a8
a013929c:  90 10 20 a1  mov  0xa1, %o0
a01392a0:  c2 2f bf f0  stb  %g1, [ %fp + -16 ]
a01392a4:  90 10 20 a1  mov  0xa1, %o0
a01392a8:  92 10 20 04  mov  4, %o1
a01392ac:  94 07 bf f0  add  %fp, -16, %o2
a01392b0:  7f ff f7 8b  call  0xa01370dc
a01392b4:  96 10 20 00  clr  %o3
a01392b8:  7f ff f8 23  call  0xa0137344
a01392bc:  90 10 20 01  mov  1, %o0
a01392c0:  03 2a 00 b2  sethi  %hi(0xa802c800), %g1
a01392c4:  f0 08 63 a3  ldub  [ %g1 + 0x3a3 ], %i0	! 0xa802cba3
a01392c8:  81 c7 e0 08  ret
a01392cc:  81 e8 00 00  restore
