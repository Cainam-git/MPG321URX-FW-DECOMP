# leon2m FUN_a01483f4 0xa01483f4-0xa0148500 (268 bytes)  [FUN_a01484f8 = unreachable ret/restore tail, merged]
a01483f4:  9d e3 bf 98  save  %sp, -104, %sp
a01483f8:  03 2a 00 b8  sethi  %hi(0xa802e000), %g1
a01483fc:  a0 10 63 78  or  %g1, 0x378, %l0	! 0xa802e378
a0148400:  82 10 20 00  clr  %g1
a0148404:  96 00 60 01  add  %g1, 1, %o3
a0148408:  95 28 60 10  sll  %g1, 0x10, %o2
a014840c:  91 32 a0 10  srl  %o2, 0x10, %o0
a0148410:  93 2a e0 10  sll  %o3, 0x10, %o1
a0148414:  9b 32 60 10  srl  %o1, 0x10, %o5
a0148418:  d8 0e 00 08  ldub  [ %i0 + %o0 ], %o4
a014841c:  d8 2a 00 10  stb  %o4, [ %o0 + %l0 ]
a0148420:  80 a3 60 57  cmp  %o5, 0x57
a0148424:  08 bf ff f8  bleu  0xa0148404
a0148428:  82 10 00 0b  mov  %o3, %g1
a014842c:  15 00 06 9b  sethi  %hi(0x1a6c00), %o2
a0148430:  90 12 a2 90  or  %o2, 0x290, %o0	! 0x1a6e90
a0148434:  d8 04 20 1c  ld  [ %l0 + 0x1c ], %o4
a0148438:  d6 04 20 18  ld  [ %l0 + 0x18 ], %o3
a014843c:  d2 04 20 10  ld  [ %l0 + 0x10 ], %o1
a0148440:  7f fe 5b 4c  call  0xa00df170
a0148444:  d4 04 20 14  ld  [ %l0 + 0x14 ], %o2
a0148448:  13 00 06 9b  sethi  %hi(0x1a6c00), %o1
a014844c:  90 12 62 a0  or  %o1, 0x2a0, %o0	! 0x1a6ea0
a0148450:  d2 14 20 20  lduh  [ %l0 + 0x20 ], %o1
a0148454:  d4 14 20 22  lduh  [ %l0 + 0x22 ], %o2
a0148458:  7f fe 5b 46  call  0xa00df170
a014845c:  d6 14 20 24  lduh  [ %l0 + 0x24 ], %o3
a0148460:  17 00 06 9b  sethi  %hi(0x1a6c00), %o3
a0148464:  90 12 e2 b8  or  %o3, 0x2b8, %o0	! 0x1a6eb8
a0148468:  d2 14 20 2a  lduh  [ %l0 + 0x2a ], %o1
a014846c:  d4 14 20 2c  lduh  [ %l0 + 0x2c ], %o2
a0148470:  7f fe 5b 40  call  0xa00df170
a0148474:  d6 14 20 2e  lduh  [ %l0 + 0x2e ], %o3
a0148478:  d6 14 20 20  lduh  [ %l0 + 0x20 ], %o3
a014847c:  da 14 20 08  lduh  [ %l0 + 8 ], %o5
a0148480:  19 0a aa aa  sethi  %hi(0x2aaaa800), %o4
a0148484:  b0 22 c0 0d  sub  %o3, %o5, %i0
a0148488:  90 13 22 ab  or  %o4, 0x2ab, %o0
a014848c:  80 5e 00 08  smul  %i0, %o0, %g0
a0148490:  83 40 00 00  rd  %y, %g1
a0148494:  95 38 60 03  sra  %g1, 3, %o2
a0148498:  9f 3e 20 1f  sra  %i0, 0x1f, %o7
a014849c:  92 22 80 0f  sub  %o2, %o7, %o1
a01484a0:  91 2a 60 04  sll  %o1, 4, %o0
a01484a4:  d0 34 20 28  sth  %o0, [ %l0 + 0x28 ]
a01484a8:  d0 34 20 26  sth  %o0, [ %l0 + 0x26 ]
a01484ac:  94 10 20 00  clr  %o2
a01484b0:  40 00 33 56  call  0xa0155208
a01484b4:  d0 1c 20 10  ldd  [ %l0 + 0x10 ], %o0
a01484b8:  da 14 20 2a  lduh  [ %l0 + 0x2a ], %o5
a01484bc:  94 10 20 00  clr  %o2
a01484c0:  40 00 33 52  call  0xa0155208
a01484c4:  96 10 00 0d  mov  %o5, %o3
a01484c8:  83 2a 60 02  sll  %o1, 2, %g1
a01484cc:  b0 80 40 09  addcc  %g1, %o1, %i0
a01484d0:  9e 06 00 18  add  %i0, %i0, %o7
a01484d4:  de 34 20 48  sth  %o7, [ %l0 + 0x48 ]
a01484d8:  7f ff e4 da  call  0xa0141840
a01484dc:  01 00 00 00  nop
a01484e0:  80 8e 60 ff  btst  0xff, %i1
a01484e4:  02 80 00 04  be  0xa01484f4
a01484e8:  01 00 00 00  nop
a01484ec:  7f fe e7 c2  call  0xa01023f4
a01484f0:  91 e8 20 00  restore  %g0, 0, %o0
a01484f4:  01 00 00 00  nop
a01484f8:  81 c7 e0 08  ret
a01484fc:  81 e8 00 00  restore
