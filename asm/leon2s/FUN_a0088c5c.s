# leon2s FUN_a0088c5c 0xa0088c5c-0xa0088ea0 (580 bytes)
a0088c5c:  9d e3 bf 98  save  %sp, -104, %sp
a0088c60:  a4 10 20 00  clr  %l2
a0088c64:  80 8e 20 ff  btst  0xff, %i0
a0088c68:  82 10 20 00  clr  %g1
a0088c6c:  02 80 00 06  be  0xa0088c84
a0088c70:  90 10 00 12  mov  %l2, %o0
a0088c74:  03 2a 01 d8  sethi  %hi(0xa8076000), %g1
a0088c78:  d0 08 61 c0  ldub  [ %g1 + 0x1c0 ], %o0	! 0xa80761c0
a0088c7c:  03 2a 01 d8  sethi  %hi(0xa8076000), %g1
a0088c80:  c2 08 61 bf  ldub  [ %g1 + 0x1bf ], %g1	! 0xa80761bf
a0088c84:  a0 10 00 08  mov  %o0, %l0
a0088c88:  a6 08 60 ff  and  %g1, 0xff, %l3
a0088c8c:  b0 0c 20 ff  and  %l0, 0xff, %i0
a0088c90:  80 a6 00 13  cmp  %i0, %l3
a0088c94:  38 80 00 81  bgu,a   0xa0088e98
a0088c98:  b0 10 20 00  clr  %i0
a0088c9c:  7f ff ff 95  call  0xa0088af0
a0088ca0:  90 10 00 18  mov  %i0, %o0
a0088ca4:  80 8a 20 ff  btst  0xff, %o0
a0088ca8:  22 bf ff f9  be,a   0xa0088c8c
a0088cac:  a0 04 20 01  inc  %l0
a0088cb0:  92 10 20 03  mov  3, %o1
a0088cb4:  40 00 7b 00  call  0xa00a78b4
a0088cb8:  90 10 00 18  mov  %i0, %o0
a0088cbc:  a2 0a 20 1f  and  %o0, 0x1f, %l1
a0088cc0:  90 10 00 18  mov  %i0, %o0
a0088cc4:  7f ff f8 65  call  0xa0086e58
a0088cc8:  92 10 00 19  mov  %i1, %o1
a0088ccc:  c2 0e 40 00  ldub  [ %i1 ], %g1
a0088cd0:  80 88 60 80  btst  0x80, %g1
a0088cd4:  12 80 00 0a  bne  0xa0088cfc
a0088cd8:  82 10 20 01  mov  1, %g1
a0088cdc:  da 0e 80 00  ldub  [ %i2 ], %o5
a0088ce0:  83 28 40 18  sll  %g1, %i0, %g1
a0088ce4:  82 2b 40 01  andn  %o5, %g1, %g1
a0088ce8:  80 a6 20 00  cmp  %i0, 0
a0088cec:  12 80 00 69  bne  0xa0088e90
a0088cf0:  c2 2e 80 00  stb  %g1, [ %i2 ]
a0088cf4:  10 80 00 64  b  0xa0088e84
a0088cf8:  a4 10 20 01  mov  1, %l2
a0088cfc:  7f ff f6 6a  call  0xa00866a4
a0088d00:  01 00 00 00  nop
a0088d04:  80 8a 20 ff  btst  0xff, %o0
a0088d08:  02 80 00 08  be  0xa0088d28
a0088d0c:  90 0c 60 1f  and  %l1, 0x1f, %o0
a0088d10:  80 a6 20 00  cmp  %i0, 0
a0088d14:  12 80 00 05  bne  0xa0088d28
a0088d18:  01 00 00 00  nop
a0088d1c:  7f c5 0c d7  call  0x9f1cc078
a0088d20:  d0 0e 60 03  ldub  [ %i1 + 3 ], %o0
a0088d24:  90 0c 60 1f  and  %l1, 0x1f, %o0
a0088d28:  7f ff f9 8f  call  0xa0087364
a0088d2c:  92 10 00 19  mov  %i1, %o1
a0088d30:  90 0a 20 ff  and  %o0, 0xff, %o0
a0088d34:  80 a2 20 05  cmp  %o0, 5
a0088d38:  02 80 00 06  be  0xa0088d50
a0088d3c:  11 28 01 a2  sethi  %hi(0xa0068800), %o0
a0088d40:  90 12 22 50  or  %o0, 0x250, %o0	! 0xa0068a50
a0088d44:  7f ff a8 c0  call  0xa0073044
a0088d48:  92 0c 20 ff  and  %l0, 0xff, %o1
a0088d4c:  a4 10 20 01  mov  1, %l2
a0088d50:  c2 0e 60 06  ldub  [ %i1 + 6 ], %g1
a0088d54:  80 88 60 01  btst  1, %g1
a0088d58:  22 80 00 02  be,a   0xa0088d60
a0088d5c:  a4 10 20 01  mov  1, %l2
a0088d60:  7f ff f7 9e  call  0xa0086bd8
a0088d64:  01 00 00 00  nop
a0088d68:  80 8a 20 ff  btst  0xff, %o0
a0088d6c:  02 80 00 47  be  0xa0088e88
a0088d70:  80 8c a0 ff  btst  0xff, %l2
a0088d74:  80 8c 20 ff  btst  0xff, %l0
a0088d78:  12 80 00 44  bne  0xa0088e88
a0088d7c:  80 8c a0 ff  btst  0xff, %l2
a0088d80:  7f ff f2 dc  call  0xa00858f0
a0088d84:  90 10 20 00  clr  %o0
a0088d88:  90 0a 20 ff  and  %o0, 0xff, %o0
a0088d8c:  80 a2 20 71  cmp  %o0, 0x71
a0088d90:  12 80 00 0a  bne  0xa0088db8
a0088d94:  b0 10 3f ff  mov  -1, %i0
a0088d98:  40 00 91 39  call  0xa00ad27c
a0088d9c:  90 10 20 00  clr  %o0
a0088da0:  90 0a 20 ff  and  %o0, 0xff, %o0
a0088da4:  80 a2 20 01  cmp  %o0, 1
a0088da8:  32 80 00 0c  bne,a   0xa0088dd8
a0088dac:  90 0e 20 ff  and  %i0, 0xff, %o0
a0088db0:  10 80 00 06  b  0xa0088dc8
a0088db4:  90 10 20 00  clr  %o0
a0088db8:  80 a2 20 81  cmp  %o0, 0x81
a0088dbc:  12 80 00 07  bne  0xa0088dd8
a0088dc0:  90 0e 20 ff  and  %i0, 0xff, %o0
a0088dc4:  90 10 20 01  mov  1, %o0
a0088dc8:  40 00 77 7c  call  0xa00a6bb8
a0088dcc:  92 10 20 80  mov  0x80, %o1
a0088dd0:  b0 10 00 08  mov  %o0, %i0
a0088dd4:  90 0e 20 ff  and  %i0, 0xff, %o0
a0088dd8:  80 a2 20 ff  cmp  %o0, 0xff
a0088ddc:  02 80 00 2a  be  0xa0088e84
a0088de0:  b0 8a 20 03  andcc  %o0, 3, %i0
a0088de4:  12 80 00 0b  bne  0xa0088e10
a0088de8:  80 a6 20 01  cmp  %i0, 1
a0088dec:  90 10 20 00  clr  %o0
a0088df0:  40 00 7a b1  call  0xa00a78b4
a0088df4:  92 10 20 02  mov  2, %o1
a0088df8:  90 0a 20 ff  and  %o0, 0xff, %o0
a0088dfc:  80 a2 20 06  cmp  %o0, 6
a0088e00:  32 80 00 21  bne,a   0xa0088e84
a0088e04:  a4 10 20 01  mov  1, %l2
a0088e08:  10 80 00 0d  b  0xa0088e3c
a0088e0c:  80 a6 20 02  cmp  %i0, 2
a0088e10:  12 80 00 0b  bne  0xa0088e3c
a0088e14:  80 a6 20 02  cmp  %i0, 2
a0088e18:  90 0c 20 ff  and  %l0, 0xff, %o0
a0088e1c:  40 00 7a a6  call  0xa00a78b4
a0088e20:  92 10 20 02  mov  2, %o1
a0088e24:  90 0a 20 ff  and  %o0, 0xff, %o0
a0088e28:  80 a2 20 0a  cmp  %o0, 0xa
a0088e2c:  32 80 00 16  bne,a   0xa0088e84
a0088e30:  a4 10 20 01  mov  1, %l2
a0088e34:  10 80 00 0a  b  0xa0088e5c
a0088e38:  80 a6 20 03  cmp  %i0, 3
a0088e3c:  32 80 00 08  bne,a   0xa0088e5c
a0088e40:  80 a6 20 03  cmp  %i0, 3
a0088e44:  90 0c 20 ff  and  %l0, 0xff, %o0
a0088e48:  40 00 7a 9b  call  0xa00a78b4
a0088e4c:  92 10 20 02  mov  2, %o1
a0088e50:  90 0a 20 ff  and  %o0, 0xff, %o0
a0088e54:  10 80 00 09  b  0xa0088e78
a0088e58:  80 a2 20 14  cmp  %o0, 0x14
a0088e5c:  12 80 00 0b  bne  0xa0088e88
a0088e60:  80 8c a0 ff  btst  0xff, %l2
a0088e64:  90 0c 20 ff  and  %l0, 0xff, %o0
a0088e68:  40 00 7a 93  call  0xa00a78b4
a0088e6c:  92 10 20 02  mov  2, %o1
a0088e70:  90 0a 20 ff  and  %o0, 0xff, %o0
a0088e74:  80 a2 20 1e  cmp  %o0, 0x1e
a0088e78:  02 80 00 04  be  0xa0088e88
a0088e7c:  80 8c a0 ff  btst  0xff, %l2
a0088e80:  a4 10 20 01  mov  1, %l2
a0088e84:  80 8c a0 ff  btst  0xff, %l2
a0088e88:  12 80 00 04  bne  0xa0088e98
a0088e8c:  b0 10 20 01  mov  1, %i0
a0088e90:  10 bf ff 7f  b  0xa0088c8c
a0088e94:  a0 04 20 01  inc  %l0
a0088e98:  81 c7 e0 08  ret
a0088e9c:  81 e8 00 00  restore
