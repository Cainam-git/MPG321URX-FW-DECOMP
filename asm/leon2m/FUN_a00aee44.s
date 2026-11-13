# leon2m FUN_a00aee44 0xa00aee44-0xa00af44c (1544 bytes)
a00aee44:  9d e3 bf 68  save  %sp, -152, %sp
a00aee48:  98 10 20 00  clr  %o4
a00aee4c:  9a 10 20 00  clr  %o5
a00aee50:  d8 3f bf e8  std  %o4, [ %fp + -24 ]
a00aee54:  92 10 20 06  mov  6, %o1
a00aee58:  90 10 20 07  mov  7, %o0
a00aee5c:  96 10 20 05  mov  5, %o3
a00aee60:  94 10 20 04  mov  4, %o2
a00aee64:  82 10 20 08  mov  8, %g1
a00aee68:  9a 10 20 0b  mov  0xb, %o5
a00aee6c:  d2 2f bf e3  stb  %o1, [ %fp + -29 ]
a00aee70:  d0 2f bf e4  stb  %o0, [ %fp + -28 ]
a00aee74:  d6 2f bf e0  stb  %o3, [ %fp + -32 ]
a00aee78:  d4 2f bf e2  stb  %o2, [ %fp + -30 ]
a00aee7c:  c2 2f bf e5  stb  %g1, [ %fp + -27 ]
a00aee80:  da 2f bf e6  stb  %o5, [ %fp + -26 ]
a00aee84:  90 10 21 20  mov  0x120, %o0
a00aee88:  92 10 20 00  clr  %o1
a00aee8c:  c0 27 bf f0  clr  [ %fp + -16 ]
a00aee90:  c0 37 bf f4  clrh  [ %fp + -12 ]
a00aee94:  c0 2f bf f6  clrb  [ %fp + -10 ]
a00aee98:  40 02 5f 2e  call  0xa0146b50
a00aee9c:  c0 2f bf e1  clrb  [ %fp + -31 ]
a00aeea0:  90 10 20 00  clr  %o0
a00aeea4:  40 02 5f 32  call  0xa0146b6c
a00aeea8:  92 10 20 00  clr  %o1
a00aeeac:  a2 0e 20 ff  and  %i0, 0xff, %l1
a00aeeb0:  a4 10 00 18  mov  %i0, %l2
a00aeeb4:  80 a4 60 bf  cmp  %l1, 0xbf
a00aeeb8:  02 80 01 24  be  0xa00af348
a00aeebc:  a6 10 20 06  mov  6, %l3
a00aeec0:  a8 06 20 09  add  %i0, 9, %l4
a00aeec4:  a0 0d 20 ff  and  %l4, 0xff, %l0
a00aeec8:  80 a4 20 02  cmp  %l0, 2
a00aeecc:  08 80 00 bc  bleu  0xa00af1bc
a00aeed0:  90 10 21 11  mov  0x111, %o0
a00aeed4:  b0 0c e0 ff  and  %l3, 0xff, %i0
a00aeed8:  90 10 20 28  mov  0x28, %o0
a00aeedc:  92 10 00 18  mov  %i0, %o1
a00aeee0:  94 10 20 0c  mov  0xc, %o2
a00aeee4:  96 10 2e 96  mov  0xe96, %o3
a00aeee8:  40 02 5e e6  call  0xa0146a80
a00aeeec:  98 10 20 00  clr  %o4
a00aeef0:  92 1c 60 0e  xor  %l1, 0xe, %o1
a00aeef4:  80 a0 00 09  cmp  %g0, %o1
a00aeef8:  90 60 3f ff  subx  %g0, -1, %o0
a00aeefc:  82 1c 60 15  xor  %l1, 0x15, %g1
a00aef00:  80 a0 00 01  cmp  %g0, %g1
a00aef04:  9a 60 3f ff  subx  %g0, -1, %o5
a00aef08:  80 92 00 0d  orcc  %o0, %o5, %g0
a00aef0c:  12 80 00 5b  bne  0xa00af078
a00aef10:  80 a4 60 23  cmp  %l1, 0x23
a00aef14:  02 80 00 5a  be  0xa00af07c
a00aef18:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00aef1c:  7f ff d2 47  call  0xa00a3838
a00aef20:  ab 2e 20 03  sll  %i0, 3, %l5
a00aef24:  a0 10 00 08  mov  %o0, %l0
a00aef28:  90 10 20 05  mov  5, %o0
a00aef2c:  92 10 20 00  clr  %o1
a00aef30:  40 02 5f 44  call  0xa0146c40
a00aef34:  94 10 20 00  clr  %o2
a00aef38:  90 10 20 05  mov  5, %o0
a00aef3c:  92 10 20 00  clr  %o1
a00aef40:  94 10 20 00  clr  %o2
a00aef44:  96 10 20 00  clr  %o3
a00aef48:  98 10 20 00  clr  %o4
a00aef4c:  9a 10 20 0f  mov  0xf, %o5
a00aef50:  c0 23 a0 5c  clr  [ %sp + 0x5c ]
a00aef54:  c0 23 a0 60  clr  [ %sp + 0x60 ]
a00aef58:  c0 23 a0 64  clr  [ %sp + 0x64 ]
a00aef5c:  c0 23 a0 68  clr  [ %sp + 0x68 ]
a00aef60:  40 02 5d c7  call  0xa014667c
a00aef64:  c0 23 a0 6c  clr  [ %sp + 0x6c ]
a00aef68:  a8 05 40 18  add  %l5, %i0, %l4
a00aef6c:  9f 2d 20 02  sll  %l4, 2, %o7
a00aef70:  98 04 23 c0  add  %l0, 0x3c0, %o4
a00aef74:  94 03 e0 24  add  %o7, 0x24, %o2
a00aef78:  b1 2b 20 10  sll  %o4, 0x10, %i0
a00aef7c:  98 10 00 0a  mov  %o2, %o4
a00aef80:  97 36 20 10  srl  %i0, 0x10, %o3
a00aef84:  90 10 20 05  mov  5, %o0
a00aef88:  92 10 23 c0  mov  0x3c0, %o1
a00aef8c:  40 02 5e 39  call  0xa0146870
a00aef90:  9a 10 20 00  clr  %o5
a00aef94:  90 10 20 05  mov  5, %o0
a00aef98:  92 10 20 01  mov  1, %o1
a00aef9c:  40 02 5f 29  call  0xa0146c40
a00aefa0:  94 10 20 00  clr  %o2
a00aefa4:  80 a4 60 0e  cmp  %l1, 0xe
a00aefa8:  02 80 00 96  be  0xa00af200
a00aefac:  80 a4 60 23  cmp  %l1, 0x23
a00aefb0:  02 80 00 a0  be  0xa00af230
a00aefb4:  80 a4 60 bf  cmp  %l1, 0xbf
a00aefb8:  22 80 00 f6  be,a   0xa00af390
a00aefbc:  a4 0c e0 ff  and  %l3, 0xff, %l2
a00aefc0:  a2 04 a0 09  add  %l2, 9, %l1
a00aefc4:  a8 0c 60 ff  and  %l1, 0xff, %l4
a00aefc8:  80 a5 20 02  cmp  %l4, 2
a00aefcc:  18 80 00 38  bgu  0xa00af0ac
a00aefd0:  25 2a 00 b4  sethi  %hi(0xa802d000), %l2
a00aefd4:  a2 0c e0 ff  and  %l3, 0xff, %l1
a00aefd8:  b0 10 20 00  clr  %i0
a00aefdc:  27 2a 00 b4  sethi  %hi(0xa802d000), %l3
a00aefe0:  b2 10 20 00  clr  %i1
a00aefe4:  25 00 06 0f  sethi  %hi(0x183c00), %l2
a00aefe8:  9a 06 40 19  add  %i1, %i1, %o5
a00aefec:  aa 03 40 11  add  %o5, %l1, %l5
a00aeff0:  a8 05 60 02  add  %l5, 2, %l4
a00aeff4:  a1 2d 20 10  sll  %l4, 0x10, %l0
a00aeff8:  ab 34 20 10  srl  %l0, 0x10, %l5
a00aeffc:  92 10 00 15  mov  %l5, %o1
a00af000:  94 10 20 0d  mov  0xd, %o2
a00af004:  96 10 2e 96  mov  0xe96, %o3
a00af008:  98 10 20 00  clr  %o4
a00af00c:  40 02 5e 9d  call  0xa0146a80
a00af010:  90 10 20 28  mov  0x28, %o0
a00af014:  99 2e 60 03  sll  %i1, 3, %o4
a00af018:  96 23 00 19  sub  %o4, %i1, %o3
a00af01c:  93 2a e0 02  sll  %o3, 2, %o1
a00af020:  94 14 e2 90  or  %l3, 0x290, %o2
a00af024:  9e 02 40 19  add  %o1, %i1, %o7
a00af028:  c2 0a a0 08  ldub  [ %o2 + 8 ], %g1
a00af02c:  90 03 c0 01  add  %o7, %g1, %o0
a00af030:  9a 14 a0 b4  or  %l2, 0xb4, %o5
a00af034:  b3 2a 20 02  sll  %o0, 2, %i1
a00af038:  90 06 40 0d  add  %i1, %o5, %o0
a00af03c:  7f ff d2 02  call  0xa00a3844
a00af040:  92 10 20 00  clr  %o1
a00af044:  98 10 00 08  mov  %o0, %o4
a00af048:  94 10 00 15  mov  %l5, %o2
a00af04c:  90 10 20 00  clr  %o0
a00af050:  92 10 20 28  mov  0x28, %o1
a00af054:  96 10 20 01  mov  1, %o3
a00af058:  9a 10 20 00  clr  %o5
a00af05c:  7f ff d0 52  call  0xa00a31a4
a00af060:  b0 06 20 01  inc  %i0
a00af064:  b2 0e 20 ff  and  %i0, 0xff, %i1
a00af068:  80 a6 60 02  cmp  %i1, 2
a00af06c:  08 bf ff e0  bleu  0xa00aefec
a00af070:  9a 06 40 19  add  %i1, %i1, %o5
a00af074:  30 80 00 f4  b,a   0xa00af444
a00af078:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00af07c:  15 00 06 16  sethi  %hi(0x185800), %o2
a00af080:  d2 0a e2 98  ldub  [ %o3 + 0x298 ], %o1
a00af084:  7f ff d1 f0  call  0xa00a3844
a00af088:  90 12 a2 f0  or  %o2, 0x2f0, %o0
a00af08c:  98 10 00 08  mov  %o0, %o4
a00af090:  90 10 20 00  clr  %o0
a00af094:  92 10 20 28  mov  0x28, %o1
a00af098:  94 10 00 18  mov  %i0, %o2
a00af09c:  96 10 20 01  mov  1, %o3
a00af0a0:  7f ff d0 41  call  0xa00a31a4
a00af0a4:  9a 10 20 00  clr  %o5
a00af0a8:  30 bf ff 9d  b,a   0xa00aef1c
a00af0ac:  aa 14 a2 90  or  %l2, 0x290, %l5
a00af0b0:  a2 10 20 00  clr  %l1
a00af0b4:  a4 10 20 00  clr  %l2
a00af0b8:  b0 10 20 00  clr  %i0
a00af0bc:  a8 07 bf f8  add  %fp, -8, %l4
a00af0c0:  90 05 00 18  add  %l4, %i0, %o0
a00af0c4:  f2 0a 3f f0  ldub  [ %o0 + -16 ], %i1
a00af0c8:  80 a6 60 00  cmp  %i1, 0
a00af0cc:  02 80 00 36  be  0xa00af1a4
a00af0d0:  a0 0c a0 ff  and  %l2, 0xff, %l0
a00af0d4:  b2 0c e0 ff  and  %l3, 0xff, %i1
a00af0d8:  94 06 60 0e  add  %i1, 0xe, %o2
a00af0dc:  9f 2a a0 10  sll  %o2, 0x10, %o7
a00af0e0:  82 04 00 10  add  %l0, %l0, %g1
a00af0e4:  93 33 e0 10  srl  %o7, 0x10, %o1
a00af0e8:  90 10 20 28  mov  0x28, %o0
a00af0ec:  94 10 20 0a  mov  0xa, %o2
a00af0f0:  96 10 2e 96  mov  0xe96, %o3
a00af0f4:  80 a4 20 06  cmp  %l0, 6
a00af0f8:  02 80 00 0b  be  0xa00af124
a00af0fc:  98 10 20 00  clr  %o4
a00af100:  b2 0c e0 ff  and  %l3, 0xff, %i1
a00af104:  96 00 40 19  add  %g1, %i1, %o3
a00af108:  92 02 e0 02  add  %o3, 2, %o1
a00af10c:  83 2a 60 10  sll  %o1, 0x10, %g1
a00af110:  93 30 60 10  srl  %g1, 0x10, %o1
a00af114:  90 10 20 28  mov  0x28, %o0
a00af118:  94 10 20 0d  mov  0xd, %o2
a00af11c:  96 10 2e 96  mov  0xe96, %o3
a00af120:  98 10 20 00  clr  %o4
a00af124:  40 02 5e 57  call  0xa0146a80
a00af128:  a4 04 a0 01  inc  %l2
a00af12c:  98 04 00 10  add  %l0, %l0, %o4
a00af130:  a0 03 00 19  add  %o4, %i1, %l0
a00af134:  96 04 20 02  add  %l0, 2, %o3
a00af138:  93 2a e0 10  sll  %o3, 0x10, %o1
a00af13c:  a1 32 60 10  srl  %o1, 0x10, %l0
a00af140:  96 10 20 01  mov  1, %o3
a00af144:  94 10 00 10  mov  %l0, %o2
a00af148:  98 10 20 01  mov  1, %o4
a00af14c:  9a 10 20 00  clr  %o5
a00af150:  90 10 20 00  clr  %o0
a00af154:  40 02 5e 73  call  0xa0146b20
a00af158:  92 10 20 28  mov  0x28, %o1
a00af15c:  83 2e 20 03  sll  %i0, 3, %g1
a00af160:  94 20 40 18  sub  %g1, %i0, %o2
a00af164:  9f 2a a0 02  sll  %o2, 2, %o7
a00af168:  b2 03 c0 18  add  %o7, %i0, %i1
a00af16c:  d0 0d 60 08  ldub  [ %l5 + 8 ], %o0
a00af170:  9a 06 40 08  add  %i1, %o0, %o5
a00af174:  99 2b 60 10  sll  %o5, 0x10, %o4
a00af178:  31 00 06 0c  sethi  %hi(0x183000), %i0
a00af17c:  93 33 20 10  srl  %o4, 0x10, %o1
a00af180:  7f ff d1 b1  call  0xa00a3844
a00af184:  90 16 22 e4  or  %i0, 0x2e4, %o0
a00af188:  98 10 00 08  mov  %o0, %o4
a00af18c:  94 10 00 10  mov  %l0, %o2
a00af190:  90 10 20 00  clr  %o0
a00af194:  92 10 20 29  mov  0x29, %o1
a00af198:  96 10 20 01  mov  1, %o3
a00af19c:  7f ff d0 02  call  0xa00a31a4
a00af1a0:  9a 10 20 00  clr  %o5
a00af1a4:  a2 04 60 01  inc  %l1
a00af1a8:  b0 0c 60 ff  and  %l1, 0xff, %i0
a00af1ac:  80 a6 20 0b  cmp  %i0, 0xb
a00af1b0:  08 bf ff c5  bleu  0xa00af0c4
a00af1b4:  90 05 00 18  add  %l4, %i0, %o0
a00af1b8:  30 80 00 a3  b,a   0xa00af444
a00af1bc:  40 02 5e 65  call  0xa0146b50
a00af1c0:  92 10 20 00  clr  %o1
a00af1c4:  2b 2a 00 b4  sethi  %hi(0xa802d000), %l5
a00af1c8:  27 00 06 0e  sethi  %hi(0x183800), %l3
a00af1cc:  d2 0d 62 98  ldub  [ %l5 + 0x298 ], %o1
a00af1d0:  7f ff d1 9d  call  0xa00a3844
a00af1d4:  90 14 e2 70  or  %l3, 0x270, %o0
a00af1d8:  98 10 00 08  mov  %o0, %o4
a00af1dc:  a6 10 20 0a  mov  0xa, %l3
a00af1e0:  90 10 20 00  clr  %o0
a00af1e4:  92 10 20 28  mov  0x28, %o1
a00af1e8:  94 10 20 0a  mov  0xa, %o2
a00af1ec:  96 10 20 01  mov  1, %o3
a00af1f0:  7f ff cf ed  call  0xa00a31a4
a00af1f4:  9a 10 20 00  clr  %o5
a00af1f8:  10 bf ff 38  b  0xa00aeed8
a00af1fc:  b0 0c e0 ff  and  %l3, 0xff, %i0
a00af200:  b2 0e 60 ff  and  %i1, 0xff, %i1
a00af204:  80 a6 60 05  cmp  %i1, 5
a00af208:  02 80 00 8a  be  0xa00af430
a00af20c:  80 a6 60 02  cmp  %i1, 2
a00af210:  02 80 00 4b  be  0xa00af33c
a00af214:  80 a6 60 06  cmp  %i1, 6
a00af218:  12 bf ff 6b  bne  0xa00aefc4
a00af21c:  a2 04 a0 09  add  %l2, 9, %l1
a00af220:  9a 10 20 01  mov  1, %o5
a00af224:  da 2f bf ec  stb  %o5, [ %fp + -20 ]
a00af228:  10 bf ff 67  b  0xa00aefc4
a00af22c:  da 2f bf eb  stb  %o5, [ %fp + -21 ]
a00af230:  25 2a 00 b4  sethi  %hi(0xa802d000), %l2
a00af234:  90 10 20 01  mov  1, %o0
a00af238:  b0 0c e0 ff  and  %l3, 0xff, %i0
a00af23c:  a8 14 a2 90  or  %l2, 0x290, %l4
a00af240:  d0 2f bf f3  stb  %o0, [ %fp + -13 ]
a00af244:  d0 2f bf e8  stb  %o0, [ %fp + -24 ]
a00af248:  d0 2f bf ec  stb  %o0, [ %fp + -20 ]
a00af24c:  d0 2f bf ee  stb  %o0, [ %fp + -18 ]
a00af250:  d0 2f bf ef  stb  %o0, [ %fp + -17 ]
a00af254:  d0 2f bf f0  stb  %o0, [ %fp + -16 ]
a00af258:  a2 10 20 00  clr  %l1
a00af25c:  a4 10 20 00  clr  %l2
a00af260:  9a 10 20 00  clr  %o5
a00af264:  10 80 00 06  b  0xa00af27c
a00af268:  a6 07 bf f8  add  %fp, -8, %l3
a00af26c:  9a 0c 60 ff  and  %l1, 0xff, %o5
a00af270:  80 a3 60 06  cmp  %o5, 6
a00af274:  18 80 00 74  bgu  0xa00af444
a00af278:  01 00 00 00  nop
a00af27c:  a0 0c a0 ff  and  %l2, 0xff, %l0
a00af280:  98 04 00 10  add  %l0, %l0, %o4
a00af284:  96 03 00 18  add  %o4, %i0, %o3
a00af288:  b2 04 c0 0d  add  %l3, %o5, %i1
a00af28c:  94 02 e0 02  add  %o3, 2, %o2
a00af290:  ea 0e 7f e8  ldub  [ %i1 + -24 ], %l5
a00af294:  93 2a a0 10  sll  %o2, 0x10, %o1
a00af298:  82 04 c0 15  add  %l3, %l5, %g1
a00af29c:  a1 32 60 10  srl  %o1, 0x10, %l0
a00af2a0:  de 08 7f f0  ldub  [ %g1 + -16 ], %o7
a00af2a4:  92 10 00 10  mov  %l0, %o1
a00af2a8:  90 10 20 28  mov  0x28, %o0
a00af2ac:  94 10 20 0d  mov  0xd, %o2
a00af2b0:  96 10 2e 96  mov  0xe96, %o3
a00af2b4:  98 10 20 00  clr  %o4
a00af2b8:  80 a3 e0 00  cmp  %o7, 0
a00af2bc:  02 bf ff ec  be  0xa00af26c
a00af2c0:  a2 04 60 01  inc  %l1
a00af2c4:  40 02 5d ef  call  0xa0146a80
a00af2c8:  a4 04 a0 01  inc  %l2
a00af2cc:  98 10 20 01  mov  1, %o4
a00af2d0:  94 10 00 10  mov  %l0, %o2
a00af2d4:  96 10 20 01  mov  1, %o3
a00af2d8:  9a 10 20 00  clr  %o5
a00af2dc:  90 10 20 00  clr  %o0
a00af2e0:  40 02 5e 10  call  0xa0146b20
a00af2e4:  92 10 20 28  mov  0x28, %o1
a00af2e8:  d4 0e 7f e8  ldub  [ %i1 + -24 ], %o2
a00af2ec:  97 2a a0 03  sll  %o2, 3, %o3
a00af2f0:  92 22 c0 0a  sub  %o3, %o2, %o1
a00af2f4:  ab 2a 60 02  sll  %o1, 2, %l5
a00af2f8:  9e 05 40 0a  add  %l5, %o2, %o7
a00af2fc:  c2 0d 20 08  ldub  [ %l4 + 8 ], %g1
a00af300:  90 03 c0 01  add  %o7, %g1, %o0
a00af304:  9b 2a 20 10  sll  %o0, 0x10, %o5
a00af308:  33 00 06 0c  sethi  %hi(0x183000), %i1
a00af30c:  93 33 60 10  srl  %o5, 0x10, %o1
a00af310:  7f ff d1 4d  call  0xa00a3844
a00af314:  90 16 62 e4  or  %i1, 0x2e4, %o0
a00af318:  98 10 00 08  mov  %o0, %o4
a00af31c:  94 10 00 10  mov  %l0, %o2
a00af320:  90 10 20 00  clr  %o0
a00af324:  92 10 20 29  mov  0x29, %o1
a00af328:  96 10 20 01  mov  1, %o3
a00af32c:  7f ff cf 9e  call  0xa00a31a4
a00af330:  9a 10 20 00  clr  %o5
a00af334:  10 bf ff cf  b  0xa00af270
a00af338:  9a 0c 60 ff  and  %l1, 0xff, %o5
a00af33c:  b2 10 20 01  mov  1, %i1
a00af340:  10 bf ff 20  b  0xa00aefc0
a00af344:  f2 2f bf f1  stb  %i1, [ %fp + -15 ]
a00af348:  90 10 21 34  mov  0x134, %o0
a00af34c:  40 02 5e 01  call  0xa0146b50
a00af350:  92 10 20 00  clr  %o1
a00af354:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a00af358:  19 00 06 0e  sethi  %hi(0x183800), %o4
a00af35c:  d2 0b e2 98  ldub  [ %o7 + 0x298 ], %o1
a00af360:  7f ff d1 39  call  0xa00a3844
a00af364:  90 13 22 70  or  %o4, 0x270, %o0
a00af368:  98 10 00 08  mov  %o0, %o4
a00af36c:  a6 10 20 0a  mov  0xa, %l3
a00af370:  90 10 20 00  clr  %o0
a00af374:  92 10 20 28  mov  0x28, %o1
a00af378:  94 10 20 0a  mov  0xa, %o2
a00af37c:  96 10 20 01  mov  1, %o3
a00af380:  7f ff cf 89  call  0xa00a31a4
a00af384:  9a 10 20 00  clr  %o5
a00af388:  10 bf fe cf  b  0xa00aeec4
a00af38c:  a8 06 20 09  add  %i0, 9, %l4
a00af390:  a2 10 20 00  clr  %l1
a00af394:  29 2a 00 b4  sethi  %hi(0xa802d000), %l4
a00af398:  b2 10 20 00  clr  %i1
a00af39c:  27 00 06 0f  sethi  %hi(0x183c00), %l3
a00af3a0:  98 06 40 19  add  %i1, %i1, %o4
a00af3a4:  b0 03 00 12  add  %o4, %l2, %i0
a00af3a8:  96 06 20 02  add  %i0, 2, %o3
a00af3ac:  a1 2a e0 10  sll  %o3, 0x10, %l0
a00af3b0:  b1 34 20 10  srl  %l0, 0x10, %i0
a00af3b4:  96 10 2e 96  mov  0xe96, %o3
a00af3b8:  92 10 00 18  mov  %i0, %o1
a00af3bc:  94 10 20 0d  mov  0xd, %o2
a00af3c0:  98 10 20 00  clr  %o4
a00af3c4:  40 02 5d af  call  0xa0146a80
a00af3c8:  90 10 20 28  mov  0x28, %o0
a00af3cc:  93 2e 60 03  sll  %i1, 3, %o1
a00af3d0:  94 22 40 19  sub  %o1, %i1, %o2
a00af3d4:  ab 2a a0 02  sll  %o2, 2, %l5
a00af3d8:  82 15 22 90  or  %l4, 0x290, %g1
a00af3dc:  90 05 40 19  add  %l5, %i1, %o0
a00af3e0:  de 08 60 08  ldub  [ %g1 + 8 ], %o7
a00af3e4:  9a 02 00 0f  add  %o0, %o7, %o5
a00af3e8:  99 2b 60 02  sll  %o5, 2, %o4
a00af3ec:  b2 14 e0 b4  or  %l3, 0xb4, %i1
a00af3f0:  90 03 00 19  add  %o4, %i1, %o0
a00af3f4:  7f ff d1 14  call  0xa00a3844
a00af3f8:  92 10 20 00  clr  %o1
a00af3fc:  98 10 00 08  mov  %o0, %o4
a00af400:  94 10 00 18  mov  %i0, %o2
a00af404:  90 10 20 00  clr  %o0
a00af408:  92 10 20 28  mov  0x28, %o1
a00af40c:  96 10 20 01  mov  1, %o3
a00af410:  9a 10 20 00  clr  %o5
a00af414:  7f ff cf 64  call  0xa00a31a4
a00af418:  a2 04 60 01  inc  %l1
a00af41c:  b2 0c 60 ff  and  %l1, 0xff, %i1
a00af420:  80 a6 60 02  cmp  %i1, 2
a00af424:  08 bf ff e0  bleu  0xa00af3a4
a00af428:  98 06 40 19  add  %i1, %i1, %o4
a00af42c:  30 80 00 06  b,a   0xa00af444
a00af430:  a2 10 20 01  mov  1, %l1
a00af434:  e2 2f bf ee  stb  %l1, [ %fp + -18 ]
a00af438:  e2 2f bf eb  stb  %l1, [ %fp + -21 ]
a00af43c:  10 bf fe e1  b  0xa00aefc0
a00af440:  e2 2f bf ec  stb  %l1, [ %fp + -20 ]
a00af444:  81 c7 e0 08  ret
a00af448:  81 e8 00 00  restore
