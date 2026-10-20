# leon2m FUN_a002e2a4 0xa002e2a4-0xa002e3c4 (288 bytes)  [FUN_a002e3bc = unreachable ret/restore tail, merged]
a002e2a4:  9d e3 bf 98  save  %sp, -104, %sp
a002e2a8:  31 33 c0 3b  sethi  %hi(0xcf00ec00), %i0
a002e2ac:  82 16 21 40  or  %i0, 0x140, %g1	! 0xcf00ed40
a002e2b0:  da 00 40 00  ld  [ %g1 ], %o5
a002e2b4:  80 8b 60 01  btst  1, %o5
a002e2b8:  02 80 00 3e  be  0xa002e3b0
a002e2bc:  92 16 21 58  or  %i0, 0x158, %o1
a002e2c0:  d0 02 40 00  ld  [ %o1 ], %o0
a002e2c4:  80 8a 20 10  btst  0x10, %o0
a002e2c8:  12 80 00 1d  bne  0xa002e33c
a002e2cc:  01 00 00 00  nop
a002e2d0:  7f ff fc ae  call  0xa002d588
a002e2d4:  b0 16 22 1c  or  %i0, 0x21c, %i0
a002e2d8:  a1 2a 20 10  sll  %o0, 0x10, %l0
a002e2dc:  7f ff fc ae  call  0xa002d594
a002e2e0:  91 34 20 10  srl  %l0, 0x10, %o0
a002e2e4:  99 2a 20 10  sll  %o0, 0x10, %o4
a002e2e8:  97 33 20 10  srl  %o4, 0x10, %o3
a002e2ec:  80 a2 e0 31  cmp  %o3, 0x31
a002e2f0:  18 80 00 06  bgu  0xa002e308
a002e2f4:  1f 33 c0 3b  sethi  %hi(0xcf00ec00), %o7
a002e2f8:  d4 06 00 00  ld  [ %i0 ], %o2
a002e2fc:  80 8a a0 80  btst  0x80, %o2
a002e300:  12 bf ff f7  bne  0xa002e2dc
a002e304:  01 00 00 00  nop
a002e308:  b0 13 e2 1c  or  %o7, 0x21c, %i0
a002e30c:  7f ff fc a2  call  0xa002d594
a002e310:  91 34 20 10  srl  %l0, 0x10, %o0
a002e314:  91 2a 20 10  sll  %o0, 0x10, %o0
a002e318:  83 32 20 10  srl  %o0, 0x10, %g1
a002e31c:  80 a0 60 63  cmp  %g1, 0x63
a002e320:  18 80 00 26  bgu  0xa002e3b8
a002e324:  01 00 00 00  nop
a002e328:  da 06 00 00  ld  [ %i0 ], %o5
a002e32c:  80 8b 60 80  btst  0x80, %o5
a002e330:  02 bf ff f7  be  0xa002e30c
a002e334:  01 00 00 00  nop
a002e338:  30 80 00 20  b,a   0xa002e3b8
a002e33c:  7f ff fc 93  call  0xa002d588
a002e340:  01 00 00 00  nop
a002e344:  13 33 c0 3b  sethi  %hi(0xcf00ec00), %o1
a002e348:  a1 2a 20 10  sll  %o0, 0x10, %l0
a002e34c:  b0 12 62 1c  or  %o1, 0x21c, %i0
a002e350:  7f ff fc 91  call  0xa002d594
a002e354:  91 34 20 10  srl  %l0, 0x10, %o0
a002e358:  99 2a 20 10  sll  %o0, 0x10, %o4
a002e35c:  97 33 20 10  srl  %o4, 0x10, %o3
a002e360:  80 a2 e0 31  cmp  %o3, 0x31
a002e364:  18 80 00 06  bgu  0xa002e37c
a002e368:  1f 33 c0 3b  sethi  %hi(0xcf00ec00), %o7
a002e36c:  d4 06 00 00  ld  [ %i0 ], %o2
a002e370:  80 8a a0 80  btst  0x80, %o2
a002e374:  02 bf ff f7  be  0xa002e350
a002e378:  01 00 00 00  nop
a002e37c:  b0 13 e2 1c  or  %o7, 0x21c, %i0
a002e380:  7f ff fc 85  call  0xa002d594
a002e384:  91 34 20 10  srl  %l0, 0x10, %o0
a002e388:  91 2a 20 10  sll  %o0, 0x10, %o0
a002e38c:  83 32 20 10  srl  %o0, 0x10, %g1
a002e390:  80 a0 60 63  cmp  %g1, 0x63
a002e394:  18 80 00 09  bgu  0xa002e3b8
a002e398:  01 00 00 00  nop
a002e39c:  da 06 00 00  ld  [ %i0 ], %o5
a002e3a0:  80 8b 60 80  btst  0x80, %o5
a002e3a4:  12 bf ff f7  bne  0xa002e380
a002e3a8:  01 00 00 00  nop
a002e3ac:  30 80 00 03  b,a   0xa002e3b8
a002e3b0:  7f ff fb 7c  call  0xa002d1a0
a002e3b4:  91 e8 20 28  restore  %g0, 0x28, %o0
a002e3b8:  01 00 00 00  nop
a002e3bc:  81 c7 e0 08  ret
a002e3c0:  81 e8 00 00  restore
