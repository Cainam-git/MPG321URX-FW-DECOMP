# leon2m FUN_a01566b0 0xa01566b0-0xa0156714 (100 bytes)
a01566b0:  9d e3 bf 58  save  %sp, -168, %sp
a01566b4:  a0 07 bf e0  add  %fp, -32, %l0
a01566b8:  f0 3f bf c0  std  %i0, [ %fp + -64 ]
a01566bc:  f4 3f bf b8  std  %i2, [ %fp + -72 ]
a01566c0:  90 07 bf c0  add  %fp, -64, %o0
a01566c4:  40 00 03 22  call  0xa015734c
a01566c8:  92 10 00 10  mov  %l0, %o1
a01566cc:  b6 07 bf c8  add  %fp, -56, %i3
a01566d0:  90 07 bf b8  add  %fp, -72, %o0
a01566d4:  40 00 03 1e  call  0xa015734c
a01566d8:  92 10 00 1b  mov  %i3, %o1
a01566dc:  c2 07 bf e0  ld  [ %fp + -32 ], %g1
a01566e0:  80 a0 60 01  cmp  %g1, 1
a01566e4:  08 80 00 0a  bleu  0xa015670c
a01566e8:  b0 10 20 01  mov  1, %i0
a01566ec:  c2 07 bf c8  ld  [ %fp + -56 ], %g1
a01566f0:  90 10 00 10  mov  %l0, %o0
a01566f4:  80 a0 60 01  cmp  %g1, 1
a01566f8:  08 80 00 05  bleu  0xa015670c
a01566fc:  92 10 00 1b  mov  %i3, %o1
a0156700:  40 00 03 60  call  0xa0157480
a0156704:  01 00 00 00  nop
a0156708:  b0 10 00 08  mov  %o0, %i0
a015670c:  81 c7 e0 08  ret
a0156710:  81 e8 00 00  restore
