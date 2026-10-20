# leon2m FUN_a0155bdc 0xa0155bdc-0xa0155c40 (100 bytes)
a0155bdc:  9d e3 bf 70  save  %sp, -144, %sp
a0155be0:  a0 07 bf e8  add  %fp, -24, %l0
a0155be4:  f0 27 bf d4  st  %i0, [ %fp + -44 ]
a0155be8:  f2 27 bf d0  st  %i1, [ %fp + -48 ]
a0155bec:  90 07 bf d4  add  %fp, -44, %o0
a0155bf0:  40 00 04 d1  call  0xa0156f34
a0155bf4:  92 10 00 10  mov  %l0, %o1
a0155bf8:  b2 07 bf d8  add  %fp, -40, %i1
a0155bfc:  90 07 bf d0  add  %fp, -48, %o0
a0155c00:  40 00 04 cd  call  0xa0156f34
a0155c04:  92 10 00 19  mov  %i1, %o1
a0155c08:  c2 07 bf e8  ld  [ %fp + -24 ], %g1
a0155c0c:  80 a0 60 01  cmp  %g1, 1
a0155c10:  08 80 00 0a  bleu  0xa0155c38
a0155c14:  b0 10 3f ff  mov  -1, %i0
a0155c18:  c2 07 bf d8  ld  [ %fp + -40 ], %g1
a0155c1c:  90 10 00 10  mov  %l0, %o0
a0155c20:  80 a0 60 01  cmp  %g1, 1
a0155c24:  08 80 00 05  bleu  0xa0155c38
a0155c28:  92 10 00 19  mov  %i1, %o1
a0155c2c:  40 00 04 f8  call  0xa015700c
a0155c30:  01 00 00 00  nop
a0155c34:  b0 10 00 08  mov  %o0, %i0
a0155c38:  81 c7 e0 08  ret
a0155c3c:  81 e8 00 00  restore
