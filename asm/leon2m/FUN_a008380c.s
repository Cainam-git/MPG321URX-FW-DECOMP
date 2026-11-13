# leon2m FUN_a008380c 0xa008380c-0xa0083aa0 (660 bytes)
a008380c:  9d e3 bf 98  save  %sp, -104, %sp
a0083810:  92 10 20 01  mov  1, %o1
a0083814:  40 03 07 93  call  0xa0145660
a0083818:  90 10 20 00  clr  %o0
a008381c:  a2 10 00 08  mov  %o0, %l1
a0083820:  92 10 20 00  clr  %o1
a0083824:  40 03 07 8f  call  0xa0145660
a0083828:  90 10 20 00  clr  %o0
a008382c:  92 10 20 07  mov  7, %o1
a0083830:  40 03 07 8c  call  0xa0145660
a0083834:  90 10 20 00  clr  %o0
a0083838:  a0 10 00 08  mov  %o0, %l0
a008383c:  92 10 20 08  mov  8, %o1
a0083840:  40 03 07 88  call  0xa0145660
a0083844:  90 10 20 00  clr  %o0
a0083848:  a8 10 00 08  mov  %o0, %l4
a008384c:  40 03 12 cc  call  0xa014837c
a0083850:  90 10 20 01  mov  1, %o0
a0083854:  40 03 29 ef  call  0xa014e010
a0083858:  a6 10 00 08  mov  %o0, %l3
a008385c:  90 0a 20 ff  and  %o0, 0xff, %o0
a0083860:  80 a2 20 01  cmp  %o0, 1
a0083864:  02 80 00 50  be  0xa00839a4
a0083868:  b0 10 20 00  clr  %i0
a008386c:  25 2a 00 b4  sethi  %hi(0xa802d000), %l2
a0083870:  a0 14 a2 90  or  %l2, 0x290, %l0	! 0xa802d290
a0083874:  d0 0c 20 1f  ldub  [ %l0 + 0x1f ], %o0
a0083878:  80 a2 20 00  cmp  %o0, 0
a008387c:  02 80 00 43  be  0xa0083988
a0083880:  01 00 00 00  nop
a0083884:  40 03 13 57  call  0xa01485e0
a0083888:  90 10 20 00  clr  %o0	! 0x0
a008388c:  80 8a 20 ff  btst  0xff, %o0
a0083890:  32 80 00 7d  bne,a   0xa0083a84
a0083894:  b0 10 20 00  clr  %i0
a0083898:  1f 2a 00 b5  sethi  %hi(0xa802d400), %o7
a008389c:  d8 03 e2 a4  ld  [ %o7 + 0x2a4 ], %o4	! 0xa802d6a4
a00838a0:  a3 2c 60 10  sll  %l1, 0x10, %l1
a00838a4:  d6 13 20 4e  lduh  [ %o4 + 0x4e ], %o3
a00838a8:  94 02 ff ec  add  %o3, -20, %o2
a00838ac:  9b 34 60 10  srl  %l1, 0x10, %o5
a00838b0:  80 a3 40 0a  cmp  %o5, %o2
a00838b4:  26 80 00 74  bl,a   0xa0083a84
a00838b8:  b0 10 20 00  clr  %i0
a00838bc:  c2 13 20 50  lduh  [ %o4 + 0x50 ], %g1
a00838c0:  98 00 60 14  add  %g1, 0x14, %o4
a00838c4:  80 a3 40 0c  cmp  %o5, %o4
a00838c8:  34 80 00 6f  bg,a   0xa0083a84
a00838cc:  b0 10 20 00  clr  %i0
a00838d0:  d2 0c 20 1f  ldub  [ %l0 + 0x1f ], %o1
a00838d4:  80 a2 60 00  cmp  %o1, 0
a00838d8:  12 80 00 0e  bne  0xa0083910
a00838dc:  01 00 00 00  nop
a00838e0:  da 0c 21 a4  ldub  [ %l0 + 0x1a4 ], %o5
a00838e4:  a0 03 7f fc  add  %o5, -4, %l0
a00838e8:  96 0c 20 ff  and  %l0, 0xff, %o3
a00838ec:  80 a2 e0 02  cmp  %o3, 2
a00838f0:  08 80 00 4d  bleu  0xa0083a24
a00838f4:  82 10 20 00  clr  %g1
a00838f8:  80 88 60 ff  btst  0xff, %g1
a00838fc:  12 80 00 4c  bne  0xa0083a2c
a0083900:  82 0b 60 ff  and  %o5, 0xff, %g1
a0083904:  80 a0 60 08  cmp  %g1, 8
a0083908:  02 80 00 4a  be  0xa0083a30
a008390c:  90 18 60 04  xor  %g1, 4, %o0
a0083910:  40 03 13 0c  call  0xa0148540
a0083914:  90 10 20 00  clr  %o0
a0083918:  80 8a 20 ff  btst  0xff, %o0
a008391c:  02 80 00 05  be  0xa0083930
a0083920:  a7 34 60 10  srl  %l1, 0x10, %l3
a0083924:  80 a4 e9 5f  cmp  %l3, 0x95f
a0083928:  08 80 00 50  bleu  0xa0083a68
a008392c:  01 00 00 00  nop
a0083930:  40 03 13 04  call  0xa0148540
a0083934:  90 10 20 00  clr  %o0	! 0x0
a0083938:  80 8a 20 ff  btst  0xff, %o0
a008393c:  12 80 00 08  bne  0xa008395c
a0083940:  98 14 a2 90  or  %l2, 0x290, %o4
a0083944:  9e 14 a2 90  or  %l2, 0x290, %o7
a0083948:  d6 0b e0 05  ldub  [ %o7 + 5 ], %o3
a008394c:  80 a2 e0 00  cmp  %o3, 0
a0083950:  22 80 00 4e  be,a   0xa0083a88
a0083954:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0083958:  98 14 a2 90  or  %l2, 0x290, %o4
a008395c:  d2 03 20 34  ld  [ %o4 + 0x34 ], %o1
a0083960:  03 00 00 3c  sethi  %hi(0xf000), %g1
a0083964:  80 8a 40 01  btst  %o1, %g1
a0083968:  32 80 00 48  bne,a   0xa0083a88
a008396c:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0083970:  e0 0b 20 1f  ldub  [ %o4 + 0x1f ], %l0
a0083974:  80 a4 20 01  cmp  %l0, 1
a0083978:  28 80 00 43  bleu,a   0xa0083a84
a008397c:  b0 10 20 02  mov  2, %i0
a0083980:  10 80 00 42  b  0xa0083a88
a0083984:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0083988:  40 03 13 16  call  0xa01485e0
a008398c:  90 10 20 00  clr  %o0
a0083990:  80 8a 20 ff  btst  0xff, %o0
a0083994:  02 bf ff c1  be  0xa0083898
a0083998:  b0 10 20 02  mov  2, %i0
a008399c:  10 80 00 3a  b  0xa0083a84
a00839a0:  b0 10 20 00  clr  %i0
a00839a4:  15 2a 00 b5  sethi  %hi(0xa802d400), %o2
a00839a8:  d8 02 a2 a4  ld  [ %o2 + 0x2a4 ], %o4	! 0xa802d6a4
a00839ac:  9b 2c 60 10  sll  %l1, 0x10, %o5
a00839b0:  d2 13 20 4e  lduh  [ %o4 + 0x4e ], %o1
a00839b4:  91 33 60 10  srl  %o5, 0x10, %o0
a00839b8:  82 02 7f ec  add  %o1, -20, %g1
a00839bc:  80 a2 00 01  cmp  %o0, %g1
a00839c0:  24 80 00 31  ble,a   0xa0083a84
a00839c4:  b0 10 20 00  clr  %i0
a00839c8:  de 13 20 50  lduh  [ %o4 + 0x50 ], %o7
a00839cc:  96 03 e0 14  add  %o7, 0x14, %o3
a00839d0:  80 a2 00 0b  cmp  %o0, %o3
a00839d4:  36 80 00 2c  bge,a   0xa0083a84
a00839d8:  b0 10 20 00  clr  %i0
a00839dc:  9b 2c 20 10  sll  %l0, 0x10, %o5
a00839e0:  93 33 60 10  srl  %o5, 0x10, %o1
a00839e4:  82 1a 63 20  xor  %o1, 0x320, %g1
a00839e8:  a7 2d 20 10  sll  %l4, 0x10, %l3
a00839ec:  80 a0 00 01  cmp  %g0, %g1
a00839f0:  a5 34 e0 10  srl  %l3, 0x10, %l2
a00839f4:  98 60 3f ff  subx  %g0, -1, %o4
a00839f8:  a2 1c a2 58  xor  %l2, 0x258, %l1
a00839fc:  80 a0 00 11  cmp  %g0, %l1
a0083a00:  a0 60 3f ff  subx  %g0, -1, %l0
a0083a04:  80 8b 00 10  btst  %o4, %l0
a0083a08:  22 80 00 1f  be,a   0xa0083a84
a0083a0c:  b0 10 20 01  mov  1, %i0
a0083a10:  80 a2 22 6b  cmp  %o0, 0x26b
a0083a14:  28 80 00 1d  bleu,a   0xa0083a88
a0083a18:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0083a1c:  10 80 00 1a  b  0xa0083a84
a0083a20:  b0 10 20 01  mov  1, %i0
a0083a24:  10 bf ff b5  b  0xa00838f8
a0083a28:  82 10 20 01  mov  1, %g1
a0083a2c:  90 18 60 04  xor  %g1, 4, %o0
a0083a30:  80 a0 00 08  cmp  %g0, %o0
a0083a34:  9a 1c c0 14  xor  %l3, %l4, %o5
a0083a38:  a2 60 3f ff  subx  %g0, -1, %l1
a0083a3c:  a5 2b 60 10  sll  %o5, 0x10, %l2
a0083a40:  80 a0 00 12  cmp  %g0, %l2
a0083a44:  a8 60 3f ff  subx  %g0, -1, %l4
a0083a48:  80 8c 40 14  btst  %l1, %l4
a0083a4c:  12 80 00 0f  bne  0xa0083a88
a0083a50:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0083a54:  80 a2 e0 02  cmp  %o3, 2
a0083a58:  18 80 00 0b  bgu  0xa0083a84
a0083a5c:  b0 10 20 00  clr  %i0
a0083a60:  10 80 00 09  b  0xa0083a84
a0083a64:  b0 10 20 01  mov  1, %i0
a0083a68:  40 02 65 48  call  0xa011cf88
a0083a6c:  01 00 00 00  nop
a0083a70:  94 0a 20 ff  and  %o0, 0xff, %o2
a0083a74:  80 a2 a0 82  cmp  %o2, 0x82
a0083a78:  18 bf ff ae  bgu  0xa0083930
a0083a7c:  01 00 00 00  nop
a0083a80:  b0 10 20 03  mov  3, %i0	! 0x3
a0083a84:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0083a88:  19 00 03 fb  sethi  %hi(0xfec00), %o4
a0083a8c:  90 13 22 d8  or  %o4, 0x2d8, %o0	! 0xfeed8
a0083a90:  40 01 6d b8  call  0xa00df170
a0083a94:  92 10 00 18  mov  %i0, %o1
a0083a98:  81 c7 e0 08  ret
a0083a9c:  81 e8 00 00  restore
