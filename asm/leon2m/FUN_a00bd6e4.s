# leon2m FUN_a00bd6e4 0xa00bd6e4-0xa00bd760 (124 bytes)
a00bd6e4:  9d e3 bf 98  save  %sp, -104, %sp
a00bd6e8:  1b 2a 00 b5  sethi  %hi(0xa802d400), %o5
a00bd6ec:  c2 0b 60 1d  ldub  [ %o5 + 0x1d ], %g1	! 0xa802d41d
a00bd6f0:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00bd6f4:  98 12 20 78  or  %o0, 0x78, %o4	! 0xa802d078
a00bd6f8:  9a 00 60 26  add  %g1, 0x26, %o5
a00bd6fc:  96 10 20 30  mov  0x30, %o3
a00bd700:  80 a0 60 09  cmp  %g1, 9
a00bd704:  d6 2b 20 07  stb  %o3, [ %o4 + 7 ]
a00bd708:  08 80 00 0c  bleu  0xa00bd738
a00bd70c:  82 00 60 30  add  %g1, 0x30, %g1
a00bd710:  92 10 20 31  mov  0x31, %o1
a00bd714:  da 2b 20 09  stb  %o5, [ %o4 + 9 ]
a00bd718:  d2 2b 20 08  stb  %o1, [ %o4 + 8 ]
a00bd71c:  7f ff f5 48  call  0xa00bac3c
a00bd720:  90 10 20 2b  mov  0x2b, %o0
a00bd724:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00bd728:  7f ff f4 8a  call  0xa00ba950
a00bd72c:  90 10 00 18  mov  %i0, %o0
a00bd730:  7f ff f5 2d  call  0xa00babe4
a00bd734:  93 e8 20 0b  restore  %g0, 0xb, %o1
a00bd738:  c2 2b 20 09  stb  %g1, [ %o4 + 9 ]
a00bd73c:  d6 2b 20 08  stb  %o3, [ %o4 + 8 ]
a00bd740:  7f ff f5 3f  call  0xa00bac3c
a00bd744:  90 10 20 2b  mov  0x2b, %o0
a00bd748:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00bd74c:  7f ff f4 81  call  0xa00ba950
a00bd750:  90 10 00 18  mov  %i0, %o0
a00bd754:  7f ff f5 24  call  0xa00babe4
a00bd758:  93 e8 20 0b  restore  %g0, 0xb, %o1
a00bd75c:  01 00 00 00  nop
