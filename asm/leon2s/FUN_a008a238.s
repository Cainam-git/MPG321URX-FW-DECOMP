# leon2s FUN_a008a238 0xa008a238-0xa008a470 (568 bytes)
a008a238:  82 0a 20 ff  and  %o0, 0xff, %g1
a008a23c:  80 a0 60 04  cmp  %g1, 4
a008a240:  18 80 00 8a  bgu  0xa008a468
a008a244:  1b 28 02 28  sethi  %hi(0xa008a000), %o5
a008a248:  83 28 60 02  sll  %g1, 2, %g1
a008a24c:  9a 13 62 24  or  %o5, 0x224, %o5
a008a250:  c2 03 40 01  ld  [ %o5 + %g1 ], %g1
a008a254:  81 c0 40 00  jmp  %g1
a008a258:  01 00 00 00  nop
a008a25c:  03 33 c0 f2  sethi  %hi(0xcf03c800), %g1
a008a260:  98 10 60 40  or  %g1, 0x40, %o4	! 0xcf03c840
a008a264:  03 00 00 3f  sethi  %hi(0xfc00), %g1
a008a268:  94 10 63 ff  or  %g1, 0x3ff, %o2	! 0xffff
a008a26c:  9a 10 3f ff  mov  -1, %o5
a008a270:  96 10 20 02  mov  2, %o3
a008a274:  c2 03 00 00  ld  [ %o4 ], %g1
a008a278:  80 a0 60 01  cmp  %g1, 1
a008a27c:  32 80 00 02  bne,a   0xa008a284
a008a280:  d6 23 00 00  st  %o3, [ %o4 ]
a008a284:  c2 03 00 00  ld  [ %o4 ], %g1
a008a288:  80 a0 60 02  cmp  %g1, 2
a008a28c:  02 80 00 08  be  0xa008a2ac
a008a290:  82 10 20 02  mov  2, %g1
a008a294:  9a 03 7f ff  add  %o5, -1, %o5
a008a298:  83 2b 60 10  sll  %o5, 0x10, %g1
a008a29c:  83 30 60 10  srl  %g1, 0x10, %g1
a008a2a0:  80 a0 40 0a  cmp  %g1, %o2
a008a2a4:  12 bf ff f4  bne  0xa008a274
a008a2a8:  82 10 20 02  mov  2, %g1
a008a2ac:  1b 33 c0 49  sethi  %hi(0xcf012400), %o5
a008a2b0:  c2 23 00 00  st  %g1, [ %o4 ]
a008a2b4:  9a 13 60 44  or  %o5, 0x44, %o5
a008a2b8:  c2 03 40 00  ld  [ %o5 ], %g1
a008a2bc:  10 80 00 69  b  0xa008a460
a008a2c0:  82 10 60 10  or  %g1, 0x10, %g1
a008a2c4:  03 33 c0 f2  sethi  %hi(0xcf03c800), %g1
a008a2c8:  98 10 60 40  or  %g1, 0x40, %o4	! 0xcf03c840
a008a2cc:  03 00 00 3f  sethi  %hi(0xfc00), %g1
a008a2d0:  94 10 63 ff  or  %g1, 0x3ff, %o2	! 0xffff
a008a2d4:  9a 10 3f ff  mov  -1, %o5
a008a2d8:  96 10 20 02  mov  2, %o3
a008a2dc:  c2 03 00 00  ld  [ %o4 ], %g1
a008a2e0:  80 a0 60 01  cmp  %g1, 1
a008a2e4:  32 80 00 02  bne,a   0xa008a2ec
a008a2e8:  d6 23 00 00  st  %o3, [ %o4 ]
a008a2ec:  c2 03 00 00  ld  [ %o4 ], %g1
a008a2f0:  80 a0 60 02  cmp  %g1, 2
a008a2f4:  02 80 00 08  be  0xa008a314
a008a2f8:  82 10 20 02  mov  2, %g1
a008a2fc:  9a 03 7f ff  add  %o5, -1, %o5
a008a300:  83 2b 60 10  sll  %o5, 0x10, %g1
a008a304:  83 30 60 10  srl  %g1, 0x10, %g1
a008a308:  80 a0 40 0a  cmp  %g1, %o2
a008a30c:  12 bf ff f4  bne  0xa008a2dc
a008a310:  82 10 20 02  mov  2, %g1
a008a314:  1b 33 c0 49  sethi  %hi(0xcf012400), %o5
a008a318:  c2 23 00 00  st  %g1, [ %o4 ]
a008a31c:  9a 13 60 44  or  %o5, 0x44, %o5
a008a320:  c2 03 40 00  ld  [ %o5 ], %g1
a008a324:  10 80 00 4f  b  0xa008a460
a008a328:  82 10 60 20  or  %g1, 0x20, %g1
a008a32c:  03 33 c0 f2  sethi  %hi(0xcf03c800), %g1
a008a330:  98 10 60 40  or  %g1, 0x40, %o4	! 0xcf03c840
a008a334:  03 00 00 3f  sethi  %hi(0xfc00), %g1
a008a338:  94 10 63 ff  or  %g1, 0x3ff, %o2	! 0xffff
a008a33c:  9a 10 3f ff  mov  -1, %o5
a008a340:  96 10 20 02  mov  2, %o3
a008a344:  c2 03 00 00  ld  [ %o4 ], %g1
a008a348:  80 a0 60 01  cmp  %g1, 1
a008a34c:  32 80 00 02  bne,a   0xa008a354
a008a350:  d6 23 00 00  st  %o3, [ %o4 ]
a008a354:  c2 03 00 00  ld  [ %o4 ], %g1
a008a358:  80 a0 60 02  cmp  %g1, 2
a008a35c:  02 80 00 08  be  0xa008a37c
a008a360:  82 10 20 02  mov  2, %g1
a008a364:  9a 03 7f ff  add  %o5, -1, %o5
a008a368:  83 2b 60 10  sll  %o5, 0x10, %g1
a008a36c:  83 30 60 10  srl  %g1, 0x10, %g1
a008a370:  80 a0 40 0a  cmp  %g1, %o2
a008a374:  12 bf ff f4  bne  0xa008a344
a008a378:  82 10 20 02  mov  2, %g1
a008a37c:  1b 33 c0 49  sethi  %hi(0xcf012400), %o5
a008a380:  c2 23 00 00  st  %g1, [ %o4 ]
a008a384:  9a 13 60 44  or  %o5, 0x44, %o5
a008a388:  c2 03 40 00  ld  [ %o5 ], %g1
a008a38c:  10 80 00 35  b  0xa008a460
a008a390:  82 10 60 40  or  %g1, 0x40, %g1
a008a394:  03 33 c0 f2  sethi  %hi(0xcf03c800), %g1
a008a398:  98 10 60 40  or  %g1, 0x40, %o4	! 0xcf03c840
a008a39c:  03 00 00 3f  sethi  %hi(0xfc00), %g1
a008a3a0:  94 10 63 ff  or  %g1, 0x3ff, %o2	! 0xffff
a008a3a4:  9a 10 3f ff  mov  -1, %o5
a008a3a8:  96 10 20 02  mov  2, %o3
a008a3ac:  c2 03 00 00  ld  [ %o4 ], %g1
a008a3b0:  80 a0 60 01  cmp  %g1, 1
a008a3b4:  32 80 00 02  bne,a   0xa008a3bc
a008a3b8:  d6 23 00 00  st  %o3, [ %o4 ]
a008a3bc:  c2 03 00 00  ld  [ %o4 ], %g1
a008a3c0:  80 a0 60 02  cmp  %g1, 2
a008a3c4:  02 80 00 08  be  0xa008a3e4
a008a3c8:  82 10 20 02  mov  2, %g1
a008a3cc:  9a 03 7f ff  add  %o5, -1, %o5
a008a3d0:  83 2b 60 10  sll  %o5, 0x10, %g1
a008a3d4:  83 30 60 10  srl  %g1, 0x10, %g1
a008a3d8:  80 a0 40 0a  cmp  %g1, %o2
a008a3dc:  12 bf ff f4  bne  0xa008a3ac
a008a3e0:  82 10 20 02  mov  2, %g1
a008a3e4:  1b 33 c0 49  sethi  %hi(0xcf012400), %o5
a008a3e8:  c2 23 00 00  st  %g1, [ %o4 ]
a008a3ec:  9a 13 60 44  or  %o5, 0x44, %o5
a008a3f0:  c2 03 40 00  ld  [ %o5 ], %g1
a008a3f4:  10 80 00 1b  b  0xa008a460
a008a3f8:  82 10 60 80  or  %g1, 0x80, %g1
a008a3fc:  03 33 c0 f2  sethi  %hi(0xcf03c800), %g1
a008a400:  98 10 60 40  or  %g1, 0x40, %o4	! 0xcf03c840
a008a404:  03 00 00 3f  sethi  %hi(0xfc00), %g1
a008a408:  94 10 63 ff  or  %g1, 0x3ff, %o2	! 0xffff
a008a40c:  9a 10 3f ff  mov  -1, %o5
a008a410:  96 10 20 02  mov  2, %o3
a008a414:  c2 03 00 00  ld  [ %o4 ], %g1
a008a418:  80 a0 60 01  cmp  %g1, 1
a008a41c:  32 80 00 02  bne,a   0xa008a424
a008a420:  d6 23 00 00  st  %o3, [ %o4 ]
a008a424:  c2 03 00 00  ld  [ %o4 ], %g1
a008a428:  80 a0 60 02  cmp  %g1, 2
a008a42c:  02 80 00 07  be  0xa008a448
a008a430:  9a 03 7f ff  add  %o5, -1, %o5
a008a434:  83 2b 60 10  sll  %o5, 0x10, %g1
a008a438:  83 30 60 10  srl  %g1, 0x10, %g1
a008a43c:  80 a0 40 0a  cmp  %g1, %o2
a008a440:  12 bf ff f5  bne  0xa008a414
a008a444:  01 00 00 00  nop
a008a448:  82 10 20 02  mov  2, %g1	! 0x2
a008a44c:  1b 33 c0 49  sethi  %hi(0xcf012400), %o5
a008a450:  c2 23 00 00  st  %g1, [ %o4 ]
a008a454:  9a 13 60 44  or  %o5, 0x44, %o5
a008a458:  c2 03 40 00  ld  [ %o5 ], %g1
a008a45c:  82 10 60 f0  or  %g1, 0xf0, %g1
a008a460:  c2 23 40 00  st  %g1, [ %o5 ]
a008a464:  c0 23 00 00  clr  [ %o4 ]
a008a468:  81 c3 e0 08  retl
a008a46c:  01 00 00 00  nop
