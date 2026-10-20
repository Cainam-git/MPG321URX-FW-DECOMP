# leon2m FUN_a01312d4 0xa01312d4-0xa013143c (360 bytes)
a01312d4:  9d e3 bf 30  save  %sp, -208, %sp
a01312d8:  b0 0e 20 ff  and  %i0, 0xff, %i0
a01312dc:  97 2e 20 04  sll  %i0, 4, %o3
a01312e0:  94 22 c0 18  sub  %o3, %i0, %o2
a01312e4:  21 2a 00 b7  sethi  %hi(0xa802dc00), %l0
a01312e8:  83 2a a0 03  sll  %o2, 3, %g1
a01312ec:  9a 14 23 30  or  %l0, 0x330, %o5
a01312f0:  d2 03 40 01  ld  [ %o5 + %g1 ], %o1
a01312f4:  91 32 60 0c  srl  %o1, 0xc, %o0
a01312f8:  90 0a 20 0f  and  %o0, 0xf, %o0
a01312fc:  7f ff 31 49  call  0xa00fd820
a0131300:  a8 00 40 0d  add  %g1, %o5, %l4
a0131304:  ac 07 bf b8  add  %fp, -72, %l6
a0131308:  92 10 20 01  mov  1, %o1
a013130c:  80 8e 60 ff  btst  0xff, %i1
a0131310:  02 80 00 31  be  0xa01313d4
a0131314:  a4 10 20 01  mov  1, %l2
a0131318:  e6 05 00 00  ld  [ %l4 ], %l3
a013131c:  a3 34 e0 0c  srl  %l3, 0xc, %l1
a0131320:  7f ff bd 9e  call  0xa0120998
a0131324:  90 0c 60 0f  and  %l1, 0xf, %o0
a0131328:  de 05 00 00  ld  [ %l4 ], %o7
a013132c:  99 33 e0 0c  srl  %o7, 0xc, %o4
a0131330:  7f ff 31 3c  call  0xa00fd820
a0131334:  90 0b 20 0f  and  %o4, 0xf, %o0
a0131338:  90 0a 20 ff  and  %o0, 0xff, %o0
a013133c:  80 a2 20 b1  cmp  %o0, 0xb1
a0131340:  02 80 00 2b  be  0xa01313ec
a0131344:  96 10 3f ff  mov  -1, %o3
a0131348:  40 00 43 88  call  0xa0142168
a013134c:  21 2a 00 b8  sethi  %hi(0xa802e000), %l0
a0131350:  9e 0a 20 ff  and  %o0, 0xff, %o7
a0131354:  b3 2b e0 03  sll  %o7, 3, %i1
a0131358:  aa 06 40 0f  add  %i1, %o7, %l5
a013135c:  a2 05 40 15  add  %l5, %l5, %l1
a0131360:  a6 14 21 16  or  %l0, 0x116, %l3
a0131364:  92 05 20 06  add  %l4, 6, %o1
a0131368:  94 10 20 3c  mov  0x3c, %o2
a013136c:  90 10 00 16  mov  %l6, %o0
a0131370:  80 a3 e0 06  cmp  %o7, 6
a0131374:  18 80 00 03  bgu  0xa0131380
a0131378:  9a 04 40 13  add  %l1, %l3, %o5
a013137c:  e4 13 60 0e  lduh  [ %o5 + 0xe ], %l2
a0131380:  40 00 2d 64  call  0xa013c910
a0131384:  01 00 00 00  nop
a0131388:  da 05 00 00  ld  [ %l4 ], %o5
a013138c:  91 33 60 0c  srl  %o5, 0xc, %o0
a0131390:  93 2c a0 10  sll  %l2, 0x10, %o1
a0131394:  d4 1d 20 50  ldd  [ %l4 + 0x50 ], %o2
a0131398:  d8 1d 20 48  ldd  [ %l4 + 0x48 ], %o4
a013139c:  e0 1d 20 58  ldd  [ %l4 + 0x58 ], %l0
a01313a0:  e4 1d 20 60  ldd  [ %l4 + 0x60 ], %l2
a01313a4:  e8 1d 20 68  ldd  [ %l4 + 0x68 ], %l4
a01313a8:  d4 3f bf 98  std  %o2, [ %fp + -104 ]
a01313ac:  d8 3f bf 90  std  %o4, [ %fp + -112 ]
a01313b0:  e0 3f bf a0  std  %l0, [ %fp + -96 ]
a01313b4:  e4 3f bf a8  std  %l2, [ %fp + -88 ]
a01313b8:  e8 3f bf b0  std  %l4, [ %fp + -80 ]
a01313bc:  90 0a 20 0f  and  %o0, 0xf, %o0
a01313c0:  93 32 60 10  srl  %o1, 0x10, %o1
a01313c4:  94 10 00 16  mov  %l6, %o2
a01313c8:  7f ff 50 f2  call  0xa0105790
a01313cc:  96 07 bf 90  add  %fp, -112, %o3
a01313d0:  30 80 00 19  b,a   0xa0131434
a01313d4:  ec 05 00 00  ld  [ %l4 ], %l6
a01313d8:  a5 35 a0 0c  srl  %l6, 0xc, %l2
a01313dc:  90 0c a0 0f  and  %l2, 0xf, %o0
a01313e0:  7f ff bd 6e  call  0xa0120998
a01313e4:  92 10 20 00  clr  %o1
a01313e8:  30 80 00 13  b,a   0xa0131434
a01313ec:  1b 2a 00 a9  sethi  %hi(0xa802a400), %o5
a01313f0:  94 14 23 30  or  %l0, 0x330, %o2
a01313f4:  e0 0b 60 4c  ldub  [ %o5 + 0x4c ], %l0
a01313f8:  b3 2c 20 04  sll  %l0, 4, %i1
a01313fc:  aa 26 40 10  sub  %i1, %l0, %l5
a0131400:  80 a4 20 ff  cmp  %l0, 0xff
a0131404:  02 80 00 0a  be  0xa013142c
a0131408:  9b 2d 60 03  sll  %l5, 3, %o5
a013140c:  d8 02 80 0d  ld  [ %o2 + %o5 ], %o4
a0131410:  b1 33 20 0c  srl  %o4, 0xc, %i0
a0131414:  96 0e 20 0f  and  %i0, 0xf, %o3
a0131418:  15 2a 00 b8  sethi  %hi(0xa802e000), %o2
a013141c:  92 5a e0 2a  smul  %o3, 0x2a, %o1
a0131420:  82 12 a2 24  or  %o2, 0x224, %g1
a0131424:  90 02 40 01  add  %o1, %g1, %o0
a0131428:  d6 0a 20 0a  ldub  [ %o0 + 0xa ], %o3
a013142c:  10 bf ff c7  b  0xa0131348
a0131430:  90 0a e0 ff  and  %o3, 0xff, %o0
a0131434:  81 c7 e0 08  ret
a0131438:  81 e8 00 00  restore
