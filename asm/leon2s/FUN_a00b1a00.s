# leon2s FUN_a00b1a00 0xa00b1a00-0xa00b1a4c (76 bytes)
a00b1a00:  17 27 c4 80  sethi  %hi(0x9f120000), %o3
a00b1a04:  9a 12 e0 48  or  %o3, 0x48, %o5	! 0x9f120048
a00b1a08:  c2 03 40 00  ld  [ %o5 ], %g1
a00b1a0c:  82 10 60 40  or  %g1, 0x40, %g1
a00b1a10:  c2 23 40 00  st  %g1, [ %o5 ]
a00b1a14:  d8 03 40 00  ld  [ %o5 ], %o4
a00b1a18:  03 00 10 00  sethi  %hi(0x400000), %g1
a00b1a1c:  82 2b 00 01  andn  %o4, %g1, %g1
a00b1a20:  c2 23 40 00  st  %g1, [ %o5 ]
a00b1a24:  9a 12 e0 80  or  %o3, 0x80, %o5
a00b1a28:  c2 03 40 00  ld  [ %o5 ], %g1
a00b1a2c:  82 10 60 40  or  %g1, 0x40, %g1
a00b1a30:  c2 23 40 00  st  %g1, [ %o5 ]
a00b1a34:  96 12 e0 34  or  %o3, 0x34, %o3
a00b1a38:  c2 02 c0 00  ld  [ %o3 ], %g1
a00b1a3c:  82 10 60 20  or  %g1, 0x20, %g1
a00b1a40:  c2 22 c0 00  st  %g1, [ %o3 ]
a00b1a44:  81 c3 e0 08  retl
a00b1a48:  01 00 00 00  nop
