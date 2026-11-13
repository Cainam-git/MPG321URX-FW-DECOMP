# leon2m FUN_a015e9a4 0xa015e9a4-0xa015e9d8 (52 bytes)
a015e9a4:  9d e3 bf 98  save  %sp, -104, %sp
a015e9a8:  03 2a 00 b3  sethi  %hi(0xa802cc00), %g1
a015e9ac:  c2 00 63 f0  ld  [ %g1 + 0x3f0 ], %g1	! 0xa802cff0
a015e9b0:  90 10 00 18  mov  %i0, %o0
a015e9b4:  92 10 00 19  mov  %i1, %o1
a015e9b8:  80 a0 60 00  cmp  %g1, 0
a015e9bc:  02 80 00 05  be  0xa015e9d0
a015e9c0:  b0 10 20 00  clr  %i0
a015e9c4:  9f c0 40 00  call  %g1
a015e9c8:  01 00 00 00  nop
a015e9cc:  b0 10 00 08  mov  %o0, %i0
a015e9d0:  81 c7 e0 08  ret
a015e9d4:  81 e8 00 00  restore
