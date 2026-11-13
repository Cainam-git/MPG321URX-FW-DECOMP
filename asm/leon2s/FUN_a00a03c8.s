# leon2s FUN_a00a03c8 0xa00a03c8-0xa00a0478 (176 bytes)
a00a03c8:  90 0a 20 ff  and  %o0, 0xff, %o0
a00a03cc:  03 2a 01 f6  sethi  %hi(0xa807d800), %g1
a00a03d0:  82 10 63 00  or  %g1, 0x300, %g1	! 0xa807db00
a00a03d4:  90 5a 20 34  smul  %o0, 0x34, %o0
a00a03d8:  90 02 00 01  add  %o0, %g1, %o0
a00a03dc:  d8 02 20 2c  ld  [ %o0 + 0x2c ], %o4
a00a03e0:  c2 03 00 00  ld  [ %o4 ], %g1
a00a03e4:  80 88 60 30  btst  0x30, %g1
a00a03e8:  32 80 00 22  bne,a   0xa00a0470
a00a03ec:  90 10 20 00  clr  %o0
a00a03f0:  c2 03 00 00  ld  [ %o4 ], %g1
a00a03f4:  83 30 60 10  srl  %g1, 0x10, %g1
a00a03f8:  82 08 60 ff  and  %g1, 0xff, %g1
a00a03fc:  80 a0 60 01  cmp  %g1, 1
a00a0400:  32 80 00 1c  bne,a   0xa00a0470
a00a0404:  90 10 20 00  clr  %o0
a00a0408:  c2 03 00 00  ld  [ %o4 ], %g1
a00a040c:  83 30 60 18  srl  %g1, 0x18, %g1
a00a0410:  da 03 20 04  ld  [ %o4 + 4 ], %o5
a00a0414:  83 28 60 08  sll  %g1, 8, %g1
a00a0418:  9a 0b 60 ff  and  %o5, 0xff, %o5
a00a041c:  82 00 40 0d  add  %g1, %o5, %g1
a00a0420:  80 a0 60 02  cmp  %g1, 2
a00a0424:  12 80 00 13  bne  0xa00a0470
a00a0428:  90 10 20 00  clr  %o0
a00a042c:  c2 03 20 04  ld  [ %o4 + 4 ], %g1
a00a0430:  83 30 60 08  srl  %g1, 8, %g1
a00a0434:  da 03 20 04  ld  [ %o4 + 4 ], %o5
a00a0438:  82 08 60 ff  and  %g1, 0xff, %g1
a00a043c:  9b 33 60 10  srl  %o5, 0x10, %o5
a00a0440:  83 28 60 08  sll  %g1, 8, %g1
a00a0444:  9a 0b 60 ff  and  %o5, 0xff, %o5
a00a0448:  82 00 40 0d  add  %g1, %o5, %g1
a00a044c:  80 a0 60 00  cmp  %g1, 0
a00a0450:  02 80 00 07  be  0xa00a046c
a00a0454:  90 10 20 01  mov  1, %o0
a00a0458:  c2 03 20 04  ld  [ %o4 + 4 ], %g1
a00a045c:  83 30 60 18  srl  %g1, 0x18, %g1
a00a0460:  80 a0 60 00  cmp  %g1, 0
a00a0464:  12 80 00 03  bne  0xa00a0470
a00a0468:  01 00 00 00  nop
a00a046c:  90 10 20 00  clr  %o0	! 0x0
a00a0470:  81 c3 e0 08  retl
a00a0474:  01 00 00 00  nop
