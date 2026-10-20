# leon2m FUN_a00ad5a4 0xa00ad5a4-0xa00ad86c (712 bytes)
a00ad5a4:  9d e3 bf 90  save  %sp, -112, %sp
a00ad5a8:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00ad5ac:  82 1e 20 03  xor  %i0, 3, %g1
a00ad5b0:  80 a0 00 01  cmp  %g0, %g1
a00ad5b4:  9a 60 20 00  subx  %g0, 0, %o5
a00ad5b8:  96 0b 60 06  and  %o5, 6, %o3
a00ad5bc:  b6 0e e0 ff  and  %i3, 0xff, %i3
a00ad5c0:  80 a6 e0 00  cmp  %i3, 0
a00ad5c4:  a8 10 00 1a  mov  %i2, %l4
a00ad5c8:  12 80 00 13  bne  0xa00ad614
a00ad5cc:  a4 02 e0 0a  add  %o3, 0xa, %l2
a00ad5d0:  23 2a 00 b4  sethi  %hi(0xa802d000), %l1
a00ad5d4:  e0 0c 60 33  ldub  [ %l1 + 0x33 ], %l0	! 0xa802d033
a00ad5d8:  9e 1c 20 00  xor  %l0, 0, %o7
a00ad5dc:  80 a0 00 0f  cmp  %g0, %o7
a00ad5e0:  98 40 20 00  addx  %g0, 0, %o4
a00ad5e4:  96 20 00 0c  neg  %o4, %o3
a00ad5e8:  94 0a e0 04  and  %o3, 4, %o2
a00ad5ec:  90 02 a0 3a  add  %o2, 0x3a, %o0
a00ad5f0:  13 00 00 16  sethi  %hi(0x5800), %o1
a00ad5f4:  aa 12 63 9a  or  %o1, 0x39a, %l5	! 0x5b9a
a00ad5f8:  a6 10 00 08  mov  %o0, %l3
a00ad5fc:  ac 10 27 c2  mov  0x7c2, %l6
a00ad600:  80 a6 20 03  cmp  %i0, 3
a00ad604:  12 80 00 98  bne  0xa00ad864
a00ad608:  ae 10 2b 92  mov  0xb92, %l7
a00ad60c:  10 80 00 40  b  0xa00ad70c
a00ad610:  80 a6 e0 00  cmp  %i3, 0
a00ad614:  27 2a 00 b4  sethi  %hi(0xa802d000), %l3
a00ad618:  d4 0c e0 33  ldub  [ %l3 + 0x33 ], %o2	! 0xa802d033
a00ad61c:  80 a0 00 0a  cmp  %g0, %o2
a00ad620:  aa 60 20 00  subx  %g0, 0, %l5
a00ad624:  90 0d 60 04  and  %l5, 4, %o0
a00ad628:  13 00 00 16  sethi  %hi(0x5800), %o1
a00ad62c:  a2 0e a0 ff  and  %i2, 0xff, %l1
a00ad630:  a0 0e 60 ff  and  %i1, 0xff, %l0
a00ad634:  aa 12 60 9a  or  %o1, 0x9a, %l5
a00ad638:  a6 02 20 38  add  %o0, 0x38, %l3
a00ad63c:  96 02 e0 08  add  %o3, 8, %o3
a00ad640:  90 10 20 01  mov  1, %o0
a00ad644:  92 10 00 10  mov  %l0, %o1
a00ad648:  40 00 1a 22  call  0xa00b3ed0
a00ad64c:  94 10 00 11  mov  %l1, %o2
a00ad650:  82 1c 60 0a  xor  %l1, 0xa, %g1
a00ad654:  80 a0 00 01  cmp  %g0, %g1
a00ad658:  ae 60 3f ff  subx  %g0, -1, %l7
a00ad65c:  9a 1e 20 02  xor  %i0, 2, %o5
a00ad660:  80 a0 00 0d  cmp  %g0, %o5
a00ad664:  ac 60 3f ff  subx  %g0, -1, %l6
a00ad668:  80 8d c0 16  btst  %l7, %l6
a00ad66c:  ac 10 27 42  mov  0x742, %l6
a00ad670:  12 80 00 4e  bne  0xa00ad7a8
a00ad674:  ae 10 23 92  mov  0x392, %l7
a00ad678:  90 10 20 29  mov  0x29, %o0
a00ad67c:  d0 23 a0 5c  st  %o0, [ %sp + 0x5c ]
a00ad680:  03 00 00 16  sethi  %hi(0x5800), %g1
a00ad684:  94 10 60 9a  or  %g1, 0x9a, %o2	! 0x589a
a00ad688:  96 10 00 10  mov  %l0, %o3
a00ad68c:  90 10 20 00  clr  %o0
a00ad690:  92 10 20 01  mov  1, %o1
a00ad694:  98 10 00 11  mov  %l1, %o4
a00ad698:  9a 10 20 03  mov  3, %o5
a00ad69c:  40 00 17 12  call  0xa00b32e4
a00ad6a0:  01 00 00 00  nop
a00ad6a4:  9e 0c a0 ff  and  %l2, 0xff, %o7
a00ad6a8:  96 0e 60 ff  and  %i1, 0xff, %o3
a00ad6ac:  b4 02 c0 0f  add  %o3, %o7, %i2
a00ad6b0:  94 10 20 2c  mov  0x2c, %o2
a00ad6b4:  98 06 bf ff  add  %i2, -1, %o4
a00ad6b8:  d4 23 a0 5c  st  %o2, [ %sp + 0x5c ]
a00ad6bc:  13 00 00 16  sethi  %hi(0x5800), %o1
a00ad6c0:  94 12 60 9a  or  %o1, 0x9a, %o2	! 0x589a
a00ad6c4:  a1 2b 20 10  sll  %o4, 0x10, %l0
a00ad6c8:  97 34 20 10  srl  %l0, 0x10, %o3
a00ad6cc:  98 10 00 11  mov  %l1, %o4
a00ad6d0:  9a 10 20 03  mov  3, %o5
a00ad6d4:  90 10 20 00  clr  %o0
a00ad6d8:  40 00 17 03  call  0xa00b32e4
a00ad6dc:  92 10 20 01  mov  1, %o1
a00ad6e0:  90 10 20 01  mov  1, %o0
a00ad6e4:  92 10 20 01  mov  1, %o1
a00ad6e8:  40 02 65 56  call  0xa0146c40
a00ad6ec:  94 10 20 00  clr  %o2
a00ad6f0:  90 10 20 02  mov  2, %o0
a00ad6f4:  92 10 20 01  mov  1, %o1
a00ad6f8:  40 02 65 52  call  0xa0146c40
a00ad6fc:  94 10 20 00  clr  %o2
a00ad700:  80 a6 20 03  cmp  %i0, 3
a00ad704:  12 80 00 58  bne  0xa00ad864
a00ad708:  80 a6 e0 00  cmp  %i3, 0
a00ad70c:  b4 0d 20 ff  and  %l4, 0xff, %i2
a00ad710:  02 80 00 3b  be  0xa00ad7fc
a00ad714:  b6 0e 60 ff  and  %i1, 0xff, %i3
a00ad718:  a2 0d 20 ff  and  %l4, 0xff, %l1
a00ad71c:  b2 06 e0 01  add  %i3, 1, %i1
a00ad720:  98 04 60 01  add  %l1, 1, %o4
a00ad724:  9f 2e 60 10  sll  %i1, 0x10, %o7
a00ad728:  96 04 bf fe  add  %l2, -2, %o3
a00ad72c:  95 2b 20 10  sll  %o4, 0x10, %o2
a00ad730:  b1 33 e0 10  srl  %o7, 0x10, %i0
a00ad734:  b6 0a e0 ff  and  %o3, 0xff, %i3
a00ad738:  93 32 a0 10  srl  %o2, 0x10, %o1
a00ad73c:  96 0d a7 c2  and  %l6, 0x7c2, %o3
a00ad740:  90 10 00 18  mov  %i0, %o0
a00ad744:  94 10 00 1b  mov  %i3, %o2
a00ad748:  40 02 64 ce  call  0xa0146a80
a00ad74c:  98 10 20 00  clr  %o4
a00ad750:  92 0c e0 ff  and  %l3, 0xff, %o1
a00ad754:  a4 0d eb 92  and  %l7, 0xb92, %l2
a00ad758:  d2 23 a0 5c  st  %o1, [ %sp + 0x5c ]
a00ad75c:  98 10 00 1a  mov  %i2, %o4
a00ad760:  94 10 00 12  mov  %l2, %o2
a00ad764:  96 10 00 18  mov  %i0, %o3
a00ad768:  9a 10 00 1b  mov  %i3, %o5
a00ad76c:  ac 05 20 02  add  %l4, 2, %l6
a00ad770:  90 10 20 01  mov  1, %o0
a00ad774:  92 10 20 00  clr  %o1
a00ad778:  40 00 16 db  call  0xa00b32e4
a00ad77c:  ae 04 e0 01  add  %l3, 1, %l7
a00ad780:  a8 0d e0 ff  and  %l7, 0xff, %l4
a00ad784:  e8 23 a0 5c  st  %l4, [ %sp + 0x5c ]
a00ad788:  94 10 00 12  mov  %l2, %o2
a00ad78c:  96 10 00 18  mov  %i0, %o3
a00ad790:  98 0d a0 ff  and  %l6, 0xff, %o4
a00ad794:  9a 10 00 1b  mov  %i3, %o5
a00ad798:  90 10 20 01  mov  1, %o0
a00ad79c:  40 00 16 d2  call  0xa00b32e4
a00ad7a0:  92 10 20 00  clr  %o1
a00ad7a4:  30 80 00 30  b,a   0xa00ad864
a00ad7a8:  9a 10 20 29  mov  0x29, %o5
a00ad7ac:  da 23 a0 5c  st  %o5, [ %sp + 0x5c ]
a00ad7b0:  1f 00 00 16  sethi  %hi(0x5800), %o7
a00ad7b4:  94 13 e0 9a  or  %o7, 0x9a, %o2	! 0x589a
a00ad7b8:  96 10 00 10  mov  %l0, %o3
a00ad7bc:  98 10 00 11  mov  %l1, %o4
a00ad7c0:  90 10 20 00  clr  %o0
a00ad7c4:  92 10 20 01  mov  1, %o1
a00ad7c8:  40 00 16 c7  call  0xa00b32e4
a00ad7cc:  9a 10 20 02  mov  2, %o5
a00ad7d0:  98 06 a0 02  add  %i2, 2, %o4
a00ad7d4:  96 10 20 2f  mov  0x2f, %o3
a00ad7d8:  d6 23 a0 5c  st  %o3, [ %sp + 0x5c ]
a00ad7dc:  35 00 00 29  sethi  %hi(0xa400), %i2
a00ad7e0:  94 16 a1 9a  or  %i2, 0x19a, %o2	! 0xa59a
a00ad7e4:  96 10 00 10  mov  %l0, %o3
a00ad7e8:  98 0b 20 ff  and  %o4, 0xff, %o4
a00ad7ec:  90 10 20 00  clr  %o0
a00ad7f0:  92 10 20 00  clr  %o1
a00ad7f4:  10 bf ff aa  b  0xa00ad69c
a00ad7f8:  9a 10 20 01  mov  1, %o5
a00ad7fc:  a1 2d 60 10  sll  %l5, 0x10, %l0
a00ad800:  90 10 20 29  mov  0x29, %o0
a00ad804:  a3 34 20 10  srl  %l0, 0x10, %l1
a00ad808:  d0 23 a0 5c  st  %o0, [ %sp + 0x5c ]
a00ad80c:  94 10 00 11  mov  %l1, %o2
a00ad810:  96 0e 60 ff  and  %i1, 0xff, %o3
a00ad814:  98 10 00 1a  mov  %i2, %o4
a00ad818:  90 10 20 00  clr  %o0
a00ad81c:  92 10 20 01  mov  1, %o1
a00ad820:  40 00 16 b1  call  0xa00b32e4
a00ad824:  9a 10 20 03  mov  3, %o5
a00ad828:  82 0c a0 ff  and  %l2, 0xff, %g1
a00ad82c:  9a 06 c0 01  add  %i3, %g1, %o5
a00ad830:  aa 03 7f ff  add  %o5, -1, %l5
a00ad834:  b1 2d 60 10  sll  %l5, 0x10, %i0
a00ad838:  b2 10 20 2c  mov  0x2c, %i1
a00ad83c:  f2 23 a0 5c  st  %i1, [ %sp + 0x5c ]
a00ad840:  94 10 00 11  mov  %l1, %o2
a00ad844:  97 36 20 10  srl  %i0, 0x10, %o3
a00ad848:  90 10 20 00  clr  %o0
a00ad84c:  92 10 20 01  mov  1, %o1
a00ad850:  98 10 00 1a  mov  %i2, %o4
a00ad854:  40 00 16 a4  call  0xa00b32e4
a00ad858:  9a 10 20 03  mov  3, %o5
a00ad85c:  10 bf ff b0  b  0xa00ad71c
a00ad860:  a2 0d 20 ff  and  %l4, 0xff, %l1
a00ad864:  81 c7 e0 08  ret
a00ad868:  81 e8 00 00  restore
