# leon2m FUN_a01567dc 0xa01567dc-0xa0156840 (100 bytes)
a01567dc:  9d e3 bf 58  save  %sp, -168, %sp
a01567e0:  a0 07 bf e0  add  %fp, -32, %l0
a01567e4:  f0 3f bf c0  std  %i0, [ %fp + -64 ]
a01567e8:  f4 3f bf b8  std  %i2, [ %fp + -72 ]
a01567ec:  90 07 bf c0  add  %fp, -64, %o0
a01567f0:  40 00 02 d7  call  0xa015734c
a01567f4:  92 10 00 10  mov  %l0, %o1
a01567f8:  b6 07 bf c8  add  %fp, -56, %i3
a01567fc:  90 07 bf b8  add  %fp, -72, %o0
a0156800:  40 00 02 d3  call  0xa015734c
a0156804:  92 10 00 1b  mov  %i3, %o1
a0156808:  c2 07 bf e0  ld  [ %fp + -32 ], %g1
a015680c:  80 a0 60 01  cmp  %g1, 1
a0156810:  08 80 00 0a  bleu  0xa0156838
a0156814:  b0 10 3f ff  mov  -1, %i0
a0156818:  c2 07 bf c8  ld  [ %fp + -56 ], %g1
a015681c:  90 10 00 10  mov  %l0, %o0
a0156820:  80 a0 60 01  cmp  %g1, 1
a0156824:  08 80 00 05  bleu  0xa0156838
a0156828:  92 10 00 1b  mov  %i3, %o1
a015682c:  40 00 03 15  call  0xa0157480
a0156830:  01 00 00 00  nop
a0156834:  b0 10 00 08  mov  %o0, %i0
a0156838:  81 c7 e0 08  ret
a015683c:  81 e8 00 00  restore
