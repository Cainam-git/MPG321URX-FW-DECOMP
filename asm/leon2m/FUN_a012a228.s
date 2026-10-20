# leon2m FUN_a012a228 0xa012a228-0xa012a2f0 (200 bytes)
a012a228:  9d e3 bf 98  save  %sp, -104, %sp
a012a22c:  03 2a 00 b2  sethi  %hi(0xa802c800), %g1
a012a230:  fa 00 62 0c  ld  [ %g1 + 0x20c ], %i5	! 0xa802ca0c
a012a234:  80 a7 60 00  cmp  %i5, 0
a012a238:  02 80 00 2c  be  0xa012a2e8
a012a23c:  b0 10 20 00  clr  %i0
a012a240:  31 2a 00 b2  sethi  %hi(0xa802c800), %i0
a012a244:  33 2a 00 b2  sethi  %hi(0xa802c800), %i1
a012a248:  9e 16 22 9c  or  %i0, 0x29c, %o7
a012a24c:  b0 16 62 5c  or  %i1, 0x25c, %i0
a012a250:  b2 10 20 00  clr  %i1
a012a254:  b6 10 20 00  clr  %i3
a012a258:  b4 10 20 00  clr  %i2
a012a25c:  ba 10 20 00  clr  %i5
a012a260:  bb 2f 60 02  sll  %i5, 2, %i5
a012a264:  f8 06 00 1d  ld  [ %i0 + %i5 ], %i4
a012a268:  c2 03 c0 1d  ld  [ %o7 + %i5 ], %g1
a012a26c:  82 20 40 1c  sub  %g1, %i4, %g1
a012a270:  bb 38 60 1f  sra  %g1, 0x1f, %i5
a012a274:  82 1f 40 01  xor  %i5, %g1, %g1
a012a278:  b8 20 40 1d  sub  %g1, %i5, %i4
a012a27c:  83 2f 20 10  sll  %i4, 0x10, %g1
a012a280:  ba 06 e0 01  add  %i3, 1, %i5
a012a284:  b9 30 60 10  srl  %g1, 0x10, %i4
a012a288:  80 a7 20 40  cmp  %i4, 0x40
a012a28c:  08 80 00 08  bleu  0xa012a2ac
a012a290:  b6 0e e0 80  and  %i3, 0x80, %i3
a012a294:  82 0f 60 ff  and  %i5, 0xff, %g1
a012a298:  b6 10 00 1d  mov  %i5, %i3
a012a29c:  80 a0 60 01  cmp  %g1, 1
a012a2a0:  08 80 00 03  bleu  0xa012a2ac
a012a2a4:  b2 06 60 01  inc  %i1
a012a2a8:  b6 17 7f 80  or  %i5, -128, %i3
a012a2ac:  b4 06 a0 01  inc  %i2
a012a2b0:  ba 0e a0 ff  and  %i2, 0xff, %i5
a012a2b4:  80 a7 60 0f  cmp  %i5, 0xf
a012a2b8:  28 bf ff eb  bleu,a   0xa012a264
a012a2bc:  bb 2f 60 02  sll  %i5, 2, %i5
a012a2c0:  b8 0e 60 ff  and  %i1, 0xff, %i4
a012a2c4:  80 a7 20 03  cmp  %i4, 3
a012a2c8:  b3 2e e0 18  sll  %i3, 0x18, %i1
a012a2cc:  b5 36 60 1f  srl  %i1, 0x1f, %i2
a012a2d0:  b6 60 20 00  subx  %g0, 0, %i3
a012a2d4:  80 8e c0 1a  btst  %i3, %i2
a012a2d8:  12 80 00 04  bne  0xa012a2e8
a012a2dc:  b0 10 20 00  clr  %i0
a012a2e0:  80 a0 00 1c  cmp  %g0, %i4
a012a2e4:  b0 40 20 00  addx  %g0, 0, %i0
a012a2e8:  81 c7 e0 08  ret
a012a2ec:  81 e8 00 00  restore
