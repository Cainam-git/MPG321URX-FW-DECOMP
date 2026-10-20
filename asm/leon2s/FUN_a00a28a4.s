# leon2s FUN_a00a28a4 0xa00a28a4-0xa00a28d8 (52 bytes)
a00a28a4:  9d e3 bf 98  save  %sp, -104, %sp
a00a28a8:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00a28ac:  03 2a 01 f6  sethi  %hi(0xa807d800), %g1
a00a28b0:  b0 5e 20 34  smul  %i0, 0x34, %i0
a00a28b4:  82 10 63 00  or  %g1, 0x300, %g1
a00a28b8:  d2 00 40 18  ld  [ %g1 + %i0 ], %o1
a00a28bc:  92 02 60 04  add  %o1, 4, %o1
a00a28c0:  40 00 12 d2  call  0xa00a7408
a00a28c4:  90 10 20 11  mov  0x11, %o0
a00a28c8:  80 a0 00 08  cmp  %g0, %o0
a00a28cc:  b0 40 20 00  addx  %g0, 0, %i0
a00a28d0:  81 c7 e0 08  ret
a00a28d4:  81 e8 00 00  restore
