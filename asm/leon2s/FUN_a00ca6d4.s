# leon2s FUN_a00ca6d4 0xa00ca6d4-0xa00ca8c4 (496 bytes)
a00ca6d4:  9d e3 bf 98  save  %sp, -104, %sp
a00ca6d8:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00ca6dc:  90 10 00 18  mov  %i0, %o0
a00ca6e0:  92 10 20 05  mov  5, %o1
a00ca6e4:  94 10 20 01  mov  1, %o2
a00ca6e8:  7f ff f3 f6  call  0xa00c76c0
a00ca6ec:  96 10 20 01  mov  1, %o3
a00ca6f0:  90 10 00 18  mov  %i0, %o0
a00ca6f4:  92 10 20 05  mov  5, %o1
a00ca6f8:  94 10 20 02  mov  2, %o2
a00ca6fc:  7f ff f3 f1  call  0xa00c76c0
a00ca700:  96 10 20 01  mov  1, %o3
a00ca704:  90 10 00 18  mov  %i0, %o0
a00ca708:  92 10 20 0f  mov  0xf, %o1
a00ca70c:  7f ff f8 37  call  0xa00c87e8
a00ca710:  15 00 00 20  sethi  %hi(0x8000), %o2
a00ca714:  a2 10 20 00  clr  %l1
a00ca718:  1b 27 c7 07  sethi  %hi(0x9f1c1c00), %o5
a00ca71c:  82 0c 60 ff  and  %l1, 0xff, %g1
a00ca720:  98 13 62 48  or  %o5, 0x248, %o4
a00ca724:  90 10 00 18  mov  %i0, %o0
a00ca728:  92 10 20 12  mov  0x12, %o1
a00ca72c:  80 a6 20 02  cmp  %i0, 2
a00ca730:  a0 04 60 01  add  %l1, 1, %l0
a00ca734:  02 80 00 04  be  0xa00ca744
a00ca738:  98 00 40 0c  add  %g1, %o4, %o4
a00ca73c:  10 80 00 05  b  0xa00ca750
a00ca740:  d4 0b 20 4f  ldub  [ %o4 + 0x4f ], %o2
a00ca744:  d4 0b 20 4f  ldub  [ %o4 + 0x4f ], %o2
a00ca748:  90 10 20 02  mov  2, %o0
a00ca74c:  92 10 20 01  mov  1, %o1
a00ca750:  7f ff f3 c1  call  0xa00c7654
a00ca754:  a2 10 00 10  mov  %l0, %l1
a00ca758:  82 0c 20 ff  and  %l0, 0xff, %g1
a00ca75c:  80 a0 60 0f  cmp  %g1, 0xf
a00ca760:  08 bf ff ef  bleu  0xa00ca71c
a00ca764:  1b 27 c7 07  sethi  %hi(0x9f1c1c00), %o5
a00ca768:  90 10 00 18  mov  %i0, %o0
a00ca76c:  92 10 20 01  mov  1, %o1
a00ca770:  7f ff f8 1e  call  0xa00c87e8
a00ca774:  15 00 00 20  sethi  %hi(0x8000), %o2
a00ca778:  a2 10 20 00  clr  %l1
a00ca77c:  a2 04 60 01  inc  %l1
a00ca780:  82 0c 60 ff  and  %l1, 0xff, %g1
a00ca784:  80 a0 60 0a  cmp  %g1, 0xa
a00ca788:  08 bf ff fe  bleu  0xa00ca780
a00ca78c:  a2 04 60 01  inc  %l1
a00ca790:  90 10 00 18  mov  %i0, %o0
a00ca794:  92 10 20 03  mov  3, %o1
a00ca798:  7f ff f8 14  call  0xa00c87e8
a00ca79c:  15 00 00 20  sethi  %hi(0x8000), %o2
a00ca7a0:  a2 10 20 00  clr  %l1
a00ca7a4:  a2 04 60 01  inc  %l1
a00ca7a8:  82 0c 60 ff  and  %l1, 0xff, %g1
a00ca7ac:  80 a0 60 0a  cmp  %g1, 0xa
a00ca7b0:  08 bf ff fe  bleu  0xa00ca7a8
a00ca7b4:  a2 04 60 01  inc  %l1
a00ca7b8:  90 10 00 18  mov  %i0, %o0
a00ca7bc:  92 10 20 0f  mov  0xf, %o1
a00ca7c0:  7f ff f8 0a  call  0xa00c87e8
a00ca7c4:  15 00 00 20  sethi  %hi(0x8000), %o2
a00ca7c8:  a2 10 20 00  clr  %l1
a00ca7cc:  a2 04 60 01  inc  %l1
a00ca7d0:  82 0c 60 ff  and  %l1, 0xff, %g1
a00ca7d4:  80 a0 60 0f  cmp  %g1, 0xf
a00ca7d8:  28 bf ff fe  bleu,a   0xa00ca7d0
a00ca7dc:  a2 04 60 01  inc  %l1
a00ca7e0:  90 10 00 18  mov  %i0, %o0
a00ca7e4:  92 10 20 08  mov  8, %o1
a00ca7e8:  94 10 20 03  mov  3, %o2
a00ca7ec:  7f ff f3 b5  call  0xa00c76c0
a00ca7f0:  96 10 20 01  mov  1, %o3
a00ca7f4:  90 10 00 18  mov  %i0, %o0
a00ca7f8:  92 10 20 06  mov  6, %o1
a00ca7fc:  7f ff f3 96  call  0xa00c7654
a00ca800:  94 10 20 08  mov  8, %o2
a00ca804:  10 80 00 07  b  0xa00ca820
a00ca808:  a0 10 3f ff  mov  -1, %l0
a00ca80c:  80 8c 20 ff  btst  0xff, %l0
a00ca810:  12 80 00 05  bne  0xa00ca824
a00ca814:  90 10 00 18  mov  %i0, %o0
a00ca818:  10 80 00 29  b  0xa00ca8bc
a00ca81c:  b0 10 20 01  mov  1, %i0
a00ca820:  90 10 00 18  mov  %i0, %o0
a00ca824:  7f ff f3 d3  call  0xa00c7770
a00ca828:  92 10 20 08  mov  8, %o1
a00ca82c:  80 8a 20 03  btst  3, %o0
a00ca830:  02 bf ff f7  be  0xa00ca80c
a00ca834:  a0 04 3f ff  add  %l0, -1, %l0
a00ca838:  90 10 00 18  mov  %i0, %o0
a00ca83c:  92 10 20 10  mov  0x10, %o1
a00ca840:  7f ff f7 ea  call  0xa00c87e8
a00ca844:  15 00 00 20  sethi  %hi(0x8000), %o2
a00ca848:  a2 10 20 00  clr  %l1
a00ca84c:  a2 04 60 01  inc  %l1
a00ca850:  82 0c 60 ff  and  %l1, 0xff, %g1
a00ca854:  80 a0 60 1f  cmp  %g1, 0x1f
a00ca858:  08 bf ff fe  bleu  0xa00ca850
a00ca85c:  a2 04 60 01  inc  %l1
a00ca860:  90 10 00 18  mov  %i0, %o0
a00ca864:  92 10 20 06  mov  6, %o1
a00ca868:  7f ff f7 e0  call  0xa00c87e8
a00ca86c:  15 00 00 20  sethi  %hi(0x8000), %o2
a00ca870:  a2 10 20 00  clr  %l1
a00ca874:  90 10 00 18  mov  %i0, %o0
a00ca878:  7f ff f3 be  call  0xa00c7770
a00ca87c:  92 10 20 01  mov  1, %o1
a00ca880:  a0 0c 60 ff  and  %l1, 0xff, %l0
a00ca884:  a2 04 60 01  inc  %l1
a00ca888:  03 2a 01 f4  sethi  %hi(0xa807d000), %g1
a00ca88c:  9a 0c 60 ff  and  %l1, 0xff, %o5
a00ca890:  82 10 60 88  or  %g1, 0x88, %g1
a00ca894:  80 a3 60 1f  cmp  %o5, 0x1f
a00ca898:  08 bf ff f7  bleu  0xa00ca874
a00ca89c:  d0 28 40 10  stb  %o0, [ %g1 + %l0 ]
a00ca8a0:  a2 10 20 00  clr  %l1
a00ca8a4:  a2 04 60 01  inc  %l1
a00ca8a8:  82 0c 60 ff  and  %l1, 0xff, %g1
a00ca8ac:  80 a0 60 1f  cmp  %g1, 0x1f
a00ca8b0:  28 bf ff fe  bleu,a   0xa00ca8a8
a00ca8b4:  a2 04 60 01  inc  %l1
a00ca8b8:  b0 10 20 00  clr  %i0
a00ca8bc:  81 c7 e0 08  ret
a00ca8c0:  81 e8 00 00  restore
