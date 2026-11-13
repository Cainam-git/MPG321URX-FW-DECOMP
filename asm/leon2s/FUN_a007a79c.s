# leon2s FUN_a007a79c 0xa007a79c-0xa007a9c0 (548 bytes)
a007a79c:  9d e3 bf 98  save  %sp, -104, %sp
a007a7a0:  b0 0e 20 ff  and  %i0, 0xff, %i0
a007a7a4:  b8 10 20 00  clr  %i4
a007a7a8:  7f ff ff d8  call  0xa007a708
a007a7ac:  90 10 00 18  mov  %i0, %o0
a007a7b0:  37 28 02 ce  sethi  %hi(0xa00b3800), %i3
a007a7b4:  a0 07 00 1c  add  %i4, %i4, %l0
a007a7b8:  82 16 e3 18  or  %i3, 0x318, %g1
a007a7bc:  d6 10 40 10  lduh  [ %g1 + %l0 ], %o3
a007a7c0:  90 10 20 00  clr  %o0
a007a7c4:  94 10 00 18  mov  %i0, %o2
a007a7c8:  40 00 b3 17  call  0xa00a7424
a007a7cc:  92 10 20 07  mov  7, %o1
a007a7d0:  80 a7 20 03  cmp  %i4, 3
a007a7d4:  15 00 3f ff  sethi  %hi(0xfffc00), %o2
a007a7d8:  b8 07 20 01  inc  %i4
a007a7dc:  94 12 a3 ff  or  %o2, 0x3ff, %o2
a007a7e0:  90 10 00 18  mov  %i0, %o0
a007a7e4:  14 80 00 06  bg  0xa007a7fc
a007a7e8:  17 06 00 00  sethi  %hi(0x18000000), %o3
a007a7ec:  03 28 02 ce  sethi  %hi(0xa00b3800), %g1
a007a7f0:  82 10 63 10  or  %g1, 0x310, %g1	! 0xa00b3b10
a007a7f4:  40 00 b3 25  call  0xa00a7488
a007a7f8:  d2 10 40 10  lduh  [ %g1 + %l0 ], %o1
a007a7fc:  80 a7 20 03  cmp  %i4, 3
a007a800:  24 bf ff ed  ble,a   0xa007a7b4
a007a804:  37 28 02 ce  sethi  %hi(0xa00b3800), %i3
a007a808:  b8 10 20 00  clr  %i4
a007a80c:  82 0e 60 ff  and  %i1, 0xff, %g1
a007a810:  83 38 40 1c  sra  %g1, %i4, %g1
a007a814:  80 88 60 01  btst  1, %g1
a007a818:  22 80 00 65  be,a   0xa007a9ac
a007a81c:  b8 07 20 01  inc  %i4
a007a820:  80 a7 20 03  cmp  %i4, 3
a007a824:  34 80 00 62  bg,a   0xa007a9ac
a007a828:  b8 07 20 01  inc  %i4
a007a82c:  a0 07 00 1c  add  %i4, %i4, %l0
a007a830:  82 16 e3 18  or  %i3, 0x318, %g1
a007a834:  d6 10 40 10  lduh  [ %g1 + %l0 ], %o3
a007a838:  90 10 20 00  clr  %o0
a007a83c:  92 10 20 07  mov  7, %o1
a007a840:  40 00 b2 f9  call  0xa00a7424
a007a844:  94 10 00 18  mov  %i0, %o2
a007a848:  03 28 02 ce  sethi  %hi(0xa00b3800), %g1
a007a84c:  29 00 3f ff  sethi  %hi(0xfffc00), %l4
a007a850:  82 10 63 10  or  %g1, 0x310, %g1
a007a854:  d2 10 40 10  lduh  [ %g1 + %l0 ], %o1
a007a858:  90 10 00 18  mov  %i0, %o0
a007a85c:  94 15 23 ff  or  %l4, 0x3ff, %o2
a007a860:  40 00 b3 0a  call  0xa00a7488
a007a864:  17 06 00 00  sethi  %hi(0x18000000), %o3
a007a868:  03 28 02 ce  sethi  %hi(0xa00b3800), %g1
a007a86c:  82 10 63 40  or  %g1, 0x340, %g1	! 0xa00b3b40
a007a870:  fa 10 40 10  lduh  [ %g1 + %l0 ], %i5
a007a874:  90 10 00 18  mov  %i0, %o0
a007a878:  92 10 00 1d  mov  %i5, %o1
a007a87c:  94 15 23 ff  or  %l4, 0x3ff, %o2
a007a880:  40 00 b3 02  call  0xa00a7488
a007a884:  17 22 00 00  sethi  %hi(0x88000000), %o3
a007a888:  03 28 02 ce  sethi  %hi(0xa00b3800), %g1
a007a88c:  82 10 63 50  or  %g1, 0x350, %g1	! 0xa00b3b50
a007a890:  ee 10 40 10  lduh  [ %g1 + %l0 ], %l7
a007a894:  90 10 00 18  mov  %i0, %o0
a007a898:  92 10 00 17  mov  %l7, %o1
a007a89c:  94 10 3f 00  mov  -256, %o2
a007a8a0:  40 00 b2 fa  call  0xa00a7488
a007a8a4:  96 10 20 88  mov  0x88, %o3
a007a8a8:  03 28 02 ce  sethi  %hi(0xa00b3800), %g1
a007a8ac:  82 10 63 38  or  %g1, 0x338, %g1	! 0xa00b3b38
a007a8b0:  ec 10 40 10  lduh  [ %g1 + %l0 ], %l6
a007a8b4:  90 10 00 18  mov  %i0, %o0
a007a8b8:  92 10 00 16  mov  %l6, %o1
a007a8bc:  94 15 23 ff  or  %l4, 0x3ff, %o2
a007a8c0:  40 00 b2 f2  call  0xa00a7488
a007a8c4:  17 22 00 00  sethi  %hi(0x88000000), %o3
a007a8c8:  03 28 02 ce  sethi  %hi(0xa00b3800), %g1
a007a8cc:  82 10 63 48  or  %g1, 0x348, %g1	! 0xa00b3b48
a007a8d0:  ea 10 40 10  lduh  [ %g1 + %l0 ], %l5
a007a8d4:  90 10 00 18  mov  %i0, %o0
a007a8d8:  92 10 00 15  mov  %l5, %o1
a007a8dc:  94 10 3f 00  mov  -256, %o2
a007a8e0:  40 00 b2 ea  call  0xa00a7488
a007a8e4:  96 10 20 88  mov  0x88, %o3
a007a8e8:  03 28 02 ce  sethi  %hi(0xa00b3800), %g1
a007a8ec:  82 10 63 30  or  %g1, 0x330, %g1	! 0xa00b3b30
a007a8f0:  e6 10 40 10  lduh  [ %g1 + %l0 ], %l3
a007a8f4:  23 3f ff c0  sethi  %hi(0xffff0000), %l1
a007a8f8:  90 10 00 18  mov  %i0, %o0
a007a8fc:  92 10 00 13  mov  %l3, %o1
a007a900:  94 14 60 ff  or  %l1, 0xff, %o2
a007a904:  40 00 b2 e1  call  0xa00a7488
a007a908:  96 10 20 00  clr  %o3
a007a90c:  03 28 02 ce  sethi  %hi(0xa00b3800), %g1
a007a910:  82 10 63 28  or  %g1, 0x328, %g1	! 0xa00b3b28
a007a914:  e4 10 40 10  lduh  [ %g1 + %l0 ], %l2
a007a918:  94 14 60 ff  or  %l1, 0xff, %o2
a007a91c:  90 10 00 18  mov  %i0, %o0
a007a920:  92 10 00 12  mov  %l2, %o1
a007a924:  40 00 b2 d9  call  0xa00a7488
a007a928:  96 10 20 00  clr  %o3
a007a92c:  21 3f c0 3f  sethi  %hi(0xff00fc00), %l0
a007a930:  90 10 00 18  mov  %i0, %o0
a007a934:  92 10 00 13  mov  %l3, %o1
a007a938:  94 14 23 ff  or  %l0, 0x3ff, %o2
a007a93c:  40 00 b2 d3  call  0xa00a7488
a007a940:  96 10 20 00  clr  %o3
a007a944:  90 10 00 18  mov  %i0, %o0
a007a948:  92 10 00 12  mov  %l2, %o1
a007a94c:  94 14 23 ff  or  %l0, 0x3ff, %o2
a007a950:  40 00 b2 ce  call  0xa00a7488
a007a954:  96 10 20 00  clr  %o3
a007a958:  90 10 00 18  mov  %i0, %o0
a007a95c:  92 10 00 1d  mov  %i5, %o1
a007a960:  94 15 23 ff  or  %l4, 0x3ff, %o2
a007a964:  40 00 b2 c9  call  0xa00a7488
a007a968:  17 02 00 00  sethi  %hi(0x8000000), %o3
a007a96c:  90 10 00 18  mov  %i0, %o0
a007a970:  92 10 00 17  mov  %l7, %o1
a007a974:  94 10 3f 00  mov  -256, %o2
a007a978:  40 00 b2 c4  call  0xa00a7488
a007a97c:  96 10 20 08  mov  8, %o3
a007a980:  90 10 00 18  mov  %i0, %o0
a007a984:  92 10 00 16  mov  %l6, %o1
a007a988:  94 15 23 ff  or  %l4, 0x3ff, %o2
a007a98c:  40 00 b2 bf  call  0xa00a7488
a007a990:  17 02 00 00  sethi  %hi(0x8000000), %o3
a007a994:  90 10 00 18  mov  %i0, %o0
a007a998:  92 10 00 15  mov  %l5, %o1
a007a99c:  94 10 3f 00  mov  -256, %o2
a007a9a0:  40 00 b2 ba  call  0xa00a7488
a007a9a4:  96 10 20 08  mov  8, %o3
a007a9a8:  b8 07 20 01  inc  %i4
a007a9ac:  80 a7 20 03  cmp  %i4, 3
a007a9b0:  04 bf ff 98  ble  0xa007a810
a007a9b4:  82 0e 60 ff  and  %i1, 0xff, %g1
a007a9b8:  81 c7 e0 08  ret
a007a9bc:  81 e8 00 00  restore
