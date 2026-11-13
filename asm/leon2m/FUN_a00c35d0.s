# leon2m FUN_a00c35d0 0xa00c35d0-0xa00c3820 (592 bytes)
a00c35d0:  9d e3 bf 98  save  %sp, -104, %sp
a00c35d4:  a0 0e 20 ff  and  %i0, 0xff, %l0
a00c35d8:  80 a4 20 02  cmp  %l0, 2
a00c35dc:  02 80 00 55  be  0xa00c3730
a00c35e0:  80 a4 20 03  cmp  %l0, 3
a00c35e4:  02 80 00 70  be  0xa00c37a4
a00c35e8:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00c35ec:  c2 0a 60 d9  ldub  [ %o1 + 0xd9 ], %g1	! 0xa802d0d9
a00c35f0:  94 08 60 ff  and  %g1, 0xff, %o2
a00c35f4:  96 02 bf d0  add  %o2, -48, %o3
a00c35f8:  9a 0a e0 ff  and  %o3, 0xff, %o5
a00c35fc:  80 a3 60 0c  cmp  %o5, 0xc
a00c3600:  18 80 00 86  bgu  0xa00c3818
a00c3604:  b0 10 20 ff  mov  0xff, %i0
a00c3608:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00c360c:  03 2a 00 b3  sethi  %hi(0xa802cc00), %g1
a00c3610:  b0 12 22 90  or  %o0, 0x290, %i0
a00c3614:  d8 10 63 f8  lduh  [ %g1 + 0x3f8 ], %o4
a00c3618:  1f 00 00 18  sethi  %hi(0x6000), %o7
a00c361c:  80 8b c0 0c  btst  %o7, %o4
a00c3620:  02 80 00 47  be  0xa00c373c
a00c3624:  d6 2e 21 90  stb  %o3, [ %i0 + 0x190 ]
a00c3628:  80 a4 20 02  cmp  %l0, 2
a00c362c:  02 80 00 24  be  0xa00c36bc
a00c3630:  80 a4 20 03  cmp  %l0, 3
a00c3634:  02 80 00 5f  be  0xa00c37b0
a00c3638:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00c363c:  94 13 20 78  or  %o4, 0x78, %o2	! 0xa802d078
a00c3640:  96 10 20 30  mov  0x30, %o3
a00c3644:  9e 10 20 35  mov  0x35, %o7
a00c3648:  b0 10 20 36  mov  0x36, %i0
a00c364c:  9a 10 20 2b  mov  0x2b, %o5
a00c3650:  92 10 20 0d  mov  0xd, %o1
a00c3654:  de 2b 20 78  stb  %o7, [ %o4 + 0x78 ]
a00c3658:  f0 2a a0 01  stb  %i0, [ %o2 + 1 ]
a00c365c:  d6 2a a0 03  stb  %o3, [ %o2 + 3 ]
a00c3660:  da 2a a0 04  stb  %o5, [ %o2 + 4 ]
a00c3664:  d2 2a a0 05  stb  %o1, [ %o2 + 5 ]
a00c3668:  80 a4 20 02  cmp  %l0, 2
a00c366c:  02 80 00 21  be  0xa00c36f0
a00c3670:  d6 2a a0 02  stb  %o3, [ %o2 + 2 ]
a00c3674:  80 a4 20 03  cmp  %l0, 3
a00c3678:  02 80 00 5b  be  0xa00c37e4
a00c367c:  19 2a 00 ac  sethi  %hi(0xa802b000), %o4
a00c3680:  31 2a 00 b4  sethi  %hi(0xa802d000), %i0
a00c3684:  9a 16 20 d0  or  %i0, 0xd0, %o5	! 0xa802d0d0
a00c3688:  c0 2b 20 9c  clrb  [ %o4 + 0x9c ]
a00c368c:  c0 2e 20 d0  clrb  [ %i0 + 0xd0 ]
a00c3690:  c0 2b 60 19  clrb  [ %o5 + 0x19 ]
a00c3694:  c0 2b 60 01  clrb  [ %o5 + 1 ]
a00c3698:  c0 2b 60 07  clrb  [ %o5 + 7 ]
a00c369c:  80 a4 20 02  cmp  %l0, 2
a00c36a0:  02 80 00 1d  be  0xa00c3714
a00c36a4:  c0 2b 60 0a  clrb  [ %o5 + 0xa ]
a00c36a8:  80 a4 20 03  cmp  %l0, 3
a00c36ac:  12 80 00 1d  bne  0xa00c3720
a00c36b0:  90 10 00 10  mov  %l0, %o0
a00c36b4:  10 80 00 56  b  0xa00c380c
a00c36b8:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00c36bc:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00c36c0:  a0 12 61 28  or  %o1, 0x128, %l0	! 0xa802d128
a00c36c4:  9e 10 20 30  mov  0x30, %o7
a00c36c8:  9a 10 20 35  mov  0x35, %o5
a00c36cc:  96 10 20 0d  mov  0xd, %o3
a00c36d0:  90 10 20 36  mov  0x36, %o0
a00c36d4:  82 10 20 2b  mov  0x2b, %g1
a00c36d8:  da 2a 61 28  stb  %o5, [ %o1 + 0x128 ]
a00c36dc:  d6 2c 20 05  stb  %o3, [ %l0 + 5 ]
a00c36e0:  d0 2c 20 01  stb  %o0, [ %l0 + 1 ]
a00c36e4:  de 2c 20 03  stb  %o7, [ %l0 + 3 ]
a00c36e8:  c2 2c 20 04  stb  %g1, [ %l0 + 4 ]
a00c36ec:  de 2c 20 02  stb  %o7, [ %l0 + 2 ]
a00c36f0:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a00c36f4:  94 14 20 40  or  %l0, 0x40, %o2	! 0xa802d040
a00c36f8:  11 2a 00 ac  sethi  %hi(0xa802b000), %o0
a00c36fc:  c0 2a 20 9a  clrb  [ %o0 + 0x9a ]	! 0xa802b09a
a00c3700:  c0 2c 20 40  clrb  [ %l0 + 0x40 ]
a00c3704:  c0 2a a0 19  clrb  [ %o2 + 0x19 ]
a00c3708:  c0 2a a0 01  clrb  [ %o2 + 1 ]
a00c370c:  c0 2a a0 07  clrb  [ %o2 + 7 ]
a00c3710:  c0 2a a0 0a  clrb  [ %o2 + 0xa ]
a00c3714:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a00c3718:  94 13 e1 28  or  %o7, 0x128, %o2	! 0xa802d128
a00c371c:  90 10 20 02  mov  2, %o0
a00c3720:  40 02 14 32  call  0xa01487e8
a00c3724:  92 10 20 06  mov  6, %o1
a00c3728:  10 80 00 3c  b  0xa00c3818
a00c372c:  b0 10 20 00  clr  %i0
a00c3730:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00c3734:  10 bf ff af  b  0xa00c35f0
a00c3738:  c2 08 60 49  ldub  [ %g1 + 0x49 ], %g1	! 0xa802d049
a00c373c:  7f ff 36 27  call  0xa0090fd8
a00c3740:  01 00 00 00  nop
a00c3744:  7f ff 36 1a  call  0xa0090fac
a00c3748:  01 00 00 00  nop
a00c374c:  d6 0e 21 90  ldub  [ %i0 + 0x190 ], %o3
a00c3750:  80 a2 e0 00  cmp  %o3, 0
a00c3754:  12 bf ff b6  bne  0xa00c362c
a00c3758:  80 a4 20 02  cmp  %l0, 2
a00c375c:  da 06 20 a8  ld  [ %i0 + 0xa8 ], %o5
a00c3760:  13 00 00 04  sethi  %hi(0x1000), %o1
a00c3764:  80 8b 40 09  btst  %o5, %o1
a00c3768:  12 bf ff b1  bne  0xa00c362c
a00c376c:  80 a4 20 02  cmp  %l0, 2
a00c3770:  d4 0e 21 a0  ldub  [ %i0 + 0x1a0 ], %o2
a00c3774:  80 a2 a0 00  cmp  %o2, 0
a00c3778:  12 bf ff ad  bne  0xa00c362c
a00c377c:  80 a4 20 02  cmp  %l0, 2
a00c3780:  d8 06 20 ac  ld  [ %i0 + 0xac ], %o4
a00c3784:  31 00 10 00  sethi  %hi(0x400000), %i0
a00c3788:  80 8b 00 18  btst  %o4, %i0
a00c378c:  32 bf ff a8  bne,a   0xa00c362c
a00c3790:  80 a4 20 02  cmp  %l0, 2
a00c3794:  7f ff 36 11  call  0xa0090fd8
a00c3798:  01 00 00 00  nop
a00c379c:  10 bf ff a4  b  0xa00c362c
a00c37a0:  80 a4 20 02  cmp  %l0, 2
a00c37a4:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00c37a8:  10 bf ff 92  b  0xa00c35f0
a00c37ac:  c2 0a 20 a1  ldub  [ %o0 + 0xa1 ], %g1	! 0xa802d0a1
a00c37b0:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00c37b4:  b0 12 21 08  or  %o0, 0x108, %i0	! 0xa802d108
a00c37b8:  94 10 20 30  mov  0x30, %o2
a00c37bc:  82 10 20 35  mov  0x35, %g1
a00c37c0:  9e 10 20 0d  mov  0xd, %o7
a00c37c4:  a0 10 20 36  mov  0x36, %l0
a00c37c8:  98 10 20 2b  mov  0x2b, %o4
a00c37cc:  c2 2a 21 08  stb  %g1, [ %o0 + 0x108 ]
a00c37d0:  de 2e 20 05  stb  %o7, [ %i0 + 5 ]
a00c37d4:  e0 2e 20 01  stb  %l0, [ %i0 + 1 ]
a00c37d8:  d4 2e 20 03  stb  %o2, [ %i0 + 3 ]
a00c37dc:  d8 2e 20 04  stb  %o4, [ %i0 + 4 ]
a00c37e0:  d4 2e 20 02  stb  %o2, [ %i0 + 2 ]
a00c37e4:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00c37e8:  96 12 60 98  or  %o1, 0x98, %o3	! 0xa802d098
a00c37ec:  03 2a 00 ac  sethi  %hi(0xa802b000), %g1
a00c37f0:  c0 28 60 98  clrb  [ %g1 + 0x98 ]	! 0xa802b098
a00c37f4:  c0 2a 60 98  clrb  [ %o1 + 0x98 ]
a00c37f8:  c0 2a e0 19  clrb  [ %o3 + 0x19 ]
a00c37fc:  c0 2a e0 01  clrb  [ %o3 + 1 ]
a00c3800:  c0 2a e0 07  clrb  [ %o3 + 7 ]
a00c3804:  c0 2a e0 0a  clrb  [ %o3 + 0xa ]
a00c3808:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00c380c:  94 12 a1 08  or  %o2, 0x108, %o2	! 0xa802d108
a00c3810:  10 bf ff c4  b  0xa00c3720
a00c3814:  90 10 20 03  mov  3, %o0
a00c3818:  81 c7 e0 08  ret
a00c381c:  81 e8 00 00  restore
