# leon2m FUN_a01370dc 0xa01370dc-0xa013730c (560 bytes)
a01370dc:  9d e3 bf 78  save  %sp, -136, %sp
a01370e0:  98 10 20 00  clr  %o4
a01370e4:  9a 10 20 00  clr  %o5
a01370e8:  d8 3f bf f0  std  %o4, [ %fp + -16 ]
a01370ec:  d8 3f bf d8  std  %o4, [ %fp + -40 ]
a01370f0:  d8 3f bf e0  std  %o4, [ %fp + -32 ]
a01370f4:  d8 3f bf e8  std  %o4, [ %fp + -24 ]
a01370f8:  a2 10 20 00  clr  %l1
a01370fc:  a0 10 20 64  mov  0x64, %l0
a0137100:  a4 07 bf d8  add  %fp, -40, %l2
a0137104:  90 10 20 01  mov  1, %o0
a0137108:  92 10 20 80  mov  0x80, %o1
a013710c:  94 10 00 12  mov  %l2, %o2
a0137110:  67 fd 54 f0  call  0x4008c4d0
a0137114:  96 10 20 01  mov  1, %o3
a0137118:  c2 07 bf d8  ld  [ %fp + -40 ], %g1
a013711c:  90 10 20 01  mov  1, %o0
a0137120:  80 a0 60 00  cmp  %g1, 0
a0137124:  02 80 00 07  be  0xa0137140
a0137128:  a0 04 3f ff  add  %l0, -1, %l0
a013712c:  67 fd 58 1d  call  0x4008d1a0
a0137130:  01 00 00 00  nop
a0137134:  80 8c 20 ff  btst  0xff, %l0
a0137138:  12 bf ff f4  bne  0xa0137108
a013713c:  90 10 20 01  mov  1, %o0
a0137140:  a0 0e 60 ff  and  %i1, 0xff, %l0
a0137144:  80 a4 20 1c  cmp  %l0, 0x1c
a0137148:  08 80 00 05  bleu  0xa013715c
a013714c:  9f 34 20 02  srl  %l0, 2, %o7
a0137150:  b2 10 20 1c  mov  0x1c, %i1
a0137154:  a0 10 20 1c  mov  0x1c, %l0
a0137158:  9f 34 20 02  srl  %l0, 2, %o7
a013715c:  80 a3 e0 00  cmp  %o7, 0
a0137160:  a8 0c 20 03  and  %l0, 3, %l4
a0137164:  02 80 00 18  be  0xa01371c4
a0137168:  90 10 20 00  clr  %o0
a013716c:  92 10 20 00  clr  %o1
a0137170:  a6 07 bf f8  add  %fp, -8, %l3
a0137174:  98 0c 60 ff  and  %l1, 0xff, %o4
a0137178:  96 03 00 1a  add  %o4, %i2, %o3
a013717c:  d4 0a e0 01  ldub  [ %o3 + 1 ], %o2
a0137180:  83 2a a0 08  sll  %o2, 8, %g1
a0137184:  da 0b 00 1a  ldub  [ %o4 + %i2 ], %o5
a0137188:  d4 0a e0 02  ldub  [ %o3 + 2 ], %o2
a013718c:  9a 13 40 01  or  %o5, %g1, %o5
a0137190:  99 2a a0 10  sll  %o2, 0x10, %o4
a0137194:  c2 0a e0 03  ldub  [ %o3 + 3 ], %g1
a0137198:  95 2a 60 02  sll  %o1, 2, %o2
a013719c:  96 13 40 0c  or  %o5, %o4, %o3
a01371a0:  93 28 60 18  sll  %g1, 0x18, %o1
a01371a4:  9a 12 c0 09  or  %o3, %o1, %o5
a01371a8:  90 02 20 01  inc  %o0
a01371ac:  96 02 80 13  add  %o2, %l3, %o3
a01371b0:  92 0a 20 ff  and  %o0, 0xff, %o1
a01371b4:  da 22 ff e4  st  %o5, [ %o3 + -28 ]
a01371b8:  80 a2 40 0f  cmp  %o1, %o7
a01371bc:  0a bf ff ee  bcs  0xa0137174
a01371c0:  a2 04 60 04  add  %l1, 4, %l1
a01371c4:  96 0d 20 ff  and  %l4, 0xff, %o3
a01371c8:  80 a2 e0 00  cmp  %o3, 0
a01371cc:  22 80 00 16  be,a   0xa0137224
a01371d0:  a0 06 60 04  add  %i1, 4, %l0
a01371d4:  80 a2 e0 00  cmp  %o3, 0
a01371d8:  02 80 00 12  be  0xa0137220
a01371dc:  92 10 20 00  clr  %o1
a01371e0:  9e 0c 60 ff  and  %l1, 0xff, %o7
a01371e4:  a2 0c 20 fc  and  %l0, 0xfc, %l1
a01371e8:  a0 07 bf f8  add  %fp, -8, %l0
a01371ec:  90 04 40 10  add  %l1, %l0, %o0
a01371f0:  94 03 c0 1a  add  %o7, %i2, %o2
a01371f4:  9a 10 20 00  clr  %o5
a01371f8:  83 2b 60 03  sll  %o5, 3, %g1
a01371fc:  da 0a 80 0d  ldub  [ %o2 + %o5 ], %o5
a0137200:  b5 2b 40 01  sll  %o5, %g1, %i2
a0137204:  e8 02 3f e4  ld  [ %o0 + -28 ], %l4
a0137208:  92 02 60 01  inc  %o1
a013720c:  a6 15 00 1a  or  %l4, %i2, %l3
a0137210:  9a 0a 60 ff  and  %o1, 0xff, %o5
a0137214:  80 a3 40 0b  cmp  %o5, %o3
a0137218:  0a bf ff f8  bcs  0xa01371f8
a013721c:  e6 22 3f e4  st  %l3, [ %o0 + -28 ]
a0137220:  a0 06 60 04  add  %i1, 4, %l0
a0137224:  9e 0c 20 ff  and  %l0, 0xff, %o7
a0137228:  99 2e 20 08  sll  %i0, 8, %o4
a013722c:  95 2b e0 10  sll  %o7, 0x10, %o2
a0137230:  96 13 00 0a  or  %o4, %o2, %o3
a0137234:  13 00 3f ff  sethi  %hi(0xfffc00), %o1
a0137238:  b0 12 e0 55  or  %o3, 0x55, %i0
a013723c:  b2 12 63 ff  or  %o1, 0x3ff, %i1
a0137240:  90 0e 00 19  and  %i0, %i1, %o0
a0137244:  d0 27 bf d8  st  %o0, [ %fp + -40 ]
a0137248:  98 10 20 00  clr  %o4
a013724c:  94 10 20 00  clr  %o2
a0137250:  82 10 20 00  clr  %g1
a0137254:  b1 28 60 02  sll  %g1, 2, %i0
a0137258:  e8 04 80 18  ld  [ %l2 + %i0 ], %l4
a013725c:  90 1d 00 0c  xor  %l4, %o4, %o0
a0137260:  83 35 20 08  srl  %l4, 8, %g1
a0137264:  b4 1a 00 01  xor  %o0, %g1, %i2
a0137268:  9b 35 20 10  srl  %l4, 0x10, %o5
a013726c:  94 02 a0 01  inc  %o2
a0137270:  a2 1e 80 0d  xor  %i2, %o5, %l1
a0137274:  a7 35 20 18  srl  %l4, 0x18, %l3
a0137278:  82 0a a0 ff  and  %o2, 0xff, %g1
a013727c:  80 a0 60 08  cmp  %g1, 8
a0137280:  0a bf ff f5  bcs  0xa0137254
a0137284:  98 1c 40 13  xor  %l1, %l3, %o4
a0137288:  97 2b 20 18  sll  %o4, 0x18, %o3
a013728c:  d2 04 80 00  ld  [ %l2 ], %o1
a0137290:  b2 12 40 0b  or  %o1, %o3, %i1
a0137294:  90 10 20 01  mov  1, %o0
a0137298:  92 10 20 80  mov  0x80, %o1
a013729c:  94 10 00 12  mov  %l2, %o2
a01372a0:  96 10 20 08  mov  8, %o3
a01372a4:  67 fd 54 d5  call  0x4008c5f8
a01372a8:  f2 24 80 00  st  %i1, [ %l2 ]
a01372ac:  7f fe 9d b1  call  0xa00de970
a01372b0:  b6 0e e0 ff  and  %i3, 0xff, %i3
a01372b4:  80 a6 e0 00  cmp  %i3, 0
a01372b8:  02 80 00 13  be  0xa0137304
a01372bc:  a0 10 20 64  mov  0x64, %l0
a01372c0:  90 10 20 01  mov  1, %o0
a01372c4:  92 10 20 80  mov  0x80, %o1
a01372c8:  94 10 00 12  mov  %l2, %o2
a01372cc:  67 fd 54 81  call  0x4008c4d0
a01372d0:  96 10 20 01  mov  1, %o3
a01372d4:  d8 07 bf d8  ld  [ %fp + -40 ], %o4
a01372d8:  90 10 20 01  mov  1, %o0
a01372dc:  80 a3 20 00  cmp  %o4, 0
a01372e0:  02 80 00 09  be  0xa0137304
a01372e4:  a0 04 3f ff  add  %l0, -1, %l0
a01372e8:  67 fd 57 ae  call  0x4008d1a0
a01372ec:  01 00 00 00  nop
a01372f0:  80 8c 20 ff  btst  0xff, %l0
a01372f4:  02 80 00 04  be  0xa0137304
a01372f8:  80 a6 e0 00  cmp  %i3, 0
a01372fc:  12 bf ff f2  bne  0xa01372c4
a0137300:  90 10 20 01  mov  1, %o0
a0137304:  81 c7 e0 08  ret
a0137308:  81 e8 00 00  restore
