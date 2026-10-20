# leon2m FUN_a010a2cc 0xa010a2cc-0xa010a3a8 (220 bytes)
a010a2cc:  9d e3 bf 98  save  %sp, -104, %sp
a010a2d0:  11 33 c0 7a  sethi  %hi(0xcf01e800), %o0
a010a2d4:  9a 10 00 18  mov  %i0, %o5
a010a2d8:  92 06 3f ff  add  %i0, -1, %o1
a010a2dc:  96 12 22 40  or  %o0, 0x240, %o3
a010a2e0:  21 33 c0 79  sethi  %hi(0xcf01e400), %l0
a010a2e4:  82 0a 60 ff  and  %o1, 0xff, %g1
a010a2e8:  31 00 06 6b  sethi  %hi(0x19ac00), %i0
a010a2ec:  90 10 20 c8  mov  0xc8, %o0
a010a2f0:  94 14 22 00  or  %l0, 0x200, %o2
a010a2f4:  b0 16 20 88  or  %i0, 0x88, %i0
a010a2f8:  80 a0 60 01  cmp  %g1, 1
a010a2fc:  18 80 00 19  bgu  0xa010a360
a010a300:  a2 10 00 0d  mov  %o5, %l1
a010a304:  c2 04 00 00  ld  [ %l0 ], %g1
a010a308:  94 10 60 10  or  %g1, 0x10, %o2
a010a30c:  d4 24 00 00  st  %o2, [ %l0 ]
a010a310:  67 fe 0b a4  call  0x4008d1a0
a010a314:  01 00 00 00  nop
a010a318:  98 14 22 00  or  %l0, 0x200, %o4
a010a31c:  da 03 00 00  ld  [ %o4 ], %o5
a010a320:  17 33 c0 7a  sethi  %hi(0xcf01e800), %o3
a010a324:  a0 13 60 10  or  %o5, 0x10, %l0
a010a328:  9e 0c 60 ff  and  %l1, 0xff, %o7
a010a32c:  94 12 e2 40  or  %o3, 0x240, %o2
a010a330:  e0 23 00 00  st  %l0, [ %o4 ]
a010a334:  80 a3 e0 01  cmp  %o7, 1
a010a338:  02 80 00 15  be  0xa010a38c
a010a33c:  01 00 00 00  nop
a010a340:  d8 02 80 00  ld  [ %o2 ], %o4
a010a344:  9e 0b 20 3f  and  %o4, 0x3f, %o7
a010a348:  90 13 e0 c1  or  %o7, 0xc1, %o0
a010a34c:  21 00 06 6b  sethi  %hi(0x19ac00), %l0
a010a350:  d0 22 80 00  st  %o0, [ %o2 ]
a010a354:  b0 14 20 a0  or  %l0, 0xa0, %i0
a010a358:  7f ff 53 86  call  0xa00df170
a010a35c:  81 e8 00 00  restore
a010a360:  d0 02 c0 00  ld  [ %o3 ], %o0
a010a364:  92 0a 3f 3f  and  %o0, -193, %o1
a010a368:  d2 22 c0 00  st  %o1, [ %o3 ]
a010a36c:  e2 04 00 00  ld  [ %l0 ], %l1
a010a370:  82 0c 7f ef  and  %l1, -17, %g1
a010a374:  c2 24 00 00  st  %g1, [ %l0 ]
a010a378:  d6 02 80 00  ld  [ %o2 ], %o3
a010a37c:  9a 0a ff ef  and  %o3, -17, %o5
a010a380:  da 22 80 00  st  %o5, [ %o2 ]
a010a384:  7f ff 53 7b  call  0xa00df170
a010a388:  81 e8 00 00  restore
a010a38c:  d2 02 80 00  ld  [ %o2 ], %o1
a010a390:  b0 0a 60 3f  and  %o1, 0x3f, %i0
a010a394:  a2 16 20 81  or  %i0, 0x81, %l1
a010a398:  21 00 06 6b  sethi  %hi(0x19ac00), %l0
a010a39c:  e2 22 80 00  st  %l1, [ %o2 ]
a010a3a0:  10 bf ff ee  b  0xa010a358
a010a3a4:  b0 14 20 a0  or  %l0, 0xa0, %i0
