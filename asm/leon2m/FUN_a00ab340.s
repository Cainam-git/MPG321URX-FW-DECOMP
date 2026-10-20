# leon2m FUN_a00ab340 0xa00ab340-0xa00ab3d8 (152 bytes)
a00ab340:  9d e3 bf 98  save  %sp, -104, %sp
a00ab344:  7f ff f6 51  call  0xa00a8c88
a00ab348:  a2 10 20 00  clr  %l1
a00ab34c:  90 10 21 11  mov  0x111, %o0
a00ab350:  40 02 6e 00  call  0xa0146b50
a00ab354:  92 10 20 00  clr  %o1
a00ab358:  90 10 20 00  clr  %o0
a00ab35c:  40 02 6e 04  call  0xa0146b6c
a00ab360:  92 10 20 00  clr  %o1
a00ab364:  a0 10 20 00  clr  %l0
a00ab368:  27 2a 00 b4  sethi  %hi(0xa802d000), %l3
a00ab36c:  25 00 06 3a  sethi  %hi(0x18e800), %l2
a00ab370:  95 2c 20 03  sll  %l0, 3, %o2
a00ab374:  9e 22 80 10  sub  %o2, %l0, %o7
a00ab378:  99 2b e0 02  sll  %o7, 2, %o4
a00ab37c:  9a 14 e2 90  or  %l3, 0x290, %o5
a00ab380:  96 03 00 10  add  %o4, %l0, %o3
a00ab384:  c2 0b 60 08  ldub  [ %o5 + 8 ], %g1
a00ab388:  90 02 c0 01  add  %o3, %g1, %o0
a00ab38c:  93 2a 20 10  sll  %o0, 0x10, %o1
a00ab390:  93 32 60 10  srl  %o1, 0x10, %o1
a00ab394:  7f ff e1 2c  call  0xa00a3844
a00ab398:  90 14 a1 f8  or  %l2, 0x1f8, %o0
a00ab39c:  98 10 00 08  mov  %o0, %o4
a00ab3a0:  94 04 00 10  add  %l0, %l0, %o2
a00ab3a4:  94 02 a0 06  add  %o2, 6, %o2
a00ab3a8:  90 10 20 00  clr  %o0
a00ab3ac:  92 10 20 2a  mov  0x2a, %o1
a00ab3b0:  96 10 20 01  mov  1, %o3
a00ab3b4:  9a 10 20 00  clr  %o5
a00ab3b8:  7f ff df 7b  call  0xa00a31a4
a00ab3bc:  a2 04 60 01  inc  %l1
a00ab3c0:  a0 0c 60 ff  and  %l1, 0xff, %l0
a00ab3c4:  80 a4 20 04  cmp  %l0, 4
a00ab3c8:  08 bf ff eb  bleu  0xa00ab374
a00ab3cc:  95 2c 20 03  sll  %l0, 3, %o2
a00ab3d0:  81 c7 e0 08  ret
a00ab3d4:  81 e8 00 00  restore
