# leon2m FUN_a013808c 0xa013808c-0xa01380c4 (56 bytes)
a013808c:  9d e3 bf 90  save  %sp, -112, %sp
a0138090:  c0 27 bf f0  clr  [ %fp + -16 ]
a0138094:  f0 2f bf f0  stb  %i0, [ %fp + -16 ]
a0138098:  90 10 20 5c  mov  0x5c, %o0
a013809c:  92 10 20 04  mov  4, %o1
a01380a0:  94 07 bf f0  add  %fp, -16, %o2
a01380a4:  7f ff fc 0e  call  0xa01370dc
a01380a8:  96 10 20 00  clr  %o3
a01380ac:  7f ff fc a6  call  0xa0137344
a01380b0:  90 10 20 01  mov  1, %o0
a01380b4:  03 2a 00 b2  sethi  %hi(0xa802c800), %g1
a01380b8:  f0 08 63 a3  ldub  [ %g1 + 0x3a3 ], %i0	! 0xa802cba3
a01380bc:  81 c7 e0 08  ret
a01380c0:  81 e8 00 00  restore
