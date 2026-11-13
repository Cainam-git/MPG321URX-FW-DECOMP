# leon2m FUN_a00a8654 0xa00a8654-0xa00a86e8 (148 bytes)
a00a8654:  9d e3 bf 98  save  %sp, -104, %sp
a00a8658:  90 10 21 11  mov  0x111, %o0
a00a865c:  40 02 79 3d  call  0xa0146b50
a00a8660:  92 10 20 00  clr  %o1
a00a8664:  90 10 20 00  clr  %o0
a00a8668:  40 02 79 41  call  0xa0146b6c
a00a866c:  92 10 20 00  clr  %o1
a00a8670:  a2 10 20 00  clr  %l1
a00a8674:  a0 10 20 00  clr  %l0
a00a8678:  27 2a 00 b4  sethi  %hi(0xa802d000), %l3
a00a867c:  25 00 06 43  sethi  %hi(0x190c00), %l2
a00a8680:  95 2c 20 03  sll  %l0, 3, %o2
a00a8684:  9e 22 80 10  sub  %o2, %l0, %o7
a00a8688:  99 2b e0 02  sll  %o7, 2, %o4
a00a868c:  9a 14 e2 90  or  %l3, 0x290, %o5
a00a8690:  96 03 00 10  add  %o4, %l0, %o3
a00a8694:  c2 0b 60 08  ldub  [ %o5 + 8 ], %g1
a00a8698:  90 02 c0 01  add  %o3, %g1, %o0
a00a869c:  93 2a 20 10  sll  %o0, 0x10, %o1
a00a86a0:  93 32 60 10  srl  %o1, 0x10, %o1
a00a86a4:  7f ff ec 68  call  0xa00a3844
a00a86a8:  90 14 a0 ec  or  %l2, 0xec, %o0
a00a86ac:  98 10 00 08  mov  %o0, %o4
a00a86b0:  94 04 00 10  add  %l0, %l0, %o2
a00a86b4:  94 02 a0 06  add  %o2, 6, %o2
a00a86b8:  90 10 20 00  clr  %o0
a00a86bc:  92 10 20 2a  mov  0x2a, %o1
a00a86c0:  96 10 20 01  mov  1, %o3
a00a86c4:  9a 10 20 00  clr  %o5
a00a86c8:  7f ff ea b7  call  0xa00a31a4
a00a86cc:  a2 04 60 01  inc  %l1
a00a86d0:  a0 0c 60 ff  and  %l1, 0xff, %l0
a00a86d4:  80 a4 20 02  cmp  %l0, 2
a00a86d8:  08 bf ff eb  bleu  0xa00a8684
a00a86dc:  95 2c 20 03  sll  %l0, 3, %o2
a00a86e0:  81 c7 e0 08  ret
a00a86e4:  81 e8 00 00  restore
