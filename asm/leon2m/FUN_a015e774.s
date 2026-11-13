# leon2m FUN_a015e774 0xa015e774-0xa015e7d8 (100 bytes)
a015e774:  9d e3 bf 58  save  %sp, -168, %sp
a015e778:  a0 07 bf e0  add  %fp, -32, %l0
a015e77c:  f0 3f bf c0  std  %i0, [ %fp + -64 ]
a015e780:  f4 3f bf b8  std  %i2, [ %fp + -72 ]
a015e784:  90 07 bf c0  add  %fp, -64, %o0
a015e788:  7f ff e2 f1  call  0xa015734c
a015e78c:  92 10 00 10  mov  %l0, %o1
a015e790:  b6 07 bf c8  add  %fp, -56, %i3
a015e794:  90 07 bf b8  add  %fp, -72, %o0
a015e798:  7f ff e2 ed  call  0xa015734c
a015e79c:  92 10 00 1b  mov  %i3, %o1
a015e7a0:  c2 07 bf e0  ld  [ %fp + -32 ], %g1
a015e7a4:  80 a0 60 01  cmp  %g1, 1
a015e7a8:  08 80 00 0a  bleu  0xa015e7d0
a015e7ac:  b0 10 20 01  mov  1, %i0
a015e7b0:  c2 07 bf c8  ld  [ %fp + -56 ], %g1
a015e7b4:  90 10 00 10  mov  %l0, %o0
a015e7b8:  80 a0 60 01  cmp  %g1, 1
a015e7bc:  08 80 00 05  bleu  0xa015e7d0
a015e7c0:  92 10 00 1b  mov  %i3, %o1
a015e7c4:  7f ff e3 2f  call  0xa0157480
a015e7c8:  01 00 00 00  nop
a015e7cc:  b0 10 00 08  mov  %o0, %i0
a015e7d0:  81 c7 e0 08  ret
a015e7d4:  81 e8 00 00  restore
