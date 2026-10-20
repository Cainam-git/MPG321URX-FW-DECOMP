# leon2m FUN_a00e2714 0xa00e2714-0xa00e285c (328 bytes)
a00e2714:  9d e3 bf 98  save  %sp, -104, %sp
a00e2718:  80 a6 60 09  cmp  %i1, 9
a00e271c:  18 80 00 38  bgu  0xa00e27fc
a00e2720:  82 10 00 19  mov  %i1, %g1
a00e2724:  80 a6 a0 09  cmp  %i2, 9
a00e2728:  18 80 00 2e  bgu  0xa00e27e0
a00e272c:  b2 10 00 1a  mov  %i2, %i1
a00e2730:  13 2a 00 98  sethi  %hi(0xa8026000), %o1
a00e2734:  15 2a 00 98  sethi  %hi(0xa8026000), %o2
a00e2738:  17 2a 00 98  sethi  %hi(0xa8026000), %o3
a00e273c:  b5 28 60 02  sll  %g1, 2, %i2
a00e2740:  98 10 00 1d  mov  %i5, %o4
a00e2744:  90 10 00 18  mov  %i0, %o0
a00e2748:  92 12 61 f0  or  %o1, 0x1f0, %o1
a00e274c:  94 12 a1 c8  or  %o2, 0x1c8, %o2
a00e2750:  80 a0 7f ff  cmp  %g1, -1
a00e2754:  02 80 00 30  be  0xa00e2814
a00e2758:  96 12 e1 a0  or  %o3, 0x1a0, %o3
a00e275c:  1b 2a 00 98  sethi  %hi(0xa8026000), %o5
a00e2760:  17 2a 00 98  sethi  %hi(0xa8026000), %o3
a00e2764:  3b 2a 00 98  sethi  %hi(0xa8026000), %i5
a00e2768:  82 12 e1 c8  or  %o3, 0x1c8, %g1
a00e276c:  b2 13 61 f0  or  %o5, 0x1f0, %i1
a00e2770:  a2 17 61 a0  or  %i5, 0x1a0, %l1
a00e2774:  d4 00 40 1a  ld  [ %g1 + %i2 ], %o2
a00e2778:  d2 06 40 1a  ld  [ %i1 + %i2 ], %o1
a00e277c:  7f ff f7 fe  call  0xa00e0774
a00e2780:  d6 04 40 1a  ld  [ %l1 + %i2 ], %o3
a00e2784:  13 2a 00 98  sethi  %hi(0xa8026000), %o1
a00e2788:  15 2a 00 98  sethi  %hi(0xa8026000), %o2
a00e278c:  19 2a 00 98  sethi  %hi(0xa8026000), %o4
a00e2790:  b2 13 21 28  or  %o4, 0x128, %i1	! 0xa8026128
a00e2794:  9e 12 61 78  or  %o1, 0x178, %o7
a00e2798:  9a 12 a1 50  or  %o2, 0x150, %o5
a00e279c:  d6 06 40 1a  ld  [ %i1 + %i2 ], %o3
a00e27a0:  90 10 00 18  mov  %i0, %o0
a00e27a4:  d2 03 c0 1a  ld  [ %o7 + %i2 ], %o1
a00e27a8:  d4 03 40 1a  ld  [ %o5 + %i2 ], %o2
a00e27ac:  7f ff f7 f2  call  0xa00e0774
a00e27b0:  98 10 00 1b  mov  %i3, %o4
a00e27b4:  17 2a 00 ad  sethi  %hi(0xa802b400), %o3
a00e27b8:  3b 2a 00 98  sethi  %hi(0xa8026000), %i5
a00e27bc:  82 12 e1 d0  or  %o3, 0x1d0, %g1
a00e27c0:  a2 17 61 00  or  %i5, 0x100, %l1
a00e27c4:  21 2a 00 98  sethi  %hi(0xa8026000), %l0
a00e27c8:  f6 00 40 1a  ld  [ %g1 + %i2 ], %i3
a00e27cc:  f2 04 40 1a  ld  [ %l1 + %i2 ], %i1
a00e27d0:  90 14 20 d8  or  %l0, 0xd8, %o0
a00e27d4:  f4 02 00 1a  ld  [ %o0 + %i2 ], %i2
a00e27d8:  7f ff f7 e7  call  0xa00e0774
a00e27dc:  81 e8 00 00  restore
a00e27e0:  7f ff f4 0b  call  0xa00df80c
a00e27e4:  01 00 00 00  nop
a00e27e8:  7f ff f8 f6  call  0xa00e0bc0
a00e27ec:  01 00 00 00  nop
a00e27f0:  03 00 06 65  sethi  %hi(0x199400), %g1
a00e27f4:  7f ff f2 5f  call  0xa00df170
a00e27f8:  91 e8 63 68  restore  %g1, 0x368, %o0
a00e27fc:  7f ff f4 04  call  0xa00df80c
a00e2800:  31 00 06 65  sethi  %hi(0x199400), %i0
a00e2804:  7f ff f8 ef  call  0xa00e0bc0
a00e2808:  b0 16 23 88  or  %i0, 0x388, %i0	! 0x199788
a00e280c:  7f ff f2 59  call  0xa00df170
a00e2810:  81 e8 00 00  restore
a00e2814:  7f ff f7 d8  call  0xa00e0774
a00e2818:  33 2a 00 98  sethi  %hi(0xa8026000), %i1
a00e281c:  19 2a 00 98  sethi  %hi(0xa8026000), %o4
a00e2820:  96 13 21 28  or  %o4, 0x128, %o3	! 0xa8026128
a00e2824:  1f 2a 00 98  sethi  %hi(0xa8026000), %o7
a00e2828:  1b 2a 00 98  sethi  %hi(0xa8026000), %o5
a00e282c:  98 10 00 1b  mov  %i3, %o4
a00e2830:  90 10 00 18  mov  %i0, %o0
a00e2834:  92 13 e1 78  or  %o7, 0x178, %o1
a00e2838:  94 13 61 50  or  %o5, 0x150, %o2
a00e283c:  35 2a 00 98  sethi  %hi(0xa8026000), %i2
a00e2840:  7f ff f7 cd  call  0xa00e0774
a00e2844:  37 2a 00 ad  sethi  %hi(0xa802b400), %i3
a00e2848:  b2 16 61 00  or  %i1, 0x100, %i1
a00e284c:  b4 16 a0 d8  or  %i2, 0xd8, %i2
a00e2850:  7f ff f7 c9  call  0xa00e0774
a00e2854:  97 ee e1 d0  restore  %i3, 0x1d0, %o3
a00e2858:  01 00 00 00  nop
