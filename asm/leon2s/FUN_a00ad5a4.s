# leon2s FUN_a00ad5a4 0xa00ad5a4-0xa00ad5cc (40 bytes)
a00ad5a4:  90 0a 20 ff  and  %o0, 0xff, %o0
a00ad5a8:  80 a2 20 01  cmp  %o0, 1
a00ad5ac:  18 80 00 06  bgu  0xa00ad5c4
a00ad5b0:  82 10 20 00  clr  %g1
a00ad5b4:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a00ad5b8:  c2 08 63 12  ldub  [ %g1 + 0x312 ], %g1	! 0xa8079312
a00ad5bc:  83 38 40 08  sra  %g1, %o0, %g1
a00ad5c0:  82 08 60 01  and  %g1, 1, %g1
a00ad5c4:  81 c3 e0 08  retl
a00ad5c8:  90 10 00 01  mov  %g1, %o0
