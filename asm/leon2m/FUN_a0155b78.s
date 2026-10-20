# leon2m FUN_a0155b78 0xa0155b78-0xa0155bdc (100 bytes)
a0155b78:  9d e3 bf 70  save  %sp, -144, %sp
a0155b7c:  a0 07 bf e8  add  %fp, -24, %l0
a0155b80:  f0 27 bf d4  st  %i0, [ %fp + -44 ]
a0155b84:  f2 27 bf d0  st  %i1, [ %fp + -48 ]
a0155b88:  90 07 bf d4  add  %fp, -44, %o0
a0155b8c:  40 00 04 ea  call  0xa0156f34
a0155b90:  92 10 00 10  mov  %l0, %o1
a0155b94:  b2 07 bf d8  add  %fp, -40, %i1
a0155b98:  90 07 bf d0  add  %fp, -48, %o0
a0155b9c:  40 00 04 e6  call  0xa0156f34
a0155ba0:  92 10 00 19  mov  %i1, %o1
a0155ba4:  c2 07 bf e8  ld  [ %fp + -24 ], %g1
a0155ba8:  80 a0 60 01  cmp  %g1, 1
a0155bac:  08 80 00 0a  bleu  0xa0155bd4
a0155bb0:  b0 10 3f ff  mov  -1, %i0
a0155bb4:  c2 07 bf d8  ld  [ %fp + -40 ], %g1
a0155bb8:  90 10 00 10  mov  %l0, %o0
a0155bbc:  80 a0 60 01  cmp  %g1, 1
a0155bc0:  08 80 00 05  bleu  0xa0155bd4
a0155bc4:  92 10 00 19  mov  %i1, %o1
a0155bc8:  40 00 05 11  call  0xa015700c
a0155bcc:  01 00 00 00  nop
a0155bd0:  b0 10 00 08  mov  %o0, %i0
a0155bd4:  81 c7 e0 08  ret
a0155bd8:  81 e8 00 00  restore
