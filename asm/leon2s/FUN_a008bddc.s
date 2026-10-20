# leon2s FUN_a008bddc 0xa008bddc-0xa008c530 (1876 bytes)
a008bddc:  9d e3 bf 98  save  %sp, -104, %sp
a008bde0:  a0 0e 20 ff  and  %i0, 0xff, %l0
a008bde4:  82 04 3f fe  add  %l0, -2, %g1
a008bde8:  80 a0 60 11  cmp  %g1, 0x11
a008bdec:  18 80 00 1c  bgu  0xa008be5c
a008bdf0:  b0 10 00 19  mov  %i1, %i0
a008bdf4:  1b 28 02 2f  sethi  %hi(0xa008bc00), %o5
a008bdf8:  83 28 60 02  sll  %g1, 2, %g1
a008bdfc:  9a 13 61 94  or  %o5, 0x194, %o5
a008be00:  c2 03 40 01  ld  [ %o5 + %g1 ], %g1
a008be04:  81 c0 40 00  jmp  %g1
a008be08:  01 00 00 00  nop
a008be0c:  03 2a 01 d9  sethi  %hi(0xa8076400), %g1
a008be10:  c2 08 62 89  ldub  [ %g1 + 0x289 ], %g1	! 0xa8076689
a008be14:  83 30 60 06  srl  %g1, 6, %g1
a008be18:  80 a0 60 01  cmp  %g1, 1
a008be1c:  02 80 00 06  be  0xa008be34
a008be20:  80 a0 60 02  cmp  %g1, 2
a008be24:  12 80 00 08  bne  0xa008be44
a008be28:  90 0e 60 ff  and  %i1, 0xff, %o0
a008be2c:  10 80 00 0a  b  0xa008be54
a008be30:  92 10 20 00  clr  %o1
a008be34:  90 0e 60 ff  and  %i1, 0xff, %o0
a008be38:  10 80 00 07  b  0xa008be54
a008be3c:  92 10 20 02  mov  2, %o1
a008be40:  90 0e 60 ff  and  %i1, 0xff, %o0
a008be44:  10 80 00 04  b  0xa008be54
a008be48:  92 10 20 01  mov  1, %o1
a008be4c:  90 0e 60 ff  and  %i1, 0xff, %o0
a008be50:  92 10 20 03  mov  3, %o1
a008be54:  7f ff ff b2  call  0xa008bd1c
a008be58:  01 00 00 00  nop
a008be5c:  b0 0e 20 ff  and  %i0, 0xff, %i0
a008be60:  90 10 00 18  mov  %i0, %o0
a008be64:  92 10 20 02  mov  2, %o1
a008be68:  94 10 20 2c  mov  0x2c, %o2
a008be6c:  40 00 6c e4  call  0xa00a71fc
a008be70:  96 10 20 00  clr  %o3
a008be74:  82 04 3f ff  add  %l0, -1, %g1
a008be78:  80 a0 60 12  cmp  %g1, 0x12
a008be7c:  18 80 01 ac  bgu  0xa008c52c
a008be80:  1b 28 02 2f  sethi  %hi(0xa008bc00), %o5
a008be84:  83 28 60 02  sll  %g1, 2, %g1
a008be88:  9a 13 61 48  or  %o5, 0x148, %o5
a008be8c:  c2 03 40 01  ld  [ %o5 + %g1 ], %g1
a008be90:  81 c0 40 00  jmp  %g1
a008be94:  01 00 00 00  nop
a008be98:  90 10 00 18  mov  %i0, %o0
a008be9c:  92 10 20 07  mov  7, %o1
a008bea0:  94 10 20 40  mov  0x40, %o2
a008bea4:  40 00 6c d6  call  0xa00a71fc
a008bea8:  96 10 20 00  clr  %o3
a008beac:  90 10 00 18  mov  %i0, %o0
a008beb0:  92 10 20 07  mov  7, %o1
a008beb4:  94 10 20 80  mov  0x80, %o2
a008beb8:  40 00 6c d1  call  0xa00a71fc
a008bebc:  96 10 20 00  clr  %o3
a008bec0:  90 10 00 18  mov  %i0, %o0
a008bec4:  92 10 20 07  mov  7, %o1
a008bec8:  94 10 20 10  mov  0x10, %o2
a008becc:  40 00 6c cc  call  0xa00a71fc
a008bed0:  96 10 20 00  clr  %o3
a008bed4:  90 10 00 18  mov  %i0, %o0
a008bed8:  92 10 20 02  mov  2, %o1
a008bedc:  94 10 20 08  mov  8, %o2
a008bee0:  40 00 6c c7  call  0xa00a71fc
a008bee4:  96 10 20 08  mov  8, %o3
a008bee8:  90 10 00 18  mov  %i0, %o0
a008beec:  92 10 20 00  clr  %o1
a008bef0:  94 10 20 01  mov  1, %o2
a008bef4:  40 00 6c c2  call  0xa00a71fc
a008bef8:  96 10 20 01  mov  1, %o3
a008befc:  7f ff fc f0  call  0xa008b2bc
a008bf00:  90 10 00 10  mov  %l0, %o0
a008bf04:  80 8a 20 ff  btst  0xff, %o0
a008bf08:  22 80 00 1e  be,a   0xa008bf80
a008bf0c:  90 10 00 18  mov  %i0, %o0
a008bf10:  10 80 00 42  b  0xa008c018
a008bf14:  90 10 20 00  clr  %o0
a008bf18:  90 10 00 18  mov  %i0, %o0
a008bf1c:  92 10 20 07  mov  7, %o1
a008bf20:  94 10 20 40  mov  0x40, %o2
a008bf24:  40 00 6c b6  call  0xa00a71fc
a008bf28:  96 10 20 00  clr  %o3
a008bf2c:  90 10 00 18  mov  %i0, %o0
a008bf30:  92 10 20 07  mov  7, %o1
a008bf34:  94 10 20 80  mov  0x80, %o2
a008bf38:  40 00 6c b1  call  0xa00a71fc
a008bf3c:  96 10 20 00  clr  %o3
a008bf40:  90 10 00 18  mov  %i0, %o0
a008bf44:  92 10 20 07  mov  7, %o1
a008bf48:  94 10 20 10  mov  0x10, %o2
a008bf4c:  40 00 6c ac  call  0xa00a71fc
a008bf50:  96 10 20 00  clr  %o3
a008bf54:  90 10 00 18  mov  %i0, %o0
a008bf58:  92 10 20 02  mov  2, %o1
a008bf5c:  94 10 20 08  mov  8, %o2
a008bf60:  40 00 6c a7  call  0xa00a71fc
a008bf64:  96 10 20 08  mov  8, %o3
a008bf68:  90 10 00 18  mov  %i0, %o0
a008bf6c:  92 10 20 00  clr  %o1
a008bf70:  94 10 20 01  mov  1, %o2
a008bf74:  40 00 6c a2  call  0xa00a71fc
a008bf78:  96 10 20 01  mov  1, %o3
a008bf7c:  90 10 00 18  mov  %i0, %o0
a008bf80:  92 10 20 01  mov  1, %o1
a008bf84:  94 10 20 40  mov  0x40, %o2
a008bf88:  40 00 6c 9d  call  0xa00a71fc
a008bf8c:  96 10 20 40  mov  0x40, %o3
a008bf90:  b2 10 20 03  mov  3, %i1
a008bf94:  10 80 01 64  b  0xa008c524
a008bf98:  b4 10 20 12  mov  0x12, %i2
a008bf9c:  90 10 00 18  mov  %i0, %o0
a008bfa0:  92 10 20 07  mov  7, %o1
a008bfa4:  94 10 20 40  mov  0x40, %o2
a008bfa8:  40 00 6c 95  call  0xa00a71fc
a008bfac:  96 10 20 00  clr  %o3
a008bfb0:  90 10 00 18  mov  %i0, %o0
a008bfb4:  92 10 20 07  mov  7, %o1
a008bfb8:  94 10 20 80  mov  0x80, %o2
a008bfbc:  40 00 6c 90  call  0xa00a71fc
a008bfc0:  96 10 20 00  clr  %o3
a008bfc4:  90 10 00 18  mov  %i0, %o0
a008bfc8:  92 10 20 07  mov  7, %o1
a008bfcc:  94 10 20 10  mov  0x10, %o2
a008bfd0:  40 00 6c 8b  call  0xa00a71fc
a008bfd4:  96 10 20 00  clr  %o3
a008bfd8:  90 10 00 18  mov  %i0, %o0
a008bfdc:  92 10 20 02  mov  2, %o1
a008bfe0:  94 10 20 08  mov  8, %o2
a008bfe4:  40 00 6c 86  call  0xa00a71fc
a008bfe8:  96 10 20 08  mov  8, %o3
a008bfec:  90 10 00 18  mov  %i0, %o0
a008bff0:  92 10 20 00  clr  %o1
a008bff4:  94 10 20 01  mov  1, %o2
a008bff8:  40 00 6c 81  call  0xa00a71fc
a008bffc:  96 10 20 01  mov  1, %o3
a008c000:  7f ff fc af  call  0xa008b2bc
a008c004:  90 10 00 10  mov  %l0, %o0
a008c008:  80 8a 20 ff  btst  0xff, %o0
a008c00c:  02 bf ff dd  be  0xa008bf80
a008c010:  90 10 00 18  mov  %i0, %o0
a008c014:  90 10 20 01  mov  1, %o0
a008c018:  40 00 6a e8  call  0xa00a6bb8
a008c01c:  92 10 20 51  mov  0x51, %o1
a008c020:  80 8a 20 01  btst  1, %o0
a008c024:  02 bf ff d7  be  0xa008bf80
a008c028:  90 10 00 18  mov  %i0, %o0
a008c02c:  10 bf ff c2  b  0xa008bf34
a008c030:  92 10 20 07  mov  7, %o1
a008c034:  90 10 00 18  mov  %i0, %o0
a008c038:  92 10 20 07  mov  7, %o1
a008c03c:  94 10 20 40  mov  0x40, %o2
a008c040:  40 00 6c 6f  call  0xa00a71fc
a008c044:  96 10 20 00  clr  %o3
a008c048:  90 10 00 18  mov  %i0, %o0
a008c04c:  92 10 20 07  mov  7, %o1
a008c050:  94 10 20 10  mov  0x10, %o2
a008c054:  40 00 6c 6a  call  0xa00a71fc
a008c058:  96 10 20 10  mov  0x10, %o3
a008c05c:  90 10 00 18  mov  %i0, %o0
a008c060:  92 10 20 00  clr  %o1
a008c064:  94 10 20 01  mov  1, %o2
a008c068:  40 00 6c 65  call  0xa00a71fc
a008c06c:  96 10 20 00  clr  %o3
a008c070:  90 10 00 18  mov  %i0, %o0
a008c074:  92 10 20 01  mov  1, %o1
a008c078:  94 10 20 40  mov  0x40, %o2
a008c07c:  40 00 6c 60  call  0xa00a71fc
a008c080:  96 10 20 40  mov  0x40, %o3
a008c084:  90 10 00 18  mov  %i0, %o0
a008c088:  92 10 20 03  mov  3, %o1
a008c08c:  40 00 6c 37  call  0xa00a7168
a008c090:  94 10 20 1a  mov  0x1a, %o2
a008c094:  80 a6 20 01  cmp  %i0, 1
a008c098:  02 80 00 0e  be  0xa008c0d0
a008c09c:  19 33 c0 44  sethi  %hi(0xcf011000), %o4
a008c0a0:  14 80 00 07  bg  0xa008c0bc
a008c0a4:  80 a6 20 02  cmp  %i0, 2
a008c0a8:  03 33 c0 44  sethi  %hi(0xcf011000), %g1
a008c0ac:  80 a6 20 00  cmp  %i0, 0
a008c0b0:  02 80 00 0c  be  0xa008c0e0
a008c0b4:  82 10 62 40  or  %g1, 0x240, %g1
a008c0b8:  30 80 01 1d  b,a   0xa008c52c
a008c0bc:  02 80 00 07  be  0xa008c0d8
a008c0c0:  80 a6 20 03  cmp  %i0, 3
a008c0c4:  02 80 00 0d  be  0xa008c0f8
a008c0c8:  19 33 c0 44  sethi  %hi(0xcf011000), %o4
a008c0cc:  30 80 01 18  b,a   0xa008c52c
a008c0d0:  10 80 00 0b  b  0xa008c0fc
a008c0d4:  98 13 22 40  or  %o4, 0x240, %o4
a008c0d8:  03 33 c0 44  sethi  %hi(0xcf011000), %g1
a008c0dc:  82 10 62 44  or  %g1, 0x244, %g1	! 0xcf011244
a008c0e0:  da 00 40 00  ld  [ %g1 ], %o5
a008c0e4:  9a 0b 60 f0  and  %o5, 0xf0, %o5
a008c0e8:  98 0c 20 0f  and  %l0, 0xf, %o4
a008c0ec:  9a 13 40 0c  or  %o5, %o4, %o5
a008c0f0:  da 20 40 00  st  %o5, [ %g1 ]
a008c0f4:  30 80 01 0e  b,a   0xa008c52c
a008c0f8:  98 13 22 44  or  %o4, 0x244, %o4
a008c0fc:  c2 03 00 00  ld  [ %o4 ], %g1
a008c100:  9a 0c 20 0f  and  %l0, 0xf, %o5
a008c104:  82 08 60 0f  and  %g1, 0xf, %g1
a008c108:  9b 2b 60 04  sll  %o5, 4, %o5
a008c10c:  82 10 40 0d  or  %g1, %o5, %g1
a008c110:  c2 23 00 00  st  %g1, [ %o4 ]
a008c114:  30 80 01 06  b,a   0xa008c52c
a008c118:  90 10 00 18  mov  %i0, %o0
a008c11c:  92 10 20 07  mov  7, %o1
a008c120:  94 10 20 40  mov  0x40, %o2
a008c124:  40 00 6c 36  call  0xa00a71fc
a008c128:  96 10 20 00  clr  %o3
a008c12c:  90 10 00 18  mov  %i0, %o0
a008c130:  92 10 20 00  clr  %o1
a008c134:  94 10 20 01  mov  1, %o2
a008c138:  40 00 6c 31  call  0xa00a71fc
a008c13c:  96 10 20 00  clr  %o3
a008c140:  90 10 00 18  mov  %i0, %o0
a008c144:  92 10 20 02  mov  2, %o1
a008c148:  94 10 20 24  mov  0x24, %o2
a008c14c:  40 00 6c 2c  call  0xa00a71fc
a008c150:  96 10 20 24  mov  0x24, %o3
a008c154:  96 10 20 80  mov  0x80, %o3
a008c158:  90 10 00 18  mov  %i0, %o0
a008c15c:  92 10 20 07  mov  7, %o1
a008c160:  40 00 6c 27  call  0xa00a71fc
a008c164:  94 10 20 80  mov  0x80, %o2
a008c168:  90 10 00 18  mov  %i0, %o0
a008c16c:  92 10 20 08  mov  8, %o1
a008c170:  40 00 6b fe  call  0xa00a7168
a008c174:  94 10 20 00  clr  %o2
a008c178:  90 10 00 18  mov  %i0, %o0
a008c17c:  92 10 20 09  mov  9, %o1
a008c180:  40 00 6b fa  call  0xa00a7168
a008c184:  94 10 20 04  mov  4, %o2
a008c188:  90 10 00 18  mov  %i0, %o0
a008c18c:  92 10 20 0a  mov  0xa, %o1
a008c190:  40 00 6b f6  call  0xa00a7168
a008c194:  94 10 20 00  clr  %o2
a008c198:  90 10 00 18  mov  %i0, %o0
a008c19c:  92 10 20 0c  mov  0xc, %o1
a008c1a0:  40 00 6b f2  call  0xa00a7168
a008c1a4:  94 10 20 00  clr  %o2
a008c1a8:  90 10 00 18  mov  %i0, %o0
a008c1ac:  92 10 20 0d  mov  0xd, %o1
a008c1b0:  40 00 6b ee  call  0xa00a7168
a008c1b4:  94 10 20 01  mov  1, %o2
a008c1b8:  90 10 00 18  mov  %i0, %o0
a008c1bc:  92 10 20 0e  mov  0xe, %o1
a008c1c0:  40 00 6b ea  call  0xa00a7168
a008c1c4:  94 10 20 00  clr  %o2
a008c1c8:  94 10 20 1a  mov  0x1a, %o2
a008c1cc:  90 10 00 18  mov  %i0, %o0
a008c1d0:  40 00 6b e6  call  0xa00a7168
a008c1d4:  92 10 20 03  mov  3, %o1
a008c1d8:  92 10 20 02  mov  2, %o1
a008c1dc:  40 00 6b f6  call  0xa00a71b4
a008c1e0:  90 10 00 18  mov  %i0, %o0
a008c1e4:  a2 10 00 08  mov  %o0, %l1
a008c1e8:  a0 0c 60 bf  and  %l1, 0xbf, %l0
a008c1ec:  90 10 00 18  mov  %i0, %o0
a008c1f0:  92 10 20 02  mov  2, %o1
a008c1f4:  40 00 6b dd  call  0xa00a7168
a008c1f8:  94 10 00 10  mov  %l0, %o2
a008c1fc:  94 14 60 40  or  %l1, 0x40, %o2
a008c200:  94 0a a0 ff  and  %o2, 0xff, %o2
a008c204:  90 10 00 18  mov  %i0, %o0
a008c208:  40 00 6b d8  call  0xa00a7168
a008c20c:  92 10 20 02  mov  2, %o1
a008c210:  94 10 00 10  mov  %l0, %o2
a008c214:  90 10 00 18  mov  %i0, %o0
a008c218:  40 00 6b d4  call  0xa00a7168
a008c21c:  92 10 20 02  mov  2, %o1
a008c220:  92 10 20 07  mov  7, %o1
a008c224:  40 00 6b e4  call  0xa00a71b4
a008c228:  90 10 00 18  mov  %i0, %o0
a008c22c:  a2 10 00 08  mov  %o0, %l1
a008c230:  90 10 00 18  mov  %i0, %o0
a008c234:  92 10 20 07  mov  7, %o1
a008c238:  94 0c 60 7f  and  %l1, 0x7f, %o2
a008c23c:  40 00 6b cb  call  0xa00a7168
a008c240:  b4 14 7f 80  or  %l1, -128, %i2
a008c244:  b4 0e a0 ff  and  %i2, 0xff, %i2
a008c248:  10 80 00 b7  b  0xa008c524
a008c24c:  b2 10 20 07  mov  7, %i1
a008c250:  90 10 00 18  mov  %i0, %o0
a008c254:  92 10 20 07  mov  7, %o1
a008c258:  94 10 20 40  mov  0x40, %o2
a008c25c:  40 00 6b e8  call  0xa00a71fc
a008c260:  96 10 20 00  clr  %o3
a008c264:  90 10 00 18  mov  %i0, %o0
a008c268:  92 10 20 00  clr  %o1
a008c26c:  94 10 20 01  mov  1, %o2
a008c270:  40 00 6b e3  call  0xa00a71fc
a008c274:  96 10 20 00  clr  %o3
a008c278:  96 10 20 00  clr  %o3
a008c27c:  90 10 00 18  mov  %i0, %o0
a008c280:  92 10 20 07  mov  7, %o1
a008c284:  40 00 6b de  call  0xa00a71fc
a008c288:  94 10 20 10  mov  0x10, %o2
a008c28c:  90 10 00 18  mov  %i0, %o0
a008c290:  92 10 20 03  mov  3, %o1
a008c294:  40 00 6b b5  call  0xa00a7168
a008c298:  94 10 20 02  mov  2, %o2
a008c29c:  94 10 20 80  mov  0x80, %o2
a008c2a0:  96 10 20 00  clr  %o3
a008c2a4:  90 10 00 18  mov  %i0, %o0
a008c2a8:  40 00 6b d5  call  0xa00a71fc
a008c2ac:  92 10 20 07  mov  7, %o1
a008c2b0:  03 33 c0 f2  sethi  %hi(0xcf03c800), %g1
a008c2b4:  96 10 60 40  or  %g1, 0x40, %o3	! 0xcf03c840
a008c2b8:  03 00 00 3f  sethi  %hi(0xfc00), %g1
a008c2bc:  94 10 63 ff  or  %g1, 0x3ff, %o2	! 0xffff
a008c2c0:  9a 10 3f ff  mov  -1, %o5
a008c2c4:  98 10 20 02  mov  2, %o4
a008c2c8:  c2 02 c0 00  ld  [ %o3 ], %g1
a008c2cc:  80 a0 60 01  cmp  %g1, 1
a008c2d0:  32 80 00 02  bne,a   0xa008c2d8
a008c2d4:  d8 22 c0 00  st  %o4, [ %o3 ]
a008c2d8:  c2 02 c0 00  ld  [ %o3 ], %g1
a008c2dc:  80 a0 60 02  cmp  %g1, 2
a008c2e0:  02 80 00 07  be  0xa008c2fc
a008c2e4:  9a 03 7f ff  add  %o5, -1, %o5
a008c2e8:  83 2b 60 10  sll  %o5, 0x10, %g1
a008c2ec:  83 30 60 10  srl  %g1, 0x10, %g1
a008c2f0:  80 a0 40 0a  cmp  %g1, %o2
a008c2f4:  12 bf ff f5  bne  0xa008c2c8
a008c2f8:  01 00 00 00  nop
a008c2fc:  82 10 20 02  mov  2, %g1	! 0x2
a008c300:  c2 22 c0 00  st  %g1, [ %o3 ]
a008c304:  82 06 20 04  add  %i0, 4, %g1
a008c308:  19 33 c0 49  sethi  %hi(0xcf012400), %o4
a008c30c:  9a 10 20 01  mov  1, %o5
a008c310:  98 13 20 44  or  %o4, 0x44, %o4
a008c314:  9b 2b 40 01  sll  %o5, %g1, %o5
a008c318:  c2 03 00 00  ld  [ %o4 ], %g1
a008c31c:  82 10 40 0d  or  %g1, %o5, %g1
a008c320:  c2 23 00 00  st  %g1, [ %o4 ]
a008c324:  03 33 c0 f2  sethi  %hi(0xcf03c800), %g1
a008c328:  c0 22 c0 00  clr  [ %o3 ]
a008c32c:  96 10 60 40  or  %g1, 0x40, %o3
a008c330:  03 00 00 3f  sethi  %hi(0xfc00), %g1
a008c334:  94 10 63 ff  or  %g1, 0x3ff, %o2	! 0xffff
a008c338:  9a 10 3f ff  mov  -1, %o5
a008c33c:  98 10 20 02  mov  2, %o4
a008c340:  c2 02 c0 00  ld  [ %o3 ], %g1
a008c344:  80 a0 60 01  cmp  %g1, 1
a008c348:  32 80 00 02  bne,a   0xa008c350
a008c34c:  d8 22 c0 00  st  %o4, [ %o3 ]
a008c350:  c2 02 c0 00  ld  [ %o3 ], %g1
a008c354:  80 a0 60 02  cmp  %g1, 2
a008c358:  02 80 00 07  be  0xa008c374
a008c35c:  9a 03 7f ff  add  %o5, -1, %o5
a008c360:  83 2b 60 10  sll  %o5, 0x10, %g1
a008c364:  83 30 60 10  srl  %g1, 0x10, %g1
a008c368:  80 a0 40 0a  cmp  %g1, %o2
a008c36c:  12 bf ff f5  bne  0xa008c340
a008c370:  01 00 00 00  nop
a008c374:  82 10 20 02  mov  2, %g1	! 0x2
a008c378:  c2 22 c0 00  st  %g1, [ %o3 ]
a008c37c:  9a 06 20 04  add  %i0, 4, %o5
a008c380:  19 33 c0 49  sethi  %hi(0xcf012400), %o4
a008c384:  82 10 20 01  mov  1, %g1
a008c388:  98 13 20 44  or  %o4, 0x44, %o4
a008c38c:  83 28 40 0d  sll  %g1, %o5, %g1
a008c390:  da 03 00 00  ld  [ %o4 ], %o5
a008c394:  82 2b 40 01  andn  %o5, %g1, %g1
a008c398:  c2 23 00 00  st  %g1, [ %o4 ]
a008c39c:  03 33 c0 f2  sethi  %hi(0xcf03c800), %g1
a008c3a0:  c0 22 c0 00  clr  [ %o3 ]
a008c3a4:  96 10 60 40  or  %g1, 0x40, %o3
a008c3a8:  03 00 00 3f  sethi  %hi(0xfc00), %g1
a008c3ac:  94 10 63 ff  or  %g1, 0x3ff, %o2	! 0xffff
a008c3b0:  9a 10 3f ff  mov  -1, %o5
a008c3b4:  98 10 20 02  mov  2, %o4
a008c3b8:  c2 02 c0 00  ld  [ %o3 ], %g1
a008c3bc:  80 a0 60 01  cmp  %g1, 1
a008c3c0:  32 80 00 02  bne,a   0xa008c3c8
a008c3c4:  d8 22 c0 00  st  %o4, [ %o3 ]
a008c3c8:  c2 02 c0 00  ld  [ %o3 ], %g1
a008c3cc:  80 a0 60 02  cmp  %g1, 2
a008c3d0:  02 80 00 07  be  0xa008c3ec
a008c3d4:  9a 03 7f ff  add  %o5, -1, %o5
a008c3d8:  83 2b 60 10  sll  %o5, 0x10, %g1
a008c3dc:  83 30 60 10  srl  %g1, 0x10, %g1
a008c3e0:  80 a0 40 0a  cmp  %g1, %o2
a008c3e4:  12 bf ff f5  bne  0xa008c3b8
a008c3e8:  01 00 00 00  nop
a008c3ec:  82 10 20 02  mov  2, %g1	! 0x2
a008c3f0:  c2 22 c0 00  st  %g1, [ %o3 ]
a008c3f4:  82 06 20 04  add  %i0, 4, %g1
a008c3f8:  19 33 c0 49  sethi  %hi(0xcf012400), %o4
a008c3fc:  9a 10 20 01  mov  1, %o5
a008c400:  98 13 20 44  or  %o4, 0x44, %o4
a008c404:  9b 2b 40 01  sll  %o5, %g1, %o5
a008c408:  c2 03 00 00  ld  [ %o4 ], %g1
a008c40c:  82 10 40 0d  or  %g1, %o5, %g1
a008c410:  c2 23 00 00  st  %g1, [ %o4 ]
a008c414:  c0 22 c0 00  clr  [ %o3 ]
a008c418:  90 10 00 18  mov  %i0, %o0
a008c41c:  92 10 20 04  mov  4, %o1
a008c420:  40 00 6b 52  call  0xa00a7168
a008c424:  94 10 20 95  mov  0x95, %o2
a008c428:  90 10 00 18  mov  %i0, %o0
a008c42c:  92 10 20 05  mov  5, %o1
a008c430:  40 00 6b 4e  call  0xa00a7168
a008c434:  94 10 20 18  mov  0x18, %o2
a008c438:  90 10 00 18  mov  %i0, %o0
a008c43c:  92 10 20 06  mov  6, %o1
a008c440:  40 00 6b 4a  call  0xa00a7168
a008c444:  94 10 20 04  mov  4, %o2
a008c448:  b2 10 20 01  mov  1, %i1
a008c44c:  10 80 00 36  b  0xa008c524
a008c450:  b4 10 20 68  mov  0x68, %i2
a008c454:  90 10 00 18  mov  %i0, %o0
a008c458:  92 10 20 03  mov  3, %o1
a008c45c:  40 00 6b 43  call  0xa00a7168
a008c460:  94 10 20 1a  mov  0x1a, %o2
a008c464:  96 10 20 24  mov  0x24, %o3
a008c468:  90 10 00 18  mov  %i0, %o0
a008c46c:  92 10 20 02  mov  2, %o1
a008c470:  40 00 6b 63  call  0xa00a71fc
a008c474:  94 10 20 24  mov  0x24, %o2
a008c478:  90 10 00 18  mov  %i0, %o0
a008c47c:  92 10 20 07  mov  7, %o1
a008c480:  40 00 6b 3a  call  0xa00a7168
a008c484:  94 10 20 40  mov  0x40, %o2
a008c488:  90 10 00 18  mov  %i0, %o0
a008c48c:  92 10 20 08  mov  8, %o1
a008c490:  40 00 6b 36  call  0xa00a7168
a008c494:  94 10 20 00  clr  %o2
a008c498:  90 10 00 18  mov  %i0, %o0
a008c49c:  92 10 20 09  mov  9, %o1
a008c4a0:  40 00 6b 32  call  0xa00a7168
a008c4a4:  94 10 20 80  mov  0x80, %o2
a008c4a8:  90 10 00 18  mov  %i0, %o0
a008c4ac:  92 10 20 0a  mov  0xa, %o1
a008c4b0:  40 00 6b 2e  call  0xa00a7168
a008c4b4:  94 10 20 00  clr  %o2
a008c4b8:  90 10 00 18  mov  %i0, %o0
a008c4bc:  92 10 20 0c  mov  0xc, %o1
a008c4c0:  40 00 6b 2a  call  0xa00a7168
a008c4c4:  94 10 20 00  clr  %o2
a008c4c8:  90 10 00 18  mov  %i0, %o0
a008c4cc:  92 10 20 0d  mov  0xd, %o1
a008c4d0:  40 00 6b 26  call  0xa00a7168
a008c4d4:  94 10 20 01  mov  1, %o2
a008c4d8:  94 10 20 00  clr  %o2
a008c4dc:  90 10 00 18  mov  %i0, %o0
a008c4e0:  40 00 6b 22  call  0xa00a7168
a008c4e4:  92 10 20 0e  mov  0xe, %o1
a008c4e8:  92 10 20 02  mov  2, %o1
a008c4ec:  40 00 6b 32  call  0xa00a71b4
a008c4f0:  90 10 00 18  mov  %i0, %o0
a008c4f4:  a2 10 00 08  mov  %o0, %l1
a008c4f8:  b4 0c 60 bf  and  %l1, 0xbf, %i2
a008c4fc:  90 10 00 18  mov  %i0, %o0
a008c500:  92 10 20 02  mov  2, %o1
a008c504:  40 00 6b 19  call  0xa00a7168
a008c508:  94 10 00 1a  mov  %i2, %o2
a008c50c:  94 14 60 40  or  %l1, 0x40, %o2
a008c510:  94 0a a0 ff  and  %o2, 0xff, %o2
a008c514:  90 10 00 18  mov  %i0, %o0
a008c518:  40 00 6b 14  call  0xa00a7168
a008c51c:  92 10 20 02  mov  2, %o1
a008c520:  b2 10 20 02  mov  2, %i1
a008c524:  40 00 6b 11  call  0xa00a7168
a008c528:  81 e8 00 00  restore
a008c52c:  01 00 00 00  nop
