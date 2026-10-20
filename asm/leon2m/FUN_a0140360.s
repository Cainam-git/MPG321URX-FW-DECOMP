# leon2m FUN_a0140360 0xa0140360-0xa0140500 (416 bytes)
a0140360:  9d e3 bf 88  save  %sp, -120, %sp
a0140364:  94 0e 20 ff  and  %i0, 0xff, %o2
a0140368:  13 00 06 9a  sethi  %hi(0x1a6800), %o1
a014036c:  90 12 61 fe  or  %o1, 0x1fe, %o0	! 0x1a69fe
a0140370:  96 5a a0 26  smul  %o2, 0x26, %o3
a0140374:  c2 4a 00 0b  ldsb  [ %o0 + %o3 ], %g1
a0140378:  80 a0 60 00  cmp  %g1, 0
a014037c:  b0 10 00 19  mov  %i1, %i0
a0140380:  9e 10 00 1a  mov  %i2, %o7
a0140384:  06 80 00 1b  bl  0xa01403f0
a0140388:  c2 0a 00 0b  ldub  [ %o0 + %o3 ], %g1
a014038c:  90 08 60 ff  and  %g1, 0xff, %o0
a0140390:  9f 2a 20 02  sll  %o0, 2, %o7
a0140394:  b0 03 c0 08  add  %o7, %o0, %i0
a0140398:  13 00 06 9a  sethi  %hi(0x1a6800), %o1
a014039c:  98 12 61 e0  or  %o1, 0x1e0, %o4	! 0x1a69e0
a01403a0:  94 06 00 18  add  %i0, %i0, %o2
a01403a4:  9a 02 80 0c  add  %o2, %o4, %o5
a01403a8:  93 2e 60 10  sll  %i1, 0x10, %o1
a01403ac:  d6 13 00 0a  lduh  [ %o4 + %o2 ], %o3
a01403b0:  b3 2e a0 10  sll  %i2, 0x10, %i1
a01403b4:  d0 13 60 02  lduh  [ %o5 + 2 ], %o0
a01403b8:  de 13 60 08  lduh  [ %o5 + 8 ], %o7
a01403bc:  c2 13 60 04  lduh  [ %o5 + 4 ], %g1
a01403c0:  f4 13 60 06  lduh  [ %o5 + 6 ], %i2
a01403c4:  d6 37 bf e8  sth  %o3, [ %fp + -24 ]
a01403c8:  d0 37 bf ea  sth  %o0, [ %fp + -22 ]
a01403cc:  c2 37 bf ec  sth  %g1, [ %fp + -20 ]
a01403d0:  f4 37 bf ee  sth  %i2, [ %fp + -18 ]
a01403d4:  de 37 bf f0  sth  %o7, [ %fp + -16 ]
a01403d8:  93 32 60 10  srl  %o1, 0x10, %o1
a01403dc:  95 36 60 10  srl  %i1, 0x10, %o2
a01403e0:  96 10 00 1b  mov  %i3, %o3
a01403e4:  67 fd 2d d1  call  0x4008bb28
a01403e8:  90 07 bf e8  add  %fp, -24, %o0
a01403ec:  30 80 00 43  b,a   0xa01404f8
a01403f0:  92 08 60 ff  and  %g1, 0xff, %o1
a01403f4:  b3 2a 60 03  sll  %o1, 3, %i1
a01403f8:  82 06 40 09  add  %i1, %o1, %g1
a01403fc:  19 00 06 9a  sethi  %hi(0x1a6800), %o4
a0140400:  9a 13 22 24  or  %o4, 0x224, %o5	! 0x1a6a24
a0140404:  b5 28 60 02  sll  %g1, 2, %i2
a0140408:  b2 06 80 0d  add  %i2, %o5, %i1
a014040c:  d8 0e 60 02  ldub  [ %i1 + 2 ], %o4
a0140410:  80 a3 20 00  cmp  %o4, 0
a0140414:  02 80 00 28  be  0xa01404b4
a0140418:  98 02 40 09  add  %o1, %o1, %o4
a014041c:  96 02 c0 08  add  %o3, %o0, %o3
a0140420:  9a 03 00 09  add  %o4, %o1, %o5
a0140424:  f4 0a e0 01  ldub  [ %o3 + 1 ], %i2
a0140428:  11 2a 00 b2  sethi  %hi(0xa802c800), %o0
a014042c:  93 2b 60 02  sll  %o5, 2, %o1
a0140430:  82 12 23 dc  or  %o0, 0x3dc, %g1
a0140434:  17 2a 00 b3  sethi  %hi(0xa802cc00), %o3
a0140438:  99 2e a0 0b  sll  %i2, 0xb, %o4
a014043c:  f2 10 40 09  lduh  [ %g1 + %o1 ], %i1
a0140440:  95 2a a0 02  sll  %o2, 2, %o2
a0140444:  90 12 e0 00  mov  %o3, %o0
a0140448:  92 03 00 19  add  %o4, %i1, %o1
a014044c:  da 12 00 0a  lduh  [ %o0 + %o2 ], %o5
a0140450:  98 02 40 0d  add  %o1, %o5, %o4
a0140454:  95 2b e0 10  sll  %o7, 0x10, %o2
a0140458:  91 32 a0 10  srl  %o2, 0x10, %o0
a014045c:  9f 2b 20 10  sll  %o4, 0x10, %o7
a0140460:  99 33 e0 10  srl  %o7, 0x10, %o4
a0140464:  80 a2 20 00  cmp  %o0, 0
a0140468:  02 80 00 24  be  0xa01404f8
a014046c:  94 10 20 00  clr  %o2
a0140470:  03 00 00 00  sethi  %hi(0), %g1
a0140474:  92 10 60 00  mov  %g1, %o1	! 0x0
a0140478:  b5 2e 20 10  sll  %i0, 0x10, %i2
a014047c:  b2 03 00 09  add  %o4, %o1, %i1
a0140480:  b1 36 a0 10  srl  %i2, 0x10, %i0
a0140484:  92 06 40 18  add  %i1, %i0, %o1
a0140488:  96 02 a0 01  add  %o2, 1, %o3
a014048c:  b1 2a a0 10  sll  %o2, 0x10, %i0
a0140490:  9f 36 20 10  srl  %i0, 0x10, %o7
a0140494:  95 2a e0 10  sll  %o3, 0x10, %o2
a0140498:  9b 32 a0 10  srl  %o2, 0x10, %o5
a014049c:  d8 0a 40 0f  ldub  [ %o1 + %o7 ], %o4
a01404a0:  d8 2b c0 1b  stb  %o4, [ %o7 + %i3 ]
a01404a4:  80 a3 40 08  cmp  %o5, %o0
a01404a8:  0a bf ff f8  bcs  0xa0140488
a01404ac:  94 10 00 0b  mov  %o3, %o2
a01404b0:  30 80 00 12  b,a   0xa01404f8
a01404b4:  94 03 00 09  add  %o4, %o1, %o2
a01404b8:  1b 2a 00 b2  sethi  %hi(0xa802c800), %o5
a01404bc:  99 2a a0 02  sll  %o2, 2, %o4
a01404c0:  92 13 63 dc  or  %o5, 0x3dc, %o1
a01404c4:  b4 03 00 09  add  %o4, %o1, %i2
a01404c8:  d4 0e a0 08  ldub  [ %i2 + 8 ], %o2
a01404cc:  80 a2 a0 ff  cmp  %o2, 0xff
a01404d0:  02 80 00 08  be  0xa01404f0
a01404d4:  b4 02 c0 08  add  %o3, %o0, %i2
a01404d8:  f2 0e a0 04  ldub  [ %i2 + 4 ], %i1
a01404dc:  83 2e 60 08  sll  %i1, 8, %g1
a01404e0:  96 5a 80 01  smul  %o2, %g1, %o3
a01404e4:  d0 12 40 0c  lduh  [ %o1 + %o4 ], %o0
a01404e8:  10 bf ff db  b  0xa0140454
a01404ec:  98 02 c0 08  add  %o3, %o0, %o4
a01404f0:  10 bf ff d9  b  0xa0140454
a01404f4:  d8 12 40 0c  lduh  [ %o1 + %o4 ], %o4
a01404f8:  81 c7 e0 08  ret
a01404fc:  81 e8 00 00  restore
