# leon2m FUN_a00f446c 0xa00f446c-0xa00f4e60 (2548 bytes)
a00f446c:  9d e3 bf 80  save  %sp, -128, %sp
a00f4470:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00f4474:  40 00 b6 36  call  0xa0121d4c
a00f4478:  90 10 00 18  mov  %i0, %o0
a00f447c:  80 8a 20 ff  btst  0xff, %o0
a00f4480:  02 80 02 76  be  0xa00f4e58
a00f4484:  82 10 20 00  clr  %g1
a00f4488:  94 10 20 04  mov  4, %o2
a00f448c:  37 2a 00 ad  sethi  %hi(0xa802b400), %i3
a00f4490:  d4 2e e3 b1  stb  %o2, [ %i3 + 0x3b1 ]	! 0xa802b7b1
a00f4494:  92 10 20 2a  mov  0x2a, %o1
a00f4498:  7f ff f7 6f  call  0xa00f2254
a00f449c:  90 10 00 18  mov  %i0, %o0
a00f44a0:  b4 10 00 08  mov  %o0, %i2
a00f44a4:  92 10 20 4a  mov  0x4a, %o1
a00f44a8:  7f ff f5 7a  call  0xa00f1a90
a00f44ac:  90 10 00 18  mov  %i0, %o0
a00f44b0:  d0 2f bf f7  stb  %o0, [ %fp + -9 ]
a00f44b4:  90 10 00 18  mov  %i0, %o0
a00f44b8:  92 10 20 2a  mov  0x2a, %o1
a00f44bc:  7f ff f7 77  call  0xa00f2298
a00f44c0:  94 10 20 00  clr  %o2
a00f44c4:  13 33 c0 80  sethi  %hi(0xcf020000), %o1
a00f44c8:  82 12 61 14  or  %o1, 0x114, %g1	! 0xcf020114
a00f44cc:  d0 00 40 00  ld  [ %g1 ], %o0
a00f44d0:  9a 0a 20 07  and  %o0, 7, %o5
a00f44d4:  80 a3 60 05  cmp  %o5, 5
a00f44d8:  02 80 01 d9  be  0xa00f4c3c
a00f44dc:  90 10 00 18  mov  %i0, %o0
a00f44e0:  92 10 20 4a  mov  0x4a, %o1
a00f44e4:  94 10 20 80  mov  0x80, %o2
a00f44e8:  96 10 20 00  clr  %o3
a00f44ec:  7f ff f5 9c  call  0xa00f1b5c
a00f44f0:  29 2a 00 ad  sethi  %hi(0xa802b400), %l4
a00f44f4:  3b 2a 00 ad  sethi  %hi(0xa802b400), %i5
a00f44f8:  c0 2d 23 ad  clrb  [ %l4 + 0x3ad ]
a00f44fc:  c0 2f 63 ac  clrb  [ %i5 + 0x3ac ]
a00f4500:  90 10 00 18  mov  %i0, %o0
a00f4504:  7f ff fd c5  call  0xa00f3c18
a00f4508:  92 10 00 19  mov  %i1, %o1
a00f450c:  80 8a 20 ff  btst  0xff, %o0
a00f4510:  02 80 01 a4  be  0xa00f4ba0
a00f4514:  e0 0f 63 ac  ldub  [ %i5 + 0x3ac ], %l0
a00f4518:  80 a4 20 00  cmp  %l0, 0
a00f451c:  02 80 00 8b  be  0xa00f4748
a00f4520:  e2 0d 23 ad  ldub  [ %l4 + 0x3ad ], %l1
a00f4524:  c2 0e e3 b1  ldub  [ %i3 + 0x3b1 ], %g1
a00f4528:  90 08 60 ff  and  %g1, 0xff, %o0
a00f452c:  80 a2 20 63  cmp  %o0, 0x63
a00f4530:  18 80 00 06  bgu  0xa00f4548
a00f4534:  39 2a 00 ad  sethi  %hi(0xa802b400), %i4
a00f4538:  da 07 23 9c  ld  [ %i4 + 0x39c ], %o5	! 0xa802b79c
a00f453c:  80 a3 60 00  cmp  %o5, 0
a00f4540:  12 80 02 14  bne  0xa00f4d90
a00f4544:  ae 00 60 01  add  %g1, 1, %l7
a00f4548:  7f ff fb f8  call  0xa00f3528
a00f454c:  ae 10 20 00  clr  %l7
a00f4550:  a4 10 00 08  mov  %o0, %l2
a00f4554:  ac 10 20 00  clr  %l6
a00f4558:  aa 10 00 08  mov  %o0, %l5
a00f455c:  a6 10 20 00  clr  %l3
a00f4560:  a8 10 3f ff  mov  -1, %l4
a00f4564:  a2 04 bf fe  add  %l2, -2, %l1
a00f4568:  a0 10 20 00  clr  %l0
a00f456c:  91 2c 60 10  sll  %l1, 0x10, %o0
a00f4570:  93 32 20 10  srl  %o0, 0x10, %o1
a00f4574:  7f ff ff 51  call  0xa00f42b8
a00f4578:  90 10 00 18  mov  %i0, %o0
a00f457c:  7f ff fe 7a  call  0xa00f3f64
a00f4580:  90 10 00 18  mov  %i0, %o0
a00f4584:  a0 04 20 01  inc  %l0
a00f4588:  de 0f 63 ac  ldub  [ %i5 + 0x3ac ], %o7
a00f458c:  80 a3 e0 01  cmp  %o7, 1
a00f4590:  02 80 01 b7  be  0xa00f4c6c
a00f4594:  98 0c 20 ff  and  %l0, 0xff, %o4
a00f4598:  80 a4 c0 08  cmp  %l3, %o0
a00f459c:  1a 80 00 08  bcc  0xa00f45bc
a00f45a0:  80 a5 00 08  cmp  %l4, %o0
a00f45a4:  15 2a 00 ad  sethi  %hi(0xa802b400), %o2
a00f45a8:  1b 2a 00 ad  sethi  %hi(0xa802b400), %o5
a00f45ac:  ee 0a a3 af  ldub  [ %o2 + 0x3af ], %l7
a00f45b0:  ec 0b 63 b0  ldub  [ %o5 + 0x3b0 ], %l6
a00f45b4:  a6 10 00 08  mov  %o0, %l3
a00f45b8:  a4 10 00 11  mov  %l1, %l2
a00f45bc:  08 80 00 04  bleu  0xa00f45cc
a00f45c0:  80 a3 20 03  cmp  %o4, 3
a00f45c4:  a8 10 00 08  mov  %o0, %l4
a00f45c8:  aa 10 00 11  mov  %l1, %l5
a00f45cc:  08 bf ff e8  bleu  0xa00f456c
a00f45d0:  a2 04 60 01  inc  %l1
a00f45d4:  90 10 00 12  mov  %l2, %o0
a00f45d8:  93 2d 60 10  sll  %l5, 0x10, %o1
a00f45dc:  ab 2a 20 10  sll  %o0, 0x10, %l5
a00f45e0:  a3 35 60 10  srl  %l5, 0x10, %l1
a00f45e4:  a5 32 60 10  srl  %o1, 0x10, %l2
a00f45e8:  98 24 40 12  sub  %l1, %l2, %o4
a00f45ec:  97 3b 20 1f  sra  %o4, 0x1f, %o3
a00f45f0:  82 1a c0 0c  xor  %o3, %o4, %g1
a00f45f4:  a0 20 40 0b  sub  %g1, %o3, %l0
a00f45f8:  80 a4 20 01  cmp  %l0, 1
a00f45fc:  32 80 00 02  bne,a   0xa00f4604
a00f4600:  90 0a 3f fe  and  %o0, -2, %o0
a00f4604:  9f 2a 20 10  sll  %o0, 0x10, %o7
a00f4608:  a9 33 e0 10  srl  %o7, 0x10, %l4
a00f460c:  90 10 00 18  mov  %i0, %o0
a00f4610:  7f ff ff 2a  call  0xa00f42b8
a00f4614:  92 10 00 14  mov  %l4, %o1
a00f4618:  80 a4 40 14  cmp  %l1, %l4
a00f461c:  02 80 00 09  be  0xa00f4640
a00f4620:  01 00 00 00  nop
a00f4624:  7f ff fe 50  call  0xa00f3f64
a00f4628:  90 10 00 18  mov  %i0, %o0
a00f462c:  2d 2a 00 ad  sethi  %hi(0xa802b400), %l6
a00f4630:  ee 0d a3 af  ldub  [ %l6 + 0x3af ], %l7	! 0xa802b7af
a00f4634:  23 2a 00 ad  sethi  %hi(0xa802b400), %l1
a00f4638:  a6 10 00 08  mov  %o0, %l3
a00f463c:  ec 0c 63 b0  ldub  [ %l1 + 0x3b0 ], %l6
a00f4640:  40 00 11 e5  call  0xa00f8dd4
a00f4644:  90 10 00 18  mov  %i0, %o0
a00f4648:  a4 10 00 08  mov  %o0, %l2
a00f464c:  40 00 11 e9  call  0xa00f8df0
a00f4650:  90 10 00 18  mov  %i0, %o0
a00f4654:  97 2a 20 10  sll  %o0, 0x10, %o3
a00f4658:  a1 2c a0 10  sll  %l2, 0x10, %l0
a00f465c:  95 34 20 10  srl  %l0, 0x10, %o2
a00f4660:  83 32 e0 10  srl  %o3, 0x10, %g1
a00f4664:  9a 5a 80 01  smul  %o2, %g1, %o5
a00f4668:  91 2b 60 06  sll  %o5, 6, %o0
a00f466c:  98 05 e0 18  add  %l7, 0x18, %o4
a00f4670:  80 a4 c0 08  cmp  %l3, %o0
a00f4674:  0a 80 00 04  bcs  0xa00f4684
a00f4678:  9a 10 20 20  mov  0x20, %o5
a00f467c:  98 05 bf f8  add  %l6, -8, %o4
a00f4680:  9a 10 20 10  mov  0x10, %o5
a00f4684:  a6 0b 20 3f  and  %o4, 0x3f, %l3
a00f4688:  2f 2a 00 ad  sethi  %hi(0xa802b400), %l7
a00f468c:  da 2d e3 ae  stb  %o5, [ %l7 + 0x3ae ]	! 0xa802b7ae
a00f4690:  7f ff fc 50  call  0xa00f37d0
a00f4694:  90 0c e0 3f  and  %l3, 0x3f, %o0
a00f4698:  82 10 20 01  mov  1, %g1
a00f469c:  80 a0 60 00  cmp  %g1, 0
a00f46a0:  12 80 00 b4  bne  0xa00f4970
a00f46a4:  23 2a 00 ad  sethi  %hi(0xa802b400), %l1
a00f46a8:  94 0e a0 ff  and  %i2, 0xff, %o2
a00f46ac:  90 10 00 18  mov  %i0, %o0
a00f46b0:  7f ff f6 fa  call  0xa00f2298
a00f46b4:  92 10 20 2a  mov  0x2a, %o1
a00f46b8:  90 10 00 18  mov  %i0, %o0
a00f46bc:  d4 0f bf f7  ldub  [ %fp + -9 ], %o2
a00f46c0:  7f ff f5 05  call  0xa00f1ad4
a00f46c4:  92 10 20 4a  mov  0x4a, %o1
a00f46c8:  f2 07 23 9c  ld  [ %i4 + 0x39c ], %i1
a00f46cc:  80 a6 60 00  cmp  %i1, 0
a00f46d0:  02 80 01 e2  be  0xa00f4e58
a00f46d4:  82 10 20 00  clr  %g1
a00f46d8:  1b 2a 00 ad  sethi  %hi(0xa802b400), %o5
a00f46dc:  f4 0b 63 b1  ldub  [ %o5 + 0x3b1 ], %i2	! 0xa802b7b1
a00f46e0:  80 a6 a0 63  cmp  %i2, 0x63
a00f46e4:  18 80 00 15  bgu  0xa00f4738
a00f46e8:  c2 07 23 9c  ld  [ %i4 + 0x39c ], %g1
a00f46ec:  a0 10 00 0d  mov  %o5, %l0
a00f46f0:  d8 0c 23 b1  ldub  [ %l0 + 0x3b1 ], %o4
a00f46f4:  92 03 20 01  add  %o4, 1, %o1
a00f46f8:  d2 2c 23 b1  stb  %o1, [ %l0 + 0x3b1 ]
a00f46fc:  f6 07 23 9c  ld  [ %i4 + 0x39c ], %i3
a00f4700:  9f c6 c0 00  call  %i3
a00f4704:  90 0b 20 ff  and  %o4, 0xff, %o0
a00f4708:  67 fe 62 a6  call  0x4008d1a0
a00f470c:  90 10 20 14  mov  0x14, %o0
a00f4710:  40 00 b3 19  call  0xa0121374
a00f4714:  90 10 00 18  mov  %i0, %o0
a00f4718:  90 0a 20 ff  and  %o0, 0xff, %o0
a00f471c:  80 a2 20 01  cmp  %o0, 1
a00f4720:  02 80 01 99  be  0xa00f4d84
a00f4724:  ea 0c 23 b1  ldub  [ %l0 + 0x3b1 ], %l5
a00f4728:  80 a5 60 63  cmp  %l5, 0x63
a00f472c:  08 bf ff f2  bleu  0xa00f46f4
a00f4730:  d8 0c 23 b1  ldub  [ %l0 + 0x3b1 ], %o4
a00f4734:  c2 07 23 9c  ld  [ %i4 + 0x39c ], %g1
a00f4738:  9f c0 40 00  call  %g1
a00f473c:  90 10 20 64  mov  0x64, %o0
a00f4740:  10 80 01 c6  b  0xa00f4e58
a00f4744:  82 10 20 00  clr  %g1
a00f4748:  80 a4 60 00  cmp  %l1, 0
a00f474c:  12 bf ff 77  bne  0xa00f4528
a00f4750:  c2 0e e3 b1  ldub  [ %i3 + 0x3b1 ], %g1
a00f4754:  e4 16 60 0c  lduh  [ %i1 + 0xc ], %l2
a00f4758:  ad 2c a0 10  sll  %l2, 0x10, %l6
a00f475c:  af 35 a0 10  srl  %l6, 0x10, %l7
a00f4760:  94 10 00 17  mov  %l7, %o2
a00f4764:  90 10 00 18  mov  %i0, %o0
a00f4768:  7f ff f5 78  call  0xa00f1d48
a00f476c:  92 10 20 47  mov  0x47, %o1
a00f4770:  7f ff fb 6e  call  0xa00f3528
a00f4774:  01 00 00 00  nop
a00f4778:  a2 10 00 08  mov  %o0, %l1
a00f477c:  ab 2c 60 10  sll  %l1, 0x10, %l5
a00f4780:  b9 35 60 10  srl  %l5, 0x10, %i4
a00f4784:  80 a7 00 17  cmp  %i4, %l7
a00f4788:  08 80 01 31  bleu  0xa00f4c4c
a00f478c:  ae 04 80 12  add  %l2, %l2, %l7
a00f4790:  a6 10 20 00  clr  %l3
a00f4794:  40 00 b5 aa  call  0xa0121e3c
a00f4798:  90 10 00 18  mov  %i0, %o0
a00f479c:  90 10 00 18  mov  %i0, %o0
a00f47a0:  92 10 20 36  mov  0x36, %o1
a00f47a4:  7f ff f4 cc  call  0xa00f1ad4
a00f47a8:  94 10 20 41  mov  0x41, %o2
a00f47ac:  67 fe 63 77  call  0x4008d588
a00f47b0:  a4 10 20 00  clr  %l2
a00f47b4:  a1 2a 20 10  sll  %o0, 0x10, %l0
a00f47b8:  40 00 b2 ef  call  0xa0121374
a00f47bc:  90 10 00 18  mov  %i0, %o0
a00f47c0:  82 0a 20 ff  and  %o0, 0xff, %g1
a00f47c4:  92 10 20 36  mov  0x36, %o1
a00f47c8:  80 a0 60 01  cmp  %g1, 1
a00f47cc:  02 80 00 0e  be  0xa00f4804
a00f47d0:  90 10 00 18  mov  %i0, %o0
a00f47d4:  7f ff f4 af  call  0xa00f1a90
a00f47d8:  01 00 00 00  nop
a00f47dc:  80 8a 20 01  btst  1, %o0
a00f47e0:  02 80 01 67  be  0xa00f4d7c
a00f47e4:  91 34 20 10  srl  %l0, 0x10, %o0
a00f47e8:  67 fe 63 6b  call  0x4008d594
a00f47ec:  01 00 00 00  nop
a00f47f0:  95 2a 20 10  sll  %o0, 0x10, %o2
a00f47f4:  93 32 a0 10  srl  %o2, 0x10, %o1
a00f47f8:  80 a2 60 63  cmp  %o1, 0x63
a00f47fc:  08 bf ff ef  bleu  0xa00f47b8
a00f4800:  01 00 00 00  nop
a00f4804:  9a 0c a0 ff  and  %l2, 0xff, %o5
a00f4808:  80 a3 60 00  cmp  %o5, 0
a00f480c:  12 80 00 04  bne  0xa00f481c
a00f4810:  96 10 20 01  mov  1, %o3
a00f4814:  d6 2f 63 ac  stb  %o3, [ %i5 + 0x3ac ]
a00f4818:  80 a3 60 00  cmp  %o5, 0
a00f481c:  02 80 01 88  be  0xa00f4e3c
a00f4820:  92 10 20 40  mov  0x40, %o1
a00f4824:  7f ff f5 30  call  0xa00f1ce4
a00f4828:  90 10 00 18  mov  %i0, %o0
a00f482c:  90 10 00 18  mov  %i0, %o0
a00f4830:  7f ff f4 98  call  0xa00f1a90
a00f4834:  92 10 20 49  mov  0x49, %o1
a00f4838:  98 0a 20 c0  and  %o0, 0xc0, %o4
a00f483c:  83 33 20 06  srl  %o4, 6, %g1
a00f4840:  80 a0 60 00  cmp  %g1, 0
a00f4844:  02 80 01 83  be  0xa00f4e50
a00f4848:  90 0a 20 3f  and  %o0, 0x3f, %o0
a00f484c:  80 a0 60 01  cmp  %g1, 1
a00f4850:  02 80 01 0d  be  0xa00f4c84
a00f4854:  b8 0a 20 ff  and  %o0, 0xff, %i4
a00f4858:  08 80 00 07  bleu  0xa00f4874
a00f485c:  9a 0a 20 ff  and  %o0, 0xff, %o5
a00f4860:  90 24 40 0d  sub  %l1, %o5, %o0
a00f4864:  a3 2a 20 10  sll  %o0, 0x10, %l1
a00f4868:  80 a5 80 11  cmp  %l6, %l1
a00f486c:  18 80 01 0c  bgu  0xa00f4c9c
a00f4870:  a2 10 00 08  mov  %o0, %l1
a00f4874:  40 00 b0 69  call  0xa0120a18
a00f4878:  90 10 00 18  mov  %i0, %o0
a00f487c:  93 2a 20 10  sll  %o0, 0x10, %o1
a00f4880:  99 32 60 10  srl  %o1, 0x10, %o4
a00f4884:  a5 2c 60 10  sll  %l1, 0x10, %l2
a00f4888:  93 34 a0 10  srl  %l2, 0x10, %o1
a00f488c:  17 00 07 d1  sethi  %hi(0x1f4400), %o3
a00f4890:  94 5b 00 09  smul  %o4, %o1, %o2
a00f4894:  82 12 e3 d0  or  %o3, 0x3d0, %g1
a00f4898:  80 a0 40 0a  cmp  %g1, %o2
a00f489c:  2a 80 01 01  bcs,a   0xa00f4ca0
a00f48a0:  93 35 60 10  srl  %l5, 0x10, %o1
a00f48a4:  7f ff fe 85  call  0xa00f42b8
a00f48a8:  90 10 00 18  mov  %i0, %o0
a00f48ac:  a6 04 e0 01  inc  %l3
a00f48b0:  82 0c e0 ff  and  %l3, 0xff, %g1
a00f48b4:  80 a0 60 1f  cmp  %g1, 0x1f
a00f48b8:  08 bf ff b7  bleu  0xa00f4794
a00f48bc:  01 00 00 00  nop
a00f48c0:  80 a0 60 ff  cmp  %g1, 0xff
a00f48c4:  02 80 00 f6  be  0xa00f4c9c
a00f48c8:  82 10 20 01  mov  1, %g1
a00f48cc:  80 a0 60 00  cmp  %g1, 0
a00f48d0:  12 bf ff 16  bne  0xa00f4528
a00f48d4:  c2 0e e3 b1  ldub  [ %i3 + 0x3b1 ], %g1
a00f48d8:  94 0e a0 ff  and  %i2, 0xff, %o2
a00f48dc:  90 10 00 18  mov  %i0, %o0
a00f48e0:  7f ff f6 6e  call  0xa00f2298
a00f48e4:  92 10 20 2a  mov  0x2a, %o1
a00f48e8:  90 10 00 18  mov  %i0, %o0
a00f48ec:  d4 0f bf f7  ldub  [ %fp + -9 ], %o2
a00f48f0:  7f ff f4 79  call  0xa00f1ad4
a00f48f4:  92 10 20 4a  mov  0x4a, %o1
a00f48f8:  23 2a 00 ad  sethi  %hi(0xa802b400), %l1
a00f48fc:  ec 04 63 9c  ld  [ %l1 + 0x39c ], %l6	! 0xa802b79c
a00f4900:  80 a5 a0 00  cmp  %l6, 0
a00f4904:  02 80 01 55  be  0xa00f4e58
a00f4908:  82 10 20 00  clr  %g1
a00f490c:  1b 2a 00 ad  sethi  %hi(0xa802b400), %o5
a00f4910:  f2 0b 63 b1  ldub  [ %o5 + 0x3b1 ], %i1	! 0xa802b7b1
a00f4914:  80 a6 60 63  cmp  %i1, 0x63
a00f4918:  18 bf ff 88  bgu  0xa00f4738
a00f491c:  c2 04 63 9c  ld  [ %l1 + 0x39c ], %g1
a00f4920:  a0 10 00 0d  mov  %o5, %l0
a00f4924:  f6 0c 23 b1  ldub  [ %l0 + 0x3b1 ], %i3
a00f4928:  a6 06 e0 01  add  %i3, 1, %l3
a00f492c:  e6 2c 23 b1  stb  %l3, [ %l0 + 0x3b1 ]
a00f4930:  f4 04 63 9c  ld  [ %l1 + 0x39c ], %i2
a00f4934:  9f c6 80 00  call  %i2
a00f4938:  90 0e e0 ff  and  %i3, 0xff, %o0
a00f493c:  67 fe 62 19  call  0x4008d1a0
a00f4940:  90 10 20 14  mov  0x14, %o0
a00f4944:  40 00 b2 8c  call  0xa0121374
a00f4948:  90 10 00 18  mov  %i0, %o0
a00f494c:  90 0a 20 ff  and  %o0, 0xff, %o0
a00f4950:  80 a2 20 01  cmp  %o0, 1
a00f4954:  02 80 01 0c  be  0xa00f4d84
a00f4958:  e8 0c 23 b1  ldub  [ %l0 + 0x3b1 ], %l4
a00f495c:  80 a5 20 63  cmp  %l4, 0x63
a00f4960:  28 bf ff f2  bleu,a   0xa00f4928
a00f4964:  f6 0c 23 b1  ldub  [ %l0 + 0x3b1 ], %i3
a00f4968:  10 bf ff 74  b  0xa00f4738
a00f496c:  c2 04 63 9c  ld  [ %l1 + 0x39c ], %g1
a00f4970:  7f ff fb 04  call  0xa00f3580
a00f4974:  e8 0c 63 ae  ldub  [ %l1 + 0x3ae ], %l4
a00f4978:  ae 10 00 08  mov  %o0, %l7
a00f497c:  90 10 00 18  mov  %i0, %o0
a00f4980:  92 10 20 36  mov  0x36, %o1
a00f4984:  7f ff f4 54  call  0xa00f1ad4
a00f4988:  94 10 20 42  mov  0x42, %o2
a00f498c:  ac 10 00 14  mov  %l4, %l6
a00f4990:  80 a5 20 01  cmp  %l4, 1
a00f4994:  9e 10 3f ff  mov  -1, %o7
a00f4998:  c0 2f bf ef  clrb  [ %fp + -17 ]
a00f499c:  a8 10 20 00  clr  %l4
a00f49a0:  a6 10 20 00  clr  %l3
a00f49a4:  aa 10 20 00  clr  %l5
a00f49a8:  de 27 bf e4  st  %o7, [ %fp + -28 ]
a00f49ac:  08 80 00 50  bleu  0xa00f4aec
a00f49b0:  a4 10 20 01  mov  1, %l2
a00f49b4:  c2 0e e3 b1  ldub  [ %i3 + 0x3b1 ], %g1
a00f49b8:  90 08 60 ff  and  %g1, 0xff, %o0
a00f49bc:  80 a2 20 63  cmp  %o0, 0x63
a00f49c0:  18 80 00 05  bgu  0xa00f49d4
a00f49c4:  da 07 23 9c  ld  [ %i4 + 0x39c ], %o5
a00f49c8:  80 a3 60 00  cmp  %o5, 0
a00f49cc:  12 80 00 e9  bne  0xa00f4d70
a00f49d0:  94 00 60 01  add  %g1, 1, %o2
a00f49d4:  67 fe 62 ed  call  0x4008d588
a00f49d8:  a2 10 20 00  clr  %l1
a00f49dc:  a1 2a 20 10  sll  %o0, 0x10, %l0
a00f49e0:  40 00 b2 65  call  0xa0121374
a00f49e4:  90 10 00 18  mov  %i0, %o0
a00f49e8:  82 0a 20 ff  and  %o0, 0xff, %g1
a00f49ec:  92 10 20 36  mov  0x36, %o1
a00f49f0:  80 a0 60 01  cmp  %g1, 1
a00f49f4:  02 80 00 a1  be  0xa00f4c78
a00f49f8:  90 10 00 18  mov  %i0, %o0
a00f49fc:  7f ff f4 25  call  0xa00f1a90
a00f4a00:  01 00 00 00  nop
a00f4a04:  80 8a 20 02  btst  2, %o0
a00f4a08:  02 80 00 d8  be  0xa00f4d68
a00f4a0c:  91 34 20 10  srl  %l0, 0x10, %o0
a00f4a10:  67 fe 62 e1  call  0x4008d594
a00f4a14:  01 00 00 00  nop
a00f4a18:  9b 2a 20 10  sll  %o0, 0x10, %o5
a00f4a1c:  91 33 60 10  srl  %o5, 0x10, %o0
a00f4a20:  80 a2 20 63  cmp  %o0, 0x63
a00f4a24:  08 bf ff ef  bleu  0xa00f49e0
a00f4a28:  01 00 00 00  nop
a00f4a2c:  80 8c 60 ff  btst  0xff, %l1
a00f4a30:  02 80 00 91  be  0xa00f4c74
a00f4a34:  96 05 c0 12  add  %l7, %l2, %o3
a00f4a38:  a2 0a e0 3f  and  %o3, 0x3f, %l1
a00f4a3c:  7f ff fb 65  call  0xa00f37d0
a00f4a40:  90 10 00 11  mov  %l1, %o0
a00f4a44:  94 10 20 42  mov  0x42, %o2
a00f4a48:  90 10 00 18  mov  %i0, %o0
a00f4a4c:  7f ff f4 22  call  0xa00f1ad4
a00f4a50:  92 10 20 36  mov  0x36, %o1
a00f4a54:  92 10 20 45  mov  0x45, %o1
a00f4a58:  7f ff f4 a3  call  0xa00f1ce4
a00f4a5c:  90 10 00 18  mov  %i0, %o0
a00f4a60:  a1 2a 20 10  sll  %o0, 0x10, %l0
a00f4a64:  92 10 20 43  mov  0x43, %o1
a00f4a68:  7f ff f4 9f  call  0xa00f1ce4
a00f4a6c:  90 10 00 18  mov  %i0, %o0
a00f4a70:  92 10 00 13  mov  %l3, %o1
a00f4a74:  91 2a 20 10  sll  %o0, 0x10, %o0
a00f4a78:  a7 32 20 10  srl  %o0, 0x10, %l3
a00f4a7c:  9a 04 00 13  add  %l0, %l3, %o5
a00f4a80:  a6 10 00 14  mov  %l4, %l3
a00f4a84:  9f 33 60 02  srl  %o5, 2, %o7
a00f4a88:  95 34 e0 01  srl  %l3, 1, %o2
a00f4a8c:  a8 10 00 0d  mov  %o5, %l4
a00f4a90:  a0 03 c0 0a  add  %o7, %o2, %l0
a00f4a94:  96 04 7f ff  add  %l1, -1, %o3
a00f4a98:  99 32 60 02  srl  %o1, 2, %o4
a00f4a9c:  82 0c a0 ff  and  %l2, 0xff, %g1
a00f4aa0:  9a 04 00 0c  add  %l0, %o4, %o5
a00f4aa4:  80 a0 60 03  cmp  %g1, 3
a00f4aa8:  08 80 00 0c  bleu  0xa00f4ad8
a00f4aac:  a2 0a e0 3f  and  %o3, 0x3f, %l1
a00f4ab0:  80 a3 40 15  cmp  %o5, %l5
a00f4ab4:  18 80 00 03  bgu  0xa00f4ac0
a00f4ab8:  82 23 40 15  sub  %o5, %l5, %g1
a00f4abc:  82 25 40 0d  sub  %l5, %o5, %g1
a00f4ac0:  ea 07 bf e4  ld  [ %fp + -28 ], %l5
a00f4ac4:  80 a0 40 15  cmp  %g1, %l5
a00f4ac8:  3a 80 00 05  bcc,a   0xa00f4adc
a00f4acc:  a4 04 a0 01  inc  %l2
a00f4ad0:  e2 2f bf ef  stb  %l1, [ %fp + -17 ]
a00f4ad4:  c2 27 bf e4  st  %g1, [ %fp + -28 ]
a00f4ad8:  a4 04 a0 01  inc  %l2
a00f4adc:  82 0c a0 ff  and  %l2, 0xff, %g1
a00f4ae0:  80 a0 40 16  cmp  %g1, %l6
a00f4ae4:  0a bf ff b4  bcs  0xa00f49b4
a00f4ae8:  aa 10 00 0d  mov  %o5, %l5
a00f4aec:  e4 0f bf ef  ldub  [ %fp + -17 ], %l2
a00f4af0:  ac 04 bf ff  add  %l2, -1, %l6
a00f4af4:  7f ff fb 37  call  0xa00f37d0
a00f4af8:  90 0d a0 3f  and  %l6, 0x3f, %o0
a00f4afc:  82 10 20 01  mov  1, %g1
a00f4b00:  80 a0 60 00  cmp  %g1, 0
a00f4b04:  12 80 00 6d  bne  0xa00f4cb8
a00f4b08:  92 10 00 19  mov  %i1, %o1
a00f4b0c:  94 0e a0 ff  and  %i2, 0xff, %o2
a00f4b10:  90 10 00 18  mov  %i0, %o0
a00f4b14:  7f ff f5 e1  call  0xa00f2298
a00f4b18:  92 10 20 2a  mov  0x2a, %o1
a00f4b1c:  90 10 00 18  mov  %i0, %o0
a00f4b20:  d4 0f bf f7  ldub  [ %fp + -9 ], %o2
a00f4b24:  7f ff f3 ec  call  0xa00f1ad4
a00f4b28:  92 10 20 4a  mov  0x4a, %o1
a00f4b2c:  ee 07 23 9c  ld  [ %i4 + 0x39c ], %l7
a00f4b30:  80 a5 e0 00  cmp  %l7, 0
a00f4b34:  02 80 00 c9  be  0xa00f4e58
a00f4b38:  82 10 20 00  clr  %g1
a00f4b3c:  1b 2a 00 ad  sethi  %hi(0xa802b400), %o5
a00f4b40:  f2 0b 63 b1  ldub  [ %o5 + 0x3b1 ], %i1	! 0xa802b7b1
a00f4b44:  80 a6 60 63  cmp  %i1, 0x63
a00f4b48:  18 bf fe fc  bgu  0xa00f4738
a00f4b4c:  c2 07 23 9c  ld  [ %i4 + 0x39c ], %g1
a00f4b50:  a0 10 00 0d  mov  %o5, %l0
a00f4b54:  f6 0c 23 b1  ldub  [ %l0 + 0x3b1 ], %i3
a00f4b58:  a8 06 e0 01  add  %i3, 1, %l4
a00f4b5c:  e8 2c 23 b1  stb  %l4, [ %l0 + 0x3b1 ]
a00f4b60:  f4 07 23 9c  ld  [ %i4 + 0x39c ], %i2
a00f4b64:  9f c6 80 00  call  %i2
a00f4b68:  90 0e e0 ff  and  %i3, 0xff, %o0
a00f4b6c:  67 fe 61 8d  call  0x4008d1a0
a00f4b70:  90 10 20 14  mov  0x14, %o0
a00f4b74:  40 00 b2 00  call  0xa0121374
a00f4b78:  90 10 00 18  mov  %i0, %o0
a00f4b7c:  90 0a 20 ff  and  %o0, 0xff, %o0
a00f4b80:  80 a2 20 01  cmp  %o0, 1
a00f4b84:  02 80 00 80  be  0xa00f4d84
a00f4b88:  d8 0c 23 b1  ldub  [ %l0 + 0x3b1 ], %o4
a00f4b8c:  80 a3 20 63  cmp  %o4, 0x63
a00f4b90:  28 bf ff f2  bleu,a   0xa00f4b58
a00f4b94:  f6 0c 23 b1  ldub  [ %l0 + 0x3b1 ], %i3
a00f4b98:  10 bf fe e8  b  0xa00f4738
a00f4b9c:  c2 07 23 9c  ld  [ %i4 + 0x39c ], %g1
a00f4ba0:  94 0e a0 ff  and  %i2, 0xff, %o2
a00f4ba4:  90 10 00 18  mov  %i0, %o0
a00f4ba8:  7f ff f5 bc  call  0xa00f2298
a00f4bac:  92 10 20 2a  mov  0x2a, %o1
a00f4bb0:  90 10 00 18  mov  %i0, %o0
a00f4bb4:  d4 0f bf f7  ldub  [ %fp + -9 ], %o2
a00f4bb8:  7f ff f3 c7  call  0xa00f1ad4
a00f4bbc:  92 10 20 4a  mov  0x4a, %o1
a00f4bc0:  23 2a 00 ad  sethi  %hi(0xa802b400), %l1
a00f4bc4:  d6 04 63 9c  ld  [ %l1 + 0x39c ], %o3	! 0xa802b79c
a00f4bc8:  80 a2 e0 00  cmp  %o3, 0
a00f4bcc:  02 80 00 a3  be  0xa00f4e58
a00f4bd0:  82 10 20 00  clr  %g1
a00f4bd4:  1b 2a 00 ad  sethi  %hi(0xa802b400), %o5
a00f4bd8:  d8 0b 63 b1  ldub  [ %o5 + 0x3b1 ], %o4	! 0xa802b7b1
a00f4bdc:  80 a3 20 63  cmp  %o4, 0x63
a00f4be0:  18 bf fe d6  bgu  0xa00f4738
a00f4be4:  c2 04 63 9c  ld  [ %l1 + 0x39c ], %g1
a00f4be8:  a0 10 00 0d  mov  %o5, %l0
a00f4bec:  de 0c 23 b1  ldub  [ %l0 + 0x3b1 ], %o7
a00f4bf0:  a6 03 e0 01  add  %o7, 1, %l3
a00f4bf4:  90 0b e0 ff  and  %o7, 0xff, %o0
a00f4bf8:  e6 2c 23 b1  stb  %l3, [ %l0 + 0x3b1 ]
a00f4bfc:  e4 04 63 9c  ld  [ %l1 + 0x39c ], %l2
a00f4c00:  9f c4 80 00  call  %l2
a00f4c04:  01 00 00 00  nop
a00f4c08:  67 fe 61 66  call  0x4008d1a0
a00f4c0c:  90 10 20 14  mov  0x14, %o0	! 0x14
a00f4c10:  40 00 b1 d9  call  0xa0121374
a00f4c14:  90 10 00 18  mov  %i0, %o0
a00f4c18:  90 0a 20 ff  and  %o0, 0xff, %o0
a00f4c1c:  80 a2 20 01  cmp  %o0, 1
a00f4c20:  02 80 00 59  be  0xa00f4d84
a00f4c24:  e8 0c 23 b1  ldub  [ %l0 + 0x3b1 ], %l4
a00f4c28:  80 a5 20 63  cmp  %l4, 0x63
a00f4c2c:  08 bf ff f1  bleu  0xa00f4bf0
a00f4c30:  de 0c 23 b1  ldub  [ %l0 + 0x3b1 ], %o7
a00f4c34:  10 bf fe c1  b  0xa00f4738
a00f4c38:  c2 04 63 9c  ld  [ %l1 + 0x39c ], %g1
a00f4c3c:  92 10 20 4a  mov  0x4a, %o1
a00f4c40:  94 10 20 80  mov  0x80, %o2
a00f4c44:  10 bf fe 2a  b  0xa00f44ec
a00f4c48:  96 10 20 01  mov  1, %o3
a00f4c4c:  9a 04 a0 10  add  %l2, 0x10, %o5
a00f4c50:  91 2b 60 10  sll  %o5, 0x10, %o0
a00f4c54:  93 32 20 10  srl  %o0, 0x10, %o1
a00f4c58:  a2 10 00 0d  mov  %o5, %l1
a00f4c5c:  7f ff fd 97  call  0xa00f42b8
a00f4c60:  90 10 00 18  mov  %i0, %o0
a00f4c64:  10 bf fe cc  b  0xa00f4794
a00f4c68:  a6 10 20 00  clr  %l3
a00f4c6c:  10 bf fe 8c  b  0xa00f469c
a00f4c70:  82 10 20 00  clr  %g1
a00f4c74:  82 10 20 01  mov  1, %g1
a00f4c78:  c2 2f 63 ac  stb  %g1, [ %i5 + 0x3ac ]
a00f4c7c:  10 bf ff a1  b  0xa00f4b00
a00f4c80:  82 10 20 00  clr  %g1
a00f4c84:  a4 04 40 1c  add  %l1, %i4, %l2
a00f4c88:  9f 2c a0 10  sll  %l2, 0x10, %o7
a00f4c8c:  a1 2d e0 10  sll  %l7, 0x10, %l0
a00f4c90:  80 a4 00 0f  cmp  %l0, %o7
a00f4c94:  1a bf fe f8  bcc  0xa00f4874
a00f4c98:  a2 10 00 12  mov  %l2, %l1
a00f4c9c:  93 35 60 10  srl  %l5, 0x10, %o1
a00f4ca0:  7f ff fd 86  call  0xa00f42b8
a00f4ca4:  90 10 00 18  mov  %i0, %o0
a00f4ca8:  aa 10 20 01  mov  1, %l5
a00f4cac:  ea 2d 23 ad  stb  %l5, [ %l4 + 0x3ad ]
a00f4cb0:  10 bf ff 07  b  0xa00f48cc
a00f4cb4:  82 10 20 00  clr  %g1
a00f4cb8:  7f ff fb d8  call  0xa00f3c18
a00f4cbc:  90 10 00 18  mov  %i0, %o0
a00f4cc0:  80 8a 20 ff  btst  0xff, %o0
a00f4cc4:  02 80 00 36  be  0xa00f4d9c
a00f4cc8:  e0 07 23 9c  ld  [ %i4 + 0x39c ], %l0
a00f4ccc:  80 a4 20 00  cmp  %l0, 0
a00f4cd0:  02 80 00 1d  be  0xa00f4d44
a00f4cd4:  94 0e a0 ff  and  %i2, 0xff, %o2
a00f4cd8:  1b 2a 00 ad  sethi  %hi(0xa802b400), %o5
a00f4cdc:  d0 0b 63 b1  ldub  [ %o5 + 0x3b1 ], %o0	! 0xa802b7b1
a00f4ce0:  80 a2 20 63  cmp  %o0, 0x63
a00f4ce4:  38 80 00 15  bgu,a   0xa00f4d38
a00f4ce8:  fa 07 23 9c  ld  [ %i4 + 0x39c ], %i5
a00f4cec:  a0 10 00 0d  mov  %o5, %l0
a00f4cf0:  ea 0c 23 b1  ldub  [ %l0 + 0x3b1 ], %l5
a00f4cf4:  82 05 60 01  add  %l5, 1, %g1
a00f4cf8:  c2 2c 23 b1  stb  %g1, [ %l0 + 0x3b1 ]
a00f4cfc:  d6 07 23 9c  ld  [ %i4 + 0x39c ], %o3
a00f4d00:  9f c2 c0 00  call  %o3
a00f4d04:  90 0d 60 ff  and  %l5, 0xff, %o0
a00f4d08:  67 fe 61 26  call  0x4008d1a0
a00f4d0c:  90 10 20 14  mov  0x14, %o0
a00f4d10:  40 00 b1 99  call  0xa0121374
a00f4d14:  90 10 00 18  mov  %i0, %o0
a00f4d18:  90 0a 20 ff  and  %o0, 0xff, %o0
a00f4d1c:  80 a2 20 01  cmp  %o0, 1
a00f4d20:  02 80 00 45  be  0xa00f4e34
a00f4d24:  ec 0c 23 b1  ldub  [ %l0 + 0x3b1 ], %l6
a00f4d28:  80 a5 a0 63  cmp  %l6, 0x63
a00f4d2c:  28 bf ff f2  bleu,a   0xa00f4cf4
a00f4d30:  ea 0c 23 b1  ldub  [ %l0 + 0x3b1 ], %l5
a00f4d34:  fa 07 23 9c  ld  [ %i4 + 0x39c ], %i5
a00f4d38:  9f c7 40 00  call  %i5
a00f4d3c:  90 10 20 64  mov  0x64, %o0
a00f4d40:  94 0e a0 ff  and  %i2, 0xff, %o2
a00f4d44:  90 10 00 18  mov  %i0, %o0
a00f4d48:  7f ff f5 54  call  0xa00f2298
a00f4d4c:  92 10 20 2a  mov  0x2a, %o1
a00f4d50:  90 10 00 18  mov  %i0, %o0
a00f4d54:  d4 0f bf f7  ldub  [ %fp + -9 ], %o2
a00f4d58:  7f ff f3 5f  call  0xa00f1ad4
a00f4d5c:  92 10 20 4a  mov  0x4a, %o1
a00f4d60:  10 80 00 3e  b  0xa00f4e58
a00f4d64:  82 10 20 01  mov  1, %g1
a00f4d68:  10 bf ff 31  b  0xa00f4a2c
a00f4d6c:  a2 10 20 01  mov  1, %l1
a00f4d70:  9f c3 40 00  call  %o5
a00f4d74:  d4 2e e3 b1  stb  %o2, [ %i3 + 0x3b1 ]
a00f4d78:  30 bf ff 17  b,a   0xa00f49d4
a00f4d7c:  10 bf fe a2  b  0xa00f4804
a00f4d80:  a4 10 20 01  mov  1, %l2
a00f4d84:  d0 2f 63 ac  stb  %o0, [ %i5 + 0x3ac ]
a00f4d88:  10 80 00 34  b  0xa00f4e58
a00f4d8c:  82 10 20 00  clr  %g1
a00f4d90:  9f c3 40 00  call  %o5
a00f4d94:  ee 2e e3 b1  stb  %l7, [ %i3 + 0x3b1 ]
a00f4d98:  30 bf fd ec  b,a   0xa00f4548
a00f4d9c:  94 0e a0 ff  and  %i2, 0xff, %o2
a00f4da0:  90 10 00 18  mov  %i0, %o0
a00f4da4:  7f ff f5 3d  call  0xa00f2298
a00f4da8:  92 10 20 2a  mov  0x2a, %o1
a00f4dac:  92 10 20 4a  mov  0x4a, %o1
a00f4db0:  90 10 00 18  mov  %i0, %o0
a00f4db4:  7f ff f3 48  call  0xa00f1ad4
a00f4db8:  d4 0f bf f7  ldub  [ %fp + -9 ], %o2
a00f4dbc:  d2 07 23 9c  ld  [ %i4 + 0x39c ], %o1
a00f4dc0:  80 a2 60 00  cmp  %o1, 0
a00f4dc4:  02 80 00 25  be  0xa00f4e58
a00f4dc8:  82 10 20 00  clr  %g1
a00f4dcc:  1b 2a 00 ad  sethi  %hi(0xa802b400), %o5
a00f4dd0:  e2 0b 63 b1  ldub  [ %o5 + 0x3b1 ], %l1	! 0xa802b7b1
a00f4dd4:  80 a4 60 63  cmp  %l1, 0x63
a00f4dd8:  18 bf fe 58  bgu  0xa00f4738
a00f4ddc:  c2 07 23 9c  ld  [ %i4 + 0x39c ], %g1
a00f4de0:  a0 10 00 0d  mov  %o5, %l0
a00f4de4:  de 0c 23 b1  ldub  [ %l0 + 0x3b1 ], %o7
a00f4de8:  9a 03 e0 01  add  %o7, 1, %o5
a00f4dec:  90 0b e0 ff  and  %o7, 0xff, %o0
a00f4df0:  da 2c 23 b1  stb  %o5, [ %l0 + 0x3b1 ]
a00f4df4:  d4 07 23 9c  ld  [ %i4 + 0x39c ], %o2
a00f4df8:  9f c2 80 00  call  %o2
a00f4dfc:  01 00 00 00  nop
a00f4e00:  67 fe 60 e8  call  0x4008d1a0
a00f4e04:  90 10 20 14  mov  0x14, %o0	! 0x14
a00f4e08:  40 00 b1 5b  call  0xa0121374
a00f4e0c:  90 10 00 18  mov  %i0, %o0
a00f4e10:  90 0a 20 ff  and  %o0, 0xff, %o0
a00f4e14:  80 a2 20 01  cmp  %o0, 1
a00f4e18:  02 bf ff db  be  0xa00f4d84
a00f4e1c:  e6 0c 23 b1  ldub  [ %l0 + 0x3b1 ], %l3
a00f4e20:  80 a4 e0 63  cmp  %l3, 0x63
a00f4e24:  08 bf ff f1  bleu  0xa00f4de8
a00f4e28:  de 0c 23 b1  ldub  [ %l0 + 0x3b1 ], %o7
a00f4e2c:  10 bf fe 43  b  0xa00f4738
a00f4e30:  c2 07 23 9c  ld  [ %i4 + 0x39c ], %g1
a00f4e34:  10 bf ff c3  b  0xa00f4d40
a00f4e38:  d0 2f 63 ac  stb  %o0, [ %i5 + 0x3ac ]
a00f4e3c:  93 35 60 10  srl  %l5, 0x10, %o1
a00f4e40:  7f ff fd 1e  call  0xa00f42b8
a00f4e44:  90 10 00 18  mov  %i0, %o0
a00f4e48:  10 bf fe a1  b  0xa00f48cc
a00f4e4c:  82 10 20 00  clr  %g1
a00f4e50:  10 bf fe 9c  b  0xa00f48c0
a00f4e54:  82 0c e0 ff  and  %l3, 0xff, %g1
a00f4e58:  81 c7 e0 08  ret
a00f4e5c:  91 e8 00 01  restore  %g0, %g1, %o0
