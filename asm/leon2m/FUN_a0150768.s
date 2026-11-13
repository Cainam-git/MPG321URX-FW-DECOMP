# leon2m FUN_a0150768 0xa0150768-0xa0150a98 (816 bytes)  [FUN_a0150a90 = unreachable ret/restore tail, merged]
a0150768:  9d e3 bf 98  save  %sp, -104, %sp
a015076c:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0150770:  80 a6 20 01  cmp  %i0, 1
a0150774:  02 80 00 60  be  0xa01508f4
a0150778:  35 2a 00 b3  sethi  %hi(0xa802cc00), %i2
a015077c:  d6 0e a0 86  ldub  [ %i2 + 0x86 ], %o3	! 0xa802cc86
a0150780:  80 8a e0 01  btst  1, %o3
a0150784:  12 80 00 06  bne  0xa015079c
a0150788:  1f 2a 00 b3  sethi  %hi(0xa802cc00), %o7
a015078c:  d8 0b e0 87  ldub  [ %o7 + 0x87 ], %o4	! 0xa802cc87
a0150790:  80 8b 20 01  btst  1, %o4
a0150794:  02 80 00 07  be  0xa01507b0
a0150798:  f0 0e a0 86  ldub  [ %i2 + 0x86 ], %i0
a015079c:  90 0e 60 ff  and  %i1, 0xff, %o0
a01507a0:  92 10 20 01  mov  1, %o1
a01507a4:  7f fe b8 37  call  0xa00fe880
a01507a8:  94 10 20 00  clr  %o2
a01507ac:  f0 0e a0 86  ldub  [ %i2 + 0x86 ], %i0
a01507b0:  80 8e 20 02  btst  2, %i0
a01507b4:  12 80 00 06  bne  0xa01507cc
a01507b8:  03 2a 00 b3  sethi  %hi(0xa802cc00), %g1
a01507bc:  da 08 60 87  ldub  [ %g1 + 0x87 ], %o5	! 0xa802cc87
a01507c0:  80 8b 60 02  btst  2, %o5
a01507c4:  02 80 00 07  be  0xa01507e0
a01507c8:  d0 0e a0 86  ldub  [ %i2 + 0x86 ], %o0
a01507cc:  90 0e 60 ff  and  %i1, 0xff, %o0
a01507d0:  92 10 20 02  mov  2, %o1
a01507d4:  7f fe b8 2b  call  0xa00fe880
a01507d8:  94 10 20 00  clr  %o2
a01507dc:  d0 0e a0 86  ldub  [ %i2 + 0x86 ], %o0
a01507e0:  80 8a 20 04  btst  4, %o0
a01507e4:  12 80 00 06  bne  0xa01507fc
a01507e8:  15 2a 00 b3  sethi  %hi(0xa802cc00), %o2
a01507ec:  d2 0a a0 87  ldub  [ %o2 + 0x87 ], %o1	! 0xa802cc87
a01507f0:  80 8a 60 04  btst  4, %o1
a01507f4:  02 80 00 07  be  0xa0150810
a01507f8:  d6 0e a0 86  ldub  [ %i2 + 0x86 ], %o3
a01507fc:  90 0e 60 ff  and  %i1, 0xff, %o0
a0150800:  92 10 20 04  mov  4, %o1
a0150804:  7f fe b8 1f  call  0xa00fe880
a0150808:  94 10 20 00  clr  %o2
a015080c:  d6 0e a0 86  ldub  [ %i2 + 0x86 ], %o3
a0150810:  80 8a e0 08  btst  8, %o3
a0150814:  12 80 00 06  bne  0xa015082c
a0150818:  1f 2a 00 b3  sethi  %hi(0xa802cc00), %o7
a015081c:  d8 0b e0 87  ldub  [ %o7 + 0x87 ], %o4	! 0xa802cc87
a0150820:  80 8b 20 08  btst  8, %o4
a0150824:  02 80 00 07  be  0xa0150840
a0150828:  f0 0e a0 86  ldub  [ %i2 + 0x86 ], %i0
a015082c:  90 0e 60 ff  and  %i1, 0xff, %o0
a0150830:  92 10 20 08  mov  8, %o1
a0150834:  7f fe b8 13  call  0xa00fe880
a0150838:  94 10 20 00  clr  %o2
a015083c:  f0 0e a0 86  ldub  [ %i2 + 0x86 ], %i0
a0150840:  80 8e 20 10  btst  0x10, %i0
a0150844:  12 80 00 06  bne  0xa015085c
a0150848:  03 2a 00 b3  sethi  %hi(0xa802cc00), %g1
a015084c:  da 08 60 87  ldub  [ %g1 + 0x87 ], %o5	! 0xa802cc87
a0150850:  80 8b 60 10  btst  0x10, %o5
a0150854:  02 80 00 07  be  0xa0150870
a0150858:  d0 0e a0 86  ldub  [ %i2 + 0x86 ], %o0
a015085c:  90 0e 60 ff  and  %i1, 0xff, %o0
a0150860:  92 10 20 10  mov  0x10, %o1
a0150864:  7f fe b8 07  call  0xa00fe880
a0150868:  94 10 20 00  clr  %o2
a015086c:  d0 0e a0 86  ldub  [ %i2 + 0x86 ], %o0
a0150870:  80 8a 20 20  btst  0x20, %o0
a0150874:  12 80 00 06  bne  0xa015088c
a0150878:  15 2a 00 b3  sethi  %hi(0xa802cc00), %o2
a015087c:  d2 0a a0 87  ldub  [ %o2 + 0x87 ], %o1	! 0xa802cc87
a0150880:  80 8a 60 20  btst  0x20, %o1
a0150884:  02 80 00 07  be  0xa01508a0
a0150888:  d6 0e a0 86  ldub  [ %i2 + 0x86 ], %o3
a015088c:  90 0e 60 ff  and  %i1, 0xff, %o0
a0150890:  92 10 20 20  mov  0x20, %o1
a0150894:  7f fe b7 fb  call  0xa00fe880
a0150898:  94 10 20 00  clr  %o2
a015089c:  d6 0e a0 86  ldub  [ %i2 + 0x86 ], %o3
a01508a0:  80 8a e0 40  btst  0x40, %o3
a01508a4:  12 80 00 06  bne  0xa01508bc
a01508a8:  1f 2a 00 b3  sethi  %hi(0xa802cc00), %o7
a01508ac:  d8 0b e0 87  ldub  [ %o7 + 0x87 ], %o4	! 0xa802cc87
a01508b0:  80 8b 20 40  btst  0x40, %o4
a01508b4:  02 80 00 07  be  0xa01508d0
a01508b8:  f0 4e a0 86  ldsb  [ %i2 + 0x86 ], %i0
a01508bc:  90 0e 60 ff  and  %i1, 0xff, %o0
a01508c0:  92 10 20 40  mov  0x40, %o1
a01508c4:  7f fe b7 ef  call  0xa00fe880
a01508c8:  94 10 20 00  clr  %o2
a01508cc:  f0 4e a0 86  ldsb  [ %i2 + 0x86 ], %i0
a01508d0:  80 a6 20 00  cmp  %i0, 0
a01508d4:  06 80 00 6a  bl  0xa0150a7c
a01508d8:  1b 2a 00 b3  sethi  %hi(0xa802cc00), %o5
a01508dc:  f4 4b 60 87  ldsb  [ %o5 + 0x87 ], %i2	! 0xa802cc87
a01508e0:  80 a6 a0 00  cmp  %i2, 0
a01508e4:  16 80 00 6a  bge  0xa0150a8c
a01508e8:  b0 0e 60 ff  and  %i1, 0xff, %i0
a01508ec:  10 80 00 66  b  0xa0150a84
a01508f0:  b2 10 20 80  mov  0x80, %i1
a01508f4:  c2 0e a0 86  ldub  [ %i2 + 0x86 ], %g1
a01508f8:  80 88 60 01  btst  1, %g1
a01508fc:  12 80 00 5a  bne  0xa0150a64
a0150900:  11 2a 00 b3  sethi  %hi(0xa802cc00), %o0
a0150904:  da 0a 20 87  ldub  [ %o0 + 0x87 ], %o5	! 0xa802cc87
a0150908:  80 8b 60 01  btst  1, %o5
a015090c:  12 80 00 57  bne  0xa0150a68
a0150910:  90 0e 60 ff  and  %i1, 0xff, %o0
a0150914:  d2 0e a0 86  ldub  [ %i2 + 0x86 ], %o1
a0150918:  80 8a 60 02  btst  2, %o1
a015091c:  12 80 00 06  bne  0xa0150934
a0150920:  17 2a 00 b3  sethi  %hi(0xa802cc00), %o3
a0150924:  d4 0a e0 87  ldub  [ %o3 + 0x87 ], %o2	! 0xa802cc87
a0150928:  80 8a a0 02  btst  2, %o2
a015092c:  02 80 00 07  be  0xa0150948
a0150930:  d8 0e a0 86  ldub  [ %i2 + 0x86 ], %o4
a0150934:  90 0e 60 ff  and  %i1, 0xff, %o0
a0150938:  92 10 20 02  mov  2, %o1
a015093c:  7f fe b7 d1  call  0xa00fe880
a0150940:  94 10 20 0a  mov  0xa, %o2
a0150944:  d8 0e a0 86  ldub  [ %i2 + 0x86 ], %o4
a0150948:  80 8b 20 04  btst  4, %o4
a015094c:  12 80 00 06  bne  0xa0150964
a0150950:  31 2a 00 b3  sethi  %hi(0xa802cc00), %i0
a0150954:  de 0e 20 87  ldub  [ %i0 + 0x87 ], %o7	! 0xa802cc87
a0150958:  80 8b e0 04  btst  4, %o7
a015095c:  02 80 00 07  be  0xa0150978
a0150960:  c2 0e a0 86  ldub  [ %i2 + 0x86 ], %g1
a0150964:  90 0e 60 ff  and  %i1, 0xff, %o0
a0150968:  92 10 20 04  mov  4, %o1
a015096c:  7f fe b7 c5  call  0xa00fe880
a0150970:  94 10 20 0a  mov  0xa, %o2
a0150974:  c2 0e a0 86  ldub  [ %i2 + 0x86 ], %g1
a0150978:  80 88 60 08  btst  8, %g1
a015097c:  12 80 00 06  bne  0xa0150994
a0150980:  11 2a 00 b3  sethi  %hi(0xa802cc00), %o0
a0150984:  da 0a 20 87  ldub  [ %o0 + 0x87 ], %o5	! 0xa802cc87
a0150988:  80 8b 60 08  btst  8, %o5
a015098c:  02 80 00 07  be  0xa01509a8
a0150990:  d2 0e a0 86  ldub  [ %i2 + 0x86 ], %o1
a0150994:  90 0e 60 ff  and  %i1, 0xff, %o0
a0150998:  92 10 20 08  mov  8, %o1
a015099c:  7f fe b7 b9  call  0xa00fe880
a01509a0:  94 10 20 0a  mov  0xa, %o2
a01509a4:  d2 0e a0 86  ldub  [ %i2 + 0x86 ], %o1
a01509a8:  80 8a 60 10  btst  0x10, %o1
a01509ac:  12 80 00 06  bne  0xa01509c4
a01509b0:  17 2a 00 b3  sethi  %hi(0xa802cc00), %o3
a01509b4:  d4 0a e0 87  ldub  [ %o3 + 0x87 ], %o2	! 0xa802cc87
a01509b8:  80 8a a0 10  btst  0x10, %o2
a01509bc:  02 80 00 07  be  0xa01509d8
a01509c0:  d8 0e a0 86  ldub  [ %i2 + 0x86 ], %o4
a01509c4:  90 0e 60 ff  and  %i1, 0xff, %o0
a01509c8:  92 10 20 10  mov  0x10, %o1
a01509cc:  7f fe b7 ad  call  0xa00fe880
a01509d0:  94 10 20 0a  mov  0xa, %o2
a01509d4:  d8 0e a0 86  ldub  [ %i2 + 0x86 ], %o4
a01509d8:  80 8b 20 20  btst  0x20, %o4
a01509dc:  12 80 00 06  bne  0xa01509f4
a01509e0:  31 2a 00 b3  sethi  %hi(0xa802cc00), %i0
a01509e4:  de 0e 20 87  ldub  [ %i0 + 0x87 ], %o7	! 0xa802cc87
a01509e8:  80 8b e0 20  btst  0x20, %o7
a01509ec:  02 80 00 07  be  0xa0150a08
a01509f0:  c2 0e a0 86  ldub  [ %i2 + 0x86 ], %g1
a01509f4:  90 0e 60 ff  and  %i1, 0xff, %o0
a01509f8:  92 10 20 20  mov  0x20, %o1
a01509fc:  7f fe b7 a1  call  0xa00fe880
a0150a00:  94 10 20 0a  mov  0xa, %o2
a0150a04:  c2 0e a0 86  ldub  [ %i2 + 0x86 ], %g1
a0150a08:  80 88 60 40  btst  0x40, %g1
a0150a0c:  12 80 00 06  bne  0xa0150a24
a0150a10:  11 2a 00 b3  sethi  %hi(0xa802cc00), %o0
a0150a14:  da 0a 20 87  ldub  [ %o0 + 0x87 ], %o5	! 0xa802cc87
a0150a18:  80 8b 60 40  btst  0x40, %o5
a0150a1c:  02 80 00 07  be  0xa0150a38
a0150a20:  d2 4e a0 86  ldsb  [ %i2 + 0x86 ], %o1
a0150a24:  90 0e 60 ff  and  %i1, 0xff, %o0
a0150a28:  92 10 20 40  mov  0x40, %o1
a0150a2c:  7f fe b7 95  call  0xa00fe880
a0150a30:  94 10 20 0a  mov  0xa, %o2
a0150a34:  d2 4e a0 86  ldsb  [ %i2 + 0x86 ], %o1
a0150a38:  80 a2 60 00  cmp  %o1, 0
a0150a3c:  06 80 00 06  bl  0xa0150a54
a0150a40:  15 2a 00 b3  sethi  %hi(0xa802cc00), %o2
a0150a44:  f4 4a a0 87  ldsb  [ %o2 + 0x87 ], %i2	! 0xa802cc87
a0150a48:  80 a6 a0 00  cmp  %i2, 0
a0150a4c:  16 80 00 10  bge  0xa0150a8c
a0150a50:  01 00 00 00  nop
a0150a54:  b0 0e 60 ff  and  %i1, 0xff, %i0
a0150a58:  b2 10 20 80  mov  0x80, %i1
a0150a5c:  7f fe b7 89  call  0xa00fe880
a0150a60:  95 e8 20 0a  restore  %g0, 0xa, %o2
a0150a64:  90 0e 60 ff  and  %i1, 0xff, %o0
a0150a68:  92 10 20 01  mov  1, %o1
a0150a6c:  7f fe b7 85  call  0xa00fe880
a0150a70:  94 10 20 0a  mov  0xa, %o2
a0150a74:  10 bf ff a9  b  0xa0150918
a0150a78:  d2 0e a0 86  ldub  [ %i2 + 0x86 ], %o1
a0150a7c:  b0 0e 60 ff  and  %i1, 0xff, %i0
a0150a80:  b2 10 20 80  mov  0x80, %i1
a0150a84:  7f fe b7 7f  call  0xa00fe880
a0150a88:  95 e8 20 00  restore  %g0, 0, %o2
a0150a8c:  01 00 00 00  nop
a0150a90:  81 c7 e0 08  ret
a0150a94:  81 e8 00 00  restore
