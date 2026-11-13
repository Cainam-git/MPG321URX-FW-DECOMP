# leon2m FUN_a0102f6c 0xa0102f6c-0xa0102fd0 (100 bytes)
a0102f6c:  9d e3 bf 98  save  %sp, -104, %sp
a0102f70:  1f 2a 00 b5  sethi  %hi(0xa802d400), %o7
a0102f74:  da 03 e2 a4  ld  [ %o7 + 0x2a4 ], %o5	! 0xa802d6a4
a0102f78:  19 33 33 33  sethi  %hi(0xcccccc00), %o4
a0102f7c:  d4 03 60 34  ld  [ %o5 + 0x34 ], %o2
a0102f80:  96 13 20 cd  or  %o4, 0xcd, %o3
a0102f84:  80 52 80 0b  umul  %o2, %o3, %g0
a0102f88:  93 40 00 00  rd  %y, %o1
a0102f8c:  c2 13 60 22  lduh  [ %o5 + 0x22 ], %g1
a0102f90:  91 32 60 03  srl  %o1, 3, %o0
a0102f94:  b2 5a 00 01  smul  %o0, %g1, %i1
a0102f98:  92 10 00 19  mov  %i1, %o1
a0102f9c:  7f ff fd d3  call  0xa01026e8
a0102fa0:  90 10 20 00  clr  %o0
a0102fa4:  a1 36 60 01  srl  %i1, 1, %l0
a0102fa8:  90 10 20 01  mov  1, %o0
a0102fac:  7f ff fd cf  call  0xa01026e8
a0102fb0:  92 10 00 10  mov  %l0, %o1
a0102fb4:  92 10 00 10  mov  %l0, %o1
a0102fb8:  7f ff fd cc  call  0xa01026e8
a0102fbc:  90 10 20 02  mov  2, %o0
a0102fc0:  b3 36 60 02  srl  %i1, 2, %i1
a0102fc4:  7f ff fd c9  call  0xa01026e8
a0102fc8:  91 e8 20 03  restore  %g0, 3, %o0
a0102fcc:  01 00 00 00  nop
