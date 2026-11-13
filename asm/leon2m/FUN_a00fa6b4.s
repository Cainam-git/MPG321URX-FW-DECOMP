# leon2m FUN_a00fa6b4 0xa00fa6b4-0xa00fa814 (352 bytes)
a00fa6b4:  9d e3 bf 98  save  %sp, -104, %sp
a00fa6b8:  35 34 01 00  sethi  %hi(0xd0040000), %i2
a00fa6bc:  b2 16 a0 14  or  %i2, 0x14, %i1	! 0xd0040014
a00fa6c0:  f8 06 40 00  ld  [ %i1 ], %i4
a00fa6c4:  b1 2f 20 06  sll  %i4, 6, %i0
a00fa6c8:  37 2a 00 b2  sethi  %hi(0xa802c800), %i3
a00fa6cc:  bb 36 20 16  srl  %i0, 0x16, %i5
a00fa6d0:  b9 37 20 1e  srl  %i4, 0x1e, %i4
a00fa6d4:  33 2a 00 af  sethi  %hi(0xa802bc00), %i1
a00fa6d8:  c2 0e e0 5e  ldub  [ %i3 + 0x5e ], %g1
a00fa6dc:  80 a7 00 01  cmp  %i4, %g1
a00fa6e0:  02 80 00 48  be  0xa00fa800
a00fa6e4:  fa 36 62 c0  sth  %i5, [ %i1 + 0x2c0 ]
a00fa6e8:  f8 2e e0 5e  stb  %i4, [ %i3 + 0x5e ]
a00fa6ec:  35 2a 00 ad  sethi  %hi(0xa802b400), %i2
a00fa6f0:  b6 10 20 01  mov  1, %i3
a00fa6f4:  f6 2e a3 fe  stb  %i3, [ %i2 + 0x3fe ]
a00fa6f8:  31 2a 00 ad  sethi  %hi(0xa802b400), %i0
a00fa6fc:  f8 0e 23 f8  ldub  [ %i0 + 0x3f8 ], %i4	! 0xa802b7f8
a00fa700:  ba 07 3f ff  add  %i4, -1, %i5
a00fa704:  82 0f 60 ff  and  %i5, 0xff, %g1
a00fa708:  80 a0 60 02  cmp  %g1, 2
a00fa70c:  18 80 00 40  bgu  0xa00fa80c
a00fa710:  f6 0e a3 fe  ldub  [ %i2 + 0x3fe ], %i3
a00fa714:  80 a6 e0 00  cmp  %i3, 0
a00fa718:  02 80 00 3d  be  0xa00fa80c
a00fa71c:  f8 16 62 c0  lduh  [ %i1 + 0x2c0 ], %i4
a00fa720:  35 2a 00 9a  sethi  %hi(0xa8026800), %i2
a00fa724:  33 2a 00 af  sethi  %hi(0xa802bc00), %i1
a00fa728:  c0 36 a2 94  clrh  [ %i2 + 0x294 ]
a00fa72c:  3b 2a 00 ae  sethi  %hi(0xa802b800), %i5
a00fa730:  b4 16 60 80  or  %i1, 0x80, %i2
a00fa734:  31 2a 00 af  sethi  %hi(0xa802bc00), %i0
a00fa738:  b2 17 60 00  mov  %i5, %i1
a00fa73c:  03 2a 00 ae  sethi  %hi(0xa802b800), %g1
a00fa740:  f8 36 22 c2  sth  %i4, [ %i0 + 0x2c2 ]
a00fa744:  ba 10 62 40  or  %g1, 0x240, %i5
a00fa748:  b6 10 20 00  clr  %i3
a00fa74c:  82 06 c0 1b  add  %i3, %i3, %g1
a00fa750:  b6 06 e0 01  inc  %i3
a00fa754:  f8 37 40 01  sth  %i4, [ %i5 + %g1 ]
a00fa758:  f8 36 80 01  sth  %i4, [ %i2 + %g1 ]
a00fa75c:  80 a6 e1 1f  cmp  %i3, 0x11f
a00fa760:  08 bf ff fb  bleu  0xa00fa74c
a00fa764:  f8 36 40 01  sth  %i4, [ %i1 + %g1 ]
a00fa768:  39 3f bf ff  sethi  %hi(0xfefffc00), %i4
a00fa76c:  37 34 01 00  sethi  %hi(0xd0040000), %i3
a00fa770:  9e 10 00 19  mov  %i1, %o7
a00fa774:  b0 17 23 ff  or  %i4, 0x3ff, %i0
a00fa778:  9a 16 e0 a0  or  %i3, 0xa0, %o5
a00fa77c:  98 10 20 00  clr  %o4
a00fa780:  b8 10 20 00  clr  %i4
a00fa784:  b2 16 e0 a4  or  %i3, 0xa4, %i1
a00fa788:  b4 07 00 1c  add  %i4, %i4, %i2
a00fa78c:  ba 06 80 1c  add  %i2, %i4, %i5
a00fa790:  b5 2f 60 03  sll  %i5, 3, %i2
a00fa794:  b6 10 20 00  clr  %i3
a00fa798:  ba 0e e0 ff  and  %i3, 0xff, %i5
a00fa79c:  82 06 80 1d  add  %i2, %i5, %g1
a00fa7a0:  b9 28 60 10  sll  %g1, 0x10, %i4
a00fa7a4:  83 37 20 10  srl  %i4, 0x10, %g1
a00fa7a8:  ba 00 40 01  add  %g1, %g1, %i5
a00fa7ac:  f8 13 c0 1d  lduh  [ %o7 + %i5 ], %i4
a00fa7b0:  f8 26 40 00  st  %i4, [ %i1 ]
a00fa7b4:  82 10 62 00  or  %g1, 0x200, %g1
a00fa7b8:  b6 06 e0 01  inc  %i3
a00fa7bc:  82 08 40 18  and  %g1, %i0, %g1
a00fa7c0:  b8 0e e0 ff  and  %i3, 0xff, %i4
a00fa7c4:  80 a7 20 17  cmp  %i4, 0x17
a00fa7c8:  c2 23 40 00  st  %g1, [ %o5 ]
a00fa7cc:  28 bf ff f4  bleu,a   0xa00fa79c
a00fa7d0:  ba 0e e0 ff  and  %i3, 0xff, %i5
a00fa7d4:  98 03 20 01  inc  %o4
a00fa7d8:  b8 0b 20 ff  and  %o4, 0xff, %i4
a00fa7dc:  80 a7 20 0b  cmp  %i4, 0xb
a00fa7e0:  28 bf ff eb  bleu,a   0xa00fa78c
a00fa7e4:  b4 07 00 1c  add  %i4, %i4, %i2
a00fa7e8:  c0 26 40 00  clr  [ %i1 ]
a00fa7ec:  b0 08 7d ff  and  %g1, -513, %i0
a00fa7f0:  f0 23 40 00  st  %i0, [ %o5 ]
a00fa7f4:  33 2a 00 b2  sethi  %hi(0xa802c800), %i1
a00fa7f8:  10 80 00 05  b  0xa00fa80c
a00fa7fc:  f0 26 60 60  st  %i0, [ %i1 + 0x60 ]	! 0xa802c860
a00fa800:  35 2a 00 ad  sethi  %hi(0xa802b400), %i2
a00fa804:  10 bf ff bd  b  0xa00fa6f8
a00fa808:  c0 2e a3 fe  clrb  [ %i2 + 0x3fe ]	! 0xa802b7fe
a00fa80c:  81 c7 e0 08  ret
a00fa810:  81 e8 00 00  restore
