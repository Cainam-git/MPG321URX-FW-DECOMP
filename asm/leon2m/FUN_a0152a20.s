# leon2m FUN_a0152a20 0xa0152a20-0xa0152e28 (1032 bytes)
a0152a20:  9d e3 bf 98  save  %sp, -104, %sp
a0152a24:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0152a28:  80 a6 20 71  cmp  %i0, 0x71
a0152a2c:  a6 10 00 19  mov  %i1, %l3
a0152a30:  02 80 00 4f  be  0xa0152b6c
a0152a34:  a8 10 00 1a  mov  %i2, %l4
a0152a38:  80 a6 20 71  cmp  %i0, 0x71
a0152a3c:  14 80 00 09  bg  0xa0152a60
a0152a40:  80 a6 20 b1  cmp  %i0, 0xb1
a0152a44:  80 a6 20 51  cmp  %i0, 0x51
a0152a48:  02 80 00 8f  be  0xa0152c84
a0152a4c:  80 a6 20 61  cmp  %i0, 0x61
a0152a50:  12 80 00 f4  bne  0xa0152e20
a0152a54:  96 10 20 00  clr  %o3
a0152a58:  10 80 00 c7  b  0xa0152d74
a0152a5c:  98 10 20 00  clr  %o4
a0152a60:  02 80 00 c0  be  0xa0152d60
a0152a64:  80 a6 20 b1  cmp  %i0, 0xb1
a0152a68:  14 80 00 27  bg  0xa0152b04
a0152a6c:  80 a6 20 ff  cmp  %i0, 0xff
a0152a70:  80 a6 20 81  cmp  %i0, 0x81
a0152a74:  12 80 00 eb  bne  0xa0152e20
a0152a78:  01 00 00 00  nop
a0152a7c:  7f ff 60 bc  call  0xa012ad6c
a0152a80:  a0 10 20 08  mov  8, %l0	! 0x8
a0152a84:  98 0a 20 ff  and  %o0, 0xff, %o4
a0152a88:  80 a3 20 01  cmp  %o4, 1
a0152a8c:  32 80 00 02  bne,a   0xa0152a94
a0152a90:  a0 10 20 0a  mov  0xa, %l0
a0152a94:  17 2a 00 b8  sethi  %hi(0xa802e000), %o3
a0152a98:  d0 0a e1 5c  ldub  [ %o3 + 0x15c ], %o0	! 0xa802e15c
a0152a9c:  96 0c 20 ff  and  %l0, 0xff, %o3
a0152aa0:  94 10 20 00  clr  %o2
a0152aa4:  98 10 20 00  clr  %o4
a0152aa8:  9a 10 20 00  clr  %o5
a0152aac:  b2 03 40 0d  add  %o5, %o5, %i1
a0152ab0:  b0 06 40 0d  add  %i1, %o5, %i0
a0152ab4:  98 03 20 01  inc  %o4
a0152ab8:  c2 0c c0 18  ldub  [ %l3 + %i0 ], %g1
a0152abc:  80 a0 40 0b  cmp  %g1, %o3
a0152ac0:  02 80 00 d6  be  0xa0152e18
a0152ac4:  9a 0b 20 ff  and  %o4, 0xff, %o5
a0152ac8:  80 a0 60 1f  cmp  %g1, 0x1f
a0152acc:  02 80 00 04  be  0xa0152adc
a0152ad0:  80 a3 60 09  cmp  %o5, 9
a0152ad4:  08 bf ff f7  bleu  0xa0152ab0
a0152ad8:  b2 03 40 0d  add  %o5, %o5, %i1
a0152adc:  80 8a a0 ff  btst  0xff, %o2
a0152ae0:  12 80 00 d0  bne  0xa0152e20
a0152ae4:  a4 0a 20 ff  and  %o0, 0xff, %l2
a0152ae8:  7f ff 49 96  call  0xa0125140
a0152aec:  90 10 00 12  mov  %l2, %o0
a0152af0:  9a 0a 20 ff  and  %o0, 0xff, %o5
a0152af4:  80 a3 60 ff  cmp  %o5, 0xff
a0152af8:  32 80 00 3f  bne,a   0xa0152bf4
a0152afc:  d2 0d 00 00  ldub  [ %l4 ], %o1
a0152b00:  30 80 00 c8  b,a   0xa0152e20
a0152b04:  12 80 00 c7  bne  0xa0152e20
a0152b08:  96 10 20 01  mov  1, %o3
a0152b0c:  d8 0e 80 00  ldub  [ %i2 ], %o4
a0152b10:  94 03 00 0c  add  %o4, %o4, %o2
a0152b14:  a4 02 80 0c  add  %o2, %o4, %l2
a0152b18:  de 0e 40 12  ldub  [ %i1 + %l2 ], %o7
a0152b1c:  a0 0b ff df  and  %o7, -33, %l0
a0152b20:  e0 2e 40 12  stb  %l0, [ %i1 + %l2 ]
a0152b24:  d2 0e 80 00  ldub  [ %i2 ], %o1
a0152b28:  90 02 40 09  add  %o1, %o1, %o0
a0152b2c:  b4 02 00 09  add  %o0, %o1, %i2
a0152b30:  e2 0e 40 1a  ldub  [ %i1 + %i2 ], %l1
a0152b34:  82 14 60 1f  or  %l1, 0x1f, %g1
a0152b38:  c2 2e 40 1a  stb  %g1, [ %i1 + %i2 ]
a0152b3c:  da 0d 00 00  ldub  [ %l4 ], %o5
a0152b40:  b2 03 40 0d  add  %o5, %o5, %i1
a0152b44:  b0 06 40 0d  add  %i1, %o5, %i0
a0152b48:  98 04 c0 18  add  %l3, %i0, %o4
a0152b4c:  d6 2b 20 01  stb  %o3, [ %o4 + 1 ]
a0152b50:  d4 0d 00 00  ldub  [ %l4 ], %o2
a0152b54:  9e 02 80 0a  add  %o2, %o2, %o7
a0152b58:  a0 03 c0 0a  add  %o7, %o2, %l0
a0152b5c:  a4 04 c0 10  add  %l3, %l0, %l2
a0152b60:  a6 10 3f ff  mov  -1, %l3
a0152b64:  10 80 00 44  b  0xa0152c74
a0152b68:  e6 2c a0 02  stb  %l3, [ %l2 + 2 ]
a0152b6c:  7f ff 60 80  call  0xa012ad6c
a0152b70:  a0 10 20 09  mov  9, %l0
a0152b74:  90 0a 20 ff  and  %o0, 0xff, %o0
a0152b78:  80 a2 20 01  cmp  %o0, 1
a0152b7c:  32 80 00 02  bne,a   0xa0152b84
a0152b80:  a0 10 20 07  mov  7, %l0
a0152b84:  13 2a 00 b8  sethi  %hi(0xa802e000), %o1
a0152b88:  d0 0a 61 4a  ldub  [ %o1 + 0x14a ], %o0	! 0xa802e14a
a0152b8c:  96 0c 20 ff  and  %l0, 0xff, %o3
a0152b90:  94 10 20 00  clr  %o2
a0152b94:  98 10 20 00  clr  %o4
a0152b98:  9a 10 20 00  clr  %o5
a0152b9c:  a2 03 40 0d  add  %o5, %o5, %l1
a0152ba0:  9e 04 40 0d  add  %l1, %o5, %o7
a0152ba4:  98 03 20 01  inc  %o4
a0152ba8:  c2 0c c0 0f  ldub  [ %l3 + %o7 ], %g1
a0152bac:  80 a0 40 0b  cmp  %g1, %o3
a0152bb0:  02 80 00 94  be  0xa0152e00
a0152bb4:  9a 0b 20 ff  and  %o4, 0xff, %o5
a0152bb8:  80 a0 60 1f  cmp  %g1, 0x1f
a0152bbc:  02 80 00 04  be  0xa0152bcc
a0152bc0:  80 a3 60 09  cmp  %o5, 9
a0152bc4:  08 bf ff f7  bleu  0xa0152ba0
a0152bc8:  a2 03 40 0d  add  %o5, %o5, %l1
a0152bcc:  80 8a a0 ff  btst  0xff, %o2
a0152bd0:  12 80 00 94  bne  0xa0152e20
a0152bd4:  a4 0a 20 ff  and  %o0, 0xff, %l2
a0152bd8:  7f ff 49 5a  call  0xa0125140
a0152bdc:  90 10 00 12  mov  %l2, %o0
a0152be0:  94 0a 20 ff  and  %o0, 0xff, %o2
a0152be4:  80 a2 a0 ff  cmp  %o2, 0xff
a0152be8:  02 80 00 8e  be  0xa0152e20
a0152bec:  01 00 00 00  nop
a0152bf0:  d2 0d 00 00  ldub  [ %l4 ], %o1
a0152bf4:  90 02 40 09  add  %o1, %o1, %o0
a0152bf8:  b4 02 00 09  add  %o0, %o1, %i2
a0152bfc:  e2 0c c0 1a  ldub  [ %l3 + %i2 ], %l1
a0152c00:  82 0c 7f df  and  %l1, -33, %g1
a0152c04:  c2 2c c0 1a  stb  %g1, [ %l3 + %i2 ]
a0152c08:  da 0d 00 00  ldub  [ %l4 ], %o5
a0152c0c:  b2 03 40 0d  add  %o5, %o5, %i1
a0152c10:  94 06 40 0d  add  %i1, %o5, %o2
a0152c14:  f0 0c c0 0a  ldub  [ %l3 + %o2 ], %i0
a0152c18:  96 0e 3f e0  and  %i0, -32, %o3
a0152c1c:  98 12 c0 10  or  %o3, %l0, %o4
a0152c20:  d8 2c c0 0a  stb  %o4, [ %l3 + %o2 ]
a0152c24:  de 0d 00 00  ldub  [ %l4 ], %o7
a0152c28:  92 03 c0 0f  add  %o7, %o7, %o1
a0152c2c:  90 02 40 0f  add  %o1, %o7, %o0
a0152c30:  a2 04 c0 08  add  %l3, %o0, %l1
a0152c34:  7f ff 49 a4  call  0xa01252c4
a0152c38:  90 10 00 12  mov  %l2, %o0
a0152c3c:  d0 2c 60 01  stb  %o0, [ %l1 + 1 ]
a0152c40:  c2 0d 00 00  ldub  [ %l4 ], %g1
a0152c44:  b4 00 40 01  add  %g1, %g1, %i2
a0152c48:  a0 06 80 01  add  %i2, %g1, %l0
a0152c4c:  7f ff 49 36  call  0xa0125124
a0152c50:  90 10 00 12  mov  %l2, %o0
a0152c54:  a2 04 c0 10  add  %l3, %l0, %l1
a0152c58:  a0 0a 20 0f  and  %o0, 0xf, %l0
a0152c5c:  7f ff 49 8e  call  0xa0125294
a0152c60:  90 10 00 12  mov  %l2, %o0
a0152c64:  82 0a 20 0f  and  %o0, 0xf, %g1
a0152c68:  a5 28 60 04  sll  %g1, 4, %l2
a0152c6c:  a6 14 00 12  or  %l0, %l2, %l3
a0152c70:  e6 2c 60 02  stb  %l3, [ %l1 + 2 ]
a0152c74:  d6 0d 00 00  ldub  [ %l4 ], %o3
a0152c78:  a6 02 e0 01  add  %o3, 1, %l3
a0152c7c:  10 80 00 69  b  0xa0152e20
a0152c80:  e6 2d 00 00  stb  %l3, [ %l4 ]
a0152c84:  96 10 20 00  clr  %o3
a0152c88:  98 10 20 00  clr  %o4
a0152c8c:  9a 10 20 00  clr  %o5
a0152c90:  90 03 40 0d  add  %o5, %o5, %o0
a0152c94:  82 02 00 0d  add  %o0, %o5, %g1
a0152c98:  98 03 20 01  inc  %o4
a0152c9c:  c2 0c c0 01  ldub  [ %l3 + %g1 ], %g1
a0152ca0:  80 a0 60 05  cmp  %g1, 5
a0152ca4:  02 80 00 59  be  0xa0152e08
a0152ca8:  9a 0b 20 ff  and  %o4, 0xff, %o5
a0152cac:  80 a0 60 1f  cmp  %g1, 0x1f
a0152cb0:  02 80 00 04  be  0xa0152cc0
a0152cb4:  80 a3 60 09  cmp  %o5, 9
a0152cb8:  08 bf ff f7  bleu  0xa0152c94
a0152cbc:  90 03 40 0d  add  %o5, %o5, %o0
a0152cc0:  80 8a e0 ff  btst  0xff, %o3
a0152cc4:  12 80 00 57  bne  0xa0152e20
a0152cc8:  03 2a 00 b8  sethi  %hi(0xa802e000), %g1
a0152ccc:  d2 0d 00 00  ldub  [ %l4 ], %o1
a0152cd0:  90 02 40 09  add  %o1, %o1, %o0
a0152cd4:  96 02 00 09  add  %o0, %o1, %o3
a0152cd8:  f4 00 63 d0  ld  [ %g1 + 0x3d0 ], %i2
a0152cdc:  f2 0c c0 0b  ldub  [ %l3 + %o3 ], %i1
a0152ce0:  b1 36 a0 0d  srl  %i2, 0xd, %i0
a0152ce4:  a4 0e 20 20  and  %i0, 0x20, %l2
a0152ce8:  a2 0e 7f df  and  %i1, -33, %l1
a0152cec:  9e 14 40 12  or  %l1, %l2, %o7
a0152cf0:  21 2a 00 b8  sethi  %hi(0xa802e000), %l0
a0152cf4:  e4 0c 21 26  ldub  [ %l0 + 0x126 ], %l2	! 0xa802e126
a0152cf8:  de 2c c0 0b  stb  %o7, [ %l3 + %o3 ]
a0152cfc:  d8 0d 00 00  ldub  [ %l4 ], %o4
a0152d00:  9a 03 00 0c  add  %o4, %o4, %o5
a0152d04:  9a 03 40 0c  add  %o5, %o4, %o5
a0152d08:  d4 0c c0 0d  ldub  [ %l3 + %o5 ], %o2
a0152d0c:  92 0a bf e0  and  %o2, -32, %o1
a0152d10:  82 12 60 05  or  %o1, 5, %g1
a0152d14:  c2 2c c0 0d  stb  %g1, [ %l3 + %o5 ]
a0152d18:  f4 0d 00 00  ldub  [ %l4 ], %i2
a0152d1c:  b2 06 80 1a  add  %i2, %i2, %i1
a0152d20:  b0 06 40 1a  add  %i1, %i2, %i0
a0152d24:  7f ff 49 68  call  0xa01252c4
a0152d28:  90 10 00 12  mov  %l2, %o0
a0152d2c:  a2 04 c0 18  add  %l3, %i0, %l1
a0152d30:  d0 2c 60 01  stb  %o0, [ %l1 + 1 ]
a0152d34:  e0 0d 00 00  ldub  [ %l4 ], %l0
a0152d38:  9a 04 00 10  add  %l0, %l0, %o5
a0152d3c:  96 03 40 10  add  %o5, %l0, %o3
a0152d40:  a2 04 c0 0b  add  %l3, %o3, %l1
a0152d44:  7f ff 48 f8  call  0xa0125124
a0152d48:  90 10 00 12  mov  %l2, %o0
a0152d4c:  a0 0a 20 0f  and  %o0, 0xf, %l0
a0152d50:  7f ff 49 45  call  0xa0125264
a0152d54:  90 10 00 12  mov  %l2, %o0
a0152d58:  10 bf ff c4  b  0xa0152c68
a0152d5c:  82 0a 20 0f  and  %o0, 0xf, %g1
a0152d60:  7f fe ae 5a  call  0xa00fe6c8
a0152d64:  01 00 00 00  nop
a0152d68:  b0 0a 20 ff  and  %o0, 0xff, %i0
a0152d6c:  7f ff ff 2d  call  0xa0152a20
a0152d70:  81 e8 00 00  restore
a0152d74:  9a 10 20 00  clr  %o5
a0152d78:  9e 03 40 0d  add  %o5, %o5, %o7
a0152d7c:  94 03 c0 0d  add  %o7, %o5, %o2
a0152d80:  98 03 20 01  inc  %o4
a0152d84:  c2 0c c0 0a  ldub  [ %l3 + %o2 ], %g1
a0152d88:  80 a0 60 06  cmp  %g1, 6
a0152d8c:  02 80 00 21  be  0xa0152e10
a0152d90:  9a 0b 20 ff  and  %o4, 0xff, %o5
a0152d94:  80 a0 60 1f  cmp  %g1, 0x1f
a0152d98:  02 80 00 04  be  0xa0152da8
a0152d9c:  80 a3 60 09  cmp  %o5, 9
a0152da0:  08 bf ff f7  bleu  0xa0152d7c
a0152da4:  9e 03 40 0d  add  %o5, %o5, %o7
a0152da8:  80 8a e0 ff  btst  0xff, %o3
a0152dac:  12 80 00 1d  bne  0xa0152e20
a0152db0:  15 2a 00 b8  sethi  %hi(0xa802e000), %o2
a0152db4:  d8 0d 00 00  ldub  [ %l4 ], %o4
a0152db8:  9e 03 00 0c  add  %o4, %o4, %o7
a0152dbc:  a2 03 c0 0c  add  %o7, %o4, %l1
a0152dc0:  d2 02 a3 d0  ld  [ %o2 + 0x3d0 ], %o1
a0152dc4:  83 32 60 0d  srl  %o1, 0xd, %g1
a0152dc8:  d0 0c c0 11  ldub  [ %l3 + %l1 ], %o0
a0152dcc:  a4 0a 3f df  and  %o0, -33, %l2
a0152dd0:  b4 08 60 20  and  %g1, 0x20, %i2
a0152dd4:  b0 14 80 1a  or  %l2, %i2, %i0
a0152dd8:  33 2a 00 b8  sethi  %hi(0xa802e000), %i1
a0152ddc:  e4 0e 61 38  ldub  [ %i1 + 0x138 ], %l2	! 0xa802e138
a0152de0:  f0 2c c0 11  stb  %i0, [ %l3 + %l1 ]
a0152de4:  e0 0d 00 00  ldub  [ %l4 ], %l0
a0152de8:  9a 04 00 10  add  %l0, %l0, %o5
a0152dec:  9a 03 40 10  add  %o5, %l0, %o5
a0152df0:  d6 0c c0 0d  ldub  [ %l3 + %o5 ], %o3
a0152df4:  98 0a ff e0  and  %o3, -32, %o4
a0152df8:  10 bf ff c7  b  0xa0152d14
a0152dfc:  82 13 20 06  or  %o4, 6, %g1
a0152e00:  10 bf ff 73  b  0xa0152bcc
a0152e04:  94 10 20 01  mov  1, %o2
a0152e08:  10 bf ff ae  b  0xa0152cc0
a0152e0c:  96 10 20 01  mov  1, %o3
a0152e10:  10 bf ff e6  b  0xa0152da8
a0152e14:  96 10 20 01  mov  1, %o3
a0152e18:  10 bf ff 31  b  0xa0152adc
a0152e1c:  94 10 20 01  mov  1, %o2
a0152e20:  81 c7 e0 08  ret
a0152e24:  81 e8 00 00  restore
