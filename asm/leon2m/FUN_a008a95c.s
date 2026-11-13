# leon2m FUN_a008a95c 0xa008a95c-0xa008abe0 (644 bytes)
a008a95c:  9d e3 bf 98  save  %sp, -104, %sp
a008a960:  39 2a 00 ab  sethi  %hi(0xa802ac00), %i4
a008a964:  c2 0f 23 bd  ldub  [ %i4 + 0x3bd ], %g1	! 0xa802afbd
a008a968:  80 a0 60 14  cmp  %g1, 0x14
a008a96c:  02 80 00 47  be  0xa008aa88
a008a970:  33 2a 00 b4  sethi  %hi(0xa802d000), %i1
a008a974:  da 0f 23 bd  ldub  [ %i4 + 0x3bd ], %o5
a008a978:  98 03 7f ff  add  %o5, -1, %o4
a008a97c:  90 0b 20 ff  and  %o4, 0xff, %o0
a008a980:  80 a2 20 0b  cmp  %o0, 0xb
a008a984:  08 80 00 27  bleu  0xa008aa20
a008a988:  82 0b 60 ff  and  %o5, 0xff, %g1
a008a98c:  9a 0b 60 ff  and  %o5, 0xff, %o5
a008a990:  80 a3 60 13  cmp  %o5, 0x13
a008a994:  02 80 00 71  be  0xa008ab58
a008a998:  80 a3 60 18  cmp  %o5, 0x18
a008a99c:  02 80 00 87  be  0xa008abb8
a008a9a0:  80 a3 60 10  cmp  %o5, 0x10
a008a9a4:  02 80 00 4a  be  0xa008aacc
a008a9a8:  80 a3 60 0f  cmp  %o5, 0xf
a008a9ac:  02 80 00 88  be  0xa008abcc
a008a9b0:  80 a3 60 14  cmp  %o5, 0x14
a008a9b4:  02 80 00 51  be  0xa008aaf8
a008a9b8:  92 03 40 0d  add  %o5, %o5, %o1
a008a9bc:  37 00 04 00  sethi  %hi(0x100000), %i3
a008a9c0:  82 02 40 0d  add  %o1, %o5, %g1
a008a9c4:  94 16 e2 42  or  %i3, 0x242, %o2
a008a9c8:  b0 00 40 0a  add  %g1, %o2, %i0
a008a9cc:  f4 0a 80 01  ldub  [ %o2 + %g1 ], %i2
a008a9d0:  da 0e 20 02  ldub  [ %i0 + 2 ], %o5
a008a9d4:  b2 06 80 0d  add  %i2, %o5, %i1
a008a9d8:  99 2e 60 10  sll  %i1, 0x10, %o4
a008a9dc:  91 33 20 10  srl  %o4, 0x10, %o0
a008a9e0:  d2 0e 20 01  ldub  [ %i0 + 1 ], %o1
a008a9e4:  94 10 20 04  mov  4, %o2
a008a9e8:  96 10 27 90  mov  0x790, %o3
a008a9ec:  40 02 f0 25  call  0xa0146a80
a008a9f0:  98 10 20 00  clr  %o4
a008a9f4:  f0 0f 23 bd  ldub  [ %i4 + 0x3bd ], %i0
a008a9f8:  9e 06 00 18  add  %i0, %i0, %o7
a008a9fc:  96 16 e2 42  or  %i3, 0x242, %o3
a008aa00:  90 03 c0 18  add  %o7, %i0, %o0
a008aa04:  b8 02 00 0b  add  %o0, %o3, %i4
a008aa08:  f4 0f 20 02  ldub  [ %i4 + 2 ], %i2
a008aa0c:  f2 0f 20 01  ldub  [ %i4 + 1 ], %i1
a008aa10:  f0 0a c0 08  ldub  [ %o3 + %o0 ], %i0
a008aa14:  b6 10 20 90  mov  0x90, %i3
a008aa18:  40 02 f0 1a  call  0xa0146a80
a008aa1c:  99 e8 20 00  restore  %g0, 0, %o4
a008aa20:  37 00 04 00  sethi  %hi(0x100000), %i3
a008aa24:  b4 00 40 01  add  %g1, %g1, %i2
a008aa28:  b0 06 80 01  add  %i2, %g1, %i0
a008aa2c:  b2 16 e2 42  or  %i3, 0x242, %i1
a008aa30:  94 06 00 19  add  %i0, %i1, %o2
a008aa34:  de 0e 40 18  ldub  [ %i1 + %i0 ], %o7
a008aa38:  da 0a a0 02  ldub  [ %o2 + 2 ], %o5
a008aa3c:  96 03 c0 0d  add  %o7, %o5, %o3
a008aa40:  93 2a e0 10  sll  %o3, 0x10, %o1
a008aa44:  91 32 60 10  srl  %o1, 0x10, %o0
a008aa48:  d2 0a a0 01  ldub  [ %o2 + 1 ], %o1
a008aa4c:  96 10 27 90  mov  0x790, %o3
a008aa50:  94 10 20 03  mov  3, %o2
a008aa54:  40 02 f0 0b  call  0xa0146a80
a008aa58:  98 10 20 00  clr  %o4
a008aa5c:  f0 0f 23 bd  ldub  [ %i4 + 0x3bd ], %i0
a008aa60:  9e 06 00 18  add  %i0, %i0, %o7
a008aa64:  96 16 e2 42  or  %i3, 0x242, %o3
a008aa68:  90 03 c0 18  add  %o7, %i0, %o0
a008aa6c:  b8 02 00 0b  add  %o0, %o3, %i4
a008aa70:  f4 0f 20 02  ldub  [ %i4 + 2 ], %i2
a008aa74:  f2 0f 20 01  ldub  [ %i4 + 1 ], %i1
a008aa78:  f0 0a c0 08  ldub  [ %o3 + %o0 ], %i0
a008aa7c:  b6 10 20 90  mov  0x90, %i3
a008aa80:  40 02 f0 00  call  0xa0146a80
a008aa84:  99 e8 20 00  restore  %g0, 0, %o4
a008aa88:  31 2a 00 ab  sethi  %hi(0xa802ac00), %i0
a008aa8c:  98 16 62 90  or  %i1, 0x290, %o4
a008aa90:  de 0e 23 be  ldub  [ %i0 + 0x3be ], %o7
a008aa94:  d4 03 21 d4  ld  [ %o4 + 0x1d4 ], %o2
a008aa98:  96 0b e0 01  and  %o7, 1, %o3
a008aa9c:  9b 2a e0 06  sll  %o3, 6, %o5
a008aaa0:  92 0a bf bf  and  %o2, -65, %o1
a008aaa4:  90 12 40 0d  or  %o1, %o5, %o0
a008aaa8:  80 8a 20 40  btst  0x40, %o0
a008aaac:  12 bf ff b2  bne  0xa008a974
a008aab0:  d0 23 21 d4  st  %o0, [ %o4 + 0x1d4 ]
a008aab4:  40 01 38 88  call  0xa00d8cd4
a008aab8:  35 2a 00 ac  sethi  %hi(0xa802b000), %i2
a008aabc:  c2 0e a0 8e  ldub  [ %i2 + 0x8e ], %g1	! 0xa802b08e
a008aac0:  b6 10 60 08  or  %g1, 8, %i3
a008aac4:  10 bf ff ac  b  0xa008a974
a008aac8:  f6 2e a0 8e  stb  %i3, [ %i2 + 0x8e ]
a008aacc:  37 00 04 00  sethi  %hi(0x100000), %i3
a008aad0:  82 16 e2 42  or  %i3, 0x242, %g1	! 0x100242
a008aad4:  98 00 60 30  add  %g1, 0x30, %o4
a008aad8:  f2 08 60 30  ldub  [ %g1 + 0x30 ], %i1
a008aadc:  f4 0b 20 02  ldub  [ %o4 + 2 ], %i2
a008aae0:  b0 06 40 1a  add  %i1, %i2, %i0
a008aae4:  9b 2e 20 10  sll  %i0, 0x10, %o5
a008aae8:  91 33 60 10  srl  %o5, 0x10, %o0
a008aaec:  d2 0b 20 01  ldub  [ %o4 + 1 ], %o1
a008aaf0:  10 bf ff be  b  0xa008a9e8
a008aaf4:  94 10 20 01  mov  1, %o2
a008aaf8:  37 00 04 00  sethi  %hi(0x100000), %i3
a008aafc:  92 16 e2 42  or  %i3, 0x242, %o1	! 0x100242
a008ab00:  98 02 60 3c  add  %o1, 0x3c, %o4
a008ab04:  d0 0a 60 3c  ldub  [ %o1 + 0x3c ], %o0
a008ab08:  de 0b 20 02  ldub  [ %o4 + 2 ], %o7
a008ab0c:  96 02 00 0f  add  %o0, %o7, %o3
a008ab10:  91 2a e0 10  sll  %o3, 0x10, %o0
a008ab14:  d2 0b 20 01  ldub  [ %o4 + 1 ], %o1
a008ab18:  91 32 20 10  srl  %o0, 0x10, %o0
a008ab1c:  96 10 27 90  mov  0x790, %o3
a008ab20:  94 10 20 06  mov  6, %o2
a008ab24:  40 02 ef d7  call  0xa0146a80
a008ab28:  98 10 20 00  clr  %o4
a008ab2c:  f0 0f 23 bd  ldub  [ %i4 + 0x3bd ], %i0
a008ab30:  9e 06 00 18  add  %i0, %i0, %o7
a008ab34:  96 16 e2 42  or  %i3, 0x242, %o3
a008ab38:  90 03 c0 18  add  %o7, %i0, %o0
a008ab3c:  b8 02 00 0b  add  %o0, %o3, %i4
a008ab40:  f4 0f 20 02  ldub  [ %i4 + 2 ], %i2
a008ab44:  f2 0f 20 01  ldub  [ %i4 + 1 ], %i1
a008ab48:  f0 0a c0 08  ldub  [ %o3 + %o0 ], %i0
a008ab4c:  b6 10 20 90  mov  0x90, %i3
a008ab50:  40 02 ef cc  call  0xa0146a80
a008ab54:  99 e8 20 00  restore  %g0, 0, %o4
a008ab58:  37 00 04 00  sethi  %hi(0x100000), %i3
a008ab5c:  94 16 e2 42  or  %i3, 0x242, %o2	! 0x100242
a008ab60:  98 02 a0 39  add  %o2, 0x39, %o4
a008ab64:  d0 0a a0 39  ldub  [ %o2 + 0x39 ], %o0
a008ab68:  de 0b 20 02  ldub  [ %o4 + 2 ], %o7
a008ab6c:  96 02 00 0f  add  %o0, %o7, %o3
a008ab70:  91 2a e0 10  sll  %o3, 0x10, %o0
a008ab74:  d2 0b 20 01  ldub  [ %o4 + 1 ], %o1
a008ab78:  91 32 20 10  srl  %o0, 0x10, %o0
a008ab7c:  96 10 27 90  mov  0x790, %o3
a008ab80:  94 10 20 0a  mov  0xa, %o2
a008ab84:  40 02 ef bf  call  0xa0146a80
a008ab88:  98 10 20 00  clr  %o4
a008ab8c:  f0 0f 23 bd  ldub  [ %i4 + 0x3bd ], %i0
a008ab90:  9e 06 00 18  add  %i0, %i0, %o7
a008ab94:  96 16 e2 42  or  %i3, 0x242, %o3
a008ab98:  90 03 c0 18  add  %o7, %i0, %o0
a008ab9c:  b8 02 00 0b  add  %o0, %o3, %i4
a008aba0:  f4 0f 20 02  ldub  [ %i4 + 2 ], %i2
a008aba4:  f2 0f 20 01  ldub  [ %i4 + 1 ], %i1
a008aba8:  f0 0a c0 08  ldub  [ %o3 + %o0 ], %i0
a008abac:  b6 10 20 90  mov  0x90, %i3
a008abb0:  40 02 ef b4  call  0xa0146a80
a008abb4:  99 e8 20 00  restore  %g0, 0, %o4
a008abb8:  37 00 04 00  sethi  %hi(0x100000), %i3
a008abbc:  92 16 e2 42  or  %i3, 0x242, %o1	! 0x100242
a008abc0:  98 02 60 48  add  %o1, 0x48, %o4
a008abc4:  10 bf ff e9  b  0xa008ab68
a008abc8:  d0 0a 60 48  ldub  [ %o1 + 0x48 ], %o0
a008abcc:  37 00 04 00  sethi  %hi(0x100000), %i3
a008abd0:  94 16 e2 42  or  %i3, 0x242, %o2	! 0x100242
a008abd4:  98 02 a0 2d  add  %o2, 0x2d, %o4
a008abd8:  10 bf ff cc  b  0xa008ab08
a008abdc:  d0 0a a0 2d  ldub  [ %o2 + 0x2d ], %o0
