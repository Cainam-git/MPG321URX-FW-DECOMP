# leon2s FUN_a00d77c4 0xa00d77c4-0xa00d7828 (100 bytes)
a00d77c4:  c2 0a 00 00  ldub  [ %o0 ], %g1
a00d77c8:  82 08 60 7f  and  %g1, 0x7f, %g1
a00d77cc:  c2 2a 40 00  stb  %g1, [ %o1 ]
a00d77d0:  c2 0a 20 01  ldub  [ %o0 + 1 ], %g1
a00d77d4:  82 08 60 0f  and  %g1, 0xf, %g1
a00d77d8:  c2 2a 60 01  stb  %g1, [ %o1 + 1 ]
a00d77dc:  c2 0a 20 02  ldub  [ %o0 + 2 ], %g1
a00d77e0:  c2 2a 60 02  stb  %g1, [ %o1 + 2 ]
a00d77e4:  c2 0a 20 02  ldub  [ %o0 + 2 ], %g1
a00d77e8:  80 a0 60 00  cmp  %g1, 0
a00d77ec:  02 80 00 0d  be  0xa00d7820
a00d77f0:  98 10 20 00  clr  %o4
a00d77f4:  82 0b 20 ff  and  %o4, 0xff, %g1
a00d77f8:  9a 02 00 01  add  %o0, %g1, %o5
a00d77fc:  da 0b 60 03  ldub  [ %o5 + 3 ], %o5
a00d7800:  82 02 40 01  add  %o1, %g1, %g1
a00d7804:  da 28 60 03  stb  %o5, [ %g1 + 3 ]
a00d7808:  98 03 20 01  inc  %o4
a00d780c:  9a 0b 20 ff  and  %o4, 0xff, %o5
a00d7810:  c2 0a 20 02  ldub  [ %o0 + 2 ], %g1
a00d7814:  80 a3 40 01  cmp  %o5, %g1
a00d7818:  0a bf ff f8  bcs  0xa00d77f8
a00d781c:  82 0b 20 ff  and  %o4, 0xff, %g1
a00d7820:  81 c3 e0 08  retl
a00d7824:  01 00 00 00  nop
