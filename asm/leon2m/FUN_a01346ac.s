# leon2m FUN_a01346ac 0xa01346ac-0xa013480c (352 bytes)
a01346ac:  9d e3 bf 90  save  %sp, -112, %sp
a01346b0:  21 2a 00 b2  sethi  %hi(0xa802c800), %l0
a01346b4:  c0 27 bf f4  clr  [ %fp + -12 ]
a01346b8:  e2 0c 23 8c  ldub  [ %l0 + 0x38c ], %l1
a01346bc:  10 80 00 06  b  0xa01346d4
a01346c0:  b0 10 20 00  clr  %i0
a01346c4:  96 0e 20 ff  and  %i0, 0xff, %o3
a01346c8:  80 a2 e0 03  cmp  %o3, 3
a01346cc:  18 80 00 19  bgu  0xa0134730
a01346d0:  c0 2c 23 8c  clrb  [ %l0 + 0x38c ]
a01346d4:  d8 0c 23 8c  ldub  [ %l0 + 0x38c ], %o4
a01346d8:  97 2b 20 02  sll  %o4, 2, %o3
a01346dc:  94 02 c0 0c  add  %o3, %o4, %o2
a01346e0:  91 2a a0 02  sll  %o2, 2, %o0
a01346e4:  92 02 20 60  add  %o0, 0x60, %o1
a01346e8:  92 0a 60 fc  and  %o1, 0xfc, %o1
a01346ec:  90 10 20 00  clr  %o0
a01346f0:  94 07 bf f4  add  %fp, -12, %o2
a01346f4:  67 fd 5f 77  call  0x4008c4d0
a01346f8:  96 10 20 01  mov  1, %o3
a01346fc:  c2 07 bf f4  ld  [ %fp + -12 ], %g1
a0134700:  80 88 60 0f  btst  0xf, %g1
a0134704:  12 80 00 3d  bne  0xa01347f8
a0134708:  de 0c 23 8c  ldub  [ %l0 + 0x38c ], %o7
a013470c:  82 03 e0 01  add  %o7, 1, %g1
a0134710:  9a 08 60 ff  and  %g1, 0xff, %o5
a0134714:  80 a3 60 03  cmp  %o5, 3
a0134718:  18 bf ff eb  bgu  0xa01346c4
a013471c:  b0 06 20 01  inc  %i0
a0134720:  96 0e 20 ff  and  %i0, 0xff, %o3
a0134724:  80 a2 e0 03  cmp  %o3, 3
a0134728:  08 bf ff eb  bleu  0xa01346d4
a013472c:  c2 2c 23 8c  stb  %g1, [ %l0 + 0x38c ]
a0134730:  80 a0 00 0b  cmp  %g0, %o3
a0134734:  82 40 20 00  addx  %g0, 0, %g1
a0134738:  92 1a e0 04  xor  %o3, 4, %o1
a013473c:  80 a0 00 09  cmp  %g0, %o1
a0134740:  b0 40 20 00  addx  %g0, 0, %i0
a0134744:  80 88 40 18  btst  %g1, %i0
a0134748:  02 80 00 22  be  0xa01347d0
a013474c:  80 a2 e0 04  cmp  %o3, 4
a0134750:  e2 2c 23 8c  stb  %l1, [ %l0 + 0x38c ]
a0134754:  10 80 00 06  b  0xa013476c
a0134758:  b0 10 20 00  clr  %i0
a013475c:  96 0e 20 ff  and  %i0, 0xff, %o3
a0134760:  80 a2 e0 03  cmp  %o3, 3
a0134764:  18 80 00 1a  bgu  0xa01347cc
a0134768:  c0 2c 23 8c  clrb  [ %l0 + 0x38c ]
a013476c:  da 0c 23 8c  ldub  [ %l0 + 0x38c ], %o5
a0134770:  99 2b 60 02  sll  %o5, 2, %o4
a0134774:  96 03 00 0d  add  %o4, %o5, %o3
a0134778:  95 2a e0 02  sll  %o3, 2, %o2
a013477c:  90 02 a0 60  add  %o2, 0x60, %o0
a0134780:  92 0a 20 fc  and  %o0, 0xfc, %o1
a0134784:  90 10 20 00  clr  %o0
a0134788:  94 07 bf f4  add  %fp, -12, %o2
a013478c:  67 fd 5f 51  call  0x4008c4d0
a0134790:  96 10 20 01  mov  1, %o3
a0134794:  e2 07 bf f4  ld  [ %fp + -12 ], %l1
a0134798:  80 8c 60 0f  btst  0xf, %l1
a013479c:  12 80 00 0c  bne  0xa01347cc
a01347a0:  96 0e 20 ff  and  %i0, 0xff, %o3
a01347a4:  c2 0c 23 8c  ldub  [ %l0 + 0x38c ], %g1
a01347a8:  82 00 60 01  inc  %g1
a01347ac:  9e 08 60 ff  and  %g1, 0xff, %o7
a01347b0:  80 a3 e0 03  cmp  %o7, 3
a01347b4:  18 bf ff ea  bgu  0xa013475c
a01347b8:  b0 06 20 01  inc  %i0
a01347bc:  96 0e 20 ff  and  %i0, 0xff, %o3
a01347c0:  80 a2 e0 03  cmp  %o3, 3
a01347c4:  08 bf ff ea  bleu  0xa013476c
a01347c8:  c2 2c 23 8c  stb  %g1, [ %l0 + 0x38c ]
a01347cc:  80 a2 e0 04  cmp  %o3, 4
a01347d0:  02 80 00 0c  be  0xa0134800
a01347d4:  b0 10 3f fe  mov  -2, %i0
a01347d8:  f0 0c 23 8c  ldub  [ %l0 + 0x38c ], %i0
a01347dc:  9a 06 20 01  add  %i0, 1, %o5
a01347e0:  92 0b 60 ff  and  %o5, 0xff, %o1
a01347e4:  80 a2 60 03  cmp  %o1, 3
a01347e8:  28 80 00 06  bleu,a   0xa0134800
a01347ec:  da 2c 23 8c  stb  %o5, [ %l0 + 0x38c ]
a01347f0:  10 80 00 04  b  0xa0134800
a01347f4:  c0 2c 23 8c  clrb  [ %l0 + 0x38c ]
a01347f8:  10 bf ff ce  b  0xa0134730
a01347fc:  96 0e 20 ff  and  %i0, 0xff, %o3
a0134800:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0134804:  81 c7 e0 08  ret
a0134808:  81 e8 00 00  restore
