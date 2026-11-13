# leon2m FUN_a0122480 0xa0122480-0xa0122634 (436 bytes)
a0122480:  9d e3 bf 98  save  %sp, -104, %sp
a0122484:  80 a0 00 18  cmp  %g0, %i0
a0122488:  03 33 c0 73  sethi  %hi(0xcf01cc00), %g1
a012248c:  b4 1e 20 04  xor  %i0, 4, %i2
a0122490:  9e 60 3f ff  subx  %g0, -1, %o7
a0122494:  ba 10 00 01  mov  %g1, %i5
a0122498:  80 a0 00 1a  cmp  %g0, %i2
a012249c:  b8 10 00 01  mov  %g1, %i4
a01224a0:  b6 10 00 01  mov  %g1, %i3
a01224a4:  aa 10 61 30  or  %g1, 0x130, %l5
a01224a8:  a8 10 61 34  or  %g1, 0x134, %l4
a01224ac:  a2 10 61 38  or  %g1, 0x138, %l1
a01224b0:  90 10 61 3c  or  %g1, 0x13c, %o0
a01224b4:  ac 10 61 c8  or  %g1, 0x1c8, %l6
a01224b8:  9a 1e 20 01  xor  %i0, 1, %o5
a01224bc:  98 1e 20 02  xor  %i0, 2, %o4
a01224c0:  94 10 61 40  or  %g1, 0x140, %o2
a01224c4:  a4 10 61 cc  or  %g1, 0x1cc, %l2
a01224c8:  96 10 61 44  or  %g1, 0x144, %o3
a01224cc:  a0 10 61 d0  or  %g1, 0x1d0, %l0
a01224d0:  ae 10 62 5c  or  %g1, 0x25c, %l7
a01224d4:  b4 60 3f ff  subx  %g0, -1, %i2
a01224d8:  92 17 61 d4  or  %i5, 0x1d4, %o1
a01224dc:  a6 17 62 60  or  %i5, 0x260, %l3
a01224e0:  b0 06 3f fd  add  %i0, -3, %i0
a01224e4:  82 10 61 48  or  %g1, 0x148, %g1
a01224e8:  80 93 c0 1a  orcc  %o7, %i2, %g0
a01224ec:  ba 17 61 4c  or  %i5, 0x14c, %i5
a01224f0:  b8 17 21 d8  or  %i4, 0x1d8, %i4
a01224f4:  02 80 00 0a  be  0xa012251c
a01224f8:  b6 16 e2 64  or  %i3, 0x264, %i3
a01224fc:  f2 25 40 00  st  %i1, [ %l5 ]
a0122500:  f2 25 00 00  st  %i1, [ %l4 ]
a0122504:  f2 24 40 00  st  %i1, [ %l1 ]
a0122508:  f2 22 00 00  st  %i1, [ %o0 ]
a012250c:  f2 22 80 00  st  %i1, [ %o2 ]
a0122510:  f2 22 c0 00  st  %i1, [ %o3 ]
a0122514:  f2 20 40 00  st  %i1, [ %g1 ]
a0122518:  f2 27 40 00  st  %i1, [ %i5 ]
a012251c:  80 a0 00 0d  cmp  %g0, %o5
a0122520:  ba 60 3f ff  subx  %g0, -1, %i5
a0122524:  80 97 40 1a  orcc  %i5, %i2, %g0
a0122528:  02 80 00 11  be  0xa012256c
a012252c:  80 a0 00 0c  cmp  %g0, %o4
a0122530:  3b 33 c0 73  sethi  %hi(0xcf01cc00), %i5
a0122534:  82 17 61 bc  or  %i5, 0x1bc, %g1	! 0xcf01cdbc
a0122538:  f2 20 40 00  st  %i1, [ %g1 ]
a012253c:  3b 33 c0 73  sethi  %hi(0xcf01cc00), %i5
a0122540:  82 17 61 c0  or  %i5, 0x1c0, %g1	! 0xcf01cdc0
a0122544:  f2 20 40 00  st  %i1, [ %g1 ]
a0122548:  3b 33 c0 73  sethi  %hi(0xcf01cc00), %i5
a012254c:  82 17 61 c4  or  %i5, 0x1c4, %g1	! 0xcf01cdc4
a0122550:  f2 20 40 00  st  %i1, [ %g1 ]
a0122554:  f2 25 80 00  st  %i1, [ %l6 ]
a0122558:  f2 24 80 00  st  %i1, [ %l2 ]
a012255c:  f2 24 00 00  st  %i1, [ %l0 ]
a0122560:  f2 22 40 00  st  %i1, [ %o1 ]
a0122564:  f2 27 00 00  st  %i1, [ %i4 ]
a0122568:  80 a0 00 0c  cmp  %g0, %o4
a012256c:  b8 60 3f ff  subx  %g0, -1, %i4
a0122570:  80 97 00 1a  orcc  %i4, %i2, %g0
a0122574:  02 80 00 15  be  0xa01225c8
a0122578:  80 a6 20 01  cmp  %i0, 1
a012257c:  03 33 c0 73  sethi  %hi(0xcf01cc00), %g1
a0122580:  b4 10 62 48  or  %g1, 0x248, %i2	! 0xcf01ce48
a0122584:  39 33 c0 73  sethi  %hi(0xcf01cc00), %i4
a0122588:  f2 26 80 00  st  %i1, [ %i2 ]
a012258c:  ba 17 22 4c  or  %i4, 0x24c, %i5
a0122590:  03 33 c0 73  sethi  %hi(0xcf01cc00), %g1
a0122594:  f2 27 40 00  st  %i1, [ %i5 ]
a0122598:  b4 10 62 50  or  %g1, 0x250, %i2
a012259c:  39 33 c0 73  sethi  %hi(0xcf01cc00), %i4
a01225a0:  f2 26 80 00  st  %i1, [ %i2 ]
a01225a4:  ba 17 22 54  or  %i4, 0x254, %i5
a01225a8:  03 33 c0 73  sethi  %hi(0xcf01cc00), %g1
a01225ac:  f2 27 40 00  st  %i1, [ %i5 ]
a01225b0:  b4 10 62 58  or  %g1, 0x258, %i2
a01225b4:  f2 26 80 00  st  %i1, [ %i2 ]
a01225b8:  f2 25 c0 00  st  %i1, [ %l7 ]
a01225bc:  f2 24 c0 00  st  %i1, [ %l3 ]
a01225c0:  f2 26 c0 00  st  %i1, [ %i3 ]
a01225c4:  80 a6 20 01  cmp  %i0, 1
a01225c8:  18 80 00 19  bgu  0xa012262c
a01225cc:  39 33 c0 73  sethi  %hi(0xcf01cc00), %i4
a01225d0:  ba 17 22 d4  or  %i4, 0x2d4, %i5	! 0xcf01ced4
a01225d4:  37 33 c0 73  sethi  %hi(0xcf01cc00), %i3
a01225d8:  f2 27 40 00  st  %i1, [ %i5 ]
a01225dc:  b0 16 e2 d8  or  %i3, 0x2d8, %i0
a01225e0:  03 33 c0 73  sethi  %hi(0xcf01cc00), %g1
a01225e4:  f2 26 00 00  st  %i1, [ %i0 ]
a01225e8:  b4 10 62 dc  or  %g1, 0x2dc, %i2
a01225ec:  39 33 c0 73  sethi  %hi(0xcf01cc00), %i4
a01225f0:  f2 26 80 00  st  %i1, [ %i2 ]
a01225f4:  ba 17 22 e0  or  %i4, 0x2e0, %i5
a01225f8:  37 33 c0 73  sethi  %hi(0xcf01cc00), %i3
a01225fc:  f2 27 40 00  st  %i1, [ %i5 ]
a0122600:  b0 16 e2 e4  or  %i3, 0x2e4, %i0
a0122604:  03 33 c0 73  sethi  %hi(0xcf01cc00), %g1
a0122608:  f2 26 00 00  st  %i1, [ %i0 ]
a012260c:  b4 10 62 e8  or  %g1, 0x2e8, %i2
a0122610:  39 33 c0 73  sethi  %hi(0xcf01cc00), %i4
a0122614:  f2 26 80 00  st  %i1, [ %i2 ]
a0122618:  ba 17 22 ec  or  %i4, 0x2ec, %i5
a012261c:  37 33 c0 73  sethi  %hi(0xcf01cc00), %i3
a0122620:  f2 27 40 00  st  %i1, [ %i5 ]
a0122624:  b0 16 e2 f0  or  %i3, 0x2f0, %i0
a0122628:  f2 26 00 00  st  %i1, [ %i0 ]
a012262c:  81 c7 e0 08  ret
a0122630:  81 e8 00 00  restore
