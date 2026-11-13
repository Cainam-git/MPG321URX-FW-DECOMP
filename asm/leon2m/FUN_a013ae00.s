# leon2m FUN_a013ae00 0xa013ae00-0xa013b42c (1580 bytes)
a013ae00:  9d e3 bf 08  save  %sp, -248, %sp
a013ae04:  03 2a 00 a9  sethi  %hi(0xa802a400), %g1
a013ae08:  f0 28 60 60  stb  %i0, [ %g1 + 0x60 ]	! 0xa802a460
a013ae0c:  98 10 20 00  clr  %o4
a013ae10:  9a 10 20 00  clr  %o5
a013ae14:  ba 07 bf f8  add  %fp, -8, %i5
a013ae18:  96 03 40 0d  add  %o5, %o5, %o3
a013ae1c:  94 02 c0 0d  add  %o3, %o5, %o2
a013ae20:  93 2a a0 02  sll  %o2, 2, %o1
a013ae24:  98 03 20 01  inc  %o4
a013ae28:  90 02 40 1d  add  %o1, %i5, %o0
a013ae2c:  9a 0b 20 ff  and  %o4, 0xff, %o5
a013ae30:  80 a3 60 02  cmp  %o5, 2
a013ae34:  08 bf ff f9  bleu  0xa013ae18
a013ae38:  c0 22 3f 88  clr  [ %o0 + -120 ]
a013ae3c:  98 10 20 00  clr  %o4
a013ae40:  9a 10 20 00  clr  %o5
a013ae44:  a1 2b 60 02  sll  %o5, 2, %l0
a013ae48:  98 03 20 01  inc  %o4
a013ae4c:  9e 04 00 1d  add  %l0, %i5, %o7
a013ae50:  9a 0b 20 ff  and  %o4, 0xff, %o5
a013ae54:  80 a3 60 02  cmp  %o5, 2
a013ae58:  08 bf ff fb  bleu  0xa013ae44
a013ae5c:  c0 23 ff 88  clr  [ %o7 + -120 ]
a013ae60:  2b 2a 00 a9  sethi  %hi(0xa802a400), %l5
a013ae64:  1b 2a 00 a9  sethi  %hi(0xa802a400), %o5
a013ae68:  d8 4d 60 61  ldsb  [ %l5 + 0x61 ], %o4
a013ae6c:  d6 0b 60 62  ldub  [ %o5 + 0x62 ], %o3
a013ae70:  80 a3 20 00  cmp  %o4, 0
a013ae74:  06 80 01 5a  bl  0xa013b3dc
a013ae78:  da 0d 60 61  ldub  [ %l5 + 0x61 ], %o5
a013ae7c:  a6 0b 60 ff  and  %o5, 0xff, %l3
a013ae80:  a4 0a e0 ff  and  %o3, 0xff, %l2
a013ae84:  a2 5c 80 13  smul  %l2, %l3, %l1
a013ae88:  9b 34 60 07  srl  %l1, 7, %o5
a013ae8c:  1f 2a 00 b2  sethi  %hi(0xa802c800), %o7
a013ae90:  d6 0b e3 bd  ldub  [ %o7 + 0x3bd ], %o3	! 0xa802cbbd
a013ae94:  a0 02 e0 40  add  %o3, 0x40, %l0
a013ae98:  93 2b 60 10  sll  %o5, 0x10, %o1
a013ae9c:  98 0c 20 c0  and  %l0, 0xc0, %o4
a013aea0:  80 a3 20 40  cmp  %o4, 0x40
a013aea4:  97 32 60 0b  srl  %o1, 0xb, %o3
a013aea8:  02 80 01 29  be  0xa013b34c
a013aeac:  82 0c 20 3f  and  %l0, 0x3f, %g1
a013aeb0:  80 a3 20 40  cmp  %o4, 0x40
a013aeb4:  14 80 01 1c  bg  0xa013b324
a013aeb8:  80 a3 20 80  cmp  %o4, 0x80
a013aebc:  80 a3 20 00  cmp  %o4, 0
a013aec0:  22 80 01 25  be,a   0xa013b354
a013aec4:  82 08 60 ff  and  %g1, 0xff, %g1
a013aec8:  a6 08 60 ff  and  %g1, 0xff, %l3
a013aecc:  a4 10 20 40  mov  0x40, %l2
a013aed0:  82 24 80 13  sub  %l2, %l3, %g1
a013aed4:  11 00 06 95  sethi  %hi(0x1a5400), %o0
a013aed8:  ad 28 60 02  sll  %g1, 2, %l6
a013aedc:  ae 12 22 b4  or  %o0, 0x2b4, %l7
a013aee0:  e8 05 c0 16  ld  [ %l7 + %l6 ], %l4
a013aee4:  82 20 00 14  neg  %l4, %g1
a013aee8:  9a 5a c0 01  smul  %o3, %g1, %o5
a013aeec:  94 03 68 00  add  %o5, 0x800, %o2
a013aef0:  83 3a a0 0c  sra  %o2, 0xc, %g1
a013aef4:  e0 0b e3 bd  ldub  [ %o7 + 0x3bd ], %l0
a013aef8:  96 0c 20 c0  and  %l0, 0xc0, %o3
a013aefc:  c2 27 bf 90  st  %g1, [ %fp + -112 ]
a013af00:  80 a2 e0 40  cmp  %o3, 0x40
a013af04:  95 32 60 0b  srl  %o1, 0xb, %o2
a013af08:  02 80 01 21  be  0xa013b38c
a013af0c:  82 0c 20 3f  and  %l0, 0x3f, %g1
a013af10:  80 a2 e0 40  cmp  %o3, 0x40
a013af14:  14 80 01 00  bg  0xa013b314
a013af18:  80 a2 e0 80  cmp  %o3, 0x80
a013af1c:  80 a2 e0 00  cmp  %o3, 0
a013af20:  22 80 01 1d  be,a   0xa013b394
a013af24:  82 08 60 ff  and  %g1, 0xff, %g1
a013af28:  a6 08 60 ff  and  %g1, 0xff, %l3
a013af2c:  a4 10 20 40  mov  0x40, %l2
a013af30:  82 24 80 13  sub  %l2, %l3, %g1
a013af34:  ad 28 60 02  sll  %g1, 2, %l6
a013af38:  ae 12 22 b4  or  %o0, 0x2b4, %l7
a013af3c:  e8 05 c0 16  ld  [ %l7 + %l6 ], %l4
a013af40:  82 20 00 14  neg  %l4, %g1
a013af44:  9a 5a 80 01  smul  %o2, %g1, %o5
a013af48:  94 03 68 00  add  %o5, 0x800, %o2
a013af4c:  e0 0b e3 bd  ldub  [ %o7 + 0x3bd ], %l0
a013af50:  83 3a a0 0c  sra  %o2, 0xc, %g1
a013af54:  96 0c 20 c0  and  %l0, 0xc0, %o3
a013af58:  c2 27 bf 94  st  %g1, [ %fp + -108 ]
a013af5c:  80 a2 e0 40  cmp  %o3, 0x40
a013af60:  02 80 01 19  be  0xa013b3c4
a013af64:  82 0c 20 3f  and  %l0, 0x3f, %g1
a013af68:  80 a2 e0 40  cmp  %o3, 0x40
a013af6c:  14 80 00 e6  bg  0xa013b304
a013af70:  80 a2 e0 80  cmp  %o3, 0x80
a013af74:  80 a2 e0 00  cmp  %o3, 0
a013af78:  22 80 01 15  be,a   0xa013b3cc
a013af7c:  82 08 60 ff  and  %g1, 0xff, %g1
a013af80:  a6 08 60 ff  and  %g1, 0xff, %l3
a013af84:  a4 10 20 40  mov  0x40, %l2
a013af88:  82 24 80 13  sub  %l2, %l3, %g1
a013af8c:  ad 28 60 02  sll  %g1, 2, %l6
a013af90:  ae 12 22 b4  or  %o0, 0x2b4, %l7
a013af94:  e8 05 c0 16  ld  [ %l7 + %l6 ], %l4
a013af98:  82 20 00 14  neg  %l4, %g1
a013af9c:  98 20 00 01  neg  %g1, %o4
a013afa0:  97 32 60 0b  srl  %o1, 0xb, %o3
a013afa4:  94 5b 00 0b  smul  %o4, %o3, %o2
a013afa8:  da 0b e3 bd  ldub  [ %o7 + 0x3bd ], %o5
a013afac:  9e 03 60 40  add  %o5, 0x40, %o7
a013afb0:  82 02 a8 00  add  %o2, 0x800, %g1
a013afb4:  a1 38 60 0c  sra  %g1, 0xc, %l0
a013afb8:  96 0b e0 c0  and  %o7, 0xc0, %o3
a013afbc:  e0 27 bf 9c  st  %l0, [ %fp + -100 ]
a013afc0:  80 a2 e0 40  cmp  %o3, 0x40
a013afc4:  02 80 00 dc  be  0xa013b334
a013afc8:  82 0b e0 3f  and  %o7, 0x3f, %g1
a013afcc:  80 a2 e0 40  cmp  %o3, 0x40
a013afd0:  14 80 00 c9  bg  0xa013b2f4
a013afd4:  80 a2 e0 80  cmp  %o3, 0x80
a013afd8:  80 a2 e0 00  cmp  %o3, 0
a013afdc:  22 80 00 d8  be,a   0xa013b33c
a013afe0:  82 08 60 ff  and  %g1, 0xff, %g1
a013afe4:  a8 08 60 ff  and  %g1, 0xff, %l4
a013afe8:  a6 10 20 40  mov  0x40, %l3
a013afec:  82 24 c0 14  sub  %l3, %l4, %g1
a013aff0:  9e 12 22 b4  or  %o0, 0x2b4, %o7
a013aff4:  af 28 60 02  sll  %g1, 2, %l7
a013aff8:  ec 03 c0 17  ld  [ %o7 + %l7 ], %l6
a013affc:  98 20 00 16  neg  %l6, %o4
a013b000:  9b 32 60 0b  srl  %o1, 0xb, %o5
a013b004:  94 5b 00 0d  smul  %o4, %o5, %o2
a013b008:  82 02 a8 00  add  %o2, 0x800, %g1
a013b00c:  a1 38 60 0c  sra  %g1, 0xc, %l0
a013b010:  13 00 06 95  sethi  %hi(0x1a5400), %o1
a013b014:  e0 27 bf a0  st  %l0, [ %fp + -96 ]
a013b018:  90 12 62 90  or  %o1, 0x290, %o0
a013b01c:  a2 07 bf 80  add  %fp, -128, %l1
a013b020:  a6 07 bf a8  add  %fp, -88, %l3
a013b024:  a8 10 20 00  clr  %l4
a013b028:  9a 10 20 00  clr  %o5
a013b02c:  98 03 40 0d  add  %o5, %o5, %o4
a013b030:  a0 03 00 0d  add  %o4, %o5, %l0
a013b034:  a4 10 20 00  clr  %l2
a013b038:  9e 10 20 00  clr  %o7
a013b03c:  92 10 20 00  clr  %o1
a013b040:  94 10 20 00  clr  %o2
a013b044:  9a 10 20 00  clr  %o5
a013b048:  96 03 40 0d  add  %o5, %o5, %o3
a013b04c:  ae 02 c0 0d  add  %o3, %o5, %l7
a013b050:  98 05 c0 0f  add  %l7, %o7, %o4
a013b054:  ac 04 00 0d  add  %l0, %o5, %l6
a013b058:  9b 2d a0 02  sll  %l6, 2, %o5
a013b05c:  83 2b 20 02  sll  %o4, 2, %g1
a013b060:  ee 04 40 0d  ld  [ %l1 + %o5 ], %l7
a013b064:  d6 02 00 01  ld  [ %o0 + %g1 ], %o3
a013b068:  94 02 a0 01  inc  %o2
a013b06c:  ac 5d c0 0b  smul  %l7, %o3, %l6
a013b070:  9a 0a a0 ff  and  %o2, 0xff, %o5
a013b074:  80 a3 60 02  cmp  %o5, 2
a013b078:  08 bf ff f4  bleu  0xa013b048
a013b07c:  92 02 40 16  add  %o1, %l6, %o1
a013b080:  82 04 00 0f  add  %l0, %o7, %g1
a013b084:  9e 02 68 00  add  %o1, 0x800, %o7
a013b088:  95 3b e0 0c  sra  %o7, 0xc, %o2
a013b08c:  a4 04 a0 01  inc  %l2
a013b090:  93 28 60 02  sll  %g1, 2, %o1
a013b094:  9e 0c a0 ff  and  %l2, 0xff, %o7
a013b098:  80 a3 e0 02  cmp  %o7, 2
a013b09c:  08 bf ff e8  bleu  0xa013b03c
a013b0a0:  d4 24 c0 09  st  %o2, [ %l3 + %o1 ]
a013b0a4:  a8 05 20 01  inc  %l4
a013b0a8:  9a 0d 20 ff  and  %l4, 0xff, %o5
a013b0ac:  80 a3 60 02  cmp  %o5, 2
a013b0b0:  08 bf ff e0  bleu  0xa013b030
a013b0b4:  98 03 40 0d  add  %o5, %o5, %o4
a013b0b8:  e2 0d 60 61  ldub  [ %l5 + 0x61 ], %l1
a013b0bc:  2b 00 06 95  sethi  %hi(0x1a5400), %l5
a013b0c0:  92 15 62 90  or  %l5, 0x290, %o1	! 0x1a5690
a013b0c4:  95 2c 60 05  sll  %l1, 5, %o2
a013b0c8:  96 10 20 00  clr  %o3
a013b0cc:  98 10 20 00  clr  %o4
a013b0d0:  a9 2b 20 02  sll  %o4, 2, %l4
a013b0d4:  d8 02 40 14  ld  [ %o1 + %l4 ], %o4
a013b0d8:  9a 5b 00 0a  smul  %o4, %o2, %o5
a013b0dc:  a0 03 68 00  add  %o5, 0x800, %l0
a013b0e0:  96 02 e0 01  inc  %o3
a013b0e4:  a5 3c 20 0c  sra  %l0, 0xc, %l2
a013b0e8:  90 05 00 1d  add  %l4, %i5, %o0
a013b0ec:  98 0a e0 ff  and  %o3, 0xff, %o4
a013b0f0:  80 a3 20 02  cmp  %o4, 2
a013b0f4:  08 bf ff f7  bleu  0xa013b0d0
a013b0f8:  e4 22 3f b0  st  %l2, [ %o0 + -80 ]
a013b0fc:  2d 00 06 95  sethi  %hi(0x1a5400), %l6
a013b100:  a2 15 a2 6c  or  %l6, 0x26c, %l1	! 0x1a566c
a013b104:  a8 07 bf d0  add  %fp, -48, %l4
a013b108:  aa 10 20 00  clr  %l5
a013b10c:  9a 10 20 00  clr  %o5
a013b110:  ae 03 40 0d  add  %o5, %o5, %l7
a013b114:  a0 05 c0 0d  add  %l7, %o5, %l0
a013b118:  a4 10 20 00  clr  %l2
a013b11c:  9e 10 20 00  clr  %o7
a013b120:  92 10 20 00  clr  %o1
a013b124:  94 10 20 00  clr  %o2
a013b128:  9a 10 20 00  clr  %o5
a013b12c:  90 03 40 0d  add  %o5, %o5, %o0
a013b130:  82 02 00 0d  add  %o0, %o5, %g1
a013b134:  ac 00 40 0f  add  %g1, %o7, %l6
a013b138:  ae 04 00 0d  add  %l0, %o5, %l7
a013b13c:  9b 2d e0 02  sll  %l7, 2, %o5
a013b140:  99 2d a0 02  sll  %l6, 2, %o4
a013b144:  d0 04 40 0d  ld  [ %l1 + %o5 ], %o0
a013b148:  d6 04 c0 0c  ld  [ %l3 + %o4 ], %o3
a013b14c:  94 02 a0 01  inc  %o2
a013b150:  82 5a 00 0b  smul  %o0, %o3, %g1
a013b154:  9a 0a a0 ff  and  %o2, 0xff, %o5
a013b158:  80 a3 60 02  cmp  %o5, 2
a013b15c:  08 bf ff f4  bleu  0xa013b12c
a013b160:  92 02 40 01  add  %o1, %g1, %o1
a013b164:  96 04 00 0f  add  %l0, %o7, %o3
a013b168:  9e 02 68 00  add  %o1, 0x800, %o7
a013b16c:  95 3b e0 0c  sra  %o7, 0xc, %o2
a013b170:  a4 04 a0 01  inc  %l2
a013b174:  93 2a e0 02  sll  %o3, 2, %o1
a013b178:  9e 0c a0 ff  and  %l2, 0xff, %o7
a013b17c:  80 a3 e0 02  cmp  %o7, 2
a013b180:  08 bf ff e8  bleu  0xa013b120
a013b184:  d4 25 00 09  st  %o2, [ %l4 + %o1 ]
a013b188:  aa 05 60 01  inc  %l5
a013b18c:  9a 0d 60 ff  and  %l5, 0xff, %o5
a013b190:  80 a3 60 02  cmp  %o5, 2
a013b194:  08 bf ff e0  bleu  0xa013b114
a013b198:  ae 03 40 0d  add  %o5, %o5, %l7
a013b19c:  23 00 06 95  sethi  %hi(0x1a5400), %l1
a013b1a0:  27 00 06 69  sethi  %hi(0x19a400), %l3
a013b1a4:  b0 0e 20 ff  and  %i0, 0xff, %i0
a013b1a8:  ec 04 63 b8  ld  [ %l1 + 0x3b8 ], %l6
a013b1ac:  e8 1c e2 38  ldd  [ %l3 + 0x238 ], %l4
a013b1b0:  ae 10 20 00  clr  %l7
a013b1b4:  a0 10 20 00  clr  %l0
a013b1b8:  a4 04 00 10  add  %l0, %l0, %l2
a013b1bc:  40 00 6a a1  call  0xa0155c40
a013b1c0:  90 10 00 18  mov  %i0, %o0
a013b1c4:  a6 04 80 10  add  %l2, %l0, %l3
a013b1c8:  a4 10 00 08  mov  %o0, %l2
a013b1cc:  a2 10 20 00  clr  %l1
a013b1d0:  82 10 20 00  clr  %g1
a013b1d4:  9a 04 c0 01  add  %l3, %g1, %o5
a013b1d8:  99 2b 60 02  sll  %o5, 2, %o4
a013b1dc:  a0 03 00 1d  add  %o4, %i5, %l0
a013b1e0:  40 00 6a 98  call  0xa0155c40
a013b1e4:  d0 04 3f d8  ld  [ %l0 + -40 ], %o0
a013b1e8:  40 00 69 92  call  0xa0155830
a013b1ec:  92 10 00 12  mov  %l2, %o1
a013b1f0:  40 00 69 90  call  0xa0155830
a013b1f4:  92 10 00 16  mov  %l6, %o1
a013b1f8:  40 00 6a e6  call  0xa0155d90
a013b1fc:  a2 04 60 01  inc  %l1
a013b200:  94 10 00 14  mov  %l4, %o2
a013b204:  40 00 6b aa  call  0xa01560ac
a013b208:  96 10 00 15  mov  %l5, %o3
a013b20c:  40 00 6d ce  call  0xa0156944
a013b210:  01 00 00 00  nop
a013b214:  82 0c 60 ff  and  %l1, 0xff, %g1
a013b218:  80 a0 60 02  cmp  %g1, 2
a013b21c:  08 bf ff ee  bleu  0xa013b1d4
a013b220:  d0 24 3f d8  st  %o0, [ %l0 + -40 ]
a013b224:  ae 05 e0 01  inc  %l7
a013b228:  a0 0d e0 ff  and  %l7, 0xff, %l0
a013b22c:  80 a4 20 02  cmp  %l0, 2
a013b230:  28 bf ff e3  bleu,a   0xa013b1bc
a013b234:  a4 04 00 10  add  %l0, %l0, %l2
a013b238:  2b 2a 00 a9  sethi  %hi(0xa802a400), %l5
a013b23c:  31 00 00 3f  sethi  %hi(0xfc00), %i0
a013b240:  a6 15 60 6c  or  %l5, 0x6c, %l3
a013b244:  a0 16 23 ff  or  %i0, 0x3ff, %l0
a013b248:  a2 10 20 00  clr  %l1
a013b24c:  98 10 20 00  clr  %o4
a013b250:  25 00 00 3d  sethi  %hi(0xf400), %l2
a013b254:  a8 03 00 0c  add  %o4, %o4, %l4
a013b258:  ec 14 c0 14  lduh  [ %l3 + %l4 ], %l6
a013b25c:  9f 2d a0 04  sll  %l6, 4, %o7
a013b260:  91 2b 20 02  sll  %o4, 2, %o0
a013b264:  94 10 20 00  clr  %o2
a013b268:  96 10 20 00  clr  %o3
a013b26c:  10 80 00 05  b  0xa013b280
a013b270:  92 05 00 0c  add  %l4, %o4, %o1
a013b274:  80 a2 e0 02  cmp  %o3, 2
a013b278:  18 80 00 18  bgu  0xa013b2d8
a013b27c:  da 33 3f 70  sth  %o5, [ %o4 + -144 ]
a013b280:  9a 02 40 0b  add  %o1, %o3, %o5
a013b284:  af 2b 60 02  sll  %o5, 2, %l7
a013b288:  ac 05 c0 1d  add  %l7, %i5, %l6
a013b28c:  e8 05 bf d8  ld  [ %l6 + -40 ], %l4
a013b290:  aa 05 20 08  add  %l4, 8, %l5
a013b294:  98 02 00 0b  add  %o0, %o3, %o4
a013b298:  b1 3d 60 04  sra  %l5, 4, %i0
a013b29c:  96 5e 00 0f  smul  %i0, %o7, %o3
a013b2a0:  9a 02 e8 00  add  %o3, 0x800, %o5
a013b2a4:  82 03 00 0c  add  %o4, %o4, %g1
a013b2a8:  9b 3b 60 0c  sra  %o5, 0xc, %o5
a013b2ac:  94 02 a0 01  inc  %o2
a013b2b0:  98 00 40 1d  add  %g1, %i5, %o4
a013b2b4:  ae 1b 40 10  xor  %o5, %l0, %l7
a013b2b8:  96 0a a0 ff  and  %o2, 0xff, %o3
a013b2bc:  80 a3 60 00  cmp  %o5, 0
a013b2c0:  16 bf ff ed  bge  0xa013b274
a013b2c4:  82 05 e0 01  add  %l7, 1, %g1
a013b2c8:  9a 10 40 12  or  %g1, %l2, %o5
a013b2cc:  80 a2 e0 02  cmp  %o3, 2
a013b2d0:  08 bf ff ec  bleu  0xa013b280
a013b2d4:  da 33 3f 70  sth  %o5, [ %o4 + -144 ]
a013b2d8:  a2 04 60 01  inc  %l1
a013b2dc:  98 0c 60 ff  and  %l1, 0xff, %o4
a013b2e0:  80 a3 20 02  cmp  %o4, 2
a013b2e4:  08 bf ff dd  bleu  0xa013b258
a013b2e8:  a8 03 00 0c  add  %o4, %o4, %l4
a013b2ec:  10 80 00 46  b  0xa013b404
a013b2f0:  13 2a 00 b2  sethi  %hi(0xa802c800), %o1
a013b2f4:  12 bf ff 3d  bne  0xa013afe8
a013b2f8:  a8 08 60 ff  and  %g1, 0xff, %l4
a013b2fc:  10 bf ff 3d  b  0xa013aff0
a013b300:  82 08 60 ff  and  %g1, 0xff, %g1
a013b304:  12 bf ff 20  bne  0xa013af84
a013b308:  a6 08 60 ff  and  %g1, 0xff, %l3
a013b30c:  10 bf ff 20  b  0xa013af8c
a013b310:  82 08 60 ff  and  %g1, 0xff, %g1
a013b314:  12 bf ff 06  bne  0xa013af2c
a013b318:  a6 08 60 ff  and  %g1, 0xff, %l3
a013b31c:  10 bf ff 06  b  0xa013af34
a013b320:  82 08 60 ff  and  %g1, 0xff, %g1
a013b324:  12 bf fe ea  bne  0xa013aecc
a013b328:  a6 08 60 ff  and  %g1, 0xff, %l3
a013b32c:  10 bf fe ea  b  0xa013aed4
a013b330:  82 08 60 ff  and  %g1, 0xff, %g1
a013b334:  a2 08 60 ff  and  %g1, 0xff, %l1
a013b338:  82 22 c0 11  sub  %o3, %l1, %g1
a013b33c:  a4 12 22 b4  or  %o0, 0x2b4, %l2
a013b340:  91 28 60 02  sll  %g1, 2, %o0
a013b344:  10 bf ff 2f  b  0xa013b000
a013b348:  d8 04 80 08  ld  [ %l2 + %o0 ], %o4
a013b34c:  9a 08 60 ff  and  %g1, 0xff, %o5
a013b350:  82 23 00 0d  sub  %o4, %o5, %g1
a013b354:  11 00 06 95  sethi  %hi(0x1a5400), %o0
a013b358:  99 28 60 02  sll  %g1, 2, %o4
a013b35c:  a2 12 22 b4  or  %o0, 0x2b4, %l1
a013b360:  c2 04 40 0c  ld  [ %l1 + %o4 ], %g1
a013b364:  9a 5a c0 01  smul  %o3, %g1, %o5
a013b368:  94 03 68 00  add  %o5, 0x800, %o2
a013b36c:  83 3a a0 0c  sra  %o2, 0xc, %g1
a013b370:  e0 0b e3 bd  ldub  [ %o7 + 0x3bd ], %l0
a013b374:  96 0c 20 c0  and  %l0, 0xc0, %o3
a013b378:  c2 27 bf 90  st  %g1, [ %fp + -112 ]
a013b37c:  80 a2 e0 40  cmp  %o3, 0x40
a013b380:  95 32 60 0b  srl  %o1, 0xb, %o2
a013b384:  12 bf fe e4  bne  0xa013af14
a013b388:  82 0c 20 3f  and  %l0, 0x3f, %g1
a013b38c:  98 08 60 ff  and  %g1, 0xff, %o4
a013b390:  82 22 c0 0c  sub  %o3, %o4, %g1
a013b394:  97 28 60 02  sll  %g1, 2, %o3
a013b398:  a2 12 22 b4  or  %o0, 0x2b4, %l1
a013b39c:  c2 04 40 0b  ld  [ %l1 + %o3 ], %g1
a013b3a0:  9a 5a 80 01  smul  %o2, %g1, %o5
a013b3a4:  94 03 68 00  add  %o5, 0x800, %o2
a013b3a8:  e0 0b e3 bd  ldub  [ %o7 + 0x3bd ], %l0
a013b3ac:  83 3a a0 0c  sra  %o2, 0xc, %g1
a013b3b0:  96 0c 20 c0  and  %l0, 0xc0, %o3
a013b3b4:  c2 27 bf 94  st  %g1, [ %fp + -108 ]
a013b3b8:  80 a2 e0 40  cmp  %o3, 0x40
a013b3bc:  12 bf fe ec  bne  0xa013af6c
a013b3c0:  82 0c 20 3f  and  %l0, 0x3f, %g1
a013b3c4:  98 08 60 ff  and  %g1, 0xff, %o4
a013b3c8:  82 22 c0 0c  sub  %o3, %o4, %g1
a013b3cc:  97 28 60 02  sll  %g1, 2, %o3
a013b3d0:  a2 12 22 b4  or  %o0, 0x2b4, %l1
a013b3d4:  10 bf fe f2  b  0xa013af9c
a013b3d8:  c2 04 40 0b  ld  [ %l1 + %o3 ], %g1
a013b3dc:  9e 0b 60 ff  and  %o5, 0xff, %o7
a013b3e0:  94 10 21 00  mov  0x100, %o2
a013b3e4:  92 22 80 0f  sub  %o2, %o7, %o1
a013b3e8:  90 0a e0 ff  and  %o3, 0xff, %o0
a013b3ec:  ac 5a 00 09  smul  %o0, %o1, %l6
a013b3f0:  83 3d a0 1f  sra  %l6, 0x1f, %g1
a013b3f4:  af 30 60 19  srl  %g1, 0x19, %l7
a013b3f8:  a8 05 80 17  add  %l6, %l7, %l4
a013b3fc:  10 bf fe a4  b  0xa013ae8c
a013b400:  9b 35 20 07  srl  %l4, 7, %o5
a013b404:  d0 0a 63 bc  ldub  [ %o1 + 0x3bc ], %o0
a013b408:  bb 32 20 01  srl  %o0, 1, %i5
a013b40c:  90 0a 20 01  and  %o0, 1, %o0
a013b410:  92 0f 60 01  and  %i5, 1, %o1
a013b414:  94 07 bf 68  add  %fp, -152, %o2
a013b418:  7f fe ee f3  call  0xa00f6fe4
a013b41c:  96 10 20 07  mov  7, %o3
a013b420:  01 00 00 00  nop
a013b424:  81 c7 e0 08  ret
a013b428:  81 e8 00 00  restore
