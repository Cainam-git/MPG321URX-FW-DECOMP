# leon2m FUN_a01253bc 0xa01253bc-0xa01254b8 (252 bytes)
a01253bc:  9d e3 bf 98  save  %sp, -104, %sp
a01253c0:  94 10 20 01  mov  1, %o2
a01253c4:  13 2a 00 b8  sethi  %hi(0xa802e000), %o1
a01253c8:  a0 0e 20 ff  and  %i0, 0xff, %l0
a01253cc:  99 2a 80 18  sll  %o2, %i0, %o4
a01253d0:  82 12 61 a0  or  %o1, 0x1a0, %g1
a01253d4:  11 2a 00 b2  sethi  %hi(0xa802c800), %o0
a01253d8:  9a 10 20 01  mov  1, %o5
a01253dc:  9e 10 00 08  mov  %o0, %o7
a01253e0:  80 8e 60 ff  btst  0xff, %i1
a01253e4:  97 2b 40 10  sll  %o5, %l0, %o3
a01253e8:  94 04 00 01  add  %l0, %g1, %o2
a01253ec:  b0 0b 20 ff  and  %o4, 0xff, %i0
a01253f0:  02 80 00 22  be  0xa0125478
a01253f4:  92 10 3f ff  mov  -1, %o1
a01253f8:  da 0a 21 fb  ldub  [ %o0 + 0x1fb ], %o5
a01253fc:  03 2a 00 b6  sethi  %hi(0xa802d800), %g1
a0125400:  b2 12 c0 0d  or  %o3, %o5, %i1
a0125404:  b4 10 60 80  or  %g1, 0x80, %i2
a0125408:  d8 0e 80 10  ldub  [ %i2 + %l0 ], %o4
a012540c:  f2 2b e1 fb  stb  %i1, [ %o7 + 0x1fb ]
a0125410:  31 00 06 90  sethi  %hi(0x1a4000), %i0
a0125414:  96 5b 20 16  smul  %o4, 0x16, %o3
a0125418:  9e 16 22 a8  or  %i0, 0x2a8, %o7
a012541c:  90 10 00 10  mov  %l0, %o0
a0125420:  80 a3 20 ff  cmp  %o4, 0xff
a0125424:  02 80 00 03  be  0xa0125430
a0125428:  96 02 c0 0f  add  %o3, %o7, %o3
a012542c:  d2 12 e0 06  lduh  [ %o3 + 6 ], %o1
a0125430:  d8 0a a0 1b  ldub  [ %o2 + 0x1b ], %o4
a0125434:  95 2a 60 10  sll  %o1, 0x10, %o2
a0125438:  b5 32 a0 10  srl  %o2, 0x10, %i2
a012543c:  80 a3 20 ff  cmp  %o4, 0xff
a0125440:  02 80 00 13  be  0xa012548c
a0125444:  9a 03 00 0c  add  %o4, %o4, %o5
a0125448:  11 00 06 9a  sethi  %hi(0x1a6800), %o0
a012544c:  b0 10 20 01  mov  1, %i0
a0125450:  92 12 22 d8  or  %o0, 0x2d8, %o1
a0125454:  9f 2e 00 10  sll  %i0, %l0, %o7
a0125458:  d0 12 40 0d  lduh  [ %o1 + %o5 ], %o0
a012545c:  97 2a 20 10  sll  %o0, 0x10, %o3
a0125460:  a1 36 a0 07  srl  %i2, 7, %l0
a0125464:  b0 0b e0 ff  and  %o7, 0xff, %i0
a0125468:  b3 32 e0 10  srl  %o3, 0x10, %i1
a012546c:  b4 0c 20 ff  and  %l0, 0xff, %i2
a0125470:  40 00 3a d3  call  0xa0133fbc
a0125474:  81 e8 00 00  restore
a0125478:  f4 0a 21 fb  ldub  [ %o0 + 0x1fb ], %i2
a012547c:  b2 2e 80 0c  andn  %i2, %o4, %i1
a0125480:  f2 2a 21 fb  stb  %i1, [ %o0 + 0x1fb ]
a0125484:  40 00 3a c0  call  0xa0133f84
a0125488:  81 e8 00 00  restore
a012548c:  40 00 1b 38  call  0xa012c16c
a0125490:  b0 10 20 01  mov  1, %i0
a0125494:  9f 2e 00 10  sll  %i0, %l0, %o7
a0125498:  97 2a 20 10  sll  %o0, 0x10, %o3
a012549c:  a1 36 a0 07  srl  %i2, 7, %l0
a01254a0:  b0 0b e0 ff  and  %o7, 0xff, %i0
a01254a4:  b3 32 e0 10  srl  %o3, 0x10, %i1
a01254a8:  b4 0c 20 ff  and  %l0, 0xff, %i2
a01254ac:  40 00 3a c4  call  0xa0133fbc
a01254b0:  81 e8 00 00  restore
a01254b4:  01 00 00 00  nop
