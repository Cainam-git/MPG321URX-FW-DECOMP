# leon2m FUN_a014737c 0xa014737c-0xa01474b0 (308 bytes)
a014737c:  9d e3 bf 88  save  %sp, -120, %sp
a0147380:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0147384:  80 a6 20 01  cmp  %i0, 1
a0147388:  02 80 00 0b  be  0xa01473b4
a014738c:  82 10 20 01  mov  1, %g1
a0147390:  80 a6 20 01  cmp  %i0, 1
a0147394:  04 80 00 3b  ble  0xa0147480
a0147398:  80 a6 20 02  cmp  %i0, 2
a014739c:  02 80 00 06  be  0xa01473b4
a01473a0:  82 10 20 02  mov  2, %g1
a01473a4:  80 a6 20 03  cmp  %i0, 3
a01473a8:  02 80 00 03  be  0xa01473b4
a01473ac:  82 10 20 03  mov  3, %g1
a01473b0:  82 10 3f ff  mov  -1, %g1
a01473b4:  b0 08 60 ff  and  %g1, 0xff, %i0
a01473b8:  80 a6 20 03  cmp  %i0, 3
a01473bc:  18 80 00 2d  bgu  0xa0147470
a01473c0:  11 00 06 9b  sethi  %hi(0x1a6c00), %o0
a01473c4:  9f 2e 20 04  sll  %i0, 4, %o7
a01473c8:  96 23 c0 18  sub  %o7, %i0, %o3
a01473cc:  25 2a 00 b7  sethi  %hi(0xa802dc00), %l2
a01473d0:  95 2a e0 03  sll  %o3, 3, %o2
a01473d4:  98 14 a3 30  or  %l2, 0x330, %o4
a01473d8:  d2 03 00 0a  ld  [ %o4 + %o2 ], %o1
a01473dc:  83 32 60 04  srl  %o1, 4, %g1
a01473e0:  9a 08 60 0f  and  %g1, 0xf, %o5
a01473e4:  80 a3 60 04  cmp  %o5, 4
a01473e8:  02 80 00 30  be  0xa01474a8
a01473ec:  b2 0e 60 ff  and  %i1, 0xff, %i1
a01473f0:  80 a6 60 01  cmp  %i1, 1
a01473f4:  02 80 00 08  be  0xa0147414
a01473f8:  a2 10 20 08  mov  8, %l1
a01473fc:  80 a6 60 01  cmp  %i1, 1
a0147400:  04 80 00 25  ble  0xa0147494
a0147404:  80 a6 60 03  cmp  %i1, 3
a0147408:  02 80 00 03  be  0xa0147414
a014740c:  a2 10 20 20  mov  0x20, %l1
a0147410:  a2 10 20 10  mov  0x10, %l1
a0147414:  7f fe be 38  call  0xa00f6cf4
a0147418:  01 00 00 00  nop
a014741c:  93 2e 20 04  sll  %i0, 4, %o1
a0147420:  82 22 40 18  sub  %o1, %i0, %g1
a0147424:  a0 10 00 08  mov  %o0, %l0
a0147428:  91 28 60 03  sll  %g1, 3, %o0
a014742c:  9a 14 a3 30  or  %l2, 0x330, %o5
a0147430:  f2 03 40 08  ld  [ %o5 + %o0 ], %i1
a0147434:  b1 36 60 04  srl  %i1, 4, %i0
a0147438:  e2 2f bf f2  stb  %l1, [ %fp + -14 ]
a014743c:  90 0e 20 0f  and  %i0, 0xf, %o0
a0147440:  f6 2f bf f1  stb  %i3, [ %fp + -15 ]
a0147444:  7f fe bb de  call  0xa00f63bc
a0147448:  f4 2f bf f0  stb  %i2, [ %fp + -16 ]
a014744c:  e4 17 bf f0  lduh  [ %fp + -16 ], %l2
a0147450:  e2 0f bf f2  ldub  [ %fp + -14 ], %l1
a0147454:  90 07 bf e8  add  %fp, -24, %o0
a0147458:  e4 37 bf e8  sth  %l2, [ %fp + -24 ]
a014745c:  7f fe c1 0e  call  0xa00f7894
a0147460:  e2 2f bf ea  stb  %l1, [ %fp + -22 ]
a0147464:  7f fe bb d6  call  0xa00f63bc
a0147468:  90 0c 20 ff  and  %l0, 0xff, %o0
a014746c:  30 80 00 0f  b,a   0xa01474a8
a0147470:  7f fe 5f 40  call  0xa00df170
a0147474:  90 12 21 d8  or  %o0, 0x1d8, %o0
a0147478:  10 bf ff d3  b  0xa01473c4
a014747c:  b0 10 20 00  clr  %i0
a0147480:  80 a6 20 00  cmp  %i0, 0
a0147484:  02 bf ff cc  be  0xa01473b4
a0147488:  82 10 20 00  clr  %g1
a014748c:  10 bf ff ca  b  0xa01473b4
a0147490:  82 10 3f ff  mov  -1, %g1
a0147494:  80 a6 60 00  cmp  %i1, 0
a0147498:  02 bf ff df  be  0xa0147414
a014749c:  a2 10 20 04  mov  4, %l1
a01474a0:  10 bf ff dd  b  0xa0147414
a01474a4:  a2 10 20 10  mov  0x10, %l1
a01474a8:  81 c7 e0 08  ret
a01474ac:  81 e8 00 00  restore
