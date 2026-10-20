# leon2m FUN_a00ab5f0 0xa00ab5f0-0xa00ab96c (892 bytes)  [FUN_a00ab964 = unreachable ret/restore tail, merged]
a00ab5f0:  9d e3 bf 90  save  %sp, -112, %sp
a00ab5f4:  b4 0e a0 ff  and  %i2, 0xff, %i2
a00ab5f8:  21 33 33 33  sethi  %hi(0xcccccc00), %l0
a00ab5fc:  b5 36 a0 01  srl  %i2, 1, %i2
a00ab600:  98 14 20 cd  or  %l0, 0xcd, %o4
a00ab604:  80 56 80 0c  umul  %i2, %o4, %g0
a00ab608:  9f 40 00 00  rd  %y, %o7
a00ab60c:  99 33 e0 03  srl  %o7, 3, %o4
a00ab610:  97 2b 20 02  sll  %o4, 2, %o3
a00ab614:  94 02 c0 0c  add  %o3, %o4, %o2
a00ab618:  92 02 80 0a  add  %o2, %o2, %o1
a00ab61c:  90 26 80 09  sub  %i2, %o1, %o0
a00ab620:  ae 0a 20 ff  and  %o0, 0xff, %l7
a00ab624:  80 a0 00 17  cmp  %g0, %l7
a00ab628:  9a 60 3f ff  subx  %g0, -1, %o5
a00ab62c:  a8 0b 20 ff  and  %o4, 0xff, %l4
a00ab630:  80 a0 00 14  cmp  %g0, %l4
a00ab634:  82 40 20 00  addx  %g0, 0, %g1
a00ab638:  aa 10 00 0c  mov  %o4, %l5
a00ab63c:  80 8b 40 01  btst  %o5, %g1
a00ab640:  02 80 00 04  be  0xa00ab650
a00ab644:  ba 10 20 00  clr  %i5
a00ab648:  aa 03 3f ff  add  %o4, -1, %l5
a00ab64c:  a8 0d 60 ff  and  %l5, 0xff, %l4
a00ab650:  80 a5 20 04  cmp  %l4, 4
a00ab654:  16 80 00 05  bge  0xa00ab668
a00ab658:  27 3f ff e0  sethi  %hi(0xffff8000), %l3
a00ab65c:  a4 10 20 06  mov  6, %l2
a00ab660:  a2 24 80 15  sub  %l2, %l5, %l1
a00ab664:  ba 04 7f fe  add  %l1, -2, %i5
a00ab668:  b8 0f 20 ff  and  %i4, 0xff, %i4
a00ab66c:  ac 14 e3 9a  or  %l3, 0x39a, %l6
a00ab670:  ec 37 bf f6  sth  %l6, [ %fp + -10 ]
a00ab674:  80 a7 20 00  cmp  %i4, 0
a00ab678:  02 80 00 07  be  0xa00ab694
a00ab67c:  82 14 e0 9a  or  %l3, 0x9a, %g1
a00ab680:  11 3f ff e0  sethi  %hi(0xffff8000), %o0
a00ab684:  03 3f ff e1  sethi  %hi(0xffff8400), %g1
a00ab688:  9a 12 23 4a  or  %o0, 0x34a, %o5
a00ab68c:  82 10 62 4a  or  %g1, 0x24a, %g1
a00ab690:  da 37 bf f6  sth  %o5, [ %fp + -10 ]
a00ab694:  80 a5 20 00  cmp  %l4, 0
a00ab698:  ac 0e 20 ff  and  %i0, 0xff, %l6
a00ab69c:  a4 0e 60 ff  and  %i1, 0xff, %l2
a00ab6a0:  02 80 00 1b  be  0xa00ab70c
a00ab6a4:  a7 28 60 10  sll  %g1, 0x10, %l3
a00ab6a8:  80 a5 20 00  cmp  %l4, 0
a00ab6ac:  02 80 00 18  be  0xa00ab70c
a00ab6b0:  a2 10 20 00  clr  %l1
a00ab6b4:  96 0c 60 ff  and  %l1, 0xff, %o3
a00ab6b8:  94 05 80 0b  add  %l6, %o3, %o2
a00ab6bc:  93 2a a0 10  sll  %o2, 0x10, %o1
a00ab6c0:  b3 32 60 10  srl  %o1, 0x10, %i1
a00ab6c4:  90 10 00 19  mov  %i1, %o0
a00ab6c8:  92 10 00 12  mov  %l2, %o1
a00ab6cc:  94 10 20 01  mov  1, %o2
a00ab6d0:  97 34 e0 10  srl  %l3, 0x10, %o3
a00ab6d4:  40 02 6c eb  call  0xa0146a80
a00ab6d8:  98 10 20 00  clr  %o4
a00ab6dc:  92 10 00 19  mov  %i1, %o1
a00ab6e0:  90 10 20 00  clr  %o0
a00ab6e4:  94 10 00 12  mov  %l2, %o2
a00ab6e8:  96 10 20 01  mov  1, %o3
a00ab6ec:  98 10 20 01  mov  1, %o4
a00ab6f0:  9a 10 20 00  clr  %o5
a00ab6f4:  40 02 6d 0b  call  0xa0146b20
a00ab6f8:  a2 04 60 01  inc  %l1
a00ab6fc:  b0 0c 60 ff  and  %l1, 0xff, %i0
a00ab700:  80 a6 00 14  cmp  %i0, %l4
a00ab704:  0a bf ff ed  bcs  0xa00ab6b8
a00ab708:  96 0c 60 ff  and  %l1, 0xff, %o3
a00ab70c:  80 a6 a0 00  cmp  %i2, 0
a00ab710:  12 80 00 48  bne  0xa00ab830
a00ab714:  aa 0d 60 ff  and  %l5, 0xff, %l5
a00ab718:  b4 05 80 15  add  %l6, %l5, %i2
a00ab71c:  a3 2e a0 10  sll  %i2, 0x10, %l1
a00ab720:  a1 34 60 10  srl  %l1, 0x10, %l0
a00ab724:  97 34 e0 10  srl  %l3, 0x10, %o3
a00ab728:  90 10 00 10  mov  %l0, %o0
a00ab72c:  92 10 00 12  mov  %l2, %o1
a00ab730:  94 10 20 01  mov  1, %o2
a00ab734:  40 02 6c d3  call  0xa0146a80
a00ab738:  98 10 20 00  clr  %o4
a00ab73c:  92 10 00 10  mov  %l0, %o1
a00ab740:  94 10 00 12  mov  %l2, %o2
a00ab744:  9a 10 20 00  clr  %o5
a00ab748:  90 10 20 00  clr  %o0
a00ab74c:  96 10 20 01  mov  1, %o3
a00ab750:  40 02 6c f4  call  0xa0146b20
a00ab754:  98 10 20 02  mov  2, %o4
a00ab758:  98 06 a0 01  add  %i2, 1, %o4
a00ab75c:  9f 2b 20 10  sll  %o4, 0x10, %o7
a00ab760:  a9 33 e0 10  srl  %o7, 0x10, %l4
a00ab764:  2f 00 00 20  sethi  %hi(0x8000), %l7
a00ab768:  96 15 e3 9a  or  %l7, 0x39a, %o3	! 0x839a
a00ab76c:  90 10 00 14  mov  %l4, %o0
a00ab770:  92 10 00 12  mov  %l2, %o1
a00ab774:  94 10 20 01  mov  1, %o2
a00ab778:  40 02 6c c2  call  0xa0146a80
a00ab77c:  98 10 20 00  clr  %o4
a00ab780:  92 10 00 14  mov  %l4, %o1
a00ab784:  90 10 20 00  clr  %o0
a00ab788:  94 10 00 12  mov  %l2, %o2
a00ab78c:  96 10 20 01  mov  1, %o3
a00ab790:  98 10 20 01  mov  1, %o4
a00ab794:  40 02 6c e3  call  0xa0146b20
a00ab798:  9a 10 20 00  clr  %o5
a00ab79c:  a8 0f 60 ff  and  %i5, 0xff, %l4
a00ab7a0:  80 a5 20 00  cmp  %l4, 0
a00ab7a4:  02 80 00 1c  be  0xa00ab814
a00ab7a8:  b4 10 20 00  clr  %i2
a00ab7ac:  a2 05 80 15  add  %l6, %l5, %l1
a00ab7b0:  ea 17 bf f6  lduh  [ %fp + -10 ], %l5
a00ab7b4:  a7 2d 60 10  sll  %l5, 0x10, %l3
a00ab7b8:  9e 0e a0 ff  and  %i2, 0xff, %o7
a00ab7bc:  ae 04 40 0f  add  %l1, %o7, %l7
a00ab7c0:  96 05 e0 02  add  %l7, 2, %o3
a00ab7c4:  95 2a e0 10  sll  %o3, 0x10, %o2
a00ab7c8:  ad 32 a0 10  srl  %o2, 0x10, %l6
a00ab7cc:  90 10 00 16  mov  %l6, %o0
a00ab7d0:  92 10 00 12  mov  %l2, %o1
a00ab7d4:  94 10 20 01  mov  1, %o2
a00ab7d8:  97 34 e0 10  srl  %l3, 0x10, %o3
a00ab7dc:  40 02 6c a9  call  0xa0146a80
a00ab7e0:  98 10 20 00  clr  %o4
a00ab7e4:  92 10 00 16  mov  %l6, %o1
a00ab7e8:  90 10 20 00  clr  %o0
a00ab7ec:  94 10 00 12  mov  %l2, %o2
a00ab7f0:  96 10 20 01  mov  1, %o3
a00ab7f4:  98 10 20 01  mov  1, %o4
a00ab7f8:  9a 10 20 00  clr  %o5
a00ab7fc:  40 02 6c c9  call  0xa0146b20
a00ab800:  b4 06 a0 01  inc  %i2
a00ab804:  ba 0e a0 ff  and  %i2, 0xff, %i5
a00ab808:  80 a7 40 14  cmp  %i5, %l4
a00ab80c:  0a bf ff ec  bcs  0xa00ab7bc
a00ab810:  9e 0e a0 ff  and  %i2, 0xff, %o7
a00ab814:  80 a7 20 01  cmp  %i4, 1
a00ab818:  02 80 00 2c  be  0xa00ab8c8
a00ab81c:  a4 0e e0 ff  and  %i3, 0xff, %l2
a00ab820:  80 a4 a0 06  cmp  %l2, 6
a00ab824:  12 80 00 4f  bne  0xa00ab960
a00ab828:  01 00 00 00  nop
a00ab82c:  30 80 00 36  b,a   0xa00ab904
a00ab830:  b4 05 80 15  add  %l6, %l5, %i2
a00ab834:  91 2e a0 10  sll  %i2, 0x10, %o0
a00ab838:  b1 32 20 10  srl  %o0, 0x10, %i0
a00ab83c:  a7 34 e0 10  srl  %l3, 0x10, %l3
a00ab840:  90 10 00 18  mov  %i0, %o0
a00ab844:  92 10 00 12  mov  %l2, %o1
a00ab848:  94 10 20 01  mov  1, %o2
a00ab84c:  96 10 00 13  mov  %l3, %o3
a00ab850:  40 02 6c 8c  call  0xa0146a80
a00ab854:  98 10 20 00  clr  %o4
a00ab858:  a2 05 c0 17  add  %l7, %l7, %l1
a00ab85c:  9a 04 60 01  add  %l1, 1, %o5
a00ab860:  98 0b 60 ff  and  %o5, 0xff, %o4
a00ab864:  92 10 00 18  mov  %i0, %o1
a00ab868:  90 10 20 00  clr  %o0
a00ab86c:  94 10 00 12  mov  %l2, %o2
a00ab870:  96 10 20 01  mov  1, %o3
a00ab874:  40 02 6c ab  call  0xa0146b20
a00ab878:  9a 10 20 00  clr  %o5
a00ab87c:  80 a5 20 05  cmp  %l4, 5
a00ab880:  18 bf ff c8  bgu  0xa00ab7a0
a00ab884:  a8 0f 60 ff  and  %i5, 0xff, %l4
a00ab888:  92 06 a0 01  add  %i2, 1, %o1
a00ab88c:  83 2a 60 10  sll  %o1, 0x10, %g1
a00ab890:  b3 30 60 10  srl  %g1, 0x10, %i1
a00ab894:  96 10 00 13  mov  %l3, %o3
a00ab898:  90 10 00 19  mov  %i1, %o0
a00ab89c:  92 10 00 12  mov  %l2, %o1
a00ab8a0:  94 10 20 01  mov  1, %o2
a00ab8a4:  40 02 6c 77  call  0xa0146a80
a00ab8a8:  98 10 20 00  clr  %o4
a00ab8ac:  a6 04 60 02  add  %l1, 2, %l3
a00ab8b0:  92 10 00 19  mov  %i1, %o1
a00ab8b4:  98 0c e0 fe  and  %l3, 0xfe, %o4
a00ab8b8:  90 10 20 00  clr  %o0
a00ab8bc:  94 10 00 12  mov  %l2, %o2
a00ab8c0:  10 bf ff b5  b  0xa00ab794
a00ab8c4:  96 10 20 01  mov  1, %o3
a00ab8c8:  b8 0e e0 ff  and  %i3, 0xff, %i4
a00ab8cc:  80 a7 20 06  cmp  %i4, 6
a00ab8d0:  12 80 00 24  bne  0xa00ab960
a00ab8d4:  90 10 20 02  mov  2, %o0
a00ab8d8:  7f ff f6 e4  call  0xa00a9468
a00ab8dc:  92 10 20 06  mov  6, %o1
a00ab8e0:  90 10 20 00  clr  %o0
a00ab8e4:  7f ff f6 e1  call  0xa00a9468
a00ab8e8:  92 10 20 01  mov  1, %o1
a00ab8ec:  90 10 20 01  mov  1, %o0
a00ab8f0:  7f ff f6 de  call  0xa00a9468
a00ab8f4:  92 10 20 03  mov  3, %o1
a00ab8f8:  b0 10 20 03  mov  3, %i0
a00ab8fc:  40 00 1e f6  call  0xa00b34d4
a00ab900:  93 e8 20 05  restore  %g0, 5, %o1
a00ab904:  7f ff 95 b2  call  0xa0090fcc
a00ab908:  01 00 00 00  nop
a00ab90c:  a9 2a 20 10  sll  %o0, 0x10, %l4
a00ab910:  b7 35 20 10  srl  %l4, 0x10, %i3
a00ab914:  80 a6 e0 05  cmp  %i3, 5
a00ab918:  02 80 00 12  be  0xa00ab960
a00ab91c:  01 00 00 00  nop
a00ab920:  7f ff fe e7  call  0xa00ab4bc
a00ab924:  b0 10 20 07  mov  7, %i0	! 0x7
a00ab928:  90 10 20 02  mov  2, %o0
a00ab92c:  7f ff f6 cf  call  0xa00a9468
a00ab930:  92 10 20 05  mov  5, %o1
a00ab934:  90 10 20 00  clr  %o0
a00ab938:  7f ff f6 cc  call  0xa00a9468
a00ab93c:  92 10 20 00  clr  %o1
a00ab940:  90 10 20 01  mov  1, %o0
a00ab944:  7f ff f6 c9  call  0xa00a9468
a00ab948:  92 10 20 02  mov  2, %o1
a00ab94c:  90 10 20 00  clr  %o0
a00ab950:  40 00 1e e1  call  0xa00b34d4
a00ab954:  92 10 20 01  mov  1, %o1
a00ab958:  40 00 1e bd  call  0xa00b344c
a00ab95c:  81 e8 00 00  restore
a00ab960:  01 00 00 00  nop
a00ab964:  81 c7 e0 08  ret
a00ab968:  81 e8 00 00  restore
