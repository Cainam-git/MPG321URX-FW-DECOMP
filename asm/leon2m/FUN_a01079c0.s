# leon2m FUN_a01079c0 0xa01079c0-0xa01079f4 (52 bytes)
a01079c0:  d8 0a 00 00  ldub  [ %o0 ], %o4
a01079c4:  03 2a 00 9e  sethi  %hi(0xa8027800), %g1
a01079c8:  d8 28 62 82  stb  %o4, [ %g1 + 0x282 ]	! 0xa8027a82
a01079cc:  da 0a 20 01  ldub  [ %o0 + 1 ], %o5
a01079d0:  82 10 62 82  or  %g1, 0x282, %g1
a01079d4:  da 28 60 01  stb  %o5, [ %g1 + 1 ]
a01079d8:  d8 0a 20 02  ldub  [ %o0 + 2 ], %o4
a01079dc:  d8 28 60 02  stb  %o4, [ %g1 + 2 ]
a01079e0:  da 0a 20 03  ldub  [ %o0 + 3 ], %o5
a01079e4:  da 28 60 03  stb  %o5, [ %g1 + 3 ]
a01079e8:  d8 0a 20 04  ldub  [ %o0 + 4 ], %o4
a01079ec:  81 c3 e0 08  retl
a01079f0:  d8 28 60 04  stb  %o4, [ %g1 + 4 ]
