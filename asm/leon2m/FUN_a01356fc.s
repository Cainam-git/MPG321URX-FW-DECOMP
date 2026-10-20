# leon2m FUN_a01356fc 0xa01356fc-0xa013588c (400 bytes)
a01356fc:  9d e3 bf 90  save  %sp, -112, %sp
a0135700:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0135704:  80 a6 20 02  cmp  %i0, 2
a0135708:  02 80 00 29  be  0xa01357ac
a013570c:  c0 27 bf f4  clr  [ %fp + -12 ]
a0135710:  80 a6 20 02  cmp  %i0, 2
a0135714:  04 80 00 07  ble  0xa0135730
a0135718:  80 a6 20 01  cmp  %i0, 1
a013571c:  80 a6 20 03  cmp  %i0, 3
a0135720:  12 80 00 59  bne  0xa0135884
a0135724:  31 2a 00 b2  sethi  %hi(0xa802c800), %i0
a0135728:  10 80 00 39  b  0xa013580c
a013572c:  33 2a 00 b2  sethi  %hi(0xa802c800), %i1
a0135730:  12 80 00 55  bne  0xa0135884
a0135734:  83 2e 60 10  sll  %i1, 0x10, %g1
a0135738:  b3 30 60 10  srl  %g1, 0x10, %i1
a013573c:  21 2a 00 b2  sethi  %hi(0xa802c800), %l0
a0135740:  10 80 00 04  b  0xa0135750
a0135744:  31 2a 00 b2  sethi  %hi(0xa802c800), %i0
a0135748:  7f ff fe 65  call  0xa01350dc
a013574c:  01 00 00 00  nop
a0135750:  d6 0c 23 97  ldub  [ %l0 + 0x397 ], %o3
a0135754:  d8 0e 23 96  ldub  [ %i0 + 0x396 ], %o4
a0135758:  92 0b 20 ff  and  %o4, 0xff, %o1
a013575c:  9a 0a e0 ff  and  %o3, 0xff, %o5
a0135760:  90 22 40 0d  sub  %o1, %o5, %o0
a0135764:  92 0a e0 ff  and  %o3, 0xff, %o1
a0135768:  94 0b 20 ff  and  %o4, 0xff, %o2
a013576c:  80 a2 40 0a  cmp  %o1, %o2
a0135770:  18 80 00 09  bgu  0xa0135794
a0135774:  82 02 20 24  add  %o0, 0x24, %g1
a0135778:  9e 0b 20 ff  and  %o4, 0xff, %o7
a013577c:  98 0a e0 ff  and  %o3, 0xff, %o4
a0135780:  80 a2 40 0a  cmp  %o1, %o2
a0135784:  9a 23 c0 0c  sub  %o7, %o4, %o5
a0135788:  1a 80 00 03  bcc  0xa0135794
a013578c:  82 10 20 24  mov  0x24, %g1
a0135790:  82 03 7f ff  add  %o5, -1, %g1
a0135794:  97 28 60 14  sll  %g1, 0x14, %o3
a0135798:  95 32 e0 10  srl  %o3, 0x10, %o2
a013579c:  80 a6 40 0a  cmp  %i1, %o2
a01357a0:  18 bf ff ea  bgu  0xa0135748
a01357a4:  01 00 00 00  nop
a01357a8:  30 80 00 37  b,a   0xa0135884
a01357ac:  31 2a 00 b2  sethi  %hi(0xa802c800), %i0
a01357b0:  33 2a 00 b2  sethi  %hi(0xa802c800), %i1
a01357b4:  c2 0e 23 97  ldub  [ %i0 + 0x397 ], %g1
a01357b8:  e0 0e 63 96  ldub  [ %i1 + 0x396 ], %l0
a01357bc:  80 a0 40 10  cmp  %g1, %l0
a01357c0:  02 80 00 31  be  0xa0135884
a01357c4:  01 00 00 00  nop
a01357c8:  7f ff fe 45  call  0xa01350dc
a01357cc:  01 00 00 00  nop
a01357d0:  d2 0e 23 97  ldub  [ %i0 + 0x397 ], %o1
a01357d4:  d0 0e 63 96  ldub  [ %i1 + 0x396 ], %o0
a01357d8:  80 a2 40 08  cmp  %o1, %o0
a01357dc:  02 80 00 2a  be  0xa0135884
a01357e0:  01 00 00 00  nop
a01357e4:  7f ff fe 3e  call  0xa01350dc
a01357e8:  01 00 00 00  nop
a01357ec:  d2 0e 23 97  ldub  [ %i0 + 0x397 ], %o1
a01357f0:  d0 0e 63 96  ldub  [ %i1 + 0x396 ], %o0
a01357f4:  80 a2 40 08  cmp  %o1, %o0
a01357f8:  12 bf ff f4  bne  0xa01357c8
a01357fc:  01 00 00 00  nop
a0135800:  30 80 00 21  b,a   0xa0135884
a0135804:  7f ff fe 36  call  0xa01350dc
a0135808:  01 00 00 00  nop
a013580c:  da 0e 23 97  ldub  [ %i0 + 0x397 ], %o5
a0135810:  de 0e 63 96  ldub  [ %i1 + 0x396 ], %o7
a0135814:  80 a3 40 0f  cmp  %o5, %o7
a0135818:  12 bf ff fb  bne  0xa0135804
a013581c:  01 00 00 00  nop
a0135820:  b0 10 20 00  clr  %i0	! 0x0
a0135824:  b2 10 20 00  clr  %i1
a0135828:  98 10 20 00  clr  %o4
a013582c:  9b 2b 20 02  sll  %o4, 2, %o5
a0135830:  9e 03 40 0c  add  %o5, %o4, %o7
a0135834:  93 2b e0 02  sll  %o7, 2, %o1
a0135838:  98 02 60 10  add  %o1, 0x10, %o4
a013583c:  92 0b 20 fc  and  %o4, 0xfc, %o1
a0135840:  90 10 20 00  clr  %o0
a0135844:  94 07 bf f4  add  %fp, -12, %o2
a0135848:  67 fd 5b 22  call  0x4008c4d0
a013584c:  96 10 20 01  mov  1, %o3
a0135850:  b2 06 60 01  inc  %i1
a0135854:  98 0e 60 ff  and  %i1, 0xff, %o4
a0135858:  91 2b 20 02  sll  %o4, 2, %o0
a013585c:  82 02 00 0c  add  %o0, %o4, %g1
a0135860:  a1 28 60 02  sll  %g1, 2, %l0
a0135864:  94 04 20 10  add  %l0, 0x10, %o2
a0135868:  d6 07 bf f4  ld  [ %fp + -12 ], %o3
a013586c:  80 a2 a0 50  cmp  %o2, 0x50
a0135870:  04 bf ff ef  ble  0xa013582c
a0135874:  b0 16 00 0b  or  %i0, %o3, %i0
a0135878:  80 a6 20 00  cmp  %i0, 0
a013587c:  12 bf ff ea  bne  0xa0135824
a0135880:  b0 10 20 00  clr  %i0
a0135884:  81 c7 e0 08  ret
a0135888:  81 e8 00 00  restore
