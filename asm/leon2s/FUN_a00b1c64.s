# leon2s FUN_a00b1c64 0xa00b1c64-0xa00b1cb0 (76 bytes)
a00b1c64:  17 27 c4 80  sethi  %hi(0x9f120000), %o3
a00b1c68:  9a 12 e0 48  or  %o3, 0x48, %o5	! 0x9f120048
a00b1c6c:  c2 03 40 00  ld  [ %o5 ], %g1
a00b1c70:  82 10 62 00  or  %g1, 0x200, %g1
a00b1c74:  c2 23 40 00  st  %g1, [ %o5 ]
a00b1c78:  d8 03 40 00  ld  [ %o5 ], %o4
a00b1c7c:  03 00 80 00  sethi  %hi(0x2000000), %g1
a00b1c80:  82 2b 00 01  andn  %o4, %g1, %g1
a00b1c84:  c2 23 40 00  st  %g1, [ %o5 ]
a00b1c88:  9a 12 e0 80  or  %o3, 0x80, %o5
a00b1c8c:  c2 03 40 00  ld  [ %o5 ], %g1
a00b1c90:  82 10 62 00  or  %g1, 0x200, %g1
a00b1c94:  c2 23 40 00  st  %g1, [ %o5 ]
a00b1c98:  96 12 e0 34  or  %o3, 0x34, %o3
a00b1c9c:  c2 02 c0 00  ld  [ %o3 ], %g1
a00b1ca0:  82 10 60 20  or  %g1, 0x20, %g1
a00b1ca4:  c2 22 c0 00  st  %g1, [ %o3 ]
a00b1ca8:  81 c3 e0 08  retl
a00b1cac:  01 00 00 00  nop
