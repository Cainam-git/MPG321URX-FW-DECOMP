# leon2m FUN_a0144350 0xa0144350-0xa0144414 (196 bytes)
a0144350:  9d e3 bf 98  save  %sp, -104, %sp
a0144354:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0144358:  80 a6 20 01  cmp  %i0, 1
a014435c:  02 80 00 0b  be  0xa0144388
a0144360:  98 10 20 01  mov  1, %o4
a0144364:  80 a6 20 01  cmp  %i0, 1
a0144368:  04 80 00 24  ble  0xa01443f8
a014436c:  80 a6 20 02  cmp  %i0, 2
a0144370:  02 80 00 06  be  0xa0144388
a0144374:  98 10 20 02  mov  2, %o4
a0144378:  80 a6 20 03  cmp  %i0, 3
a014437c:  02 80 00 03  be  0xa0144388
a0144380:  98 10 20 03  mov  3, %o4
a0144384:  98 10 3f ff  mov  -1, %o4
a0144388:  82 0b 20 ff  and  %o4, 0xff, %g1
a014438c:  80 a0 60 03  cmp  %g1, 3
a0144390:  18 80 00 16  bgu  0xa01443e8
a0144394:  11 00 06 9b  sethi  %hi(0x1a6c00), %o0
a0144398:  9b 28 60 04  sll  %g1, 4, %o5
a014439c:  96 23 40 01  sub  %o5, %g1, %o3
a01443a0:  15 2a 00 b7  sethi  %hi(0xa802dc00), %o2
a01443a4:  99 2a e0 03  sll  %o3, 3, %o4
a01443a8:  92 12 a3 30  or  %o2, 0x330, %o1
a01443ac:  c2 02 40 0c  ld  [ %o1 + %o4 ], %g1
a01443b0:  91 30 60 0c  srl  %g1, 0xc, %o0
a01443b4:  b0 0a 20 0f  and  %o0, 0xf, %i0
a01443b8:  1f 2a 00 b8  sethi  %hi(0xa802e000), %o7
a01443bc:  96 5e 20 2a  smul  %i0, 0x2a, %o3
a01443c0:  9a 13 e2 24  or  %o7, 0x224, %o5
a01443c4:  94 02 c0 0d  add  %o3, %o5, %o2
a01443c8:  d2 0a a0 09  ldub  [ %o2 + 9 ], %o1
a01443cc:  82 02 7f fe  add  %o1, -2, %g1
a01443d0:  98 08 60 ff  and  %g1, 0xff, %o4
a01443d4:  80 a3 20 02  cmp  %o4, 2
a01443d8:  08 80 00 0d  bleu  0xa014440c
a01443dc:  b0 10 20 01  mov  1, %i0
a01443e0:  10 80 00 0b  b  0xa014440c
a01443e4:  b0 10 20 00  clr  %i0
a01443e8:  7f fe 6b 62  call  0xa00df170
a01443ec:  90 12 21 d8  or  %o0, 0x1d8, %o0
a01443f0:  10 bf ff ea  b  0xa0144398
a01443f4:  82 10 20 00  clr  %g1
a01443f8:  80 a6 20 00  cmp  %i0, 0
a01443fc:  02 bf ff e3  be  0xa0144388
a0144400:  98 10 20 00  clr  %o4
a0144404:  10 bf ff e1  b  0xa0144388
a0144408:  98 10 3f ff  mov  -1, %o4
a014440c:  81 c7 e0 08  ret
a0144410:  81 e8 00 00  restore
