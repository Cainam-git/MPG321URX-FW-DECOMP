# leon2m FUN_a0156714 0xa0156714-0xa0156778 (100 bytes)
a0156714:  9d e3 bf 58  save  %sp, -168, %sp
a0156718:  a0 07 bf e0  add  %fp, -32, %l0
a015671c:  f0 3f bf c0  std  %i0, [ %fp + -64 ]
a0156720:  f4 3f bf b8  std  %i2, [ %fp + -72 ]
a0156724:  90 07 bf c0  add  %fp, -64, %o0
a0156728:  40 00 03 09  call  0xa015734c
a015672c:  92 10 00 10  mov  %l0, %o1
a0156730:  b6 07 bf c8  add  %fp, -56, %i3
a0156734:  90 07 bf b8  add  %fp, -72, %o0
a0156738:  40 00 03 05  call  0xa015734c
a015673c:  92 10 00 1b  mov  %i3, %o1
a0156740:  c2 07 bf e0  ld  [ %fp + -32 ], %g1
a0156744:  80 a0 60 01  cmp  %g1, 1
a0156748:  08 80 00 0a  bleu  0xa0156770
a015674c:  b0 10 20 01  mov  1, %i0
a0156750:  c2 07 bf c8  ld  [ %fp + -56 ], %g1
a0156754:  90 10 00 10  mov  %l0, %o0
a0156758:  80 a0 60 01  cmp  %g1, 1
a015675c:  08 80 00 05  bleu  0xa0156770
a0156760:  92 10 00 1b  mov  %i3, %o1
a0156764:  40 00 03 47  call  0xa0157480
a0156768:  01 00 00 00  nop
a015676c:  b0 10 00 08  mov  %o0, %i0
a0156770:  81 c7 e0 08  ret
a0156774:  81 e8 00 00  restore
