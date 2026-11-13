# leon2s FUN_a009f5c8 0xa009f5c8-0xa009f654 (140 bytes)
a009f5c8:  90 0a 20 ff  and  %o0, 0xff, %o0
a009f5cc:  03 2a 01 f6  sethi  %hi(0xa807d800), %g1
a009f5d0:  82 10 63 00  or  %g1, 0x300, %g1	! 0xa807db00
a009f5d4:  9a 5a 20 34  smul  %o0, 0x34, %o5
a009f5d8:  9a 03 40 01  add  %o5, %g1, %o5
a009f5dc:  c2 03 60 18  ld  [ %o5 + 0x18 ], %g1
a009f5e0:  da 00 60 90  ld  [ %g1 + 0x90 ], %o5
a009f5e4:  03 2a 01 f5  sethi  %hi(0xa807d400), %g1
a009f5e8:  82 10 62 80  or  %g1, 0x280, %g1	! 0xa807d680
a009f5ec:  98 5a 20 b0  smul  %o0, 0xb0, %o4
a009f5f0:  98 03 00 01  add  %o4, %g1, %o4
a009f5f4:  9b 33 60 18  srl  %o5, 0x18, %o5
a009f5f8:  9a 0b 60 0f  and  %o5, 0xf, %o5
a009f5fc:  c2 0b 20 02  ldub  [ %o4 + 2 ], %g1
a009f600:  80 a3 40 01  cmp  %o5, %g1
a009f604:  02 80 00 12  be  0xa009f64c
a009f608:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a009f60c:  82 10 60 d8  or  %g1, 0xd8, %g1	! 0xa80790d8
a009f610:  c2 08 40 08  ldub  [ %g1 + %o0 ], %g1
a009f614:  80 a0 60 00  cmp  %g1, 0
a009f618:  02 80 00 0d  be  0xa009f64c
a009f61c:  9b 2a 20 02  sll  %o0, 2, %o5
a009f620:  03 2a 01 f5  sethi  %hi(0xa807d400), %g1
a009f624:  82 10 62 48  or  %g1, 0x248, %g1	! 0xa807d648
a009f628:  c2 00 40 0d  ld  [ %g1 + %o5 ], %g1
a009f62c:  80 a0 60 04  cmp  %g1, 4
a009f630:  08 80 00 07  bleu  0xa009f64c
a009f634:  80 a0 60 07  cmp  %g1, 7
a009f638:  02 80 00 05  be  0xa009f64c
a009f63c:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a009f640:  9a 10 20 01  mov  1, %o5
a009f644:  82 10 60 d0  or  %g1, 0xd0, %g1
a009f648:  da 28 40 08  stb  %o5, [ %g1 + %o0 ]
a009f64c:  81 c3 e0 08  retl
a009f650:  01 00 00 00  nop
