# leon2s DRV_HDMI21_RXDetect_FSM_LTS_4 0xa00983ec-0xa0098468 (124 bytes)
a00983ec:  9d e3 bf 98  save  %sp, -104, %sp
a00983f0:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00983f4:  03 2a 01 f5  sethi  %hi(0xa807d400), %g1
a00983f8:  9a 5e 20 b0  smul  %i0, 0xb0, %o5
a00983fc:  82 10 62 80  or  %g1, 0x280, %g1
a0098400:  27 2a 01 f5  sethi  %hi(0xa807d400), %l3
a0098404:  a2 03 40 01  add  %o5, %g1, %l1
a0098408:  a4 14 e2 48  or  %l3, 0x248, %l2
a009840c:  a1 2e 20 02  sll  %i0, 2, %l0
a0098410:  da 04 80 10  ld  [ %l2 + %l0 ], %o5
a0098414:  c2 04 60 30  ld  [ %l1 + 0x30 ], %g1
a0098418:  80 a3 40 01  cmp  %o5, %g1
a009841c:  02 80 00 0d  be  0xa0098450
a0098420:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a0098424:  c2 00 62 34  ld  [ %g1 + 0x234 ], %g1	! 0xa8078634
a0098428:  11 28 01 9e  sethi  %hi(0xa0067800), %o0
a009842c:  13 28 02 d0  sethi  %hi(0xa00b4000), %o1
a0098430:  80 88 68 00  btst  0x800, %g1
a0098434:  90 12 20 c8  or  %o0, 0xc8, %o0
a0098438:  02 80 00 04  be  0xa0098448
a009843c:  92 12 62 d8  or  %o1, 0x2d8, %o1
a0098440:  7f ff 6b 01  call  0xa0073044
a0098444:  01 00 00 00  nop
a0098448:  c2 04 80 10  ld  [ %l2 + %l0 ], %g1
a009844c:  c2 24 60 30  st  %g1, [ %l1 + 0x30 ]
a0098450:  9b 2e 20 02  sll  %i0, 2, %o5
a0098454:  98 14 e2 48  or  %l3, 0x248, %o4
a0098458:  82 10 20 07  mov  7, %g1
a009845c:  c2 23 00 0d  st  %g1, [ %o4 + %o5 ]
a0098460:  81 c7 e0 08  ret
a0098464:  91 e8 20 00  restore  %g0, 0, %o0
