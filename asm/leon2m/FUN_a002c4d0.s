# leon2m FUN_a002c4d0 0xa002c4d0-0xa002c5f8 (296 bytes)
a002c4d0:  9d e3 bf 98  save  %sp, -104, %sp
a002c4d4:  b0 0e 20 ff  and  %i0, 0xff, %i0
a002c4d8:  80 a6 20 01  cmp  %i0, 1
a002c4dc:  22 80 00 11  be,a   0xa002c520
a002c4e0:  b6 0e e0 ff  and  %i3, 0xff, %i3
a002c4e4:  04 80 00 30  ble  0xa002c5a4
a002c4e8:  80 a6 20 02  cmp  %i0, 2
a002c4ec:  02 80 00 1e  be  0xa002c564
a002c4f0:  b6 0e e0 ff  and  %i3, 0xff, %i3
a002c4f4:  80 a6 e0 00  cmp  %i3, 0
a002c4f8:  02 80 00 3e  be  0xa002c5f0
a002c4fc:  98 10 20 00  clr  %o4
a002c500:  9a 10 20 00  clr  %o5
a002c504:  9f 2b 60 02  sll  %o5, 2, %o7
a002c508:  98 03 20 01  inc  %o4
a002c50c:  9a 0b 20 ff  and  %o4, 0xff, %o5
a002c510:  80 a3 40 1b  cmp  %o5, %i3
a002c514:  0a bf ff fc  bcs  0xa002c504
a002c518:  c0 26 80 0f  clr  [ %i2 + %o7 ]
a002c51c:  30 80 00 35  b,a   0xa002c5f0
a002c520:  80 a6 e0 00  cmp  %i3, 0
a002c524:  02 80 00 33  be  0xa002c5f0
a002c528:  b0 10 20 00  clr  %i0
a002c52c:  13 27 c4 c0  sethi  %hi(0x9f130000), %o1
a002c530:  b2 0e 60 ff  and  %i1, 0xff, %i1
a002c534:  a2 12 61 00  or  %o1, 0x100, %l1
a002c538:  82 10 20 00  clr  %g1
a002c53c:  a1 28 60 02  sll  %g1, 2, %l0
a002c540:  94 06 40 10  add  %i1, %l0, %o2
a002c544:  7f ff ff 43  call  0xa002c250
a002c548:  90 02 80 11  add  %o2, %l1, %o0
a002c54c:  b0 06 20 01  inc  %i0
a002c550:  82 0e 20 ff  and  %i0, 0xff, %g1
a002c554:  80 a0 40 1b  cmp  %g1, %i3
a002c558:  0a bf ff f9  bcs  0xa002c53c
a002c55c:  d0 26 80 10  st  %o0, [ %i2 + %l0 ]
a002c560:  30 80 00 24  b,a   0xa002c5f0
a002c564:  80 a6 e0 00  cmp  %i3, 0
a002c568:  02 80 00 22  be  0xa002c5f0
a002c56c:  b0 10 20 00  clr  %i0
a002c570:  b2 0e 60 ff  and  %i1, 0xff, %i1
a002c574:  82 10 20 00  clr  %g1
a002c578:  23 2d c2 44  sethi  %hi(0xb7091000), %l1
a002c57c:  a1 28 60 02  sll  %g1, 2, %l0
a002c580:  96 06 40 10  add  %i1, %l0, %o3
a002c584:  7f ff ff 33  call  0xa002c250
a002c588:  90 02 c0 11  add  %o3, %l1, %o0
a002c58c:  b0 06 20 01  inc  %i0
a002c590:  82 0e 20 ff  and  %i0, 0xff, %g1
a002c594:  80 a0 40 1b  cmp  %g1, %i3
a002c598:  0a bf ff f9  bcs  0xa002c57c
a002c59c:  d0 26 80 10  st  %o0, [ %i2 + %l0 ]
a002c5a0:  30 80 00 14  b,a   0xa002c5f0
a002c5a4:  80 a6 20 00  cmp  %i0, 0
a002c5a8:  12 bf ff d3  bne  0xa002c4f4
a002c5ac:  b6 0e e0 ff  and  %i3, 0xff, %i3
a002c5b0:  80 a6 00 1b  cmp  %i0, %i3
a002c5b4:  1a 80 00 0f  bcc  0xa002c5f0
a002c5b8:  b0 10 20 00  clr  %i0
a002c5bc:  03 27 c2 80  sethi  %hi(0x9f0a0000), %g1
a002c5c0:  a2 10 61 00  or  %g1, 0x100, %l1	! 0x9f0a0100
a002c5c4:  b2 0e 60 ff  and  %i1, 0xff, %i1
a002c5c8:  82 10 20 00  clr  %g1
a002c5cc:  a1 28 60 02  sll  %g1, 2, %l0
a002c5d0:  90 06 40 10  add  %i1, %l0, %o0
a002c5d4:  7f ff ff 1f  call  0xa002c250
a002c5d8:  90 02 00 11  add  %o0, %l1, %o0
a002c5dc:  b0 06 20 01  inc  %i0
a002c5e0:  82 0e 20 ff  and  %i0, 0xff, %g1
a002c5e4:  80 a0 40 1b  cmp  %g1, %i3
a002c5e8:  0a bf ff f9  bcs  0xa002c5cc
a002c5ec:  d0 26 80 10  st  %o0, [ %i2 + %l0 ]
a002c5f0:  81 c7 e0 08  ret
a002c5f4:  81 e8 00 00  restore
