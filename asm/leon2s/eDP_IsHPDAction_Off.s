# leon2s eDP_IsHPDAction_Off 0xa0089090-0xa0089420 (912 bytes)
a0089090:  9d e3 bf 80  save  %sp, -128, %sp
a0089094:  98 10 20 00  clr  %o4
a0089098:  9a 10 20 00  clr  %o5
a008909c:  aa 10 20 00  clr  %l5
a00890a0:  d8 3f bf f0  std  %o4, [ %fp + -16 ]
a00890a4:  80 8e 20 ff  btst  0xff, %i0
a00890a8:  d8 3f bf e8  std  %o4, [ %fp + -24 ]
a00890ac:  c0 2f bf e7  clrb  [ %fp + -25 ]
a00890b0:  a4 10 20 00  clr  %l2
a00890b4:  02 80 00 06  be  0xa00890cc
a00890b8:  ae 10 00 15  mov  %l5, %l7
a00890bc:  03 2a 01 d8  sethi  %hi(0xa8076000), %g1
a00890c0:  ea 08 61 c0  ldub  [ %g1 + 0x1c0 ], %l5	! 0xa80761c0
a00890c4:  03 2a 01 d8  sethi  %hi(0xa8076000), %g1
a00890c8:  ee 08 61 bf  ldub  [ %g1 + 0x1bf ], %l7	! 0xa80761bf
a00890cc:  a8 0d 60 ff  and  %l5, 0xff, %l4
a00890d0:  a6 0d e0 ff  and  %l7, 0xff, %l3
a00890d4:  90 10 00 14  mov  %l4, %o0
a00890d8:  7f ff ff e0  call  0xa0089058
a00890dc:  92 10 00 13  mov  %l3, %o1
a00890e0:  d0 2f bf e7  stb  %o0, [ %fp + -25 ]
a00890e4:  80 a5 00 13  cmp  %l4, %l3
a00890e8:  b0 10 00 15  mov  %l5, %i0
a00890ec:  18 80 00 44  bgu  0xa00891fc
a00890f0:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a00890f4:  c2 08 62 0c  ldub  [ %g1 + 0x20c ], %g1	! 0xa8078a0c
a00890f8:  80 a0 60 00  cmp  %g1, 0
a00890fc:  22 80 00 3d  be,a   0xa00891f0
a0089100:  b0 06 20 01  inc  %i0
a0089104:  2d 2a 01 d8  sethi  %hi(0xa8076000), %l6
a0089108:  82 15 a1 b8  or  %l6, 0x1b8, %g1	! 0xa80761b8
a008910c:  a0 0e 20 ff  and  %i0, 0xff, %l0
a0089110:  c2 08 40 10  ldub  [ %g1 + %l0 ], %g1
a0089114:  80 a0 60 01  cmp  %g1, 1
a0089118:  12 80 00 12  bne  0xa0089160
a008911c:  01 00 00 00  nop
a0089120:  7f ff fe 74  call  0xa0088af0
a0089124:  90 10 00 10  mov  %l0, %o0
a0089128:  90 0a 20 ff  and  %o0, 0xff, %o0
a008912c:  80 a2 20 01  cmp  %o0, 1
a0089130:  12 80 00 07  bne  0xa008914c
a0089134:  a2 10 20 02  mov  2, %l1
a0089138:  11 28 01 a2  sethi  %hi(0xa0068800), %o0
a008913c:  90 12 22 70  or  %o0, 0x270, %o0	! 0xa0068a70
a0089140:  a2 10 20 01  mov  1, %l1
a0089144:  7f ff a7 c0  call  0xa0073044
a0089148:  92 10 00 10  mov  %l0, %o1
a008914c:  7f ff fe 14  call  0xa008899c
a0089150:  90 10 00 10  mov  %l0, %o0
a0089154:  82 15 a1 b8  or  %l6, 0x1b8, %g1
a0089158:  10 80 00 05  b  0xa008916c
a008915c:  c0 28 40 10  clrb  [ %g1 + %l0 ]
a0089160:  7f ff fe 0f  call  0xa008899c
a0089164:  90 10 00 10  mov  %l0, %o0
a0089168:  a2 10 00 08  mov  %o0, %l1
a008916c:  90 0c 60 ff  and  %l1, 0xff, %o0
a0089170:  80 a2 20 01  cmp  %o0, 1
a0089174:  12 80 00 08  bne  0xa0089194
a0089178:  80 a2 20 02  cmp  %o0, 2
a008917c:  11 28 01 a2  sethi  %hi(0xa0068800), %o0
a0089180:  90 12 22 a8  or  %o0, 0x2a8, %o0	! 0xa0068aa8
a0089184:  7f ff a7 b0  call  0xa0073044
a0089188:  92 0e 20 ff  and  %i0, 0xff, %o1
a008918c:  10 80 00 09  b  0xa00891b0
a0089190:  a4 14 a0 09  or  %l2, 9, %l2
a0089194:  12 80 00 08  bne  0xa00891b4
a0089198:  a0 0e 20 ff  and  %i0, 0xff, %l0
a008919c:  11 28 01 a2  sethi  %hi(0xa0068800), %o0
a00891a0:  90 12 22 c0  or  %o0, 0x2c0, %o0	! 0xa0068ac0
a00891a4:  7f ff a7 a8  call  0xa0073044
a00891a8:  92 0e 20 ff  and  %i0, 0xff, %o1
a00891ac:  a4 14 a0 40  or  %l2, 0x40, %l2
a00891b0:  a0 0e 20 ff  and  %i0, 0xff, %l0
a00891b4:  7f ff fe 33  call  0xa0088a80
a00891b8:  90 10 00 10  mov  %l0, %o0
a00891bc:  80 8a 20 ff  btst  0xff, %o0
a00891c0:  22 80 00 0c  be,a   0xa00891f0
a00891c4:  b0 06 20 01  inc  %i0
a00891c8:  11 28 01 a2  sethi  %hi(0xa0068800), %o0
a00891cc:  7f ff a8 be  call  0xa00734c4
a00891d0:  90 12 22 e0  or  %o0, 0x2e0, %o0	! 0xa0068ae0
a00891d4:  7f ff fe 47  call  0xa0088af0
a00891d8:  90 10 00 10  mov  %l0, %o0
a00891dc:  90 0a 20 ff  and  %o0, 0xff, %o0
a00891e0:  80 a2 20 01  cmp  %o0, 1
a00891e4:  22 80 00 02  be,a   0xa00891ec
a00891e8:  a4 14 a0 08  or  %l2, 8, %l2
a00891ec:  b0 06 20 01  inc  %i0
a00891f0:  82 0e 20 ff  and  %i0, 0xff, %g1
a00891f4:  10 bf ff be  b  0xa00890ec
a00891f8:  80 a0 40 13  cmp  %g1, %l3
a00891fc:  a6 0d e0 ff  and  %l7, 0xff, %l3
a0089200:  80 a5 00 13  cmp  %l4, %l3
a0089204:  b0 10 00 15  mov  %l5, %i0
a0089208:  18 80 00 1d  bgu  0xa008927c
a008920c:  a0 0e 20 ff  and  %i0, 0xff, %l0
a0089210:  7f ff ff 68  call  0xa0088fb0
a0089214:  90 10 00 10  mov  %l0, %o0
a0089218:  a2 12 00 12  or  %o0, %l2, %l1
a008921c:  7f ff fe 35  call  0xa0088af0
a0089220:  90 10 00 10  mov  %l0, %o0
a0089224:  90 0a 20 ff  and  %o0, 0xff, %o0
a0089228:  82 10 20 01  mov  1, %g1
a008922c:  9b 28 40 10  sll  %g1, %l0, %o5
a0089230:  80 a2 20 01  cmp  %o0, 1
a0089234:  12 80 00 04  bne  0xa0089244
a0089238:  a4 10 00 11  mov  %l1, %l2
a008923c:  10 80 00 05  b  0xa0089250
a0089240:  a4 0c 7f bf  and  %l1, -65, %l2
a0089244:  c2 0f bf e7  ldub  [ %fp + -25 ], %g1
a0089248:  82 28 40 0d  andn  %g1, %o5, %g1
a008924c:  c2 2f bf e7  stb  %g1, [ %fp + -25 ]
a0089250:  03 00 00 10  sethi  %hi(0x4000), %g1
a0089254:  b0 06 20 01  inc  %i0
a0089258:  80 88 40 12  btst  %g1, %l2
a008925c:  90 10 00 10  mov  %l0, %o0
a0089260:  02 80 00 04  be  0xa0089270
a0089264:  92 10 20 00  clr  %o1
a0089268:  40 00 85 89  call  0xa00aa88c
a008926c:  01 00 00 00  nop
a0089270:  82 0e 20 ff  and  %i0, 0xff, %g1
a0089274:  10 bf ff e5  b  0xa0089208
a0089278:  80 a0 40 13  cmp  %g1, %l3
a008927c:  83 2c a0 10  sll  %l2, 0x10, %g1
a0089280:  a1 30 60 10  srl  %g1, 0x10, %l0
a0089284:  80 a4 20 00  cmp  %l0, 0
a0089288:  02 80 00 07  be  0xa00892a4
a008928c:  80 8c 20 08  btst  8, %l0
a0089290:  11 28 01 a2  sethi  %hi(0xa0068800), %o0
a0089294:  90 12 22 f8  or  %o0, 0x2f8, %o0	! 0xa0068af8
a0089298:  7f ff a7 6b  call  0xa0073044
a008929c:  92 10 00 10  mov  %l0, %o1
a00892a0:  80 8c 20 08  btst  8, %l0
a00892a4:  02 80 00 18  be  0xa0089304
a00892a8:  80 8c a0 10  btst  0x10, %l2
a00892ac:  11 28 01 a2  sethi  %hi(0xa0068800), %o0
a00892b0:  92 10 00 14  mov  %l4, %o1
a00892b4:  7f ff a7 64  call  0xa0073044
a00892b8:  90 12 23 08  or  %o0, 0x308, %o0
a00892bc:  90 10 00 14  mov  %l4, %o0
a00892c0:  92 07 bf e8  add  %fp, -24, %o1
a00892c4:  7f ff fe 66  call  0xa0088c5c
a00892c8:  94 07 bf e7  add  %fp, -25, %o2
a00892cc:  90 0a 20 ff  and  %o0, 0xff, %o0
a00892d0:  80 a2 20 01  cmp  %o0, 1
a00892d4:  22 80 00 02  be,a   0xa00892dc
a00892d8:  a4 14 a0 01  or  %l2, 1, %l2
a00892dc:  c2 0f bf ea  ldub  [ %fp + -22 ], %g1
a00892e0:  80 a0 60 00  cmp  %g1, 0
a00892e4:  02 80 00 08  be  0xa0089304
a00892e8:  80 8c a0 10  btst  0x10, %l2
a00892ec:  11 28 01 a2  sethi  %hi(0xa0068800), %o0
a00892f0:  90 12 23 28  or  %o0, 0x328, %o0	! 0xa0068b28
a00892f4:  7f ff a7 54  call  0xa0073044
a00892f8:  92 10 00 14  mov  %l4, %o1
a00892fc:  a4 14 a0 10  or  %l2, 0x10, %l2
a0089300:  80 8c a0 10  btst  0x10, %l2
a0089304:  02 80 00 1e  be  0xa008937c
a0089308:  83 2c a0 10  sll  %l2, 0x10, %g1
a008930c:  a0 0d e0 ff  and  %l7, 0xff, %l0
a0089310:  82 0d 60 ff  and  %l5, 0xff, %g1
a0089314:  80 a0 40 10  cmp  %g1, %l0
a0089318:  b0 10 00 15  mov  %l5, %i0
a008931c:  18 80 00 17  bgu  0xa0089378
a0089320:  9a 0e 20 ff  and  %i0, 0xff, %o5
a0089324:  c2 0f bf e7  ldub  [ %fp + -25 ], %g1
a0089328:  83 38 40 0d  sra  %g1, %o5, %g1
a008932c:  92 07 bf e8  add  %fp, -24, %o1
a0089330:  80 88 60 01  btst  1, %g1
a0089334:  02 80 00 0d  be  0xa0089368
a0089338:  90 10 00 0d  mov  %o5, %o0
a008933c:  7f ff fc 25  call  0xa00883d0
a0089340:  01 00 00 00  nop
a0089344:  90 0a 20 ff  and  %o0, 0xff, %o0
a0089348:  80 a2 20 01  cmp  %o0, 1
a008934c:  22 80 00 07  be,a   0xa0089368
a0089350:  a4 14 a0 03  or  %l2, 3, %l2
a0089354:  80 a2 20 02  cmp  %o0, 2
a0089358:  22 80 00 04  be,a   0xa0089368
a008935c:  a4 10 20 00  clr  %l2
a0089360:  10 80 00 03  b  0xa008936c
a0089364:  b0 06 20 01  inc  %i0
a0089368:  b0 06 20 01  inc  %i0
a008936c:  82 0e 20 ff  and  %i0, 0xff, %g1
a0089370:  10 bf ff eb  b  0xa008931c
a0089374:  80 a0 40 10  cmp  %g1, %l0
a0089378:  83 2c a0 10  sll  %l2, 0x10, %g1
a008937c:  b1 30 60 10  srl  %g1, 0x10, %i0
a0089380:  80 8e 20 04  btst  4, %i0
a0089384:  02 80 00 0a  be  0xa00893ac
a0089388:  80 8e 20 40  btst  0x40, %i0
a008938c:  a0 0d 60 ff  and  %l5, 0xff, %l0
a0089390:  11 28 01 a2  sethi  %hi(0xa0068800), %o0
a0089394:  90 12 23 48  or  %o0, 0x348, %o0	! 0xa0068b48
a0089398:  7f ff a7 2b  call  0xa0073044
a008939c:  92 10 00 10  mov  %l0, %o1
a00893a0:  7f ff fd f0  call  0xa0088b60
a00893a4:  90 10 00 10  mov  %l0, %o0
a00893a8:  80 8e 20 40  btst  0x40, %i0
a00893ac:  02 80 00 07  be  0xa00893c8
a00893b0:  80 8e 20 01  btst  1, %i0
a00893b4:  11 28 01 a2  sethi  %hi(0xa0068800), %o0
a00893b8:  90 12 23 60  or  %o0, 0x360, %o0	! 0xa0068b60
a00893bc:  7f ff a7 22  call  0xa0073044
a00893c0:  92 0d 60 ff  and  %l5, 0xff, %o1
a00893c4:  80 8e 20 01  btst  1, %i0
a00893c8:  02 80 00 13  be  0xa0089414
a00893cc:  a0 0d 60 ff  and  %l5, 0xff, %l0
a00893d0:  11 28 01 a2  sethi  %hi(0xa0068800), %o0
a00893d4:  92 10 00 10  mov  %l0, %o1
a00893d8:  7f ff a7 1b  call  0xa0073044
a00893dc:  90 12 23 80  or  %o0, 0x380, %o0
a00893e0:  90 10 00 10  mov  %l0, %o0
a00893e4:  7f ff f4 bf  call  0xa00866e0
a00893e8:  92 07 bf e7  add  %fp, -25, %o1
a00893ec:  90 10 00 10  mov  %l0, %o0
a00893f0:  7f ff f9 0d  call  0xa0087824
a00893f4:  92 07 bf e7  add  %fp, -25, %o1
a00893f8:  90 0a 20 ff  and  %o0, 0xff, %o0
a00893fc:  80 a2 20 01  cmp  %o0, 1
a0089400:  12 80 00 05  bne  0xa0089414
a0089404:  11 28 01 a2  sethi  %hi(0xa0068800), %o0
a0089408:  90 12 23 98  or  %o0, 0x398, %o0	! 0xa0068b98
a008940c:  7f ff a7 0e  call  0xa0073044
a0089410:  92 10 00 10  mov  %l0, %o1
a0089414:  01 00 00 00  nop
a0089418:  81 c7 e0 08  ret
a008941c:  81 e8 00 00  restore
