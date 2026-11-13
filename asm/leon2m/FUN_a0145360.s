# leon2m FUN_a0145360 0xa0145360-0xa01454c4 (356 bytes)
a0145360:  9d e3 bf 98  save  %sp, -104, %sp
a0145364:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0145368:  80 a6 20 01  cmp  %i0, 1
a014536c:  02 80 00 0c  be  0xa014539c
a0145370:  23 2a 00 b8  sethi  %hi(0xa802e000), %l1
a0145374:  04 80 00 42  ble  0xa014547c
a0145378:  80 a6 20 02  cmp  %i0, 2
a014537c:  02 80 00 0b  be  0xa01453a8
a0145380:  80 a6 20 03  cmp  %i0, 3
a0145384:  02 80 00 4e  be  0xa01454bc
a0145388:  21 2a 00 b8  sethi  %hi(0xa802e000), %l0
a014538c:  90 14 21 f0  or  %l0, 0x1f0, %o0	! 0xa802e1f0
a0145390:  40 00 39 81  call  0xa0153994
a0145394:  92 10 20 00  clr  %o1
a0145398:  23 2a 00 b8  sethi  %hi(0xa802e000), %l1
a014539c:  b0 14 61 a0  or  %l1, 0x1a0, %i0	! 0xa802e1a0
a01453a0:  40 00 39 74  call  0xa0153970
a01453a4:  93 e8 20 00  restore  %g0, 0, %o1
a01453a8:  19 2a 00 b8  sethi  %hi(0xa802e000), %o4
a01453ac:  1b 2a 00 b7  sethi  %hi(0xa802dc00), %o5
a01453b0:  a0 13 22 24  or  %o4, 0x224, %l0
a01453b4:  a2 13 63 30  or  %o5, 0x330, %l1
a01453b8:  b0 10 20 00  clr  %i0
a01453bc:  10 80 00 06  b  0xa01453d4
a01453c0:  b2 10 20 00  clr  %i1
a01453c4:  b2 0e 20 ff  and  %i0, 0xff, %i1
a01453c8:  80 a6 60 03  cmp  %i1, 3
a01453cc:  18 80 00 3c  bgu  0xa01454bc
a01453d0:  01 00 00 00  nop
a01453d4:  7f ff de a6  call  0xa013ce6c
a01453d8:  90 10 00 19  mov  %i1, %o0
a01453dc:  9e 0a 20 ff  and  %o0, 0xff, %o7
a01453e0:  80 a3 e0 0c  cmp  %o7, 0xc
a01453e4:  32 bf ff f8  bne,a   0xa01453c4
a01453e8:  b0 06 20 01  inc  %i0
a01453ec:  80 a6 60 01  cmp  %i1, 1
a01453f0:  02 80 00 0b  be  0xa014541c
a01453f4:  82 10 20 01  mov  1, %g1
a01453f8:  80 a6 60 01  cmp  %i1, 1
a01453fc:  04 80 00 2b  ble  0xa01454a8
a0145400:  80 a6 60 02  cmp  %i1, 2
a0145404:  02 80 00 06  be  0xa014541c
a0145408:  82 10 20 02  mov  2, %g1
a014540c:  80 a6 60 03  cmp  %i1, 3
a0145410:  02 80 00 03  be  0xa014541c
a0145414:  82 10 20 03  mov  3, %g1
a0145418:  82 10 3f ff  mov  -1, %g1
a014541c:  9a 08 60 ff  and  %g1, 0xff, %o5
a0145420:  80 a3 60 03  cmp  %o5, 3
a0145424:  18 80 00 1d  bgu  0xa0145498
a0145428:  11 00 06 9b  sethi  %hi(0x1a6c00), %o0
a014542c:  83 2b 60 04  sll  %o5, 4, %g1
a0145430:  90 20 40 0d  sub  %g1, %o5, %o0
a0145434:  9f 2a 20 03  sll  %o0, 3, %o7
a0145438:  d8 04 40 0f  ld  [ %l1 + %o7 ], %o4
a014543c:  9b 33 20 0c  srl  %o4, 0xc, %o5
a0145440:  96 0b 60 0f  and  %o5, 0xf, %o3
a0145444:  94 5a e0 2a  smul  %o3, 0x2a, %o2
a0145448:  92 02 80 10  add  %o2, %l0, %o1
a014544c:  c2 0a 60 09  ldub  [ %o1 + 9 ], %g1
a0145450:  80 a0 60 05  cmp  %g1, 5
a0145454:  22 bf ff dc  be,a   0xa01453c4
a0145458:  b0 06 20 01  inc  %i0
a014545c:  97 2e 60 04  sll  %i1, 4, %o3
a0145460:  94 22 c0 19  sub  %o3, %i1, %o2
a0145464:  13 2a 00 b7  sethi  %hi(0xa802dc00), %o1
a0145468:  83 2a a0 03  sll  %o2, 3, %g1
a014546c:  90 12 63 36  or  %o1, 0x336, %o0
a0145470:  40 00 3b 95  call  0xa01542c4
a0145474:  90 00 40 08  add  %g1, %o0, %o0
a0145478:  30 80 00 11  b,a   0xa01454bc
a014547c:  80 a6 20 00  cmp  %i0, 0
a0145480:  32 bf ff c3  bne,a   0xa014538c
a0145484:  21 2a 00 b8  sethi  %hi(0xa802e000), %l0
a0145488:  31 2a 00 b8  sethi  %hi(0xa802e000), %i0
a014548c:  b0 16 21 f0  or  %i0, 0x1f0, %i0	! 0xa802e1f0
a0145490:  40 00 39 41  call  0xa0153994
a0145494:  93 e8 20 00  restore  %g0, 0, %o1
a0145498:  7f fe 67 36  call  0xa00df170
a014549c:  90 12 21 d8  or  %o0, 0x1d8, %o0
a01454a0:  10 bf ff e3  b  0xa014542c
a01454a4:  9a 10 20 00  clr  %o5
a01454a8:  80 a6 60 00  cmp  %i1, 0
a01454ac:  02 bf ff dc  be  0xa014541c
a01454b0:  82 10 20 00  clr  %g1
a01454b4:  10 bf ff da  b  0xa014541c
a01454b8:  82 10 3f ff  mov  -1, %g1
a01454bc:  81 c7 e0 08  ret
a01454c0:  81 e8 00 00  restore
