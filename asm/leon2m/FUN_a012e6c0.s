# leon2m FUN_a012e6c0 0xa012e6c0-0xa012e82c (364 bytes)
a012e6c0:  9d e3 bf 68  save  %sp, -152, %sp
a012e6c4:  98 10 20 00  clr  %o4
a012e6c8:  9a 10 20 00  clr  %o5
a012e6cc:  b0 0e 20 ff  and  %i0, 0xff, %i0
a012e6d0:  d8 3f bf e8  std  %o4, [ %fp + -24 ]
a012e6d4:  d8 3f bf e0  std  %o4, [ %fp + -32 ]
a012e6d8:  c0 37 bf f0  clrh  [ %fp + -16 ]
a012e6dc:  80 8e 20 07  btst  7, %i0
a012e6e0:  12 80 00 3b  bne  0xa012e7cc
a012e6e4:  98 10 20 00  clr  %o4
a012e6e8:  98 10 3f ff  mov  -1, %o4
a012e6ec:  9e 0b 20 ff  and  %o4, 0xff, %o7
a012e6f0:  15 2a 00 b8  sethi  %hi(0xa802e000), %o2
a012e6f4:  96 12 a1 a0  or  %o2, 0x1a0, %o3	! 0xa802e1a0
a012e6f8:  93 2b e0 03  sll  %o7, 3, %o1
a012e6fc:  90 02 40 0f  add  %o1, %o7, %o0
a012e700:  da 0a e0 37  ldub  [ %o3 + 0x37 ], %o5
a012e704:  d8 02 e0 34  ld  [ %o3 + 0x34 ], %o4
a012e708:  80 a3 60 01  cmp  %o5, 1
a012e70c:  82 02 00 08  add  %o0, %o0, %g1
a012e710:  99 33 20 08  srl  %o4, 8, %o4
a012e714:  08 80 00 03  bleu  0xa012e720
a012e718:  92 10 21 20  mov  0x120, %o1
a012e71c:  92 10 22 40  mov  0x240, %o1
a012e720:  96 0a 63 60  and  %o1, 0x360, %o3
a012e724:  9a 02 e0 30  add  %o3, 0x30, %o5
a012e728:  90 03 00 0d  add  %o4, %o5, %o0
a012e72c:  b0 02 00 01  add  %o0, %g1, %i0
a012e730:  a1 2e 20 10  sll  %i0, 0x10, %l0
a012e734:  a2 12 a1 a0  or  %o2, 0x1a0, %l1
a012e738:  93 34 20 10  srl  %l0, 0x10, %o1
a012e73c:  d0 0c 60 34  ldub  [ %l1 + 0x34 ], %o0
a012e740:  94 10 20 12  mov  0x12, %o2
a012e744:  40 00 47 07  call  0xa0140360
a012e748:  96 07 bf e0  add  %fp, -32, %o3
a012e74c:  b0 10 20 00  clr  %i0
a012e750:  92 10 20 00  clr  %o1
a012e754:  a0 07 bf f8  add  %fp, -8, %l0
a012e758:  a2 10 20 80  mov  0x80, %l1
a012e75c:  98 02 40 09  add  %o1, %o1, %o4
a012e760:  90 03 00 09  add  %o4, %o1, %o0
a012e764:  96 02 00 08  add  %o0, %o0, %o3
a012e768:  82 02 c0 10  add  %o3, %l0, %g1
a012e76c:  d4 08 7f eb  ldub  [ %g1 + -21 ], %o2
a012e770:  da 08 7f ed  ldub  [ %g1 + -19 ], %o5
a012e774:  97 2a a0 08  sll  %o2, 8, %o3
a012e778:  95 2b 60 08  sll  %o5, 8, %o2
a012e77c:  de 08 7f e9  ldub  [ %g1 + -23 ], %o7
a012e780:  9b 2a 60 03  sll  %o1, 3, %o5
a012e784:  d2 08 7f e8  ldub  [ %g1 + -24 ], %o1
a012e788:  99 2b e0 08  sll  %o7, 8, %o4
a012e78c:  d0 08 7f ea  ldub  [ %g1 + -22 ], %o0
a012e790:  de 08 7f ec  ldub  [ %g1 + -20 ], %o7
a012e794:  98 13 00 09  or  %o4, %o1, %o4
a012e798:  b0 06 20 01  inc  %i0
a012e79c:  82 03 40 10  add  %o5, %l0, %g1
a012e7a0:  96 12 c0 08  or  %o3, %o0, %o3
a012e7a4:  94 12 80 0f  or  %o2, %o7, %o2
a012e7a8:  92 0e 20 ff  and  %i0, 0xff, %o1
a012e7ac:  d8 30 7f d0  sth  %o4, [ %g1 + -48 ]
a012e7b0:  d6 30 7f d2  sth  %o3, [ %g1 + -46 ]
a012e7b4:  d4 30 7f d4  sth  %o2, [ %g1 + -44 ]
a012e7b8:  80 a2 60 02  cmp  %o1, 2
a012e7bc:  08 bf ff e8  bleu  0xa012e75c
a012e7c0:  e2 30 7f d6  sth  %l1, [ %g1 + -42 ]
a012e7c4:  10 80 00 13  b  0xa012e810
a012e7c8:  90 10 20 01  mov  1, %o0
a012e7cc:  80 a6 20 01  cmp  %i0, 1
a012e7d0:  02 bf ff c7  be  0xa012e6ec
a012e7d4:  94 10 20 00  clr  %o2
a012e7d8:  96 10 20 00  clr  %o3
a012e7dc:  92 10 20 07  mov  7, %o1
a012e7e0:  83 3a 40 0b  sra  %o1, %o3, %g1
a012e7e4:  94 02 a0 01  inc  %o2
a012e7e8:  96 0a a0 ff  and  %o2, 0xff, %o3
a012e7ec:  80 88 60 01  btst  1, %g1
a012e7f0:  02 80 00 03  be  0xa012e7fc
a012e7f4:  9b 3e 00 0b  sra  %i0, %o3, %o5
a012e7f8:  98 03 20 01  inc  %o4
a012e7fc:  80 a3 60 01  cmp  %o5, 1
a012e800:  12 bf ff f9  bne  0xa012e7e4
a012e804:  83 3a 40 0b  sra  %o1, %o3, %g1
a012e808:  10 bf ff ba  b  0xa012e6f0
a012e80c:  9e 0b 20 ff  and  %o4, 0xff, %o7
a012e810:  92 10 20 01  mov  1, %o1
a012e814:  94 07 bf c8  add  %fp, -56, %o2
a012e818:  7f ff 21 f3  call  0xa00f6fe4
a012e81c:  96 10 20 ff  mov  0xff, %o3
a012e820:  01 00 00 00  nop
a012e824:  81 c7 e0 08  ret
a012e828:  81 e8 00 00  restore
