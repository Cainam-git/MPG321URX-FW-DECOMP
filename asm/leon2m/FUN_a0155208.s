# leon2m FUN_a0155208 0xa0155208-0xa015555c (852 bytes)
a0155208:  9d e3 bf 98  save  %sp, -104, %sp
a015520c:  a0 10 00 18  mov  %i0, %l0
a0155210:  92 10 00 1a  mov  %i2, %o1
a0155214:  80 a6 a0 00  cmp  %i2, 0
a0155218:  a2 10 20 00  clr  %l1
a015521c:  90 10 00 1b  mov  %i3, %o0
a0155220:  12 80 00 1e  bne  0xa0155298
a0155224:  b0 10 00 19  mov  %i1, %i0
a0155228:  80 a6 c0 10  cmp  %i3, %l0
a015522c:  08 80 00 3d  bleu  0xa0155320
a0155230:  80 a6 e0 00  cmp  %i3, 0
a0155234:  98 10 00 19  mov  %i1, %o4
a0155238:  9a 10 20 00  clr  %o5
a015523c:  82 10 20 20  mov  0x20, %g1
a0155240:  80 a4 00 1b  cmp  %l0, %i3
a0155244:  0a 80 00 0c  bcs  0xa0155274
a0155248:  98 c3 00 0c  addxcc  %o4, %o4, %o4
a015524c:  a0 24 00 1b  sub  %l0, %i3, %l0
a0155250:  a0 44 00 10  addx  %l0, %l0, %l0
a0155254:  82 a0 60 01  deccc  %g1
a0155258:  12 bf ff fb  bne  0xa0155244
a015525c:  80 a4 00 1b  cmp  %l0, %i3
a0155260:  0a 80 00 0b  bcs  0xa015528c
a0155264:  98 c3 00 0c  addxcc  %o4, %o4, %o4
a0155268:  10 80 00 09  b  0xa015528c
a015526c:  a0 24 00 1b  sub  %l0, %i3, %l0
a0155270:  a0 24 00 1b  sub  %l0, %i3, %l0
a0155274:  a0 c4 00 10  addxcc  %l0, %l0, %l0
a0155278:  1a bf ff f8  bcc  0xa0155258
a015527c:  82 a0 60 01  deccc  %g1
a0155280:  12 bf ff fc  bne  0xa0155270
a0155284:  98 83 00 0c  addcc  %o4, %o4, %o4
a0155288:  a0 24 00 1b  sub  %l0, %i3, %l0
a015528c:  98 3b 20 00  xnor  %o4, 0, %o4
a0155290:  10 80 00 b1  b  0xa0155554
a0155294:  b0 10 00 0d  mov  %o5, %i0
a0155298:  80 a6 80 10  cmp  %i2, %l0
a015529c:  98 10 20 00  clr  %o4
a01552a0:  18 80 00 ac  bgu  0xa0155550
a01552a4:  9a 10 20 00  clr  %o5
a01552a8:  03 00 00 3f  sethi  %hi(0xfc00), %g1
a01552ac:  82 10 63 ff  or  %g1, 0x3ff, %g1	! 0xffff
a01552b0:  80 a6 80 01  cmp  %i2, %g1
a01552b4:  08 80 00 4f  bleu  0xa01553f0
a01552b8:  80 a6 a0 ff  cmp  %i2, 0xff
a01552bc:  03 00 3f ff  sethi  %hi(0xfffc00), %g1
a01552c0:  82 10 63 ff  or  %g1, 0x3ff, %g1	! 0xffffff
a01552c4:  80 a0 40 1a  cmp  %g1, %i2
a01552c8:  9a 60 20 00  subx  %g0, 0, %o5
a01552cc:  96 0b 60 08  and  %o5, 8, %o3
a01552d0:  96 02 e0 10  add  %o3, 0x10, %o3
a01552d4:  1b 00 06 a0  sethi  %hi(0x1a8000), %o5
a01552d8:  9a 13 62 d8  or  %o5, 0x2d8, %o5	! 0x1a82d8
a01552dc:  83 32 40 0b  srl  %o1, %o3, %g1
a01552e0:  d8 0b 40 01  ldub  [ %o5 + %g1 ], %o4
a01552e4:  98 03 00 0b  add  %o4, %o3, %o4
a01552e8:  9a 10 20 20  mov  0x20, %o5
a01552ec:  9e a3 40 0c  subcc  %o5, %o4, %o7
a01552f0:  12 80 00 44  bne  0xa0155400
a01552f4:  9a 23 40 0f  sub  %o5, %o7, %o5
a01552f8:  80 a2 40 10  cmp  %o1, %l0
a01552fc:  9a 40 20 00  addx  %g0, 0, %o5
a0155300:  80 a6 00 08  cmp  %i0, %o0
a0155304:  82 60 3f ff  subx  %g0, -1, %g1
a0155308:  80 93 40 01  orcc  %o5, %g1, %g0
a015530c:  12 80 00 03  bne  0xa0155318
a0155310:  98 10 20 01  mov  1, %o4
a0155314:  98 10 20 00  clr  %o4
a0155318:  10 80 00 8e  b  0xa0155550
a015531c:  9a 10 20 00  clr  %o5
a0155320:  12 80 00 06  bne  0xa0155338
a0155324:  9a 10 00 10  mov  %l0, %o5
a0155328:  90 10 20 01  mov  1, %o0
a015532c:  40 00 05 d0  call  0xa0156a6c
a0155330:  92 10 20 00  clr  %o1
a0155334:  9a 10 00 10  mov  %l0, %o5
a0155338:  98 10 00 18  mov  %i0, %o4
a015533c:  82 10 20 20  mov  0x20, %g1
a0155340:  80 a4 40 08  cmp  %l1, %o0
a0155344:  0a 80 00 0c  bcs  0xa0155374
a0155348:  9a c3 40 0d  addxcc  %o5, %o5, %o5
a015534c:  a2 24 40 08  sub  %l1, %o0, %l1
a0155350:  a2 44 40 11  addx  %l1, %l1, %l1
a0155354:  82 a0 60 01  deccc  %g1
a0155358:  12 bf ff fb  bne  0xa0155344
a015535c:  80 a4 40 08  cmp  %l1, %o0
a0155360:  0a 80 00 0b  bcs  0xa015538c
a0155364:  9a c3 40 0d  addxcc  %o5, %o5, %o5
a0155368:  10 80 00 09  b  0xa015538c
a015536c:  a2 24 40 08  sub  %l1, %o0, %l1
a0155370:  a2 24 40 08  sub  %l1, %o0, %l1
a0155374:  a2 c4 40 11  addxcc  %l1, %l1, %l1
a0155378:  1a bf ff f8  bcc  0xa0155358
a015537c:  82 a0 60 01  deccc  %g1
a0155380:  12 bf ff fc  bne  0xa0155370
a0155384:  9a 83 40 0d  addcc  %o5, %o5, %o5
a0155388:  a2 24 40 08  sub  %l1, %o0, %l1
a015538c:  9a 3b 60 00  xnor  %o5, 0, %o5
a0155390:  a0 10 00 11  mov  %l1, %l0
a0155394:  82 10 20 20  mov  0x20, %g1
a0155398:  80 a4 00 08  cmp  %l0, %o0
a015539c:  0a 80 00 0c  bcs  0xa01553cc
a01553a0:  98 c3 00 0c  addxcc  %o4, %o4, %o4
a01553a4:  a0 24 00 08  sub  %l0, %o0, %l0
a01553a8:  a0 44 00 10  addx  %l0, %l0, %l0
a01553ac:  82 a0 60 01  deccc  %g1
a01553b0:  12 bf ff fb  bne  0xa015539c
a01553b4:  80 a4 00 08  cmp  %l0, %o0
a01553b8:  0a 80 00 0b  bcs  0xa01553e4
a01553bc:  98 c3 00 0c  addxcc  %o4, %o4, %o4
a01553c0:  10 80 00 09  b  0xa01553e4
a01553c4:  a0 24 00 08  sub  %l0, %o0, %l0
a01553c8:  a0 24 00 08  sub  %l0, %o0, %l0
a01553cc:  a0 c4 00 10  addxcc  %l0, %l0, %l0
a01553d0:  1a bf ff f8  bcc  0xa01553b0
a01553d4:  82 a0 60 01  deccc  %g1
a01553d8:  12 bf ff fc  bne  0xa01553c8
a01553dc:  98 83 00 0c  addcc  %o4, %o4, %o4
a01553e0:  a0 24 00 08  sub  %l0, %o0, %l0
a01553e4:  98 3b 20 00  xnor  %o4, 0, %o4
a01553e8:  10 80 00 5b  b  0xa0155554
a01553ec:  b0 10 00 0d  mov  %o5, %i0
a01553f0:  08 bf ff b9  bleu  0xa01552d4
a01553f4:  96 10 20 00  clr  %o3
a01553f8:  10 bf ff b7  b  0xa01552d4
a01553fc:  96 10 20 08  mov  8, %o3
a0155400:  83 32 00 0d  srl  %o0, %o5, %g1
a0155404:  95 36 00 0d  srl  %i0, %o5, %o2
a0155408:  99 2a 40 0f  sll  %o1, %o7, %o4
a015540c:  97 2c 00 0f  sll  %l0, %o7, %o3
a0155410:  9b 34 00 0d  srl  %l0, %o5, %o5
a0155414:  92 13 00 01  or  %o4, %g1, %o1
a0155418:  a0 12 c0 0a  or  %o3, %o2, %l0
a015541c:  98 10 00 10  mov  %l0, %o4
a0155420:  82 10 20 20  mov  0x20, %g1
a0155424:  80 a3 40 09  cmp  %o5, %o1
a0155428:  0a 80 00 0c  bcs  0xa0155458
a015542c:  98 c3 00 0c  addxcc  %o4, %o4, %o4
a0155430:  9a 23 40 09  sub  %o5, %o1, %o5
a0155434:  9a 43 40 0d  addx  %o5, %o5, %o5
a0155438:  82 a0 60 01  deccc  %g1
a015543c:  12 bf ff fb  bne  0xa0155428
a0155440:  80 a3 40 09  cmp  %o5, %o1
a0155444:  0a 80 00 0b  bcs  0xa0155470
a0155448:  98 c3 00 0c  addxcc  %o4, %o4, %o4
a015544c:  10 80 00 09  b  0xa0155470
a0155450:  9a 23 40 09  sub  %o5, %o1, %o5
a0155454:  9a 23 40 09  sub  %o5, %o1, %o5
a0155458:  9a c3 40 0d  addxcc  %o5, %o5, %o5
a015545c:  1a bf ff f8  bcc  0xa015543c
a0155460:  82 a0 60 01  deccc  %g1
a0155464:  12 bf ff fc  bne  0xa0155454
a0155468:  98 83 00 0c  addcc  %o4, %o4, %o4
a015546c:  9a 23 40 09  sub  %o5, %o1, %o5
a0155470:  98 3b 20 00  xnor  %o4, 0, %o4
a0155474:  a0 10 00 0d  mov  %o5, %l0
a0155478:  91 2a 00 0f  sll  %o0, %o7, %o0
a015547c:  b1 2e 00 0f  sll  %i0, %o7, %i0
a0155480:  81 80 00 0c  wr  %g0, %o4, %y
a0155484:  9b 3a 20 1f  sra  %o0, 0x1f, %o5
a0155488:  9a 0b 00 0d  and  %o4, %o5, %o5
a015548c:  82 88 20 00  andcc  %g0, 0, %g1
a0155490:  83 20 40 08  mulscc  %g1, %o0, %g1
a0155494:  83 20 40 08  mulscc  %g1, %o0, %g1
a0155498:  83 20 40 08  mulscc  %g1, %o0, %g1
a015549c:  83 20 40 08  mulscc  %g1, %o0, %g1
a01554a0:  83 20 40 08  mulscc  %g1, %o0, %g1
a01554a4:  83 20 40 08  mulscc  %g1, %o0, %g1
a01554a8:  83 20 40 08  mulscc  %g1, %o0, %g1
a01554ac:  83 20 40 08  mulscc  %g1, %o0, %g1
a01554b0:  83 20 40 08  mulscc  %g1, %o0, %g1
a01554b4:  83 20 40 08  mulscc  %g1, %o0, %g1
a01554b8:  83 20 40 08  mulscc  %g1, %o0, %g1
a01554bc:  83 20 40 08  mulscc  %g1, %o0, %g1
a01554c0:  83 20 40 08  mulscc  %g1, %o0, %g1
a01554c4:  83 20 40 08  mulscc  %g1, %o0, %g1
a01554c8:  83 20 40 08  mulscc  %g1, %o0, %g1
a01554cc:  83 20 40 08  mulscc  %g1, %o0, %g1
a01554d0:  83 20 40 08  mulscc  %g1, %o0, %g1
a01554d4:  83 20 40 08  mulscc  %g1, %o0, %g1
a01554d8:  83 20 40 08  mulscc  %g1, %o0, %g1
a01554dc:  83 20 40 08  mulscc  %g1, %o0, %g1
a01554e0:  83 20 40 08  mulscc  %g1, %o0, %g1
a01554e4:  83 20 40 08  mulscc  %g1, %o0, %g1
a01554e8:  83 20 40 08  mulscc  %g1, %o0, %g1
a01554ec:  83 20 40 08  mulscc  %g1, %o0, %g1
a01554f0:  83 20 40 08  mulscc  %g1, %o0, %g1
a01554f4:  83 20 40 08  mulscc  %g1, %o0, %g1
a01554f8:  83 20 40 08  mulscc  %g1, %o0, %g1
a01554fc:  83 20 40 08  mulscc  %g1, %o0, %g1
a0155500:  83 20 40 08  mulscc  %g1, %o0, %g1
a0155504:  83 20 40 08  mulscc  %g1, %o0, %g1
a0155508:  83 20 40 08  mulscc  %g1, %o0, %g1
a015550c:  83 20 40 08  mulscc  %g1, %o0, %g1
a0155510:  83 20 60 00  mulscc  %g1, 0, %g1
a0155514:  96 00 40 0d  add  %g1, %o5, %o3
a0155518:  95 40 00 00  rd  %y, %o2
a015551c:  80 a2 c0 10  cmp  %o3, %l0
a0155520:  38 80 00 0b  bgu,a   0xa015554c
a0155524:  98 03 3f ff  add  %o4, -1, %o4
a0155528:  82 1a c0 10  xor  %o3, %l0, %g1
a015552c:  80 a0 00 01  cmp  %g0, %g1
a0155530:  9a 60 3f ff  subx  %g0, -1, %o5
a0155534:  80 a6 00 0a  cmp  %i0, %o2
a0155538:  82 40 20 00  addx  %g0, 0, %g1
a015553c:  80 8b 40 01  btst  %o5, %g1
a0155540:  02 80 00 04  be  0xa0155550
a0155544:  9a 10 20 00  clr  %o5
a0155548:  98 03 3f ff  add  %o4, -1, %o4
a015554c:  9a 10 20 00  clr  %o5
a0155550:  b0 10 00 0d  mov  %o5, %i0
a0155554:  81 c7 e0 08  ret
a0155558:  93 e8 00 0c  restore  %g0, %o4, %o1
