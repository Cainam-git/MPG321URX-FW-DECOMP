# leon2m FUN_a0083ff0 0xa0083ff0-0xa0084330 (832 bytes)
a0083ff0:  9d e3 bf 98  save  %sp, -104, %sp
a0083ff4:  40 00 33 f6  call  0xa0090fcc
a0083ff8:  01 00 00 00  nop
a0083ffc:  83 2a 20 10  sll  %o0, 0x10, %g1
a0084000:  91 30 60 10  srl  %g1, 0x10, %o0
a0084004:  80 a2 20 3b  cmp  %o0, 0x3b
a0084008:  08 80 00 09  bleu  0xa008402c
a008400c:  01 00 00 00  nop
a0084010:  40 00 33 ef  call  0xa0090fcc
a0084014:  01 00 00 00  nop
a0084018:  95 2a 20 10  sll  %o0, 0x10, %o2
a008401c:  93 32 a0 10  srl  %o2, 0x10, %o1
a0084020:  80 a2 60 3e  cmp  %o1, 0x3e
a0084024:  08 80 00 c1  bleu  0xa0084328
a0084028:  01 00 00 00  nop
a008402c:  40 00 33 e8  call  0xa0090fcc
a0084030:  01 00 00 00  nop
a0084034:  99 2a 20 10  sll  %o0, 0x10, %o4
a0084038:  97 33 20 10  srl  %o4, 0x10, %o3
a008403c:  80 a2 e1 04  cmp  %o3, 0x104
a0084040:  02 80 00 ba  be  0xa0084328
a0084044:  9a 0e 20 ff  and  %i0, 0xff, %o5
a0084048:  80 a3 60 01  cmp  %o5, 1
a008404c:  02 80 00 56  be  0xa00841a4
a0084050:  29 2a 00 90  sethi  %hi(0xa8024000), %l4
a0084054:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a0084058:  b0 14 22 90  or  %l0, 0x290, %i0	! 0xa802d290
a008405c:  e2 0e 21 d5  ldub  [ %i0 + 0x1d5 ], %l1
a0084060:  80 a0 00 11  cmp  %g0, %l1
a0084064:  a6 40 3f ff  addx  %g0, -1, %l3
a0084068:  e4 0d 20 1d  ldub  [ %l4 + 0x1d ], %l2
a008406c:  d8 0e 21 7c  ldub  [ %i0 + 0x17c ], %o4
a0084070:  80 a3 20 00  cmp  %o4, 0
a0084074:  02 80 00 58  be  0xa00841d4
a0084078:  a2 0c c0 12  and  %l3, %l2, %l1
a008407c:  80 a3 20 01  cmp  %o4, 1
a0084080:  02 80 00 86  be  0xa0084298
a0084084:  01 00 00 00  nop
a0084088:  40 02 86 80  call  0xa0125a88
a008408c:  01 00 00 00  nop
a0084090:  92 0a 20 ff  and  %o0, 0xff, %o1
a0084094:  80 a0 00 09  cmp  %g0, %o1
a0084098:  90 40 3f ff  addx  %g0, -1, %o0
a008409c:  a2 12 20 01  or  %o0, 1, %l1
a00840a0:  b0 0c 60 ff  and  %l1, 0xff, %i0
a00840a4:  c2 0d 20 1d  ldub  [ %l4 + 0x1d ], %g1
a00840a8:  80 a6 00 01  cmp  %i0, %g1
a00840ac:  02 80 00 0c  be  0xa00840dc
a00840b0:  80 a6 20 ff  cmp  %i0, 0xff
a00840b4:  02 80 00 6a  be  0xa008425c
a00840b8:  01 00 00 00  nop
a00840bc:  40 02 86 5c  call  0xa0125a2c
a00840c0:  90 10 00 18  mov  %i0, %o0
a00840c4:  40 02 86 4c  call  0xa01259f4
a00840c8:  01 00 00 00  nop
a00840cc:  17 00 03 fb  sethi  %hi(0xfec00), %o3
a00840d0:  90 12 e3 50  or  %o3, 0x350, %o0	! 0xfef50
a00840d4:  40 01 6c 27  call  0xa00df170
a00840d8:  92 10 00 18  mov  %i0, %o1
a00840dc:  96 14 22 90  or  %l0, 0x290, %o3
a00840e0:  de 0a e0 1f  ldub  [ %o3 + 0x1f ], %o7
a00840e4:  9a 1b e0 02  xor  %o7, 2, %o5
a00840e8:  80 a0 00 0d  cmp  %g0, %o5
a00840ec:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00840f0:  a0 60 3f ff  subx  %g0, -1, %l0
a00840f4:  f0 0b 22 88  ldub  [ %o4 + 0x288 ], %i0
a00840f8:  80 a6 20 01  cmp  %i0, 1
a00840fc:  02 80 00 22  be  0xa0084184
a0084100:  b0 10 00 10  mov  %l0, %i0
a0084104:  a0 10 20 00  clr  %l0
a0084108:  25 2a 00 90  sethi  %hi(0xa8024000), %l2
a008410c:  c2 0c a0 1e  ldub  [ %l2 + 0x1e ], %g1	! 0xa802401e
a0084110:  92 0e 20 ff  and  %i0, 0xff, %o1
a0084114:  80 a0 40 09  cmp  %g1, %o1
a0084118:  02 80 00 4a  be  0xa0084240
a008411c:  27 2a 00 90  sethi  %hi(0xa8024000), %l3
a0084120:  98 16 00 10  or  %i0, %l0, %o4
a0084124:  80 8b 20 ff  btst  0xff, %o4
a0084128:  02 80 00 12  be  0xa0084170
a008412c:  01 00 00 00  nop
a0084130:  90 10 20 16  mov  0x16, %o0	! 0x16
a0084134:  40 00 0a 1f  call  0xa00869b0
a0084138:  92 10 23 e8  mov  0x3e8, %o1
a008413c:  03 2a 00 b3  sethi  %hi(0xa802cc00), %g1
a0084140:  9e 10 63 f4  or  %g1, 0x3f4, %o7	! 0xa802cff4
a0084144:  d2 13 e0 04  lduh  [ %o7 + 4 ], %o1
a0084148:  90 12 68 00  or  %o1, 0x800, %o0
a008414c:  d0 33 e0 04  sth  %o0, [ %o7 + 4 ]
a0084150:  1b 00 03 fb  sethi  %hi(0xfec00), %o5
a0084154:  90 13 63 68  or  %o5, 0x368, %o0	! 0xfef68
a0084158:  40 01 6c 06  call  0xa00df170
a008415c:  01 00 00 00  nop
a0084160:  f0 2c a0 1e  stb  %i0, [ %l2 + 0x1e ]
a0084164:  e0 2c e0 1f  stb  %l0, [ %l3 + 0x1f ]
a0084168:  10 80 00 70  b  0xa0084328
a008416c:  e2 2d 20 1d  stb  %l1, [ %l4 + 0x1d ]
a0084170:  40 02 86 93  call  0xa0125bbc
a0084174:  90 10 20 00  clr  %o0
a0084178:  15 00 03 fb  sethi  %hi(0xfec00), %o2
a008417c:  10 bf ff f7  b  0xa0084158
a0084180:  90 12 a3 98  or  %o2, 0x398, %o0	! 0xfef98
a0084184:  11 00 00 15  sethi  %hi(0x5400), %o0
a0084188:  e6 12 e1 f6  lduh  [ %o3 + 0x1f6 ], %l3
a008418c:  a4 12 21 aa  or  %o0, 0x1aa, %l2
a0084190:  80 a4 c0 12  cmp  %l3, %l2
a0084194:  12 bf ff dc  bne  0xa0084104
a0084198:  a0 10 20 01  mov  1, %l0
a008419c:  10 bf ff dc  b  0xa008410c
a00841a0:  25 2a 00 90  sethi  %hi(0xa8024000), %l2
a00841a4:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a00841a8:  b0 14 22 90  or  %l0, 0x290, %i0	! 0xa802d290
a00841ac:  e2 0e 21 d5  ldub  [ %i0 + 0x1d5 ], %l1
a00841b0:  9e 10 3f ff  mov  -1, %o7
a00841b4:  80 a0 00 11  cmp  %g0, %l1
a00841b8:  de 2d 20 1d  stb  %o7, [ %l4 + 0x1d ]
a00841bc:  a6 40 3f ff  addx  %g0, -1, %l3
a00841c0:  e4 0d 20 1d  ldub  [ %l4 + 0x1d ], %l2
a00841c4:  d8 0e 21 7c  ldub  [ %i0 + 0x17c ], %o4
a00841c8:  80 a3 20 00  cmp  %o4, 0
a00841cc:  12 bf ff ac  bne  0xa008407c
a00841d0:  a2 0c c0 12  and  %l3, %l2, %l1
a00841d4:  40 02 86 23  call  0xa0125a60
a00841d8:  01 00 00 00  nop
a00841dc:  80 8a 20 ff  btst  0xff, %o0
a00841e0:  12 80 00 07  bne  0xa00841fc
a00841e4:  01 00 00 00  nop
a00841e8:  40 02 86 28  call  0xa0125a88
a00841ec:  01 00 00 00  nop
a00841f0:  80 8a 20 ff  btst  0xff, %o0
a00841f4:  02 80 00 40  be  0xa00842f4
a00841f8:  03 00 00 15  sethi  %hi(0x5400), %g1
a00841fc:  40 02 fe 86  call  0xa0143c14
a0084200:  90 10 20 00  clr  %o0
a0084204:  b0 0a 20 ff  and  %o0, 0xff, %i0
a0084208:  80 a6 20 0a  cmp  %i0, 0xa
a008420c:  02 80 00 05  be  0xa0084220
a0084210:  d6 04 22 90  ld  [ %l0 + 0x290 ], %o3
a0084214:  80 8a e2 00  btst  0x200, %o3
a0084218:  12 80 00 26  bne  0xa00842b0
a008421c:  98 14 22 90  or  %l0, 0x290, %o4
a0084220:  40 03 00 9b  call  0xa014448c
a0084224:  90 10 20 00  clr  %o0
a0084228:  9e 0a 20 ff  and  %o0, 0xff, %o7
a008422c:  9a 1b e0 0d  xor  %o7, 0xd, %o5
a0084230:  80 a0 00 0d  cmp  %g0, %o5
a0084234:  98 60 3f ff  subx  %g0, -1, %o4
a0084238:  10 bf ff 9a  b  0xa00840a0
a008423c:  a2 10 00 0c  mov  %o4, %l1
a0084240:  d6 0c e0 1f  ldub  [ %l3 + 0x1f ], %o3
a0084244:  94 0c 20 ff  and  %l0, 0xff, %o2
a0084248:  80 a2 c0 0a  cmp  %o3, %o2
a008424c:  12 bf ff b6  bne  0xa0084124
a0084250:  98 16 00 10  or  %i0, %l0, %o4
a0084254:  10 bf ff c4  b  0xa0084164
a0084258:  f0 2c a0 1e  stb  %i0, [ %l2 + 0x1e ]
a008425c:  40 02 85 d9  call  0xa01259c0
a0084260:  90 10 20 00  clr  %o0
a0084264:  94 14 22 90  or  %l0, 0x290, %o2
a0084268:  c2 0a a1 7c  ldub  [ %o2 + 0x17c ], %g1
a008426c:  80 a0 60 01  cmp  %g1, 1
a0084270:  02 80 00 06  be  0xa0084288
a0084274:  90 10 20 00  clr  %o0
a0084278:  80 a0 60 02  cmp  %g1, 2
a008427c:  32 bf ff 95  bne,a   0xa00840d0
a0084280:  17 00 03 fb  sethi  %hi(0xfec00), %o3
a0084284:  90 10 20 01  mov  1, %o0
a0084288:  40 02 85 e9  call  0xa0125a2c
a008428c:  01 00 00 00  nop
a0084290:  10 bf ff 90  b  0xa00840d0
a0084294:  17 00 03 fb  sethi  %hi(0xfec00), %o3
a0084298:  40 02 85 f2  call  0xa0125a60
a008429c:  01 00 00 00  nop
a00842a0:  a2 0a 20 ff  and  %o0, 0xff, %l1
a00842a4:  80 a0 00 11  cmp  %g0, %l1
a00842a8:  10 bf ff 7e  b  0xa00840a0
a00842ac:  a2 40 3f ff  addx  %g0, -1, %l1
a00842b0:  e6 03 20 a8  ld  [ %o4 + 0xa8 ], %l3
a00842b4:  25 00 00 20  sethi  %hi(0x8000), %l2
a00842b8:  80 8c c0 12  btst  %l3, %l2
a00842bc:  02 bf ff 7a  be  0xa00840a4
a00842c0:  b0 0c 60 ff  and  %l1, 0xff, %i0
a00842c4:  c2 0b 20 1e  ldub  [ %o4 + 0x1e ], %g1
a00842c8:  80 a0 60 0d  cmp  %g1, 0xd
a00842cc:  02 80 00 15  be  0xa0084320
a00842d0:  80 a0 60 0c  cmp  %g1, 0xc
a00842d4:  02 80 00 06  be  0xa00842ec
a00842d8:  80 a0 60 05  cmp  %g1, 5
a00842dc:  02 80 00 04  be  0xa00842ec
a00842e0:  80 a0 60 06  cmp  %g1, 6
a00842e4:  12 bf ff 71  bne  0xa00840a8
a00842e8:  c2 0d 20 1d  ldub  [ %l4 + 0x1d ], %g1
a00842ec:  10 bf ff 6d  b  0xa00840a0
a00842f0:  a2 10 20 00  clr  %l1
a00842f4:  d2 16 21 f6  lduh  [ %i0 + 0x1f6 ], %o1
a00842f8:  90 10 61 aa  or  %g1, 0x1aa, %o0
a00842fc:  80 a2 40 08  cmp  %o1, %o0
a0084300:  12 bf ff 68  bne  0xa00840a0
a0084304:  a2 10 3f ff  mov  -1, %l1
a0084308:  d4 0e 21 d6  ldub  [ %i0 + 0x1d6 ], %o2
a008430c:  80 a2 a0 55  cmp  %o2, 0x55
a0084310:  02 bf ff 64  be  0xa00840a0
a0084314:  a2 10 20 00  clr  %l1
a0084318:  10 bf ff 62  b  0xa00840a0
a008431c:  a2 10 3f ff  mov  -1, %l1
a0084320:  10 bf ff 60  b  0xa00840a0
a0084324:  a2 10 20 01  mov  1, %l1
a0084328:  81 c7 e0 08  ret
a008432c:  81 e8 00 00  restore
