# leon2m FUN_a00b617c 0xa00b617c-0xa00b621c (160 bytes)
a00b617c:  9d e3 bf 98  save  %sp, -104, %sp
a00b6180:  90 10 21 11  mov  0x111, %o0
a00b6184:  40 02 42 73  call  0xa0146b50
a00b6188:  92 10 20 00  clr  %o1
a00b618c:  90 10 20 00  clr  %o0
a00b6190:  40 02 42 77  call  0xa0146b6c
a00b6194:  92 10 20 00  clr  %o1
a00b6198:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00b619c:  a0 10 62 90  or  %g1, 0x290, %l0	! 0xa802d290
a00b61a0:  b2 10 20 00  clr  %i1
a00b61a4:  b4 10 20 00  clr  %i2
a00b61a8:  31 00 06 57  sethi  %hi(0x195c00), %i0
a00b61ac:  83 2e a0 03  sll  %i2, 3, %g1
a00b61b0:  9e 20 40 1a  sub  %g1, %i2, %o7
a00b61b4:  9b 2b e0 02  sll  %o7, 2, %o5
a00b61b8:  96 03 40 1a  add  %o5, %i2, %o3
a00b61bc:  d8 0c 20 08  ldub  [ %l0 + 8 ], %o4
a00b61c0:  90 02 c0 0c  add  %o3, %o4, %o0
a00b61c4:  93 2a 20 10  sll  %o0, 0x10, %o1
a00b61c8:  93 32 60 10  srl  %o1, 0x10, %o1
a00b61cc:  7f ff b5 9e  call  0xa00a3844
a00b61d0:  90 16 23 24  or  %i0, 0x324, %o0
a00b61d4:  98 10 00 08  mov  %o0, %o4
a00b61d8:  94 06 80 1a  add  %i2, %i2, %o2
a00b61dc:  94 02 a0 06  add  %o2, 6, %o2
a00b61e0:  90 10 20 00  clr  %o0
a00b61e4:  92 10 20 2a  mov  0x2a, %o1
a00b61e8:  96 10 20 01  mov  1, %o3
a00b61ec:  9a 10 20 00  clr  %o5
a00b61f0:  7f ff b3 ed  call  0xa00a31a4
a00b61f4:  b2 06 60 01  inc  %i1
a00b61f8:  b4 0e 60 ff  and  %i1, 0xff, %i2
a00b61fc:  80 a6 a0 05  cmp  %i2, 5
a00b6200:  08 bf ff ec  bleu  0xa00b61b0
a00b6204:  83 2e a0 03  sll  %i2, 3, %g1
a00b6208:  f2 0c 21 82  ldub  [ %l0 + 0x182 ], %i1
a00b620c:  b0 10 20 01  mov  1, %i0
a00b6210:  7f ff c7 cb  call  0xa00a813c
a00b6214:  95 e8 20 01  restore  %g0, 1, %o2
a00b6218:  01 00 00 00  nop
