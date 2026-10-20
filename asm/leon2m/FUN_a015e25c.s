# leon2m FUN_a015e25c 0xa015e25c-0xa015e3ec (400 bytes)
a015e25c:  9d e3 bf 98  save  %sp, -104, %sp
a015e260:  a2 10 00 18  mov  %i0, %l1
a015e264:  80 a6 60 00  cmp  %i1, 0
a015e268:  02 80 00 5f  be  0xa015e3e4
a015e26c:  90 10 20 00  clr  %o0
a015e270:  7f ff f4 e1  call  0xa015b5f4
a015e274:  01 00 00 00  nop
a015e278:  c2 16 60 0c  lduh  [ %i1 + 0xc ], %g1
a015e27c:  80 88 62 00  btst  0x200, %g1
a015e280:  02 80 00 3b  be  0xa015e36c
a015e284:  01 00 00 00  nop
a015e288:  21 2a 00 aa  sethi  %hi(0xa802a800), %l0
a015e28c:  d0 04 22 18  ld  [ %l0 + 0x218 ], %o0	! 0xa802aa18
a015e290:  80 a2 20 00  cmp  %o0, 0
a015e294:  22 80 00 07  be,a   0xa015e2b0
a015e298:  c2 16 60 0c  lduh  [ %i1 + 0xc ], %g1
a015e29c:  c2 02 20 38  ld  [ %o0 + 0x38 ], %g1
a015e2a0:  80 a0 60 00  cmp  %g1, 0
a015e2a4:  02 80 00 39  be  0xa015e388
a015e2a8:  01 00 00 00  nop
a015e2ac:  c2 16 60 0c  lduh  [ %i1 + 0xc ], %g1
a015e2b0:  83 28 60 10  sll  %g1, 0x10, %g1
a015e2b4:  80 a0 60 00  cmp  %g1, 0
a015e2b8:  12 80 00 09  bne  0xa015e2dc
a015e2bc:  83 30 60 10  srl  %g1, 0x10, %g1
a015e2c0:  80 88 62 00  btst  0x200, %g1
a015e2c4:  02 80 00 2e  be  0xa015e37c
a015e2c8:  01 00 00 00  nop
a015e2cc:  7f ff f4 d0  call  0xa015b60c
a015e2d0:  01 00 00 00  nop
a015e2d4:  10 80 00 44  b  0xa015e3e4
a015e2d8:  90 10 20 00  clr  %o0	! 0x0
a015e2dc:  80 88 60 08  btst  8, %g1
a015e2e0:  12 80 00 35  bne  0xa015e3b4
a015e2e4:  b0 10 20 00  clr  %i0
a015e2e8:  c2 06 60 2c  ld  [ %i1 + 0x2c ], %g1
a015e2ec:  80 a0 60 00  cmp  %g1, 0
a015e2f0:  12 80 00 2a  bne  0xa015e398
a015e2f4:  01 00 00 00  nop
a015e2f8:  c2 16 60 0c  lduh  [ %i1 + 0xc ], %g1
a015e2fc:  80 88 60 80  btst  0x80, %g1
a015e300:  12 80 00 31  bne  0xa015e3c4
a015e304:  90 10 00 11  mov  %l1, %o0
a015e308:  d2 06 60 30  ld  [ %i1 + 0x30 ], %o1
a015e30c:  80 a2 60 00  cmp  %o1, 0
a015e310:  22 80 00 0a  be,a   0xa015e338
a015e314:  d2 06 60 44  ld  [ %i1 + 0x44 ], %o1
a015e318:  82 06 60 40  add  %i1, 0x40, %g1
a015e31c:  80 a2 40 01  cmp  %o1, %g1
a015e320:  22 80 00 05  be,a   0xa015e334
a015e324:  c0 26 60 30  clr  [ %i1 + 0x30 ]
a015e328:  7f ff f5 66  call  0xa015b8c0
a015e32c:  d0 04 22 18  ld  [ %l0 + 0x218 ], %o0
a015e330:  c0 26 60 30  clr  [ %i1 + 0x30 ]
a015e334:  d2 06 60 44  ld  [ %i1 + 0x44 ], %o1
a015e338:  80 a2 60 00  cmp  %o1, 0
a015e33c:  12 80 00 26  bne  0xa015e3d4
a015e340:  01 00 00 00  nop
a015e344:  a0 06 60 58  add  %i1, 0x58, %l0
a015e348:  c0 36 60 0c  clrh  [ %i1 + 0xc ]
a015e34c:  40 00 01 c7  call  0xa015ea68
a015e350:  90 10 00 10  mov  %l0, %o0
a015e354:  40 00 01 a1  call  0xa015e9d8
a015e358:  90 10 00 10  mov  %l0, %o0
a015e35c:  7f ff f4 ac  call  0xa015b60c
a015e360:  01 00 00 00  nop
a015e364:  10 80 00 20  b  0xa015e3e4
a015e368:  90 10 00 18  mov  %i0, %o0
a015e36c:  40 00 01 a7  call  0xa015ea08
a015e370:  90 06 60 58  add  %i1, 0x58, %o0
a015e374:  10 bf ff c6  b  0xa015e28c
a015e378:  21 2a 00 aa  sethi  %hi(0xa802a800), %l0
a015e37c:  40 00 01 bb  call  0xa015ea68
a015e380:  90 06 60 58  add  %i1, 0x58, %o0
a015e384:  30 bf ff d2  b,a   0xa015e2cc
a015e388:  7f ff f4 74  call  0xa015b558
a015e38c:  01 00 00 00  nop
a015e390:  10 bf ff c8  b  0xa015e2b0
a015e394:  c2 16 60 0c  lduh  [ %i1 + 0xc ], %g1
a015e398:  9f c0 40 00  call  %g1
a015e39c:  d0 06 60 1c  ld  [ %i1 + 0x1c ], %o0
a015e3a0:  80 a2 20 00  cmp  %o0, 0
a015e3a4:  26 bf ff d5  bl,a   0xa015e2f8
a015e3a8:  b0 10 3f ff  mov  -1, %i0
a015e3ac:  10 bf ff d4  b  0xa015e2fc
a015e3b0:  c2 16 60 0c  lduh  [ %i1 + 0xc ], %g1
a015e3b4:  7f ff f3 d3  call  0xa015b300
a015e3b8:  90 10 00 19  mov  %i1, %o0
a015e3bc:  10 bf ff cb  b  0xa015e2e8
a015e3c0:  b0 10 00 08  mov  %o0, %i0
a015e3c4:  7f ff f5 3f  call  0xa015b8c0
a015e3c8:  d2 06 60 10  ld  [ %i1 + 0x10 ], %o1
a015e3cc:  10 bf ff d0  b  0xa015e30c
a015e3d0:  d2 06 60 30  ld  [ %i1 + 0x30 ], %o1
a015e3d4:  7f ff f5 3b  call  0xa015b8c0
a015e3d8:  d0 04 22 18  ld  [ %l0 + 0x218 ], %o0
a015e3dc:  10 bf ff da  b  0xa015e344
a015e3e0:  c0 26 60 44  clr  [ %i1 + 0x44 ]
a015e3e4:  81 c7 e0 08  ret
a015e3e8:  91 e8 00 08  restore  %g0, %o0, %o0
