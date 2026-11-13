# leon2m FUN_a015e224 0xa015e224-0xa015e25c (56 bytes)
a015e224:  9d e3 bf 98  save  %sp, -104, %sp
a015e228:  21 2a 00 b9  sethi  %hi(0xa802e400), %l0
a015e22c:  c0 24 20 0c  clr  [ %l0 + 0xc ]	! 0xa802e40c
a015e230:  40 00 01 6a  call  0xa015e7d8
a015e234:  90 10 00 19  mov  %i1, %o0
a015e238:  80 a2 3f ff  cmp  %o0, -1
a015e23c:  12 80 00 06  bne  0xa015e254
a015e240:  c2 04 20 0c  ld  [ %l0 + 0xc ], %g1
a015e244:  80 a0 60 00  cmp  %g1, 0
a015e248:  02 80 00 03  be  0xa015e254
a015e24c:  01 00 00 00  nop
a015e250:  c2 26 00 00  st  %g1, [ %i0 ]
a015e254:  81 c7 e0 08  ret
a015e258:  91 e8 00 08  restore  %g0, %o0, %o0
