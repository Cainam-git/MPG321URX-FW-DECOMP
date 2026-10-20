# leon2m FUN_a00db738 0xa00db738-0xa00dbcf0 (1464 bytes)
a00db738:  9d e3 bf 98  save  %sp, -104, %sp
a00db73c:  25 2a 00 b4  sethi  %hi(0xa802d000), %l2
a00db740:  a0 14 a2 90  or  %l2, 0x290, %l0	! 0xa802d290
a00db744:  90 10 20 00  clr  %o0
a00db748:  7f ff f2 6e  call  0xa00d8100
a00db74c:  e6 0c 20 b3  ldub  [ %l0 + 0xb3 ], %l3
a00db750:  7f ff f2 6c  call  0xa00d8100
a00db754:  90 10 20 01  mov  1, %o0
a00db758:  c2 0c 20 1f  ldub  [ %l0 + 0x1f ], %g1
a00db75c:  80 a0 60 00  cmp  %g1, 0
a00db760:  02 80 00 fe  be  0xa00dbb58
a00db764:  01 00 00 00  nop
a00db768:  7f ff f2 66  call  0xa00d8100
a00db76c:  90 10 20 03  mov  3, %o0	! 0x3
a00db770:  7f ff f2 64  call  0xa00d8100
a00db774:  90 10 20 05  mov  5, %o0
a00db778:  7f ff f2 62  call  0xa00d8100
a00db77c:  90 10 20 06  mov  6, %o0
a00db780:  7f ff f2 60  call  0xa00d8100
a00db784:  90 10 20 07  mov  7, %o0
a00db788:  7f ff f2 5e  call  0xa00d8100
a00db78c:  90 10 20 08  mov  8, %o0
a00db790:  11 00 06 62  sethi  %hi(0x198800), %o0
a00db794:  90 12 22 28  or  %o0, 0x228, %o0	! 0x198a28
a00db798:  40 00 0e 76  call  0xa00df170
a00db79c:  d2 0c 21 81  ldub  [ %l0 + 0x181 ], %o1
a00db7a0:  c2 0c 21 81  ldub  [ %l0 + 0x181 ], %g1
a00db7a4:  80 a0 60 02  cmp  %g1, 2
a00db7a8:  02 80 00 09  be  0xa00db7cc
a00db7ac:  90 10 20 07  mov  7, %o0
a00db7b0:  80 a0 60 02  cmp  %g1, 2
a00db7b4:  14 80 00 a5  bg  0xa00dba48
a00db7b8:  80 a0 60 03  cmp  %g1, 3
a00db7bc:  80 a0 60 01  cmp  %g1, 1
a00db7c0:  02 80 00 03  be  0xa00db7cc
a00db7c4:  90 10 20 06  mov  6, %o0
a00db7c8:  90 10 20 01  mov  1, %o0
a00db7cc:  7f fe b0 92  call  0xa0087a14
a00db7d0:  01 00 00 00  nop
a00db7d4:  7f ff f0 fb  call  0xa00d7bc0
a00db7d8:  01 00 00 00  nop
a00db7dc:  7f ff f7 e2  call  0xa00d9764
a00db7e0:  01 00 00 00  nop
a00db7e4:  9a 14 a2 90  or  %l2, 0x290, %o5
a00db7e8:  d2 03 60 b0  ld  [ %o5 + 0xb0 ], %o1
a00db7ec:  80 a2 60 00  cmp  %o1, 0
a00db7f0:  12 80 00 06  bne  0xa00db808
a00db7f4:  01 00 00 00  nop
a00db7f8:  d4 03 61 1c  ld  [ %o5 + 0x11c ], %o2
a00db7fc:  80 a2 a0 00  cmp  %o2, 0
a00db800:  16 80 00 f6  bge  0xa00dbbd8
a00db804:  01 00 00 00  nop
a00db808:  7f ff f1 76  call  0xa00d7de0
a00db80c:  01 00 00 00  nop
a00db810:  7f ff f6 44  call  0xa00d9120
a00db814:  01 00 00 00  nop
a00db818:  40 01 c1 56  call  0xa014bd70
a00db81c:  90 10 20 00  clr  %o0	! 0x0
a00db820:  96 0a 20 ff  and  %o0, 0xff, %o3
a00db824:  80 a2 e0 01  cmp  %o3, 1
a00db828:  02 80 00 0d  be  0xa00db85c
a00db82c:  90 10 20 00  clr  %o0
a00db830:  40 01 a0 2b  call  0xa01438dc
a00db834:  90 10 20 00  clr  %o0
a00db838:  98 0a 20 ff  and  %o0, 0xff, %o4
a00db83c:  80 a3 20 01  cmp  %o4, 1
a00db840:  02 80 00 85  be  0xa00dba54
a00db844:  a0 14 a2 90  or  %l2, 0x290, %l0
a00db848:  de 04 21 74  ld  [ %l0 + 0x174 ], %o7
a00db84c:  1b 00 00 20  sethi  %hi(0x8000), %o5
a00db850:  80 8b c0 0d  btst  %o7, %o5
a00db854:  02 80 00 8d  be  0xa00dba88
a00db858:  90 10 20 01  mov  1, %o0
a00db85c:  40 01 cc 07  call  0xa014e878
a00db860:  a0 14 a2 90  or  %l2, 0x290, %l0
a00db864:  7f ff f6 2f  call  0xa00d9120
a00db868:  01 00 00 00  nop
a00db86c:  c2 14 20 34  lduh  [ %l0 + 0x34 ], %g1
a00db870:  92 08 60 0f  and  %g1, 0xf, %o1
a00db874:  40 01 b5 fc  call  0xa0149064
a00db878:  90 10 20 00  clr  %o0
a00db87c:  e2 14 20 34  lduh  [ %l0 + 0x34 ], %l1
a00db880:  92 0c 60 0f  and  %l1, 0xf, %o1
a00db884:  40 01 b5 f8  call  0xa0149064
a00db888:  90 10 20 01  mov  1, %o0
a00db88c:  da 0c 20 49  ldub  [ %l0 + 0x49 ], %o5
a00db890:  80 a3 60 05  cmp  %o5, 5
a00db894:  38 80 00 02  bgu,a   0xa00db89c
a00db898:  9a 10 20 05  mov  5, %o5
a00db89c:  96 0b 60 ff  and  %o5, 0xff, %o3
a00db8a0:  94 02 c0 0b  add  %o3, %o3, %o2
a00db8a4:  92 02 80 0b  add  %o2, %o3, %o1
a00db8a8:  94 0a 60 ff  and  %o1, 0xff, %o2
a00db8ac:  90 10 20 00  clr  %o0
a00db8b0:  da 2c 20 49  stb  %o5, [ %l0 + 0x49 ]
a00db8b4:  40 01 ae 3b  call  0xa01471a0
a00db8b8:  92 10 20 0d  mov  0xd, %o1
a00db8bc:  d0 0c 20 1f  ldub  [ %l0 + 0x1f ], %o0
a00db8c0:  80 a2 20 00  cmp  %o0, 0
a00db8c4:  12 80 00 30  bne  0xa00db984
a00db8c8:  a2 14 a2 90  or  %l2, 0x290, %l1
a00db8cc:  d8 04 20 b0  ld  [ %l0 + 0xb0 ], %o4
a00db8d0:  80 a3 20 00  cmp  %o4, 0
a00db8d4:  12 80 00 c4  bne  0xa00dbbe4
a00db8d8:  e2 0c 20 19  ldub  [ %l0 + 0x19 ], %l1
a00db8dc:  82 0c 60 ff  and  %l1, 0xff, %g1
a00db8e0:  80 a0 60 03  cmp  %g1, 3
a00db8e4:  08 80 00 05  bleu  0xa00db8f8
a00db8e8:  80 a0 60 00  cmp  %g1, 0
a00db8ec:  a2 10 20 03  mov  3, %l1
a00db8f0:  82 10 20 03  mov  3, %g1
a00db8f4:  80 a0 60 00  cmp  %g1, 0
a00db8f8:  02 80 00 9f  be  0xa00dbb74
a00db8fc:  e2 2c 20 8f  stb  %l1, [ %l0 + 0x8f ]
a00db900:  c0 2c 20 19  clrb  [ %l0 + 0x19 ]
a00db904:  40 01 b6 0e  call  0xa014913c
a00db908:  90 10 20 05  mov  5, %o0
a00db90c:  a0 14 a2 90  or  %l2, 0x290, %l0
a00db910:  e2 0c 20 8f  ldub  [ %l0 + 0x8f ], %l1
a00db914:  e2 2c 20 19  stb  %l1, [ %l0 + 0x19 ]
a00db918:  96 0c e0 ff  and  %l3, 0xff, %o3
a00db91c:  98 14 a2 90  or  %l2, 0x290, %o4
a00db920:  e6 03 20 b0  ld  [ %o4 + 0xb0 ], %l3
a00db924:  80 a2 c0 13  cmp  %o3, %l3
a00db928:  02 80 00 17  be  0xa00db984
a00db92c:  a2 14 a2 90  or  %l2, 0x290, %l1
a00db930:  40 01 c1 10  call  0xa014bd70
a00db934:  90 10 20 00  clr  %o0
a00db938:  9a 0a 20 ff  and  %o0, 0xff, %o5
a00db93c:  80 a3 60 01  cmp  %o5, 1
a00db940:  02 80 00 11  be  0xa00db984
a00db944:  a2 14 a2 90  or  %l2, 0x290, %l1
a00db948:  40 01 9f e5  call  0xa01438dc
a00db94c:  90 10 20 00  clr  %o0
a00db950:  9e 0a 20 ff  and  %o0, 0xff, %o7
a00db954:  80 a3 e0 01  cmp  %o7, 1
a00db958:  02 80 00 cb  be  0xa00dbc84
a00db95c:  9a 14 a2 90  or  %l2, 0x290, %o5
a00db960:  d0 0b 60 4a  ldub  [ %o5 + 0x4a ], %o0
a00db964:  80 a2 20 00  cmp  %o0, 0
a00db968:  02 80 00 07  be  0xa00db984
a00db96c:  a2 14 a2 90  or  %l2, 0x290, %l1
a00db970:  c2 03 60 b0  ld  [ %o5 + 0xb0 ], %g1
a00db974:  80 a0 60 00  cmp  %g1, 0
a00db978:  32 80 00 b0  bne,a   0xa00dbc38
a00db97c:  d2 0b 60 1f  ldub  [ %o5 + 0x1f ], %o1
a00db980:  a2 14 a2 90  or  %l2, 0x290, %l1
a00db984:  de 04 61 1c  ld  [ %l1 + 0x11c ], %o7
a00db988:  a1 33 e0 1f  srl  %o7, 0x1f, %l0
a00db98c:  94 0c 20 ff  and  %l0, 0xff, %o2
a00db990:  1b 20 00 00  sethi  %hi(0x80000000), %o5
a00db994:  96 2b c0 0d  andn  %o7, %o5, %o3
a00db998:  99 2a a0 1f  sll  %o2, 0x1f, %o4
a00db99c:  a6 12 c0 0c  or  %o3, %o4, %l3
a00db9a0:  80 a2 a0 01  cmp  %o2, 1
a00db9a4:  02 80 00 72  be  0xa00dbb6c
a00db9a8:  e6 24 61 1c  st  %l3, [ %l1 + 0x11c ]
a00db9ac:  80 a2 a0 01  cmp  %o2, 1
a00db9b0:  04 80 00 9e  ble  0xa00dbc28
a00db9b4:  80 a2 a0 02  cmp  %o2, 2
a00db9b8:  22 80 00 02  be,a   0xa00db9c0
a00db9bc:  a0 10 20 02  mov  2, %l0
a00db9c0:  40 01 c0 ec  call  0xa014bd70
a00db9c4:  90 10 20 00  clr  %o0
a00db9c8:  94 0a 20 ff  and  %o0, 0xff, %o2
a00db9cc:  80 a2 a0 01  cmp  %o2, 1
a00db9d0:  22 80 00 3e  be,a   0xa00dbac8
a00db9d4:  a0 10 20 00  clr  %l0
a00db9d8:  40 01 9f c1  call  0xa01438dc
a00db9dc:  90 10 20 00  clr  %o0
a00db9e0:  90 0a 20 ff  and  %o0, 0xff, %o0
a00db9e4:  80 a2 20 01  cmp  %o0, 1
a00db9e8:  02 80 00 2a  be  0xa00dba90
a00db9ec:  01 00 00 00  nop
a00db9f0:  40 01 b6 32  call  0xa01492b8
a00db9f4:  90 0c 20 03  and  %l0, 3, %o0
a00db9f8:  a0 14 a2 90  or  %l2, 0x290, %l0
a00db9fc:  c2 04 21 1c  ld  [ %l0 + 0x11c ], %g1
a00dba00:  80 a0 60 00  cmp  %g1, 0
a00dba04:  16 80 00 38  bge  0xa00dbae4
a00dba08:  23 2a 00 b3  sethi  %hi(0xa802cc00), %l1
a00dba0c:  d2 14 63 fe  lduh  [ %l1 + 0x3fe ], %o1	! 0xa802cffe
a00dba10:  80 8a 60 80  btst  0x80, %o1
a00dba14:  02 80 00 3a  be  0xa00dbafc
a00dba18:  01 00 00 00  nop
a00dba1c:  da 04 20 a8  ld  [ %l0 + 0xa8 ], %o5
a00dba20:  95 33 60 01  srl  %o5, 1, %o2
a00dba24:  9e 0a a4 00  and  %o2, 0x400, %o7
a00dba28:  98 0b 7b ff  and  %o5, -1025, %o4
a00dba2c:  a6 13 00 0f  or  %o4, %o7, %l3
a00dba30:  e4 0c 21 82  ldub  [ %l0 + 0x182 ], %l2
a00dba34:  d6 0c 21 81  ldub  [ %l0 + 0x181 ], %o3
a00dba38:  d6 2c 21 83  stb  %o3, [ %l0 + 0x183 ]
a00dba3c:  e6 24 20 a8  st  %l3, [ %l0 + 0xa8 ]
a00dba40:  10 80 00 aa  b  0xa00dbce8
a00dba44:  e4 2c 21 84  stb  %l2, [ %l0 + 0x184 ]
a00dba48:  12 bf ff 60  bne  0xa00db7c8
a00dba4c:  90 10 20 08  mov  8, %o0
a00dba50:  30 bf ff 5f  b,a   0xa00db7cc
a00dba54:  40 01 c0 05  call  0xa014ba68
a00dba58:  01 00 00 00  nop
a00dba5c:  90 0a 20 ff  and  %o0, 0xff, %o0
a00dba60:  80 a2 20 02  cmp  %o0, 2
a00dba64:  22 bf ff 7e  be,a   0xa00db85c
a00dba68:  90 10 20 00  clr  %o0
a00dba6c:  04 80 00 82  ble  0xa00dbc74
a00dba70:  80 a2 20 01  cmp  %o0, 1
a00dba74:  80 a2 20 03  cmp  %o0, 3
a00dba78:  02 80 00 04  be  0xa00dba88
a00dba7c:  80 a2 20 04  cmp  %o0, 4
a00dba80:  12 bf ff 72  bne  0xa00db848
a00dba84:  a0 14 a2 90  or  %l2, 0x290, %l0
a00dba88:  10 bf ff 75  b  0xa00db85c
a00dba8c:  90 10 20 00  clr  %o0
a00dba90:  40 01 bf f6  call  0xa014ba68
a00dba94:  01 00 00 00  nop
a00dba98:  90 0a 20 ff  and  %o0, 0xff, %o0
a00dba9c:  80 a2 20 02  cmp  %o0, 2
a00dbaa0:  22 80 00 0a  be,a   0xa00dbac8
a00dbaa4:  a0 10 20 00  clr  %l0
a00dbaa8:  04 80 00 6f  ble  0xa00dbc64
a00dbaac:  80 a2 20 01  cmp  %o0, 1
a00dbab0:  80 a2 20 03  cmp  %o0, 3
a00dbab4:  02 80 00 04  be  0xa00dbac4
a00dbab8:  80 a2 20 04  cmp  %o0, 4
a00dbabc:  12 bf ff cd  bne  0xa00db9f0
a00dbac0:  01 00 00 00  nop
a00dbac4:  a0 10 20 00  clr  %l0	! 0x0
a00dbac8:  40 01 b5 fc  call  0xa01492b8
a00dbacc:  90 0c 20 03  and  %l0, 3, %o0
a00dbad0:  a0 14 a2 90  or  %l2, 0x290, %l0
a00dbad4:  c2 04 21 1c  ld  [ %l0 + 0x11c ], %g1
a00dbad8:  80 a0 60 00  cmp  %g1, 0
a00dbadc:  06 bf ff cc  bl  0xa00dba0c
a00dbae0:  23 2a 00 b3  sethi  %hi(0xa802cc00), %l1
a00dbae4:  7f ff f4 7c  call  0xa00d8cd4
a00dbae8:  23 2a 00 b3  sethi  %hi(0xa802cc00), %l1
a00dbaec:  d2 14 63 fe  lduh  [ %l1 + 0x3fe ], %o1	! 0xa802cffe
a00dbaf0:  80 8a 60 80  btst  0x80, %o1
a00dbaf4:  32 bf ff cb  bne,a   0xa00dba20
a00dbaf8:  da 04 20 a8  ld  [ %l0 + 0xa8 ], %o5
a00dbafc:  40 01 c0 9d  call  0xa014bd70
a00dbb00:  90 10 20 00  clr  %o0
a00dbb04:  a0 0a 20 ff  and  %o0, 0xff, %l0
a00dbb08:  80 a4 20 01  cmp  %l0, 1
a00dbb0c:  02 80 00 28  be  0xa00dbbac
a00dbb10:  92 14 a2 90  or  %l2, 0x290, %o1
a00dbb14:  40 01 9f 72  call  0xa01438dc
a00dbb18:  90 10 20 00  clr  %o0
a00dbb1c:  90 0a 20 ff  and  %o0, 0xff, %o0
a00dbb20:  80 a2 20 01  cmp  %o0, 1
a00dbb24:  02 80 00 16  be  0xa00dbb7c
a00dbb28:  94 14 a2 90  or  %l2, 0x290, %o2
a00dbb2c:  e4 02 a0 a8  ld  [ %o2 + 0xa8 ], %l2
a00dbb30:  83 34 a0 02  srl  %l2, 2, %g1
a00dbb34:  a2 08 62 00  and  %g1, 0x200, %l1
a00dbb38:  92 0c bd ff  and  %l2, -513, %o1
a00dbb3c:  9a 12 40 11  or  %o1, %l1, %o5
a00dbb40:  e0 0a a1 82  ldub  [ %o2 + 0x182 ], %l0
a00dbb44:  d0 0a a1 81  ldub  [ %o2 + 0x181 ], %o0
a00dbb48:  d0 2a a1 85  stb  %o0, [ %o2 + 0x185 ]
a00dbb4c:  da 22 a0 a8  st  %o5, [ %o2 + 0xa8 ]
a00dbb50:  10 80 00 66  b  0xa00dbce8
a00dbb54:  e0 2a a1 86  stb  %l0, [ %o2 + 0x186 ]
a00dbb58:  7f ff f1 6a  call  0xa00d8100
a00dbb5c:  90 10 20 02  mov  2, %o0
a00dbb60:  7f ff f1 68  call  0xa00d8100
a00dbb64:  90 10 20 04  mov  4, %o0
a00dbb68:  30 bf ff 00  b,a   0xa00db768
a00dbb6c:  10 bf ff 95  b  0xa00db9c0
a00dbb70:  a0 10 20 01  mov  1, %l0
a00dbb74:  10 bf ff 64  b  0xa00db904
a00dbb78:  e2 2c 20 19  stb  %l1, [ %l0 + 0x19 ]
a00dbb7c:  40 01 bf bb  call  0xa014ba68
a00dbb80:  01 00 00 00  nop
a00dbb84:  90 0a 20 ff  and  %o0, 0xff, %o0
a00dbb88:  80 a2 20 02  cmp  %o0, 2
a00dbb8c:  02 80 00 08  be  0xa00dbbac
a00dbb90:  92 14 a2 90  or  %l2, 0x290, %o1
a00dbb94:  14 80 00 49  bg  0xa00dbcb8
a00dbb98:  80 a2 20 03  cmp  %o0, 3
a00dbb9c:  80 a2 20 01  cmp  %o0, 1
a00dbba0:  12 bf ff e3  bne  0xa00dbb2c
a00dbba4:  94 14 a2 90  or  %l2, 0x290, %o2
a00dbba8:  92 14 a2 90  or  %l2, 0x290, %o1
a00dbbac:  d8 02 60 a8  ld  [ %o1 + 0xa8 ], %o4
a00dbbb0:  9f 33 20 03  srl  %o4, 3, %o7
a00dbbb4:  96 0b e1 00  and  %o7, 0x100, %o3
a00dbbb8:  a6 0b 3e ff  and  %o4, -257, %l3
a00dbbbc:  a4 14 c0 0b  or  %l3, %o3, %l2
a00dbbc0:  e2 0a 61 82  ldub  [ %o1 + 0x182 ], %l1
a00dbbc4:  c2 0a 61 81  ldub  [ %o1 + 0x181 ], %g1
a00dbbc8:  c2 2a 61 87  stb  %g1, [ %o1 + 0x187 ]
a00dbbcc:  e4 22 60 a8  st  %l2, [ %o1 + 0xa8 ]
a00dbbd0:  10 80 00 46  b  0xa00dbce8
a00dbbd4:  e2 2a 61 88  stb  %l1, [ %o1 + 0x188 ]
a00dbbd8:  7f ff f4 3f  call  0xa00d8cd4
a00dbbdc:  01 00 00 00  nop
a00dbbe0:  30 bf ff 0a  b,a   0xa00db808
a00dbbe4:  92 10 20 01  mov  1, %o1	! 0x1
a00dbbe8:  40 01 a6 9e  call  0xa0145660
a00dbbec:  90 10 20 00  clr  %o0
a00dbbf0:  95 2a 20 10  sll  %o0, 0x10, %o2
a00dbbf4:  13 33 33 33  sethi  %hi(0xcccccc00), %o1
a00dbbf8:  91 32 a0 10  srl  %o2, 0x10, %o0
a00dbbfc:  82 12 60 cd  or  %o1, 0xcd, %g1
a00dbc00:  80 52 00 01  umul  %o0, %g1, %g0
a00dbc04:  9f 40 00 00  rd  %y, %o7
a00dbc08:  9b 2b e0 0d  sll  %o7, 0xd, %o5
a00dbc0c:  7f fe ae 13  call  0xa0087458
a00dbc10:  91 33 60 10  srl  %o5, 0x10, %o0
a00dbc14:  80 a2 20 00  cmp  %o0, 0
a00dbc18:  02 bf ff 32  be  0xa00db8e0
a00dbc1c:  82 0c 60 ff  and  %l1, 0xff, %g1
a00dbc20:  10 bf ff 3f  b  0xa00db91c
a00dbc24:  96 0c e0 ff  and  %l3, 0xff, %o3
a00dbc28:  80 a2 a0 00  cmp  %o2, 0
a00dbc2c:  22 bf ff 65  be,a   0xa00db9c0
a00dbc30:  a0 10 20 00  clr  %l0
a00dbc34:  30 bf ff 63  b,a   0xa00db9c0
a00dbc38:  80 a2 60 00  cmp  %o1, 0
a00dbc3c:  12 bf ff 51  bne  0xa00db980
a00dbc40:  c0 2b 60 4a  clrb  [ %o5 + 0x4a ]
a00dbc44:  90 10 20 01  mov  1, %o0
a00dbc48:  40 01 c6 0b  call  0xa014d474
a00dbc4c:  92 10 20 00  clr  %o1
a00dbc50:  90 10 20 01  mov  1, %o0
a00dbc54:  40 01 c8 51  call  0xa014dd98
a00dbc58:  92 10 20 00  clr  %o1
a00dbc5c:  10 bf ff 4a  b  0xa00db984
a00dbc60:  a2 14 a2 90  or  %l2, 0x290, %l1
a00dbc64:  12 bf ff 63  bne  0xa00db9f0
a00dbc68:  01 00 00 00  nop
a00dbc6c:  10 bf ff 97  b  0xa00dbac8
a00dbc70:  a0 10 20 00  clr  %l0	! 0x0
a00dbc74:  12 bf fe f5  bne  0xa00db848
a00dbc78:  a0 14 a2 90  or  %l2, 0x290, %l0
a00dbc7c:  10 bf fe f8  b  0xa00db85c
a00dbc80:  90 10 20 00  clr  %o0
a00dbc84:  40 01 bf 79  call  0xa014ba68
a00dbc88:  01 00 00 00  nop
a00dbc8c:  90 0a 20 ff  and  %o0, 0xff, %o0
a00dbc90:  80 a2 20 02  cmp  %o0, 2
a00dbc94:  02 bf ff 3c  be  0xa00db984
a00dbc98:  a2 14 a2 90  or  %l2, 0x290, %l1
a00dbc9c:  14 80 00 0d  bg  0xa00dbcd0
a00dbca0:  80 a2 20 03  cmp  %o0, 3
a00dbca4:  80 a2 20 01  cmp  %o0, 1
a00dbca8:  12 bf ff 2e  bne  0xa00db960
a00dbcac:  9a 14 a2 90  or  %l2, 0x290, %o5
a00dbcb0:  10 bf ff 36  b  0xa00db988
a00dbcb4:  de 04 61 1c  ld  [ %l1 + 0x11c ], %o7
a00dbcb8:  02 bf ff bc  be  0xa00dbba8
a00dbcbc:  80 a2 20 04  cmp  %o0, 4
a00dbcc0:  12 bf ff 9b  bne  0xa00dbb2c
a00dbcc4:  94 14 a2 90  or  %l2, 0x290, %o2
a00dbcc8:  10 bf ff b9  b  0xa00dbbac
a00dbccc:  92 14 a2 90  or  %l2, 0x290, %o1
a00dbcd0:  02 bf ff 2c  be  0xa00db980
a00dbcd4:  80 a2 20 04  cmp  %o0, 4
a00dbcd8:  12 bf ff 22  bne  0xa00db960
a00dbcdc:  9a 14 a2 90  or  %l2, 0x290, %o5
a00dbce0:  10 bf ff 29  b  0xa00db984
a00dbce4:  a2 14 a2 90  or  %l2, 0x290, %l1
a00dbce8:  81 c7 e0 08  ret
a00dbcec:  81 e8 00 00  restore
