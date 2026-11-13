# leon2s FUN_a00866e0 0xa00866e0-0xa008686c (396 bytes)
a00866e0:  9d e3 bf 98  save  %sp, -104, %sp
a00866e4:  80 8e 20 ff  btst  0xff, %i0
a00866e8:  9a 10 20 00  clr  %o5
a00866ec:  02 80 00 06  be  0xa0086704
a00866f0:  82 10 20 00  clr  %g1
a00866f4:  03 2a 01 d8  sethi  %hi(0xa8076000), %g1
a00866f8:  da 08 61 c0  ldub  [ %g1 + 0x1c0 ], %o5	! 0xa80761c0
a00866fc:  03 2a 01 d8  sethi  %hi(0xa8076000), %g1
a0086700:  c2 08 61 bf  ldub  [ %g1 + 0x1bf ], %g1	! 0xa80761bf
a0086704:  aa 08 60 ff  and  %g1, 0xff, %l5
a0086708:  90 0b 60 ff  and  %o5, 0xff, %o0
a008670c:  80 a2 00 15  cmp  %o0, %l5
a0086710:  18 80 00 55  bgu  0xa0086864
a0086714:  a4 10 00 0d  mov  %o5, %l2
a0086718:  82 02 00 08  add  %o0, %o0, %g1
a008671c:  82 00 40 08  add  %g1, %o0, %g1
a0086720:  29 2a 01 f3  sethi  %hi(0xa807cc00), %l4
a0086724:  82 00 40 01  add  %g1, %g1, %g1
a0086728:  9a 15 21 2e  or  %l4, 0x12e, %o5
a008672c:  b0 00 40 0d  add  %g1, %o5, %i0
a0086730:  19 2a 01 f3  sethi  %hi(0xa807cc00), %o4
a0086734:  da 0b 21 00  ldub  [ %o4 + 0x100 ], %o5	! 0xa807cd00
a0086738:  82 10 20 12  mov  0x12, %g1
a008673c:  c2 2e 20 01  stb  %g1, [ %i0 + 1 ]
a0086740:  82 10 20 1e  mov  0x1e, %g1
a0086744:  c2 2e 20 02  stb  %g1, [ %i0 + 2 ]
a0086748:  80 a3 60 1d  cmp  %o5, 0x1d
a008674c:  18 80 00 04  bgu  0xa008675c
a0086750:  96 13 21 00  or  %o4, 0x100, %o3
a0086754:  c2 0b 21 00  ldub  [ %o4 + 0x100 ], %g1
a0086758:  c2 2e 20 02  stb  %g1, [ %i0 + 2 ]
a008675c:  da 0a e0 01  ldub  [ %o3 + 1 ], %o5
a0086760:  82 10 20 04  mov  4, %g1
a0086764:  80 a3 60 03  cmp  %o5, 3
a0086768:  18 80 00 04  bgu  0xa0086778
a008676c:  c2 2e 20 03  stb  %g1, [ %i0 + 3 ]
a0086770:  c2 0a e0 01  ldub  [ %o3 + 1 ], %g1
a0086774:  c2 2e 20 03  stb  %g1, [ %i0 + 3 ]
a0086778:  27 2a 01 e2  sethi  %hi(0xa8078800), %l3
a008677c:  92 10 20 90  mov  0x90, %o1
a0086780:  94 10 20 0e  mov  0xe, %o2
a0086784:  96 10 20 00  clr  %o3
a0086788:  7f ff ff 1e  call  0xa0086400
a008678c:  98 14 e1 f0  or  %l3, 0x1f0, %o4
a0086790:  90 0a 20 ff  and  %o0, 0xff, %o0
a0086794:  80 a2 20 01  cmp  %o0, 1
a0086798:  12 80 00 0c  bne  0xa00867c8
a008679c:  82 10 20 0a  mov  0xa, %g1
a00867a0:  da 0c e1 f0  ldub  [ %l3 + 0x1f0 ], %o5
a00867a4:  82 03 7f ff  add  %o5, -1, %g1
a00867a8:  82 08 60 ff  and  %g1, 0xff, %g1
a00867ac:  80 a0 60 03  cmp  %g1, 3
a00867b0:  18 80 00 04  bgu  0xa00867c0
a00867b4:  da 2e 20 05  stb  %o5, [ %i0 + 5 ]
a00867b8:  10 80 00 04  b  0xa00867c8
a00867bc:  83 2b 60 02  sll  %o5, 2, %g1
a00867c0:  10 80 00 03  b  0xa00867cc
a00867c4:  d0 2e 20 05  stb  %o0, [ %i0 + 5 ]
a00867c8:  c2 2e 20 05  stb  %g1, [ %i0 + 5 ]
a00867cc:  a2 0c a0 ff  and  %l2, 0xff, %l1
a00867d0:  82 04 40 11  add  %l1, %l1, %g1
a00867d4:  82 00 40 11  add  %g1, %l1, %g1
a00867d8:  b0 00 40 01  add  %g1, %g1, %i0
a00867dc:  a0 15 21 2e  or  %l4, 0x12e, %l0
a00867e0:  c2 0c 00 18  ldub  [ %l0 + %i0 ], %g1
a00867e4:  82 10 60 10  or  %g1, 0x10, %g1
a00867e8:  c2 2c 00 18  stb  %g1, [ %l0 + %i0 ]
a00867ec:  90 10 00 11  mov  %l1, %o0
a00867f0:  92 10 20 90  mov  0x90, %o1
a00867f4:  94 10 20 07  mov  7, %o2
a00867f8:  96 10 20 00  clr  %o3
a00867fc:  7f ff ff 01  call  0xa0086400
a0086800:  98 14 e1 f0  or  %l3, 0x1f0, %o4
a0086804:  90 0a 20 ff  and  %o0, 0xff, %o0
a0086808:  80 a2 20 01  cmp  %o0, 1
a008680c:  32 80 00 08  bne,a   0xa008682c
a0086810:  c2 0c 00 18  ldub  [ %l0 + %i0 ], %g1
a0086814:  c2 0c e1 f0  ldub  [ %l3 + 0x1f0 ], %g1
a0086818:  80 88 60 40  btst  0x40, %g1
a008681c:  02 80 00 04  be  0xa008682c
a0086820:  c2 0c 00 18  ldub  [ %l0 + %i0 ], %g1
a0086824:  10 80 00 03  b  0xa0086830
a0086828:  82 10 60 08  or  %g1, 8, %g1
a008682c:  82 08 7f f7  and  %g1, -9, %g1
a0086830:  c2 2c 00 18  stb  %g1, [ %l0 + %i0 ]
a0086834:  82 04 40 11  add  %l1, %l1, %g1
a0086838:  82 00 40 11  add  %g1, %l1, %g1
a008683c:  98 15 21 2e  or  %l4, 0x12e, %o4
a0086840:  82 00 40 01  add  %g1, %g1, %g1
a0086844:  da 0b 00 01  ldub  [ %o4 + %g1 ], %o5
a0086848:  9a 0b 7f 99  and  %o5, -103, %o5
a008684c:  a4 04 a0 01  inc  %l2
a0086850:  9a 13 7f 80  or  %o5, -128, %o5
a0086854:  90 0c a0 ff  and  %l2, 0xff, %o0
a0086858:  80 a2 00 15  cmp  %o0, %l5
a008685c:  08 bf ff af  bleu  0xa0086718
a0086860:  da 2b 00 01  stb  %o5, [ %o4 + %g1 ]
a0086864:  81 c7 e0 08  ret
a0086868:  81 e8 00 00  restore
