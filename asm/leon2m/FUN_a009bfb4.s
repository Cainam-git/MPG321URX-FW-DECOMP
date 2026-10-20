# leon2m FUN_a009bfb4 0xa009bfb4-0xa009c22c (632 bytes)  [FUN_a009c224 = unreachable ret/restore tail, merged]
a009bfb4:  9d e3 bf 98  save  %sp, -104, %sp
a009bfb8:  35 2a 00 ab  sethi  %hi(0xa802ac00), %i2
a009bfbc:  da 06 a3 ec  ld  [ %i2 + 0x3ec ], %o5	! 0xa802afec
a009bfc0:  33 09 24 92  sethi  %hi(0x24924800), %i1
a009bfc4:  92 03 7f a4  add  %o5, -92, %o1
a009bfc8:  b0 16 61 25  or  %i1, 0x125, %i0
a009bfcc:  80 52 40 18  umul  %o1, %i0, %g0
a009bfd0:  99 40 00 00  rd  %y, %o4
a009bfd4:  a0 22 40 0c  sub  %o1, %o4, %l0
a009bfd8:  9f 34 20 01  srl  %l0, 1, %o7
a009bfdc:  96 03 00 0f  add  %o4, %o7, %o3
a009bfe0:  9b 32 e0 02  srl  %o3, 2, %o5
a009bfe4:  95 2b 60 03  sll  %o5, 3, %o2
a009bfe8:  82 22 80 0d  sub  %o2, %o5, %g1
a009bfec:  90 22 40 01  sub  %o1, %g1, %o0
a009bff0:  90 0a 20 ff  and  %o0, 0xff, %o0
a009bff4:  40 00 34 f2  call  0xa00a93bc
a009bff8:  b0 10 00 0d  mov  %o5, %i0
a009bffc:  e0 16 a3 ee  lduh  [ %i2 + 0x3ee ], %l0
a009c000:  94 04 3f ab  add  %l0, -85, %o2
a009c004:  9f 3a a0 1f  sra  %o2, 0x1f, %o7
a009c008:  99 33 e0 1d  srl  %o7, 0x1d, %o4
a009c00c:  96 02 80 0c  add  %o2, %o4, %o3
a009c010:  82 0a ff f8  and  %o3, -8, %g1
a009c014:  90 22 80 01  sub  %o2, %g1, %o0
a009c018:  92 02 20 5c  add  %o0, 0x5c, %o1
a009c01c:  d2 26 a3 ec  st  %o1, [ %i2 + 0x3ec ]
a009c020:  40 00 3b 44  call  0xa00aad30
a009c024:  90 0a 20 ff  and  %o0, 0xff, %o0
a009c028:  a0 0a 20 ff  and  %o0, 0xff, %l0
a009c02c:  80 a4 20 01  cmp  %l0, 1
a009c030:  32 bf ff f4  bne,a   0xa009c000
a009c034:  e0 16 a3 ee  lduh  [ %i2 + 0x3ee ], %l0
a009c038:  f2 06 a3 ec  ld  [ %i2 + 0x3ec ], %i1
a009c03c:  96 06 7f a4  add  %i1, -92, %o3
a009c040:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a009c044:  b2 12 a2 90  or  %o2, 0x290, %i1	! 0xa802d290
a009c048:  90 0a e0 ff  and  %o3, 0xff, %o0
a009c04c:  40 00 6a cf  call  0xa00b6b88
a009c050:  92 10 20 01  mov  1, %o1
a009c054:  da 06 a3 ec  ld  [ %i2 + 0x3ec ], %o5
a009c058:  13 09 24 92  sethi  %hi(0x24924800), %o1
a009c05c:  98 03 7f a4  add  %o5, -92, %o4
a009c060:  96 10 00 08  mov  %o0, %o3
a009c064:  9e 12 61 25  or  %o1, 0x125, %o7
a009c068:  80 53 00 0f  umul  %o4, %o7, %g0
a009c06c:  91 40 00 00  rd  %y, %o0
a009c070:  82 23 00 08  sub  %o4, %o0, %g1
a009c074:  95 30 60 01  srl  %g1, 1, %o2
a009c078:  9a 02 00 0a  add  %o0, %o2, %o5
a009c07c:  92 0e 20 ff  and  %i0, 0xff, %o1
a009c080:  91 33 60 02  srl  %o5, 2, %o0
a009c084:  80 a2 40 08  cmp  %o1, %o0
a009c088:  02 80 00 05  be  0xa009c09c
a009c08c:  d6 2e 61 81  stb  %o3, [ %i1 + 0x181 ]
a009c090:  40 00 6a d7  call  0xa00b6bec
a009c094:  90 0a 20 ff  and  %o0, 0xff, %o0
a009c098:  d6 0e 61 81  ldub  [ %i1 + 0x181 ], %o3
a009c09c:  90 02 ff fc  add  %o3, -4, %o0
a009c0a0:  b0 0a 20 ff  and  %o0, 0xff, %i0
a009c0a4:  80 a6 20 02  cmp  %i0, 2
a009c0a8:  18 80 00 34  bgu  0xa009c178
a009c0ac:  19 2a 00 97  sethi  %hi(0xa8025c00), %o4
a009c0b0:  c2 0e 60 11  ldub  [ %i1 + 0x11 ], %g1
a009c0b4:  80 a0 60 01  cmp  %g1, 1
a009c0b8:  32 80 00 02  bne,a   0xa009c0c0
a009c0bc:  e0 2e 60 11  stb  %l0, [ %i1 + 0x11 ]
a009c0c0:  40 00 fd 9e  call  0xa00db738
a009c0c4:  01 00 00 00  nop
a009c0c8:  90 10 20 02  mov  2, %o0	! 0x2
a009c0cc:  40 00 3a fa  call  0xa00aacb4
a009c0d0:  92 10 20 01  mov  1, %o1
a009c0d4:  f0 06 a3 ec  ld  [ %i2 + 0x3ec ], %i0
a009c0d8:  94 06 3f a4  add  %i0, -92, %o2
a009c0dc:  17 09 24 92  sethi  %hi(0x24924800), %o3
a009c0e0:  b0 12 e1 25  or  %o3, 0x125, %i0	! 0x24924925
a009c0e4:  80 52 80 18  umul  %o2, %i0, %g0
a009c0e8:  a1 40 00 00  rd  %y, %l0
a009c0ec:  9a 22 80 10  sub  %o2, %l0, %o5
a009c0f0:  93 33 60 01  srl  %o5, 1, %o1
a009c0f4:  9e 04 00 09  add  %l0, %o1, %o7
a009c0f8:  83 33 e0 02  srl  %o7, 2, %g1
a009c0fc:  b3 28 60 03  sll  %g1, 3, %i1
a009c100:  98 26 40 01  sub  %i1, %g1, %o4
a009c104:  96 22 80 0c  sub  %o2, %o4, %o3
a009c108:  90 0a e0 ff  and  %o3, 0xff, %o0
a009c10c:  40 00 35 51  call  0xa00a9650
a009c110:  92 10 20 01  mov  1, %o1
a009c114:  da 06 a3 ec  ld  [ %i2 + 0x3ec ], %o5
a009c118:  92 03 7f a4  add  %o5, -92, %o1
a009c11c:  80 52 40 18  umul  %o1, %i0, %g0
a009c120:  b3 40 00 00  rd  %y, %i1
a009c124:  a0 22 40 19  sub  %o1, %i1, %l0
a009c128:  9f 34 20 01  srl  %l0, 1, %o7
a009c12c:  98 06 40 0f  add  %i1, %o7, %o4
a009c130:  33 2a 00 97  sethi  %hi(0xa8025c00), %i1
a009c134:  a1 33 20 02  srl  %o4, 2, %l0
a009c138:  92 10 20 00  clr  %o1
a009c13c:  40 00 6a 93  call  0xa00b6b88
a009c140:  d0 0e 60 56  ldub  [ %i1 + 0x56 ], %o0
a009c144:  82 0a 20 ff  and  %o0, 0xff, %g1
a009c148:  80 50 40 18  umul  %g1, %i0, %g0
a009c14c:  97 40 00 00  rd  %y, %o3
a009c150:  90 20 40 0b  sub  %g1, %o3, %o0
a009c154:  95 32 20 01  srl  %o0, 1, %o2
a009c158:  9a 02 c0 0a  add  %o3, %o2, %o5
a009c15c:  93 33 60 02  srl  %o5, 2, %o1
a009c160:  9e 0a 60 ff  and  %o1, 0xff, %o7
a009c164:  80 a4 00 0f  cmp  %l0, %o7
a009c168:  12 80 00 2e  bne  0xa009c220
a009c16c:  d0 06 a3 ec  ld  [ %i2 + 0x3ec ], %o0
a009c170:  10 80 00 05  b  0xa009c184
a009c174:  a0 02 3f a4  add  %o0, -92, %l0
a009c178:  e0 0b 20 54  ldub  [ %o4 + 0x54 ], %l0
a009c17c:  10 bf ff d1  b  0xa009c0c0
a009c180:  e0 2e 60 11  stb  %l0, [ %i1 + 0x11 ]
a009c184:  d0 0e 60 56  ldub  [ %i1 + 0x56 ], %o0
a009c188:  40 00 6a 80  call  0xa00b6b88
a009c18c:  92 10 20 00  clr  %o1
a009c190:  b4 0a 20 ff  and  %o0, 0xff, %i2
a009c194:  80 a4 00 1a  cmp  %l0, %i2
a009c198:  02 80 00 12  be  0xa009c1e0
a009c19c:  d0 0e 60 56  ldub  [ %i1 + 0x56 ], %o0
a009c1a0:  40 00 6a 7a  call  0xa00b6b88
a009c1a4:  92 10 20 00  clr  %o1
a009c1a8:  a0 0a 20 ff  and  %o0, 0xff, %l0
a009c1ac:  80 54 00 18  umul  %l0, %i0, %g0
a009c1b0:  83 40 00 00  rd  %y, %g1
a009c1b4:  96 24 00 01  sub  %l0, %g1, %o3
a009c1b8:  93 32 e0 01  srl  %o3, 1, %o1
a009c1bc:  9e 00 40 09  add  %g1, %o1, %o7
a009c1c0:  b3 33 e0 02  srl  %o7, 2, %i1
a009c1c4:  99 2e 60 03  sll  %i1, 3, %o4
a009c1c8:  94 23 00 19  sub  %o4, %i1, %o2
a009c1cc:  b4 24 00 0a  sub  %l0, %o2, %i2
a009c1d0:  b2 0e a0 ff  and  %i2, 0xff, %i1
a009c1d4:  b0 10 20 01  mov  1, %i0
a009c1d8:  40 00 2f d9  call  0xa00a813c
a009c1dc:  95 e8 20 01  restore  %g0, 1, %o2
a009c1e0:  40 00 6a 6a  call  0xa00b6b88
a009c1e4:  92 10 20 00  clr  %o1
a009c1e8:  98 0a 20 ff  and  %o0, 0xff, %o4
a009c1ec:  80 53 00 18  umul  %o4, %i0, %g0
a009c1f0:  97 40 00 00  rd  %y, %o3
a009c1f4:  b0 23 00 0b  sub  %o4, %o3, %i0
a009c1f8:  9b 36 20 01  srl  %i0, 1, %o5
a009c1fc:  92 02 c0 0d  add  %o3, %o5, %o1
a009c200:  83 32 60 02  srl  %o1, 2, %g1
a009c204:  9f 28 60 03  sll  %g1, 3, %o7
a009c208:  b2 23 c0 01  sub  %o7, %g1, %i1
a009c20c:  94 23 00 19  sub  %o4, %i1, %o2
a009c210:  b2 0a a0 ff  and  %o2, 0xff, %i1
a009c214:  b0 10 20 01  mov  1, %i0
a009c218:  40 00 2f c9  call  0xa00a813c
a009c21c:  95 e8 20 00  restore  %g0, 0, %o2
a009c220:  01 00 00 00  nop
a009c224:  81 c7 e0 08  ret
a009c228:  81 e8 00 00  restore
