# leon2m FUN_a00f3a04 0xa00f3a04-0xa00f3a30 (44 bytes)
a00f3a04:  da 02 00 00  ld  [ %o0 ], %o5
a00f3a08:  19 2a 00 ad  sethi  %hi(0xa802b400), %o4
a00f3a0c:  da 23 23 9c  st  %o5, [ %o4 + 0x39c ]	! 0xa802b79c
a00f3a10:  c2 02 20 04  ld  [ %o0 + 4 ], %g1
a00f3a14:  98 13 23 9c  or  %o4, 0x39c, %o4
a00f3a18:  c2 23 20 04  st  %g1, [ %o4 + 4 ]
a00f3a1c:  da 02 20 08  ld  [ %o0 + 8 ], %o5
a00f3a20:  da 23 20 08  st  %o5, [ %o4 + 8 ]
a00f3a24:  c2 02 20 0c  ld  [ %o0 + 0xc ], %g1
a00f3a28:  81 c3 e0 08  retl
a00f3a2c:  c2 23 20 0c  st  %g1, [ %o4 + 0xc ]
