# leon2m FUN_a01380c4 0xa01380c4-0xa0138110 (76 bytes)
a01380c4:  9d e3 bf 90  save  %sp, -112, %sp
a01380c8:  90 10 20 5d  mov  0x5d, %o0
a01380cc:  92 10 20 04  mov  4, %o1
a01380d0:  94 07 bf f0  add  %fp, -16, %o2
a01380d4:  96 10 20 00  clr  %o3
a01380d8:  c0 27 bf f0  clr  [ %fp + -16 ]
a01380dc:  80 8e 20 ff  btst  0xff, %i0
a01380e0:  12 80 00 09  bne  0xa0138104
a01380e4:  82 10 3f ff  mov  -1, %g1
a01380e8:  f0 2f bf f0  stb  %i0, [ %fp + -16 ]
a01380ec:  7f ff fb fc  call  0xa01370dc
a01380f0:  f2 2f bf f1  stb  %i1, [ %fp + -15 ]
a01380f4:  7f ff fc 94  call  0xa0137344
a01380f8:  90 10 20 01  mov  1, %o0
a01380fc:  03 2a 00 b2  sethi  %hi(0xa802c800), %g1
a0138100:  c2 08 63 a3  ldub  [ %g1 + 0x3a3 ], %g1	! 0xa802cba3
a0138104:  b0 08 60 ff  and  %g1, 0xff, %i0
a0138108:  81 c7 e0 08  ret
a013810c:  81 e8 00 00  restore
