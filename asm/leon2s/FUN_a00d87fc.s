# leon2s FUN_a00d87fc 0xa00d87fc-0xa00d8b90 (916 bytes)
a00d87fc:  9d e3 be 80  save  %sp, -384, %sp
a00d8800:  98 10 20 00  clr  %o4
a00d8804:  9a 10 20 00  clr  %o5
a00d8808:  d8 3f bf e8  std  %o4, [ %fp + -24 ]
a00d880c:  92 10 20 00  clr  %o1
a00d8810:  96 10 20 17  mov  0x17, %o3
a00d8814:  c0 27 bf f0  clr  [ %fp + -16 ]
a00d8818:  90 07 bf e8  add  %fp, -24, %o0
a00d881c:  7f ff fa e6  call  0xa00d73b4
a00d8820:  94 10 20 01  mov  1, %o2
a00d8824:  c2 07 be e0  ld  [ %fp + -288 ], %g1
a00d8828:  19 1f c0 00  sethi  %hi(0x7f000000), %o4
a00d882c:  98 28 40 0c  andn  %g1, %o4, %o4
a00d8830:  d6 07 bf e8  ld  [ %fp + -24 ], %o3
a00d8834:  03 08 00 00  sethi  %hi(0x20000000), %g1
a00d8838:  9b 32 e0 14  srl  %o3, 0x14, %o5
a00d883c:  98 13 00 01  or  %o4, %g1, %o4
a00d8840:  9a 0b 60 0f  and  %o5, 0xf, %o5
a00d8844:  03 00 03 c0  sethi  %hi(0xf0000), %g1
a00d8848:  9b 2b 60 10  sll  %o5, 0x10, %o5
a00d884c:  82 2b 00 01  andn  %o4, %g1, %g1
a00d8850:  82 10 40 0d  or  %g1, %o5, %g1
a00d8854:  c2 27 be e0  st  %g1, [ %fp + -288 ]
a00d8858:  03 00 3c 00  sethi  %hi(0xf00000), %g1
a00d885c:  96 0a c0 01  and  %o3, %g1, %o3
a00d8860:  da 0f bf f0  ldub  [ %fp + -16 ], %o5
a00d8864:  03 00 04 00  sethi  %hi(0x100000), %g1
a00d8868:  80 a2 c0 01  cmp  %o3, %g1
a00d886c:  da 2f be e2  stb  %o5, [ %fp + -286 ]
a00d8870:  a2 10 00 0d  mov  %o5, %l1
a00d8874:  92 10 20 00  clr  %o1
a00d8878:  b8 10 20 00  clr  %i4
a00d887c:  a0 10 20 00  clr  %l0
a00d8880:  12 80 00 2e  bne  0xa00d8938
a00d8884:  a6 10 20 00  clr  %l3
a00d8888:  9b 2c 60 10  sll  %l1, 0x10, %o5
a00d888c:  80 a3 60 00  cmp  %o5, 0
a00d8890:  02 80 00 b4  be  0xa00d8b60
a00d8894:  83 33 60 10  srl  %o5, 0x10, %g1
a00d8898:  80 a0 60 10  cmp  %g1, 0x10
a00d889c:  28 80 00 05  bleu,a   0xa00d88b0
a00d88a0:  a4 10 00 11  mov  %l1, %l2
a00d88a4:  a4 10 20 10  mov  0x10, %l2
a00d88a8:  10 80 00 03  b  0xa00d88b4
a00d88ac:  a2 04 7f f0  add  %l1, -16, %l1
a00d88b0:  a2 10 20 00  clr  %l1
a00d88b4:  83 2c e0 10  sll  %l3, 0x10, %g1
a00d88b8:  a1 30 60 10  srl  %g1, 0x10, %l0
a00d88bc:  96 04 bf ff  add  %l2, -1, %o3
a00d88c0:  d4 07 bf ec  ld  [ %fp + -20 ], %o2
a00d88c4:  97 2a e0 18  sll  %o3, 0x18, %o3
a00d88c8:  98 07 80 10  add  %fp, %l0, %o4
a00d88cc:  94 02 80 10  add  %o2, %l0, %o2
a00d88d0:  97 3a e0 18  sra  %o3, 0x18, %o3
a00d88d4:  98 03 3e e3  add  %o4, -285, %o4
a00d88d8:  90 10 20 00  clr  %o0
a00d88dc:  40 3a f6 c9  call  0xa0f96400
a00d88e0:  92 10 20 90  mov  0x90, %o1
a00d88e4:  90 0a 20 ff  and  %o0, 0xff, %o0
a00d88e8:  80 a2 20 00  cmp  %o0, 0
a00d88ec:  12 80 00 10  bne  0xa00d892c
a00d88f0:  82 0c a0 ff  and  %l2, 0xff, %g1
a00d88f4:  94 0c a0 ff  and  %l2, 0xff, %o2
a00d88f8:  80 a2 00 0a  cmp  %o0, %o2
a00d88fc:  1a 80 00 0c  bcc  0xa00d892c
a00d8900:  98 10 20 00  clr  %o4
a00d8904:  82 07 bf f8  add  %fp, -8, %g1
a00d8908:  96 00 40 10  add  %g1, %l0, %o3
a00d890c:  82 0b 20 ff  and  %o4, 0xff, %g1
a00d8910:  98 03 20 01  inc  %o4
a00d8914:  82 02 c0 01  add  %o3, %g1, %g1
a00d8918:  9a 0b 20 ff  and  %o4, 0xff, %o5
a00d891c:  80 a3 40 0a  cmp  %o5, %o2
a00d8920:  0a bf ff fb  bcs  0xa00d890c
a00d8924:  c0 28 7e eb  clrb  [ %g1 + -277 ]
a00d8928:  82 0c a0 ff  and  %l2, 0xff, %g1
a00d892c:  9b 2c 60 10  sll  %l1, 0x10, %o5
a00d8930:  10 bf ff d7  b  0xa00d888c
a00d8934:  a6 04 c0 01  add  %l3, %g1, %l3
a00d8938:  da 07 bf ec  ld  [ %fp + -20 ], %o5
a00d893c:  80 a3 60 0b  cmp  %o5, 0xb
a00d8940:  18 80 00 05  bgu  0xa00d8954
a00d8944:  82 03 7f d0  add  %o5, -48, %g1
a00d8948:  a6 0b 60 0f  and  %o5, 0xf, %l3
a00d894c:  10 80 00 47  b  0xa00d8a68
a00d8950:  96 10 20 0b  mov  0xb, %o3
a00d8954:  80 a0 60 0f  cmp  %g1, 0xf
a00d8958:  18 80 00 06  bgu  0xa00d8970
a00d895c:  82 03 7f 00  add  %o5, -256, %g1
a00d8960:  a6 0b 60 0f  and  %o5, 0xf, %l3
a00d8964:  96 10 20 0f  mov  0xf, %o3
a00d8968:  10 80 00 40  b  0xa00d8a68
a00d896c:  92 10 20 0f  mov  0xf, %o1
a00d8970:  80 a0 60 01  cmp  %g1, 1
a00d8974:  18 80 00 06  bgu  0xa00d898c
a00d8978:  03 3f fe 60  sethi  %hi(0xfff98000), %g1
a00d897c:  a6 0b 60 0f  and  %o5, 0xf, %l3
a00d8980:  96 10 20 02  mov  2, %o3
a00d8984:  10 80 00 39  b  0xa00d8a68
a00d8988:  92 10 20 2d  mov  0x2d, %o1
a00d898c:  82 03 40 01  add  %o5, %g1, %g1
a00d8990:  80 a0 60 2b  cmp  %g1, 0x2b
a00d8994:  18 80 00 06  bgu  0xa00d89ac
a00d8998:  80 a3 60 0e  cmp  %o5, 0xe
a00d899c:  a6 0b 60 2f  and  %o5, 0x2f, %l3
a00d89a0:  96 10 20 2c  mov  0x2c, %o3
a00d89a4:  10 80 00 31  b  0xa00d8a68
a00d89a8:  92 10 20 79  mov  0x79, %o1
a00d89ac:  12 80 00 05  bne  0xa00d89c0
a00d89b0:  82 03 7f a0  add  %o5, -96, %g1
a00d89b4:  96 10 20 01  mov  1, %o3
a00d89b8:  10 80 00 2c  b  0xa00d8a68
a00d89bc:  92 10 20 0d  mov  0xd, %o1
a00d89c0:  80 a0 60 0f  cmp  %g1, 0xf
a00d89c4:  18 80 00 06  bgu  0xa00d89dc
a00d89c8:  82 03 7f 70  add  %o5, -144, %g1
a00d89cc:  a6 0b 60 0f  and  %o5, 0xf, %l3
a00d89d0:  96 10 20 10  mov  0x10, %o3
a00d89d4:  10 80 00 25  b  0xa00d8a68
a00d89d8:  92 10 20 1f  mov  0x1f, %o1
a00d89dc:  80 a0 60 01  cmp  %g1, 1
a00d89e0:  18 80 00 06  bgu  0xa00d89f8
a00d89e4:  80 a3 61 20  cmp  %o5, 0x120
a00d89e8:  a6 0b 60 0f  and  %o5, 0xf, %l3
a00d89ec:  96 10 20 02  mov  2, %o3
a00d89f0:  10 80 00 1e  b  0xa00d8a68
a00d89f4:  92 10 20 2c  mov  0x2c, %o1
a00d89f8:  12 80 00 05  bne  0xa00d8a0c
a00d89fc:  80 a3 61 60  cmp  %o5, 0x160
a00d8a00:  96 10 20 01  mov  1, %o3
a00d8a04:  10 80 00 19  b  0xa00d8a68
a00d8a08:  92 10 20 40  mov  0x40, %o1
a00d8a0c:  12 80 00 05  bne  0xa00d8a20
a00d8a10:  03 3f ff f7  sethi  %hi(0xffffdc00), %g1
a00d8a14:  96 10 20 01  mov  1, %o3
a00d8a18:  10 80 00 14  b  0xa00d8a68
a00d8a1c:  92 10 20 41  mov  0x41, %o1
a00d8a20:  82 10 62 00  or  %g1, 0x200, %g1
a00d8a24:  82 03 40 01  add  %o5, %g1, %g1
a00d8a28:  80 a0 60 10  cmp  %g1, 0x10
a00d8a2c:  18 80 00 06  bgu  0xa00d8a44
a00d8a30:  82 03 7f c0  add  %o5, -64, %g1
a00d8a34:  a6 0b 60 1f  and  %o5, 0x1f, %l3
a00d8a38:  96 10 20 11  mov  0x11, %o3
a00d8a3c:  10 80 00 0b  b  0xa00d8a68
a00d8a40:  92 10 20 65  mov  0x65, %o1
a00d8a44:  80 a0 60 0f  cmp  %g1, 0xf
a00d8a48:  96 10 20 00  clr  %o3
a00d8a4c:  18 80 00 07  bgu  0xa00d8a68
a00d8a50:  a6 10 20 00  clr  %l3
a00d8a54:  03 2a 01 d8  sethi  %hi(0xa8076000), %g1
a00d8a58:  a6 0b 60 0f  and  %o5, 0xf, %l3
a00d8a5c:  b8 10 60 b8  or  %g1, 0xb8, %i4
a00d8a60:  96 10 20 10  mov  0x10, %o3
a00d8a64:  a0 10 20 01  mov  1, %l0
a00d8a68:  83 2c 60 10  sll  %l1, 0x10, %g1
a00d8a6c:  91 30 60 10  srl  %g1, 0x10, %o0
a00d8a70:  80 a2 20 00  cmp  %o0, 0
a00d8a74:  02 80 00 2f  be  0xa00d8b30
a00d8a78:  98 10 20 00  clr  %o4
a00d8a7c:  83 2c e0 10  sll  %l3, 0x10, %g1
a00d8a80:  95 30 60 10  srl  %g1, 0x10, %o2
a00d8a84:  9e 0a e0 ff  and  %o3, 0xff, %o7
a00d8a88:  80 a2 80 0f  cmp  %o2, %o7
a00d8a8c:  16 80 00 28  bge  0xa00d8b2c
a00d8a90:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a00d8a94:  da 08 60 32  ldub  [ %g1 + 0x32 ], %o5	! 0xa8078832
a00d8a98:  03 2a 01 d8  sethi  %hi(0xa8076000), %g1
a00d8a9c:  aa 0c 20 ff  and  %l0, 0xff, %l5
a00d8aa0:  ba 10 60 a4  or  %g1, 0xa4, %i5
a00d8aa4:  03 28 02 ce  sethi  %hi(0xa00b3800), %g1
a00d8aa8:  a0 10 00 08  mov  %o0, %l0
a00d8aac:  a9 2b 60 02  sll  %o5, 2, %l4
a00d8ab0:  ae 10 60 3c  or  %g1, 0x3c, %l7
a00d8ab4:  a4 0a 60 7f  and  %o1, 0x7f, %l2
a00d8ab8:  ac 07 bf f8  add  %fp, -8, %l6
a00d8abc:  90 10 00 0a  mov  %o2, %o0
a00d8ac0:  9a 0b 20 ff  and  %o4, 0xff, %o5
a00d8ac4:  82 04 80 0d  add  %l2, %o5, %g1
a00d8ac8:  92 03 20 01  add  %o4, 1, %o1
a00d8acc:  82 00 40 0a  add  %g1, %o2, %g1
a00d8ad0:  80 a5 60 00  cmp  %l5, 0
a00d8ad4:  82 00 40 01  add  %g1, %g1, %g1
a00d8ad8:  98 07 00 0d  add  %i4, %o5, %o4
a00d8adc:  12 80 00 08  bne  0xa00d8afc
a00d8ae0:  96 05 80 0d  add  %l6, %o5, %o3
a00d8ae4:  c2 15 c0 01  lduh  [ %l7 + %g1 ], %g1
a00d8ae8:  83 28 60 02  sll  %g1, 2, %g1
a00d8aec:  da 07 40 14  ld  [ %i5 + %l4 ], %o5
a00d8af0:  c2 03 40 01  ld  [ %o5 + %g1 ], %g1
a00d8af4:  10 80 00 04  b  0xa00d8b04
a00d8af8:  c2 2a fe eb  stb  %g1, [ %o3 + -277 ]
a00d8afc:  c2 0b 00 08  ldub  [ %o4 + %o0 ], %g1
a00d8b00:  c2 2a fe eb  stb  %g1, [ %o3 + -277 ]
a00d8b04:  83 2c e0 10  sll  %l3, 0x10, %g1
a00d8b08:  95 30 60 10  srl  %g1, 0x10, %o2
a00d8b0c:  82 0a 60 ff  and  %o1, 0xff, %g1
a00d8b10:  98 10 00 09  mov  %o1, %o4
a00d8b14:  80 a0 40 10  cmp  %g1, %l0
a00d8b18:  1a 80 00 05  bcc  0xa00d8b2c
a00d8b1c:  9a 02 80 01  add  %o2, %g1, %o5
a00d8b20:  80 a3 40 0f  cmp  %o5, %o7
a00d8b24:  06 bf ff e8  bl  0xa00d8ac4
a00d8b28:  9a 0b 20 ff  and  %o4, 0xff, %o5
a00d8b2c:  83 2c 60 10  sll  %l1, 0x10, %g1
a00d8b30:  97 30 60 10  srl  %g1, 0x10, %o3
a00d8b34:  82 0b 20 ff  and  %o4, 0xff, %g1
a00d8b38:  80 a0 40 0b  cmp  %g1, %o3
a00d8b3c:  1a 80 00 09  bcc  0xa00d8b60
a00d8b40:  94 07 bf f8  add  %fp, -8, %o2
a00d8b44:  82 0b 20 ff  and  %o4, 0xff, %g1
a00d8b48:  98 03 20 01  inc  %o4
a00d8b4c:  82 02 80 01  add  %o2, %g1, %g1
a00d8b50:  9a 0b 20 ff  and  %o4, 0xff, %o5
a00d8b54:  80 a3 40 0b  cmp  %o5, %o3
a00d8b58:  0a bf ff fb  bcs  0xa00d8b44
a00d8b5c:  c0 28 7e eb  clrb  [ %g1 + -277 ]
a00d8b60:  d8 0f be e2  ldub  [ %fp + -286 ], %o4
a00d8b64:  98 03 20 03  add  %o4, 3, %o4
a00d8b68:  99 2b 20 10  sll  %o4, 0x10, %o4
a00d8b6c:  99 33 20 10  srl  %o4, 0x10, %o4
a00d8b70:  90 07 be e0  add  %fp, -288, %o0
a00d8b74:  92 10 20 02  mov  2, %o1
a00d8b78:  94 10 20 01  mov  1, %o2
a00d8b7c:  7f ff fb 68  call  0xa00d791c
a00d8b80:  96 10 20 07  mov  7, %o3
a00d8b84:  01 00 00 00  nop
a00d8b88:  81 c7 e0 08  ret
a00d8b8c:  81 e8 00 00  restore
