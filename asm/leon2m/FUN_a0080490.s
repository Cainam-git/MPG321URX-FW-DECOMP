# leon2m FUN_a0080490 0xa0080490-0xa00808ac (1052 bytes)
a0080490:  9d e3 bf 98  save  %sp, -104, %sp
a0080494:  40 03 1c a4  call  0xa0147724
a0080498:  25 2a 00 b3  sethi  %hi(0xa802cc00), %l2
a008049c:  40 03 20 f3  call  0xa0148868
a00804a0:  01 00 00 00  nop
a00804a4:  82 14 a3 f4  or  %l2, 0x3f4, %g1
a00804a8:  90 0a 20 ff  and  %o0, 0xff, %o0
a00804ac:  c0 30 60 0c  clrh  [ %g1 + 0xc ]
a00804b0:  80 a2 20 04  cmp  %o0, 4
a00804b4:  02 80 00 1a  be  0xa008051c
a00804b8:  c0 28 60 3f  clrb  [ %g1 + 0x3f ]
a00804bc:  23 2a 00 b4  sethi  %hi(0xa802d000), %l1
a00804c0:  94 14 62 90  or  %l1, 0x290, %o2	! 0xa802d290
a00804c4:  13 00 00 15  sethi  %hi(0x5400), %o1
a00804c8:  d8 12 a1 f6  lduh  [ %o2 + 0x1f6 ], %o4
a00804cc:  9a 12 61 aa  or  %o1, 0x1aa, %o5
a00804d0:  80 a3 00 0d  cmp  %o4, %o5
a00804d4:  02 80 00 14  be  0xa0080524
a00804d8:  98 14 a3 f4  or  %l2, 0x3f4, %o4
a00804dc:  40 02 9d 40  call  0xa01279dc
a00804e0:  01 00 00 00  nop
a00804e4:  80 8a 20 ff  btst  0xff, %o0
a00804e8:  12 80 00 96  bne  0xa0080740
a00804ec:  01 00 00 00  nop
a00804f0:  40 02 9d 2f  call  0xa01279ac
a00804f4:  01 00 00 00  nop
a00804f8:  80 8a 20 ff  btst  0xff, %o0
a00804fc:  12 80 00 0a  bne  0xa0080524
a0080500:  98 14 a3 f4  or  %l2, 0x3f4, %o4
a0080504:  40 02 9d 0a  call  0xa012792c
a0080508:  01 00 00 00  nop
a008050c:  80 8a 20 ff  btst  0xff, %o0
a0080510:  12 80 00 e5  bne  0xa00808a4
a0080514:  01 00 00 00  nop
a0080518:  30 80 00 9a  b,a   0xa0080780
a008051c:  23 2a 00 b4  sethi  %hi(0xa802d000), %l1
a0080520:  98 14 a3 f4  or  %l2, 0x3f4, %o4
a0080524:  d6 13 20 3e  lduh  [ %o4 + 0x3e ], %o3
a0080528:  15 3f ff e0  sethi  %hi(0xffff8000), %o2
a008052c:  92 2a c0 0a  andn  %o3, %o2, %o1
a0080530:  1b 00 03 fb  sethi  %hi(0xfec00), %o5
a0080534:  d2 33 20 3e  sth  %o1, [ %o4 + 0x3e ]
a0080538:  40 01 7b 0e  call  0xa00df170
a008053c:  90 13 61 10  or  %o5, 0x110, %o0
a0080540:  40 02 91 32  call  0xa0124a08
a0080544:  01 00 00 00  nop
a0080548:  98 14 62 90  or  %l1, 0x290, %o4
a008054c:  d0 03 20 ac  ld  [ %o4 + 0xac ], %o0
a0080550:  03 00 04 00  sethi  %hi(0x100000), %g1
a0080554:  80 8a 00 01  btst  %o0, %g1
a0080558:  02 80 00 46  be  0xa0080670
a008055c:  92 14 62 90  or  %l1, 0x290, %o1
a0080560:  e0 0b 20 1f  ldub  [ %o4 + 0x1f ], %l0
a0080564:  80 a4 20 00  cmp  %l0, 0
a0080568:  32 80 00 43  bne,a   0xa0080674
a008056c:  d8 02 60 a8  ld  [ %o1 + 0xa8 ], %o4
a0080570:  03 2a 00 90  sethi  %hi(0xa8024000), %g1
a0080574:  90 10 3f ff  mov  -1, %o0
a0080578:  9e 10 60 10  or  %g1, 0x10, %o7
a008057c:  d0 28 60 10  stb  %o0, [ %g1 + 0x10 ]
a0080580:  d0 2b e0 01  stb  %o0, [ %o7 + 1 ]
a0080584:  d0 2b e0 03  stb  %o0, [ %o7 + 3 ]
a0080588:  d0 2b e0 02  stb  %o0, [ %o7 + 2 ]
a008058c:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a0080590:  92 12 e2 74  or  %o3, 0x274, %o1	! 0xa802d274
a0080594:  d4 0a 60 14  ldub  [ %o1 + 0x14 ], %o2
a0080598:  80 a2 a0 00  cmp  %o2, 0
a008059c:  32 80 00 43  bne,a   0xa00806a8
a00805a0:  c0 2a 60 14  clrb  [ %o1 + 0x14 ]
a00805a4:  40 02 8f 86  call  0xa01243bc
a00805a8:  90 10 20 01  mov  1, %o0
a00805ac:  40 02 91 41  call  0xa0124ab0
a00805b0:  a0 14 62 90  or  %l1, 0x290, %l0
a00805b4:  40 02 91 63  call  0xa0124b40
a00805b8:  23 00 00 20  sethi  %hi(0x8000), %l1
a00805bc:  40 01 6a ee  call  0xa00db174
a00805c0:  01 00 00 00  nop
a00805c4:  40 03 2d d2  call  0xa014bd0c
a00805c8:  90 10 20 00  clr  %o0	! 0x0
a00805cc:  de 04 20 a8  ld  [ %l0 + 0xa8 ], %o7
a00805d0:  80 8b c0 11  btst  %o7, %l1
a00805d4:  02 80 00 52  be  0xa008071c
a00805d8:  01 00 00 00  nop
a00805dc:  40 02 95 3b  call  0xa0125ac8
a00805e0:  01 00 00 00  nop
a00805e4:  40 02 95 8d  call  0xa0125c18
a00805e8:  01 00 00 00  nop
a00805ec:  92 10 20 00  clr  %o1	! 0x0
a00805f0:  40 00 3a 1f  call  0xa008ee6c
a00805f4:  90 10 20 40  mov  0x40, %o0
a00805f8:  40 03 21 2c  call  0xa0148aa8
a00805fc:  90 10 20 00  clr  %o0
a0080600:  40 03 28 88  call  0xa014a820
a0080604:  90 10 20 01  mov  1, %o0
a0080608:  d0 04 20 a8  ld  [ %l0 + 0xa8 ], %o0
a008060c:  80 8a 00 11  btst  %o0, %l1
a0080610:  02 80 00 2b  be  0xa00806bc
a0080614:  90 10 20 00  clr  %o0
a0080618:  40 03 1c f5  call  0xa01479ec
a008061c:  90 10 20 01  mov  1, %o0
a0080620:  92 10 20 01  mov  1, %o1
a0080624:  40 03 12 c2  call  0xa014512c
a0080628:  90 10 20 00  clr  %o0
a008062c:  92 14 a3 f4  or  %l2, 0x3f4, %o1
a0080630:  d8 12 60 04  lduh  [ %o1 + 4 ], %o4
a0080634:  15 00 00 18  sethi  %hi(0x6000), %o2
a0080638:  82 2b 00 0a  andn  %o4, %o2, %g1
a008063c:  1b 00 00 08  sethi  %hi(0x2000), %o5
a0080640:  e2 04 20 b0  ld  [ %l0 + 0xb0 ], %l1
a0080644:  a4 10 40 0d  or  %g1, %o5, %l2
a0080648:  80 a4 60 00  cmp  %l1, 0
a008064c:  12 80 00 47  bne  0xa0080768
a0080650:  e4 32 60 04  sth  %l2, [ %o1 + 4 ]
a0080654:  40 03 0d d1  call  0xa0143d98
a0080658:  21 00 00 3f  sethi  %hi(0xfc00), %l0
a008065c:  40 01 f7 88  call  0xa00fe47c
a0080660:  b0 14 22 df  or  %l0, 0x2df, %i0	! 0xfedf
a0080664:  b0 0a 00 18  and  %o0, %i0, %i0
a0080668:  40 01 f7 79  call  0xa00fe44c
a008066c:  81 e8 00 00  restore
a0080670:  d8 02 60 a8  ld  [ %o1 + 0xa8 ], %o4
a0080674:  1b 00 00 20  sethi  %hi(0x8000), %o5
a0080678:  80 8b 00 0d  btst  %o4, %o5
a008067c:  12 bf ff c5  bne  0xa0080590
a0080680:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a0080684:  40 03 1c 37  call  0xa0147760
a0080688:  01 00 00 00  nop
a008068c:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a0080690:  92 12 e2 74  or  %o3, 0x274, %o1	! 0xa802d274
a0080694:  d4 0a 60 14  ldub  [ %o1 + 0x14 ], %o2
a0080698:  80 a2 a0 00  cmp  %o2, 0
a008069c:  02 bf ff c2  be  0xa00805a4
a00806a0:  01 00 00 00  nop
a00806a4:  c0 2a 60 14  clrb  [ %o1 + 0x14 ]
a00806a8:  94 10 22 e0  mov  0x2e0, %o2
a00806ac:  96 10 20 1c  mov  0x1c, %o3
a00806b0:  40 03 2a 08  call  0xa014aed0
a00806b4:  90 10 20 30  mov  0x30, %o0
a00806b8:  30 bf ff bb  b,a   0xa00805a4
a00806bc:  40 03 12 9c  call  0xa014512c
a00806c0:  92 10 20 01  mov  1, %o1
a00806c4:  92 10 20 00  clr  %o1
a00806c8:  40 03 0c c4  call  0xa01439d8
a00806cc:  90 10 20 02  mov  2, %o0
a00806d0:  68 00 32 b4  call  0x4008d1a0
a00806d4:  90 10 20 0a  mov  0xa, %o0
a00806d8:  40 02 95 77  call  0xa0125cb4
a00806dc:  90 10 20 03  mov  3, %o0
a00806e0:  40 02 94 75  call  0xa01258b4
a00806e4:  01 00 00 00  nop
a00806e8:  40 02 94 81  call  0xa01258ec
a00806ec:  01 00 00 00  nop
a00806f0:  40 02 94 91  call  0xa0125934
a00806f4:  01 00 00 00  nop
a00806f8:  40 02 94 cb  call  0xa0125a24
a00806fc:  01 00 00 00  nop
a0080700:  40 02 95 b9  call  0xa0125de4
a0080704:  01 00 00 00  nop
a0080708:  80 8e 20 ff  btst  0xff, %i0
a008070c:  02 80 00 13  be  0xa0080758
a0080710:  01 00 00 00  nop
a0080714:  68 00 3c 71  call  0x4008f8d8
a0080718:  81 e8 00 00  restore
a008071c:  40 02 94 94  call  0xa012596c
a0080720:  01 00 00 00  nop
a0080724:  40 02 94 a7  call  0xa01259c0
a0080728:  90 10 20 00  clr  %o0	! 0x0
a008072c:  40 02 94 9e  call  0xa01259a4
a0080730:  01 00 00 00  nop
a0080734:  40 02 95 2b  call  0xa0125be0
a0080738:  01 00 00 00  nop
a008073c:  30 bf ff a8  b,a   0xa00805dc
a0080740:  40 02 9c a1  call  0xa01279c4
a0080744:  01 00 00 00  nop
a0080748:  80 8a 20 ff  btst  0xff, %o0
a008074c:  12 bf ff 76  bne  0xa0080524
a0080750:  98 14 a3 f4  or  %l2, 0x3f4, %o4
a0080754:  30 bf ff 67  b,a   0xa00804f0
a0080758:  40 00 1b c9  call  0xa008767c
a008075c:  90 10 20 01  mov  1, %o0
a0080760:  68 00 3c 5e  call  0x4008f8d8
a0080764:  81 e8 00 00  restore
a0080768:  80 8e 20 ff  btst  0xff, %i0
a008076c:  12 bf ff ba  bne  0xa0080654
a0080770:  01 00 00 00  nop
a0080774:  40 03 2d 39  call  0xa014bc58
a0080778:  90 10 20 00  clr  %o0	! 0x0
a008077c:  30 bf ff b6  b,a   0xa0080654
a0080780:  40 02 9c 71  call  0xa0127944
a0080784:  01 00 00 00  nop
a0080788:  80 8a 20 ff  btst  0xff, %o0
a008078c:  12 80 00 46  bne  0xa00808a4
a0080790:  01 00 00 00  nop
a0080794:  40 00 42 11  call  0xa0090fd8
a0080798:  01 00 00 00  nop
a008079c:  40 02 8f 08  call  0xa01243bc
a00807a0:  90 10 20 01  mov  1, %o0	! 0x1
a00807a4:  40 02 90 c3  call  0xa0124ab0
a00807a8:  01 00 00 00  nop
a00807ac:  40 02 90 e5  call  0xa0124b40
a00807b0:  01 00 00 00  nop
a00807b4:  40 01 6a 70  call  0xa00db174
a00807b8:  01 00 00 00  nop
a00807bc:  40 02 9c 85  call  0xa01279d0
a00807c0:  90 10 20 00  clr  %o0	! 0x0
a00807c4:  40 02 9c 48  call  0xa01278e4
a00807c8:  90 10 20 01  mov  1, %o0
a00807cc:  40 02 9c 49  call  0xa01278f0
a00807d0:  90 10 20 01  mov  1, %o0
a00807d4:  40 02 9c 50  call  0xa0127914
a00807d8:  90 10 20 02  mov  2, %o0
a00807dc:  40 02 9d 27  call  0xa0127c78
a00807e0:  01 00 00 00  nop
a00807e4:  40 02 9c 52  call  0xa012792c
a00807e8:  01 00 00 00  nop
a00807ec:  40 02 9c 56  call  0xa0127944
a00807f0:  a0 0a 20 ff  and  %o0, 0xff, %l0
a00807f4:  94 0a 20 ff  and  %o0, 0xff, %o2
a00807f8:  17 00 03 fb  sethi  %hi(0xfec00), %o3
a00807fc:  92 10 00 10  mov  %l0, %o1
a0080800:  40 01 7a 5c  call  0xa00df170
a0080804:  90 12 e1 28  or  %o3, 0x128, %o0
a0080808:  40 02 9c 49  call  0xa012792c
a008080c:  01 00 00 00  nop
a0080810:  80 8a 20 ff  btst  0xff, %o0
a0080814:  12 80 00 07  bne  0xa0080830
a0080818:  01 00 00 00  nop
a008081c:  40 02 9c 4a  call  0xa0127944
a0080820:  01 00 00 00  nop
a0080824:  80 8a 20 ff  btst  0xff, %o0
a0080828:  02 bf ff 3f  be  0xa0080524
a008082c:  98 14 a3 f4  or  %l2, 0x3f4, %o4
a0080830:  40 02 9c 3f  call  0xa012792c
a0080834:  01 00 00 00  nop
a0080838:  9e 0a 20 ff  and  %o0, 0xff, %o7
a008083c:  80 a3 e0 04  cmp  %o7, 4
a0080840:  02 80 00 11  be  0xa0080884
a0080844:  25 00 03 fb  sethi  %hi(0xfec00), %l2
a0080848:  40 01 7a 4a  call  0xa00df170
a008084c:  90 14 a1 38  or  %l2, 0x138, %o0	! 0xfed38
a0080850:  40 03 0d 52  call  0xa0143d98
a0080854:  31 00 03 fb  sethi  %hi(0xfec00), %i0
a0080858:  90 10 20 00  clr  %o0
a008085c:  40 02 ba 64  call  0xa012f1ec
a0080860:  92 10 20 00  clr  %o1
a0080864:  90 10 20 01  mov  1, %o0
a0080868:  40 02 ba 61  call  0xa012f1ec
a008086c:  92 10 20 00  clr  %o1
a0080870:  90 10 20 03  mov  3, %o0
a0080874:  40 02 ba 5e  call  0xa012f1ec
a0080878:  92 10 20 00  clr  %o1
a008087c:  40 01 7a 3d  call  0xa00df170
a0080880:  91 ee 21 48  restore  %i0, 0x148, %o0
a0080884:  23 00 03 fb  sethi  %hi(0xfec00), %l1
a0080888:  40 01 7a 3a  call  0xa00df170
a008088c:  90 14 61 58  or  %l1, 0x158, %o0	! 0xfed58
a0080890:  90 10 20 00  clr  %o0
a0080894:  40 03 12 26  call  0xa014512c
a0080898:  92 10 20 00  clr  %o1
a008089c:  10 bf ff f8  b  0xa008087c
a00808a0:  31 00 03 fb  sethi  %hi(0xfec00), %i0
a00808a4:  81 c7 e0 08  ret
a00808a8:  81 e8 00 00  restore
