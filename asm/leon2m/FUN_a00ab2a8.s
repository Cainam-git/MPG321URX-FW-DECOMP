# leon2m FUN_a00ab2a8 0xa00ab2a8-0xa00ab340 (152 bytes)
a00ab2a8:  9d e3 bf 98  save  %sp, -104, %sp
a00ab2ac:  7f ff f6 77  call  0xa00a8c88
a00ab2b0:  a2 10 20 00  clr  %l1
a00ab2b4:  90 10 21 11  mov  0x111, %o0
a00ab2b8:  40 02 6e 26  call  0xa0146b50
a00ab2bc:  92 10 20 00  clr  %o1
a00ab2c0:  90 10 20 00  clr  %o0
a00ab2c4:  40 02 6e 2a  call  0xa0146b6c
a00ab2c8:  92 10 20 00  clr  %o1
a00ab2cc:  a0 10 20 00  clr  %l0
a00ab2d0:  27 2a 00 b4  sethi  %hi(0xa802d000), %l3
a00ab2d4:  25 00 06 3d  sethi  %hi(0x18f400), %l2
a00ab2d8:  95 2c 20 03  sll  %l0, 3, %o2
a00ab2dc:  9e 22 80 10  sub  %o2, %l0, %o7
a00ab2e0:  99 2b e0 02  sll  %o7, 2, %o4
a00ab2e4:  9a 14 e2 90  or  %l3, 0x290, %o5
a00ab2e8:  96 03 00 10  add  %o4, %l0, %o3
a00ab2ec:  c2 0b 60 08  ldub  [ %o5 + 8 ], %g1
a00ab2f0:  90 02 c0 01  add  %o3, %g1, %o0
a00ab2f4:  93 2a 20 10  sll  %o0, 0x10, %o1
a00ab2f8:  93 32 60 10  srl  %o1, 0x10, %o1
a00ab2fc:  7f ff e1 52  call  0xa00a3844
a00ab300:  90 14 a1 50  or  %l2, 0x150, %o0
a00ab304:  98 10 00 08  mov  %o0, %o4
a00ab308:  94 04 00 10  add  %l0, %l0, %o2
a00ab30c:  94 02 a0 06  add  %o2, 6, %o2
a00ab310:  90 10 20 00  clr  %o0
a00ab314:  92 10 20 2a  mov  0x2a, %o1
a00ab318:  96 10 20 01  mov  1, %o3
a00ab31c:  9a 10 20 00  clr  %o5
a00ab320:  7f ff df a1  call  0xa00a31a4
a00ab324:  a2 04 60 01  inc  %l1
a00ab328:  a0 0c 60 ff  and  %l1, 0xff, %l0
a00ab32c:  80 a4 20 02  cmp  %l0, 2
a00ab330:  08 bf ff eb  bleu  0xa00ab2dc
a00ab334:  95 2c 20 03  sll  %l0, 3, %o2
a00ab338:  81 c7 e0 08  ret
a00ab33c:  81 e8 00 00  restore
