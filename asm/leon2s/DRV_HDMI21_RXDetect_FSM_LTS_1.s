# leon2s DRV_HDMI21_RXDetect_FSM_LTS_1 0xa0098240-0xa0098300 (192 bytes)
a0098240:  9d e3 bf 98  save  %sp, -104, %sp
a0098244:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0098248:  7f ff f7 e8  call  0xa00961e8
a009824c:  90 10 00 18  mov  %i0, %o0
a0098250:  03 2a 01 f5  sethi  %hi(0xa807d400), %g1
a0098254:  9a 5e 20 b0  smul  %i0, 0xb0, %o5
a0098258:  82 10 62 80  or  %g1, 0x280, %g1
a009825c:  29 2a 01 f5  sethi  %hi(0xa807d400), %l4
a0098260:  a2 03 40 01  add  %o5, %g1, %l1
a0098264:  a4 15 22 48  or  %l4, 0x248, %l2
a0098268:  a1 2e 20 02  sll  %i0, 2, %l0
a009826c:  da 04 60 30  ld  [ %l1 + 0x30 ], %o5
a0098270:  c2 04 80 10  ld  [ %l2 + %l0 ], %g1
a0098274:  80 a0 40 0d  cmp  %g1, %o5
a0098278:  02 80 00 0e  be  0xa00982b0
a009827c:  a6 10 00 08  mov  %o0, %l3
a0098280:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a0098284:  c2 00 62 34  ld  [ %g1 + 0x234 ], %g1	! 0xa8078634
a0098288:  13 28 02 d0  sethi  %hi(0xa00b4000), %o1
a009828c:  11 28 01 9e  sethi  %hi(0xa0067800), %o0
a0098290:  80 88 68 00  btst  0x800, %g1
a0098294:  92 12 62 98  or  %o1, 0x298, %o1
a0098298:  02 80 00 04  be  0xa00982a8
a009829c:  90 12 20 68  or  %o0, 0x68, %o0
a00982a0:  7f ff 6b 69  call  0xa0073044
a00982a4:  01 00 00 00  nop
a00982a8:  c2 04 80 10  ld  [ %l2 + %l0 ], %g1
a00982ac:  c2 24 60 30  st  %g1, [ %l1 + 0x30 ]
a00982b0:  82 0c e0 ff  and  %l3, 0xff, %g1
a00982b4:  9a 00 40 01  add  %g1, %g1, %o5
a00982b8:  9a 03 40 01  add  %o5, %g1, %o5
a00982bc:  03 2a 01 f3  sethi  %hi(0xa807cc00), %g1
a00982c0:  82 10 60 64  or  %g1, 0x64, %g1	! 0xa807cc64
a00982c4:  9b 2b 60 03  sll  %o5, 3, %o5
a00982c8:  9a 03 40 01  add  %o5, %g1, %o5
a00982cc:  11 28 01 a6  sethi  %hi(0xa0069800), %o0
a00982d0:  c2 0b 60 06  ldub  [ %o5 + 6 ], %g1
a00982d4:  80 a0 60 01  cmp  %g1, 1
a00982d8:  12 80 00 08  bne  0xa00982f8
a00982dc:  90 12 23 e8  or  %o0, 0x3e8, %o0
a00982e0:  7f ff 6b 59  call  0xa0073044
a00982e4:  01 00 00 00  nop
a00982e8:  98 15 22 48  or  %l4, 0x248, %o4
a00982ec:  9b 2e 20 02  sll  %i0, 2, %o5
a00982f0:  82 10 20 02  mov  2, %g1
a00982f4:  c2 23 00 0d  st  %g1, [ %o4 + %o5 ]
a00982f8:  81 c7 e0 08  ret
a00982fc:  91 e8 20 00  restore  %g0, 0, %o0
