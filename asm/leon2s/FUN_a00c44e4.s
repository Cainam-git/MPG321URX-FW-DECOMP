# leon2s FUN_a00c44e4 0xa00c44e4-0xa00c4e4c (176 bytes)
a00c44e4:  9d e3 bf 88  save  %sp, -120, %sp
a00c44e8:  c0 27 bf f0  clr  [ %fp + -16 ]
a00c44ec:  c0 2f bf f4  clrb  [ %fp + -12 ]
a00c44f0:  c0 37 bf e8  clrh  [ %fp + -24 ]
a00c44f4:  c0 2f bf ea  clrb  [ %fp + -22 ]
a00c44f8:  a8 10 20 00  clr  %l4
a00c44fc:  a2 0d 20 ff  and  %l4, 0xff, %l1
a00c4500:  03 2a 01 f5  sethi  %hi(0xa807d400), %g1
a00c4504:  9b 2c 60 04  sll  %l1, 4, %o5
a00c4508:  82 10 62 08  or  %g1, 0x208, %g1
a00c450c:  a4 03 40 01  add  %o5, %g1, %l2
a00c4510:  1b 01 c0 00  sethi  %hi(0x7000000), %o5
a00c4514:  c2 04 80 00  ld  [ %l2 ], %g1
a00c4518:  82 08 40 0d  and  %g1, %o5, %g1
a00c451c:  1b 01 40 00  sethi  %hi(0x5000000), %o5
a00c4520:  80 a0 40 0d  cmp  %g1, %o5
a00c4524:  12 80 02 48  bne  0xa00c4e44
a00c4528:  90 10 00 11  mov  %l1, %o0
a00c452c:  40 3b c9 a3  call  0xa0fb6bb8
a00c4530:  92 10 24 08  mov  0x408, %o1
a00c4534:  80 8a 20 01  btst  1, %o0
a00c4538:  22 80 00 05  be,a   0xa00c454c
a00c453c:  c2 0c a0 0d  ldub  [ %l2 + 0xd ], %g1
a00c4540:  c0 2c a0 0d  clrb  [ %l2 + 0xd ]
a00c4544:  c0 2c a0 0c  clrb  [ %l2 + 0xc ]
a00c4548:  c2 0c a0 0d  ldub  [ %l2 + 0xd ], %g1
a00c454c:  80 a0 60 0d  cmp  %g1, 0xd
a00c4550:  18 80 02 36  bgu  0xa00c4e28
a00c4554:  90 05 20 04  add  %l4, 4, %o0
a00c4558:  1b 27 c6 d1  sethi  %hi(0x9f1b4400), %o5
a00c455c:  83 28 60 02  sll  %g1, 2, %g1
a00c4560:  9a 13 60 ac  or  %o5, 0xac, %o5
a00c4564:  c2 03 40 01  ld  [ %o5 + %g1 ], %g1
a00c4568:  81 c0 40 00  jmp  %g1
a00c456c:  01 00 00 00  nop
a00c4570:  90 10 00 11  mov  %l1, %o0
a00c4574:  40 3b c9 91  call  0xa0fb6bb8
a00c4578:  92 10 24 08  mov  0x408, %o1
a00c457c:  80 8a 20 01  btst  1, %o0
a00c4580:  02 80 02 2a  be  0xa00c4e28
a00c4584:  90 05 20 04  add  %l4, 4, %o0
a00c4588:  da 04 80 00  ld  [ %l2 ], %o5
a00c458c:  03 00 10 00  sethi  %hi(0x400000), %g1
a00c4590:  82 2b 40 01  andn  %o5, %g1, %g1
a00c4594:  c2 24 80 00  st  %g1, [ %l2 ]
a00c4598:  27 2a 01 e1  sethi  %hi(0xa8078400), %l3
a00c459c:  90 14 e2 10  or  %l3, 0x210, %o0	! 0xa8078610
a00c45a0:  7f ff f7 2b  call  0xa00c224c
a00c45a4:  c0 2f bf f4  clrb  [ %fp + -12 ]
a00c45a8:  96 10 20 00  clr  %o3
a00c45ac:  90 10 00 11  mov  %l1, %o0
a00c45b0:  92 10 20 00  clr  %o1
a00c45b4:  40 3b c9 b9  call  0xa0fb6c98
a00c45b8:  94 10 20 20  mov  0x20, %o2
a00c45bc:  90 10 00 11  mov  %l1, %o0
a00c45c0:  92 10 24 00  mov  0x400, %o1
a00c45c4:  40 3b c9 8f  call  0xa0fb6c00
a00c45c8:  94 10 20 03  mov  3, %o2
a00c45cc:  90 10 00 11  mov  %l1, %o0
a00c45d0:  92 10 24 02  mov  0x402, %o1
a00c45d4:  94 10 20 80  mov  0x80, %o2
a00c45d8:  40 3b c9 b0  call  0xa0fb6c98
a00c45dc:  96 10 20 01  mov  1, %o3
a00c45e0:  90 10 00 11  mov  %l1, %o0
a00c45e4:  92 10 24 03  mov  0x403, %o1
a00c45e8:  40 3b c9 86  call  0xa0fb6c00
a00c45ec:  94 10 20 00  clr  %o2
a00c45f0:  a0 10 20 00  clr  %l0
a00c45f4:  83 2c 20 10  sll  %l0, 0x10, %g1
a00c45f8:  83 30 60 10  srl  %g1, 0x10, %g1
a00c45fc:  9a 14 e2 10  or  %l3, 0x210, %o5
a00c4600:  d4 0b 40 01  ldub  [ %o5 + %g1 ], %o2
a00c4604:  90 10 00 11  mov  %l1, %o0
a00c4608:  40 3b c9 7e  call  0xa0fb6c00
a00c460c:  92 10 24 01  mov  0x401, %o1
a00c4610:  9a 04 20 01  add  %l0, 1, %o5
a00c4614:  83 2b 60 10  sll  %o5, 0x10, %g1
a00c4618:  83 30 60 10  srl  %g1, 0x10, %g1
a00c461c:  80 a0 60 07  cmp  %g1, 7
a00c4620:  08 bf ff f5  bleu  0xa00c45f4
a00c4624:  a0 10 00 0d  mov  %o5, %l0
a00c4628:  90 10 00 11  mov  %l1, %o0
a00c462c:  92 10 24 08  mov  0x408, %o1
a00c4630:  40 3b c9 74  call  0xa0fb6c00
a00c4634:  94 10 20 01  mov  1, %o2
a00c4638:  92 10 24 04  mov  0x404, %o1
a00c463c:  94 10 20 07  mov  7, %o2
a00c4640:  40 3b c9 70  call  0xa0fb6c00
a00c4644:  90 10 00 11  mov  %l1, %o0
a00c4648:  40 3b f3 f1  call  0xa0fc160c
a00c464c:  90 10 20 01  mov  1, %o0
a00c4650:  90 10 00 11  mov  %l1, %o0
a00c4654:  92 10 24 04  mov  0x404, %o1
a00c4658:  40 3b c9 6a  call  0xa0fb6c00
a00c465c:  94 10 20 01  mov  1, %o2
a00c4660:  82 10 20 02  mov  2, %g1
a00c4664:  c2 2c a0 0d  stb  %g1, [ %l2 + 0xd ]
a00c4668:  90 10 00 11  mov  %l1, %o0
a00c466c:  92 10 20 00  clr  %o1
a00c4670:  94 10 20 20  mov  0x20, %o2
a00c4674:  40 3b c9 89  call  0xa0fb6c98
a00c4678:  96 10 20 00  clr  %o3
a00c467c:  da 04 80 00  ld  [ %l2 ], %o5
a00c4680:  03 00 20 00  sethi  %hi(0x800000), %g1
a00c4684:  82 2b 40 01  andn  %o5, %g1, %g1
a00c4688:  10 80 01 e7  b  0xa00c4e24
a00c468c:  c2 24 80 00  st  %g1, [ %l2 ]
a00c4690:  90 10 00 11  mov  %l1, %o0
a00c4694:  40 3b c9 49  call  0xa0fb6bb8
a00c4698:  92 10 24 08  mov  0x408, %o1
a00c469c:  80 8a 20 04  btst  4, %o0
a00c46a0:  02 80 00 0d  be  0xa00c46d4
a00c46a4:  90 10 00 11  mov  %l1, %o0
a00c46a8:  92 10 24 08  mov  0x408, %o1
a00c46ac:  40 3b c9 55  call  0xa0fb6c00
a00c46b0:  94 10 20 06  mov  6, %o2
a00c46b4:  c2 04 80 00  ld  [ %l2 ], %g1
a00c46b8:  1b 20 00 00  sethi  %hi(0x80000000), %o5
a00c46bc:  9a 28 40 0d  andn  %g1, %o5, %o5
a00c46c0:  03 10 00 00  sethi  %hi(0x40000000), %g1
a00c46c4:  82 2b 40 01  andn  %o5, %g1, %g1
a00c46c8:  c2 24 80 00  st  %g1, [ %l2 ]
a00c46cc:  10 80 00 bc  b  0xa00c49bc
a00c46d0:  82 10 20 03  mov  3, %g1
a00c46d4:  40 3b c9 39  call  0xa0fb6bb8
a00c46d8:  92 10 24 08  mov  0x408, %o1
a00c46dc:  80 8a 20 08  btst  8, %o0
a00c46e0:  22 80 01 d2  be,a   0xa00c4e28
a00c46e4:  90 05 20 04  add  %l4, 4, %o0
a00c46e8:  90 10 00 11  mov  %l1, %o0
a00c46ec:  92 10 24 08  mov  0x408, %o1
a00c46f0:  40 3b c9 44  call  0xa0fb6c00
a00c46f4:  94 10 20 0a  mov  0xa, %o2
a00c46f8:  10 80 00 b1  b  0xa00c49bc
a00c46fc:  82 10 20 04  mov  4, %g1
a00c4700:  c2 04 80 00  ld  [ %l2 ], %g1
a00c4704:  80 a0 60 00  cmp  %g1, 0
a00c4708:  06 80 00 19  bl  0xa00c476c
a00c470c:  1b 30 00 00  sethi  %hi(0xc0000000), %o5
a00c4710:  03 2a 01 f5  sethi  %hi(0xa807d400), %g1
a00c4714:  da 08 62 2b  ldub  [ %g1 + 0x22b ], %o5	! 0xa807d62b
a00c4718:  80 a3 60 ff  cmp  %o5, 0xff
a00c471c:  02 80 00 05  be  0xa00c4730
a00c4720:  82 04 60 04  add  %l1, 4, %g1
a00c4724:  80 a3 40 01  cmp  %o5, %g1
a00c4728:  32 80 00 0c  bne,a   0xa00c4758
a00c472c:  da 04 80 00  ld  [ %l2 ], %o5
a00c4730:  90 05 20 04  add  %l4, 4, %o0
a00c4734:  7f ff f8 09  call  0xa00c2758
a00c4738:  90 0a 20 ff  and  %o0, 0xff, %o0
a00c473c:  da 04 80 00  ld  [ %l2 ], %o5
a00c4740:  03 20 00 00  sethi  %hi(0x80000000), %g1
a00c4744:  82 2b 40 01  andn  %o5, %g1, %g1
a00c4748:  91 2a 20 1f  sll  %o0, 0x1f, %o0
a00c474c:  82 10 40 08  or  %g1, %o0, %g1
a00c4750:  c2 24 80 00  st  %g1, [ %l2 ]
a00c4754:  da 04 80 00  ld  [ %l2 ], %o5
a00c4758:  03 10 00 00  sethi  %hi(0x40000000), %g1
a00c475c:  82 2b 40 01  andn  %o5, %g1, %g1
a00c4760:  c2 24 80 00  st  %g1, [ %l2 ]
a00c4764:  1b 30 00 00  sethi  %hi(0xc0000000), %o5
a00c4768:  c2 04 80 00  ld  [ %l2 ], %g1
a00c476c:  82 08 40 0d  and  %g1, %o5, %g1
a00c4770:  1b 20 00 00  sethi  %hi(0x80000000), %o5
a00c4774:  80 a0 40 0d  cmp  %g1, %o5
a00c4778:  32 80 00 14  bne,a   0xa00c47c8
a00c477c:  da 04 80 00  ld  [ %l2 ], %o5
a00c4780:  a0 0d 20 ff  and  %l4, 0xff, %l0
a00c4784:  90 10 00 10  mov  %l0, %o0
a00c4788:  40 3b c9 0c  call  0xa0fb6bb8
a00c478c:  92 10 24 08  mov  0x408, %o1
a00c4790:  80 8a 20 10  btst  0x10, %o0
a00c4794:  22 80 00 0d  be,a   0xa00c47c8
a00c4798:  da 04 80 00  ld  [ %l2 ], %o5
a00c479c:  90 10 00 10  mov  %l0, %o0
a00c47a0:  92 10 24 08  mov  0x408, %o1
a00c47a4:  40 3b c9 17  call  0xa0fb6c00
a00c47a8:  94 10 20 10  mov  0x10, %o2
a00c47ac:  c2 04 80 00  ld  [ %l2 ], %g1
a00c47b0:  1b 10 00 00  sethi  %hi(0x40000000), %o5
a00c47b4:  82 10 40 0d  or  %g1, %o5, %g1
a00c47b8:  c2 24 80 00  st  %g1, [ %l2 ]
a00c47bc:  82 10 20 06  mov  6, %g1
a00c47c0:  c2 2c a0 0d  stb  %g1, [ %l2 + 0xd ]
a00c47c4:  da 04 80 00  ld  [ %l2 ], %o5
a00c47c8:  03 10 00 00  sethi  %hi(0x40000000), %g1
a00c47cc:  80 8b 40 01  btst  %o5, %g1
a00c47d0:  02 80 01 96  be  0xa00c4e28
a00c47d4:  90 05 20 04  add  %l4, 4, %o0
a00c47d8:  a0 0d 20 ff  and  %l4, 0xff, %l0
a00c47dc:  90 10 00 10  mov  %l0, %o0
a00c47e0:  40 3b c8 f6  call  0xa0fb6bb8
a00c47e4:  92 10 24 08  mov  0x408, %o1
a00c47e8:  80 8a 20 20  btst  0x20, %o0
a00c47ec:  22 80 01 8f  be,a   0xa00c4e28
a00c47f0:  90 05 20 04  add  %l4, 4, %o0
a00c47f4:  90 10 00 10  mov  %l0, %o0
a00c47f8:  92 10 24 08  mov  0x408, %o1
a00c47fc:  40 3b c9 01  call  0xa0fb6c00
a00c4800:  94 10 20 20  mov  0x20, %o2
a00c4804:  82 10 20 06  mov  6, %g1
a00c4808:  c2 2c a0 0d  stb  %g1, [ %l2 + 0xd ]
a00c480c:  10 80 00 0f  b  0xa00c4848
a00c4810:  90 10 00 10  mov  %l0, %o0
a00c4814:  90 10 00 11  mov  %l1, %o0
a00c4818:  40 3b c8 e8  call  0xa0fb6bb8
a00c481c:  92 10 24 08  mov  0x408, %o1
a00c4820:  80 8a 20 10  btst  0x10, %o0
a00c4824:  22 80 01 81  be,a   0xa00c4e28
a00c4828:  90 05 20 04  add  %l4, 4, %o0
a00c482c:  90 10 00 11  mov  %l1, %o0
a00c4830:  92 10 24 08  mov  0x408, %o1
a00c4834:  40 3b c8 f3  call  0xa0fb6c00
a00c4838:  94 10 20 10  mov  0x10, %o2
a00c483c:  82 10 20 06  mov  6, %g1
a00c4840:  c2 2c a0 0d  stb  %g1, [ %l2 + 0xd ]
a00c4844:  90 10 00 11  mov  %l1, %o0
a00c4848:  92 10 20 00  clr  %o1
a00c484c:  94 10 20 20  mov  0x20, %o2
a00c4850:  40 3b c9 12  call  0xa0fb6c98
a00c4854:  96 10 20 00  clr  %o3
a00c4858:  10 80 01 74  b  0xa00c4e28
a00c485c:  90 05 20 04  add  %l4, 4, %o0
a00c4860:  90 10 00 11  mov  %l1, %o0
a00c4864:  40 3b c8 d5  call  0xa0fb6bb8
a00c4868:  92 10 24 08  mov  0x408, %o1
a00c486c:  80 8a 20 40  btst  0x40, %o0
a00c4870:  22 80 01 6e  be,a   0xa00c4e28
a00c4874:  90 05 20 04  add  %l4, 4, %o0
a00c4878:  90 10 00 11  mov  %l1, %o0
a00c487c:  92 10 20 00  clr  %o1
a00c4880:  94 10 20 20  mov  0x20, %o2
a00c4884:  40 3b c9 05  call  0xa0fb6c98
a00c4888:  96 10 20 00  clr  %o3
a00c488c:  90 10 00 11  mov  %l1, %o0
a00c4890:  92 10 24 08  mov  0x408, %o1
a00c4894:  40 3b c8 db  call  0xa0fb6c00
a00c4898:  94 10 20 40  mov  0x40, %o2
a00c489c:  10 80 00 48  b  0xa00c49bc
a00c48a0:  82 10 20 07  mov  7, %g1
a00c48a4:  90 10 00 11  mov  %l1, %o0
a00c48a8:  40 3b c8 c4  call  0xa0fb6bb8
a00c48ac:  92 10 24 08  mov  0x408, %o1
a00c48b0:  80 8a 20 80  btst  0x80, %o0
a00c48b4:  22 80 01 5d  be,a   0xa00c4e28
a00c48b8:  90 05 20 04  add  %l4, 4, %o0
a00c48bc:  90 10 00 11  mov  %l1, %o0
a00c48c0:  92 10 24 08  mov  0x408, %o1
a00c48c4:  40 3b c8 cf  call  0xa0fb6c00
a00c48c8:  94 10 20 80  mov  0x80, %o2
a00c48cc:  10 80 00 3c  b  0xa00c49bc
a00c48d0:  82 10 20 08  mov  8, %g1
a00c48d4:  90 10 00 11  mov  %l1, %o0
a00c48d8:  40 3b c8 b8  call  0xa0fb6bb8
a00c48dc:  92 10 24 09  mov  0x409, %o1
a00c48e0:  80 8a 20 01  btst  1, %o0
a00c48e4:  02 80 01 51  be  0xa00c4e28
a00c48e8:  90 05 20 04  add  %l4, 4, %o0
a00c48ec:  90 10 00 11  mov  %l1, %o0
a00c48f0:  92 10 24 09  mov  0x409, %o1
a00c48f4:  40 3b c8 c3  call  0xa0fb6c00
a00c48f8:  94 10 20 01  mov  1, %o2
a00c48fc:  03 2a 01 e3  sethi  %hi(0xa8078c00), %g1
a00c4900:  c2 08 60 58  ldub  [ %g1 + 0x58 ], %g1	! 0xa8078c58
a00c4904:  9a 04 60 04  add  %l1, 4, %o5
a00c4908:  83 38 40 0d  sra  %g1, %o5, %g1
a00c490c:  80 88 60 01  btst  1, %g1
a00c4910:  12 80 00 2b  bne  0xa00c49bc
a00c4914:  82 10 20 09  mov  9, %g1
a00c4918:  da 04 80 00  ld  [ %l2 ], %o5
a00c491c:  03 00 20 00  sethi  %hi(0x800000), %g1
a00c4920:  9a 13 40 01  or  %o5, %g1, %o5
a00c4924:  82 10 20 0d  mov  0xd, %g1
a00c4928:  11 27 c6 dd  sethi  %hi(0x9f1b7400), %o0
a00c492c:  c2 2c a0 0d  stb  %g1, [ %l2 + 0xd ]
a00c4930:  da 24 80 00  st  %o5, [ %l2 ]
a00c4934:  92 10 00 11  mov  %l1, %o1
a00c4938:  40 3a f9 c3  call  0xa0f83044
a00c493c:  90 12 21 f0  or  %o0, 0x1f0, %o0
a00c4940:  10 80 01 3a  b  0xa00c4e28
a00c4944:  90 05 20 04  add  %l4, 4, %o0
a00c4948:  da 04 80 00  ld  [ %l2 ], %o5
a00c494c:  03 00 10 00  sethi  %hi(0x400000), %g1
a00c4950:  80 8b 40 01  btst  %o5, %g1
a00c4954:  02 80 01 35  be  0xa00c4e28
a00c4958:  90 05 20 04  add  %l4, 4, %o0
a00c495c:  c2 0f bf f4  ldub  [ %fp + -12 ], %g1
a00c4960:  80 a0 60 00  cmp  %g1, 0
a00c4964:  12 80 01 31  bne  0xa00c4e28
a00c4968:  92 10 20 00  clr  %o1
a00c496c:  90 10 00 11  mov  %l1, %o0
a00c4970:  94 10 20 20  mov  0x20, %o2
a00c4974:  40 3b c8 c9  call  0xa0fb6c98
a00c4978:  96 10 20 00  clr  %o3
a00c497c:  90 10 00 11  mov  %l1, %o0
a00c4980:  92 10 24 05  mov  0x405, %o1
a00c4984:  94 10 20 10  mov  0x10, %o2
a00c4988:  40 3b c8 c4  call  0xa0fb6c98
a00c498c:  96 10 20 00  clr  %o3
a00c4990:  90 10 00 11  mov  %l1, %o0
a00c4994:  92 10 24 05  mov  0x405, %o1
a00c4998:  94 10 20 10  mov  0x10, %o2
a00c499c:  40 3b c8 bf  call  0xa0fb6c98
a00c49a0:  96 10 20 01  mov  1, %o3
a00c49a4:  90 10 00 11  mov  %l1, %o0
a00c49a8:  92 10 24 05  mov  0x405, %o1
a00c49ac:  94 10 20 10  mov  0x10, %o2
a00c49b0:  40 3b c8 ba  call  0xa0fb6c98
a00c49b4:  96 10 20 00  clr  %o3
a00c49b8:  82 10 20 0a  mov  0xa, %g1
a00c49bc:  10 80 01 1a  b  0xa00c4e24
a00c49c0:  c2 2c a0 0d  stb  %g1, [ %l2 + 0xd ]
a00c49c4:  90 10 00 11  mov  %l1, %o0
a00c49c8:  40 3b c8 7c  call  0xa0fb6bb8
a00c49cc:  92 10 24 09  mov  0x409, %o1
a00c49d0:  80 8a 20 02  btst  2, %o0
a00c49d4:  02 80 00 06  be  0xa00c49ec
a00c49d8:  90 10 00 11  mov  %l1, %o0
a00c49dc:  92 10 24 09  mov  0x409, %o1
a00c49e0:  40 3b c8 88  call  0xa0fb6c00
a00c49e4:  94 10 20 02  mov  2, %o2
a00c49e8:  90 10 00 11  mov  %l1, %o0
a00c49ec:  40 3b c8 73  call  0xa0fb6bb8
a00c49f0:  92 10 24 09  mov  0x409, %o1
a00c49f4:  80 8a 20 04  btst  4, %o0
a00c49f8:  02 80 00 06  be  0xa00c4a10
a00c49fc:  90 10 00 11  mov  %l1, %o0
a00c4a00:  92 10 24 09  mov  0x409, %o1
a00c4a04:  40 3b c8 7f  call  0xa0fb6c00
a00c4a08:  94 10 20 04  mov  4, %o2
a00c4a0c:  90 10 00 11  mov  %l1, %o0
a00c4a10:  40 3b c8 6a  call  0xa0fb6bb8
a00c4a14:  92 10 24 09  mov  0x409, %o1
a00c4a18:  80 8a 20 40  btst  0x40, %o0
a00c4a1c:  02 80 00 0d  be  0xa00c4a50
a00c4a20:  90 10 00 11  mov  %l1, %o0
a00c4a24:  92 10 24 09  mov  0x409, %o1
a00c4a28:  40 3b c8 76  call  0xa0fb6c00
a00c4a2c:  94 10 20 40  mov  0x40, %o2
a00c4a30:  90 10 00 11  mov  %l1, %o0
a00c4a34:  92 10 24 0e  mov  0x40e, %o1
a00c4a38:  94 10 20 80  mov  0x80, %o2
a00c4a3c:  40 3b c8 97  call  0xa0fb6c98
a00c4a40:  96 10 20 01  mov  1, %o3
a00c4a44:  82 10 20 01  mov  1, %g1
a00c4a48:  c2 2c a0 0d  stb  %g1, [ %l2 + 0xd ]
a00c4a4c:  90 10 00 11  mov  %l1, %o0
a00c4a50:  40 3b c8 5a  call  0xa0fb6bb8
a00c4a54:  92 10 24 09  mov  0x409, %o1
a00c4a58:  80 8a 20 08  btst  8, %o0
a00c4a5c:  02 80 00 e7  be  0xa00c4df8
a00c4a60:  a0 0d 20 ff  and  %l4, 0xff, %l0
a00c4a64:  90 10 00 11  mov  %l1, %o0
a00c4a68:  92 10 24 09  mov  0x409, %o1
a00c4a6c:  40 3b c8 65  call  0xa0fb6c00
a00c4a70:  94 10 20 08  mov  8, %o2
a00c4a74:  82 10 20 01  mov  1, %g1
a00c4a78:  c2 2f bf f4  stb  %g1, [ %fp + -12 ]
a00c4a7c:  90 10 00 11  mov  %l1, %o0
a00c4a80:  92 10 24 06  mov  0x406, %o1
a00c4a84:  40 3b c8 5f  call  0xa0fb6c00
a00c4a88:  94 10 20 90  mov  0x90, %o2
a00c4a8c:  90 10 00 11  mov  %l1, %o0
a00c4a90:  40 3b c8 4a  call  0xa0fb6bb8
a00c4a94:  92 10 24 06  mov  0x406, %o1
a00c4a98:  80 8a 20 80  btst  0x80, %o0
a00c4a9c:  12 bf ff fd  bne  0xa00c4a90
a00c4aa0:  90 10 00 11  mov  %l1, %o0
a00c4aa4:  92 10 24 00  mov  0x400, %o1
a00c4aa8:  40 3b c8 56  call  0xa0fb6c00
a00c4aac:  94 10 20 0d  mov  0xd, %o2
a00c4ab0:  90 10 00 11  mov  %l1, %o0
a00c4ab4:  92 10 24 02  mov  0x402, %o1
a00c4ab8:  40 3b c8 52  call  0xa0fb6c00
a00c4abc:  94 10 20 80  mov  0x80, %o2
a00c4ac0:  94 10 20 00  clr  %o2
a00c4ac4:  90 10 00 11  mov  %l1, %o0
a00c4ac8:  40 3b c8 4e  call  0xa0fb6c00
a00c4acc:  92 10 24 03  mov  0x403, %o1
a00c4ad0:  92 10 24 01  mov  0x401, %o1
a00c4ad4:  40 3b c8 39  call  0xa0fb6bb8
a00c4ad8:  90 10 00 11  mov  %l1, %o0
a00c4adc:  d0 2f bf e8  stb  %o0, [ %fp + -24 ]
a00c4ae0:  92 10 24 01  mov  0x401, %o1
a00c4ae4:  40 3b c8 35  call  0xa0fb6bb8
a00c4ae8:  90 10 00 11  mov  %l1, %o0
a00c4aec:  d0 2f bf e9  stb  %o0, [ %fp + -23 ]
a00c4af0:  92 10 24 01  mov  0x401, %o1
a00c4af4:  40 3b c8 31  call  0xa0fb6bb8
a00c4af8:  90 10 00 11  mov  %l1, %o0
a00c4afc:  d0 2f bf ea  stb  %o0, [ %fp + -22 ]
a00c4b00:  92 10 24 01  mov  0x401, %o1
a00c4b04:  40 3b c8 2d  call  0xa0fb6bb8
a00c4b08:  90 10 00 11  mov  %l1, %o0
a00c4b0c:  92 10 24 01  mov  0x401, %o1
a00c4b10:  40 3b c8 2a  call  0xa0fb6bb8
a00c4b14:  90 10 00 11  mov  %l1, %o0
a00c4b18:  d0 2c a0 03  stb  %o0, [ %l2 + 3 ]
a00c4b1c:  a6 02 00 08  add  %o0, %o0, %l3
a00c4b20:  92 10 24 01  mov  0x401, %o1
a00c4b24:  40 3b c8 25  call  0xa0fb6bb8
a00c4b28:  90 10 00 11  mov  %l1, %o0
a00c4b2c:  21 3f f7 ff  sethi  %hi(0xffdffc00), %l0
a00c4b30:  c2 04 80 00  ld  [ %l2 ], %g1
a00c4b34:  a0 14 23 ff  or  %l0, 0x3ff, %l0
a00c4b38:  90 0a 20 01  and  %o0, 1, %o0
a00c4b3c:  91 2a 20 15  sll  %o0, 0x15, %o0
a00c4b40:  82 08 40 10  and  %g1, %l0, %g1
a00c4b44:  82 10 40 08  or  %g1, %o0, %g1
a00c4b48:  c2 24 80 00  st  %g1, [ %l2 ]
a00c4b4c:  92 10 24 01  mov  0x401, %o1
a00c4b50:  40 3b c8 1a  call  0xa0fb6bb8
a00c4b54:  90 10 00 11  mov  %l1, %o0
a00c4b58:  c2 04 80 00  ld  [ %l2 ], %g1
a00c4b5c:  90 0a 20 01  and  %o0, 1, %o0
a00c4b60:  91 2a 20 15  sll  %o0, 0x15, %o0
a00c4b64:  82 08 40 10  and  %g1, %l0, %g1
a00c4b68:  82 10 40 08  or  %g1, %o0, %g1
a00c4b6c:  c2 24 80 00  st  %g1, [ %l2 ]
a00c4b70:  90 10 00 11  mov  %l1, %o0
a00c4b74:  92 10 24 0e  mov  0x40e, %o1
a00c4b78:  94 10 20 20  mov  0x20, %o2
a00c4b7c:  40 3b c8 47  call  0xa0fb6c98
a00c4b80:  96 10 20 01  mov  1, %o3
a00c4b84:  90 10 00 11  mov  %l1, %o0
a00c4b88:  40 3b c8 0c  call  0xa0fb6bb8
a00c4b8c:  92 10 24 0e  mov  0x40e, %o1
a00c4b90:  80 8a 20 20  btst  0x20, %o0
a00c4b94:  12 bf ff fd  bne  0xa00c4b88
a00c4b98:  90 10 00 11  mov  %l1, %o0
a00c4b9c:  92 10 24 02  mov  0x402, %o1
a00c4ba0:  40 3b c8 18  call  0xa0fb6c00
a00c4ba4:  94 10 20 90  mov  0x90, %o2
a00c4ba8:  90 10 00 11  mov  %l1, %o0
a00c4bac:  92 10 24 03  mov  0x403, %o1
a00c4bb0:  40 3b c8 14  call  0xa0fb6c00
a00c4bb4:  94 10 20 00  clr  %o2
a00c4bb8:  90 10 00 11  mov  %l1, %o0
a00c4bbc:  92 10 24 01  mov  0x401, %o1
a00c4bc0:  40 3b c8 10  call  0xa0fb6c00
a00c4bc4:  d4 0f bf e8  ldub  [ %fp + -24 ], %o2
a00c4bc8:  90 10 00 11  mov  %l1, %o0
a00c4bcc:  92 10 24 03  mov  0x403, %o1
a00c4bd0:  40 3b c8 0c  call  0xa0fb6c00
a00c4bd4:  94 10 20 01  mov  1, %o2
a00c4bd8:  90 10 00 11  mov  %l1, %o0
a00c4bdc:  92 10 24 01  mov  0x401, %o1
a00c4be0:  40 3b c8 08  call  0xa0fb6c00
a00c4be4:  d4 0f bf e9  ldub  [ %fp + -23 ], %o2
a00c4be8:  90 10 00 11  mov  %l1, %o0
a00c4bec:  92 10 24 03  mov  0x403, %o1
a00c4bf0:  40 3b c8 04  call  0xa0fb6c00
a00c4bf4:  94 10 20 02  mov  2, %o2
a00c4bf8:  90 10 00 11  mov  %l1, %o0
a00c4bfc:  92 10 24 01  mov  0x401, %o1
a00c4c00:  40 3b c8 00  call  0xa0fb6c00
a00c4c04:  d4 0f bf ea  ldub  [ %fp + -22 ], %o2
a00c4c08:  90 10 00 11  mov  %l1, %o0
a00c4c0c:  92 10 24 03  mov  0x403, %o1
a00c4c10:  40 3b c7 fc  call  0xa0fb6c00
a00c4c14:  94 10 20 04  mov  4, %o2
a00c4c18:  90 10 00 11  mov  %l1, %o0
a00c4c1c:  92 10 24 01  mov  0x401, %o1
a00c4c20:  40 3b c7 f8  call  0xa0fb6c00
a00c4c24:  d4 0c a0 03  ldub  [ %l2 + 3 ], %o2
a00c4c28:  90 10 00 11  mov  %l1, %o0
a00c4c2c:  92 10 24 03  mov  0x403, %o1
a00c4c30:  40 3b c7 f4  call  0xa0fb6c00
a00c4c34:  94 10 20 06  mov  6, %o2
a00c4c38:  d4 04 80 00  ld  [ %l2 ], %o2
a00c4c3c:  95 32 a0 15  srl  %o2, 0x15, %o2
a00c4c40:  94 0a a0 01  and  %o2, 1, %o2
a00c4c44:  90 10 00 11  mov  %l1, %o0
a00c4c48:  40 3b c7 ee  call  0xa0fb6c00
a00c4c4c:  92 10 24 01  mov  0x401, %o1
a00c4c50:  94 04 e0 05  add  %l3, 5, %o2
a00c4c54:  94 0a a0 ff  and  %o2, 0xff, %o2
a00c4c58:  90 10 00 11  mov  %l1, %o0
a00c4c5c:  40 3b c7 e9  call  0xa0fb6c00
a00c4c60:  92 10 24 03  mov  0x403, %o1
a00c4c64:  90 10 00 11  mov  %l1, %o0
a00c4c68:  92 10 24 01  mov  0x401, %o1
a00c4c6c:  40 3b c7 e5  call  0xa0fb6c00
a00c4c70:  d4 0f bf e8  ldub  [ %fp + -24 ], %o2
a00c4c74:  94 04 e0 06  add  %l3, 6, %o2
a00c4c78:  94 0a a0 fe  and  %o2, 0xfe, %o2
a00c4c7c:  90 10 00 11  mov  %l1, %o0
a00c4c80:  40 3b c7 e0  call  0xa0fb6c00
a00c4c84:  92 10 24 03  mov  0x403, %o1
a00c4c88:  90 10 00 11  mov  %l1, %o0
a00c4c8c:  92 10 24 01  mov  0x401, %o1
a00c4c90:  40 3b c7 dc  call  0xa0fb6c00
a00c4c94:  d4 0f bf e9  ldub  [ %fp + -23 ], %o2
a00c4c98:  94 04 e0 07  add  %l3, 7, %o2
a00c4c9c:  94 0a a0 ff  and  %o2, 0xff, %o2
a00c4ca0:  90 10 00 11  mov  %l1, %o0
a00c4ca4:  40 3b c7 d7  call  0xa0fb6c00
a00c4ca8:  92 10 24 03  mov  0x403, %o1
a00c4cac:  90 10 00 11  mov  %l1, %o0
a00c4cb0:  92 10 24 01  mov  0x401, %o1
a00c4cb4:  40 3b c7 d3  call  0xa0fb6c00
a00c4cb8:  d4 0f bf ea  ldub  [ %fp + -22 ], %o2
a00c4cbc:  94 04 e0 08  add  %l3, 8, %o2
a00c4cc0:  94 0a a0 fe  and  %o2, 0xfe, %o2
a00c4cc4:  90 10 00 11  mov  %l1, %o0
a00c4cc8:  40 3b c7 ce  call  0xa0fb6c00
a00c4ccc:  92 10 24 03  mov  0x403, %o1
a00c4cd0:  90 10 00 11  mov  %l1, %o0
a00c4cd4:  92 10 24 01  mov  0x401, %o1
a00c4cd8:  40 3b c7 ca  call  0xa0fb6c00
a00c4cdc:  94 10 20 80  mov  0x80, %o2
a00c4ce0:  90 10 00 11  mov  %l1, %o0
a00c4ce4:  92 10 24 02  mov  0x402, %o1
a00c4ce8:  40 3b c7 c6  call  0xa0fb6c00
a00c4cec:  94 10 20 00  clr  %o2
a00c4cf0:  96 10 20 01  mov  1, %o3
a00c4cf4:  90 10 00 11  mov  %l1, %o0
a00c4cf8:  92 10 24 05  mov  0x405, %o1
a00c4cfc:  40 3b c7 e7  call  0xa0fb6c98
a00c4d00:  94 10 20 01  mov  1, %o2
a00c4d04:  90 10 00 11  mov  %l1, %o0
a00c4d08:  92 10 24 0a  mov  0x40a, %o1
a00c4d0c:  40 3b c7 bd  call  0xa0fb6c00
a00c4d10:  94 10 20 01  mov  1, %o2
a00c4d14:  90 10 00 11  mov  %l1, %o0
a00c4d18:  92 10 24 05  mov  0x405, %o1
a00c4d1c:  94 10 20 20  mov  0x20, %o2
a00c4d20:  40 3b c7 de  call  0xa0fb6c98
a00c4d24:  96 10 20 01  mov  1, %o3
a00c4d28:  96 10 20 00  clr  %o3
a00c4d2c:  90 10 00 11  mov  %l1, %o0
a00c4d30:  92 10 24 05  mov  0x405, %o1
a00c4d34:  40 3b c7 d9  call  0xa0fb6c98
a00c4d38:  94 10 20 20  mov  0x20, %o2
a00c4d3c:  1b 00 20 00  sethi  %hi(0x800000), %o5
a00c4d40:  c2 04 80 00  ld  [ %l2 ], %g1
a00c4d44:  82 10 40 0d  or  %g1, %o5, %g1
a00c4d48:  c2 24 80 00  st  %g1, [ %l2 ]
a00c4d4c:  90 10 00 11  mov  %l1, %o0
a00c4d50:  92 10 24 00  mov  0x400, %o1
a00c4d54:  40 3b c7 ab  call  0xa0fb6c00
a00c4d58:  94 10 20 12  mov  0x12, %o2
a00c4d5c:  90 10 00 11  mov  %l1, %o0
a00c4d60:  92 10 24 02  mov  0x402, %o1
a00c4d64:  40 3b c7 a7  call  0xa0fb6c00
a00c4d68:  94 10 20 90  mov  0x90, %o2
a00c4d6c:  90 10 00 11  mov  %l1, %o0
a00c4d70:  92 10 24 03  mov  0x403, %o1
a00c4d74:  40 3b c7 a3  call  0xa0fb6c00
a00c4d78:  94 10 20 08  mov  8, %o2
a00c4d7c:  d4 04 80 00  ld  [ %l2 ], %o2
a00c4d80:  95 32 a0 15  srl  %o2, 0x15, %o2
a00c4d84:  94 0a a0 01  and  %o2, 1, %o2
a00c4d88:  90 10 00 11  mov  %l1, %o0
a00c4d8c:  40 3b c7 9d  call  0xa0fb6c00
a00c4d90:  92 10 24 01  mov  0x401, %o1
a00c4d94:  90 10 00 11  mov  %l1, %o0
a00c4d98:  92 10 24 03  mov  0x403, %o1
a00c4d9c:  40 3b c7 99  call  0xa0fb6c00
a00c4da0:  94 10 20 09  mov  9, %o2
a00c4da4:  d4 04 80 00  ld  [ %l2 ], %o2
a00c4da8:  95 32 a0 15  srl  %o2, 0x15, %o2
a00c4dac:  94 0a a0 01  and  %o2, 1, %o2
a00c4db0:  90 10 00 11  mov  %l1, %o0
a00c4db4:  40 3b c7 93  call  0xa0fb6c00
a00c4db8:  92 10 24 01  mov  0x401, %o1
a00c4dbc:  90 10 00 11  mov  %l1, %o0
a00c4dc0:  92 10 24 03  mov  0x403, %o1
a00c4dc4:  40 3b c7 8f  call  0xa0fb6c00
a00c4dc8:  94 10 20 0a  mov  0xa, %o2
a00c4dcc:  d4 04 80 00  ld  [ %l2 ], %o2
a00c4dd0:  95 32 a0 15  srl  %o2, 0x15, %o2
a00c4dd4:  94 0a a0 01  and  %o2, 1, %o2
a00c4dd8:  90 10 00 11  mov  %l1, %o0
a00c4ddc:  40 3b c7 89  call  0xa0fb6c00
a00c4de0:  92 10 24 01  mov  0x401, %o1
a00c4de4:  90 10 00 11  mov  %l1, %o0
a00c4de8:  92 10 24 00  mov  0x400, %o1
a00c4dec:  40 3b c7 85  call  0xa0fb6c00
a00c4df0:  94 10 20 00  clr  %o2
a00c4df4:  a0 0d 20 ff  and  %l4, 0xff, %l0
a00c4df8:  90 10 00 10  mov  %l0, %o0
a00c4dfc:  40 3b c7 6f  call  0xa0fb6bb8
a00c4e00:  92 10 24 09  mov  0x409, %o1
a00c4e04:  80 8a 20 10  btst  0x10, %o0
a00c4e08:  22 80 00 08  be,a   0xa00c4e28
a00c4e0c:  90 05 20 04  add  %l4, 4, %o0
a00c4e10:  90 10 00 10  mov  %l0, %o0
a00c4e14:  92 10 24 09  mov  0x409, %o1
a00c4e18:  40 3b c7 7a  call  0xa0fb6c00
a00c4e1c:  94 10 20 10  mov  0x10, %o2
a00c4e20:  c0 2f bf f4  clrb  [ %fp + -12 ]
a00c4e24:  90 05 20 04  add  %l4, 4, %o0
a00c4e28:  7f ff f8 c7  call  0xa00c3144
a00c4e2c:  90 0a 20 ff  and  %o0, 0xff, %o0
a00c4e30:  a8 05 20 01  inc  %l4
a00c4e34:  82 0d 20 ff  and  %l4, 0xff, %g1
a00c4e38:  80 a0 60 01  cmp  %g1, 1
a00c4e3c:  08 bf fd b1  bleu  0xa00c4500
a00c4e40:  a2 0d 20 ff  and  %l4, 0xff, %l1
a00c4e44:  81 c7 e0 08  ret
a00c4e48:  81 e8 00 00  restore
