# leon2s FUN_a00802cc 0xa00802cc-0xa0080494 (456 bytes)
a00802cc:  9d e3 bf 98  save  %sp, -104, %sp
a00802d0:  82 0e 20 ff  and  %i0, 0xff, %g1
a00802d4:  80 a0 60 02  cmp  %g1, 2
a00802d8:  02 80 00 05  be  0xa00802ec
a00802dc:  a8 10 20 00  clr  %l4
a00802e0:  80 a0 60 03  cmp  %g1, 3
a00802e4:  12 80 00 6a  bne  0xa008048c
a00802e8:  a8 10 20 01  mov  1, %l4
a00802ec:  ac 0e 60 ff  and  %i1, 0xff, %l6
a00802f0:  80 a5 a0 00  cmp  %l6, 0
a00802f4:  02 80 00 66  be  0xa008048c
a00802f8:  2f 2a 01 f5  sethi  %hi(0xa807d400), %l7
a00802fc:  aa 0d 20 ff  and  %l4, 0xff, %l5
a0080300:  82 15 e2 80  or  %l7, 0x280, %g1
a0080304:  9a 5d 60 b0  smul  %l5, 0xb0, %o5
a0080308:  c2 08 40 0d  ldub  [ %g1 + %o5 ], %g1
a008030c:  80 a0 60 00  cmp  %g1, 0
a0080310:  02 80 00 36  be  0xa00803e8
a0080314:  a6 10 20 00  clr  %l3
a0080318:  a2 0c e0 ff  and  %l3, 0xff, %l1
a008031c:  83 3d 80 11  sra  %l6, %l1, %g1
a0080320:  80 88 60 01  btst  1, %g1
a0080324:  02 80 00 2a  be  0xa00803cc
a0080328:  a6 04 e0 01  inc  %l3
a008032c:  a4 04 40 11  add  %l1, %l1, %l2
a0080330:  90 10 20 00  clr  %o0
a0080334:  92 10 20 10  mov  0x10, %o1
a0080338:  80 a4 60 03  cmp  %l1, 3
a008033c:  18 80 00 24  bgu  0xa00803cc
a0080340:  94 0e 20 ff  and  %i0, 0xff, %o2
a0080344:  03 28 02 ce  sethi  %hi(0xa00b3800), %g1
a0080348:  82 10 63 70  or  %g1, 0x370, %g1	! 0xa00b3b70
a008034c:  e0 10 40 12  lduh  [ %g1 + %l2 ], %l0
a0080350:  40 00 9c 35  call  0xa00a7424
a0080354:  96 10 00 10  mov  %l0, %o3
a0080358:  03 28 02 ce  sethi  %hi(0xa00b3800), %g1
a008035c:  82 10 63 10  or  %g1, 0x310, %g1	! 0xa00b3b10
a0080360:  d6 10 40 12  lduh  [ %g1 + %l2 ], %o3
a0080364:  90 10 20 01  mov  1, %o0
a0080368:  92 10 20 04  mov  4, %o1
a008036c:  40 00 9c 2e  call  0xa00a7424
a0080370:  94 0e 20 ff  and  %i0, 0xff, %o2
a0080374:  90 10 20 00  clr  %o0
a0080378:  92 10 20 00  clr  %o1
a008037c:  94 0e 20 ff  and  %i0, 0xff, %o2
a0080380:  40 00 9c 29  call  0xa00a7424
a0080384:  96 10 00 10  mov  %l0, %o3
a0080388:  96 10 00 10  mov  %l0, %o3
a008038c:  90 10 20 01  mov  1, %o0
a0080390:  92 10 20 11  mov  0x11, %o1
a0080394:  40 00 9c 24  call  0xa00a7424
a0080398:  94 0e 20 ff  and  %i0, 0xff, %o2
a008039c:  da 0e 80 11  ldub  [ %i2 + %l1 ], %o5
a00803a0:  d6 16 c0 12  lduh  [ %i3 + %l2 ], %o3
a00803a4:  03 28 02 ce  sethi  %hi(0xa00b3800), %g1
a00803a8:  9a 0b 60 0f  and  %o5, 0xf, %o5
a00803ac:  97 2a e0 08  sll  %o3, 8, %o3
a00803b0:  82 10 63 18  or  %g1, 0x318, %g1
a00803b4:  15 3f c0 00  sethi  %hi(0xff000000), %o2
a00803b8:  d2 10 40 12  lduh  [ %g1 + %l2 ], %o1
a00803bc:  96 13 40 0b  or  %o5, %o3, %o3
a00803c0:  94 12 a0 f0  or  %o2, 0xf0, %o2
a00803c4:  40 00 9c 31  call  0xa00a7488
a00803c8:  90 0e 20 ff  and  %i0, 0xff, %o0
a00803cc:  82 5d 60 b0  smul  %l5, 0xb0, %g1
a00803d0:  9a 15 e2 80  or  %l7, 0x280, %o5
a00803d4:  da 0b 40 01  ldub  [ %o5 + %g1 ], %o5
a00803d8:  82 0c e0 ff  and  %l3, 0xff, %g1
a00803dc:  80 a0 40 0d  cmp  %g1, %o5
a00803e0:  0a bf ff cf  bcs  0xa008031c
a00803e4:  a2 0c e0 ff  and  %l3, 0xff, %l1
a00803e8:  b2 0e 60 ff  and  %i1, 0xff, %i1
a00803ec:  90 0e 20 ff  and  %i0, 0xff, %o0
a00803f0:  7f ff fd 44  call  0xa007f900
a00803f4:  92 10 00 19  mov  %i1, %o1
a00803f8:  a2 0d 20 ff  and  %l4, 0xff, %l1
a00803fc:  25 2a 01 f5  sethi  %hi(0xa807d400), %l2
a0080400:  82 14 a2 80  or  %l2, 0x280, %g1	! 0xa807d680
a0080404:  9a 5c 60 b0  smul  %l1, 0xb0, %o5
a0080408:  c2 08 40 0d  ldub  [ %g1 + %o5 ], %g1
a008040c:  80 a0 60 00  cmp  %g1, 0
a0080410:  02 80 00 1f  be  0xa008048c
a0080414:  a6 10 20 00  clr  %l3
a0080418:  9a 0c e0 ff  and  %l3, 0xff, %o5
a008041c:  83 3e 40 0d  sra  %i1, %o5, %g1
a0080420:  80 88 60 01  btst  1, %g1
a0080424:  02 80 00 13  be  0xa0080470
a0080428:  a6 04 e0 01  inc  %l3
a008042c:  a0 03 40 0d  add  %o5, %o5, %l0
a0080430:  90 10 20 01  mov  1, %o0
a0080434:  92 10 20 00  clr  %o1
a0080438:  80 a3 60 03  cmp  %o5, 3
a008043c:  18 80 00 0d  bgu  0xa0080470
a0080440:  94 0e 20 ff  and  %i0, 0xff, %o2
a0080444:  03 28 02 ce  sethi  %hi(0xa00b3800), %g1
a0080448:  82 10 63 70  or  %g1, 0x370, %g1	! 0xa00b3b70
a008044c:  40 00 9b f6  call  0xa00a7424
a0080450:  d6 10 40 10  lduh  [ %g1 + %l0 ], %o3
a0080454:  03 28 02 ce  sethi  %hi(0xa00b3800), %g1
a0080458:  82 10 63 10  or  %g1, 0x310, %g1	! 0xa00b3b10
a008045c:  d6 10 40 10  lduh  [ %g1 + %l0 ], %o3
a0080460:  90 10 20 00  clr  %o0
a0080464:  92 10 20 04  mov  4, %o1
a0080468:  40 00 9b ef  call  0xa00a7424
a008046c:  94 0e 20 ff  and  %i0, 0xff, %o2
a0080470:  82 5c 60 b0  smul  %l1, 0xb0, %g1
a0080474:  9a 14 a2 80  or  %l2, 0x280, %o5
a0080478:  da 0b 40 01  ldub  [ %o5 + %g1 ], %o5
a008047c:  82 0c e0 ff  and  %l3, 0xff, %g1
a0080480:  80 a0 40 0d  cmp  %g1, %o5
a0080484:  0a bf ff e6  bcs  0xa008041c
a0080488:  9a 0c e0 ff  and  %l3, 0xff, %o5
a008048c:  81 c7 e0 08  ret
a0080490:  81 e8 00 00  restore
