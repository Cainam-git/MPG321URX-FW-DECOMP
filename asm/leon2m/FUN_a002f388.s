# leon2m FUN_a002f388 0xa002f388-0xa002f3f4 (108 bytes)
a002f388:  9d e3 bf 90  save  %sp, -112, %sp
a002f38c:  90 10 20 00  clr  %o0
a002f390:  92 10 20 b8  mov  0xb8, %o1
a002f394:  94 07 bf f4  add  %fp, -12, %o2
a002f398:  96 10 20 01  mov  1, %o3
a002f39c:  7f ff f4 4d  call  0xa002c4d0
a002f3a0:  c0 27 bf f4  clr  [ %fp + -12 ]
a002f3a4:  d2 07 bf f4  ld  [ %fp + -12 ], %o1
a002f3a8:  90 0a 7f 00  and  %o1, -256, %o0
a002f3ac:  82 12 20 01  or  %o0, 1, %g1
a002f3b0:  c2 27 bf f4  st  %g1, [ %fp + -12 ]
a002f3b4:  90 10 20 00  clr  %o0
a002f3b8:  92 10 20 b8  mov  0xb8, %o1
a002f3bc:  94 07 bf f4  add  %fp, -12, %o2
a002f3c0:  7f ff f4 8e  call  0xa002c5f8
a002f3c4:  96 10 20 01  mov  1, %o3
a002f3c8:  94 07 bf f4  add  %fp, -12, %o2
a002f3cc:  90 10 20 00  clr  %o0
a002f3d0:  92 10 20 b8  mov  0xb8, %o1
a002f3d4:  7f ff f4 3f  call  0xa002c4d0
a002f3d8:  96 10 20 01  mov  1, %o3
a002f3dc:  d4 0f bf f7  ldub  [ %fp + -9 ], %o2
a002f3e0:  80 a2 a0 02  cmp  %o2, 2
a002f3e4:  12 bf ff fa  bne  0xa002f3cc
a002f3e8:  94 07 bf f4  add  %fp, -12, %o2
a002f3ec:  81 c7 e0 08  ret
a002f3f0:  81 e8 00 00  restore
