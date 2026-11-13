# leon2m FUN_a00bd4a4 0xa00bd4a4-0xa00bd520 (124 bytes)
a00bd4a4:  9d e3 bf 98  save  %sp, -104, %sp
a00bd4a8:  1b 2a 00 b5  sethi  %hi(0xa802d400), %o5
a00bd4ac:  c2 0b 60 1a  ldub  [ %o5 + 0x1a ], %g1	! 0xa802d41a
a00bd4b0:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00bd4b4:  98 12 20 78  or  %o0, 0x78, %o4	! 0xa802d078
a00bd4b8:  9a 00 60 26  add  %g1, 0x26, %o5
a00bd4bc:  96 10 20 30  mov  0x30, %o3
a00bd4c0:  80 a0 60 09  cmp  %g1, 9
a00bd4c4:  d6 2b 20 07  stb  %o3, [ %o4 + 7 ]
a00bd4c8:  08 80 00 0c  bleu  0xa00bd4f8
a00bd4cc:  82 00 60 30  add  %g1, 0x30, %g1
a00bd4d0:  92 10 20 31  mov  0x31, %o1
a00bd4d4:  da 2b 20 09  stb  %o5, [ %o4 + 9 ]
a00bd4d8:  d2 2b 20 08  stb  %o1, [ %o4 + 8 ]
a00bd4dc:  7f ff f5 d8  call  0xa00bac3c
a00bd4e0:  90 10 20 28  mov  0x28, %o0
a00bd4e4:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00bd4e8:  7f ff f5 1a  call  0xa00ba950
a00bd4ec:  90 10 00 18  mov  %i0, %o0
a00bd4f0:  7f ff f5 bd  call  0xa00babe4
a00bd4f4:  93 e8 20 0b  restore  %g0, 0xb, %o1
a00bd4f8:  c2 2b 20 09  stb  %g1, [ %o4 + 9 ]
a00bd4fc:  d6 2b 20 08  stb  %o3, [ %o4 + 8 ]
a00bd500:  7f ff f5 cf  call  0xa00bac3c
a00bd504:  90 10 20 28  mov  0x28, %o0
a00bd508:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00bd50c:  7f ff f5 11  call  0xa00ba950
a00bd510:  90 10 00 18  mov  %i0, %o0
a00bd514:  7f ff f5 b4  call  0xa00babe4
a00bd518:  93 e8 20 0b  restore  %g0, 0xb, %o1
a00bd51c:  01 00 00 00  nop
