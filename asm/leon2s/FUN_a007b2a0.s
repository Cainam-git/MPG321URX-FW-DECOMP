# leon2s FUN_a007b2a0 0xa007b2a0-0xa007b394 (244 bytes)
a007b2a0:  9d e3 bf 98  save  %sp, -104, %sp
a007b2a4:  b0 0e 20 ff  and  %i0, 0xff, %i0
a007b2a8:  82 06 00 18  add  %i0, %i0, %g1
a007b2ac:  82 00 40 18  add  %g1, %i0, %g1
a007b2b0:  1b 2a 01 f3  sethi  %hi(0xa807cc00), %o5
a007b2b4:  83 28 60 03  sll  %g1, 3, %g1
a007b2b8:  9a 13 60 64  or  %o5, 0x64, %o5
a007b2bc:  82 00 40 0d  add  %g1, %o5, %g1
a007b2c0:  c2 08 60 07  ldub  [ %g1 + 7 ], %g1
a007b2c4:  80 a0 60 01  cmp  %g1, 1
a007b2c8:  90 10 00 18  mov  %i0, %o0
a007b2cc:  02 80 00 30  be  0xa007b38c
a007b2d0:  82 10 20 00  clr  %g1
a007b2d4:  7f ff e7 aa  call  0xa007517c
a007b2d8:  01 00 00 00  nop
a007b2dc:  80 8a 20 ff  btst  0xff, %o0
a007b2e0:  02 80 00 09  be  0xa007b304
a007b2e4:  82 10 20 00  clr  %g1
a007b2e8:  80 a6 20 02  cmp  %i0, 2
a007b2ec:  02 80 00 28  be  0xa007b38c
a007b2f0:  90 10 00 18  mov  %i0, %o0
a007b2f4:  7f ff fe e8  call  0xa007ae94
a007b2f8:  01 00 00 00  nop
a007b2fc:  10 80 00 24  b  0xa007b38c
a007b300:  82 0a 20 ff  and  %o0, 0xff, %g1
a007b304:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a007b308:  82 10 61 80  or  %g1, 0x180, %g1	! 0xa8078980
a007b30c:  c2 08 40 18  ldub  [ %g1 + %i0 ], %g1
a007b310:  80 a0 60 01  cmp  %g1, 1
a007b314:  12 80 00 06  bne  0xa007b32c
a007b318:  90 10 00 18  mov  %i0, %o0
a007b31c:  03 2a 01 d8  sethi  %hi(0xa8076000), %g1
a007b320:  82 10 61 98  or  %g1, 0x198, %g1	! 0xa8076198
a007b324:  10 80 00 1a  b  0xa007b38c
a007b328:  c2 08 40 18  ldub  [ %g1 + %i0 ], %g1
a007b32c:  7f ff e0 7d  call  0xa0073520
a007b330:  01 00 00 00  nop
a007b334:  80 8a 20 ff  btst  0xff, %o0
a007b338:  82 1e 20 02  xor  %i0, 2, %g1
a007b33c:  92 10 22 e1  mov  0x2e1, %o1
a007b340:  02 80 00 0e  be  0xa007b378
a007b344:  90 10 00 18  mov  %i0, %o0
a007b348:  80 a0 00 01  cmp  %g0, %g1
a007b34c:  82 40 20 00  addx  %g0, 0, %g1
a007b350:  1b 2a 01 f6  sethi  %hi(0xa807d800), %o5
a007b354:  9a 13 63 00  or  %o5, 0x300, %o5	! 0xa807db00
a007b358:  82 58 60 34  smul  %g1, 0x34, %g1
a007b35c:  82 00 40 0d  add  %g1, %o5, %g1
a007b360:  d2 00 60 0c  ld  [ %g1 + 0xc ], %o1
a007b364:  92 02 60 60  add  %o1, 0x60, %o1
a007b368:  40 00 b0 28  call  0xa00a7408
a007b36c:  90 10 20 09  mov  9, %o0
a007b370:  10 80 00 06  b  0xa007b388
a007b374:  80 a0 00 08  cmp  %g0, %o0
a007b378:  40 00 ac 81  call  0xa00a657c
a007b37c:  01 00 00 00  nop
a007b380:  90 0a 20 02  and  %o0, 2, %o0
a007b384:  80 a0 00 08  cmp  %g0, %o0
a007b388:  82 40 20 00  addx  %g0, 0, %g1
a007b38c:  81 c7 e0 08  ret
a007b390:  91 e8 00 01  restore  %g0, %g1, %o0
