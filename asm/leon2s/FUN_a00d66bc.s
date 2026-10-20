# leon2s FUN_a00d66bc 0xa00d66bc-0xa00d6724 (104 bytes)
a00d66bc:  80 8a 20 ff  btst  0xff, %o0
a00d66c0:  12 80 00 16  bne  0xa00d6718
a00d66c4:  92 0a 60 ff  and  %o1, 0xff, %o1
a00d66c8:  80 a2 60 01  cmp  %o1, 1
a00d66cc:  32 80 00 14  bne,a   0xa00d671c
a00d66d0:  90 10 20 00  clr  %o0
a00d66d4:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a00d66d8:  d6 08 60 32  ldub  [ %g1 + 0x32 ], %o3	! 0xa8078832
a00d66dc:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a00d66e0:  82 10 60 28  or  %g1, 0x28, %g1	! 0xa8078828
a00d66e4:  c2 08 40 0b  ldub  [ %g1 + %o3 ], %g1
a00d66e8:  82 08 60 0f  and  %g1, 0xf, %g1
a00d66ec:  98 00 40 01  add  %g1, %g1, %o4
a00d66f0:  9a 02 c0 0b  add  %o3, %o3, %o5
a00d66f4:  98 03 00 01  add  %o4, %g1, %o4
a00d66f8:  9a 03 40 0b  add  %o5, %o3, %o5
a00d66fc:  9b 2b 60 08  sll  %o5, 8, %o5
a00d6700:  99 2b 20 04  sll  %o4, 4, %o4
a00d6704:  03 2a 01 e5  sethi  %hi(0xa8079400), %g1
a00d6708:  9a 03 40 0c  add  %o5, %o4, %o5
a00d670c:  82 10 62 3d  or  %g1, 0x23d, %g1
a00d6710:  10 80 00 03  b  0xa00d671c
a00d6714:  90 03 40 01  add  %o5, %g1, %o0
a00d6718:  90 10 20 00  clr  %o0
a00d671c:  81 c3 e0 08  retl
a00d6720:  01 00 00 00  nop
