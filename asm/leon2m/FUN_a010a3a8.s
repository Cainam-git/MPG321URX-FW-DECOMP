# leon2m FUN_a010a3a8 0xa010a3a8-0xa010a494 (236 bytes)
a010a3a8:  9d e3 bf 98  save  %sp, -104, %sp
a010a3ac:  03 33 c0 79  sethi  %hi(0xcf01e400), %g1
a010a3b0:  b0 0e 20 ff  and  %i0, 0xff, %i0
a010a3b4:  b8 10 62 84  or  %g1, 0x284, %i4
a010a3b8:  b6 10 62 88  or  %g1, 0x288, %i3
a010a3bc:  80 a6 20 01  cmp  %i0, 1
a010a3c0:  02 80 00 12  be  0xa010a408
a010a3c4:  9a 10 00 19  mov  %i1, %o5
a010a3c8:  ba 10 00 01  mov  %g1, %i5
a010a3cc:  b2 10 00 1c  mov  %i4, %i1
a010a3d0:  b4 10 62 8c  or  %g1, 0x28c, %i2
a010a3d4:  80 a6 20 02  cmp  %i0, 2
a010a3d8:  02 80 00 1b  be  0xa010a444
a010a3dc:  9e 10 00 1b  mov  %i3, %o7
a010a3e0:  f2 07 00 00  ld  [ %i4 ], %i1
a010a3e4:  b0 0e 7f ef  and  %i1, -17, %i0
a010a3e8:  f0 27 00 00  st  %i0, [ %i4 ]
a010a3ec:  c2 06 c0 00  ld  [ %i3 ], %g1
a010a3f0:  ba 08 7f ef  and  %g1, -17, %i5
a010a3f4:  fa 26 c0 00  st  %i5, [ %i3 ]
a010a3f8:  f8 06 80 00  ld  [ %i2 ], %i4
a010a3fc:  b2 0f 3f ef  and  %i4, -17, %i1
a010a400:  f2 26 80 00  st  %i1, [ %i2 ]
a010a404:  30 80 00 22  b,a   0xa010a48c
a010a408:  f4 07 00 00  ld  [ %i4 ], %i2
a010a40c:  b0 16 a0 10  or  %i2, 0x10, %i0
a010a410:  f0 27 00 00  st  %i0, [ %i4 ]
a010a414:  fa 06 c0 00  ld  [ %i3 ], %i5
a010a418:  b2 10 62 8c  or  %g1, 0x28c, %i1
a010a41c:  b8 0f 7f ef  and  %i5, -17, %i4
a010a420:  b4 10 00 19  mov  %i1, %i2
a010a424:  f8 26 c0 00  st  %i4, [ %i3 ]
a010a428:  80 8b 60 ff  btst  0xff, %o5
a010a42c:  02 bf ff f3  be  0xa010a3f8
a010a430:  01 00 00 00  nop
a010a434:  c2 06 40 00  ld  [ %i1 ], %g1
a010a438:  b6 10 60 10  or  %g1, 0x10, %i3
a010a43c:  f6 26 40 00  st  %i3, [ %i1 ]
a010a440:  30 80 00 13  b,a   0xa010a48c
a010a444:  c2 07 00 00  ld  [ %i4 ], %g1
a010a448:  b6 10 60 10  or  %g1, 0x10, %i3
a010a44c:  f6 26 40 00  st  %i3, [ %i1 ]
a010a450:  f4 03 c0 00  ld  [ %o7 ], %i2
a010a454:  b8 17 62 8c  or  %i5, 0x28c, %i4
a010a458:  b0 16 a0 10  or  %i2, 0x10, %i0
a010a45c:  ba 10 00 1c  mov  %i4, %i5
a010a460:  f0 23 c0 00  st  %i0, [ %o7 ]
a010a464:  80 8b 60 ff  btst  0xff, %o5
a010a468:  02 80 00 06  be  0xa010a480
a010a46c:  01 00 00 00  nop
a010a470:  f2 07 00 00  ld  [ %i4 ], %i1
a010a474:  ba 16 60 10  or  %i1, 0x10, %i5
a010a478:  fa 27 00 00  st  %i5, [ %i4 ]
a010a47c:  30 80 00 04  b,a   0xa010a48c
a010a480:  f0 07 00 00  ld  [ %i4 ], %i0
a010a484:  b8 0e 3f ef  and  %i0, -17, %i4
a010a488:  f8 27 40 00  st  %i4, [ %i5 ]
a010a48c:  81 c7 e0 08  ret
a010a490:  81 e8 00 00  restore
