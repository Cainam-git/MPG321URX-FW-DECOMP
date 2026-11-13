# leon2m FUN_a013a7f4 0xa013a7f4-0xa013a824 (48 bytes)
a013a7f4:  9d e3 bf 90  save  %sp, -112, %sp
a013a7f8:  c0 27 bf f4  clr  [ %fp + -12 ]
a013a7fc:  90 10 20 02  mov  2, %o0
a013a800:  92 10 20 4c  mov  0x4c, %o1
a013a804:  94 07 bf f4  add  %fp, -12, %o2
a013a808:  67 fd 47 32  call  0x4008c4d0
a013a80c:  96 10 20 01  mov  1, %o3
a013a810:  c2 0f bf f7  ldub  [ %fp + -9 ], %g1
a013a814:  80 a0 00 01  cmp  %g0, %g1
a013a818:  b0 40 20 00  addx  %g0, 0, %i0
a013a81c:  81 c7 e0 08  ret
a013a820:  81 e8 00 00  restore
