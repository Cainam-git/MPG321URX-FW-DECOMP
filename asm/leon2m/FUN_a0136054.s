# leon2m FUN_a0136054 0xa0136054-0xa0136384 (816 bytes)
a0136054:  9d e3 bf 58  save  %sp, -168, %sp
a0136058:  98 10 20 00  clr  %o4
a013605c:  9a 10 20 00  clr  %o5
a0136060:  d8 3f bf e0  std  %o4, [ %fp + -32 ]
a0136064:  d8 3f bf e8  std  %o4, [ %fp + -24 ]
a0136068:  d8 3f bf d8  std  %o4, [ %fp + -40 ]
a013606c:  c0 27 bf f0  clr  [ %fp + -16 ]
a0136070:  7f ff bc 15  call  0xa01250c4
a0136074:  c0 37 bf f4  clrh  [ %fp + -12 ]
a0136078:  a0 0a 20 ff  and  %o0, 0xff, %l0
a013607c:  11 00 06 95  sethi  %hi(0x1a5400), %o0
a0136080:  90 12 21 40  or  %o0, 0x140, %o0	! 0x1a5540
a0136084:  7f fe a4 3b  call  0xa00df170
a0136088:  92 10 00 10  mov  %l0, %o1
a013608c:  80 a4 20 ff  cmp  %l0, 0xff
a0136090:  a2 10 20 01  mov  1, %l1
a0136094:  b2 10 20 10  mov  0x10, %i1
a0136098:  02 80 00 b9  be  0xa013637c
a013609c:  aa 10 20 00  clr  %l5
a01360a0:  40 00 30 5e  call  0xa0142218
a01360a4:  90 10 00 10  mov  %l0, %o0
a01360a8:  40 00 30 47  call  0xa01421c4
a01360ac:  90 0a 20 ff  and  %o0, 0xff, %o0
a01360b0:  40 00 30 6f  call  0xa014226c
a01360b4:  90 0a 20 ff  and  %o0, 0xff, %o0
a01360b8:  90 10 00 10  mov  %l0, %o0
a01360bc:  7f ff ba b3  call  0xa0124b88
a01360c0:  92 07 bf d0  add  %fp, -48, %o1
a01360c4:  80 a4 20 05  cmp  %l0, 5
a01360c8:  02 80 00 06  be  0xa01360e0
a01360cc:  e8 07 bf d0  ld  [ %fp + -48 ], %l4
a01360d0:  82 1c 20 06  xor  %l0, 6, %g1
a01360d4:  80 a0 00 01  cmp  %g0, %g1
a01360d8:  9a 40 20 00  addx  %g0, 0, %o5
a01360dc:  a2 10 00 0d  mov  %o5, %l1
a01360e0:  ae 0c 60 ff  and  %l1, 0xff, %l7
a01360e4:  ad 35 20 0b  srl  %l4, 0xb, %l6
a01360e8:  a7 2d e0 02  sll  %l7, 2, %l3
a01360ec:  a4 0d a0 01  and  %l6, 1, %l2
a01360f0:  a3 35 20 08  srl  %l4, 8, %l1
a01360f4:  a0 14 ff f2  or  %l3, -14, %l0
a01360f8:  98 10 20 01  mov  1, %o4
a01360fc:  94 10 3f ff  mov  -1, %o2
a0136100:  9e 14 a0 60  or  %l2, 0x60, %o7
a0136104:  96 0c 60 03  and  %l1, 3, %o3
a0136108:  e0 2f bf e8  stb  %l0, [ %fp + -24 ]
a013610c:  92 10 20 02  mov  2, %o1
a0136110:  de 2f bf e9  stb  %o7, [ %fp + -23 ]
a0136114:  d2 2f bf ec  stb  %o1, [ %fp + -20 ]
a0136118:  d4 2f bf ee  stb  %o2, [ %fp + -18 ]
a013611c:  d8 2f bf f0  stb  %o4, [ %fp + -16 ]
a0136120:  d6 2f bf f1  stb  %o3, [ %fp + -15 ]
a0136124:  d4 2f bf ea  stb  %o2, [ %fp + -22 ]
a0136128:  d8 2f bf eb  stb  %o4, [ %fp + -21 ]
a013612c:  d8 2f bf ed  stb  %o4, [ %fp + -19 ]
a0136130:  d8 2f bf ef  stb  %o4, [ %fp + -17 ]
a0136134:  29 2a 00 b2  sethi  %hi(0xa802c800), %l4
a0136138:  2d 2a 00 b2  sethi  %hi(0xa802c800), %l6
a013613c:  10 80 00 04  b  0xa013614c
a0136140:  a0 10 20 0a  mov  0xa, %l0
a0136144:  7f ff fb e6  call  0xa01350dc
a0136148:  01 00 00 00  nop
a013614c:  d6 0d 23 97  ldub  [ %l4 + 0x397 ], %o3
a0136150:  d8 0d a3 96  ldub  [ %l6 + 0x396 ], %o4
a0136154:  b8 0a e0 ff  and  %o3, 0xff, %i4
a0136158:  b6 0b 20 ff  and  %o4, 0xff, %i3
a013615c:  b4 26 c0 1c  sub  %i3, %i4, %i2
a0136160:  92 0a e0 ff  and  %o3, 0xff, %o1
a0136164:  94 0b 20 ff  and  %o4, 0xff, %o2
a0136168:  80 a2 40 0a  cmp  %o1, %o2
a013616c:  18 80 00 09  bgu  0xa0136190
a0136170:  82 06 a0 24  add  %i2, 0x24, %g1
a0136174:  ba 0b 20 ff  and  %o4, 0xff, %i5
a0136178:  90 0a e0 ff  and  %o3, 0xff, %o0
a013617c:  80 a2 40 0a  cmp  %o1, %o2
a0136180:  9a 27 40 08  sub  %i5, %o0, %o5
a0136184:  1a 80 00 03  bcc  0xa0136190
a0136188:  82 10 20 24  mov  0x24, %g1
a013618c:  82 03 7f ff  add  %o5, -1, %g1
a0136190:  83 28 60 14  sll  %g1, 0x14, %g1
a0136194:  9b 30 60 10  srl  %g1, 0x10, %o5
a0136198:  80 a4 00 0d  cmp  %l0, %o5
a013619c:  18 bf ff ea  bgu  0xa0136144
a01361a0:  19 2a 00 b6  sethi  %hi(0xa802d800), %o4
a01361a4:  ae 13 22 6c  or  %o4, 0x26c, %l7	! 0xa802da6c
a01361a8:  a6 10 20 00  clr  %l3
a01361ac:  b4 07 bf f8  add  %fp, -8, %i2
a01361b0:  39 00 06 95  sethi  %hi(0x1a5400), %i4
a01361b4:  b6 07 bf e8  add  %fp, -24, %i3
a01361b8:  a2 07 bf d8  add  %fp, -40, %l1
a01361bc:  ba 10 20 0a  mov  0xa, %i5
a01361c0:  97 2c e0 10  sll  %l3, 0x10, %o3
a01361c4:  a5 32 e0 10  srl  %o3, 0x10, %l2
a01361c8:  94 27 40 12  sub  %i5, %l2, %o2
a01361cc:  80 a2 a0 0f  cmp  %o2, 0xf
a01361d0:  24 80 00 02  ble,a   0xa01361d8
a01361d4:  b2 27 40 13  sub  %i5, %l3, %i1
a01361d8:  82 06 80 12  add  %i2, %l2, %g1
a01361dc:  d2 08 7f f0  ldub  [ %g1 + -16 ], %o1
a01361e0:  d4 08 7f f1  ldub  [ %g1 + -15 ], %o2
a01361e4:  da 08 7f f4  ldub  [ %g1 + -12 ], %o5
a01361e8:  d0 08 7f f5  ldub  [ %g1 + -11 ], %o0
a01361ec:  e0 08 7f f7  ldub  [ %g1 + -9 ], %l0
a01361f0:  d6 08 7f f2  ldub  [ %g1 + -14 ], %o3
a01361f4:  d8 08 7f f3  ldub  [ %g1 + -13 ], %o4
a01361f8:  de 08 7f f6  ldub  [ %g1 + -10 ], %o7
a01361fc:  d0 23 a0 5c  st  %o0, [ %sp + 0x5c ]
a0136200:  de 23 a0 60  st  %o7, [ %sp + 0x60 ]
a0136204:  e0 23 a0 64  st  %l0, [ %sp + 0x64 ]
a0136208:  7f fe a3 da  call  0xa00df170
a013620c:  90 17 21 50  or  %i4, 0x150, %o0
a0136210:  92 06 c0 12  add  %i3, %l2, %o1
a0136214:  94 10 20 00  clr  %o2
a0136218:  9a 10 20 00  clr  %o5
a013621c:  a5 2b 60 02  sll  %o5, 2, %l2
a0136220:  e0 0a 40 12  ldub  [ %o1 + %l2 ], %l0
a0136224:  e0 24 40 12  st  %l0, [ %l1 + %l2 ]
a0136228:  9e 04 80 09  add  %l2, %o1, %o7
a013622c:  da 0b e0 01  ldub  [ %o7 + 1 ], %o5
a0136230:  97 2c 20 08  sll  %l0, 8, %o3
a0136234:  82 02 c0 0d  add  %o3, %o5, %g1
a0136238:  c2 24 40 12  st  %g1, [ %l1 + %l2 ]
a013623c:  d8 0b e0 02  ldub  [ %o7 + 2 ], %o4
a0136240:  91 28 60 08  sll  %g1, 8, %o0
a0136244:  a0 02 00 0c  add  %o0, %o4, %l0
a0136248:  e0 24 40 12  st  %l0, [ %l1 + %l2 ]
a013624c:  da 0b e0 03  ldub  [ %o7 + 3 ], %o5
a0136250:  97 2c 20 08  sll  %l0, 8, %o3
a0136254:  98 02 c0 0d  add  %o3, %o5, %o4
a0136258:  94 02 a0 01  inc  %o2
a013625c:  9a 0a a0 ff  and  %o2, 0xff, %o5
a0136260:  80 a3 60 04  cmp  %o5, 4
a0136264:  0a bf ff ee  bcs  0xa013621c
a0136268:  d8 24 40 12  st  %o4, [ %l1 + %l2 ]
a013626c:  d4 0d 23 97  ldub  [ %l4 + 0x397 ], %o2
a0136270:  96 0a a0 ff  and  %o2, 0xff, %o3
a0136274:  98 0e 60 ff  and  %i1, 0xff, %o4
a0136278:  9f 2b 20 10  sll  %o4, 0x10, %o7
a013627c:  91 2a e0 02  sll  %o3, 2, %o0
a0136280:  a5 2d 60 18  sll  %l5, 0x18, %l2
a0136284:  92 02 00 0b  add  %o0, %o3, %o1
a0136288:  a0 04 80 0f  add  %l2, %o7, %l0
a013628c:  83 2a 60 02  sll  %o1, 2, %g1
a0136290:  9a 04 20 0b  add  %l0, 0xb, %o5
a0136294:  94 02 a0 01  inc  %o2
a0136298:  da 25 c0 01  st  %o5, [ %l7 + %g1 ]
a013629c:  a4 00 40 17  add  %g1, %l7, %l2
a01362a0:  92 0a a0 ff  and  %o2, 0xff, %o1
a01362a4:  d6 07 bf e4  ld  [ %fp + -28 ], %o3
a01362a8:  d8 07 bf d8  ld  [ %fp + -40 ], %o4
a01362ac:  d0 07 bf dc  ld  [ %fp + -36 ], %o0
a01362b0:  de 07 bf e0  ld  [ %fp + -32 ], %o7
a01362b4:  d6 24 a0 10  st  %o3, [ %l2 + 0x10 ]
a01362b8:  d8 24 a0 04  st  %o4, [ %l2 + 4 ]
a01362bc:  d0 24 a0 08  st  %o0, [ %l2 + 8 ]
a01362c0:  80 a2 60 24  cmp  %o1, 0x24
a01362c4:  08 80 00 2c  bleu  0xa0136374
a01362c8:  de 24 a0 0c  st  %o7, [ %l2 + 0xc ]
a01362cc:  c0 2d 23 97  clrb  [ %l4 + 0x397 ]
a01362d0:  9a 04 e0 10  add  %l3, 0x10, %o5
a01362d4:  83 2b 60 10  sll  %o5, 0x10, %g1
a01362d8:  a7 30 60 10  srl  %g1, 0x10, %l3
a01362dc:  80 a4 e0 09  cmp  %l3, 9
a01362e0:  aa 05 60 01  inc  %l5
a01362e4:  08 bf ff b7  bleu  0xa01361c0
a01362e8:  a6 10 00 0d  mov  %o5, %l3
a01362ec:  10 80 00 04  b  0xa01362fc
a01362f0:  c0 27 bf cc  clr  [ %fp + -52 ]
a01362f4:  7f ff fb 7a  call  0xa01350dc
a01362f8:  01 00 00 00  nop
a01362fc:  f2 0d 23 97  ldub  [ %l4 + 0x397 ], %i1
a0136300:  ea 0d a3 96  ldub  [ %l6 + 0x396 ], %l5
a0136304:  80 a6 40 15  cmp  %i1, %l5
a0136308:  12 bf ff fb  bne  0xa01362f4
a013630c:  a2 10 20 00  clr  %l1
a0136310:  a0 10 20 00  clr  %l0
a0136314:  98 10 20 00  clr  %o4
a0136318:  93 2b 20 02  sll  %o4, 2, %o1
a013631c:  94 02 40 0c  add  %o1, %o4, %o2
a0136320:  bb 2a a0 02  sll  %o2, 2, %i5
a0136324:  b8 07 60 10  add  %i5, 0x10, %i4
a0136328:  92 0f 20 fc  and  %i4, 0xfc, %o1
a013632c:  90 10 20 00  clr  %o0
a0136330:  94 07 bf cc  add  %fp, -52, %o2
a0136334:  67 fd 58 67  call  0x4008c4d0
a0136338:  96 10 20 01  mov  1, %o3
a013633c:  a0 04 20 01  inc  %l0
a0136340:  98 0c 20 ff  and  %l0, 0xff, %o4
a0136344:  b7 2b 20 02  sll  %o4, 2, %i3
a0136348:  b4 06 c0 0c  add  %i3, %o4, %i2
a013634c:  af 2e a0 02  sll  %i2, 2, %l7
a0136350:  a8 05 e0 10  add  %l7, 0x10, %l4
a0136354:  ec 07 bf cc  ld  [ %fp + -52 ], %l6
a0136358:  80 a5 20 50  cmp  %l4, 0x50
a013635c:  04 bf ff ef  ble  0xa0136318
a0136360:  a2 14 40 16  or  %l1, %l6, %l1
a0136364:  80 a4 60 00  cmp  %l1, 0
a0136368:  12 bf ff ea  bne  0xa0136310
a013636c:  a2 10 20 00  clr  %l1
a0136370:  30 80 00 03  b,a   0xa013637c
a0136374:  10 bf ff d7  b  0xa01362d0
a0136378:  d4 2d 23 97  stb  %o2, [ %l4 + 0x397 ]
a013637c:  81 c7 e0 08  ret
a0136380:  81 e8 00 00  restore
