# leon2m FUN_a00803a4 0xa00803a4-0xa0080490 (236 bytes)
a00803a4:  9d e3 bf 98  save  %sp, -104, %sp
a00803a8:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00803ac:  a2 10 62 90  or  %g1, 0x290, %l1	! 0xa802d290
a00803b0:  b0 10 20 01  mov  1, %i0
a00803b4:  a0 10 20 00  clr  %l0
a00803b8:  10 80 00 11  b  0xa00803fc
a00803bc:  90 10 20 00  clr  %o0
a00803c0:  80 a2 20 01  cmp  %o0, 1
a00803c4:  02 80 00 1d  be  0xa0080438
a00803c8:  80 a2 20 02  cmp  %o0, 2
a00803cc:  02 80 00 21  be  0xa0080450
a00803d0:  80 a2 20 03  cmp  %o0, 3
a00803d4:  22 80 00 27  be,a   0xa0080470
a00803d8:  de 0c 60 1f  ldub  [ %l1 + 0x1f ], %o7
a00803dc:  80 8b 60 ff  btst  0xff, %o5
a00803e0:  12 80 00 0e  bne  0xa0080418
a00803e4:  01 00 00 00  nop
a00803e8:  a0 04 20 01  inc  %l0
a00803ec:  90 0c 20 ff  and  %l0, 0xff, %o0
a00803f0:  80 a2 20 03  cmp  %o0, 3
a00803f4:  38 80 00 25  bgu,a   0xa0080488
a00803f8:  b0 0e 20 01  and  %i0, 1, %i0
a00803fc:  80 a2 20 00  cmp  %o0, 0
a0080400:  12 bf ff f0  bne  0xa00803c0
a0080404:  9a 10 20 00  clr  %o5
a0080408:  9a 10 20 01  mov  1, %o5
a008040c:  80 8b 60 ff  btst  0xff, %o5
a0080410:  22 bf ff f7  be,a   0xa00803ec
a0080414:  a0 04 20 01  inc  %l0
a0080418:  40 03 0d ff  call  0xa0143c14
a008041c:  01 00 00 00  nop
a0080420:  90 0a 20 ff  and  %o0, 0xff, %o0
a0080424:  80 a2 20 04  cmp  %o0, 4
a0080428:  28 bf ff f1  bleu,a   0xa00803ec
a008042c:  a0 04 20 01  inc  %l0
a0080430:  10 80 00 15  b  0xa0080484
a0080434:  b0 10 20 00  clr  %i0
a0080438:  d2 0c 60 1f  ldub  [ %l1 + 0x1f ], %o1
a008043c:  80 a2 60 00  cmp  %o1, 0
a0080440:  02 bf ff e8  be  0xa00803e0
a0080444:  80 8b 60 ff  btst  0xff, %o5
a0080448:  10 bf ff f1  b  0xa008040c
a008044c:  9a 10 20 01  mov  1, %o5
a0080450:  d8 0c 60 1f  ldub  [ %l1 + 0x1f ], %o4
a0080454:  96 03 3f fc  add  %o4, -4, %o3
a0080458:  94 0a e0 ff  and  %o3, 0xff, %o2
a008045c:  80 a2 a0 03  cmp  %o2, 3
a0080460:  18 bf ff e0  bgu  0xa00803e0
a0080464:  80 8b 60 ff  btst  0xff, %o5
a0080468:  10 bf ff e9  b  0xa008040c
a008046c:  9a 10 20 01  mov  1, %o5
a0080470:  80 a3 e0 07  cmp  %o7, 7
a0080474:  12 bf ff db  bne  0xa00803e0
a0080478:  80 8b 60 ff  btst  0xff, %o5
a008047c:  10 bf ff e4  b  0xa008040c
a0080480:  9a 10 20 01  mov  1, %o5
a0080484:  b0 0e 20 01  and  %i0, 1, %i0
a0080488:  81 c7 e0 08  ret
a008048c:  81 e8 00 00  restore
