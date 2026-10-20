# leon2s FUN_a00a0bfc 0xa00a0bfc-0xa00a0c84 (136 bytes)
a00a0bfc:  90 0a 20 ff  and  %o0, 0xff, %o0
a00a0c00:  03 2a 01 f6  sethi  %hi(0xa807d800), %g1
a00a0c04:  82 10 63 00  or  %g1, 0x300, %g1	! 0xa807db00
a00a0c08:  90 5a 20 34  smul  %o0, 0x34, %o0
a00a0c0c:  d8 00 40 08  ld  [ %g1 + %o0 ], %o4
a00a0c10:  c2 03 20 70  ld  [ %o4 + 0x70 ], %g1
a00a0c14:  82 08 60 ff  and  %g1, 0xff, %g1
a00a0c18:  82 10 7c 00  or  %g1, -1024, %g1
a00a0c1c:  c2 23 20 70  st  %g1, [ %o4 + 0x70 ]
a00a0c20:  c2 03 20 74  ld  [ %o4 + 0x74 ], %g1
a00a0c24:  82 10 60 ff  or  %g1, 0xff, %g1
a00a0c28:  c2 23 20 74  st  %g1, [ %o4 + 0x74 ]
a00a0c2c:  1b 00 3f ff  sethi  %hi(0xfffc00), %o5
a00a0c30:  c2 03 20 78  ld  [ %o4 + 0x78 ], %g1
a00a0c34:  9a 13 63 ff  or  %o5, 0x3ff, %o5
a00a0c38:  82 08 40 0d  and  %g1, %o5, %g1
a00a0c3c:  17 3f c0 00  sethi  %hi(0xff000000), %o3
a00a0c40:  82 10 40 0b  or  %g1, %o3, %g1
a00a0c44:  c2 23 20 78  st  %g1, [ %o4 + 0x78 ]
a00a0c48:  c2 03 20 7c  ld  [ %o4 + 0x7c ], %g1
a00a0c4c:  82 10 60 ff  or  %g1, 0xff, %g1
a00a0c50:  c2 23 20 7c  st  %g1, [ %o4 + 0x7c ]
a00a0c54:  c2 03 20 80  ld  [ %o4 + 0x80 ], %g1
a00a0c58:  82 08 40 0d  and  %g1, %o5, %g1
a00a0c5c:  82 10 40 0b  or  %g1, %o3, %g1
a00a0c60:  c2 23 20 80  st  %g1, [ %o4 + 0x80 ]
a00a0c64:  03 3f c0 3f  sethi  %hi(0xff00fc00), %g1
a00a0c68:  da 03 20 90  ld  [ %o4 + 0x90 ], %o5
a00a0c6c:  82 10 63 00  or  %g1, 0x300, %g1
a00a0c70:  9a 0b 40 01  and  %o5, %g1, %o5
a00a0c74:  9a 13 60 ff  or  %o5, 0xff, %o5
a00a0c78:  da 23 20 90  st  %o5, [ %o4 + 0x90 ]
a00a0c7c:  81 c3 e0 08  retl
a00a0c80:  01 00 00 00  nop
