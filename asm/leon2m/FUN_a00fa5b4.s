# leon2m FUN_a00fa5b4 0xa00fa5b4-0xa00fa6b4 (256 bytes)
a00fa5b4:  9d e3 bf 98  save  %sp, -104, %sp
a00fa5b8:  03 2a 00 ad  sethi  %hi(0xa802b400), %g1
a00fa5bc:  fa 08 63 fe  ldub  [ %g1 + 0x3fe ], %i5	! 0xa802b7fe
a00fa5c0:  80 a7 60 00  cmp  %i5, 0
a00fa5c4:  02 80 00 3a  be  0xa00fa6ac
a00fa5c8:  35 2a 00 9a  sethi  %hi(0xa8026800), %i2
a00fa5cc:  33 2a 00 af  sethi  %hi(0xa802bc00), %i1
a00fa5d0:  03 2a 00 af  sethi  %hi(0xa802bc00), %g1
a00fa5d4:  c0 36 a2 94  clrh  [ %i2 + 0x294 ]
a00fa5d8:  3b 2a 00 af  sethi  %hi(0xa802bc00), %i5
a00fa5dc:  37 2a 00 ae  sethi  %hi(0xa802b800), %i3
a00fa5e0:  f8 10 62 c0  lduh  [ %g1 + 0x2c0 ], %i4
a00fa5e4:  b4 16 60 80  or  %i1, 0x80, %i2
a00fa5e8:  f8 37 62 c2  sth  %i4, [ %i5 + 0x2c2 ]
a00fa5ec:  b2 16 e0 00  mov  %i3, %i1
a00fa5f0:  31 2a 00 ae  sethi  %hi(0xa802b800), %i0
a00fa5f4:  ba 16 22 40  or  %i0, 0x240, %i5	! 0xa802ba40
a00fa5f8:  b6 10 20 00  clr  %i3
a00fa5fc:  b0 06 c0 1b  add  %i3, %i3, %i0
a00fa600:  b6 06 e0 01  inc  %i3
a00fa604:  f8 37 40 18  sth  %i4, [ %i5 + %i0 ]
a00fa608:  f8 36 80 18  sth  %i4, [ %i2 + %i0 ]
a00fa60c:  80 a6 e1 1f  cmp  %i3, 0x11f
a00fa610:  08 bf ff fb  bleu  0xa00fa5fc
a00fa614:  f8 36 40 18  sth  %i4, [ %i1 + %i0 ]
a00fa618:  39 3f bf ff  sethi  %hi(0xfefffc00), %i4
a00fa61c:  37 34 01 00  sethi  %hi(0xd0040000), %i3
a00fa620:  9e 10 00 19  mov  %i1, %o7
a00fa624:  b0 17 23 ff  or  %i4, 0x3ff, %i0
a00fa628:  9a 16 e0 a0  or  %i3, 0xa0, %o5
a00fa62c:  98 10 20 00  clr  %o4
a00fa630:  b8 10 20 00  clr  %i4
a00fa634:  b2 16 e0 a4  or  %i3, 0xa4, %i1
a00fa638:  b4 07 00 1c  add  %i4, %i4, %i2
a00fa63c:  ba 06 80 1c  add  %i2, %i4, %i5
a00fa640:  b5 2f 60 03  sll  %i5, 3, %i2
a00fa644:  b6 10 20 00  clr  %i3
a00fa648:  ba 0e e0 ff  and  %i3, 0xff, %i5
a00fa64c:  82 06 80 1d  add  %i2, %i5, %g1
a00fa650:  b9 28 60 10  sll  %g1, 0x10, %i4
a00fa654:  83 37 20 10  srl  %i4, 0x10, %g1
a00fa658:  ba 00 40 01  add  %g1, %g1, %i5
a00fa65c:  f8 13 c0 1d  lduh  [ %o7 + %i5 ], %i4
a00fa660:  f8 26 40 00  st  %i4, [ %i1 ]
a00fa664:  82 10 62 00  or  %g1, 0x200, %g1
a00fa668:  b6 06 e0 01  inc  %i3
a00fa66c:  82 08 40 18  and  %g1, %i0, %g1
a00fa670:  b8 0e e0 ff  and  %i3, 0xff, %i4
a00fa674:  80 a7 20 17  cmp  %i4, 0x17
a00fa678:  c2 23 40 00  st  %g1, [ %o5 ]
a00fa67c:  28 bf ff f4  bleu,a   0xa00fa64c
a00fa680:  ba 0e e0 ff  and  %i3, 0xff, %i5
a00fa684:  98 03 20 01  inc  %o4
a00fa688:  b8 0b 20 ff  and  %o4, 0xff, %i4
a00fa68c:  80 a7 20 0b  cmp  %i4, 0xb
a00fa690:  28 bf ff eb  bleu,a   0xa00fa63c
a00fa694:  b4 07 00 1c  add  %i4, %i4, %i2
a00fa698:  c0 26 40 00  clr  [ %i1 ]
a00fa69c:  b0 08 7d ff  and  %g1, -513, %i0
a00fa6a0:  f0 23 40 00  st  %i0, [ %o5 ]
a00fa6a4:  33 2a 00 b2  sethi  %hi(0xa802c800), %i1
a00fa6a8:  f0 26 60 60  st  %i0, [ %i1 + 0x60 ]	! 0xa802c860
a00fa6ac:  81 c7 e0 08  ret
a00fa6b0:  81 e8 00 00  restore
