# leon2s FUN_a00a4658 0xa00a4658-0xa00a47b0 (344 bytes)
a00a4658:  9d e3 bf 98  save  %sp, -104, %sp
a00a465c:  a2 10 20 00  clr  %l1
a00a4660:  a0 0c 60 ff  and  %l1, 0xff, %l0
a00a4664:  90 10 00 10  mov  %l0, %o0
a00a4668:  92 10 20 00  clr  %o1
a00a466c:  40 00 0e 5b  call  0xa00a7fd8
a00a4670:  94 10 20 09  mov  9, %o2
a00a4674:  80 8a 20 02  btst  2, %o0
a00a4678:  02 80 00 06  be  0xa00a4690
a00a467c:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a00a4680:  9a 10 62 10  or  %g1, 0x210, %o5	! 0xa8079210
a00a4684:  82 10 20 01  mov  1, %g1
a00a4688:  10 80 00 04  b  0xa00a4698
a00a468c:  c2 2b 40 10  stb  %g1, [ %o5 + %l0 ]
a00a4690:  82 10 62 10  or  %g1, 0x210, %g1
a00a4694:  c0 28 40 10  clrb  [ %g1 + %l0 ]
a00a4698:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a00a469c:  82 10 62 10  or  %g1, 0x210, %g1	! 0xa8079210
a00a46a0:  c2 08 40 10  ldub  [ %g1 + %l0 ], %g1
a00a46a4:  80 a0 60 00  cmp  %g1, 0
a00a46a8:  02 80 00 16  be  0xa00a4700
a00a46ac:  03 2a 01 f6  sethi  %hi(0xa807d800), %g1
a00a46b0:  7f ff b4 d8  call  0xa0091a10
a00a46b4:  90 10 00 10  mov  %l0, %o0
a00a46b8:  80 8a 20 ff  btst  0xff, %o0
a00a46bc:  02 80 00 0b  be  0xa00a46e8
a00a46c0:  83 2c 20 03  sll  %l0, 3, %g1
a00a46c4:  82 20 40 10  sub  %g1, %l0, %g1
a00a46c8:  1b 2a 01 f5  sethi  %hi(0xa807d400), %o5
a00a46cc:  83 28 60 02  sll  %g1, 2, %g1
a00a46d0:  9a 13 61 80  or  %o5, 0x180, %o5
a00a46d4:  82 00 40 0d  add  %g1, %o5, %g1
a00a46d8:  c2 00 60 14  ld  [ %g1 + 0x14 ], %g1
a00a46dc:  80 88 68 00  btst  0x800, %g1
a00a46e0:  12 80 00 0c  bne  0xa00a4710
a00a46e4:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a00a46e8:  7f ff b5 31  call  0xa0091bac
a00a46ec:  90 10 00 10  mov  %l0, %o0
a00a46f0:  80 8a 20 ff  btst  0xff, %o0
a00a46f4:  12 80 00 07  bne  0xa00a4710
a00a46f8:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a00a46fc:  03 2a 01 f6  sethi  %hi(0xa807d800), %g1
a00a4700:  9b 2c 20 02  sll  %l0, 2, %o5
a00a4704:  82 10 63 6c  or  %g1, 0x36c, %g1
a00a4708:  10 80 00 1d  b  0xa00a477c
a00a470c:  c0 20 40 0d  clr  [ %g1 + %o5 ]
a00a4710:  96 10 62 08  or  %g1, 0x208, %o3
a00a4714:  c2 0a c0 10  ldub  [ %o3 + %l0 ], %g1
a00a4718:  80 a0 60 00  cmp  %g1, 0
a00a471c:  02 80 00 0c  be  0xa00a474c
a00a4720:  03 2a 01 f6  sethi  %hi(0xa807d800), %g1
a00a4724:  98 10 63 6c  or  %g1, 0x36c, %o4	! 0xa807db6c
a00a4728:  9b 2c 20 02  sll  %l0, 2, %o5
a00a472c:  c2 03 00 0d  ld  [ %o4 + %o5 ], %g1
a00a4730:  80 a0 60 01  cmp  %g1, 1
a00a4734:  08 80 00 06  bleu  0xa00a474c
a00a4738:  03 2a 01 f6  sethi  %hi(0xa807d800), %g1
a00a473c:  82 10 20 02  mov  2, %g1
a00a4740:  c2 23 00 0d  st  %g1, [ %o4 + %o5 ]
a00a4744:  c0 2a c0 10  clrb  [ %o3 + %l0 ]
a00a4748:  03 2a 01 f6  sethi  %hi(0xa807d800), %g1
a00a474c:  82 10 63 6c  or  %g1, 0x36c, %g1	! 0xa807db6c
a00a4750:  9b 2c 20 02  sll  %l0, 2, %o5
a00a4754:  da 00 40 0d  ld  [ %g1 + %o5 ], %o5
a00a4758:  03 28 02 d3  sethi  %hi(0xa00b4c00), %g1
a00a475c:  9b 2b 60 02  sll  %o5, 2, %o5
a00a4760:  82 10 60 f8  or  %g1, 0xf8, %g1
a00a4764:  c2 00 40 0d  ld  [ %g1 + %o5 ], %g1
a00a4768:  9f c0 40 00  call  %g1
a00a476c:  90 10 00 10  mov  %l0, %o0
a00a4770:  80 8a 20 ff  btst  0xff, %o0
a00a4774:  12 bf ff f6  bne  0xa00a474c
a00a4778:  03 2a 01 f6  sethi  %hi(0xa807d800), %g1
a00a477c:  11 2a 01 e4  sethi  %hi(0xa8079000), %o0
a00a4780:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a00a4784:  c2 00 63 44  ld  [ %g1 + 0x344 ], %g1	! 0xa8078744
a00a4788:  90 12 22 18  or  %o0, 0x218, %o0
a00a478c:  40 00 36 82  call  0xa00b2194
a00a4790:  c2 22 20 04  st  %g1, [ %o0 + 4 ]
a00a4794:  a2 04 60 01  inc  %l1
a00a4798:  82 0c 60 ff  and  %l1, 0xff, %g1
a00a479c:  80 a0 60 01  cmp  %g1, 1
a00a47a0:  08 bf ff b1  bleu  0xa00a4664
a00a47a4:  a0 0c 60 ff  and  %l1, 0xff, %l0
a00a47a8:  81 c7 e0 08  ret
a00a47ac:  81 e8 00 00  restore
