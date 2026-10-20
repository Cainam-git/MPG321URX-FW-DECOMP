# leon2s FUN_a00ab884 0xa00ab884-0xa00ab8b8 (52 bytes)
a00ab884:  90 0a 20 ff  and  %o0, 0xff, %o0
a00ab888:  82 10 20 01  mov  1, %g1
a00ab88c:  80 8a 60 ff  btst  0xff, %o1
a00ab890:  97 28 40 08  sll  %g1, %o0, %o3
a00ab894:  02 80 00 05  be  0xa00ab8a8
a00ab898:  1b 2a 01 e4  sethi  %hi(0xa8079000), %o5
a00ab89c:  c2 0b 63 14  ldub  [ %o5 + 0x314 ], %g1	! 0xa8079314
a00ab8a0:  10 80 00 04  b  0xa00ab8b0
a00ab8a4:  82 12 c0 01  or  %o3, %g1, %g1
a00ab8a8:  c2 0b 63 14  ldub  [ %o5 + 0x314 ], %g1
a00ab8ac:  82 28 40 0b  andn  %g1, %o3, %g1
a00ab8b0:  81 c3 e0 08  retl
a00ab8b4:  c2 2b 63 14  stb  %g1, [ %o5 + 0x314 ]
