# leon2s FUN_a0099560 0xa0099560-0xa0099610 (176 bytes)
a0099560:  9d e3 bf 98  save  %sp, -104, %sp
a0099564:  33 2a 01 f5  sethi  %hi(0xa807d400), %i1
a0099568:  b4 0e 20 ff  and  %i0, 0xff, %i2
a009956c:  ba 16 62 80  or  %i1, 0x280, %i5
a0099570:  82 5e a0 b0  smul  %i2, 0xb0, %g1
a0099574:  82 00 40 1d  add  %g1, %i5, %g1
a0099578:  c0 28 60 8e  clrb  [ %g1 + 0x8e ]
a009957c:  c0 28 60 8f  clrb  [ %g1 + 0x8f ]
a0099580:  c0 28 60 91  clrb  [ %g1 + 0x91 ]
a0099584:  b6 10 00 01  mov  %g1, %i3
a0099588:  b8 10 20 00  clr  %i4
a009958c:  82 0f 20 ff  and  %i4, 0xff, %g1
a0099590:  b8 07 20 01  inc  %i4
a0099594:  82 06 c0 01  add  %i3, %g1, %g1
a0099598:  ba 0f 20 ff  and  %i4, 0xff, %i5
a009959c:  80 a7 60 03  cmp  %i5, 3
a00995a0:  08 bf ff fb  bleu  0xa009958c
a00995a4:  c0 28 60 92  clrb  [ %g1 + 0x92 ]
a00995a8:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a00995ac:  fa 08 62 30  ldub  [ %g1 + 0x230 ], %i5	! 0xa8078630
a00995b0:  80 a7 60 00  cmp  %i5, 0
a00995b4:  22 80 00 0b  be,a   0xa00995e0
a00995b8:  ba 16 62 80  or  %i1, 0x280, %i5
a00995bc:  82 10 20 64  mov  0x64, %g1
a00995c0:  9b 38 60 1f  sra  %g1, 0x1f, %o5
a00995c4:  81 83 60 00  mov  %o5, %y
a00995c8:  01 00 00 00  nop
a00995cc:  01 00 00 00  nop
a00995d0:  01 00 00 00  nop
a00995d4:  82 78 40 1d  sdiv  %g1, %i5, %g1
a00995d8:  10 80 00 05  b  0xa00995ec
a00995dc:  c2 2e e0 90  stb  %g1, [ %i3 + 0x90 ]
a00995e0:  82 5e a0 b0  smul  %i2, 0xb0, %g1
a00995e4:  82 00 40 1d  add  %g1, %i5, %g1
a00995e8:  c0 28 60 90  clrb  [ %g1 + 0x90 ]
a00995ec:  82 0e 20 ff  and  %i0, 0xff, %g1
a00995f0:  31 2a 01 f5  sethi  %hi(0xa807d400), %i0
a00995f4:  82 58 60 b0  smul  %g1, 0xb0, %g1
a00995f8:  b0 16 22 be  or  %i0, 0x2be, %i0
a00995fc:  b0 00 40 18  add  %g1, %i0, %i0
a0099600:  b2 10 20 00  clr  %i1
a0099604:  40 00 5f ea  call  0xa00b15ac
a0099608:  95 e8 20 50  restore  %g0, 0x50, %o2
a009960c:  01 00 00 00  nop
