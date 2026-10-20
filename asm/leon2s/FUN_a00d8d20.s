# leon2s FUN_a00d8d20 0xa00d8d20-0xa00d8f58 (568 bytes)
a00d8d20:  9d e3 be 70  save  %sp, -400, %sp
a00d8d24:  a0 07 bf d8  add  %fp, -40, %l0
a00d8d28:  92 10 20 00  clr  %o1
a00d8d2c:  94 10 20 1e  mov  0x1e, %o2
a00d8d30:  40 3b a2 1f  call  0xa0fc15ac
a00d8d34:  90 10 00 10  mov  %l0, %o0
a00d8d38:  92 10 20 00  clr  %o1
a00d8d3c:  90 10 00 10  mov  %l0, %o0
a00d8d40:  94 10 20 01  mov  1, %o2
a00d8d44:  7f ff f9 9c  call  0xa00d73b4
a00d8d48:  96 10 20 19  mov  0x19, %o3
a00d8d4c:  d2 07 bf d8  ld  [ %fp + -40 ], %o1
a00d8d50:  83 32 60 10  srl  %o1, 0x10, %g1
a00d8d54:  82 08 60 03  and  %g1, 3, %g1
a00d8d58:  80 a0 60 02  cmp  %g1, 2
a00d8d5c:  12 80 00 0e  bne  0xa00d8d94
a00d8d60:  a4 10 20 00  clr  %l2
a00d8d64:  83 32 60 08  srl  %o1, 8, %g1
a00d8d68:  82 08 60 7f  and  %g1, 0x7f, %g1
a00d8d6c:  80 a0 60 30  cmp  %g1, 0x30
a00d8d70:  32 80 00 0a  bne,a   0xa00d8d98
a00d8d74:  e4 0f bf dc  ldub  [ %fp + -36 ], %l2
a00d8d78:  c2 0f bf dc  ldub  [ %fp + -36 ], %g1
a00d8d7c:  80 a0 60 01  cmp  %g1, 1
a00d8d80:  12 80 00 07  bne  0xa00d8d9c
a00d8d84:  c2 07 be d0  ld  [ %fp + -304 ], %g1
a00d8d88:  c2 0f bf e9  ldub  [ %fp + -23 ], %g1
a00d8d8c:  10 80 00 03  b  0xa00d8d98
a00d8d90:  a4 00 61 00  add  %g1, 0x100, %l2
a00d8d94:  e4 0f bf dc  ldub  [ %fp + -36 ], %l2
a00d8d98:  c2 07 be d0  ld  [ %fp + -304 ], %g1
a00d8d9c:  19 1f c0 00  sethi  %hi(0x7f000000), %o4
a00d8da0:  98 28 40 0c  andn  %g1, %o4, %o4
a00d8da4:  d4 0f bf f4  ldub  [ %fp + -12 ], %o2
a00d8da8:  94 0a a0 7f  and  %o2, 0x7f, %o2
a00d8dac:  03 08 80 00  sethi  %hi(0x22000000), %g1
a00d8db0:  98 13 00 01  or  %o4, %g1, %o4
a00d8db4:  9a 02 bf b0  add  %o2, -80, %o5
a00d8db8:  97 32 60 14  srl  %o1, 0x14, %o3
a00d8dbc:  9a 0b 60 ff  and  %o5, 0xff, %o5
a00d8dc0:  96 0a e0 0f  and  %o3, 0xf, %o3
a00d8dc4:  03 00 03 c0  sethi  %hi(0xf0000), %g1
a00d8dc8:  80 a3 60 02  cmp  %o5, 2
a00d8dcc:  82 2b 00 01  andn  %o4, %g1, %g1
a00d8dd0:  97 2a e0 10  sll  %o3, 0x10, %o3
a00d8dd4:  9a 60 20 00  subx  %g0, 0, %o5
a00d8dd8:  82 10 40 0b  or  %g1, %o3, %g1
a00d8ddc:  94 1a a0 53  xor  %o2, 0x53, %o2
a00d8de0:  80 a0 00 0a  cmp  %g0, %o2
a00d8de4:  c2 27 be d0  st  %g1, [ %fp + -304 ]
a00d8de8:  9a 0b 60 01  and  %o5, 1, %o5
a00d8dec:  82 60 3f ff  subx  %g0, -1, %g1
a00d8df0:  d8 0f bf f5  ldub  [ %fp + -11 ], %o4
a00d8df4:  9a 93 40 01  orcc  %o5, %g1, %o5
a00d8df8:  02 80 00 40  be  0xa00d8ef8
a00d8dfc:  d8 2f be d2  stb  %o4, [ %fp + -302 ]
a00d8e00:  83 32 60 10  srl  %o1, 0x10, %g1
a00d8e04:  82 08 60 f0  and  %g1, 0xf0, %g1
a00d8e08:  80 a0 60 80  cmp  %g1, 0x80
a00d8e0c:  02 80 00 15  be  0xa00d8e60
a00d8e10:  96 0b 20 ff  and  %o4, 0xff, %o3
a00d8e14:  80 a2 e0 00  cmp  %o3, 0
a00d8e18:  02 80 00 44  be  0xa00d8f28
a00d8e1c:  a0 10 20 00  clr  %l0
a00d8e20:  9b 2c a0 10  sll  %l2, 0x10, %o5
a00d8e24:  03 27 c6 c0  sethi  %hi(0x9f1b0000), %g1
a00d8e28:  9b 33 60 10  srl  %o5, 0x10, %o5
a00d8e2c:  82 10 60 00  mov  %g1, %g1
a00d8e30:  94 03 40 01  add  %o5, %g1, %o2
a00d8e34:  92 07 bf f8  add  %fp, -8, %o1
a00d8e38:  82 0c 20 ff  and  %l0, 0xff, %g1
a00d8e3c:  d8 0a 80 01  ldub  [ %o2 + %g1 ], %o4
a00d8e40:  a0 04 20 01  inc  %l0
a00d8e44:  82 02 40 01  add  %o1, %g1, %g1
a00d8e48:  9a 0c 20 ff  and  %l0, 0xff, %o5
a00d8e4c:  80 a3 40 0b  cmp  %o5, %o3
a00d8e50:  0a bf ff fa  bcs  0xa00d8e38
a00d8e54:  d8 28 7e db  stb  %o4, [ %g1 + -293 ]
a00d8e58:  10 80 00 35  b  0xa00d8f2c
a00d8e5c:  d8 0f be d2  ldub  [ %fp + -302 ], %o4
a00d8e60:  80 a2 e0 00  cmp  %o3, 0
a00d8e64:  02 80 00 31  be  0xa00d8f28
a00d8e68:  a0 10 20 00  clr  %l0
a00d8e6c:  23 2a 01 e2  sethi  %hi(0xa8078800), %l1
a00d8e70:  40 3b a1 89  call  0xa0fc1494
a00d8e74:  d0 0c 60 32  ldub  [ %l1 + 0x32 ], %o0	! 0xa8078832
a00d8e78:  83 2c a0 10  sll  %l2, 0x10, %g1
a00d8e7c:  1b 27 c7 32  sethi  %hi(0x9f1cc800), %o5
a00d8e80:  83 30 60 10  srl  %g1, 0x10, %g1
a00d8e84:  9a 13 60 f0  or  %o5, 0xf0, %o5
a00d8e88:  98 00 40 0d  add  %g1, %o5, %o4
a00d8e8c:  82 0c 20 ff  and  %l0, 0xff, %g1
a00d8e90:  90 0a 20 ff  and  %o0, 0xff, %o0
a00d8e94:  80 a2 20 01  cmp  %o0, 1
a00d8e98:  02 80 00 0e  be  0xa00d8ed0
a00d8e9c:  9a 07 80 01  add  %fp, %g1, %o5
a00d8ea0:  40 3b a1 7d  call  0xa0fc1494
a00d8ea4:  d0 0c 60 32  ldub  [ %l1 + 0x32 ], %o0
a00d8ea8:  83 2c a0 10  sll  %l2, 0x10, %g1
a00d8eac:  1b 27 c7 31  sethi  %hi(0x9f1cc400), %o5
a00d8eb0:  83 30 60 10  srl  %g1, 0x10, %g1
a00d8eb4:  9a 13 63 70  or  %o5, 0x370, %o5
a00d8eb8:  98 00 40 0d  add  %g1, %o5, %o4
a00d8ebc:  90 0a 20 ff  and  %o0, 0xff, %o0
a00d8ec0:  82 0c 20 ff  and  %l0, 0xff, %g1
a00d8ec4:  80 a2 20 02  cmp  %o0, 2
a00d8ec8:  12 80 00 04  bne  0xa00d8ed8
a00d8ecc:  9a 07 80 01  add  %fp, %g1, %o5
a00d8ed0:  c2 0b 00 01  ldub  [ %o4 + %g1 ], %g1
a00d8ed4:  c2 2b 7e d3  stb  %g1, [ %o5 + -301 ]
a00d8ed8:  a0 04 20 01  inc  %l0
a00d8edc:  9a 0c 20 ff  and  %l0, 0xff, %o5
a00d8ee0:  c2 0f bf f5  ldub  [ %fp + -11 ], %g1
a00d8ee4:  80 a3 40 01  cmp  %o5, %g1
a00d8ee8:  2a bf ff e2  bcs,a   0xa00d8e70
a00d8eec:  23 2a 01 e2  sethi  %hi(0xa8078800), %l1
a00d8ef0:  10 80 00 0f  b  0xa00d8f2c
a00d8ef4:  d8 0f be d2  ldub  [ %fp + -302 ], %o4
a00d8ef8:  98 0b 20 ff  and  %o4, 0xff, %o4
a00d8efc:  80 a3 40 0c  cmp  %o5, %o4
a00d8f00:  1a 80 00 0a  bcc  0xa00d8f28
a00d8f04:  a0 10 20 00  clr  %l0
a00d8f08:  96 07 bf f8  add  %fp, -8, %o3
a00d8f0c:  82 0c 20 ff  and  %l0, 0xff, %g1
a00d8f10:  a0 04 20 01  inc  %l0
a00d8f14:  82 02 c0 01  add  %o3, %g1, %g1
a00d8f18:  9a 0c 20 ff  and  %l0, 0xff, %o5
a00d8f1c:  80 a3 40 0c  cmp  %o5, %o4
a00d8f20:  0a bf ff fb  bcs  0xa00d8f0c
a00d8f24:  c0 28 7e db  clrb  [ %g1 + -293 ]
a00d8f28:  d8 0f be d2  ldub  [ %fp + -302 ], %o4
a00d8f2c:  98 03 20 03  add  %o4, 3, %o4
a00d8f30:  99 2b 20 10  sll  %o4, 0x10, %o4
a00d8f34:  99 33 20 10  srl  %o4, 0x10, %o4
a00d8f38:  90 07 be d0  add  %fp, -304, %o0
a00d8f3c:  92 10 20 02  mov  2, %o1
a00d8f40:  94 10 20 01  mov  1, %o2
a00d8f44:  7f ff fa 76  call  0xa00d791c
a00d8f48:  96 10 20 09  mov  9, %o3
a00d8f4c:  01 00 00 00  nop
a00d8f50:  81 c7 e0 08  ret
a00d8f54:  81 e8 00 00  restore
