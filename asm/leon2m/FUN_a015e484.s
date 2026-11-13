# leon2m FUN_a015e484 0xa015e484-0xa015e4c4 (64 bytes)
a015e484:  9d e3 bf 98  save  %sp, -104, %sp
a015e488:  21 2a 00 b9  sethi  %hi(0xa802e400), %l0
a015e48c:  c0 24 20 0c  clr  [ %l0 + 0xc ]	! 0xa802e40c
a015e490:  90 10 00 19  mov  %i1, %o0
a015e494:  92 10 00 1a  mov  %i2, %o1
a015e498:  40 00 00 e0  call  0xa015e818
a015e49c:  94 10 00 1b  mov  %i3, %o2
a015e4a0:  80 a2 3f ff  cmp  %o0, -1
a015e4a4:  12 80 00 06  bne  0xa015e4bc
a015e4a8:  c2 04 20 0c  ld  [ %l0 + 0xc ], %g1
a015e4ac:  80 a0 60 00  cmp  %g1, 0
a015e4b0:  02 80 00 03  be  0xa015e4bc
a015e4b4:  01 00 00 00  nop
a015e4b8:  c2 26 00 00  st  %g1, [ %i0 ]
a015e4bc:  81 c7 e0 08  ret
a015e4c0:  91 e8 00 08  restore  %g0, %o0, %o0
