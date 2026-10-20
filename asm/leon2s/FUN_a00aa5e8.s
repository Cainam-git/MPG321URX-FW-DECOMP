# leon2s FUN_a00aa5e8 0xa00aa5e8-0xa00aa7b4 (460 bytes)
a00aa5e8:  9d e3 bf 98  save  %sp, -104, %sp
a00aa5ec:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00aa5f0:  92 0e a0 ff  and  %i2, 0xff, %o1
a00aa5f4:  7f ff ff d1  call  0xa00aa538
a00aa5f8:  90 10 00 18  mov  %i0, %o0
a00aa5fc:  80 a6 20 00  cmp  %i0, 0
a00aa600:  12 80 00 2f  bne  0xa00aa6bc
a00aa604:  b2 0e 60 ff  and  %i1, 0xff, %i1
a00aa608:  80 a6 60 06  cmp  %i1, 6
a00aa60c:  12 80 00 0b  bne  0xa00aa638
a00aa610:  80 a6 60 0a  cmp  %i1, 0xa
a00aa614:  1b 33 c0 4a  sethi  %hi(0xcf012800), %o5
a00aa618:  82 13 62 c4  or  %o5, 0x2c4, %g1	! 0xcf012ac4
a00aa61c:  c0 20 40 00  clr  [ %g1 ]
a00aa620:  98 13 62 c8  or  %o5, 0x2c8, %o4
a00aa624:  82 10 20 80  mov  0x80, %g1
a00aa628:  c2 23 00 00  st  %g1, [ %o4 ]
a00aa62c:  9a 13 62 cc  or  %o5, 0x2cc, %o5
a00aa630:  10 80 00 1d  b  0xa00aa6a4
a00aa634:  82 10 20 0d  mov  0xd, %g1
a00aa638:  12 80 00 0b  bne  0xa00aa664
a00aa63c:  80 a6 60 14  cmp  %i1, 0x14
a00aa640:  1b 33 c0 4a  sethi  %hi(0xcf012800), %o5
a00aa644:  82 13 62 c4  or  %o5, 0x2c4, %g1	! 0xcf012ac4
a00aa648:  c0 20 40 00  clr  [ %g1 ]
a00aa64c:  98 13 62 c8  or  %o5, 0x2c8, %o4
a00aa650:  82 10 20 80  mov  0x80, %g1
a00aa654:  c2 23 00 00  st  %g1, [ %o4 ]
a00aa658:  9a 13 62 cc  or  %o5, 0x2cc, %o5
a00aa65c:  10 80 00 12  b  0xa00aa6a4
a00aa660:  82 10 20 16  mov  0x16, %g1
a00aa664:  12 80 00 09  bne  0xa00aa688
a00aa668:  1b 33 c0 4a  sethi  %hi(0xcf012800), %o5
a00aa66c:  82 13 62 c4  or  %o5, 0x2c4, %g1	! 0xcf012ac4
a00aa670:  c0 20 40 00  clr  [ %g1 ]
a00aa674:  82 13 62 c8  or  %o5, 0x2c8, %g1
a00aa678:  c0 20 40 00  clr  [ %g1 ]
a00aa67c:  9a 13 62 cc  or  %o5, 0x2cc, %o5
a00aa680:  10 80 00 09  b  0xa00aa6a4
a00aa684:  82 10 20 2d  mov  0x2d, %g1
a00aa688:  82 13 62 c4  or  %o5, 0x2c4, %g1
a00aa68c:  c0 20 40 00  clr  [ %g1 ]
a00aa690:  98 13 62 c8  or  %o5, 0x2c8, %o4
a00aa694:  82 10 20 80  mov  0x80, %g1
a00aa698:  c2 23 00 00  st  %g1, [ %o4 ]
a00aa69c:  9a 13 62 cc  or  %o5, 0x2cc, %o5
a00aa6a0:  82 10 20 43  mov  0x43, %g1
a00aa6a4:  c2 23 40 00  st  %g1, [ %o5 ]
a00aa6a8:  80 8e e0 ff  btst  0xff, %i3
a00aa6ac:  02 80 00 41  be  0xa00aa7b0
a00aa6b0:  01 00 00 00  nop
a00aa6b4:  7f ff fe 56  call  0xa00aa00c
a00aa6b8:  81 e8 00 00  restore
a00aa6bc:  80 a6 60 06  cmp  %i1, 6
a00aa6c0:  12 80 00 0c  bne  0xa00aa6f0
a00aa6c4:  80 a6 60 0a  cmp  %i1, 0xa
a00aa6c8:  1b 33 c0 4a  sethi  %hi(0xcf012800), %o5
a00aa6cc:  98 13 62 84  or  %o5, 0x284, %o4	! 0xcf012a84
a00aa6d0:  82 10 20 5c  mov  0x5c, %g1
a00aa6d4:  c2 23 00 00  st  %g1, [ %o4 ]
a00aa6d8:  98 13 62 88  or  %o5, 0x288, %o4
a00aa6dc:  82 10 20 77  mov  0x77, %g1
a00aa6e0:  c2 23 00 00  st  %g1, [ %o4 ]
a00aa6e4:  9a 13 62 8c  or  %o5, 0x28c, %o5
a00aa6e8:  10 80 00 26  b  0xa00aa780
a00aa6ec:  82 10 20 0d  mov  0xd, %g1
a00aa6f0:  12 80 00 0c  bne  0xa00aa720
a00aa6f4:  80 a6 60 14  cmp  %i1, 0x14
a00aa6f8:  1b 33 c0 4a  sethi  %hi(0xcf012800), %o5
a00aa6fc:  98 13 62 84  or  %o5, 0x284, %o4	! 0xcf012a84
a00aa700:  82 10 20 99  mov  0x99, %g1
a00aa704:  c2 23 00 00  st  %g1, [ %o4 ]
a00aa708:  98 13 62 88  or  %o5, 0x288, %o4
a00aa70c:  82 10 20 71  mov  0x71, %g1
a00aa710:  c2 23 00 00  st  %g1, [ %o4 ]
a00aa714:  9a 13 62 8c  or  %o5, 0x28c, %o5
a00aa718:  10 80 00 0c  b  0xa00aa748
a00aa71c:  82 10 20 16  mov  0x16, %g1
a00aa720:  12 80 00 10  bne  0xa00aa760
a00aa724:  1b 33 c0 4a  sethi  %hi(0xcf012800), %o5
a00aa728:  98 13 62 84  or  %o5, 0x284, %o4	! 0xcf012a84
a00aa72c:  82 10 20 33  mov  0x33, %g1
a00aa730:  c2 23 00 00  st  %g1, [ %o4 ]
a00aa734:  98 13 62 88  or  %o5, 0x288, %o4
a00aa738:  82 10 20 e3  mov  0xe3, %g1
a00aa73c:  c2 23 00 00  st  %g1, [ %o4 ]
a00aa740:  9a 13 62 8c  or  %o5, 0x28c, %o5
a00aa744:  82 10 20 2c  mov  0x2c, %g1
a00aa748:  c2 23 40 00  st  %g1, [ %o5 ]
a00aa74c:  90 10 20 01  mov  1, %o0
a00aa750:  92 10 20 e6  mov  0xe6, %o1
a00aa754:  94 10 20 02  mov  2, %o2
a00aa758:  10 80 00 0f  b  0xa00aa794
a00aa75c:  96 10 20 00  clr  %o3
a00aa760:  98 13 62 84  or  %o5, 0x284, %o4
a00aa764:  82 10 20 cc  mov  0xcc, %g1
a00aa768:  c2 23 00 00  st  %g1, [ %o4 ]
a00aa76c:  98 13 62 88  or  %o5, 0x288, %o4
a00aa770:  82 10 20 54  mov  0x54, %g1
a00aa774:  c2 23 00 00  st  %g1, [ %o4 ]
a00aa778:  9a 13 62 8c  or  %o5, 0x28c, %o5
a00aa77c:  82 10 20 43  mov  0x43, %g1
a00aa780:  c2 23 40 00  st  %g1, [ %o5 ]
a00aa784:  90 10 20 01  mov  1, %o0
a00aa788:  92 10 20 e6  mov  0xe6, %o1
a00aa78c:  94 10 20 02  mov  2, %o2
a00aa790:  96 10 20 01  mov  1, %o3
a00aa794:  7f ff f5 5c  call  0xa00a7d04
a00aa798:  01 00 00 00  nop
a00aa79c:  80 8e e0 ff  btst  0xff, %i3
a00aa7a0:  02 80 00 04  be  0xa00aa7b0
a00aa7a4:  01 00 00 00  nop
a00aa7a8:  7f ff fd 29  call  0xa00a9c4c
a00aa7ac:  81 e8 00 00  restore
a00aa7b0:  01 00 00 00  nop
