# leon2s DRV_HDMI21_Print_SCDC_Error 0xa00795a0-0xa0079778 (472 bytes)
a00795a0:  9d e3 bf 88  save  %sp, -120, %sp
a00795a4:  98 10 20 00  clr  %o4
a00795a8:  9a 10 20 00  clr  %o5
a00795ac:  a2 0e 20 ff  and  %i0, 0xff, %l1
a00795b0:  d8 3f bf f0  std  %o4, [ %fp + -16 ]
a00795b4:  d8 3f bf e8  std  %o4, [ %fp + -24 ]
a00795b8:  80 a4 60 02  cmp  %l1, 2
a00795bc:  02 80 00 05  be  0xa00795d0
a00795c0:  a4 10 20 00  clr  %l2
a00795c4:  80 a4 60 03  cmp  %l1, 3
a00795c8:  12 80 00 6a  bne  0xa0079770
a00795cc:  a4 10 20 01  mov  1, %l2
a00795d0:  2b 2a 01 e1  sethi  %hi(0xa8078400), %l5
a00795d4:  c2 05 62 34  ld  [ %l5 + 0x234 ], %g1	! 0xa8078634
a00795d8:  80 88 68 00  btst  0x800, %g1
a00795dc:  02 80 00 08  be  0xa00795fc
a00795e0:  21 00 00 0b  sethi  %hi(0x2c00), %l0
a00795e4:  11 28 01 9e  sethi  %hi(0xa0067800), %o0
a00795e8:  13 28 02 cf  sethi  %hi(0xa00b3c00), %o1
a00795ec:  90 12 20 68  or  %o0, 0x68, %o0
a00795f0:  7f ff e6 95  call  0xa0073044
a00795f4:  92 12 61 e0  or  %o1, 0x1e0, %o1
a00795f8:  21 00 00 0b  sethi  %hi(0x2c00), %l0
a00795fc:  90 10 20 01  mov  1, %o0
a0079600:  92 10 20 14  mov  0x14, %o1
a0079604:  94 10 00 11  mov  %l1, %o2
a0079608:  40 00 b7 87  call  0xa00a7424
a007960c:  96 14 22 60  or  %l0, 0x260, %o3
a0079610:  92 10 20 10  mov  0x10, %o1
a0079614:  94 10 00 11  mov  %l1, %o2
a0079618:  96 14 22 60  or  %l0, 0x260, %o3
a007961c:  40 00 b7 82  call  0xa00a7424
a0079620:  90 10 20 01  mov  1, %o0
a0079624:  40 00 df fa  call  0xa00b160c
a0079628:  90 10 20 01  mov  1, %o0
a007962c:  94 10 00 11  mov  %l1, %o2
a0079630:  96 14 22 60  or  %l0, 0x260, %o3
a0079634:  90 10 20 00  clr  %o0
a0079638:  40 00 b7 7b  call  0xa00a7424
a007963c:  92 10 20 10  mov  0x10, %o1
a0079640:  40 00 e0 55  call  0xa00b1794
a0079644:  90 10 20 01  mov  1, %o0
a0079648:  a6 0c a0 ff  and  %l2, 0xff, %l3
a007964c:  29 2a 01 f5  sethi  %hi(0xa807d400), %l4
a0079650:  9a 15 22 80  or  %l4, 0x280, %o5	! 0xa807d680
a0079654:  82 5c e0 b0  smul  %l3, 0xb0, %g1
a0079658:  c2 0b 40 01  ldub  [ %o5 + %g1 ], %g1
a007965c:  80 a0 60 00  cmp  %g1, 0
a0079660:  02 80 00 44  be  0xa0079770
a0079664:  a4 10 20 00  clr  %l2
a0079668:  13 00 00 0b  sethi  %hi(0x2c00), %o1
a007966c:  a0 0c a0 ff  and  %l2, 0xff, %l0
a0079670:  92 12 62 64  or  %o1, 0x264, %o1
a0079674:  80 a4 20 00  cmp  %l0, 0
a0079678:  12 80 00 09  bne  0xa007969c
a007967c:  90 0e 20 ff  and  %i0, 0xff, %o0
a0079680:  40 00 b7 25  call  0xa00a7314
a0079684:  01 00 00 00  nop
a0079688:  03 00 00 3f  sethi  %hi(0xfc00), %g1
a007968c:  82 10 63 ff  or  %g1, 0x3ff, %g1	! 0xffff
a0079690:  90 0a 00 01  and  %o0, %g1, %o0
a0079694:  10 80 00 20  b  0xa0079714
a0079698:  d0 27 bf e8  st  %o0, [ %fp + -24 ]
a007969c:  13 00 00 0b  sethi  %hi(0x2c00), %o1
a00796a0:  92 12 62 64  or  %o1, 0x264, %o1	! 0x2e64
a00796a4:  80 a4 20 01  cmp  %l0, 1
a00796a8:  12 80 00 07  bne  0xa00796c4
a00796ac:  98 10 00 08  mov  %o0, %o4
a00796b0:  40 00 b7 19  call  0xa00a7314
a00796b4:  01 00 00 00  nop
a00796b8:  91 32 20 10  srl  %o0, 0x10, %o0
a00796bc:  10 80 00 16  b  0xa0079714
a00796c0:  d0 27 bf ec  st  %o0, [ %fp + -20 ]
a00796c4:  13 00 00 0b  sethi  %hi(0x2c00), %o1
a00796c8:  9b 2c 20 02  sll  %l0, 2, %o5
a00796cc:  82 07 bf f8  add  %fp, -8, %g1
a00796d0:  92 12 62 68  or  %o1, 0x268, %o1
a00796d4:  80 a4 20 02  cmp  %l0, 2
a00796d8:  12 80 00 09  bne  0xa00796fc
a00796dc:  a2 03 40 01  add  %o5, %g1, %l1
a00796e0:  40 00 b7 0d  call  0xa00a7314
a00796e4:  01 00 00 00  nop
a00796e8:  03 00 00 3f  sethi  %hi(0xfc00), %g1
a00796ec:  82 10 63 ff  or  %g1, 0x3ff, %g1	! 0xffff
a00796f0:  90 0a 00 01  and  %o0, %g1, %o0
a00796f4:  10 80 00 08  b  0xa0079714
a00796f8:  d0 27 bf f0  st  %o0, [ %fp + -16 ]
a00796fc:  13 00 00 0b  sethi  %hi(0x2c00), %o1
a0079700:  92 12 62 68  or  %o1, 0x268, %o1	! 0x2e68
a0079704:  40 00 b7 04  call  0xa00a7314
a0079708:  90 10 00 0c  mov  %o4, %o0
a007970c:  91 32 20 10  srl  %o0, 0x10, %o0
a0079710:  d0 24 7f f0  st  %o0, [ %l1 + -16 ]
a0079714:  83 2c 20 02  sll  %l0, 2, %g1
a0079718:  9a 07 80 01  add  %fp, %g1, %o5
a007971c:  92 06 20 41  add  %i0, 0x41, %o1
a0079720:  93 2a 60 18  sll  %o1, 0x18, %o1
a0079724:  c2 05 62 34  ld  [ %l5 + 0x234 ], %g1
a0079728:  11 28 01 9e  sethi  %hi(0xa0067800), %o0
a007972c:  a4 04 a0 01  inc  %l2
a0079730:  80 88 68 00  btst  0x800, %g1
a0079734:  90 12 20 80  or  %o0, 0x80, %o0
a0079738:  93 3a 60 18  sra  %o1, 0x18, %o1
a007973c:  02 80 00 06  be  0xa0079754
a0079740:  94 10 00 10  mov  %l0, %o2
a0079744:  c2 03 7f e8  ld  [ %o5 + -24 ], %g1
a0079748:  17 3f ff e0  sethi  %hi(0xffff8000), %o3
a007974c:  7f ff e6 3e  call  0xa0073044
a0079750:  96 28 40 0b  andn  %g1, %o3, %o3
a0079754:  82 5c e0 b0  smul  %l3, 0xb0, %g1
a0079758:  9a 15 22 80  or  %l4, 0x280, %o5
a007975c:  da 0b 40 01  ldub  [ %o5 + %g1 ], %o5
a0079760:  82 0c a0 ff  and  %l2, 0xff, %g1
a0079764:  80 a0 40 0d  cmp  %g1, %o5
a0079768:  0a bf ff c1  bcs  0xa007966c
a007976c:  13 00 00 0b  sethi  %hi(0x2c00), %o1
a0079770:  81 c7 e0 08  ret
a0079774:  91 e8 20 00  restore  %g0, 0, %o0
