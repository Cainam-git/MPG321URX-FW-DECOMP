# leon2s FUN_a00908d0 0xa00908d0-0xa0090d7c (1196 bytes)  [FUN_a0090d74 = unreachable ret/restore tail, merged]
a00908d0:  9d e3 bf 98  save  %sp, -104, %sp
a00908d4:  b4 0e 20 ff  and  %i0, 0xff, %i2
a00908d8:  90 10 00 1a  mov  %i2, %o0
a00908dc:  7f ff fa fd  call  0xa008f4d0
a00908e0:  27 2a 01 f4  sethi  %hi(0xa807d000), %l3
a00908e4:  a4 14 e3 e4  or  %l3, 0x3e4, %l2	! 0xa807d3e4
a00908e8:  a2 5e a0 b0  smul  %i2, 0xb0, %l1
a00908ec:  a8 10 00 08  mov  %o0, %l4
a00908f0:  b2 04 40 12  add  %l1, %l2, %i1
a00908f4:  c0 2e 60 a6  clrb  [ %i1 + 0xa6 ]
a00908f8:  90 10 00 1a  mov  %i2, %o0
a00908fc:  40 00 57 20  call  0xa00a657c
a0090900:  92 10 20 72  mov  0x72, %o1
a0090904:  a0 0a 20 ff  and  %o0, 0xff, %l0
a0090908:  80 a4 20 00  cmp  %l0, 0
a009090c:  22 80 00 1d  be,a   0xa0090980
a0090910:  90 10 00 1a  mov  %i2, %o0
a0090914:  80 8a 20 80  btst  0x80, %o0
a0090918:  02 80 00 09  be  0xa009093c
a009091c:  80 8c 20 02  btst  2, %l0
a0090920:  82 10 20 01  mov  1, %g1
a0090924:  c2 2e 60 a6  stb  %g1, [ %i1 + 0xa6 ]
a0090928:  90 10 00 1a  mov  %i2, %o0
a009092c:  92 10 20 72  mov  0x72, %o1
a0090930:  40 00 57 25  call  0xa00a65c4
a0090934:  94 10 20 80  mov  0x80, %o2
a0090938:  80 8c 20 02  btst  2, %l0
a009093c:  02 80 00 11  be  0xa0090980
a0090940:  90 10 00 1a  mov  %i2, %o0
a0090944:  82 10 20 01  mov  1, %g1
a0090948:  da 0e 60 8c  ldub  [ %i1 + 0x8c ], %o5
a009094c:  c2 2e 60 8a  stb  %g1, [ %i1 + 0x8a ]
a0090950:  80 a3 60 00  cmp  %o5, 0
a0090954:  12 80 00 07  bne  0xa0090970
a0090958:  c2 2e 60 8b  stb  %g1, [ %i1 + 0x8b ]
a009095c:  92 04 a0 6b  add  %l2, 0x6b, %o1
a0090960:  92 04 40 09  add  %l1, %o1, %o1
a0090964:  7f ff fe cd  call  0xa0090498
a0090968:  90 10 00 1a  mov  %i2, %o0
a009096c:  90 10 00 1a  mov  %i2, %o0
a0090970:  92 10 20 72  mov  0x72, %o1
a0090974:  40 00 57 14  call  0xa00a65c4
a0090978:  94 10 20 02  mov  2, %o2
a009097c:  90 10 00 1a  mov  %i2, %o0
a0090980:  40 00 56 ff  call  0xa00a657c
a0090984:  92 10 20 73  mov  0x73, %o1
a0090988:  a0 0a 20 ff  and  %o0, 0xff, %l0
a009098c:  80 8c 20 40  btst  0x40, %l0
a0090990:  02 80 00 0c  be  0xa00909c0
a0090994:  80 8c 20 04  btst  4, %l0
a0090998:  82 14 e3 e4  or  %l3, 0x3e4, %g1
a009099c:  9a 5e a0 b0  smul  %i2, 0xb0, %o5
a00909a0:  9a 03 40 01  add  %o5, %g1, %o5
a00909a4:  82 10 20 01  mov  1, %g1
a00909a8:  c2 2b 60 a6  stb  %g1, [ %o5 + 0xa6 ]
a00909ac:  90 10 00 1a  mov  %i2, %o0
a00909b0:  92 10 20 73  mov  0x73, %o1
a00909b4:  40 00 57 04  call  0xa00a65c4
a00909b8:  94 10 20 40  mov  0x40, %o2
a00909bc:  80 8c 20 04  btst  4, %l0
a00909c0:  02 80 00 1a  be  0xa0090a28
a00909c4:  80 8c 20 02  btst  2, %l0
a00909c8:  03 2a 01 f4  sethi  %hi(0xa807d000), %g1
a00909cc:  92 10 63 e4  or  %g1, 0x3e4, %o1	! 0xa807d3e4
a00909d0:  96 5e a0 b0  smul  %i2, 0xb0, %o3
a00909d4:  82 02 c0 09  add  %o3, %o1, %g1
a00909d8:  9a 10 20 01  mov  1, %o5
a00909dc:  d8 08 60 6a  ldub  [ %g1 + 0x6a ], %o4
a00909e0:  da 28 60 68  stb  %o5, [ %g1 + 0x68 ]
a00909e4:  80 a3 20 00  cmp  %o4, 0
a00909e8:  12 80 00 06  bne  0xa0090a00
a00909ec:  da 28 60 69  stb  %o5, [ %g1 + 0x69 ]
a00909f0:  92 02 60 5a  add  %o1, 0x5a, %o1
a00909f4:  92 02 c0 09  add  %o3, %o1, %o1
a00909f8:  7f ff ff 48  call  0xa0090718
a00909fc:  90 10 00 1a  mov  %i2, %o0
a0090a00:  90 10 00 1a  mov  %i2, %o0
a0090a04:  92 10 20 73  mov  0x73, %o1
a0090a08:  40 00 56 ef  call  0xa00a65c4
a0090a0c:  94 10 20 04  mov  4, %o2
a0090a10:  90 10 20 02  mov  2, %o0
a0090a14:  92 10 20 7a  mov  0x7a, %o1
a0090a18:  94 10 20 04  mov  4, %o2
a0090a1c:  40 00 57 67  call  0xa00a67b8
a0090a20:  96 10 20 00  clr  %o3
a0090a24:  80 8c 20 02  btst  2, %l0
a0090a28:  02 80 00 1f  be  0xa0090aa4
a0090a2c:  80 8c 20 01  btst  1, %l0
a0090a30:  7f ff fb 5b  call  0xa008f79c
a0090a34:  90 10 00 1a  mov  %i2, %o0
a0090a38:  80 8a 20 ff  btst  0xff, %o0
a0090a3c:  12 80 00 11  bne  0xa0090a80
a0090a40:  90 10 00 1a  mov  %i2, %o0
a0090a44:  03 2a 01 f4  sethi  %hi(0xa807d000), %g1
a0090a48:  92 10 63 e4  or  %g1, 0x3e4, %o1	! 0xa807d3e4
a0090a4c:  96 5e a0 b0  smul  %i2, 0xb0, %o3
a0090a50:  82 02 c0 09  add  %o3, %o1, %g1
a0090a54:  9a 10 20 01  mov  1, %o5
a0090a58:  d8 08 60 43  ldub  [ %g1 + 0x43 ], %o4
a0090a5c:  da 28 60 41  stb  %o5, [ %g1 + 0x41 ]
a0090a60:  80 a3 20 00  cmp  %o4, 0
a0090a64:  12 80 00 07  bne  0xa0090a80
a0090a68:  da 28 60 42  stb  %o5, [ %g1 + 0x42 ]
a0090a6c:  92 02 60 22  add  %o1, 0x22, %o1
a0090a70:  92 02 c0 09  add  %o3, %o1, %o1
a0090a74:  7f ff fe bd  call  0xa0090568
a0090a78:  90 10 00 1a  mov  %i2, %o0
a0090a7c:  90 10 00 1a  mov  %i2, %o0
a0090a80:  92 10 20 73  mov  0x73, %o1
a0090a84:  40 00 56 d0  call  0xa00a65c4
a0090a88:  94 10 20 02  mov  2, %o2
a0090a8c:  90 10 20 02  mov  2, %o0
a0090a90:  92 10 20 7a  mov  0x7a, %o1
a0090a94:  94 10 20 02  mov  2, %o2
a0090a98:  40 00 57 48  call  0xa00a67b8
a0090a9c:  96 10 20 00  clr  %o3
a0090aa0:  80 8c 20 01  btst  1, %l0
a0090aa4:  02 80 00 18  be  0xa0090b04
a0090aa8:  03 2a 01 f4  sethi  %hi(0xa807d000), %g1
a0090aac:  b2 0e 20 ff  and  %i0, 0xff, %i1
a0090ab0:  92 10 63 e4  or  %g1, 0x3e4, %o1
a0090ab4:  98 5e 60 b0  smul  %i1, 0xb0, %o4
a0090ab8:  b4 03 00 09  add  %o4, %o1, %i2
a0090abc:  9a 10 20 01  mov  1, %o5
a0090ac0:  c2 0e a0 59  ldub  [ %i2 + 0x59 ], %g1
a0090ac4:  da 2e a0 57  stb  %o5, [ %i2 + 0x57 ]
a0090ac8:  80 a0 60 00  cmp  %g1, 0
a0090acc:  12 80 00 06  bne  0xa0090ae4
a0090ad0:  da 2e a0 58  stb  %o5, [ %i2 + 0x58 ]
a0090ad4:  92 02 60 44  add  %o1, 0x44, %o1
a0090ad8:  92 03 00 09  add  %o4, %o1, %o1
a0090adc:  7f ff ff 45  call  0xa00907f0
a0090ae0:  90 10 00 19  mov  %i1, %o0
a0090ae4:  90 10 00 19  mov  %i1, %o0
a0090ae8:  92 10 20 73  mov  0x73, %o1
a0090aec:  40 00 56 b6  call  0xa00a65c4
a0090af0:  94 10 20 01  mov  1, %o2
a0090af4:  40 00 85 5c  call  0xa00b2064
a0090af8:  01 00 00 00  nop
a0090afc:  10 80 00 17  b  0xa0090b58
a0090b00:  d0 26 a0 a8  st  %o0, [ %i2 + 0xa8 ]
a0090b04:  7f ff 91 9e  call  0xa007517c
a0090b08:  90 0d 20 ff  and  %l4, 0xff, %o0
a0090b0c:  80 8a 20 ff  btst  0xff, %o0
a0090b10:  02 80 00 13  be  0xa0090b5c
a0090b14:  b4 0e 20 ff  and  %i0, 0xff, %i2
a0090b18:  03 2a 01 f4  sethi  %hi(0xa807d000), %g1
a0090b1c:  9a 5e a0 b0  smul  %i2, 0xb0, %o5
a0090b20:  82 10 63 e4  or  %g1, 0x3e4, %g1
a0090b24:  b2 03 40 01  add  %o5, %g1, %i1
a0090b28:  7f ff fb 9a  call  0xa008f990
a0090b2c:  d0 06 60 a8  ld  [ %i1 + 0xa8 ], %o0
a0090b30:  80 8a 20 ff  btst  0xff, %o0
a0090b34:  22 80 00 0a  be,a   0xa0090b5c
a0090b38:  b4 0e 20 ff  and  %i0, 0xff, %i2
a0090b3c:  7f ff fb a1  call  0xa008f9c0
a0090b40:  90 10 00 1a  mov  %i2, %o0
a0090b44:  80 8a 20 ff  btst  0xff, %o0
a0090b48:  02 80 00 05  be  0xa0090b5c
a0090b4c:  b4 0e 20 ff  and  %i0, 0xff, %i2
a0090b50:  82 10 20 01  mov  1, %g1
a0090b54:  c2 2e 60 ac  stb  %g1, [ %i1 + 0xac ]
a0090b58:  b4 0e 20 ff  and  %i0, 0xff, %i2
a0090b5c:  90 10 00 1a  mov  %i2, %o0
a0090b60:  40 00 56 87  call  0xa00a657c
a0090b64:  92 10 20 74  mov  0x74, %o1
a0090b68:  a0 0a 20 ff  and  %o0, 0xff, %l0
a0090b6c:  80 a4 20 00  cmp  %l0, 0
a0090b70:  02 80 00 35  be  0xa0090c44
a0090b74:  b2 10 00 08  mov  %o0, %i1
a0090b78:  90 10 00 1a  mov  %i2, %o0
a0090b7c:  40 00 56 80  call  0xa00a657c
a0090b80:  92 10 22 80  mov  0x280, %o1
a0090b84:  80 8a 20 ff  btst  0xff, %o0
a0090b88:  02 80 00 26  be  0xa0090c20
a0090b8c:  a2 0c 20 02  and  %l0, 2, %l1
a0090b90:  90 10 00 1a  mov  %i2, %o0
a0090b94:  40 00 56 7a  call  0xa00a657c
a0090b98:  92 10 22 81  mov  0x281, %o1
a0090b9c:  80 8a 20 ff  btst  0xff, %o0
a0090ba0:  02 80 00 21  be  0xa0090c24
a0090ba4:  80 8e 60 80  btst  0x80, %i1
a0090ba8:  80 8c 20 01  btst  1, %l0
a0090bac:  02 80 00 0f  be  0xa0090be8
a0090bb0:  80 a4 60 00  cmp  %l1, 0
a0090bb4:  90 10 00 1a  mov  %i2, %o0
a0090bb8:  92 10 20 05  mov  5, %o1
a0090bbc:  94 10 20 02  mov  2, %o2
a0090bc0:  40 00 56 fe  call  0xa00a67b8
a0090bc4:  96 10 20 01  mov  1, %o3
a0090bc8:  90 10 00 1a  mov  %i2, %o0
a0090bcc:  92 10 20 05  mov  5, %o1
a0090bd0:  94 10 20 02  mov  2, %o2
a0090bd4:  40 00 56 f9  call  0xa00a67b8
a0090bd8:  96 10 20 00  clr  %o3
a0090bdc:  40 00 82 ee  call  0xa00b1794
a0090be0:  90 10 20 05  mov  5, %o0
a0090be4:  80 a4 60 00  cmp  %l1, 0
a0090be8:  02 80 00 0f  be  0xa0090c24
a0090bec:  80 8e 60 80  btst  0x80, %i1
a0090bf0:  90 10 00 1a  mov  %i2, %o0
a0090bf4:  92 10 20 05  mov  5, %o1
a0090bf8:  94 10 20 02  mov  2, %o2
a0090bfc:  40 00 56 ef  call  0xa00a67b8
a0090c00:  96 10 20 01  mov  1, %o3
a0090c04:  90 10 00 1a  mov  %i2, %o0
a0090c08:  92 10 20 05  mov  5, %o1
a0090c0c:  94 10 20 02  mov  2, %o2
a0090c10:  40 00 56 ea  call  0xa00a67b8
a0090c14:  96 10 20 00  clr  %o3
a0090c18:  40 00 82 df  call  0xa00b1794
a0090c1c:  90 10 20 05  mov  5, %o0
a0090c20:  80 8e 60 80  btst  0x80, %i1
a0090c24:  02 80 00 05  be  0xa0090c38
a0090c28:  94 10 00 10  mov  %l0, %o2
a0090c2c:  7f ff fa c6  call  0xa008f744
a0090c30:  90 10 00 1a  mov  %i2, %o0
a0090c34:  94 10 00 10  mov  %l0, %o2
a0090c38:  90 0e 20 ff  and  %i0, 0xff, %o0
a0090c3c:  40 00 56 62  call  0xa00a65c4
a0090c40:  92 10 20 74  mov  0x74, %o1
a0090c44:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0090c48:  90 10 00 18  mov  %i0, %o0
a0090c4c:  40 00 56 4c  call  0xa00a657c
a0090c50:  92 10 20 84  mov  0x84, %o1
a0090c54:  b2 0a 20 ff  and  %o0, 0xff, %i1
a0090c58:  80 a6 60 00  cmp  %i1, 0
a0090c5c:  02 80 00 45  be  0xa0090d70
a0090c60:  b4 10 00 08  mov  %o0, %i2
a0090c64:  80 8e 60 01  btst  1, %i1
a0090c68:  03 2a 01 f4  sethi  %hi(0xa807d000), %g1
a0090c6c:  02 80 00 0e  be  0xa0090ca4
a0090c70:  92 5e 20 b0  smul  %i0, 0xb0, %o1
a0090c74:  82 10 63 e4  or  %g1, 0x3e4, %g1
a0090c78:  92 02 40 01  add  %o1, %g1, %o1
a0090c7c:  9a 10 20 01  mov  1, %o5
a0090c80:  c2 0a 60 21  ldub  [ %o1 + 0x21 ], %g1
a0090c84:  da 2a 60 1f  stb  %o5, [ %o1 + 0x1f ]
a0090c88:  80 a0 60 00  cmp  %g1, 0
a0090c8c:  12 80 00 0a  bne  0xa0090cb4
a0090c90:  da 2a 60 20  stb  %o5, [ %o1 + 0x20 ]
a0090c94:  7f ff fe 69  call  0xa0090638
a0090c98:  90 10 00 18  mov  %i0, %o0
a0090c9c:  10 80 00 07  b  0xa0090cb8
a0090ca0:  90 10 00 18  mov  %i0, %o0
a0090ca4:  82 10 63 e4  or  %g1, 0x3e4, %g1
a0090ca8:  82 02 40 01  add  %o1, %g1, %g1
a0090cac:  c0 28 60 1f  clrb  [ %g1 + 0x1f ]
a0090cb0:  c0 28 60 20  clrb  [ %g1 + 0x20 ]
a0090cb4:  90 10 00 18  mov  %i0, %o0
a0090cb8:  40 00 56 31  call  0xa00a657c
a0090cbc:  92 10 22 9f  mov  0x29f, %o1
a0090cc0:  90 0a 20 ff  and  %o0, 0xff, %o0
a0090cc4:  80 a2 20 02  cmp  %o0, 2
a0090cc8:  12 80 00 14  bne  0xa0090d18
a0090ccc:  03 2a 01 f4  sethi  %hi(0xa807d000), %g1
a0090cd0:  80 8e 60 02  btst  2, %i1
a0090cd4:  02 80 00 16  be  0xa0090d2c
a0090cd8:  90 10 00 18  mov  %i0, %o0
a0090cdc:  40 00 56 28  call  0xa00a657c
a0090ce0:  92 10 22 81  mov  0x281, %o1
a0090ce4:  80 8a 20 10  btst  0x10, %o0
a0090ce8:  03 2a 01 f4  sethi  %hi(0xa807d000), %g1
a0090cec:  02 80 00 07  be  0xa0090d08
a0090cf0:  9a 5e 20 b0  smul  %i0, 0xb0, %o5
a0090cf4:  82 10 63 e4  or  %g1, 0x3e4, %g1
a0090cf8:  82 03 40 01  add  %o5, %g1, %g1
a0090cfc:  9a 10 20 01  mov  1, %o5
a0090d00:  10 80 00 0a  b  0xa0090d28
a0090d04:  da 28 60 a7  stb  %o5, [ %g1 + 0xa7 ]
a0090d08:  82 10 63 e4  or  %g1, 0x3e4, %g1
a0090d0c:  82 03 40 01  add  %o5, %g1, %g1
a0090d10:  10 80 00 06  b  0xa0090d28
a0090d14:  c0 28 60 a7  clrb  [ %g1 + 0xa7 ]
a0090d18:  9a 5e 20 b0  smul  %i0, 0xb0, %o5
a0090d1c:  82 10 63 e4  or  %g1, 0x3e4, %g1
a0090d20:  9a 03 40 01  add  %o5, %g1, %o5
a0090d24:  c0 2b 60 a7  clrb  [ %o5 + 0xa7 ]
a0090d28:  90 10 00 18  mov  %i0, %o0
a0090d2c:  40 00 56 14  call  0xa00a657c
a0090d30:  92 10 21 af  mov  0x1af, %o1
a0090d34:  90 0a 20 ff  and  %o0, 0xff, %o0
a0090d38:  80 a2 20 09  cmp  %o0, 9
a0090d3c:  32 80 00 0b  bne,a   0xa0090d68
a0090d40:  b4 0e a0 ff  and  %i2, 0xff, %i2
a0090d44:  80 8e a0 04  btst  4, %i2
a0090d48:  02 80 00 08  be  0xa0090d68
a0090d4c:  b4 0e a0 ff  and  %i2, 0xff, %i2
a0090d50:  1b 2a 01 f4  sethi  %hi(0xa807d000), %o5
a0090d54:  9a 13 63 e4  or  %o5, 0x3e4, %o5	! 0xa807d3e4
a0090d58:  82 5e 20 b0  smul  %i0, 0xb0, %g1
a0090d5c:  82 00 40 0d  add  %g1, %o5, %g1
a0090d60:  9a 10 20 02  mov  2, %o5
a0090d64:  da 28 60 a7  stb  %o5, [ %g1 + 0xa7 ]
a0090d68:  40 00 56 17  call  0xa00a65c4
a0090d6c:  93 e8 20 84  restore  %g0, 0x84, %o1
a0090d70:  01 00 00 00  nop
a0090d74:  81 c7 e0 08  ret
a0090d78:  81 e8 00 00  restore
