# leon2m FUN_a014c118 0xa014c118-0xa014c778 (624 bytes)
a014c118:  9d e3 bf 90  save  %sp, -112, %sp
a014c11c:  23 2a 00 b8  sethi  %hi(0xa802e000), %l1
a014c120:  82 14 63 d0  or  %l1, 0x3d0, %g1	! 0xa802e3d0
a014c124:  c0 37 bf f0  clrh  [ %fp + -16 ]
a014c128:  c0 2f bf f2  clrb  [ %fp + -14 ]
a014c12c:  7f ff 8c 02  call  0xa012f134
a014c130:  d0 08 60 18  ldub  [ %g1 + 0x18 ], %o0
a014c134:  80 8a 20 ff  btst  0xff, %o0
a014c138:  a0 10 00 18  mov  %i0, %l0
a014c13c:  aa 10 20 ff  mov  0xff, %l5
a014c140:  a6 10 20 ff  mov  0xff, %l3
a014c144:  a8 10 20 ff  mov  0xff, %l4
a014c148:  02 80 00 07  be  0xa014c164
a014c14c:  a4 10 20 01  mov  1, %l2
a014c150:  92 06 3f f1  add  %i0, -15, %o1
a014c154:  90 0a 60 ff  and  %o1, 0xff, %o0
a014c158:  80 a2 20 07  cmp  %o0, 7
a014c15c:  08 80 00 14  bleu  0xa014c1ac
a014c160:  01 00 00 00  nop
a014c164:  7f fe fb 99  call  0xa010afc8
a014c168:  01 00 00 00  nop
a014c16c:  7f fe fc 0b  call  0xa010b198
a014c170:  01 00 00 00  nop
a014c174:  96 04 3f f1  add  %l0, -15, %o3
a014c178:  94 0a e0 ff  and  %o3, 0xff, %o2
a014c17c:  80 a2 a0 07  cmp  %o2, 7
a014c180:  08 80 00 26  bleu  0xa014c218
a014c184:  b0 0c 20 ff  and  %l0, 0xff, %i0
a014c188:  80 a6 20 16  cmp  %i0, 0x16
a014c18c:  18 80 00 2b  bgu  0xa014c238
a014c190:  82 14 63 d0  or  %l1, 0x3d0, %g1
a014c194:  11 00 03 8d  sethi  %hi(0xe3400), %o0
a014c198:  a1 2e 20 02  sll  %i0, 2, %l0
a014c19c:  82 12 21 34  or  %o0, 0x134, %g1
a014c1a0:  de 00 40 10  ld  [ %g1 + %l0 ], %o7
a014c1a4:  81 c3 c0 00  jmp  %o7
a014c1a8:  01 00 00 00  nop
a014c1ac:  7f fe fb 7b  call  0xa010af98
a014c1b0:  01 00 00 00  nop
a014c1b4:  80 8a 20 ff  btst  0xff, %o0
a014c1b8:  02 80 00 07  be  0xa014c1d4
a014c1bc:  01 00 00 00  nop
a014c1c0:  7f fe fb e8  call  0xa010b160
a014c1c4:  01 00 00 00  nop
a014c1c8:  80 8a 20 ff  btst  0xff, %o0
a014c1cc:  12 bf ff eb  bne  0xa014c178
a014c1d0:  96 04 3f f1  add  %l0, -15, %o3
a014c1d4:  7f fe fb 7d  call  0xa010afc8
a014c1d8:  b0 0c 20 ff  and  %l0, 0xff, %i0
a014c1dc:  7f fe fb ef  call  0xa010b198
a014c1e0:  01 00 00 00  nop
a014c1e4:  7f fe fb 80  call  0xa010afe4
a014c1e8:  90 10 20 00  clr  %o0	! 0x0
a014c1ec:  7f fe fb f2  call  0xa010b1b4
a014c1f0:  90 10 20 00  clr  %o0
a014c1f4:  7f fe fb 6e  call  0xa010afac
a014c1f8:  01 00 00 00  nop
a014c1fc:  7f fe fb e0  call  0xa010b17c
a014c200:  01 00 00 00  nop
a014c204:  96 04 3f f1  add  %l0, -15, %o3
a014c208:  94 0a e0 ff  and  %o3, 0xff, %o2
a014c20c:  80 a2 a0 07  cmp  %o2, 7
a014c210:  18 bf ff df  bgu  0xa014c18c
a014c214:  80 a6 20 16  cmp  %i0, 0x16
a014c218:  7f ff 89 aa  call  0xa012e8c0
a014c21c:  90 10 00 18  mov  %i0, %o0
a014c220:  9a 0a 20 ff  and  %o0, 0xff, %o5
a014c224:  98 14 63 d0  or  %l1, 0x3d0, %o4
a014c228:  80 a6 20 16  cmp  %i0, 0x16
a014c22c:  08 bf ff da  bleu  0xa014c194
a014c230:  da 33 20 1a  sth  %o5, [ %o4 + 0x1a ]
a014c234:  82 14 63 d0  or  %l1, 0x3d0, %g1
a014c238:  d0 08 60 0e  ldub  [ %g1 + 0xe ], %o0
a014c23c:  e8 08 60 0c  ldub  [ %g1 + 0xc ], %l4
a014c240:  e6 08 60 0d  ldub  [ %g1 + 0xd ], %l3
a014c244:  9a 5d 20 c8  smul  %l4, 0xc8, %o5
a014c248:  98 5c e0 c8  smul  %l3, 0xc8, %o4
a014c24c:  9e 5a 20 c8  smul  %o0, 0xc8, %o7
a014c250:  21 14 7a e1  sethi  %hi(0x51eb8400), %l0
a014c254:  aa 14 21 1f  or  %l0, 0x11f, %l5	! 0x51eb851f
a014c258:  94 03 60 32  add  %o5, 0x32, %o2
a014c25c:  92 03 20 32  add  %o4, 0x32, %o1
a014c260:  96 03 e0 32  add  %o7, 0x32, %o3
a014c264:  80 52 c0 15  umul  %o3, %l5, %g0
a014c268:  a7 40 00 00  rd  %y, %l3
a014c26c:  80 52 40 15  umul  %o1, %l5, %g0
a014c270:  a9 40 00 00  rd  %y, %l4
a014c274:  80 52 80 15  umul  %o2, %l5, %g0
a014c278:  b1 40 00 00  rd  %y, %i0
a014c27c:  91 35 20 05  srl  %l4, 5, %o0
a014c280:  a1 34 e0 05  srl  %l3, 5, %l0
a014c284:  83 36 20 05  srl  %i0, 5, %g1
a014c288:  aa 00 60 37  add  %g1, 0x37, %l5
a014c28c:  a6 02 20 37  add  %o0, 0x37, %l3
a014c290:  a8 04 20 37  add  %l0, 0x37, %l4
a014c294:  21 2a 00 b7  sethi  %hi(0xa802dc00), %l0
a014c298:  d4 04 23 30  ld  [ %l0 + 0x330 ], %o2	! 0xa802df30
a014c29c:  93 32 a0 0c  srl  %o2, 0xc, %o1
a014c2a0:  7f ff cf 6e  call  0xa0140058
a014c2a4:  90 0a 60 0f  and  %o1, 0xf, %o0
a014c2a8:  b0 0a 20 ff  and  %o0, 0xff, %i0
a014c2ac:  80 a6 20 01  cmp  %i0, 1
a014c2b0:  02 80 00 0f  be  0xa014c2ec
a014c2b4:  c2 04 23 30  ld  [ %l0 + 0x330 ], %g1
a014c2b8:  91 30 60 0c  srl  %g1, 0xc, %o0
a014c2bc:  a0 0a 20 0f  and  %o0, 0xf, %l0
a014c2c0:  1b 2a 00 b8  sethi  %hi(0xa802e000), %o5
a014c2c4:  9e 5c 20 2a  smul  %l0, 0x2a, %o7
a014c2c8:  98 13 62 24  or  %o5, 0x224, %o4
a014c2cc:  d6 13 00 0f  lduh  [ %o4 + %o7 ], %o3
a014c2d0:  80 8a e0 40  btst  0x40, %o3
a014c2d4:  12 80 00 06  bne  0xa014c2ec
a014c2d8:  80 8c a0 ff  btst  0xff, %l2
a014c2dc:  02 80 01 25  be  0xa014c770
a014c2e0:  92 04 e0 01  add  %l3, 1, %o1
a014c2e4:  10 80 00 1e  b  0xa014c35c
a014c2e8:  94 05 20 01  add  %l4, 1, %o2
a014c2ec:  aa 14 63 d0  or  %l1, 0x3d0, %l5
a014c2f0:  e2 0d 60 0e  ldub  [ %l5 + 0xe ], %l1
a014c2f4:  e6 0d 60 0c  ldub  [ %l5 + 0xc ], %l3
a014c2f8:  e8 0d 60 0d  ldub  [ %l5 + 0xd ], %l4
a014c2fc:  90 5c e0 c8  smul  %l3, 0xc8, %o0
a014c300:  a0 5c 60 c8  smul  %l1, 0xc8, %l0
a014c304:  03 14 7a e1  sethi  %hi(0x51eb8400), %g1
a014c308:  9e 10 61 1f  or  %g1, 0x11f, %o7	! 0x51eb851f
a014c30c:  98 5d 20 c8  smul  %l4, 0xc8, %o4
a014c310:  9a 02 20 32  add  %o0, 0x32, %o5
a014c314:  96 04 20 32  add  %l0, 0x32, %o3
a014c318:  80 52 c0 0f  umul  %o3, %o7, %g0
a014c31c:  ab 40 00 00  rd  %y, %l5
a014c320:  94 03 20 32  add  %o4, 0x32, %o2
a014c324:  80 53 40 0f  umul  %o5, %o7, %g0
a014c328:  93 40 00 00  rd  %y, %o1
a014c32c:  a7 32 60 05  srl  %o1, 5, %l3
a014c330:  a3 35 60 05  srl  %l5, 5, %l1
a014c334:  80 52 80 0f  umul  %o2, %o7, %g0
a014c338:  b1 40 00 00  rd  %y, %i0
a014c33c:  a9 36 20 05  srl  %i0, 5, %l4
a014c340:  aa 04 e0 37  add  %l3, 0x37, %l5
a014c344:  a6 05 20 37  add  %l4, 0x37, %l3
a014c348:  80 8c a0 ff  btst  0xff, %l2
a014c34c:  02 80 01 09  be  0xa014c770
a014c350:  a8 04 60 37  add  %l1, 0x37, %l4
a014c354:  92 04 e0 01  add  %l3, 1, %o1
a014c358:  94 05 20 01  add  %l4, 1, %o2
a014c35c:  9a 05 60 01  add  %l5, 1, %o5
a014c360:  9f 2b 60 10  sll  %o5, 0x10, %o7
a014c364:  b1 2a 60 10  sll  %o1, 0x10, %i0
a014c368:  a5 2a a0 10  sll  %o2, 0x10, %l2
a014c36c:  91 33 e0 10  srl  %o7, 0x10, %o0
a014c370:  93 36 20 10  srl  %i0, 0x10, %o1
a014c374:  7f ff bc 4c  call  0xa013b4a4
a014c378:  95 34 a0 10  srl  %l2, 0x10, %o2
a014c37c:  30 80 00 fd  b,a   0xa014c770
a014c380:  aa 10 20 ff  mov  0xff, %l5
a014c384:  a6 10 20 ff  mov  0xff, %l3
a014c388:  10 bf ff c3  b  0xa014c294
a014c38c:  a8 10 20 ff  mov  0xff, %l4
a014c390:  a0 14 63 d0  or  %l1, 0x3d0, %l0
a014c394:  7f ff 8b 68  call  0xa012f134
a014c398:  d0 0c 20 18  ldub  [ %l0 + 0x18 ], %o0
a014c39c:  80 8a 20 ff  btst  0xff, %o0
a014c3a0:  32 80 00 cd  bne,a   0xa014c6d4
a014c3a4:  f0 0c 20 18  ldub  [ %l0 + 0x18 ], %i0
a014c3a8:  17 2a 00 b8  sethi  %hi(0xa802e000), %o3
a014c3ac:  9a 12 e1 f0  or  %o3, 0x1f0, %o5	! 0xa802e1f0
a014c3b0:  d2 0b 60 06  ldub  [ %o5 + 6 ], %o1
a014c3b4:  80 a2 60 7e  cmp  %o1, 0x7e
a014c3b8:  08 80 00 bc  bleu  0xa014c6a8
a014c3bc:  98 12 e1 f0  or  %o3, 0x1f0, %o4
a014c3c0:  d4 0b 60 07  ldub  [ %o5 + 7 ], %o2
a014c3c4:  80 a2 a0 73  cmp  %o2, 0x73
a014c3c8:  08 80 00 b9  bleu  0xa014c6ac
a014c3cc:  a0 10 3f bd  mov  -67, %l0
a014c3d0:  c2 0b 60 08  ldub  [ %o5 + 8 ], %g1
a014c3d4:  80 a0 60 00  cmp  %g1, 0
a014c3d8:  02 80 00 b6  be  0xa014c6b0
a014c3dc:  9e 10 3f ff  mov  -1, %o7
a014c3e0:  80 a0 60 ff  cmp  %g1, 0xff
a014c3e4:  02 80 00 b3  be  0xa014c6b0
a014c3e8:  01 00 00 00  nop
a014c3ec:  82 12 e1 f0  or  %o3, 0x1f0, %g1
a014c3f0:  e8 08 60 08  ldub  [ %g1 + 8 ], %l4
a014c3f4:  ea 08 60 06  ldub  [ %g1 + 6 ], %l5
a014c3f8:  10 bf ff a7  b  0xa014c294
a014c3fc:  e6 08 60 07  ldub  [ %g1 + 7 ], %l3
a014c400:  a0 14 63 d0  or  %l1, 0x3d0, %l0
a014c404:  7f ff 8b 4c  call  0xa012f134
a014c408:  d0 0c 20 18  ldub  [ %l0 + 0x18 ], %o0
a014c40c:  80 8a 20 ff  btst  0xff, %o0
a014c410:  12 80 00 cb  bne  0xa014c73c
a014c414:  19 2a 00 b8  sethi  %hi(0xa802e000), %o4
a014c418:  9a 13 21 f0  or  %o4, 0x1f0, %o5	! 0xa802e1f0
a014c41c:  ea 0b 60 09  ldub  [ %o5 + 9 ], %l5
a014c420:  80 a5 60 7e  cmp  %l5, 0x7e
a014c424:  08 80 00 0b  bleu  0xa014c450
a014c428:  94 13 21 f0  or  %o4, 0x1f0, %o2
a014c42c:  f0 0b 60 0a  ldub  [ %o5 + 0xa ], %i0
a014c430:  80 a6 20 7e  cmp  %i0, 0x7e
a014c434:  28 80 00 08  bleu,a   0xa014c454
a014c438:  9a 10 3f ff  mov  -1, %o5
a014c43c:  d2 0b 60 0b  ldub  [ %o5 + 0xb ], %o1
a014c440:  80 a2 60 7e  cmp  %o1, 0x7e
a014c444:  18 80 00 08  bgu  0xa014c464
a014c448:  9e 13 21 f0  or  %o4, 0x1f0, %o7
a014c44c:  94 13 21 f0  or  %o4, 0x1f0, %o2
a014c450:  9a 10 3f ff  mov  -1, %o5
a014c454:  da 2a a0 0b  stb  %o5, [ %o2 + 0xb ]
a014c458:  da 2a a0 09  stb  %o5, [ %o2 + 9 ]
a014c45c:  da 2a a0 0a  stb  %o5, [ %o2 + 0xa ]
a014c460:  9e 13 21 f0  or  %o4, 0x1f0, %o7
a014c464:  e8 0b e0 0b  ldub  [ %o7 + 0xb ], %l4
a014c468:  ea 0b e0 09  ldub  [ %o7 + 9 ], %l5
a014c46c:  10 bf ff 8a  b  0xa014c294
a014c470:  e6 0b e0 0a  ldub  [ %o7 + 0xa ], %l3
a014c474:  17 2a 00 b8  sethi  %hi(0xa802e000), %o3
a014c478:  9a 12 e1 f0  or  %o3, 0x1f0, %o5	! 0xa802e1f0
a014c47c:  d8 0b 60 0c  ldub  [ %o5 + 0xc ], %o4
a014c480:  80 a3 20 7b  cmp  %o4, 0x7b
a014c484:  08 80 00 0b  bleu  0xa014c4b0
a014c488:  90 12 e1 f0  or  %o3, 0x1f0, %o0
a014c48c:  e0 0b 60 0d  ldub  [ %o5 + 0xd ], %l0
a014c490:  80 a4 20 7e  cmp  %l0, 0x7e
a014c494:  08 80 00 08  bleu  0xa014c4b4
a014c498:  a6 10 3f ff  mov  -1, %l3
a014c49c:  c2 0b 60 0e  ldub  [ %o5 + 0xe ], %g1
a014c4a0:  80 a0 60 7e  cmp  %g1, 0x7e
a014c4a4:  18 80 00 09  bgu  0xa014c4c8
a014c4a8:  b0 12 e1 f0  or  %o3, 0x1f0, %i0
a014c4ac:  90 12 e1 f0  or  %o3, 0x1f0, %o0
a014c4b0:  a6 10 3f ff  mov  -1, %l3
a014c4b4:  a8 10 3f f8  mov  -8, %l4
a014c4b8:  e6 2a 20 0e  stb  %l3, [ %o0 + 0xe ]
a014c4bc:  e8 2a 20 0c  stb  %l4, [ %o0 + 0xc ]
a014c4c0:  e6 2a 20 0d  stb  %l3, [ %o0 + 0xd ]
a014c4c4:  b0 12 e1 f0  or  %o3, 0x1f0, %i0
a014c4c8:  e8 0e 20 0e  ldub  [ %i0 + 0xe ], %l4
a014c4cc:  ea 0e 20 0c  ldub  [ %i0 + 0xc ], %l5
a014c4d0:  10 bf ff 71  b  0xa014c294
a014c4d4:  e6 0e 20 0d  ldub  [ %i0 + 0xd ], %l3
a014c4d8:  17 2a 00 b8  sethi  %hi(0xa802e000), %o3
a014c4dc:  9a 12 e1 f0  or  %o3, 0x1f0, %o5	! 0xa802e1f0
a014c4e0:  ea 0b 60 0f  ldub  [ %o5 + 0xf ], %l5
a014c4e4:  80 a5 60 7b  cmp  %l5, 0x7b
a014c4e8:  08 80 00 0b  bleu  0xa014c514
a014c4ec:  9e 12 e1 f0  or  %o3, 0x1f0, %o7
a014c4f0:  d2 0b 60 10  ldub  [ %o5 + 0x10 ], %o1
a014c4f4:  80 a2 60 7b  cmp  %o1, 0x7b
a014c4f8:  08 80 00 08  bleu  0xa014c518
a014c4fc:  98 10 3f f8  mov  -8, %o4
a014c500:  d4 0b 60 11  ldub  [ %o5 + 0x11 ], %o2
a014c504:  80 a2 a0 7e  cmp  %o2, 0x7e
a014c508:  18 80 00 09  bgu  0xa014c52c
a014c50c:  a0 12 e1 f0  or  %o3, 0x1f0, %l0
a014c510:  9e 12 e1 f0  or  %o3, 0x1f0, %o7
a014c514:  98 10 3f f8  mov  -8, %o4
a014c518:  9a 10 3f ff  mov  -1, %o5
a014c51c:  da 2b e0 11  stb  %o5, [ %o7 + 0x11 ]
a014c520:  d8 2b e0 10  stb  %o4, [ %o7 + 0x10 ]
a014c524:  d8 2b e0 0f  stb  %o4, [ %o7 + 0xf ]
a014c528:  a0 12 e1 f0  or  %o3, 0x1f0, %l0
a014c52c:  e8 0c 20 11  ldub  [ %l0 + 0x11 ], %l4
a014c530:  ea 0c 20 0f  ldub  [ %l0 + 0xf ], %l5
a014c534:  10 bf ff 58  b  0xa014c294
a014c538:  e6 0c 20 10  ldub  [ %l0 + 0x10 ], %l3
a014c53c:  a0 14 63 d0  or  %l1, 0x3d0, %l0
a014c540:  7f ff 8a fd  call  0xa012f134
a014c544:  d0 0c 20 18  ldub  [ %l0 + 0x18 ], %o0
a014c548:  80 8a 20 ff  btst  0xff, %o0
a014c54c:  32 80 00 70  bne,a   0xa014c70c
a014c550:  e6 0c 20 18  ldub  [ %l0 + 0x18 ], %l3
a014c554:  17 2a 00 b8  sethi  %hi(0xa802e000), %o3
a014c558:  9a 12 e1 f0  or  %o3, 0x1f0, %o5	! 0xa802e1f0
a014c55c:  e8 0b 60 12  ldub  [ %o5 + 0x12 ], %l4
a014c560:  80 a5 20 67  cmp  %l4, 0x67
a014c564:  08 80 00 0b  bleu  0xa014c590
a014c568:  92 12 e1 f0  or  %o3, 0x1f0, %o1
a014c56c:  f0 0b 60 13  ldub  [ %o5 + 0x13 ], %i0
a014c570:  80 a6 20 6a  cmp  %i0, 0x6a
a014c574:  08 80 00 08  bleu  0xa014c594
a014c578:  98 10 3f ff  mov  -1, %o4
a014c57c:  ea 0b 60 14  ldub  [ %o5 + 0x14 ], %l5
a014c580:  80 a5 60 7e  cmp  %l5, 0x7e
a014c584:  38 80 00 0b  bgu,a   0xa014c5b0
a014c588:  e8 0b 60 14  ldub  [ %o5 + 0x14 ], %l4
a014c58c:  92 12 e1 f0  or  %o3, 0x1f0, %o1
a014c590:  98 10 3f ff  mov  -1, %o4
a014c594:  9e 10 3f d1  mov  -47, %o7
a014c598:  94 10 3f d6  mov  -42, %o2
a014c59c:  d8 2a 60 14  stb  %o4, [ %o1 + 0x14 ]
a014c5a0:  de 2a 60 12  stb  %o7, [ %o1 + 0x12 ]
a014c5a4:  d4 2a 60 13  stb  %o2, [ %o1 + 0x13 ]
a014c5a8:  9a 12 e1 f0  or  %o3, 0x1f0, %o5
a014c5ac:  e8 0b 60 14  ldub  [ %o5 + 0x14 ], %l4
a014c5b0:  ea 0b 60 12  ldub  [ %o5 + 0x12 ], %l5
a014c5b4:  10 bf ff 38  b  0xa014c294
a014c5b8:  e6 0b 60 13  ldub  [ %o5 + 0x13 ], %l3
a014c5bc:  17 2a 00 b8  sethi  %hi(0xa802e000), %o3
a014c5c0:  9a 12 e1 f0  or  %o3, 0x1f0, %o5	! 0xa802e1f0
a014c5c4:  e0 0b 60 15  ldub  [ %o5 + 0x15 ], %l0
a014c5c8:  80 a4 20 77  cmp  %l0, 0x77
a014c5cc:  08 80 00 0b  bleu  0xa014c5f8
a014c5d0:  a6 12 e1 f0  or  %o3, 0x1f0, %l3
a014c5d4:  d0 0b 60 16  ldub  [ %o5 + 0x16 ], %o0
a014c5d8:  80 a2 20 77  cmp  %o0, 0x77
a014c5dc:  08 80 00 08  bleu  0xa014c5fc
a014c5e0:  a8 10 3f f0  mov  -16, %l4
a014c5e4:  c2 0b 60 17  ldub  [ %o5 + 0x17 ], %g1
a014c5e8:  80 a0 60 7e  cmp  %g1, 0x7e
a014c5ec:  18 80 00 09  bgu  0xa014c610
a014c5f0:  92 12 e1 f0  or  %o3, 0x1f0, %o1
a014c5f4:  a6 12 e1 f0  or  %o3, 0x1f0, %l3
a014c5f8:  a8 10 3f f0  mov  -16, %l4
a014c5fc:  b0 10 3f ff  mov  -1, %i0
a014c600:  f0 2c e0 17  stb  %i0, [ %l3 + 0x17 ]
a014c604:  e8 2c e0 16  stb  %l4, [ %l3 + 0x16 ]
a014c608:  e8 2c e0 15  stb  %l4, [ %l3 + 0x15 ]
a014c60c:  92 12 e1 f0  or  %o3, 0x1f0, %o1
a014c610:  e8 0a 60 17  ldub  [ %o1 + 0x17 ], %l4
a014c614:  ea 0a 60 15  ldub  [ %o1 + 0x15 ], %l5
a014c618:  10 bf ff 1f  b  0xa014c294
a014c61c:  e6 0a 60 16  ldub  [ %o1 + 0x16 ], %l3
a014c620:  7f fe fa 63  call  0xa010afac
a014c624:  a4 10 20 00  clr  %l2
a014c628:  7f fe fa d5  call  0xa010b17c
a014c62c:  21 2a 00 b7  sethi  %hi(0xa802dc00), %l0
a014c630:  10 bf ff 1b  b  0xa014c29c
a014c634:  d4 04 23 30  ld  [ %l0 + 0x330 ], %o2	! 0xa802df30
a014c638:  2b 2a 00 b8  sethi  %hi(0xa802e000), %l5
a014c63c:  96 15 61 f0  or  %l5, 0x1f0, %o3	! 0xa802e1f0
a014c640:  e8 0a e0 1d  ldub  [ %o3 + 0x1d ], %l4
a014c644:  ea 0a e0 1b  ldub  [ %o3 + 0x1b ], %l5
a014c648:  10 bf ff 13  b  0xa014c294
a014c64c:  e6 0a e0 1c  ldub  [ %o3 + 0x1c ], %l3
a014c650:  1f 2a 00 b8  sethi  %hi(0xa802e000), %o7
a014c654:  94 13 e1 f0  or  %o7, 0x1f0, %o2	! 0xa802e1f0
a014c658:  e8 0a a0 20  ldub  [ %o2 + 0x20 ], %l4
a014c65c:  ea 0a a0 1e  ldub  [ %o2 + 0x1e ], %l5
a014c660:  10 bf ff 0d  b  0xa014c294
a014c664:  e6 0a a0 1f  ldub  [ %o2 + 0x1f ], %l3
a014c668:  a0 14 63 d0  or  %l1, 0x3d0, %l0
a014c66c:  7f ff 8a b2  call  0xa012f134
a014c670:  d0 0c 20 18  ldub  [ %l0 + 0x18 ], %o0
a014c674:  80 8a 20 ff  btst  0xff, %o0
a014c678:  12 80 00 13  bne  0xa014c6c4
a014c67c:  80 a6 20 0f  cmp  %i0, 0xf
a014c680:  aa 10 20 ff  mov  0xff, %l5
a014c684:  a6 10 20 ff  mov  0xff, %l3
a014c688:  12 bf ff 03  bne  0xa014c294
a014c68c:  a8 10 20 ff  mov  0xff, %l4
a014c690:  1b 2a 00 b8  sethi  %hi(0xa802e000), %o5
a014c694:  98 13 61 f0  or  %o5, 0x1f0, %o4	! 0xa802e1f0
a014c698:  e8 0b 20 23  ldub  [ %o4 + 0x23 ], %l4
a014c69c:  ea 0b 20 21  ldub  [ %o4 + 0x21 ], %l5
a014c6a0:  10 bf fe fd  b  0xa014c294
a014c6a4:  e6 0b 20 22  ldub  [ %o4 + 0x22 ], %l3
a014c6a8:  a0 10 3f bd  mov  -67, %l0
a014c6ac:  9e 10 3f ff  mov  -1, %o7
a014c6b0:  9a 10 3f e8  mov  -24, %o5
a014c6b4:  e0 2b 20 08  stb  %l0, [ %o4 + 8 ]
a014c6b8:  de 2b 20 06  stb  %o7, [ %o4 + 6 ]
a014c6bc:  10 bf ff 4c  b  0xa014c3ec
a014c6c0:  da 2b 20 07  stb  %o5, [ %o4 + 7 ]
a014c6c4:  7f ff 87 ff  call  0xa012e6c0
a014c6c8:  d0 14 20 1a  lduh  [ %l0 + 0x1a ], %o0
a014c6cc:  10 bf fe f2  b  0xa014c294
a014c6d0:  a4 10 20 00  clr  %l2
a014c6d4:  aa 0e 20 0f  and  %i0, 0xf, %l5
a014c6d8:  29 00 00 40  sethi  %hi(0x10000), %l4
a014c6dc:  a7 2d 00 15  sll  %l4, %l5, %l3
a014c6e0:  91 34 e0 10  srl  %l3, 0x10, %o0
a014c6e4:  92 10 20 02  mov  2, %o1
a014c6e8:  7f ff 87 9a  call  0xa012e550
a014c6ec:  94 07 bf f0  add  %fp, -16, %o2
a014c6f0:  80 8a 20 ff  btst  0xff, %o0
a014c6f4:  02 bf ff 2e  be  0xa014c3ac
a014c6f8:  17 2a 00 b8  sethi  %hi(0xa802e000), %o3
a014c6fc:  ea 0f bf f0  ldub  [ %fp + -16 ], %l5
a014c700:  e6 0f bf f1  ldub  [ %fp + -15 ], %l3
a014c704:  10 bf fe e4  b  0xa014c294
a014c708:  e8 0f bf f2  ldub  [ %fp + -14 ], %l4
a014c70c:  82 0c e0 0f  and  %l3, 0xf, %g1
a014c710:  11 00 00 40  sethi  %hi(0x10000), %o0
a014c714:  97 2a 00 01  sll  %o0, %g1, %o3
a014c718:  91 32 e0 10  srl  %o3, 0x10, %o0
a014c71c:  92 10 20 80  mov  0x80, %o1
a014c720:  7f ff 87 8c  call  0xa012e550
a014c724:  94 07 bf f0  add  %fp, -16, %o2
a014c728:  80 8a 20 ff  btst  0xff, %o0
a014c72c:  02 bf ff 8b  be  0xa014c558
a014c730:  17 2a 00 b8  sethi  %hi(0xa802e000), %o3
a014c734:  10 bf ff f3  b  0xa014c700
a014c738:  ea 0f bf f0  ldub  [ %fp + -16 ], %l5
a014c73c:  e8 0c 20 18  ldub  [ %l0 + 0x18 ], %l4
a014c740:  11 00 00 40  sethi  %hi(0x10000), %o0
a014c744:  a6 0d 20 0f  and  %l4, 0xf, %l3
a014c748:  97 2a 00 13  sll  %o0, %l3, %o3
a014c74c:  91 32 e0 10  srl  %o3, 0x10, %o0
a014c750:  92 10 20 10  mov  0x10, %o1
a014c754:  7f ff 87 7f  call  0xa012e550
a014c758:  94 07 bf f0  add  %fp, -16, %o2
a014c75c:  80 8a 20 ff  btst  0xff, %o0
a014c760:  12 bf ff e8  bne  0xa014c700
a014c764:  ea 0f bf f0  ldub  [ %fp + -16 ], %l5
a014c768:  10 bf ff 2c  b  0xa014c418
a014c76c:  19 2a 00 b8  sethi  %hi(0xa802e000), %o4
a014c770:  81 c7 e0 08  ret
a014c774:  81 e8 00 00  restore
