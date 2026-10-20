# leon2m FUN_a01166d8 0xa01166d8-0xa01167ec (276 bytes)
a01166d8:  93 2a 60 10  sll  %o1, 0x10, %o1
a01166dc:  93 32 60 10  srl  %o1, 0x10, %o1
a01166e0:  80 a2 60 01  cmp  %o1, 1
a01166e4:  82 10 20 00  clr  %g1
a01166e8:  02 80 00 14  be  0xa0116738
a01166ec:  96 10 20 00  clr  %o3
a01166f0:  80 a2 60 01  cmp  %o1, 1
a01166f4:  04 80 00 37  ble  0xa01167d0
a01166f8:  80 a2 60 02  cmp  %o1, 2
a01166fc:  02 80 00 20  be  0xa011677c
a0116700:  80 a2 60 03  cmp  %o1, 3
a0116704:  22 80 00 02  be,a   0xa011670c
a0116708:  96 10 21 64  mov  0x164, %o3
a011670c:  90 0a 20 ff  and  %o0, 0xff, %o0
a0116710:  80 a2 20 01  cmp  %o0, 1
a0116714:  02 80 00 0e  be  0xa011674c
a0116718:  9a 0a e0 ff  and  %o3, 0xff, %o5
a011671c:  80 a2 20 01  cmp  %o0, 1
a0116720:  04 80 00 21  ble  0xa01167a4
a0116724:  80 a2 20 02  cmp  %o0, 2
a0116728:  12 80 00 2f  bne  0xa01167e4
a011672c:  01 00 00 00  nop
a0116730:  10 80 00 15  b  0xa0116784
a0116734:  03 00 00 22  sethi  %hi(0x8800), %g1
a0116738:  90 0a 20 ff  and  %o0, 0xff, %o0
a011673c:  80 a2 20 01  cmp  %o0, 1
a0116740:  12 bf ff f8  bne  0xa0116720
a0116744:  96 10 21 62  mov  0x162, %o3
a0116748:  9a 0a e0 ff  and  %o3, 0xff, %o5
a011674c:  11 00 00 23  sethi  %hi(0x8c00), %o0
a0116750:  98 03 40 08  add  %o5, %o0, %o4
a0116754:  93 2a e0 10  sll  %o3, 0x10, %o1
a0116758:  97 32 60 18  srl  %o1, 0x18, %o3
a011675c:  9b 2b 20 02  sll  %o4, 2, %o5
a0116760:  03 33 c0 8c  sethi  %hi(0xcf023000), %g1
a0116764:  98 10 63 f8  or  %g1, 0x3f8, %o4	! 0xcf0233f8
a0116768:  d6 23 00 00  st  %o3, [ %o4 ]
a011676c:  03 33 c0 00  sethi  %hi(0xcf000000), %g1
a0116770:  96 13 40 01  or  %o5, %g1, %o3
a0116774:  c2 02 c0 00  ld  [ %o3 ], %g1
a0116778:  30 80 00 1b  b,a   0xa01167e4
a011677c:  10 bf ff e4  b  0xa011670c
a0116780:  96 10 21 63  mov  0x163, %o3
a0116784:  9a 0a e0 ff  and  %o3, 0xff, %o5
a0116788:  90 10 63 00  or  %g1, 0x300, %o0
a011678c:  92 03 40 08  add  %o5, %o0, %o1
a0116790:  97 2a e0 10  sll  %o3, 0x10, %o3
a0116794:  97 32 e0 18  srl  %o3, 0x18, %o3
a0116798:  9b 2a 60 02  sll  %o1, 2, %o5
a011679c:  10 bf ff f2  b  0xa0116764
a01167a0:  03 33 c0 8b  sethi  %hi(0xcf022c00), %g1
a01167a4:  80 a2 20 00  cmp  %o0, 0
a01167a8:  12 80 00 0f  bne  0xa01167e4
a01167ac:  19 00 00 22  sethi  %hi(0x8800), %o4
a01167b0:  90 0a e0 ff  and  %o3, 0xff, %o0
a01167b4:  82 13 22 00  or  %o4, 0x200, %g1
a01167b8:  9a 02 00 01  add  %o0, %g1, %o5
a01167bc:  97 2a e0 10  sll  %o3, 0x10, %o3
a01167c0:  97 32 e0 18  srl  %o3, 0x18, %o3
a01167c4:  9b 2b 60 02  sll  %o5, 2, %o5
a01167c8:  10 bf ff e7  b  0xa0116764
a01167cc:  03 33 c0 8a  sethi  %hi(0xcf022800), %g1
a01167d0:  80 a2 60 00  cmp  %o1, 0
a01167d4:  22 bf ff ce  be,a   0xa011670c
a01167d8:  96 10 21 61  mov  0x161, %o3
a01167dc:  10 bf ff cd  b  0xa0116710
a01167e0:  90 0a 20 ff  and  %o0, 0xff, %o0
a01167e4:  81 c3 e0 08  retl
a01167e8:  90 08 60 ff  and  %g1, 0xff, %o0
