# leon2m FUN_a00d3dbc 0xa00d3dbc-0xa00d3e28 (108 bytes)
a00d3dbc:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00d3dc0:  82 10 62 90  or  %g1, 0x290, %g1	! 0xa802d290
a00d3dc4:  da 00 60 a8  ld  [ %g1 + 0xa8 ], %o5
a00d3dc8:  80 8b 68 00  btst  0x800, %o5
a00d3dcc:  02 80 00 15  be  0xa00d3e20
a00d3dd0:  01 00 00 00  nop
a00d3dd4:  d8 08 61 81  ldub  [ %g1 + 0x181 ], %o4
a00d3dd8:  80 a3 20 07  cmp  %o4, 7
a00d3ddc:  12 80 00 11  bne  0xa00d3e20
a00d3de0:  01 00 00 00  nop
a00d3de4:  da 12 00 00  lduh  [ %o0 ], %o5
a00d3de8:  99 2b 60 03  sll  %o5, 3, %o4
a00d3dec:  82 23 00 0d  sub  %o4, %o5, %g1
a00d3df0:  99 28 60 07  sll  %g1, 7, %o4
a00d3df4:  98 03 00 0d  add  %o4, %o5, %o4
a00d3df8:  03 3f ff 91  sethi  %hi(0xfffe4400), %g1
a00d3dfc:  9a 10 62 82  or  %g1, 0x282, %o5	! 0xfffe4682
a00d3e00:  98 03 00 0d  add  %o4, %o5, %o4
a00d3e04:  03 24 87 d9  sethi  %hi(0x921f6400), %g1
a00d3e08:  9a 10 60 bf  or  %g1, 0xbf, %o5	! 0x921f64bf
a00d3e0c:  80 53 00 0d  umul  %o4, %o5, %g0
a00d3e10:  99 40 00 00  rd  %y, %o4
a00d3e14:  83 33 20 09  srl  %o4, 9, %g1
a00d3e18:  9a 00 60 7e  add  %g1, 0x7e, %o5
a00d3e1c:  da 32 00 00  sth  %o5, [ %o0 ]
a00d3e20:  81 c3 e0 08  retl
a00d3e24:  01 00 00 00  nop
