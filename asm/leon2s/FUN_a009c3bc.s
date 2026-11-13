# leon2s FUN_a009c3bc 0xa009c3bc-0xa009c3f0 (52 bytes)
a009c3bc:  9d e3 bf 98  save  %sp, -104, %sp
a009c3c0:  b0 0e 20 ff  and  %i0, 0xff, %i0
a009c3c4:  03 2a 01 f6  sethi  %hi(0xa807d800), %g1
a009c3c8:  b0 5e 20 34  smul  %i0, 0x34, %i0
a009c3cc:  82 10 63 00  or  %g1, 0x300, %g1
a009c3d0:  d2 00 40 18  ld  [ %g1 + %i0 ], %o1
a009c3d4:  92 02 60 54  add  %o1, 0x54, %o1
a009c3d8:  40 00 2c 0c  call  0xa00a7408
a009c3dc:  90 10 20 0a  mov  0xa, %o0
a009c3e0:  80 a0 00 08  cmp  %g0, %o0
a009c3e4:  b0 40 20 00  addx  %g0, 0, %i0
a009c3e8:  81 c7 e0 08  ret
a009c3ec:  81 e8 00 00  restore
