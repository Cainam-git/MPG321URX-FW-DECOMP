# leon2m FUN_a015d3b0 0xa015d3b0-0xa015d4c4 (276 bytes)
a015d3b0:  9d e3 bf 98  save  %sp, -104, %sp
a015d3b4:  a1 3e a0 05  sra  %i2, 5, %l0
a015d3b8:  c2 06 60 10  ld  [ %i1 + 0x10 ], %g1
a015d3bc:  82 00 40 10  add  %g1, %l0, %g1
a015d3c0:  a2 00 60 01  add  %g1, 1, %l1
a015d3c4:  c2 06 60 08  ld  [ %i1 + 8 ], %g1
a015d3c8:  a4 10 00 18  mov  %i0, %l2
a015d3cc:  80 a4 40 01  cmp  %l1, %g1
a015d3d0:  04 80 00 06  ble  0xa015d3e8
a015d3d4:  d2 06 60 04  ld  [ %i1 + 4 ], %o1
a015d3d8:  82 00 40 01  add  %g1, %g1, %g1
a015d3dc:  80 a4 40 01  cmp  %l1, %g1
a015d3e0:  14 bf ff fe  bg  0xa015d3d8
a015d3e4:  92 02 60 01  inc  %o1
a015d3e8:  7f ff fe 27  call  0xa015cc84
a015d3ec:  90 10 00 12  mov  %l2, %o0
a015d3f0:  b0 10 00 08  mov  %o0, %i0
a015d3f4:  80 a4 20 00  cmp  %l0, 0
a015d3f8:  04 80 00 07  ble  0xa015d414
a015d3fc:  96 02 20 14  add  %o0, 0x14, %o3
a015d400:  82 10 00 10  mov  %l0, %g1
a015d404:  c0 22 c0 00  clr  [ %o3 ]
a015d408:  82 80 7f ff  addcc  %g1, -1, %g1
a015d40c:  12 bf ff fe  bne  0xa015d404
a015d410:  96 02 e0 04  add  %o3, 4, %o3
a015d414:  c2 06 60 10  ld  [ %i1 + 0x10 ], %g1
a015d418:  83 28 60 02  sll  %g1, 2, %g1
a015d41c:  98 06 60 14  add  %i1, 0x14, %o4
a015d420:  b4 8e a0 1f  andcc  %i2, 0x1f, %i2
a015d424:  02 80 00 14  be  0xa015d474
a015d428:  94 00 40 0c  add  %g1, %o4, %o2
a015d42c:  82 10 20 20  mov  0x20, %g1
a015d430:  92 20 40 1a  sub  %g1, %i2, %o1
a015d434:  9a 10 20 00  clr  %o5
a015d438:  c2 03 00 00  ld  [ %o4 ], %g1
a015d43c:  83 28 40 1a  sll  %g1, %i2, %g1
a015d440:  82 10 40 0d  or  %g1, %o5, %g1
a015d444:  c2 22 c0 00  st  %g1, [ %o3 ]
a015d448:  da 03 00 00  ld  [ %o4 ], %o5
a015d44c:  98 03 20 04  add  %o4, 4, %o4
a015d450:  96 02 e0 04  add  %o3, 4, %o3
a015d454:  80 a3 00 0a  cmp  %o4, %o2
a015d458:  0a bf ff f8  bcs  0xa015d438
a015d45c:  9b 33 40 09  srl  %o5, %o1, %o5
a015d460:  80 a3 60 00  cmp  %o5, 0
a015d464:  02 80 00 10  be  0xa015d4a4
a015d468:  da 22 c0 00  st  %o5, [ %o3 ]
a015d46c:  10 80 00 0e  b  0xa015d4a4
a015d470:  a2 04 60 01  inc  %l1
a015d474:  c2 03 00 00  ld  [ %o4 ], %g1
a015d478:  c2 22 c0 00  st  %g1, [ %o3 ]
a015d47c:  98 03 20 04  add  %o4, 4, %o4
a015d480:  80 a3 00 0a  cmp  %o4, %o2
a015d484:  1a 80 00 08  bcc  0xa015d4a4
a015d488:  96 02 e0 04  add  %o3, 4, %o3
a015d48c:  c2 03 00 00  ld  [ %o4 ], %g1
a015d490:  c2 22 c0 00  st  %g1, [ %o3 ]
a015d494:  98 03 20 04  add  %o4, 4, %o4
a015d498:  80 a3 00 0a  cmp  %o4, %o2
a015d49c:  0a bf ff f6  bcs  0xa015d474
a015d4a0:  96 02 e0 04  add  %o3, 4, %o3
a015d4a4:  82 04 7f ff  add  %l1, -1, %g1
a015d4a8:  c2 26 20 10  st  %g1, [ %i0 + 0x10 ]
a015d4ac:  90 10 00 12  mov  %l2, %o0
a015d4b0:  7f ff fe 1e  call  0xa015cd28
a015d4b4:  92 10 00 19  mov  %i1, %o1
a015d4b8:  01 00 00 00  nop
a015d4bc:  81 c7 e0 08  ret
a015d4c0:  81 e8 00 00  restore
