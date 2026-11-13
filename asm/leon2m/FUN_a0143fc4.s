# leon2m FUN_a0143fc4 0xa0143fc4-0xa0143fe4 (32 bytes)
a0143fc4:  03 2a 00 b6  sethi  %hi(0xa802d800), %g1
a0143fc8:  82 10 61 90  or  %g1, 0x190, %g1	! 0xa802d990
a0143fcc:  da 08 60 01  ldub  [ %g1 + 1 ], %o5
a0143fd0:  19 2a 00 a9  sethi  %hi(0xa802a400), %o4
a0143fd4:  9a 0b 60 7f  and  %o5, 0x7f, %o5
a0143fd8:  d0 2b 20 7d  stb  %o0, [ %o4 + 0x7d ]
a0143fdc:  81 c3 e0 08  retl
a0143fe0:  da 28 60 01  stb  %o5, [ %g1 + 1 ]
