# leon2m FUN_a013cfc4 0xa013cfc4-0xa013d008 (68 bytes)
a013cfc4:  13 3f 7f ff  sethi  %hi(0xfdfffc00), %o1
a013cfc8:  03 2a 00 b7  sethi  %hi(0xa802dc00), %g1
a013cfcc:  82 10 63 30  or  %g1, 0x330, %g1	! 0xa802df30
a013cfd0:  98 12 63 ff  or  %o1, 0x3ff, %o4
a013cfd4:  d6 00 60 70  ld  [ %g1 + 0x70 ], %o3
a013cfd8:  d4 00 60 e8  ld  [ %g1 + 0xe8 ], %o2
a013cfdc:  d2 00 61 60  ld  [ %g1 + 0x160 ], %o1
a013cfe0:  da 00 61 d8  ld  [ %g1 + 0x1d8 ], %o5
a013cfe4:  9a 0b 40 0c  and  %o5, %o4, %o5
a013cfe8:  96 0a c0 0c  and  %o3, %o4, %o3
a013cfec:  94 0a 80 0c  and  %o2, %o4, %o2
a013cff0:  92 0a 40 0c  and  %o1, %o4, %o1
a013cff4:  da 20 61 d8  st  %o5, [ %g1 + 0x1d8 ]
a013cff8:  d6 20 60 70  st  %o3, [ %g1 + 0x70 ]
a013cffc:  d4 20 60 e8  st  %o2, [ %g1 + 0xe8 ]
a013d000:  81 c3 e0 08  retl
a013d004:  d2 20 61 60  st  %o1, [ %g1 + 0x160 ]
