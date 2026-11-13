# leon2m FUN_a0142418 0xa0142418-0xa0142518 (256 bytes)
a0142418:  9d e3 bf 98  save  %sp, -104, %sp
a014241c:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0142420:  7f ff ea 7c  call  0xa013ce10
a0142424:  90 10 00 18  mov  %i0, %o0
a0142428:  b4 10 00 08  mov  %o0, %i2
a014242c:  80 a6 20 00  cmp  %i0, 0
a0142430:  02 80 00 0b  be  0xa014245c
a0142434:  90 10 20 03  mov  3, %o0
a0142438:  80 a6 20 01  cmp  %i0, 1
a014243c:  12 80 00 0a  bne  0xa0142464
a0142440:  b0 0a 20 03  and  %o0, 3, %i0
a0142444:  90 10 20 01  mov  1, %o0
a0142448:  b0 0a 20 03  and  %o0, 3, %i0
a014244c:  80 a6 20 03  cmp  %i0, 3
a0142450:  32 80 00 09  bne,a   0xa0142474
a0142454:  c2 06 80 00  ld  [ %i2 ], %g1
a0142458:  30 80 00 2e  b,a   0xa0142510
a014245c:  90 10 20 00  clr  %o0
a0142460:  b0 0a 20 03  and  %o0, 3, %i0
a0142464:  80 a6 20 03  cmp  %i0, 3
a0142468:  02 80 00 2a  be  0xa0142510
a014246c:  01 00 00 00  nop
a0142470:  c2 06 80 00  ld  [ %i2 ], %g1
a0142474:  91 30 60 0c  srl  %g1, 0xc, %o0
a0142478:  7f ff 09 ef  call  0xa0104c34
a014247c:  90 0a 20 0f  and  %o0, 0xf, %o0
a0142480:  80 8a 20 ff  btst  0xff, %o0
a0142484:  02 80 00 1f  be  0xa0142500
a0142488:  01 00 00 00  nop
a014248c:  80 a6 60 00  cmp  %i1, 0
a0142490:  12 80 00 07  bne  0xa01424ac
a0142494:  19 00 06 9b  sethi  %hi(0x1a6c00), %o4
a0142498:  d2 06 80 00  ld  [ %i2 ], %o1
a014249c:  b3 32 60 0c  srl  %o1, 0xc, %i1
a01424a0:  b2 0e 60 0f  and  %i1, 0xf, %i1
a01424a4:  7f ff 73 49  call  0xa011f1c8
a01424a8:  95 e8 20 00  restore  %g0, 0, %o2
a01424ac:  a2 13 20 b4  or  %o4, 0xb4, %l1
a01424b0:  a1 2e 60 04  sll  %i1, 4, %l0
a01424b4:  d2 04 40 10  ld  [ %l1 + %l0 ], %o1
a01424b8:  7f ff 73 ab  call  0xa011f364
a01424bc:  90 10 00 18  mov  %i0, %o0
a01424c0:  a0 04 00 11  add  %l0, %l1, %l0
a01424c4:  d4 04 20 08  ld  [ %l0 + 8 ], %o2
a01424c8:  90 10 00 18  mov  %i0, %o0
a01424cc:  7f ff 74 76  call  0xa011f6a4
a01424d0:  d2 04 20 04  ld  [ %l0 + 4 ], %o1
a01424d4:  90 10 00 18  mov  %i0, %o0
a01424d8:  7f ff 75 c0  call  0xa011fbd8
a01424dc:  d2 14 20 0c  lduh  [ %l0 + 0xc ], %o1
a01424e0:  90 10 00 18  mov  %i0, %o0
a01424e4:  7f ff 75 f2  call  0xa011fcac
a01424e8:  d2 0c 20 0e  ldub  [ %l0 + 0xe ], %o1
a01424ec:  d6 06 80 00  ld  [ %i2 ], %o3
a01424f0:  95 32 e0 0c  srl  %o3, 0xc, %o2
a01424f4:  b2 0a a0 0f  and  %o2, 0xf, %i1
a01424f8:  7f ff 73 34  call  0xa011f1c8
a01424fc:  95 e8 20 01  restore  %g0, 1, %o2
a0142500:  67 fd 2f 69  call  0x4008e2a4
a0142504:  01 00 00 00  nop
a0142508:  10 bf ff e2  b  0xa0142490
a014250c:  80 a6 60 00  cmp  %i1, 0
a0142510:  81 c7 e0 08  ret
a0142514:  81 e8 00 00  restore
