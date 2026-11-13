# leon2s FUN_a00c1c18 0xa00c1c18-0xa00c224c (1588 bytes)
a00c1c18:  9d e3 bb 10  save  %sp, -1264, %sp
a00c1c1c:  1b 33 c0 4a  sethi  %hi(0xcf012800), %o5
a00c1c20:  82 13 63 84  or  %o5, 0x384, %g1	! 0xcf012b84
a00c1c24:  c0 20 40 00  clr  [ %g1 ]
a00c1c28:  82 13 63 88  or  %o5, 0x388, %g1
a00c1c2c:  c0 20 40 00  clr  [ %g1 ]
a00c1c30:  82 10 20 44  mov  0x44, %g1
a00c1c34:  9a 13 63 8c  or  %o5, 0x38c, %o5
a00c1c38:  11 27 c6 dd  sethi  %hi(0x9f1b7400), %o0
a00c1c3c:  c2 23 40 00  st  %g1, [ %o5 ]
a00c1c40:  92 10 20 00  clr  %o1
a00c1c44:  40 3b 05 00  call  0xa0f83044
a00c1c48:  90 12 21 38  or  %o0, 0x138, %o0
a00c1c4c:  90 10 20 02  mov  2, %o0
a00c1c50:  92 10 20 2e  mov  0x2e, %o1
a00c1c54:  94 10 20 04  mov  4, %o2
a00c1c58:  40 3b d2 d8  call  0xa0fb67b8
a00c1c5c:  96 10 20 01  mov  1, %o3
a00c1c60:  a2 07 bf f0  add  %fp, -16, %l1
a00c1c64:  90 10 21 38  mov  0x138, %o0
a00c1c68:  92 10 20 05  mov  5, %o1
a00c1c6c:  40 3b 6d 9d  call  0xa0f9d2e0
a00c1c70:  94 10 00 11  mov  %l1, %o2
a00c1c74:  c2 0f bf f0  ldub  [ %fp + -16 ], %g1
a00c1c78:  80 a0 60 00  cmp  %g1, 0
a00c1c7c:  12 80 00 15  bne  0xa00c1cd0
a00c1c80:  c2 0f bf f1  ldub  [ %fp + -15 ], %g1
a00c1c84:  80 a0 60 00  cmp  %g1, 0
a00c1c88:  12 80 00 13  bne  0xa00c1cd4
a00c1c8c:  90 10 20 20  mov  0x20, %o0
a00c1c90:  c2 0f bf f2  ldub  [ %fp + -14 ], %g1
a00c1c94:  80 a0 60 00  cmp  %g1, 0
a00c1c98:  12 80 00 10  bne  0xa00c1cd8
a00c1c9c:  92 10 21 1a  mov  0x11a, %o1
a00c1ca0:  c2 0f bf f3  ldub  [ %fp + -13 ], %g1
a00c1ca4:  80 a0 60 00  cmp  %g1, 0
a00c1ca8:  12 80 00 0c  bne  0xa00c1cd8
a00c1cac:  c2 0f bf f4  ldub  [ %fp + -12 ], %g1
a00c1cb0:  80 a0 60 00  cmp  %g1, 0
a00c1cb4:  12 80 00 09  bne  0xa00c1cd8
a00c1cb8:  01 00 00 00  nop
a00c1cbc:  90 10 00 11  mov  %l1, %o0
a00c1cc0:  7f ff fb d2  call  0xa00c0c08
a00c1cc4:  92 07 be d0  add  %fp, -304, %o1
a00c1cc8:  10 80 00 1e  b  0xa00c1d40
a00c1ccc:  a0 07 be d0  add  %fp, -304, %l0
a00c1cd0:  90 10 20 20  mov  0x20, %o0
a00c1cd4:  92 10 21 1a  mov  0x11a, %o1
a00c1cd8:  40 3b 6d 82  call  0xa0f9d2e0
a00c1cdc:  94 07 be d0  add  %fp, -304, %o2
a00c1ce0:  c2 0f bf f0  ldub  [ %fp + -16 ], %g1
a00c1ce4:  80 a0 60 24  cmp  %g1, 0x24
a00c1ce8:  32 80 00 14  bne,a   0xa00c1d38
a00c1cec:  c0 2f bf e8  clrb  [ %fp + -24 ]
a00c1cf0:  c2 0f bf f1  ldub  [ %fp + -15 ], %g1
a00c1cf4:  80 a0 60 c8  cmp  %g1, 0xc8
a00c1cf8:  32 80 00 10  bne,a   0xa00c1d38
a00c1cfc:  c0 2f bf e8  clrb  [ %fp + -24 ]
a00c1d00:  c2 0f bf f2  ldub  [ %fp + -14 ], %g1
a00c1d04:  80 a0 60 eb  cmp  %g1, 0xeb
a00c1d08:  32 80 00 0c  bne,a   0xa00c1d38
a00c1d0c:  c0 2f bf e8  clrb  [ %fp + -24 ]
a00c1d10:  c2 0f bf f3  ldub  [ %fp + -13 ], %g1
a00c1d14:  80 a0 60 3e  cmp  %g1, 0x3e
a00c1d18:  32 80 00 08  bne,a   0xa00c1d38
a00c1d1c:  c0 2f bf e8  clrb  [ %fp + -24 ]
a00c1d20:  c2 0f bf f4  ldub  [ %fp + -12 ], %g1
a00c1d24:  80 a0 60 9c  cmp  %g1, 0x9c
a00c1d28:  32 80 00 04  bne,a   0xa00c1d38
a00c1d2c:  c0 2f bf e8  clrb  [ %fp + -24 ]
a00c1d30:  82 10 20 68  mov  0x68, %g1
a00c1d34:  c2 2f bf e8  stb  %g1, [ %fp + -24 ]
a00c1d38:  c0 2f bf e9  clrb  [ %fp + -23 ]
a00c1d3c:  a0 07 be d0  add  %fp, -304, %l0
a00c1d40:  90 10 20 00  clr  %o0
a00c1d44:  92 10 00 11  mov  %l1, %o1
a00c1d48:  7f ff fb e8  call  0xa00c0ce8
a00c1d4c:  94 10 00 10  mov  %l0, %o2
a00c1d50:  90 10 20 01  mov  1, %o0
a00c1d54:  92 10 00 11  mov  %l1, %o1
a00c1d58:  7f ff fb e4  call  0xa00c0ce8
a00c1d5c:  94 10 00 10  mov  %l0, %o2
a00c1d60:  90 10 20 00  clr  %o0
a00c1d64:  92 10 00 11  mov  %l1, %o1
a00c1d68:  7f ff fc 25  call  0xa00c0dfc
a00c1d6c:  94 10 00 10  mov  %l0, %o2
a00c1d70:  90 10 20 01  mov  1, %o0
a00c1d74:  92 10 00 11  mov  %l1, %o1
a00c1d78:  7f ff fc 21  call  0xa00c0dfc
a00c1d7c:  94 10 00 10  mov  %l0, %o2
a00c1d80:  90 10 20 00  clr  %o0
a00c1d84:  92 10 00 11  mov  %l1, %o1
a00c1d88:  7f ff fd 64  call  0xa00c1318
a00c1d8c:  94 10 00 10  mov  %l0, %o2
a00c1d90:  90 10 20 01  mov  1, %o0
a00c1d94:  92 10 00 11  mov  %l1, %o1
a00c1d98:  7f ff fd 60  call  0xa00c1318
a00c1d9c:  94 10 00 10  mov  %l0, %o2
a00c1da0:  90 10 22 60  mov  0x260, %o0
a00c1da4:  92 10 20 05  mov  5, %o1
a00c1da8:  40 3b 6d 4e  call  0xa0f9d2e0
a00c1dac:  94 10 00 11  mov  %l1, %o2
a00c1db0:  c2 0f bf f0  ldub  [ %fp + -16 ], %g1
a00c1db4:  80 a0 60 00  cmp  %g1, 0
a00c1db8:  12 80 00 16  bne  0xa00c1e10
a00c1dbc:  c2 0f bf f1  ldub  [ %fp + -15 ], %g1
a00c1dc0:  80 a0 60 00  cmp  %g1, 0
a00c1dc4:  32 80 00 14  bne,a   0xa00c1e14
a00c1dc8:  94 10 00 10  mov  %l0, %o2
a00c1dcc:  c2 0f bf f2  ldub  [ %fp + -14 ], %g1
a00c1dd0:  80 a0 60 00  cmp  %g1, 0
a00c1dd4:  32 80 00 10  bne,a   0xa00c1e14
a00c1dd8:  94 10 00 10  mov  %l0, %o2
a00c1ddc:  c2 0f bf f3  ldub  [ %fp + -13 ], %g1
a00c1de0:  80 a0 60 00  cmp  %g1, 0
a00c1de4:  32 80 00 0c  bne,a   0xa00c1e14
a00c1de8:  94 10 00 10  mov  %l0, %o2
a00c1dec:  c2 0f bf f4  ldub  [ %fp + -12 ], %g1
a00c1df0:  80 a0 60 00  cmp  %g1, 0
a00c1df4:  32 80 00 08  bne,a   0xa00c1e14
a00c1df8:  94 10 00 10  mov  %l0, %o2
a00c1dfc:  92 10 00 10  mov  %l0, %o1
a00c1e00:  7f ff fb 9e  call  0xa00c0c78
a00c1e04:  90 10 00 11  mov  %l1, %o0
a00c1e08:  10 80 00 09  b  0xa00c1e2c
a00c1e0c:  a0 07 be d0  add  %fp, -304, %l0
a00c1e10:  94 10 00 10  mov  %l0, %o2
a00c1e14:  90 10 21 48  mov  0x148, %o0
a00c1e18:  40 3b 6d 32  call  0xa0f9d2e0
a00c1e1c:  92 10 21 1a  mov  0x11a, %o1
a00c1e20:  c0 2f bf e8  clrb  [ %fp + -24 ]
a00c1e24:  c0 2f bf e9  clrb  [ %fp + -23 ]
a00c1e28:  a0 07 be d0  add  %fp, -304, %l0
a00c1e2c:  92 10 00 10  mov  %l0, %o1
a00c1e30:  7f ff fb 46  call  0xa00c0b48
a00c1e34:  90 10 00 11  mov  %l1, %o0
a00c1e38:  92 10 00 10  mov  %l0, %o1
a00c1e3c:  7f ff fb 13  call  0xa00c0a88
a00c1e40:  90 10 00 11  mov  %l1, %o0
a00c1e44:  96 10 20 00  clr  %o3
a00c1e48:  90 10 20 02  mov  2, %o0
a00c1e4c:  92 10 20 2e  mov  0x2e, %o1
a00c1e50:  40 3b d2 5a  call  0xa0fb67b8
a00c1e54:  94 10 20 04  mov  4, %o2
a00c1e58:  90 10 20 02  mov  2, %o0
a00c1e5c:  92 10 20 46  mov  0x46, %o1
a00c1e60:  40 3b d1 d9  call  0xa0fb65c4
a00c1e64:  94 10 20 60  mov  0x60, %o2
a00c1e68:  90 10 20 02  mov  2, %o0
a00c1e6c:  92 10 20 41  mov  0x41, %o1
a00c1e70:  94 10 20 10  mov  0x10, %o2
a00c1e74:  40 3b d3 0b  call  0xa0fb6aa0
a00c1e78:  96 10 20 01  mov  1, %o3
a00c1e7c:  96 10 20 01  mov  1, %o3
a00c1e80:  90 10 20 02  mov  2, %o0
a00c1e84:  92 10 20 42  mov  0x42, %o1
a00c1e88:  40 3b d3 06  call  0xa0fb6aa0
a00c1e8c:  94 10 20 01  mov  1, %o2
a00c1e90:  a0 10 20 80  mov  0x80, %l0
a00c1e94:  96 07 bf f8  add  %fp, -8, %o3
a00c1e98:  82 04 20 01  add  %l0, 1, %g1
a00c1e9c:  9b 2c 20 10  sll  %l0, 0x10, %o5
a00c1ea0:  9b 33 60 10  srl  %o5, 0x10, %o5
a00c1ea4:  99 28 60 10  sll  %g1, 0x10, %o4
a00c1ea8:  9a 02 c0 0d  add  %o3, %o5, %o5
a00c1eac:  99 33 20 10  srl  %o4, 0x10, %o4
a00c1eb0:  c0 2b 7b 78  clrb  [ %o5 + -1160 ]
a00c1eb4:  80 a3 21 3f  cmp  %o4, 0x13f
a00c1eb8:  08 bf ff f8  bleu  0xa00c1e98
a00c1ebc:  a0 10 00 01  mov  %g1, %l0
a00c1ec0:  21 2a 01 f5  sethi  %hi(0xa807d400), %l0
a00c1ec4:  a4 07 be c0  add  %fp, -320, %l2
a00c1ec8:  c0 2c 22 28  clrb  [ %l0 + 0x228 ]
a00c1ecc:  90 10 22 70  mov  0x270, %o0
a00c1ed0:  92 10 20 10  mov  0x10, %o1
a00c1ed4:  40 3b 6d 03  call  0xa0f9d2e0
a00c1ed8:  94 10 00 12  mov  %l2, %o2
a00c1edc:  c2 0f be c0  ldub  [ %fp + -320 ], %g1
a00c1ee0:  80 a0 60 00  cmp  %g1, 0
a00c1ee4:  12 80 00 39  bne  0xa00c1fc8
a00c1ee8:  c2 0f be c1  ldub  [ %fp + -319 ], %g1
a00c1eec:  80 a0 60 00  cmp  %g1, 0
a00c1ef0:  12 80 00 37  bne  0xa00c1fcc
a00c1ef4:  90 10 22 80  mov  0x280, %o0
a00c1ef8:  c2 0f be c2  ldub  [ %fp + -318 ], %g1
a00c1efc:  80 a0 60 00  cmp  %g1, 0
a00c1f00:  12 80 00 34  bne  0xa00c1fd0
a00c1f04:  92 10 22 0a  mov  0x20a, %o1
a00c1f08:  c2 0f be c3  ldub  [ %fp + -317 ], %g1
a00c1f0c:  80 a0 60 00  cmp  %g1, 0
a00c1f10:  12 80 00 30  bne  0xa00c1fd0
a00c1f14:  c2 0f be c4  ldub  [ %fp + -316 ], %g1
a00c1f18:  80 a0 60 00  cmp  %g1, 0
a00c1f1c:  12 80 00 2d  bne  0xa00c1fd0
a00c1f20:  c2 0f be c5  ldub  [ %fp + -315 ], %g1
a00c1f24:  80 a0 60 00  cmp  %g1, 0
a00c1f28:  12 80 00 2a  bne  0xa00c1fd0
a00c1f2c:  c2 0f be c6  ldub  [ %fp + -314 ], %g1
a00c1f30:  80 a0 60 00  cmp  %g1, 0
a00c1f34:  12 80 00 27  bne  0xa00c1fd0
a00c1f38:  c2 0f be c7  ldub  [ %fp + -313 ], %g1
a00c1f3c:  80 a0 60 00  cmp  %g1, 0
a00c1f40:  12 80 00 24  bne  0xa00c1fd0
a00c1f44:  c2 0f be c8  ldub  [ %fp + -312 ], %g1
a00c1f48:  80 a0 60 00  cmp  %g1, 0
a00c1f4c:  12 80 00 21  bne  0xa00c1fd0
a00c1f50:  c2 0f be c9  ldub  [ %fp + -311 ], %g1
a00c1f54:  80 a0 60 00  cmp  %g1, 0
a00c1f58:  12 80 00 1e  bne  0xa00c1fd0
a00c1f5c:  c2 0f be ca  ldub  [ %fp + -310 ], %g1
a00c1f60:  80 a0 60 00  cmp  %g1, 0
a00c1f64:  12 80 00 1b  bne  0xa00c1fd0
a00c1f68:  c2 0f be cb  ldub  [ %fp + -309 ], %g1
a00c1f6c:  80 a0 60 00  cmp  %g1, 0
a00c1f70:  12 80 00 18  bne  0xa00c1fd0
a00c1f74:  c2 0f be cc  ldub  [ %fp + -308 ], %g1
a00c1f78:  80 a0 60 00  cmp  %g1, 0
a00c1f7c:  12 80 00 15  bne  0xa00c1fd0
a00c1f80:  c2 0f be cd  ldub  [ %fp + -307 ], %g1
a00c1f84:  80 a0 60 00  cmp  %g1, 0
a00c1f88:  12 80 00 12  bne  0xa00c1fd0
a00c1f8c:  c2 0f be ce  ldub  [ %fp + -306 ], %g1
a00c1f90:  80 a0 60 00  cmp  %g1, 0
a00c1f94:  12 80 00 0f  bne  0xa00c1fd0
a00c1f98:  c2 0f be cf  ldub  [ %fp + -305 ], %g1
a00c1f9c:  80 a0 60 00  cmp  %g1, 0
a00c1fa0:  12 80 00 0c  bne  0xa00c1fd0
a00c1fa4:  01 00 00 00  nop
a00c1fa8:  90 10 00 12  mov  %l2, %o0
a00c1fac:  92 07 bc b0  add  %fp, -848, %o1
a00c1fb0:  94 10 20 00  clr  %o2
a00c1fb4:  7f ff fb c6  call  0xa00c0ecc
a00c1fb8:  96 07 bb 70  add  %fp, -1168, %o3
a00c1fbc:  82 10 20 01  mov  1, %g1
a00c1fc0:  10 80 00 0a  b  0xa00c1fe8
a00c1fc4:  c2 2c 22 28  stb  %g1, [ %l0 + 0x228 ]
a00c1fc8:  90 10 22 80  mov  0x280, %o0
a00c1fcc:  92 10 22 0a  mov  0x20a, %o1
a00c1fd0:  40 3b 6c c4  call  0xa0f9d2e0
a00c1fd4:  94 07 bc b0  add  %fp, -848, %o2
a00c1fd8:  90 10 25 0a  mov  0x50a, %o0
a00c1fdc:  92 10 20 80  mov  0x80, %o1
a00c1fe0:  40 3b 6c c0  call  0xa0f9d2e0
a00c1fe4:  94 07 bb 70  add  %fp, -1168, %o2
a00c1fe8:  a0 07 bc b0  add  %fp, -848, %l0
a00c1fec:  a2 07 bb 70  add  %fp, -1168, %l1
a00c1ff0:  94 10 00 10  mov  %l0, %o2
a00c1ff4:  98 10 00 11  mov  %l1, %o4
a00c1ff8:  90 10 20 00  clr  %o0
a00c1ffc:  92 10 00 12  mov  %l2, %o1
a00c2000:  7f ff fb e2  call  0xa00c0f88
a00c2004:  96 10 20 00  clr  %o3
a00c2008:  94 10 00 10  mov  %l0, %o2
a00c200c:  98 10 00 11  mov  %l1, %o4
a00c2010:  90 10 20 01  mov  1, %o0
a00c2014:  92 10 00 12  mov  %l2, %o1
a00c2018:  7f ff fb dc  call  0xa00c0f88
a00c201c:  96 10 20 00  clr  %o3
a00c2020:  94 10 00 10  mov  %l0, %o2
a00c2024:  98 10 00 11  mov  %l1, %o4
a00c2028:  90 10 20 00  clr  %o0
a00c202c:  92 10 00 12  mov  %l2, %o1
a00c2030:  7f ff fc 25  call  0xa00c10c4
a00c2034:  96 10 20 00  clr  %o3
a00c2038:  94 10 00 10  mov  %l0, %o2
a00c203c:  98 10 00 11  mov  %l1, %o4
a00c2040:  90 10 20 01  mov  1, %o0
a00c2044:  92 10 00 12  mov  %l2, %o1
a00c2048:  7f ff fc 1f  call  0xa00c10c4
a00c204c:  96 10 20 00  clr  %o3
a00c2050:  94 10 00 10  mov  %l0, %o2
a00c2054:  98 10 00 11  mov  %l1, %o4
a00c2058:  90 10 20 00  clr  %o0
a00c205c:  92 10 00 12  mov  %l2, %o1
a00c2060:  7f ff fd 3c  call  0xa00c1550
a00c2064:  96 10 20 00  clr  %o3
a00c2068:  94 10 00 10  mov  %l0, %o2
a00c206c:  98 10 00 11  mov  %l1, %o4
a00c2070:  92 10 00 12  mov  %l2, %o1
a00c2074:  90 10 20 01  mov  1, %o0
a00c2078:  7f ff fd 36  call  0xa00c1550
a00c207c:  96 10 20 00  clr  %o3
a00c2080:  21 2a 01 f5  sethi  %hi(0xa807d400), %l0
a00c2084:  23 2a 01 f5  sethi  %hi(0xa807d400), %l1
a00c2088:  90 10 25 90  mov  0x590, %o0
a00c208c:  c0 2c 62 2c  clrb  [ %l1 + 0x22c ]
a00c2090:  92 10 20 24  mov  0x24, %o1
a00c2094:  40 3b 6c 93  call  0xa0f9d2e0
a00c2098:  94 14 22 38  or  %l0, 0x238, %o2
a00c209c:  c2 0c 22 38  ldub  [ %l0 + 0x238 ], %g1
a00c20a0:  80 a0 60 00  cmp  %g1, 0
a00c20a4:  12 80 00 43  bne  0xa00c21b0
a00c20a8:  90 14 22 38  or  %l0, 0x238, %o0
a00c20ac:  c2 0a 20 01  ldub  [ %o0 + 1 ], %g1
a00c20b0:  80 a0 60 00  cmp  %g1, 0
a00c20b4:  32 80 00 40  bne,a   0xa00c21b4
a00c20b8:  a0 10 20 00  clr  %l0
a00c20bc:  c2 0a 20 02  ldub  [ %o0 + 2 ], %g1
a00c20c0:  80 a0 60 00  cmp  %g1, 0
a00c20c4:  32 80 00 3c  bne,a   0xa00c21b4
a00c20c8:  a0 10 20 00  clr  %l0
a00c20cc:  c2 0a 20 03  ldub  [ %o0 + 3 ], %g1
a00c20d0:  80 a0 60 00  cmp  %g1, 0
a00c20d4:  32 80 00 38  bne,a   0xa00c21b4
a00c20d8:  a0 10 20 00  clr  %l0
a00c20dc:  c2 0a 20 04  ldub  [ %o0 + 4 ], %g1
a00c20e0:  80 a0 60 00  cmp  %g1, 0
a00c20e4:  32 80 00 34  bne,a   0xa00c21b4
a00c20e8:  a0 10 20 00  clr  %l0
a00c20ec:  c2 0a 20 05  ldub  [ %o0 + 5 ], %g1
a00c20f0:  80 a0 60 00  cmp  %g1, 0
a00c20f4:  32 80 00 30  bne,a   0xa00c21b4
a00c20f8:  a0 10 20 00  clr  %l0
a00c20fc:  c2 0a 20 06  ldub  [ %o0 + 6 ], %g1
a00c2100:  80 a0 60 00  cmp  %g1, 0
a00c2104:  32 80 00 2c  bne,a   0xa00c21b4
a00c2108:  a0 10 20 00  clr  %l0
a00c210c:  c2 0a 20 07  ldub  [ %o0 + 7 ], %g1
a00c2110:  80 a0 60 00  cmp  %g1, 0
a00c2114:  32 80 00 28  bne,a   0xa00c21b4
a00c2118:  a0 10 20 00  clr  %l0
a00c211c:  c2 0a 20 08  ldub  [ %o0 + 8 ], %g1
a00c2120:  80 a0 60 00  cmp  %g1, 0
a00c2124:  32 80 00 24  bne,a   0xa00c21b4
a00c2128:  a0 10 20 00  clr  %l0
a00c212c:  c2 0a 20 09  ldub  [ %o0 + 9 ], %g1
a00c2130:  80 a0 60 00  cmp  %g1, 0
a00c2134:  32 80 00 20  bne,a   0xa00c21b4
a00c2138:  a0 10 20 00  clr  %l0
a00c213c:  c2 0a 20 0a  ldub  [ %o0 + 0xa ], %g1
a00c2140:  80 a0 60 00  cmp  %g1, 0
a00c2144:  32 80 00 1c  bne,a   0xa00c21b4
a00c2148:  a0 10 20 00  clr  %l0
a00c214c:  c2 0a 20 0b  ldub  [ %o0 + 0xb ], %g1
a00c2150:  80 a0 60 00  cmp  %g1, 0
a00c2154:  32 80 00 18  bne,a   0xa00c21b4
a00c2158:  a0 10 20 00  clr  %l0
a00c215c:  c2 0a 20 0c  ldub  [ %o0 + 0xc ], %g1
a00c2160:  80 a0 60 00  cmp  %g1, 0
a00c2164:  32 80 00 14  bne,a   0xa00c21b4
a00c2168:  a0 10 20 00  clr  %l0
a00c216c:  c2 0a 20 0d  ldub  [ %o0 + 0xd ], %g1
a00c2170:  80 a0 60 00  cmp  %g1, 0
a00c2174:  32 80 00 10  bne,a   0xa00c21b4
a00c2178:  a0 10 20 00  clr  %l0
a00c217c:  c2 0a 20 0e  ldub  [ %o0 + 0xe ], %g1
a00c2180:  80 a0 60 00  cmp  %g1, 0
a00c2184:  32 80 00 0c  bne,a   0xa00c21b4
a00c2188:  a0 10 20 00  clr  %l0
a00c218c:  c2 0a 20 0f  ldub  [ %o0 + 0xf ], %g1
a00c2190:  80 a0 60 00  cmp  %g1, 0
a00c2194:  32 80 00 08  bne,a   0xa00c21b4
a00c2198:  a0 10 20 00  clr  %l0
a00c219c:  92 10 20 00  clr  %o1
a00c21a0:  7f ff fc 4e  call  0xa00c12d8
a00c21a4:  94 10 20 00  clr  %o2
a00c21a8:  82 10 20 01  mov  1, %g1
a00c21ac:  c2 2c 62 2c  stb  %g1, [ %l1 + 0x22c ]
a00c21b0:  a0 10 20 00  clr  %l0
a00c21b4:  90 0c 20 ff  and  %l0, 0xff, %o0
a00c21b8:  7f ff fd 70  call  0xa00c1778
a00c21bc:  92 10 20 01  mov  1, %o1
a00c21c0:  9a 04 20 01  add  %l0, 1, %o5
a00c21c4:  83 2b 60 10  sll  %o5, 0x10, %g1
a00c21c8:  83 30 60 10  srl  %g1, 0x10, %g1
a00c21cc:  80 a0 60 03  cmp  %g1, 3
a00c21d0:  08 bf ff f9  bleu  0xa00c21b4
a00c21d4:  a0 10 00 0d  mov  %o5, %l0
a00c21d8:  a0 10 20 04  mov  4, %l0
a00c21dc:  90 0c 20 ff  and  %l0, 0xff, %o0
a00c21e0:  7f ff fd 66  call  0xa00c1778
a00c21e4:  92 10 20 00  clr  %o1
a00c21e8:  9a 04 20 01  add  %l0, 1, %o5
a00c21ec:  83 2b 60 10  sll  %o5, 0x10, %g1
a00c21f0:  83 30 60 10  srl  %g1, 0x10, %g1
a00c21f4:  80 a0 60 05  cmp  %g1, 5
a00c21f8:  08 bf ff f9  bleu  0xa00c21dc
a00c21fc:  a0 10 00 0d  mov  %o5, %l0
a00c2200:  7f ff fd bf  call  0xa00c18fc
a00c2204:  01 00 00 00  nop
a00c2208:  40 00 15 f0  call  0xa00c79c8
a00c220c:  90 10 20 03  mov  3, %o0	! 0x3
a00c2210:  9a 10 20 01  mov  1, %o5
a00c2214:  03 2a 01 e3  sethi  %hi(0xa8078c00), %g1
a00c2218:  40 3a f7 31  call  0xa0f7fedc
a00c221c:  da 28 60 5c  stb  %o5, [ %g1 + 0x5c ]	! 0xa8078c5c
a00c2220:  11 27 c6 dd  sethi  %hi(0x9f1b7400), %o0
a00c2224:  92 10 20 00  clr  %o1
a00c2228:  40 3b 03 87  call  0xa0f83044
a00c222c:  90 12 21 50  or  %o0, 0x150, %o0
a00c2230:  13 27 c6 c6  sethi  %hi(0x9f1b1800), %o1
a00c2234:  92 12 62 c0  or  %o1, 0x2c0, %o1	! 0x9f1b1ac0
a00c2238:  40 3b ff 8e  call  0xa0fc2070
a00c223c:  90 10 20 00  clr  %o0
a00c2240:  01 00 00 00  nop
a00c2244:  81 c7 e0 08  ret
a00c2248:  81 e8 00 00  restore
