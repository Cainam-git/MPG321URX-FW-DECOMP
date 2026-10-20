# leon2m FUN_a00aa33c 0xa00aa33c-0xa00aa4c0 (388 bytes)
a00aa33c:  9d e3 bf 90  save  %sp, -112, %sp
a00aa340:  15 09 24 92  sethi  %hi(0x24924800), %o2
a00aa344:  98 0e 20 ff  and  %i0, 0xff, %o4
a00aa348:  92 12 a1 25  or  %o2, 0x125, %o1
a00aa34c:  80 53 00 09  umul  %o4, %o1, %g0
a00aa350:  83 40 00 00  rd  %y, %g1
a00aa354:  90 23 00 01  sub  %o4, %g1, %o0
a00aa358:  9b 32 20 01  srl  %o0, 1, %o5
a00aa35c:  9e 00 40 0d  add  %g1, %o5, %o7
a00aa360:  97 33 e0 02  srl  %o7, 2, %o3
a00aa364:  95 2a e0 03  sll  %o3, 3, %o2
a00aa368:  92 22 80 0b  sub  %o2, %o3, %o1
a00aa36c:  90 23 00 09  sub  %o4, %o1, %o0
a00aa370:  82 0a 20 ff  and  %o0, 0xff, %g1
a00aa374:  9a 00 40 01  add  %g1, %g1, %o5
a00aa378:  96 03 60 06  add  %o5, 6, %o3
a00aa37c:  80 a3 20 05  cmp  %o4, 5
a00aa380:  02 80 00 36  be  0xa00aa458
a00aa384:  9a 10 3f ff  mov  -1, %o5
a00aa388:  80 a3 20 06  cmp  %o4, 6
a00aa38c:  02 80 00 3b  be  0xa00aa478
a00aa390:  80 a3 20 07  cmp  %o4, 7
a00aa394:  22 80 00 44  be,a   0xa00aa4a4
a00aa398:  1b 2a 00 b5  sethi  %hi(0xa802d400), %o5
a00aa39c:  80 a3 20 08  cmp  %o4, 8
a00aa3a0:  02 80 00 44  be  0xa00aa4b0
a00aa3a4:  15 2a 00 b5  sethi  %hi(0xa802d400), %o2
a00aa3a8:  9e 06 3f fb  add  %i0, -5, %o7
a00aa3ac:  b0 0b e0 ff  and  %o7, 0xff, %i0
a00aa3b0:  80 a6 20 03  cmp  %i0, 3
a00aa3b4:  18 80 00 23  bgu  0xa00aa440
a00aa3b8:  82 0e 60 ff  and  %i1, 0xff, %g1
a00aa3bc:  80 a0 60 01  cmp  %g1, 1
a00aa3c0:  02 80 00 32  be  0xa00aa488
a00aa3c4:  9e 0b 60 ff  and  %o5, 0xff, %o7
a00aa3c8:  b0 1b e0 01  xor  %o7, 1, %i0
a00aa3cc:  80 a0 00 18  cmp  %g0, %i0
a00aa3d0:  94 60 20 00  subx  %g0, 0, %o2
a00aa3d4:  92 0a be 00  and  %o2, -512, %o1
a00aa3d8:  82 02 67 92  add  %o1, 0x792, %g1
a00aa3dc:  91 28 60 10  sll  %g1, 0x10, %o0
a00aa3e0:  95 32 20 10  srl  %o0, 0x10, %o2
a00aa3e4:  9a 1a a7 42  xor  %o2, 0x742, %o5
a00aa3e8:  80 a0 00 0d  cmp  %g0, %o5
a00aa3ec:  98 60 3f ff  subx  %g0, -1, %o4
a00aa3f0:  82 1a a7 92  xor  %o2, 0x792, %g1
a00aa3f4:  80 a0 00 01  cmp  %g0, %g1
a00aa3f8:  b2 60 3f ff  subx  %g0, -1, %i1
a00aa3fc:  80 93 00 19  orcc  %o4, %i1, %g0
a00aa400:  12 80 00 03  bne  0xa00aa40c
a00aa404:  82 10 20 37  mov  0x37, %g1
a00aa408:  82 10 20 34  mov  0x34, %g1
a00aa40c:  98 0a e0 fe  and  %o3, 0xfe, %o4
a00aa410:  c2 23 a0 5c  st  %g1, [ %sp + 0x5c ]
a00aa414:  90 10 20 01  mov  1, %o0
a00aa418:  92 10 20 01  mov  1, %o1
a00aa41c:  96 10 20 22  mov  0x22, %o3
a00aa420:  40 00 23 b1  call  0xa00b32e4
a00aa424:  9a 10 20 03  mov  3, %o5
a00aa428:  90 10 20 01  mov  1, %o0
a00aa42c:  7f ff fc 0f  call  0xa00a9468
a00aa430:  92 10 20 03  mov  3, %o1
a00aa434:  b0 10 20 00  clr  %i0
a00aa438:  40 00 24 27  call  0xa00b34d4
a00aa43c:  93 e8 20 02  restore  %g0, 2, %o1
a00aa440:  90 10 20 01  mov  1, %o0
a00aa444:  7f ff fc 09  call  0xa00a9468
a00aa448:  92 10 20 02  mov  2, %o1
a00aa44c:  b0 10 20 00  clr  %i0
a00aa450:  40 00 24 21  call  0xa00b34d4
a00aa454:  93 e8 20 01  restore  %g0, 1, %o1
a00aa458:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a00aa45c:  d8 03 e3 3c  ld  [ %o7 + 0x33c ], %o4	! 0xa802d33c
a00aa460:  1b 00 10 00  sethi  %hi(0x400000), %o5
a00aa464:  80 8b 00 0d  btst  %o4, %o5
a00aa468:  12 bf ff d0  bne  0xa00aa3a8
a00aa46c:  9a 10 20 01  mov  1, %o5
a00aa470:  10 bf ff ce  b  0xa00aa3a8
a00aa474:  9a 10 20 00  clr  %o5
a00aa478:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00aa47c:  d8 00 63 3c  ld  [ %g1 + 0x33c ], %o4	! 0xa802d33c
a00aa480:  10 bf ff f9  b  0xa00aa464
a00aa484:  1b 00 04 00  sethi  %hi(0x100000), %o5
a00aa488:  90 0b 60 ff  and  %o5, 0xff, %o0
a00aa48c:  9a 1a 20 01  xor  %o0, 1, %o5
a00aa490:  80 a0 00 0d  cmp  %g0, %o5
a00aa494:  98 60 20 00  subx  %g0, 0, %o4
a00aa498:  b2 0b 3e 00  and  %o4, -512, %i1
a00aa49c:  10 bf ff d0  b  0xa00aa3dc
a00aa4a0:  82 06 67 42  add  %i1, 0x742, %g1
a00aa4a4:  d8 03 60 7c  ld  [ %o5 + 0x7c ], %o4
a00aa4a8:  10 bf ff f0  b  0xa00aa468
a00aa4ac:  80 8b 20 80  btst  0x80, %o4
a00aa4b0:  d2 02 a0 84  ld  [ %o2 + 0x84 ], %o1
a00aa4b4:  91 32 60 1e  srl  %o1, 0x1e, %o0
a00aa4b8:  10 bf ff bc  b  0xa00aa3a8
a00aa4bc:  9a 0a 20 01  and  %o0, 1, %o5
