# leon2m FUN_a00a27a4 0xa00a27a4-0xa00a285c (184 bytes)
a00a27a4:  9d e3 bf 98  save  %sp, -104, %sp
a00a27a8:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00a27ac:  1b 2a 00 97  sethi  %hi(0xa8025c00), %o5
a00a27b0:  a0 10 62 90  or  %g1, 0x290, %l0
a00a27b4:  de 0b 60 55  ldub  [ %o5 + 0x55 ], %o7
a00a27b8:  98 10 20 02  mov  2, %o4
a00a27bc:  23 2a 00 97  sethi  %hi(0xa8025c00), %l1
a00a27c0:  de 2c 21 ed  stb  %o7, [ %l0 + 0x1ed ]
a00a27c4:  d8 2c 60 56  stb  %o4, [ %l1 + 0x56 ]
a00a27c8:  40 00 1a fd  call  0xa00a93bc
a00a27cc:  90 10 20 00  clr  %o0
a00a27d0:  40 00 19 2e  call  0xa00a8c88
a00a27d4:  01 00 00 00  nop
a00a27d8:  96 10 20 c2  mov  0xc2, %o3	! 0xc2
a00a27dc:  15 2a 00 ab  sethi  %hi(0xa802ac00), %o2
a00a27e0:  d6 22 a3 ec  st  %o3, [ %o2 + 0x3ec ]	! 0xa802afec
a00a27e4:  40 00 27 cd  call  0xa00ac718
a00a27e8:  90 10 20 3a  mov  0x3a, %o0
a00a27ec:  d0 0c 60 56  ldub  [ %l1 + 0x56 ], %o0
a00a27f0:  40 00 1b 98  call  0xa00a9650
a00a27f4:  92 10 20 01  mov  1, %o1
a00a27f8:  92 10 3f ff  mov  -1, %o1
a00a27fc:  40 00 23 30  call  0xa00ab4bc
a00a2800:  d2 2c 21 89  stb  %o1, [ %l0 + 0x189 ]
a00a2804:  90 10 20 01  mov  1, %o0
a00a2808:  40 00 1b 18  call  0xa00a9468
a00a280c:  92 10 20 02  mov  2, %o1
a00a2810:  90 10 20 02  mov  2, %o0
a00a2814:  40 00 1b 15  call  0xa00a9468
a00a2818:  92 10 20 05  mov  5, %o1
a00a281c:  92 10 20 00  clr  %o1
a00a2820:  40 00 1b 12  call  0xa00a9468
a00a2824:  90 10 20 00  clr  %o0
a00a2828:  40 00 43 09  call  0xa00b344c
a00a282c:  90 10 20 07  mov  7, %o0
a00a2830:  90 10 20 00  clr  %o0
a00a2834:  40 00 43 28  call  0xa00b34d4
a00a2838:  92 10 20 01  mov  1, %o1
a00a283c:  40 00 e0 d5  call  0xa00dab90
a00a2840:  01 00 00 00  nop
a00a2844:  1b 2a 00 ac  sethi  %hi(0xa802b000), %o5
a00a2848:  d0 0b 60 8e  ldub  [ %o5 + 0x8e ], %o0	! 0xa802b08e
a00a284c:  82 12 20 02  or  %o0, 2, %g1
a00a2850:  c2 2b 60 8e  stb  %g1, [ %o5 + 0x8e ]
a00a2854:  81 c7 e0 08  ret
a00a2858:  81 e8 00 00  restore
