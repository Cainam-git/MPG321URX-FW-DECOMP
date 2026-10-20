# leon2m FUN_a0145c5c 0xa0145c5c-0xa0145eb8 (40 bytes)
a0145c5c:  80 a2 20 11  cmp  %o0, 0x11
a0145c60:  18 80 00 94  bgu  0xa0145eb0
a0145c64:  83 2a 20 02  sll  %o0, 2, %g1
a0145c68:  11 00 03 8c  sethi  %hi(0xe3000), %o0
a0145c6c:  9a 12 22 80  or  %o0, 0x280, %o5	! 0xe3280
a0145c70:  d8 03 40 01  ld  [ %o5 + %g1 ], %o4
a0145c74:  81 c3 00 00  jmp  %o4
a0145c78:  01 00 00 00  nop
a0145c7c:  17 2a 00 b8  sethi  %hi(0xa802e000), %o3
a0145c80:  90 12 e1 a0  or  %o3, 0x1a0, %o0	! 0xa802e1a0
a0145c84:  d4 02 20 18  ld  [ %o0 + 0x18 ], %o2
a0145c88:  03 3f c0 00  sethi  %hi(0xff000000), %g1
a0145c8c:  9b 2a 60 10  sll  %o1, 0x10, %o5
a0145c90:  82 2a 80 01  andn  %o2, %g1, %g1
a0145c94:  d2 02 20 14  ld  [ %o0 + 0x14 ], %o1
a0145c98:  95 2b 60 08  sll  %o5, 8, %o2
a0145c9c:  98 0a 7f 00  and  %o1, -256, %o4
a0145ca0:  9b 33 60 18  srl  %o5, 0x18, %o5
a0145ca4:  98 13 00 0d  or  %o4, %o5, %o4
a0145ca8:  92 10 40 0a  or  %g1, %o2, %o1
a0145cac:  d2 22 20 18  st  %o1, [ %o0 + 0x18 ]
a0145cb0:  10 80 00 80  b  0xa0145eb0
a0145cb4:  d8 22 20 14  st  %o4, [ %o0 + 0x14 ]
a0145cb8:  11 2a 00 b8  sethi  %hi(0xa802e000), %o0
a0145cbc:  98 12 21 a0  or  %o0, 0x1a0, %o4	! 0xa802e1a0
a0145cc0:  94 0a 60 01  and  %o1, 1, %o2
a0145cc4:  d6 03 20 18  ld  [ %o4 + 0x18 ], %o3
a0145cc8:  03 00 10 00  sethi  %hi(0x400000), %g1
a0145ccc:  82 2a c0 01  andn  %o3, %g1, %g1
a0145cd0:  9b 2a a0 16  sll  %o2, 0x16, %o5
a0145cd4:  92 10 40 0d  or  %g1, %o5, %o1
a0145cd8:  10 80 00 76  b  0xa0145eb0
a0145cdc:  d2 23 20 18  st  %o1, [ %o4 + 0x18 ]
a0145ce0:  19 2a 00 b8  sethi  %hi(0xa802e000), %o4
a0145ce4:  98 13 21 a0  or  %o4, 0x1a0, %o4	! 0xa802e1a0
a0145ce8:  90 0a 60 01  and  %o1, 1, %o0
a0145cec:  d2 03 20 18  ld  [ %o4 + 0x18 ], %o1
a0145cf0:  1b 00 20 00  sethi  %hi(0x800000), %o5
a0145cf4:  82 2a 40 0d  andn  %o1, %o5, %g1
a0145cf8:  9b 2a 20 17  sll  %o0, 0x17, %o5
a0145cfc:  92 10 40 0d  or  %g1, %o5, %o1
a0145d00:  10 80 00 6c  b  0xa0145eb0
a0145d04:  d2 23 20 18  st  %o1, [ %o4 + 0x18 ]
a0145d08:  17 2a 00 b8  sethi  %hi(0xa802e000), %o3
a0145d0c:  90 12 e1 a0  or  %o3, 0x1a0, %o0	! 0xa802e1a0
a0145d10:  95 2a 60 10  sll  %o1, 0x10, %o2
a0145d14:  1b 3f c0 00  sethi  %hi(0xff000000), %o5
a0145d18:  d2 02 20 14  ld  [ %o0 + 0x14 ], %o1
a0145d1c:  82 13 60 ff  or  %o5, 0xff, %g1
a0145d20:  9a 0a 40 01  and  %o1, %g1, %o5
a0145d24:  99 32 a0 08  srl  %o2, 8, %o4
a0145d28:  92 13 40 0c  or  %o5, %o4, %o1
a0145d2c:  10 80 00 61  b  0xa0145eb0
a0145d30:  d2 22 20 14  st  %o1, [ %o0 + 0x14 ]
a0145d34:  17 2a 00 b8  sethi  %hi(0xa802e000), %o3
a0145d38:  90 12 e1 a0  or  %o3, 0x1a0, %o0	! 0xa802e1a0
a0145d3c:  9b 2a 60 10  sll  %o1, 0x10, %o5
a0145d40:  d4 02 20 14  ld  [ %o0 + 0x14 ], %o2
a0145d44:  03 3f c0 00  sethi  %hi(0xff000000), %g1
a0145d48:  92 2a 80 01  andn  %o2, %g1, %o1
a0145d4c:  d8 02 20 10  ld  [ %o0 + 0x10 ], %o4
a0145d50:  95 2b 60 08  sll  %o5, 8, %o2
a0145d54:  98 0b 3f 00  and  %o4, -256, %o4
a0145d58:  9b 33 60 18  srl  %o5, 0x18, %o5
a0145d5c:  98 13 00 0d  or  %o4, %o5, %o4
a0145d60:  82 12 40 0a  or  %o1, %o2, %g1
a0145d64:  c2 22 20 14  st  %g1, [ %o0 + 0x14 ]
a0145d68:  10 80 00 52  b  0xa0145eb0
a0145d6c:  d8 22 20 10  st  %o4, [ %o0 + 0x10 ]
a0145d70:  17 2a 00 b8  sethi  %hi(0xa802e000), %o3
a0145d74:  90 12 e1 a0  or  %o3, 0x1a0, %o0	! 0xa802e1a0
a0145d78:  95 2a 60 10  sll  %o1, 0x10, %o2
a0145d7c:  1b 3f c0 00  sethi  %hi(0xff000000), %o5
a0145d80:  d8 02 20 10  ld  [ %o0 + 0x10 ], %o4
a0145d84:  92 13 60 ff  or  %o5, 0xff, %o1
a0145d88:  9a 0b 00 09  and  %o4, %o1, %o5
a0145d8c:  83 32 a0 08  srl  %o2, 8, %g1
a0145d90:  92 13 40 01  or  %o5, %g1, %o1
a0145d94:  10 80 00 47  b  0xa0145eb0
a0145d98:  d2 22 20 10  st  %o1, [ %o0 + 0x10 ]
a0145d9c:  19 2a 00 b8  sethi  %hi(0xa802e000), %o4
a0145da0:  10 80 00 44  b  0xa0145eb0
a0145da4:  d2 2b 21 b0  stb  %o1, [ %o4 + 0x1b0 ]	! 0xa802e1b0
a0145da8:  15 2a 00 b8  sethi  %hi(0xa802e000), %o2
a0145dac:  10 80 00 41  b  0xa0145eb0
a0145db0:  d2 2a a1 af  stb  %o1, [ %o2 + 0x1af ]	! 0xa802e1af
a0145db4:  17 2a 00 b8  sethi  %hi(0xa802e000), %o3
a0145db8:  94 12 e1 a0  or  %o3, 0x1a0, %o2	! 0xa802e1a0
a0145dbc:  91 2a 60 10  sll  %o1, 0x10, %o0
a0145dc0:  1b 3f c0 00  sethi  %hi(0xff000000), %o5
a0145dc4:  d2 02 a0 0c  ld  [ %o2 + 0xc ], %o1
a0145dc8:  82 13 60 ff  or  %o5, 0xff, %g1
a0145dcc:  9a 0a 40 01  and  %o1, %g1, %o5
a0145dd0:  99 32 20 08  srl  %o0, 8, %o4
a0145dd4:  92 13 40 0c  or  %o5, %o4, %o1
a0145dd8:  10 80 00 36  b  0xa0145eb0
a0145ddc:  d2 22 a0 0c  st  %o1, [ %o2 + 0xc ]
a0145de0:  11 2a 00 b8  sethi  %hi(0xa802e000), %o0
a0145de4:  10 80 00 33  b  0xa0145eb0
a0145de8:  d2 2a 21 ac  stb  %o1, [ %o0 + 0x1ac ]	! 0xa802e1ac
a0145dec:  17 2a 00 b8  sethi  %hi(0xa802e000), %o3
a0145df0:  90 12 e1 a0  or  %o3, 0x1a0, %o0	! 0xa802e1a0
a0145df4:  95 2a 60 10  sll  %o1, 0x10, %o2
a0145df8:  1b 3f c0 00  sethi  %hi(0xff000000), %o5
a0145dfc:  d2 02 20 08  ld  [ %o0 + 8 ], %o1
a0145e00:  82 13 60 ff  or  %o5, 0xff, %g1
a0145e04:  9a 0a 40 01  and  %o1, %g1, %o5
a0145e08:  99 32 a0 08  srl  %o2, 8, %o4
a0145e0c:  92 13 40 0c  or  %o5, %o4, %o1
a0145e10:  10 80 00 28  b  0xa0145eb0
a0145e14:  d2 22 20 08  st  %o1, [ %o0 + 8 ]
a0145e18:  17 2a 00 b8  sethi  %hi(0xa802e000), %o3
a0145e1c:  10 80 00 25  b  0xa0145eb0
a0145e20:  d2 2a e1 a8  stb  %o1, [ %o3 + 0x1a8 ]	! 0xa802e1a8
a0145e24:  17 2a 00 b8  sethi  %hi(0xa802e000), %o3
a0145e28:  d0 02 e1 a0  ld  [ %o3 + 0x1a0 ], %o0	! 0xa802e1a0
a0145e2c:  9a 0a 60 01  and  %o1, 1, %o5
a0145e30:  03 01 00 00  sethi  %hi(0x4000000), %g1
a0145e34:  82 2a 00 01  andn  %o0, %g1, %g1
a0145e38:  9b 2b 60 1a  sll  %o5, 0x1a, %o5
a0145e3c:  94 10 40 0d  or  %g1, %o5, %o2
a0145e40:  10 80 00 1c  b  0xa0145eb0
a0145e44:  d4 22 e1 a0  st  %o2, [ %o3 + 0x1a0 ]
a0145e48:  94 0a 60 01  and  %o1, 1, %o2
a0145e4c:  17 2a 00 b8  sethi  %hi(0xa802e000), %o3
a0145e50:  d8 02 e1 a0  ld  [ %o3 + 0x1a0 ], %o4	! 0xa802e1a0
a0145e54:  13 02 00 00  sethi  %hi(0x8000000), %o1
a0145e58:  82 2b 00 09  andn  %o4, %o1, %g1
a0145e5c:  9b 2a a0 1b  sll  %o2, 0x1b, %o5
a0145e60:  94 10 40 0d  or  %g1, %o5, %o2
a0145e64:  10 80 00 13  b  0xa0145eb0
a0145e68:  d4 22 e1 a0  st  %o2, [ %o3 + 0x1a0 ]
a0145e6c:  17 2a 00 b8  sethi  %hi(0xa802e000), %o3
a0145e70:  d0 02 e1 a0  ld  [ %o3 + 0x1a0 ], %o0	! 0xa802e1a0
a0145e74:  9a 0a 60 01  and  %o1, 1, %o5
a0145e78:  03 08 00 00  sethi  %hi(0x20000000), %g1
a0145e7c:  82 2a 00 01  andn  %o0, %g1, %g1
a0145e80:  9b 2b 60 1d  sll  %o5, 0x1d, %o5
a0145e84:  94 10 40 0d  or  %g1, %o5, %o2
a0145e88:  10 80 00 0a  b  0xa0145eb0
a0145e8c:  d4 22 e1 a0  st  %o2, [ %o3 + 0x1a0 ]
a0145e90:  94 0a 60 01  and  %o1, 1, %o2
a0145e94:  17 2a 00 b8  sethi  %hi(0xa802e000), %o3
a0145e98:  d8 02 e1 a0  ld  [ %o3 + 0x1a0 ], %o4	! 0xa802e1a0
a0145e9c:  13 10 00 00  sethi  %hi(0x40000000), %o1
a0145ea0:  82 2b 00 09  andn  %o4, %o1, %g1
a0145ea4:  9b 2a a0 1e  sll  %o2, 0x1e, %o5
a0145ea8:  94 10 40 0d  or  %g1, %o5, %o2
a0145eac:  d4 22 e1 a0  st  %o2, [ %o3 + 0x1a0 ]
a0145eb0:  81 c3 e0 08  retl
a0145eb4:  01 00 00 00  nop
