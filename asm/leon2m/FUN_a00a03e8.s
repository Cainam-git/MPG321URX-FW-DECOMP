# leon2m FUN_a00a03e8 0xa00a03e8-0xa00a0508 (288 bytes)
a00a03e8:  9d e3 bf 98  save  %sp, -104, %sp
a00a03ec:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a00a03f0:  a0 13 62 90  or  %o5, 0x290, %l0	! 0xa802d290
a00a03f4:  13 2a 00 b3  sethi  %hi(0xa802cc00), %o1
a00a03f8:  c2 0c 21 a9  ldub  [ %l0 + 0x1a9 ], %g1
a00a03fc:  94 10 20 00  clr  %o2
a00a0400:  90 10 20 01  mov  1, %o0
a00a0404:  27 2a 00 ab  sethi  %hi(0xa802ac00), %l3
a00a0408:  80 a0 60 01  cmp  %g1, 1
a00a040c:  02 80 00 22  be  0xa00a0494
a00a0410:  a2 12 63 f4  or  %o1, 0x3f4, %l1
a00a0414:  40 00 1f 4a  call  0xa00a813c
a00a0418:  d2 0c 21 82  ldub  [ %l0 + 0x182 ], %o1
a00a041c:  da 04 e3 ec  ld  [ %l3 + 0x3ec ], %o5
a00a0420:  a2 03 7f f2  add  %o5, -14, %l1
a00a0424:  90 0c 60 ff  and  %l1, 0xff, %o0
a00a0428:  40 00 22 f9  call  0xa00a900c
a00a042c:  92 10 20 02  mov  2, %o1
a00a0430:  d0 0c 21 82  ldub  [ %l0 + 0x182 ], %o0
a00a0434:  98 02 20 48  add  %o0, 0x48, %o4
a00a0438:  d8 24 e3 ec  st  %o4, [ %l3 + 0x3ec ]
a00a043c:  40 00 24 85  call  0xa00a9650
a00a0440:  92 10 20 01  mov  1, %o1
a00a0444:  e6 04 20 a8  ld  [ %l0 + 0xa8 ], %l3
a00a0448:  93 34 e0 0b  srl  %l3, 0xb, %o1
a00a044c:  94 0a 60 01  and  %o1, 1, %o2
a00a0450:  d6 0c 21 82  ldub  [ %l0 + 0x182 ], %o3
a00a0454:  1f 2a 00 97  sethi  %hi(0xa8025c00), %o7
a00a0458:  11 2a 00 97  sethi  %hi(0xa8025c00), %o0
a00a045c:  92 0c f7 ff  and  %l3, -2049, %o1
a00a0460:  d6 2b e0 56  stb  %o3, [ %o7 + 0x56 ]
a00a0464:  80 8c e8 00  btst  0x800, %l3
a00a0468:  02 80 00 26  be  0xa00a0500
a00a046c:  d4 2a 20 55  stb  %o2, [ %o0 + 0x55 ]
a00a0470:  11 00 3f ff  sethi  %hi(0xfffc00), %o0
a00a0474:  e6 04 21 80  ld  [ %l0 + 0x180 ], %l3
a00a0478:  82 12 23 00  or  %o0, 0x300, %g1
a00a047c:  a4 0c c0 01  and  %l3, %g1, %l2
a00a0480:  80 a4 a1 00  cmp  %l2, 0x100
a00a0484:  02 80 00 1f  be  0xa00a0500
a00a0488:  d2 24 20 a8  st  %o1, [ %l0 + 0xa8 ]
a00a048c:  40 00 ee 19  call  0xa00dbcf0
a00a0490:  81 e8 00 00  restore
a00a0494:  d4 14 60 04  lduh  [ %l1 + 4 ], %o2
a00a0498:  19 3f ff e0  sethi  %hi(0xffff8000), %o4
a00a049c:  96 0a 80 0c  and  %o2, %o4, %o3
a00a04a0:  91 2a e0 10  sll  %o3, 0x10, %o0
a00a04a4:  80 a2 20 00  cmp  %o0, 0
a00a04a8:  9a 12 a4 00  or  %o2, 0x400, %o5
a00a04ac:  92 10 20 00  clr  %o1
a00a04b0:  12 80 00 11  bne  0xa00a04f4
a00a04b4:  90 10 20 04  mov  4, %o0
a00a04b8:  40 00 52 f2  call  0xa00b5080
a00a04bc:  c0 24 e3 ec  clr  [ %l3 + 0x3ec ]
a00a04c0:  40 00 42 a2  call  0xa00b0f48
a00a04c4:  c0 2c 60 0a  clrb  [ %l1 + 0xa ]
a00a04c8:  23 2a 00 ac  sethi  %hi(0xa802b000), %l1
a00a04cc:  c2 0c 60 8e  ldub  [ %l1 + 0x8e ], %g1	! 0xa802b08e
a00a04d0:  a4 10 60 02  or  %g1, 2, %l2
a00a04d4:  9a 10 21 16  mov  0x116, %o5
a00a04d8:  da 24 e3 ec  st  %o5, [ %l3 + 0x3ec ]
a00a04dc:  e4 2c 60 8e  stb  %l2, [ %l1 + 0x8e ]
a00a04e0:  67 ff b4 2a  call  0x4008d588
a00a04e4:  c0 2c 21 aa  clrb  [ %l0 + 0x1aa ]
a00a04e8:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a00a04ec:  10 80 00 05  b  0xa00a0500
a00a04f0:  d0 33 e0 3c  sth  %o0, [ %o7 + 0x3c ]	! 0xa802d03c
a00a04f4:  7f ff 80 ee  call  0xa00808ac
a00a04f8:  da 34 60 04  sth  %o5, [ %l1 + 4 ]
a00a04fc:  30 bf ff ef  b,a   0xa00a04b8
a00a0500:  81 c7 e0 08  ret
a00a0504:  81 e8 00 00  restore
