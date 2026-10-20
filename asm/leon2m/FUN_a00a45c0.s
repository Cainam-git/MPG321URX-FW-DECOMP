# leon2m FUN_a00a45c0 0xa00a45c0-0xa00a493c (892 bytes)
a00a45c0:  9d e3 bf 98  save  %sp, -104, %sp
a00a45c4:  1f 0e 38 e3  sethi  %hi(0x38e38c00), %o7
a00a45c8:  b4 0e a0 ff  and  %i2, 0xff, %i2
a00a45cc:  98 13 e2 39  or  %o7, 0x239, %o4
a00a45d0:  80 56 80 0c  umul  %i2, %o4, %g0
a00a45d4:  97 40 00 00  rd  %y, %o3
a00a45d8:  99 32 e0 01  srl  %o3, 1, %o4
a00a45dc:  95 2b 20 03  sll  %o4, 3, %o2
a00a45e0:  92 02 80 0c  add  %o2, %o4, %o1
a00a45e4:  90 26 80 09  sub  %i2, %o1, %o0
a00a45e8:  aa 0a 20 ff  and  %o0, 0xff, %l5
a00a45ec:  80 a0 00 15  cmp  %g0, %l5
a00a45f0:  9a 60 3f ff  subx  %g0, -1, %o5
a00a45f4:  a4 0b 20 ff  and  %o4, 0xff, %l2
a00a45f8:  80 a0 00 12  cmp  %g0, %l2
a00a45fc:  82 40 20 00  addx  %g0, 0, %g1
a00a4600:  80 8b 40 01  btst  %o5, %g1
a00a4604:  a6 10 00 0c  mov  %o4, %l3
a00a4608:  82 10 00 1b  mov  %i3, %g1
a00a460c:  02 80 00 04  be  0xa00a461c
a00a4610:  ac 10 20 00  clr  %l6
a00a4614:  a6 03 3f ff  add  %o4, -1, %l3
a00a4618:  a4 0c e0 ff  and  %l3, 0xff, %l2
a00a461c:  a2 08 60 ff  and  %g1, 0xff, %l1
a00a4620:  a0 04 7f fe  add  %l1, -2, %l0
a00a4624:  80 a4 80 10  cmp  %l2, %l0
a00a4628:  16 80 00 04  bge  0xa00a4638
a00a462c:  80 a4 a0 00  cmp  %l2, 0
a00a4630:  a8 26 c0 13  sub  %i3, %l3, %l4
a00a4634:  ac 05 3f fe  add  %l4, -2, %l6
a00a4638:  a8 0e 20 ff  and  %i0, 0xff, %l4
a00a463c:  02 80 00 1c  be  0xa00a46ac
a00a4640:  b6 0e 60 ff  and  %i1, 0xff, %i3
a00a4644:  80 a4 a0 00  cmp  %l2, 0
a00a4648:  02 80 00 19  be  0xa00a46ac
a00a464c:  a2 10 20 00  clr  %l1
a00a4650:  33 21 a6 80  sethi  %hi(0x869a0000), %i1
a00a4654:  90 0c 60 ff  and  %l1, 0xff, %o0
a00a4658:  9a 05 00 08  add  %l4, %o0, %o5
a00a465c:  83 2b 60 10  sll  %o5, 0x10, %g1
a00a4660:  a1 30 60 10  srl  %g1, 0x10, %l0
a00a4664:  90 10 00 10  mov  %l0, %o0
a00a4668:  92 10 00 1b  mov  %i3, %o1
a00a466c:  94 10 20 01  mov  1, %o2
a00a4670:  97 36 60 10  srl  %i1, 0x10, %o3
a00a4674:  40 02 89 03  call  0xa0146a80
a00a4678:  98 10 20 00  clr  %o4
a00a467c:  92 10 00 10  mov  %l0, %o1
a00a4680:  90 10 20 00  clr  %o0
a00a4684:  94 10 00 1b  mov  %i3, %o2
a00a4688:  96 10 20 01  mov  1, %o3
a00a468c:  98 10 20 7b  mov  0x7b, %o4
a00a4690:  9a 10 20 00  clr  %o5
a00a4694:  40 02 89 23  call  0xa0146b20
a00a4698:  a2 04 60 01  inc  %l1
a00a469c:  b0 0c 60 ff  and  %l1, 0xff, %i0
a00a46a0:  80 a6 00 12  cmp  %i0, %l2
a00a46a4:  0a bf ff ed  bcs  0xa00a4658
a00a46a8:  90 0c 60 ff  and  %l1, 0xff, %o0
a00a46ac:  80 a6 a0 00  cmp  %i2, 0
a00a46b0:  02 80 00 3b  be  0xa00a479c
a00a46b4:  80 a6 a0 63  cmp  %i2, 0x63
a00a46b8:  02 80 00 7d  be  0xa00a48ac
a00a46bc:  80 a6 a0 64  cmp  %i2, 0x64
a00a46c0:  02 80 00 5c  be  0xa00a4830
a00a46c4:  a6 0c e0 ff  and  %l3, 0xff, %l3
a00a46c8:  b4 05 00 13  add  %l4, %l3, %i2
a00a46cc:  93 2e a0 10  sll  %i2, 0x10, %o1
a00a46d0:  23 21 a6 80  sethi  %hi(0x869a0000), %l1
a00a46d4:  a1 32 60 10  srl  %o1, 0x10, %l0
a00a46d8:  b3 34 60 10  srl  %l1, 0x10, %i1
a00a46dc:  90 10 00 10  mov  %l0, %o0
a00a46e0:  92 10 00 1b  mov  %i3, %o1
a00a46e4:  94 10 20 01  mov  1, %o2
a00a46e8:  96 10 00 19  mov  %i1, %o3
a00a46ec:  40 02 88 e5  call  0xa0146a80
a00a46f0:  98 10 20 00  clr  %o4
a00a46f4:  a2 05 40 15  add  %l5, %l5, %l1
a00a46f8:  94 04 60 7b  add  %l1, 0x7b, %o2
a00a46fc:  98 0a a0 ff  and  %o2, 0xff, %o4
a00a4700:  92 10 00 10  mov  %l0, %o1
a00a4704:  90 10 20 00  clr  %o0
a00a4708:  94 10 00 1b  mov  %i3, %o2
a00a470c:  96 10 20 01  mov  1, %o3
a00a4710:  40 02 89 04  call  0xa0146b20
a00a4714:  9a 10 20 00  clr  %o5
a00a4718:  80 a4 a0 0b  cmp  %l2, 0xb
a00a471c:  08 80 00 55  bleu  0xa00a4870
a00a4720:  98 06 a0 01  add  %i2, 1, %o4
a00a4724:  a4 0d a0 ff  and  %l6, 0xff, %l2
a00a4728:  80 a4 a0 00  cmp  %l2, 0
a00a472c:  02 80 00 82  be  0xa00a4934
a00a4730:  a2 10 20 00  clr  %l1
a00a4734:  b4 05 00 13  add  %l4, %l3, %i2
a00a4738:  27 20 e6 80  sethi  %hi(0x839a0000), %l3
a00a473c:  9a 0c 60 ff  and  %l1, 0xff, %o5
a00a4740:  82 06 80 0d  add  %i2, %o5, %g1
a00a4744:  9e 00 60 02  add  %g1, 2, %o7
a00a4748:  b3 2b e0 10  sll  %o7, 0x10, %i1
a00a474c:  a9 36 60 10  srl  %i1, 0x10, %l4
a00a4750:  90 10 00 14  mov  %l4, %o0
a00a4754:  92 10 00 1b  mov  %i3, %o1
a00a4758:  94 10 20 01  mov  1, %o2
a00a475c:  97 34 e0 10  srl  %l3, 0x10, %o3
a00a4760:  40 02 88 c8  call  0xa0146a80
a00a4764:  98 10 20 00  clr  %o4
a00a4768:  92 10 00 14  mov  %l4, %o1
a00a476c:  90 10 20 00  clr  %o0
a00a4770:  94 10 00 1b  mov  %i3, %o2
a00a4774:  96 10 20 01  mov  1, %o3
a00a4778:  98 10 20 7b  mov  0x7b, %o4
a00a477c:  9a 10 20 00  clr  %o5
a00a4780:  40 02 88 e8  call  0xa0146b20
a00a4784:  a2 04 60 01  inc  %l1
a00a4788:  ac 0c 60 ff  and  %l1, 0xff, %l6
a00a478c:  80 a5 80 12  cmp  %l6, %l2
a00a4790:  0a bf ff ec  bcs  0xa00a4740
a00a4794:  9a 0c 60 ff  and  %l1, 0xff, %o5
a00a4798:  30 80 00 67  b,a   0xa00a4934
a00a479c:  a6 0c e0 ff  and  %l3, 0xff, %l3
a00a47a0:  b0 05 00 13  add  %l4, %l3, %i0
a00a47a4:  95 2e 20 10  sll  %i0, 0x10, %o2
a00a47a8:  13 21 a6 80  sethi  %hi(0x869a0000), %o1
a00a47ac:  a3 32 a0 10  srl  %o2, 0x10, %l1
a00a47b0:  97 32 60 10  srl  %o1, 0x10, %o3
a00a47b4:  90 10 00 11  mov  %l1, %o0
a00a47b8:  92 10 00 1b  mov  %i3, %o1
a00a47bc:  94 10 20 01  mov  1, %o2
a00a47c0:  40 02 88 b0  call  0xa0146a80
a00a47c4:  98 10 20 00  clr  %o4
a00a47c8:  b4 06 20 01  add  %i0, 1, %i2
a00a47cc:  92 10 00 11  mov  %l1, %o1
a00a47d0:  94 10 00 1b  mov  %i3, %o2
a00a47d4:  9a 10 20 00  clr  %o5
a00a47d8:  90 10 20 00  clr  %o0
a00a47dc:  96 10 20 01  mov  1, %o3
a00a47e0:  98 10 20 7c  mov  0x7c, %o4
a00a47e4:  40 02 88 cf  call  0xa0146b20
a00a47e8:  b3 2e a0 10  sll  %i2, 0x10, %i1
a00a47ec:  a5 36 60 10  srl  %i1, 0x10, %l2
a00a47f0:  2b 00 00 20  sethi  %hi(0x8000), %l5
a00a47f4:  96 15 63 9a  or  %l5, 0x39a, %o3	! 0x839a
a00a47f8:  90 10 00 12  mov  %l2, %o0
a00a47fc:  92 10 00 1b  mov  %i3, %o1
a00a4800:  94 10 20 01  mov  1, %o2
a00a4804:  40 02 88 9f  call  0xa0146a80
a00a4808:  98 10 20 00  clr  %o4
a00a480c:  92 10 00 12  mov  %l2, %o1
a00a4810:  90 10 20 00  clr  %o0
a00a4814:  94 10 00 1b  mov  %i3, %o2
a00a4818:  96 10 20 01  mov  1, %o3
a00a481c:  98 10 20 7b  mov  0x7b, %o4
a00a4820:  40 02 88 c0  call  0xa0146b20
a00a4824:  9a 10 20 00  clr  %o5
a00a4828:  10 bf ff c0  b  0xa00a4728
a00a482c:  a4 0d a0 ff  and  %l6, 0xff, %l2
a00a4830:  b0 05 00 13  add  %l4, %l3, %i0
a00a4834:  91 2e 20 10  sll  %i0, 0x10, %o0
a00a4838:  b5 32 20 10  srl  %o0, 0x10, %i2
a00a483c:  1b 21 a6 80  sethi  %hi(0x869a0000), %o5
a00a4840:  97 33 60 10  srl  %o5, 0x10, %o3
a00a4844:  90 10 00 1a  mov  %i2, %o0
a00a4848:  92 10 00 1b  mov  %i3, %o1
a00a484c:  94 10 20 01  mov  1, %o2
a00a4850:  40 02 88 8c  call  0xa0146a80
a00a4854:  98 10 20 00  clr  %o4
a00a4858:  92 10 00 1a  mov  %i2, %o1
a00a485c:  90 10 20 00  clr  %o0
a00a4860:  94 10 00 1b  mov  %i3, %o2
a00a4864:  96 10 20 01  mov  1, %o3
a00a4868:  10 bf ff ee  b  0xa00a4820
a00a486c:  98 10 20 7c  mov  0x7c, %o4
a00a4870:  97 2b 20 10  sll  %o4, 0x10, %o3
a00a4874:  ab 32 e0 10  srl  %o3, 0x10, %l5
a00a4878:  96 10 00 19  mov  %i1, %o3
a00a487c:  90 10 00 15  mov  %l5, %o0
a00a4880:  92 10 00 1b  mov  %i3, %o1
a00a4884:  94 10 20 01  mov  1, %o2
a00a4888:  40 02 88 7e  call  0xa0146a80
a00a488c:  98 10 20 00  clr  %o4
a00a4890:  a4 04 60 7c  add  %l1, 0x7c, %l2
a00a4894:  92 10 00 15  mov  %l5, %o1
a00a4898:  98 0c a0 fe  and  %l2, 0xfe, %o4
a00a489c:  90 10 20 00  clr  %o0
a00a48a0:  94 10 00 1b  mov  %i3, %o2
a00a48a4:  10 bf ff df  b  0xa00a4820
a00a48a8:  96 10 20 01  mov  1, %o3
a00a48ac:  a6 0c e0 ff  and  %l3, 0xff, %l3
a00a48b0:  aa 05 00 13  add  %l4, %l3, %l5
a00a48b4:  83 2d 60 10  sll  %l5, 0x10, %g1
a00a48b8:  1f 21 a6 80  sethi  %hi(0x869a0000), %o7
a00a48bc:  b3 30 60 10  srl  %g1, 0x10, %i1
a00a48c0:  a5 33 e0 10  srl  %o7, 0x10, %l2
a00a48c4:  90 10 00 19  mov  %i1, %o0
a00a48c8:  92 10 00 1b  mov  %i3, %o1
a00a48cc:  96 10 00 12  mov  %l2, %o3
a00a48d0:  94 10 20 01  mov  1, %o2
a00a48d4:  40 02 88 6b  call  0xa0146a80
a00a48d8:  98 10 20 00  clr  %o4
a00a48dc:  92 10 00 19  mov  %i1, %o1
a00a48e0:  94 10 00 1b  mov  %i3, %o2
a00a48e4:  9a 10 20 00  clr  %o5
a00a48e8:  90 10 20 00  clr  %o0
a00a48ec:  96 10 20 01  mov  1, %o3
a00a48f0:  40 02 88 8c  call  0xa0146b20
a00a48f4:  98 10 20 8d  mov  0x8d, %o4
a00a48f8:  98 05 60 01  add  %l5, 1, %o4
a00a48fc:  97 2b 20 10  sll  %o4, 0x10, %o3
a00a4900:  a1 32 e0 10  srl  %o3, 0x10, %l0
a00a4904:  96 10 00 12  mov  %l2, %o3
a00a4908:  90 10 00 10  mov  %l0, %o0
a00a490c:  92 10 00 1b  mov  %i3, %o1
a00a4910:  94 10 20 01  mov  1, %o2
a00a4914:  40 02 88 5b  call  0xa0146a80
a00a4918:  98 10 20 00  clr  %o4
a00a491c:  92 10 00 10  mov  %l0, %o1
a00a4920:  90 10 20 00  clr  %o0
a00a4924:  94 10 00 1b  mov  %i3, %o2
a00a4928:  96 10 20 01  mov  1, %o3
a00a492c:  10 bf ff bd  b  0xa00a4820
a00a4930:  98 10 20 8e  mov  0x8e, %o4
a00a4934:  81 c7 e0 08  ret
a00a4938:  81 e8 00 00  restore
