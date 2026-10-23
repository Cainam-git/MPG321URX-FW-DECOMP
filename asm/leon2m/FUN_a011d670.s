# leon2m FUN_a011d670 0xa011d670-0xa011d740 (208 bytes)
a011d670:  82 0a 60 ff  and  %o1, 0xff, %g1
a011d674:  80 a0 60 03  cmp  %g1, 3
a011d678:  08 80 00 03  bleu  0xa011d684
a011d67c:  98 10 00 08  mov  %o0, %o4
a011d680:  92 10 20 03  mov  3, %o1
a011d684:  9a 0a a0 ff  and  %o2, 0xff, %o5
a011d688:  80 a3 60 03  cmp  %o5, 3
a011d68c:  38 80 00 02  bgu,a   0xa011d694
a011d690:  94 10 20 03  mov  3, %o2
a011d694:  82 0b 20 ff  and  %o4, 0xff, %g1
a011d698:  19 33 c0 58  sethi  %hi(0xcf016000), %o4
a011d69c:  80 a0 60 01  cmp  %g1, 1
a011d6a0:  02 80 00 1c  be  0xa011d710
a011d6a4:  98 13 21 34  or  %o4, 0x134, %o4
a011d6a8:  1b 33 c0 58  sethi  %hi(0xcf016000), %o5
a011d6ac:  80 a0 60 02  cmp  %g1, 2
a011d6b0:  02 80 00 18  be  0xa011d710
a011d6b4:  98 13 61 4c  or  %o5, 0x14c, %o4
a011d6b8:  19 33 c0 58  sethi  %hi(0xcf016000), %o4
a011d6bc:  80 a0 60 03  cmp  %g1, 3
a011d6c0:  02 80 00 14  be  0xa011d710
a011d6c4:  98 13 21 64  or  %o4, 0x164, %o4
a011d6c8:  1b 33 c0 58  sethi  %hi(0xcf016000), %o5
a011d6cc:  80 a0 60 04  cmp  %g1, 4
a011d6d0:  02 80 00 10  be  0xa011d710
a011d6d4:  98 13 61 7c  or  %o5, 0x17c, %o4
a011d6d8:  19 33 c0 58  sethi  %hi(0xcf016000), %o4
a011d6dc:  80 a0 60 05  cmp  %g1, 5
a011d6e0:  02 80 00 0c  be  0xa011d710
a011d6e4:  98 13 21 94  or  %o4, 0x194, %o4
a011d6e8:  1b 33 c0 58  sethi  %hi(0xcf016000), %o5
a011d6ec:  80 a0 60 06  cmp  %g1, 6
a011d6f0:  02 80 00 08  be  0xa011d710
a011d6f4:  98 13 61 ac  or  %o5, 0x1ac, %o4
a011d6f8:  82 02 3f f0  add  %o0, -16, %g1
a011d6fc:  90 08 60 ff  and  %g1, 0xff, %o0
a011d700:  80 a2 20 03  cmp  %o0, 3
a011d704:  18 80 00 0d  bgu  0xa011d738
a011d708:  19 33 c0 59  sethi  %hi(0xcf016400), %o4
a011d70c:  98 13 20 0c  or  %o4, 0xc, %o4	! 0xcf01640c
a011d710:  d0 03 00 00  ld  [ %o4 ], %o0
a011d714:  9a 0a 60 ff  and  %o1, 0xff, %o5
a011d718:  93 2b 60 02  sll  %o5, 2, %o1
a011d71c:  82 0a 20 f0  and  %o0, 0xf0, %g1
a011d720:  90 12 40 0a  or  %o1, %o2, %o0
a011d724:  c2 23 00 00  st  %g1, [ %o4 ]
a011d728:  d4 03 00 00  ld  [ %o4 ], %o2
a011d72c:  9a 0a 20 ff  and  %o0, 0xff, %o5
a011d730:  92 12 80 0d  or  %o2, %o5, %o1
a011d734:  d2 23 00 00  st  %o1, [ %o4 ]
a011d738:  81 c3 e0 08  retl
a011d73c:  01 00 00 00  nop
