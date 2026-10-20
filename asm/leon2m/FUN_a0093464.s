# leon2m FUN_a0093464 0xa0093464-0xa00934dc (120 bytes)
a0093464:  9d e3 bf 98  save  %sp, -104, %sp
a0093468:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a009346c:  a0 12 22 90  or  %o0, 0x290, %l0	! 0xa802d290
a0093470:  c2 04 20 a8  ld  [ %l0 + 0xa8 ], %g1
a0093474:  a3 30 60 0c  srl  %g1, 0xc, %l1
a0093478:  b0 0c 60 01  and  %l1, 1, %i0
a009347c:  92 06 20 01  add  %i0, 1, %o1
a0093480:  90 10 20 01  mov  1, %o0
a0093484:  40 00 53 2e  call  0xa00a813c
a0093488:  94 10 20 00  clr  %o2
a009348c:  f2 04 20 a8  ld  [ %l0 + 0xa8 ], %i1
a0093490:  23 2a 00 ab  sethi  %hi(0xa802ac00), %l1
a0093494:  9f 36 60 0c  srl  %i1, 0xc, %o7
a0093498:  d8 04 63 ec  ld  [ %l1 + 0x3ec ], %o4
a009349c:  9a 0b e0 01  and  %o7, 1, %o5
a00934a0:  94 03 3f f2  add  %o4, -14, %o2
a00934a4:  17 2a 00 97  sethi  %hi(0xa8025c00), %o3
a00934a8:  90 0a a0 ff  and  %o2, 0xff, %o0
a00934ac:  92 10 20 02  mov  2, %o1
a00934b0:  40 00 56 d7  call  0xa00a900c
a00934b4:  da 2a e0 56  stb  %o5, [ %o3 + 0x56 ]
a00934b8:  d2 04 20 a8  ld  [ %l0 + 0xa8 ], %o1
a00934bc:  91 32 60 0c  srl  %o1, 0xc, %o0
a00934c0:  b0 0a 20 01  and  %o0, 1, %i0
a00934c4:  82 06 20 54  add  %i0, 0x54, %g1
a00934c8:  c2 24 63 ec  st  %g1, [ %l1 + 0x3ec ]
a00934cc:  b0 06 20 01  inc  %i0
a00934d0:  40 00 58 60  call  0xa00a9650
a00934d4:  93 e8 20 01  restore  %g0, 1, %o1
a00934d8:  01 00 00 00  nop
