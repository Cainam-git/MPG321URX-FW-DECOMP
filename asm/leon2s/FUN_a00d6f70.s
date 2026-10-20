# leon2s FUN_a00d6f70 0xa00d6f70-0xa00d714c (476 bytes)
a00d6f70:  9d e3 bf 98  save  %sp, -104, %sp
a00d6f74:  c2 0e 40 00  ldub  [ %i1 ], %g1
a00d6f78:  83 30 60 04  srl  %g1, 4, %g1
a00d6f7c:  82 00 7f ff  add  %g1, -1, %g1
a00d6f80:  bb 30 60 1f  srl  %g1, 0x1f, %i5
a00d6f84:  ba 00 40 1d  add  %g1, %i5, %i5
a00d6f88:  bb 3f 60 01  sra  %i5, 1, %i5
a00d6f8c:  90 10 00 19  mov  %i1, %o0
a00d6f90:  80 88 60 01  btst  1, %g1
a00d6f94:  9e 10 00 18  mov  %i0, %o7
a00d6f98:  02 80 00 03  be  0xa00d6fa4
a00d6f9c:  94 10 00 1d  mov  %i5, %o2
a00d6fa0:  94 07 60 01  add  %i5, 1, %o2
a00d6fa4:  b6 0a a0 ff  and  %o2, 0xff, %i3
a00d6fa8:  b8 06 c0 08  add  %i3, %o0, %i4
a00d6fac:  fa 0f 20 03  ldub  [ %i4 + 3 ], %i5
a00d6fb0:  c2 0b c0 00  ldub  [ %o7 ], %g1
a00d6fb4:  ba 0f 60 7f  and  %i5, 0x7f, %i5
a00d6fb8:  82 08 7f 80  and  %g1, -128, %g1
a00d6fbc:  82 10 40 1d  or  %g1, %i5, %g1
a00d6fc0:  c2 2b c0 00  stb  %g1, [ %o7 ]
a00d6fc4:  fa 0f 20 04  ldub  [ %i4 + 4 ], %i5
a00d6fc8:  c2 0b e0 01  ldub  [ %o7 + 1 ], %g1
a00d6fcc:  ba 0f 60 f0  and  %i5, 0xf0, %i5
a00d6fd0:  82 08 60 0f  and  %g1, 0xf, %g1
a00d6fd4:  82 10 40 1d  or  %g1, %i5, %g1
a00d6fd8:  c2 2b e0 01  stb  %g1, [ %o7 + 1 ]
a00d6fdc:  fa 0f 20 04  ldub  [ %i4 + 4 ], %i5
a00d6fe0:  ba 0f 60 03  and  %i5, 3, %i5
a00d6fe4:  82 08 7f fc  and  %g1, -4, %g1
a00d6fe8:  82 10 40 1d  or  %g1, %i5, %g1
a00d6fec:  80 88 60 03  btst  3, %g1
a00d6ff0:  c2 2b e0 01  stb  %g1, [ %o7 + 1 ]
a00d6ff4:  b0 10 20 05  mov  5, %i0
a00d6ff8:  02 80 00 45  be  0xa00d710c
a00d6ffc:  92 10 20 00  clr  %o1
a00d7000:  a0 10 00 1b  mov  %i3, %l0
a00d7004:  9a 10 00 1c  mov  %i4, %o5
a00d7008:  a2 10 20 00  clr  %l1
a00d700c:  b6 0a 60 ff  and  %o1, 0xff, %i3
a00d7010:  82 06 c0 1b  add  %i3, %i3, %g1
a00d7014:  82 00 40 1b  add  %g1, %i3, %g1
a00d7018:  83 28 60 02  sll  %g1, 2, %g1
a00d701c:  bb 2e 20 10  sll  %i0, 0x10, %i5
a00d7020:  82 00 40 1b  add  %g1, %i3, %g1
a00d7024:  b4 03 c0 01  add  %o7, %g1, %i2
a00d7028:  bb 37 60 10  srl  %i5, 0x10, %i5
a00d702c:  c2 0b 40 1d  ldub  [ %o5 + %i5 ], %g1
a00d7030:  fa 0e a0 02  ldub  [ %i2 + 2 ], %i5
a00d7034:  82 08 60 7f  and  %g1, 0x7f, %g1
a00d7038:  ba 0f 7f 80  and  %i5, -128, %i5
a00d703c:  b8 06 20 01  add  %i0, 1, %i4
a00d7040:  ba 17 40 01  or  %i5, %g1, %i5
a00d7044:  83 2f 20 10  sll  %i4, 0x10, %g1
a00d7048:  fa 2e a0 02  stb  %i5, [ %i2 + 2 ]
a00d704c:  83 30 60 10  srl  %g1, 0x10, %g1
a00d7050:  c2 0b 40 01  ldub  [ %o5 + %g1 ], %g1
a00d7054:  c2 2e a0 03  stb  %g1, [ %i2 + 3 ]
a00d7058:  80 a4 40 01  cmp  %l1, %g1
a00d705c:  b0 07 20 01  add  %i4, 1, %i0
a00d7060:  1a 80 00 11  bcc  0xa00d70a4
a00d7064:  b2 10 20 00  clr  %i1
a00d7068:  96 10 00 1a  mov  %i2, %o3
a00d706c:  98 10 00 01  mov  %g1, %o4
a00d7070:  b4 04 00 08  add  %l0, %o0, %i2
a00d7074:  82 10 00 18  mov  %i0, %g1
a00d7078:  ba 0e 60 ff  and  %i1, 0xff, %i5
a00d707c:  83 28 60 10  sll  %g1, 0x10, %g1
a00d7080:  83 30 60 10  srl  %g1, 0x10, %g1
a00d7084:  b2 06 60 01  inc  %i1
a00d7088:  ba 02 c0 1d  add  %o3, %i5, %i5
a00d708c:  c2 0e 80 01  ldub  [ %i2 + %g1 ], %g1
a00d7090:  b8 0e 60 ff  and  %i1, 0xff, %i4
a00d7094:  c2 2f 60 04  stb  %g1, [ %i5 + 4 ]
a00d7098:  80 a7 00 0c  cmp  %i4, %o4
a00d709c:  0a bf ff f6  bcs  0xa00d7074
a00d70a0:  b0 06 20 01  inc  %i0
a00d70a4:  b8 06 c0 1b  add  %i3, %i3, %i4
a00d70a8:  b8 07 00 1b  add  %i4, %i3, %i4
a00d70ac:  b9 2f 20 02  sll  %i4, 2, %i4
a00d70b0:  b8 07 00 1b  add  %i4, %i3, %i4
a00d70b4:  b7 2e 20 10  sll  %i0, 0x10, %i3
a00d70b8:  b8 07 00 0f  add  %i4, %o7, %i4
a00d70bc:  b7 36 e0 10  srl  %i3, 0x10, %i3
a00d70c0:  fa 0b 40 1b  ldub  [ %o5 + %i3 ], %i5
a00d70c4:  c2 0f 20 0e  ldub  [ %i4 + 0xe ], %g1
a00d70c8:  ba 0f 60 10  and  %i5, 0x10, %i5
a00d70cc:  82 08 7f ef  and  %g1, -17, %g1
a00d70d0:  82 10 40 1d  or  %g1, %i5, %g1
a00d70d4:  c2 2f 20 0e  stb  %g1, [ %i4 + 0xe ]
a00d70d8:  fa 0b 40 1b  ldub  [ %o5 + %i3 ], %i5
a00d70dc:  ba 0f 60 0f  and  %i5, 0xf, %i5
a00d70e0:  82 08 7f f0  and  %g1, -16, %g1
a00d70e4:  82 10 40 1d  or  %g1, %i5, %g1
a00d70e8:  c2 2f 20 0e  stb  %g1, [ %i4 + 0xe ]
a00d70ec:  92 02 60 01  inc  %o1
a00d70f0:  c2 0b e0 01  ldub  [ %o7 + 1 ], %g1
a00d70f4:  82 08 60 03  and  %g1, 3, %g1
a00d70f8:  ba 0a 60 ff  and  %o1, 0xff, %i5
a00d70fc:  80 a7 40 01  cmp  %i5, %g1
a00d7100:  0a bf ff c3  bcs  0xa00d700c
a00d7104:  b0 06 20 01  inc  %i0
a00d7108:  b6 0a a0 ff  and  %o2, 0xff, %i3
a00d710c:  83 2e 20 10  sll  %i0, 0x10, %g1
a00d7110:  b6 06 c0 08  add  %i3, %o0, %i3
a00d7114:  83 30 60 10  srl  %g1, 0x10, %g1
a00d7118:  f8 0e c0 01  ldub  [ %i3 + %g1 ], %i4
a00d711c:  fa 0b e0 1c  ldub  [ %o7 + 0x1c ], %i5
a00d7120:  b8 0f 20 7f  and  %i4, 0x7f, %i4
a00d7124:  ba 0f 7f 80  and  %i5, -128, %i5
a00d7128:  82 06 20 01  add  %i0, 1, %g1
a00d712c:  ba 17 40 1c  or  %i5, %i4, %i5
a00d7130:  83 28 60 10  sll  %g1, 0x10, %g1
a00d7134:  fa 2b e0 1c  stb  %i5, [ %o7 + 0x1c ]
a00d7138:  83 30 60 10  srl  %g1, 0x10, %g1
a00d713c:  c2 0e c0 01  ldub  [ %i3 + %g1 ], %g1
a00d7140:  c2 2b e0 1d  stb  %g1, [ %o7 + 0x1d ]
a00d7144:  81 c7 e0 08  ret
a00d7148:  81 e8 00 00  restore
