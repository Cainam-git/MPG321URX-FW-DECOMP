# leon2s FUN_a00700cc 0xa00700cc-0xa00703b8 (748 bytes)
a00700cc:  9d e3 bf 60  save  %sp, -160, %sp
a00700d0:  13 28 02 ce  sethi  %hi(0xa00b3800), %o1
a00700d4:  92 12 61 f8  or  %o1, 0x1f8, %o1	! 0xa00b39f8
a00700d8:  94 10 20 0e  mov  0xe, %o2
a00700dc:  40 01 05 3f  call  0xa00b15d8
a00700e0:  90 07 bf e8  add  %fp, -24, %o0
a00700e4:  7f ff fe f1  call  0xa006fca8
a00700e8:  90 07 bf d0  add  %fp, -48, %o0
a00700ec:  a8 10 20 00  clr  %l4
a00700f0:  a4 0d 20 ff  and  %l4, 0xff, %l2
a00700f4:  ac 07 bf f8  add  %fp, -8, %l6
a00700f8:  82 05 80 12  add  %l6, %l2, %g1
a00700fc:  d8 08 7f d8  ldub  [ %g1 + -40 ], %o4
a0070100:  82 03 3f ff  add  %o4, -1, %g1
a0070104:  a0 08 60 ff  and  %g1, 0xff, %l0
a0070108:  9b 2c 20 02  sll  %l0, 2, %o5
a007010c:  9a 03 40 10  add  %o5, %l0, %o5
a0070110:  03 2a 01 ea  sethi  %hi(0xa807a800), %g1
a0070114:  82 10 60 24  or  %g1, 0x24, %g1	! 0xa807a824
a0070118:  9b 2b 60 02  sll  %o5, 2, %o5
a007011c:  a2 03 40 01  add  %o5, %g1, %l1
a0070120:  a6 0b 20 ff  and  %o4, 0xff, %l3
a0070124:  82 04 ff ff  add  %l3, -1, %g1
a0070128:  80 a0 60 08  cmp  %g1, 8
a007012c:  18 80 00 22  bgu  0xa00701b4
a0070130:  a8 05 20 01  inc  %l4
a0070134:  11 28 01 99  sethi  %hi(0xa0066400), %o0
a0070138:  c2 0c 60 0f  ldub  [ %l1 + 0xf ], %g1
a007013c:  90 12 20 98  or  %o0, 0x98, %o0
a0070140:  92 10 00 10  mov  %l0, %o1
a0070144:  80 a0 60 01  cmp  %g1, 1
a0070148:  02 80 00 06  be  0xa0070160
a007014c:  aa 07 bf d8  add  %fp, -40, %l5
a0070150:  c2 0c 60 10  ldub  [ %l1 + 0x10 ], %g1
a0070154:  80 a0 60 01  cmp  %g1, 1
a0070158:  12 80 00 18  bne  0xa00701b8
a007015c:  82 0d 20 ff  and  %l4, 0xff, %g1
a0070160:  40 00 0b b9  call  0xa0073044
a0070164:  01 00 00 00  nop
a0070168:  90 10 00 13  mov  %l3, %o0
a007016c:  92 10 00 10  mov  %l0, %o1
a0070170:  7f ff fe 8f  call  0xa006fbac
a0070174:  94 10 00 15  mov  %l5, %o2
a0070178:  82 04 80 12  add  %l2, %l2, %g1
a007017c:  82 00 40 16  add  %g1, %l6, %g1
a0070180:  d0 08 7f f1  ldub  [ %g1 + -15 ], %o0
a0070184:  94 10 00 15  mov  %l5, %o2
a0070188:  92 10 20 00  clr  %o1
a007018c:  7f ff fe 52  call  0xa006fad4
a0070190:  96 10 20 04  mov  4, %o3
a0070194:  c2 0c 60 10  ldub  [ %l1 + 0x10 ], %g1
a0070198:  80 a0 60 01  cmp  %g1, 1
a007019c:  12 80 00 05  bne  0xa00701b0
a00701a0:  90 10 00 12  mov  %l2, %o0
a00701a4:  7f ff fe ad  call  0xa006fc58
a00701a8:  01 00 00 00  nop
a00701ac:  c0 2c 60 10  clrb  [ %l1 + 0x10 ]
a00701b0:  c0 2c 60 0f  clrb  [ %l1 + 0xf ]
a00701b4:  82 0d 20 ff  and  %l4, 0xff, %g1
a00701b8:  80 a0 60 06  cmp  %g1, 6
a00701bc:  28 bf ff ce  bleu,a   0xa00700f4
a00701c0:  a4 0d 20 ff  and  %l4, 0xff, %l2
a00701c4:  90 10 20 00  clr  %o0
a00701c8:  92 10 20 02  mov  2, %o1
a00701cc:  94 07 bf cc  add  %fp, -52, %o2
a00701d0:  7f ff fe 36  call  0xa006faa8
a00701d4:  96 10 20 01  mov  1, %o3
a00701d8:  da 0f bf cc  ldub  [ %fp + -52 ], %o5
a00701dc:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a00701e0:  da 28 60 d3  stb  %o5, [ %g1 + 0xd3 ]	! 0xa80788d3
a00701e4:  92 10 20 03  mov  3, %o1
a00701e8:  94 07 bf c8  add  %fp, -56, %o2
a00701ec:  96 10 20 01  mov  1, %o3
a00701f0:  90 10 20 00  clr  %o0
a00701f4:  7f ff fe 2d  call  0xa006faa8
a00701f8:  c0 27 bf c8  clr  [ %fp + -56 ]
a00701fc:  03 3f ff c0  sethi  %hi(0xffff0000), %g1
a0070200:  da 07 bf c8  ld  [ %fp + -56 ], %o5
a0070204:  82 10 60 ff  or  %g1, 0xff, %g1
a0070208:  9a 0b 40 01  and  %o5, %g1, %o5
a007020c:  40 00 4f 07  call  0xa0083e28
a0070210:  da 27 bf c8  st  %o5, [ %fp + -56 ]
a0070214:  90 0a 20 ff  and  %o0, 0xff, %o0
a0070218:  c2 07 bf c8  ld  [ %fp + -56 ], %g1
a007021c:  91 2a 20 08  sll  %o0, 8, %o0
a0070220:  82 10 40 08  or  %g1, %o0, %g1
a0070224:  c2 27 bf c8  st  %g1, [ %fp + -56 ]
a0070228:  90 10 20 00  clr  %o0
a007022c:  92 10 20 03  mov  3, %o1
a0070230:  94 07 bf c8  add  %fp, -56, %o2
a0070234:  7f ff fe 28  call  0xa006fad4
a0070238:  96 10 20 01  mov  1, %o3
a007023c:  7f ff ff 28  call  0xa006fedc
a0070240:  21 2a 01 e2  sethi  %hi(0xa8078800), %l0
a0070244:  92 10 20 03  mov  3, %o1
a0070248:  90 10 20 00  clr  %o0
a007024c:  94 07 bf c4  add  %fp, -60, %o2
a0070250:  96 10 20 01  mov  1, %o3
a0070254:  7f ff fe 15  call  0xa006faa8
a0070258:  c0 27 bf c4  clr  [ %fp + -60 ]
a007025c:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a0070260:  d6 0c 20 d2  ldub  [ %l0 + 0xd2 ], %o3
a0070264:  da 07 bf c4  ld  [ %fp + -60 ], %o5
a0070268:  c2 08 60 dd  ldub  [ %g1 + 0xdd ], %g1
a007026c:  82 2a c0 01  andn  %o3, %g1, %g1
a0070270:  98 0a e0 3f  and  %o3, 0x3f, %o4
a0070274:  9a 0b 7f 00  and  %o5, -256, %o5
a0070278:  c2 2c 20 d2  stb  %g1, [ %l0 + 0xd2 ]
a007027c:  9a 13 40 0c  or  %o5, %o4, %o5
a0070280:  40 00 63 41  call  0xa0088f84
a0070284:  da 27 bf c4  st  %o5, [ %fp + -60 ]
a0070288:  90 0a 20 03  and  %o0, 3, %o0
a007028c:  c2 07 bf c4  ld  [ %fp + -60 ], %g1
a0070290:  91 2a 20 06  sll  %o0, 6, %o0
a0070294:  d2 0c 20 d2  ldub  [ %l0 + 0xd2 ], %o1
a0070298:  82 10 40 08  or  %g1, %o0, %g1
a007029c:  80 a2 60 00  cmp  %o1, 0
a00702a0:  02 80 00 15  be  0xa00702f4
a00702a4:  c2 27 bf c4  st  %g1, [ %fp + -60 ]
a00702a8:  11 28 01 99  sethi  %hi(0xa0066400), %o0
a00702ac:  40 00 0b 66  call  0xa0073044
a00702b0:  90 12 20 b0  or  %o0, 0xb0, %o0	! 0xa00664b0
a00702b4:  c2 07 bf c4  ld  [ %fp + -60 ], %g1
a00702b8:  80 88 60 10  btst  0x10, %g1
a00702bc:  02 80 00 08  be  0xa00702dc
a00702c0:  80 88 60 20  btst  0x20, %g1
a00702c4:  7f c5 6f e8  call  0x9f1cc264
a00702c8:  90 10 20 00  clr  %o0
a00702cc:  7f c5 6f 77  call  0x9f1cc0a8
a00702d0:  01 00 00 00  nop
a00702d4:  c2 07 bf c4  ld  [ %fp + -60 ], %g1
a00702d8:  80 88 60 20  btst  0x20, %g1
a00702dc:  22 80 00 07  be,a   0xa00702f8
a00702e0:  92 10 20 03  mov  3, %o1
a00702e4:  7f c5 6f e0  call  0x9f1cc264
a00702e8:  90 10 20 01  mov  1, %o0
a00702ec:  7f c5 6f 6f  call  0x9f1cc0a8
a00702f0:  01 00 00 00  nop
a00702f4:  92 10 20 03  mov  3, %o1	! 0x3
a00702f8:  94 07 bf c4  add  %fp, -60, %o2
a00702fc:  96 10 20 01  mov  1, %o3
a0070300:  7f ff fd f5  call  0xa006fad4
a0070304:  90 10 20 00  clr  %o0
a0070308:  21 2a 01 e2  sethi  %hi(0xa8078800), %l0
a007030c:  c2 04 20 e0  ld  [ %l0 + 0xe0 ], %g1	! 0xa80788e0
a0070310:  82 08 7f f9  and  %g1, -7, %g1
a0070314:  7f c5 4e fa  call  0x9f1c3efc
a0070318:  c2 24 20 e0  st  %g1, [ %l0 + 0xe0 ]
a007031c:  90 0a 20 03  and  %o0, 3, %o0
a0070320:  c2 04 20 e0  ld  [ %l0 + 0xe0 ], %g1
a0070324:  90 02 00 08  add  %o0, %o0, %o0
a0070328:  82 10 40 08  or  %g1, %o0, %g1
a007032c:  94 14 20 e0  or  %l0, 0xe0, %o2
a0070330:  c2 24 20 e0  st  %g1, [ %l0 + 0xe0 ]
a0070334:  96 10 20 01  mov  1, %o3
a0070338:  90 10 20 00  clr  %o0
a007033c:  7f ff fd e6  call  0xa006fad4
a0070340:  92 10 20 00  clr  %o1
a0070344:  03 2a 01 ea  sethi  %hi(0xa807a800), %g1
a0070348:  94 10 60 24  or  %g1, 0x24, %o2	! 0xa807a824
a007034c:  96 10 20 00  clr  %o3
a0070350:  98 10 20 00  clr  %o4
a0070354:  82 0b 20 ff  and  %o4, 0xff, %g1
a0070358:  9b 28 60 02  sll  %g1, 2, %o5
a007035c:  82 03 40 01  add  %o5, %g1, %g1
a0070360:  83 28 60 02  sll  %g1, 2, %g1
a0070364:  c2 0a 80 01  ldub  [ %o2 + %g1 ], %g1
a0070368:  82 08 60 0f  and  %g1, 0xf, %g1
a007036c:  83 28 40 0d  sll  %g1, %o5, %g1
a0070370:  98 03 20 01  inc  %o4
a0070374:  9a 0b 20 ff  and  %o4, 0xff, %o5
a0070378:  80 a3 60 07  cmp  %o5, 7
a007037c:  0a bf ff f6  bcs  0xa0070354
a0070380:  96 12 c0 01  or  %o3, %g1, %o3
a0070384:  c2 04 20 e0  ld  [ %l0 + 0xe0 ], %g1
a0070388:  9b 2a e0 04  sll  %o3, 4, %o5
a007038c:  82 08 60 0f  and  %g1, 0xf, %g1
a0070390:  82 10 40 0d  or  %g1, %o5, %g1
a0070394:  c2 24 20 e0  st  %g1, [ %l0 + 0xe0 ]
a0070398:  94 14 20 e0  or  %l0, 0xe0, %o2
a007039c:  90 10 20 00  clr  %o0
a00703a0:  92 10 20 00  clr  %o1
a00703a4:  7f ff fd cc  call  0xa006fad4
a00703a8:  96 10 20 01  mov  1, %o3
a00703ac:  01 00 00 00  nop
a00703b0:  81 c7 e0 08  ret
a00703b4:  81 e8 00 00  restore
