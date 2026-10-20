# leon2m FUN_a002a614 0xa002a614-0xa002a734 (288 bytes)
a002a614:  9d e3 bf 98  save  %sp, -104, %sp
a002a618:  17 27 c0 00  sethi  %hi(0x9f000000), %o3
a002a61c:  90 12 e0 90  or  %o3, 0x90, %o0	! 0x9f000090
a002a620:  92 10 20 00  clr  %o1
a002a624:  40 00 07 11  call  0xa002c268
a002a628:  15 00 00 08  sethi  %hi(0x2000), %o2
a002a62c:  13 00 00 08  sethi  %hi(0x2000), %o1
a002a630:  23 27 c0 80  sethi  %hi(0x9f020000), %l1
a002a634:  94 10 00 09  mov  %o1, %o2
a002a638:  40 00 07 0c  call  0xa002c268
a002a63c:  90 14 60 28  or  %l1, 0x28, %o0
a002a640:  40 00 07 04  call  0xa002c250
a002a644:  90 14 60 a0  or  %l1, 0xa0, %o0
a002a648:  a4 10 00 08  mov  %o0, %l2
a002a64c:  40 00 07 01  call  0xa002c250
a002a650:  90 14 60 68  or  %l1, 0x68, %o0
a002a654:  a0 2c 80 08  andn  %l2, %o0, %l0
a002a658:  15 00 00 3f  sethi  %hi(0xfc00), %o2
a002a65c:  92 12 a3 ff  or  %o2, 0x3ff, %o1	! 0xffff
a002a660:  91 32 20 10  srl  %o0, 0x10, %o0
a002a664:  03 2a 00 ac  sethi  %hi(0xa802b000), %g1
a002a668:  a4 0a 00 09  and  %o0, %o1, %l2
a002a66c:  a0 0c 00 09  and  %l0, %o1, %l0
a002a670:  b0 10 61 70  or  %g1, 0x170, %i0
a002a674:  b2 10 20 00  clr  %i1
a002a678:  98 10 20 01  mov  1, %o4
a002a67c:  b5 2b 00 19  sll  %o4, %i1, %i2
a002a680:  80 8e 80 10  btst  %i2, %l0
a002a684:  22 80 00 0f  be,a   0xa002a6c0
a002a688:  b2 06 60 01  inc  %i1
a002a68c:  c2 06 23 40  ld  [ %i0 + 0x340 ], %g1
a002a690:  80 a0 60 00  cmp  %g1, 0
a002a694:  22 80 00 0b  be,a   0xa002a6c0
a002a698:  b2 06 60 01  inc  %i1
a002a69c:  92 10 00 1a  mov  %i2, %o1
a002a6a0:  80 8e 80 12  btst  %i2, %l2
a002a6a4:  02 80 00 1a  be  0xa002a70c
a002a6a8:  90 14 60 a0  or  %l1, 0xa0, %o0
a002a6ac:  9f c0 40 00  call  %g1
a002a6b0:  b2 06 60 01  inc  %i1
a002a6b4:  92 10 00 1a  mov  %i2, %o1
a002a6b8:  40 00 06 e9  call  0xa002c25c
a002a6bc:  90 14 60 a0  or  %l1, 0xa0, %o0
a002a6c0:  80 a6 60 02  cmp  %i1, 2
a002a6c4:  08 bf ff ed  bleu  0xa002a678
a002a6c8:  b0 06 20 04  add  %i0, 4, %i0
a002a6cc:  23 27 c0 80  sethi  %hi(0x9f020000), %l1
a002a6d0:  90 14 60 34  or  %l1, 0x34, %o0	! 0x9f020034
a002a6d4:  40 00 06 e2  call  0xa002c25c
a002a6d8:  13 00 00 08  sethi  %hi(0x2000), %o1
a002a6dc:  31 27 c0 00  sethi  %hi(0x9f000000), %i0
a002a6e0:  90 16 20 9c  or  %i0, 0x9c, %o0	! 0x9f00009c
a002a6e4:  40 00 06 de  call  0xa002c25c
a002a6e8:  13 00 00 08  sethi  %hi(0x2000), %o1
a002a6ec:  15 00 00 08  sethi  %hi(0x2000), %o2
a002a6f0:  b2 10 00 0a  mov  %o2, %i1
a002a6f4:  90 14 60 28  or  %l1, 0x28, %o0
a002a6f8:  40 00 06 dc  call  0xa002c268
a002a6fc:  92 10 20 00  clr  %o1
a002a700:  b0 16 20 90  or  %i0, 0x90, %i0
a002a704:  40 00 06 d9  call  0xa002c268
a002a708:  95 e8 00 19  restore  %g0, %i1, %o2
a002a70c:  40 00 06 d4  call  0xa002c25c
a002a710:  b2 06 60 01  inc  %i1
a002a714:  da 06 23 40  ld  [ %i0 + 0x340 ], %o5
a002a718:  9f c3 40 00  call  %o5
a002a71c:  b0 06 20 04  add  %i0, 4, %i0
a002a720:  80 a6 60 02  cmp  %i1, 2
a002a724:  08 bf ff d6  bleu  0xa002a67c
a002a728:  98 10 20 01  mov  1, %o4
a002a72c:  10 bf ff e9  b  0xa002a6d0
a002a730:  23 27 c0 80  sethi  %hi(0x9f020000), %l1
