# leon2m FUN_a0091710 0xa0091710-0xa0091784 (116 bytes)
a0091710:  9d e3 bf 98  save  %sp, -104, %sp
a0091714:  21 2a 00 ab  sethi  %hi(0xa802ac00), %l0
a0091718:  d6 04 23 ec  ld  [ %l0 + 0x3ec ], %o3	! 0xa802afec
a009171c:  94 02 ff f5  add  %o3, -11, %o2
a0091720:  40 00 5d f2  call  0xa00a8ee8
a0091724:  90 0a a0 ff  and  %o2, 0xff, %o0
a0091728:  d2 04 23 ec  ld  [ %l0 + 0x3ec ], %o1
a009172c:  90 02 7f f5  add  %o1, -11, %o0
a0091730:  90 0a 20 ff  and  %o0, 0xff, %o0
a0091734:  40 00 63 63  call  0xa00aa4c0
a0091738:  92 10 20 00  clr  %o1
a009173c:  90 10 20 0b  mov  0xb, %o0
a0091740:  40 00 77 43  call  0xa00af44c
a0091744:  92 10 20 00  clr  %o1
a0091748:  90 10 20 00  clr  %o0
a009174c:  40 00 5e 30  call  0xa00a900c
a0091750:  92 10 20 00  clr  %o1
a0091754:  82 10 20 02  mov  2, %g1
a0091758:  c2 24 23 ec  st  %g1, [ %l0 + 0x3ec ]
a009175c:  90 10 20 00  clr  %o0
a0091760:  40 00 8a 79  call  0xa00b4144
a0091764:  92 10 20 01  mov  1, %o1
a0091768:  90 10 20 01  mov  1, %o0
a009176c:  40 00 5f 3f  call  0xa00a9468
a0091770:  92 10 20 02  mov  2, %o1
a0091774:  b0 10 20 00  clr  %i0
a0091778:  40 00 87 57  call  0xa00b34d4
a009177c:  93 e8 20 01  restore  %g0, 1, %o1
a0091780:  01 00 00 00  nop
