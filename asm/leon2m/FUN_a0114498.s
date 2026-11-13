# leon2m FUN_a0114498 0xa0114498-0xa0114570 (216 bytes)
a0114498:  9d e3 bf 98  save  %sp, -104, %sp
a011449c:  3b 00 00 23  sethi  %hi(0x8c00), %i5
a01144a0:  82 0e 60 ff  and  %i1, 0xff, %g1
a01144a4:  b7 2e 60 10  sll  %i1, 0x10, %i3
a01144a8:  82 00 40 1d  add  %g1, %i5, %g1
a01144ac:  b0 0e 20 ff  and  %i0, 0xff, %i0
a01144b0:  9f 36 e0 18  srl  %i3, 0x18, %o7
a01144b4:  83 28 60 02  sll  %g1, 2, %g1
a01144b8:  3b 33 c0 00  sethi  %hi(0xcf000000), %i5
a01144bc:  b6 0e a0 ff  and  %i2, 0xff, %i3
a01144c0:  80 a6 20 01  cmp  %i0, 1
a01144c4:  02 80 00 09  be  0xa01144e8
a01144c8:  ba 10 40 1d  or  %g1, %i5, %i5
a01144cc:  80 a6 20 01  cmp  %i0, 1
a01144d0:  04 80 00 18  ble  0xa0114530
a01144d4:  80 a6 20 02  cmp  %i0, 2
a01144d8:  12 80 00 24  bne  0xa0114568
a01144dc:  3b 00 00 22  sethi  %hi(0x8800), %i5
a01144e0:  10 80 00 07  b  0xa01144fc
a01144e4:  b0 0e 60 ff  and  %i1, 0xff, %i0
a01144e8:  33 33 c0 8c  sethi  %hi(0xcf023000), %i1
a01144ec:  b4 16 63 f8  or  %i1, 0x3f8, %i2	! 0xcf0233f8
a01144f0:  de 26 80 00  st  %o7, [ %i2 ]
a01144f4:  f6 27 40 00  st  %i3, [ %i5 ]
a01144f8:  30 80 00 1c  b,a   0xa0114568
a01144fc:  b6 17 63 00  or  %i5, 0x300, %i3
a0114500:  b8 06 00 1b  add  %i0, %i3, %i4
a0114504:  83 2e 60 10  sll  %i1, 0x10, %g1
a0114508:  b7 30 60 18  srl  %g1, 0x18, %i3
a011450c:  3b 33 c0 8b  sethi  %hi(0xcf022c00), %i5
a0114510:  b0 17 63 f8  or  %i5, 0x3f8, %i0	! 0xcf022ff8
a0114514:  b3 2f 20 02  sll  %i4, 2, %i1
a0114518:  03 33 c0 00  sethi  %hi(0xcf000000), %g1
a011451c:  f6 26 00 00  st  %i3, [ %i0 ]
a0114520:  b8 16 40 01  or  %i1, %g1, %i4
a0114524:  ba 0e a0 ff  and  %i2, 0xff, %i5
a0114528:  fa 27 00 00  st  %i5, [ %i4 ]
a011452c:  30 80 00 0f  b,a   0xa0114568
a0114530:  35 00 00 22  sethi  %hi(0x8800), %i2
a0114534:  82 16 a2 00  or  %i2, 0x200, %g1	! 0x8a00
a0114538:  b2 0e 60 ff  and  %i1, 0xff, %i1
a011453c:  ba 06 40 01  add  %i1, %g1, %i5
a0114540:  35 33 c0 00  sethi  %hi(0xcf000000), %i2
a0114544:  b9 2f 60 02  sll  %i5, 2, %i4
a0114548:  b8 17 00 1a  or  %i4, %i2, %i4
a011454c:  80 a6 20 00  cmp  %i0, 0
a0114550:  12 80 00 06  bne  0xa0114568
a0114554:  b4 10 00 1b  mov  %i3, %i2
a0114558:  37 33 c0 8a  sethi  %hi(0xcf022800), %i3
a011455c:  b0 16 e3 f8  or  %i3, 0x3f8, %i0	! 0xcf022bf8
a0114560:  de 26 00 00  st  %o7, [ %i0 ]
a0114564:  f4 27 00 00  st  %i2, [ %i4 ]
a0114568:  81 c7 e0 08  ret
a011456c:  81 e8 00 00  restore
