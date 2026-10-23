# leon2m FUN_a01158b4 0xa01158b4-0xa0115a44 (400 bytes)
a01158b4:  83 2a 60 10  sll  %o1, 0x10, %g1
a01158b8:  83 30 60 10  srl  %g1, 0x10, %g1
a01158bc:  80 a0 60 01  cmp  %g1, 1
a01158c0:  04 80 00 10  ble  0xa0115900
a01158c4:  96 10 20 00  clr  %o3
a01158c8:  80 a0 60 03  cmp  %g1, 3
a01158cc:  24 80 00 02  ble,a   0xa01158d4
a01158d0:  96 10 20 c7  mov  0xc7, %o3
a01158d4:  90 0a 20 ff  and  %o0, 0xff, %o0
a01158d8:  80 a2 20 01  cmp  %o0, 1
a01158dc:  22 80 00 0e  be,a   0xa0115914
a01158e0:  91 2a 60 10  sll  %o1, 0x10, %o0
a01158e4:  80 a2 20 01  cmp  %o0, 1
a01158e8:  04 80 00 3c  ble  0xa01159d8
a01158ec:  80 a2 20 02  cmp  %o0, 2
a01158f0:  12 80 00 53  bne  0xa0115a3c
a01158f4:  9b 2a 60 10  sll  %o1, 0x10, %o5
a01158f8:  10 80 00 2a  b  0xa01159a0
a01158fc:  93 33 60 10  srl  %o5, 0x10, %o1
a0115900:  90 0a 20 ff  and  %o0, 0xff, %o0
a0115904:  80 a2 20 01  cmp  %o0, 1
a0115908:  12 bf ff f8  bne  0xa01158e8
a011590c:  96 10 20 c6  mov  0xc6, %o3
a0115910:  91 2a 60 10  sll  %o1, 0x10, %o0
a0115914:  9b 32 20 10  srl  %o0, 0x10, %o5
a0115918:  80 a0 00 0d  cmp  %g0, %o5
a011591c:  90 60 3f ff  subx  %g0, -1, %o0
a0115920:  92 1b 60 02  xor  %o5, 2, %o1
a0115924:  80 a0 00 09  cmp  %g0, %o1
a0115928:  19 33 c0 8c  sethi  %hi(0xcf023000), %o4
a011592c:  9a 60 3f ff  subx  %g0, -1, %o5
a0115930:  82 13 23 f8  or  %o4, 0x3f8, %g1
a0115934:  c0 20 40 00  clr  [ %g1 ]
a0115938:  80 92 00 0d  orcc  %o0, %o5, %g0
a011593c:  02 80 00 0d  be  0xa0115970
a0115940:  9a 0a e0 ff  and  %o3, 0xff, %o5
a0115944:  03 00 00 23  sethi  %hi(0x8c00), %g1
a0115948:  92 03 40 01  add  %o5, %g1, %o1
a011594c:  91 2a 60 02  sll  %o1, 2, %o0
a0115950:  19 33 c0 00  sethi  %hi(0xcf000000), %o4
a0115954:  9a 12 00 0c  or  %o0, %o4, %o5
a0115958:  c2 03 40 00  ld  [ %o5 ], %g1
a011595c:  82 08 60 f0  and  %g1, 0xf0, %g1
a0115960:  98 0a a0 0f  and  %o2, 0xf, %o4
a0115964:  90 10 40 0c  or  %g1, %o4, %o0
a0115968:  d0 23 40 00  st  %o0, [ %o5 ]
a011596c:  30 80 00 34  b,a   0xa0115a3c
a0115970:  03 00 00 23  sethi  %hi(0x8c00), %g1
a0115974:  92 03 40 01  add  %o5, %g1, %o1
a0115978:  99 2a 60 02  sll  %o1, 2, %o4
a011597c:  03 33 c0 00  sethi  %hi(0xcf000000), %g1
a0115980:  9a 13 00 01  or  %o4, %g1, %o5
a0115984:  96 0a a0 ff  and  %o2, 0xff, %o3
a0115988:  d4 03 40 00  ld  [ %o5 ], %o2
a011598c:  82 0a a0 0f  and  %o2, 0xf, %g1
a0115990:  99 2a e0 04  sll  %o3, 4, %o4
a0115994:  90 10 40 0c  or  %g1, %o4, %o0
a0115998:  d0 23 40 00  st  %o0, [ %o5 ]
a011599c:  30 80 00 28  b,a   0xa0115a3c
a01159a0:  80 a0 00 09  cmp  %g0, %o1
a01159a4:  9a 60 3f ff  subx  %g0, -1, %o5
a01159a8:  90 1a 60 02  xor  %o1, 2, %o0
a01159ac:  80 a0 00 08  cmp  %g0, %o0
a01159b0:  19 33 c0 8b  sethi  %hi(0xcf022c00), %o4
a01159b4:  92 60 3f ff  subx  %g0, -1, %o1
a01159b8:  82 13 23 f8  or  %o4, 0x3f8, %g1
a01159bc:  c0 20 40 00  clr  [ %g1 ]
a01159c0:  80 93 40 09  orcc  %o5, %o1, %g0
a01159c4:  02 80 00 18  be  0xa0115a24
a01159c8:  9a 0a e0 ff  and  %o3, 0xff, %o5
a01159cc:  17 00 00 22  sethi  %hi(0x8800), %o3
a01159d0:  10 bf ff de  b  0xa0115948
a01159d4:  82 12 e3 00  or  %o3, 0x300, %g1	! 0x8b00
a01159d8:  80 a2 20 00  cmp  %o0, 0
a01159dc:  12 80 00 18  bne  0xa0115a3c
a01159e0:  99 2a 60 10  sll  %o1, 0x10, %o4
a01159e4:  9b 33 20 10  srl  %o4, 0x10, %o5
a01159e8:  80 a0 00 0d  cmp  %g0, %o5
a01159ec:  98 60 3f ff  subx  %g0, -1, %o4
a01159f0:  82 1b 60 02  xor  %o5, 2, %g1
a01159f4:  80 a0 00 01  cmp  %g0, %g1
a01159f8:  13 33 c0 8a  sethi  %hi(0xcf022800), %o1
a01159fc:  9a 60 3f ff  subx  %g0, -1, %o5
a0115a00:  90 12 63 f8  or  %o1, 0x3f8, %o0
a0115a04:  c0 22 00 00  clr  [ %o0 ]
a0115a08:  80 93 00 0d  orcc  %o4, %o5, %g0
a0115a0c:  02 80 00 09  be  0xa0115a30
a0115a10:  11 00 00 22  sethi  %hi(0x8800), %o0
a0115a14:  9a 0a e0 ff  and  %o3, 0xff, %o5
a0115a18:  17 00 00 22  sethi  %hi(0x8800), %o3
a0115a1c:  10 bf ff cb  b  0xa0115948
a0115a20:  82 12 e2 00  or  %o3, 0x200, %g1	! 0x8a00
a0115a24:  17 00 00 22  sethi  %hi(0x8800), %o3
a0115a28:  10 bf ff d3  b  0xa0115974
a0115a2c:  82 12 e3 00  or  %o3, 0x300, %g1	! 0x8b00
a0115a30:  9a 0a e0 ff  and  %o3, 0xff, %o5
a0115a34:  10 bf ff d0  b  0xa0115974
a0115a38:  82 12 22 00  or  %o0, 0x200, %g1
a0115a3c:  81 c3 e0 08  retl
a0115a40:  01 00 00 00  nop
