# leon2s FUN_a00d0550 0xa00d0550-0xa00d0798 (584 bytes)  [FUN_a00d0790 = unreachable ret/restore tail, merged]
a00d0550:  9d e3 bf 98  save  %sp, -104, %sp
a00d0554:  7f ff fd 73  call  0xa00cfb20
a00d0558:  90 10 20 0a  mov  0xa, %o0
a00d055c:  80 a2 20 00  cmp  %o0, 0
a00d0560:  02 80 00 04  be  0xa00d0570
a00d0564:  a2 10 00 18  mov  %i0, %l1
a00d0568:  10 80 00 2b  b  0xa00d0614
a00d056c:  82 0e 20 ff  and  %i0, 0xff, %g1
a00d0570:  19 2a 01 f5  sethi  %hi(0xa807d400), %o4
a00d0574:  da 0b 22 36  ldub  [ %o4 + 0x236 ], %o5	! 0xa807d636
a00d0578:  80 a3 60 ff  cmp  %o5, 0xff
a00d057c:  02 80 00 05  be  0xa00d0590
a00d0580:  82 0e 20 ff  and  %i0, 0xff, %g1
a00d0584:  80 a3 40 01  cmp  %o5, %g1
a00d0588:  32 80 00 24  bne,a   0xa00d0618
a00d058c:  98 00 40 01  add  %g1, %g1, %o4
a00d0590:  a0 0c 60 ff  and  %l1, 0xff, %l0
a00d0594:  82 04 00 10  add  %l0, %l0, %g1
a00d0598:  82 00 40 10  add  %g1, %l0, %g1
a00d059c:  25 2a 01 e2  sethi  %hi(0xa8078800), %l2
a00d05a0:  9a 14 a3 b0  or  %l2, 0x3b0, %o5	! 0xa8078bb0
a00d05a4:  83 28 60 03  sll  %g1, 3, %g1
a00d05a8:  82 00 40 0d  add  %g1, %o5, %g1
a00d05ac:  9a 10 20 03  mov  3, %o5
a00d05b0:  da 28 60 09  stb  %o5, [ %g1 + 9 ]
a00d05b4:  1b 33 c0 63  sethi  %hi(0xcf018c00), %o5
a00d05b8:  9a 13 61 00  or  %o5, 0x100, %o5	! 0xcf018d00
a00d05bc:  c0 20 60 10  clr  [ %g1 + 0x10 ]
a00d05c0:  c0 20 60 0c  clr  [ %g1 + 0xc ]
a00d05c4:  c2 03 40 00  ld  [ %o5 ], %g1
a00d05c8:  82 08 7f fc  and  %g1, -4, %g1
a00d05cc:  f0 2b 22 36  stb  %i0, [ %o4 + 0x236 ]
a00d05d0:  c2 23 40 00  st  %g1, [ %o5 ]
a00d05d4:  92 10 20 04  mov  4, %o1
a00d05d8:  94 10 20 17  mov  0x17, %o2
a00d05dc:  7f ff dc 1e  call  0xa00c7654
a00d05e0:  90 10 00 10  mov  %l0, %o0
a00d05e4:  40 3b c4 0a  call  0xa0fc160c
a00d05e8:  90 10 20 01  mov  1, %o0
a00d05ec:  90 10 00 10  mov  %l0, %o0
a00d05f0:  92 10 20 04  mov  4, %o1
a00d05f4:  7f ff dc 18  call  0xa00c7654
a00d05f8:  94 10 20 11  mov  0x11, %o2
a00d05fc:  90 10 00 10  mov  %l0, %o0
a00d0600:  92 10 20 11  mov  0x11, %o1
a00d0604:  7f ff e0 79  call  0xa00c87e8
a00d0608:  15 00 00 20  sethi  %hi(0x8000), %o2
a00d060c:  10 80 00 0e  b  0xa00d0644
a00d0610:  b2 10 20 00  clr  %i1
a00d0614:  98 00 40 01  add  %g1, %g1, %o4
a00d0618:  98 03 00 01  add  %o4, %g1, %o4
a00d061c:  17 2a 01 e2  sethi  %hi(0xa8078800), %o3
a00d0620:  96 12 e3 b0  or  %o3, 0x3b0, %o3	! 0xa8078bb0
a00d0624:  99 2b 20 03  sll  %o4, 3, %o4
a00d0628:  c2 02 c0 0c  ld  [ %o3 + %o4 ], %g1
a00d062c:  1b 00 00 c0  sethi  %hi(0x30000), %o5
a00d0630:  82 10 40 0d  or  %g1, %o5, %g1
a00d0634:  10 80 00 56  b  0xa00d078c
a00d0638:  c2 22 c0 0c  st  %g1, [ %o3 + %o4 ]
a00d063c:  7f ff dc 06  call  0xa00c7654
a00d0640:  01 00 00 00  nop
a00d0644:  83 2e 60 10  sll  %i1, 0x10, %g1
a00d0648:  83 30 60 10  srl  %g1, 0x10, %g1
a00d064c:  90 10 00 10  mov  %l0, %o0
a00d0650:  92 10 20 01  mov  1, %o1
a00d0654:  94 10 20 00  clr  %o2
a00d0658:  80 a0 60 17  cmp  %g1, 0x17
a00d065c:  08 bf ff f8  bleu  0xa00d063c
a00d0660:  b2 06 60 01  inc  %i1
a00d0664:  b2 10 20 00  clr  %i1
a00d0668:  9b 2e 60 10  sll  %i1, 0x10, %o5
a00d066c:  03 2a 01 f5  sethi  %hi(0xa807d400), %g1
a00d0670:  9b 33 60 10  srl  %o5, 0x10, %o5
a00d0674:  82 10 62 38  or  %g1, 0x238, %g1
a00d0678:  a0 0c 60 ff  and  %l1, 0xff, %l0
a00d067c:  d4 08 40 0d  ldub  [ %g1 + %o5 ], %o2
a00d0680:  90 10 00 10  mov  %l0, %o0
a00d0684:  7f ff db f4  call  0xa00c7654
a00d0688:  92 10 20 01  mov  1, %o1
a00d068c:  9a 06 60 01  add  %i1, 1, %o5
a00d0690:  83 2b 60 10  sll  %o5, 0x10, %g1
a00d0694:  83 30 60 10  srl  %g1, 0x10, %g1
a00d0698:  80 a0 60 0f  cmp  %g1, 0xf
a00d069c:  08 bf ff f3  bleu  0xa00d0668
a00d06a0:  b2 10 00 0d  mov  %o5, %i1
a00d06a4:  31 2a 01 f3  sethi  %hi(0xa807cc00), %i0
a00d06a8:  82 10 20 01  mov  1, %g1
a00d06ac:  c2 2e 22 50  stb  %g1, [ %i0 + 0x250 ]
a00d06b0:  9a 16 22 50  or  %i0, 0x250, %o5
a00d06b4:  82 10 20 03  mov  3, %g1
a00d06b8:  c2 2b 60 02  stb  %g1, [ %o5 + 2 ]
a00d06bc:  82 10 20 04  mov  4, %g1
a00d06c0:  c2 2b 60 03  stb  %g1, [ %o5 + 3 ]
a00d06c4:  82 10 20 05  mov  5, %g1
a00d06c8:  c2 2b 60 04  stb  %g1, [ %o5 + 4 ]
a00d06cc:  82 10 20 06  mov  6, %g1
a00d06d0:  c2 2b 60 05  stb  %g1, [ %o5 + 5 ]
a00d06d4:  82 10 20 07  mov  7, %g1
a00d06d8:  c2 2b 60 06  stb  %g1, [ %o5 + 6 ]
a00d06dc:  98 10 20 02  mov  2, %o4
a00d06e0:  82 10 20 08  mov  8, %g1
a00d06e4:  c2 2b 60 07  stb  %g1, [ %o5 + 7 ]
a00d06e8:  d8 2b 60 08  stb  %o4, [ %o5 + 8 ]
a00d06ec:  c0 2b 60 0a  clrb  [ %o5 + 0xa ]
a00d06f0:  d8 2b 60 01  stb  %o4, [ %o5 + 1 ]
a00d06f4:  c0 2b 60 09  clrb  [ %o5 + 9 ]
a00d06f8:  90 10 00 10  mov  %l0, %o0
a00d06fc:  92 10 20 01  mov  1, %o1
a00d0700:  7f ff e0 3a  call  0xa00c87e8
a00d0704:  15 00 00 20  sethi  %hi(0x8000), %o2
a00d0708:  b2 10 20 00  clr  %i1
a00d070c:  83 2e 60 10  sll  %i1, 0x10, %g1
a00d0710:  83 30 60 10  srl  %g1, 0x10, %g1
a00d0714:  a2 16 22 50  or  %i0, 0x250, %l1
a00d0718:  d4 0c 40 01  ldub  [ %l1 + %g1 ], %o2
a00d071c:  90 10 00 10  mov  %l0, %o0
a00d0720:  7f ff db cd  call  0xa00c7654
a00d0724:  92 10 20 01  mov  1, %o1
a00d0728:  9a 06 60 01  add  %i1, 1, %o5
a00d072c:  83 2b 60 10  sll  %o5, 0x10, %g1
a00d0730:  83 30 60 10  srl  %g1, 0x10, %g1
a00d0734:  80 a0 60 0a  cmp  %g1, 0xa
a00d0738:  08 bf ff f5  bleu  0xa00d070c
a00d073c:  b2 10 00 0d  mov  %o5, %i1
a00d0740:  98 10 00 11  mov  %l1, %o4
a00d0744:  96 10 20 0a  mov  0xa, %o3
a00d0748:  90 10 20 00  clr  %o0
a00d074c:  92 10 20 80  mov  0x80, %o1
a00d0750:  40 3b 17 21  call  0xa0f963d4
a00d0754:  15 00 01 a4  sethi  %hi(0x69000), %o2
a00d0758:  98 04 00 10  add  %l0, %l0, %o4
a00d075c:  98 03 00 10  add  %o4, %l0, %o4
a00d0760:  96 14 a3 b0  or  %l2, 0x3b0, %o3
a00d0764:  99 2b 20 03  sll  %o4, 3, %o4
a00d0768:  da 02 c0 0c  ld  [ %o3 + %o4 ], %o5
a00d076c:  03 00 00 c0  sethi  %hi(0x30000), %g1
a00d0770:  82 2b 40 01  andn  %o5, %g1, %g1
a00d0774:  1b 00 00 40  sethi  %hi(0x10000), %o5
a00d0778:  82 10 40 0d  or  %g1, %o5, %g1
a00d077c:  c2 22 c0 0c  st  %g1, [ %o3 + %o4 ]
a00d0780:  b0 10 20 0a  mov  0xa, %i0
a00d0784:  7f ff ff 6b  call  0xa00d0530
a00d0788:  93 e8 20 64  restore  %g0, 0x64, %o1
a00d078c:  01 00 00 00  nop
a00d0790:  81 c7 e0 08  ret
a00d0794:  81 e8 00 00  restore
