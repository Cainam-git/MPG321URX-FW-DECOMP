# leon2m FUN_a00ae4f0 0xa00ae4f0-0xa00ae638 (328 bytes)
a00ae4f0:  9d e3 bf 90  save  %sp, -112, %sp
a00ae4f4:  23 2a 00 b4  sethi  %hi(0xa802d000), %l1
a00ae4f8:  94 14 62 90  or  %l1, 0x290, %o2	! 0xa802d290
a00ae4fc:  d2 0a a1 a0  ldub  [ %o2 + 0x1a0 ], %o1
a00ae500:  90 0a 60 03  and  %o1, 3, %o0
a00ae504:  82 02 00 08  add  %o0, %o0, %g1
a00ae508:  a0 00 60 04  add  %g1, 4, %l0
a00ae50c:  90 10 20 00  clr  %o0
a00ae510:  92 10 20 00  clr  %o1
a00ae514:  94 10 20 00  clr  %o2
a00ae518:  40 00 16 6e  call  0xa00b3ed0
a00ae51c:  96 10 20 00  clr  %o3
a00ae520:  a0 0c 20 ff  and  %l0, 0xff, %l0
a00ae524:  90 10 20 00  clr  %o0
a00ae528:  92 10 20 00  clr  %o1
a00ae52c:  94 10 27 92  mov  0x792, %o2
a00ae530:  96 10 20 03  mov  3, %o3
a00ae534:  98 10 20 0a  mov  0xa, %o4
a00ae538:  80 a4 20 0a  cmp  %l0, 0xa
a00ae53c:  02 80 00 29  be  0xa00ae5e0
a00ae540:  9a 10 20 02  mov  2, %o5
a00ae544:  c0 23 a0 5c  clr  [ %sp + 0x5c ]
a00ae548:  90 10 20 00  clr  %o0
a00ae54c:  92 10 20 00  clr  %o1
a00ae550:  94 10 27 92  mov  0x792, %o2
a00ae554:  96 10 20 03  mov  3, %o3
a00ae558:  98 10 00 10  mov  %l0, %o4
a00ae55c:  9a 10 20 03  mov  3, %o5
a00ae560:  40 00 13 61  call  0xa00b32e4
a00ae564:  01 00 00 00  nop
a00ae568:  98 10 00 10  mov  %l0, %o4
a00ae56c:  90 10 20 00  clr  %o0
a00ae570:  92 10 20 00  clr  %o1
a00ae574:  94 10 27 92  mov  0x792, %o2
a00ae578:  96 10 20 12  mov  0x12, %o3
a00ae57c:  9a 10 20 03  mov  3, %o5
a00ae580:  40 00 13 59  call  0xa00b32e4
a00ae584:  c0 23 a0 5c  clr  [ %sp + 0x5c ]
a00ae588:  a0 14 62 90  or  %l1, 0x290, %l0
a00ae58c:  e2 0c 21 a0  ldub  [ %l0 + 0x1a0 ], %l1
a00ae590:  1f 19 99 99  sethi  %hi(0x66666400), %o7
a00ae594:  90 04 60 04  add  %l1, 4, %o0
a00ae598:  9a 13 e2 67  or  %o7, 0x267, %o5
a00ae59c:  80 5a 00 0d  smul  %o0, %o5, %g0
a00ae5a0:  99 40 00 00  rd  %y, %o4
a00ae5a4:  97 3b 20 01  sra  %o4, 1, %o3
a00ae5a8:  95 2a e0 02  sll  %o3, 2, %o2
a00ae5ac:  92 02 80 0b  add  %o2, %o3, %o1
a00ae5b0:  9e 22 00 09  sub  %o0, %o1, %o7
a00ae5b4:  82 03 ff fd  add  %o7, -3, %g1
a00ae5b8:  a2 08 60 ff  and  %g1, 0xff, %l1
a00ae5bc:  9a 0b e0 ff  and  %o7, 0xff, %o5
a00ae5c0:  80 a4 60 01  cmp  %l1, 1
a00ae5c4:  de 2c 21 a0  stb  %o7, [ %l0 + 0x1a0 ]
a00ae5c8:  18 80 00 12  bgu  0xa00ae610
a00ae5cc:  91 33 60 02  srl  %o5, 2, %o0
a00ae5d0:  40 00 28 fd  call  0xa00b89c4
a00ae5d4:  01 00 00 00  nop
a00ae5d8:  10 80 00 0f  b  0xa00ae614
a00ae5dc:  d2 0c 21 a0  ldub  [ %l0 + 0x1a0 ], %o1
a00ae5e0:  40 00 13 41  call  0xa00b32e4
a00ae5e4:  c0 23 a0 5c  clr  [ %sp + 0x5c ]
a00ae5e8:  98 10 20 11  mov  0x11, %o4
a00ae5ec:  17 00 00 0c  sethi  %hi(0x3000), %o3
a00ae5f0:  d8 23 a0 5c  st  %o4, [ %sp + 0x5c ]
a00ae5f4:  94 12 e0 92  or  %o3, 0x92, %o2
a00ae5f8:  90 10 20 01  mov  1, %o0
a00ae5fc:  92 10 20 00  clr  %o1
a00ae600:  96 10 20 03  mov  3, %o3
a00ae604:  98 10 20 0c  mov  0xc, %o4
a00ae608:  10 bf ff d6  b  0xa00ae560
a00ae60c:  9a 10 20 01  mov  1, %o5
a00ae610:  d2 0c 21 a0  ldub  [ %l0 + 0x1a0 ], %o1
a00ae614:  90 0a 60 03  and  %o1, 3, %o0
a00ae618:  7f ff fc 95  call  0xa00ad86c
a00ae61c:  92 10 20 01  mov  1, %o1
a00ae620:  21 2a 00 ac  sethi  %hi(0xa802b000), %l0
a00ae624:  d0 0c 20 8e  ldub  [ %l0 + 0x8e ], %o0	! 0xa802b08e
a00ae628:  82 12 20 02  or  %o0, 2, %g1
a00ae62c:  c2 2c 20 8e  stb  %g1, [ %l0 + 0x8e ]
a00ae630:  81 c7 e0 08  ret
a00ae634:  81 e8 00 00  restore
