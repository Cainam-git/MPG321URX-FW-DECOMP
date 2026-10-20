# leon2m FUN_a00e03b0 0xa00e03b0-0xa00e0514 (356 bytes)
a00e03b0:  9d e3 bf 88  save  %sp, -120, %sp
a00e03b4:  83 36 60 08  srl  %i1, 8, %g1
a00e03b8:  a0 08 60 0f  and  %g1, 0xf, %l0
a00e03bc:  80 a6 20 02  cmp  %i0, 2
a00e03c0:  14 80 00 35  bg  0xa00e0494
a00e03c4:  a2 0e 60 ff  and  %i1, 0xff, %l1
a00e03c8:  15 33 c0 8a  sethi  %hi(0xcf022800), %o2
a00e03cc:  13 33 c0 8b  sethi  %hi(0xcf022c00), %o1
a00e03d0:  11 33 c0 8c  sethi  %hi(0xcf023000), %o0
a00e03d4:  9f 2e 20 02  sll  %i0, 2, %o7
a00e03d8:  a6 07 bf f8  add  %fp, -8, %l3
a00e03dc:  d4 27 bf e8  st  %o2, [ %fp + -24 ]
a00e03e0:  d2 27 bf ec  st  %o1, [ %fp + -20 ]
a00e03e4:  d0 27 bf f0  st  %o0, [ %fp + -16 ]
a00e03e8:  96 03 c0 13  add  %o7, %l3, %o3
a00e03ec:  da 02 ff f0  ld  [ %o3 + -16 ], %o5
a00e03f0:  80 a4 60 fe  cmp  %l1, 0xfe
a00e03f4:  02 80 00 3d  be  0xa00e04e8
a00e03f8:  99 2c 60 02  sll  %l1, 2, %o4
a00e03fc:  25 2a 00 97  sethi  %hi(0xa8025c00), %l2
a00e0400:  96 14 a1 10  or  %l2, 0x110, %o3	! 0xa8025d10
a00e0404:  c2 0a c0 18  ldub  [ %o3 + %i0 ], %g1
a00e0408:  80 a0 40 10  cmp  %g1, %l0
a00e040c:  02 80 00 07  be  0xa00e0428
a00e0410:  01 00 00 00  nop
a00e0414:  e0 23 63 f8  st  %l0, [ %o5 + 0x3f8 ]
a00e0418:  d4 27 bf e8  st  %o2, [ %fp + -24 ]
a00e041c:  d2 27 bf ec  st  %o1, [ %fp + -20 ]
a00e0420:  d0 27 bf f0  st  %o0, [ %fp + -16 ]
a00e0424:  e0 2a c0 18  stb  %l0, [ %o3 + %i0 ]
a00e0428:  f4 23 40 0c  st  %i2, [ %o5 + %o4 ]
a00e042c:  15 2a 00 ad  sethi  %hi(0xa802b400), %o2
a00e0430:  da 02 a1 50  ld  [ %o2 + 0x150 ], %o5	! 0xa802b550
a00e0434:  80 a3 60 00  cmp  %o5, 0
a00e0438:  02 80 00 35  be  0xa00e050c
a00e043c:  90 14 a1 10  or  %l2, 0x110, %o0
a00e0440:  d8 0a 00 18  ldub  [ %o0 + %i0 ], %o4
a00e0444:  17 33 c0 8a  sethi  %hi(0xcf022800), %o3
a00e0448:  13 33 c0 8b  sethi  %hi(0xcf022c00), %o1
a00e044c:  35 33 c0 8c  sethi  %hi(0xcf023000), %i2
a00e0450:  a4 03 c0 13  add  %o7, %l3, %l2
a00e0454:  d6 27 bf e8  st  %o3, [ %fp + -24 ]
a00e0458:  d2 27 bf ec  st  %o1, [ %fp + -20 ]
a00e045c:  f4 27 bf f0  st  %i2, [ %fp + -16 ]
a00e0460:  80 a3 00 10  cmp  %o4, %l0
a00e0464:  99 2c 60 02  sll  %l1, 2, %o4
a00e0468:  02 80 00 04  be  0xa00e0478
a00e046c:  c2 04 bf f0  ld  [ %l2 + -16 ], %g1
a00e0470:  e0 20 63 f8  st  %l0, [ %g1 + 0x3f8 ]
a00e0474:  e0 2a 00 18  stb  %l0, [ %o0 + %i0 ]
a00e0478:  1f 00 06 65  sethi  %hi(0x199400), %o7
a00e047c:  d6 00 40 0c  ld  [ %g1 + %o4 ], %o3
a00e0480:  90 13 e0 10  or  %o7, 0x10, %o0
a00e0484:  92 10 00 18  mov  %i0, %o1
a00e0488:  7f ff fb 3a  call  0xa00df170
a00e048c:  94 10 00 19  mov  %i1, %o2
a00e0490:  30 80 00 1f  b,a   0xa00e050c
a00e0494:  7f ff fc de  call  0xa00df80c
a00e0498:  01 00 00 00  nop
a00e049c:  40 00 01 cf  call  0xa00e0bd8
a00e04a0:  01 00 00 00  nop
a00e04a4:  11 00 06 65  sethi  %hi(0x199400), %o0
a00e04a8:  92 10 00 18  mov  %i0, %o1
a00e04ac:  7f ff fb 31  call  0xa00df170
a00e04b0:  90 12 20 30  or  %o0, 0x30, %o0
a00e04b4:  15 33 c0 8a  sethi  %hi(0xcf022800), %o2
a00e04b8:  13 33 c0 8b  sethi  %hi(0xcf022c00), %o1
a00e04bc:  11 33 c0 8c  sethi  %hi(0xcf023000), %o0
a00e04c0:  9f 2e 20 02  sll  %i0, 2, %o7
a00e04c4:  a6 07 bf f8  add  %fp, -8, %l3
a00e04c8:  d4 27 bf e8  st  %o2, [ %fp + -24 ]
a00e04cc:  d2 27 bf ec  st  %o1, [ %fp + -20 ]
a00e04d0:  d0 27 bf f0  st  %o0, [ %fp + -16 ]
a00e04d4:  96 03 c0 13  add  %o7, %l3, %o3
a00e04d8:  da 02 ff f0  ld  [ %o3 + -16 ], %o5
a00e04dc:  80 a4 60 fe  cmp  %l1, 0xfe
a00e04e0:  12 bf ff c7  bne  0xa00e03fc
a00e04e4:  99 2c 60 02  sll  %l1, 2, %o4
a00e04e8:  25 2a 00 97  sethi  %hi(0xa8025c00), %l2
a00e04ec:  98 14 a1 10  or  %l2, 0x110, %o4	! 0xa8025d10
a00e04f0:  d2 0b 00 18  ldub  [ %o4 + %i0 ], %o1
a00e04f4:  80 a2 40 1a  cmp  %o1, %i2
a00e04f8:  02 bf ff ce  be  0xa00e0430
a00e04fc:  15 2a 00 ad  sethi  %hi(0xa802b400), %o2
a00e0500:  f4 23 63 f8  st  %i2, [ %o5 + 0x3f8 ]
a00e0504:  10 bf ff ca  b  0xa00e042c
a00e0508:  f4 2b 00 18  stb  %i2, [ %o4 + %i0 ]
a00e050c:  81 c7 e0 08  ret
a00e0510:  81 e8 00 00  restore
