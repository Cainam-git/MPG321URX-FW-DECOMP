# leon2s FUN_a00b1b98 0xa00b1b98-0xa00b1be4 (76 bytes)
a00b1b98:  17 27 c4 80  sethi  %hi(0x9f120000), %o3
a00b1b9c:  9a 12 e0 48  or  %o3, 0x48, %o5	! 0x9f120048
a00b1ba0:  c2 03 40 00  ld  [ %o5 ], %g1
a00b1ba4:  82 10 61 00  or  %g1, 0x100, %g1
a00b1ba8:  c2 23 40 00  st  %g1, [ %o5 ]
a00b1bac:  d8 03 40 00  ld  [ %o5 ], %o4
a00b1bb0:  03 00 40 00  sethi  %hi(0x1000000), %g1
a00b1bb4:  82 2b 00 01  andn  %o4, %g1, %g1
a00b1bb8:  c2 23 40 00  st  %g1, [ %o5 ]
a00b1bbc:  9a 12 e0 80  or  %o3, 0x80, %o5
a00b1bc0:  c2 03 40 00  ld  [ %o5 ], %g1
a00b1bc4:  82 10 61 00  or  %g1, 0x100, %g1
a00b1bc8:  c2 23 40 00  st  %g1, [ %o5 ]
a00b1bcc:  96 12 e0 34  or  %o3, 0x34, %o3
a00b1bd0:  c2 02 c0 00  ld  [ %o3 ], %g1
a00b1bd4:  82 10 60 20  or  %g1, 0x20, %g1
a00b1bd8:  c2 22 c0 00  st  %g1, [ %o3 ]
a00b1bdc:  81 c3 e0 08  retl
a00b1be0:  01 00 00 00  nop
