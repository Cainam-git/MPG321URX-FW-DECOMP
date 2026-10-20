# leon2s FUN_a0097ed0 0xa0097ed0-0xa0097f04 (52 bytes)
a0097ed0:  9d e3 bf 98  save  %sp, -104, %sp
a0097ed4:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0097ed8:  03 2a 01 f6  sethi  %hi(0xa807d800), %g1
a0097edc:  b0 5e 20 34  smul  %i0, 0x34, %i0
a0097ee0:  82 10 63 00  or  %g1, 0x300, %g1
a0097ee4:  d2 00 40 18  ld  [ %g1 + %i0 ], %o1
a0097ee8:  92 02 60 30  add  %o1, 0x30, %o1
a0097eec:  40 00 3d 47  call  0xa00a7408
a0097ef0:  90 10 20 04  mov  4, %o0
a0097ef4:  80 a0 00 08  cmp  %g0, %o0
a0097ef8:  b0 40 20 00  addx  %g0, 0, %i0
a0097efc:  81 c7 e0 08  ret
a0097f00:  81 e8 00 00  restore
