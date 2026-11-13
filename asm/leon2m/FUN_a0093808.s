# leon2m FUN_a0093808 0xa0093808-0xa0093884 (124 bytes)
a0093808:  9d e3 bf 98  save  %sp, -104, %sp
a009380c:  25 2a 00 ab  sethi  %hi(0xa802ac00), %l2
a0093810:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a0093814:  21 2a 00 97  sethi  %hi(0xa8025c00), %l0
a0093818:  f2 04 a3 ec  ld  [ %l2 + 0x3ec ], %i1
a009381c:  a2 13 62 90  or  %o5, 0x290, %l1
a0093820:  9e 06 7f aa  add  %i1, -86, %o7
a0093824:  f0 0c 20 56  ldub  [ %l0 + 0x56 ], %i0
a0093828:  90 0b e0 ff  and  %o7, 0xff, %o0
a009382c:  40 00 56 e4  call  0xa00a93bc
a0093830:  f0 2c 61 a0  stb  %i0, [ %l1 + 0x1a0 ]
a0093834:  d6 0c 20 56  ldub  [ %l0 + 0x56 ], %o3
a0093838:  94 02 e0 01  add  %o3, 1, %o2
a009383c:  90 0a a0 ff  and  %o2, 0xff, %o0
a0093840:  40 00 57 84  call  0xa00a9650
a0093844:  92 10 20 00  clr  %o1
a0093848:  d0 0c 20 56  ldub  [ %l0 + 0x56 ], %o0
a009384c:  92 02 20 01  add  %o0, 1, %o1
a0093850:  92 0a 60 ff  and  %o1, 0xff, %o1
a0093854:  90 10 20 01  mov  1, %o0
a0093858:  40 00 52 39  call  0xa00a813c
a009385c:  94 10 20 01  mov  1, %o2
a0093860:  d8 0c 61 a0  ldub  [ %l1 + 0x1a0 ], %o4
a0093864:  03 2a 00 ab  sethi  %hi(0xa802ac00), %g1
a0093868:  9a 10 20 12  mov  0x12, %o5
a009386c:  d8 28 63 ea  stb  %o4, [ %g1 + 0x3ea ]
a0093870:  da 24 a3 ec  st  %o5, [ %l2 + 0x3ec ]
a0093874:  b0 10 20 04  mov  4, %i0
a0093878:  40 00 55 e5  call  0xa00a900c
a009387c:  93 e8 20 01  restore  %g0, 1, %o1
a0093880:  01 00 00 00  nop
