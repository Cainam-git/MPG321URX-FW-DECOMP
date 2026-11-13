# leon2s FUN_a00d8714 0xa00d8714-0xa00d87fc (232 bytes)
a00d8714:  9d e3 bf 90  save  %sp, -112, %sp
a00d8718:  c2 0f bf f7  ldub  [ %fp + -9 ], %g1
a00d871c:  82 08 7f 80  and  %g1, -128, %g1
a00d8720:  82 10 60 14  or  %g1, 0x14, %g1
a00d8724:  c2 2f bf f7  stb  %g1, [ %fp + -9 ]
a00d8728:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a00d872c:  c0 30 63 fa  clrh  [ %g1 + 0x3fa ]	! 0xa80787fa
a00d8730:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a00d8734:  c0 30 63 f8  clrh  [ %g1 + 0x3f8 ]	! 0xa80787f8
a00d8738:  03 2a 01 d8  sethi  %hi(0xa8076000), %g1
a00d873c:  92 10 60 9c  or  %g1, 0x9c, %o1	! 0xa807609c
a00d8740:  90 10 20 00  clr  %o0
a00d8744:  15 2a 01 e2  sethi  %hi(0xa8078800), %o2
a00d8748:  c2 0a a0 32  ldub  [ %o2 + 0x32 ], %g1	! 0xa8078832
a00d874c:  83 28 60 02  sll  %g1, 2, %g1
a00d8750:  d8 02 40 01  ld  [ %o1 + %g1 ], %o4
a00d8754:  d6 03 22 ac  ld  [ %o4 + 0x2ac ], %o3
a00d8758:  9a 0a 20 ff  and  %o0, 0xff, %o5
a00d875c:  96 0a e0 ff  and  %o3, 0xff, %o3
a00d8760:  9a 03 60 01  inc  %o5
a00d8764:  9b 2b 60 06  sll  %o5, 6, %o5
a00d8768:  82 0a e0 3f  and  %o3, 0x3f, %g1
a00d876c:  82 10 40 0d  or  %g1, %o5, %g1
a00d8770:  c2 23 22 ac  st  %g1, [ %o4 + 0x2ac ]
a00d8774:  c2 0a a0 32  ldub  [ %o2 + 0x32 ], %g1
a00d8778:  83 28 60 02  sll  %g1, 2, %g1
a00d877c:  c2 02 40 01  ld  [ %o1 + %g1 ], %g1
a00d8780:  c0 20 62 84  clr  [ %g1 + 0x284 ]
a00d8784:  c2 0a a0 32  ldub  [ %o2 + 0x32 ], %g1
a00d8788:  83 28 60 02  sll  %g1, 2, %g1
a00d878c:  da 02 40 01  ld  [ %o1 + %g1 ], %o5
a00d8790:  c2 03 62 b0  ld  [ %o5 + 0x2b0 ], %g1
a00d8794:  82 10 60 10  or  %g1, 0x10, %g1
a00d8798:  c2 23 62 b0  st  %g1, [ %o5 + 0x2b0 ]
a00d879c:  c2 0a a0 32  ldub  [ %o2 + 0x32 ], %g1
a00d87a0:  83 28 60 02  sll  %g1, 2, %g1
a00d87a4:  da 02 40 01  ld  [ %o1 + %g1 ], %o5
a00d87a8:  c2 03 62 b0  ld  [ %o5 + 0x2b0 ], %g1
a00d87ac:  82 08 7f ef  and  %g1, -17, %g1
a00d87b0:  c2 23 62 b0  st  %g1, [ %o5 + 0x2b0 ]
a00d87b4:  c2 0a a0 32  ldub  [ %o2 + 0x32 ], %g1
a00d87b8:  83 28 60 02  sll  %g1, 2, %g1
a00d87bc:  90 02 20 01  inc  %o0
a00d87c0:  c2 02 40 01  ld  [ %o1 + %g1 ], %g1
a00d87c4:  9a 0a 20 ff  and  %o0, 0xff, %o5
a00d87c8:  d6 20 62 ac  st  %o3, [ %g1 + 0x2ac ]
a00d87cc:  80 a3 60 03  cmp  %o5, 3
a00d87d0:  08 bf ff df  bleu  0xa00d874c
a00d87d4:  c2 0a a0 32  ldub  [ %o2 + 0x32 ], %g1
a00d87d8:  90 07 bf f7  add  %fp, -9, %o0
a00d87dc:  92 10 20 02  mov  2, %o1
a00d87e0:  94 10 20 01  mov  1, %o2
a00d87e4:  96 10 20 06  mov  6, %o3
a00d87e8:  7f ff fc 4d  call  0xa00d791c
a00d87ec:  98 10 20 01  mov  1, %o4
a00d87f0:  01 00 00 00  nop
a00d87f4:  81 c7 e0 08  ret
a00d87f8:  81 e8 00 00  restore
