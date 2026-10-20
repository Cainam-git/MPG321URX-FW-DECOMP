# leon2s FUN_a00b3530 0xa00b3530-0xa00b383c (780 bytes)
a00b3530:  9d e3 bf 90  save  %sp, -112, %sp
a00b3534:  82 10 00 18  mov  %i0, %g1
a00b3538:  c2 2f a0 44  stb  %g1, [ %fp + 0x44 ]
a00b353c:  c2 0f a0 44  ldub  [ %fp + 0x44 ], %g1
a00b3540:  82 08 60 ff  and  %g1, 0xff, %g1
a00b3544:  80 a0 60 09  cmp  %g1, 9
a00b3548:  02 80 00 06  be  0xa00b3560
a00b354c:  01 00 00 00  nop
a00b3550:  82 10 3f ff  mov  -1, %g1	! 0xffffffff
a00b3554:  c2 27 bf f0  st  %g1, [ %fp + -16 ]
a00b3558:  10 80 00 b6  b  0xa00b3830
a00b355c:  01 00 00 00  nop
a00b3560:  03 33 c0 f2  sethi  %hi(0xcf03c800), %g1
a00b3564:  82 10 60 80  or  %g1, 0x80, %g1	! 0xcf03c880
a00b3568:  c2 00 40 00  ld  [ %g1 ], %g1
a00b356c:  c2 2f bf f6  stb  %g1, [ %fp + -10 ]
a00b3570:  c0 2f bf f7  clrb  [ %fp + -9 ]
a00b3574:  c2 0f bf f7  ldub  [ %fp + -9 ], %g1
a00b3578:  ba 08 60 ff  and  %g1, 0xff, %i5
a00b357c:  c2 0f a0 44  ldub  [ %fp + 0x44 ], %g1
a00b3580:  82 08 60 ff  and  %g1, 0xff, %g1
a00b3584:  80 a7 40 01  cmp  %i5, %g1
a00b3588:  1a 80 00 a2  bcc  0xa00b3810
a00b358c:  01 00 00 00  nop
a00b3590:  03 2a 01 ea  sethi  %hi(0xa807a800), %g1
a00b3594:  b8 10 60 24  or  %g1, 0x24, %i4	! 0xa807a824
a00b3598:  c2 0f bf f7  ldub  [ %fp + -9 ], %g1
a00b359c:  ba 08 60 ff  and  %g1, 0xff, %i5
a00b35a0:  82 10 00 1d  mov  %i5, %g1
a00b35a4:  83 28 60 02  sll  %g1, 2, %g1
a00b35a8:  82 00 40 1d  add  %g1, %i5, %g1
a00b35ac:  83 28 60 02  sll  %g1, 2, %g1
a00b35b0:  c2 0f 00 01  ldub  [ %i4 + %g1 ], %g1
a00b35b4:  82 08 60 ff  and  %g1, 0xff, %g1
a00b35b8:  80 a0 60 03  cmp  %g1, 3
a00b35bc:  08 80 00 90  bleu  0xa00b37fc
a00b35c0:  01 00 00 00  nop
a00b35c4:  c2 0f bf f6  ldub  [ %fp + -10 ], %g1
a00b35c8:  82 08 60 ff  and  %g1, 0xff, %g1
a00b35cc:  82 08 60 01  and  %g1, 1, %g1
a00b35d0:  80 a0 60 00  cmp  %g1, 0
a00b35d4:  02 80 00 48  be  0xa00b36f4
a00b35d8:  01 00 00 00  nop
a00b35dc:  03 2a 01 ea  sethi  %hi(0xa807a800), %g1
a00b35e0:  b8 10 60 24  or  %g1, 0x24, %i4	! 0xa807a824
a00b35e4:  c2 0f bf f7  ldub  [ %fp + -9 ], %g1
a00b35e8:  ba 08 60 ff  and  %g1, 0xff, %i5
a00b35ec:  82 10 00 1d  mov  %i5, %g1
a00b35f0:  83 28 60 02  sll  %g1, 2, %g1
a00b35f4:  82 00 40 1d  add  %g1, %i5, %g1
a00b35f8:  83 28 60 02  sll  %g1, 2, %g1
a00b35fc:  82 00 40 1c  add  %g1, %i4, %g1
a00b3600:  c2 10 60 12  lduh  [ %g1 + 0x12 ], %g1
a00b3604:  83 28 60 10  sll  %g1, 0x10, %g1
a00b3608:  83 30 60 10  srl  %g1, 0x10, %g1
a00b360c:  83 30 60 03  srl  %g1, 3, %g1
a00b3610:  82 08 60 01  and  %g1, 1, %g1
a00b3614:  82 08 60 ff  and  %g1, 0xff, %g1
a00b3618:  80 a0 60 00  cmp  %g1, 0
a00b361c:  02 80 00 1d  be  0xa00b3690
a00b3620:  01 00 00 00  nop
a00b3624:  03 2a 01 ea  sethi  %hi(0xa807a800), %g1
a00b3628:  b8 10 60 24  or  %g1, 0x24, %i4	! 0xa807a824
a00b362c:  c2 0f bf f7  ldub  [ %fp + -9 ], %g1
a00b3630:  ba 08 60 ff  and  %g1, 0xff, %i5
a00b3634:  82 10 00 1d  mov  %i5, %g1
a00b3638:  83 28 60 02  sll  %g1, 2, %g1
a00b363c:  82 00 40 1d  add  %g1, %i5, %g1
a00b3640:  83 28 60 02  sll  %g1, 2, %g1
a00b3644:  82 00 40 1c  add  %g1, %i4, %g1
a00b3648:  c2 08 60 0d  ldub  [ %g1 + 0xd ], %g1
a00b364c:  82 08 60 ff  and  %g1, 0xff, %g1
a00b3650:  82 08 60 02  and  %g1, 2, %g1
a00b3654:  80 a0 60 00  cmp  %g1, 0
a00b3658:  02 80 00 27  be  0xa00b36f4
a00b365c:  01 00 00 00  nop
a00b3660:  03 2a 01 ea  sethi  %hi(0xa807a800), %g1
a00b3664:  b8 10 60 24  or  %g1, 0x24, %i4	! 0xa807a824
a00b3668:  c2 0f bf f7  ldub  [ %fp + -9 ], %g1
a00b366c:  ba 08 60 ff  and  %g1, 0xff, %i5
a00b3670:  82 10 00 1d  mov  %i5, %g1
a00b3674:  83 28 60 02  sll  %g1, 2, %g1
a00b3678:  82 00 40 1d  add  %g1, %i5, %g1
a00b367c:  bb 28 60 02  sll  %g1, 2, %i5
a00b3680:  82 10 20 02  mov  2, %g1
a00b3684:  c2 2f 00 1d  stb  %g1, [ %i4 + %i5 ]
a00b3688:  10 80 00 1b  b  0xa00b36f4
a00b368c:  01 00 00 00  nop
a00b3690:  03 2a 01 ea  sethi  %hi(0xa807a800), %g1
a00b3694:  b8 10 60 24  or  %g1, 0x24, %i4	! 0xa807a824
a00b3698:  c2 0f bf f7  ldub  [ %fp + -9 ], %g1
a00b369c:  ba 08 60 ff  and  %g1, 0xff, %i5
a00b36a0:  82 10 00 1d  mov  %i5, %g1
a00b36a4:  83 28 60 02  sll  %g1, 2, %g1
a00b36a8:  82 00 40 1d  add  %g1, %i5, %g1
a00b36ac:  83 28 60 02  sll  %g1, 2, %g1
a00b36b0:  82 00 40 1c  add  %g1, %i4, %g1
a00b36b4:  c2 08 60 0d  ldub  [ %g1 + 0xd ], %g1
a00b36b8:  82 08 60 ff  and  %g1, 0xff, %g1
a00b36bc:  82 08 60 02  and  %g1, 2, %g1
a00b36c0:  80 a0 60 00  cmp  %g1, 0
a00b36c4:  02 80 00 0c  be  0xa00b36f4
a00b36c8:  01 00 00 00  nop
a00b36cc:  03 2a 01 ea  sethi  %hi(0xa807a800), %g1
a00b36d0:  b8 10 60 24  or  %g1, 0x24, %i4	! 0xa807a824
a00b36d4:  c2 0f bf f7  ldub  [ %fp + -9 ], %g1
a00b36d8:  ba 08 60 ff  and  %g1, 0xff, %i5
a00b36dc:  82 10 00 1d  mov  %i5, %g1
a00b36e0:  83 28 60 02  sll  %g1, 2, %g1
a00b36e4:  82 00 40 1d  add  %g1, %i5, %g1
a00b36e8:  bb 28 60 02  sll  %g1, 2, %i5
a00b36ec:  82 10 20 02  mov  2, %g1
a00b36f0:  c2 2f 00 1d  stb  %g1, [ %i4 + %i5 ]
a00b36f4:  c2 0f bf f6  ldub  [ %fp + -10 ], %g1
a00b36f8:  82 08 60 ff  and  %g1, 0xff, %g1
a00b36fc:  82 08 60 02  and  %g1, 2, %g1
a00b3700:  80 a0 60 00  cmp  %g1, 0
a00b3704:  02 80 00 3e  be  0xa00b37fc
a00b3708:  01 00 00 00  nop
a00b370c:  03 2a 01 ea  sethi  %hi(0xa807a800), %g1
a00b3710:  b8 10 60 24  or  %g1, 0x24, %i4	! 0xa807a824
a00b3714:  c2 0f bf f7  ldub  [ %fp + -9 ], %g1
a00b3718:  ba 08 60 ff  and  %g1, 0xff, %i5
a00b371c:  82 10 00 1d  mov  %i5, %g1
a00b3720:  83 28 60 02  sll  %g1, 2, %g1
a00b3724:  82 00 40 1d  add  %g1, %i5, %g1
a00b3728:  83 28 60 02  sll  %g1, 2, %g1
a00b372c:  82 00 40 1c  add  %g1, %i4, %g1
a00b3730:  c2 10 60 12  lduh  [ %g1 + 0x12 ], %g1
a00b3734:  83 28 60 10  sll  %g1, 0x10, %g1
a00b3738:  83 30 60 10  srl  %g1, 0x10, %g1
a00b373c:  83 30 60 03  srl  %g1, 3, %g1
a00b3740:  82 08 60 01  and  %g1, 1, %g1
a00b3744:  82 08 60 ff  and  %g1, 0xff, %g1
a00b3748:  80 a0 60 00  cmp  %g1, 0
a00b374c:  12 80 00 2c  bne  0xa00b37fc
a00b3750:  01 00 00 00  nop
a00b3754:  03 2a 01 ea  sethi  %hi(0xa807a800), %g1
a00b3758:  b8 10 60 24  or  %g1, 0x24, %i4	! 0xa807a824
a00b375c:  c2 0f bf f7  ldub  [ %fp + -9 ], %g1
a00b3760:  ba 08 60 ff  and  %g1, 0xff, %i5
a00b3764:  82 10 00 1d  mov  %i5, %g1
a00b3768:  83 28 60 02  sll  %g1, 2, %g1
a00b376c:  82 00 40 1d  add  %g1, %i5, %g1
a00b3770:  83 28 60 02  sll  %g1, 2, %g1
a00b3774:  82 00 40 1c  add  %g1, %i4, %g1
a00b3778:  c2 10 60 0e  lduh  [ %g1 + 0xe ], %g1
a00b377c:  83 28 60 10  sll  %g1, 0x10, %g1
a00b3780:  83 30 60 10  srl  %g1, 0x10, %g1
a00b3784:  83 30 60 0d  srl  %g1, 0xd, %g1
a00b3788:  82 08 60 01  and  %g1, 1, %g1
a00b378c:  82 08 60 ff  and  %g1, 0xff, %g1
a00b3790:  80 a0 60 00  cmp  %g1, 0
a00b3794:  02 80 00 1a  be  0xa00b37fc
a00b3798:  01 00 00 00  nop
a00b379c:  03 2a 01 ea  sethi  %hi(0xa807a800), %g1
a00b37a0:  b8 10 60 24  or  %g1, 0x24, %i4	! 0xa807a824
a00b37a4:  c2 0f bf f7  ldub  [ %fp + -9 ], %g1
a00b37a8:  ba 08 60 ff  and  %g1, 0xff, %i5
a00b37ac:  82 10 00 1d  mov  %i5, %g1
a00b37b0:  83 28 60 02  sll  %g1, 2, %g1
a00b37b4:  82 00 40 1d  add  %g1, %i5, %g1
a00b37b8:  83 28 60 02  sll  %g1, 2, %g1
a00b37bc:  ba 00 40 1c  add  %g1, %i4, %i5
a00b37c0:  f8 17 60 0e  lduh  [ %i5 + 0xe ], %i4
a00b37c4:  03 3f ff f7  sethi  %hi(0xffffdc00), %g1
a00b37c8:  82 10 63 ff  or  %g1, 0x3ff, %g1	! 0xffffdfff
a00b37cc:  82 0f 00 01  and  %i4, %g1, %g1
a00b37d0:  c2 37 60 0e  sth  %g1, [ %i5 + 0xe ]
a00b37d4:  03 2a 01 ea  sethi  %hi(0xa807a800), %g1
a00b37d8:  b8 10 60 24  or  %g1, 0x24, %i4	! 0xa807a824
a00b37dc:  c2 0f bf f7  ldub  [ %fp + -9 ], %g1
a00b37e0:  ba 08 60 ff  and  %g1, 0xff, %i5
a00b37e4:  82 10 00 1d  mov  %i5, %g1
a00b37e8:  83 28 60 02  sll  %g1, 2, %g1
a00b37ec:  82 00 40 1d  add  %g1, %i5, %g1
a00b37f0:  bb 28 60 02  sll  %g1, 2, %i5
a00b37f4:  82 10 20 02  mov  2, %g1
a00b37f8:  c2 2f 00 1d  stb  %g1, [ %i4 + %i5 ]
a00b37fc:  c2 0f bf f7  ldub  [ %fp + -9 ], %g1
a00b3800:  82 00 60 01  inc  %g1
a00b3804:  c2 2f bf f7  stb  %g1, [ %fp + -9 ]
a00b3808:  10 bf ff 5b  b  0xa00b3574
a00b380c:  01 00 00 00  nop
a00b3810:  03 33 c0 f2  sethi  %hi(0xcf03c800), %g1
a00b3814:  ba 10 61 20  or  %g1, 0x120, %i5	! 0xcf03c920
a00b3818:  03 33 c0 f2  sethi  %hi(0xcf03c800), %g1
a00b381c:  82 10 61 10  or  %g1, 0x110, %g1	! 0xcf03c910
a00b3820:  c2 00 40 00  ld  [ %g1 ], %g1
a00b3824:  c2 27 40 00  st  %g1, [ %i5 ]
a00b3828:  82 10 20 03  mov  3, %g1
a00b382c:  c2 27 bf f0  st  %g1, [ %fp + -16 ]
a00b3830:  f0 07 bf f0  ld  [ %fp + -16 ], %i0
a00b3834:  81 c7 e0 08  ret
a00b3838:  81 e8 00 00  restore
