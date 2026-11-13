# leon2s FUN_a00ce66c 0xa00ce66c-0xa00ce864 (504 bytes)
a00ce66c:  9d e3 bf 78  save  %sp, -136, %sp
a00ce670:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00ce674:  82 06 00 18  add  %i0, %i0, %g1
a00ce678:  82 00 40 18  add  %g1, %i0, %g1
a00ce67c:  1b 2a 01 e2  sethi  %hi(0xa8078800), %o5
a00ce680:  a1 28 60 03  sll  %g1, 3, %l0
a00ce684:  a2 13 63 b0  or  %o5, 0x3b0, %l1
a00ce688:  da 04 40 10  ld  [ %l1 + %l0 ], %o5
a00ce68c:  03 00 00 c0  sethi  %hi(0x30000), %g1
a00ce690:  82 2b 40 01  andn  %o5, %g1, %g1
a00ce694:  1b 00 00 40  sethi  %hi(0x10000), %o5
a00ce698:  82 10 40 0d  or  %g1, %o5, %g1
a00ce69c:  a4 07 bf d8  add  %fp, -40, %l2
a00ce6a0:  15 00 01 a5  sethi  %hi(0x69400), %o2
a00ce6a4:  c2 24 40 10  st  %g1, [ %l1 + %l0 ]
a00ce6a8:  94 12 a0 93  or  %o2, 0x93, %o2
a00ce6ac:  90 10 20 00  clr  %o0
a00ce6b0:  92 10 20 90  mov  0x90, %o1
a00ce6b4:  96 10 20 00  clr  %o3
a00ce6b8:  40 3b 1f 52  call  0xa0f96400
a00ce6bc:  98 10 00 12  mov  %l2, %o4
a00ce6c0:  c2 0f bf d8  ldub  [ %fp + -40 ], %g1
a00ce6c4:  80 88 60 04  btst  4, %g1
a00ce6c8:  12 80 00 06  bne  0xa00ce6e0
a00ce6cc:  1b 00 00 c0  sethi  %hi(0x30000), %o5
a00ce6d0:  c2 04 40 10  ld  [ %l1 + %l0 ], %g1
a00ce6d4:  82 10 40 0d  or  %g1, %o5, %g1
a00ce6d8:  10 80 00 61  b  0xa00ce85c
a00ce6dc:  c2 24 40 10  st  %g1, [ %l1 + %l0 ]
a00ce6e0:  15 00 01 a4  sethi  %hi(0x69000), %o2
a00ce6e4:  94 12 a2 e0  or  %o2, 0x2e0, %o2	! 0x692e0
a00ce6e8:  98 10 00 12  mov  %l2, %o4
a00ce6ec:  92 10 20 90  mov  0x90, %o1
a00ce6f0:  96 10 20 0f  mov  0xf, %o3
a00ce6f4:  40 3b 1f 43  call  0xa0f96400
a00ce6f8:  90 10 20 00  clr  %o0
a00ce6fc:  90 10 00 18  mov  %i0, %o0
a00ce700:  92 10 20 01  mov  1, %o1
a00ce704:  7f ff e8 39  call  0xa00c87e8
a00ce708:  15 00 00 20  sethi  %hi(0x8000), %o2
a00ce70c:  a2 10 20 00  clr  %l1
a00ce710:  90 10 00 18  mov  %i0, %o0
a00ce714:  7f ff e4 17  call  0xa00c7770
a00ce718:  92 10 20 01  mov  1, %o1
a00ce71c:  a1 2c 60 10  sll  %l1, 0x10, %l0
a00ce720:  9a 04 60 01  add  %l1, 1, %o5
a00ce724:  a1 34 20 10  srl  %l0, 0x10, %l0
a00ce728:  a4 07 bf f8  add  %fp, -8, %l2
a00ce72c:  83 2b 60 10  sll  %o5, 0x10, %g1
a00ce730:  a0 04 80 10  add  %l2, %l0, %l0
a00ce734:  83 30 60 10  srl  %g1, 0x10, %g1
a00ce738:  d0 2c 3f f0  stb  %o0, [ %l0 + -16 ]
a00ce73c:  80 a0 60 07  cmp  %g1, 7
a00ce740:  08 bf ff f4  bleu  0xa00ce710
a00ce744:  a2 10 00 0d  mov  %o5, %l1
a00ce748:  90 10 00 18  mov  %i0, %o0
a00ce74c:  92 10 20 03  mov  3, %o1
a00ce750:  7f ff e8 26  call  0xa00c87e8
a00ce754:  15 00 00 20  sethi  %hi(0x8000), %o2
a00ce758:  a2 10 20 08  mov  8, %l1
a00ce75c:  90 10 00 18  mov  %i0, %o0
a00ce760:  7f ff e4 04  call  0xa00c7770
a00ce764:  92 10 20 01  mov  1, %o1
a00ce768:  a1 2c 60 10  sll  %l1, 0x10, %l0
a00ce76c:  9a 04 60 01  add  %l1, 1, %o5
a00ce770:  a1 34 20 10  srl  %l0, 0x10, %l0
a00ce774:  83 2b 60 10  sll  %o5, 0x10, %g1
a00ce778:  a0 04 80 10  add  %l2, %l0, %l0
a00ce77c:  83 30 60 10  srl  %g1, 0x10, %g1
a00ce780:  d0 2c 3f f0  stb  %o0, [ %l0 + -16 ]
a00ce784:  80 a0 60 0f  cmp  %g1, 0xf
a00ce788:  08 bf ff f5  bleu  0xa00ce75c
a00ce78c:  a2 10 00 0d  mov  %o5, %l1
a00ce790:  90 10 00 18  mov  %i0, %o0
a00ce794:  92 10 20 05  mov  5, %o1
a00ce798:  7f ff e8 14  call  0xa00c87e8
a00ce79c:  15 00 00 20  sethi  %hi(0x8000), %o2
a00ce7a0:  a2 10 20 00  clr  %l1
a00ce7a4:  83 2c 60 10  sll  %l1, 0x10, %g1
a00ce7a8:  83 30 60 10  srl  %g1, 0x10, %g1
a00ce7ac:  82 04 80 01  add  %l2, %g1, %g1
a00ce7b0:  d4 08 7f e0  ldub  [ %g1 + -32 ], %o2
a00ce7b4:  90 10 00 18  mov  %i0, %o0
a00ce7b8:  7f ff e3 a7  call  0xa00c7654
a00ce7bc:  92 10 20 01  mov  1, %o1
a00ce7c0:  9a 04 60 01  add  %l1, 1, %o5
a00ce7c4:  83 2b 60 10  sll  %o5, 0x10, %g1
a00ce7c8:  83 30 60 10  srl  %g1, 0x10, %g1
a00ce7cc:  80 a0 60 0f  cmp  %g1, 0xf
a00ce7d0:  08 bf ff f5  bleu  0xa00ce7a4
a00ce7d4:  a2 10 00 0d  mov  %o5, %l1
a00ce7d8:  a2 10 20 00  clr  %l1
a00ce7dc:  83 2c 60 10  sll  %l1, 0x10, %g1
a00ce7e0:  83 30 60 10  srl  %g1, 0x10, %g1
a00ce7e4:  82 04 80 01  add  %l2, %g1, %g1
a00ce7e8:  d4 08 7f f0  ldub  [ %g1 + -16 ], %o2
a00ce7ec:  90 10 00 18  mov  %i0, %o0
a00ce7f0:  7f ff e3 99  call  0xa00c7654
a00ce7f4:  92 10 20 01  mov  1, %o1
a00ce7f8:  9a 04 60 01  add  %l1, 1, %o5
a00ce7fc:  83 2b 60 10  sll  %o5, 0x10, %g1
a00ce800:  83 30 60 10  srl  %g1, 0x10, %g1
a00ce804:  80 a0 60 0f  cmp  %g1, 0xf
a00ce808:  08 bf ff f5  bleu  0xa00ce7dc
a00ce80c:  a2 10 00 0d  mov  %o5, %l1
a00ce810:  83 2e 20 02  sll  %i0, 2, %g1
a00ce814:  1b 2a 01 f3  sethi  %hi(0xa807cc00), %o5
a00ce818:  82 00 40 18  add  %g1, %i0, %g1
a00ce81c:  9a 13 62 38  or  %o5, 0x238, %o5
a00ce820:  90 00 40 0d  add  %g1, %o5, %o0
a00ce824:  03 2a 01 f3  sethi  %hi(0xa807cc00), %g1
a00ce828:  94 10 61 a8  or  %g1, 0x1a8, %o2	! 0xa807cda8
a00ce82c:  a2 10 20 00  clr  %l1
a00ce830:  83 2c 60 10  sll  %l1, 0x10, %g1
a00ce834:  96 04 60 01  add  %l1, 1, %o3
a00ce838:  83 30 60 10  srl  %g1, 0x10, %g1
a00ce83c:  d8 0a 00 01  ldub  [ %o0 + %g1 ], %o4
a00ce840:  9b 2a e0 10  sll  %o3, 0x10, %o5
a00ce844:  9b 33 60 10  srl  %o5, 0x10, %o5
a00ce848:  82 00 40 0a  add  %g1, %o2, %g1
a00ce84c:  d8 28 60 0a  stb  %o4, [ %g1 + 0xa ]
a00ce850:  80 a3 60 04  cmp  %o5, 4
a00ce854:  08 bf ff f7  bleu  0xa00ce830
a00ce858:  a2 10 00 0b  mov  %o3, %l1
a00ce85c:  81 c7 e0 08  ret
a00ce860:  81 e8 00 00  restore
