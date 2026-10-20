# leon2m FUN_a00f7434 0xa00f7434-0xa00f7534 (256 bytes)
a00f7434:  9d e3 bf 98  save  %sp, -104, %sp
a00f7438:  1f 33 c0 3b  sethi  %hi(0xcf00ec00), %o7
a00f743c:  a2 13 e2 80  or  %o7, 0x280, %l1	! 0xcf00ee80
a00f7440:  2b 2a 00 ad  sethi  %hi(0xa802b400), %l5
a00f7444:  da 04 40 00  ld  [ %l1 ], %o5
a00f7448:  d6 0d 63 b4  ldub  [ %l5 + 0x3b4 ], %o3
a00f744c:  a8 02 c0 0b  add  %o3, %o3, %l4
a00f7450:  a6 0b 60 f9  and  %o5, 0xf9, %l3
a00f7454:  a4 14 c0 14  or  %l3, %l4, %l2
a00f7458:  e4 24 40 00  st  %l2, [ %l1 ]
a00f745c:  98 13 e2 c0  or  %o7, 0x2c0, %o4
a00f7460:  e0 03 00 00  ld  [ %o4 ], %l0
a00f7464:  94 0c 3f df  and  %l0, -33, %o2
a00f7468:  d4 23 00 00  st  %o2, [ %o4 ]
a00f746c:  96 13 e2 c4  or  %o7, 0x2c4, %o3
a00f7470:  d2 02 c0 00  ld  [ %o3 ], %o1
a00f7474:  90 0a 60 0f  and  %o1, 0xf, %o0
a00f7478:  a8 12 20 50  or  %o0, 0x50, %l4
a00f747c:  82 0d 20 ff  and  %l4, 0xff, %g1
a00f7480:  1b 00 06 68  sethi  %hi(0x19a000), %o5
a00f7484:  c2 22 c0 00  st  %g1, [ %o3 ]
a00f7488:  80 a6 20 00  cmp  %i0, 0
a00f748c:  02 80 00 03  be  0xa00f7498
a00f7490:  a2 13 63 78  or  %o5, 0x378, %l1
a00f7494:  a2 10 00 18  mov  %i0, %l1
a00f7498:  27 33 c0 3b  sethi  %hi(0xcf00ec00), %l3
a00f749c:  b0 10 20 00  clr  %i0
a00f74a0:  a0 10 20 00  clr  %l0
a00f74a4:  a4 14 e2 c8  or  %l3, 0x2c8, %l2
a00f74a8:  98 04 00 10  add  %l0, %l0, %o4
a00f74ac:  a0 03 00 11  add  %o4, %l1, %l0
a00f74b0:  de 0c 20 03  ldub  [ %l0 + 3 ], %o7
a00f74b4:  de 24 80 00  st  %o7, [ %l2 ]
a00f74b8:  7f ff ee 6f  call  0xa00f2e74
a00f74bc:  01 00 00 00  nop
a00f74c0:  d2 14 20 02  lduh  [ %l0 + 2 ], %o1
a00f74c4:  91 32 60 08  srl  %o1, 8, %o0
a00f74c8:  d0 24 80 00  st  %o0, [ %l2 ]
a00f74cc:  7f ff ee 6a  call  0xa00f2e74
a00f74d0:  b0 06 20 01  inc  %i0
a00f74d4:  c2 0c 40 00  ldub  [ %l1 ], %g1
a00f74d8:  a0 0e 20 ff  and  %i0, 0xff, %l0
a00f74dc:  80 a0 40 10  cmp  %g1, %l0
a00f74e0:  1a bf ff f3  bcc  0xa00f74ac
a00f74e4:  98 04 00 10  add  %l0, %l0, %o4
a00f74e8:  a0 15 3f 90  or  %l4, -112, %l0
a00f74ec:  b0 14 e2 c4  or  %l3, 0x2c4, %i0
a00f74f0:  92 0c 20 ff  and  %l0, 0xff, %o1
a00f74f4:  d2 26 00 00  st  %o1, [ %i0 ]
a00f74f8:  67 fe 5b 6b  call  0x4008e2a4
a00f74fc:  a2 14 e2 80  or  %l3, 0x280, %l1
a00f7500:  d0 0d 63 b4  ldub  [ %l5 + 0x3b4 ], %o0
a00f7504:  82 02 20 04  add  %o0, 4, %g1
a00f7508:  9a 10 20 01  mov  1, %o5
a00f750c:  e8 04 40 00  ld  [ %l1 ], %l4
a00f7510:  97 2b 40 01  sll  %o5, %g1, %o3
a00f7514:  a6 15 00 0b  or  %l4, %o3, %l3
a00f7518:  a4 0c e0 ff  and  %l3, 0xff, %l2
a00f751c:  e4 24 40 00  st  %l2, [ %l1 ]
a00f7520:  d4 06 00 00  ld  [ %i0 ], %o2
a00f7524:  aa 0a bf 7f  and  %o2, -129, %l5
a00f7528:  ea 26 00 00  st  %l5, [ %i0 ]
a00f752c:  81 c7 e0 08  ret
a00f7530:  81 e8 00 00  restore
