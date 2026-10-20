# leon2m FUN_a008454c 0xa008454c-0xa0085984 (384 bytes)
a008454c:  9d e3 bf 98  save  %sp, -104, %sp
a0084550:  82 0e 20 c0  and  %i0, 0xc0, %g1
a0084554:  80 a0 60 40  cmp  %g1, 0x40
a0084558:  02 80 00 1d  be  0xa00845cc
a008455c:  80 a0 60 80  cmp  %g1, 0x80
a0084560:  02 80 00 34  be  0xa0084630
a0084564:  80 a0 60 c0  cmp  %g1, 0xc0
a0084568:  02 80 00 44  be  0xa0084678
a008456c:  80 a0 60 00  cmp  %g1, 0
a0084570:  12 80 05 03  bne  0xa008597c
a0084574:  23 00 03 fb  sethi  %hi(0xfec00), %l1
a0084578:  9e 0e 20 3f  and  %i0, 0x3f, %o7
a008457c:  a0 14 60 40  or  %l1, 0x40, %l0
a0084580:  f0 0c 00 0f  ldub  [ %l0 + %o7 ], %i0
a0084584:  80 a6 20 30  cmp  %i0, 0x30
a0084588:  02 80 04 fd  be  0xa008597c
a008458c:  35 00 03 fb  sethi  %hi(0xfec00), %i2
a0084590:  b2 16 a0 08  or  %i2, 8, %i1	! 0xfec08
a0084594:  e0 0e 40 18  ldub  [ %i1 + %i0 ], %l0
a0084598:  40 01 64 1f  call  0xa00dd614
a008459c:  90 10 20 80  mov  0x80, %o0
a00845a0:  80 8a 20 ff  btst  0xff, %o0
a00845a4:  12 80 03 e1  bne  0xa0085528
a00845a8:  1b 00 03 fb  sethi  %hi(0xfec00), %o5
a00845ac:  80 a4 20 3e  cmp  %l0, 0x3e
a00845b0:  18 80 04 f3  bgu  0xa008597c
a00845b4:  31 00 00 80  sethi  %hi(0x20000), %i0
a00845b8:  83 2c 20 02  sll  %l0, 2, %g1
a00845bc:  92 16 22 04  or  %i0, 0x204, %o1
a00845c0:  d0 02 40 01  ld  [ %o1 + %g1 ], %o0
a00845c4:  81 c2 00 00  jmp  %o0
a00845c8:  01 00 00 00  nop
a00845cc:  11 00 03 fb  sethi  %hi(0xfec00), %o0
a00845d0:  9a 0e 20 3f  and  %i0, 0x3f, %o5
a00845d4:  82 12 20 e0  or  %o0, 0xe0, %g1
a00845d8:  f0 08 40 0d  ldub  [ %g1 + %o5 ], %i0
a00845dc:  80 a6 20 0a  cmp  %i0, 0xa
a00845e0:  02 80 04 e7  be  0xa008597c
a00845e4:  17 00 03 fb  sethi  %hi(0xfec00), %o3
a00845e8:  93 2e 20 02  sll  %i0, 2, %o1
a00845ec:  94 12 e0 b0  or  %o3, 0xb0, %o2
a00845f0:  e0 02 80 09  ld  [ %o2 + %o1 ], %l0
a00845f4:  40 01 64 08  call  0xa00dd614
a00845f8:  90 10 20 80  mov  0x80, %o0
a00845fc:  80 8a 20 ff  btst  0xff, %o0
a0084600:  02 bf ff ec  be  0xa00845b0
a0084604:  80 a4 20 3e  cmp  %l0, 0x3e
a0084608:  19 00 03 fb  sethi  %hi(0xfec00), %o4
a008460c:  90 13 23 f8  or  %o4, 0x3f8, %o0	! 0xfeff8
a0084610:  92 10 00 18  mov  %i0, %o1
a0084614:  40 01 6a d7  call  0xa00df170
a0084618:  94 10 00 10  mov  %l0, %o2
a008461c:  80 a4 20 3e  cmp  %l0, 0x3e
a0084620:  18 80 04 d7  bgu  0xa008597c
a0084624:  31 00 00 80  sethi  %hi(0x20000), %i0
a0084628:  10 bf ff e5  b  0xa00845bc
a008462c:  83 2c 20 02  sll  %l0, 2, %g1
a0084630:  23 00 03 fb  sethi  %hi(0xfec00), %l1
a0084634:  9e 0e 20 3f  and  %i0, 0x3f, %o7
a0084638:  a0 14 60 a8  or  %l1, 0xa8, %l0
a008463c:  f0 0c 00 0f  ldub  [ %l0 + %o7 ], %i0
a0084640:  80 a6 20 04  cmp  %i0, 4
a0084644:  02 80 04 ce  be  0xa008597c
a0084648:  1b 00 03 fb  sethi  %hi(0xfec00), %o5
a008464c:  b4 13 60 90  or  %o5, 0x90, %i2	! 0xfec90
a0084650:  b3 2e 20 02  sll  %i0, 2, %i1
a0084654:  e0 06 80 19  ld  [ %i2 + %i1 ], %l0
a0084658:  40 01 63 ef  call  0xa00dd614
a008465c:  90 10 20 80  mov  0x80, %o0
a0084660:  80 8a 20 ff  btst  0xff, %o0
a0084664:  02 bf ff d3  be  0xa00845b0
a0084668:  80 a4 20 3e  cmp  %l0, 0x3e
a008466c:  03 00 03 fc  sethi  %hi(0xff000), %g1
a0084670:  10 bf ff e8  b  0xa0084610
a0084674:  90 10 60 28  or  %g1, 0x28, %o0	! 0xff028
a0084678:  90 0e 20 3f  and  %i0, 0x3f, %o0
a008467c:  31 00 03 fb  sethi  %hi(0xfec00), %i0
a0084680:  92 16 20 88  or  %i0, 0x88, %o1	! 0xfec88
a0084684:  f0 0a 40 08  ldub  [ %o1 + %o0 ], %i0
a0084688:  80 a6 20 07  cmp  %i0, 7
a008468c:  02 80 04 bc  be  0xa008597c
a0084690:  17 00 03 fb  sethi  %hi(0xfec00), %o3
a0084694:  94 12 e0 80  or  %o3, 0x80, %o2	! 0xfec80
a0084698:  e0 0a 80 18  ldub  [ %o2 + %i0 ], %l0
a008469c:  40 01 63 de  call  0xa00dd614
a00846a0:  90 10 20 80  mov  0x80, %o0
a00846a4:  80 8a 20 ff  btst  0xff, %o0
a00846a8:  02 bf ff c2  be  0xa00845b0
a00846ac:  80 a4 20 3e  cmp  %l0, 0x3e
a00846b0:  19 00 03 fc  sethi  %hi(0xff000), %o4
a00846b4:  10 bf ff d7  b  0xa0084610
a00846b8:  90 13 20 58  or  %o4, 0x58, %o0	! 0xff058
a00846bc:  19 00 03 fc  sethi  %hi(0xff000), %o4
a00846c0:  40 01 6a ac  call  0xa00df170
a00846c4:  90 13 20 90  or  %o4, 0x90, %o0	! 0xff090
a00846c8:  19 2a 00 b3  sethi  %hi(0xa802cc00), %o4
a00846cc:  9a 13 23 f4  or  %o4, 0x3f4, %o5	! 0xa802cff4
a00846d0:  e0 0b 60 1c  ldub  [ %o5 + 0x1c ], %l0
a00846d4:  80 8c 20 01  btst  1, %l0
a00846d8:  32 80 00 14  bne,a   0xa0084728
a00846dc:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a00846e0:  c2 13 60 06  lduh  [ %o5 + 6 ], %g1
a00846e4:  80 88 60 40  btst  0x40, %g1
a00846e8:  12 80 04 28  bne  0xa0085788
a00846ec:  a2 13 23 f4  or  %o4, 0x3f4, %l1
a00846f0:  da 0c 60 1c  ldub  [ %l1 + 0x1c ], %o5
a00846f4:  80 8b 60 01  btst  1, %o5
a00846f8:  12 80 03 95  bne  0xa008554c
a00846fc:  11 00 04 00  sethi  %hi(0x100000), %o0
a0084700:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a0084704:  98 14 22 90  or  %l0, 0x290, %o4	! 0xa802d290
a0084708:  c2 03 20 ac  ld  [ %o4 + 0xac ], %g1
a008470c:  80 88 40 08  btst  %g1, %o0
a0084710:  02 80 00 11  be  0xa0084754
a0084714:  13 2a 00 b8  sethi  %hi(0xa802e000), %o1
a0084718:  d2 0b 20 1f  ldub  [ %o4 + 0x1f ], %o1
a008471c:  80 a2 60 00  cmp  %o1, 0
a0084720:  02 80 04 69  be  0xa00858c4
a0084724:  01 00 00 00  nop
a0084728:  b4 14 22 90  or  %l0, 0x290, %i2
a008472c:  f2 06 a0 ac  ld  [ %i2 + 0xac ], %i1
a0084730:  21 00 04 00  sethi  %hi(0x100000), %l0
a0084734:  80 8e 40 10  btst  %i1, %l0
a0084738:  02 80 00 07  be  0xa0084754
a008473c:  13 2a 00 b8  sethi  %hi(0xa802e000), %o1
a0084740:  90 10 20 00  clr  %o0
a0084744:  92 10 20 01  mov  1, %o1
a0084748:  40 03 18 63  call  0xa014a8d4
a008474c:  94 10 23 e8  mov  0x3e8, %o2
a0084750:  13 2a 00 b8  sethi  %hi(0xa802e000), %o1
a0084754:  c2 0a 61 a7  ldub  [ %o1 + 0x1a7 ], %g1	! 0xa802e1a7
a0084758:  80 a0 00 01  cmp  %g0, %g1
a008475c:  a2 60 3f ff  subx  %g0, -1, %l1
a0084760:  90 18 60 02  xor  %g1, 2, %o0
a0084764:  80 a0 00 08  cmp  %g0, %o0
a0084768:  9a 60 3f ff  subx  %g0, -1, %o5
a008476c:  80 94 40 0d  orcc  %l1, %o5, %g0
a0084770:  02 80 00 04  be  0xa0084780
a0084774:  01 00 00 00  nop
a0084778:  40 02 80 a4  call  0xa0124a08
a008477c:  01 00 00 00  nop
a0084780:  7f ff f0 7e  call  0xa0080978
a0084784:  81 e8 00 00  restore
a0084788:  7f ff f5 c8  call  0xa0081ea8
a008478c:  90 10 20 01  mov  1, %o0
a0084790:  90 10 20 01  mov  1, %o0
a0084794:  40 00 08 87  call  0xa00869b0
a0084798:  92 10 23 e8  mov  0x3e8, %o1
a008479c:  1b 2a 00 ab  sethi  %hi(0xa802ac00), %o5
a00847a0:  f0 0b 63 44  ldub  [ %o5 + 0x344 ], %i0	! 0xa802af44
a00847a4:  82 16 20 02  or  %i0, 2, %g1
a00847a8:  10 80 04 75  b  0xa008597c
a00847ac:  c2 2b 63 44  stb  %g1, [ %o5 + 0x344 ]
a00847b0:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00847b4:  da 03 22 90  ld  [ %o4 + 0x290 ], %o5	! 0xa802d290
a00847b8:  03 00 00 10  sethi  %hi(0x4000), %g1
a00847bc:  80 8b 40 01  btst  %o5, %g1
a00847c0:  22 80 00 03  be,a   0xa00847cc
a00847c4:  82 13 40 01  or  %o5, %g1, %g1
a00847c8:  82 2b 40 01  andn  %o5, %g1, %g1
a00847cc:  c2 23 22 90  st  %g1, [ %o4 + 0x290 ]
a00847d0:  90 10 20 fe  mov  0xfe, %o0
a00847d4:  40 03 1b 38  call  0xa014b4b4
a00847d8:  92 10 20 01  mov  1, %o1
a00847dc:  7f ff f5 b3  call  0xa0081ea8
a00847e0:  90 10 20 02  mov  2, %o0
a00847e4:  90 10 20 01  mov  1, %o0
a00847e8:  40 00 08 72  call  0xa00869b0
a00847ec:  92 10 23 e8  mov  0x3e8, %o1
a00847f0:  1b 2a 00 ab  sethi  %hi(0xa802ac00), %o5
a00847f4:  e0 0b 63 44  ldub  [ %o5 + 0x344 ], %l0	! 0xa802af44
a00847f8:  82 14 20 08  or  %l0, 8, %g1
a00847fc:  10 80 04 60  b  0xa008597c
a0084800:  c2 2b 63 44  stb  %g1, [ %o5 + 0x344 ]
a0084804:  40 02 f4 a5  call  0xa0141a98
a0084808:  31 2a 00 b4  sethi  %hi(0xa802d000), %i0
a008480c:  17 2a 00 b3  sethi  %hi(0xa802cc00), %o3
a0084810:  a0 12 e3 f4  or  %o3, 0x3f4, %l0	! 0xa802cff4
a0084814:  da 14 20 18  lduh  [ %l0 + 0x18 ], %o5
a0084818:  96 0a 20 ff  and  %o0, 0xff, %o3
a008481c:  b3 33 60 0d  srl  %o5, 0xd, %i1
a0084820:  a2 16 22 90  or  %i0, 0x290, %l1
a0084824:  35 00 03 fc  sethi  %hi(0xff000), %i2
a0084828:  90 16 a0 a8  or  %i2, 0xa8, %o0	! 0xff0a8
a008482c:  94 0e 60 01  and  %i1, 1, %o2
a0084830:  40 01 6a 50  call  0xa00df170
a0084834:  d2 0c 60 1f  ldub  [ %l1 + 0x1f ], %o1
a0084838:  d8 0c 20 1c  ldub  [ %l0 + 0x1c ], %o4
a008483c:  80 8b 20 01  btst  1, %o4
a0084840:  02 80 03 9d  be  0xa00856b4
a0084844:  92 10 20 07  mov  7, %o1
a0084848:  92 10 20 07  mov  7, %o1
a008484c:  40 03 03 85  call  0xa0145660
a0084850:  90 10 20 00  clr  %o0
a0084854:  a0 10 00 08  mov  %o0, %l0
a0084858:  92 10 20 08  mov  8, %o1
a008485c:  40 03 03 81  call  0xa0145660
a0084860:  90 10 20 00  clr  %o0
a0084864:  a2 10 00 08  mov  %o0, %l1
a0084868:  92 10 20 01  mov  1, %o1
a008486c:  40 03 03 7d  call  0xa0145660
a0084870:  90 10 20 00  clr  %o0
a0084874:  b4 10 00 08  mov  %o0, %i2
a0084878:  40 02 ff d1  call  0xa01447bc
a008487c:  90 10 20 00  clr  %o0
a0084880:  b2 10 00 08  mov  %o0, %i1
a0084884:  40 02 ff 02  call  0xa014448c
a0084888:  90 10 20 00  clr  %o0
a008488c:  a1 2c 20 10  sll  %l0, 0x10, %l0
a0084890:  95 34 20 10  srl  %l0, 0x10, %o2
a0084894:  9e 1a a7 80  xor  %o2, 0x780, %o7
a0084898:  a3 2c 60 10  sll  %l1, 0x10, %l1
a008489c:  80 a0 00 0f  cmp  %g0, %o7
a00848a0:  93 34 60 10  srl  %l1, 0x10, %o1
a00848a4:  96 60 3f ff  subx  %g0, -1, %o3
a00848a8:  82 1a 64 38  xor  %o1, 0x438, %g1
a00848ac:  80 a0 00 01  cmp  %g0, %g1
a00848b0:  9a 60 3f ff  subx  %g0, -1, %o5
a00848b4:  80 8a c0 0d  btst  %o3, %o5
a00848b8:  02 80 00 0e  be  0xa00848f0
a00848bc:  9b 34 20 10  srl  %l0, 0x10, %o5
a00848c0:  97 2e a0 10  sll  %i2, 0x10, %o3
a00848c4:  9b 32 e0 10  srl  %o3, 0x10, %o5
a00848c8:  80 a3 69 92  cmp  %o5, 0x992
a00848cc:  98 60 20 00  subx  %g0, 0, %o4
a00848d0:  80 a3 69 2e  cmp  %o5, 0x92e
a00848d4:  9a 0b 20 01  and  %o4, 1, %o5
a00848d8:  18 80 00 03  bgu  0xa00848e4
a00848dc:  82 10 20 01  mov  1, %g1
a00848e0:  82 10 20 00  clr  %g1
a00848e4:  80 8b 40 01  btst  %o5, %g1
a00848e8:  12 80 00 38  bne  0xa00849c8
a00848ec:  9b 34 20 10  srl  %l0, 0x10, %o5
a00848f0:  98 1b 6f 00  xor  %o5, 0xf00, %o4
a00848f4:  80 a0 00 0c  cmp  %g0, %o4
a00848f8:  95 34 60 10  srl  %l1, 0x10, %o2
a00848fc:  92 60 3f ff  subx  %g0, -1, %o1
a0084900:  9e 1a a8 70  xor  %o2, 0x870, %o7
a0084904:  80 a0 00 0f  cmp  %g0, %o7
a0084908:  82 60 3f ff  subx  %g0, -1, %g1
a008490c:  80 8a 40 01  btst  %o1, %g1
a0084910:  02 80 00 0e  be  0xa0084948
a0084914:  9b 34 20 10  srl  %l0, 0x10, %o5
a0084918:  93 2e a0 10  sll  %i2, 0x10, %o1
a008491c:  83 32 60 10  srl  %o1, 0x10, %g1
a0084920:  80 a0 64 e2  cmp  %g1, 0x4e2
a0084924:  96 60 20 00  subx  %g0, 0, %o3
a0084928:  80 a0 64 7e  cmp  %g1, 0x47e
a008492c:  9a 0a e0 01  and  %o3, 1, %o5
a0084930:  18 80 00 03  bgu  0xa008493c
a0084934:  82 10 20 01  mov  1, %g1
a0084938:  82 10 20 00  clr  %g1
a008493c:  80 8b 40 01  btst  %o5, %g1
a0084940:  12 80 00 22  bne  0xa00849c8
a0084944:  9b 34 20 10  srl  %l0, 0x10, %o5
a0084948:  98 1b 6a 00  xor  %o5, 0xa00, %o4
a008494c:  80 a0 00 0c  cmp  %g0, %o4
a0084950:  95 34 60 10  srl  %l1, 0x10, %o2
a0084954:  a0 60 3f ff  subx  %g0, -1, %l0
a0084958:  9e 1a a6 40  xor  %o2, 0x640, %o7
a008495c:  80 a0 00 0f  cmp  %g0, %o7
a0084960:  a2 60 3f ff  subx  %g0, -1, %l1
a0084964:  80 8c 00 11  btst  %l0, %l1
a0084968:  22 80 00 13  be,a   0xa00849b4
a008496c:  a2 16 22 90  or  %i0, 0x290, %l1
a0084970:  83 2e a0 10  sll  %i2, 0x10, %g1
a0084974:  97 30 60 10  srl  %g1, 0x10, %o3
a0084978:  80 a2 e5 d2  cmp  %o3, 0x5d2
a008497c:  b4 60 20 00  subx  %g0, 0, %i2
a0084980:  80 a2 e5 6e  cmp  %o3, 0x56e
a0084984:  9a 0e a0 01  and  %i2, 1, %o5
a0084988:  18 80 00 03  bgu  0xa0084994
a008498c:  82 10 20 01  mov  1, %g1
a0084990:  82 10 20 00  clr  %g1
a0084994:  80 8b 40 01  btst  %o5, %g1
a0084998:  02 80 00 07  be  0xa00849b4
a008499c:  a2 16 22 90  or  %i0, 0x290, %l1
a00849a0:  92 0e 60 ff  and  %i1, 0xff, %o1
a00849a4:  80 a2 60 06  cmp  %o1, 6
a00849a8:  02 80 03 c0  be  0xa00858a8
a00849ac:  b2 02 3f f4  add  %o0, -12, %i1
a00849b0:  a2 16 22 90  or  %i0, 0x290, %l1
a00849b4:  f0 04 60 a8  ld  [ %l1 + 0xa8 ], %i0
a00849b8:  90 10 20 00  clr  %o0
a00849bc:  80 8e 20 80  btst  0x80, %i0
a00849c0:  02 80 00 04  be  0xa00849d0
a00849c4:  92 10 20 00  clr  %o1
a00849c8:  90 10 20 00  clr  %o0
a00849cc:  92 10 20 01  mov  1, %o1
a00849d0:  40 03 24 f2  call  0xa014dd98
a00849d4:  01 00 00 00  nop
a00849d8:  90 10 20 01  mov  1, %o0	! 0x1
a00849dc:  92 10 20 01  mov  1, %o1
a00849e0:  40 01 58 96  call  0xa00dac38
a00849e4:  94 10 20 00  clr  %o2
a00849e8:  40 02 92 fa  call  0xa01295d0
a00849ec:  81 e8 00 00  restore
a00849f0:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00849f4:  da 03 22 90  ld  [ %o4 + 0x290 ], %o5	! 0xa802d290
a00849f8:  03 00 00 08  sethi  %hi(0x2000), %g1
a00849fc:  80 8b 40 01  btst  %o5, %g1
a0084a00:  22 80 02 d1  be,a   0xa0085544
a0084a04:  82 13 40 01  or  %o5, %g1, %g1
a0084a08:  82 2b 40 01  andn  %o5, %g1, %g1
a0084a0c:  10 bf ff 74  b  0xa00847dc
a0084a10:  c2 23 22 90  st  %g1, [ %o4 + 0x290 ]
a0084a14:  7f ff fe 47  call  0xa0084330
a0084a18:  90 10 20 01  mov  1, %o0
a0084a1c:  7f ff ef d7  call  0xa0080978
a0084a20:  01 00 00 00  nop
a0084a24:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a0084a28:  9e 13 22 90  or  %o4, 0x290, %o7	! 0xa802d290
a0084a2c:  f0 0b e0 1f  ldub  [ %o7 + 0x1f ], %i0
a0084a30:  80 a6 20 00  cmp  %i0, 0
a0084a34:  02 80 03 d2  be  0xa008597c
a0084a38:  d4 03 22 90  ld  [ %o4 + 0x290 ], %o2
a0084a3c:  80 8a a2 00  btst  0x200, %o2
a0084a40:  12 80 03 cf  bne  0xa008597c
a0084a44:  01 00 00 00  nop
a0084a48:  40 02 8b b9  call  0xa012792c
a0084a4c:  01 00 00 00  nop
a0084a50:  80 8a 20 ff  btst  0xff, %o0
a0084a54:  12 80 03 ca  bne  0xa008597c
a0084a58:  01 00 00 00  nop
a0084a5c:  40 02 8b ba  call  0xa0127944
a0084a60:  01 00 00 00  nop
a0084a64:  80 8a 20 ff  btst  0xff, %o0
a0084a68:  12 80 03 c5  bne  0xa008597c
a0084a6c:  01 00 00 00  nop
a0084a70:  40 02 80 34  call  0xa0124b40
a0084a74:  01 00 00 00  nop
a0084a78:  40 02 7f fc  call  0xa0124a68
a0084a7c:  81 e8 00 00  restore
a0084a80:  1b 2a 00 ab  sethi  %hi(0xa802ac00), %o5
a0084a84:  d6 13 63 42  lduh  [ %o5 + 0x342 ], %o3	! 0xa802af42
a0084a88:  82 12 e0 04  or  %o3, 4, %g1
a0084a8c:  10 80 03 bc  b  0xa008597c
a0084a90:  c2 33 63 42  sth  %g1, [ %o5 + 0x342 ]
a0084a94:  1b 2a 00 ab  sethi  %hi(0xa802ac00), %o5
a0084a98:  d4 13 63 42  lduh  [ %o5 + 0x342 ], %o2	! 0xa802af42
a0084a9c:  82 12 a0 02  or  %o2, 2, %g1
a0084aa0:  10 80 03 b7  b  0xa008597c
a0084aa4:  c2 33 63 42  sth  %g1, [ %o5 + 0x342 ]
a0084aa8:  1b 2a 00 ab  sethi  %hi(0xa802ac00), %o5
a0084aac:  de 13 63 42  lduh  [ %o5 + 0x342 ], %o7	! 0xa802af42
a0084ab0:  82 13 e0 01  or  %o7, 1, %g1
a0084ab4:  10 80 03 b2  b  0xa008597c
a0084ab8:  c2 33 63 42  sth  %g1, [ %o5 + 0x342 ]
a0084abc:  17 2a 00 b3  sethi  %hi(0xa802cc00), %o3
a0084ac0:  c2 12 e3 f4  lduh  [ %o3 + 0x3f4 ], %g1	! 0xa802cff4
a0084ac4:  98 12 e3 f4  or  %o3, 0x3f4, %o4
a0084ac8:  d4 0b 20 1c  ldub  [ %o4 + 0x1c ], %o2
a0084acc:  9a 10 61 00  or  %g1, 0x100, %o5
a0084ad0:  80 a2 a0 00  cmp  %o2, 0
a0084ad4:  02 80 02 a0  be  0xa0085554
a0084ad8:  da 32 e3 f4  sth  %o5, [ %o3 + 0x3f4 ]
a0084adc:  11 00 03 fc  sethi  %hi(0xff000), %o0
a0084ae0:  40 01 69 a4  call  0xa00df170
a0084ae4:  90 12 20 e0  or  %o0, 0xe0, %o0	! 0xff0e0
a0084ae8:  40 01 3f a2  call  0xa00d4970
a0084aec:  01 00 00 00  nop
a0084af0:  40 01 3f 77  call  0xa00d48cc
a0084af4:  01 00 00 00  nop
a0084af8:  40 01 57 fc  call  0xa00daae8
a0084afc:  01 00 00 00  nop
a0084b00:  40 01 58 02  call  0xa00dab08
a0084b04:  01 00 00 00  nop
a0084b08:  40 01 58 06  call  0xa00dab20
a0084b0c:  01 00 00 00  nop
a0084b10:  40 01 58 20  call  0xa00dab90
a0084b14:  01 00 00 00  nop
a0084b18:  40 01 58 2c  call  0xa00dabc8
a0084b1c:  01 00 00 00  nop
a0084b20:  40 01 58 38  call  0xa00dac00
a0084b24:  81 e8 00 00  restore
a0084b28:  33 2a 00 b4  sethi  %hi(0xa802d000), %i1
a0084b2c:  f4 0e 60 10  ldub  [ %i1 + 0x10 ], %i2	! 0xa802d010
a0084b30:  80 8e a0 08  btst  8, %i2
a0084b34:  02 80 02 57  be  0xa0085490
a0084b38:  01 00 00 00  nop
a0084b3c:  b0 10 20 03  mov  3, %i0	! 0x3
a0084b40:  b2 10 20 00  clr  %i1
a0084b44:  40 03 17 64  call  0xa014a8d4
a0084b48:  95 e8 20 00  restore  %g0, 0, %o2
a0084b4c:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a0084b50:  d8 0a e0 10  ldub  [ %o3 + 0x10 ], %o4	! 0xa802d010
a0084b54:  80 8b 20 02  btst  2, %o4
a0084b58:  02 80 02 28  be  0xa00853f8
a0084b5c:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a0084b60:  10 bf ff f8  b  0xa0084b40
a0084b64:  b0 10 20 01  mov  1, %i0
a0084b68:  19 00 03 fc  sethi  %hi(0xff000), %o4
a0084b6c:  40 01 69 81  call  0xa00df170
a0084b70:  90 13 21 08  or  %o4, 0x108, %o0	! 0xff108
a0084b74:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a0084b78:  de 0a a0 10  ldub  [ %o2 + 0x10 ], %o7	! 0xa802d010
a0084b7c:  80 8b e0 01  btst  1, %o7
a0084b80:  02 80 02 9e  be  0xa00855f8
a0084b84:  23 2a 00 b4  sethi  %hi(0xa802d000), %l1
a0084b88:  90 10 20 00  clr  %o0
a0084b8c:  92 10 20 00  clr  %o1
a0084b90:  40 03 17 51  call  0xa014a8d4
a0084b94:  94 10 20 00  clr  %o2
a0084b98:  98 14 62 90  or  %l1, 0x290, %o4
a0084b9c:  d0 03 20 ac  ld  [ %o4 + 0xac ], %o0
a0084ba0:  23 00 04 00  sethi  %hi(0x100000), %l1
a0084ba4:  80 8a 00 11  btst  %o0, %l1
a0084ba8:  02 80 00 06  be  0xa0084bc0
a0084bac:  15 00 00 06  sethi  %hi(0x1800), %o2
a0084bb0:  f0 0b 20 1f  ldub  [ %o4 + 0x1f ], %i0
a0084bb4:  80 a6 20 00  cmp  %i0, 0
a0084bb8:  02 80 02 51  be  0xa00854fc
a0084bbc:  01 00 00 00  nop
a0084bc0:  b0 12 a1 64  or  %o2, 0x164, %i0
a0084bc4:  40 03 0d e5  call  0xa0148358
a0084bc8:  81 e8 00 00  restore
a0084bcc:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a0084bd0:  de 0a a0 10  ldub  [ %o2 + 0x10 ], %o7	! 0xa802d010
a0084bd4:  80 8b e0 04  btst  4, %o7
a0084bd8:  02 80 02 3b  be  0xa00854c4
a0084bdc:  01 00 00 00  nop
a0084be0:  10 bf ff d8  b  0xa0084b40
a0084be4:  b0 10 20 02  mov  2, %i0	! 0x2
a0084be8:  31 00 03 fc  sethi  %hi(0xff000), %i0
a0084bec:  40 01 69 61  call  0xa00df170
a0084bf0:  91 ee 21 28  restore  %i0, 0x128, %o0
a0084bf4:  11 2a 00 b3  sethi  %hi(0xa802cc00), %o0
a0084bf8:  a0 12 23 f4  or  %o0, 0x3f4, %l0	! 0xa802cff4
a0084bfc:  f2 0c 20 1c  ldub  [ %l0 + 0x1c ], %i1
a0084c00:  80 a6 60 00  cmp  %i1, 0
a0084c04:  12 80 03 5e  bne  0xa008597c
a0084c08:  23 00 03 fc  sethi  %hi(0xff000), %l1
a0084c0c:  40 01 69 59  call  0xa00df170
a0084c10:  90 14 61 48  or  %l1, 0x148, %o0	! 0xff148
a0084c14:  40 00 19 c7  call  0xa008b330
a0084c18:  01 00 00 00  nop
a0084c1c:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a0084c20:  d4 14 20 04  lduh  [ %l0 + 4 ], %o2
a0084c24:  a2 13 22 90  or  %o4, 0x290, %l1
a0084c28:  f0 0c 61 d5  ldub  [ %l1 + 0x1d5 ], %i0
a0084c2c:  9e 0a bd ff  and  %o2, -513, %o7
a0084c30:  80 a6 20 00  cmp  %i0, 0
a0084c34:  12 80 03 0d  bne  0xa0085868
a0084c38:  de 34 20 04  sth  %o7, [ %l0 + 4 ]
a0084c3c:  40 01 53 4f  call  0xa00d9978
a0084c40:  35 00 00 15  sethi  %hi(0x5400), %i2
a0084c44:  40 01 53 59  call  0xa00d99a8
a0084c48:  01 00 00 00  nop
a0084c4c:  40 01 56 c2  call  0xa00da754
a0084c50:  d0 0c 60 ac  ldub  [ %l1 + 0xac ], %o0
a0084c54:  d2 14 61 f6  lduh  [ %l1 + 0x1f6 ], %o1
a0084c58:  82 16 a1 aa  or  %i2, 0x1aa, %g1
a0084c5c:  80 a2 40 01  cmp  %o1, %g1
a0084c60:  22 80 03 0f  be,a   0xa008589c
a0084c64:  d0 04 61 ec  ld  [ %l1 + 0x1ec ], %o0
a0084c68:  40 01 59 31  call  0xa00db12c
a0084c6c:  91 e8 20 00  restore  %g0, 0, %o0
a0084c70:  1f 00 03 fc  sethi  %hi(0xff000), %o7
a0084c74:  90 13 e1 68  or  %o7, 0x168, %o0	! 0xff168
a0084c78:  40 01 69 3e  call  0xa00df170
a0084c7c:  23 2a 00 b4  sethi  %hi(0xa802d000), %l1
a0084c80:  f0 0c 60 10  ldub  [ %l1 + 0x10 ], %i0	! 0xa802d010
a0084c84:  80 8e 20 02  btst  2, %i0
a0084c88:  12 80 03 3d  bne  0xa008597c
a0084c8c:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a0084c90:  9a 14 22 90  or  %l0, 0x290, %o5	! 0xa802d290
a0084c94:  d4 0b 60 1f  ldub  [ %o5 + 0x1f ], %o2
a0084c98:  80 a2 a0 00  cmp  %o2, 0
a0084c9c:  02 80 03 38  be  0xa008597c
a0084ca0:  d8 04 22 90  ld  [ %l0 + 0x290 ], %o4
a0084ca4:  80 8b 22 00  btst  0x200, %o4
a0084ca8:  12 80 00 09  bne  0xa0084ccc
a0084cac:  82 14 22 90  or  %l0, 0x290, %g1
a0084cb0:  d6 03 60 a8  ld  [ %o5 + 0xa8 ], %o3
a0084cb4:  80 8a e8 00  btst  0x800, %o3
a0084cb8:  12 80 02 f5  bne  0xa008588c
a0084cbc:  01 00 00 00  nop
a0084cc0:  40 01 5c 0c  call  0xa00dbcf0
a0084cc4:  01 00 00 00  nop
a0084cc8:  82 14 22 90  or  %l0, 0x290, %g1
a0084ccc:  e0 00 60 a8  ld  [ %g1 + 0xa8 ], %l0
a0084cd0:  1b 00 00 10  sethi  %hi(0x4000), %o5
a0084cd4:  80 8c 00 0d  btst  %l0, %o5
a0084cd8:  12 80 02 e1  bne  0xa008585c
a0084cdc:  01 00 00 00  nop
a0084ce0:  40 00 30 bb  call  0xa0090fcc
a0084ce4:  01 00 00 00  nop
a0084ce8:  b5 2a 20 10  sll  %o0, 0x10, %i2
a0084cec:  93 36 a0 10  srl  %i2, 0x10, %o1
a0084cf0:  80 a2 61 0d  cmp  %o1, 0x10d
a0084cf4:  12 80 03 22  bne  0xa008597c
a0084cf8:  01 00 00 00  nop
a0084cfc:  40 00 30 b7  call  0xa0090fd8
a0084d00:  81 e8 00 00  restore
a0084d04:  1b 00 03 fc  sethi  %hi(0xff000), %o5
a0084d08:  40 01 69 1a  call  0xa00df170
a0084d0c:  90 13 61 88  or  %o5, 0x188, %o0	! 0xff188
a0084d10:  40 03 0d 9b  call  0xa014837c
a0084d14:  90 10 20 00  clr  %o0
a0084d18:  99 2a 20 10  sll  %o0, 0x10, %o4
a0084d1c:  b5 33 20 10  srl  %o4, 0x10, %i2
a0084d20:  40 03 0d 97  call  0xa014837c
a0084d24:  90 10 20 01  mov  1, %o0
a0084d28:  95 2a 20 10  sll  %o0, 0x10, %o2
a0084d2c:  99 32 a0 10  srl  %o2, 0x10, %o4
a0084d30:  96 10 00 1a  mov  %i2, %o3
a0084d34:  90 10 20 00  clr  %o0
a0084d38:  92 10 20 00  clr  %o1
a0084d3c:  40 03 08 3c  call  0xa0146e2c
a0084d40:  94 10 20 00  clr  %o2
a0084d44:  1f 2a 00 b3  sethi  %hi(0xa802cc00), %o7
a0084d48:  a2 13 e3 f4  or  %o7, 0x3f4, %l1	! 0xa802cff4
a0084d4c:  e0 0c 60 1c  ldub  [ %l1 + 0x1c ], %l0
a0084d50:  35 2a 00 b4  sethi  %hi(0xa802d000), %i2
a0084d54:  80 8c 20 01  btst  1, %l0
a0084d58:  12 80 03 09  bne  0xa008597c
a0084d5c:  a0 16 a2 90  or  %i2, 0x290, %l0
a0084d60:  11 00 03 fc  sethi  %hi(0xff000), %o0
a0084d64:  40 01 69 03  call  0xa00df170
a0084d68:  90 12 21 a8  or  %o0, 0x1a8, %o0	! 0xff1a8
a0084d6c:  40 02 fe cc  call  0xa014489c
a0084d70:  90 10 20 00  clr  %o0
a0084d74:  33 2a 00 97  sethi  %hi(0xa8025c00), %i1
a0084d78:  13 00 03 fc  sethi  %hi(0xff000), %o1
a0084d7c:  d0 2e 60 57  stb  %o0, [ %i1 + 0x57 ]
a0084d80:  40 01 68 fc  call  0xa00df170
a0084d84:  90 12 61 c8  or  %o1, 0x1c8, %o0
a0084d88:  40 01 55 cc  call  0xa00da4b8
a0084d8c:  01 00 00 00  nop
a0084d90:  c2 0c 21 b4  ldub  [ %l0 + 0x1b4 ], %g1
a0084d94:  17 2a 00 ab  sethi  %hi(0xa802ac00), %o3
a0084d98:  40 03 25 62  call  0xa014e320
a0084d9c:  c2 2a e3 40  stb  %g1, [ %o3 + 0x340 ]	! 0xa802af40
a0084da0:  40 01 4b ea  call  0xa00d7d48
a0084da4:  01 00 00 00  nop
a0084da8:  80 a2 20 00  cmp  %o0, 0
a0084dac:  02 80 00 11  be  0xa0084df0
a0084db0:  92 16 a2 90  or  %i2, 0x290, %o1
a0084db4:  f0 14 60 0a  lduh  [ %l1 + 0xa ], %i0
a0084db8:  80 8e 20 80  btst  0x80, %i0
a0084dbc:  32 80 00 0e  bne,a   0xa0084df4
a0084dc0:  e0 02 60 a8  ld  [ %o1 + 0xa8 ], %l0
a0084dc4:  da 04 20 a8  ld  [ %l0 + 0xa8 ], %o5
a0084dc8:  83 2b 60 03  sll  %o5, 3, %g1
a0084dcc:  96 08 68 00  and  %g1, 0x800, %o3
a0084dd0:  98 0b 77 ff  and  %o5, -2049, %o4
a0084dd4:  9e 13 00 0b  or  %o4, %o3, %o7
a0084dd8:  e2 0c 21 88  ldub  [ %l0 + 0x188 ], %l1
a0084ddc:  d4 0c 21 87  ldub  [ %l0 + 0x187 ], %o2
a0084de0:  d4 2c 21 81  stb  %o2, [ %l0 + 0x181 ]
a0084de4:  de 24 20 a8  st  %o7, [ %l0 + 0xa8 ]
a0084de8:  e2 2c 21 82  stb  %l1, [ %l0 + 0x182 ]
a0084dec:  92 16 a2 90  or  %i2, 0x290, %o1
a0084df0:  e0 02 60 a8  ld  [ %o1 + 0xa8 ], %l0
a0084df4:  80 8c 28 00  btst  0x800, %l0
a0084df8:  12 80 02 73  bne  0xa00857c4
a0084dfc:  01 00 00 00  nop
a0084e00:  40 01 5b bc  call  0xa00dbcf0
a0084e04:  01 00 00 00  nop
a0084e08:  98 16 a2 90  or  %i2, 0x290, %o4
a0084e0c:  f2 03 20 a8  ld  [ %o4 + 0xa8 ], %i1
a0084e10:  35 00 00 10  sethi  %hi(0x4000), %i2
a0084e14:  80 8e 40 1a  btst  %i1, %i2
a0084e18:  02 80 00 06  be  0xa0084e30
a0084e1c:  01 00 00 00  nop
a0084e20:  d0 0b 20 1f  ldub  [ %o4 + 0x1f ], %o0
a0084e24:  80 a2 20 00  cmp  %o0, 0
a0084e28:  12 bf ff 90  bne  0xa0084c68
a0084e2c:  01 00 00 00  nop
a0084e30:  40 01 43 aa  call  0xa00d5cd8
a0084e34:  01 00 00 00  nop
a0084e38:  30 bf ff 8c  b,a   0xa0084c68
a0084e3c:  17 00 03 fc  sethi  %hi(0xff000), %o3
a0084e40:  40 01 68 cc  call  0xa00df170
a0084e44:  90 12 e1 e0  or  %o3, 0x1e0, %o0	! 0xff1e0
a0084e48:  15 2a 00 b3  sethi  %hi(0xa802cc00), %o2
a0084e4c:  9a 12 a3 f4  or  %o2, 0x3f4, %o5	! 0xa802cff4
a0084e50:  c2 13 60 06  lduh  [ %o5 + 6 ], %g1
a0084e54:  80 88 60 40  btst  0x40, %g1
a0084e58:  02 80 02 c9  be  0xa008597c
a0084e5c:  9e 08 7f bf  and  %g1, -65, %o7
a0084e60:  19 00 03 fc  sethi  %hi(0xff000), %o4
a0084e64:  de 33 60 06  sth  %o7, [ %o5 + 6 ]
a0084e68:  40 01 68 c2  call  0xa00df170
a0084e6c:  90 13 21 f8  or  %o4, 0x1f8, %o0
a0084e70:  40 02 7f 34  call  0xa0124b40
a0084e74:  b0 10 20 02  mov  2, %i0
a0084e78:  40 02 7e fc  call  0xa0124a68
a0084e7c:  01 00 00 00  nop
a0084e80:  40 03 0f 0a  call  0xa0148aa8
a0084e84:  90 10 20 01  mov  1, %o0	! 0x1
a0084e88:  40 00 07 18  call  0xa0086ae8
a0084e8c:  81 e8 00 00  restore
a0084e90:  40 03 0a 86  call  0xa01478a8
a0084e94:  81 e8 00 00  restore
a0084e98:  92 10 23 e8  mov  0x3e8, %o1
a0084e9c:  40 00 06 c5  call  0xa00869b0
a0084ea0:  90 10 20 01  mov  1, %o0
a0084ea4:  1b 2a 00 ab  sethi  %hi(0xa802ac00), %o5
a0084ea8:  d2 0b 63 44  ldub  [ %o5 + 0x344 ], %o1	! 0xa802af44
a0084eac:  82 12 60 04  or  %o1, 4, %g1
a0084eb0:  10 80 02 b3  b  0xa008597c
a0084eb4:  c2 2b 63 44  stb  %g1, [ %o5 + 0x344 ]
a0084eb8:  90 10 20 01  mov  1, %o0
a0084ebc:  40 00 06 bd  call  0xa00869b0
a0084ec0:  92 10 23 e8  mov  0x3e8, %o1
a0084ec4:  1b 2a 00 ab  sethi  %hi(0xa802ac00), %o5
a0084ec8:  d4 0b 63 44  ldub  [ %o5 + 0x344 ], %o2	! 0xa802af44
a0084ecc:  82 12 a0 01  or  %o2, 1, %g1
a0084ed0:  10 80 02 ab  b  0xa008597c
a0084ed4:  c2 2b 63 44  stb  %g1, [ %o5 + 0x344 ]
a0084ed8:  7f ff f3 f4  call  0xa0081ea8
a0084edc:  91 e8 20 03  restore  %g0, 3, %o0
a0084ee0:  7f ff f3 f2  call  0xa0081ea8
a0084ee4:  90 10 20 02  mov  2, %o0
a0084ee8:  10 bf fe 2b  b  0xa0084794
a0084eec:  90 10 20 01  mov  1, %o0
a0084ef0:  35 2a 00 b4  sethi  %hi(0xa802d000), %i2
a0084ef4:  a0 16 a2 90  or  %i2, 0x290, %l0	! 0xa802d290
a0084ef8:  f2 04 20 ac  ld  [ %l0 + 0xac ], %i1
a0084efc:  23 00 04 00  sethi  %hi(0x100000), %l1
a0084f00:  80 8e 40 11  btst  %i1, %l1
a0084f04:  12 80 01 df  bne  0xa0085680
a0084f08:  01 00 00 00  nop
a0084f0c:  40 02 8a 88  call  0xa012792c
a0084f10:  01 00 00 00  nop
a0084f14:  82 0a 20 ff  and  %o0, 0xff, %g1
a0084f18:  80 a0 60 02  cmp  %g1, 2
a0084f1c:  02 80 01 53  be  0xa0085468
a0084f20:  01 00 00 00  nop
a0084f24:  40 02 8a 82  call  0xa012792c
a0084f28:  01 00 00 00  nop
a0084f2c:  92 0a 20 ff  and  %o0, 0xff, %o1
a0084f30:  80 a2 60 01  cmp  %o1, 1
a0084f34:  02 80 01 4d  be  0xa0085468
a0084f38:  01 00 00 00  nop
a0084f3c:  90 10 20 00  clr  %o0	! 0x0
a0084f40:  7f ff f3 da  call  0xa0081ea8
a0084f44:  01 00 00 00  nop
a0084f48:  10 bf fe 13  b  0xa0084794
a0084f4c:  90 10 20 01  mov  1, %o0	! 0x1
a0084f50:  17 00 03 fc  sethi  %hi(0xff000), %o3
a0084f54:  40 01 68 87  call  0xa00df170
a0084f58:  90 12 e2 18  or  %o3, 0x218, %o0	! 0xff218
a0084f5c:  13 2a 00 b3  sethi  %hi(0xa802cc00), %o1
a0084f60:  d4 12 63 f4  lduh  [ %o1 + 0x3f4 ], %o2	! 0xa802cff4
a0084f64:  b0 0a be ff  and  %o2, -257, %i0
a0084f68:  40 02 7e a8  call  0xa0124a08
a0084f6c:  f0 32 63 f4  sth  %i0, [ %o1 + 0x3f4 ]
a0084f70:  92 10 20 01  mov  1, %o1
a0084f74:  40 03 00 6e  call  0xa014512c
a0084f78:  90 10 20 00  clr  %o0
a0084f7c:  03 00 03 fc  sethi  %hi(0xff000), %g1
a0084f80:  40 01 68 7c  call  0xa00df170
a0084f84:  90 10 62 30  or  %g1, 0x230, %o0	! 0xff230
a0084f88:  40 03 0a 99  call  0xa01479ec
a0084f8c:  90 10 20 01  mov  1, %o0
a0084f90:  40 02 fc 0d  call  0xa0143fc4
a0084f94:  91 e8 20 01  restore  %g0, 1, %o0
a0084f98:  11 00 00 04  sethi  %hi(0x1000), %o0
a0084f9c:  b2 12 23 88  or  %o0, 0x388, %i1	! 0x1388
a0084fa0:  40 00 06 84  call  0xa00869b0
a0084fa4:  91 e8 20 07  restore  %g0, 7, %o0
a0084fa8:  23 00 00 04  sethi  %hi(0x1000), %l1
a0084fac:  b2 14 63 88  or  %l1, 0x388, %i1	! 0x1388
a0084fb0:  40 00 06 80  call  0xa00869b0
a0084fb4:  91 e8 20 06  restore  %g0, 6, %o0
a0084fb8:  21 00 00 04  sethi  %hi(0x1000), %l0
a0084fbc:  92 14 23 88  or  %l0, 0x388, %o1	! 0x1388
a0084fc0:  40 00 06 7c  call  0xa00869b0
a0084fc4:  90 10 20 05  mov  5, %o0
a0084fc8:  19 00 03 fc  sethi  %hi(0xff000), %o4
a0084fcc:  40 01 68 69  call  0xa00df170
a0084fd0:  90 13 22 48  or  %o4, 0x248, %o0	! 0xff248
a0084fd4:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a0084fd8:  98 13 e2 90  or  %o7, 0x290, %o4	! 0xa802d290
a0084fdc:  d6 03 20 a8  ld  [ %o4 + 0xa8 ], %o3
a0084fe0:  15 00 00 10  sethi  %hi(0x4000), %o2
a0084fe4:  80 8a c0 0a  btst  %o3, %o2
a0084fe8:  02 80 02 65  be  0xa008597c
a0084fec:  01 00 00 00  nop
a0084ff0:  f2 0b 20 1f  ldub  [ %o4 + 0x1f ], %i1
a0084ff4:  80 a6 60 00  cmp  %i1, 0
a0084ff8:  02 80 02 61  be  0xa008597c
a0084ffc:  35 00 00 80  sethi  %hi(0x20000), %i2
a0085000:  da 03 20 ac  ld  [ %o4 + 0xac ], %o5
a0085004:  80 8b 40 1a  btst  %o5, %i2
a0085008:  02 80 02 5d  be  0xa008597c
a008500c:  01 00 00 00  nop
a0085010:  40 03 0a 77  call  0xa01479ec
a0085014:  91 e8 20 01  restore  %g0, 1, %o0
a0085018:  23 2a 00 b4  sethi  %hi(0xa802d000), %l1
a008501c:  d4 04 62 90  ld  [ %l1 + 0x290 ], %o2	! 0xa802d290
a0085020:  80 8a a2 00  btst  0x200, %o2
a0085024:  02 80 01 c4  be  0xa0085734
a0085028:  82 14 62 90  or  %l1, 0x290, %g1
a008502c:  1f 00 00 15  sethi  %hi(0x5400), %o7
a0085030:  d8 10 61 f6  lduh  [ %g1 + 0x1f6 ], %o4
a0085034:  96 13 e1 aa  or  %o7, 0x1aa, %o3
a0085038:  90 10 20 04  mov  4, %o0
a008503c:  80 a3 00 0b  cmp  %o4, %o3
a0085040:  02 80 00 05  be  0xa0085054
a0085044:  92 10 2b b8  mov  0xbb8, %o1
a0085048:  21 00 00 0b  sethi  %hi(0x2c00), %l0
a008504c:  92 14 22 e0  or  %l0, 0x2e0, %o1	! 0x2ee0
a0085050:  90 10 20 04  mov  4, %o0
a0085054:  40 00 06 57  call  0xa00869b0
a0085058:  33 00 04 00  sethi  %hi(0x100000), %i1
a008505c:  98 14 62 90  or  %l1, 0x290, %o4
a0085060:  f4 03 20 ac  ld  [ %o4 + 0xac ], %i2
a0085064:  80 8e 80 19  btst  %i2, %i1
a0085068:  02 80 00 07  be  0xa0085084
a008506c:  31 00 00 15  sethi  %hi(0x5400), %i0
a0085070:  da 0b 20 1f  ldub  [ %o4 + 0x1f ], %o5
a0085074:  80 a3 60 00  cmp  %o5, 0
a0085078:  02 80 01 ea  be  0xa0085820
a008507c:  01 00 00 00  nop
a0085080:  31 00 00 15  sethi  %hi(0x5400), %i0
a0085084:  d2 13 21 f6  lduh  [ %o4 + 0x1f6 ], %o1
a0085088:  82 16 21 aa  or  %i0, 0x1aa, %g1
a008508c:  80 a2 40 01  cmp  %o1, %g1
a0085090:  12 80 00 07  bne  0xa00850ac
a0085094:  17 00 00 06  sethi  %hi(0x1800), %o3
a0085098:  d4 0b 21 d5  ldub  [ %o4 + 0x1d5 ], %o2
a008509c:  80 a2 a0 00  cmp  %o2, 0
a00850a0:  12 80 00 04  bne  0xa00850b0
a00850a4:  90 10 20 64  mov  0x64, %o0
a00850a8:  17 00 00 06  sethi  %hi(0x1800), %o3
a00850ac:  90 12 e1 64  or  %o3, 0x164, %o0	! 0x1964
a00850b0:  40 03 0c aa  call  0xa0148358
a00850b4:  21 00 03 fc  sethi  %hi(0xff000), %l0
a00850b8:  40 01 68 2e  call  0xa00df170
a00850bc:  90 14 22 60  or  %l0, 0x260, %o0	! 0xff260
a00850c0:  a0 14 62 90  or  %l1, 0x290, %l0
a00850c4:  de 0c 20 1f  ldub  [ %l0 + 0x1f ], %o7
a00850c8:  80 a3 e0 00  cmp  %o7, 0
a00850cc:  12 80 01 65  bne  0xa0085660
a00850d0:  01 00 00 00  nop
a00850d4:  f2 04 20 b0  ld  [ %l0 + 0xb0 ], %i1
a00850d8:  80 a6 60 00  cmp  %i1, 0
a00850dc:  12 80 01 65  bne  0xa0085670
a00850e0:  01 00 00 00  nop
a00850e4:  f4 0c 20 1f  ldub  [ %l0 + 0x1f ], %i2
a00850e8:  80 a6 a0 00  cmp  %i2, 0
a00850ec:  12 80 00 06  bne  0xa0085104
a00850f0:  98 14 62 90  or  %l1, 0x290, %o4
a00850f4:  da 0c 20 4a  ldub  [ %l0 + 0x4a ], %o5
a00850f8:  80 a3 60 00  cmp  %o5, 0
a00850fc:  12 80 01 98  bne  0xa008575c
a0085100:  90 10 20 01  mov  1, %o0
a0085104:  d0 03 20 a8  ld  [ %o4 + 0xa8 ], %o0
a0085108:  23 00 00 10  sethi  %hi(0x4000), %l1
a008510c:  80 8a 00 11  btst  %o0, %l1
a0085110:  12 80 02 1b  bne  0xa008597c
a0085114:  01 00 00 00  nop
a0085118:  c2 0b 20 1f  ldub  [ %o4 + 0x1f ], %g1
a008511c:  80 a0 60 00  cmp  %g1, 0
a0085120:  02 80 02 17  be  0xa008597c
a0085124:  13 00 00 80  sethi  %hi(0x20000), %o1
a0085128:  f0 03 20 ac  ld  [ %o4 + 0xac ], %i0
a008512c:  80 8e 00 09  btst  %i0, %o1
a0085130:  02 80 02 13  be  0xa008597c
a0085134:  01 00 00 00  nop
a0085138:  30 bf ff b6  b,a   0xa0085010
a008513c:  1f 00 03 fc  sethi  %hi(0xff000), %o7
a0085140:  90 13 e2 80  or  %o7, 0x280, %o0	! 0xff280
a0085144:  40 01 68 0b  call  0xa00df170
a0085148:  b0 10 20 00  clr  %i0
a008514c:  40 02 7e 2f  call  0xa0124a08
a0085150:  b2 10 20 00  clr  %i1
a0085154:  40 02 ff f6  call  0xa014512c
a0085158:  81 e8 00 00  restore
a008515c:  7f ff f3 53  call  0xa0081ea8
a0085160:  91 e8 20 04  restore  %g0, 4, %o0
a0085164:  40 03 0c 7b  call  0xa0148350
a0085168:  90 10 20 00  clr  %o0
a008516c:  1b 2a 00 ab  sethi  %hi(0xa802ac00), %o5
a0085170:  d2 13 63 42  lduh  [ %o5 + 0x342 ], %o1	! 0xa802af42
a0085174:  82 12 60 20  or  %o1, 0x20, %g1
a0085178:  10 80 02 01  b  0xa008597c
a008517c:  c2 33 63 42  sth  %g1, [ %o5 + 0x342 ]
a0085180:  15 2a 00 ab  sethi  %hi(0xa802ac00), %o2
a0085184:  d8 12 a3 42  lduh  [ %o2 + 0x342 ], %o4	! 0xa802af42
a0085188:  80 8b 24 00  btst  0x400, %o4
a008518c:  02 80 01 fc  be  0xa008597c
a0085190:  92 10 00 0c  mov  %o4, %o1
a0085194:  35 2a 00 b4  sethi  %hi(0xa802d000), %i2
a0085198:  c2 0e a2 af  ldub  [ %i2 + 0x2af ], %g1	! 0xa802d2af
a008519c:  9a 08 60 ff  and  %g1, 0xff, %o5
a00851a0:  80 a3 60 00  cmp  %o5, 0
a00851a4:  02 80 00 03  be  0xa00851b0
a00851a8:  96 10 20 00  clr  %o3
a00851ac:  96 10 20 01  mov  1, %o3
a00851b0:  80 8a e0 ff  btst  0xff, %o3
a00851b4:  12 80 01 66  bne  0xa008574c
a00851b8:  a2 00 7f fc  add  %g1, -4, %l1
a00851bc:  b2 0c 60 ff  and  %l1, 0xff, %i1
a00851c0:  80 a6 60 03  cmp  %i1, 3
a00851c4:  18 80 00 03  bgu  0xa00851d0
a00851c8:  82 10 20 00  clr  %g1
a00851cc:  82 10 20 01  mov  1, %g1
a00851d0:  80 88 60 ff  btst  0xff, %g1
a00851d4:  12 80 01 80  bne  0xa00857d4
a00851d8:  9e 1b 60 07  xor  %o5, 7, %o7
a00851dc:  80 a0 00 0f  cmp  %g0, %o7
a00851e0:  b0 60 3f ff  subx  %g0, -1, %i0
a00851e4:  80 8e 20 ff  btst  0xff, %i0
a00851e8:  12 80 01 98  bne  0xa0085848
a00851ec:  23 2a 00 b4  sethi  %hi(0xa802d000), %l1
a00851f0:  f4 14 60 32  lduh  [ %l1 + 0x32 ], %i2	! 0xa802d032
a00851f4:  33 3f ff e0  sethi  %hi(0xffff8000), %i1
a00851f8:  90 0e 80 19  and  %i2, %i1, %o0
a00851fc:  1b 00 00 10  sethi  %hi(0x4000), %o5
a0085200:  82 12 40 0d  or  %o1, %o5, %g1
a0085204:  99 2a 20 10  sll  %o0, 0x10, %o4
a0085208:  80 a3 20 00  cmp  %o4, 0
a008520c:  12 80 01 dc  bne  0xa008597c
a0085210:  c2 32 a3 42  sth  %g1, [ %o2 + 0x342 ]
a0085214:  15 00 00 04  sethi  %hi(0x1000), %o2
a0085218:  b2 12 a3 88  or  %o2, 0x388, %i1	! 0x1388
a008521c:  b0 10 20 0b  mov  0xb, %i0
a0085220:  40 00 05 e4  call  0xa00869b0
a0085224:  81 e8 00 00  restore
a0085228:  03 2a 00 ab  sethi  %hi(0xa802ac00), %g1
a008522c:  da 10 63 42  lduh  [ %g1 + 0x342 ], %o5	! 0xa802af42
a0085230:  19 00 00 08  sethi  %hi(0x2000), %o4
a0085234:  9a 13 40 0c  or  %o5, %o4, %o5
a0085238:  10 80 01 d1  b  0xa008597c
a008523c:  da 30 63 42  sth  %o5, [ %g1 + 0x342 ]
a0085240:  03 2a 00 ab  sethi  %hi(0xa802ac00), %g1
a0085244:  da 10 63 42  lduh  [ %g1 + 0x342 ], %o5	! 0xa802af42
a0085248:  19 00 00 04  sethi  %hi(0x1000), %o4
a008524c:  9a 13 40 0c  or  %o5, %o4, %o5
a0085250:  10 80 01 cb  b  0xa008597c
a0085254:  da 30 63 42  sth  %o5, [ %g1 + 0x342 ]
a0085258:  1b 2a 00 ab  sethi  %hi(0xa802ac00), %o5
a008525c:  d2 13 63 42  lduh  [ %o5 + 0x342 ], %o1	! 0xa802af42
a0085260:  82 12 68 00  or  %o1, 0x800, %g1
a0085264:  10 80 01 c6  b  0xa008597c
a0085268:  c2 33 63 42  sth  %g1, [ %o5 + 0x342 ]
a008526c:  1b 2a 00 ab  sethi  %hi(0xa802ac00), %o5
a0085270:  d0 13 63 42  lduh  [ %o5 + 0x342 ], %o0	! 0xa802af42
a0085274:  82 12 24 00  or  %o0, 0x400, %g1
a0085278:  10 80 01 c1  b  0xa008597c
a008527c:  c2 33 63 42  sth  %g1, [ %o5 + 0x342 ]
a0085280:  11 2a 00 ab  sethi  %hi(0xa802ac00), %o0
a0085284:  d4 12 23 42  lduh  [ %o0 + 0x342 ], %o2	! 0xa802af42
a0085288:  99 2a a0 10  sll  %o2, 0x10, %o4
a008528c:  93 33 20 10  srl  %o4, 0x10, %o1
a0085290:  9b 33 20 1a  srl  %o4, 0x1a, %o5
a0085294:  82 12 40 0d  or  %o1, %o5, %g1
a0085298:  80 88 60 01  btst  1, %g1
a008529c:  02 80 01 b8  be  0xa008597c
a00852a0:  35 2a 00 b4  sethi  %hi(0xa802d000), %i2
a00852a4:  d6 0e a2 af  ldub  [ %i2 + 0x2af ], %o3	! 0xa802d2af
a00852a8:  92 0a e0 ff  and  %o3, 0xff, %o1
a00852ac:  80 a2 60 00  cmp  %o1, 0
a00852b0:  02 80 00 03  be  0xa00852bc
a00852b4:  82 10 20 00  clr  %g1
a00852b8:  82 10 20 01  mov  1, %g1
a00852bc:  80 88 60 ff  btst  0xff, %g1
a00852c0:  12 80 01 2b  bne  0xa008576c
a00852c4:  9e 02 ff fc  add  %o3, -4, %o7
a00852c8:  b0 0b e0 ff  and  %o7, 0xff, %i0
a00852cc:  80 a6 20 03  cmp  %i0, 3
a00852d0:  18 80 00 03  bgu  0xa00852dc
a00852d4:  82 10 20 00  clr  %g1
a00852d8:  82 10 20 01  mov  1, %g1
a00852dc:  80 88 60 ff  btst  0xff, %g1
a00852e0:  12 80 01 42  bne  0xa00857e8
a00852e4:  b4 1a 60 07  xor  %o1, 7, %i2
a00852e8:  80 a0 00 1a  cmp  %g0, %i2
a00852ec:  92 60 3f ff  subx  %g0, -1, %o1
a00852f0:  80 8a 60 ff  btst  0xff, %o1
a00852f4:  12 80 01 44  bne  0xa0085804
a00852f8:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00852fc:  de 10 60 32  lduh  [ %g1 + 0x32 ], %o7	! 0xa802d032
a0085300:  17 3f ff e0  sethi  %hi(0xffff8000), %o3
a0085304:  a0 12 a0 10  or  %o2, 0x10, %l0
a0085308:  b0 0b c0 0b  and  %o7, %o3, %i0
a008530c:  95 2e 20 10  sll  %i0, 0x10, %o2
a0085310:  80 a2 a0 00  cmp  %o2, 0
a0085314:  12 80 01 9a  bne  0xa008597c
a0085318:  e0 32 23 42  sth  %l0, [ %o0 + 0x342 ]
a008531c:  10 bf ff bf  b  0xa0085218
a0085320:  15 00 00 04  sethi  %hi(0x1000), %o2
a0085324:  1b 2a 00 ab  sethi  %hi(0xa802ac00), %o5
a0085328:  d8 13 63 42  lduh  [ %o5 + 0x342 ], %o4	! 0xa802af42
a008532c:  82 13 20 08  or  %o4, 8, %g1
a0085330:  10 80 01 93  b  0xa008597c
a0085334:  c2 33 63 42  sth  %g1, [ %o5 + 0x342 ]
a0085338:  19 2a 00 ab  sethi  %hi(0xa802ac00), %o4
a008533c:  d0 13 23 42  lduh  [ %o4 + 0x342 ], %o0	! 0xa802af42
a0085340:  82 12 22 00  or  %o0, 0x200, %g1
a0085344:  17 00 00 3a  sethi  %hi(0xe800), %o3
a0085348:  c2 33 23 42  sth  %g1, [ %o4 + 0x342 ]
a008534c:  b2 12 e2 60  or  %o3, 0x260, %i1
a0085350:  10 bf ff b4  b  0xa0085220
a0085354:  b0 10 20 0b  mov  0xb, %i0
a0085358:  40 03 0b fe  call  0xa0148350
a008535c:  90 10 20 03  mov  3, %o0
a0085360:  1b 2a 00 ab  sethi  %hi(0xa802ac00), %o5
a0085364:  de 13 63 42  lduh  [ %o5 + 0x342 ], %o7	! 0xa802af42
a0085368:  82 13 e1 00  or  %o7, 0x100, %g1
a008536c:  10 80 01 84  b  0xa008597c
a0085370:  c2 33 63 42  sth  %g1, [ %o5 + 0x342 ]
a0085374:  40 03 0b f7  call  0xa0148350
a0085378:  90 10 20 02  mov  2, %o0
a008537c:  1b 2a 00 ab  sethi  %hi(0xa802ac00), %o5
a0085380:  f0 13 63 42  lduh  [ %o5 + 0x342 ], %i0	! 0xa802af42
a0085384:  82 16 20 80  or  %i0, 0x80, %g1
a0085388:  10 80 01 7d  b  0xa008597c
a008538c:  c2 33 63 42  sth  %g1, [ %o5 + 0x342 ]
a0085390:  40 03 0b f0  call  0xa0148350
a0085394:  90 10 20 01  mov  1, %o0
a0085398:  1b 2a 00 ab  sethi  %hi(0xa802ac00), %o5
a008539c:  e0 13 63 42  lduh  [ %o5 + 0x342 ], %l0	! 0xa802af42
a00853a0:  82 14 20 40  or  %l0, 0x40, %g1
a00853a4:  10 80 01 76  b  0xa008597c
a00853a8:  c2 33 63 42  sth  %g1, [ %o5 + 0x342 ]
a00853ac:  33 2a 00 b4  sethi  %hi(0xa802d000), %i1
a00853b0:  a0 16 62 90  or  %i1, 0x290, %l0	! 0xa802d290
a00853b4:  40 02 fc 92  call  0xa01445fc
a00853b8:  d0 0c 20 1e  ldub  [ %l0 + 0x1e ], %o0
a00853bc:  b4 02 20 01  add  %o0, 1, %i2
a00853c0:  40 02 fc 77  call  0xa014459c
a00853c4:  90 0e a0 ff  and  %i2, 0xff, %o0
a00853c8:  9a 0a 20 ff  and  %o0, 0xff, %o5
a00853cc:  80 a3 60 14  cmp  %o5, 0x14
a00853d0:  08 80 00 58  bleu  0xa0085530
a00853d4:  01 00 00 00  nop
a00853d8:  90 10 20 00  clr  %o0	! 0x0
a00853dc:  40 02 fc 70  call  0xa014459c
a00853e0:  01 00 00 00  nop
a00853e4:  d0 2c 20 1e  stb  %o0, [ %l0 + 0x1e ]
a00853e8:  40 01 4f 94  call  0xa00d9238
a00853ec:  81 e8 00 00  restore
a00853f0:  7f ff f2 ae  call  0xa0081ea8
a00853f4:  91 e8 20 05  restore  %g0, 5, %o0
a00853f8:  a0 10 62 90  or  %g1, 0x290, %l0
a00853fc:  da 0c 20 1f  ldub  [ %l0 + 0x1f ], %o5
a0085400:  80 a3 60 00  cmp  %o5, 0
a0085404:  02 bf fd cf  be  0xa0084b40
a0085408:  b0 10 20 01  mov  1, %i0
a008540c:  40 02 fc 20  call  0xa014448c
a0085410:  90 10 20 01  mov  1, %o0
a0085414:  d0 2c 20 20  stb  %o0, [ %l0 + 0x20 ]
a0085418:  33 00 03 fc  sethi  %hi(0xff000), %i1
a008541c:  40 01 67 55  call  0xa00df170
a0085420:  90 16 62 98  or  %i1, 0x298, %o0	! 0xff298
a0085424:  f4 04 20 a8  ld  [ %l0 + 0xa8 ], %i2
a0085428:  13 00 00 10  sethi  %hi(0x4000), %o1
a008542c:  80 8e 80 09  btst  %i2, %o1
a0085430:  02 80 00 06  be  0xa0085448
a0085434:  90 10 20 01  mov  1, %o0
a0085438:  e2 0c 20 1f  ldub  [ %l0 + 0x1f ], %l1
a008543c:  80 a4 60 00  cmp  %l1, 0
a0085440:  12 80 01 4b  bne  0xa008596c
a0085444:  01 00 00 00  nop
a0085448:  40 00 05 5a  call  0xa00869b0
a008544c:  92 10 23 e8  mov  0x3e8, %o1	! 0x3e8
a0085450:  21 2a 00 ab  sethi  %hi(0xa802ac00), %l0
a0085454:  f0 0c 23 44  ldub  [ %l0 + 0x344 ], %i0	! 0xa802af44
a0085458:  90 16 20 02  or  %i0, 2, %o0
a008545c:  d0 2c 23 44  stb  %o0, [ %l0 + 0x344 ]
a0085460:  10 bf fd b8  b  0xa0084b40
a0085464:  b0 10 20 01  mov  1, %i0
a0085468:  40 02 89 34  call  0xa0127938
a008546c:  90 10 20 03  mov  3, %o0
a0085470:  40 02 89 38  call  0xa0127950
a0085474:  90 10 20 00  clr  %o0
a0085478:  40 02 89 1b  call  0xa01278e4
a008547c:  90 10 20 00  clr  %o0
a0085480:  40 02 89 25  call  0xa0127914
a0085484:  90 10 20 02  mov  2, %o0
a0085488:  10 bf fe ae  b  0xa0084f40
a008548c:  90 10 20 00  clr  %o0
a0085490:  40 02 fb ff  call  0xa014448c
a0085494:  90 10 20 03  mov  3, %o0
a0085498:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a008549c:  b0 13 e2 90  or  %o7, 0x290, %i0	! 0xa802d290
a00854a0:  d0 2e 20 22  stb  %o0, [ %i0 + 0x22 ]
a00854a4:  90 10 20 01  mov  1, %o0
a00854a8:  40 00 05 42  call  0xa00869b0
a00854ac:  92 10 23 e8  mov  0x3e8, %o1
a00854b0:  23 2a 00 ab  sethi  %hi(0xa802ac00), %l1
a00854b4:  d0 0c 63 44  ldub  [ %l1 + 0x344 ], %o0	! 0xa802af44
a00854b8:  a0 12 20 02  or  %o0, 2, %l0
a00854bc:  10 bf fd a0  b  0xa0084b3c
a00854c0:  e0 2c 63 44  stb  %l0, [ %l1 + 0x344 ]
a00854c4:  40 02 fb f2  call  0xa014448c
a00854c8:  90 10 20 02  mov  2, %o0
a00854cc:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00854d0:  82 12 62 90  or  %o1, 0x290, %g1	! 0xa802d290
a00854d4:  d0 28 60 21  stb  %o0, [ %g1 + 0x21 ]
a00854d8:  90 10 20 01  mov  1, %o0
a00854dc:  40 00 05 35  call  0xa00869b0
a00854e0:  92 10 23 e8  mov  0x3e8, %o1
a00854e4:  19 2a 00 ab  sethi  %hi(0xa802ac00), %o4
a00854e8:  da 0b 23 44  ldub  [ %o4 + 0x344 ], %o5	! 0xa802af44
a00854ec:  96 13 60 02  or  %o5, 2, %o3
a00854f0:  d6 2b 23 44  stb  %o3, [ %o4 + 0x344 ]
a00854f4:  10 bf fd 93  b  0xa0084b40
a00854f8:  b0 10 20 02  mov  2, %i0
a00854fc:  40 02 fb e4  call  0xa014448c
a0085500:  90 10 20 00  clr  %o0
a0085504:  40 02 fc 3e  call  0xa01445fc
a0085508:  90 0a 20 ff  and  %o0, 0xff, %o0
a008550c:  1f 00 00 07  sethi  %hi(0x1c00), %o7
a0085510:  80 8a 20 ff  btst  0xff, %o0
a0085514:  02 bf fd ac  be  0xa0084bc4
a0085518:  b0 13 e3 40  or  %o7, 0x340, %i0
a008551c:  15 00 00 06  sethi  %hi(0x1800), %o2
a0085520:  10 bf fd a9  b  0xa0084bc4
a0085524:  b0 12 a1 64  or  %o2, 0x164, %i0	! 0x1964
a0085528:  10 bf fc 3a  b  0xa0084610
a008552c:  90 13 63 c8  or  %o5, 0x3c8, %o0
a0085530:  40 02 fc 33  call  0xa01445fc
a0085534:  d0 0c 20 1e  ldub  [ %l0 + 0x1e ], %o0
a0085538:  a2 02 20 01  add  %o0, 1, %l1
a008553c:  10 bf ff a8  b  0xa00853dc
a0085540:  90 0c 60 ff  and  %l1, 0xff, %o0
a0085544:  10 bf fc a6  b  0xa00847dc
a0085548:  c2 23 22 90  st  %g1, [ %o4 + 0x290 ]
a008554c:  10 bf fc 77  b  0xa0084728
a0085550:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a0085554:  35 00 03 fc  sethi  %hi(0xff000), %i2
a0085558:  40 01 67 06  call  0xa00df170
a008555c:  90 16 a2 b8  or  %i2, 0x2b8, %o0	! 0xff2b8
a0085560:  40 01 3d 04  call  0xa00d4970
a0085564:  01 00 00 00  nop
a0085568:  40 01 4e a5  call  0xa00d8ffc
a008556c:  01 00 00 00  nop
a0085570:  40 02 81 a3  call  0xa0125bfc
a0085574:  01 00 00 00  nop
a0085578:  40 02 88 ea  call  0xa0127920
a008557c:  01 00 00 00  nop
a0085580:  92 0a 20 ff  and  %o0, 0xff, %o1
a0085584:  80 a2 60 01  cmp  %o1, 1
a0085588:  02 80 00 ea  be  0xa0085930
a008558c:  01 00 00 00  nop
a0085590:  40 01 55 56  call  0xa00daae8
a0085594:  01 00 00 00  nop
a0085598:  40 01 55 5c  call  0xa00dab08
a008559c:  01 00 00 00  nop
a00855a0:  40 01 55 60  call  0xa00dab20
a00855a4:  01 00 00 00  nop
a00855a8:  40 01 55 7a  call  0xa00dab90
a00855ac:  01 00 00 00  nop
a00855b0:  40 01 55 86  call  0xa00dabc8
a00855b4:  01 00 00 00  nop
a00855b8:  40 01 55 92  call  0xa00dac00
a00855bc:  01 00 00 00  nop
a00855c0:  40 01 55 2f  call  0xa00daa7c
a00855c4:  01 00 00 00  nop
a00855c8:  40 03 24 c4  call  0xa014e8d8
a00855cc:  01 00 00 00  nop
a00855d0:  a0 0a 20 ff  and  %o0, 0xff, %l0
a00855d4:  80 a4 20 01  cmp  %l0, 1
a00855d8:  12 80 00 e9  bne  0xa008597c
a00855dc:  31 00 03 fc  sethi  %hi(0xff000), %i0
a00855e0:  40 01 66 e4  call  0xa00df170
a00855e4:  90 16 22 d0  or  %i0, 0x2d0, %o0	! 0xff2d0
a00855e8:  40 01 66 e2  call  0xa00df170
a00855ec:  90 16 22 d0  or  %i0, 0x2d0, %o0
a00855f0:  40 01 66 e0  call  0xa00df170
a00855f4:  91 ee 22 d0  restore  %i0, 0x2d0, %o0
a00855f8:  40 02 fb a5  call  0xa014448c
a00855fc:  90 10 20 00  clr  %o0
a0085600:  a0 14 62 90  or  %l1, 0x290, %l0
a0085604:  d0 2c 20 1e  stb  %o0, [ %l0 + 0x1e ]
a0085608:  03 00 03 fc  sethi  %hi(0xff000), %g1
a008560c:  40 01 66 d9  call  0xa00df170
a0085610:  90 10 63 00  or  %g1, 0x300, %o0	! 0xff300
a0085614:  da 04 20 a8  ld  [ %l0 + 0xa8 ], %o5
a0085618:  17 00 00 10  sethi  %hi(0x4000), %o3
a008561c:  80 8b 40 0b  btst  %o5, %o3
a0085620:  02 80 00 06  be  0xa0085638
a0085624:  01 00 00 00  nop
a0085628:  d2 0c 20 1f  ldub  [ %l0 + 0x1f ], %o1
a008562c:  80 a2 60 00  cmp  %o1, 0
a0085630:  12 80 00 05  bne  0xa0085644
a0085634:  90 10 20 01  mov  1, %o0
a0085638:  40 01 3c a5  call  0xa00d48cc
a008563c:  01 00 00 00  nop
a0085640:  90 10 20 01  mov  1, %o0	! 0x1
a0085644:  40 00 04 db  call  0xa00869b0
a0085648:  92 10 23 e8  mov  0x3e8, %o1
a008564c:  21 2a 00 ab  sethi  %hi(0xa802ac00), %l0
a0085650:  f2 0c 23 44  ldub  [ %l0 + 0x344 ], %i1	! 0xa802af44
a0085654:  b4 16 60 02  or  %i1, 2, %i2
a0085658:  10 bf fd 4c  b  0xa0084b88
a008565c:  f4 2c 23 44  stb  %i2, [ %l0 + 0x344 ]
a0085660:  40 00 2e 5e  call  0xa0090fd8
a0085664:  01 00 00 00  nop
a0085668:  10 bf fe 9c  b  0xa00850d8
a008566c:  f2 04 20 b0  ld  [ %l0 + 0xb0 ], %i1
a0085670:  40 03 19 7a  call  0xa014bc58
a0085674:  90 10 20 00  clr  %o0
a0085678:  10 bf fe 9c  b  0xa00850e8
a008567c:  f4 0c 20 1f  ldub  [ %l0 + 0x1f ], %i2
a0085680:  40 02 fb 83  call  0xa014448c
a0085684:  90 10 20 00  clr  %o0
a0085688:  9a 0a 20 ff  and  %o0, 0xff, %o5
a008568c:  80 a3 60 05  cmp  %o5, 5
a0085690:  12 bf fe 1f  bne  0xa0084f0c
a0085694:  01 00 00 00  nop
a0085698:  d0 0c 20 1f  ldub  [ %l0 + 0x1f ], %o0
a008569c:  80 a2 20 00  cmp  %o0, 0
a00856a0:  12 bf fe 1b  bne  0xa0084f0c
a00856a4:  01 00 00 00  nop
a00856a8:  40 03 08 61  call  0xa014782c
a00856ac:  90 10 20 01  mov  1, %o0	! 0x1
a00856b0:  30 bf fe 17  b,a   0xa0084f0c
a00856b4:  40 02 ff eb  call  0xa0145660
a00856b8:  90 10 20 00  clr  %o0
a00856bc:  a0 10 00 08  mov  %o0, %l0
a00856c0:  40 03 0b 2f  call  0xa014837c
a00856c4:  90 10 20 00  clr  %o0
a00856c8:  83 2c 20 10  sll  %l0, 0x10, %g1
a00856cc:  91 2a 20 10  sll  %o0, 0x10, %o0
a00856d0:  80 a2 00 01  cmp  %o0, %g1
a00856d4:  12 bf fc 5e  bne  0xa008484c
a00856d8:  92 10 20 07  mov  7, %o1
a00856dc:  92 10 20 08  mov  8, %o1
a00856e0:  40 02 ff e0  call  0xa0145660
a00856e4:  90 10 20 00  clr  %o0
a00856e8:  b2 10 00 08  mov  %o0, %i1
a00856ec:  40 03 0b 24  call  0xa014837c
a00856f0:  90 10 20 01  mov  1, %o0
a00856f4:  93 2e 60 10  sll  %i1, 0x10, %o1
a00856f8:  9f 2a 20 10  sll  %o0, 0x10, %o7
a00856fc:  80 a3 c0 09  cmp  %o7, %o1
a0085700:  12 bf fc 53  bne  0xa008484c
a0085704:  92 10 20 07  mov  7, %o1
a0085708:  d4 0c 61 a4  ldub  [ %l1 + 0x1a4 ], %o2
a008570c:  80 a2 a0 04  cmp  %o2, 4
a0085710:  12 bf fc 4f  bne  0xa008484c
a0085714:  01 00 00 00  nop
a0085718:  40 01 52 cf  call  0xa00da254
a008571c:  c0 2c 61 a4  clrb  [ %l1 + 0x1a4 ]
a0085720:  23 2a 00 ab  sethi  %hi(0xa802ac00), %l1
a0085724:  f4 0c 63 44  ldub  [ %l1 + 0x344 ], %i2	! 0xa802af44
a0085728:  98 16 a0 02  or  %i2, 2, %o4
a008572c:  10 bf fc 47  b  0xa0084848
a0085730:  d8 2c 63 44  stb  %o4, [ %l1 + 0x344 ]
a0085734:  19 00 00 04  sethi  %hi(0x1000), %o4
a0085738:  92 13 23 88  or  %o4, 0x388, %o1	! 0x1388
a008573c:  40 00 04 9d  call  0xa00869b0
a0085740:  90 10 20 04  mov  4, %o0
a0085744:  10 bf fe 5d  b  0xa00850b8
a0085748:  21 00 03 fc  sethi  %hi(0xff000), %l0
a008574c:  80 8b 28 00  btst  0x800, %o4
a0085750:  02 80 00 8b  be  0xa008597c
a0085754:  b2 0c 60 ff  and  %l1, 0xff, %i1
a0085758:  30 bf fe 9a  b,a   0xa00851c0
a008575c:  40 03 1f 46  call  0xa014d474
a0085760:  92 10 20 00  clr  %o1
a0085764:  10 bf fe 68  b  0xa0085104
a0085768:  98 14 62 90  or  %l1, 0x290, %o4
a008576c:  a3 33 20 11  srl  %o4, 0x11, %l1
a0085770:  a1 33 20 1b  srl  %o4, 0x1b, %l0
a0085774:  b2 14 40 10  or  %l1, %l0, %i1
a0085778:  80 8e 60 01  btst  1, %i1
a008577c:  02 80 00 80  be  0xa008597c
a0085780:  b0 0b e0 ff  and  %o7, 0xff, %i0
a0085784:  30 bf fe d2  b,a   0xa00852cc
a0085788:  b4 08 7f bf  and  %g1, -65, %i2
a008578c:  33 00 03 fc  sethi  %hi(0xff000), %i1
a0085790:  f4 33 60 06  sth  %i2, [ %o5 + 6 ]
a0085794:  40 01 66 77  call  0xa00df170
a0085798:  90 16 61 f8  or  %i1, 0x1f8, %o0
a008579c:  40 02 7c e9  call  0xa0124b40
a00857a0:  01 00 00 00  nop
a00857a4:  40 02 7c b1  call  0xa0124a68
a00857a8:  01 00 00 00  nop
a00857ac:  40 03 0c bf  call  0xa0148aa8
a00857b0:  90 10 20 01  mov  1, %o0	! 0x1
a00857b4:  40 00 04 cd  call  0xa0086ae8
a00857b8:  90 10 20 02  mov  2, %o0
a00857bc:  10 bf fb e6  b  0xa0084754
a00857c0:  13 2a 00 b8  sethi  %hi(0xa802e000), %o1
a00857c4:  40 01 57 dd  call  0xa00db738
a00857c8:  01 00 00 00  nop
a00857cc:  10 bf fd 90  b  0xa0084e0c
a00857d0:  98 16 a2 90  or  %i2, 0x290, %o4
a00857d4:  21 00 00 04  sethi  %hi(0x1000), %l0
a00857d8:  80 8b 00 10  btst  %o4, %l0
a00857dc:  02 80 00 68  be  0xa008597c
a00857e0:  80 a0 00 0f  cmp  %g0, %o7
a00857e4:  30 bf fe 7f  b,a   0xa00851e0
a00857e8:  83 33 20 12  srl  %o4, 0x12, %g1
a00857ec:  9b 33 20 1c  srl  %o4, 0x1c, %o5
a00857f0:  96 10 40 0d  or  %g1, %o5, %o3
a00857f4:  80 8a e0 01  btst  1, %o3
a00857f8:  02 80 00 61  be  0xa008597c
a00857fc:  80 a0 00 1a  cmp  %g0, %i2
a0085800:  30 bf fe bb  b,a   0xa00852ec
a0085804:  a3 33 20 1d  srl  %o4, 0x1d, %l1
a0085808:  b3 33 20 13  srl  %o4, 0x13, %i1
a008580c:  98 16 40 11  or  %i1, %l1, %o4
a0085810:  80 8b 20 01  btst  1, %o4
a0085814:  02 80 00 5a  be  0xa008597c
a0085818:  de 10 60 32  lduh  [ %g1 + 0x32 ], %o7
a008581c:  30 bf fe b9  b,a   0xa0085300
a0085820:  40 02 fb 1b  call  0xa014448c
a0085824:  90 10 20 00  clr  %o0
a0085828:  40 02 fb 75  call  0xa01445fc
a008582c:  90 0a 20 ff  and  %o0, 0xff, %o0
a0085830:  80 8a 20 ff  btst  0xff, %o0
a0085834:  12 bf fe 13  bne  0xa0085080
a0085838:  98 14 62 90  or  %l1, 0x290, %o4
a008583c:  11 00 00 07  sethi  %hi(0x1c00), %o0
a0085840:  10 bf fe 1c  b  0xa00850b0
a0085844:  90 12 23 40  or  %o0, 0x340, %o0	! 0x1f40
a0085848:  17 00 00 08  sethi  %hi(0x2000), %o3
a008584c:  80 8b 00 0b  btst  %o4, %o3
a0085850:  02 80 00 4b  be  0xa008597c
a0085854:  f4 14 60 32  lduh  [ %l1 + 0x32 ], %i2
a0085858:  30 bf fe 67  b,a   0xa00851f4
a008585c:  40 01 41 1f  call  0xa00d5cd8
a0085860:  01 00 00 00  nop
a0085864:  30 bf fd 1f  b,a   0xa0084ce0
a0085868:  40 02 7c b6  call  0xa0124b40
a008586c:  01 00 00 00  nop
a0085870:  40 02 7c 7e  call  0xa0124a68
a0085874:  01 00 00 00  nop
a0085878:  e0 04 60 ac  ld  [ %l1 + 0xac ], %l0
a008587c:  1b 00 00 80  sethi  %hi(0x20000), %o5
a0085880:  96 14 00 0d  or  %l0, %o5, %o3
a0085884:  10 bf fc ee  b  0xa0084c3c
a0085888:  d6 24 60 ac  st  %o3, [ %l1 + 0xac ]
a008588c:  40 01 57 ab  call  0xa00db738
a0085890:  01 00 00 00  nop
a0085894:  10 bf fd 0e  b  0xa0084ccc
a0085898:  82 14 22 90  or  %l0, 0x290, %g1
a008589c:  b2 12 20 80  or  %o0, 0x80, %i1
a00858a0:  10 bf fc f2  b  0xa0084c68
a00858a4:  f2 24 61 ec  st  %i1, [ %l1 + 0x1ec ]
a00858a8:  90 0e 60 ff  and  %i1, 0xff, %o0
a00858ac:  80 a2 20 01  cmp  %o0, 1
a00858b0:  18 bf fc 41  bgu  0xa00849b4
a00858b4:  a2 16 22 90  or  %i0, 0x290, %l1
a00858b8:  90 10 20 00  clr  %o0
a00858bc:  10 bf fc 45  b  0xa00849d0
a00858c0:  92 10 20 01  mov  1, %o1
a00858c4:  40 02 fa f2  call  0xa014448c
a00858c8:  90 10 20 00  clr  %o0
a00858cc:  40 02 fb 4c  call  0xa01445fc
a00858d0:  90 0a 20 ff  and  %o0, 0xff, %o0
a00858d4:  80 8a 20 ff  btst  0xff, %o0
a00858d8:  32 bf fb 95  bne,a   0xa008472c
a00858dc:  b4 14 22 90  or  %l0, 0x290, %i2
a00858e0:  15 2a 00 90  sethi  %hi(0xa8024000), %o2
a00858e4:  17 2a 00 90  sethi  %hi(0xa8024000), %o3
a00858e8:  9e 10 3f ff  mov  -1, %o7
a00858ec:  b0 12 e0 18  or  %o3, 0x18, %i0
a00858f0:  98 12 a0 10  or  %o2, 0x10, %o4
a00858f4:  de 2a e0 18  stb  %o7, [ %o3 + 0x18 ]
a00858f8:  de 2b 20 01  stb  %o7, [ %o4 + 1 ]
a00858fc:  de 2a a0 10  stb  %o7, [ %o2 + 0x10 ]
a0085900:  de 2e 20 01  stb  %o7, [ %i0 + 1 ]
a0085904:  de 2b 20 03  stb  %o7, [ %o4 + 3 ]
a0085908:  de 2b 20 02  stb  %o7, [ %o4 + 2 ]
a008590c:  de 2e 20 04  stb  %o7, [ %i0 + 4 ]
a0085910:  de 2e 20 03  stb  %o7, [ %i0 + 3 ]
a0085914:  de 2e 20 02  stb  %o7, [ %i0 + 2 ]
a0085918:  40 03 07 c5  call  0xa014782c
a008591c:  90 10 20 05  mov  5, %o0
a0085920:  40 03 07 c3  call  0xa014782c
a0085924:  90 10 20 07  mov  7, %o0
a0085928:  10 bf fb 81  b  0xa008472c
a008592c:  b4 14 22 90  or  %l0, 0x290, %i2
a0085930:  40 02 87 ff  call  0xa012792c
a0085934:  01 00 00 00  nop
a0085938:  b2 0a 20 ff  and  %o0, 0xff, %i1
a008593c:  80 a6 60 02  cmp  %i1, 2
a0085940:  02 80 00 08  be  0xa0085960
a0085944:  01 00 00 00  nop
a0085948:  40 02 87 f9  call  0xa012792c
a008594c:  01 00 00 00  nop
a0085950:  a2 0a 20 ff  and  %o0, 0xff, %l1
a0085954:  80 a4 60 01  cmp  %l1, 1
a0085958:  12 bf ff 0e  bne  0xa0085590
a008595c:  01 00 00 00  nop
a0085960:  40 02 87 ed  call  0xa0127914
a0085964:  90 10 20 00  clr  %o0	! 0x0
a0085968:  30 bf ff 0a  b,a   0xa0085590
a008596c:  40 01 3b d8  call  0xa00d48cc
a0085970:  01 00 00 00  nop
a0085974:  10 bf fe b5  b  0xa0085448
a0085978:  90 10 20 01  mov  1, %o0	! 0x1
a008597c:  81 c7 e0 08  ret
a0085980:  81 e8 00 00  restore
