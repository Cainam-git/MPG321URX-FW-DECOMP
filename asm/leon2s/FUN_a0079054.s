# leon2s FUN_a0079054 0xa0079054-0xa0079460 (1036 bytes)
a0079054:  9d e3 bf 80  save  %sp, -128, %sp
a0079058:  13 28 02 cf  sethi  %hi(0xa00b3c00), %o1
a007905c:  92 12 61 d3  or  %o1, 0x1d3, %o1	! 0xa00b3dd3
a0079060:  94 10 20 03  mov  3, %o2
a0079064:  c0 27 bf f0  clr  [ %fp + -16 ]
a0079068:  c0 37 bf f4  clrh  [ %fp + -12 ]
a007906c:  40 00 e1 5b  call  0xa00b15d8
a0079070:  90 07 bf e8  add  %fp, -24, %o0
a0079074:  13 28 02 cf  sethi  %hi(0xa00b3c00), %o1
a0079078:  92 12 61 d6  or  %o1, 0x1d6, %o1	! 0xa00b3dd6
a007907c:  90 07 bf e0  add  %fp, -32, %o0
a0079080:  40 00 e1 56  call  0xa00b15d8
a0079084:  94 10 20 06  mov  6, %o2
a0079088:  b2 0e 60 ff  and  %i1, 0xff, %i1
a007908c:  80 a6 60 01  cmp  %i1, 1
a0079090:  12 80 00 05  bne  0xa00790a4
a0079094:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a0079098:  9a 0e 20 ff  and  %i0, 0xff, %o5
a007909c:  82 10 61 c0  or  %g1, 0x1c0, %g1
a00790a0:  f2 28 40 0d  stb  %i1, [ %g1 + %o5 ]
a00790a4:  40 00 e3 f0  call  0xa00b2064
a00790a8:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00790ac:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a00790b0:  a2 10 61 b4  or  %g1, 0x1b4, %l1	! 0xa80789b4
a00790b4:  a1 2e 20 02  sll  %i0, 2, %l0
a00790b8:  c2 04 40 10  ld  [ %l1 + %l0 ], %g1
a00790bc:  90 22 00 01  sub  %o0, %g1, %o0
a00790c0:  80 a2 20 64  cmp  %o0, 0x64
a00790c4:  18 80 00 04  bgu  0xa00790d4
a00790c8:  80 a6 60 01  cmp  %i1, 1
a00790cc:  12 80 00 e2  bne  0xa0079454
a00790d0:  01 00 00 00  nop
a00790d4:  40 00 e3 e4  call  0xa00b2064
a00790d8:  25 00 00 07  sethi  %hi(0x1c00), %l2
a00790dc:  d0 24 40 10  st  %o0, [ %l1 + %l0 ]
a00790e0:  92 14 a2 a0  or  %l2, 0x2a0, %o1
a00790e4:  40 00 b8 8c  call  0xa00a7314
a00790e8:  90 10 00 18  mov  %i0, %o0
a00790ec:  a0 0a 3f 00  and  %o0, -256, %l0
a00790f0:  92 14 a2 a0  or  %l2, 0x2a0, %o1
a00790f4:  40 00 b8 88  call  0xa00a7314
a00790f8:  90 10 00 18  mov  %i0, %o0
a00790fc:  27 00 3f c0  sethi  %hi(0xff0000), %l3
a0079100:  90 0a 00 13  and  %o0, %l3, %o0
a0079104:  91 32 20 10  srl  %o0, 0x10, %o0
a0079108:  23 00 00 1f  sethi  %hi(0x7c00), %l1
a007910c:  a2 14 63 ff  or  %l1, 0x3ff, %l1	! 0x7fff
a0079110:  a0 14 00 08  or  %l0, %o0, %l0
a0079114:  a0 0c 00 11  and  %l0, %l1, %l0
a0079118:  e0 37 bf f0  sth  %l0, [ %fp + -16 ]
a007911c:  92 14 a2 a0  or  %l2, 0x2a0, %o1
a0079120:  40 00 b8 7d  call  0xa00a7314
a0079124:  90 10 00 18  mov  %i0, %o0
a0079128:  33 3f c0 00  sethi  %hi(0xff000000), %i1
a007912c:  a0 0a 00 19  and  %o0, %i1, %l0
a0079130:  92 14 a2 a4  or  %l2, 0x2a4, %o1
a0079134:  40 00 b8 78  call  0xa00a7314
a0079138:  90 10 00 18  mov  %i0, %o0
a007913c:  90 0a 20 ff  and  %o0, 0xff, %o0
a0079140:  a1 34 20 10  srl  %l0, 0x10, %l0
a0079144:  a0 14 00 08  or  %l0, %o0, %l0
a0079148:  a0 0c 00 11  and  %l0, %l1, %l0
a007914c:  e0 37 bf f2  sth  %l0, [ %fp + -14 ]
a0079150:  92 14 a2 a4  or  %l2, 0x2a4, %o1
a0079154:  40 00 b8 70  call  0xa00a7314
a0079158:  90 10 00 18  mov  %i0, %o0
a007915c:  a0 0a 3f 00  and  %o0, -256, %l0
a0079160:  92 14 a2 a4  or  %l2, 0x2a4, %o1
a0079164:  40 00 b8 6c  call  0xa00a7314
a0079168:  90 10 00 18  mov  %i0, %o0
a007916c:  90 0a 00 13  and  %o0, %l3, %o0
a0079170:  91 32 20 10  srl  %o0, 0x10, %o0
a0079174:  a0 14 00 08  or  %l0, %o0, %l0
a0079178:  c2 17 bf f0  lduh  [ %fp + -16 ], %g1
a007917c:  a0 0c 00 11  and  %l0, %l1, %l0
a0079180:  80 a0 60 80  cmp  %g1, 0x80
a0079184:  e0 37 bf f4  sth  %l0, [ %fp + -12 ]
a0079188:  18 80 00 09  bgu  0xa00791ac
a007918c:  92 10 00 01  mov  %g1, %o1
a0079190:  c2 17 bf f2  lduh  [ %fp + -14 ], %g1
a0079194:  80 a0 60 80  cmp  %g1, 0x80
a0079198:  38 80 00 06  bgu,a   0xa00791b0
a007919c:  93 2a 60 10  sll  %o1, 0x10, %o1
a00791a0:  80 a4 20 80  cmp  %l0, 0x80
a00791a4:  08 80 00 3b  bleu  0xa0079290
a00791a8:  82 06 00 18  add  %i0, %i0, %g1
a00791ac:  93 2a 60 10  sll  %o1, 0x10, %o1
a00791b0:  11 28 01 9d  sethi  %hi(0xa0067400), %o0
a00791b4:  93 32 60 10  srl  %o1, 0x10, %o1
a00791b8:  d4 17 bf f2  lduh  [ %fp + -14 ], %o2
a00791bc:  d6 17 bf f4  lduh  [ %fp + -12 ], %o3
a00791c0:  7f ff e7 a1  call  0xa0073044
a00791c4:  90 12 23 00  or  %o0, 0x300, %o0
a00791c8:  21 00 00 07  sethi  %hi(0x1c00), %l0
a00791cc:  90 10 00 18  mov  %i0, %o0
a00791d0:  92 14 22 a0  or  %l0, 0x2a0, %o1
a00791d4:  94 10 3f 00  mov  -256, %o2
a00791d8:  40 00 b8 ac  call  0xa00a7488
a00791dc:  96 10 20 87  mov  0x87, %o3
a00791e0:  90 10 00 18  mov  %i0, %o0
a00791e4:  92 14 22 a0  or  %l0, 0x2a0, %o1
a00791e8:  94 10 3f 00  mov  -256, %o2
a00791ec:  40 00 b8 a7  call  0xa00a7488
a00791f0:  96 10 20 c7  mov  0xc7, %o3
a00791f4:  90 10 00 18  mov  %i0, %o0
a00791f8:  92 14 22 a0  or  %l0, 0x2a0, %o1
a00791fc:  94 10 3f 00  mov  -256, %o2
a0079200:  40 00 b8 a2  call  0xa00a7488
a0079204:  96 10 20 87  mov  0x87, %o3
a0079208:  82 06 00 18  add  %i0, %i0, %g1
a007920c:  82 00 40 18  add  %g1, %i0, %g1
a0079210:  1b 2a 01 f3  sethi  %hi(0xa807cc00), %o5
a0079214:  9a 13 60 c4  or  %o5, 0xc4, %o5	! 0xa807ccc4
a0079218:  83 28 60 02  sll  %g1, 2, %g1
a007921c:  82 00 40 0d  add  %g1, %o5, %g1
a0079220:  da 08 60 08  ldub  [ %g1 + 8 ], %o5
a0079224:  80 a3 60 01  cmp  %o5, 1
a0079228:  12 80 00 8b  bne  0xa0079454
a007922c:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a0079230:  82 10 61 c0  or  %g1, 0x1c0, %g1	! 0xa80789c0
a0079234:  21 3f c0 3f  sethi  %hi(0xff00fc00), %l0
a0079238:  13 00 00 04  sethi  %hi(0x1000), %o1
a007923c:  da 28 40 18  stb  %o5, [ %g1 + %i0 ]
a0079240:  90 10 00 18  mov  %i0, %o0
a0079244:  94 14 23 ff  or  %l0, 0x3ff, %o2
a0079248:  92 12 61 70  or  %o1, 0x170, %o1
a007924c:  40 00 b8 8f  call  0xa00a7488
a0079250:  17 00 0b 00  sethi  %hi(0x2c0000), %o3
a0079254:  13 00 00 05  sethi  %hi(0x1400), %o1
a0079258:  90 10 00 18  mov  %i0, %o0
a007925c:  94 14 23 ff  or  %l0, 0x3ff, %o2
a0079260:  92 12 61 70  or  %o1, 0x170, %o1
a0079264:  40 00 b8 89  call  0xa00a7488
a0079268:  17 00 0b 00  sethi  %hi(0x2c0000), %o3
a007926c:  13 00 00 06  sethi  %hi(0x1800), %o1
a0079270:  90 10 00 18  mov  %i0, %o0
a0079274:  92 12 61 70  or  %o1, 0x170, %o1
a0079278:  94 14 23 ff  or  %l0, 0x3ff, %o2
a007927c:  40 00 b8 83  call  0xa00a7488
a0079280:  17 00 0b 00  sethi  %hi(0x2c0000), %o3
a0079284:  7f ff fd 5c  call  0xa00787f4
a0079288:  90 10 00 18  mov  %i0, %o0
a007928c:  30 80 00 72  b,a   0xa0079454
a0079290:  82 00 40 18  add  %g1, %i0, %g1
a0079294:  1b 2a 01 f3  sethi  %hi(0xa807cc00), %o5
a0079298:  83 28 60 02  sll  %g1, 2, %g1
a007929c:  9a 13 60 c4  or  %o5, 0xc4, %o5
a00792a0:  82 00 40 0d  add  %g1, %o5, %g1
a00792a4:  c2 08 60 08  ldub  [ %g1 + 8 ], %g1
a00792a8:  80 a0 60 01  cmp  %g1, 1
a00792ac:  12 80 00 6a  bne  0xa0079454
a00792b0:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a00792b4:  9a 10 61 c0  or  %g1, 0x1c0, %o5	! 0xa80789c0
a00792b8:  c2 0b 40 18  ldub  [ %o5 + %i0 ], %g1
a00792bc:  80 a0 60 01  cmp  %g1, 1
a00792c0:  12 80 00 65  bne  0xa0079454
a00792c4:  27 00 00 04  sethi  %hi(0x1000), %l3
a00792c8:  c0 2b 40 18  clrb  [ %o5 + %i0 ]
a00792cc:  92 14 e1 78  or  %l3, 0x178, %o1
a00792d0:  40 00 b8 11  call  0xa00a7314
a00792d4:  90 10 00 18  mov  %i0, %o0
a00792d8:  90 0a 20 0f  and  %o0, 0xf, %o0
a00792dc:  d0 2f bf e8  stb  %o0, [ %fp + -24 ]
a00792e0:  92 14 e1 78  or  %l3, 0x178, %o1
a00792e4:  90 10 00 18  mov  %i0, %o0
a00792e8:  40 00 b8 0b  call  0xa00a7314
a00792ec:  21 00 3f ff  sethi  %hi(0xfffc00), %l0
a00792f0:  a0 14 23 00  or  %l0, 0x300, %l0	! 0xffff00
a00792f4:  90 0a 00 10  and  %o0, %l0, %o0
a00792f8:  91 32 20 08  srl  %o0, 8, %o0
a00792fc:  25 00 00 05  sethi  %hi(0x1400), %l2
a0079300:  d0 37 bf e0  sth  %o0, [ %fp + -32 ]
a0079304:  92 14 a1 78  or  %l2, 0x178, %o1
a0079308:  40 00 b8 03  call  0xa00a7314
a007930c:  90 10 00 18  mov  %i0, %o0
a0079310:  90 0a 20 0f  and  %o0, 0xf, %o0
a0079314:  d0 2f bf e9  stb  %o0, [ %fp + -23 ]
a0079318:  92 14 a1 78  or  %l2, 0x178, %o1
a007931c:  40 00 b7 fe  call  0xa00a7314
a0079320:  90 10 00 18  mov  %i0, %o0
a0079324:  90 0a 00 10  and  %o0, %l0, %o0
a0079328:  91 32 20 08  srl  %o0, 8, %o0
a007932c:  23 00 00 06  sethi  %hi(0x1800), %l1
a0079330:  d0 37 bf e2  sth  %o0, [ %fp + -30 ]
a0079334:  92 14 61 78  or  %l1, 0x178, %o1
a0079338:  40 00 b7 f7  call  0xa00a7314
a007933c:  90 10 00 18  mov  %i0, %o0
a0079340:  90 0a 20 0f  and  %o0, 0xf, %o0
a0079344:  d0 2f bf ea  stb  %o0, [ %fp + -22 ]
a0079348:  92 14 61 78  or  %l1, 0x178, %o1
a007934c:  40 00 b7 f2  call  0xa00a7314
a0079350:  90 10 00 18  mov  %i0, %o0
a0079354:  90 0a 00 10  and  %o0, %l0, %o0
a0079358:  c2 0f bf e8  ldub  [ %fp + -24 ], %g1
a007935c:  d6 17 bf e0  lduh  [ %fp + -32 ], %o3
a0079360:  91 32 20 08  srl  %o0, 8, %o0
a0079364:  82 08 60 0f  and  %g1, 0xf, %g1
a0079368:  d0 37 bf e4  sth  %o0, [ %fp + -28 ]
a007936c:  97 2a e0 08  sll  %o3, 8, %o3
a0079370:  96 10 40 0b  or  %g1, %o3, %o3
a0079374:  90 10 00 18  mov  %i0, %o0
a0079378:  92 14 e1 78  or  %l3, 0x178, %o1
a007937c:  40 00 b8 43  call  0xa00a7488
a0079380:  94 16 60 f0  or  %i1, 0xf0, %o2
a0079384:  c2 0f bf e9  ldub  [ %fp + -23 ], %g1
a0079388:  d6 17 bf e2  lduh  [ %fp + -30 ], %o3
a007938c:  82 08 60 0f  and  %g1, 0xf, %g1
a0079390:  97 2a e0 08  sll  %o3, 8, %o3
a0079394:  96 10 40 0b  or  %g1, %o3, %o3
a0079398:  90 10 00 18  mov  %i0, %o0
a007939c:  92 14 a1 78  or  %l2, 0x178, %o1
a00793a0:  40 00 b8 3a  call  0xa00a7488
a00793a4:  94 16 60 f0  or  %i1, 0xf0, %o2
a00793a8:  c2 0f bf ea  ldub  [ %fp + -22 ], %g1
a00793ac:  d6 17 bf e4  lduh  [ %fp + -28 ], %o3
a00793b0:  82 08 60 0f  and  %g1, 0xf, %g1
a00793b4:  97 2a e0 08  sll  %o3, 8, %o3
a00793b8:  96 10 40 0b  or  %g1, %o3, %o3
a00793bc:  94 16 60 f0  or  %i1, 0xf0, %o2
a00793c0:  90 10 00 18  mov  %i0, %o0
a00793c4:  40 00 b8 31  call  0xa00a7488
a00793c8:  92 14 61 78  or  %l1, 0x178, %o1
a00793cc:  21 3f c0 3f  sethi  %hi(0xff00fc00), %l0
a00793d0:  90 10 00 18  mov  %i0, %o0
a00793d4:  92 14 e1 70  or  %l3, 0x170, %o1
a00793d8:  94 14 23 ff  or  %l0, 0x3ff, %o2
a00793dc:  40 00 b8 2b  call  0xa00a7488
a00793e0:  17 00 0b c0  sethi  %hi(0x2f0000), %o3
a00793e4:  90 10 00 18  mov  %i0, %o0
a00793e8:  92 14 a1 70  or  %l2, 0x170, %o1
a00793ec:  94 14 23 ff  or  %l0, 0x3ff, %o2
a00793f0:  40 00 b8 26  call  0xa00a7488
a00793f4:  17 00 0b c0  sethi  %hi(0x2f0000), %o3
a00793f8:  90 10 00 18  mov  %i0, %o0
a00793fc:  92 14 61 70  or  %l1, 0x170, %o1
a0079400:  94 14 23 ff  or  %l0, 0x3ff, %o2
a0079404:  40 00 b8 21  call  0xa00a7488
a0079408:  17 00 0b c0  sethi  %hi(0x2f0000), %o3
a007940c:  11 28 01 9d  sethi  %hi(0xa0067400), %o0
a0079410:  92 10 00 18  mov  %i0, %o1
a0079414:  d4 17 bf e0  lduh  [ %fp + -32 ], %o2
a0079418:  d6 0f bf e8  ldub  [ %fp + -24 ], %o3
a007941c:  7f ff e7 0a  call  0xa0073044
a0079420:  90 12 23 20  or  %o0, 0x320, %o0
a0079424:  11 28 01 9d  sethi  %hi(0xa0067400), %o0
a0079428:  92 10 00 18  mov  %i0, %o1
a007942c:  d4 17 bf e2  lduh  [ %fp + -30 ], %o2
a0079430:  d6 0f bf e9  ldub  [ %fp + -23 ], %o3
a0079434:  7f ff e7 04  call  0xa0073044
a0079438:  90 12 23 48  or  %o0, 0x348, %o0
a007943c:  11 28 01 9d  sethi  %hi(0xa0067400), %o0
a0079440:  90 12 23 70  or  %o0, 0x370, %o0	! 0xa0067770
a0079444:  92 10 00 18  mov  %i0, %o1
a0079448:  d4 17 bf e4  lduh  [ %fp + -28 ], %o2
a007944c:  7f ff e6 fe  call  0xa0073044
a0079450:  d6 0f bf ea  ldub  [ %fp + -22 ], %o3
a0079454:  01 00 00 00  nop
a0079458:  81 c7 e0 08  ret
a007945c:  81 e8 00 00  restore
