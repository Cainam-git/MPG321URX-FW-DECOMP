# leon2m FUN_a00d27ac 0xa00d27ac-0xa00d2884 (216 bytes)
a00d27ac:  9d e3 bf 98  save  %sp, -104, %sp
a00d27b0:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00d27b4:  d8 0e 20 07  ldub  [ %i0 + 7 ], %o4
a00d27b8:  a0 10 62 90  or  %g1, 0x290, %l0
a00d27bc:  80 a3 20 00  cmp  %o4, 0
a00d27c0:  02 80 00 22  be  0xa00d2848
a00d27c4:  96 10 20 19  mov  0x19, %o3
a00d27c8:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00d27cc:  a0 12 62 90  or  %o1, 0x290, %l0	! 0xa802d290
a00d27d0:  96 10 20 46  mov  0x46, %o3
a00d27d4:  80 a3 20 01  cmp  %o4, 1
a00d27d8:  02 80 00 21  be  0xa00d285c
a00d27dc:  b0 10 20 e4  mov  0xe4, %i0
a00d27e0:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00d27e4:  a0 12 e2 90  or  %o3, 0x290, %l0	! 0xa802d290
a00d27e8:  80 a3 20 02  cmp  %o4, 2
a00d27ec:  12 80 00 24  bne  0xa00d287c
a00d27f0:  96 10 20 46  mov  0x46, %o3
a00d27f4:  c2 04 20 a8  ld  [ %l0 + 0xa8 ], %g1
a00d27f8:  1b 2a 00 b8  sethi  %hi(0xa802e000), %o5
a00d27fc:  82 08 77 ff  and  %g1, -2049, %g1
a00d2800:  d8 2b 61 ab  stb  %o4, [ %o5 + 0x1ab ]
a00d2804:  98 10 20 01  mov  1, %o4
a00d2808:  d6 2c 20 59  stb  %o3, [ %l0 + 0x59 ]
a00d280c:  c2 24 20 a8  st  %g1, [ %l0 + 0xa8 ]
a00d2810:  d8 2c 21 82  stb  %o4, [ %l0 + 0x182 ]
a00d2814:  d6 2c 20 09  stb  %o3, [ %l0 + 9 ]
a00d2818:  40 00 19 2f  call  0xa00d8cd4
a00d281c:  c0 2c 21 81  clrb  [ %l0 + 0x181 ]
a00d2820:  40 00 25 34  call  0xa00dbcf0
a00d2824:  b0 10 20 e0  mov  0xe0, %i0
a00d2828:  92 10 00 10  mov  %l0, %o1
a00d282c:  94 10 20 00  clr  %o2
a00d2830:  96 10 21 fc  mov  0x1fc, %o3
a00d2834:  40 01 e1 a7  call  0xa014aed0
a00d2838:  90 10 20 30  mov  0x30, %o0
a00d283c:  40 01 ca c9  call  0xa0145360
a00d2840:  90 10 20 01  mov  1, %o0
a00d2844:  30 80 00 0e  b,a   0xa00d287c
a00d2848:  d0 04 20 a8  ld  [ %l0 + 0xa8 ], %o0
a00d284c:  1b 2a 00 b8  sethi  %hi(0xa802e000), %o5
a00d2850:  82 0a 37 ff  and  %o0, -2049, %g1
a00d2854:  10 bf ff ec  b  0xa00d2804
a00d2858:  c0 2b 61 ab  clrb  [ %o5 + 0x1ab ]
a00d285c:  f0 04 20 a8  ld  [ %l0 + 0xa8 ], %i0
a00d2860:  1f 2a 00 b8  sethi  %hi(0xa802e000), %o7
a00d2864:  94 0e 37 ff  and  %i0, -2049, %o2
a00d2868:  d8 2b e1 ab  stb  %o4, [ %o7 + 0x1ab ]
a00d286c:  d6 2c 20 59  stb  %o3, [ %l0 + 0x59 ]
a00d2870:  d4 24 20 a8  st  %o2, [ %l0 + 0xa8 ]
a00d2874:  10 bf ff e8  b  0xa00d2814
a00d2878:  d8 2c 21 82  stb  %o4, [ %l0 + 0x182 ]
a00d287c:  81 c7 e0 08  ret
a00d2880:  81 e8 00 00  restore
