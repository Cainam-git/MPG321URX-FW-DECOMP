# leon2s FUN_a008d2e0 0xa008d2e0-0xa008d490 (432 bytes)
a008d2e0:  9d e3 bf 98  save  %sp, -104, %sp
a008d2e4:  21 33 c0 48  sethi  %hi(0xcf012000), %l0
a008d2e8:  9a 14 21 c0  or  %l0, 0x1c0, %o5	! 0xcf0121c0
a008d2ec:  d4 03 40 00  ld  [ %o5 ], %o2
a008d2f0:  98 14 21 e0  or  %l0, 0x1e0, %o4
a008d2f4:  d6 03 00 00  ld  [ %o4 ], %o3
a008d2f8:  82 10 20 35  mov  0x35, %g1
a008d2fc:  c2 23 40 00  st  %g1, [ %o5 ]
a008d300:  82 10 20 80  mov  0x80, %g1
a008d304:  c2 23 00 00  st  %g1, [ %o4 ]
a008d308:  82 14 22 28  or  %l0, 0x228, %g1
a008d30c:  c0 20 40 00  clr  [ %g1 ]
a008d310:  82 14 22 40  or  %l0, 0x240, %g1
a008d314:  c0 20 40 00  clr  [ %g1 ]
a008d318:  82 14 22 44  or  %l0, 0x244, %g1
a008d31c:  c0 20 40 00  clr  [ %g1 ]
a008d320:  9a 14 22 4c  or  %l0, 0x24c, %o5
a008d324:  82 10 20 02  mov  2, %g1
a008d328:  c2 23 40 00  st  %g1, [ %o5 ]
a008d32c:  a0 14 22 48  or  %l0, 0x248, %l0
a008d330:  82 10 20 61  mov  0x61, %g1
a008d334:  ae 10 00 0a  mov  %o2, %l7
a008d338:  ba 10 00 0b  mov  %o3, %i5
a008d33c:  c2 24 00 00  st  %g1, [ %l0 ]
a008d340:  40 00 90 b3  call  0xa00b160c
a008d344:  90 10 20 05  mov  5, %o0
a008d348:  a2 10 20 60  mov  0x60, %l1
a008d34c:  90 10 20 01  mov  1, %o0
a008d350:  e2 24 00 00  st  %l1, [ %l0 ]
a008d354:  40 00 90 ae  call  0xa00b160c
a008d358:  01 00 00 00  nop
a008d35c:  82 10 20 40  mov  0x40, %g1	! 0x40
a008d360:  c2 24 00 00  st  %g1, [ %l0 ]
a008d364:  40 00 90 aa  call  0xa00b160c
a008d368:  90 10 20 01  mov  1, %o0
a008d36c:  90 10 20 01  mov  1, %o0
a008d370:  e2 24 00 00  st  %l1, [ %l0 ]
a008d374:  40 00 90 a6  call  0xa00b160c
a008d378:  01 00 00 00  nop
a008d37c:  82 10 20 70  mov  0x70, %g1	! 0x70
a008d380:  91 2e 20 10  sll  %i0, 0x10, %o0
a008d384:  c2 24 00 00  st  %g1, [ %l0 ]
a008d388:  7f ff ff 4c  call  0xa008d0b8
a008d38c:  91 32 20 10  srl  %o0, 0x10, %o0
a008d390:  90 0a 20 ff  and  %o0, 0xff, %o0
a008d394:  80 a2 20 01  cmp  %o0, 1
a008d398:  aa 10 00 19  mov  %i1, %l5
a008d39c:  12 80 00 03  bne  0xa008d3a8
a008d3a0:  ac 10 20 00  clr  %l6
a008d3a4:  ac 10 20 01  mov  1, %l6
a008d3a8:  83 2e 60 10  sll  %i1, 0x10, %g1
a008d3ac:  80 a0 60 00  cmp  %g1, 0
a008d3b0:  02 80 00 2f  be  0xa008d46c
a008d3b4:  9a 10 20 00  clr  %o5
a008d3b8:  03 33 c0 48  sethi  %hi(0xcf012000), %g1
a008d3bc:  96 10 62 40  or  %g1, 0x240, %o3	! 0xcf012240
a008d3c0:  94 10 62 44  or  %g1, 0x244, %o2
a008d3c4:  92 10 62 00  or  %g1, 0x200, %o1
a008d3c8:  82 06 00 0d  add  %i0, %o5, %g1
a008d3cc:  a1 28 60 10  sll  %g1, 0x10, %l0
a008d3d0:  a5 34 20 10  srl  %l0, 0x10, %l2
a008d3d4:  a6 03 60 01  add  %o5, 1, %l3
a008d3d8:  b3 2b 60 10  sll  %o5, 0x10, %i1
a008d3dc:  a2 10 00 01  mov  %g1, %l1
a008d3e0:  90 10 00 12  mov  %l2, %o0
a008d3e4:  99 34 20 18  srl  %l0, 0x18, %o4
a008d3e8:  80 8d a0 ff  btst  0xff, %l6
a008d3ec:  9b 36 60 10  srl  %i1, 0x10, %o5
a008d3f0:  82 08 60 ff  and  %g1, 0xff, %g1
a008d3f4:  02 80 00 16  be  0xa008d44c
a008d3f8:  a9 2d 60 10  sll  %l5, 0x10, %l4
a008d3fc:  7f ff ff 77  call  0xa008d1d8
a008d400:  01 00 00 00  nop
a008d404:  03 33 c0 48  sethi  %hi(0xcf012000), %g1
a008d408:  9e 10 62 40  or  %g1, 0x240, %o7	! 0xcf012240
a008d40c:  94 10 62 44  or  %g1, 0x244, %o2
a008d410:  92 10 62 00  or  %g1, 0x200, %o1
a008d414:  82 0a 20 ff  and  %o0, 0xff, %g1
a008d418:  96 0c 60 ff  and  %l1, 0xff, %o3
a008d41c:  99 34 20 18  srl  %l0, 0x18, %o4
a008d420:  90 10 00 12  mov  %l2, %o0
a008d424:  80 a0 60 01  cmp  %g1, 1
a008d428:  12 80 00 07  bne  0xa008d444
a008d42c:  9b 36 60 10  srl  %i1, 0x10, %o5
a008d430:  7f ff ff 94  call  0xa008d280
a008d434:  01 00 00 00  nop
a008d438:  83 36 60 10  srl  %i1, 0x10, %g1
a008d43c:  10 80 00 08  b  0xa008d45c
a008d440:  d0 2e 80 01  stb  %o0, [ %i2 + %g1 ]
a008d444:  d6 23 c0 00  st  %o3, [ %o7 ]
a008d448:  30 80 00 02  b,a   0xa008d450
a008d44c:  c2 22 c0 00  st  %g1, [ %o3 ]
a008d450:  d8 22 80 00  st  %o4, [ %o2 ]
a008d454:  c2 02 40 00  ld  [ %o1 ], %g1
a008d458:  c2 2e 80 0d  stb  %g1, [ %i2 + %o5 ]
a008d45c:  83 2c e0 10  sll  %l3, 0x10, %g1
a008d460:  80 a5 00 01  cmp  %l4, %g1
a008d464:  18 bf ff d5  bgu  0xa008d3b8
a008d468:  9a 10 00 13  mov  %l3, %o5
a008d46c:  1b 33 c0 48  sethi  %hi(0xcf012000), %o5
a008d470:  82 13 61 c0  or  %o5, 0x1c0, %g1	! 0xcf0121c0
a008d474:  98 0d e0 ff  and  %l7, 0xff, %o4
a008d478:  d8 20 40 00  st  %o4, [ %g1 ]
a008d47c:  9a 13 61 e0  or  %o5, 0x1e0, %o5
a008d480:  82 0f 60 ff  and  %i5, 0xff, %g1
a008d484:  c2 23 40 00  st  %g1, [ %o5 ]
a008d488:  81 c7 e0 08  ret
a008d48c:  81 e8 00 00  restore
