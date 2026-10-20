# leon2s FUN_a008b32c 0xa008b32c-0xa008b53c (528 bytes)
a008b32c:  03 2a 01 d9  sethi  %hi(0xa8076400), %g1
a008b330:  90 0a 20 ff  and  %o0, 0xff, %o0
a008b334:  82 10 62 90  or  %g1, 0x290, %g1
a008b338:  80 a2 20 08  cmp  %o0, 8
a008b33c:  18 80 00 7e  bgu  0xa008b534
a008b340:  d2 28 40 08  stb  %o1, [ %g1 + %o0 ]
a008b344:  1b 28 02 2c  sethi  %hi(0xa008b000), %o5
a008b348:  83 2a 20 02  sll  %o0, 2, %g1
a008b34c:  9a 13 63 08  or  %o5, 0x308, %o5
a008b350:  c2 03 40 01  ld  [ %o5 + %g1 ], %g1
a008b354:  81 c0 40 00  jmp  %g1
a008b358:  01 00 00 00  nop
a008b35c:  80 8a a0 ff  btst  0xff, %o2
a008b360:  02 80 00 21  be  0xa008b3e4
a008b364:  1b 33 c0 44  sethi  %hi(0xcf011000), %o5
a008b368:  17 33 c0 44  sethi  %hi(0xcf011000), %o3
a008b36c:  98 12 e2 00  or  %o3, 0x200, %o4	! 0xcf011200
a008b370:  c2 03 00 00  ld  [ %o4 ], %g1
a008b374:  92 0a 60 ff  and  %o1, 0xff, %o1
a008b378:  9a 0a 60 0f  and  %o1, 0xf, %o5
a008b37c:  82 08 60 f0  and  %g1, 0xf0, %g1
a008b380:  82 10 40 0d  or  %g1, %o5, %g1
a008b384:  1b 2a 01 f3  sethi  %hi(0xa807cc00), %o5
a008b388:  da 0b 61 80  ldub  [ %o5 + 0x180 ], %o5	! 0xa807cd80
a008b38c:  c2 23 00 00  st  %g1, [ %o4 ]
a008b390:  80 a3 60 00  cmp  %o5, 0
a008b394:  12 80 00 07  bne  0xa008b3b0
a008b398:  82 1a 60 01  xor  %o1, 1, %g1
a008b39c:  9a 12 e0 18  or  %o3, 0x18, %o5
a008b3a0:  c2 03 40 00  ld  [ %o5 ], %g1
a008b3a4:  82 08 7f f3  and  %g1, -13, %g1
a008b3a8:  c2 23 40 00  st  %g1, [ %o5 ]
a008b3ac:  82 1a 60 01  xor  %o1, 1, %g1
a008b3b0:  80 a0 00 01  cmp  %g0, %g1
a008b3b4:  03 2a 01 d9  sethi  %hi(0xa8076400), %g1
a008b3b8:  da 08 62 88  ldub  [ %g1 + 0x288 ], %o5	! 0xa8076688
a008b3bc:  82 60 3f ff  subx  %g0, -1, %g1
a008b3c0:  80 a8 40 0d  andncc  %g1, %o5, %g0
a008b3c4:  02 80 00 05  be  0xa008b3d8
a008b3c8:  98 12 e0 08  or  %o3, 8, %o4
a008b3cc:  c2 03 00 00  ld  [ %o4 ], %g1
a008b3d0:  10 80 00 50  b  0xa008b510
a008b3d4:  82 08 7f df  and  %g1, -33, %g1
a008b3d8:  c2 03 00 00  ld  [ %o4 ], %g1
a008b3dc:  10 80 00 4d  b  0xa008b510
a008b3e0:  82 10 60 20  or  %g1, 0x20, %g1
a008b3e4:  9a 13 60 18  or  %o5, 0x18, %o5
a008b3e8:  c2 03 40 00  ld  [ %o5 ], %g1
a008b3ec:  82 10 60 0c  or  %g1, 0xc, %g1
a008b3f0:  c2 23 40 00  st  %g1, [ %o5 ]
a008b3f4:  30 80 00 50  b,a   0xa008b534
a008b3f8:  19 33 c0 44  sethi  %hi(0xcf011000), %o4
a008b3fc:  9a 13 22 2c  or  %o4, 0x22c, %o5	! 0xcf01122c
a008b400:  82 10 20 c0  mov  0xc0, %g1
a008b404:  c2 23 40 00  st  %g1, [ %o5 ]
a008b408:  98 13 22 04  or  %o4, 0x204, %o4
a008b40c:  c2 03 00 00  ld  [ %o4 ], %g1
a008b410:  82 08 60 f0  and  %g1, 0xf0, %g1
a008b414:  10 80 00 28  b  0xa008b4b4
a008b418:  9a 0a 60 0f  and  %o1, 0xf, %o5
a008b41c:  19 33 c0 44  sethi  %hi(0xcf011000), %o4
a008b420:  9a 13 22 30  or  %o4, 0x230, %o5	! 0xcf011230
a008b424:  82 10 20 c0  mov  0xc0, %g1
a008b428:  c2 23 40 00  st  %g1, [ %o5 ]
a008b42c:  98 13 22 08  or  %o4, 0x208, %o4
a008b430:  c2 03 00 00  ld  [ %o4 ], %g1
a008b434:  92 0a 60 ff  and  %o1, 0xff, %o1
a008b438:  82 08 60 f0  and  %g1, 0xf0, %g1
a008b43c:  9a 0a 60 0f  and  %o1, 0xf, %o5
a008b440:  82 10 40 0d  or  %g1, %o5, %g1
a008b444:  c2 23 00 00  st  %g1, [ %o4 ]
a008b448:  10 80 00 0f  b  0xa008b484
a008b44c:  90 10 20 00  clr  %o0
a008b450:  19 33 c0 44  sethi  %hi(0xcf011000), %o4
a008b454:  9a 13 22 34  or  %o4, 0x234, %o5	! 0xcf011234
a008b458:  82 10 20 c0  mov  0xc0, %g1
a008b45c:  c2 23 40 00  st  %g1, [ %o5 ]
a008b460:  98 13 22 08  or  %o4, 0x208, %o4
a008b464:  92 0a 60 ff  and  %o1, 0xff, %o1
a008b468:  da 03 00 00  ld  [ %o4 ], %o5
a008b46c:  82 0a 60 0f  and  %o1, 0xf, %g1
a008b470:  9a 0b 60 0f  and  %o5, 0xf, %o5
a008b474:  83 28 60 04  sll  %g1, 4, %g1
a008b478:  9a 13 40 01  or  %o5, %g1, %o5
a008b47c:  da 23 00 00  st  %o5, [ %o4 ]
a008b480:  90 10 20 01  mov  1, %o0
a008b484:  82 13 c0 00  mov  %o7, %g1
a008b488:  40 00 1a 8d  call  0xa0091ebc
a008b48c:  9e 10 40 00  mov  %g1, %o7
a008b490:  03 33 c0 44  sethi  %hi(0xcf011000), %g1
a008b494:  10 80 00 23  b  0xa008b520
a008b498:  82 10 62 10  or  %g1, 0x210, %g1	! 0xcf011210
a008b49c:  19 33 c0 44  sethi  %hi(0xcf011000), %o4
a008b4a0:  98 13 22 10  or  %o4, 0x210, %o4	! 0xcf011210
a008b4a4:  9a 0a 60 0f  and  %o1, 0xf, %o5
a008b4a8:  c2 03 00 00  ld  [ %o4 ], %g1
a008b4ac:  82 08 60 0f  and  %g1, 0xf, %g1
a008b4b0:  9b 2b 60 04  sll  %o5, 4, %o5
a008b4b4:  10 80 00 17  b  0xa008b510
a008b4b8:  82 10 40 0d  or  %g1, %o5, %g1
a008b4bc:  19 33 c0 44  sethi  %hi(0xcf011000), %o4
a008b4c0:  96 13 22 0c  or  %o4, 0x20c, %o3	! 0xcf01120c
a008b4c4:  c2 02 c0 00  ld  [ %o3 ], %g1
a008b4c8:  82 08 60 f0  and  %g1, 0xf0, %g1
a008b4cc:  9a 0a 60 0f  and  %o1, 0xf, %o5
a008b4d0:  82 10 40 0d  or  %g1, %o5, %g1
a008b4d4:  c2 22 c0 00  st  %g1, [ %o3 ]
a008b4d8:  98 13 21 c0  or  %o4, 0x1c0, %o4
a008b4dc:  c2 03 00 00  ld  [ %o4 ], %g1
a008b4e0:  10 80 00 0c  b  0xa008b510
a008b4e4:  82 10 60 02  or  %g1, 2, %g1
a008b4e8:  19 33 c0 44  sethi  %hi(0xcf011000), %o4
a008b4ec:  96 13 22 18  or  %o4, 0x218, %o3	! 0xcf011218
a008b4f0:  c2 02 c0 00  ld  [ %o3 ], %g1
a008b4f4:  82 08 60 f0  and  %g1, 0xf0, %g1
a008b4f8:  9a 0a 60 0f  and  %o1, 0xf, %o5
a008b4fc:  82 10 40 0d  or  %g1, %o5, %g1
a008b500:  c2 22 c0 00  st  %g1, [ %o3 ]
a008b504:  98 13 21 c0  or  %o4, 0x1c0, %o4
a008b508:  c2 03 00 00  ld  [ %o4 ], %g1
a008b50c:  82 10 60 01  or  %g1, 1, %g1
a008b510:  c2 23 00 00  st  %g1, [ %o4 ]
a008b514:  30 80 00 08  b,a   0xa008b534
a008b518:  03 33 c0 44  sethi  %hi(0xcf011000), %g1
a008b51c:  82 10 62 14  or  %g1, 0x214, %g1	! 0xcf011214
a008b520:  da 00 40 00  ld  [ %g1 ], %o5
a008b524:  9a 0b 60 f0  and  %o5, 0xf0, %o5
a008b528:  98 0a 60 0f  and  %o1, 0xf, %o4
a008b52c:  9a 13 40 0c  or  %o5, %o4, %o5
a008b530:  da 20 40 00  st  %o5, [ %g1 ]
a008b534:  81 c3 e0 08  retl
a008b538:  01 00 00 00  nop
