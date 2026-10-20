# leon2m FUN_a009c4a4 0xa009c4a4-0xa009c590 (236 bytes)
a009c4a4:  9d e3 bf 98  save  %sp, -104, %sp
a009c4a8:  35 2a 00 ab  sethi  %hi(0xa802ac00), %i2
a009c4ac:  d2 06 a3 ec  ld  [ %i2 + 0x3ec ], %o1	! 0xa802afec
a009c4b0:  90 02 7f 9c  add  %o1, -100, %o0
a009c4b4:  40 00 33 c2  call  0xa00a93bc
a009c4b8:  90 0a 20 ff  and  %o0, 0xff, %o0
a009c4bc:  03 19 99 99  sethi  %hi(0x66666400), %g1
a009c4c0:  b2 10 62 67  or  %g1, 0x267, %i1	! 0x66666667
a009c4c4:  d0 16 a3 ee  lduh  [ %i2 + 0x3ee ], %o0
a009c4c8:  9e 02 3f a0  add  %o0, -96, %o7
a009c4cc:  80 5b c0 19  smul  %o7, %i1, %g0
a009c4d0:  97 40 00 00  rd  %y, %o3
a009c4d4:  93 3a e0 01  sra  %o3, 1, %o1
a009c4d8:  95 3b e0 1f  sra  %o7, 0x1f, %o2
a009c4dc:  82 22 40 0a  sub  %o1, %o2, %g1
a009c4e0:  b1 28 60 02  sll  %g1, 2, %i0
a009c4e4:  98 06 00 01  add  %i0, %g1, %o4
a009c4e8:  96 23 c0 0c  sub  %o7, %o4, %o3
a009c4ec:  9a 02 e0 64  add  %o3, 0x64, %o5
a009c4f0:  da 26 a3 ec  st  %o5, [ %i2 + 0x3ec ]
a009c4f4:  40 00 3a 0f  call  0xa00aad30
a009c4f8:  90 0a e0 ff  and  %o3, 0xff, %o0
a009c4fc:  94 0a 20 ff  and  %o0, 0xff, %o2
a009c500:  80 a2 a0 01  cmp  %o2, 1
a009c504:  12 bf ff f1  bne  0xa009c4c8
a009c508:  d0 16 a3 ee  lduh  [ %i2 + 0x3ee ], %o0
a009c50c:  da 06 a3 ec  ld  [ %i2 + 0x3ec ], %o5
a009c510:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a009c514:  b0 13 22 90  or  %o4, 0x290, %i0	! 0xa802d290
a009c518:  b2 03 7f 9c  add  %o5, -100, %i1
a009c51c:  d6 06 20 34  ld  [ %i0 + 0x34 ], %o3
a009c520:  90 0e 60 0f  and  %i1, 0xf, %o0
a009c524:  1f 00 03 c0  sethi  %hi(0xf0000), %o7
a009c528:  92 2a c0 0f  andn  %o3, %o7, %o1
a009c52c:  95 2a 20 10  sll  %o0, 0x10, %o2
a009c530:  82 12 40 0a  or  %o1, %o2, %g1
a009c534:  40 00 e4 f1  call  0xa00d58f8
a009c538:  c2 26 20 34  st  %g1, [ %i0 + 0x34 ]
a009c53c:  40 00 e4 e7  call  0xa00d58d8
a009c540:  b0 10 20 01  mov  1, %i0
a009c544:  40 00 e1 15  call  0xa00d4998
a009c548:  01 00 00 00  nop
a009c54c:  d8 06 a3 ec  ld  [ %i2 + 0x3ec ], %o4
a009c550:  9a 03 3f 9c  add  %o4, -100, %o5
a009c554:  90 0b 60 ff  and  %o5, 0xff, %o0
a009c558:  40 00 34 3e  call  0xa00a9650
a009c55c:  92 10 20 01  mov  1, %o1
a009c560:  f2 06 a3 ec  ld  [ %i2 + 0x3ec ], %i1
a009c564:  9e 06 7f 9c  add  %i1, -100, %o7
a009c568:  35 2a 00 97  sethi  %hi(0xa8025c00), %i2
a009c56c:  f2 0e a0 56  ldub  [ %i2 + 0x56 ], %i1	! 0xa8025c56
a009c570:  80 a3 c0 19  cmp  %o7, %i1
a009c574:  02 80 00 04  be  0xa009c584
a009c578:  b4 10 20 00  clr  %i2
a009c57c:  b0 10 20 01  mov  1, %i0
a009c580:  b4 10 20 01  mov  1, %i2
a009c584:  40 00 2e ee  call  0xa00a813c
a009c588:  81 e8 00 00  restore
a009c58c:  01 00 00 00  nop
