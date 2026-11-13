# leon2m FUN_a00badc0 0xa00badc0-0xa00badf8 (56 bytes)
a00badc0:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00badc4:  9a 13 22 90  or  %o4, 0x290, %o5	! 0xa802d290
a00badc8:  d8 0b 60 14  ldub  [ %o5 + 0x14 ], %o4
a00badcc:  d6 0b 60 12  ldub  [ %o5 + 0x12 ], %o3
a00badd0:  d4 0b 60 13  ldub  [ %o5 + 0x13 ], %o2
a00badd4:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00badd8:  9a 10 60 78  or  %g1, 0x78, %o5	! 0xa802d078
a00baddc:  96 02 e0 30  add  %o3, 0x30, %o3
a00bade0:  94 02 a0 30  add  %o2, 0x30, %o2
a00bade4:  98 03 20 30  add  %o4, 0x30, %o4
a00bade8:  d8 2b 60 09  stb  %o4, [ %o5 + 9 ]
a00badec:  d6 2b 60 07  stb  %o3, [ %o5 + 7 ]
a00badf0:  81 c3 e0 08  retl
a00badf4:  d4 2b 60 08  stb  %o2, [ %o5 + 8 ]
