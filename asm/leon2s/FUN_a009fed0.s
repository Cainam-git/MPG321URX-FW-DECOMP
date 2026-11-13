# leon2s FUN_a009fed0 0xa009fed0-0xa00a0268 (920 bytes)
a009fed0:  9d e3 bf 88  save  %sp, -120, %sp
a009fed4:  92 0e 20 ff  and  %i0, 0xff, %o1
a009fed8:  23 2a 01 f6  sethi  %hi(0xa807d800), %l1
a009fedc:  82 14 63 00  or  %l1, 0x300, %g1	! 0xa807db00
a009fee0:  9a 5a 60 34  smul  %o1, 0x34, %o5
a009fee4:  9a 03 40 01  add  %o5, %g1, %o5
a009fee8:  d0 03 60 14  ld  [ %o5 + 0x14 ], %o0
a009feec:  c2 02 00 00  ld  [ %o0 ], %g1
a009fef0:  82 08 60 ff  and  %g1, 0xff, %g1
a009fef4:  80 a0 60 87  cmp  %g1, 0x87
a009fef8:  32 80 00 5d  bne,a   0xa00a006c
a009fefc:  90 10 00 19  mov  %i1, %o0
a009ff00:  c2 02 00 00  ld  [ %o0 ], %g1
a009ff04:  83 30 60 08  srl  %g1, 8, %g1
a009ff08:  82 08 60 ff  and  %g1, 0xff, %g1
a009ff0c:  80 a0 60 01  cmp  %g1, 1
a009ff10:  32 80 00 57  bne,a   0xa00a006c
a009ff14:  90 10 00 19  mov  %i1, %o0
a009ff18:  c2 02 20 04  ld  [ %o0 + 4 ], %g1
a009ff1c:  82 08 60 07  and  %g1, 7, %g1
a009ff20:  80 a0 60 03  cmp  %g1, 3
a009ff24:  38 80 00 02  bgu,a   0xa009ff2c
a009ff28:  82 10 20 04  mov  4, %g1
a009ff2c:  9a 08 60 ff  and  %g1, 0xff, %o5
a009ff30:  03 28 02 d1  sethi  %hi(0xa00b4400), %g1
a009ff34:  9b 2b 60 03  sll  %o5, 3, %o5
a009ff38:  d8 02 20 04  ld  [ %o0 + 4 ], %o4
a009ff3c:  82 10 61 68  or  %g1, 0x168, %g1
a009ff40:  c2 00 40 0d  ld  [ %g1 + %o5 ], %g1
a009ff44:  99 33 20 08  srl  %o4, 8, %o4
a009ff48:  9a 0b 20 07  and  %o4, 7, %o5
a009ff4c:  80 a3 60 00  cmp  %o5, 0
a009ff50:  02 80 00 03  be  0xa009ff5c
a009ff54:  c2 26 60 04  st  %g1, [ %i1 + 4 ]
a009ff58:  9a 10 20 01  mov  1, %o5
a009ff5c:  d8 02 20 04  ld  [ %o0 + 4 ], %o4
a009ff60:  d6 02 20 08  ld  [ %o0 + 8 ], %o3
a009ff64:  d4 02 20 0c  ld  [ %o0 + 0xc ], %o2
a009ff68:  e0 02 20 08  ld  [ %o0 + 8 ], %l0
a009ff6c:  9a 0b 60 ff  and  %o5, 0xff, %o5
a009ff70:  03 28 02 d1  sethi  %hi(0xa00b4400), %g1
a009ff74:  de 02 20 0c  ld  [ %o0 + 0xc ], %o7
a009ff78:  9b 2b 60 03  sll  %o5, 3, %o5
a009ff7c:  82 10 61 58  or  %g1, 0x158, %g1
a009ff80:  99 33 20 10  srl  %o4, 0x10, %o4
a009ff84:  97 32 e0 10  srl  %o3, 0x10, %o3
a009ff88:  c2 00 40 0d  ld  [ %g1 + %o5 ], %g1
a009ff8c:  95 32 a0 10  srl  %o2, 0x10, %o2
a009ff90:  d0 02 20 10  ld  [ %o0 + 0x10 ], %o0
a009ff94:  c2 26 60 08  st  %g1, [ %i1 + 8 ]
a009ff98:  80 a3 00 0b  cmp  %o4, %o3
a009ff9c:  d8 37 bf f0  sth  %o4, [ %fp + -16 ]
a009ffa0:  d6 37 bf f2  sth  %o3, [ %fp + -14 ]
a009ffa4:  d4 37 bf f4  sth  %o2, [ %fp + -12 ]
a009ffa8:  e0 37 bf e8  sth  %l0, [ %fp + -24 ]
a009ffac:  de 37 bf ea  sth  %o7, [ %fp + -22 ]
a009ffb0:  0a 80 00 10  bcs  0xa009fff0
a009ffb4:  d0 37 bf ec  sth  %o0, [ %fp + -20 ]
a009ffb8:  80 a3 00 0a  cmp  %o4, %o2
a009ffbc:  2a 80 00 0e  bcs,a   0xa009fff4
a009ffc0:  da 17 bf f2  lduh  [ %fp + -14 ], %o5
a009ffc4:  9b 2b e0 10  sll  %o7, 0x10, %o5
a009ffc8:  83 2c 20 10  sll  %l0, 0x10, %g1
a009ffcc:  80 a0 40 0d  cmp  %g1, %o5
a009ffd0:  96 10 20 00  clr  %o3
a009ffd4:  18 80 00 19  bgu  0xa00a0038
a009ffd8:  9b 33 60 10  srl  %o5, 0x10, %o5
a009ffdc:  83 2a 20 10  sll  %o0, 0x10, %g1
a009ffe0:  83 30 60 10  srl  %g1, 0x10, %g1
a009ffe4:  80 a3 40 01  cmp  %o5, %g1
a009ffe8:  10 80 00 12  b  0xa00a0030
a009ffec:  98 10 20 01  mov  1, %o4
a009fff0:  da 17 bf f2  lduh  [ %fp + -14 ], %o5
a009fff4:  c2 17 bf f0  lduh  [ %fp + -16 ], %g1
a009fff8:  80 a3 40 01  cmp  %o5, %g1
a009fffc:  2a 80 00 11  bcs,a   0xa00a0040
a00a0000:  da 17 bf e8  lduh  [ %fp + -24 ], %o5
a00a0004:  c2 17 bf f4  lduh  [ %fp + -12 ], %g1
a00a0008:  80 a3 40 01  cmp  %o5, %g1
a00a000c:  0a 80 00 0d  bcs  0xa00a0040
a00a0010:  da 17 bf e8  lduh  [ %fp + -24 ], %o5
a00a0014:  c2 17 bf ea  lduh  [ %fp + -22 ], %g1
a00a0018:  80 a3 40 01  cmp  %o5, %g1
a00a001c:  0a 80 00 07  bcs  0xa00a0038
a00a0020:  96 10 20 01  mov  1, %o3
a00a0024:  c2 17 bf ec  lduh  [ %fp + -20 ], %g1
a00a0028:  80 a3 40 01  cmp  %o5, %g1
a00a002c:  98 10 20 00  clr  %o4
a00a0030:  1a 80 00 15  bcc  0xa00a0084
a00a0034:  82 14 63 00  or  %l1, 0x300, %g1
a00a0038:  10 80 00 12  b  0xa00a0080
a00a003c:  98 10 20 02  mov  2, %o4
a00a0040:  c2 17 bf ea  lduh  [ %fp + -22 ], %g1
a00a0044:  80 a3 40 01  cmp  %o5, %g1
a00a0048:  96 10 20 02  mov  2, %o3
a00a004c:  0a 80 00 06  bcs  0xa00a0064
a00a0050:  98 10 20 00  clr  %o4
a00a0054:  c2 17 bf ec  lduh  [ %fp + -20 ], %g1
a00a0058:  80 a3 40 01  cmp  %o5, %g1
a00a005c:  1a 80 00 0a  bcc  0xa00a0084
a00a0060:  82 14 63 00  or  %l1, 0x300, %g1
a00a0064:  10 80 00 07  b  0xa00a0080
a00a0068:  98 10 20 01  mov  1, %o4
a00a006c:  92 10 20 00  clr  %o1
a00a0070:  40 00 45 4f  call  0xa00b15ac
a00a0074:  94 10 20 48  mov  0x48, %o2
a00a0078:  10 80 00 7a  b  0xa00a0260
a00a007c:  b0 10 20 01  mov  1, %i0
a00a0080:  82 14 63 00  or  %l1, 0x300, %g1
a00a0084:  92 5a 60 34  smul  %o1, 0x34, %o1
a00a0088:  92 02 40 01  add  %o1, %g1, %o1
a00a008c:  c2 02 60 14  ld  [ %o1 + 0x14 ], %g1
a00a0090:  de 00 60 10  ld  [ %g1 + 0x10 ], %o7
a00a0094:  e8 00 60 14  ld  [ %g1 + 0x14 ], %l4
a00a0098:  e0 00 60 14  ld  [ %g1 + 0x14 ], %l0
a00a009c:  ea 00 60 18  ld  [ %g1 + 0x18 ], %l5
a00a00a0:  e2 00 60 18  ld  [ %g1 + 0x18 ], %l1
a00a00a4:  ec 00 60 1c  ld  [ %g1 + 0x1c ], %l6
a00a00a8:  82 10 20 01  mov  1, %g1
a00a00ac:  c2 2e 40 00  stb  %g1, [ %i1 ]
a00a00b0:  82 10 3f 87  mov  -121, %g1
a00a00b4:  c2 2e 60 24  stb  %g1, [ %i1 + 0x24 ]
a00a00b8:  c2 02 60 14  ld  [ %o1 + 0x14 ], %g1
a00a00bc:  c2 00 40 00  ld  [ %g1 ], %g1
a00a00c0:  83 30 60 08  srl  %g1, 8, %g1
a00a00c4:  c2 2e 60 25  stb  %g1, [ %i1 + 0x25 ]
a00a00c8:  c2 02 60 14  ld  [ %o1 + 0x14 ], %g1
a00a00cc:  c2 00 40 00  ld  [ %g1 ], %g1
a00a00d0:  96 0a e0 ff  and  %o3, 0xff, %o3
a00a00d4:  98 0b 20 ff  and  %o4, 0xff, %o4
a00a00d8:  9a 20 00 0b  neg  %o3, %o5
a00a00dc:  83 30 60 10  srl  %g1, 0x10, %g1
a00a00e0:  c2 2e 60 26  stb  %g1, [ %i1 + 0x26 ]
a00a00e4:  9a 23 40 0c  sub  %o5, %o4, %o5
a00a00e8:  82 07 bf f8  add  %fp, -8, %g1
a00a00ec:  9a 03 40 0d  add  %o5, %o5, %o5
a00a00f0:  96 02 c0 0b  add  %o3, %o3, %o3
a00a00f4:  98 03 00 0c  add  %o4, %o4, %o4
a00a00f8:  9a 03 40 01  add  %o5, %g1, %o5
a00a00fc:  96 02 c0 01  add  %o3, %g1, %o3
a00a0100:  98 03 00 01  add  %o4, %g1, %o4
a00a0104:  c2 02 60 14  ld  [ %o1 + 0x14 ], %g1
a00a0108:  e4 13 3f f0  lduh  [ %o4 + -16 ], %l2
a00a010c:  e6 13 7f f6  lduh  [ %o5 + -10 ], %l3
a00a0110:  d4 00 40 00  ld  [ %g1 ], %o2
a00a0114:  c2 12 ff f8  lduh  [ %o3 + -8 ], %g1
a00a0118:  d8 13 3f f8  lduh  [ %o4 + -8 ], %o4
a00a011c:  da 13 7f fe  lduh  [ %o5 + -2 ], %o5
a00a0120:  d0 12 ff f0  lduh  [ %o3 + -16 ], %o0
a00a0124:  9f 33 e0 10  srl  %o7, 0x10, %o7
a00a0128:  a1 34 20 10  srl  %l0, 0x10, %l0
a00a012c:  c2 36 60 0c  sth  %g1, [ %i1 + 0xc ]
a00a0130:  d8 36 60 10  sth  %o4, [ %i1 + 0x10 ]
a00a0134:  da 36 60 14  sth  %o5, [ %i1 + 0x14 ]
a00a0138:  a3 34 60 10  srl  %l1, 0x10, %l1
a00a013c:  d0 36 60 0e  sth  %o0, [ %i1 + 0xe ]
a00a0140:  e4 36 60 12  sth  %l2, [ %i1 + 0x12 ]
a00a0144:  e6 36 60 16  sth  %l3, [ %i1 + 0x16 ]
a00a0148:  de 36 60 18  sth  %o7, [ %i1 + 0x18 ]
a00a014c:  e8 36 60 1a  sth  %l4, [ %i1 + 0x1a ]
a00a0150:  e0 36 60 1c  sth  %l0, [ %i1 + 0x1c ]
a00a0154:  ea 36 60 1e  sth  %l5, [ %i1 + 0x1e ]
a00a0158:  e2 36 60 20  sth  %l1, [ %i1 + 0x20 ]
a00a015c:  95 32 a0 18  srl  %o2, 0x18, %o2
a00a0160:  d4 2e 60 27  stb  %o2, [ %i1 + 0x27 ]
a00a0164:  c2 02 60 14  ld  [ %o1 + 0x14 ], %g1
a00a0168:  f0 00 60 04  ld  [ %g1 + 4 ], %i0
a00a016c:  99 36 20 18  srl  %i0, 0x18, %o4
a00a0170:  83 36 20 08  srl  %i0, 8, %g1
a00a0174:  9b 36 20 10  srl  %i0, 0x10, %o5
a00a0178:  da 2e 60 2a  stb  %o5, [ %i1 + 0x2a ]
a00a017c:  d8 2e 60 2b  stb  %o4, [ %i1 + 0x2b ]
a00a0180:  c2 2e 60 29  stb  %g1, [ %i1 + 0x29 ]
a00a0184:  f0 2e 60 28  stb  %i0, [ %i1 + 0x28 ]
a00a0188:  c2 02 60 14  ld  [ %o1 + 0x14 ], %g1
a00a018c:  f0 00 60 08  ld  [ %g1 + 8 ], %i0
a00a0190:  99 36 20 18  srl  %i0, 0x18, %o4
a00a0194:  83 36 20 08  srl  %i0, 8, %g1
a00a0198:  9b 36 20 10  srl  %i0, 0x10, %o5
a00a019c:  da 2e 60 2e  stb  %o5, [ %i1 + 0x2e ]
a00a01a0:  d8 2e 60 2f  stb  %o4, [ %i1 + 0x2f ]
a00a01a4:  c2 2e 60 2d  stb  %g1, [ %i1 + 0x2d ]
a00a01a8:  f0 2e 60 2c  stb  %i0, [ %i1 + 0x2c ]
a00a01ac:  c2 02 60 14  ld  [ %o1 + 0x14 ], %g1
a00a01b0:  f0 00 60 0c  ld  [ %g1 + 0xc ], %i0
a00a01b4:  99 36 20 18  srl  %i0, 0x18, %o4
a00a01b8:  83 36 20 08  srl  %i0, 8, %g1
a00a01bc:  9b 36 20 10  srl  %i0, 0x10, %o5
a00a01c0:  da 2e 60 32  stb  %o5, [ %i1 + 0x32 ]
a00a01c4:  d8 2e 60 33  stb  %o4, [ %i1 + 0x33 ]
a00a01c8:  c2 2e 60 31  stb  %g1, [ %i1 + 0x31 ]
a00a01cc:  f0 2e 60 30  stb  %i0, [ %i1 + 0x30 ]
a00a01d0:  c2 02 60 14  ld  [ %o1 + 0x14 ], %g1
a00a01d4:  f0 00 60 10  ld  [ %g1 + 0x10 ], %i0
a00a01d8:  99 36 20 18  srl  %i0, 0x18, %o4
a00a01dc:  83 36 20 08  srl  %i0, 8, %g1
a00a01e0:  9b 36 20 10  srl  %i0, 0x10, %o5
a00a01e4:  da 2e 60 36  stb  %o5, [ %i1 + 0x36 ]
a00a01e8:  d8 2e 60 37  stb  %o4, [ %i1 + 0x37 ]
a00a01ec:  c2 2e 60 35  stb  %g1, [ %i1 + 0x35 ]
a00a01f0:  f0 2e 60 34  stb  %i0, [ %i1 + 0x34 ]
a00a01f4:  c2 02 60 14  ld  [ %o1 + 0x14 ], %g1
a00a01f8:  f0 00 60 14  ld  [ %g1 + 0x14 ], %i0
a00a01fc:  83 36 20 08  srl  %i0, 8, %g1
a00a0200:  9b 36 20 10  srl  %i0, 0x10, %o5
a00a0204:  99 36 20 18  srl  %i0, 0x18, %o4
a00a0208:  da 2e 60 3a  stb  %o5, [ %i1 + 0x3a ]
a00a020c:  c2 2e 60 39  stb  %g1, [ %i1 + 0x39 ]
a00a0210:  d8 2e 60 3b  stb  %o4, [ %i1 + 0x3b ]
a00a0214:  f0 2e 60 38  stb  %i0, [ %i1 + 0x38 ]
a00a0218:  c2 02 60 14  ld  [ %o1 + 0x14 ], %g1
a00a021c:  f0 00 60 18  ld  [ %g1 + 0x18 ], %i0
a00a0220:  ec 36 60 22  sth  %l6, [ %i1 + 0x22 ]
a00a0224:  f0 2e 60 3c  stb  %i0, [ %i1 + 0x3c ]
a00a0228:  83 36 20 08  srl  %i0, 8, %g1
a00a022c:  c2 2e 60 3d  stb  %g1, [ %i1 + 0x3d ]
a00a0230:  9b 36 20 18  srl  %i0, 0x18, %o5
a00a0234:  83 36 20 10  srl  %i0, 0x10, %g1
a00a0238:  da 2e 60 3f  stb  %o5, [ %i1 + 0x3f ]
a00a023c:  c2 2e 60 3e  stb  %g1, [ %i1 + 0x3e ]
a00a0240:  c2 02 60 14  ld  [ %o1 + 0x14 ], %g1
a00a0244:  f0 00 60 1c  ld  [ %g1 + 0x1c ], %i0
a00a0248:  83 36 20 10  srl  %i0, 0x10, %g1
a00a024c:  9b 36 20 08  srl  %i0, 8, %o5
a00a0250:  f0 2e 60 40  stb  %i0, [ %i1 + 0x40 ]
a00a0254:  c2 2e 60 42  stb  %g1, [ %i1 + 0x42 ]
a00a0258:  da 2e 60 41  stb  %o5, [ %i1 + 0x41 ]
a00a025c:  b0 10 20 00  clr  %i0
a00a0260:  81 c7 e0 08  ret
a00a0264:  81 e8 00 00  restore
