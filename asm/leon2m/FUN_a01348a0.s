# leon2m FUN_a01348a0 0xa01348a0-0xa013497c (220 bytes)
a01348a0:  9d e3 bf 98  save  %sp, -104, %sp
a01348a4:  03 2a 00 b2  sethi  %hi(0xa802c800), %g1
a01348a8:  d8 10 63 94  lduh  [ %g1 + 0x394 ], %o4	! 0xa802cb94
a01348ac:  83 2e 60 10  sll  %i1, 0x10, %g1
a01348b0:  9b 2b 20 10  sll  %o4, 0x10, %o5
a01348b4:  80 a3 40 01  cmp  %o5, %g1
a01348b8:  08 80 00 05  bleu  0xa01348cc
a01348bc:  b5 33 60 10  srl  %o5, 0x10, %i2
a01348c0:  98 10 00 19  mov  %i1, %o4
a01348c4:  9a 10 00 01  mov  %g1, %o5
a01348c8:  b5 33 60 10  srl  %o5, 0x10, %i2
a01348cc:  80 a6 a0 00  cmp  %i2, 0
a01348d0:  02 80 00 0e  be  0xa0134908
a01348d4:  ba 10 20 00  clr  %i5
a01348d8:  37 2a 00 b7  sethi  %hi(0xa802dc00), %i3
a01348dc:  b2 16 e1 50  or  %i3, 0x150, %i1	! 0xa802dd50
a01348e0:  b6 07 60 01  add  %i5, 1, %i3
a01348e4:  83 2f 60 10  sll  %i5, 0x10, %g1
a01348e8:  bb 2e e0 10  sll  %i3, 0x10, %i5
a01348ec:  83 30 60 10  srl  %g1, 0x10, %g1
a01348f0:  bb 37 60 10  srl  %i5, 0x10, %i5
a01348f4:  f8 0e 40 01  ldub  [ %i1 + %g1 ], %i4
a01348f8:  80 a7 40 1a  cmp  %i5, %i2
a01348fc:  f8 28 40 18  stb  %i4, [ %g1 + %i0 ]
a0134900:  0a bf ff f8  bcs  0xa01348e0
a0134904:  ba 10 00 1b  mov  %i3, %i5
a0134908:  17 2a 00 b2  sethi  %hi(0xa802c800), %o3
a013490c:  b1 33 60 10  srl  %o5, 0x10, %i0
a0134910:  f8 12 e3 94  lduh  [ %o3 + 0x394 ], %i4
a0134914:  80 a6 00 1c  cmp  %i0, %i4
a0134918:  ba 10 00 0c  mov  %o4, %i5
a013491c:  1a 80 00 12  bcc  0xa0134964
a0134920:  b2 10 20 00  clr  %i1
a0134924:  35 2a 00 b7  sethi  %hi(0xa802dc00), %i2
a0134928:  9e 16 a1 50  or  %i2, 0x150, %o7	! 0xa802dd50
a013492c:  b0 10 00 1c  mov  %i4, %i0
a0134930:  b4 07 60 01  add  %i5, 1, %i2
a0134934:  b7 2f 60 10  sll  %i5, 0x10, %i3
a0134938:  bb 36 e0 10  srl  %i3, 0x10, %i5
a013493c:  83 2e 60 10  sll  %i1, 0x10, %g1
a0134940:  b9 2e a0 10  sll  %i2, 0x10, %i4
a0134944:  f6 0b c0 1d  ldub  [ %o7 + %i5 ], %i3
a0134948:  83 30 60 10  srl  %g1, 0x10, %g1
a013494c:  b9 37 20 10  srl  %i4, 0x10, %i4
a0134950:  f6 2b c0 01  stb  %i3, [ %o7 + %g1 ]
a0134954:  80 a7 00 18  cmp  %i4, %i0
a0134958:  ba 10 00 1a  mov  %i2, %i5
a013495c:  0a bf ff f5  bcs  0xa0134930
a0134960:  b2 06 60 01  inc  %i1
a0134964:  f0 12 e3 94  lduh  [ %o3 + 0x394 ], %i0
a0134968:  b2 26 00 0c  sub  %i0, %o4, %i1
a013496c:  f2 32 e3 94  sth  %i1, [ %o3 + 0x394 ]
a0134970:  b1 33 60 10  srl  %o5, 0x10, %i0
a0134974:  81 c7 e0 08  ret
a0134978:  81 e8 00 00  restore
