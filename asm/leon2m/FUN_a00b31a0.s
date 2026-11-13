# leon2m FUN_a00b31a0 0xa00b31a0-0xa00b3238 (152 bytes)
a00b31a0:  9d e3 bf 98  save  %sp, -104, %sp
a00b31a4:  7f ff d6 b9  call  0xa00a8c88
a00b31a8:  a2 10 20 00  clr  %l1
a00b31ac:  90 10 21 11  mov  0x111, %o0
a00b31b0:  40 02 4e 68  call  0xa0146b50
a00b31b4:  92 10 20 00  clr  %o1
a00b31b8:  90 10 20 00  clr  %o0
a00b31bc:  40 02 4e 6c  call  0xa0146b6c
a00b31c0:  92 10 20 00  clr  %o1
a00b31c4:  a0 10 20 00  clr  %l0
a00b31c8:  27 2a 00 b4  sethi  %hi(0xa802d000), %l3
a00b31cc:  25 00 06 3d  sethi  %hi(0x18f400), %l2
a00b31d0:  95 2c 20 03  sll  %l0, 3, %o2
a00b31d4:  9e 22 80 10  sub  %o2, %l0, %o7
a00b31d8:  99 2b e0 02  sll  %o7, 2, %o4
a00b31dc:  9a 14 e2 90  or  %l3, 0x290, %o5
a00b31e0:  96 03 00 10  add  %o4, %l0, %o3
a00b31e4:  c2 0b 60 08  ldub  [ %o5 + 8 ], %g1
a00b31e8:  90 02 c0 01  add  %o3, %g1, %o0
a00b31ec:  93 2a 20 10  sll  %o0, 0x10, %o1
a00b31f0:  93 32 60 10  srl  %o1, 0x10, %o1
a00b31f4:  7f ff c1 94  call  0xa00a3844
a00b31f8:  90 14 a1 50  or  %l2, 0x150, %o0
a00b31fc:  98 10 00 08  mov  %o0, %o4
a00b3200:  94 04 00 10  add  %l0, %l0, %o2
a00b3204:  94 02 a0 06  add  %o2, 6, %o2
a00b3208:  90 10 20 00  clr  %o0
a00b320c:  92 10 20 2a  mov  0x2a, %o1
a00b3210:  96 10 20 01  mov  1, %o3
a00b3214:  9a 10 20 00  clr  %o5
a00b3218:  7f ff bf e3  call  0xa00a31a4
a00b321c:  a2 04 60 01  inc  %l1
a00b3220:  a0 0c 60 ff  and  %l1, 0xff, %l0
a00b3224:  80 a4 20 02  cmp  %l0, 2
a00b3228:  08 bf ff eb  bleu  0xa00b31d4
a00b322c:  95 2c 20 03  sll  %l0, 3, %o2
a00b3230:  81 c7 e0 08  ret
a00b3234:  81 e8 00 00  restore
