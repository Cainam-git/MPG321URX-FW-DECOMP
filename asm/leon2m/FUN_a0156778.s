# leon2m FUN_a0156778 0xa0156778-0xa01567dc (100 bytes)
a0156778:  9d e3 bf 58  save  %sp, -168, %sp
a015677c:  a0 07 bf e0  add  %fp, -32, %l0
a0156780:  f0 3f bf c0  std  %i0, [ %fp + -64 ]
a0156784:  f4 3f bf b8  std  %i2, [ %fp + -72 ]
a0156788:  90 07 bf c0  add  %fp, -64, %o0
a015678c:  40 00 02 f0  call  0xa015734c
a0156790:  92 10 00 10  mov  %l0, %o1
a0156794:  b6 07 bf c8  add  %fp, -56, %i3
a0156798:  90 07 bf b8  add  %fp, -72, %o0
a015679c:  40 00 02 ec  call  0xa015734c
a01567a0:  92 10 00 1b  mov  %i3, %o1
a01567a4:  c2 07 bf e0  ld  [ %fp + -32 ], %g1
a01567a8:  80 a0 60 01  cmp  %g1, 1
a01567ac:  08 80 00 0a  bleu  0xa01567d4
a01567b0:  b0 10 3f ff  mov  -1, %i0
a01567b4:  c2 07 bf c8  ld  [ %fp + -56 ], %g1
a01567b8:  90 10 00 10  mov  %l0, %o0
a01567bc:  80 a0 60 01  cmp  %g1, 1
a01567c0:  08 80 00 05  bleu  0xa01567d4
a01567c4:  92 10 00 1b  mov  %i3, %o1
a01567c8:  40 00 03 2e  call  0xa0157480
a01567cc:  01 00 00 00  nop
a01567d0:  b0 10 00 08  mov  %o0, %i0
a01567d4:  81 c7 e0 08  ret
a01567d8:  81 e8 00 00  restore
