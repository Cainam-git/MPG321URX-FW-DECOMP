# leon2s FUN_a00d77a8 0xa00d77a8-0xa00d77c4 (28 bytes)
a00d77a8:  c2 0a 00 00  ldub  [ %o0 ], %g1
a00d77ac:  82 08 60 7f  and  %g1, 0x7f, %g1
a00d77b0:  c2 2a 40 00  stb  %g1, [ %o1 ]
a00d77b4:  c2 0a 20 01  ldub  [ %o0 + 1 ], %g1
a00d77b8:  82 08 60 0f  and  %g1, 0xf, %g1
a00d77bc:  81 c3 e0 08  retl
a00d77c0:  c2 2a 60 01  stb  %g1, [ %o1 + 1 ]
