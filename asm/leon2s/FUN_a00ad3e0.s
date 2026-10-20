# leon2s FUN_a00ad3e0 0xa00ad3e0-0xa00ad478 (152 bytes)
a00ad3e0:  9d e3 bf 98  save  %sp, -104, %sp
a00ad3e4:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00ad3e8:  7f ff 5a ba  call  0xa0083ed0
a00ad3ec:  90 10 00 18  mov  %i0, %o0
a00ad3f0:  90 0a 20 ff  and  %o0, 0xff, %o0
a00ad3f4:  80 a2 20 01  cmp  %o0, 1
a00ad3f8:  12 80 00 07  bne  0xa00ad414
a00ad3fc:  9a 10 20 01  mov  1, %o5
a00ad400:  03 33 c0 4c  sethi  %hi(0xcf013000), %g1
a00ad404:  82 10 62 c0  or  %g1, 0x2c0, %g1	! 0xcf0132c0
a00ad408:  c2 00 40 00  ld  [ %g1 ], %g1
a00ad40c:  10 80 00 09  b  0xa00ad430
a00ad410:  80 88 60 40  btst  0x40, %g1
a00ad414:  80 a2 20 00  cmp  %o0, 0
a00ad418:  32 80 00 09  bne,a   0xa00ad43c
a00ad41c:  1b 2a 01 f7  sethi  %hi(0xa807dc00), %o5
a00ad420:  03 33 c0 4c  sethi  %hi(0xcf013000), %g1
a00ad424:  82 10 62 c0  or  %g1, 0x2c0, %g1	! 0xcf0132c0
a00ad428:  c2 00 40 00  ld  [ %g1 ], %g1
a00ad42c:  80 88 60 80  btst  0x80, %g1
a00ad430:  12 80 00 10  bne  0xa00ad470
a00ad434:  01 00 00 00  nop
a00ad438:  1b 2a 01 f7  sethi  %hi(0xa807dc00), %o5
a00ad43c:  9a 13 60 18  or  %o5, 0x18, %o5	! 0xa807dc18
a00ad440:  82 5e 21 2c  smul  %i0, 0x12c, %g1
a00ad444:  82 00 40 0d  add  %g1, %o5, %g1
a00ad448:  c2 08 61 1f  ldub  [ %g1 + 0x11f ], %g1
a00ad44c:  80 a0 60 01  cmp  %g1, 1
a00ad450:  12 80 00 07  bne  0xa00ad46c
a00ad454:  9a 10 20 01  mov  1, %o5
a00ad458:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a00ad45c:  c2 08 63 16  ldub  [ %g1 + 0x316 ], %g1	! 0xa8079316
a00ad460:  80 a0 60 01  cmp  %g1, 1
a00ad464:  02 80 00 03  be  0xa00ad470
a00ad468:  01 00 00 00  nop
a00ad46c:  9a 10 20 00  clr  %o5	! 0x0
a00ad470:  81 c7 e0 08  ret
a00ad474:  91 e8 00 0d  restore  %g0, %o5, %o0
