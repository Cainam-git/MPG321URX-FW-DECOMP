# leon2m FUN_a011579c 0xa011579c-0xa01158b4 (280 bytes)
a011579c:  83 2a 60 10  sll  %o1, 0x10, %g1
a01157a0:  83 30 60 10  srl  %g1, 0x10, %g1
a01157a4:  80 a0 60 01  cmp  %g1, 1
a01157a8:  9a 10 20 00  clr  %o5
a01157ac:  04 80 00 1b  ble  0xa0115818
a01157b0:  98 10 20 00  clr  %o4
a01157b4:  80 a0 60 03  cmp  %g1, 3
a01157b8:  24 80 00 02  ble,a   0xa01157c0
a01157bc:  98 10 20 c9  mov  0xc9, %o4
a01157c0:  90 0a 20 ff  and  %o0, 0xff, %o0
a01157c4:  80 a2 20 01  cmp  %o0, 1
a01157c8:  22 80 00 19  be,a   0xa011582c
a01157cc:  90 0b 20 ff  and  %o4, 0xff, %o0
a01157d0:  80 a2 20 01  cmp  %o0, 1
a01157d4:  04 80 00 2c  ble  0xa0115884
a01157d8:  80 a2 20 02  cmp  %o0, 2
a01157dc:  22 80 00 24  be,a   0xa011586c
a01157e0:  90 0b 20 ff  and  %o4, 0xff, %o0
a01157e4:  83 2a 60 10  sll  %o1, 0x10, %g1
a01157e8:  83 30 60 10  srl  %g1, 0x10, %g1
a01157ec:  80 a0 60 01  cmp  %g1, 1
a01157f0:  22 80 00 08  be,a   0xa0115810
a01157f4:  92 0b 60 ff  and  %o5, 0xff, %o1
a01157f8:  04 80 00 18  ble  0xa0115858
a01157fc:  80 a0 60 02  cmp  %g1, 2
a0115800:  02 80 00 19  be  0xa0115864
a0115804:  80 a0 60 03  cmp  %g1, 3
a0115808:  12 80 00 29  bne  0xa01158ac
a011580c:  92 0b 60 ff  and  %o5, 0xff, %o1
a0115810:  10 80 00 27  b  0xa01158ac
a0115814:  9b 32 60 04  srl  %o1, 4, %o5
a0115818:  90 0a 20 ff  and  %o0, 0xff, %o0
a011581c:  80 a2 20 01  cmp  %o0, 1
a0115820:  12 bf ff ed  bne  0xa01157d4
a0115824:  98 10 20 c8  mov  0xc8, %o4
a0115828:  90 0b 20 ff  and  %o4, 0xff, %o0
a011582c:  19 00 00 23  sethi  %hi(0x8c00), %o4
a0115830:  9a 02 00 0c  add  %o0, %o4, %o5
a0115834:  9b 2b 60 02  sll  %o5, 2, %o5
a0115838:  03 33 c0 8c  sethi  %hi(0xcf023000), %g1
a011583c:  98 10 63 f8  or  %g1, 0x3f8, %o4	! 0xcf0233f8
a0115840:  11 33 c0 00  sethi  %hi(0xcf000000), %o0
a0115844:  9a 13 40 08  or  %o5, %o0, %o5
a0115848:  c0 23 00 00  clr  [ %o4 ]
a011584c:  c2 03 40 00  ld  [ %o5 ], %g1
a0115850:  10 bf ff e5  b  0xa01157e4
a0115854:  9a 10 00 01  mov  %g1, %o5
a0115858:  80 a0 60 00  cmp  %g1, 0
a011585c:  12 80 00 14  bne  0xa01158ac
a0115860:  01 00 00 00  nop
a0115864:  10 80 00 12  b  0xa01158ac
a0115868:  9a 0b 60 0f  and  %o5, 0xf, %o5
a011586c:  03 00 00 22  sethi  %hi(0x8800), %g1
a0115870:  98 10 63 00  or  %g1, 0x300, %o4	! 0x8b00
a0115874:  9a 02 00 0c  add  %o0, %o4, %o5
a0115878:  9b 2b 60 02  sll  %o5, 2, %o5
a011587c:  10 bf ff f0  b  0xa011583c
a0115880:  03 33 c0 8b  sethi  %hi(0xcf022c00), %g1
a0115884:  80 a2 20 00  cmp  %o0, 0
a0115888:  32 bf ff d8  bne,a   0xa01157e8
a011588c:  83 2a 60 10  sll  %o1, 0x10, %g1
a0115890:  90 0b 20 ff  and  %o4, 0xff, %o0
a0115894:  03 00 00 22  sethi  %hi(0x8800), %g1
a0115898:  98 10 62 00  or  %g1, 0x200, %o4	! 0x8a00
a011589c:  9a 02 00 0c  add  %o0, %o4, %o5
a01158a0:  9b 2b 60 02  sll  %o5, 2, %o5
a01158a4:  10 bf ff e6  b  0xa011583c
a01158a8:  03 33 c0 8a  sethi  %hi(0xcf022800), %g1
a01158ac:  81 c3 e0 08  retl
a01158b0:  90 0b 60 ff  and  %o5, 0xff, %o0
