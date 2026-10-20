# leon2m FUN_a00fce0c 0xa00fce0c-0xa00fce40 (52 bytes)
a00fce0c:  03 2a 00 b2  sethi  %hi(0xa802c800), %g1
a00fce10:  d8 08 61 68  ldub  [ %g1 + 0x168 ], %o4	! 0xa802c968
a00fce14:  d8 2a 00 00  stb  %o4, [ %o0 ]
a00fce18:  82 10 61 68  or  %g1, 0x168, %g1
a00fce1c:  da 08 60 01  ldub  [ %g1 + 1 ], %o5
a00fce20:  da 2a 20 01  stb  %o5, [ %o0 + 1 ]
a00fce24:  d8 08 60 02  ldub  [ %g1 + 2 ], %o4
a00fce28:  d8 2a 20 02  stb  %o4, [ %o0 + 2 ]
a00fce2c:  da 08 60 03  ldub  [ %g1 + 3 ], %o5
a00fce30:  da 2a 20 03  stb  %o5, [ %o0 + 3 ]
a00fce34:  d8 08 60 04  ldub  [ %g1 + 4 ], %o4
a00fce38:  81 c3 e0 08  retl
a00fce3c:  d8 2a 20 04  stb  %o4, [ %o0 + 4 ]
