# leon2s FUN_a0079b84 0xa0079b84-0xa0079e00 (636 bytes)
a0079b84:  9d e3 bf 98  save  %sp, -104, %sp
a0079b88:  b4 0e a0 ff  and  %i2, 0xff, %i2
a0079b8c:  b4 1e a0 05  xor  %i2, 5, %i2
a0079b90:  80 a0 00 1a  cmp  %g0, %i2
a0079b94:  b6 0e e0 ff  and  %i3, 0xff, %i3
a0079b98:  9a 60 3f ff  subx  %g0, -1, %o5
a0079b9c:  b6 1e e0 08  xor  %i3, 8, %i3
a0079ba0:  80 a0 00 1b  cmp  %g0, %i3
a0079ba4:  82 60 3f ff  subx  %g0, -1, %g1
a0079ba8:  a6 0e 60 ff  and  %i1, 0xff, %l3
a0079bac:  aa 13 40 01  or  %o5, %g1, %l5
a0079bb0:  80 a4 e0 03  cmp  %l3, 3
a0079bb4:  a8 10 20 00  clr  %l4
a0079bb8:  b2 10 20 00  clr  %i1
a0079bbc:  b4 10 20 00  clr  %i2
a0079bc0:  a4 10 20 00  clr  %l2
a0079bc4:  b6 10 20 00  clr  %i3
a0079bc8:  18 80 00 2c  bgu  0xa0079c78
a0079bcc:  96 10 20 00  clr  %o3
a0079bd0:  03 28 02 ce  sethi  %hi(0xa00b3800), %g1
a0079bd4:  82 10 62 f4  or  %g1, 0x2f4, %g1	! 0xa00b3af4
a0079bd8:  a6 04 c0 13  add  %l3, %l3, %l3
a0079bdc:  e4 10 40 13  lduh  [ %g1 + %l3 ], %l2
a0079be0:  a2 0e 20 ff  and  %i0, 0xff, %l1
a0079be4:  92 10 00 12  mov  %l2, %o1
a0079be8:  40 00 b5 cb  call  0xa00a7314
a0079bec:  90 10 00 11  mov  %l1, %o0
a0079bf0:  21 07 c0 00  sethi  %hi(0x1f000000), %l0
a0079bf4:  03 28 02 ce  sethi  %hi(0xa00b3800), %g1
a0079bf8:  82 10 62 ec  or  %g1, 0x2ec, %g1	! 0xa00b3aec
a0079bfc:  90 0a 00 10  and  %o0, %l0, %o0
a0079c00:  e6 10 40 13  lduh  [ %g1 + %l3 ], %l3
a0079c04:  a9 32 20 18  srl  %o0, 0x18, %l4
a0079c08:  92 10 00 13  mov  %l3, %o1
a0079c0c:  40 00 b5 c2  call  0xa00a7314
a0079c10:  90 10 00 11  mov  %l1, %o0
a0079c14:  90 0a 00 10  and  %o0, %l0, %o0
a0079c18:  b3 32 20 18  srl  %o0, 0x18, %i1
a0079c1c:  92 10 00 12  mov  %l2, %o1
a0079c20:  40 00 b5 bd  call  0xa00a7314
a0079c24:  90 10 00 11  mov  %l1, %o0
a0079c28:  21 00 03 c0  sethi  %hi(0xf0000), %l0
a0079c2c:  90 0a 00 10  and  %o0, %l0, %o0
a0079c30:  b5 32 20 10  srl  %o0, 0x10, %i2
a0079c34:  92 10 00 13  mov  %l3, %o1
a0079c38:  40 00 b5 b7  call  0xa00a7314
a0079c3c:  90 10 00 11  mov  %l1, %o0
a0079c40:  90 0a 00 10  and  %o0, %l0, %o0
a0079c44:  92 10 00 12  mov  %l2, %o1
a0079c48:  a5 32 20 10  srl  %o0, 0x10, %l2
a0079c4c:  90 10 00 11  mov  %l1, %o0
a0079c50:  40 00 b5 b1  call  0xa00a7314
a0079c54:  21 00 00 07  sethi  %hi(0x1c00), %l0
a0079c58:  a0 14 23 00  or  %l0, 0x300, %l0	! 0x1f00
a0079c5c:  90 0a 00 10  and  %o0, %l0, %o0
a0079c60:  b7 32 20 08  srl  %o0, 8, %i3
a0079c64:  90 10 00 11  mov  %l1, %o0
a0079c68:  40 00 b5 ab  call  0xa00a7314
a0079c6c:  92 10 00 13  mov  %l3, %o1
a0079c70:  90 0a 00 10  and  %o0, %l0, %o0
a0079c74:  97 32 20 08  srl  %o0, 8, %o3
a0079c78:  90 1e a0 08  xor  %i2, 8, %o0
a0079c7c:  82 0a 20 ff  and  %o0, 0xff, %g1
a0079c80:  80 a0 60 07  cmp  %g1, 7
a0079c84:  82 10 20 08  mov  8, %g1
a0079c88:  98 20 40 08  sub  %g1, %o0, %o4
a0079c8c:  a4 1c a0 08  xor  %l2, 8, %l2
a0079c90:  b6 1e e0 10  xor  %i3, 0x10, %i3
a0079c94:  08 80 00 03  bleu  0xa0079ca0
a0079c98:  96 1a e0 10  xor  %o3, 0x10, %o3
a0079c9c:  98 02 3f f8  add  %o0, -8, %o4
a0079ca0:  82 0c a0 ff  and  %l2, 0xff, %g1
a0079ca4:  80 a0 60 07  cmp  %g1, 7
a0079ca8:  82 10 20 08  mov  8, %g1
a0079cac:  08 80 00 03  bleu  0xa0079cb8
a0079cb0:  82 20 40 12  sub  %g1, %l2, %g1
a0079cb4:  82 04 bf f8  add  %l2, -8, %g1
a0079cb8:  9a 08 60 ff  and  %g1, 0xff, %o5
a0079cbc:  92 10 00 01  mov  %g1, %o1
a0079cc0:  82 0b 20 ff  and  %o4, 0xff, %g1
a0079cc4:  80 a3 40 01  cmp  %o5, %g1
a0079cc8:  2a 80 00 02  bcs,a   0xa0079cd0
a0079ccc:  92 10 00 0c  mov  %o4, %o1
a0079cd0:  82 0e e0 ff  and  %i3, 0xff, %g1
a0079cd4:  80 a0 60 0f  cmp  %g1, 0xf
a0079cd8:  82 10 20 10  mov  0x10, %g1
a0079cdc:  08 80 00 03  bleu  0xa0079ce8
a0079ce0:  98 20 40 1b  sub  %g1, %i3, %o4
a0079ce4:  98 06 ff f0  add  %i3, -16, %o4
a0079ce8:  82 0a e0 ff  and  %o3, 0xff, %g1
a0079cec:  80 a0 60 0f  cmp  %g1, 0xf
a0079cf0:  82 10 20 10  mov  0x10, %g1
a0079cf4:  08 80 00 03  bleu  0xa0079d00
a0079cf8:  82 20 40 0b  sub  %g1, %o3, %g1
a0079cfc:  82 02 ff f0  add  %o3, -16, %g1
a0079d00:  9a 08 60 ff  and  %g1, 0xff, %o5
a0079d04:  96 10 00 01  mov  %g1, %o3
a0079d08:  82 0b 20 ff  and  %o4, 0xff, %g1
a0079d0c:  80 a3 40 01  cmp  %o5, %g1
a0079d10:  2a 80 00 02  bcs,a   0xa0079d18
a0079d14:  96 10 00 0c  mov  %o4, %o3
a0079d18:  9a 0d 20 ff  and  %l4, 0xff, %o5
a0079d1c:  82 0e 60 ff  and  %i1, 0xff, %g1
a0079d20:  80 a3 40 01  cmp  %o5, %g1
a0079d24:  18 80 00 03  bgu  0xa0079d30
a0079d28:  90 10 00 19  mov  %i1, %o0
a0079d2c:  90 10 00 14  mov  %l4, %o0
a0079d30:  98 0a 20 ff  and  %o0, 0xff, %o4
a0079d34:  80 a3 20 05  cmp  %o4, 5
a0079d38:  18 80 00 03  bgu  0xa0079d44
a0079d3c:  94 10 20 01  mov  1, %o2
a0079d40:  94 10 20 00  clr  %o2
a0079d44:  9a 0a 60 ff  and  %o1, 0xff, %o5
a0079d48:  80 a3 60 04  cmp  %o5, 4
a0079d4c:  82 60 20 00  subx  %g0, 0, %g1
a0079d50:  80 88 40 0a  btst  %g1, %o2
a0079d54:  02 80 00 0f  be  0xa0079d90
a0079d58:  80 a3 20 05  cmp  %o4, 5
a0079d5c:  80 a5 60 00  cmp  %l5, 0
a0079d60:  02 80 00 0c  be  0xa0079d90
a0079d64:  80 a3 20 05  cmp  %o4, 5
a0079d68:  82 10 20 08  mov  8, %g1
a0079d6c:  82 20 40 0d  sub  %g1, %o5, %g1
a0079d70:  9b 2b 20 03  sll  %o4, 3, %o5
a0079d74:  83 28 60 03  sll  %g1, 3, %g1
a0079d78:  9a 23 40 0c  sub  %o5, %o4, %o5
a0079d7c:  9a 03 40 01  add  %o5, %g1, %o5
a0079d80:  82 0a e0 ff  and  %o3, 0xff, %g1
a0079d84:  9a 23 40 01  sub  %o5, %g1, %o5
a0079d88:  10 80 00 1a  b  0xa0079df0
a0079d8c:  82 03 60 10  add  %o5, 0x10, %g1
a0079d90:  18 80 00 03  bgu  0xa0079d9c
a0079d94:  98 10 20 01  mov  1, %o4
a0079d98:  98 10 20 00  clr  %o4
a0079d9c:  80 a3 60 04  cmp  %o5, 4
a0079da0:  82 40 20 00  addx  %g0, 0, %g1
a0079da4:  80 8b 00 01  btst  %o4, %g1
a0079da8:  22 80 00 0f  be,a   0xa0079de4
a0079dac:  82 0a 20 ff  and  %o0, 0xff, %g1
a0079db0:  80 a5 60 00  cmp  %l5, 0
a0079db4:  32 80 00 0c  bne,a   0xa0079de4
a0079db8:  82 0a 20 ff  and  %o0, 0xff, %g1
a0079dbc:  82 10 20 08  mov  8, %g1
a0079dc0:  82 20 40 0d  sub  %g1, %o5, %g1
a0079dc4:  9a 0a e0 ff  and  %o3, 0xff, %o5
a0079dc8:  82 00 40 01  add  %g1, %g1, %g1
a0079dcc:  82 20 40 0d  sub  %g1, %o5, %g1
a0079dd0:  82 00 40 01  add  %g1, %g1, %g1
a0079dd4:  9a 0a 20 ff  and  %o0, 0xff, %o5
a0079dd8:  82 00 40 0d  add  %g1, %o5, %g1
a0079ddc:  10 80 00 05  b  0xa0079df0
a0079de0:  82 00 60 20  add  %g1, 0x20, %g1
a0079de4:  9a 0a 60 ff  and  %o1, 0xff, %o5
a0079de8:  82 20 40 0d  sub  %g1, %o5, %g1
a0079dec:  82 00 60 08  add  %g1, 8, %g1
a0079df0:  b1 28 60 10  sll  %g1, 0x10, %i0
a0079df4:  b1 36 20 10  srl  %i0, 0x10, %i0
a0079df8:  81 c7 e0 08  ret
a0079dfc:  81 e8 00 00  restore
