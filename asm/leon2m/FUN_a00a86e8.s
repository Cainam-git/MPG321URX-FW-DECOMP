# leon2m FUN_a00a86e8 0xa00a86e8-0xa00a87cc (228 bytes)
a00a86e8:  9d e3 bf 98  save  %sp, -104, %sp
a00a86ec:  90 10 21 11  mov  0x111, %o0
a00a86f0:  40 02 79 18  call  0xa0146b50
a00a86f4:  92 10 20 00  clr  %o1
a00a86f8:  90 10 20 00  clr  %o0
a00a86fc:  40 02 79 1c  call  0xa0146b6c
a00a8700:  92 10 20 00  clr  %o1
a00a8704:  27 2a 00 b4  sethi  %hi(0xa802d000), %l3
a00a8708:  82 14 e2 90  or  %l3, 0x290, %g1	! 0xa802d290
a00a870c:  d8 08 60 20  ldub  [ %g1 + 0x20 ], %o4
a00a8710:  da 08 60 1e  ldub  [ %g1 + 0x1e ], %o5
a00a8714:  80 a3 40 0c  cmp  %o5, %o4
a00a8718:  22 80 00 06  be,a   0xa00a8730
a00a871c:  90 10 20 2a  mov  0x2a, %o0
a00a8720:  a2 10 20 00  clr  %l1
a00a8724:  a0 10 20 00  clr  %l0
a00a8728:  10 80 00 0f  b  0xa00a8764
a00a872c:  25 00 06 0a  sethi  %hi(0x182800), %l2
a00a8730:  92 10 20 0c  mov  0xc, %o1
a00a8734:  94 10 20 0b  mov  0xb, %o2
a00a8738:  96 10 22 96  mov  0x296, %o3
a00a873c:  40 02 78 d1  call  0xa0146a80
a00a8740:  98 10 20 00  clr  %o4
a00a8744:  90 10 20 2a  mov  0x2a, %o0
a00a8748:  92 10 20 0e  mov  0xe, %o1
a00a874c:  94 10 20 0b  mov  0xb, %o2
a00a8750:  96 10 22 96  mov  0x296, %o3
a00a8754:  40 02 78 cb  call  0xa0146a80
a00a8758:  98 10 20 00  clr  %o4
a00a875c:  10 bf ff f2  b  0xa00a8724
a00a8760:  a2 10 20 00  clr  %l1
a00a8764:  95 2c 20 03  sll  %l0, 3, %o2
a00a8768:  82 22 80 10  sub  %o2, %l0, %g1
a00a876c:  9b 28 60 02  sll  %g1, 2, %o5
a00a8770:  98 14 e2 90  or  %l3, 0x290, %o4
a00a8774:  96 03 40 10  add  %o5, %l0, %o3
a00a8778:  de 0b 20 08  ldub  [ %o4 + 8 ], %o7
a00a877c:  90 02 c0 0f  add  %o3, %o7, %o0
a00a8780:  93 2a 20 10  sll  %o0, 0x10, %o1
a00a8784:  93 32 60 10  srl  %o1, 0x10, %o1
a00a8788:  7f ff ec 2f  call  0xa00a3844
a00a878c:  90 14 a0 c0  or  %l2, 0xc0, %o0
a00a8790:  98 10 00 08  mov  %o0, %o4
a00a8794:  94 04 00 10  add  %l0, %l0, %o2
a00a8798:  94 02 a0 06  add  %o2, 6, %o2
a00a879c:  90 10 20 00  clr  %o0
a00a87a0:  92 10 20 2a  mov  0x2a, %o1
a00a87a4:  96 10 20 01  mov  1, %o3
a00a87a8:  9a 10 20 00  clr  %o5
a00a87ac:  7f ff ea 7e  call  0xa00a31a4
a00a87b0:  a2 04 60 01  inc  %l1
a00a87b4:  a0 0c 60 ff  and  %l1, 0xff, %l0
a00a87b8:  80 a4 20 04  cmp  %l0, 4
a00a87bc:  08 bf ff eb  bleu  0xa00a8768
a00a87c0:  95 2c 20 03  sll  %l0, 3, %o2
a00a87c4:  81 c7 e0 08  ret
a00a87c8:  81 e8 00 00  restore
