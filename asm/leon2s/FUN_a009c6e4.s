# leon2s FUN_a009c6e4 0xa009c6e4-0xa009c718 (52 bytes)
a009c6e4:  9d e3 bf 98  save  %sp, -104, %sp
a009c6e8:  b0 0e 20 ff  and  %i0, 0xff, %i0
a009c6ec:  03 2a 01 f6  sethi  %hi(0xa807d800), %g1
a009c6f0:  b0 5e 20 34  smul  %i0, 0x34, %i0
a009c6f4:  82 10 63 00  or  %g1, 0x300, %g1
a009c6f8:  d2 00 40 18  ld  [ %g1 + %i0 ], %o1
a009c6fc:  92 02 60 70  add  %o1, 0x70, %o1
a009c700:  40 00 2b 42  call  0xa00a7408
a009c704:  90 10 20 11  mov  0x11, %o0
a009c708:  80 a0 00 08  cmp  %g0, %o0
a009c70c:  b0 40 20 00  addx  %g0, 0, %i0
a009c710:  81 c7 e0 08  ret
a009c714:  81 e8 00 00  restore
