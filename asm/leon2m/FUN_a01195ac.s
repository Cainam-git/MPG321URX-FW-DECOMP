# leon2m FUN_a01195ac 0xa01195ac-0xa0119640 (148 bytes)
a01195ac:  9d e3 bf 98  save  %sp, -104, %sp
a01195b0:  a0 0e 20 ff  and  %i0, 0xff, %l0
a01195b4:  17 2a 00 9e  sethi  %hi(0xa8027800), %o3
a01195b8:  a4 12 e2 a8  or  %o3, 0x2a8, %l2	! 0xa8027aa8
a01195bc:  a8 04 00 10  add  %l0, %l0, %l4
a01195c0:  d4 14 80 14  lduh  [ %l2 + %l4 ], %o2
a01195c4:  93 2a a0 02  sll  %o2, 2, %o1
a01195c8:  27 33 c0 00  sethi  %hi(0xcf000000), %l3
a01195cc:  9a 12 40 13  or  %o1, %l3, %o5
a01195d0:  d0 03 40 00  ld  [ %o5 ], %o0
a01195d4:  82 0a 20 7f  and  %o0, 0x7f, %g1
a01195d8:  c2 23 40 00  st  %g1, [ %o5 ]
a01195dc:  67 fd d3 32  call  0x4008e2a4
a01195e0:  a2 10 00 18  mov  %i0, %l1
a01195e4:  b0 10 20 28  mov  0x28, %i0
a01195e8:  80 a4 20 01  cmp  %l0, 1
a01195ec:  08 80 00 03  bleu  0xa01195f8
a01195f0:  82 10 00 11  mov  %l1, %g1
a01195f4:  82 10 20 00  clr  %g1
a01195f8:  96 08 60 ff  and  %g1, 0xff, %o3
a01195fc:  94 02 c0 0b  add  %o3, %o3, %o2
a0119600:  d2 14 80 0a  lduh  [ %l2 + %o2 ], %o1
a0119604:  c2 14 80 14  lduh  [ %l2 + %l4 ], %g1
a0119608:  90 02 60 ce  add  %o1, 0xce, %o0
a011960c:  9b 2a 20 02  sll  %o0, 2, %o5
a0119610:  a0 00 60 cf  add  %g1, 0xcf, %l0
a0119614:  a2 13 40 13  or  %o5, %l3, %l1
a0119618:  a9 2c 20 02  sll  %l0, 2, %l4
a011961c:  c0 24 40 00  clr  [ %l1 ]
a0119620:  98 15 00 13  or  %l4, %l3, %o4
a0119624:  e6 03 00 00  ld  [ %o4 ], %l3
a0119628:  a4 14 e0 01  or  %l3, 1, %l2
a011962c:  9e 0c a0 ff  and  %l2, 0xff, %o7
a0119630:  de 23 00 00  st  %o7, [ %o4 ]
a0119634:  67 fd ce db  call  0x4008d1a0
a0119638:  81 e8 00 00  restore
a011963c:  01 00 00 00  nop
