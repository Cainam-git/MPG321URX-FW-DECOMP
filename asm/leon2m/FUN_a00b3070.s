# leon2m FUN_a00b3070 0xa00b3070-0xa00b3108 (152 bytes)
a00b3070:  9d e3 bf 98  save  %sp, -104, %sp
a00b3074:  7f ff d7 05  call  0xa00a8c88
a00b3078:  a2 10 20 00  clr  %l1
a00b307c:  90 10 21 11  mov  0x111, %o0
a00b3080:  40 02 4e b4  call  0xa0146b50
a00b3084:  92 10 20 00  clr  %o1
a00b3088:  90 10 20 00  clr  %o0
a00b308c:  40 02 4e b8  call  0xa0146b6c
a00b3090:  92 10 20 00  clr  %o1
a00b3094:  a0 10 20 00  clr  %l0
a00b3098:  27 2a 00 b4  sethi  %hi(0xa802d000), %l3
a00b309c:  25 00 06 3a  sethi  %hi(0x18e800), %l2
a00b30a0:  95 2c 20 03  sll  %l0, 3, %o2
a00b30a4:  9e 22 80 10  sub  %o2, %l0, %o7
a00b30a8:  99 2b e0 02  sll  %o7, 2, %o4
a00b30ac:  9a 14 e2 90  or  %l3, 0x290, %o5
a00b30b0:  96 03 00 10  add  %o4, %l0, %o3
a00b30b4:  c2 0b 60 08  ldub  [ %o5 + 8 ], %g1
a00b30b8:  90 02 c0 01  add  %o3, %g1, %o0
a00b30bc:  93 2a 20 10  sll  %o0, 0x10, %o1
a00b30c0:  93 32 60 10  srl  %o1, 0x10, %o1
a00b30c4:  7f ff c1 e0  call  0xa00a3844
a00b30c8:  90 14 a1 f8  or  %l2, 0x1f8, %o0
a00b30cc:  98 10 00 08  mov  %o0, %o4
a00b30d0:  94 04 00 10  add  %l0, %l0, %o2
a00b30d4:  94 02 a0 06  add  %o2, 6, %o2
a00b30d8:  90 10 20 00  clr  %o0
a00b30dc:  92 10 20 2a  mov  0x2a, %o1
a00b30e0:  96 10 20 01  mov  1, %o3
a00b30e4:  9a 10 20 00  clr  %o5
a00b30e8:  7f ff c0 2f  call  0xa00a31a4
a00b30ec:  a2 04 60 01  inc  %l1
a00b30f0:  a0 0c 60 ff  and  %l1, 0xff, %l0
a00b30f4:  80 a4 20 04  cmp  %l0, 4
a00b30f8:  08 bf ff eb  bleu  0xa00b30a4
a00b30fc:  95 2c 20 03  sll  %l0, 3, %o2
a00b3100:  81 c7 e0 08  ret
a00b3104:  81 e8 00 00  restore
