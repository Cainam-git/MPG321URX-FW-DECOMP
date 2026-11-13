# leon2s FUN_a00cc8d4 0xa00cc8d4-0xa00cc900 (44 bytes)
a00cc8d4:  90 0a 20 ff  and  %o0, 0xff, %o0
a00cc8d8:  98 02 00 08  add  %o0, %o0, %o4
a00cc8dc:  98 03 00 08  add  %o4, %o0, %o4
a00cc8e0:  17 2a 01 e2  sethi  %hi(0xa8078800), %o3
a00cc8e4:  96 12 e3 b0  or  %o3, 0x3b0, %o3	! 0xa8078bb0
a00cc8e8:  99 2b 20 03  sll  %o4, 3, %o4
a00cc8ec:  c2 02 c0 0c  ld  [ %o3 + %o4 ], %g1
a00cc8f0:  1b 00 00 c0  sethi  %hi(0x30000), %o5
a00cc8f4:  82 10 40 0d  or  %g1, %o5, %g1
a00cc8f8:  81 c3 e0 08  retl
a00cc8fc:  c2 22 c0 0c  st  %g1, [ %o3 + %o4 ]
