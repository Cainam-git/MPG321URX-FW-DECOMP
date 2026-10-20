# leon2m FUN_a015d288 0xa015d288-0xa015d3b0 (296 bytes)
a015d288:  9d e3 bf 98  save  %sp, -104, %sp
a015d28c:  a4 10 00 18  mov  %i0, %l2
a015d290:  9a 8e a0 03  andcc  %i2, 3, %o5
a015d294:  12 80 00 2d  bne  0xa015d348
a015d298:  b0 10 00 19  mov  %i1, %i0
a015d29c:  b5 3e a0 02  sra  %i2, 2, %i2
a015d2a0:  80 a6 a0 00  cmp  %i2, 0
a015d2a4:  02 80 00 41  be  0xa015d3a8
a015d2a8:  01 00 00 00  nop
a015d2ac:  e2 04 a0 48  ld  [ %l2 + 0x48 ], %l1
a015d2b0:  80 a4 60 00  cmp  %l1, 0
a015d2b4:  02 80 00 37  be  0xa015d390
a015d2b8:  90 10 00 12  mov  %l2, %o0
a015d2bc:  80 8e a0 01  btst  1, %i2
a015d2c0:  94 10 00 11  mov  %l1, %o2
a015d2c4:  92 10 00 18  mov  %i0, %o1
a015d2c8:  90 10 00 12  mov  %l2, %o0
a015d2cc:  12 80 00 12  bne  0xa015d314
a015d2d0:  b5 3e a0 01  sra  %i2, 1, %i2
a015d2d4:  92 10 00 11  mov  %l1, %o1
a015d2d8:  94 10 00 11  mov  %l1, %o2
a015d2dc:  80 a6 a0 00  cmp  %i2, 0
a015d2e0:  02 80 00 32  be  0xa015d3a8
a015d2e4:  90 10 00 12  mov  %l2, %o0
a015d2e8:  c2 04 40 00  ld  [ %l1 ], %g1
a015d2ec:  80 a0 60 00  cmp  %g1, 0
a015d2f0:  02 80 00 21  be  0xa015d374
a015d2f4:  01 00 00 00  nop
a015d2f8:  a2 10 00 01  mov  %g1, %l1
a015d2fc:  80 8e a0 01  btst  1, %i2
a015d300:  94 10 00 11  mov  %l1, %o2
a015d304:  92 10 00 18  mov  %i0, %o1
a015d308:  90 10 00 12  mov  %l2, %o0
a015d30c:  02 bf ff f2  be  0xa015d2d4
a015d310:  b5 3e a0 01  sra  %i2, 1, %i2
a015d314:  7f ff ff 56  call  0xa015d06c
a015d318:  01 00 00 00  nop
a015d31c:  a0 10 00 08  mov  %o0, %l0
a015d320:  92 10 00 18  mov  %i0, %o1
a015d324:  7f ff fe 81  call  0xa015cd28
a015d328:  90 10 00 12  mov  %l2, %o0
a015d32c:  b0 10 00 10  mov  %l0, %i0
a015d330:  92 10 00 11  mov  %l1, %o1
a015d334:  94 10 00 11  mov  %l1, %o2
a015d338:  80 a6 a0 00  cmp  %i2, 0
a015d33c:  12 bf ff eb  bne  0xa015d2e8
a015d340:  90 10 00 12  mov  %l2, %o0
a015d344:  30 80 00 19  b,a   0xa015d3a8
a015d348:  03 00 06 a1  sethi  %hi(0x1a8400), %g1
a015d34c:  82 10 62 40  or  %g1, 0x240, %g1	! 0x1a8640
a015d350:  9b 2b 60 02  sll  %o5, 2, %o5
a015d354:  9a 03 40 01  add  %o5, %g1, %o5
a015d358:  92 10 00 19  mov  %i1, %o1
a015d35c:  d4 03 7f fc  ld  [ %o5 + -4 ], %o2
a015d360:  90 10 00 12  mov  %l2, %o0
a015d364:  7f ff fe 7c  call  0xa015cd54
a015d368:  96 10 20 00  clr  %o3
a015d36c:  10 bf ff cc  b  0xa015d29c
a015d370:  b0 10 00 08  mov  %o0, %i0
a015d374:  7f ff ff 3e  call  0xa015d06c
a015d378:  01 00 00 00  nop
a015d37c:  d0 24 40 00  st  %o0, [ %l1 ]
a015d380:  82 10 00 08  mov  %o0, %g1
a015d384:  c0 22 00 00  clr  [ %o0 ]
a015d388:  10 bf ff dd  b  0xa015d2fc
a015d38c:  a2 10 00 01  mov  %g1, %l1
a015d390:  7f ff ff 2e  call  0xa015d048
a015d394:  92 10 22 71  mov  0x271, %o1
a015d398:  d0 24 a0 48  st  %o0, [ %l2 + 0x48 ]
a015d39c:  a2 10 00 08  mov  %o0, %l1
a015d3a0:  10 bf ff c7  b  0xa015d2bc
a015d3a4:  c0 22 00 00  clr  [ %o0 ]
a015d3a8:  81 c7 e0 08  ret
a015d3ac:  81 e8 00 00  restore
