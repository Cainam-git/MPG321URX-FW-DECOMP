# leon2m FUN_a01350dc 0xa01350dc-0xa0135344 (616 bytes)
a01350dc:  9d e3 bf 78  save  %sp, -136, %sp
a01350e0:  98 10 20 00  clr  %o4
a01350e4:  9a 10 20 00  clr  %o5
a01350e8:  03 2a 00 b6  sethi  %hi(0xa802d800), %g1
a01350ec:  d8 3f bf e8  std  %o4, [ %fp + -24 ]
a01350f0:  d8 3f bf e0  std  %o4, [ %fp + -32 ]
a01350f4:  c0 27 bf f0  clr  [ %fp + -16 ]
a01350f8:  a8 10 62 6c  or  %g1, 0x26c, %l4
a01350fc:  a6 10 20 64  mov  0x64, %l3
a0135100:  23 2a 00 b2  sethi  %hi(0xa802c800), %l1
a0135104:  aa 07 bf e0  add  %fp, -32, %l5
a0135108:  c0 27 bf dc  clr  [ %fp + -36 ]
a013510c:  e4 0c 63 8d  ldub  [ %l1 + 0x38d ], %l2
a0135110:  10 80 00 06  b  0xa0135128
a0135114:  a0 10 20 00  clr  %l0
a0135118:  96 0c 20 ff  and  %l0, 0xff, %o3
a013511c:  80 a2 e0 03  cmp  %o3, 3
a0135120:  18 80 00 1a  bgu  0xa0135188
a0135124:  c0 2c 63 8d  clrb  [ %l1 + 0x38d ]
a0135128:  da 0c 63 8d  ldub  [ %l1 + 0x38d ], %o5
a013512c:  99 2b 60 02  sll  %o5, 2, %o4
a0135130:  96 03 00 0d  add  %o4, %o5, %o3
a0135134:  95 2a e0 02  sll  %o3, 2, %o2
a0135138:  92 02 a0 10  add  %o2, 0x10, %o1
a013513c:  90 10 20 00  clr  %o0
a0135140:  92 0a 60 fc  and  %o1, 0xfc, %o1
a0135144:  94 07 bf dc  add  %fp, -36, %o2
a0135148:  67 fd 5c e2  call  0x4008c4d0
a013514c:  96 10 20 01  mov  1, %o3
a0135150:  d0 07 bf dc  ld  [ %fp + -36 ], %o0
a0135154:  80 8a 20 0f  btst  0xf, %o0
a0135158:  02 80 00 0c  be  0xa0135188
a013515c:  96 0c 20 ff  and  %l0, 0xff, %o3
a0135160:  c2 0c 63 8d  ldub  [ %l1 + 0x38d ], %g1
a0135164:  82 00 60 01  inc  %g1
a0135168:  9e 08 60 ff  and  %g1, 0xff, %o7
a013516c:  80 a3 e0 03  cmp  %o7, 3
a0135170:  18 bf ff ea  bgu  0xa0135118
a0135174:  a0 04 20 01  inc  %l0
a0135178:  96 0c 20 ff  and  %l0, 0xff, %o3
a013517c:  80 a2 e0 03  cmp  %o3, 3
a0135180:  08 bf ff ea  bleu  0xa0135128
a0135184:  c2 2c 63 8d  stb  %g1, [ %l1 + 0x38d ]
a0135188:  80 a0 00 0b  cmp  %g0, %o3
a013518c:  90 40 20 00  addx  %g0, 0, %o0
a0135190:  92 1a e0 04  xor  %o3, 4, %o1
a0135194:  80 a0 00 09  cmp  %g0, %o1
a0135198:  a0 40 20 00  addx  %g0, 0, %l0
a013519c:  80 8a 00 10  btst  %o0, %l0
a01351a0:  02 80 00 22  be  0xa0135228
a01351a4:  80 a2 e0 04  cmp  %o3, 4
a01351a8:  e4 2c 63 8d  stb  %l2, [ %l1 + 0x38d ]
a01351ac:  10 80 00 06  b  0xa01351c4
a01351b0:  a0 10 20 00  clr  %l0
a01351b4:  96 0c 20 ff  and  %l0, 0xff, %o3
a01351b8:  80 a2 e0 03  cmp  %o3, 3
a01351bc:  18 80 00 1a  bgu  0xa0135224
a01351c0:  c0 2c 63 8d  clrb  [ %l1 + 0x38d ]
a01351c4:  de 0c 63 8d  ldub  [ %l1 + 0x38d ], %o7
a01351c8:  9b 2b e0 02  sll  %o7, 2, %o5
a01351cc:  98 03 40 0f  add  %o5, %o7, %o4
a01351d0:  97 2b 20 02  sll  %o4, 2, %o3
a01351d4:  94 02 e0 10  add  %o3, 0x10, %o2
a01351d8:  92 0a a0 fc  and  %o2, 0xfc, %o1
a01351dc:  90 10 20 00  clr  %o0
a01351e0:  94 07 bf dc  add  %fp, -36, %o2
a01351e4:  67 fd 5c bb  call  0x4008c4d0
a01351e8:  96 10 20 01  mov  1, %o3
a01351ec:  e4 07 bf dc  ld  [ %fp + -36 ], %l2
a01351f0:  80 8c a0 0f  btst  0xf, %l2
a01351f4:  02 80 00 0c  be  0xa0135224
a01351f8:  96 0c 20 ff  and  %l0, 0xff, %o3
a01351fc:  c2 0c 63 8d  ldub  [ %l1 + 0x38d ], %g1
a0135200:  82 00 60 01  inc  %g1
a0135204:  90 08 60 ff  and  %g1, 0xff, %o0
a0135208:  80 a2 20 03  cmp  %o0, 3
a013520c:  18 bf ff ea  bgu  0xa01351b4
a0135210:  a0 04 20 01  inc  %l0
a0135214:  96 0c 20 ff  and  %l0, 0xff, %o3
a0135218:  80 a2 e0 03  cmp  %o3, 3
a013521c:  08 bf ff ea  bleu  0xa01351c4
a0135220:  c2 2c 63 8d  stb  %g1, [ %l1 + 0x38d ]
a0135224:  80 a2 e0 04  cmp  %o3, 4
a0135228:  02 80 00 03  be  0xa0135234
a013522c:  a0 10 3f ff  mov  -1, %l0
a0135230:  e0 0c 63 8d  ldub  [ %l1 + 0x38d ], %l0
a0135234:  9e 0c 20 ff  and  %l0, 0xff, %o7
a0135238:  80 a3 e0 ff  cmp  %o7, 0xff
a013523c:  02 80 00 40  be  0xa013533c
a0135240:  25 2a 00 b2  sethi  %hi(0xa802c800), %l2
a0135244:  d2 0c a3 96  ldub  [ %l2 + 0x396 ], %o1	! 0xa802cb96
a0135248:  15 2a 00 b2  sethi  %hi(0xa802c800), %o2
a013524c:  e0 0a a3 97  ldub  [ %o2 + 0x397 ], %l0	! 0xa802cb97
a0135250:  98 0a 60 ff  and  %o1, 0xff, %o4
a0135254:  80 a4 00 0c  cmp  %l0, %o4
a0135258:  22 80 00 35  be,a   0xa013532c
a013525c:  c0 27 bf ec  clr  [ %fp + -20 ]
a0135260:  91 2b 20 02  sll  %o4, 2, %o0
a0135264:  a0 02 00 0c  add  %o0, %o4, %l0
a0135268:  95 2c 20 02  sll  %l0, 2, %o2
a013526c:  9a 02 80 14  add  %o2, %l4, %o5
a0135270:  d8 05 00 0a  ld  [ %l4 + %o2 ], %o4
a0135274:  a0 02 60 01  add  %o1, 1, %l0
a0135278:  d0 03 60 10  ld  [ %o5 + 0x10 ], %o0
a013527c:  d6 03 60 04  ld  [ %o5 + 4 ], %o3
a0135280:  c2 03 60 08  ld  [ %o5 + 8 ], %g1
a0135284:  d4 03 60 0c  ld  [ %o5 + 0xc ], %o2
a0135288:  92 0c 20 ff  and  %l0, 0xff, %o1
a013528c:  d8 27 bf e0  st  %o4, [ %fp + -32 ]
a0135290:  d6 27 bf e4  st  %o3, [ %fp + -28 ]
a0135294:  c2 27 bf e8  st  %g1, [ %fp + -24 ]
a0135298:  d4 27 bf ec  st  %o2, [ %fp + -20 ]
a013529c:  80 a2 60 24  cmp  %o1, 0x24
a01352a0:  08 80 00 21  bleu  0xa0135324
a01352a4:  d0 27 bf f0  st  %o0, [ %fp + -16 ]
a01352a8:  c0 2c a3 96  clrb  [ %l2 + 0x396 ]
a01352ac:  e4 07 bf e0  ld  [ %fp + -32 ], %l2
a01352b0:  80 a4 a0 00  cmp  %l2, 0
a01352b4:  02 80 00 22  be  0xa013533c
a01352b8:  9b 2b e0 02  sll  %o7, 2, %o5
a01352bc:  98 03 40 0f  add  %o5, %o7, %o4
a01352c0:  a1 2b 20 02  sll  %o4, 2, %l0
a01352c4:  96 04 20 14  add  %l0, 0x14, %o3
a01352c8:  92 0a e0 fc  and  %o3, 0xfc, %o1
a01352cc:  90 10 20 00  clr  %o0
a01352d0:  94 07 bf e4  add  %fp, -28, %o2
a01352d4:  67 fd 5c c9  call  0x4008c5f8
a01352d8:  96 10 20 04  mov  4, %o3
a01352dc:  82 04 20 10  add  %l0, 0x10, %g1
a01352e0:  92 08 60 fc  and  %g1, 0xfc, %o1
a01352e4:  90 10 20 00  clr  %o0
a01352e8:  94 10 00 15  mov  %l5, %o2
a01352ec:  67 fd 5c c3  call  0x4008c5f8
a01352f0:  96 10 20 01  mov  1, %o3
a01352f4:  d2 0c 63 8d  ldub  [ %l1 + 0x38d ], %o1
a01352f8:  82 02 60 01  add  %o1, 1, %g1
a01352fc:  9e 08 60 ff  and  %g1, 0xff, %o7
a0135300:  80 a3 e0 03  cmp  %o7, 3
a0135304:  28 80 00 03  bleu,a   0xa0135310
a0135308:  c2 2c 63 8d  stb  %g1, [ %l1 + 0x38d ]
a013530c:  c0 2c 63 8d  clrb  [ %l1 + 0x38d ]
a0135310:  a6 04 ff ff  add  %l3, -1, %l3
a0135314:  80 8c e0 ff  btst  0xff, %l3
a0135318:  32 bf ff 7d  bne,a   0xa013510c
a013531c:  c0 27 bf dc  clr  [ %fp + -36 ]
a0135320:  30 80 00 07  b,a   0xa013533c
a0135324:  10 bf ff e2  b  0xa01352ac
a0135328:  e0 2c a3 96  stb  %l0, [ %l2 + 0x396 ]
a013532c:  c0 27 bf e8  clr  [ %fp + -24 ]
a0135330:  c0 27 bf e4  clr  [ %fp + -28 ]
a0135334:  10 bf ff de  b  0xa01352ac
a0135338:  c0 27 bf e0  clr  [ %fp + -32 ]
a013533c:  81 c7 e0 08  ret
a0135340:  81 e8 00 00  restore
