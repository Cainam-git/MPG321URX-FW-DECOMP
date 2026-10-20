# leon2s FUN_a00dcdb8 0xa00dcdb8-0xa00dd154 (924 bytes)
a00dcdb8:  9d e3 bf 98  save  %sp, -104, %sp
a00dcdbc:  23 2a 01 e5  sethi  %hi(0xa8079400), %l1
a00dcdc0:  82 14 61 38  or  %l1, 0x138, %g1	! 0xa8079538
a00dcdc4:  d6 08 60 07  ldub  [ %g1 + 7 ], %o3
a00dcdc8:  80 a0 00 0b  cmp  %g0, %o3
a00dcdcc:  98 60 3f ff  subx  %g0, -1, %o4
a00dcdd0:  82 1a e0 03  xor  %o3, 3, %g1
a00dcdd4:  80 a0 00 01  cmp  %g0, %g1
a00dcdd8:  03 30 04 40  sethi  %hi(0xc0110000), %g1
a00dcddc:  82 10 60 04  or  %g1, 4, %g1	! 0xc0110004
a00dcde0:  da 00 40 00  ld  [ %g1 ], %o5
a00dcde4:  82 60 3f ff  subx  %g0, -1, %g1
a00dcde8:  9b 33 60 10  srl  %o5, 0x10, %o5
a00dcdec:  80 93 00 01  orcc  %o4, %g1, %g0
a00dcdf0:  82 0b 63 ff  and  %o5, 0x3ff, %g1
a00dcdf4:  a4 10 20 00  clr  %l2
a00dcdf8:  12 80 00 05  bne  0xa00dce0c
a00dcdfc:  a6 10 20 01  mov  1, %l3
a00dce00:  80 a2 e0 04  cmp  %o3, 4
a00dce04:  12 80 00 0c  bne  0xa00dce34
a00dce08:  80 a2 e0 01  cmp  %o3, 1
a00dce0c:  9b 30 60 04  srl  %g1, 4, %o5
a00dce10:  82 10 20 18  mov  0x18, %g1
a00dce14:  93 38 60 1f  sra  %g1, 0x1f, %o1
a00dce18:  81 82 60 00  mov  %o1, %y
a00dce1c:  01 00 00 00  nop
a00dce20:  01 00 00 00  nop
a00dce24:  01 00 00 00  nop
a00dce28:  a8 78 40 0d  sdiv  %g1, %o5, %l4
a00dce2c:  10 80 00 1c  b  0xa00dce9c
a00dce30:  9a 0e 20 ff  and  %i0, 0xff, %o5
a00dce34:  12 80 00 0c  bne  0xa00dce64
a00dce38:  83 28 60 10  sll  %g1, 0x10, %g1
a00dce3c:  83 30 60 15  srl  %g1, 0x15, %g1
a00dce40:  9a 10 20 10  mov  0x10, %o5
a00dce44:  95 3b 60 1f  sra  %o5, 0x1f, %o2
a00dce48:  81 82 a0 00  mov  %o2, %y
a00dce4c:  01 00 00 00  nop
a00dce50:  01 00 00 00  nop
a00dce54:  01 00 00 00  nop
a00dce58:  98 7b 40 01  sdiv  %o5, %g1, %o4
a00dce5c:  10 80 00 0b  b  0xa00dce88
a00dce60:  82 5b 00 01  smul  %o4, %g1, %g1
a00dce64:  83 30 60 15  srl  %g1, 0x15, %g1
a00dce68:  9a 10 20 0c  mov  0xc, %o5
a00dce6c:  97 3b 60 1f  sra  %o5, 0x1f, %o3
a00dce70:  81 82 e0 00  mov  %o3, %y
a00dce74:  01 00 00 00  nop
a00dce78:  01 00 00 00  nop
a00dce7c:  01 00 00 00  nop
a00dce80:  98 7b 40 01  sdiv  %o5, %g1, %o4
a00dce84:  82 5b 00 01  smul  %o4, %g1, %g1
a00dce88:  80 a3 40 01  cmp  %o5, %g1
a00dce8c:  02 80 00 03  be  0xa00dce98
a00dce90:  a8 10 00 0c  mov  %o4, %l4
a00dce94:  a8 03 20 01  add  %o4, 1, %l4
a00dce98:  9a 0e 20 ff  and  %i0, 0xff, %o5
a00dce9c:  03 30 04 60  sethi  %hi(0xc0118000), %g1
a00dcea0:  c0 20 40 00  clr  [ %g1 ]
a00dcea4:  80 a3 60 01  cmp  %o5, 1
a00dcea8:  18 80 00 05  bgu  0xa00dcebc
a00dceac:  b0 10 20 04  mov  4, %i0
a00dceb0:  a4 10 20 02  mov  2, %l2
a00dceb4:  10 80 00 26  b  0xa00dcf4c
a00dceb8:  a6 10 20 01  mov  1, %l3
a00dcebc:  92 10 20 03  mov  3, %o1
a00dcec0:  40 3b 6a 7d  call  0xa0fb78b4
a00dcec4:  90 10 20 00  clr  %o0
a00dcec8:  a0 0a 20 0f  and  %o0, 0xf, %l0
a00dcecc:  40 3a f3 e0  call  0xa0f99e4c
a00dced0:  90 10 20 00  clr  %o0
a00dced4:  90 0a 20 ff  and  %o0, 0xff, %o0
a00dced8:  80 a2 20 01  cmp  %o0, 1
a00dcedc:  b0 10 20 03  mov  3, %i0
a00dcee0:  12 80 00 07  bne  0xa00dcefc
a00dcee4:  82 0c 20 ff  and  %l0, 0xff, %g1
a00dcee8:  80 a0 60 04  cmp  %g1, 4
a00dceec:  12 80 00 14  bne  0xa00dcf3c
a00dcef0:  83 28 60 04  sll  %g1, 4, %g1
a00dcef4:  10 80 00 06  b  0xa00dcf0c
a00dcef8:  a4 10 20 04  mov  4, %l2
a00dcefc:  80 a0 60 04  cmp  %g1, 4
a00dcf00:  12 80 00 05  bne  0xa00dcf14
a00dcf04:  80 a0 60 02  cmp  %g1, 2
a00dcf08:  a4 10 20 02  mov  2, %l2
a00dcf0c:  10 80 00 0a  b  0xa00dcf34
a00dcf10:  a6 10 20 01  mov  1, %l3
a00dcf14:  12 80 00 04  bne  0xa00dcf24
a00dcf18:  80 a0 60 01  cmp  %g1, 1
a00dcf1c:  10 80 00 05  b  0xa00dcf30
a00dcf20:  a4 10 20 04  mov  4, %l2
a00dcf24:  12 80 00 05  bne  0xa00dcf38
a00dcf28:  82 0c 20 ff  and  %l0, 0xff, %g1
a00dcf2c:  a4 10 20 02  mov  2, %l2
a00dcf30:  a6 10 20 03  mov  3, %l3
a00dcf34:  82 0c 20 ff  and  %l0, 0xff, %g1
a00dcf38:  83 28 60 04  sll  %g1, 4, %g1
a00dcf3c:  82 10 40 08  or  %g1, %o0, %g1
a00dcf40:  82 10 61 00  or  %g1, 0x100, %g1
a00dcf44:  1b 30 04 60  sethi  %hi(0xc0118000), %o5
a00dcf48:  c2 23 40 00  st  %g1, [ %o5 ]
a00dcf4c:  a2 14 61 38  or  %l1, 0x138, %l1
a00dcf50:  11 30 04 82  sethi  %hi(0xc0120800), %o0
a00dcf54:  e0 14 60 08  lduh  [ %l1 + 8 ], %l0
a00dcf58:  03 04 80 00  sethi  %hi(0x12000000), %g1
a00dcf5c:  9a 12 21 14  or  %o0, 0x114, %o5
a00dcf60:  a1 2c 20 10  sll  %l0, 0x10, %l0
a00dcf64:  82 10 62 10  or  %g1, 0x210, %g1
a00dcf68:  c2 23 40 00  st  %g1, [ %o5 ]
a00dcf6c:  a8 0d 20 ff  and  %l4, 0xff, %l4
a00dcf70:  99 34 20 10  srl  %l0, 0x10, %o4
a00dcf74:  9b 3b 20 1f  sra  %o4, 0x1f, %o5
a00dcf78:  81 83 60 00  mov  %o5, %y
a00dcf7c:  01 00 00 00  nop
a00dcf80:  01 00 00 00  nop
a00dcf84:  01 00 00 00  nop
a00dcf88:  98 7b 00 14  sdiv  %o4, %l4, %o4
a00dcf8c:  03 3f ff c0  sethi  %hi(0xffff0000), %g1
a00dcf90:  9a 12 21 18  or  %o0, 0x118, %o5
a00dcf94:  c2 23 40 00  st  %g1, [ %o5 ]
a00dcf98:  92 12 21 1c  or  %o0, 0x11c, %o1
a00dcf9c:  a4 0c a0 ff  and  %l2, 0xff, %l2
a00dcfa0:  17 00 00 3f  sethi  %hi(0xfc00), %o3
a00dcfa4:  da 02 40 00  ld  [ %o1 ], %o5
a00dcfa8:  a6 0c e0 ff  and  %l3, 0xff, %l3
a00dcfac:  96 12 e3 ff  or  %o3, 0x3ff, %o3
a00dcfb0:  83 3b 20 1f  sra  %o4, 0x1f, %g1
a00dcfb4:  81 80 60 00  mov  %g1, %y
a00dcfb8:  01 00 00 00  nop
a00dcfbc:  01 00 00 00  nop
a00dcfc0:  01 00 00 00  nop
a00dcfc4:  98 7b 00 12  sdiv  %o4, %l2, %o4
a00dcfc8:  9a 0b 40 0b  and  %o5, %o3, %o5
a00dcfcc:  de 14 60 0c  lduh  [ %l1 + 0xc ], %o7
a00dcfd0:  98 5b 00 13  smul  %o4, %l3, %o4
a00dcfd4:  da 22 40 00  st  %o5, [ %o1 ]
a00dcfd8:  83 3b e0 1f  sra  %o7, 0x1f, %g1
a00dcfdc:  81 80 60 00  mov  %g1, %y
a00dcfe0:  01 00 00 00  nop
a00dcfe4:  01 00 00 00  nop
a00dcfe8:  01 00 00 00  nop
a00dcfec:  94 7b c0 14  sdiv  %o7, %l4, %o2
a00dcff0:  99 2b 20 10  sll  %o4, 0x10, %o4
a00dcff4:  98 13 00 0b  or  %o4, %o3, %o4
a00dcff8:  9b 3a a0 1f  sra  %o2, 0x1f, %o5
a00dcffc:  81 83 60 00  mov  %o5, %y
a00dd000:  01 00 00 00  nop
a00dd004:  01 00 00 00  nop
a00dd008:  01 00 00 00  nop
a00dd00c:  94 7a 80 12  sdiv  %o2, %l2, %o2
a00dd010:  c2 14 60 0e  lduh  [ %l1 + 0xe ], %g1
a00dd014:  d8 22 40 00  st  %o4, [ %o1 ]
a00dd018:  da 14 60 14  lduh  [ %l1 + 0x14 ], %o5
a00dd01c:  82 00 40 0f  add  %g1, %o7, %g1
a00dd020:  d6 14 60 16  lduh  [ %l1 + 0x16 ], %o3
a00dd024:  93 38 60 1f  sra  %g1, 0x1f, %o1
a00dd028:  81 82 60 00  mov  %o1, %y
a00dd02c:  01 00 00 00  nop
a00dd030:  01 00 00 00  nop
a00dd034:  01 00 00 00  nop
a00dd038:  82 78 40 14  sdiv  %g1, %l4, %g1
a00dd03c:  96 02 c0 0d  add  %o3, %o5, %o3
a00dd040:  98 12 21 20  or  %o0, 0x120, %o4
a00dd044:  93 38 60 1f  sra  %g1, 0x1f, %o1
a00dd048:  81 82 60 00  mov  %o1, %y
a00dd04c:  01 00 00 00  nop
a00dd050:  01 00 00 00  nop
a00dd054:  01 00 00 00  nop
a00dd058:  82 78 40 12  sdiv  %g1, %l2, %g1
a00dd05c:  94 5a 80 13  smul  %o2, %l3, %o2
a00dd060:  9b 2b 60 10  sll  %o5, 0x10, %o5
a00dd064:  d2 03 00 00  ld  [ %o4 ], %o1
a00dd068:  9b 33 60 10  srl  %o5, 0x10, %o5
a00dd06c:  95 2a a0 10  sll  %o2, 0x10, %o2
a00dd070:  c0 23 00 00  clr  [ %o4 ]
a00dd074:  94 12 80 0d  or  %o2, %o5, %o2
a00dd078:  97 2a e0 10  sll  %o3, 0x10, %o3
a00dd07c:  d4 23 00 00  st  %o2, [ %o4 ]
a00dd080:  92 0e 20 ff  and  %i0, 0xff, %o1
a00dd084:  82 58 40 13  smul  %g1, %l3, %g1
a00dd088:  97 32 e0 10  srl  %o3, 0x10, %o3
a00dd08c:  da 14 60 0a  lduh  [ %l1 + 0xa ], %o5
a00dd090:  98 12 21 24  or  %o0, 0x124, %o4
a00dd094:  95 3b 60 1f  sra  %o5, 0x1f, %o2
a00dd098:  81 82 a0 00  mov  %o2, %y
a00dd09c:  01 00 00 00  nop
a00dd0a0:  01 00 00 00  nop
a00dd0a4:  01 00 00 00  nop
a00dd0a8:  9a 7b 40 14  sdiv  %o5, %l4, %o5
a00dd0ac:  96 02 c0 09  add  %o3, %o1, %o3
a00dd0b0:  83 28 60 10  sll  %g1, 0x10, %g1
a00dd0b4:  d4 03 00 00  ld  [ %o4 ], %o2
a00dd0b8:  83 30 60 10  srl  %g1, 0x10, %g1
a00dd0bc:  97 2a e0 10  sll  %o3, 0x10, %o3
a00dd0c0:  c0 23 00 00  clr  [ %o4 ]
a00dd0c4:  82 10 40 0b  or  %g1, %o3, %g1
a00dd0c8:  c2 23 00 00  st  %g1, [ %o4 ]
a00dd0cc:  93 3b 60 1f  sra  %o5, 0x1f, %o1
a00dd0d0:  81 82 60 00  mov  %o1, %y
a00dd0d4:  01 00 00 00  nop
a00dd0d8:  01 00 00 00  nop
a00dd0dc:  01 00 00 00  nop
a00dd0e0:  9a 7b 40 12  sdiv  %o5, %l2, %o5
a00dd0e4:  98 12 21 28  or  %o0, 0x128, %o4
a00dd0e8:  9a 5b 40 13  smul  %o5, %l3, %o5
a00dd0ec:  c2 03 00 00  ld  [ %o4 ], %g1
a00dd0f0:  9b 2b 60 10  sll  %o5, 0x10, %o5
a00dd0f4:  83 33 60 10  srl  %o5, 0x10, %g1
a00dd0f8:  c0 23 00 00  clr  [ %o4 ]
a00dd0fc:  82 10 40 0d  or  %g1, %o5, %g1
a00dd100:  c2 23 00 00  st  %g1, [ %o4 ]
a00dd104:  9a 12 21 2c  or  %o0, 0x12c, %o5
a00dd108:  c2 14 60 12  lduh  [ %l1 + 0x12 ], %g1
a00dd10c:  d8 03 40 00  ld  [ %o5 ], %o4
a00dd110:  83 28 60 10  sll  %g1, 0x10, %g1
a00dd114:  c0 23 40 00  clr  [ %o5 ]
a00dd118:  83 30 60 10  srl  %g1, 0x10, %g1
a00dd11c:  a1 34 20 12  srl  %l0, 0x12, %l0
a00dd120:  c2 23 40 00  st  %g1, [ %o5 ]
a00dd124:  a1 2c 20 10  sll  %l0, 0x10, %l0
a00dd128:  82 12 21 48  or  %o0, 0x148, %g1
a00dd12c:  9b 34 20 10  srl  %l0, 0x10, %o5
a00dd130:  da 20 40 00  st  %o5, [ %g1 ]
a00dd134:  90 12 21 78  or  %o0, 0x178, %o0
a00dd138:  03 30 04 88  sethi  %hi(0xc0122000), %g1
a00dd13c:  c0 22 00 00  clr  [ %o0 ]
a00dd140:  a1 34 20 11  srl  %l0, 0x11, %l0
a00dd144:  82 10 60 10  or  %g1, 0x10, %g1
a00dd148:  e0 20 40 00  st  %l0, [ %g1 ]
a00dd14c:  81 c7 e0 08  ret
a00dd150:  81 e8 00 00  restore
