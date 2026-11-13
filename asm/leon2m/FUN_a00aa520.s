# leon2m FUN_a00aa520 0xa00aa520-0xa00aa83c (796 bytes)
a00aa520:  9d e3 bf 98  save  %sp, -104, %sp
a00aa524:  03 2a 00 ac  sethi  %hi(0xa802b000), %g1
a00aa528:  d6 08 60 8f  ldub  [ %g1 + 0x8f ], %o3	! 0xa802b08f
a00aa52c:  80 a2 e0 00  cmp  %o3, 0
a00aa530:  02 80 00 2b  be  0xa00aa5dc
a00aa534:  a0 10 00 18  mov  %i0, %l0
a00aa538:  80 a2 e0 01  cmp  %o3, 1
a00aa53c:  02 80 00 32  be  0xa00aa604
a00aa540:  9a 1a e0 02  xor  %o3, 2, %o5
a00aa544:  80 a0 00 0d  cmp  %g0, %o5
a00aa548:  92 60 3f ff  subx  %g0, -1, %o1
a00aa54c:  94 1a e0 0c  xor  %o3, 0xc, %o2
a00aa550:  80 a0 00 0a  cmp  %g0, %o2
a00aa554:  b0 60 3f ff  subx  %g0, -1, %i0
a00aa558:  80 92 40 18  orcc  %o1, %i0, %g0
a00aa55c:  12 80 00 0b  bne  0xa00aa588
a00aa560:  9e 0c 20 ff  and  %l0, 0xff, %o7
a00aa564:  80 a2 e0 03  cmp  %o3, 3
a00aa568:  02 80 00 47  be  0xa00aa684
a00aa56c:  80 a2 e0 06  cmp  %o3, 6
a00aa570:  02 80 00 04  be  0xa00aa580
a00aa574:  80 a2 e0 07  cmp  %o3, 7
a00aa578:  02 80 00 87  be  0xa00aa794
a00aa57c:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00aa580:  10 80 00 ad  b  0xa00aa834
a00aa584:  b0 10 20 01  mov  1, %i0
a00aa588:  80 a3 e0 01  cmp  %o7, 1
a00aa58c:  12 80 00 aa  bne  0xa00aa834
a00aa590:  b0 10 20 01  mov  1, %i0
a00aa594:  40 00 b5 ed  call  0xa00d7d48
a00aa598:  b0 10 20 00  clr  %i0
a00aa59c:  80 a2 20 00  cmp  %o0, 0
a00aa5a0:  12 80 00 a5  bne  0xa00aa834
a00aa5a4:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00aa5a8:  9a 12 e2 90  or  %o3, 0x290, %o5	! 0xa802d290
a00aa5ac:  e4 0b 61 81  ldub  [ %o5 + 0x181 ], %l2
a00aa5b0:  a2 04 bf fc  add  %l2, -4, %l1
a00aa5b4:  a0 0c 60 ff  and  %l1, 0xff, %l0
a00aa5b8:  80 a4 20 02  cmp  %l0, 2
a00aa5bc:  38 80 00 9e  bgu,a   0xa00aa834
a00aa5c0:  b0 10 20 01  mov  1, %i0
a00aa5c4:  d8 03 60 a8  ld  [ %o5 + 0xa8 ], %o4
a00aa5c8:  80 8b 28 00  btst  0x800, %o4
a00aa5cc:  12 80 00 9a  bne  0xa00aa834
a00aa5d0:  01 00 00 00  nop
a00aa5d4:  10 80 00 98  b  0xa00aa834
a00aa5d8:  b0 10 20 01  mov  1, %i0	! 0x1
a00aa5dc:  40 00 b5 db  call  0xa00d7d48
a00aa5e0:  01 00 00 00  nop
a00aa5e4:  80 a2 20 00  cmp  %o0, 0
a00aa5e8:  22 80 00 93  be,a   0xa00aa834
a00aa5ec:  b0 10 20 01  mov  1, %i0
a00aa5f0:  90 0e 20 ff  and  %i0, 0xff, %o0
a00aa5f4:  80 a2 20 02  cmp  %o0, 2
a00aa5f8:  12 bf ff e2  bne  0xa00aa580
a00aa5fc:  b0 10 20 00  clr  %i0
a00aa600:  30 80 00 8d  b,a   0xa00aa834
a00aa604:  40 00 b5 d1  call  0xa00d7d48
a00aa608:  01 00 00 00  nop
a00aa60c:  80 a2 20 00  cmp  %o0, 0
a00aa610:  02 80 00 08  be  0xa00aa630
a00aa614:  96 0c 20 ff  and  %l0, 0xff, %o3
a00aa618:  94 06 3f ff  add  %i0, -1, %o2
a00aa61c:  92 0a a0 ff  and  %o2, 0xff, %o1
a00aa620:  80 a2 60 01  cmp  %o1, 1
a00aa624:  08 80 00 84  bleu  0xa00aa834
a00aa628:  b0 10 20 00  clr  %i0
a00aa62c:  96 0c 20 ff  and  %l0, 0xff, %o3
a00aa630:  25 2a 00 b4  sethi  %hi(0xa802d000), %l2
a00aa634:  98 14 a2 90  or  %l2, 0x290, %o4	! 0xa802d290
a00aa638:  a2 1a e0 01  xor  %o3, 1, %l1
a00aa63c:  80 a0 00 11  cmp  %g0, %l1
a00aa640:  e0 03 21 74  ld  [ %o4 + 0x174 ], %l0
a00aa644:  9f 34 20 0f  srl  %l0, 0xf, %o7
a00aa648:  9a 60 3f ff  subx  %g0, -1, %o5
a00aa64c:  80 8b c0 0d  btst  %o7, %o5
a00aa650:  12 80 00 79  bne  0xa00aa834
a00aa654:  b0 10 20 00  clr  %i0
a00aa658:  d0 0b 20 1f  ldub  [ %o4 + 0x1f ], %o0
a00aa65c:  80 a0 00 08  cmp  %g0, %o0
a00aa660:  98 40 20 00  addx  %g0, 0, %o4
a00aa664:  82 1a e0 06  xor  %o3, 6, %g1
a00aa668:  80 a0 00 01  cmp  %g0, %g1
a00aa66c:  96 60 3f ff  subx  %g0, -1, %o3
a00aa670:  80 8b 00 0b  btst  %o4, %o3
a00aa674:  12 80 00 70  bne  0xa00aa834
a00aa678:  01 00 00 00  nop
a00aa67c:  10 80 00 6e  b  0xa00aa834
a00aa680:  b0 10 20 01  mov  1, %i0	! 0x1
a00aa684:  25 2a 00 b4  sethi  %hi(0xa802d000), %l2
a00aa688:  9a 14 a2 90  or  %l2, 0x290, %o5	! 0xa802d290
a00aa68c:  c2 03 61 1c  ld  [ %o5 + 0x11c ], %g1
a00aa690:  80 a0 60 00  cmp  %g1, 0
a00aa694:  36 80 00 57  bge,a   0xa00aa7f0
a00aa698:  d0 03 60 b0  ld  [ %o5 + 0xb0 ], %o0
a00aa69c:  a2 0c 20 ff  and  %l0, 0xff, %l1
a00aa6a0:  80 a4 60 00  cmp  %l1, 0
a00aa6a4:  02 80 00 64  be  0xa00aa834
a00aa6a8:  b0 10 20 00  clr  %i0
a00aa6ac:  9a 14 a2 90  or  %l2, 0x290, %o5
a00aa6b0:  d4 0b 61 81  ldub  [ %o5 + 0x181 ], %o2
a00aa6b4:  92 02 bf fc  add  %o2, -4, %o1
a00aa6b8:  b0 0a 60 ff  and  %o1, 0xff, %i0
a00aa6bc:  80 a6 20 02  cmp  %i0, 2
a00aa6c0:  18 80 00 10  bgu  0xa00aa700
a00aa6c4:  82 14 a2 90  or  %l2, 0x290, %g1
a00aa6c8:  de 03 60 a8  ld  [ %o5 + 0xa8 ], %o7
a00aa6cc:  80 8b e8 00  btst  0x800, %o7
a00aa6d0:  22 80 00 0d  be,a   0xa00aa704
a00aa6d4:  d0 08 61 78  ldub  [ %g1 + 0x178 ], %o0
a00aa6d8:  98 1c 60 01  xor  %l1, 1, %o4
a00aa6dc:  80 a0 00 0c  cmp  %g0, %o4
a00aa6e0:  a0 60 3f ff  subx  %g0, -1, %l0
a00aa6e4:  96 1c 60 03  xor  %l1, 3, %o3
a00aa6e8:  80 a0 00 0b  cmp  %g0, %o3
a00aa6ec:  9a 60 3f ff  subx  %g0, -1, %o5
a00aa6f0:  80 94 00 0d  orcc  %l0, %o5, %g0
a00aa6f4:  12 80 00 50  bne  0xa00aa834
a00aa6f8:  b0 10 20 00  clr  %i0
a00aa6fc:  82 14 a2 90  or  %l2, 0x290, %g1
a00aa700:  d0 08 61 78  ldub  [ %g1 + 0x178 ], %o0
a00aa704:  80 a2 20 00  cmp  %o0, 0
a00aa708:  02 80 00 04  be  0xa00aa718
a00aa70c:  80 a4 60 01  cmp  %l1, 1
a00aa710:  02 80 00 49  be  0xa00aa834
a00aa714:  b0 10 20 00  clr  %i0
a00aa718:  40 00 b5 8c  call  0xa00d7d48
a00aa71c:  01 00 00 00  nop
a00aa720:  80 a2 20 00  cmp  %o0, 0
a00aa724:  02 80 00 0c  be  0xa00aa754
a00aa728:  a0 14 a2 90  or  %l2, 0x290, %l0
a00aa72c:  9e 1c 60 01  xor  %l1, 1, %o7
a00aa730:  80 a0 00 0f  cmp  %g0, %o7
a00aa734:  92 60 3f ff  subx  %g0, -1, %o1
a00aa738:  94 1c 60 03  xor  %l1, 3, %o2
a00aa73c:  80 a0 00 0a  cmp  %g0, %o2
a00aa740:  b0 60 3f ff  subx  %g0, -1, %i0
a00aa744:  80 92 40 18  orcc  %o1, %i0, %g0
a00aa748:  12 80 00 3b  bne  0xa00aa834
a00aa74c:  b0 10 20 00  clr  %i0
a00aa750:  a0 14 a2 90  or  %l2, 0x290, %l0
a00aa754:  da 0c 20 1f  ldub  [ %l0 + 0x1f ], %o5
a00aa758:  80 a3 60 02  cmp  %o5, 2
a00aa75c:  02 80 00 34  be  0xa00aa82c
a00aa760:  80 a4 60 04  cmp  %l1, 4
a00aa764:  90 14 a2 90  or  %l2, 0x290, %o0
a00aa768:  d8 0a 20 1f  ldub  [ %o0 + 0x1f ], %o4
a00aa76c:  80 a0 00 0c  cmp  %g0, %o4
a00aa770:  a4 40 20 00  addx  %g0, 0, %l2
a00aa774:  96 1c 60 05  xor  %l1, 5, %o3
a00aa778:  80 a0 00 0b  cmp  %g0, %o3
a00aa77c:  a2 60 3f ff  subx  %g0, -1, %l1
a00aa780:  80 8c 80 11  btst  %l2, %l1
a00aa784:  12 80 00 2c  bne  0xa00aa834
a00aa788:  b0 10 20 00  clr  %i0
a00aa78c:  10 80 00 2a  b  0xa00aa834
a00aa790:  b0 10 20 01  mov  1, %i0
a00aa794:  82 13 22 90  or  %o4, 0x290, %g1
a00aa798:  f0 08 60 1f  ldub  [ %g1 + 0x1f ], %i0
a00aa79c:  80 a6 20 00  cmp  %i0, 0
a00aa7a0:  02 80 00 07  be  0xa00aa7bc
a00aa7a4:  9e 13 22 90  or  %o4, 0x290, %o7
a00aa7a8:  92 0c 20 ff  and  %l0, 0xff, %o1
a00aa7ac:  80 a2 60 06  cmp  %o1, 6
a00aa7b0:  02 80 00 21  be  0xa00aa834
a00aa7b4:  b0 10 20 00  clr  %i0
a00aa7b8:  9e 13 22 90  or  %o4, 0x290, %o7
a00aa7bc:  d4 03 e0 b0  ld  [ %o7 + 0xb0 ], %o2
a00aa7c0:  80 a2 a0 00  cmp  %o2, 0
a00aa7c4:  02 80 00 1c  be  0xa00aa834
a00aa7c8:  b0 10 20 01  mov  1, %i0
a00aa7cc:  40 00 b9 03  call  0xa00d8bd8
a00aa7d0:  01 00 00 00  nop
a00aa7d4:  80 8a 20 ff  btst  0xff, %o0
a00aa7d8:  02 80 00 17  be  0xa00aa834
a00aa7dc:  9a 0c 20 ff  and  %l0, 0xff, %o5
a00aa7e0:  80 a3 60 07  cmp  %o5, 7
a00aa7e4:  12 bf ff 67  bne  0xa00aa580
a00aa7e8:  b0 10 20 00  clr  %i0
a00aa7ec:  30 80 00 12  b,a   0xa00aa834
a00aa7f0:  80 a2 20 00  cmp  %o0, 0
a00aa7f4:  02 80 00 07  be  0xa00aa810
a00aa7f8:  01 00 00 00  nop
a00aa7fc:  40 00 b8 f7  call  0xa00d8bd8
a00aa800:  01 00 00 00  nop
a00aa804:  80 8a 20 ff  btst  0xff, %o0
a00aa808:  12 bf ff a6  bne  0xa00aa6a0
a00aa80c:  a2 0c 20 ff  and  %l0, 0xff, %l1
a00aa810:  40 00 b5 4e  call  0xa00d7d48
a00aa814:  a2 0c 20 ff  and  %l0, 0xff, %l1
a00aa818:  80 a2 20 00  cmp  %o0, 0
a00aa81c:  22 bf ff a5  be,a   0xa00aa6b0
a00aa820:  9a 14 a2 90  or  %l2, 0x290, %o5
a00aa824:  10 bf ff 9f  b  0xa00aa6a0
a00aa828:  a2 0c 20 ff  and  %l0, 0xff, %l1
a00aa82c:  12 bf ff ce  bne  0xa00aa764
a00aa830:  b0 10 20 00  clr  %i0
a00aa834:  81 c7 e0 08  ret
a00aa838:  81 e8 00 00  restore
