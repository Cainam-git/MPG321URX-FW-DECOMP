# leon2s FUN_a00d9a78 0xa00d9a78-0xa00d9be4 (364 bytes)
a00d9a78:  9d e3 bf 78  save  %sp, -136, %sp
a00d9a7c:  a0 07 bf e0  add  %fp, -32, %l0
a00d9a80:  92 10 20 00  clr  %o1
a00d9a84:  94 10 20 13  mov  0x13, %o2
a00d9a88:  40 3b 9e c9  call  0xa0fc15ac
a00d9a8c:  90 10 00 10  mov  %l0, %o0
a00d9a90:  c2 07 bf f0  ld  [ %fp + -16 ], %g1
a00d9a94:  1b 00 20 00  sethi  %hi(0x800000), %o5
a00d9a98:  82 10 40 0d  or  %g1, %o5, %g1
a00d9a9c:  1b 00 10 00  sethi  %hi(0x400000), %o5
a00d9aa0:  82 10 40 0d  or  %g1, %o5, %g1
a00d9aa4:  19 00 0f c0  sethi  %hi(0x3f0000), %o4
a00d9aa8:  98 28 40 0c  andn  %g1, %o4, %o4
a00d9aac:  c2 07 bf e0  ld  [ %fp + -32 ], %g1
a00d9ab0:  1b 3c 00 00  sethi  %hi(0xf0000000), %o5
a00d9ab4:  9a 28 40 0d  andn  %g1, %o5, %o5
a00d9ab8:  03 00 00 80  sethi  %hi(0x20000), %g1
a00d9abc:  98 13 00 01  or  %o4, %g1, %o4
a00d9ac0:  03 04 00 00  sethi  %hi(0x10000000), %g1
a00d9ac4:  9a 13 40 01  or  %o5, %g1, %o5
a00d9ac8:  03 00 00 20  sethi  %hi(0x8000), %g1
a00d9acc:  98 13 00 01  or  %o4, %g1, %o4
a00d9ad0:  03 03 c0 00  sethi  %hi(0xf000000), %g1
a00d9ad4:  82 2b 40 01  andn  %o5, %g1, %g1
a00d9ad8:  1b 00 00 10  sethi  %hi(0x4000), %o5
a00d9adc:  98 13 00 0d  or  %o4, %o5, %o4
a00d9ae0:  c2 27 bf e0  st  %g1, [ %fp + -32 ]
a00d9ae4:  d8 27 bf f0  st  %o4, [ %fp + -16 ]
a00d9ae8:  90 10 00 10  mov  %l0, %o0
a00d9aec:  92 10 20 03  mov  3, %o1
a00d9af0:  7f ff f3 d9  call  0xa00d6a54
a00d9af4:  94 10 20 01  mov  1, %o2
a00d9af8:  da 07 bf e0  ld  [ %fp + -32 ], %o5
a00d9afc:  9b 33 60 1c  srl  %o5, 0x1c, %o5
a00d9b00:  9a 03 7f ff  add  %o5, -1, %o5
a00d9b04:  27 2a 01 e1  sethi  %hi(0xa8078400), %l3
a00d9b08:  83 33 60 1f  srl  %o5, 0x1f, %g1
a00d9b0c:  82 03 40 01  add  %o5, %g1, %g1
a00d9b10:  d8 0c e3 ff  ldub  [ %l3 + 0x3ff ], %o4
a00d9b14:  98 0b 20 0f  and  %o4, 0xf, %o4
a00d9b18:  97 38 60 01  sra  %g1, 1, %o3
a00d9b1c:  82 03 00 0c  add  %o4, %o4, %g1
a00d9b20:  a4 00 40 0c  add  %g1, %o4, %l2
a00d9b24:  80 8b 60 01  btst  1, %o5
a00d9b28:  02 80 00 03  be  0xa00d9b34
a00d9b2c:  a0 10 00 0b  mov  %o3, %l0
a00d9b30:  a0 02 e0 01  add  %o3, 1, %l0
a00d9b34:  da 17 bf f0  lduh  [ %fp + -16 ], %o5
a00d9b38:  82 10 20 14  mov  0x14, %g1
a00d9b3c:  a2 0b 60 3f  and  %o5, 0x3f, %l1
a00d9b40:  96 10 20 30  mov  0x30, %o3
a00d9b44:  c2 2f bf d8  stb  %g1, [ %fp + -40 ]
a00d9b48:  90 07 bf d8  add  %fp, -40, %o0
a00d9b4c:  92 10 20 01  mov  1, %o1
a00d9b50:  7f ff ff 8e  call  0xa00d9988
a00d9b54:  94 10 20 00  clr  %o2
a00d9b58:  9e 0c 60 ff  and  %l1, 0xff, %o7
a00d9b5c:  d0 2f bf d9  stb  %o0, [ %fp + -39 ]
a00d9b60:  80 a3 e0 00  cmp  %o7, 0
a00d9b64:  02 80 00 12  be  0xa00d9bac
a00d9b68:  96 10 20 00  clr  %o3
a00d9b6c:  03 2a 01 e9  sethi  %hi(0xa807a400), %g1
a00d9b70:  9b 2c a0 04  sll  %l2, 4, %o5
a00d9b74:  82 10 61 20  or  %g1, 0x120, %g1
a00d9b78:  92 03 40 01  add  %o5, %g1, %o1
a00d9b7c:  94 0c 20 ff  and  %l0, 0xff, %o2
a00d9b80:  90 07 bf f8  add  %fp, -8, %o0
a00d9b84:  82 0a e0 ff  and  %o3, 0xff, %g1
a00d9b88:  9a 02 00 01  add  %o0, %g1, %o5
a00d9b8c:  82 02 40 01  add  %o1, %g1, %g1
a00d9b90:  96 02 e0 01  inc  %o3
a00d9b94:  82 00 40 0a  add  %g1, %o2, %g1
a00d9b98:  da 0b 7f e0  ldub  [ %o5 + -32 ], %o5
a00d9b9c:  98 0a e0 ff  and  %o3, 0xff, %o4
a00d9ba0:  80 a3 00 0f  cmp  %o4, %o7
a00d9ba4:  0a bf ff f8  bcs  0xa00d9b84
a00d9ba8:  da 28 60 03  stb  %o5, [ %g1 + 3 ]
a00d9bac:  9a 04 00 11  add  %l0, %l1, %o5
a00d9bb0:  03 2a 01 e7  sethi  %hi(0xa8079c00), %g1
a00d9bb4:  d6 0c e3 ff  ldub  [ %l3 + 0x3ff ], %o3
a00d9bb8:  9a 03 60 03  add  %o5, 3, %o5
a00d9bbc:  82 10 60 88  or  %g1, 0x88, %g1
a00d9bc0:  da 28 40 0b  stb  %o5, [ %g1 + %o3 ]
a00d9bc4:  98 02 e0 01  add  %o3, 1, %o4
a00d9bc8:  98 0b 20 0f  and  %o4, 0xf, %o4
a00d9bcc:  9a 10 20 01  mov  1, %o5
a00d9bd0:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a00d9bd4:  d8 2c e3 ff  stb  %o4, [ %l3 + 0x3ff ]
a00d9bd8:  da 28 60 54  stb  %o5, [ %g1 + 0x54 ]
a00d9bdc:  81 c7 e0 08  ret
a00d9be0:  81 e8 00 00  restore
