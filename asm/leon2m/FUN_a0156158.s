# leon2m FUN_a0156158 0xa0156158-0xa01564b0 (856 bytes)
a0156158:  9d e3 bf 38  save  %sp, -200, %sp
a015615c:  ba 07 bf e0  add  %fp, -32, %i5
a0156160:  90 07 bf a8  add  %fp, -88, %o0
a0156164:  92 10 00 1d  mov  %i5, %o1
a0156168:  f0 3f bf a8  std  %i0, [ %fp + -88 ]
a015616c:  40 00 04 78  call  0xa015734c
a0156170:  f4 3f bf a0  std  %i2, [ %fp + -96 ]
a0156174:  b8 07 bf c8  add  %fp, -56, %i4
a0156178:  90 07 bf a0  add  %fp, -96, %o0
a015617c:  40 00 04 74  call  0xa015734c
a0156180:  92 10 00 1c  mov  %i4, %o1
a0156184:  c2 07 bf e0  ld  [ %fp + -32 ], %g1
a0156188:  80 a0 60 01  cmp  %g1, 1
a015618c:  08 80 00 1a  bleu  0xa01561f4
a0156190:  aa 07 bf b0  add  %fp, -80, %l5
a0156194:  da 07 bf c8  ld  [ %fp + -56 ], %o5
a0156198:  80 a3 60 01  cmp  %o5, 1
a015619c:  28 80 00 0c  bleu,a   0xa01561cc
a01561a0:  da 07 bf cc  ld  [ %fp + -52 ], %o5
a01561a4:  80 a0 60 04  cmp  %g1, 4
a01561a8:  22 80 00 10  be,a   0xa01561e8
a01561ac:  03 00 06 a0  sethi  %hi(0x1a8000), %g1
a01561b0:  80 a3 60 04  cmp  %o5, 4
a01561b4:  12 80 00 18  bne  0xa0156214
a01561b8:  80 a0 60 02  cmp  %g1, 2
a01561bc:  03 00 06 a0  sethi  %hi(0x1a8000), %g1
a01561c0:  02 80 00 b7  be  0xa015649c
a01561c4:  90 10 62 c0  or  %g1, 0x2c0, %o0	! 0x1a82c0
a01561c8:  da 07 bf cc  ld  [ %fp + -52 ], %o5
a01561cc:  c2 07 bf e4  ld  [ %fp + -28 ], %g1
a01561d0:  82 18 40 0d  xor  %g1, %o5, %g1
a01561d4:  80 a0 00 01  cmp  %g0, %g1
a01561d8:  9a 40 20 00  addx  %g0, 0, %o5
a01561dc:  da 27 bf cc  st  %o5, [ %fp + -52 ]
a01561e0:  10 80 00 af  b  0xa015649c
a01561e4:  90 10 00 1c  mov  %i4, %o0
a01561e8:  80 a3 60 02  cmp  %o5, 2
a01561ec:  02 80 00 ac  be  0xa015649c
a01561f0:  90 10 62 c0  or  %g1, 0x2c0, %o0
a01561f4:  c2 07 bf e4  ld  [ %fp + -28 ], %g1
a01561f8:  da 07 bf cc  ld  [ %fp + -52 ], %o5
a01561fc:  82 18 40 0d  xor  %g1, %o5, %g1
a0156200:  80 a0 00 01  cmp  %g0, %g1
a0156204:  9a 40 20 00  addx  %g0, 0, %o5
a0156208:  da 27 bf e4  st  %o5, [ %fp + -28 ]
a015620c:  10 80 00 a4  b  0xa015649c
a0156210:  90 10 00 1d  mov  %i5, %o0
a0156214:  02 bf ff f9  be  0xa01561f8
a0156218:  c2 07 bf e4  ld  [ %fp + -28 ], %g1
a015621c:  80 a3 60 02  cmp  %o5, 2
a0156220:  02 bf ff ec  be  0xa01561d0
a0156224:  da 07 bf cc  ld  [ %fp + -52 ], %o5
a0156228:  e0 07 bf f4  ld  [ %fp + -12 ], %l0
a015622c:  a2 10 00 10  mov  %l0, %l1
a0156230:  d6 07 bf f0  ld  [ %fp + -16 ], %o3
a0156234:  e8 07 bf dc  ld  [ %fp + -36 ], %l4
a0156238:  da 07 bf d8  ld  [ %fp + -40 ], %o5
a015623c:  a0 10 20 00  clr  %l0
a0156240:  ac 10 00 0b  mov  %o3, %l6
a0156244:  90 10 20 00  clr  %o0
a0156248:  92 10 00 14  mov  %l4, %o1
a015624c:  a4 10 00 0d  mov  %o5, %l2
a0156250:  94 10 00 10  mov  %l0, %o2
a0156254:  96 10 00 11  mov  %l1, %o3
a0156258:  40 00 02 b1  call  0xa0156d1c
a015625c:  d0 3f bf 98  std  %o0, [ %fp + -104 ]
a0156260:  a6 10 00 12  mov  %l2, %l3
a0156264:  a4 10 20 00  clr  %l2
a0156268:  b0 10 00 08  mov  %o0, %i0
a015626c:  b2 10 00 09  mov  %o1, %i1
a0156270:  94 10 00 10  mov  %l0, %o2
a0156274:  96 10 00 11  mov  %l1, %o3
a0156278:  90 10 00 12  mov  %l2, %o0
a015627c:  40 00 02 a8  call  0xa0156d1c
a0156280:  92 10 00 13  mov  %l3, %o1
a0156284:  ae 10 00 16  mov  %l6, %l7
a0156288:  b4 10 00 08  mov  %o0, %i2
a015628c:  b6 10 00 09  mov  %o1, %i3
a0156290:  ac 10 20 00  clr  %l6
a0156294:  94 10 00 16  mov  %l6, %o2
a0156298:  96 10 00 17  mov  %l7, %o3
a015629c:  40 00 02 a0  call  0xa0156d1c
a01562a0:  d0 1f bf 98  ldd  [ %fp + -104 ], %o0
a01562a4:  a0 10 00 08  mov  %o0, %l0
a01562a8:  a2 10 00 09  mov  %o1, %l1
a01562ac:  90 10 00 12  mov  %l2, %o0
a01562b0:  92 10 00 13  mov  %l3, %o1
a01562b4:  94 10 00 16  mov  %l6, %o2
a01562b8:  40 00 02 99  call  0xa0156d1c
a01562bc:  96 10 00 17  mov  %l7, %o3
a01562c0:  a2 86 c0 11  addcc  %i3, %l1, %l1
a01562c4:  a0 46 80 10  addx  %i2, %l0, %l0
a01562c8:  94 10 00 08  mov  %o0, %o2
a01562cc:  96 10 00 09  mov  %o1, %o3
a01562d0:  80 a6 80 10  cmp  %i2, %l0
a01562d4:  a4 10 20 00  clr  %l2
a01562d8:  18 80 00 65  bgu  0xa015646c
a01562dc:  a6 10 20 00  clr  %l3
a01562e0:  80 a6 80 10  cmp  %i2, %l0
a01562e4:  02 80 00 60  be  0xa0156464
a01562e8:  80 a6 c0 11  cmp  %i3, %l1
a01562ec:  b6 10 20 00  clr  %i3
a01562f0:  92 86 40 1b  addcc  %i1, %i3, %o1
a01562f4:  90 46 00 11  addx  %i0, %l1, %o0
a01562f8:  80 a6 00 08  cmp  %i0, %o0
a01562fc:  38 80 00 58  bgu,a   0xa015645c
a0156300:  a6 84 e0 01  inccc  %l3
a0156304:  80 a6 00 08  cmp  %i0, %o0
a0156308:  02 80 00 52  be  0xa0156450
a015630c:  80 a6 40 09  cmp  %i1, %o1
a0156310:  9a 84 00 0b  addcc  %l0, %o3, %o5
a0156314:  98 10 20 00  clr  %o4
a0156318:  98 43 00 0a  addx  %o4, %o2, %o4
a015631c:  d6 07 20 04  ld  [ %i4 + 4 ], %o3
a0156320:  b2 84 c0 0d  addcc  %l3, %o5, %i1
a0156324:  c2 07 60 04  ld  [ %i5 + 4 ], %g1
a0156328:  b0 44 80 0c  addx  %l2, %o4, %i0
a015632c:  82 18 40 0b  xor  %g1, %o3, %g1
a0156330:  80 a0 00 01  cmp  %g0, %g1
a0156334:  da 07 60 08  ld  [ %i5 + 8 ], %o5
a0156338:  d8 07 20 08  ld  [ %i4 + 8 ], %o4
a015633c:  9a 03 40 0c  add  %o5, %o4, %o5
a0156340:  03 07 ff ff  sethi  %hi(0x1ffffc00), %g1
a0156344:  96 40 20 00  addx  %g0, 0, %o3
a0156348:  9e 03 60 04  add  %o5, 4, %o7
a015634c:  82 10 63 ff  or  %g1, 0x3ff, %g1
a0156350:  a2 10 00 09  mov  %o1, %l1
a0156354:  d6 25 60 04  st  %o3, [ %l5 + 4 ]
a0156358:  a0 10 00 08  mov  %o0, %l0
a015635c:  80 a6 00 01  cmp  %i0, %g1
a0156360:  08 80 00 18  bleu  0xa01563c0
a0156364:  92 10 00 0f  mov  %o7, %o1
a0156368:  94 10 00 01  mov  %g1, %o2
a015636c:  25 20 00 00  sethi  %hi(0x80000000), %l2
a0156370:  a6 10 20 00  clr  %l3
a0156374:  97 2e 20 1f  sll  %i0, 0x1f, %o3
a0156378:  83 36 60 01  srl  %i1, 1, %g1
a015637c:  9a 12 c0 01  or  %o3, %g1, %o5
a0156380:  99 36 20 01  srl  %i0, 1, %o4
a0156384:  97 2c 20 1f  sll  %l0, 0x1f, %o3
a0156388:  83 34 60 01  srl  %l1, 1, %g1
a015638c:  9e 03 e0 01  inc  %o7
a0156390:  80 8e 60 01  btst  1, %i1
a0156394:  b6 12 c0 01  or  %o3, %g1, %i3
a0156398:  b5 34 20 01  srl  %l0, 1, %i2
a015639c:  b0 10 00 0c  mov  %o4, %i0
a01563a0:  b2 10 00 0d  mov  %o5, %i1
a01563a4:  02 80 00 04  be  0xa01563b4
a01563a8:  92 10 00 0f  mov  %o7, %o1
a01563ac:  a0 16 80 12  or  %i2, %l2, %l0
a01563b0:  a2 16 c0 13  or  %i3, %l3, %l1
a01563b4:  80 a6 00 0a  cmp  %i0, %o2
a01563b8:  18 bf ff f0  bgu  0xa0156378
a01563bc:  97 2e 20 1f  sll  %i0, 0x1f, %o3
a01563c0:  03 03 ff ff  sethi  %hi(0xffffc00), %g1
a01563c4:  82 10 63 ff  or  %g1, 0x3ff, %g1	! 0xfffffff
a01563c8:  80 a6 00 01  cmp  %i0, %g1
a01563cc:  18 80 00 14  bgu  0xa015641c
a01563d0:  9b 34 60 1f  srl  %l1, 0x1f, %o5
a01563d4:  82 04 00 10  add  %l0, %l0, %g1
a01563d8:  9f 36 60 1f  srl  %i1, 0x1f, %o7
a01563dc:  90 06 00 18  add  %i0, %i0, %o0
a01563e0:  94 13 40 01  or  %o5, %g1, %o2
a01563e4:  98 13 c0 08  or  %o7, %o0, %o4
a01563e8:  92 02 7f ff  add  %o1, -1, %o1
a01563ec:  96 04 40 11  add  %l1, %l1, %o3
a01563f0:  9a 06 40 19  add  %i1, %i1, %o5
a01563f4:  80 a4 20 00  cmp  %l0, 0
a01563f8:  b0 10 00 0c  mov  %o4, %i0
a01563fc:  b2 10 00 0d  mov  %o5, %i1
a0156400:  a0 10 00 0a  mov  %o2, %l0
a0156404:  a2 10 00 0b  mov  %o3, %l1
a0156408:  16 bf ff ee  bge  0xa01563c0
a015640c:  9e 10 00 09  mov  %o1, %o7
a0156410:  b0 13 20 00  mov  %o4, %i0
a0156414:  10 bf ff eb  b  0xa01563c0
a0156418:  b2 13 60 01  or  %o5, 1, %i1
a015641c:  98 0e 20 00  and  %i0, 0, %o4
a0156420:  9a 0e 60 ff  and  %i1, 0xff, %o5
a0156424:  80 a3 20 00  cmp  %o4, 0
a0156428:  12 80 00 05  bne  0xa015643c
a015642c:  de 25 60 08  st  %o7, [ %l5 + 8 ]
a0156430:  80 a3 60 80  cmp  %o5, 0x80
a0156434:  02 80 00 11  be  0xa0156478
a0156438:  9a 0e 61 00  and  %i1, 0x100, %o5
a015643c:  82 10 20 03  mov  3, %g1
a0156440:  f0 3d 60 10  std  %i0, [ %l5 + 0x10 ]
a0156444:  c2 25 40 00  st  %g1, [ %l5 ]
a0156448:  10 80 00 15  b  0xa015649c
a015644c:  90 10 00 15  mov  %l5, %o0
a0156450:  08 bf ff b1  bleu  0xa0156314
a0156454:  9a 84 00 0b  addcc  %l0, %o3, %o5
a0156458:  a6 84 e0 01  inccc  %l3
a015645c:  10 bf ff ad  b  0xa0156310
a0156460:  a4 44 a0 00  addx  %l2, 0, %l2
a0156464:  08 bf ff a3  bleu  0xa01562f0
a0156468:  b6 10 20 00  clr  %i3
a015646c:  a4 10 20 01  mov  1, %l2
a0156470:  10 bf ff 9f  b  0xa01562ec
a0156474:  a6 10 20 00  clr  %l3
a0156478:  80 93 00 0d  orcc  %o4, %o5, %g0
a015647c:  32 80 00 06  bne,a   0xa0156494
a0156480:  b2 86 60 80  addcc  %i1, 0x80, %i1
a0156484:  80 94 00 11  orcc  %l0, %l1, %g0
a0156488:  02 bf ff ee  be  0xa0156440
a015648c:  82 10 20 03  mov  3, %g1
a0156490:  b2 86 60 80  addcc  %i1, 0x80, %i1
a0156494:  10 bf ff ea  b  0xa015643c
a0156498:  b0 46 20 00  addx  %i0, 0, %i0
a015649c:  40 00 03 2c  call  0xa015714c
a01564a0:  01 00 00 00  nop
a01564a4:  b0 10 00 08  mov  %o0, %i0
a01564a8:  81 c7 e0 08  ret
a01564ac:  93 e8 00 09  restore  %g0, %o1, %o1
