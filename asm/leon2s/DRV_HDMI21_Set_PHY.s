# leon2s DRV_HDMI21_Set_PHY 0xa0080494-0xa0083324 (11920 bytes)
a0080494:  9d e3 be b0  save  %sp, -336, %sp
a0080498:  98 10 20 00  clr  %o4
a008049c:  9a 10 20 00  clr  %o5
a00804a0:  13 28 02 d0  sethi  %hi(0xa00b4000), %o1
a00804a4:  d8 3f bf 68  std  %o4, [ %fp + -152 ]
a00804a8:  c0 27 bf f0  clr  [ %fp + -16 ]
a00804ac:  c0 27 bf d0  clr  [ %fp + -48 ]
a00804b0:  c0 27 bf c8  clr  [ %fp + -56 ]
a00804b4:  c0 27 bf c0  clr  [ %fp + -64 ]
a00804b8:  d8 3f bf 98  std  %o4, [ %fp + -104 ]
a00804bc:  d8 3f bf 70  std  %o4, [ %fp + -144 ]
a00804c0:  92 12 60 0c  or  %o1, 0xc, %o1
a00804c4:  90 07 bf 40  add  %fp, -192, %o0
a00804c8:  40 00 c4 44  call  0xa00b15d8
a00804cc:  94 10 20 08  mov  8, %o2
a00804d0:  a2 0e 20 ff  and  %i0, 0xff, %l1
a00804d4:  80 a4 60 02  cmp  %l1, 2
a00804d8:  c0 37 bf 2e  clrh  [ %fp + -210 ]
a00804dc:  b4 10 20 00  clr  %i2
a00804e0:  c0 2f bf 27  clrb  [ %fp + -217 ]
a00804e4:  02 80 00 05  be  0xa00804f8
a00804e8:  b6 10 20 00  clr  %i3
a00804ec:  80 a4 60 03  cmp  %l1, 3
a00804f0:  12 80 0b 8a  bne  0xa0083318
a00804f4:  b6 10 20 01  mov  1, %i3
a00804f8:  17 2a 01 e1  sethi  %hi(0xa8078400), %o3
a00804fc:  c2 02 e2 34  ld  [ %o3 + 0x234 ], %g1	! 0xa8078634
a0080500:  80 88 68 00  btst  0x800, %g1
a0080504:  02 80 00 0a  be  0xa008052c
a0080508:  92 06 20 41  add  %i0, 0x41, %o1
a008050c:  93 2a 60 18  sll  %o1, 0x18, %o1
a0080510:  11 28 01 a1  sethi  %hi(0xa0068400), %o0
a0080514:  15 28 02 cf  sethi  %hi(0xa00b3c00), %o2
a0080518:  90 12 22 f0  or  %o0, 0x2f0, %o0
a008051c:  93 3a 60 18  sra  %o1, 0x18, %o1
a0080520:  94 12 a3 f8  or  %o2, 0x3f8, %o2
a0080524:  7f ff ca c8  call  0xa0073044
a0080528:  96 0e 60 ff  and  %i1, 0xff, %o3
a008052c:  7f ff cc 76  call  0xa0073704
a0080530:  90 10 00 11  mov  %l1, %o0
a0080534:  40 00 c4 98  call  0xa00b1794
a0080538:  90 10 20 01  mov  1, %o0
a008053c:  7f ff e9 96  call  0xa007ab94
a0080540:  90 10 00 11  mov  %l1, %o0
a0080544:  7f ff e9 ce  call  0xa007ac7c
a0080548:  90 10 00 11  mov  %l1, %o0
a008054c:  98 06 7f ff  add  %i1, -1, %o4
a0080550:  82 0b 20 ff  and  %o4, 0xff, %g1
a0080554:  80 a0 60 02  cmp  %g1, 2
a0080558:  18 80 00 23  bgu  0xa00805e4
a008055c:  d8 27 bf 1c  st  %o4, [ %fp + -228 ]
a0080560:  21 00 00 0b  sethi  %hi(0x2c00), %l0
a0080564:  96 14 22 5c  or  %l0, 0x25c, %o3	! 0x2e5c
a0080568:  94 10 00 11  mov  %l1, %o2
a008056c:  90 10 20 01  mov  1, %o0
a0080570:  40 00 9b ad  call  0xa00a7424
a0080574:  92 10 20 1b  mov  0x1b, %o1
a0080578:  96 14 22 38  or  %l0, 0x238, %o3
a008057c:  94 10 00 11  mov  %l1, %o2
a0080580:  90 10 20 01  mov  1, %o0
a0080584:  40 00 9b a8  call  0xa00a7424
a0080588:  92 10 20 1b  mov  0x1b, %o1
a008058c:  92 14 22 00  or  %l0, 0x200, %o1
a0080590:  90 10 00 11  mov  %l1, %o0
a0080594:  94 10 3f f0  mov  -16, %o2
a0080598:  40 00 9b bc  call  0xa00a7488
a008059c:  96 10 20 07  mov  7, %o3
a00805a0:  a0 04 28 00  add  %l0, 0x800, %l0
a00805a4:  94 10 00 11  mov  %l1, %o2
a00805a8:  96 14 22 18  or  %l0, 0x218, %o3
a00805ac:  90 10 20 00  clr  %o0
a00805b0:  40 00 9b 9d  call  0xa00a7424
a00805b4:  92 10 20 1d  mov  0x1d, %o1
a00805b8:  94 10 00 11  mov  %l1, %o2
a00805bc:  96 14 22 18  or  %l0, 0x218, %o3
a00805c0:  90 10 20 01  mov  1, %o0
a00805c4:  40 00 9b 98  call  0xa00a7424
a00805c8:  92 10 20 1c  mov  0x1c, %o1
a00805cc:  15 3e 3f ff  sethi  %hi(0xf8fffc00), %o2
a00805d0:  90 10 00 11  mov  %l1, %o0
a00805d4:  92 14 22 18  or  %l0, 0x218, %o1
a00805d8:  94 12 a3 ff  or  %o2, 0x3ff, %o2
a00805dc:  10 80 00 22  b  0xa0080664
a00805e0:  17 00 c0 00  sethi  %hi(0x3000000), %o3
a00805e4:  21 00 00 0b  sethi  %hi(0x2c00), %l0
a00805e8:  96 14 22 5c  or  %l0, 0x25c, %o3	! 0x2e5c
a00805ec:  90 10 20 00  clr  %o0
a00805f0:  92 10 20 1b  mov  0x1b, %o1
a00805f4:  40 00 9b 8c  call  0xa00a7424
a00805f8:  94 10 00 11  mov  %l1, %o2
a00805fc:  96 14 22 38  or  %l0, 0x238, %o3
a0080600:  90 10 20 00  clr  %o0
a0080604:  92 10 20 1b  mov  0x1b, %o1
a0080608:  40 00 9b 87  call  0xa00a7424
a008060c:  94 10 00 11  mov  %l1, %o2
a0080610:  92 14 22 00  or  %l0, 0x200, %o1
a0080614:  90 10 00 11  mov  %l1, %o0
a0080618:  94 10 3f f0  mov  -16, %o2
a008061c:  40 00 9b 9b  call  0xa00a7488
a0080620:  96 10 20 0f  mov  0xf, %o3
a0080624:  a0 04 28 00  add  %l0, 0x800, %l0
a0080628:  90 10 20 01  mov  1, %o0
a008062c:  92 10 20 1d  mov  0x1d, %o1
a0080630:  94 10 00 11  mov  %l1, %o2
a0080634:  40 00 9b 7c  call  0xa00a7424
a0080638:  96 14 22 18  or  %l0, 0x218, %o3
a008063c:  90 10 20 01  mov  1, %o0
a0080640:  92 10 20 1c  mov  0x1c, %o1
a0080644:  94 10 00 11  mov  %l1, %o2
a0080648:  40 00 9b 77  call  0xa00a7424
a008064c:  96 14 22 18  or  %l0, 0x218, %o3
a0080650:  15 3e 3f ff  sethi  %hi(0xf8fffc00), %o2
a0080654:  90 10 00 11  mov  %l1, %o0
a0080658:  92 14 22 18  or  %l0, 0x218, %o1
a008065c:  94 12 a3 ff  or  %o2, 0x3ff, %o2
a0080660:  17 01 00 00  sethi  %hi(0x4000000), %o3
a0080664:  40 00 9b 89  call  0xa00a7488
a0080668:  21 00 00 0b  sethi  %hi(0x2c00), %l0
a008066c:  90 10 00 11  mov  %l1, %o0
a0080670:  92 10 20 01  mov  1, %o1
a0080674:  7f ff e4 41  call  0xa0079778
a0080678:  94 10 20 01  mov  1, %o2
a008067c:  90 10 20 01  mov  1, %o0
a0080680:  92 10 20 14  mov  0x14, %o1
a0080684:  94 10 00 11  mov  %l1, %o2
a0080688:  40 00 9b 67  call  0xa00a7424
a008068c:  96 14 23 08  or  %l0, 0x308, %o3
a0080690:  96 14 23 08  or  %l0, 0x308, %o3
a0080694:  90 10 20 00  clr  %o0
a0080698:  92 10 20 14  mov  0x14, %o1
a008069c:  40 00 9b 62  call  0xa00a7424
a00806a0:  94 10 00 11  mov  %l1, %o2
a00806a4:  90 10 00 11  mov  %l1, %o0
a00806a8:  13 00 00 08  sethi  %hi(0x2000), %o1
a00806ac:  94 10 3f 00  mov  -256, %o2
a00806b0:  40 00 9b 76  call  0xa00a7488
a00806b4:  96 10 20 f9  mov  0xf9, %o3
a00806b8:  ac 06 7f fc  add  %i1, -4, %l6
a00806bc:  82 0d a0 ff  and  %l6, 0xff, %g1
a00806c0:  80 a0 60 02  cmp  %g1, 2
a00806c4:  38 80 00 11  bgu,a   0xa0080708
a00806c8:  17 00 00 0d  sethi  %hi(0x3400), %o3
a00806cc:  a0 04 28 00  add  %l0, 0x800, %l0
a00806d0:  94 10 00 11  mov  %l1, %o2
a00806d4:  96 14 22 08  or  %l0, 0x208, %o3
a00806d8:  90 10 20 01  mov  1, %o0
a00806dc:  40 00 9b 52  call  0xa00a7424
a00806e0:  92 10 20 04  mov  4, %o1
a00806e4:  96 14 22 08  or  %l0, 0x208, %o3
a00806e8:  90 10 20 01  mov  1, %o0
a00806ec:  94 10 00 11  mov  %l1, %o2
a00806f0:  40 00 9b 4d  call  0xa00a7424
a00806f4:  92 10 20 05  mov  5, %o1
a00806f8:  17 00 00 04  sethi  %hi(0x1000), %o3
a00806fc:  96 12 e1 40  or  %o3, 0x140, %o3	! 0x1140
a0080700:  10 80 00 0a  b  0xa0080728
a0080704:  90 10 20 01  mov  1, %o0
a0080708:  96 12 e2 08  or  %o3, 0x208, %o3
a008070c:  90 10 20 00  clr  %o0
a0080710:  92 10 20 04  mov  4, %o1
a0080714:  40 00 9b 44  call  0xa00a7424
a0080718:  94 10 00 11  mov  %l1, %o2
a008071c:  17 00 00 04  sethi  %hi(0x1000), %o3
a0080720:  96 12 e1 40  or  %o3, 0x140, %o3	! 0x1140
a0080724:  90 10 20 00  clr  %o0
a0080728:  92 10 20 00  clr  %o1
a008072c:  40 00 9b 3e  call  0xa00a7424
a0080730:  94 10 00 11  mov  %l1, %o2
a0080734:  21 00 00 0b  sethi  %hi(0x2c00), %l0
a0080738:  96 14 20 04  or  %l0, 4, %o3	! 0x2c04
a008073c:  90 10 20 01  mov  1, %o0
a0080740:  92 10 20 10  mov  0x10, %o1
a0080744:  40 00 9b 38  call  0xa00a7424
a0080748:  94 10 00 11  mov  %l1, %o2
a008074c:  96 14 20 04  or  %l0, 4, %o3
a0080750:  90 10 20 01  mov  1, %o0
a0080754:  92 10 20 13  mov  0x13, %o1
a0080758:  40 00 9b 33  call  0xa00a7424
a008075c:  94 10 00 11  mov  %l1, %o2
a0080760:  25 3f c0 3f  sethi  %hi(0xff00fc00), %l2
a0080764:  90 10 00 11  mov  %l1, %o0
a0080768:  13 00 00 08  sethi  %hi(0x2000), %o1
a008076c:  94 14 a3 ff  or  %l2, 0x3ff, %o2
a0080770:  40 00 9b 46  call  0xa00a7488
a0080774:  17 00 1b 80  sethi  %hi(0x6e0000), %o3
a0080778:  a0 04 28 00  add  %l0, 0x800, %l0
a008077c:  90 10 20 01  mov  1, %o0
a0080780:  92 10 20 08  mov  8, %o1
a0080784:  94 10 00 11  mov  %l1, %o2
a0080788:  40 00 9b 27  call  0xa00a7424
a008078c:  96 14 22 08  or  %l0, 0x208, %o3
a0080790:  90 10 20 01  mov  1, %o0
a0080794:  92 10 20 09  mov  9, %o1
a0080798:  94 10 00 11  mov  %l1, %o2
a008079c:  40 00 9b 22  call  0xa00a7424
a00807a0:  96 14 22 08  or  %l0, 0x208, %o3
a00807a4:  b8 06 7f fe  add  %i1, -2, %i4
a00807a8:  82 0f 20 ff  and  %i4, 0xff, %g1
a00807ac:  80 a0 60 04  cmp  %g1, 4
a00807b0:  18 80 00 06  bgu  0xa00807c8
a00807b4:  92 14 22 08  or  %l0, 0x208, %o1
a00807b8:  94 14 a3 ff  or  %l2, 0x3ff, %o2
a00807bc:  90 10 00 11  mov  %l1, %o0
a00807c0:  10 80 00 05  b  0xa00807d4
a00807c4:  17 00 03 00  sethi  %hi(0xc0000), %o3
a00807c8:  94 14 a3 ff  or  %l2, 0x3ff, %o2
a00807cc:  90 10 00 11  mov  %l1, %o0
a00807d0:  17 00 01 40  sethi  %hi(0x50000), %o3
a00807d4:  40 00 9b 2d  call  0xa00a7488
a00807d8:  a4 10 20 00  clr  %l2
a00807dc:  17 00 00 0b  sethi  %hi(0x2c00), %o3
a00807e0:  94 10 00 11  mov  %l1, %o2
a00807e4:  96 12 e3 40  or  %o3, 0x340, %o3
a00807e8:  90 10 20 01  mov  1, %o0
a00807ec:  40 00 9b 0e  call  0xa00a7424
a00807f0:  92 10 20 18  mov  0x18, %o1
a00807f4:  a2 0e 60 ff  and  %i1, 0xff, %l1
a00807f8:  82 1c 60 06  xor  %l1, 6, %g1
a00807fc:  80 a0 00 01  cmp  %g0, %g1
a0080800:  82 60 20 00  subx  %g0, 0, %g1
a0080804:  aa 08 60 f0  and  %g1, 0xf0, %l5
a0080808:  82 0c a0 ff  and  %l2, 0xff, %g1
a008080c:  27 3f ff c0  sethi  %hi(0xffff0000), %l3
a0080810:  90 0e 20 ff  and  %i0, 0xff, %o0
a0080814:  94 14 e0 ff  or  %l3, 0xff, %o2
a0080818:  17 00 00 22  sethi  %hi(0x8800), %o3
a008081c:  29 3f c0 3f  sethi  %hi(0xff00fc00), %l4
a0080820:  a0 00 40 01  add  %g1, %g1, %l0
a0080824:  80 a0 60 03  cmp  %g1, 3
a0080828:  18 80 00 1c  bgu  0xa0080898
a008082c:  a4 04 a0 01  inc  %l2
a0080830:  03 28 02 ce  sethi  %hi(0xa00b3800), %g1
a0080834:  82 10 63 50  or  %g1, 0x350, %g1	! 0xa00b3b50
a0080838:  40 00 9b 14  call  0xa00a7488
a008083c:  d2 10 40 10  lduh  [ %g1 + %l0 ], %o1
a0080840:  03 28 02 ce  sethi  %hi(0xa00b3800), %g1
a0080844:  82 10 63 30  or  %g1, 0x330, %g1	! 0xa00b3b30
a0080848:  96 0d 60 ff  and  %l5, 0xff, %o3
a008084c:  d2 10 40 10  lduh  [ %g1 + %l0 ], %o1
a0080850:  97 2a e0 10  sll  %o3, 0x10, %o3
a0080854:  90 0e 20 ff  and  %i0, 0xff, %o0
a0080858:  40 00 9b 0c  call  0xa00a7488
a008085c:  94 15 23 ff  or  %l4, 0x3ff, %o2
a0080860:  03 28 02 ce  sethi  %hi(0xa00b3800), %g1
a0080864:  82 10 63 48  or  %g1, 0x348, %g1	! 0xa00b3b48
a0080868:  d2 10 40 10  lduh  [ %g1 + %l0 ], %o1
a008086c:  94 14 e0 ff  or  %l3, 0xff, %o2
a0080870:  90 0e 20 ff  and  %i0, 0xff, %o0
a0080874:  40 00 9b 05  call  0xa00a7488
a0080878:  17 00 00 22  sethi  %hi(0x8800), %o3
a008087c:  03 28 02 ce  sethi  %hi(0xa00b3800), %g1
a0080880:  82 10 63 28  or  %g1, 0x328, %g1	! 0xa00b3b28
a0080884:  d2 10 40 10  lduh  [ %g1 + %l0 ], %o1
a0080888:  94 15 23 ff  or  %l4, 0x3ff, %o2
a008088c:  90 0e 20 ff  and  %i0, 0xff, %o0
a0080890:  40 00 9a fe  call  0xa00a7488
a0080894:  17 00 0c 00  sethi  %hi(0x300000), %o3
a0080898:  82 0c a0 ff  and  %l2, 0xff, %g1
a008089c:  80 a0 60 03  cmp  %g1, 3
a00808a0:  08 bf ff dc  bleu  0xa0080810
a00808a4:  27 3f ff c0  sethi  %hi(0xffff0000), %l3
a00808a8:  13 00 00 08  sethi  %hi(0x2000), %o1
a00808ac:  15 00 3f ff  sethi  %hi(0xfffc00), %o2
a00808b0:  92 12 60 1c  or  %o1, 0x1c, %o1
a00808b4:  94 12 a3 ff  or  %o2, 0x3ff, %o2
a00808b8:  90 0e 20 ff  and  %i0, 0xff, %o0
a00808bc:  40 00 9a f3  call  0xa00a7488
a00808c0:  17 22 00 00  sethi  %hi(0x88000000), %o3
a00808c4:  a4 10 20 00  clr  %l2
a00808c8:  82 0c a0 ff  and  %l2, 0xff, %g1
a00808cc:  15 3f c0 3f  sethi  %hi(0xff00fc00), %o2
a00808d0:  94 12 a3 ff  or  %o2, 0x3ff, %o2	! 0xff00ffff
a00808d4:  90 0e 20 ff  and  %i0, 0xff, %o0
a00808d8:  17 00 3f c0  sethi  %hi(0xff0000), %o3
a00808dc:  a6 00 40 01  add  %g1, %g1, %l3
a00808e0:  80 a0 60 03  cmp  %g1, 3
a00808e4:  18 80 00 19  bgu  0xa0080948
a00808e8:  a4 04 a0 01  inc  %l2
a00808ec:  03 28 02 ce  sethi  %hi(0xa00b3800), %g1
a00808f0:  82 10 63 10  or  %g1, 0x310, %g1	! 0xa00b3b10
a00808f4:  e0 10 40 13  lduh  [ %g1 + %l3 ], %l0
a00808f8:  40 00 9a e4  call  0xa00a7488
a00808fc:  92 10 00 10  mov  %l0, %o1
a0080900:  92 10 00 10  mov  %l0, %o1
a0080904:  90 0e 20 ff  and  %i0, 0xff, %o0
a0080908:  94 10 3f 00  mov  -256, %o2
a008090c:  40 00 9a df  call  0xa00a7488
a0080910:  96 10 20 a0  mov  0xa0, %o3
a0080914:  03 28 02 ce  sethi  %hi(0xa00b3800), %g1
a0080918:  82 10 63 70  or  %g1, 0x370, %g1	! 0xa00b3b70
a008091c:  e0 10 40 13  lduh  [ %g1 + %l3 ], %l0
a0080920:  90 10 20 00  clr  %o0
a0080924:  92 10 20 10  mov  0x10, %o1
a0080928:  94 0e 20 ff  and  %i0, 0xff, %o2
a008092c:  40 00 9a be  call  0xa00a7424
a0080930:  96 10 00 10  mov  %l0, %o3
a0080934:  96 10 00 10  mov  %l0, %o3
a0080938:  90 10 20 00  clr  %o0
a008093c:  92 10 20 11  mov  0x11, %o1
a0080940:  40 00 9a b9  call  0xa00a7424
a0080944:  94 0e 20 ff  and  %i0, 0xff, %o2
a0080948:  82 0c a0 ff  and  %l2, 0xff, %g1
a008094c:  80 a0 60 03  cmp  %g1, 3
a0080950:  28 bf ff e0  bleu,a   0xa00808d0
a0080954:  15 3f c0 3f  sethi  %hi(0xff00fc00), %o2
a0080958:  82 0f 20 ff  and  %i4, 0xff, %g1
a008095c:  80 a0 60 02  cmp  %g1, 2
a0080960:  18 80 00 1b  bgu  0xa00809cc
a0080964:  80 a4 60 01  cmp  %l1, 1
a0080968:  03 28 02 ce  sethi  %hi(0xa00b3800), %g1
a008096c:  da 00 62 e4  ld  [ %g1 + 0x2e4 ], %o5	! 0xa00b3ae4
a0080970:  03 28 02 ce  sethi  %hi(0xa00b3800), %g1
a0080974:  d6 00 62 dc  ld  [ %g1 + 0x2dc ], %o3	! 0xa00b3adc
a0080978:  15 2a 01 f3  sethi  %hi(0xa807cc00), %o2
a008097c:  13 2a 01 f3  sethi  %hi(0xa807cc00), %o1
a0080980:  82 12 a0 50  or  %o2, 0x50, %g1
a0080984:  98 12 60 60  or  %o1, 0x60, %o4
a0080988:  c0 28 60 01  clrb  [ %g1 + 1 ]
a008098c:  c0 2a a0 50  clrb  [ %o2 + 0x50 ]
a0080990:  da 2f bf 3b  stb  %o5, [ %fp + -197 ]
a0080994:  c0 2b 20 01  clrb  [ %o4 + 1 ]
a0080998:  c0 2a 60 60  clrb  [ %o1 + 0x60 ]
a008099c:  d6 37 bf 36  sth  %o3, [ %fp + -202 ]
a00809a0:  c0 28 60 03  clrb  [ %g1 + 3 ]
a00809a4:  c0 28 60 02  clrb  [ %g1 + 2 ]
a00809a8:  da 2f bf 38  stb  %o5, [ %fp + -200 ]
a00809ac:  da 2f bf 39  stb  %o5, [ %fp + -199 ]
a00809b0:  da 2f bf 3a  stb  %o5, [ %fp + -198 ]
a00809b4:  c0 2b 20 03  clrb  [ %o4 + 3 ]
a00809b8:  c0 2b 20 02  clrb  [ %o4 + 2 ]
a00809bc:  d6 37 bf 30  sth  %o3, [ %fp + -208 ]
a00809c0:  d6 37 bf 32  sth  %o3, [ %fp + -206 ]
a00809c4:  10 80 00 34  b  0xa0080a94
a00809c8:  d6 37 bf 34  sth  %o3, [ %fp + -204 ]
a00809cc:  12 80 00 24  bne  0xa0080a5c
a00809d0:  82 06 7f fb  add  %i1, -5, %g1
a00809d4:  9a 0e e0 ff  and  %i3, 0xff, %o5
a00809d8:  03 2a 01 f5  sethi  %hi(0xa807d400), %g1
a00809dc:  82 10 62 80  or  %g1, 0x280, %g1	! 0xa807d680
a00809e0:  9a 5b 60 b0  smul  %o5, 0xb0, %o5
a00809e4:  9a 03 40 01  add  %o5, %g1, %o5
a00809e8:  03 28 02 ce  sethi  %hi(0xa00b3800), %g1
a00809ec:  d8 00 62 e8  ld  [ %g1 + 0x2e8 ], %o4	! 0xa00b3ae8
a00809f0:  03 28 02 ce  sethi  %hi(0xa00b3800), %g1
a00809f4:  d4 00 62 e0  ld  [ %g1 + 0x2e0 ], %o2	! 0xa00b3ae0
a00809f8:  11 2a 01 f3  sethi  %hi(0xa807cc00), %o0
a00809fc:  82 12 20 50  or  %o0, 0x50, %g1	! 0xa807cc50
a0080a00:  13 2a 01 f3  sethi  %hi(0xa807cc00), %o1
a0080a04:  e2 2a 60 60  stb  %l1, [ %o1 + 0x60 ]	! 0xa807cc60
a0080a08:  e2 28 60 01  stb  %l1, [ %g1 + 1 ]
a0080a0c:  e2 2a 20 50  stb  %l1, [ %o0 + 0x50 ]
a0080a10:  e2 2b 60 15  stb  %l1, [ %o5 + 0x15 ]
a0080a14:  96 12 60 60  or  %o1, 0x60, %o3
a0080a18:  d8 2f bf 3b  stb  %o4, [ %fp + -197 ]
a0080a1c:  e2 2a e0 01  stb  %l1, [ %o3 + 1 ]
a0080a20:  d4 37 bf 36  sth  %o2, [ %fp + -202 ]
a0080a24:  e2 28 60 03  stb  %l1, [ %g1 + 3 ]
a0080a28:  e2 28 60 02  stb  %l1, [ %g1 + 2 ]
a0080a2c:  e2 2b 60 18  stb  %l1, [ %o5 + 0x18 ]
a0080a30:  e2 2b 60 17  stb  %l1, [ %o5 + 0x17 ]
a0080a34:  e2 2b 60 16  stb  %l1, [ %o5 + 0x16 ]
a0080a38:  d8 2f bf 38  stb  %o4, [ %fp + -200 ]
a0080a3c:  d8 2f bf 39  stb  %o4, [ %fp + -199 ]
a0080a40:  d8 2f bf 3a  stb  %o4, [ %fp + -198 ]
a0080a44:  e2 2a e0 03  stb  %l1, [ %o3 + 3 ]
a0080a48:  e2 2a e0 02  stb  %l1, [ %o3 + 2 ]
a0080a4c:  d4 37 bf 30  sth  %o2, [ %fp + -208 ]
a0080a50:  d4 37 bf 32  sth  %o2, [ %fp + -206 ]
a0080a54:  10 80 00 10  b  0xa0080a94
a0080a58:  d4 37 bf 34  sth  %o2, [ %fp + -204 ]
a0080a5c:  82 08 60 ff  and  %g1, 0xff, %g1
a0080a60:  80 a0 60 01  cmp  %g1, 1
a0080a64:  18 80 00 0d  bgu  0xa0080a98
a0080a68:  a4 10 20 00  clr  %l2
a0080a6c:  82 10 20 08  mov  8, %g1
a0080a70:  9a 10 20 0f  mov  0xf, %o5
a0080a74:  c2 2f bf 3b  stb  %g1, [ %fp + -197 ]
a0080a78:  da 37 bf 36  sth  %o5, [ %fp + -202 ]
a0080a7c:  c2 2f bf 38  stb  %g1, [ %fp + -200 ]
a0080a80:  c2 2f bf 39  stb  %g1, [ %fp + -199 ]
a0080a84:  c2 2f bf 3a  stb  %g1, [ %fp + -198 ]
a0080a88:  da 37 bf 30  sth  %o5, [ %fp + -208 ]
a0080a8c:  da 37 bf 32  sth  %o5, [ %fp + -206 ]
a0080a90:  da 37 bf 34  sth  %o5, [ %fp + -204 ]
a0080a94:  a4 10 20 00  clr  %l2
a0080a98:  82 0c a0 ff  and  %l2, 0xff, %g1
a0080a9c:  9a 07 bf f8  add  %fp, -8, %o5
a0080aa0:  92 00 40 01  add  %g1, %g1, %o1
a0080aa4:  15 3f c0 00  sethi  %hi(0xff000000), %o2
a0080aa8:  98 03 40 01  add  %o5, %g1, %o4
a0080aac:  96 02 40 0d  add  %o1, %o5, %o3
a0080ab0:  a4 04 a0 01  inc  %l2
a0080ab4:  80 a0 60 03  cmp  %g1, 3
a0080ab8:  94 12 a0 f0  or  %o2, 0xf0, %o2
a0080abc:  18 80 00 0b  bgu  0xa0080ae8
a0080ac0:  90 0e 20 ff  and  %i0, 0xff, %o0
a0080ac4:  da 0b 3f 40  ldub  [ %o4 + -192 ], %o5
a0080ac8:  d6 12 ff 38  lduh  [ %o3 + -200 ], %o3
a0080acc:  03 28 02 ce  sethi  %hi(0xa00b3800), %g1
a0080ad0:  9a 0b 60 0f  and  %o5, 0xf, %o5
a0080ad4:  97 2a e0 08  sll  %o3, 8, %o3
a0080ad8:  82 10 63 18  or  %g1, 0x318, %g1
a0080adc:  d2 10 40 09  lduh  [ %g1 + %o1 ], %o1
a0080ae0:  40 00 9a 6a  call  0xa00a7488
a0080ae4:  96 13 40 0b  or  %o5, %o3, %o3
a0080ae8:  82 0c a0 ff  and  %l2, 0xff, %g1
a0080aec:  80 a0 60 03  cmp  %g1, 3
a0080af0:  08 bf ff ec  bleu  0xa0080aa0
a0080af4:  9a 07 bf f8  add  %fp, -8, %o5
a0080af8:  a2 0e 20 ff  and  %i0, 0xff, %l1
a0080afc:  21 00 00 08  sethi  %hi(0x2000), %l0
a0080b00:  90 10 20 01  mov  1, %o0
a0080b04:  92 10 20 07  mov  7, %o1
a0080b08:  94 10 00 11  mov  %l1, %o2
a0080b0c:  40 00 9a 46  call  0xa00a7424
a0080b10:  96 14 20 1c  or  %l0, 0x1c, %o3
a0080b14:  25 00 00 09  sethi  %hi(0x2400), %l2
a0080b18:  90 10 20 01  mov  1, %o0
a0080b1c:  92 10 20 07  mov  7, %o1
a0080b20:  94 10 00 11  mov  %l1, %o2
a0080b24:  40 00 9a 40  call  0xa00a7424
a0080b28:  96 14 a0 1c  or  %l2, 0x1c, %o3
a0080b2c:  27 00 00 0a  sethi  %hi(0x2800), %l3
a0080b30:  90 10 20 01  mov  1, %o0
a0080b34:  92 10 20 07  mov  7, %o1
a0080b38:  94 10 00 11  mov  %l1, %o2
a0080b3c:  40 00 9a 3a  call  0xa00a7424
a0080b40:  96 14 e0 1c  or  %l3, 0x1c, %o3
a0080b44:  29 00 00 0c  sethi  %hi(0x3000), %l4
a0080b48:  90 10 20 01  mov  1, %o0
a0080b4c:  92 10 20 07  mov  7, %o1
a0080b50:  94 10 00 11  mov  %l1, %o2
a0080b54:  40 00 9a 34  call  0xa00a7424
a0080b58:  96 15 20 1c  or  %l4, 0x1c, %o3
a0080b5c:  82 0d a0 ff  and  %l6, 0xff, %g1
a0080b60:  80 a0 60 02  cmp  %g1, 2
a0080b64:  18 80 00 16  bgu  0xa0080bbc
a0080b68:  98 0e 60 ff  and  %i1, 0xff, %o4
a0080b6c:  92 14 20 1c  or  %l0, 0x1c, %o1
a0080b70:  90 10 00 11  mov  %l1, %o0
a0080b74:  94 10 3f f9  mov  -7, %o2
a0080b78:  40 00 9a 44  call  0xa00a7488
a0080b7c:  96 10 20 06  mov  6, %o3
a0080b80:  90 10 00 11  mov  %l1, %o0
a0080b84:  92 14 a0 1c  or  %l2, 0x1c, %o1
a0080b88:  94 10 3f f9  mov  -7, %o2
a0080b8c:  40 00 9a 3f  call  0xa00a7488
a0080b90:  96 10 20 06  mov  6, %o3
a0080b94:  90 10 00 11  mov  %l1, %o0
a0080b98:  92 14 e0 1c  or  %l3, 0x1c, %o1
a0080b9c:  94 10 3f f9  mov  -7, %o2
a0080ba0:  40 00 9a 3a  call  0xa00a7488
a0080ba4:  96 10 20 06  mov  6, %o3
a0080ba8:  90 10 00 11  mov  %l1, %o0
a0080bac:  92 15 20 1c  or  %l4, 0x1c, %o1
a0080bb0:  94 10 3f f9  mov  -7, %o2
a0080bb4:  10 80 00 20  b  0xa0080c34
a0080bb8:  96 10 20 06  mov  6, %o3
a0080bbc:  82 1b 20 01  xor  %o4, 1, %g1
a0080bc0:  80 a0 00 01  cmp  %g0, %g1
a0080bc4:  9a 60 3f ff  subx  %g0, -1, %o5
a0080bc8:  82 1b 20 03  xor  %o4, 3, %g1
a0080bcc:  80 a0 00 01  cmp  %g0, %g1
a0080bd0:  82 60 3f ff  subx  %g0, -1, %g1
a0080bd4:  80 93 40 01  orcc  %o5, %g1, %g0
a0080bd8:  12 80 00 04  bne  0xa0080be8
a0080bdc:  80 a3 20 02  cmp  %o4, 2
a0080be0:  32 80 00 17  bne,a   0xa0080c3c
a0080be4:  a4 0e 60 ff  and  %i1, 0xff, %l2
a0080be8:  92 14 20 1c  or  %l0, 0x1c, %o1
a0080bec:  90 10 00 11  mov  %l1, %o0
a0080bf0:  94 10 3f f9  mov  -7, %o2
a0080bf4:  40 00 9a 25  call  0xa00a7488
a0080bf8:  96 10 20 04  mov  4, %o3
a0080bfc:  90 10 00 11  mov  %l1, %o0
a0080c00:  92 14 a0 1c  or  %l2, 0x1c, %o1
a0080c04:  94 10 3f f9  mov  -7, %o2
a0080c08:  40 00 9a 20  call  0xa00a7488
a0080c0c:  96 10 20 04  mov  4, %o3
a0080c10:  90 10 00 11  mov  %l1, %o0
a0080c14:  92 14 e0 1c  or  %l3, 0x1c, %o1
a0080c18:  94 10 3f f9  mov  -7, %o2
a0080c1c:  40 00 9a 1b  call  0xa00a7488
a0080c20:  96 10 20 04  mov  4, %o3
a0080c24:  90 10 00 11  mov  %l1, %o0
a0080c28:  92 15 20 1c  or  %l4, 0x1c, %o1
a0080c2c:  94 10 3f f9  mov  -7, %o2
a0080c30:  96 10 20 04  mov  4, %o3
a0080c34:  40 00 9a 15  call  0xa00a7488
a0080c38:  a4 0e 60 ff  and  %i1, 0xff, %l2
a0080c3c:  80 a4 a0 06  cmp  %l2, 6
a0080c40:  12 80 00 0e  bne  0xa0080c78
a0080c44:  21 00 00 0d  sethi  %hi(0x3400), %l0
a0080c48:  90 10 00 11  mov  %l1, %o0
a0080c4c:  92 14 22 14  or  %l0, 0x214, %o1
a0080c50:  94 10 3f 00  mov  -256, %o2
a0080c54:  40 00 9a 0d  call  0xa00a7488
a0080c58:  96 10 20 55  mov  0x55, %o3
a0080c5c:  15 3f ff c0  sethi  %hi(0xffff0000), %o2
a0080c60:  17 00 00 15  sethi  %hi(0x5400), %o3
a0080c64:  90 10 00 11  mov  %l1, %o0
a0080c68:  92 14 22 14  or  %l0, 0x214, %o1
a0080c6c:  94 12 a0 ff  or  %o2, 0xff, %o2
a0080c70:  10 80 00 0c  b  0xa0080ca0
a0080c74:  96 12 e1 00  or  %o3, 0x100, %o3
a0080c78:  90 10 00 11  mov  %l1, %o0
a0080c7c:  92 14 22 14  or  %l0, 0x214, %o1
a0080c80:  94 10 3f 00  mov  -256, %o2
a0080c84:  40 00 9a 01  call  0xa00a7488
a0080c88:  96 10 20 00  clr  %o3
a0080c8c:  15 3f ff c0  sethi  %hi(0xffff0000), %o2
a0080c90:  90 10 00 11  mov  %l1, %o0
a0080c94:  92 14 22 14  or  %l0, 0x214, %o1
a0080c98:  94 12 a0 ff  or  %o2, 0xff, %o2
a0080c9c:  96 10 20 00  clr  %o3
a0080ca0:  40 00 99 fa  call  0xa00a7488
a0080ca4:  01 00 00 00  nop
a0080ca8:  82 0f 20 ff  and  %i4, 0xff, %g1
a0080cac:  80 a0 60 04  cmp  %g1, 4
a0080cb0:  18 80 00 08  bgu  0xa0080cd0
a0080cb4:  80 a4 a0 01  cmp  %l2, 1
a0080cb8:  13 00 00 0b  sethi  %hi(0x2c00), %o1
a0080cbc:  92 12 63 44  or  %o1, 0x344, %o1	! 0x2f44
a0080cc0:  90 0e 20 ff  and  %i0, 0xff, %o0
a0080cc4:  94 10 3f c0  mov  -64, %o2
a0080cc8:  10 80 00 09  b  0xa0080cec
a0080ccc:  96 10 20 3f  mov  0x3f, %o3
a0080cd0:  12 80 00 09  bne  0xa0080cf4
a0080cd4:  ba 0e 60 ff  and  %i1, 0xff, %i5
a0080cd8:  13 00 00 0b  sethi  %hi(0x2c00), %o1
a0080cdc:  92 12 63 44  or  %o1, 0x344, %o1	! 0x2f44
a0080ce0:  90 0e 20 ff  and  %i0, 0xff, %o0
a0080ce4:  94 10 3f c0  mov  -64, %o2
a0080ce8:  96 10 20 1f  mov  0x1f, %o3
a0080cec:  40 00 99 e7  call  0xa00a7488
a0080cf0:  ba 0e 60 ff  and  %i1, 0xff, %i5
a0080cf4:  80 a7 60 06  cmp  %i5, 6
a0080cf8:  12 80 00 33  bne  0xa0080dc4
a0080cfc:  82 0d a0 ff  and  %l6, 0xff, %g1
a0080d00:  a0 0e 20 ff  and  %i0, 0xff, %l0
a0080d04:  23 00 00 0d  sethi  %hi(0x3400), %l1
a0080d08:  27 00 00 0f  sethi  %hi(0x3c00), %l3
a0080d0c:  92 14 62 0c  or  %l1, 0x20c, %o1
a0080d10:  90 10 00 10  mov  %l0, %o0
a0080d14:  96 14 e3 d0  or  %l3, 0x3d0, %o3
a0080d18:  40 00 99 dc  call  0xa00a7488
a0080d1c:  15 3f ff c0  sethi  %hi(0xffff0000), %o2
a0080d20:  25 00 00 3f  sethi  %hi(0xfc00), %l2
a0080d24:  92 14 62 0c  or  %l1, 0x20c, %o1
a0080d28:  90 10 00 10  mov  %l0, %o0
a0080d2c:  94 14 a3 ff  or  %l2, 0x3ff, %o2
a0080d30:  40 00 99 d6  call  0xa00a7488
a0080d34:  17 0f f4 00  sethi  %hi(0x3fd00000), %o3
a0080d38:  92 14 62 10  or  %l1, 0x210, %o1
a0080d3c:  90 10 00 10  mov  %l0, %o0
a0080d40:  96 14 e3 d0  or  %l3, 0x3d0, %o3
a0080d44:  40 00 99 d1  call  0xa00a7488
a0080d48:  15 3f ff c0  sethi  %hi(0xffff0000), %o2
a0080d4c:  92 14 62 10  or  %l1, 0x210, %o1
a0080d50:  90 10 00 10  mov  %l0, %o0
a0080d54:  94 14 a3 ff  or  %l2, 0x3ff, %o2
a0080d58:  40 00 99 cc  call  0xa00a7488
a0080d5c:  17 0f f4 00  sethi  %hi(0x3fd00000), %o3
a0080d60:  23 3f f3 ff  sethi  %hi(0xffcffc00), %l1
a0080d64:  13 00 00 08  sethi  %hi(0x2000), %o1
a0080d68:  90 10 00 10  mov  %l0, %o0
a0080d6c:  92 12 60 20  or  %o1, 0x20, %o1
a0080d70:  94 14 63 ff  or  %l1, 0x3ff, %o2
a0080d74:  40 00 99 c5  call  0xa00a7488
a0080d78:  17 00 0c 00  sethi  %hi(0x300000), %o3
a0080d7c:  13 00 00 09  sethi  %hi(0x2400), %o1
a0080d80:  90 10 00 10  mov  %l0, %o0
a0080d84:  92 12 60 20  or  %o1, 0x20, %o1
a0080d88:  94 14 63 ff  or  %l1, 0x3ff, %o2
a0080d8c:  40 00 99 bf  call  0xa00a7488
a0080d90:  17 00 0c 00  sethi  %hi(0x300000), %o3
a0080d94:  13 00 00 0a  sethi  %hi(0x2800), %o1
a0080d98:  90 10 00 10  mov  %l0, %o0
a0080d9c:  92 12 60 20  or  %o1, 0x20, %o1
a0080da0:  94 14 63 ff  or  %l1, 0x3ff, %o2
a0080da4:  40 00 99 b9  call  0xa00a7488
a0080da8:  17 00 0c 00  sethi  %hi(0x300000), %o3
a0080dac:  13 00 00 0c  sethi  %hi(0x3000), %o1
a0080db0:  90 10 00 10  mov  %l0, %o0
a0080db4:  92 12 60 20  or  %o1, 0x20, %o1
a0080db8:  94 14 63 ff  or  %l1, 0x3ff, %o2
a0080dbc:  10 80 00 4a  b  0xa0080ee4
a0080dc0:  17 00 0c 00  sethi  %hi(0x300000), %o3
a0080dc4:  80 a0 60 01  cmp  %g1, 1
a0080dc8:  18 80 00 18  bgu  0xa0080e28
a0080dcc:  a6 0e 20 ff  and  %i0, 0xff, %l3
a0080dd0:  21 00 00 0d  sethi  %hi(0x3400), %l0
a0080dd4:  90 10 00 13  mov  %l3, %o0
a0080dd8:  92 14 22 0c  or  %l0, 0x20c, %o1
a0080ddc:  15 3f ff c0  sethi  %hi(0xffff0000), %o2
a0080de0:  40 00 99 aa  call  0xa00a7488
a0080de4:  96 10 23 d0  mov  0x3d0, %o3
a0080de8:  23 00 00 3f  sethi  %hi(0xfc00), %l1
a0080dec:  90 10 00 13  mov  %l3, %o0
a0080df0:  92 14 22 0c  or  %l0, 0x20c, %o1
a0080df4:  94 14 63 ff  or  %l1, 0x3ff, %o2
a0080df8:  40 00 99 a4  call  0xa00a7488
a0080dfc:  17 00 f4 00  sethi  %hi(0x3d00000), %o3
a0080e00:  90 10 00 13  mov  %l3, %o0
a0080e04:  92 14 22 10  or  %l0, 0x210, %o1
a0080e08:  15 3f ff c0  sethi  %hi(0xffff0000), %o2
a0080e0c:  40 00 99 9f  call  0xa00a7488
a0080e10:  96 10 23 d0  mov  0x3d0, %o3
a0080e14:  90 10 00 13  mov  %l3, %o0
a0080e18:  92 14 22 10  or  %l0, 0x210, %o1
a0080e1c:  94 14 63 ff  or  %l1, 0x3ff, %o2
a0080e20:  10 80 00 18  b  0xa0080e80
a0080e24:  17 00 f4 00  sethi  %hi(0x3d00000), %o3
a0080e28:  21 00 00 0d  sethi  %hi(0x3400), %l0
a0080e2c:  25 00 00 20  sethi  %hi(0x8000), %l2
a0080e30:  90 10 00 13  mov  %l3, %o0
a0080e34:  92 14 22 0c  or  %l0, 0x20c, %o1
a0080e38:  15 3f ff c0  sethi  %hi(0xffff0000), %o2
a0080e3c:  40 00 99 93  call  0xa00a7488
a0080e40:  96 14 a3 d0  or  %l2, 0x3d0, %o3
a0080e44:  23 00 00 3f  sethi  %hi(0xfc00), %l1
a0080e48:  90 10 00 13  mov  %l3, %o0
a0080e4c:  92 14 22 0c  or  %l0, 0x20c, %o1
a0080e50:  94 14 63 ff  or  %l1, 0x3ff, %o2
a0080e54:  40 00 99 8d  call  0xa00a7488
a0080e58:  17 20 f4 00  sethi  %hi(0x83d00000), %o3
a0080e5c:  90 10 00 13  mov  %l3, %o0
a0080e60:  96 14 a3 d0  or  %l2, 0x3d0, %o3
a0080e64:  92 14 22 10  or  %l0, 0x210, %o1
a0080e68:  40 00 99 88  call  0xa00a7488
a0080e6c:  15 3f ff c0  sethi  %hi(0xffff0000), %o2
a0080e70:  90 10 00 13  mov  %l3, %o0
a0080e74:  92 14 22 10  or  %l0, 0x210, %o1
a0080e78:  94 14 63 ff  or  %l1, 0x3ff, %o2
a0080e7c:  17 20 f4 00  sethi  %hi(0x83d00000), %o3
a0080e80:  40 00 99 82  call  0xa00a7488
a0080e84:  21 3f f3 ff  sethi  %hi(0xffcffc00), %l0
a0080e88:  13 00 00 08  sethi  %hi(0x2000), %o1
a0080e8c:  90 10 00 13  mov  %l3, %o0
a0080e90:  92 12 60 20  or  %o1, 0x20, %o1
a0080e94:  94 14 23 ff  or  %l0, 0x3ff, %o2
a0080e98:  40 00 99 7c  call  0xa00a7488
a0080e9c:  17 00 04 00  sethi  %hi(0x100000), %o3
a0080ea0:  13 00 00 09  sethi  %hi(0x2400), %o1
a0080ea4:  90 10 00 13  mov  %l3, %o0
a0080ea8:  92 12 60 20  or  %o1, 0x20, %o1
a0080eac:  94 14 23 ff  or  %l0, 0x3ff, %o2
a0080eb0:  40 00 99 76  call  0xa00a7488
a0080eb4:  17 00 04 00  sethi  %hi(0x100000), %o3
a0080eb8:  13 00 00 0a  sethi  %hi(0x2800), %o1
a0080ebc:  90 10 00 13  mov  %l3, %o0
a0080ec0:  92 12 60 20  or  %o1, 0x20, %o1
a0080ec4:  94 14 23 ff  or  %l0, 0x3ff, %o2
a0080ec8:  40 00 99 70  call  0xa00a7488
a0080ecc:  17 00 04 00  sethi  %hi(0x100000), %o3
a0080ed0:  13 00 00 0c  sethi  %hi(0x3000), %o1
a0080ed4:  90 10 00 13  mov  %l3, %o0
a0080ed8:  92 12 60 20  or  %o1, 0x20, %o1
a0080edc:  94 14 23 ff  or  %l0, 0x3ff, %o2
a0080ee0:  17 00 04 00  sethi  %hi(0x100000), %o3
a0080ee4:  40 00 99 69  call  0xa00a7488
a0080ee8:  aa 0e 20 ff  and  %i0, 0xff, %l5
a0080eec:  23 3f ff c0  sethi  %hi(0xffff0000), %l1
a0080ef0:  2d 00 00 08  sethi  %hi(0x2000), %l6
a0080ef4:  90 10 00 15  mov  %l5, %o0
a0080ef8:  92 15 a3 c0  or  %l6, 0x3c0, %o1
a0080efc:  94 14 60 ff  or  %l1, 0xff, %o2
a0080f00:  40 00 99 62  call  0xa00a7488
a0080f04:  17 00 00 14  sethi  %hi(0x5000), %o3
a0080f08:  29 00 00 09  sethi  %hi(0x2400), %l4
a0080f0c:  90 10 00 15  mov  %l5, %o0
a0080f10:  92 15 23 c0  or  %l4, 0x3c0, %o1
a0080f14:  94 14 60 ff  or  %l1, 0xff, %o2
a0080f18:  40 00 99 5c  call  0xa00a7488
a0080f1c:  17 00 00 04  sethi  %hi(0x1000), %o3
a0080f20:  27 00 00 0a  sethi  %hi(0x2800), %l3
a0080f24:  90 10 00 15  mov  %l5, %o0
a0080f28:  92 14 e3 c0  or  %l3, 0x3c0, %o1
a0080f2c:  94 14 60 ff  or  %l1, 0xff, %o2
a0080f30:  40 00 99 56  call  0xa00a7488
a0080f34:  17 00 00 04  sethi  %hi(0x1000), %o3
a0080f38:  25 00 00 0c  sethi  %hi(0x3000), %l2
a0080f3c:  90 10 00 15  mov  %l5, %o0
a0080f40:  92 14 a3 c0  or  %l2, 0x3c0, %o1
a0080f44:  94 14 60 ff  or  %l1, 0xff, %o2
a0080f48:  40 00 99 50  call  0xa00a7488
a0080f4c:  17 00 00 04  sethi  %hi(0x1000), %o3
a0080f50:  21 00 00 0d  sethi  %hi(0x3400), %l0
a0080f54:  15 3f c0 3f  sethi  %hi(0xff00fc00), %o2
a0080f58:  90 10 00 15  mov  %l5, %o0
a0080f5c:  94 12 a3 ff  or  %o2, 0x3ff, %o2
a0080f60:  92 14 22 14  or  %l0, 0x214, %o1
a0080f64:  40 00 99 49  call  0xa00a7488
a0080f68:  17 00 1f 00  sethi  %hi(0x7c0000), %o3
a0080f6c:  2f 00 3f ff  sethi  %hi(0xfffc00), %l7
a0080f70:  90 10 00 15  mov  %l5, %o0
a0080f74:  92 14 22 14  or  %l0, 0x214, %o1
a0080f78:  94 15 e3 ff  or  %l7, 0x3ff, %o2
a0080f7c:  40 00 99 43  call  0xa00a7488
a0080f80:  17 3f c0 00  sethi  %hi(0xff000000), %o3
a0080f84:  90 10 00 15  mov  %l5, %o0
a0080f88:  92 14 22 18  or  %l0, 0x218, %o1
a0080f8c:  94 10 3f 00  mov  -256, %o2
a0080f90:  40 00 99 3e  call  0xa00a7488
a0080f94:  96 10 20 ff  mov  0xff, %o3
a0080f98:  90 10 00 15  mov  %l5, %o0
a0080f9c:  92 14 22 20  or  %l0, 0x220, %o1
a0080fa0:  94 10 3f 00  mov  -256, %o2
a0080fa4:  40 00 99 39  call  0xa00a7488
a0080fa8:  96 10 20 00  clr  %o3
a0080fac:  90 10 00 15  mov  %l5, %o0
a0080fb0:  94 14 60 ff  or  %l1, 0xff, %o2
a0080fb4:  92 14 22 20  or  %l0, 0x220, %o1
a0080fb8:  40 00 99 34  call  0xa00a7488
a0080fbc:  96 10 21 00  mov  0x100, %o3
a0080fc0:  90 10 00 15  mov  %l5, %o0
a0080fc4:  92 15 a0 20  or  %l6, 0x20, %o1
a0080fc8:  94 15 e3 ff  or  %l7, 0x3ff, %o2
a0080fcc:  40 00 99 2f  call  0xa00a7488
a0080fd0:  17 28 80 00  sethi  %hi(0xa2000000), %o3
a0080fd4:  90 10 20 01  mov  1, %o0
a0080fd8:  92 10 20 10  mov  0x10, %o1
a0080fdc:  94 10 00 15  mov  %l5, %o2
a0080fe0:  40 00 99 11  call  0xa00a7424
a0080fe4:  96 15 a0 04  or  %l6, 4, %o3
a0080fe8:  96 15 20 04  or  %l4, 4, %o3
a0080fec:  90 10 20 01  mov  1, %o0
a0080ff0:  92 10 20 10  mov  0x10, %o1
a0080ff4:  40 00 99 0c  call  0xa00a7424
a0080ff8:  94 10 00 15  mov  %l5, %o2
a0080ffc:  96 14 e0 04  or  %l3, 4, %o3
a0081000:  90 10 20 01  mov  1, %o0
a0081004:  92 10 20 10  mov  0x10, %o1
a0081008:  40 00 99 07  call  0xa00a7424
a008100c:  94 10 00 15  mov  %l5, %o2
a0081010:  96 14 a0 04  or  %l2, 4, %o3
a0081014:  90 10 20 01  mov  1, %o0
a0081018:  92 10 20 10  mov  0x10, %o1
a008101c:  40 00 99 02  call  0xa00a7424
a0081020:  94 10 00 15  mov  %l5, %o2
a0081024:  90 10 20 01  mov  1, %o0
a0081028:  92 10 20 00  clr  %o1
a008102c:  94 10 00 15  mov  %l5, %o2
a0081030:  40 00 98 fd  call  0xa00a7424
a0081034:  96 14 22 00  or  %l0, 0x200, %o3
a0081038:  92 10 20 01  mov  1, %o1
a008103c:  94 10 00 15  mov  %l5, %o2
a0081040:  96 14 22 00  or  %l0, 0x200, %o3
a0081044:  40 00 98 f8  call  0xa00a7424
a0081048:  90 10 20 01  mov  1, %o0
a008104c:  7f ff d0 c5  call  0xa0075360
a0081050:  90 10 00 15  mov  %l5, %o0
a0081054:  90 10 20 01  mov  1, %o0
a0081058:  92 10 20 10  mov  0x10, %o1
a008105c:  94 10 00 15  mov  %l5, %o2
a0081060:  40 00 98 f1  call  0xa00a7424
a0081064:  96 14 22 1c  or  %l0, 0x21c, %o3
a0081068:  90 10 20 01  mov  1, %o0
a008106c:  92 10 20 11  mov  0x11, %o1
a0081070:  94 10 00 15  mov  %l5, %o2
a0081074:  40 00 98 ec  call  0xa00a7424
a0081078:  96 14 22 1c  or  %l0, 0x21c, %o3
a008107c:  90 10 20 01  mov  1, %o0
a0081080:  92 10 20 12  mov  0x12, %o1
a0081084:  94 10 00 15  mov  %l5, %o2
a0081088:  40 00 98 e7  call  0xa00a7424
a008108c:  96 14 22 1c  or  %l0, 0x21c, %o3
a0081090:  15 3f e3 ff  sethi  %hi(0xff8ffc00), %o2
a0081094:  90 10 00 15  mov  %l5, %o0
a0081098:  92 14 22 1c  or  %l0, 0x21c, %o1
a008109c:  94 12 a3 ff  or  %o2, 0x3ff, %o2
a00810a0:  40 00 98 fa  call  0xa00a7488
a00810a4:  17 00 18 00  sethi  %hi(0x600000), %o3
a00810a8:  82 06 7f fc  add  %i1, -4, %g1
a00810ac:  82 08 60 ff  and  %g1, 0xff, %g1
a00810b0:  80 a0 60 02  cmp  %g1, 2
a00810b4:  18 80 00 0c  bgu  0xa00810e4
a00810b8:  da 07 bf 1c  ld  [ %fp + -228 ], %o5
a00810bc:  90 10 00 15  mov  %l5, %o0
a00810c0:  92 15 a0 28  or  %l6, 0x28, %o1
a00810c4:  94 15 e3 ff  or  %l7, 0x3ff, %o2
a00810c8:  40 00 98 f0  call  0xa00a7488
a00810cc:  17 0c 40 00  sethi  %hi(0x31000000), %o3
a00810d0:  90 10 00 15  mov  %l5, %o0
a00810d4:  92 15 a0 08  or  %l6, 8, %o1
a00810d8:  94 15 e3 ff  or  %l7, 0x3ff, %o2
a00810dc:  10 80 00 0f  b  0xa0081118
a00810e0:  17 0e 80 00  sethi  %hi(0x3a000000), %o3
a00810e4:  82 0b 60 ff  and  %o5, 0xff, %g1
a00810e8:  80 a0 60 02  cmp  %g1, 2
a00810ec:  18 80 00 0d  bgu  0xa0081120
a00810f0:  21 00 00 08  sethi  %hi(0x2000), %l0
a00810f4:  90 10 00 15  mov  %l5, %o0
a00810f8:  92 15 a0 28  or  %l6, 0x28, %o1
a00810fc:  94 15 e3 ff  or  %l7, 0x3ff, %o2
a0081100:  40 00 98 e2  call  0xa00a7488
a0081104:  17 0c 00 00  sethi  %hi(0x30000000), %o3
a0081108:  90 10 00 15  mov  %l5, %o0
a008110c:  92 15 a0 08  or  %l6, 8, %o1
a0081110:  94 15 e3 ff  or  %l7, 0x3ff, %o2
a0081114:  17 0e c0 00  sethi  %hi(0x3b000000), %o3
a0081118:  40 00 98 dc  call  0xa00a7488
a008111c:  21 00 00 08  sethi  %hi(0x2000), %l0
a0081120:  90 10 20 01  mov  1, %o0
a0081124:  92 10 20 08  mov  8, %o1
a0081128:  94 10 00 15  mov  %l5, %o2
a008112c:  40 00 98 be  call  0xa00a7424
a0081130:  96 14 20 0c  or  %l0, 0xc, %o3
a0081134:  80 a7 60 01  cmp  %i5, 1
a0081138:  12 80 00 07  bne  0xa0081154
a008113c:  82 0f 20 ff  and  %i4, 0xff, %g1
a0081140:  92 14 20 0c  or  %l0, 0xc, %o1
a0081144:  90 10 00 15  mov  %l5, %o0
a0081148:  94 10 39 ff  mov  -1537, %o2
a008114c:  10 80 00 0c  b  0xa008117c
a0081150:  96 10 24 00  mov  0x400, %o3
a0081154:  80 a0 60 01  cmp  %g1, 1
a0081158:  18 80 00 06  bgu  0xa0081170
a008115c:  92 14 20 0c  or  %l0, 0xc, %o1
a0081160:  90 10 00 15  mov  %l5, %o0
a0081164:  94 10 39 ff  mov  -1537, %o2
a0081168:  10 80 00 05  b  0xa008117c
a008116c:  96 10 22 00  mov  0x200, %o3
a0081170:  90 10 00 15  mov  %l5, %o0
a0081174:  94 10 39 ff  mov  -1537, %o2
a0081178:  96 10 20 00  clr  %o3
a008117c:  40 00 98 c3  call  0xa00a7488
a0081180:  23 00 00 08  sethi  %hi(0x2000), %l1
a0081184:  15 3f c0 3f  sethi  %hi(0xff00fc00), %o2
a0081188:  94 12 a3 ff  or  %o2, 0x3ff, %o2	! 0xff00ffff
a008118c:  90 10 00 15  mov  %l5, %o0
a0081190:  92 14 60 34  or  %l1, 0x34, %o1
a0081194:  40 00 98 bd  call  0xa00a7488
a0081198:  17 00 3c 00  sethi  %hi(0xf00000), %o3
a008119c:  80 a7 60 01  cmp  %i5, 1
a00811a0:  12 80 00 19  bne  0xa0081204
a00811a4:  21 3f c3 ff  sethi  %hi(0xff0ffc00), %l0
a00811a8:  92 14 60 14  or  %l1, 0x14, %o1
a00811ac:  90 10 00 15  mov  %l5, %o0
a00811b0:  94 14 23 ff  or  %l0, 0x3ff, %o2
a00811b4:  40 00 98 b5  call  0xa00a7488
a00811b8:  17 00 20 00  sethi  %hi(0x800000), %o3
a00811bc:  13 00 00 09  sethi  %hi(0x2400), %o1
a00811c0:  90 10 00 15  mov  %l5, %o0
a00811c4:  92 12 60 14  or  %o1, 0x14, %o1
a00811c8:  94 14 23 ff  or  %l0, 0x3ff, %o2
a00811cc:  40 00 98 af  call  0xa00a7488
a00811d0:  17 00 20 00  sethi  %hi(0x800000), %o3
a00811d4:  13 00 00 0a  sethi  %hi(0x2800), %o1
a00811d8:  90 10 00 15  mov  %l5, %o0
a00811dc:  92 12 60 14  or  %o1, 0x14, %o1
a00811e0:  94 14 23 ff  or  %l0, 0x3ff, %o2
a00811e4:  40 00 98 a9  call  0xa00a7488
a00811e8:  17 00 20 00  sethi  %hi(0x800000), %o3
a00811ec:  13 00 00 0c  sethi  %hi(0x3000), %o1
a00811f0:  90 10 00 15  mov  %l5, %o0
a00811f4:  92 12 60 14  or  %o1, 0x14, %o1
a00811f8:  94 14 23 ff  or  %l0, 0x3ff, %o2
a00811fc:  10 80 00 18  b  0xa008125c
a0081200:  17 00 20 00  sethi  %hi(0x800000), %o3
a0081204:  92 14 60 14  or  %l1, 0x14, %o1
a0081208:  90 10 00 15  mov  %l5, %o0
a008120c:  94 14 23 ff  or  %l0, 0x3ff, %o2
a0081210:  40 00 98 9e  call  0xa00a7488
a0081214:  17 00 3c 00  sethi  %hi(0xf00000), %o3
a0081218:  13 00 00 09  sethi  %hi(0x2400), %o1
a008121c:  90 10 00 15  mov  %l5, %o0
a0081220:  92 12 60 14  or  %o1, 0x14, %o1
a0081224:  94 14 23 ff  or  %l0, 0x3ff, %o2
a0081228:  40 00 98 98  call  0xa00a7488
a008122c:  17 00 3c 00  sethi  %hi(0xf00000), %o3
a0081230:  13 00 00 0a  sethi  %hi(0x2800), %o1
a0081234:  90 10 00 15  mov  %l5, %o0
a0081238:  92 12 60 14  or  %o1, 0x14, %o1
a008123c:  94 14 23 ff  or  %l0, 0x3ff, %o2
a0081240:  40 00 98 92  call  0xa00a7488
a0081244:  17 00 3c 00  sethi  %hi(0xf00000), %o3
a0081248:  13 00 00 0c  sethi  %hi(0x3000), %o1
a008124c:  90 10 00 15  mov  %l5, %o0
a0081250:  92 12 60 14  or  %o1, 0x14, %o1
a0081254:  94 14 23 ff  or  %l0, 0x3ff, %o2
a0081258:  17 00 3c 00  sethi  %hi(0xf00000), %o3
a008125c:  40 00 98 8b  call  0xa00a7488
a0081260:  ac 06 7f fe  add  %i1, -2, %l6
a0081264:  82 0d a0 ff  and  %l6, 0xff, %g1
a0081268:  80 a0 60 04  cmp  %g1, 4
a008126c:  18 80 00 06  bgu  0xa0081284
a0081270:  17 00 00 0d  sethi  %hi(0x3400), %o3
a0081274:  94 10 00 15  mov  %l5, %o2
a0081278:  96 12 e2 00  or  %o3, 0x200, %o3
a008127c:  10 80 00 05  b  0xa0081290
a0081280:  90 10 20 01  mov  1, %o0
a0081284:  94 10 00 15  mov  %l5, %o2
a0081288:  96 12 e2 00  or  %o3, 0x200, %o3
a008128c:  90 10 20 00  clr  %o0
a0081290:  40 00 98 65  call  0xa00a7424
a0081294:  92 10 20 08  mov  8, %o1
a0081298:  aa 0e 20 ff  and  %i0, 0xff, %l5
a008129c:  13 00 00 0d  sethi  %hi(0x3400), %o1
a00812a0:  15 3f ff c0  sethi  %hi(0xffff0000), %o2
a00812a4:  92 12 61 34  or  %o1, 0x134, %o1
a00812a8:  94 12 a0 ff  or  %o2, 0xff, %o2
a00812ac:  90 10 00 15  mov  %l5, %o0
a00812b0:  40 00 98 76  call  0xa00a7488
a00812b4:  17 00 00 38  sethi  %hi(0xe000), %o3
a00812b8:  82 06 7f ff  add  %i1, -1, %g1
a00812bc:  c2 27 bf 18  st  %g1, [ %fp + -232 ]
a00812c0:  82 08 60 ff  and  %g1, 0xff, %g1
a00812c4:  80 a0 60 02  cmp  %g1, 2
a00812c8:  18 80 00 43  bgu  0xa00813d4
a00812cc:  29 00 00 08  sethi  %hi(0x2000), %l4
a00812d0:  94 10 00 15  mov  %l5, %o2
a00812d4:  96 15 20 14  or  %l4, 0x14, %o3
a00812d8:  90 10 20 01  mov  1, %o0
a00812dc:  40 00 98 52  call  0xa00a7424
a00812e0:  92 10 20 11  mov  0x11, %o1
a00812e4:  27 00 00 09  sethi  %hi(0x2400), %l3
a00812e8:  94 10 00 15  mov  %l5, %o2
a00812ec:  96 14 e0 14  or  %l3, 0x14, %o3
a00812f0:  90 10 20 01  mov  1, %o0
a00812f4:  40 00 98 4c  call  0xa00a7424
a00812f8:  92 10 20 11  mov  0x11, %o1
a00812fc:  25 00 00 0a  sethi  %hi(0x2800), %l2
a0081300:  94 10 00 15  mov  %l5, %o2
a0081304:  96 14 a0 14  or  %l2, 0x14, %o3
a0081308:  90 10 20 01  mov  1, %o0
a008130c:  40 00 98 46  call  0xa00a7424
a0081310:  92 10 20 11  mov  0x11, %o1
a0081314:  23 00 00 0c  sethi  %hi(0x3000), %l1
a0081318:  94 10 00 15  mov  %l5, %o2
a008131c:  96 14 60 14  or  %l1, 0x14, %o3
a0081320:  90 10 20 01  mov  1, %o0
a0081324:  40 00 98 40  call  0xa00a7424
a0081328:  92 10 20 11  mov  0x11, %o1
a008132c:  21 3f e7 ff  sethi  %hi(0xff9ffc00), %l0
a0081330:  94 14 23 ff  or  %l0, 0x3ff, %o2	! 0xff9fffff
a0081334:  90 10 00 15  mov  %l5, %o0
a0081338:  92 15 20 18  or  %l4, 0x18, %o1
a008133c:  40 00 98 53  call  0xa00a7488
a0081340:  17 00 08 00  sethi  %hi(0x200000), %o3
a0081344:  94 14 23 ff  or  %l0, 0x3ff, %o2
a0081348:  90 10 00 15  mov  %l5, %o0
a008134c:  92 14 e0 18  or  %l3, 0x18, %o1
a0081350:  40 00 98 4e  call  0xa00a7488
a0081354:  17 00 08 00  sethi  %hi(0x200000), %o3
a0081358:  94 14 23 ff  or  %l0, 0x3ff, %o2
a008135c:  90 10 00 15  mov  %l5, %o0
a0081360:  92 14 a0 18  or  %l2, 0x18, %o1
a0081364:  40 00 98 49  call  0xa00a7488
a0081368:  17 00 08 00  sethi  %hi(0x200000), %o3
a008136c:  94 14 23 ff  or  %l0, 0x3ff, %o2
a0081370:  90 10 00 15  mov  %l5, %o0
a0081374:  92 14 60 18  or  %l1, 0x18, %o1
a0081378:  40 00 98 44  call  0xa00a7488
a008137c:  17 00 08 00  sethi  %hi(0x200000), %o3
a0081380:  21 3f ff e7  sethi  %hi(0xffff9c00), %l0
a0081384:  90 10 00 15  mov  %l5, %o0
a0081388:  92 15 20 18  or  %l4, 0x18, %o1
a008138c:  94 14 23 ff  or  %l0, 0x3ff, %o2
a0081390:  40 00 98 3e  call  0xa00a7488
a0081394:  96 10 20 00  clr  %o3
a0081398:  90 10 00 15  mov  %l5, %o0
a008139c:  92 14 e0 18  or  %l3, 0x18, %o1
a00813a0:  94 14 23 ff  or  %l0, 0x3ff, %o2
a00813a4:  40 00 98 39  call  0xa00a7488
a00813a8:  96 10 20 00  clr  %o3
a00813ac:  90 10 00 15  mov  %l5, %o0
a00813b0:  92 14 a0 18  or  %l2, 0x18, %o1
a00813b4:  94 14 23 ff  or  %l0, 0x3ff, %o2
a00813b8:  40 00 98 34  call  0xa00a7488
a00813bc:  96 10 20 00  clr  %o3
a00813c0:  90 10 00 15  mov  %l5, %o0
a00813c4:  92 14 60 18  or  %l1, 0x18, %o1
a00813c8:  94 14 23 ff  or  %l0, 0x3ff, %o2
a00813cc:  10 80 00 42  b  0xa00814d4
a00813d0:  96 10 20 00  clr  %o3
a00813d4:  90 10 20 00  clr  %o0
a00813d8:  92 10 20 11  mov  0x11, %o1
a00813dc:  94 10 00 15  mov  %l5, %o2
a00813e0:  40 00 98 11  call  0xa00a7424
a00813e4:  96 15 20 14  or  %l4, 0x14, %o3
a00813e8:  27 00 00 09  sethi  %hi(0x2400), %l3
a00813ec:  90 10 20 00  clr  %o0
a00813f0:  92 10 20 11  mov  0x11, %o1
a00813f4:  94 10 00 15  mov  %l5, %o2
a00813f8:  40 00 98 0b  call  0xa00a7424
a00813fc:  96 14 e0 14  or  %l3, 0x14, %o3
a0081400:  25 00 00 0a  sethi  %hi(0x2800), %l2
a0081404:  90 10 20 00  clr  %o0
a0081408:  92 10 20 11  mov  0x11, %o1
a008140c:  94 10 00 15  mov  %l5, %o2
a0081410:  40 00 98 05  call  0xa00a7424
a0081414:  96 14 a0 14  or  %l2, 0x14, %o3
a0081418:  23 00 00 0c  sethi  %hi(0x3000), %l1
a008141c:  90 10 20 00  clr  %o0
a0081420:  92 10 20 11  mov  0x11, %o1
a0081424:  94 10 00 15  mov  %l5, %o2
a0081428:  40 00 97 ff  call  0xa00a7424
a008142c:  96 14 60 14  or  %l1, 0x14, %o3
a0081430:  21 3f e7 ff  sethi  %hi(0xff9ffc00), %l0
a0081434:  94 14 23 ff  or  %l0, 0x3ff, %o2	! 0xff9fffff
a0081438:  90 10 00 15  mov  %l5, %o0
a008143c:  92 15 20 18  or  %l4, 0x18, %o1
a0081440:  40 00 98 12  call  0xa00a7488
a0081444:  17 00 10 00  sethi  %hi(0x400000), %o3
a0081448:  94 14 23 ff  or  %l0, 0x3ff, %o2
a008144c:  90 10 00 15  mov  %l5, %o0
a0081450:  92 14 e0 18  or  %l3, 0x18, %o1
a0081454:  40 00 98 0d  call  0xa00a7488
a0081458:  17 00 10 00  sethi  %hi(0x400000), %o3
a008145c:  94 14 23 ff  or  %l0, 0x3ff, %o2
a0081460:  90 10 00 15  mov  %l5, %o0
a0081464:  92 14 a0 18  or  %l2, 0x18, %o1
a0081468:  40 00 98 08  call  0xa00a7488
a008146c:  17 00 10 00  sethi  %hi(0x400000), %o3
a0081470:  94 14 23 ff  or  %l0, 0x3ff, %o2
a0081474:  90 10 00 15  mov  %l5, %o0
a0081478:  92 14 60 18  or  %l1, 0x18, %o1
a008147c:  40 00 98 03  call  0xa00a7488
a0081480:  17 00 10 00  sethi  %hi(0x400000), %o3
a0081484:  21 3f ff e7  sethi  %hi(0xffff9c00), %l0
a0081488:  90 10 00 15  mov  %l5, %o0
a008148c:  92 15 20 18  or  %l4, 0x18, %o1
a0081490:  94 14 23 ff  or  %l0, 0x3ff, %o2
a0081494:  40 00 97 fd  call  0xa00a7488
a0081498:  17 00 00 10  sethi  %hi(0x4000), %o3
a008149c:  90 10 00 15  mov  %l5, %o0
a00814a0:  92 14 e0 18  or  %l3, 0x18, %o1
a00814a4:  94 14 23 ff  or  %l0, 0x3ff, %o2
a00814a8:  40 00 97 f8  call  0xa00a7488
a00814ac:  17 00 00 10  sethi  %hi(0x4000), %o3
a00814b0:  90 10 00 15  mov  %l5, %o0
a00814b4:  92 14 a0 18  or  %l2, 0x18, %o1
a00814b8:  94 14 23 ff  or  %l0, 0x3ff, %o2
a00814bc:  40 00 97 f3  call  0xa00a7488
a00814c0:  17 00 00 10  sethi  %hi(0x4000), %o3
a00814c4:  90 10 00 15  mov  %l5, %o0
a00814c8:  92 14 60 18  or  %l1, 0x18, %o1
a00814cc:  94 14 23 ff  or  %l0, 0x3ff, %o2
a00814d0:  17 00 00 10  sethi  %hi(0x4000), %o3
a00814d4:  40 00 97 ed  call  0xa00a7488
a00814d8:  23 00 00 08  sethi  %hi(0x2000), %l1
a00814dc:  15 00 3f ff  sethi  %hi(0xfffc00), %o2
a00814e0:  94 12 a3 ff  or  %o2, 0x3ff, %o2	! 0xffffff
a00814e4:  90 10 00 15  mov  %l5, %o0
a00814e8:  92 14 61 54  or  %l1, 0x154, %o1
a00814ec:  40 00 97 e7  call  0xa00a7488
a00814f0:  17 00 80 00  sethi  %hi(0x2000000), %o3
a00814f4:  90 10 20 01  mov  1, %o0
a00814f8:  92 10 20 15  mov  0x15, %o1
a00814fc:  94 10 00 15  mov  %l5, %o2
a0081500:  40 00 97 c9  call  0xa00a7424
a0081504:  96 14 61 48  or  %l1, 0x148, %o3
a0081508:  25 00 00 09  sethi  %hi(0x2400), %l2
a008150c:  90 10 20 01  mov  1, %o0
a0081510:  92 10 20 15  mov  0x15, %o1
a0081514:  94 10 00 15  mov  %l5, %o2
a0081518:  40 00 97 c3  call  0xa00a7424
a008151c:  96 14 a1 48  or  %l2, 0x148, %o3
a0081520:  27 00 00 0a  sethi  %hi(0x2800), %l3
a0081524:  90 10 20 01  mov  1, %o0
a0081528:  92 10 20 15  mov  0x15, %o1
a008152c:  94 10 00 15  mov  %l5, %o2
a0081530:  40 00 97 bd  call  0xa00a7424
a0081534:  96 14 e1 48  or  %l3, 0x148, %o3
a0081538:  29 00 00 0c  sethi  %hi(0x3000), %l4
a008153c:  90 10 20 01  mov  1, %o0
a0081540:  92 10 20 15  mov  0x15, %o1
a0081544:  94 10 00 15  mov  %l5, %o2
a0081548:  40 00 97 b7  call  0xa00a7424
a008154c:  96 15 21 48  or  %l4, 0x148, %o3
a0081550:  90 10 00 15  mov  %l5, %o0
a0081554:  92 14 61 04  or  %l1, 0x104, %o1
a0081558:  94 10 3f 00  mov  -256, %o2
a008155c:  40 00 97 cb  call  0xa00a7488
a0081560:  96 10 20 03  mov  3, %o3
a0081564:  90 10 00 15  mov  %l5, %o0
a0081568:  92 14 61 08  or  %l1, 0x108, %o1
a008156c:  94 10 3f 00  mov  -256, %o2
a0081570:  40 00 97 c6  call  0xa00a7488
a0081574:  96 10 20 05  mov  5, %o3
a0081578:  21 3f ff c0  sethi  %hi(0xffff0000), %l0
a008157c:  90 10 00 15  mov  %l5, %o0
a0081580:  92 14 61 08  or  %l1, 0x108, %o1
a0081584:  94 14 20 ff  or  %l0, 0xff, %o2
a0081588:  40 00 97 c0  call  0xa00a7488
a008158c:  96 10 21 00  mov  0x100, %o3
a0081590:  90 10 00 15  mov  %l5, %o0
a0081594:  92 14 a1 04  or  %l2, 0x104, %o1
a0081598:  94 10 3f 00  mov  -256, %o2
a008159c:  40 00 97 bb  call  0xa00a7488
a00815a0:  96 10 20 03  mov  3, %o3
a00815a4:  90 10 00 15  mov  %l5, %o0
a00815a8:  92 14 a1 08  or  %l2, 0x108, %o1
a00815ac:  94 10 3f 00  mov  -256, %o2
a00815b0:  40 00 97 b6  call  0xa00a7488
a00815b4:  96 10 20 05  mov  5, %o3
a00815b8:  90 10 00 15  mov  %l5, %o0
a00815bc:  92 14 a1 08  or  %l2, 0x108, %o1
a00815c0:  94 14 20 ff  or  %l0, 0xff, %o2
a00815c4:  40 00 97 b1  call  0xa00a7488
a00815c8:  96 10 21 00  mov  0x100, %o3
a00815cc:  90 10 00 15  mov  %l5, %o0
a00815d0:  92 14 e1 04  or  %l3, 0x104, %o1
a00815d4:  94 10 3f 00  mov  -256, %o2
a00815d8:  40 00 97 ac  call  0xa00a7488
a00815dc:  96 10 20 03  mov  3, %o3
a00815e0:  90 10 00 15  mov  %l5, %o0
a00815e4:  92 14 e1 08  or  %l3, 0x108, %o1
a00815e8:  94 10 3f 00  mov  -256, %o2
a00815ec:  40 00 97 a7  call  0xa00a7488
a00815f0:  96 10 20 05  mov  5, %o3
a00815f4:  90 10 00 15  mov  %l5, %o0
a00815f8:  92 14 e1 08  or  %l3, 0x108, %o1
a00815fc:  94 14 20 ff  or  %l0, 0xff, %o2
a0081600:  40 00 97 a2  call  0xa00a7488
a0081604:  96 10 21 00  mov  0x100, %o3
a0081608:  90 10 00 15  mov  %l5, %o0
a008160c:  92 15 21 04  or  %l4, 0x104, %o1
a0081610:  94 10 3f 00  mov  -256, %o2
a0081614:  40 00 97 9d  call  0xa00a7488
a0081618:  96 10 20 03  mov  3, %o3
a008161c:  90 10 00 15  mov  %l5, %o0
a0081620:  92 15 21 08  or  %l4, 0x108, %o1
a0081624:  94 10 3f 00  mov  -256, %o2
a0081628:  40 00 97 98  call  0xa00a7488
a008162c:  96 10 20 05  mov  5, %o3
a0081630:  90 10 00 15  mov  %l5, %o0
a0081634:  92 15 21 08  or  %l4, 0x108, %o1
a0081638:  94 14 20 ff  or  %l0, 0xff, %o2
a008163c:  40 00 97 93  call  0xa00a7488
a0081640:  96 10 21 00  mov  0x100, %o3
a0081644:  90 10 00 15  mov  %l5, %o0
a0081648:  92 14 61 54  or  %l1, 0x154, %o1
a008164c:  94 10 3f 00  mov  -256, %o2
a0081650:  40 00 97 8e  call  0xa00a7488
a0081654:  96 10 20 f0  mov  0xf0, %o3
a0081658:  15 3f ff f8  sethi  %hi(0xffffe000), %o2
a008165c:  90 10 00 15  mov  %l5, %o0
a0081660:  94 12 a0 ff  or  %o2, 0xff, %o2
a0081664:  92 14 61 54  or  %l1, 0x154, %o1
a0081668:  40 00 97 88  call  0xa00a7488
a008166c:  96 10 20 00  clr  %o3
a0081670:  90 10 00 15  mov  %l5, %o0
a0081674:  94 14 20 ff  or  %l0, 0xff, %o2
a0081678:  92 14 61 4c  or  %l1, 0x14c, %o1
a008167c:  40 00 97 83  call  0xa00a7488
a0081680:  96 10 26 00  mov  0x600, %o3
a0081684:  15 3f 3f ff  sethi  %hi(0xfcfffc00), %o2
a0081688:  90 10 00 15  mov  %l5, %o0
a008168c:  94 12 a3 ff  or  %o2, 0x3ff, %o2
a0081690:  92 14 61 60  or  %l1, 0x160, %o1
a0081694:  40 00 97 7d  call  0xa00a7488
a0081698:  17 00 c0 00  sethi  %hi(0x3000000), %o3
a008169c:  15 3c ff ff  sethi  %hi(0xf3fffc00), %o2
a00816a0:  90 10 00 15  mov  %l5, %o0
a00816a4:  94 12 a3 ff  or  %o2, 0x3ff, %o2
a00816a8:  92 14 61 60  or  %l1, 0x160, %o1
a00816ac:  40 00 97 77  call  0xa00a7488
a00816b0:  17 02 00 00  sethi  %hi(0x8000000), %o3
a00816b4:  90 10 20 01  mov  1, %o0
a00816b8:  92 10 20 1c  mov  0x1c, %o1
a00816bc:  94 10 00 15  mov  %l5, %o2
a00816c0:  40 00 97 59  call  0xa00a7424
a00816c4:  96 14 61 60  or  %l1, 0x160, %o3
a00816c8:  90 10 20 01  mov  1, %o0
a00816cc:  92 10 20 1d  mov  0x1d, %o1
a00816d0:  94 10 00 15  mov  %l5, %o2
a00816d4:  40 00 97 54  call  0xa00a7424
a00816d8:  96 14 61 60  or  %l1, 0x160, %o3
a00816dc:  90 10 20 01  mov  1, %o0
a00816e0:  92 10 20 1e  mov  0x1e, %o1
a00816e4:  94 10 00 15  mov  %l5, %o2
a00816e8:  40 00 97 4f  call  0xa00a7424
a00816ec:  96 14 61 60  or  %l1, 0x160, %o3
a00816f0:  90 10 20 01  mov  1, %o0
a00816f4:  92 10 20 12  mov  0x12, %o1
a00816f8:  94 10 00 15  mov  %l5, %o2
a00816fc:  40 00 97 4a  call  0xa00a7424
a0081700:  96 14 61 5c  or  %l1, 0x15c, %o3
a0081704:  90 10 20 00  clr  %o0
a0081708:  92 10 20 13  mov  0x13, %o1
a008170c:  94 10 00 15  mov  %l5, %o2
a0081710:  40 00 97 45  call  0xa00a7424
a0081714:  96 14 61 5c  or  %l1, 0x15c, %o3
a0081718:  90 10 20 00  clr  %o0
a008171c:  92 10 20 14  mov  0x14, %o1
a0081720:  94 10 00 15  mov  %l5, %o2
a0081724:  40 00 97 40  call  0xa00a7424
a0081728:  96 14 61 5c  or  %l1, 0x15c, %o3
a008172c:  90 10 20 00  clr  %o0
a0081730:  92 10 20 15  mov  0x15, %o1
a0081734:  94 10 00 15  mov  %l5, %o2
a0081738:  40 00 97 3b  call  0xa00a7424
a008173c:  96 14 61 5c  or  %l1, 0x15c, %o3
a0081740:  90 10 20 01  mov  1, %o0
a0081744:  92 10 20 16  mov  0x16, %o1
a0081748:  94 10 00 15  mov  %l5, %o2
a008174c:  40 00 97 36  call  0xa00a7424
a0081750:  96 14 61 5c  or  %l1, 0x15c, %o3
a0081754:  80 a7 60 03  cmp  %i5, 3
a0081758:  08 80 00 10  bleu  0xa0081798
a008175c:  96 14 61 40  or  %l1, 0x140, %o3
a0081760:  94 10 00 15  mov  %l5, %o2
a0081764:  90 10 20 01  mov  1, %o0
a0081768:  40 00 97 2f  call  0xa00a7424
a008176c:  92 10 20 00  clr  %o1
a0081770:  96 14 a1 40  or  %l2, 0x140, %o3
a0081774:  94 10 00 15  mov  %l5, %o2
a0081778:  90 10 20 01  mov  1, %o0
a008177c:  40 00 97 2a  call  0xa00a7424
a0081780:  92 10 20 00  clr  %o1
a0081784:  96 14 e1 40  or  %l3, 0x140, %o3
a0081788:  94 10 00 15  mov  %l5, %o2
a008178c:  90 10 20 01  mov  1, %o0
a0081790:  10 80 00 0f  b  0xa00817cc
a0081794:  92 10 20 00  clr  %o1
a0081798:  90 10 20 00  clr  %o0
a008179c:  92 10 20 00  clr  %o1
a00817a0:  40 00 97 21  call  0xa00a7424
a00817a4:  94 10 00 15  mov  %l5, %o2
a00817a8:  96 14 a1 40  or  %l2, 0x140, %o3
a00817ac:  90 10 20 01  mov  1, %o0
a00817b0:  92 10 20 00  clr  %o1
a00817b4:  40 00 97 1c  call  0xa00a7424
a00817b8:  94 10 00 15  mov  %l5, %o2
a00817bc:  96 14 e1 40  or  %l3, 0x140, %o3
a00817c0:  90 10 20 01  mov  1, %o0
a00817c4:  92 10 20 00  clr  %o1
a00817c8:  94 10 00 15  mov  %l5, %o2
a00817cc:  40 00 97 16  call  0xa00a7424
a00817d0:  21 00 00 08  sethi  %hi(0x2000), %l0
a00817d4:  96 15 21 40  or  %l4, 0x140, %o3
a00817d8:  90 10 20 01  mov  1, %o0
a00817dc:  92 10 20 00  clr  %o1
a00817e0:  40 00 97 11  call  0xa00a7424
a00817e4:  94 10 00 15  mov  %l5, %o2
a00817e8:  90 10 00 15  mov  %l5, %o0
a00817ec:  92 14 21 f0  or  %l0, 0x1f0, %o1
a00817f0:  94 10 3f 00  mov  -256, %o2
a00817f4:  40 00 97 25  call  0xa00a7488
a00817f8:  96 10 20 80  mov  0x80, %o3
a00817fc:  80 a7 60 01  cmp  %i5, 1
a0081800:  12 80 00 0c  bne  0xa0081830
a0081804:  15 3f ff c3  sethi  %hi(0xffff0c00), %o2
a0081808:  92 14 21 f4  or  %l0, 0x1f4, %o1
a008180c:  94 12 a3 ff  or  %o2, 0x3ff, %o2
a0081810:  90 10 00 15  mov  %l5, %o0
a0081814:  40 00 97 1d  call  0xa00a7488
a0081818:  17 00 00 20  sethi  %hi(0x8000), %o3
a008181c:  90 10 00 15  mov  %l5, %o0
a0081820:  92 14 21 f4  or  %l0, 0x1f4, %o1
a0081824:  94 10 3c 00  mov  -1024, %o2
a0081828:  10 80 00 24  b  0xa00818b8
a008182c:  96 10 20 96  mov  0x96, %o3
a0081830:  94 12 a3 ff  or  %o2, 0x3ff, %o2
a0081834:  90 10 00 15  mov  %l5, %o0
a0081838:  92 14 21 f4  or  %l0, 0x1f4, %o1
a008183c:  40 00 97 13  call  0xa00a7488
a0081840:  17 00 00 3c  sethi  %hi(0xf000), %o3
a0081844:  82 0d a0 ff  and  %l6, 0xff, %g1
a0081848:  80 a0 60 01  cmp  %g1, 1
a008184c:  18 80 00 07  bgu  0xa0081868
a0081850:  80 a7 60 04  cmp  %i5, 4
a0081854:  90 10 00 15  mov  %l5, %o0
a0081858:  92 14 21 f4  or  %l0, 0x1f4, %o1
a008185c:  94 10 3c 00  mov  -1024, %o2
a0081860:  10 80 00 16  b  0xa00818b8
a0081864:  96 10 21 2c  mov  0x12c, %o3
a0081868:  12 80 00 07  bne  0xa0081884
a008186c:  80 a7 60 05  cmp  %i5, 5
a0081870:  90 10 00 15  mov  %l5, %o0
a0081874:  92 14 21 f4  or  %l0, 0x1f4, %o1
a0081878:  94 10 3c 00  mov  -1024, %o2
a008187c:  10 80 00 0f  b  0xa00818b8
a0081880:  96 10 21 90  mov  0x190, %o3
a0081884:  12 80 00 07  bne  0xa00818a0
a0081888:  80 a7 60 06  cmp  %i5, 6
a008188c:  90 10 00 15  mov  %l5, %o0
a0081890:  92 14 21 f4  or  %l0, 0x1f4, %o1
a0081894:  94 10 3c 00  mov  -1024, %o2
a0081898:  10 80 00 08  b  0xa00818b8
a008189c:  96 10 21 f4  mov  0x1f4, %o3
a00818a0:  32 80 00 08  bne,a   0xa00818c0
a00818a4:  aa 0e 20 ff  and  %i0, 0xff, %l5
a00818a8:  90 10 00 15  mov  %l5, %o0
a00818ac:  92 14 21 f4  or  %l0, 0x1f4, %o1
a00818b0:  94 10 3c 00  mov  -1024, %o2
a00818b4:  96 10 22 58  mov  0x258, %o3
a00818b8:  40 00 96 f4  call  0xa00a7488
a00818bc:  aa 0e 20 ff  and  %i0, 0xff, %l5
a00818c0:  17 00 00 0d  sethi  %hi(0x3400), %o3
a00818c4:  96 12 e2 04  or  %o3, 0x204, %o3	! 0x3604
a00818c8:  90 10 20 00  clr  %o0
a00818cc:  92 10 20 1b  mov  0x1b, %o1
a00818d0:  40 00 96 d5  call  0xa00a7424
a00818d4:  94 10 00 15  mov  %l5, %o2
a00818d8:  21 00 00 0b  sethi  %hi(0x2c00), %l0
a00818dc:  15 3f ff c0  sethi  %hi(0xffff0000), %o2
a00818e0:  17 00 00 1c  sethi  %hi(0x7000), %o3
a00818e4:  90 10 00 15  mov  %l5, %o0
a00818e8:  94 12 a0 ff  or  %o2, 0xff, %o2
a00818ec:  96 12 e1 00  or  %o3, 0x100, %o3
a00818f0:  40 00 96 e6  call  0xa00a7488
a00818f4:  92 14 23 44  or  %l0, 0x344, %o1
a00818f8:  15 3f c0 3f  sethi  %hi(0xff00fc00), %o2
a00818fc:  90 10 00 15  mov  %l5, %o0
a0081900:  94 12 a3 ff  or  %o2, 0x3ff, %o2
a0081904:  92 14 23 44  or  %l0, 0x344, %o1
a0081908:  40 00 96 e0  call  0xa00a7488
a008190c:  17 00 1c 40  sethi  %hi(0x710000), %o3
a0081910:  15 00 3f ff  sethi  %hi(0xfffc00), %o2
a0081914:  90 10 00 15  mov  %l5, %o0
a0081918:  94 12 a3 ff  or  %o2, 0x3ff, %o2
a008191c:  92 14 23 44  or  %l0, 0x344, %o1
a0081920:  40 00 96 da  call  0xa00a7488
a0081924:  17 1c 40 00  sethi  %hi(0x71000000), %o3
a0081928:  96 10 20 71  mov  0x71, %o3
a008192c:  90 10 00 15  mov  %l5, %o0
a0081930:  92 14 23 48  or  %l0, 0x348, %o1
a0081934:  40 00 96 d5  call  0xa00a7488
a0081938:  94 10 3f 00  mov  -256, %o2
a008193c:  96 06 7f fb  add  %i1, -5, %o3
a0081940:  82 0a e0 ff  and  %o3, 0xff, %g1
a0081944:  d6 27 bf 14  st  %o3, [ %fp + -236 ]
a0081948:  80 a0 60 01  cmp  %g1, 1
a008194c:  18 80 00 05  bgu  0xa0081960
a0081950:  b8 10 20 00  clr  %i4
a0081954:  b8 10 20 01  mov  1, %i4
a0081958:  10 80 00 07  b  0xa0081974
a008195c:  ac 10 20 03  mov  3, %l6
a0081960:  80 a7 60 04  cmp  %i5, 4
a0081964:  12 80 00 04  bne  0xa0081974
a0081968:  ac 10 20 13  mov  0x13, %l6
a008196c:  b8 10 20 01  mov  1, %i4
a0081970:  ac 10 20 05  mov  5, %l6
a0081974:  21 3f f3 ff  sethi  %hi(0xffcffc00), %l0
a0081978:  29 00 00 08  sethi  %hi(0x2000), %l4
a008197c:  94 14 23 ff  or  %l0, 0x3ff, %o2
a0081980:  90 10 00 15  mov  %l5, %o0
a0081984:  92 15 20 60  or  %l4, 0x60, %o1
a0081988:  40 00 96 c0  call  0xa00a7488
a008198c:  96 10 20 00  clr  %o3
a0081990:  27 00 00 09  sethi  %hi(0x2400), %l3
a0081994:  94 14 23 ff  or  %l0, 0x3ff, %o2
a0081998:  90 10 00 15  mov  %l5, %o0
a008199c:  92 14 e0 60  or  %l3, 0x60, %o1
a00819a0:  40 00 96 ba  call  0xa00a7488
a00819a4:  96 10 20 00  clr  %o3
a00819a8:  25 00 00 0a  sethi  %hi(0x2800), %l2
a00819ac:  94 14 23 ff  or  %l0, 0x3ff, %o2
a00819b0:  90 10 00 15  mov  %l5, %o0
a00819b4:  92 14 a0 60  or  %l2, 0x60, %o1
a00819b8:  40 00 96 b4  call  0xa00a7488
a00819bc:  96 10 20 00  clr  %o3
a00819c0:  23 00 00 0c  sethi  %hi(0x3000), %l1
a00819c4:  94 14 23 ff  or  %l0, 0x3ff, %o2
a00819c8:  90 10 00 15  mov  %l5, %o0
a00819cc:  92 14 60 60  or  %l1, 0x60, %o1
a00819d0:  40 00 96 ae  call  0xa00a7488
a00819d4:  96 10 20 00  clr  %o3
a00819d8:  21 3f cf ff  sethi  %hi(0xff3ffc00), %l0
a00819dc:  90 10 00 15  mov  %l5, %o0
a00819e0:  92 15 20 60  or  %l4, 0x60, %o1
a00819e4:  94 14 23 ff  or  %l0, 0x3ff, %o2
a00819e8:  40 00 96 a8  call  0xa00a7488
a00819ec:  17 00 20 00  sethi  %hi(0x800000), %o3
a00819f0:  90 10 00 15  mov  %l5, %o0
a00819f4:  92 14 e0 60  or  %l3, 0x60, %o1
a00819f8:  94 14 23 ff  or  %l0, 0x3ff, %o2
a00819fc:  40 00 96 a3  call  0xa00a7488
a0081a00:  17 00 20 00  sethi  %hi(0x800000), %o3
a0081a04:  90 10 00 15  mov  %l5, %o0
a0081a08:  92 14 a0 60  or  %l2, 0x60, %o1
a0081a0c:  94 14 23 ff  or  %l0, 0x3ff, %o2
a0081a10:  40 00 96 9e  call  0xa00a7488
a0081a14:  17 00 20 00  sethi  %hi(0x800000), %o3
a0081a18:  90 10 00 15  mov  %l5, %o0
a0081a1c:  92 14 60 60  or  %l1, 0x60, %o1
a0081a20:  94 14 23 ff  or  %l0, 0x3ff, %o2
a0081a24:  40 00 96 99  call  0xa00a7488
a0081a28:  17 00 20 00  sethi  %hi(0x800000), %o3
a0081a2c:  ae 0e 60 ff  and  %i1, 0xff, %l7
a0081a30:  80 a5 e0 01  cmp  %l7, 1
a0081a34:  02 80 00 06  be  0xa0081a4c
a0081a38:  82 06 7f fe  add  %i1, -2, %g1
a0081a3c:  82 08 60 ff  and  %g1, 0xff, %g1
a0081a40:  80 a0 60 01  cmp  %g1, 1
a0081a44:  18 80 00 5c  bgu  0xa0081bb4
a0081a48:  80 a5 e0 04  cmp  %l7, 4
a0081a4c:  21 00 00 0b  sethi  %hi(0x2c00), %l0
a0081a50:  94 10 00 15  mov  %l5, %o2
a0081a54:  96 14 20 34  or  %l0, 0x34, %o3
a0081a58:  90 10 20 00  clr  %o0
a0081a5c:  40 00 96 72  call  0xa00a7424
a0081a60:  92 10 20 13  mov  0x13, %o1
a0081a64:  94 10 00 15  mov  %l5, %o2
a0081a68:  96 14 20 34  or  %l0, 0x34, %o3
a0081a6c:  90 10 20 01  mov  1, %o0
a0081a70:  40 00 96 6d  call  0xa00a7424
a0081a74:  92 10 20 19  mov  0x19, %o1
a0081a78:  94 10 00 15  mov  %l5, %o2
a0081a7c:  96 14 20 34  or  %l0, 0x34, %o3
a0081a80:  90 10 20 00  clr  %o0
a0081a84:  40 00 96 68  call  0xa00a7424
a0081a88:  92 10 20 10  mov  0x10, %o1
a0081a8c:  94 10 00 15  mov  %l5, %o2
a0081a90:  96 14 20 34  or  %l0, 0x34, %o3
a0081a94:  90 10 20 00  clr  %o0
a0081a98:  40 00 96 63  call  0xa00a7424
a0081a9c:  92 10 20 11  mov  0x11, %o1
a0081aa0:  94 10 00 15  mov  %l5, %o2
a0081aa4:  96 14 20 34  or  %l0, 0x34, %o3
a0081aa8:  90 10 20 00  clr  %o0
a0081aac:  40 00 96 5e  call  0xa00a7424
a0081ab0:  92 10 20 12  mov  0x12, %o1
a0081ab4:  15 3f fc 3f  sethi  %hi(0xfff0fc00), %o2
a0081ab8:  90 10 00 15  mov  %l5, %o0
a0081abc:  94 12 a3 ff  or  %o2, 0x3ff, %o2
a0081ac0:  92 14 20 30  or  %l0, 0x30, %o1
a0081ac4:  40 00 96 71  call  0xa00a7488
a0081ac8:  17 00 02 c0  sethi  %hi(0xb0000), %o3
a0081acc:  15 3f c3 ff  sethi  %hi(0xff0ffc00), %o2
a0081ad0:  90 10 00 15  mov  %l5, %o0
a0081ad4:  94 12 a3 ff  or  %o2, 0x3ff, %o2
a0081ad8:  92 14 20 30  or  %l0, 0x30, %o1
a0081adc:  40 00 96 6b  call  0xa00a7488
a0081ae0:  17 00 10 00  sethi  %hi(0x400000), %o3
a0081ae4:  15 3c 3f ff  sethi  %hi(0xf0fffc00), %o2
a0081ae8:  90 10 00 15  mov  %l5, %o0
a0081aec:  94 12 a3 ff  or  %o2, 0x3ff, %o2
a0081af0:  92 14 20 30  or  %l0, 0x30, %o1
a0081af4:  40 00 96 65  call  0xa00a7488
a0081af8:  17 03 40 00  sethi  %hi(0xd000000), %o3
a0081afc:  15 03 ff ff  sethi  %hi(0xffffc00), %o2
a0081b00:  90 10 00 15  mov  %l5, %o0
a0081b04:  94 12 a3 ff  or  %o2, 0x3ff, %o2
a0081b08:  92 14 20 30  or  %l0, 0x30, %o1
a0081b0c:  40 00 96 5f  call  0xa00a7488
a0081b10:  17 08 00 00  sethi  %hi(0x20000000), %o3
a0081b14:  94 10 00 15  mov  %l5, %o2
a0081b18:  96 14 20 30  or  %l0, 0x30, %o3
a0081b1c:  90 10 20 00  clr  %o0
a0081b20:  40 00 96 41  call  0xa00a7424
a0081b24:  92 10 20 00  clr  %o1
a0081b28:  15 3f c7 ff  sethi  %hi(0xff1ffc00), %o2
a0081b2c:  90 10 00 15  mov  %l5, %o0
a0081b30:  94 12 a3 ff  or  %o2, 0x3ff, %o2
a0081b34:  92 14 20 34  or  %l0, 0x34, %o1
a0081b38:  40 00 96 54  call  0xa00a7488
a0081b3c:  17 00 30 00  sethi  %hi(0xc00000), %o3
a0081b40:  90 10 00 15  mov  %l5, %o0
a0081b44:  92 14 20 38  or  %l0, 0x38, %o1
a0081b48:  94 10 31 ff  mov  -3585, %o2
a0081b4c:  40 00 96 4f  call  0xa00a7488
a0081b50:  96 10 20 00  clr  %o3
a0081b54:  90 10 00 15  mov  %l5, %o0
a0081b58:  92 14 20 34  or  %l0, 0x34, %o1
a0081b5c:  94 10 33 ff  mov  -3073, %o2
a0081b60:  40 00 96 4a  call  0xa00a7488
a0081b64:  96 10 20 00  clr  %o3
a0081b68:  94 10 00 15  mov  %l5, %o2
a0081b6c:  96 14 20 34  or  %l0, 0x34, %o3
a0081b70:  90 10 20 00  clr  %o0
a0081b74:  40 00 96 2c  call  0xa00a7424
a0081b78:  92 10 20 14  mov  0x14, %o1
a0081b7c:  15 3f 3f ff  sethi  %hi(0xfcfffc00), %o2
a0081b80:  90 10 00 15  mov  %l5, %o0
a0081b84:  94 12 a3 ff  or  %o2, 0x3ff, %o2
a0081b88:  92 14 20 24  or  %l0, 0x24, %o1
a0081b8c:  40 00 96 3f  call  0xa00a7488
a0081b90:  96 10 20 00  clr  %o3
a0081b94:  96 14 20 20  or  %l0, 0x20, %o3
a0081b98:  90 10 20 00  clr  %o0
a0081b9c:  94 10 00 15  mov  %l5, %o2
a0081ba0:  40 00 96 21  call  0xa00a7424
a0081ba4:  92 10 20 05  mov  5, %o1
a0081ba8:  96 14 20 20  or  %l0, 0x20, %o3
a0081bac:  10 80 00 dc  b  0xa0081f1c
a0081bb0:  90 10 20 00  clr  %o0
a0081bb4:  12 80 00 1b  bne  0xa0081c20
a0081bb8:  80 a5 e0 05  cmp  %l7, 5
a0081bbc:  21 00 00 0b  sethi  %hi(0x2c00), %l0
a0081bc0:  94 10 00 15  mov  %l5, %o2
a0081bc4:  96 14 20 34  or  %l0, 0x34, %o3
a0081bc8:  90 10 20 01  mov  1, %o0
a0081bcc:  40 00 96 16  call  0xa00a7424
a0081bd0:  92 10 20 13  mov  0x13, %o1
a0081bd4:  94 10 00 15  mov  %l5, %o2
a0081bd8:  96 14 20 34  or  %l0, 0x34, %o3
a0081bdc:  90 10 20 00  clr  %o0
a0081be0:  40 00 96 11  call  0xa00a7424
a0081be4:  92 10 20 19  mov  0x19, %o1
a0081be8:  94 10 00 15  mov  %l5, %o2
a0081bec:  96 14 20 34  or  %l0, 0x34, %o3
a0081bf0:  90 10 20 01  mov  1, %o0
a0081bf4:  40 00 96 0c  call  0xa00a7424
a0081bf8:  92 10 20 10  mov  0x10, %o1
a0081bfc:  94 10 00 15  mov  %l5, %o2
a0081c00:  96 14 20 34  or  %l0, 0x34, %o3
a0081c04:  90 10 20 00  clr  %o0
a0081c08:  40 00 96 07  call  0xa00a7424
a0081c0c:  92 10 20 11  mov  0x11, %o1
a0081c10:  94 10 00 15  mov  %l5, %o2
a0081c14:  96 14 20 34  or  %l0, 0x34, %o3
a0081c18:  10 80 00 1c  b  0xa0081c88
a0081c1c:  90 10 20 01  mov  1, %o0
a0081c20:  12 80 00 5d  bne  0xa0081d94
a0081c24:  80 a5 e0 06  cmp  %l7, 6
a0081c28:  21 00 00 0b  sethi  %hi(0x2c00), %l0
a0081c2c:  94 10 00 15  mov  %l5, %o2
a0081c30:  96 14 20 34  or  %l0, 0x34, %o3
a0081c34:  90 10 20 01  mov  1, %o0
a0081c38:  40 00 95 fb  call  0xa00a7424
a0081c3c:  92 10 20 13  mov  0x13, %o1
a0081c40:  94 10 00 15  mov  %l5, %o2
a0081c44:  96 14 20 34  or  %l0, 0x34, %o3
a0081c48:  90 10 20 00  clr  %o0
a0081c4c:  40 00 95 f6  call  0xa00a7424
a0081c50:  92 10 20 19  mov  0x19, %o1
a0081c54:  94 10 00 15  mov  %l5, %o2
a0081c58:  96 14 20 34  or  %l0, 0x34, %o3
a0081c5c:  90 10 20 01  mov  1, %o0
a0081c60:  40 00 95 f1  call  0xa00a7424
a0081c64:  92 10 20 10  mov  0x10, %o1
a0081c68:  94 10 00 15  mov  %l5, %o2
a0081c6c:  96 14 20 34  or  %l0, 0x34, %o3
a0081c70:  90 10 20 01  mov  1, %o0
a0081c74:  40 00 95 ec  call  0xa00a7424
a0081c78:  92 10 20 11  mov  0x11, %o1
a0081c7c:  94 10 00 15  mov  %l5, %o2
a0081c80:  96 14 20 34  or  %l0, 0x34, %o3
a0081c84:  90 10 20 00  clr  %o0
a0081c88:  40 00 95 e7  call  0xa00a7424
a0081c8c:  92 10 20 12  mov  0x12, %o1
a0081c90:  15 3f fc 3f  sethi  %hi(0xfff0fc00), %o2
a0081c94:  90 10 00 15  mov  %l5, %o0
a0081c98:  94 12 a3 ff  or  %o2, 0x3ff, %o2
a0081c9c:  92 14 20 30  or  %l0, 0x30, %o1
a0081ca0:  40 00 95 fa  call  0xa00a7488
a0081ca4:  17 00 02 80  sethi  %hi(0xa0000), %o3
a0081ca8:  15 3f c3 ff  sethi  %hi(0xff0ffc00), %o2
a0081cac:  90 10 00 15  mov  %l5, %o0
a0081cb0:  94 12 a3 ff  or  %o2, 0x3ff, %o2
a0081cb4:  92 14 20 30  or  %l0, 0x30, %o1
a0081cb8:  40 00 95 f4  call  0xa00a7488
a0081cbc:  17 00 0c 00  sethi  %hi(0x300000), %o3
a0081cc0:  15 3c 3f ff  sethi  %hi(0xf0fffc00), %o2
a0081cc4:  90 10 00 15  mov  %l5, %o0
a0081cc8:  94 12 a3 ff  or  %o2, 0x3ff, %o2
a0081ccc:  92 14 20 30  or  %l0, 0x30, %o1
a0081cd0:  40 00 95 ee  call  0xa00a7488
a0081cd4:  17 03 00 00  sethi  %hi(0xc000000), %o3
a0081cd8:  15 03 ff ff  sethi  %hi(0xffffc00), %o2
a0081cdc:  90 10 00 15  mov  %l5, %o0
a0081ce0:  94 12 a3 ff  or  %o2, 0x3ff, %o2
a0081ce4:  92 14 20 30  or  %l0, 0x30, %o1
a0081ce8:  40 00 95 e8  call  0xa00a7488
a0081cec:  17 04 00 00  sethi  %hi(0x10000000), %o3
a0081cf0:  94 10 00 15  mov  %l5, %o2
a0081cf4:  96 14 20 30  or  %l0, 0x30, %o3
a0081cf8:  90 10 20 01  mov  1, %o0
a0081cfc:  40 00 95 ca  call  0xa00a7424
a0081d00:  92 10 20 00  clr  %o1
a0081d04:  15 3f c7 ff  sethi  %hi(0xff1ffc00), %o2
a0081d08:  90 10 00 15  mov  %l5, %o0
a0081d0c:  94 12 a3 ff  or  %o2, 0x3ff, %o2
a0081d10:  92 14 20 34  or  %l0, 0x34, %o1
a0081d14:  40 00 95 dd  call  0xa00a7488
a0081d18:  17 00 20 00  sethi  %hi(0x800000), %o3
a0081d1c:  90 10 00 15  mov  %l5, %o0
a0081d20:  92 14 20 38  or  %l0, 0x38, %o1
a0081d24:  94 10 31 ff  mov  -3585, %o2
a0081d28:  40 00 95 d8  call  0xa00a7488
a0081d2c:  96 10 26 00  mov  0x600, %o3
a0081d30:  90 10 00 15  mov  %l5, %o0
a0081d34:  92 14 20 34  or  %l0, 0x34, %o1
a0081d38:  94 10 33 ff  mov  -3073, %o2
a0081d3c:  40 00 95 d3  call  0xa00a7488
a0081d40:  96 10 2c 00  mov  0xc00, %o3
a0081d44:  94 10 00 15  mov  %l5, %o2
a0081d48:  96 14 20 34  or  %l0, 0x34, %o3
a0081d4c:  90 10 20 01  mov  1, %o0
a0081d50:  40 00 95 b5  call  0xa00a7424
a0081d54:  92 10 20 14  mov  0x14, %o1
a0081d58:  15 3f 3f ff  sethi  %hi(0xfcfffc00), %o2
a0081d5c:  90 10 00 15  mov  %l5, %o0
a0081d60:  94 12 a3 ff  or  %o2, 0x3ff, %o2
a0081d64:  92 14 20 24  or  %l0, 0x24, %o1
a0081d68:  40 00 95 c8  call  0xa00a7488
a0081d6c:  17 00 c0 00  sethi  %hi(0x3000000), %o3
a0081d70:  94 10 00 15  mov  %l5, %o2
a0081d74:  96 14 20 20  or  %l0, 0x20, %o3
a0081d78:  92 10 20 05  mov  5, %o1
a0081d7c:  40 00 95 aa  call  0xa00a7424
a0081d80:  90 10 20 01  mov  1, %o0
a0081d84:  94 10 00 15  mov  %l5, %o2
a0081d88:  96 14 20 20  or  %l0, 0x20, %o3
a0081d8c:  10 80 00 5e  b  0xa0081f04
a0081d90:  92 10 20 04  mov  4, %o1
a0081d94:  12 80 00 66  bne  0xa0081f2c
a0081d98:  a0 0d a0 ff  and  %l6, 0xff, %l0
a0081d9c:  21 00 00 0b  sethi  %hi(0x2c00), %l0
a0081da0:  90 10 20 01  mov  1, %o0
a0081da4:  92 10 20 13  mov  0x13, %o1
a0081da8:  94 10 00 15  mov  %l5, %o2
a0081dac:  40 00 95 9e  call  0xa00a7424
a0081db0:  96 14 20 34  or  %l0, 0x34, %o3
a0081db4:  90 10 20 00  clr  %o0
a0081db8:  92 10 20 19  mov  0x19, %o1
a0081dbc:  94 10 00 15  mov  %l5, %o2
a0081dc0:  40 00 95 99  call  0xa00a7424
a0081dc4:  96 14 20 34  or  %l0, 0x34, %o3
a0081dc8:  90 10 20 01  mov  1, %o0
a0081dcc:  92 10 20 10  mov  0x10, %o1
a0081dd0:  94 10 00 15  mov  %l5, %o2
a0081dd4:  40 00 95 94  call  0xa00a7424
a0081dd8:  96 14 20 34  or  %l0, 0x34, %o3
a0081ddc:  90 10 20 01  mov  1, %o0
a0081de0:  92 10 20 11  mov  0x11, %o1
a0081de4:  94 10 00 15  mov  %l5, %o2
a0081de8:  40 00 95 8f  call  0xa00a7424
a0081dec:  96 14 20 34  or  %l0, 0x34, %o3
a0081df0:  90 10 20 00  clr  %o0
a0081df4:  92 10 20 12  mov  0x12, %o1
a0081df8:  94 10 00 15  mov  %l5, %o2
a0081dfc:  40 00 95 8a  call  0xa00a7424
a0081e00:  96 14 20 34  or  %l0, 0x34, %o3
a0081e04:  15 3f fc 3f  sethi  %hi(0xfff0fc00), %o2
a0081e08:  90 10 00 15  mov  %l5, %o0
a0081e0c:  94 12 a3 ff  or  %o2, 0x3ff, %o2
a0081e10:  92 14 20 30  or  %l0, 0x30, %o1
a0081e14:  40 00 95 9d  call  0xa00a7488
a0081e18:  17 00 02 80  sethi  %hi(0xa0000), %o3
a0081e1c:  15 3f c3 ff  sethi  %hi(0xff0ffc00), %o2
a0081e20:  90 10 00 15  mov  %l5, %o0
a0081e24:  94 12 a3 ff  or  %o2, 0x3ff, %o2
a0081e28:  92 14 20 30  or  %l0, 0x30, %o1
a0081e2c:  40 00 95 97  call  0xa00a7488
a0081e30:  17 00 0c 00  sethi  %hi(0x300000), %o3
a0081e34:  15 3c 3f ff  sethi  %hi(0xf0fffc00), %o2
a0081e38:  90 10 00 15  mov  %l5, %o0
a0081e3c:  94 12 a3 ff  or  %o2, 0x3ff, %o2
a0081e40:  92 14 20 30  or  %l0, 0x30, %o1
a0081e44:  40 00 95 91  call  0xa00a7488
a0081e48:  17 03 00 00  sethi  %hi(0xc000000), %o3
a0081e4c:  15 03 ff ff  sethi  %hi(0xffffc00), %o2
a0081e50:  90 10 00 15  mov  %l5, %o0
a0081e54:  94 12 a3 ff  or  %o2, 0x3ff, %o2
a0081e58:  92 14 20 30  or  %l0, 0x30, %o1
a0081e5c:  40 00 95 8b  call  0xa00a7488
a0081e60:  17 04 00 00  sethi  %hi(0x10000000), %o3
a0081e64:  90 10 20 01  mov  1, %o0
a0081e68:  92 10 20 00  clr  %o1
a0081e6c:  94 10 00 15  mov  %l5, %o2
a0081e70:  40 00 95 6d  call  0xa00a7424
a0081e74:  96 14 20 30  or  %l0, 0x30, %o3
a0081e78:  15 3f c7 ff  sethi  %hi(0xff1ffc00), %o2
a0081e7c:  90 10 00 15  mov  %l5, %o0
a0081e80:  94 12 a3 ff  or  %o2, 0x3ff, %o2
a0081e84:  92 14 20 34  or  %l0, 0x34, %o1
a0081e88:  40 00 95 80  call  0xa00a7488
a0081e8c:  17 00 20 00  sethi  %hi(0x800000), %o3
a0081e90:  90 10 00 15  mov  %l5, %o0
a0081e94:  92 14 20 38  or  %l0, 0x38, %o1
a0081e98:  94 10 31 ff  mov  -3585, %o2
a0081e9c:  40 00 95 7b  call  0xa00a7488
a0081ea0:  96 10 26 00  mov  0x600, %o3
a0081ea4:  90 10 00 15  mov  %l5, %o0
a0081ea8:  92 14 20 34  or  %l0, 0x34, %o1
a0081eac:  94 10 33 ff  mov  -3073, %o2
a0081eb0:  40 00 95 76  call  0xa00a7488
a0081eb4:  96 10 2c 00  mov  0xc00, %o3
a0081eb8:  90 10 20 01  mov  1, %o0
a0081ebc:  92 10 20 14  mov  0x14, %o1
a0081ec0:  94 10 00 15  mov  %l5, %o2
a0081ec4:  40 00 95 58  call  0xa00a7424
a0081ec8:  96 14 20 34  or  %l0, 0x34, %o3
a0081ecc:  15 3f 3f ff  sethi  %hi(0xfcfffc00), %o2
a0081ed0:  90 10 00 15  mov  %l5, %o0
a0081ed4:  94 12 a3 ff  or  %o2, 0x3ff, %o2
a0081ed8:  92 14 20 24  or  %l0, 0x24, %o1
a0081edc:  40 00 95 6b  call  0xa00a7488
a0081ee0:  17 00 c0 00  sethi  %hi(0x3000000), %o3
a0081ee4:  92 10 20 05  mov  5, %o1
a0081ee8:  94 10 00 15  mov  %l5, %o2
a0081eec:  96 14 20 20  or  %l0, 0x20, %o3
a0081ef0:  40 00 95 4d  call  0xa00a7424
a0081ef4:  90 10 20 01  mov  1, %o0
a0081ef8:  92 10 20 04  mov  4, %o1
a0081efc:  94 10 00 15  mov  %l5, %o2
a0081f00:  96 14 20 20  or  %l0, 0x20, %o3
a0081f04:  40 00 95 48  call  0xa00a7424
a0081f08:  90 10 20 00  clr  %o0
a0081f0c:  40 00 be 22  call  0xa00b1794
a0081f10:  90 10 20 01  mov  1, %o0
a0081f14:  96 14 20 20  or  %l0, 0x20, %o3
a0081f18:  90 10 20 01  mov  1, %o0
a0081f1c:  92 10 20 04  mov  4, %o1
a0081f20:  40 00 95 41  call  0xa00a7424
a0081f24:  94 10 00 15  mov  %l5, %o2
a0081f28:  a0 0d a0 ff  and  %l6, 0xff, %l0
a0081f2c:  a1 2c 20 10  sll  %l0, 0x10, %l0
a0081f30:  23 3f c0 3f  sethi  %hi(0xff00fc00), %l1
a0081f34:  25 00 00 08  sethi  %hi(0x2000), %l2
a0081f38:  90 10 00 15  mov  %l5, %o0
a0081f3c:  92 14 a0 68  or  %l2, 0x68, %o1
a0081f40:  94 14 63 ff  or  %l1, 0x3ff, %o2
a0081f44:  40 00 95 51  call  0xa00a7488
a0081f48:  96 10 00 10  mov  %l0, %o3
a0081f4c:  27 00 00 09  sethi  %hi(0x2400), %l3
a0081f50:  90 10 00 15  mov  %l5, %o0
a0081f54:  92 14 e0 68  or  %l3, 0x68, %o1
a0081f58:  94 14 63 ff  or  %l1, 0x3ff, %o2
a0081f5c:  40 00 95 4b  call  0xa00a7488
a0081f60:  96 10 00 10  mov  %l0, %o3
a0081f64:  29 00 00 0a  sethi  %hi(0x2800), %l4
a0081f68:  90 10 00 15  mov  %l5, %o0
a0081f6c:  92 15 20 68  or  %l4, 0x68, %o1
a0081f70:  94 14 63 ff  or  %l1, 0x3ff, %o2
a0081f74:  40 00 95 45  call  0xa00a7488
a0081f78:  96 10 00 10  mov  %l0, %o3
a0081f7c:  2d 00 00 0c  sethi  %hi(0x3000), %l6
a0081f80:  90 10 00 15  mov  %l5, %o0
a0081f84:  96 10 00 10  mov  %l0, %o3
a0081f88:  92 15 a0 68  or  %l6, 0x68, %o1
a0081f8c:  40 00 95 3f  call  0xa00a7488
a0081f90:  94 14 63 ff  or  %l1, 0x3ff, %o2
a0081f94:  7f ff e3 00  call  0xa007ab94
a0081f98:  90 10 00 15  mov  %l5, %o0
a0081f9c:  80 8f 20 ff  btst  0xff, %i4
a0081fa0:  02 80 00 5b  be  0xa008210c
a0081fa4:  80 a5 e0 06  cmp  %l7, 6
a0081fa8:  94 10 00 15  mov  %l5, %o2
a0081fac:  96 14 a0 70  or  %l2, 0x70, %o3
a0081fb0:  90 10 20 01  mov  1, %o0
a0081fb4:  40 00 95 1c  call  0xa00a7424
a0081fb8:  92 10 20 03  mov  3, %o1
a0081fbc:  94 10 00 15  mov  %l5, %o2
a0081fc0:  96 14 e0 70  or  %l3, 0x70, %o3
a0081fc4:  90 10 20 01  mov  1, %o0
a0081fc8:  40 00 95 17  call  0xa00a7424
a0081fcc:  92 10 20 03  mov  3, %o1
a0081fd0:  94 10 00 15  mov  %l5, %o2
a0081fd4:  96 15 20 70  or  %l4, 0x70, %o3
a0081fd8:  90 10 20 01  mov  1, %o0
a0081fdc:  40 00 95 12  call  0xa00a7424
a0081fe0:  92 10 20 03  mov  3, %o1
a0081fe4:  94 10 00 15  mov  %l5, %o2
a0081fe8:  96 15 a0 70  or  %l6, 0x70, %o3
a0081fec:  90 10 20 01  mov  1, %o0
a0081ff0:  40 00 95 0d  call  0xa00a7424
a0081ff4:  92 10 20 03  mov  3, %o1
a0081ff8:  90 10 00 15  mov  %l5, %o0
a0081ffc:  92 14 a0 28  or  %l2, 0x28, %o1
a0082000:  94 14 63 ff  or  %l1, 0x3ff, %o2
a0082004:  40 00 95 21  call  0xa00a7488
a0082008:  17 00 00 80  sethi  %hi(0x20000), %o3
a008200c:  90 10 00 15  mov  %l5, %o0
a0082010:  92 14 e0 28  or  %l3, 0x28, %o1
a0082014:  94 14 63 ff  or  %l1, 0x3ff, %o2
a0082018:  40 00 95 1c  call  0xa00a7488
a008201c:  17 00 00 80  sethi  %hi(0x20000), %o3
a0082020:  90 10 00 15  mov  %l5, %o0
a0082024:  92 15 20 28  or  %l4, 0x28, %o1
a0082028:  94 14 63 ff  or  %l1, 0x3ff, %o2
a008202c:  40 00 95 17  call  0xa00a7488
a0082030:  17 00 00 80  sethi  %hi(0x20000), %o3
a0082034:  90 10 00 15  mov  %l5, %o0
a0082038:  92 15 a0 28  or  %l6, 0x28, %o1
a008203c:  94 14 63 ff  or  %l1, 0x3ff, %o2
a0082040:  40 00 95 12  call  0xa00a7488
a0082044:  17 00 00 80  sethi  %hi(0x20000), %o3
a0082048:  90 10 00 15  mov  %l5, %o0
a008204c:  92 14 a0 08  or  %l2, 8, %o1
a0082050:  94 14 63 ff  or  %l1, 0x3ff, %o2
a0082054:  40 00 95 0d  call  0xa00a7488
a0082058:  17 00 04 80  sethi  %hi(0x120000), %o3
a008205c:  90 10 00 15  mov  %l5, %o0
a0082060:  92 14 e0 08  or  %l3, 8, %o1
a0082064:  94 14 63 ff  or  %l1, 0x3ff, %o2
a0082068:  40 00 95 08  call  0xa00a7488
a008206c:  17 00 04 80  sethi  %hi(0x120000), %o3
a0082070:  90 10 00 15  mov  %l5, %o0
a0082074:  92 15 20 08  or  %l4, 8, %o1
a0082078:  94 14 63 ff  or  %l1, 0x3ff, %o2
a008207c:  40 00 95 03  call  0xa00a7488
a0082080:  17 00 04 80  sethi  %hi(0x120000), %o3
a0082084:  90 10 00 15  mov  %l5, %o0
a0082088:  94 14 63 ff  or  %l1, 0x3ff, %o2
a008208c:  92 15 a0 08  or  %l6, 8, %o1
a0082090:  40 00 94 fe  call  0xa00a7488
a0082094:  17 00 04 80  sethi  %hi(0x120000), %o3
a0082098:  94 10 00 15  mov  %l5, %o2
a008209c:  96 14 a0 08  or  %l2, 8, %o3
a00820a0:  90 10 20 01  mov  1, %o0
a00820a4:  40 00 94 e0  call  0xa00a7424
a00820a8:  92 10 20 11  mov  0x11, %o1
a00820ac:  96 14 e0 08  or  %l3, 8, %o3
a00820b0:  94 10 00 15  mov  %l5, %o2
a00820b4:  90 10 20 01  mov  1, %o0
a00820b8:  40 00 94 db  call  0xa00a7424
a00820bc:  92 10 20 11  mov  0x11, %o1
a00820c0:  96 15 20 08  or  %l4, 8, %o3
a00820c4:  94 10 00 15  mov  %l5, %o2
a00820c8:  90 10 20 01  mov  1, %o0
a00820cc:  40 00 94 d6  call  0xa00a7424
a00820d0:  92 10 20 11  mov  0x11, %o1
a00820d4:  96 15 a0 08  or  %l6, 8, %o3
a00820d8:  94 10 00 15  mov  %l5, %o2
a00820dc:  90 10 20 01  mov  1, %o0
a00820e0:  40 00 94 d1  call  0xa00a7424
a00820e4:  92 10 20 11  mov  0x11, %o1
a00820e8:  96 14 a0 28  or  %l2, 0x28, %o3
a00820ec:  90 10 20 01  mov  1, %o0
a00820f0:  92 10 20 18  mov  0x18, %o1
a00820f4:  40 00 94 cc  call  0xa00a7424
a00820f8:  94 10 00 15  mov  %l5, %o2
a00820fc:  96 14 a0 08  or  %l2, 8, %o3
a0082100:  90 10 20 00  clr  %o0
a0082104:  10 80 00 90  b  0xa0082344
a0082108:  92 10 20 18  mov  0x18, %o1
a008210c:  12 80 00 3c  bne  0xa00821fc
a0082110:  90 10 00 15  mov  %l5, %o0
a0082114:  92 14 a0 28  or  %l2, 0x28, %o1
a0082118:  94 14 63 ff  or  %l1, 0x3ff, %o2
a008211c:  40 00 94 db  call  0xa00a7488
a0082120:  17 00 00 80  sethi  %hi(0x20000), %o3
a0082124:  90 10 00 15  mov  %l5, %o0
a0082128:  92 14 e0 28  or  %l3, 0x28, %o1
a008212c:  94 14 63 ff  or  %l1, 0x3ff, %o2
a0082130:  40 00 94 d6  call  0xa00a7488
a0082134:  17 00 00 80  sethi  %hi(0x20000), %o3
a0082138:  90 10 00 15  mov  %l5, %o0
a008213c:  92 15 20 28  or  %l4, 0x28, %o1
a0082140:  94 14 63 ff  or  %l1, 0x3ff, %o2
a0082144:  40 00 94 d1  call  0xa00a7488
a0082148:  17 00 00 80  sethi  %hi(0x20000), %o3
a008214c:  90 10 00 15  mov  %l5, %o0
a0082150:  92 15 a0 28  or  %l6, 0x28, %o1
a0082154:  94 14 63 ff  or  %l1, 0x3ff, %o2
a0082158:  40 00 94 cc  call  0xa00a7488
a008215c:  17 00 00 80  sethi  %hi(0x20000), %o3
a0082160:  90 10 00 15  mov  %l5, %o0
a0082164:  92 14 a0 08  or  %l2, 8, %o1
a0082168:  94 14 63 ff  or  %l1, 0x3ff, %o2
a008216c:  40 00 94 c7  call  0xa00a7488
a0082170:  17 00 04 80  sethi  %hi(0x120000), %o3
a0082174:  90 10 00 15  mov  %l5, %o0
a0082178:  92 14 e0 08  or  %l3, 8, %o1
a008217c:  94 14 63 ff  or  %l1, 0x3ff, %o2
a0082180:  40 00 94 c2  call  0xa00a7488
a0082184:  17 00 04 80  sethi  %hi(0x120000), %o3
a0082188:  90 10 00 15  mov  %l5, %o0
a008218c:  92 15 20 08  or  %l4, 8, %o1
a0082190:  94 14 63 ff  or  %l1, 0x3ff, %o2
a0082194:  40 00 94 bd  call  0xa00a7488
a0082198:  17 00 04 80  sethi  %hi(0x120000), %o3
a008219c:  90 10 00 15  mov  %l5, %o0
a00821a0:  94 14 63 ff  or  %l1, 0x3ff, %o2
a00821a4:  92 15 a0 08  or  %l6, 8, %o1
a00821a8:  40 00 94 b8  call  0xa00a7488
a00821ac:  17 00 04 80  sethi  %hi(0x120000), %o3
a00821b0:  96 14 a0 70  or  %l2, 0x70, %o3
a00821b4:  94 10 00 15  mov  %l5, %o2
a00821b8:  90 10 20 01  mov  1, %o0
a00821bc:  40 00 94 9a  call  0xa00a7424
a00821c0:  92 10 20 03  mov  3, %o1
a00821c4:  96 14 e0 70  or  %l3, 0x70, %o3
a00821c8:  94 10 00 15  mov  %l5, %o2
a00821cc:  90 10 20 01  mov  1, %o0
a00821d0:  40 00 94 95  call  0xa00a7424
a00821d4:  92 10 20 03  mov  3, %o1
a00821d8:  96 15 20 70  or  %l4, 0x70, %o3
a00821dc:  90 10 20 01  mov  1, %o0
a00821e0:  92 10 20 03  mov  3, %o1
a00821e4:  40 00 94 90  call  0xa00a7424
a00821e8:  94 10 00 15  mov  %l5, %o2
a00821ec:  96 15 a0 70  or  %l6, 0x70, %o3
a00821f0:  90 10 20 01  mov  1, %o0
a00821f4:  10 80 00 54  b  0xa0082344
a00821f8:  92 10 20 03  mov  3, %o1
a00821fc:  92 14 a0 28  or  %l2, 0x28, %o1
a0082200:  94 14 63 ff  or  %l1, 0x3ff, %o2
a0082204:  40 00 94 a1  call  0xa00a7488
a0082208:  96 10 20 00  clr  %o3
a008220c:  90 10 00 15  mov  %l5, %o0
a0082210:  92 14 e0 28  or  %l3, 0x28, %o1
a0082214:  94 14 63 ff  or  %l1, 0x3ff, %o2
a0082218:  40 00 94 9c  call  0xa00a7488
a008221c:  96 10 20 00  clr  %o3
a0082220:  90 10 00 15  mov  %l5, %o0
a0082224:  92 15 20 28  or  %l4, 0x28, %o1
a0082228:  94 14 63 ff  or  %l1, 0x3ff, %o2
a008222c:  40 00 94 97  call  0xa00a7488
a0082230:  96 10 20 00  clr  %o3
a0082234:  90 10 00 15  mov  %l5, %o0
a0082238:  92 15 a0 28  or  %l6, 0x28, %o1
a008223c:  94 14 63 ff  or  %l1, 0x3ff, %o2
a0082240:  40 00 94 92  call  0xa00a7488
a0082244:  96 10 20 00  clr  %o3
a0082248:  90 10 00 15  mov  %l5, %o0
a008224c:  92 14 a0 08  or  %l2, 8, %o1
a0082250:  94 14 63 ff  or  %l1, 0x3ff, %o2
a0082254:  40 00 94 8d  call  0xa00a7488
a0082258:  17 00 04 00  sethi  %hi(0x100000), %o3
a008225c:  90 10 00 15  mov  %l5, %o0
a0082260:  92 14 e0 08  or  %l3, 8, %o1
a0082264:  94 14 63 ff  or  %l1, 0x3ff, %o2
a0082268:  40 00 94 88  call  0xa00a7488
a008226c:  17 00 04 00  sethi  %hi(0x100000), %o3
a0082270:  90 10 00 15  mov  %l5, %o0
a0082274:  92 15 20 08  or  %l4, 8, %o1
a0082278:  94 14 63 ff  or  %l1, 0x3ff, %o2
a008227c:  40 00 94 83  call  0xa00a7488
a0082280:  17 00 04 00  sethi  %hi(0x100000), %o3
a0082284:  90 10 00 15  mov  %l5, %o0
a0082288:  94 14 63 ff  or  %l1, 0x3ff, %o2
a008228c:  92 15 a0 08  or  %l6, 8, %o1
a0082290:  40 00 94 7e  call  0xa00a7488
a0082294:  17 00 04 00  sethi  %hi(0x100000), %o3
a0082298:  90 10 20 00  clr  %o0
a008229c:  92 10 20 03  mov  3, %o1
a00822a0:  94 10 00 15  mov  %l5, %o2
a00822a4:  40 00 94 60  call  0xa00a7424
a00822a8:  96 14 a0 70  or  %l2, 0x70, %o3
a00822ac:  90 10 20 00  clr  %o0
a00822b0:  92 10 20 03  mov  3, %o1
a00822b4:  94 10 00 15  mov  %l5, %o2
a00822b8:  40 00 94 5b  call  0xa00a7424
a00822bc:  96 14 e0 70  or  %l3, 0x70, %o3
a00822c0:  90 10 20 00  clr  %o0
a00822c4:  92 10 20 03  mov  3, %o1
a00822c8:  94 10 00 15  mov  %l5, %o2
a00822cc:  40 00 94 56  call  0xa00a7424
a00822d0:  96 15 20 70  or  %l4, 0x70, %o3
a00822d4:  90 10 20 00  clr  %o0
a00822d8:  92 10 20 03  mov  3, %o1
a00822dc:  94 10 00 15  mov  %l5, %o2
a00822e0:  40 00 94 51  call  0xa00a7424
a00822e4:  96 15 a0 70  or  %l6, 0x70, %o3
a00822e8:  90 10 20 00  clr  %o0
a00822ec:  92 10 20 18  mov  0x18, %o1
a00822f0:  94 10 00 15  mov  %l5, %o2
a00822f4:  40 00 94 4c  call  0xa00a7424
a00822f8:  96 14 a0 28  or  %l2, 0x28, %o3
a00822fc:  96 14 a0 28  or  %l2, 0x28, %o3
a0082300:  90 10 20 00  clr  %o0
a0082304:  92 10 20 11  mov  0x11, %o1
a0082308:  40 00 94 47  call  0xa00a7424
a008230c:  94 10 00 15  mov  %l5, %o2
a0082310:  96 14 e0 28  or  %l3, 0x28, %o3
a0082314:  90 10 20 00  clr  %o0
a0082318:  92 10 20 11  mov  0x11, %o1
a008231c:  40 00 94 42  call  0xa00a7424
a0082320:  94 10 00 15  mov  %l5, %o2
a0082324:  96 15 20 28  or  %l4, 0x28, %o3
a0082328:  90 10 20 00  clr  %o0
a008232c:  92 10 20 11  mov  0x11, %o1
a0082330:  40 00 94 3d  call  0xa00a7424
a0082334:  94 10 00 15  mov  %l5, %o2
a0082338:  96 15 a0 28  or  %l6, 0x28, %o3
a008233c:  90 10 20 00  clr  %o0
a0082340:  92 10 20 11  mov  0x11, %o1
a0082344:  40 00 94 38  call  0xa00a7424
a0082348:  94 10 00 15  mov  %l5, %o2
a008234c:  90 10 00 15  mov  %l5, %o0
a0082350:  13 00 00 0b  sethi  %hi(0x2c00), %o1
a0082354:  94 10 3f 00  mov  -256, %o2
a0082358:  40 00 94 4c  call  0xa00a7488
a008235c:  96 10 20 00  clr  %o3
a0082360:  d8 07 bf 18  ld  [ %fp + -232 ], %o4
a0082364:  82 0b 20 ff  and  %o4, 0xff, %g1
a0082368:  80 a0 60 01  cmp  %g1, 1
a008236c:  18 80 00 14  bgu  0xa00823bc
a0082370:  21 00 00 0b  sethi  %hi(0x2c00), %l0
a0082374:  94 10 00 15  mov  %l5, %o2
a0082378:  96 14 22 5c  or  %l0, 0x25c, %o3
a008237c:  90 10 20 01  mov  1, %o0
a0082380:  40 00 94 29  call  0xa00a7424
a0082384:  92 10 20 1b  mov  0x1b, %o1
a0082388:  94 10 00 15  mov  %l5, %o2
a008238c:  96 14 22 38  or  %l0, 0x238, %o3
a0082390:  90 10 20 01  mov  1, %o0
a0082394:  40 00 94 24  call  0xa00a7424
a0082398:  92 10 20 1b  mov  0x1b, %o1
a008239c:  90 10 00 15  mov  %l5, %o0
a00823a0:  96 10 20 07  mov  7, %o3
a00823a4:  92 14 22 00  or  %l0, 0x200, %o1
a00823a8:  40 00 94 38  call  0xa00a7488
a00823ac:  94 10 3f f0  mov  -16, %o2
a00823b0:  96 14 22 04  or  %l0, 0x204, %o3
a00823b4:  10 80 00 13  b  0xa0082400
a00823b8:  90 10 20 01  mov  1, %o0
a00823bc:  90 10 20 00  clr  %o0
a00823c0:  92 10 20 1b  mov  0x1b, %o1
a00823c4:  94 10 00 15  mov  %l5, %o2
a00823c8:  40 00 94 17  call  0xa00a7424
a00823cc:  96 14 22 5c  or  %l0, 0x25c, %o3
a00823d0:  90 10 20 00  clr  %o0
a00823d4:  92 10 20 1b  mov  0x1b, %o1
a00823d8:  94 10 00 15  mov  %l5, %o2
a00823dc:  40 00 94 12  call  0xa00a7424
a00823e0:  96 14 22 38  or  %l0, 0x238, %o3
a00823e4:  90 10 00 15  mov  %l5, %o0
a00823e8:  96 10 20 0f  mov  0xf, %o3
a00823ec:  92 14 22 00  or  %l0, 0x200, %o1
a00823f0:  40 00 94 26  call  0xa00a7488
a00823f4:  94 10 3f f0  mov  -16, %o2
a00823f8:  96 14 22 04  or  %l0, 0x204, %o3
a00823fc:  90 10 20 00  clr  %o0
a0082400:  94 10 00 15  mov  %l5, %o2
a0082404:  40 00 94 08  call  0xa00a7424
a0082408:  92 10 20 17  mov  0x17, %o1
a008240c:  40 00 bc e2  call  0xa00b1794
a0082410:  90 10 20 0a  mov  0xa, %o0
a0082414:  90 10 00 15  mov  %l5, %o0
a0082418:  92 10 20 00  clr  %o1
a008241c:  7f ff dc d7  call  0xa0079778
a0082420:  94 10 20 01  mov  1, %o2
a0082424:  40 00 bc dc  call  0xa00b1794
a0082428:  90 10 20 01  mov  1, %o0
a008242c:  2d 2a 01 f5  sethi  %hi(0xa807d400), %l6
a0082430:  aa 0e e0 ff  and  %i3, 0xff, %l5
a0082434:  82 15 a2 80  or  %l6, 0x280, %g1
a0082438:  9a 5d 60 b0  smul  %l5, 0xb0, %o5
a008243c:  c2 08 40 0d  ldub  [ %g1 + %o5 ], %g1
a0082440:  80 a0 60 00  cmp  %g1, 0
a0082444:  02 80 00 2f  be  0xa0082500
a0082448:  a4 10 20 00  clr  %l2
a008244c:  a2 0c a0 ff  and  %l2, 0xff, %l1
a0082450:  82 07 bf f8  add  %fp, -8, %g1
a0082454:  9a 04 40 11  add  %l1, %l1, %o5
a0082458:  90 0e 20 ff  and  %i0, 0xff, %o0
a008245c:  a6 00 40 11  add  %g1, %l1, %l3
a0082460:  a4 04 a0 01  inc  %l2
a0082464:  80 a4 60 03  cmp  %l1, 3
a0082468:  18 80 00 11  bgu  0xa00824ac
a008246c:  a8 03 40 01  add  %o5, %g1, %l4
a0082470:  03 28 02 ce  sethi  %hi(0xa00b3800), %g1
a0082474:  82 10 63 18  or  %g1, 0x318, %g1	! 0xa00b3b18
a0082478:  e0 10 40 0d  lduh  [ %g1 + %o5 ], %l0
a008247c:  40 00 93 a6  call  0xa00a7314
a0082480:  92 10 00 10  mov  %l0, %o1
a0082484:  90 0a 20 0f  and  %o0, 0xf, %o0
a0082488:  d0 2c ff 40  stb  %o0, [ %l3 + -192 ]
a008248c:  92 10 00 10  mov  %l0, %o1
a0082490:  40 00 93 a1  call  0xa00a7314
a0082494:  90 0e 20 ff  and  %i0, 0xff, %o0
a0082498:  03 00 3f ff  sethi  %hi(0xfffc00), %g1
a008249c:  82 10 63 00  or  %g1, 0x300, %g1	! 0xffff00
a00824a0:  90 0a 00 01  and  %o0, %g1, %o0
a00824a4:  91 32 20 08  srl  %o0, 8, %o0
a00824a8:  d0 35 3f 38  sth  %o0, [ %l4 + -200 ]
a00824ac:  9a 07 bf f8  add  %fp, -8, %o5
a00824b0:  82 04 40 11  add  %l1, %l1, %g1
a00824b4:  98 00 40 0d  add  %g1, %o5, %o4
a00824b8:  17 2a 01 e1  sethi  %hi(0xa8078400), %o3
a00824bc:  c2 02 e2 34  ld  [ %o3 + 0x234 ], %g1	! 0xa8078634
a00824c0:  11 28 01 a1  sethi  %hi(0xa0068400), %o0
a00824c4:  9a 03 40 11  add  %o5, %l1, %o5
a00824c8:  80 88 68 00  btst  0x800, %g1
a00824cc:  90 12 23 20  or  %o0, 0x320, %o0
a00824d0:  02 80 00 05  be  0xa00824e4
a00824d4:  92 10 00 11  mov  %l1, %o1
a00824d8:  d4 0b 7f 40  ldub  [ %o5 + -192 ], %o2
a00824dc:  7f ff c2 da  call  0xa0073044
a00824e0:  d6 13 3f 38  lduh  [ %o4 + -200 ], %o3
a00824e4:  82 5d 60 b0  smul  %l5, 0xb0, %g1
a00824e8:  9a 15 a2 80  or  %l6, 0x280, %o5
a00824ec:  da 0b 40 01  ldub  [ %o5 + %g1 ], %o5
a00824f0:  82 0c a0 ff  and  %l2, 0xff, %g1
a00824f4:  80 a0 40 0d  cmp  %g1, %o5
a00824f8:  2a bf ff d6  bcs,a   0xa0082450
a00824fc:  a2 0c a0 ff  and  %l2, 0xff, %l1
a0082500:  03 2a 01 f5  sethi  %hi(0xa807d400), %g1
a0082504:  9a 0e e0 ff  and  %i3, 0xff, %o5
a0082508:  98 10 62 80  or  %g1, 0x280, %o4
a008250c:  9a 5b 60 b0  smul  %o5, 0xb0, %o5
a0082510:  82 03 40 0c  add  %o5, %o4, %g1
a0082514:  c2 08 60 34  ldub  [ %g1 + 0x34 ], %g1
a0082518:  80 a0 60 00  cmp  %g1, 0
a008251c:  02 80 03 7f  be  0xa0083318
a0082520:  92 10 20 01  mov  1, %o1
a0082524:  c2 0b 00 0d  ldub  [ %o4 + %o5 ], %g1
a0082528:  80 a0 60 00  cmp  %g1, 0
a008252c:  02 80 00 15  be  0xa0082580
a0082530:  a4 10 20 00  clr  %l2
a0082534:  96 10 00 01  mov  %g1, %o3
a0082538:  94 07 bf f8  add  %fp, -8, %o2
a008253c:  82 0c a0 ff  and  %l2, 0xff, %g1
a0082540:  9a 00 40 01  add  %g1, %g1, %o5
a0082544:  82 02 80 01  add  %o2, %g1, %g1
a0082548:  a4 04 a0 01  inc  %l2
a008254c:  c2 08 7f 40  ldub  [ %g1 + -192 ], %g1
a0082550:  9a 03 40 0a  add  %o5, %o2, %o5
a0082554:  80 a0 60 0f  cmp  %g1, 0xf
a0082558:  12 80 00 06  bne  0xa0082570
a008255c:  98 0c a0 ff  and  %l2, 0xff, %o4
a0082560:  c2 13 7f 38  lduh  [ %o5 + -200 ], %g1
a0082564:  80 a0 60 07  cmp  %g1, 7
a0082568:  08 80 00 04  bleu  0xa0082578
a008256c:  80 a3 00 0b  cmp  %o4, %o3
a0082570:  92 10 20 00  clr  %o1
a0082574:  80 a3 00 0b  cmp  %o4, %o3
a0082578:  0a bf ff f2  bcs  0xa0082540
a008257c:  82 0c a0 ff  and  %l2, 0xff, %g1
a0082580:  80 8a 60 ff  btst  0xff, %o1
a0082584:  02 80 00 07  be  0xa00825a0
a0082588:  d8 07 bf 14  ld  [ %fp + -236 ], %o4
a008258c:  11 28 01 a1  sethi  %hi(0xa0068400), %o0
a0082590:  7f ff c3 cd  call  0xa00734c4
a0082594:  90 12 23 58  or  %o0, 0x358, %o0	! 0xa0068758
a0082598:  10 80 03 08  b  0xa00831b8
a008259c:  a0 0e 20 ff  and  %i0, 0xff, %l0
a00825a0:  82 0b 20 ff  and  %o4, 0xff, %g1
a00825a4:  80 a0 60 01  cmp  %g1, 1
a00825a8:  18 80 02 ec  bgu  0xa0083158
a00825ac:  aa 0e 60 ff  and  %i1, 0xff, %l5
a00825b0:  80 a5 60 06  cmp  %l5, 6
a00825b4:  a6 0e 20 ff  and  %i0, 0xff, %l3
a00825b8:  a8 0e e0 ff  and  %i3, 0xff, %l4
a00825bc:  12 80 00 19  bne  0xa0082620
a00825c0:  b8 07 bf 38  add  %fp, -200, %i4
a00825c4:  21 00 00 0d  sethi  %hi(0x3400), %l0
a00825c8:  25 00 00 2f  sethi  %hi(0xbc00), %l2
a00825cc:  90 10 00 13  mov  %l3, %o0
a00825d0:  92 14 22 0c  or  %l0, 0x20c, %o1
a00825d4:  96 14 a3 d0  or  %l2, 0x3d0, %o3
a00825d8:  40 00 93 ac  call  0xa00a7488
a00825dc:  15 3f ff c0  sethi  %hi(0xffff0000), %o2
a00825e0:  23 00 00 3f  sethi  %hi(0xfc00), %l1
a00825e4:  90 10 00 13  mov  %l3, %o0
a00825e8:  92 14 22 0c  or  %l0, 0x20c, %o1
a00825ec:  94 14 63 ff  or  %l1, 0x3ff, %o2
a00825f0:  40 00 93 a6  call  0xa00a7488
a00825f4:  17 2f f4 00  sethi  %hi(0xbfd00000), %o3
a00825f8:  90 10 00 13  mov  %l3, %o0
a00825fc:  96 14 a3 d0  or  %l2, 0x3d0, %o3
a0082600:  92 14 22 10  or  %l0, 0x210, %o1
a0082604:  40 00 93 a1  call  0xa00a7488
a0082608:  15 3f ff c0  sethi  %hi(0xffff0000), %o2
a008260c:  90 10 00 13  mov  %l3, %o0
a0082610:  92 14 22 10  or  %l0, 0x210, %o1
a0082614:  94 14 63 ff  or  %l1, 0x3ff, %o2
a0082618:  10 80 00 18  b  0xa0082678
a008261c:  17 2f f4 00  sethi  %hi(0xbfd00000), %o3
a0082620:  21 00 00 0d  sethi  %hi(0x3400), %l0
a0082624:  25 00 00 20  sethi  %hi(0x8000), %l2
a0082628:  90 10 00 13  mov  %l3, %o0
a008262c:  92 14 22 0c  or  %l0, 0x20c, %o1
a0082630:  15 3f ff c0  sethi  %hi(0xffff0000), %o2
a0082634:  40 00 93 95  call  0xa00a7488
a0082638:  96 14 a3 d0  or  %l2, 0x3d0, %o3
a008263c:  23 00 00 3f  sethi  %hi(0xfc00), %l1
a0082640:  90 10 00 13  mov  %l3, %o0
a0082644:  92 14 22 0c  or  %l0, 0x20c, %o1
a0082648:  94 14 63 ff  or  %l1, 0x3ff, %o2
a008264c:  40 00 93 8f  call  0xa00a7488
a0082650:  17 20 f4 00  sethi  %hi(0x83d00000), %o3
a0082654:  90 10 00 13  mov  %l3, %o0
a0082658:  96 14 a3 d0  or  %l2, 0x3d0, %o3
a008265c:  92 14 22 10  or  %l0, 0x210, %o1
a0082660:  40 00 93 8a  call  0xa00a7488
a0082664:  15 3f ff c0  sethi  %hi(0xffff0000), %o2
a0082668:  90 10 00 13  mov  %l3, %o0
a008266c:  92 14 22 10  or  %l0, 0x210, %o1
a0082670:  94 14 63 ff  or  %l1, 0x3ff, %o2
a0082674:  17 20 f4 00  sethi  %hi(0x83d00000), %o3
a0082678:  40 00 93 84  call  0xa00a7488
a008267c:  a2 0e 20 ff  and  %i0, 0xff, %l1
a0082680:  11 28 01 a1  sethi  %hi(0xa0068400), %o0
a0082684:  7f ff c3 90  call  0xa00734c4
a0082688:  90 12 23 70  or  %o0, 0x370, %o0	! 0xa0068770
a008268c:  17 00 00 0b  sethi  %hi(0x2c00), %o3
a0082690:  96 12 e2 5c  or  %o3, 0x25c, %o3	! 0x2e5c
a0082694:  94 10 00 11  mov  %l1, %o2
a0082698:  90 10 20 01  mov  1, %o0
a008269c:  40 00 93 62  call  0xa00a7424
a00826a0:  92 10 20 17  mov  0x17, %o1
a00826a4:  82 10 20 0f  mov  0xf, %g1
a00826a8:  9a 10 20 ff  mov  0xff, %o5
a00826ac:  c2 2f bf 3b  stb  %g1, [ %fp + -197 ]
a00826b0:  da 37 bf 36  sth  %o5, [ %fp + -202 ]
a00826b4:  c2 2f bf 38  stb  %g1, [ %fp + -200 ]
a00826b8:  da 37 bf 30  sth  %o5, [ %fp + -208 ]
a00826bc:  c2 2f bf 39  stb  %g1, [ %fp + -199 ]
a00826c0:  da 37 bf 32  sth  %o5, [ %fp + -206 ]
a00826c4:  c2 2f bf 3a  stb  %g1, [ %fp + -198 ]
a00826c8:  da 37 bf 34  sth  %o5, [ %fp + -204 ]
a00826cc:  90 10 00 11  mov  %l1, %o0
a00826d0:  7f ff dc d4  call  0xa0079a20
a00826d4:  92 10 20 0f  mov  0xf, %o1
a00826d8:  90 10 00 11  mov  %l1, %o0
a00826dc:  92 10 20 0f  mov  0xf, %o1
a00826e0:  94 10 00 1c  mov  %i4, %o2
a00826e4:  7f ff e0 b7  call  0xa007a9c0
a00826e8:  96 07 bf 30  add  %fp, -208, %o3
a00826ec:  03 2a 01 f5  sethi  %hi(0xa807d400), %g1
a00826f0:  9a 5d 20 b0  smul  %l4, 0xb0, %o5
a00826f4:  82 10 62 80  or  %g1, 0x280, %g1
a00826f8:  c2 08 40 0d  ldub  [ %g1 + %o5 ], %g1
a00826fc:  80 a0 60 00  cmp  %g1, 0
a0082700:  a4 10 20 00  clr  %l2
a0082704:  02 80 00 10  be  0xa0082744
a0082708:  27 2a 01 f5  sethi  %hi(0xa807d400), %l3
a008270c:  92 0c a0 ff  and  %l2, 0xff, %o1
a0082710:  a0 07 bf f8  add  %fp, -8, %l0
a0082714:  a0 04 00 09  add  %l0, %o1, %l0
a0082718:  90 10 00 11  mov  %l1, %o0
a008271c:  7f ff dc ea  call  0xa0079ac4
a0082720:  94 10 00 15  mov  %l5, %o2
a0082724:  82 5d 20 b0  smul  %l4, 0xb0, %g1
a0082728:  9a 14 e2 80  or  %l3, 0x280, %o5
a008272c:  da 0b 40 01  ldub  [ %o5 + %g1 ], %o5
a0082730:  a4 04 a0 01  inc  %l2
a0082734:  82 0c a0 ff  and  %l2, 0xff, %g1
a0082738:  80 a0 40 0d  cmp  %g1, %o5
a008273c:  0a bf ff f4  bcs  0xa008270c
a0082740:  d0 2c 3f f0  stb  %o0, [ %l0 + -16 ]
a0082744:  a6 10 20 00  clr  %l3
a0082748:  a2 0c e0 ff  and  %l3, 0xff, %l1
a008274c:  82 04 40 11  add  %l1, %l1, %g1
a0082750:  d4 0f bf e8  ldub  [ %fp + -24 ], %o2
a0082754:  d2 0f bf e9  ldub  [ %fp + -23 ], %o1
a0082758:  d6 0f bf eb  ldub  [ %fp + -21 ], %o3
a008275c:  da 0f bf ea  ldub  [ %fp + -22 ], %o5
a0082760:  96 00 40 0b  add  %g1, %o3, %o3
a0082764:  94 00 40 0a  add  %g1, %o2, %o2
a0082768:  92 00 40 09  add  %g1, %o1, %o1
a008276c:  82 00 40 0d  add  %g1, %o5, %g1
a0082770:  9a 10 20 01  mov  1, %o5
a0082774:  97 2b 40 0b  sll  %o5, %o3, %o3
a0082778:  95 2b 40 0a  sll  %o5, %o2, %o2
a008277c:  93 2b 40 09  sll  %o5, %o1, %o1
a0082780:  9b 2b 40 01  sll  %o5, %g1, %o5
a0082784:  a5 2c 60 02  sll  %l1, 2, %l2
a0082788:  82 07 bf f8  add  %fp, -8, %g1
a008278c:  90 04 80 01  add  %l2, %g1, %o0
a0082790:  a3 2c 60 03  sll  %l1, 3, %l1
a0082794:  82 04 40 01  add  %l1, %g1, %g1
a0082798:  98 10 20 08  mov  8, %o4
a008279c:  92 02 7f ff  add  %o1, -1, %o1
a00827a0:  9a 03 7f ff  add  %o5, -1, %o5
a00827a4:  d2 30 7f aa  sth  %o1, [ %g1 + -86 ]
a00827a8:  d8 2a 3f e3  stb  %o4, [ %o0 + -29 ]
a00827ac:  d8 2a 3f e0  stb  %o4, [ %o0 + -32 ]
a00827b0:  d8 2a 3f e1  stb  %o4, [ %o0 + -31 ]
a00827b4:  d8 2a 3f e2  stb  %o4, [ %o0 + -30 ]
a00827b8:  a0 0e 20 ff  and  %i0, 0xff, %l0
a00827bc:  94 02 bf ff  add  %o2, -1, %o2
a00827c0:  96 02 ff ff  add  %o3, -1, %o3
a00827c4:  d6 30 7f ae  sth  %o3, [ %g1 + -82 ]
a00827c8:  d4 30 7f a8  sth  %o2, [ %g1 + -88 ]
a00827cc:  da 30 7f ac  sth  %o5, [ %g1 + -84 ]
a00827d0:  90 10 00 10  mov  %l0, %o0
a00827d4:  7f ff df f2  call  0xa007a79c
a00827d8:  92 10 20 0f  mov  0xf, %o1
a00827dc:  ae 07 bf d8  add  %fp, -40, %l7
a00827e0:  ba 07 bf a0  add  %fp, -96, %i5
a00827e4:  94 05 c0 12  add  %l7, %l2, %o2
a00827e8:  96 07 40 11  add  %i5, %l1, %o3
a00827ec:  92 10 20 0f  mov  0xf, %o1
a00827f0:  7f ff f6 b7  call  0xa00802cc
a00827f4:  90 10 00 10  mov  %l0, %o0
a00827f8:  40 00 bb e7  call  0xa00b1794
a00827fc:  90 10 20 01  mov  1, %o0
a0082800:  7f ff df 8c  call  0xa007a630
a0082804:  90 10 00 10  mov  %l0, %o0
a0082808:  7f ff df ba  call  0xa007a6f0
a008280c:  90 10 00 10  mov  %l0, %o0
a0082810:  40 00 bb e1  call  0xa00b1794
a0082814:  90 10 20 01  mov  1, %o0
a0082818:  7f ff dc a5  call  0xa0079aac
a008281c:  90 10 00 10  mov  %l0, %o0
a0082820:  2b 2a 01 f5  sethi  %hi(0xa807d400), %l5
a0082824:  a8 0e e0 ff  and  %i3, 0xff, %l4
a0082828:  9a 15 62 80  or  %l5, 0x280, %o5
a008282c:  82 5d 20 b0  smul  %l4, 0xb0, %g1
a0082830:  c2 0b 40 01  ldub  [ %o5 + %g1 ], %g1
a0082834:  80 a0 60 00  cmp  %g1, 0
a0082838:  02 80 00 26  be  0xa00828d0
a008283c:  a4 10 20 00  clr  %l2
a0082840:  9a 0c e0 ff  and  %l3, 0xff, %o5
a0082844:  9b 2b 60 02  sll  %o5, 2, %o5
a0082848:  82 07 bf f8  add  %fp, -8, %g1
a008284c:  a2 0c a0 ff  and  %l2, 0xff, %l1
a0082850:  9a 03 40 01  add  %o5, %g1, %o5
a0082854:  90 0e 20 ff  and  %i0, 0xff, %o0
a0082858:  a4 04 a0 01  inc  %l2
a008285c:  98 04 40 11  add  %l1, %l1, %o4
a0082860:  80 a4 60 03  cmp  %l1, 3
a0082864:  18 80 00 08  bgu  0xa0082884
a0082868:  a0 03 40 11  add  %o5, %l1, %l0
a008286c:  03 28 02 ce  sethi  %hi(0xa00b3800), %g1
a0082870:  82 10 63 18  or  %g1, 0x318, %g1	! 0xa00b3b18
a0082874:  40 00 92 a8  call  0xa00a7314
a0082878:  d2 10 40 0c  lduh  [ %g1 + %o4 ], %o1
a008287c:  90 0a 20 0f  and  %o0, 0xf, %o0
a0082880:  d0 2c 3f e0  stb  %o0, [ %l0 + -32 ]
a0082884:  a0 0c e0 ff  and  %l3, 0xff, %l0
a0082888:  a1 2c 20 02  sll  %l0, 2, %l0
a008288c:  82 07 bf f8  add  %fp, -8, %g1
a0082890:  a0 04 00 11  add  %l0, %l1, %l0
a0082894:  9a 00 40 11  add  %g1, %l1, %o5
a0082898:  a0 04 00 10  add  %l0, %l0, %l0
a008289c:  a0 04 00 01  add  %l0, %g1, %l0
a00828a0:  d6 0b 7f f0  ldub  [ %o5 + -16 ], %o3
a00828a4:  92 10 00 11  mov  %l1, %o1
a00828a8:  90 0e 20 ff  and  %i0, 0xff, %o0
a00828ac:  7f ff dc b6  call  0xa0079b84
a00828b0:  94 0e 60 ff  and  %i1, 0xff, %o2
a00828b4:  82 5d 20 b0  smul  %l4, 0xb0, %g1
a00828b8:  9a 15 62 80  or  %l5, 0x280, %o5
a00828bc:  da 0b 40 01  ldub  [ %o5 + %g1 ], %o5
a00828c0:  82 0c a0 ff  and  %l2, 0xff, %g1
a00828c4:  80 a0 40 0d  cmp  %g1, %o5
a00828c8:  0a bf ff de  bcs  0xa0082840
a00828cc:  d0 34 3f 80  sth  %o0, [ %l0 + -128 ]
a00828d0:  a6 04 e0 01  inc  %l3
a00828d4:  82 0c e0 ff  and  %l3, 0xff, %g1
a00828d8:  80 a0 60 03  cmp  %g1, 3
a00828dc:  08 bf ff 9c  bleu  0xa008274c
a00828e0:  a2 0c e0 ff  and  %l3, 0xff, %l1
a00828e4:  a6 10 20 00  clr  %l3
a00828e8:  9a 0e e0 ff  and  %i3, 0xff, %o5
a00828ec:  03 2a 01 f5  sethi  %hi(0xa807d400), %g1
a00828f0:  9a 5b 60 b0  smul  %o5, 0xb0, %o5
a00828f4:  82 10 62 80  or  %g1, 0x280, %g1
a00828f8:  da 08 40 0d  ldub  [ %g1 + %o5 ], %o5
a00828fc:  80 a3 60 00  cmp  %o5, 0
a0082900:  ac 10 20 00  clr  %l6
a0082904:  02 80 00 1f  be  0xa0082980
a0082908:  a4 10 20 00  clr  %l2
a008290c:  82 0c e0 ff  and  %l3, 0xff, %g1
a0082910:  9f 28 60 02  sll  %g1, 2, %o7
a0082914:  90 07 bf f8  add  %fp, -8, %o0
a0082918:  a8 00 40 01  add  %g1, %g1, %l4
a008291c:  a2 10 00 0d  mov  %o5, %l1
a0082920:  a0 03 c0 08  add  %o7, %o0, %l0
a0082924:  aa 10 20 01  mov  1, %l5
a0082928:  98 0c a0 ff  and  %l2, 0xff, %o4
a008292c:  92 04 00 0c  add  %l0, %o4, %o1
a0082930:  82 03 c0 0c  add  %o7, %o4, %g1
a0082934:  82 00 40 01  add  %g1, %g1, %g1
a0082938:  da 0a 7f e0  ldub  [ %o1 + -32 ], %o5
a008293c:  9b 2d 40 0d  sll  %l5, %o5, %o5
a0082940:  82 00 40 08  add  %g1, %o0, %g1
a0082944:  a4 04 a0 01  inc  %l2
a0082948:  96 02 00 0c  add  %o0, %o4, %o3
a008294c:  9a 03 7f ff  add  %o5, -1, %o5
a0082950:  c2 10 7f a8  lduh  [ %g1 + -88 ], %g1
a0082954:  94 0c a0 ff  and  %l2, 0xff, %o2
a0082958:  80 a3 40 01  cmp  %o5, %g1
a008295c:  16 80 00 06  bge  0xa0082974
a0082960:  99 2d 40 0c  sll  %l5, %o4, %o4
a0082964:  c2 0a ff f0  ldub  [ %o3 + -16 ], %g1
a0082968:  82 05 00 01  add  %l4, %g1, %g1
a008296c:  ac 13 00 16  or  %o4, %l6, %l6
a0082970:  c2 2a 7f e0  stb  %g1, [ %o1 + -32 ]
a0082974:  80 a2 80 11  cmp  %o2, %l1
a0082978:  0a bf ff ed  bcs  0xa008292c
a008297c:  98 0c a0 ff  and  %l2, 0xff, %o4
a0082980:  94 0c e0 ff  and  %l3, 0xff, %o2
a0082984:  97 2a a0 03  sll  %o2, 3, %o3
a0082988:  95 2a a0 02  sll  %o2, 2, %o2
a008298c:  94 05 c0 0a  add  %l7, %o2, %o2
a0082990:  96 07 40 0b  add  %i5, %o3, %o3
a0082994:  90 0e 20 ff  and  %i0, 0xff, %o0
a0082998:  7f ff e0 0a  call  0xa007a9c0
a008299c:  92 10 20 0f  mov  0xf, %o1
a00829a0:  2b 2a 01 f5  sethi  %hi(0xa807d400), %l5
a00829a4:  a8 0e e0 ff  and  %i3, 0xff, %l4
a00829a8:  9a 15 62 80  or  %l5, 0x280, %o5
a00829ac:  82 5d 20 b0  smul  %l4, 0xb0, %g1
a00829b0:  c2 0b 40 01  ldub  [ %o5 + %g1 ], %g1
a00829b4:  80 a0 60 00  cmp  %g1, 0
a00829b8:  02 80 00 79  be  0xa0082b9c
a00829bc:  a4 10 20 00  clr  %l2
a00829c0:  82 0d a0 ff  and  %l6, 0xff, %g1
a00829c4:  a2 0c a0 ff  and  %l2, 0xff, %l1
a00829c8:  83 38 40 11  sra  %g1, %l1, %g1
a00829cc:  80 88 60 01  btst  1, %g1
a00829d0:  02 80 00 10  be  0xa0082a10
a00829d4:  80 a4 60 00  cmp  %l1, 0
a00829d8:  a0 0c e0 ff  and  %l3, 0xff, %l0
a00829dc:  a1 2c 20 02  sll  %l0, 2, %l0
a00829e0:  82 07 bf f8  add  %fp, -8, %g1
a00829e4:  a0 04 00 11  add  %l0, %l1, %l0
a00829e8:  9a 00 40 11  add  %g1, %l1, %o5
a00829ec:  a0 04 00 10  add  %l0, %l0, %l0
a00829f0:  a0 04 00 01  add  %l0, %g1, %l0
a00829f4:  d6 0b 7f f0  ldub  [ %o5 + -16 ], %o3
a00829f8:  90 0e 20 ff  and  %i0, 0xff, %o0
a00829fc:  92 10 00 11  mov  %l1, %o1
a0082a00:  7f ff dc 61  call  0xa0079b84
a0082a04:  94 0e 60 ff  and  %i1, 0xff, %o2
a0082a08:  d0 34 3f 80  sth  %o0, [ %l0 + -128 ]
a0082a0c:  80 a4 60 00  cmp  %l1, 0
a0082a10:  12 80 00 09  bne  0xa0082a34
a0082a14:  80 a4 60 01  cmp  %l1, 1
a0082a18:  a0 0c e0 ff  and  %l3, 0xff, %l0
a0082a1c:  a1 2c 20 03  sll  %l0, 3, %l0
a0082a20:  82 07 bf f8  add  %fp, -8, %g1
a0082a24:  13 00 00 0b  sethi  %hi(0x2c00), %o1
a0082a28:  a0 04 00 01  add  %l0, %g1, %l0
a0082a2c:  10 80 00 13  b  0xa0082a78
a0082a30:  92 12 62 64  or  %o1, 0x264, %o1
a0082a34:  12 80 00 09  bne  0xa0082a58
a0082a38:  80 a4 60 02  cmp  %l1, 2
a0082a3c:  a0 0c e0 ff  and  %l3, 0xff, %l0
a0082a40:  a1 2c 20 03  sll  %l0, 3, %l0
a0082a44:  a0 04 00 1e  add  %l0, %fp, %l0
a0082a48:  13 00 00 0b  sethi  %hi(0x2c00), %o1
a0082a4c:  a0 04 3f fa  add  %l0, -6, %l0
a0082a50:  10 80 00 18  b  0xa0082ab0
a0082a54:  92 12 62 64  or  %o1, 0x264, %o1
a0082a58:  12 80 00 0e  bne  0xa0082a90
a0082a5c:  80 a4 60 03  cmp  %l1, 3
a0082a60:  a0 0c e0 ff  and  %l3, 0xff, %l0
a0082a64:  a1 2c 20 03  sll  %l0, 3, %l0
a0082a68:  a0 04 00 1e  add  %l0, %fp, %l0
a0082a6c:  13 00 00 0b  sethi  %hi(0x2c00), %o1
a0082a70:  a0 04 3f fc  add  %l0, -4, %l0
a0082a74:  92 12 62 68  or  %o1, 0x268, %o1
a0082a78:  40 00 92 27  call  0xa00a7314
a0082a7c:  90 0e 20 ff  and  %i0, 0xff, %o0
a0082a80:  03 3f ff e0  sethi  %hi(0xffff8000), %g1
a0082a84:  82 2a 00 01  andn  %o0, %g1, %g1
a0082a88:  10 80 00 0f  b  0xa0082ac4
a0082a8c:  c2 34 3f 50  sth  %g1, [ %l0 + -176 ]
a0082a90:  12 80 00 0e  bne  0xa0082ac8
a0082a94:  98 0c e0 ff  and  %l3, 0xff, %o4
a0082a98:  a0 0c e0 ff  and  %l3, 0xff, %l0
a0082a9c:  a1 2c 20 03  sll  %l0, 3, %l0
a0082aa0:  a0 04 00 1e  add  %l0, %fp, %l0
a0082aa4:  13 00 00 0b  sethi  %hi(0x2c00), %o1
a0082aa8:  a0 04 3f fe  add  %l0, -2, %l0
a0082aac:  92 12 62 68  or  %o1, 0x268, %o1
a0082ab0:  40 00 92 19  call  0xa00a7314
a0082ab4:  90 0e 20 ff  and  %i0, 0xff, %o0
a0082ab8:  90 02 00 08  add  %o0, %o0, %o0
a0082abc:  91 32 20 11  srl  %o0, 0x11, %o0
a0082ac0:  d0 34 3f 50  sth  %o0, [ %l0 + -176 ]
a0082ac4:  98 0c e0 ff  and  %l3, 0xff, %o4
a0082ac8:  83 2b 20 02  sll  %o4, 2, %g1
a0082acc:  82 00 40 11  add  %g1, %l1, %g1
a0082ad0:  82 00 40 01  add  %g1, %g1, %g1
a0082ad4:  90 07 bf f8  add  %fp, -8, %o0
a0082ad8:  94 00 40 08  add  %g1, %o0, %o2
a0082adc:  da 17 bf 2e  lduh  [ %fp + -210 ], %o5
a0082ae0:  de 12 bf 50  lduh  [ %o2 + -176 ], %o7
a0082ae4:  83 2b 60 10  sll  %o5, 0x10, %g1
a0082ae8:  97 30 60 10  srl  %g1, 0x10, %o3
a0082aec:  80 a3 e0 00  cmp  %o7, 0
a0082af0:  02 80 00 07  be  0xa0082b0c
a0082af4:  a0 10 00 0f  mov  %o7, %l0
a0082af8:  82 10 20 01  mov  1, %g1
a0082afc:  83 28 40 0c  sll  %g1, %o4, %g1
a0082b00:  9b 2c 60 02  sll  %l1, 2, %o5
a0082b04:  83 28 40 0d  sll  %g1, %o5, %g1
a0082b08:  96 12 c0 01  or  %o3, %g1, %o3
a0082b0c:  82 10 20 01  mov  1, %g1
a0082b10:  83 28 40 0c  sll  %g1, %o4, %g1
a0082b14:  9b 2a e0 10  sll  %o3, 0x10, %o5
a0082b18:  99 2c 60 02  sll  %l1, 2, %o4
a0082b1c:  83 28 40 0c  sll  %g1, %o4, %g1
a0082b20:  9b 33 60 10  srl  %o5, 0x10, %o5
a0082b24:  80 8b 40 01  btst  %o5, %g1
a0082b28:  92 04 a0 01  add  %l2, 1, %o1
a0082b2c:  d6 37 bf 2e  sth  %o3, [ %fp + -210 ]
a0082b30:  12 80 00 0c  bne  0xa0082b60
a0082b34:  82 04 40 11  add  %l1, %l1, %g1
a0082b38:  98 00 40 08  add  %g1, %o0, %o4
a0082b3c:  da 12 bf 80  lduh  [ %o2 + -128 ], %o5
a0082b40:  c2 13 3f 78  lduh  [ %o4 + -136 ], %g1
a0082b44:  80 a3 40 01  cmp  %o5, %g1
a0082b48:  0a 80 00 0f  bcs  0xa0082b84
a0082b4c:  82 5d 20 b0  smul  %l4, 0xb0, %g1
a0082b50:  82 02 00 11  add  %o0, %l1, %g1
a0082b54:  da 33 3f 78  sth  %o5, [ %o4 + -136 ]
a0082b58:  10 80 00 0a  b  0xa0082b80
a0082b5c:  e6 28 7f d0  stb  %l3, [ %g1 + -48 ]
a0082b60:  9a 00 40 08  add  %g1, %o0, %o5
a0082b64:  c2 13 7f 48  lduh  [ %o5 + -184 ], %g1
a0082b68:  80 a3 c0 01  cmp  %o7, %g1
a0082b6c:  18 80 00 06  bgu  0xa0082b84
a0082b70:  82 5d 20 b0  smul  %l4, 0xb0, %g1
a0082b74:  82 02 00 11  add  %o0, %l1, %g1
a0082b78:  e0 33 7f 48  sth  %l0, [ %o5 + -184 ]
a0082b7c:  e6 28 7f c8  stb  %l3, [ %g1 + -56 ]
a0082b80:  82 5d 20 b0  smul  %l4, 0xb0, %g1
a0082b84:  9a 15 62 80  or  %l5, 0x280, %o5
a0082b88:  da 0b 40 01  ldub  [ %o5 + %g1 ], %o5
a0082b8c:  82 0a 60 ff  and  %o1, 0xff, %g1
a0082b90:  80 a0 40 0d  cmp  %g1, %o5
a0082b94:  0a bf ff 8b  bcs  0xa00829c0
a0082b98:  a4 10 00 09  mov  %o1, %l2
a0082b9c:  a6 04 e0 01  inc  %l3
a0082ba0:  82 0c e0 ff  and  %l3, 0xff, %g1
a0082ba4:  80 a0 60 03  cmp  %g1, 3
a0082ba8:  08 bf ff 51  bleu  0xa00828ec
a0082bac:  9a 0e e0 ff  and  %i3, 0xff, %o5
a0082bb0:  03 2a 01 f5  sethi  %hi(0xa807d400), %g1
a0082bb4:  9a 5b 60 b0  smul  %o5, 0xb0, %o5
a0082bb8:  82 10 62 80  or  %g1, 0x280, %g1
a0082bbc:  da 08 40 0d  ldub  [ %g1 + %o5 ], %o5
a0082bc0:  80 a3 60 00  cmp  %o5, 0
a0082bc4:  02 80 00 2f  be  0xa0082c80
a0082bc8:  a4 10 20 00  clr  %l2
a0082bcc:  d6 17 bf 2e  lduh  [ %fp + -210 ], %o3
a0082bd0:  83 2a e0 10  sll  %o3, 0x10, %g1
a0082bd4:  a7 30 60 10  srl  %g1, 0x10, %l3
a0082bd8:  a2 10 00 0d  mov  %o5, %l1
a0082bdc:  96 07 bf f8  add  %fp, -8, %o3
a0082be0:  98 0c a0 ff  and  %l2, 0xff, %o4
a0082be4:  83 2b 20 02  sll  %o4, 2, %g1
a0082be8:  83 3c c0 01  sra  %l3, %g1, %g1
a0082bec:  82 08 60 0f  and  %g1, 0xf, %g1
a0082bf0:  80 a0 60 0f  cmp  %g1, 0xf
a0082bf4:  82 03 00 0c  add  %o4, %o4, %g1
a0082bf8:  9e 02 c0 0c  add  %o3, %o4, %o7
a0082bfc:  92 04 a0 01  add  %l2, 1, %o1
a0082c00:  12 80 00 0f  bne  0xa0082c3c
a0082c04:  94 00 40 0b  add  %g1, %o3, %o2
a0082c08:  c2 0b ff c8  ldub  [ %o7 + -56 ], %g1
a0082c0c:  83 28 60 02  sll  %g1, 2, %g1
a0082c10:  9a 00 40 0c  add  %g1, %o4, %o5
a0082c14:  9a 03 40 0d  add  %o5, %o5, %o5
a0082c18:  82 00 40 0b  add  %g1, %o3, %g1
a0082c1c:  82 00 40 0c  add  %g1, %o4, %g1
a0082c20:  9a 03 40 0b  add  %o5, %o3, %o5
a0082c24:  c2 08 7f e0  ldub  [ %g1 + -32 ], %g1
a0082c28:  da 13 7f a8  lduh  [ %o5 + -88 ], %o5
a0082c2c:  c2 2b ff d8  stb  %g1, [ %o7 + -40 ]
a0082c30:  da 32 bf a0  sth  %o5, [ %o2 + -96 ]
a0082c34:  10 80 00 0f  b  0xa0082c70
a0082c38:  c0 32 bf 78  clrh  [ %o2 + -136 ]
a0082c3c:  c2 0b ff d0  ldub  [ %o7 + -48 ], %g1
a0082c40:  83 28 60 02  sll  %g1, 2, %g1
a0082c44:  9a 00 40 0c  add  %g1, %o4, %o5
a0082c48:  9a 03 40 0d  add  %o5, %o5, %o5
a0082c4c:  82 00 40 0b  add  %g1, %o3, %g1
a0082c50:  82 00 40 0c  add  %g1, %o4, %g1
a0082c54:  9a 03 40 0b  add  %o5, %o3, %o5
a0082c58:  d8 13 7f a8  lduh  [ %o5 + -88 ], %o4
a0082c5c:  c2 08 7f e0  ldub  [ %g1 + -32 ], %g1
a0082c60:  da 13 7f 80  lduh  [ %o5 + -128 ], %o5
a0082c64:  c2 2b ff d8  stb  %g1, [ %o7 + -40 ]
a0082c68:  d8 32 bf a0  sth  %o4, [ %o2 + -96 ]
a0082c6c:  da 32 bf 78  sth  %o5, [ %o2 + -136 ]
a0082c70:  82 0a 60 ff  and  %o1, 0xff, %g1
a0082c74:  80 a0 40 11  cmp  %g1, %l1
a0082c78:  0a bf ff da  bcs  0xa0082be0
a0082c7c:  a4 10 00 09  mov  %o1, %l2
a0082c80:  9a 0e e0 ff  and  %i3, 0xff, %o5
a0082c84:  03 2a 01 f5  sethi  %hi(0xa807d400), %g1
a0082c88:  9a 5b 60 b0  smul  %o5, 0xb0, %o5
a0082c8c:  82 10 62 80  or  %g1, 0x280, %g1
a0082c90:  c2 08 40 0d  ldub  [ %g1 + %o5 ], %g1
a0082c94:  80 a0 60 00  cmp  %g1, 0
a0082c98:  02 80 00 1d  be  0xa0082d0c
a0082c9c:  a4 10 20 00  clr  %l2
a0082ca0:  94 10 00 01  mov  %g1, %o2
a0082ca4:  9e 07 bf f8  add  %fp, -8, %o7
a0082ca8:  90 10 20 01  mov  1, %o0
a0082cac:  92 10 20 0f  mov  0xf, %o1
a0082cb0:  82 0c a0 ff  and  %l2, 0xff, %g1
a0082cb4:  9a 03 c0 01  add  %o7, %g1, %o5
a0082cb8:  d8 0b 7f d8  ldub  [ %o5 + -40 ], %o4
a0082cbc:  97 2a 00 01  sll  %o0, %g1, %o3
a0082cc0:  82 0b 20 ff  and  %o4, 0xff, %g1
a0082cc4:  80 a0 60 0f  cmp  %g1, 0xf
a0082cc8:  12 80 00 07  bne  0xa0082ce4
a0082ccc:  80 a0 60 0e  cmp  %g1, 0xe
a0082cd0:  c2 2b 7f 40  stb  %g1, [ %o5 + -192 ]
a0082cd4:  d8 0f bf 27  ldub  [ %fp + -217 ], %o4
a0082cd8:  98 12 c0 0c  or  %o3, %o4, %o4
a0082cdc:  10 80 00 07  b  0xa0082cf8
a0082ce0:  d8 2f bf 27  stb  %o4, [ %fp + -217 ]
a0082ce4:  12 80 00 04  bne  0xa0082cf4
a0082ce8:  82 03 20 02  add  %o4, 2, %g1
a0082cec:  10 80 00 03  b  0xa0082cf8
a0082cf0:  d2 2b 7f 40  stb  %o1, [ %o5 + -192 ]
a0082cf4:  c2 2b 7f 40  stb  %g1, [ %o5 + -192 ]
a0082cf8:  a4 04 a0 01  inc  %l2
a0082cfc:  82 0c a0 ff  and  %l2, 0xff, %g1
a0082d00:  80 a0 40 0a  cmp  %g1, %o2
a0082d04:  0a bf ff ed  bcs  0xa0082cb8
a0082d08:  9a 03 c0 01  add  %o7, %g1, %o5
a0082d0c:  c2 0f bf 27  ldub  [ %fp + -217 ], %g1
a0082d10:  80 a0 60 0f  cmp  %g1, 0xf
a0082d14:  02 80 00 7c  be  0xa0082f04
a0082d18:  da 0f bf 27  ldub  [ %fp + -217 ], %o5
a0082d1c:  92 38 00 0d  xnor  %g0, %o5, %o1
a0082d20:  a6 0e 20 ff  and  %i0, 0xff, %l3
a0082d24:  92 0a 60 0f  and  %o1, 0xf, %o1
a0082d28:  90 10 00 13  mov  %l3, %o0
a0082d2c:  94 10 00 1c  mov  %i4, %o2
a0082d30:  7f ff df 24  call  0xa007a9c0
a0082d34:  96 07 bf 98  add  %fp, -104, %o3
a0082d38:  2d 2a 01 f5  sethi  %hi(0xa807d400), %l6
a0082d3c:  aa 0e e0 ff  and  %i3, 0xff, %l5
a0082d40:  9a 15 a2 80  or  %l6, 0x280, %o5
a0082d44:  82 5d 60 b0  smul  %l5, 0xb0, %g1
a0082d48:  c2 0b 40 01  ldub  [ %o5 + %g1 ], %g1
a0082d4c:  80 a0 60 00  cmp  %g1, 0
a0082d50:  02 bf ff ef  be  0xa0082d0c
a0082d54:  a4 10 20 00  clr  %l2
a0082d58:  c2 0f bf 27  ldub  [ %fp + -217 ], %g1
a0082d5c:  82 38 00 01  xnor  %g0, %g1, %g1
a0082d60:  a2 0c a0 ff  and  %l2, 0xff, %l1
a0082d64:  83 38 40 11  sra  %g1, %l1, %g1
a0082d68:  80 88 60 01  btst  1, %g1
a0082d6c:  02 80 00 4b  be  0xa0082e98
a0082d70:  96 0c a0 ff  and  %l2, 0xff, %o3
a0082d74:  a8 07 bf f8  add  %fp, -8, %l4
a0082d78:  82 05 00 11  add  %l4, %l1, %g1
a0082d7c:  92 10 00 11  mov  %l1, %o1
a0082d80:  d6 08 7f f0  ldub  [ %g1 + -16 ], %o3
a0082d84:  90 10 00 13  mov  %l3, %o0
a0082d88:  7f ff db 7f  call  0xa0079b84
a0082d8c:  94 0e 60 ff  and  %i1, 0xff, %o2
a0082d90:  a0 04 40 11  add  %l1, %l1, %l0
a0082d94:  a0 04 00 14  add  %l0, %l4, %l0
a0082d98:  13 00 00 0b  sethi  %hi(0x2c00), %o1
a0082d9c:  d0 34 3f 70  sth  %o0, [ %l0 + -144 ]
a0082da0:  80 a4 60 00  cmp  %l1, 0
a0082da4:  02 80 00 0b  be  0xa0082dd0
a0082da8:  92 12 62 64  or  %o1, 0x264, %o1
a0082dac:  13 00 00 0b  sethi  %hi(0x2c00), %o1
a0082db0:  80 a4 60 01  cmp  %l1, 1
a0082db4:  02 80 00 10  be  0xa0082df4
a0082db8:  92 12 62 64  or  %o1, 0x264, %o1
a0082dbc:  80 a4 60 02  cmp  %l1, 2
a0082dc0:  12 80 00 09  bne  0xa0082de4
a0082dc4:  80 a4 60 03  cmp  %l1, 3
a0082dc8:  13 00 00 0b  sethi  %hi(0x2c00), %o1
a0082dcc:  92 12 62 68  or  %o1, 0x268, %o1	! 0x2e68
a0082dd0:  40 00 91 51  call  0xa00a7314
a0082dd4:  90 10 00 13  mov  %l3, %o0
a0082dd8:  03 3f ff e0  sethi  %hi(0xffff8000), %g1
a0082ddc:  10 80 00 0a  b  0xa0082e04
a0082de0:  b4 2a 00 01  andn  %o0, %g1, %i2
a0082de4:  32 80 00 09  bne,a   0xa0082e08
a0082de8:  82 04 40 11  add  %l1, %l1, %g1
a0082dec:  13 00 00 0b  sethi  %hi(0x2c00), %o1
a0082df0:  92 12 62 68  or  %o1, 0x268, %o1	! 0x2e68
a0082df4:  40 00 91 48  call  0xa00a7314
a0082df8:  90 10 00 13  mov  %l3, %o0
a0082dfc:  90 02 00 08  add  %o0, %o0, %o0
a0082e00:  b5 32 20 11  srl  %o0, 0x11, %i2
a0082e04:  82 04 40 11  add  %l1, %l1, %g1
a0082e08:  96 00 40 14  add  %g1, %l4, %o3
a0082e0c:  da 12 ff 78  lduh  [ %o3 + -136 ], %o5
a0082e10:  80 a3 60 00  cmp  %o5, 0
a0082e14:  12 80 00 15  bne  0xa0082e68
a0082e18:  83 2e a0 10  sll  %i2, 0x10, %g1
a0082e1c:  9b 30 60 10  srl  %g1, 0x10, %o5
a0082e20:  80 a3 60 00  cmp  %o5, 0
a0082e24:  32 80 00 08  bne,a   0xa0082e44
a0082e28:  c2 12 ff 48  lduh  [ %o3 + -184 ], %g1
a0082e2c:  82 05 00 11  add  %l4, %l1, %g1
a0082e30:  da 12 ff 70  lduh  [ %o3 + -144 ], %o5
a0082e34:  d8 08 7f 40  ldub  [ %g1 + -192 ], %o4
a0082e38:  da 32 ff 78  sth  %o5, [ %o3 + -136 ]
a0082e3c:  10 80 00 16  b  0xa0082e94
a0082e40:  d8 28 7f d8  stb  %o4, [ %g1 + -40 ]
a0082e44:  80 a3 40 01  cmp  %o5, %g1
a0082e48:  38 80 00 14  bgu,a   0xa0082e98
a0082e4c:  96 0c a0 ff  and  %l2, 0xff, %o3
a0082e50:  9a 05 00 11  add  %l4, %l1, %o5
a0082e54:  c2 0b 7f 40  ldub  [ %o5 + -192 ], %g1
a0082e58:  c2 2b 7f d8  stb  %g1, [ %o5 + -40 ]
a0082e5c:  c0 32 ff 78  clrh  [ %o3 + -136 ]
a0082e60:  10 80 00 0d  b  0xa0082e94
a0082e64:  f4 32 ff 48  sth  %i2, [ %o3 + -184 ]
a0082e68:  80 a0 60 00  cmp  %g1, 0
a0082e6c:  32 80 00 0b  bne,a   0xa0082e98
a0082e70:  96 0c a0 ff  and  %l2, 0xff, %o3
a0082e74:  c2 12 ff 70  lduh  [ %o3 + -144 ], %g1
a0082e78:  80 a0 40 0d  cmp  %g1, %o5
a0082e7c:  0a 80 00 06  bcs  0xa0082e94
a0082e80:  98 10 00 01  mov  %g1, %o4
a0082e84:  82 05 00 11  add  %l4, %l1, %g1
a0082e88:  da 08 7f 40  ldub  [ %g1 + -192 ], %o5
a0082e8c:  d8 32 ff 78  sth  %o4, [ %o3 + -136 ]
a0082e90:  da 28 7f d8  stb  %o5, [ %g1 + -40 ]
a0082e94:  96 0c a0 ff  and  %l2, 0xff, %o3
a0082e98:  82 07 bf f8  add  %fp, -8, %g1
a0082e9c:  98 00 40 0b  add  %g1, %o3, %o4
a0082ea0:  da 0b 3f 40  ldub  [ %o4 + -192 ], %o5
a0082ea4:  80 a3 60 0e  cmp  %o5, 0xe
a0082ea8:  08 80 00 07  bleu  0xa0082ec4
a0082eac:  9a 03 60 02  add  %o5, 2, %o5
a0082eb0:  82 10 20 01  mov  1, %g1
a0082eb4:  83 28 40 0b  sll  %g1, %o3, %g1
a0082eb8:  d6 0f bf 27  ldub  [ %fp + -217 ], %o3
a0082ebc:  96 10 40 0b  or  %g1, %o3, %o3
a0082ec0:  d6 2f bf 27  stb  %o3, [ %fp + -217 ]
a0082ec4:  82 0b 60 ff  and  %o5, 0xff, %g1
a0082ec8:  80 a0 60 10  cmp  %g1, 0x10
a0082ecc:  12 80 00 04  bne  0xa0082edc
a0082ed0:  da 2b 3f 40  stb  %o5, [ %o4 + -192 ]
a0082ed4:  82 10 20 0f  mov  0xf, %g1
a0082ed8:  c2 2b 3f 40  stb  %g1, [ %o4 + -192 ]
a0082edc:  82 5d 60 b0  smul  %l5, 0xb0, %g1
a0082ee0:  9a 15 a2 80  or  %l6, 0x280, %o5
a0082ee4:  da 0b 40 01  ldub  [ %o5 + %g1 ], %o5
a0082ee8:  a4 04 a0 01  inc  %l2
a0082eec:  82 0c a0 ff  and  %l2, 0xff, %g1
a0082ef0:  80 a0 40 0d  cmp  %g1, %o5
a0082ef4:  0a bf ff 9a  bcs  0xa0082d5c
a0082ef8:  c2 0f bf 27  ldub  [ %fp + -217 ], %g1
a0082efc:  10 bf ff 86  b  0xa0082d14
a0082f00:  80 a0 60 0f  cmp  %g1, 0xf
a0082f04:  9a 0e e0 ff  and  %i3, 0xff, %o5
a0082f08:  03 2a 01 f5  sethi  %hi(0xa807d400), %g1
a0082f0c:  9a 5b 60 b0  smul  %o5, 0xb0, %o5
a0082f10:  82 10 62 80  or  %g1, 0x280, %g1
a0082f14:  c2 08 40 0d  ldub  [ %g1 + %o5 ], %g1
a0082f18:  80 a0 60 00  cmp  %g1, 0
a0082f1c:  02 80 00 23  be  0xa0082fa8
a0082f20:  a4 10 20 00  clr  %l2
a0082f24:  a0 10 00 01  mov  %g1, %l0
a0082f28:  94 07 bf f8  add  %fp, -8, %o2
a0082f2c:  a2 10 20 01  mov  1, %l1
a0082f30:  82 0c a0 ff  and  %l2, 0xff, %g1
a0082f34:  9a 00 40 01  add  %g1, %g1, %o5
a0082f38:  92 03 40 0a  add  %o5, %o2, %o1
a0082f3c:  9e 02 80 01  add  %o2, %g1, %o7
a0082f40:  da 0b ff d8  ldub  [ %o7 + -40 ], %o5
a0082f44:  9b 2c 40 0d  sll  %l1, %o5, %o5
a0082f48:  9a 03 7f ff  add  %o5, -1, %o5
a0082f4c:  d6 12 7f a0  lduh  [ %o1 + -96 ], %o3
a0082f50:  a4 04 a0 01  inc  %l2
a0082f54:  80 a2 c0 0d  cmp  %o3, %o5
a0082f58:  98 10 00 0f  mov  %o7, %o4
a0082f5c:  90 0c a0 ff  and  %l2, 0xff, %o0
a0082f60:  02 80 00 09  be  0xa0082f84
a0082f64:  9a 10 20 00  clr  %o5
a0082f68:  c2 0b ff f0  ldub  [ %o7 + -16 ], %g1
a0082f6c:  82 00 60 06  add  %g1, 6, %g1
a0082f70:  83 2c 40 01  sll  %l1, %g1, %g1
a0082f74:  82 00 7f ff  add  %g1, -1, %g1
a0082f78:  80 a2 c0 01  cmp  %o3, %g1
a0082f7c:  26 80 00 02  bl,a   0xa0082f84
a0082f80:  9a 10 20 01  mov  1, %o5
a0082f84:  da 2b 3f f8  stb  %o5, [ %o4 + -8 ]
a0082f88:  c2 12 7f a0  lduh  [ %o1 + -96 ], %g1
a0082f8c:  82 00 60 01  inc  %g1
a0082f90:  da 0b ff f8  ldub  [ %o7 + -8 ], %o5
a0082f94:  83 28 40 0d  sll  %g1, %o5, %g1
a0082f98:  82 00 7f ff  add  %g1, -1, %g1
a0082f9c:  80 a2 00 10  cmp  %o0, %l0
a0082fa0:  0a bf ff e4  bcs  0xa0082f30
a0082fa4:  c2 32 7f 38  sth  %g1, [ %o1 + -200 ]
a0082fa8:  a6 0e 20 ff  and  %i0, 0xff, %l3
a0082fac:  ae 07 bf d0  add  %fp, -48, %l7
a0082fb0:  96 07 bf 30  add  %fp, -208, %o3
a0082fb4:  90 10 00 13  mov  %l3, %o0
a0082fb8:  92 10 20 0f  mov  0xf, %o1
a0082fbc:  7f ff de 81  call  0xa007a9c0
a0082fc0:  94 10 00 17  mov  %l7, %o2
a0082fc4:  aa 0e e0 ff  and  %i3, 0xff, %l5
a0082fc8:  2d 2a 01 f5  sethi  %hi(0xa807d400), %l6
a0082fcc:  82 15 a2 80  or  %l6, 0x280, %g1	! 0xa807d680
a0082fd0:  9a 5d 60 b0  smul  %l5, 0xb0, %o5
a0082fd4:  c2 08 40 0d  ldub  [ %g1 + %o5 ], %g1
a0082fd8:  80 a0 60 00  cmp  %g1, 0
a0082fdc:  02 80 00 51  be  0xa0083120
a0082fe0:  a4 10 20 00  clr  %l2
a0082fe4:  a2 0c a0 ff  and  %l2, 0xff, %l1
a0082fe8:  a8 07 bf f8  add  %fp, -8, %l4
a0082fec:  9a 05 00 11  add  %l4, %l1, %o5
a0082ff0:  c2 0b 7f f8  ldub  [ %o5 + -8 ], %g1
a0082ff4:  80 a0 60 00  cmp  %g1, 0
a0082ff8:  02 80 00 43  be  0xa0083104
a0082ffc:  82 5d 60 b0  smul  %l5, 0xb0, %g1
a0083000:  92 10 00 11  mov  %l1, %o1
a0083004:  d6 0b 7f f0  ldub  [ %o5 + -16 ], %o3
a0083008:  90 10 00 13  mov  %l3, %o0
a008300c:  7f ff da de  call  0xa0079b84
a0083010:  94 0e 60 ff  and  %i1, 0xff, %o2
a0083014:  a0 04 40 11  add  %l1, %l1, %l0
a0083018:  a0 04 00 14  add  %l0, %l4, %l0
a008301c:  13 00 00 0b  sethi  %hi(0x2c00), %o1
a0083020:  d0 34 3f 70  sth  %o0, [ %l0 + -144 ]
a0083024:  80 a4 60 00  cmp  %l1, 0
a0083028:  02 80 00 0b  be  0xa0083054
a008302c:  92 12 62 64  or  %o1, 0x264, %o1
a0083030:  13 00 00 0b  sethi  %hi(0x2c00), %o1
a0083034:  80 a4 60 01  cmp  %l1, 1
a0083038:  02 80 00 10  be  0xa0083078
a008303c:  92 12 62 64  or  %o1, 0x264, %o1
a0083040:  80 a4 60 02  cmp  %l1, 2
a0083044:  12 80 00 09  bne  0xa0083068
a0083048:  80 a4 60 03  cmp  %l1, 3
a008304c:  13 00 00 0b  sethi  %hi(0x2c00), %o1
a0083050:  92 12 62 68  or  %o1, 0x268, %o1	! 0x2e68
a0083054:  40 00 90 b0  call  0xa00a7314
a0083058:  90 10 00 13  mov  %l3, %o0
a008305c:  03 3f ff e0  sethi  %hi(0xffff8000), %g1
a0083060:  10 80 00 0a  b  0xa0083088
a0083064:  b4 2a 00 01  andn  %o0, %g1, %i2
a0083068:  32 80 00 09  bne,a   0xa008308c
a008306c:  82 04 40 11  add  %l1, %l1, %g1
a0083070:  13 00 00 0b  sethi  %hi(0x2c00), %o1
a0083074:  92 12 62 68  or  %o1, 0x268, %o1	! 0x2e68
a0083078:  40 00 90 a7  call  0xa00a7314
a008307c:  90 10 00 13  mov  %l3, %o0
a0083080:  90 02 00 08  add  %o0, %o0, %o0
a0083084:  b5 32 20 11  srl  %o0, 0x11, %i2
a0083088:  82 04 40 11  add  %l1, %l1, %g1
a008308c:  92 00 40 14  add  %g1, %l4, %o1
a0083090:  da 12 7f 78  lduh  [ %o1 + -136 ], %o5
a0083094:  80 a3 60 00  cmp  %o5, 0
a0083098:  12 80 00 10  bne  0xa00830d8
a008309c:  83 2e a0 10  sll  %i2, 0x10, %g1
a00830a0:  9b 30 60 10  srl  %g1, 0x10, %o5
a00830a4:  80 a3 60 00  cmp  %o5, 0
a00830a8:  32 80 00 04  bne,a   0xa00830b8
a00830ac:  c2 12 7f 48  lduh  [ %o1 + -184 ], %g1
a00830b0:  10 80 00 11  b  0xa00830f4
a00830b4:  da 12 7f 70  lduh  [ %o1 + -144 ], %o5
a00830b8:  80 a3 40 01  cmp  %o5, %g1
a00830bc:  18 80 00 12  bgu  0xa0083104
a00830c0:  82 5d 60 b0  smul  %l5, 0xb0, %g1
a00830c4:  c2 12 7f 38  lduh  [ %o1 + -200 ], %g1
a00830c8:  c2 32 7f a0  sth  %g1, [ %o1 + -96 ]
a00830cc:  f4 32 7f 48  sth  %i2, [ %o1 + -184 ]
a00830d0:  10 80 00 0c  b  0xa0083100
a00830d4:  c0 32 7f 78  clrh  [ %o1 + -136 ]
a00830d8:  80 a0 60 00  cmp  %g1, 0
a00830dc:  12 80 00 0a  bne  0xa0083104
a00830e0:  82 5d 60 b0  smul  %l5, 0xb0, %g1
a00830e4:  c2 12 7f 70  lduh  [ %o1 + -144 ], %g1
a00830e8:  80 a0 40 0d  cmp  %g1, %o5
a00830ec:  0a 80 00 05  bcs  0xa0083100
a00830f0:  9a 10 00 01  mov  %g1, %o5
a00830f4:  c2 12 7f 38  lduh  [ %o1 + -200 ], %g1
a00830f8:  c2 32 7f a0  sth  %g1, [ %o1 + -96 ]
a00830fc:  da 32 7f 78  sth  %o5, [ %o1 + -136 ]
a0083100:  82 5d 60 b0  smul  %l5, 0xb0, %g1
a0083104:  9a 15 a2 80  or  %l6, 0x280, %o5
a0083108:  da 0b 40 01  ldub  [ %o5 + %g1 ], %o5
a008310c:  a4 04 a0 01  inc  %l2
a0083110:  82 0c a0 ff  and  %l2, 0xff, %g1
a0083114:  80 a0 40 0d  cmp  %g1, %o5
a0083118:  0a bf ff b4  bcs  0xa0082fe8
a008311c:  a2 0c a0 ff  and  %l2, 0xff, %l1
a0083120:  a0 0e 20 ff  and  %i0, 0xff, %l0
a0083124:  94 10 00 17  mov  %l7, %o2
a0083128:  90 10 00 10  mov  %l0, %o0
a008312c:  96 07 bf 98  add  %fp, -104, %o3
a0083130:  7f ff de 24  call  0xa007a9c0
a0083134:  92 10 20 0f  mov  0xf, %o1
a0083138:  17 00 00 0b  sethi  %hi(0x2c00), %o3
a008313c:  94 10 00 10  mov  %l0, %o2
a0083140:  96 12 e2 5c  or  %o3, 0x25c, %o3
a0083144:  90 10 20 00  clr  %o0
a0083148:  40 00 90 b7  call  0xa00a7424
a008314c:  92 10 20 17  mov  0x17, %o1
a0083150:  10 80 00 1f  b  0xa00831cc
a0083154:  27 2a 01 e1  sethi  %hi(0xa8078400), %l3
a0083158:  a0 0e 20 ff  and  %i0, 0xff, %l0
a008315c:  23 00 00 0d  sethi  %hi(0x3400), %l1
a0083160:  27 00 00 20  sethi  %hi(0x8000), %l3
a0083164:  90 10 00 10  mov  %l0, %o0
a0083168:  92 14 62 0c  or  %l1, 0x20c, %o1
a008316c:  15 3f ff c0  sethi  %hi(0xffff0000), %o2
a0083170:  40 00 90 c6  call  0xa00a7488
a0083174:  96 14 e3 d0  or  %l3, 0x3d0, %o3
a0083178:  25 00 00 3f  sethi  %hi(0xfc00), %l2
a008317c:  90 10 00 10  mov  %l0, %o0
a0083180:  92 14 62 0c  or  %l1, 0x20c, %o1
a0083184:  94 14 a3 ff  or  %l2, 0x3ff, %o2
a0083188:  40 00 90 c0  call  0xa00a7488
a008318c:  17 20 f4 00  sethi  %hi(0x83d00000), %o3
a0083190:  90 10 00 10  mov  %l0, %o0
a0083194:  96 14 e3 d0  or  %l3, 0x3d0, %o3
a0083198:  92 14 62 10  or  %l1, 0x210, %o1
a008319c:  40 00 90 bb  call  0xa00a7488
a00831a0:  15 3f ff c0  sethi  %hi(0xffff0000), %o2
a00831a4:  90 10 00 10  mov  %l0, %o0
a00831a8:  92 14 62 10  or  %l1, 0x210, %o1
a00831ac:  94 14 a3 ff  or  %l2, 0x3ff, %o2
a00831b0:  40 00 90 b6  call  0xa00a7488
a00831b4:  17 20 f4 00  sethi  %hi(0x83d00000), %o3
a00831b8:  7f ff dd 1e  call  0xa007a630
a00831bc:  90 10 00 10  mov  %l0, %o0
a00831c0:  7f ff dd 4c  call  0xa007a6f0
a00831c4:  90 10 00 10  mov  %l0, %o0
a00831c8:  27 2a 01 e1  sethi  %hi(0xa8078400), %l3
a00831cc:  c2 04 e2 34  ld  [ %l3 + 0x234 ], %g1	! 0xa8078634
a00831d0:  80 88 68 00  btst  0x800, %g1
a00831d4:  02 80 00 51  be  0xa0083318
a00831d8:  11 28 01 a1  sethi  %hi(0xa0068400), %o0
a00831dc:  7f ff c0 ba  call  0xa00734c4
a00831e0:  90 12 23 90  or  %o0, 0x390, %o0	! 0xa0068790
a00831e4:  c2 04 e2 34  ld  [ %l3 + 0x234 ], %g1
a00831e8:  80 88 68 00  btst  0x800, %g1
a00831ec:  02 80 00 4b  be  0xa0083318
a00831f0:  a2 0e 20 ff  and  %i0, 0xff, %l1
a00831f4:  21 00 00 08  sethi  %hi(0x2000), %l0
a00831f8:  92 14 21 78  or  %l0, 0x178, %o1	! 0x2178
a00831fc:  40 00 90 46  call  0xa00a7314
a0083200:  90 10 00 11  mov  %l1, %o0
a0083204:  a4 0a 20 0f  and  %o0, 0xf, %l2
a0083208:  92 14 21 78  or  %l0, 0x178, %o1
a008320c:  40 00 90 42  call  0xa00a7314
a0083210:  90 10 00 11  mov  %l1, %o0
a0083214:  03 00 3f ff  sethi  %hi(0xfffc00), %g1
a0083218:  82 10 63 00  or  %g1, 0x300, %g1	! 0xffff00
a008321c:  94 0a 00 01  and  %o0, %g1, %o2
a0083220:  11 28 01 a1  sethi  %hi(0xa0068400), %o0
a0083224:  90 12 23 b0  or  %o0, 0x3b0, %o0	! 0xa00687b0
a0083228:  92 10 00 12  mov  %l2, %o1
a008322c:  7f ff bf 86  call  0xa0073044
a0083230:  95 32 a0 08  srl  %o2, 8, %o2
a0083234:  c2 04 e2 34  ld  [ %l3 + 0x234 ], %g1
a0083238:  80 88 68 00  btst  0x800, %g1
a008323c:  02 80 00 37  be  0xa0083318
a0083240:  a0 04 24 00  add  %l0, 0x400, %l0
a0083244:  92 14 21 78  or  %l0, 0x178, %o1
a0083248:  40 00 90 33  call  0xa00a7314
a008324c:  90 10 00 11  mov  %l1, %o0
a0083250:  a4 0a 20 0f  and  %o0, 0xf, %l2
a0083254:  92 14 21 78  or  %l0, 0x178, %o1
a0083258:  40 00 90 2f  call  0xa00a7314
a008325c:  90 10 00 11  mov  %l1, %o0
a0083260:  03 00 3f ff  sethi  %hi(0xfffc00), %g1
a0083264:  82 10 63 00  or  %g1, 0x300, %g1	! 0xffff00
a0083268:  94 0a 00 01  and  %o0, %g1, %o2
a008326c:  11 28 01 a1  sethi  %hi(0xa0068400), %o0
a0083270:  90 12 23 d0  or  %o0, 0x3d0, %o0	! 0xa00687d0
a0083274:  92 10 00 12  mov  %l2, %o1
a0083278:  7f ff bf 73  call  0xa0073044
a008327c:  95 32 a0 08  srl  %o2, 8, %o2
a0083280:  c2 04 e2 34  ld  [ %l3 + 0x234 ], %g1
a0083284:  80 88 68 00  btst  0x800, %g1
a0083288:  02 80 00 24  be  0xa0083318
a008328c:  a0 04 24 00  add  %l0, 0x400, %l0
a0083290:  92 14 21 78  or  %l0, 0x178, %o1
a0083294:  40 00 90 20  call  0xa00a7314
a0083298:  90 10 00 11  mov  %l1, %o0
a008329c:  a4 0a 20 0f  and  %o0, 0xf, %l2
a00832a0:  92 14 21 78  or  %l0, 0x178, %o1
a00832a4:  40 00 90 1c  call  0xa00a7314
a00832a8:  90 10 00 11  mov  %l1, %o0
a00832ac:  03 00 3f ff  sethi  %hi(0xfffc00), %g1
a00832b0:  82 10 63 00  or  %g1, 0x300, %g1	! 0xffff00
a00832b4:  94 0a 00 01  and  %o0, %g1, %o2
a00832b8:  11 28 01 a1  sethi  %hi(0xa0068400), %o0
a00832bc:  90 12 23 f0  or  %o0, 0x3f0, %o0	! 0xa00687f0
a00832c0:  92 10 00 12  mov  %l2, %o1
a00832c4:  7f ff bf 60  call  0xa0073044
a00832c8:  95 32 a0 08  srl  %o2, 8, %o2
a00832cc:  c2 04 e2 34  ld  [ %l3 + 0x234 ], %g1
a00832d0:  80 88 68 00  btst  0x800, %g1
a00832d4:  02 80 00 11  be  0xa0083318
a00832d8:  a0 04 28 00  add  %l0, 0x800, %l0
a00832dc:  92 14 21 78  or  %l0, 0x178, %o1
a00832e0:  40 00 90 0d  call  0xa00a7314
a00832e4:  90 10 00 11  mov  %l1, %o0
a00832e8:  a4 0a 20 0f  and  %o0, 0xf, %l2
a00832ec:  92 14 21 78  or  %l0, 0x178, %o1
a00832f0:  40 00 90 09  call  0xa00a7314
a00832f4:  90 10 00 11  mov  %l1, %o0
a00832f8:  03 00 3f ff  sethi  %hi(0xfffc00), %g1
a00832fc:  82 10 63 00  or  %g1, 0x300, %g1	! 0xffff00
a0083300:  94 0a 00 01  and  %o0, %g1, %o2
a0083304:  11 28 01 a2  sethi  %hi(0xa0068800), %o0
a0083308:  90 12 20 10  or  %o0, 0x10, %o0	! 0xa0068810
a008330c:  92 10 00 12  mov  %l2, %o1
a0083310:  7f ff bf 4d  call  0xa0073044
a0083314:  95 32 a0 08  srl  %o2, 8, %o2
a0083318:  01 00 00 00  nop
a008331c:  81 c7 e0 08  ret
a0083320:  81 e8 00 00  restore
