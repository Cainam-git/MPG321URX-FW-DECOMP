# leon2m FUN_a01382e4 0xa01382e4-0xa013832c (72 bytes)
a01382e4:  9d e3 bf 90  save  %sp, -112, %sp
a01382e8:  11 2a 00 b8  sethi  %hi(0xa802e000), %o0
a01382ec:  82 12 23 d0  or  %o0, 0x3d0, %g1	! 0xa802e3d0
a01382f0:  c0 27 bf f0  clr  [ %fp + -16 ]
a01382f4:  d6 08 60 32  ldub  [ %g1 + 0x32 ], %o3
a01382f8:  da 08 60 30  ldub  [ %g1 + 0x30 ], %o5
a01382fc:  d8 08 60 31  ldub  [ %g1 + 0x31 ], %o4
a0138300:  d6 2f bf f2  stb  %o3, [ %fp + -14 ]
a0138304:  da 2f bf f0  stb  %o5, [ %fp + -16 ]
a0138308:  d8 2f bf f1  stb  %o4, [ %fp + -15 ]
a013830c:  90 10 20 7e  mov  0x7e, %o0
a0138310:  92 10 20 04  mov  4, %o1
a0138314:  94 07 bf f0  add  %fp, -16, %o2
a0138318:  7f ff fb 71  call  0xa01370dc
a013831c:  96 10 20 00  clr  %o3
a0138320:  01 00 00 00  nop
a0138324:  81 c7 e0 08  ret
a0138328:  81 e8 00 00  restore
