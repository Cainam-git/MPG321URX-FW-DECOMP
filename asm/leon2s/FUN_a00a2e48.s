# leon2s FUN_a00a2e48 0xa00a2e48-0xa00a2ecc (132 bytes)
a00a2e48:  90 0a 20 ff  and  %o0, 0xff, %o0
a00a2e4c:  03 2a 01 f6  sethi  %hi(0xa807d800), %g1
a00a2e50:  90 5a 20 34  smul  %o0, 0x34, %o0
a00a2e54:  82 10 63 00  or  %g1, 0x300, %g1
a00a2e58:  d8 00 40 08  ld  [ %g1 + %o0 ], %o4
a00a2e5c:  c2 03 20 74  ld  [ %o4 + 0x74 ], %g1
a00a2e60:  82 08 60 ff  and  %g1, 0xff, %g1
a00a2e64:  c2 23 20 74  st  %g1, [ %o4 + 0x74 ]
a00a2e68:  c2 03 20 78  ld  [ %o4 + 0x78 ], %g1
a00a2e6c:  82 08 7f 00  and  %g1, -256, %g1
a00a2e70:  c2 23 20 78  st  %g1, [ %o4 + 0x78 ]
a00a2e74:  c2 03 20 7c  ld  [ %o4 + 0x7c ], %g1
a00a2e78:  82 08 60 ff  and  %g1, 0xff, %g1
a00a2e7c:  c2 23 20 7c  st  %g1, [ %o4 + 0x7c ]
a00a2e80:  17 00 3f c0  sethi  %hi(0xff0000), %o3
a00a2e84:  c2 03 20 90  ld  [ %o4 + 0x90 ], %g1
a00a2e88:  96 12 e0 ff  or  %o3, 0xff, %o3
a00a2e8c:  82 08 40 0b  and  %g1, %o3, %g1
a00a2e90:  c2 23 20 90  st  %g1, [ %o4 + 0x90 ]
a00a2e94:  c2 03 20 ac  ld  [ %o4 + 0xac ], %g1
a00a2e98:  1b 3f c0 00  sethi  %hi(0xff000000), %o5
a00a2e9c:  82 08 40 0d  and  %g1, %o5, %g1
a00a2ea0:  c2 23 20 ac  st  %g1, [ %o4 + 0xac ]
a00a2ea4:  c2 03 20 c4  ld  [ %o4 + 0xc4 ], %g1
a00a2ea8:  82 08 40 0b  and  %g1, %o3, %g1
a00a2eac:  c2 23 20 c4  st  %g1, [ %o4 + 0xc4 ]
a00a2eb0:  03 3f ff c0  sethi  %hi(0xffff0000), %g1
a00a2eb4:  da 03 20 c8  ld  [ %o4 + 0xc8 ], %o5
a00a2eb8:  82 10 60 ff  or  %g1, 0xff, %g1
a00a2ebc:  9a 0b 40 01  and  %o5, %g1, %o5
a00a2ec0:  da 23 20 c8  st  %o5, [ %o4 + 0xc8 ]
a00a2ec4:  81 c3 e0 08  retl
a00a2ec8:  90 10 20 00  clr  %o0
