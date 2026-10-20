# leon2s FUN_a00ccfa8 0xa00ccfa8-0xa00cd2f0 (840 bytes)
a00ccfa8:  9d e3 bf 88  save  %sp, -120, %sp
a00ccfac:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00ccfb0:  82 06 00 18  add  %i0, %i0, %g1
a00ccfb4:  82 00 40 18  add  %g1, %i0, %g1
a00ccfb8:  a1 28 60 03  sll  %g1, 3, %l0
a00ccfbc:  03 3f ff 3f  sethi  %hi(0xfffcfc00), %g1
a00ccfc0:  2b 2a 01 e2  sethi  %hi(0xa8078800), %l5
a00ccfc4:  a2 15 63 b0  or  %l5, 0x3b0, %l1	! 0xa8078bb0
a00ccfc8:  a6 10 63 ff  or  %g1, 0x3ff, %l3
a00ccfcc:  c2 04 40 10  ld  [ %l1 + %l0 ], %g1
a00ccfd0:  1b 00 00 40  sethi  %hi(0x10000), %o5
a00ccfd4:  82 08 40 13  and  %g1, %l3, %g1
a00ccfd8:  82 10 40 0d  or  %g1, %o5, %g1
a00ccfdc:  25 00 01 a0  sethi  %hi(0x68000), %l2
a00ccfe0:  c2 24 40 10  st  %g1, [ %l1 + %l0 ]
a00ccfe4:  90 10 20 00  clr  %o0
a00ccfe8:  92 10 20 90  mov  0x90, %o1
a00ccfec:  94 14 a0 28  or  %l2, 0x28, %o2
a00ccff0:  96 10 20 00  clr  %o3
a00ccff4:  40 3b 25 03  call  0xa0f96400
a00ccff8:  98 07 bf ef  add  %fp, -17, %o4
a00ccffc:  80 8a 20 ff  btst  0xff, %o0
a00cd000:  32 80 00 06  bne,a   0xa00cd018
a00cd004:  c2 0f bf ef  ldub  [ %fp + -17 ], %g1
a00cd008:  c2 04 40 10  ld  [ %l1 + %l0 ], %g1
a00cd00c:  1b 00 00 c0  sethi  %hi(0x30000), %o5
a00cd010:  10 80 00 07  b  0xa00cd02c
a00cd014:  82 10 40 0d  or  %g1, %o5, %g1
a00cd018:  80 88 60 01  btst  1, %g1
a00cd01c:  12 80 00 06  bne  0xa00cd034
a00cd020:  80 88 60 02  btst  2, %g1
a00cd024:  c2 04 40 10  ld  [ %l1 + %l0 ], %g1
a00cd028:  82 08 40 13  and  %g1, %l3, %g1
a00cd02c:  10 80 00 ae  b  0xa00cd2e4
a00cd030:  c2 24 40 10  st  %g1, [ %l1 + %l0 ]
a00cd034:  da 04 40 10  ld  [ %l1 + %l0 ], %o5
a00cd038:  02 80 00 11  be  0xa00cd07c
a00cd03c:  98 07 bf f0  add  %fp, -16, %o4
a00cd040:  03 04 00 00  sethi  %hi(0x10000000), %g1
a00cd044:  82 13 40 01  or  %o5, %g1, %g1
a00cd048:  1b 33 c0 63  sethi  %hi(0xcf018c00), %o5
a00cd04c:  c2 24 40 10  st  %g1, [ %l1 + %l0 ]
a00cd050:  9a 13 61 54  or  %o5, 0x154, %o5
a00cd054:  c2 03 40 00  ld  [ %o5 ], %g1
a00cd058:  82 10 60 01  or  %g1, 1, %g1
a00cd05c:  c2 23 40 00  st  %g1, [ %o5 ]
a00cd060:  82 10 20 01  mov  1, %g1
a00cd064:  c2 2f bf f0  stb  %g1, [ %fp + -16 ]
a00cd068:  94 14 a0 3b  or  %l2, 0x3b, %o2
a00cd06c:  92 10 20 80  mov  0x80, %o1
a00cd070:  96 10 20 00  clr  %o3
a00cd074:  10 80 00 0f  b  0xa00cd0b0
a00cd078:  90 10 20 00  clr  %o0
a00cd07c:  03 04 00 00  sethi  %hi(0x10000000), %g1
a00cd080:  82 2b 40 01  andn  %o5, %g1, %g1
a00cd084:  1b 33 c0 63  sethi  %hi(0xcf018c00), %o5
a00cd088:  c2 24 40 10  st  %g1, [ %l1 + %l0 ]
a00cd08c:  9a 13 61 54  or  %o5, 0x154, %o5
a00cd090:  c2 03 40 00  ld  [ %o5 ], %g1
a00cd094:  82 08 7f fe  and  %g1, -2, %g1
a00cd098:  c2 23 40 00  st  %g1, [ %o5 ]
a00cd09c:  c0 2f bf f0  clrb  [ %fp + -16 ]
a00cd0a0:  94 14 a0 3b  or  %l2, 0x3b, %o2
a00cd0a4:  90 10 20 00  clr  %o0
a00cd0a8:  92 10 20 80  mov  0x80, %o1
a00cd0ac:  96 10 20 00  clr  %o3
a00cd0b0:  40 3b 24 c9  call  0xa0f963d4
a00cd0b4:  a4 10 20 00  clr  %l2
a00cd0b8:  11 27 c7 08  sethi  %hi(0x9f1c2000), %o0
a00cd0bc:  40 3a d7 e2  call  0xa0f83044
a00cd0c0:  90 12 21 80  or  %o0, 0x180, %o0	! 0x9f1c2180
a00cd0c4:  a0 10 20 03  mov  3, %l0
a00cd0c8:  a2 0c a0 ff  and  %l2, 0xff, %l1
a00cd0cc:  a8 07 bf f0  add  %fp, -16, %l4
a00cd0d0:  15 00 01 a0  sethi  %hi(0x68000), %o2
a00cd0d4:  94 04 40 0a  add  %l1, %o2, %o2
a00cd0d8:  90 10 20 00  clr  %o0
a00cd0dc:  92 10 20 90  mov  0x90, %o1
a00cd0e0:  96 10 20 00  clr  %o3
a00cd0e4:  40 3b 24 c7  call  0xa0f96400
a00cd0e8:  98 05 00 11  add  %l4, %l1, %o4
a00cd0ec:  82 04 3f ff  add  %l0, -1, %g1
a00cd0f0:  9a 08 60 ff  and  %g1, 0xff, %o5
a00cd0f4:  80 8a 20 ff  btst  0xff, %o0
a00cd0f8:  12 80 00 05  bne  0xa00cd10c
a00cd0fc:  a0 10 00 01  mov  %g1, %l0
a00cd100:  80 a3 60 ff  cmp  %o5, 0xff
a00cd104:  32 bf ff f2  bne,a   0xa00cd0cc
a00cd108:  a2 0c a0 ff  and  %l2, 0xff, %l1
a00cd10c:  03 00 00 18  sethi  %hi(0x6000), %g1
a00cd110:  82 10 63 50  or  %g1, 0x350, %g1	! 0x6350
a00cd114:  82 04 40 01  add  %l1, %g1, %g1
a00cd118:  1b 33 c0 00  sethi  %hi(0xcf000000), %o5
a00cd11c:  a6 07 bf f8  add  %fp, -8, %l3
a00cd120:  83 28 60 02  sll  %g1, 2, %g1
a00cd124:  82 10 40 0d  or  %g1, %o5, %g1
a00cd128:  98 04 c0 11  add  %l3, %l1, %o4
a00cd12c:  da 0b 3f f8  ldub  [ %o4 + -8 ], %o5
a00cd130:  da 20 40 00  st  %o5, [ %g1 ]
a00cd134:  d2 00 40 00  ld  [ %g1 ], %o1
a00cd138:  93 2a 60 10  sll  %o1, 0x10, %o1
a00cd13c:  11 27 c7 32  sethi  %hi(0x9f1cc800), %o0
a00cd140:  90 12 22 30  or  %o0, 0x230, %o0	! 0x9f1cca30
a00cd144:  40 3a d7 c0  call  0xa0f83044
a00cd148:  93 32 60 10  srl  %o1, 0x10, %o1
a00cd14c:  a4 04 a0 01  inc  %l2
a00cd150:  82 0c a0 ff  and  %l2, 0xff, %g1
a00cd154:  80 a0 60 04  cmp  %g1, 4
a00cd158:  08 bf ff dc  bleu  0xa00cd0c8
a00cd15c:  a0 10 20 03  mov  3, %l0
a00cd160:  96 10 20 00  clr  %o3
a00cd164:  a0 10 20 00  clr  %l0
a00cd168:  82 0c 20 ff  and  %l0, 0xff, %g1
a00cd16c:  82 04 c0 01  add  %l3, %g1, %g1
a00cd170:  d8 08 7f f8  ldub  [ %g1 + -8 ], %o4
a00cd174:  a4 10 20 00  clr  %l2
a00cd178:  82 0b 20 ff  and  %o4, 0xff, %g1
a00cd17c:  a4 04 a0 01  inc  %l2
a00cd180:  9a 0c a0 ff  and  %l2, 0xff, %o5
a00cd184:  80 88 60 01  btst  1, %g1
a00cd188:  02 80 00 03  be  0xa00cd194
a00cd18c:  99 30 60 01  srl  %g1, 1, %o4
a00cd190:  96 02 e0 01  inc  %o3
a00cd194:  80 a3 60 07  cmp  %o5, 7
a00cd198:  08 bf ff f9  bleu  0xa00cd17c
a00cd19c:  82 0b 20 ff  and  %o4, 0xff, %g1
a00cd1a0:  a0 04 20 01  inc  %l0
a00cd1a4:  82 0c 20 ff  and  %l0, 0xff, %g1
a00cd1a8:  80 a0 60 04  cmp  %g1, 4
a00cd1ac:  08 bf ff f1  bleu  0xa00cd170
a00cd1b0:  82 04 c0 01  add  %l3, %g1, %g1
a00cd1b4:  82 0a e0 ff  and  %o3, 0xff, %g1
a00cd1b8:  80 a0 60 14  cmp  %g1, 0x14
a00cd1bc:  02 80 00 0b  be  0xa00cd1e8
a00cd1c0:  03 33 c0 63  sethi  %hi(0xcf018c00), %g1
a00cd1c4:  9a 06 00 18  add  %i0, %i0, %o5
a00cd1c8:  9a 03 40 18  add  %o5, %i0, %o5
a00cd1cc:  96 15 63 b0  or  %l5, 0x3b0, %o3
a00cd1d0:  9b 2b 60 03  sll  %o5, 3, %o5
a00cd1d4:  d8 02 c0 0d  ld  [ %o3 + %o5 ], %o4
a00cd1d8:  03 00 00 c0  sethi  %hi(0x30000), %g1
a00cd1dc:  82 2b 00 01  andn  %o4, %g1, %g1
a00cd1e0:  10 80 00 41  b  0xa00cd2e4
a00cd1e4:  c2 22 c0 0d  st  %g1, [ %o3 + %o5 ]
a00cd1e8:  82 10 61 00  or  %g1, 0x100, %g1
a00cd1ec:  da 00 40 00  ld  [ %g1 ], %o5
a00cd1f0:  9a 13 60 20  or  %o5, 0x20, %o5
a00cd1f4:  da 20 40 00  st  %o5, [ %g1 ]
a00cd1f8:  c2 00 40 00  ld  [ %g1 ], %g1
a00cd1fc:  80 88 60 20  btst  0x20, %g1
a00cd200:  a0 10 20 00  clr  %l0
a00cd204:  02 80 00 0d  be  0xa00cd238
a00cd208:  03 00 00 18  sethi  %hi(0x6000), %g1
a00cd20c:  40 3b d1 62  call  0xa0fc1794
a00cd210:  90 10 20 01  mov  1, %o0
a00cd214:  a0 04 20 01  inc  %l0
a00cd218:  82 0c 20 ff  and  %l0, 0xff, %g1
a00cd21c:  80 a0 60 64  cmp  %g1, 0x64
a00cd220:  18 bf ff e9  bgu  0xa00cd1c4
a00cd224:  03 33 c0 63  sethi  %hi(0xcf018c00), %g1
a00cd228:  82 10 61 00  or  %g1, 0x100, %g1	! 0xcf018d00
a00cd22c:  c2 00 40 00  ld  [ %g1 ], %g1
a00cd230:  10 bf ff f5  b  0xa00cd204
a00cd234:  80 88 60 20  btst  0x20, %g1
a00cd238:  94 10 63 41  or  %g1, 0x341, %o2
a00cd23c:  a0 10 20 00  clr  %l0
a00cd240:  17 33 c0 00  sethi  %hi(0xcf000000), %o3
a00cd244:  9a 0c 20 ff  and  %l0, 0xff, %o5
a00cd248:  82 03 40 0a  add  %o5, %o2, %g1
a00cd24c:  83 28 60 02  sll  %g1, 2, %g1
a00cd250:  82 10 40 0b  or  %g1, %o3, %g1
a00cd254:  d8 00 40 00  ld  [ %g1 ], %o4
a00cd258:  a0 04 20 01  inc  %l0
a00cd25c:  9a 04 c0 0d  add  %l3, %o5, %o5
a00cd260:  82 0c 20 ff  and  %l0, 0xff, %g1
a00cd264:  80 a0 60 07  cmp  %g1, 7
a00cd268:  08 bf ff f7  bleu  0xa00cd244
a00cd26c:  d8 2b 7f f8  stb  %o4, [ %o5 + -8 ]
a00cd270:  15 00 01 a0  sethi  %hi(0x68000), %o2
a00cd274:  94 12 a0 0c  or  %o2, 0xc, %o2	! 0x6800c
a00cd278:  96 10 20 07  mov  7, %o3
a00cd27c:  90 10 20 00  clr  %o0
a00cd280:  92 10 20 80  mov  0x80, %o1
a00cd284:  40 3b 24 54  call  0xa0f963d4
a00cd288:  98 10 00 14  mov  %l4, %o4
a00cd28c:  03 00 00 18  sethi  %hi(0x6000), %g1
a00cd290:  94 10 63 49  or  %g1, 0x349, %o2	! 0x6349
a00cd294:  a0 10 20 00  clr  %l0
a00cd298:  17 33 c0 00  sethi  %hi(0xcf000000), %o3
a00cd29c:  9a 0c 20 ff  and  %l0, 0xff, %o5
a00cd2a0:  82 03 40 0a  add  %o5, %o2, %g1
a00cd2a4:  83 28 60 02  sll  %g1, 2, %g1
a00cd2a8:  82 10 40 0b  or  %g1, %o3, %g1
a00cd2ac:  d8 00 40 00  ld  [ %g1 ], %o4
a00cd2b0:  a0 04 20 01  inc  %l0
a00cd2b4:  9a 04 c0 0d  add  %l3, %o5, %o5
a00cd2b8:  82 0c 20 ff  and  %l0, 0xff, %g1
a00cd2bc:  80 a0 60 04  cmp  %g1, 4
a00cd2c0:  08 bf ff f7  bleu  0xa00cd29c
a00cd2c4:  d8 2b 7f f8  stb  %o4, [ %o5 + -8 ]
a00cd2c8:  15 00 01 a0  sethi  %hi(0x68000), %o2
a00cd2cc:  94 12 a0 07  or  %o2, 7, %o2	! 0x68007
a00cd2d0:  98 10 00 14  mov  %l4, %o4
a00cd2d4:  90 10 20 00  clr  %o0
a00cd2d8:  92 10 20 80  mov  0x80, %o1
a00cd2dc:  40 3b 24 3e  call  0xa0f963d4
a00cd2e0:  96 10 20 04  mov  4, %o3
a00cd2e4:  01 00 00 00  nop
a00cd2e8:  81 c7 e0 08  ret
a00cd2ec:  81 e8 00 00  restore
