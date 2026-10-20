# leon2s FUN_a00d7744 0xa00d7744-0xa00d77a8 (100 bytes)
a00d7744:  c2 0a 00 00  ldub  [ %o0 ], %g1
a00d7748:  82 08 60 7f  and  %g1, 0x7f, %g1
a00d774c:  c2 2a 40 00  stb  %g1, [ %o1 ]
a00d7750:  c2 0a 20 01  ldub  [ %o0 + 1 ], %g1
a00d7754:  82 08 60 0f  and  %g1, 0xf, %g1
a00d7758:  c2 2a 60 01  stb  %g1, [ %o1 + 1 ]
a00d775c:  c2 0a 20 02  ldub  [ %o0 + 2 ], %g1
a00d7760:  c2 2a 60 02  stb  %g1, [ %o1 + 2 ]
a00d7764:  c2 0a 20 02  ldub  [ %o0 + 2 ], %g1
a00d7768:  80 a0 60 00  cmp  %g1, 0
a00d776c:  02 80 00 0d  be  0xa00d77a0
a00d7770:  98 10 20 00  clr  %o4
a00d7774:  82 0b 20 ff  and  %o4, 0xff, %g1
a00d7778:  9a 02 00 01  add  %o0, %g1, %o5
a00d777c:  da 0b 60 03  ldub  [ %o5 + 3 ], %o5
a00d7780:  82 02 40 01  add  %o1, %g1, %g1
a00d7784:  da 28 60 03  stb  %o5, [ %g1 + 3 ]
a00d7788:  98 03 20 01  inc  %o4
a00d778c:  9a 0b 20 ff  and  %o4, 0xff, %o5
a00d7790:  c2 0a 20 02  ldub  [ %o0 + 2 ], %g1
a00d7794:  80 a3 40 01  cmp  %o5, %g1
a00d7798:  0a bf ff f8  bcs  0xa00d7778
a00d779c:  82 0b 20 ff  and  %o4, 0xff, %g1
a00d77a0:  81 c3 e0 08  retl
a00d77a4:  01 00 00 00  nop
