# leon2s FUN_a00dcc50 0xa00dcc50-0xa00dcc80 (48 bytes)
a00dcc50:  1b 33 c0 45  sethi  %hi(0xcf011400), %o5
a00dcc54:  9a 13 62 dc  or  %o5, 0x2dc, %o5	! 0xcf0116dc
a00dcc58:  c2 03 40 00  ld  [ %o5 ], %g1
a00dcc5c:  82 08 60 3f  and  %g1, 0x3f, %g1
a00dcc60:  c2 23 40 00  st  %g1, [ %o5 ]
a00dcc64:  90 0a 20 ff  and  %o0, 0xff, %o0
a00dcc68:  c2 03 40 00  ld  [ %o5 ], %g1
a00dcc6c:  91 2a 20 06  sll  %o0, 6, %o0
a00dcc70:  82 10 40 08  or  %g1, %o0, %g1
a00dcc74:  c2 23 40 00  st  %g1, [ %o5 ]
a00dcc78:  81 c3 e0 08  retl
a00dcc7c:  01 00 00 00  nop
