# leon2m FUN_a0148d98 0xa0148d98-0xa0148e34 (156 bytes)
a0148d98:  03 2a 00 b8  sethi  %hi(0xa802e000), %g1
a0148d9c:  d8 00 61 a0  ld  [ %g1 + 0x1a0 ], %o4	! 0xa802e1a0
a0148da0:  1b 02 00 00  sethi  %hi(0x8000000), %o5
a0148da4:  15 2a 00 b8  sethi  %hi(0xa802e000), %o2
a0148da8:  80 8b 00 0d  btst  %o4, %o5
a0148dac:  02 80 00 11  be  0xa0148df0
a0148db0:  91 2a 20 1f  sll  %o0, 0x1f, %o0
a0148db4:  d6 02 a3 d0  ld  [ %o2 + 0x3d0 ], %o3
a0148db8:  11 20 00 00  sethi  %hi(0x80000000), %o0
a0148dbc:  82 2a c0 08  andn  %o3, %o0, %g1
a0148dc0:  19 2a 00 b7  sethi  %hi(0xa802dc00), %o4
a0148dc4:  c2 22 a3 d0  st  %g1, [ %o2 + 0x3d0 ]
a0148dc8:  96 13 23 30  or  %o4, 0x330, %o3
a0148dcc:  d0 02 a3 d0  ld  [ %o2 + 0x3d0 ], %o0
a0148dd0:  80 a2 20 00  cmp  %o0, 0
a0148dd4:  16 80 00 12  bge  0xa0148e1c
a0148dd8:  98 10 00 0b  mov  %o3, %o4
a0148ddc:  da 02 e0 70  ld  [ %o3 + 0x70 ], %o5
a0148de0:  03 00 20 00  sethi  %hi(0x800000), %g1
a0148de4:  94 2b 40 01  andn  %o5, %g1, %o2
a0148de8:  10 80 00 11  b  0xa0148e2c
a0148dec:  d4 22 e0 70  st  %o2, [ %o3 + 0x70 ]
a0148df0:  da 02 a3 d0  ld  [ %o2 + 0x3d0 ], %o5
a0148df4:  03 20 00 00  sethi  %hi(0x80000000), %g1
a0148df8:  98 2b 40 01  andn  %o5, %g1, %o4
a0148dfc:  82 13 00 08  or  %o4, %o0, %g1
a0148e00:  19 2a 00 b7  sethi  %hi(0xa802dc00), %o4
a0148e04:  c2 22 a3 d0  st  %g1, [ %o2 + 0x3d0 ]
a0148e08:  96 13 23 30  or  %o4, 0x330, %o3
a0148e0c:  d0 02 a3 d0  ld  [ %o2 + 0x3d0 ], %o0
a0148e10:  80 a2 20 00  cmp  %o0, 0
a0148e14:  06 bf ff f2  bl  0xa0148ddc
a0148e18:  98 10 00 0b  mov  %o3, %o4
a0148e1c:  d0 02 e0 70  ld  [ %o3 + 0x70 ], %o0
a0148e20:  15 00 20 00  sethi  %hi(0x800000), %o2
a0148e24:  96 12 00 0a  or  %o0, %o2, %o3
a0148e28:  d6 23 20 70  st  %o3, [ %o4 + 0x70 ]
a0148e2c:  81 c3 e0 08  retl
a0148e30:  01 00 00 00  nop
