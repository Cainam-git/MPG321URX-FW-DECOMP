# leon2s FUN_a00d6df8 0xa00d6df8-0xa00d6e94 (156 bytes)
a00d6df8:  c2 0a 40 00  ldub  [ %o1 ], %g1
a00d6dfc:  83 30 60 04  srl  %g1, 4, %g1
a00d6e00:  82 00 7f ff  add  %g1, -1, %g1
a00d6e04:  9b 30 60 1f  srl  %g1, 0x1f, %o5
a00d6e08:  9a 00 40 0d  add  %g1, %o5, %o5
a00d6e0c:  9b 3b 60 01  sra  %o5, 1, %o5
a00d6e10:  80 88 60 01  btst  1, %g1
a00d6e14:  02 80 00 03  be  0xa00d6e20
a00d6e18:  96 10 00 0d  mov  %o5, %o3
a00d6e1c:  96 03 60 01  add  %o5, 1, %o3
a00d6e20:  96 0a e0 ff  and  %o3, 0xff, %o3
a00d6e24:  96 02 40 0b  add  %o1, %o3, %o3
a00d6e28:  c2 0a e0 03  ldub  [ %o3 + 3 ], %g1
a00d6e2c:  da 02 00 00  ld  [ %o0 ], %o5
a00d6e30:  82 08 60 7f  and  %g1, 0x7f, %g1
a00d6e34:  19 1f c0 00  sethi  %hi(0x7f000000), %o4
a00d6e38:  98 2b 40 0c  andn  %o5, %o4, %o4
a00d6e3c:  83 28 60 18  sll  %g1, 0x18, %g1
a00d6e40:  98 13 00 01  or  %o4, %g1, %o4
a00d6e44:  d8 22 00 00  st  %o4, [ %o0 ]
a00d6e48:  da 0a e0 04  ldub  [ %o3 + 4 ], %o5
a00d6e4c:  9b 33 60 04  srl  %o5, 4, %o5
a00d6e50:  03 00 3c 00  sethi  %hi(0xf00000), %g1
a00d6e54:  9b 2b 60 14  sll  %o5, 0x14, %o5
a00d6e58:  82 2b 00 01  andn  %o4, %g1, %g1
a00d6e5c:  82 10 40 0d  or  %g1, %o5, %g1
a00d6e60:  c2 22 00 00  st  %g1, [ %o0 ]
a00d6e64:  c2 0a e0 04  ldub  [ %o3 + 4 ], %g1
a00d6e68:  da 0a e0 05  ldub  [ %o3 + 5 ], %o5
a00d6e6c:  82 08 60 0f  and  %g1, 0xf, %g1
a00d6e70:  9b 2b 60 08  sll  %o5, 8, %o5
a00d6e74:  83 28 60 10  sll  %g1, 0x10, %g1
a00d6e78:  82 10 40 0d  or  %g1, %o5, %g1
a00d6e7c:  da 0a e0 06  ldub  [ %o3 + 6 ], %o5
a00d6e80:  82 10 40 0d  or  %g1, %o5, %g1
a00d6e84:  c2 22 20 04  st  %g1, [ %o0 + 4 ]
a00d6e88:  c2 0a e0 07  ldub  [ %o3 + 7 ], %g1
a00d6e8c:  81 c3 e0 08  retl
a00d6e90:  c2 2a 20 08  stb  %g1, [ %o0 + 8 ]
