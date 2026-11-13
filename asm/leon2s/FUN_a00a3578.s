# leon2s FUN_a00a3578 0xa00a3578-0xa00a3788 (528 bytes)
a00a3578:  9d e3 bf 98  save  %sp, -104, %sp
a00a357c:  92 0e 60 ff  and  %i1, 0xff, %o1
a00a3580:  80 a2 60 02  cmp  %o1, 2
a00a3584:  12 80 00 1e  bne  0xa00a35fc
a00a3588:  80 a2 60 01  cmp  %o1, 1
a00a358c:  11 28 01 ae  sethi  %hi(0xa006b800), %o0
a00a3590:  7f ff 3f cd  call  0xa00734c4
a00a3594:  90 12 22 08  or  %o0, 0x208, %o0	! 0xa006ba08
a00a3598:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00a359c:  96 10 20 10  mov  0x10, %o3
a00a35a0:  98 10 20 01  mov  1, %o4
a00a35a4:  90 10 00 18  mov  %i0, %o0
a00a35a8:  92 10 20 01  mov  1, %o1
a00a35ac:  94 10 20 7d  mov  0x7d, %o2
a00a35b0:  40 00 12 c7  call  0xa00a80cc
a00a35b4:  23 2a 01 e4  sethi  %hi(0xa8079000), %l1
a00a35b8:  a2 14 61 f0  or  %l1, 0x1f0, %l1	! 0xa80791f0
a00a35bc:  c2 0c 40 18  ldub  [ %l1 + %i0 ], %g1
a00a35c0:  21 2a 01 e1  sethi  %hi(0xa8078400), %l0
a00a35c4:  82 00 40 01  add  %g1, %g1, %g1
a00a35c8:  a0 14 23 2a  or  %l0, 0x32a, %l0
a00a35cc:  d4 0c 00 01  ldub  [ %l0 + %g1 ], %o2
a00a35d0:  90 10 00 18  mov  %i0, %o0
a00a35d4:  7f ff aa c7  call  0xa008e0f0
a00a35d8:  92 10 20 03  mov  3, %o1
a00a35dc:  c2 0c 40 18  ldub  [ %l1 + %i0 ], %g1
a00a35e0:  82 00 40 01  add  %g1, %g1, %g1
a00a35e4:  82 00 40 10  add  %g1, %l0, %g1
a00a35e8:  d2 08 60 01  ldub  [ %g1 + 1 ], %o1
a00a35ec:  7f ff ab 05  call  0xa008e200
a00a35f0:  90 10 00 18  mov  %i0, %o0
a00a35f4:  10 80 00 16  b  0xa00a364c
a00a35f8:  b2 10 20 00  clr  %i1
a00a35fc:  12 80 00 16  bne  0xa00a3654
a00a3600:  80 a2 60 03  cmp  %o1, 3
a00a3604:  11 28 01 ae  sethi  %hi(0xa006b800), %o0
a00a3608:  7f ff 3f af  call  0xa00734c4
a00a360c:  90 12 22 28  or  %o0, 0x228, %o0	! 0xa006ba28
a00a3610:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00a3614:  96 10 20 10  mov  0x10, %o3
a00a3618:  98 10 20 01  mov  1, %o4
a00a361c:  90 10 00 18  mov  %i0, %o0
a00a3620:  92 10 20 01  mov  1, %o1
a00a3624:  40 00 12 aa  call  0xa00a80cc
a00a3628:  94 10 20 7d  mov  0x7d, %o2
a00a362c:  90 10 00 18  mov  %i0, %o0
a00a3630:  92 10 20 03  mov  3, %o1
a00a3634:  7f ff aa af  call  0xa008e0f0
a00a3638:  94 10 20 0e  mov  0xe, %o2
a00a363c:  90 10 00 18  mov  %i0, %o0
a00a3640:  7f ff aa f0  call  0xa008e200
a00a3644:  92 10 20 00  clr  %o1
a00a3648:  b2 10 20 03  mov  3, %i1
a00a364c:  7f ff ab 5d  call  0xa008e3c0
a00a3650:  81 e8 00 00  restore
a00a3654:  12 80 00 2f  bne  0xa00a3710
a00a3658:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00a365c:  11 28 01 ae  sethi  %hi(0xa006b800), %o0
a00a3660:  7f ff 3f 99  call  0xa00734c4
a00a3664:  90 12 22 48  or  %o0, 0x248, %o0	! 0xa006ba48
a00a3668:  98 10 20 01  mov  1, %o4
a00a366c:  96 10 20 10  mov  0x10, %o3
a00a3670:  90 10 00 18  mov  %i0, %o0
a00a3674:  92 10 20 01  mov  1, %o1
a00a3678:  40 00 12 95  call  0xa00a80cc
a00a367c:  94 10 20 7d  mov  0x7d, %o2
a00a3680:  92 10 20 01  mov  1, %o1
a00a3684:  94 10 20 08  mov  8, %o2
a00a3688:  40 00 12 54  call  0xa00a7fd8
a00a368c:  90 10 00 18  mov  %i0, %o0
a00a3690:  96 12 3f f0  or  %o0, -16, %o3
a00a3694:  96 0a e0 ff  and  %o3, 0xff, %o3
a00a3698:  90 10 00 18  mov  %i0, %o0
a00a369c:  92 10 20 01  mov  1, %o1
a00a36a0:  40 00 12 6d  call  0xa00a8054
a00a36a4:  94 10 20 08  mov  8, %o2
a00a36a8:  92 10 20 01  mov  1, %o1
a00a36ac:  94 10 20 0e  mov  0xe, %o2
a00a36b0:  40 00 12 4a  call  0xa00a7fd8
a00a36b4:  90 10 00 18  mov  %i0, %o0
a00a36b8:  96 0a 20 f8  and  %o0, 0xf8, %o3
a00a36bc:  90 10 00 18  mov  %i0, %o0
a00a36c0:  92 10 20 01  mov  1, %o1
a00a36c4:  40 00 12 64  call  0xa00a8054
a00a36c8:  94 10 20 0e  mov  0xe, %o2
a00a36cc:  92 10 20 01  mov  1, %o1
a00a36d0:  94 10 20 0e  mov  0xe, %o2
a00a36d4:  40 00 12 41  call  0xa00a7fd8
a00a36d8:  90 10 00 18  mov  %i0, %o0
a00a36dc:  96 0a 20 8f  and  %o0, 0x8f, %o3
a00a36e0:  90 10 00 18  mov  %i0, %o0
a00a36e4:  92 10 20 01  mov  1, %o1
a00a36e8:  40 00 12 5b  call  0xa00a8054
a00a36ec:  94 10 20 0e  mov  0xe, %o2
a00a36f0:  90 10 00 18  mov  %i0, %o0
a00a36f4:  92 10 20 01  mov  1, %o1
a00a36f8:  40 00 12 38  call  0xa00a7fd8
a00a36fc:  94 10 20 7c  mov  0x7c, %o2
a00a3700:  b6 0a 20 cf  and  %o0, 0xcf, %i3
a00a3704:  b2 10 20 01  mov  1, %i1
a00a3708:  10 80 00 1d  b  0xa00a377c
a00a370c:  b4 10 20 7c  mov  0x7c, %i2
a00a3710:  11 28 01 ae  sethi  %hi(0xa006b800), %o0
a00a3714:  7f ff 3e 4c  call  0xa0073044
a00a3718:  90 12 22 60  or  %o0, 0x260, %o0	! 0xa006ba60
a00a371c:  90 10 00 18  mov  %i0, %o0
a00a3720:  92 10 20 01  mov  1, %o1
a00a3724:  94 10 20 7d  mov  0x7d, %o2
a00a3728:  96 10 20 10  mov  0x10, %o3
a00a372c:  98 10 20 00  clr  %o4
a00a3730:  40 00 12 67  call  0xa00a80cc
a00a3734:  23 2a 01 e4  sethi  %hi(0xa8079000), %l1
a00a3738:  a2 14 61 f0  or  %l1, 0x1f0, %l1	! 0xa80791f0
a00a373c:  c2 0c 40 18  ldub  [ %l1 + %i0 ], %g1
a00a3740:  21 2a 01 e1  sethi  %hi(0xa8078400), %l0
a00a3744:  82 00 40 01  add  %g1, %g1, %g1
a00a3748:  a0 14 23 32  or  %l0, 0x332, %l0
a00a374c:  d6 14 00 01  lduh  [ %l0 + %g1 ], %o3
a00a3750:  96 0a e0 ff  and  %o3, 0xff, %o3
a00a3754:  90 10 00 18  mov  %i0, %o0
a00a3758:  92 10 20 04  mov  4, %o1
a00a375c:  40 00 12 3e  call  0xa00a8054
a00a3760:  94 10 20 e2  mov  0xe2, %o2
a00a3764:  c2 0c 40 18  ldub  [ %l1 + %i0 ], %g1
a00a3768:  82 00 40 01  add  %g1, %g1, %g1
a00a376c:  f6 14 00 01  lduh  [ %l0 + %g1 ], %i3
a00a3770:  b7 36 e0 08  srl  %i3, 8, %i3
a00a3774:  b2 10 20 04  mov  4, %i1
a00a3778:  b4 10 20 e3  mov  0xe3, %i2
a00a377c:  40 00 12 36  call  0xa00a8054
a00a3780:  81 e8 00 00  restore
a00a3784:  01 00 00 00  nop
