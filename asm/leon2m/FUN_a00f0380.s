# leon2m FUN_a00f0380 0xa00f0380-0xa00f04f8 (376 bytes)
a00f0380:  9d e3 bf 98  save  %sp, -104, %sp
a00f0384:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00f0388:  92 10 20 51  mov  0x51, %o1
a00f038c:  40 00 07 b2  call  0xa00f2254
a00f0390:  90 10 00 18  mov  %i0, %o0
a00f0394:  95 2e 60 10  sll  %i1, 0x10, %o2
a00f0398:  23 2a 00 ad  sethi  %hi(0xa802b400), %l1
a00f039c:  a0 10 00 08  mov  %o0, %l0
a00f03a0:  99 32 a0 10  srl  %o2, 0x10, %o4
a00f03a4:  d2 0c 63 50  ldub  [ %l1 + 0x350 ], %o1
a00f03a8:  80 a0 00 0c  cmp  %g0, %o4
a00f03ac:  91 32 60 01  srl  %o1, 1, %o0
a00f03b0:  82 0a 20 01  and  %o0, 1, %g1
a00f03b4:  9a 60 3f ff  subx  %g0, -1, %o5
a00f03b8:  80 90 40 0d  orcc  %g1, %o5, %g0
a00f03bc:  02 80 00 0c  be  0xa00f03ec
a00f03c0:  a4 10 20 00  clr  %l2
a00f03c4:  80 a3 20 00  cmp  %o4, 0
a00f03c8:  22 80 00 26  be,a   0xa00f0460
a00f03cc:  9a 0c 20 ff  and  %l0, 0xff, %o5
a00f03d0:  80 a3 21 2c  cmp  %o4, 0x12c
a00f03d4:  02 80 00 42  be  0xa00f04dc
a00f03d8:  80 8e a0 01  btst  1, %i2
a00f03dc:  12 80 00 35  bne  0xa00f04b0
a00f03e0:  80 8c 20 ff  btst  0xff, %l0
a00f03e4:  12 80 00 27  bne  0xa00f0480
a00f03e8:  90 04 3f ff  add  %l0, -1, %o0
a00f03ec:  99 2e 60 10  sll  %i1, 0x10, %o4
a00f03f0:  b3 33 20 10  srl  %o4, 0x10, %i1
a00f03f4:  80 a0 00 19  cmp  %g0, %i1
a00f03f8:  d6 0c 63 50  ldub  [ %l1 + 0x350 ], %o3
a00f03fc:  94 0a e0 01  and  %o3, 1, %o2
a00f0400:  92 60 3f ff  subx  %g0, -1, %o1
a00f0404:  80 92 80 09  orcc  %o2, %o1, %g0
a00f0408:  22 80 00 39  be,a   0xa00f04ec
a00f040c:  f4 2c 63 50  stb  %i2, [ %l1 + 0x350 ]
a00f0410:  80 a6 60 00  cmp  %i1, 0
a00f0414:  22 80 00 0e  be,a   0xa00f044c
a00f0418:  33 2a 00 ad  sethi  %hi(0xa802b400), %i1
a00f041c:  80 a6 61 2c  cmp  %i1, 0x12c
a00f0420:  02 80 00 2b  be  0xa00f04cc
a00f0424:  80 8e a0 02  btst  2, %i2
a00f0428:  12 80 00 1c  bne  0xa00f0498
a00f042c:  9a 04 3f ff  add  %l0, -1, %o5
a00f0430:  9e 04 20 01  add  %l0, 1, %o7
a00f0434:  90 10 00 18  mov  %i0, %o0
a00f0438:  94 0b e0 ff  and  %o7, 0xff, %o2
a00f043c:  40 00 07 97  call  0xa00f2298
a00f0440:  92 10 20 51  mov  0x51, %o1
a00f0444:  10 80 00 2a  b  0xa00f04ec
a00f0448:  f4 2c 63 50  stb  %i2, [ %l1 + 0x350 ]
a00f044c:  80 8e a0 01  btst  1, %i2
a00f0450:  02 80 00 26  be  0xa00f04e8
a00f0454:  e0 2e 63 51  stb  %l0, [ %i1 + 0x351 ]
a00f0458:  10 bf ff f7  b  0xa00f0434
a00f045c:  9e 04 20 01  add  %l0, 1, %o7
a00f0460:  80 a0 00 0d  cmp  %g0, %o5
a00f0464:  98 40 20 00  addx  %g0, 0, %o4
a00f0468:  9f 36 a0 01  srl  %i2, 1, %o7
a00f046c:  17 2a 00 ad  sethi  %hi(0xa802b400), %o3
a00f0470:  80 8b c0 0c  btst  %o7, %o4
a00f0474:  02 bf ff de  be  0xa00f03ec
a00f0478:  e0 2a e3 51  stb  %l0, [ %o3 + 0x351 ]
a00f047c:  90 04 3f ff  add  %l0, -1, %o0
a00f0480:  94 0a 20 ff  and  %o0, 0xff, %o2
a00f0484:  90 10 00 18  mov  %i0, %o0
a00f0488:  40 00 07 84  call  0xa00f2298
a00f048c:  92 10 20 51  mov  0x51, %o1
a00f0490:  10 bf ff d8  b  0xa00f03f0
a00f0494:  99 2e 60 10  sll  %i1, 0x10, %o4
a00f0498:  90 10 00 18  mov  %i0, %o0
a00f049c:  94 0b 60 ff  and  %o5, 0xff, %o2
a00f04a0:  40 00 07 7e  call  0xa00f2298
a00f04a4:  92 10 20 51  mov  0x51, %o1
a00f04a8:  10 80 00 10  b  0xa00f04e8
a00f04ac:  a4 10 20 01  mov  1, %l2
a00f04b0:  a4 04 20 01  add  %l0, 1, %l2
a00f04b4:  94 0c a0 ff  and  %l2, 0xff, %o2
a00f04b8:  90 10 00 18  mov  %i0, %o0
a00f04bc:  40 00 07 77  call  0xa00f2298
a00f04c0:  92 10 20 51  mov  0x51, %o1
a00f04c4:  10 bf ff ca  b  0xa00f03ec
a00f04c8:  a4 10 20 01  mov  1, %l2
a00f04cc:  21 2a 00 ad  sethi  %hi(0xa802b400), %l0
a00f04d0:  90 10 00 18  mov  %i0, %o0
a00f04d4:  10 bf ff da  b  0xa00f043c
a00f04d8:  d4 0c 23 51  ldub  [ %l0 + 0x351 ], %o2
a00f04dc:  03 2a 00 ad  sethi  %hi(0xa802b400), %g1
a00f04e0:  10 bf ff e9  b  0xa00f0484
a00f04e4:  d4 08 63 51  ldub  [ %g1 + 0x351 ], %o2	! 0xa802b751
a00f04e8:  f4 2c 63 50  stb  %i2, [ %l1 + 0x350 ]
a00f04ec:  b0 0c a0 01  and  %l2, 1, %i0
a00f04f0:  81 c7 e0 08  ret
a00f04f4:  81 e8 00 00  restore
