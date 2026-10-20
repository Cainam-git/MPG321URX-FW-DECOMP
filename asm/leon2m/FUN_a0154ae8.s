# leon2m FUN_a0154ae8 0xa0154ae8-0xa0155074 (1420 bytes)
a0154ae8:  9d e3 bf 90  save  %sp, -112, %sp
a0154aec:  03 00 03 ff  sethi  %hi(0xffc00), %g1
a0154af0:  82 10 63 ff  or  %g1, 0x3ff, %g1	! 0xfffff
a0154af4:  90 10 00 18  mov  %i0, %o0
a0154af8:  92 10 00 19  mov  %i1, %o1
a0154afc:  ac 10 00 18  mov  %i0, %l6
a0154b00:  80 a6 00 01  cmp  %i0, %g1
a0154b04:  14 80 00 16  bg  0xa0154b5c
a0154b08:  b8 10 20 00  clr  %i4
a0154b0c:  03 20 00 00  sethi  %hi(0x80000000), %g1
a0154b10:  82 2e 00 01  andn  %i0, %g1, %g1
a0154b14:  80 90 40 19  orcc  %g1, %i1, %g0
a0154b18:  12 80 00 09  bne  0xa0154b3c
a0154b1c:  80 a6 20 00  cmp  %i0, 0
a0154b20:  03 00 06 a0  sethi  %hi(0x1a8000), %g1
a0154b24:  d0 18 62 20  ldd  [ %g1 + 0x220 ], %o0	! 0x1a8220
a0154b28:  03 00 06 a0  sethi  %hi(0x1a8000), %g1
a0154b2c:  40 00 06 61  call  0xa01564b0
a0154b30:  d4 18 62 08  ldd  [ %g1 + 0x208 ], %o2	! 0x1a8208
a0154b34:  10 80 01 4e  b  0xa015506c
a0154b38:  b0 10 00 08  mov  %o0, %i0
a0154b3c:  06 80 00 ba  bl  0xa0154e24
a0154b40:  94 10 00 18  mov  %i0, %o2
a0154b44:  03 00 06 a0  sethi  %hi(0x1a8000), %g1
a0154b48:  40 00 05 84  call  0xa0156158
a0154b4c:  d4 18 62 28  ldd  [ %g1 + 0x228 ], %o2	! 0x1a8228
a0154b50:  98 10 00 08  mov  %o0, %o4
a0154b54:  ac 10 00 0c  mov  %o4, %l6
a0154b58:  b8 10 3f ca  mov  -54, %i4
a0154b5c:  03 1f fb ff  sethi  %hi(0x7feffc00), %g1
a0154b60:  82 10 63 ff  or  %g1, 0x3ff, %g1	! 0x7fefffff
a0154b64:  94 10 00 08  mov  %o0, %o2
a0154b68:  80 a5 80 01  cmp  %l6, %g1
a0154b6c:  04 80 00 06  ble  0xa0154b84
a0154b70:  96 10 00 09  mov  %o1, %o3
a0154b74:  40 00 05 4e  call  0xa01560ac
a0154b78:  01 00 00 00  nop
a0154b7c:  10 80 01 3c  b  0xa015506c
a0154b80:  b0 10 00 08  mov  %o0, %i0
a0154b84:  21 00 03 ff  sethi  %hi(0xffc00), %l0
a0154b88:  a0 14 23 ff  or  %l0, 0x3ff, %l0	! 0xfffff
a0154b8c:  95 3d a0 14  sra  %l6, 0x14, %o2
a0154b90:  03 00 02 57  sethi  %hi(0x95c00), %g1
a0154b94:  ac 0d 80 10  and  %l6, %l0, %l6
a0154b98:  82 10 63 64  or  %g1, 0x364, %g1
a0154b9c:  82 05 80 01  add  %l6, %g1, %g1
a0154ba0:  17 00 04 00  sethi  %hi(0x100000), %o3
a0154ba4:  ba 08 40 0b  and  %g1, %o3, %i5
a0154ba8:  03 0f fc 00  sethi  %hi(0x3ff00000), %g1
a0154bac:  82 1f 40 01  xor  %i5, %g1, %g1
a0154bb0:  98 10 40 16  or  %g1, %l6, %o4
a0154bb4:  94 02 80 1c  add  %o2, %i4, %o2
a0154bb8:  b8 02 bc 01  add  %o2, -1023, %i4
a0154bbc:  83 3f 60 14  sra  %i5, 0x14, %g1
a0154bc0:  b8 07 00 01  add  %i4, %g1, %i4
a0154bc4:  03 00 06 a0  sethi  %hi(0x1a8000), %g1
a0154bc8:  d4 18 62 30  ldd  [ %g1 + 0x230 ], %o2	! 0x1a8230
a0154bcc:  40 00 05 4c  call  0xa01560fc
a0154bd0:  90 10 00 0c  mov  %o4, %o0
a0154bd4:  82 05 a0 02  add  %l6, 2, %g1
a0154bd8:  82 08 40 10  and  %g1, %l0, %g1
a0154bdc:  b0 10 00 08  mov  %o0, %i0
a0154be0:  80 a0 60 02  cmp  %g1, 2
a0154be4:  04 80 00 71  ble  0xa0154da8
a0154be8:  b2 10 00 09  mov  %o1, %i1
a0154bec:  03 00 06 a0  sethi  %hi(0x1a8000), %g1
a0154bf0:  d4 18 62 50  ldd  [ %g1 + 0x250 ], %o2	! 0x1a8250
a0154bf4:  40 00 05 2e  call  0xa01560ac
a0154bf8:  90 10 00 18  mov  %i0, %o0
a0154bfc:  94 10 00 08  mov  %o0, %o2
a0154c00:  96 10 00 09  mov  %o1, %o3
a0154c04:  90 10 00 18  mov  %i0, %o0
a0154c08:  40 00 06 2a  call  0xa01564b0
a0154c0c:  92 10 00 19  mov  %i1, %o1
a0154c10:  d0 3f bf f0  std  %o0, [ %fp + -16 ]
a0154c14:  40 00 07 0b  call  0xa0156840
a0154c18:  90 10 00 1c  mov  %i4, %o0
a0154c1c:  b4 10 00 08  mov  %o0, %i2
a0154c20:  b6 10 00 09  mov  %o1, %i3
a0154c24:  d0 1f bf f0  ldd  [ %fp + -16 ], %o0
a0154c28:  94 10 00 08  mov  %o0, %o2
a0154c2c:  40 00 05 4b  call  0xa0156158
a0154c30:  96 10 00 09  mov  %o1, %o3
a0154c34:  03 3f fe 7a  sethi  %hi(0xfff9e800), %g1
a0154c38:  a4 10 00 08  mov  %o0, %l2
a0154c3c:  82 10 63 86  or  %g1, 0x386, %g1
a0154c40:  ba 05 80 01  add  %l6, %g1, %i5
a0154c44:  a6 10 00 09  mov  %o1, %l3
a0154c48:  94 10 00 12  mov  %l2, %o2
a0154c4c:  96 10 00 09  mov  %o1, %o3
a0154c50:  40 00 05 42  call  0xa0156158
a0154c54:  90 10 00 12  mov  %l2, %o0
a0154c58:  a0 10 00 08  mov  %o0, %l0
a0154c5c:  03 00 06 a0  sethi  %hi(0x1a8000), %g1
a0154c60:  a2 10 00 09  mov  %o1, %l1
a0154c64:  d4 18 62 58  ldd  [ %g1 + 0x258 ], %o2
a0154c68:  40 00 05 3c  call  0xa0156158
a0154c6c:  90 10 00 10  mov  %l0, %o0
a0154c70:  03 00 06 a0  sethi  %hi(0x1a8000), %g1
a0154c74:  40 00 05 0e  call  0xa01560ac
a0154c78:  d4 18 62 60  ldd  [ %g1 + 0x260 ], %o2	! 0x1a8260
a0154c7c:  94 10 00 10  mov  %l0, %o2
a0154c80:  40 00 05 36  call  0xa0156158
a0154c84:  96 10 00 11  mov  %l1, %o3
a0154c88:  03 00 06 a0  sethi  %hi(0x1a8000), %g1
a0154c8c:  40 00 05 08  call  0xa01560ac
a0154c90:  d4 18 62 68  ldd  [ %g1 + 0x268 ], %o2	! 0x1a8268
a0154c94:  29 00 01 ae  sethi  %hi(0x6b800), %l4
a0154c98:  94 10 00 10  mov  %l0, %o2
a0154c9c:  96 10 00 11  mov  %l1, %o3
a0154ca0:  40 00 05 2e  call  0xa0156158
a0154ca4:  a8 15 20 51  or  %l4, 0x51, %l4
a0154ca8:  a8 25 00 16  sub  %l4, %l6, %l4
a0154cac:  03 00 06 a0  sethi  %hi(0x1a8000), %g1
a0154cb0:  ac 10 00 08  mov  %o0, %l6
a0154cb4:  ae 10 00 09  mov  %o1, %l7
a0154cb8:  d4 18 62 70  ldd  [ %g1 + 0x270 ], %o2
a0154cbc:  90 10 00 10  mov  %l0, %o0
a0154cc0:  40 00 05 26  call  0xa0156158
a0154cc4:  92 10 00 11  mov  %l1, %o1
a0154cc8:  03 00 06 a0  sethi  %hi(0x1a8000), %g1
a0154ccc:  40 00 04 f8  call  0xa01560ac
a0154cd0:  d4 18 62 78  ldd  [ %g1 + 0x278 ], %o2	! 0x1a8278
a0154cd4:  94 10 00 10  mov  %l0, %o2
a0154cd8:  40 00 05 20  call  0xa0156158
a0154cdc:  96 10 00 11  mov  %l1, %o3
a0154ce0:  03 00 06 a0  sethi  %hi(0x1a8000), %g1
a0154ce4:  40 00 04 f2  call  0xa01560ac
a0154ce8:  d4 18 62 80  ldd  [ %g1 + 0x280 ], %o2	! 0x1a8280
a0154cec:  94 10 00 10  mov  %l0, %o2
a0154cf0:  40 00 05 1a  call  0xa0156158
a0154cf4:  96 10 00 11  mov  %l1, %o3
a0154cf8:  03 00 06 a0  sethi  %hi(0x1a8000), %g1
a0154cfc:  40 00 04 ec  call  0xa01560ac
a0154d00:  d4 18 62 88  ldd  [ %g1 + 0x288 ], %o2	! 0x1a8288
a0154d04:  94 10 00 12  mov  %l2, %o2
a0154d08:  40 00 05 14  call  0xa0156158
a0154d0c:  96 10 00 13  mov  %l3, %o3
a0154d10:  94 10 00 16  mov  %l6, %o2
a0154d14:  40 00 04 e6  call  0xa01560ac
a0154d18:  96 10 00 17  mov  %l7, %o3
a0154d1c:  ba 17 40 14  or  %i5, %l4, %i5
a0154d20:  a8 10 00 08  mov  %o0, %l4
a0154d24:  80 a7 60 00  cmp  %i5, 0
a0154d28:  04 80 00 ab  ble  0xa0154fd4
a0154d2c:  aa 10 00 09  mov  %o1, %l5
a0154d30:  03 00 06 69  sethi  %hi(0x19a400), %g1
a0154d34:  d4 18 62 38  ldd  [ %g1 + 0x238 ], %o2	! 0x19a638
a0154d38:  90 10 00 18  mov  %i0, %o0
a0154d3c:  40 00 05 07  call  0xa0156158
a0154d40:  92 10 00 19  mov  %i1, %o1
a0154d44:  94 10 00 18  mov  %i0, %o2
a0154d48:  40 00 05 04  call  0xa0156158
a0154d4c:  96 10 00 19  mov  %i1, %o3
a0154d50:  ac 10 00 08  mov  %o0, %l6
a0154d54:  80 a7 20 00  cmp  %i4, 0
a0154d58:  12 80 00 57  bne  0xa0154eb4
a0154d5c:  ae 10 00 09  mov  %o1, %l7
a0154d60:  94 10 00 14  mov  %l4, %o2
a0154d64:  96 10 00 15  mov  %l5, %o3
a0154d68:  40 00 04 d1  call  0xa01560ac
a0154d6c:  90 10 00 16  mov  %l6, %o0
a0154d70:  40 00 04 fa  call  0xa0156158
a0154d74:  d4 1f bf f0  ldd  [ %fp + -16 ], %o2
a0154d78:  94 10 00 08  mov  %o0, %o2
a0154d7c:  96 10 00 09  mov  %o1, %o3
a0154d80:  90 10 00 16  mov  %l6, %o0
a0154d84:  40 00 04 de  call  0xa01560fc
a0154d88:  92 10 00 17  mov  %l7, %o1
a0154d8c:  94 10 00 08  mov  %o0, %o2
a0154d90:  96 10 00 09  mov  %o1, %o3
a0154d94:  90 10 00 18  mov  %i0, %o0
a0154d98:  40 00 04 d9  call  0xa01560fc
a0154d9c:  92 10 00 19  mov  %i1, %o1
a0154da0:  10 80 00 b3  b  0xa015506c
a0154da4:  b0 10 00 08  mov  %o0, %i0
a0154da8:  03 00 06 a0  sethi  %hi(0x1a8000), %g1
a0154dac:  90 10 00 18  mov  %i0, %o0
a0154db0:  40 00 06 40  call  0xa01566b0
a0154db4:  d4 18 62 08  ldd  [ %g1 + 0x208 ], %o2
a0154db8:  80 a2 20 00  cmp  %o0, 0
a0154dbc:  32 80 00 1e  bne,a   0xa0154e34
a0154dc0:  94 10 00 18  mov  %i0, %o2
a0154dc4:  03 00 06 a0  sethi  %hi(0x1a8000), %g1
a0154dc8:  80 a7 20 00  cmp  %i4, 0
a0154dcc:  02 80 00 a7  be  0xa0155068
a0154dd0:  d0 18 62 08  ldd  [ %g1 + 0x208 ], %o0
a0154dd4:  40 00 06 9b  call  0xa0156840
a0154dd8:  90 10 00 1c  mov  %i4, %o0
a0154ddc:  03 00 06 a0  sethi  %hi(0x1a8000), %g1
a0154de0:  b4 10 00 08  mov  %o0, %i2
a0154de4:  d4 18 62 38  ldd  [ %g1 + 0x238 ], %o2
a0154de8:  b6 10 00 09  mov  %o1, %i3
a0154dec:  40 00 04 db  call  0xa0156158
a0154df0:  90 10 00 1a  mov  %i2, %o0
a0154df4:  a0 10 00 08  mov  %o0, %l0
a0154df8:  a2 10 00 09  mov  %o1, %l1
a0154dfc:  03 00 06 a0  sethi  %hi(0x1a8000), %g1
a0154e00:  d4 18 62 40  ldd  [ %g1 + 0x240 ], %o2	! 0x1a8240
a0154e04:  90 10 00 1a  mov  %i2, %o0
a0154e08:  40 00 04 d4  call  0xa0156158
a0154e0c:  92 10 00 1b  mov  %i3, %o1
a0154e10:  94 10 00 08  mov  %o0, %o2
a0154e14:  96 10 00 09  mov  %o1, %o3
a0154e18:  90 10 00 10  mov  %l0, %o0
a0154e1c:  10 bf ff 56  b  0xa0154b74
a0154e20:  92 10 00 11  mov  %l1, %o1
a0154e24:  40 00 04 b6  call  0xa01560fc
a0154e28:  96 10 00 19  mov  %i1, %o3
a0154e2c:  10 bf ff 40  b  0xa0154b2c
a0154e30:  03 00 06 a0  sethi  %hi(0x1a8000), %g1
a0154e34:  96 10 00 19  mov  %i1, %o3
a0154e38:  90 10 00 18  mov  %i0, %o0
a0154e3c:  40 00 04 c7  call  0xa0156158
a0154e40:  92 10 00 19  mov  %i1, %o1
a0154e44:  03 00 06 a0  sethi  %hi(0x1a8000), %g1
a0154e48:  a0 10 00 08  mov  %o0, %l0
a0154e4c:  a2 10 00 09  mov  %o1, %l1
a0154e50:  d4 18 62 48  ldd  [ %g1 + 0x248 ], %o2
a0154e54:  90 10 00 18  mov  %i0, %o0
a0154e58:  40 00 04 c0  call  0xa0156158
a0154e5c:  92 10 00 19  mov  %i1, %o1
a0154e60:  94 10 00 08  mov  %o0, %o2
a0154e64:  96 10 00 09  mov  %o1, %o3
a0154e68:  03 00 06 69  sethi  %hi(0x19a400), %g1
a0154e6c:  40 00 04 a4  call  0xa01560fc
a0154e70:  d0 18 62 38  ldd  [ %g1 + 0x238 ], %o0	! 0x19a638
a0154e74:  94 10 00 08  mov  %o0, %o2
a0154e78:  96 10 00 09  mov  %o1, %o3
a0154e7c:  90 10 00 10  mov  %l0, %o0
a0154e80:  40 00 04 b6  call  0xa0156158
a0154e84:  92 10 00 11  mov  %l1, %o1
a0154e88:  a8 10 00 08  mov  %o0, %l4
a0154e8c:  80 a7 20 00  cmp  %i4, 0
a0154e90:  12 80 00 33  bne  0xa0154f5c
a0154e94:  aa 10 00 09  mov  %o1, %l5
a0154e98:  90 10 00 18  mov  %i0, %o0
a0154e9c:  92 10 00 19  mov  %i1, %o1
a0154ea0:  94 10 00 14  mov  %l4, %o2
a0154ea4:  40 00 04 96  call  0xa01560fc
a0154ea8:  96 10 00 15  mov  %l5, %o3
a0154eac:  10 80 00 70  b  0xa015506c
a0154eb0:  b0 10 00 08  mov  %o0, %i0
a0154eb4:  03 00 06 a0  sethi  %hi(0x1a8000), %g1
a0154eb8:  d4 18 62 38  ldd  [ %g1 + 0x238 ], %o2	! 0x1a8238
a0154ebc:  90 10 00 1a  mov  %i2, %o0
a0154ec0:  40 00 04 a6  call  0xa0156158
a0154ec4:  92 10 00 1b  mov  %i3, %o1
a0154ec8:  a4 10 00 08  mov  %o0, %l2
a0154ecc:  a6 10 00 09  mov  %o1, %l3
a0154ed0:  94 10 00 14  mov  %l4, %o2
a0154ed4:  96 10 00 15  mov  %l5, %o3
a0154ed8:  90 10 00 16  mov  %l6, %o0
a0154edc:  40 00 04 74  call  0xa01560ac
a0154ee0:  92 10 00 17  mov  %l7, %o1
a0154ee4:  40 00 04 9d  call  0xa0156158
a0154ee8:  d4 1f bf f0  ldd  [ %fp + -16 ], %o2
a0154eec:  03 00 06 a0  sethi  %hi(0x1a8000), %g1
a0154ef0:  a0 10 00 08  mov  %o0, %l0
a0154ef4:  a2 10 00 09  mov  %o1, %l1
a0154ef8:  d4 18 62 40  ldd  [ %g1 + 0x240 ], %o2
a0154efc:  90 10 00 1a  mov  %i2, %o0
a0154f00:  40 00 04 96  call  0xa0156158
a0154f04:  92 10 00 1b  mov  %i3, %o1
a0154f08:  94 10 00 08  mov  %o0, %o2
a0154f0c:  96 10 00 09  mov  %o1, %o3
a0154f10:  90 10 00 10  mov  %l0, %o0
a0154f14:  40 00 04 66  call  0xa01560ac
a0154f18:  92 10 00 11  mov  %l1, %o1
a0154f1c:  94 10 00 08  mov  %o0, %o2
a0154f20:  96 10 00 09  mov  %o1, %o3
a0154f24:  90 10 00 16  mov  %l6, %o0
a0154f28:  92 10 00 17  mov  %l7, %o1
a0154f2c:  40 00 04 74  call  0xa01560fc
a0154f30:  01 00 00 00  nop
a0154f34:  94 10 00 18  mov  %i0, %o2
a0154f38:  40 00 04 71  call  0xa01560fc
a0154f3c:  96 10 00 19  mov  %i1, %o3
a0154f40:  94 10 00 08  mov  %o0, %o2
a0154f44:  96 10 00 09  mov  %o1, %o3
a0154f48:  90 10 00 12  mov  %l2, %o0
a0154f4c:  40 00 04 6c  call  0xa01560fc
a0154f50:  92 10 00 13  mov  %l3, %o1
a0154f54:  10 80 00 46  b  0xa015506c
a0154f58:  b0 10 00 08  mov  %o0, %i0
a0154f5c:  40 00 06 39  call  0xa0156840
a0154f60:  90 10 00 1c  mov  %i4, %o0
a0154f64:  b4 10 00 08  mov  %o0, %i2
a0154f68:  03 00 06 a0  sethi  %hi(0x1a8000), %g1
a0154f6c:  d4 18 62 38  ldd  [ %g1 + 0x238 ], %o2	! 0x1a8238
a0154f70:  b6 10 00 09  mov  %o1, %i3
a0154f74:  40 00 04 79  call  0xa0156158
a0154f78:  90 10 00 1a  mov  %i2, %o0
a0154f7c:  03 00 06 a0  sethi  %hi(0x1a8000), %g1
a0154f80:  a0 10 00 08  mov  %o0, %l0
a0154f84:  a2 10 00 09  mov  %o1, %l1
a0154f88:  d4 18 62 40  ldd  [ %g1 + 0x240 ], %o2
a0154f8c:  90 10 00 1a  mov  %i2, %o0
a0154f90:  40 00 04 72  call  0xa0156158
a0154f94:  92 10 00 1b  mov  %i3, %o1
a0154f98:  94 10 00 08  mov  %o0, %o2
a0154f9c:  96 10 00 09  mov  %o1, %o3
a0154fa0:  90 10 00 14  mov  %l4, %o0
a0154fa4:  40 00 04 56  call  0xa01560fc
a0154fa8:  92 10 00 15  mov  %l5, %o1
a0154fac:  94 10 00 18  mov  %i0, %o2
a0154fb0:  40 00 04 53  call  0xa01560fc
a0154fb4:  96 10 00 19  mov  %i1, %o3
a0154fb8:  94 10 00 08  mov  %o0, %o2
a0154fbc:  96 10 00 09  mov  %o1, %o3
a0154fc0:  90 10 00 10  mov  %l0, %o0
a0154fc4:  40 00 04 4e  call  0xa01560fc
a0154fc8:  92 10 00 11  mov  %l1, %o1
a0154fcc:  10 80 00 28  b  0xa015506c
a0154fd0:  b0 10 00 08  mov  %o0, %i0
a0154fd4:  80 a7 20 00  cmp  %i4, 0
a0154fd8:  12 80 00 0b  bne  0xa0155004
a0154fdc:  03 00 06 a0  sethi  %hi(0x1a8000), %g1
a0154fe0:  96 10 00 09  mov  %o1, %o3
a0154fe4:  94 10 00 14  mov  %l4, %o2
a0154fe8:  90 10 00 18  mov  %i0, %o0
a0154fec:  40 00 04 44  call  0xa01560fc
a0154ff0:  92 10 00 19  mov  %i1, %o1
a0154ff4:  40 00 04 59  call  0xa0156158
a0154ff8:  d4 1f bf f0  ldd  [ %fp + -16 ], %o2
a0154ffc:  10 bf ff 65  b  0xa0154d90
a0155000:  94 10 00 08  mov  %o0, %o2
a0155004:  d4 18 62 38  ldd  [ %g1 + 0x238 ], %o2
a0155008:  90 10 00 1a  mov  %i2, %o0
a015500c:  40 00 04 53  call  0xa0156158
a0155010:  92 10 00 1b  mov  %i3, %o1
a0155014:  a4 10 00 08  mov  %o0, %l2
a0155018:  a6 10 00 09  mov  %o1, %l3
a015501c:  94 10 00 14  mov  %l4, %o2
a0155020:  96 10 00 15  mov  %l5, %o3
a0155024:  90 10 00 18  mov  %i0, %o0
a0155028:  40 00 04 35  call  0xa01560fc
a015502c:  92 10 00 19  mov  %i1, %o1
a0155030:  40 00 04 4a  call  0xa0156158
a0155034:  d4 1f bf f0  ldd  [ %fp + -16 ], %o2
a0155038:  a0 10 00 08  mov  %o0, %l0
a015503c:  a2 10 00 09  mov  %o1, %l1
a0155040:  03 00 06 a0  sethi  %hi(0x1a8000), %g1
a0155044:  d4 18 62 40  ldd  [ %g1 + 0x240 ], %o2	! 0x1a8240
a0155048:  90 10 00 1a  mov  %i2, %o0
a015504c:  40 00 04 43  call  0xa0156158
a0155050:  92 10 00 1b  mov  %i3, %o1
a0155054:  94 10 00 08  mov  %o0, %o2
a0155058:  96 10 00 09  mov  %o1, %o3
a015505c:  90 10 00 10  mov  %l0, %o0
a0155060:  10 bf ff b3  b  0xa0154f2c
a0155064:  92 10 00 11  mov  %l1, %o1
a0155068:  b0 10 00 08  mov  %o0, %i0
a015506c:  81 c7 e0 08  ret
a0155070:  93 e8 00 09  restore  %g0, %o1, %o1
