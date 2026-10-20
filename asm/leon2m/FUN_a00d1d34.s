# leon2m FUN_a00d1d34 0xa00d1d34-0xa00d1e08 (212 bytes)
a00d1d34:  9d e3 bf 98  save  %sp, -104, %sp
a00d1d38:  c2 0e 20 07  ldub  [ %i0 + 7 ], %g1
a00d1d3c:  80 a0 60 08  cmp  %g1, 8
a00d1d40:  02 80 00 0a  be  0xa00d1d68
a00d1d44:  80 a0 60 09  cmp  %g1, 9
a00d1d48:  02 80 00 10  be  0xa00d1d88
a00d1d4c:  80 a0 60 0d  cmp  %g1, 0xd
a00d1d50:  02 80 00 1b  be  0xa00d1dbc
a00d1d54:  80 a0 60 0f  cmp  %g1, 0xf
a00d1d58:  12 80 00 28  bne  0xa00d1df8
a00d1d5c:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a00d1d60:  10 80 00 20  b  0xa00d1de0
a00d1d64:  b0 13 62 90  or  %o5, 0x290, %i0	! 0xa802d290
a00d1d68:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00d1d6c:  b0 10 62 90  or  %g1, 0x290, %i0	! 0xa802d290
a00d1d70:  40 01 ca 23  call  0xa01445fc
a00d1d74:  d0 0e 20 1e  ldub  [ %i0 + 0x1e ], %o0
a00d1d78:  80 8a 20 ff  btst  0xff, %o0
a00d1d7c:  02 80 00 1f  be  0xa00d1df8
a00d1d80:  90 10 20 00  clr  %o0
a00d1d84:  30 80 00 09  b,a   0xa00d1da8
a00d1d88:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00d1d8c:  b0 12 62 90  or  %o1, 0x290, %i0	! 0xa802d290
a00d1d90:  40 01 ca 1b  call  0xa01445fc
a00d1d94:  d0 0e 20 1e  ldub  [ %i0 + 0x1e ], %o0
a00d1d98:  90 0a 20 ff  and  %o0, 0xff, %o0
a00d1d9c:  80 a2 20 01  cmp  %o0, 1
a00d1da0:  02 80 00 16  be  0xa00d1df8
a00d1da4:  90 10 20 01  mov  1, %o0
a00d1da8:  40 01 c9 fd  call  0xa014459c
a00d1dac:  01 00 00 00  nop
a00d1db0:  7f ff 9a 95  call  0xa00b8804
a00d1db4:  d0 2e 20 1e  stb  %o0, [ %i0 + 0x1e ]
a00d1db8:  30 80 00 10  b,a   0xa00d1df8
a00d1dbc:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00d1dc0:  b0 12 e2 90  or  %o3, 0x290, %i0	! 0xa802d290
a00d1dc4:  40 01 ca 0e  call  0xa01445fc
a00d1dc8:  d0 0e 20 1e  ldub  [ %i0 + 0x1e ], %o0
a00d1dcc:  94 0a 20 ff  and  %o0, 0xff, %o2
a00d1dd0:  80 a2 a0 02  cmp  %o2, 2
a00d1dd4:  02 80 00 09  be  0xa00d1df8
a00d1dd8:  90 10 20 02  mov  2, %o0
a00d1ddc:  30 bf ff f3  b,a   0xa00d1da8
a00d1de0:  40 01 ca 07  call  0xa01445fc
a00d1de4:  d0 0e 20 1e  ldub  [ %i0 + 0x1e ], %o0
a00d1de8:  98 0a 20 ff  and  %o0, 0xff, %o4
a00d1dec:  80 a3 20 03  cmp  %o4, 3
a00d1df0:  12 bf ff ee  bne  0xa00d1da8
a00d1df4:  90 10 20 03  mov  3, %o0
a00d1df8:  7f fe e0 46  call  0xa0089f10
a00d1dfc:  b0 10 20 e0  mov  0xe0, %i0
a00d1e00:  81 c7 e0 08  ret
a00d1e04:  81 e8 00 00  restore
