# leon2m FUN_a01382b0 0xa01382b0-0xa01382e4 (52 bytes)
a01382b0:  9d e3 bf 90  save  %sp, -112, %sp
a01382b4:  c0 27 bf f0  clr  [ %fp + -16 ]
a01382b8:  d0 0f bf f0  ldub  [ %fp + -16 ], %o0
a01382bc:  82 12 20 3c  or  %o0, 0x3c, %g1
a01382c0:  c2 2f bf f0  stb  %g1, [ %fp + -16 ]
a01382c4:  90 10 20 7f  mov  0x7f, %o0
a01382c8:  92 10 20 04  mov  4, %o1
a01382cc:  94 07 bf f0  add  %fp, -16, %o2
a01382d0:  7f ff fb 83  call  0xa01370dc
a01382d4:  96 10 20 00  clr  %o3
a01382d8:  01 00 00 00  nop
a01382dc:  81 c7 e0 08  ret
a01382e0:  81 e8 00 00  restore
