# leon2m FUN_a01302e0 0xa01302e0-0xa0130438 (344 bytes)
a01302e0:  9d e3 bf 98  save  %sp, -104, %sp
a01302e4:  b0 0e 20 ff  and  %i0, 0xff, %i0
a01302e8:  a1 2e 20 04  sll  %i0, 4, %l0
a01302ec:  a2 24 00 18  sub  %l0, %i0, %l1
a01302f0:  a1 2c 60 03  sll  %l1, 3, %l0
a01302f4:  27 2a 00 b7  sethi  %hi(0xa802dc00), %l3
a01302f8:  a2 14 e3 30  or  %l3, 0x330, %l1	! 0xa802df30
a01302fc:  96 04 00 11  add  %l0, %l1, %o3
a0130300:  b2 0e 60 ff  and  %i1, 0xff, %i1
a0130304:  d8 02 e0 70  ld  [ %o3 + 0x70 ], %o4
a0130308:  9e 0e 60 01  and  %i1, 1, %o7
a013030c:  25 00 40 00  sethi  %hi(0x1000000), %l2
a0130310:  92 2b 00 12  andn  %o4, %l2, %o1
a0130314:  95 2b e0 18  sll  %o7, 0x18, %o2
a0130318:  90 12 40 0a  or  %o1, %o2, %o0
a013031c:  d0 22 e0 70  st  %o0, [ %o3 + 0x70 ]
a0130320:  d8 04 40 10  ld  [ %l1 + %l0 ], %o4
a0130324:  83 33 20 1c  srl  %o4, 0x1c, %g1
a0130328:  80 a0 00 01  cmp  %g0, %g1
a013032c:  9a 60 3f ff  subx  %g0, -1, %o5
a0130330:  80 a0 00 19  cmp  %g0, %i1
a0130334:  96 40 20 00  addx  %g0, 0, %o3
a0130338:  80 8b 40 0b  btst  %o5, %o3
a013033c:  02 80 00 09  be  0xa0130360
a0130340:  a5 33 20 0c  srl  %o4, 0xc, %l2
a0130344:  13 3c 00 00  sethi  %hi(0xf0000000), %o1
a0130348:  90 2b 00 09  andn  %o4, %o1, %o0
a013034c:  1b 14 00 00  sethi  %hi(0x50000000), %o5
a0130350:  82 12 00 0d  or  %o0, %o5, %g1
a0130354:  c2 24 40 10  st  %g1, [ %l1 + %l0 ]
a0130358:  98 10 00 01  mov  %g1, %o4
a013035c:  a5 33 20 0c  srl  %o4, 0xc, %l2
a0130360:  98 0c a0 0f  and  %l2, 0xf, %o4
a0130364:  13 2a 00 b8  sethi  %hi(0xa802e000), %o1
a0130368:  a4 12 62 24  or  %o1, 0x224, %l2	! 0xa802e224
a013036c:  90 5b 20 2a  smul  %o4, 0x2a, %o0
a0130370:  98 02 00 12  add  %o0, %l2, %o4
a0130374:  c2 0b 20 02  ldub  [ %o4 + 2 ], %g1
a0130378:  9e 18 60 01  xor  %g1, 1, %o7
a013037c:  80 a0 00 0f  cmp  %g0, %o7
a0130380:  94 60 3f ff  subx  %g0, -1, %o2
a0130384:  80 8a 80 0b  btst  %o2, %o3
a0130388:  02 80 00 03  be  0xa0130394
a013038c:  96 10 20 02  mov  2, %o3
a0130390:  d6 2b 20 02  stb  %o3, [ %o4 + 2 ]
a0130394:  40 00 46 53  call  0xa0141ce0
a0130398:  d0 0b 20 0a  ldub  [ %o4 + 0xa ], %o0
a013039c:  9a 0a 20 ff  and  %o0, 0xff, %o5
a01303a0:  80 a3 60 01  cmp  %o5, 1
a01303a4:  02 80 00 19  be  0xa0130408
a01303a8:  80 a6 60 00  cmp  %i1, 0
a01303ac:  93 2e 20 04  sll  %i0, 4, %o1
a01303b0:  98 22 40 18  sub  %o1, %i0, %o4
a01303b4:  a2 14 e3 30  or  %l3, 0x330, %l1
a01303b8:  a1 2b 20 03  sll  %o4, 3, %l0
a01303bc:  d0 04 40 10  ld  [ %l1 + %l0 ], %o0
a01303c0:  a7 32 20 04  srl  %o0, 4, %l3
a01303c4:  90 0c e0 0f  and  %l3, 0xf, %o0
a01303c8:  80 a2 20 04  cmp  %o0, 4
a01303cc:  02 80 00 05  be  0xa01303e0
a01303d0:  80 a6 60 00  cmp  %i1, 0
a01303d4:  7f ff 18 ff  call  0xa00f67d0
a01303d8:  01 00 00 00  nop
a01303dc:  80 a6 60 00  cmp  %i1, 0
a01303e0:  12 80 00 05  bne  0xa01303f4
a01303e4:  25 3c 00 00  sethi  %hi(0xf0000000), %l2
a01303e8:  d6 04 40 10  ld  [ %l1 + %l0 ], %o3
a01303ec:  b2 2a c0 12  andn  %o3, %l2, %i1
a01303f0:  f2 24 40 10  st  %i1, [ %l1 + %l0 ]
a01303f4:  40 00 32 6d  call  0xa013cda8
a01303f8:  90 10 00 18  mov  %i0, %o0
a01303fc:  b0 0a 20 ff  and  %o0, 0xff, %i0
a0130400:  7f ff 64 1d  call  0xa0109474
a0130404:  93 e8 20 00  restore  %g0, 0, %o1
a0130408:  22 bf ff ea  be,a   0xa01303b0
a013040c:  93 2e 20 04  sll  %i0, 4, %o1
a0130410:  c2 04 40 10  ld  [ %l1 + %l0 ], %g1
a0130414:  9f 30 60 0c  srl  %g1, 0xc, %o7
a0130418:  94 0b e0 0f  and  %o7, 0xf, %o2
a013041c:  a0 5a a0 2a  smul  %o2, 0x2a, %l0
a0130420:  a2 04 00 12  add  %l0, %l2, %l1
a0130424:  d0 0c 60 0a  ldub  [ %l1 + 0xa ], %o0
a0130428:  40 00 46 4a  call  0xa0141d50
a013042c:  92 10 20 02  mov  2, %o1
a0130430:  10 bf ff e0  b  0xa01303b0
a0130434:  93 2e 20 04  sll  %i0, 4, %o1
