# leon2m FUN_a00f04f8 0xa00f04f8-0xa00f0b58 (1632 bytes)
a00f04f8:  9d e3 bf 90  save  %sp, -112, %sp
a00f04fc:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00f0500:  80 a6 20 02  cmp  %i0, 2
a00f0504:  a8 10 20 00  clr  %l4
a00f0508:  02 80 00 49  be  0xa00f062c
a00f050c:  a0 10 20 00  clr  %l0
a00f0510:  80 a6 20 03  cmp  %i0, 3
a00f0514:  02 80 00 ae  be  0xa00f07cc
a00f0518:  80 a6 20 06  cmp  %i0, 6
a00f051c:  02 80 00 44  be  0xa00f062c
a00f0520:  80 a6 20 07  cmp  %i0, 7
a00f0524:  22 80 00 ab  be,a   0xa00f07d0
a00f0528:  a8 10 20 03  mov  3, %l4
a00f052c:  80 8e 60 ff  btst  0xff, %i1
a00f0530:  12 80 00 43  bne  0xa00f063c
a00f0534:  27 00 06 68  sethi  %hi(0x19a000), %l3
a00f0538:  2b 2a 00 9a  sethi  %hi(0xa8026800), %l5
a00f053c:  d2 0d 62 79  ldub  [ %l5 + 0x279 ], %o1	! 0xa8026a79
a00f0540:  80 a2 60 04  cmp  %o1, 4
a00f0544:  b4 60 20 00  subx  %g0, 0, %i2
a00f0548:  b0 0a 40 1a  and  %o1, %i2, %i0
a00f054c:  82 06 00 18  add  %i0, %i0, %g1
a00f0550:  35 00 06 67  sethi  %hi(0x199c00), %i2
a00f0554:  b0 16 a3 fc  or  %i2, 0x3fc, %i0	! 0x199ffc
a00f0558:  da 16 00 01  lduh  [ %i0 + %g1 ], %o5
a00f055c:  b8 03 60 0d  add  %o5, 0xd, %i4
a00f0560:  f6 16 00 01  lduh  [ %i0 + %g1 ], %i3
a00f0564:  33 33 c0 00  sethi  %hi(0xcf000000), %i1
a00f0568:  af 2f 20 02  sll  %i4, 2, %l7
a00f056c:  a6 06 e0 0c  add  %i3, 0xc, %l3
a00f0570:  e4 16 00 01  lduh  [ %i0 + %g1 ], %l2
a00f0574:  ac 10 00 01  mov  %g1, %l6
a00f0578:  a2 15 c0 19  or  %l7, %i1, %l1
a00f057c:  97 2c e0 02  sll  %l3, 2, %o3
a00f0580:  98 04 a0 0b  add  %l2, 0xb, %o4
a00f0584:  de 16 00 01  lduh  [ %i0 + %g1 ], %o7
a00f0588:  e6 04 40 00  ld  [ %l1 ], %l3
a00f058c:  90 12 c0 19  or  %o3, %i1, %o0
a00f0590:  93 2b 20 02  sll  %o4, 2, %o1
a00f0594:  82 03 e0 0f  add  %o7, 0xf, %g1
a00f0598:  da 16 00 16  lduh  [ %i0 + %l6 ], %o5
a00f059c:  e4 02 00 00  ld  [ %o0 ], %l2
a00f05a0:  ac 12 40 19  or  %o1, %i1, %l6
a00f05a4:  b9 28 60 02  sll  %g1, 2, %i4
a00f05a8:  b6 03 60 0e  add  %o5, 0xe, %i3
a00f05ac:  d4 05 80 00  ld  [ %l6 ], %o2
a00f05b0:  ae 17 00 19  or  %i4, %i1, %l7
a00f05b4:  bb 2e e0 02  sll  %i3, 2, %i5
a00f05b8:  d8 05 c0 00  ld  [ %l7 ], %o4
a00f05bc:  a2 0c e0 ff  and  %l3, 0xff, %l1
a00f05c0:  9e 0c a0 ff  and  %l2, 0xff, %o7
a00f05c4:  96 17 40 19  or  %i5, %i1, %o3
a00f05c8:  ec 02 c0 00  ld  [ %o3 ], %l6
a00f05cc:  3b 2a 00 ad  sethi  %hi(0xa802b400), %i5
a00f05d0:  93 2c 60 10  sll  %l1, 0x10, %o1
a00f05d4:  91 2b e0 08  sll  %o7, 8, %o0
a00f05d8:  a4 0c 20 ff  and  %l0, 0xff, %l2
a00f05dc:  b8 0a a0 ff  and  %o2, 0xff, %i4
a00f05e0:  b6 0d a0 ff  and  %l6, 0xff, %i3
a00f05e4:  82 0b 20 f0  and  %o4, 0xf0, %g1
a00f05e8:  a6 17 63 58  or  %i5, 0x358, %l3
a00f05ec:  9a 12 40 08  or  %o1, %o0, %o5
a00f05f0:  a1 28 60 08  sll  %g1, 8, %l0
a00f05f4:  ee 0c c0 12  ldub  [ %l3 + %l2 ], %l7
a00f05f8:  ac 13 40 1c  or  %o5, %i4, %l6
a00f05fc:  80 a5 e0 05  cmp  %l7, 5
a00f0600:  08 80 00 23  bleu  0xa00f068c
a00f0604:  b8 14 00 1b  or  %l0, %i3, %i4
a00f0608:  29 00 06 68  sethi  %hi(0x19a000), %l4
a00f060c:  7f ff ba d9  call  0xa00df170
a00f0610:  90 15 20 c8  or  %l4, 0xc8, %o0	! 0x19a0c8
a00f0614:  7f ff ba d7  call  0xa00df170
a00f0618:  90 15 20 c8  or  %l4, 0xc8, %o0
a00f061c:  7f ff ba d5  call  0xa00df170
a00f0620:  90 15 20 c8  or  %l4, 0xc8, %o0
a00f0624:  10 80 01 4b  b  0xa00f0b50
a00f0628:  b0 10 20 01  mov  1, %i0
a00f062c:  80 8e 60 ff  btst  0xff, %i1
a00f0630:  02 bf ff c2  be  0xa00f0538
a00f0634:  a8 10 20 02  mov  2, %l4
a00f0638:  27 00 06 68  sethi  %hi(0x19a000), %l3
a00f063c:  7f ff ba cd  call  0xa00df170
a00f0640:  90 14 e0 98  or  %l3, 0x98, %o0	! 0x19a098
a00f0644:  9e 0c 20 ff  and  %l0, 0xff, %o7
a00f0648:  17 2a 00 ad  sethi  %hi(0xa802b400), %o3
a00f064c:  25 2a 00 ad  sethi  %hi(0xa802b400), %l2
a00f0650:  a0 03 c0 0f  add  %o7, %o7, %l0
a00f0654:  90 12 e3 66  or  %o3, 0x366, %o0
a00f0658:  a2 14 a3 58  or  %l2, 0x358, %l1
a00f065c:  c0 2c 40 0f  clrb  [ %l1 + %o7 ]
a00f0660:  67 fe 73 ca  call  0x4008d588
a00f0664:  c0 32 00 10  clrh  [ %o0 + %l0 ]
a00f0668:  15 2a 00 ad  sethi  %hi(0xa802b400), %o2
a00f066c:  03 2a 00 ad  sethi  %hi(0xa802b400), %g1
a00f0670:  98 10 20 32  mov  0x32, %o4
a00f0674:  92 12 a3 6a  or  %o2, 0x36a, %o1
a00f0678:  9a 10 63 62  or  %g1, 0x362, %o5
a00f067c:  d8 32 40 10  sth  %o4, [ %o1 + %l0 ]
a00f0680:  d0 33 40 10  sth  %o0, [ %o5 + %l0 ]
a00f0684:  10 80 01 33  b  0xa00f0b50
a00f0688:  b0 10 20 00  clr  %i0
a00f068c:  37 2a 00 ad  sethi  %hi(0xa802b400), %i3
a00f0690:  ae 16 e3 66  or  %i3, 0x366, %l7	! 0xa802b766
a00f0694:  a2 04 80 12  add  %l2, %l2, %l1
a00f0698:  67 fe 73 bf  call  0x4008d594
a00f069c:  d0 15 c0 11  lduh  [ %l7 + %l1 ], %o0
a00f06a0:  91 2a 20 10  sll  %o0, 0x10, %o0
a00f06a4:  a1 32 20 10  srl  %o0, 0x10, %l0
a00f06a8:  80 a4 20 32  cmp  %l0, 0x32
a00f06ac:  28 80 00 4b  bleu,a   0xa00f07d8
a00f06b0:  23 2a 00 ad  sethi  %hi(0xa802b400), %l1
a00f06b4:  19 2a 00 ad  sethi  %hi(0xa802b400), %o4
a00f06b8:  9e 13 23 62  or  %o4, 0x362, %o7	! 0xa802b762
a00f06bc:  d4 13 c0 11  lduh  [ %o7 + %l1 ], %o2
a00f06c0:  80 a2 a0 00  cmp  %o2, 0
a00f06c4:  32 80 00 45  bne,a   0xa00f07d8
a00f06c8:  23 2a 00 ad  sethi  %hi(0xa802b400), %l1
a00f06cc:  aa 0d 20 ff  and  %l4, 0xff, %l5
a00f06d0:  80 a5 60 04  cmp  %l5, 4
a00f06d4:  90 60 20 00  subx  %g0, 0, %o0
a00f06d8:  a0 0a 00 14  and  %o0, %l4, %l0
a00f06dc:  a8 0c 20 ff  and  %l0, 0xff, %l4
a00f06e0:  92 05 00 14  add  %l4, %l4, %o1
a00f06e4:  f4 16 00 09  lduh  [ %i0 + %o1 ], %i2
a00f06e8:  82 06 a0 16  add  %i2, 0x16, %g1
a00f06ec:  9b 28 60 02  sll  %g1, 2, %o5
a00f06f0:  ba 13 40 19  or  %o5, %i1, %i5
a00f06f4:  d6 07 40 00  ld  [ %i5 ], %o3
a00f06f8:  80 8a e0 0c  btst  0xc, %o3
a00f06fc:  02 80 00 90  be  0xa00f093c
a00f0700:  80 a5 a2 00  cmp  %l6, 0x200
a00f0704:  13 2a 00 9a  sethi  %hi(0xa8026800), %o1
a00f0708:  da 0a 62 78  ldub  [ %o1 + 0x278 ], %o5	! 0xa8026a78
a00f070c:  80 a3 60 04  cmp  %o5, 4
a00f0710:  b4 40 20 00  addx  %g0, 0, %i2
a00f0714:  82 20 00 1a  neg  %i2, %g1
a00f0718:  ba 0b 40 01  and  %o5, %g1, %i5
a00f071c:  96 07 40 1d  add  %i5, %i5, %o3
a00f0720:  d8 16 00 0b  lduh  [ %i0 + %o3 ], %o4
a00f0724:  9e 03 20 16  add  %o4, 0x16, %o7
a00f0728:  95 2b e0 02  sll  %o7, 2, %o2
a00f072c:  b8 12 80 19  or  %o2, %i1, %i4
a00f0730:  e2 07 00 00  ld  [ %i4 ], %l1
a00f0734:  2f 00 06 68  sethi  %hi(0x19a000), %l7
a00f0738:  90 15 e1 00  or  %l7, 0x100, %o0	! 0x19a100
a00f073c:  94 0c 60 0c  and  %l1, 0xc, %o2
a00f0740:  96 10 00 16  mov  %l6, %o3
a00f0744:  d8 0c c0 12  ldub  [ %l3 + %l2 ], %o4
a00f0748:  7f ff ba 8a  call  0xa00df170
a00f074c:  92 10 00 15  mov  %l5, %o1
a00f0750:  80 a5 60 08  cmp  %l5, 8
a00f0754:  02 80 00 9c  be  0xa00f09c4
a00f0758:  80 a5 60 03  cmp  %l5, 3
a00f075c:  18 80 00 13  bgu  0xa00f07a8
a00f0760:  a6 05 40 15  add  %l5, %l5, %l3
a00f0764:  d2 16 00 13  lduh  [ %i0 + %l3 ], %o1
a00f0768:  b5 2a 60 02  sll  %o1, 2, %i2
a00f076c:  94 16 80 19  or  %i2, %i1, %o2
a00f0770:  c2 02 80 00  ld  [ %o2 ], %g1
a00f0774:  96 08 60 5f  and  %g1, 0x5f, %o3
a00f0778:  d6 22 80 00  st  %o3, [ %o2 ]
a00f077c:  80 a5 60 03  cmp  %l5, 3
a00f0780:  18 80 00 0a  bgu  0xa00f07a8
a00f0784:  a2 05 40 15  add  %l5, %l5, %l1
a00f0788:  d0 16 00 11  lduh  [ %i0 + %l1 ], %o0
a00f078c:  a0 02 20 16  add  %o0, 0x16, %l0
a00f0790:  a9 2c 20 02  sll  %l0, 2, %l4
a00f0794:  aa 15 00 19  or  %l4, %i1, %l5
a00f0798:  f0 05 40 00  ld  [ %l5 ], %i0
a00f079c:  ac 16 20 0c  or  %i0, 0xc, %l6
a00f07a0:  b2 0d a0 ff  and  %l6, 0xff, %i1
a00f07a4:  f2 25 40 00  st  %i1, [ %l5 ]
a00f07a8:  67 fe 73 78  call  0x4008d588
a00f07ac:  ae 04 80 12  add  %l2, %l2, %l7
a00f07b0:  1f 2a 00 ad  sethi  %hi(0xa802b400), %o7
a00f07b4:  b8 13 e3 62  or  %o7, 0x362, %i4	! 0xa802b762
a00f07b8:  a4 16 e3 66  or  %i3, 0x366, %l2
a00f07bc:  d0 37 00 17  sth  %o0, [ %i4 + %l7 ]
a00f07c0:  c0 34 80 17  clrh  [ %l2 + %l7 ]
a00f07c4:  10 80 00 e3  b  0xa00f0b50
a00f07c8:  b0 10 20 00  clr  %i0
a00f07cc:  a8 10 20 03  mov  3, %l4
a00f07d0:  10 bf ff 57  b  0xa00f052c
a00f07d4:  a0 10 20 01  mov  1, %l0
a00f07d8:  a0 04 80 12  add  %l2, %l2, %l0
a00f07dc:  a6 14 63 62  or  %l1, 0x362, %l3
a00f07e0:  67 fe 73 6d  call  0x4008d594
a00f07e4:  d0 14 c0 10  lduh  [ %l3 + %l0 ], %o0
a00f07e8:  27 2a 00 ad  sethi  %hi(0xa802b400), %l3
a00f07ec:  b1 2a 20 10  sll  %o0, 0x10, %i0
a00f07f0:  b2 14 e3 6a  or  %l3, 0x36a, %i1
a00f07f4:  9f 36 20 10  srl  %i0, 0x10, %o7
a00f07f8:  d4 16 40 10  lduh  [ %i1 + %l0 ], %o2
a00f07fc:  80 a3 c0 0a  cmp  %o7, %o2
a00f0800:  28 80 00 d4  bleu,a   0xa00f0b50
a00f0804:  b0 10 20 00  clr  %i0
a00f0808:  98 16 e3 66  or  %i3, 0x366, %o4
a00f080c:  ee 13 00 10  lduh  [ %o4 + %l0 ], %l7
a00f0810:  80 a5 e0 00  cmp  %l7, 0
a00f0814:  32 80 00 cf  bne,a   0xa00f0b50
a00f0818:  b0 10 20 00  clr  %i0
a00f081c:  40 00 c5 14  call  0xa0121c6c
a00f0820:  d0 0d 62 79  ldub  [ %l5 + 0x279 ], %o0
a00f0824:  40 00 c5 12  call  0xa0121c6c
a00f0828:  d0 0d 62 79  ldub  [ %l5 + 0x279 ], %o0
a00f082c:  92 0d 20 ff  and  %l4, 0xff, %o1
a00f0830:  80 a2 60 08  cmp  %o1, 8
a00f0834:  02 80 00 88  be  0xa00f0a54
a00f0838:  80 a2 60 03  cmp  %o1, 3
a00f083c:  18 80 00 1a  bgu  0xa00f08a4
a00f0840:  98 16 a3 fc  or  %i2, 0x3fc, %o4
a00f0844:  a0 02 40 09  add  %o1, %o1, %l0
a00f0848:  ee 13 00 10  lduh  [ %o4 + %l0 ], %l7
a00f084c:  a3 2d e0 02  sll  %l7, 2, %l1
a00f0850:  17 33 c0 00  sethi  %hi(0xcf000000), %o3
a00f0854:  b4 14 40 0b  or  %l1, %o3, %i2
a00f0858:  f0 06 80 00  ld  [ %i2 ], %i0
a00f085c:  94 16 3f a0  or  %i0, -96, %o2
a00f0860:  90 0a a0 ff  and  %o2, 0xff, %o0
a00f0864:  d0 26 80 00  st  %o0, [ %i2 ]
a00f0868:  80 a2 60 03  cmp  %o1, 3
a00f086c:  18 80 00 0e  bgu  0xa00f08a4
a00f0870:  35 00 06 67  sethi  %hi(0x199c00), %i2
a00f0874:  96 16 a3 fc  or  %i2, 0x3fc, %o3	! 0x199ffc
a00f0878:  a2 02 40 09  add  %o1, %o1, %l1
a00f087c:  f0 12 c0 11  lduh  [ %o3 + %l1 ], %i0
a00f0880:  94 06 20 16  add  %i0, 0x16, %o2
a00f0884:  9b 2a a0 02  sll  %o2, 2, %o5
a00f0888:  11 33 c0 00  sethi  %hi(0xcf000000), %o0
a00f088c:  aa 13 40 08  or  %o5, %o0, %l5
a00f0890:  f2 05 40 00  ld  [ %l5 ], %i1
a00f0894:  9e 16 60 0c  or  %i1, 0xc, %o7
a00f0898:  82 0b e0 ff  and  %o7, 0xff, %g1
a00f089c:  c2 25 40 00  st  %g1, [ %l5 ]
a00f08a0:  80 a2 60 03  cmp  %o1, 3
a00f08a4:  08 80 00 03  bleu  0xa00f08b0
a00f08a8:  9a 10 00 14  mov  %l4, %o5
a00f08ac:  9a 10 20 00  clr  %o5
a00f08b0:  a8 0b 60 ff  and  %o5, 0xff, %l4
a00f08b4:  96 16 a3 fc  or  %i2, 0x3fc, %o3
a00f08b8:  a2 05 00 14  add  %l4, %l4, %l1
a00f08bc:  f0 12 c0 11  lduh  [ %o3 + %l1 ], %i0
a00f08c0:  94 06 20 16  add  %i0, 0x16, %o2
a00f08c4:  91 2a a0 02  sll  %o2, 2, %o0
a00f08c8:  1b 33 c0 00  sethi  %hi(0xcf000000), %o5
a00f08cc:  b2 12 00 0d  or  %o0, %o5, %i1
a00f08d0:  a8 17 63 58  or  %i5, 0x358, %l4
a00f08d4:  de 06 40 00  ld  [ %i1 ], %o7
a00f08d8:  03 00 06 68  sethi  %hi(0x19a000), %g1
a00f08dc:  96 10 00 16  mov  %l6, %o3
a00f08e0:  9a 10 00 1c  mov  %i4, %o5
a00f08e4:  94 0b e0 0c  and  %o7, 0xc, %o2
a00f08e8:  90 10 61 38  or  %g1, 0x138, %o0
a00f08ec:  7f ff ba 21  call  0xa00df170
a00f08f0:  d8 0d 00 12  ldub  [ %l4 + %l2 ], %o4
a00f08f4:  a0 14 e3 6a  or  %l3, 0x36a, %l0
a00f08f8:  2b 2a 00 ad  sethi  %hi(0xa802b400), %l5
a00f08fc:  2f 2a 00 ad  sethi  %hi(0xa802b400), %l7
a00f0900:  b8 04 80 12  add  %l2, %l2, %i4
a00f0904:  98 10 20 02  mov  2, %o4
a00f0908:  b4 15 63 62  or  %l5, 0x362, %i2
a00f090c:  a6 15 e3 60  or  %l7, 0x360, %l3
a00f0910:  d8 34 00 1c  sth  %o4, [ %l0 + %i4 ]
a00f0914:  c0 2c c0 12  clrb  [ %l3 + %l2 ]
a00f0918:  67 fe 73 1c  call  0x4008d588
a00f091c:  c0 36 80 1c  clrh  [ %i2 + %i4 ]
a00f0920:  d2 0d 00 12  ldub  [ %l4 + %l2 ], %o1
a00f0924:  ba 16 e3 66  or  %i3, 0x366, %i5
a00f0928:  ac 02 60 01  add  %o1, 1, %l6
a00f092c:  d0 37 40 1c  sth  %o0, [ %i5 + %i4 ]
a00f0930:  ec 2d 00 12  stb  %l6, [ %l4 + %l2 ]
a00f0934:  10 80 00 87  b  0xa00f0b50
a00f0938:  b0 10 20 00  clr  %i0
a00f093c:  18 bf ff 73  bgu  0xa00f0708
a00f0940:  13 2a 00 9a  sethi  %hi(0xa8026800), %o1
a00f0944:  37 2a 00 ad  sethi  %hi(0xa802b400), %i3
a00f0948:  a0 16 e3 60  or  %i3, 0x360, %l0	! 0xa802b760
a00f094c:  d4 0c 00 12  ldub  [ %l0 + %l2 ], %o2
a00f0950:  80 a2 a0 05  cmp  %o2, 5
a00f0954:  28 80 00 67  bleu,a   0xa00f0af0
a00f0958:  11 2a 00 9a  sethi  %hi(0xa8026800), %o0
a00f095c:  37 2a 00 9a  sethi  %hi(0xa8026800), %i3
a00f0960:  d0 0e e2 78  ldub  [ %i3 + 0x278 ], %o0	! 0xa8026a78
a00f0964:  80 a2 20 04  cmp  %o0, 4
a00f0968:  9e 40 20 00  addx  %g0, 0, %o7
a00f096c:  b8 20 00 0f  neg  %o7, %i4
a00f0970:  a0 0a 00 1c  and  %o0, %i4, %l0
a00f0974:  a8 04 00 10  add  %l0, %l0, %l4
a00f0978:  d2 16 00 14  lduh  [ %i0 + %l4 ], %o1
a00f097c:  b4 02 60 16  add  %o1, 0x16, %i2
a00f0980:  83 2e a0 02  sll  %i2, 2, %g1
a00f0984:  96 10 40 19  or  %g1, %i1, %o3
a00f0988:  da 02 c0 00  ld  [ %o3 ], %o5
a00f098c:  ba 0b 60 0c  and  %o5, 0xc, %i5
a00f0990:  67 fe 73 01  call  0x4008d594
a00f0994:  d0 15 c0 11  lduh  [ %l7 + %l1 ], %o0
a00f0998:  99 2a 20 10  sll  %o0, 0x10, %o4
a00f099c:  15 00 06 68  sethi  %hi(0x19a000), %o2
a00f09a0:  90 12 a1 70  or  %o2, 0x170, %o0	! 0x19a170
a00f09a4:  95 33 20 10  srl  %o4, 0x10, %o2
a00f09a8:  da 0c c0 12  ldub  [ %l3 + %l2 ], %o5
a00f09ac:  92 10 00 15  mov  %l5, %o1
a00f09b0:  96 10 00 1d  mov  %i5, %o3
a00f09b4:  7f ff b9 ef  call  0xa00df170
a00f09b8:  98 10 00 16  mov  %l6, %o4
a00f09bc:  10 80 00 65  b  0xa00f0b50
a00f09c0:  b0 10 20 01  mov  1, %i0
a00f09c4:  92 10 00 18  mov  %i0, %o1
a00f09c8:  94 10 00 19  mov  %i1, %o2
a00f09cc:  96 10 20 00  clr  %o3
a00f09d0:  98 10 20 00  clr  %o4
a00f09d4:  a8 03 00 0c  add  %o4, %o4, %l4
a00f09d8:  f0 12 40 14  lduh  [ %o1 + %l4 ], %i0
a00f09dc:  ad 2e 20 02  sll  %i0, 2, %l6
a00f09e0:  aa 15 80 0a  or  %l6, %o2, %l5
a00f09e4:  f2 05 40 00  ld  [ %l5 ], %i1
a00f09e8:  96 02 e0 01  inc  %o3
a00f09ec:  a6 0e 60 5f  and  %i1, 0x5f, %l3
a00f09f0:  98 0a e0 ff  and  %o3, 0xff, %o4
a00f09f4:  e6 25 40 00  st  %l3, [ %l5 ]
a00f09f8:  80 a3 20 03  cmp  %o4, 3
a00f09fc:  08 bf ff f7  bleu  0xa00f09d8
a00f0a00:  a8 03 00 0c  add  %o4, %o4, %l4
a00f0a04:  21 00 06 67  sethi  %hi(0x199c00), %l0
a00f0a08:  92 14 23 fc  or  %l0, 0x3fc, %o1	! 0x199ffc
a00f0a0c:  96 10 20 00  clr  %o3
a00f0a10:  98 10 20 00  clr  %o4
a00f0a14:  15 33 c0 00  sethi  %hi(0xcf000000), %o2
a00f0a18:  9a 03 00 0c  add  %o4, %o4, %o5
a00f0a1c:  fa 12 40 0d  lduh  [ %o1 + %o5 ], %i5
a00f0a20:  98 07 60 16  add  %i5, 0x16, %o4
a00f0a24:  9f 2b 20 02  sll  %o4, 2, %o7
a00f0a28:  90 13 c0 0a  or  %o7, %o2, %o0
a00f0a2c:  f8 02 00 00  ld  [ %o0 ], %i4
a00f0a30:  ae 17 20 0c  or  %i4, 0xc, %l7
a00f0a34:  96 02 e0 01  inc  %o3
a00f0a38:  a2 0d e0 ff  and  %l7, 0xff, %l1
a00f0a3c:  98 0a e0 ff  and  %o3, 0xff, %o4
a00f0a40:  e2 22 00 00  st  %l1, [ %o0 ]
a00f0a44:  80 a3 20 03  cmp  %o4, 3
a00f0a48:  08 bf ff f5  bleu  0xa00f0a1c
a00f0a4c:  9a 03 00 0c  add  %o4, %o4, %o5
a00f0a50:  30 bf ff 56  b,a   0xa00f07a8
a00f0a54:  21 00 06 67  sethi  %hi(0x199c00), %l0
a00f0a58:  90 14 23 fc  or  %l0, 0x3fc, %o0	! 0x199ffc
a00f0a5c:  96 10 20 00  clr  %o3
a00f0a60:  98 10 20 00  clr  %o4
a00f0a64:  15 33 c0 00  sethi  %hi(0xcf000000), %o2
a00f0a68:  a2 03 00 0c  add  %o4, %o4, %l1
a00f0a6c:  f0 12 00 11  lduh  [ %o0 + %l1 ], %i0
a00f0a70:  9b 2e 20 02  sll  %i0, 2, %o5
a00f0a74:  aa 13 40 0a  or  %o5, %o2, %l5
a00f0a78:  f2 05 40 00  ld  [ %l5 ], %i1
a00f0a7c:  9e 16 7f a0  or  %i1, -96, %o7
a00f0a80:  96 02 e0 01  inc  %o3
a00f0a84:  82 0b e0 ff  and  %o7, 0xff, %g1
a00f0a88:  98 0a e0 ff  and  %o3, 0xff, %o4
a00f0a8c:  c2 25 40 00  st  %g1, [ %l5 ]
a00f0a90:  80 a3 20 03  cmp  %o4, 3
a00f0a94:  08 bf ff f6  bleu  0xa00f0a6c
a00f0a98:  a2 03 00 0c  add  %o4, %o4, %l1
a00f0a9c:  17 00 06 67  sethi  %hi(0x199c00), %o3
a00f0aa0:  90 12 e3 fc  or  %o3, 0x3fc, %o0	! 0x199ffc
a00f0aa4:  96 10 20 00  clr  %o3
a00f0aa8:  98 10 20 00  clr  %o4
a00f0aac:  15 33 c0 00  sethi  %hi(0xcf000000), %o2
a00f0ab0:  9a 03 00 0c  add  %o4, %o4, %o5
a00f0ab4:  f2 12 00 0d  lduh  [ %o0 + %o5 ], %i1
a00f0ab8:  9e 06 60 16  add  %i1, 0x16, %o7
a00f0abc:  83 2b e0 02  sll  %o7, 2, %g1
a00f0ac0:  ae 10 40 0a  or  %g1, %o2, %l7
a00f0ac4:  ea 05 c0 00  ld  [ %l7 ], %l5
a00f0ac8:  98 15 60 0c  or  %l5, 0xc, %o4
a00f0acc:  a0 0b 20 ff  and  %o4, 0xff, %l0
a00f0ad0:  96 02 e0 01  inc  %o3
a00f0ad4:  98 0a e0 ff  and  %o3, 0xff, %o4
a00f0ad8:  e0 25 c0 00  st  %l0, [ %l7 ]
a00f0adc:  80 a3 20 03  cmp  %o4, 3
a00f0ae0:  08 bf ff f5  bleu  0xa00f0ab4
a00f0ae4:  9a 03 00 0c  add  %o4, %o4, %o5
a00f0ae8:  10 bf ff 6f  b  0xa00f08a4
a00f0aec:  80 a2 60 03  cmp  %o1, 3
a00f0af0:  d2 0a 22 78  ldub  [ %o0 + 0x278 ], %o1
a00f0af4:  80 a2 60 04  cmp  %o1, 4
a00f0af8:  a8 40 20 00  addx  %g0, 0, %l4
a00f0afc:  82 20 00 14  neg  %l4, %g1
a00f0b00:  b4 0a 40 01  and  %o1, %g1, %i2
a00f0b04:  9a 06 80 1a  add  %i2, %i2, %o5
a00f0b08:  d6 16 00 0d  lduh  [ %i0 + %o5 ], %o3
a00f0b0c:  98 02 e0 16  add  %o3, 0x16, %o4
a00f0b10:  bb 2b 20 02  sll  %o4, 2, %i5
a00f0b14:  ae 17 40 19  or  %i5, %i1, %l7
a00f0b18:  f2 05 c0 00  ld  [ %l7 ], %i1
a00f0b1c:  e2 0c c0 12  ldub  [ %l3 + %l2 ], %l1
a00f0b20:  31 00 06 68  sethi  %hi(0x19a000), %i0
a00f0b24:  90 16 21 a8  or  %i0, 0x1a8, %o0	! 0x19a1a8
a00f0b28:  92 10 00 15  mov  %l5, %o1
a00f0b2c:  e2 23 a0 5c  st  %l1, [ %sp + 0x5c ]
a00f0b30:  96 0e 60 0c  and  %i1, 0xc, %o3
a00f0b34:  98 10 00 16  mov  %l6, %o4
a00f0b38:  7f ff b9 8e  call  0xa00df170
a00f0b3c:  9a 10 00 1c  mov  %i4, %o5
a00f0b40:  ea 0c 00 12  ldub  [ %l0 + %l2 ], %l5
a00f0b44:  a6 05 60 01  add  %l5, 1, %l3
a00f0b48:  e6 2c 00 12  stb  %l3, [ %l0 + %l2 ]
a00f0b4c:  b0 10 20 00  clr  %i0
a00f0b50:  81 c7 e0 08  ret
a00f0b54:  81 e8 00 00  restore
