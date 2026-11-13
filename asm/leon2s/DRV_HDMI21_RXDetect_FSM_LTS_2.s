# leon2s DRV_HDMI21_RXDetect_FSM_LTS_2 0xa0098330-0xa00983ec (188 bytes)
a0098330:  9d e3 bf 98  save  %sp, -104, %sp
a0098334:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0098338:  03 2a 01 f5  sethi  %hi(0xa807d400), %g1
a009833c:  9a 5e 20 b0  smul  %i0, 0xb0, %o5
a0098340:  82 10 62 80  or  %g1, 0x280, %g1
a0098344:  25 2a 01 f5  sethi  %hi(0xa807d400), %l2
a0098348:  a2 03 40 01  add  %o5, %g1, %l1
a009834c:  a6 14 a2 48  or  %l2, 0x248, %l3
a0098350:  a1 2e 20 02  sll  %i0, 2, %l0
a0098354:  da 04 60 30  ld  [ %l1 + 0x30 ], %o5
a0098358:  c2 04 c0 10  ld  [ %l3 + %l0 ], %g1
a009835c:  80 a0 40 0d  cmp  %g1, %o5
a0098360:  02 80 00 0e  be  0xa0098398
a0098364:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a0098368:  c2 00 62 34  ld  [ %g1 + 0x234 ], %g1	! 0xa8078634
a009836c:  13 28 02 d0  sethi  %hi(0xa00b4000), %o1
a0098370:  11 28 01 a7  sethi  %hi(0xa0069c00), %o0
a0098374:  80 88 68 00  btst  0x800, %g1
a0098378:  92 12 62 b8  or  %o1, 0x2b8, %o1
a009837c:  90 12 20 10  or  %o0, 0x10, %o0
a0098380:  02 80 00 04  be  0xa0098390
a0098384:  94 10 00 18  mov  %i0, %o2
a0098388:  7f ff 6b 2f  call  0xa0073044
a009838c:  01 00 00 00  nop
a0098390:  c2 04 c0 10  ld  [ %l3 + %l0 ], %g1
a0098394:  c2 24 60 30  st  %g1, [ %l1 + 0x30 ]
a0098398:  1b 2a 01 f6  sethi  %hi(0xa807d800), %o5
a009839c:  9a 13 63 00  or  %o5, 0x300, %o5	! 0xa807db00
a00983a0:  82 5e 20 34  smul  %i0, 0x34, %g1
a00983a4:  82 00 40 0d  add  %g1, %o5, %g1
a00983a8:  d2 00 60 18  ld  [ %g1 + 0x18 ], %o1
a00983ac:  92 02 60 a0  add  %o1, 0xa0, %o1
a00983b0:  40 00 3b ff  call  0xa00a73ac
a00983b4:  90 10 20 16  mov  0x16, %o0
a00983b8:  7f ff ff d2  call  0xa0098300
a00983bc:  90 10 00 18  mov  %i0, %o0
a00983c0:  80 8a 20 ff  btst  0xff, %o0
a00983c4:  98 14 a2 48  or  %l2, 0x248, %o4
a00983c8:  02 80 00 05  be  0xa00983dc
a00983cc:  91 2e 20 02  sll  %i0, 2, %o0
a00983d0:  82 10 20 07  mov  7, %g1
a00983d4:  10 80 00 04  b  0xa00983e4
a00983d8:  c2 23 00 08  st  %g1, [ %o4 + %o0 ]
a00983dc:  82 10 20 03  mov  3, %g1
a00983e0:  c2 23 00 08  st  %g1, [ %o4 + %o0 ]
a00983e4:  81 c7 e0 08  ret
a00983e8:  91 e8 20 00  restore  %g0, 0, %o0
