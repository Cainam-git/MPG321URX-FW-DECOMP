# leon2m FUN_a01138fc 0xa01138fc-0xa01139c8 (204 bytes)
a01138fc:  9d e3 bf 98  save  %sp, -104, %sp
a0113900:  b6 10 20 00  clr  %i3
a0113904:  9e 10 00 18  mov  %i0, %o7
a0113908:  80 a6 c0 1a  cmp  %i3, %i2
a011390c:  1a 80 00 2d  bcc  0xa01139c0
a0113910:  9a 10 00 19  mov  %i1, %o5
a0113914:  03 33 c0 47  sethi  %hi(0xcf011c00), %g1
a0113918:  98 10 00 1a  mov  %i2, %o4
a011391c:  a2 10 63 a0  or  %g1, 0x3a0, %l1
a0113920:  a0 10 63 a4  or  %g1, 0x3a4, %l0
a0113924:  90 10 63 a8  or  %g1, 0x3a8, %o0
a0113928:  94 10 63 ac  or  %g1, 0x3ac, %o2
a011392c:  92 10 63 84  or  %g1, 0x384, %o1
a0113930:  a4 10 63 88  or  %g1, 0x388, %l2
a0113934:  96 10 20 80  mov  0x80, %o3
a0113938:  da 24 40 00  st  %o5, [ %l1 ]
a011393c:  b3 33 60 08  srl  %o5, 8, %i1
a0113940:  f2 24 00 00  st  %i1, [ %l0 ]
a0113944:  bb 33 60 10  srl  %o5, 0x10, %i5
a0113948:  fa 22 00 00  st  %i5, [ %o0 ]
a011394c:  b1 33 60 18  srl  %o5, 0x18, %i0
a0113950:  f0 22 80 00  st  %i0, [ %o2 ]
a0113954:  b0 06 e0 08  add  %i3, 8, %i0
a0113958:  b4 10 00 1b  mov  %i3, %i2
a011395c:  d6 22 40 00  st  %o3, [ %o1 ]
a0113960:  80 a6 00 1b  cmp  %i0, %i3
a0113964:  08 80 00 14  bleu  0xa01139b4
a0113968:  b6 10 00 18  mov  %i0, %i3
a011396c:  b2 10 00 12  mov  %l2, %i1
a0113970:  b7 2e a0 02  sll  %i2, 2, %i3
a0113974:  fa 0b c0 1b  ldub  [ %o7 + %i3 ], %i5
a0113978:  fa 26 40 00  st  %i5, [ %i1 ]
a011397c:  c2 13 c0 1b  lduh  [ %o7 + %i3 ], %g1
a0113980:  b8 08 60 ff  and  %g1, 0xff, %i4
a0113984:  f8 26 40 00  st  %i4, [ %i1 ]
a0113988:  ba 03 c0 1b  add  %o7, %i3, %i5
a011398c:  c2 0f 60 02  ldub  [ %i5 + 2 ], %g1
a0113990:  c2 26 40 00  st  %g1, [ %i1 ]
a0113994:  f8 03 c0 1b  ld  [ %o7 + %i3 ], %i4
a0113998:  b6 0f 20 ff  and  %i4, 0xff, %i3
a011399c:  b4 06 a0 01  inc  %i2
a01139a0:  f6 26 40 00  st  %i3, [ %i1 ]
a01139a4:  80 a6 00 1a  cmp  %i0, %i2
a01139a8:  18 bf ff f3  bgu  0xa0113974
a01139ac:  b7 2e a0 02  sll  %i2, 2, %i3
a01139b0:  b6 10 00 18  mov  %i0, %i3
a01139b4:  98 83 3f ff  addcc  %o4, -1, %o4
a01139b8:  12 bf ff e0  bne  0xa0113938
a01139bc:  9a 03 60 01  inc  %o5
a01139c0:  81 c7 e0 08  ret
a01139c4:  81 e8 00 00  restore
