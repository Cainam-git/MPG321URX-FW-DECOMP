# leon2s HDMITX_PacketSwitch_Bypass 0xa00a8cac-0xa00a8ec4 (536 bytes)  [FUN_a00a8ebc = unreachable ret/restore tail, merged]
a00a8cac:  9d e3 bf 98  save  %sp, -104, %sp
a00a8cb0:  a4 0e 60 ff  and  %i1, 0xff, %l2
a00a8cb4:  80 a4 a0 51  cmp  %l2, 0x51
a00a8cb8:  02 80 00 16  be  0xa00a8d10
a00a8cbc:  a6 10 20 01  mov  1, %l3
a00a8cc0:  80 a4 a0 51  cmp  %l2, 0x51
a00a8cc4:  14 80 00 06  bg  0xa00a8cdc
a00a8cc8:  80 a4 a0 71  cmp  %l2, 0x71
a00a8ccc:  80 a4 a0 31  cmp  %l2, 0x31
a00a8cd0:  02 80 00 10  be  0xa00a8d10
a00a8cd4:  80 a4 a0 41  cmp  %l2, 0x41
a00a8cd8:  30 80 00 06  b,a   0xa00a8cf0
a00a8cdc:  02 80 00 33  be  0xa00a8da8
a00a8ce0:  80 a4 a0 71  cmp  %l2, 0x71
a00a8ce4:  14 80 00 07  bg  0xa00a8d00
a00a8ce8:  80 a4 a0 81  cmp  %l2, 0x81
a00a8cec:  80 a4 a0 61  cmp  %l2, 0x61
a00a8cf0:  02 80 00 09  be  0xa00a8d14
a00a8cf4:  a2 0e 20 ff  and  %i0, 0xff, %l1
a00a8cf8:  10 80 00 67  b  0xa00a8e94
a00a8cfc:  11 28 01 b0  sethi  %hi(0xa006c000), %o0
a00a8d00:  02 80 00 2a  be  0xa00a8da8
a00a8d04:  11 28 01 b0  sethi  %hi(0xa006c000), %o0
a00a8d08:  10 80 00 64  b  0xa00a8e98
a00a8d0c:  90 12 22 a0  or  %o0, 0x2a0, %o0	! 0xa006c2a0
a00a8d10:  a2 0e 20 ff  and  %i0, 0xff, %l1
a00a8d14:  92 10 00 12  mov  %l2, %o1
a00a8d18:  94 10 00 11  mov  %l1, %o2
a00a8d1c:  96 10 20 00  clr  %o3
a00a8d20:  98 10 20 01  mov  1, %o4
a00a8d24:  9a 10 20 00  clr  %o5
a00a8d28:  7f ff ff 26  call  0xa00a89c0
a00a8d2c:  90 10 20 00  clr  %o0
a00a8d30:  90 0a 20 ff  and  %o0, 0xff, %o0
a00a8d34:  80 a0 00 08  cmp  %g0, %o0
a00a8d38:  a0 60 3f ff  subx  %g0, -1, %l0
a00a8d3c:  92 10 00 12  mov  %l2, %o1
a00a8d40:  94 10 00 11  mov  %l1, %o2
a00a8d44:  96 10 20 27  mov  0x27, %o3
a00a8d48:  98 10 20 00  clr  %o4
a00a8d4c:  9a 10 20 01  mov  1, %o5
a00a8d50:  7f ff ff 1c  call  0xa00a89c0
a00a8d54:  90 10 20 01  mov  1, %o0
a00a8d58:  90 0a 20 ff  and  %o0, 0xff, %o0
a00a8d5c:  80 a0 00 08  cmp  %g0, %o0
a00a8d60:  82 60 3f ff  subx  %g0, -1, %g1
a00a8d64:  a0 14 00 01  or  %l0, %g1, %l0
a00a8d68:  92 10 00 12  mov  %l2, %o1
a00a8d6c:  94 10 00 11  mov  %l1, %o2
a00a8d70:  90 10 20 02  mov  2, %o0
a00a8d74:  96 10 20 00  clr  %o3
a00a8d78:  98 10 20 00  clr  %o4
a00a8d7c:  7f ff ff 11  call  0xa00a89c0
a00a8d80:  9a 10 20 00  clr  %o5
a00a8d84:  90 0a 20 ff  and  %o0, 0xff, %o0
a00a8d88:  80 a0 00 08  cmp  %g0, %o0
a00a8d8c:  82 60 3f ff  subx  %g0, -1, %g1
a00a8d90:  11 28 01 b0  sethi  %hi(0xa006c000), %o0
a00a8d94:  80 94 00 01  orcc  %l0, %g1, %g0
a00a8d98:  12 80 00 40  bne  0xa00a8e98
a00a8d9c:  90 12 22 d8  or  %o0, 0x2d8, %o0
a00a8da0:  10 80 00 41  b  0xa00a8ea4
a00a8da4:  80 8c e0 ff  btst  0xff, %l3
a00a8da8:  a2 0e 20 ff  and  %i0, 0xff, %l1
a00a8dac:  9a 10 20 01  mov  1, %o5
a00a8db0:  90 10 20 00  clr  %o0
a00a8db4:  92 10 00 12  mov  %l2, %o1
a00a8db8:  94 10 00 11  mov  %l1, %o2
a00a8dbc:  96 10 20 00  clr  %o3
a00a8dc0:  7f ff ff 00  call  0xa00a89c0
a00a8dc4:  98 10 20 00  clr  %o4
a00a8dc8:  82 1c a0 71  xor  %l2, 0x71, %g1
a00a8dcc:  80 a0 00 01  cmp  %g0, %g1
a00a8dd0:  a0 40 20 00  addx  %g0, 0, %l0
a00a8dd4:  29 2a 01 e4  sethi  %hi(0xa8079000), %l4
a00a8dd8:  82 04 00 10  add  %l0, %l0, %g1
a00a8ddc:  82 00 40 10  add  %g1, %l0, %g1
a00a8de0:  9a 15 22 90  or  %l4, 0x290, %o5
a00a8de4:  c2 0b 40 01  ldub  [ %o5 + %g1 ], %g1
a00a8de8:  80 a0 60 00  cmp  %g1, 0
a00a8dec:  02 80 00 09  be  0xa00a8e10
a00a8df0:  a6 0a 20 01  and  %o0, 1, %l3
a00a8df4:  92 10 00 12  mov  %l2, %o1
a00a8df8:  94 10 00 11  mov  %l1, %o2
a00a8dfc:  90 10 20 01  mov  1, %o0
a00a8e00:  96 10 20 27  mov  0x27, %o3
a00a8e04:  98 10 20 01  mov  1, %o4
a00a8e08:  10 80 00 08  b  0xa00a8e28
a00a8e0c:  9a 10 20 01  mov  1, %o5
a00a8e10:  92 10 00 12  mov  %l2, %o1
a00a8e14:  94 10 00 11  mov  %l1, %o2
a00a8e18:  90 10 20 01  mov  1, %o0
a00a8e1c:  96 10 20 27  mov  0x27, %o3
a00a8e20:  98 10 20 00  clr  %o4
a00a8e24:  9a 10 20 00  clr  %o5
a00a8e28:  7f ff fe e6  call  0xa00a89c0
a00a8e2c:  01 00 00 00  nop
a00a8e30:  82 04 00 10  add  %l0, %l0, %g1
a00a8e34:  9a 15 22 90  or  %l4, 0x290, %o5
a00a8e38:  82 00 40 10  add  %g1, %l0, %g1
a00a8e3c:  82 00 40 0d  add  %g1, %o5, %g1
a00a8e40:  da 08 60 01  ldub  [ %g1 + 1 ], %o5
a00a8e44:  c2 08 60 02  ldub  [ %g1 + 2 ], %g1
a00a8e48:  82 10 40 0d  or  %g1, %o5, %g1
a00a8e4c:  a6 0c c0 08  and  %l3, %o0, %l3
a00a8e50:  80 88 60 ff  btst  0xff, %g1
a00a8e54:  92 0e 60 ff  and  %i1, 0xff, %o1
a00a8e58:  02 80 00 07  be  0xa00a8e74
a00a8e5c:  94 0e 20 ff  and  %i0, 0xff, %o2
a00a8e60:  90 10 20 02  mov  2, %o0
a00a8e64:  96 10 20 00  clr  %o3
a00a8e68:  98 10 20 00  clr  %o4
a00a8e6c:  10 80 00 06  b  0xa00a8e84
a00a8e70:  9a 10 20 01  mov  1, %o5
a00a8e74:  90 10 20 02  mov  2, %o0
a00a8e78:  96 10 20 00  clr  %o3
a00a8e7c:  98 10 20 00  clr  %o4
a00a8e80:  9a 10 20 00  clr  %o5
a00a8e84:  7f ff fe cf  call  0xa00a89c0
a00a8e88:  01 00 00 00  nop
a00a8e8c:  10 80 00 05  b  0xa00a8ea0
a00a8e90:  a6 0a 00 13  and  %o0, %l3, %l3
a00a8e94:  90 12 22 a0  or  %o0, 0x2a0, %o0
a00a8e98:  7f ff 28 6b  call  0xa0073044
a00a8e9c:  92 10 20 00  clr  %o1
a00a8ea0:  80 8c e0 ff  btst  0xff, %l3
a00a8ea4:  12 80 00 05  bne  0xa00a8eb8
a00a8ea8:  31 28 01 b0  sethi  %hi(0xa006c000), %i0
a00a8eac:  b0 16 23 10  or  %i0, 0x310, %i0	! 0xa006c310
a00a8eb0:  7f ff 28 65  call  0xa0073044
a00a8eb4:  93 e8 20 00  restore  %g0, 0, %o1
a00a8eb8:  01 00 00 00  nop
a00a8ebc:  81 c7 e0 08  ret
a00a8ec0:  81 e8 00 00  restore
