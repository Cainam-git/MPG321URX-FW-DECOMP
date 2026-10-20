# leon2m FUN_a00d2a98 0xa00d2a98-0xa00d3650 (772 bytes)
a00d2a98:  9d e3 bf 70  save  %sp, -144, %sp
a00d2a9c:  a0 10 20 00  clr  %l0
a00d2aa0:  a6 10 20 0a  mov  0xa, %l3
a00d2aa4:  98 10 20 00  clr  %o4
a00d2aa8:  9a 10 20 00  clr  %o5
a00d2aac:  96 07 bf f8  add  %fp, -8, %o3
a00d2ab0:  82 02 c0 0d  add  %o3, %o5, %g1
a00d2ab4:  98 03 20 01  inc  %o4
a00d2ab8:  9a 0b 20 ff  and  %o4, 0xff, %o5
a00d2abc:  80 a3 60 27  cmp  %o5, 0x27
a00d2ac0:  08 bf ff fc  bleu  0xa00d2ab0
a00d2ac4:  c0 28 7f d8  clrb  [ %g1 + -40 ]
a00d2ac8:  d8 0e 60 03  ldub  [ %i1 + 3 ], %o4
a00d2acc:  d6 0e 60 04  ldub  [ %i1 + 4 ], %o3
a00d2ad0:  d4 0e 60 05  ldub  [ %i1 + 5 ], %o2
a00d2ad4:  d2 0e 60 06  ldub  [ %i1 + 6 ], %o1
a00d2ad8:  a2 10 20 6e  mov  0x6e, %l1
a00d2adc:  9e 10 3f 86  mov  -122, %o7
a00d2ae0:  9a 10 3f c0  mov  -64, %o5
a00d2ae4:  e2 2f bf d0  stb  %l1, [ %fp + -48 ]
a00d2ae8:  de 2f bf d1  stb  %o7, [ %fp + -47 ]
a00d2aec:  da 2f bf d2  stb  %o5, [ %fp + -46 ]
a00d2af0:  d6 2f bf d4  stb  %o3, [ %fp + -44 ]
a00d2af4:  d8 2f bf d3  stb  %o4, [ %fp + -45 ]
a00d2af8:  d4 2f bf d5  stb  %o2, [ %fp + -43 ]
a00d2afc:  d2 2f bf d6  stb  %o1, [ %fp + -42 ]
a00d2b00:  80 a3 20 63  cmp  %o4, 0x63
a00d2b04:  02 80 00 07  be  0xa00d2b20
a00d2b08:  a8 07 bf d0  add  %fp, -48, %l4
a00d2b0c:  80 a3 20 73  cmp  %o4, 0x73
a00d2b10:  32 80 02 c4  bne,a   0xa00d3620
a00d2b14:  94 0c 20 ff  and  %l0, 0xff, %o2
a00d2b18:  10 80 00 0c  b  0xa00d2b48
a00d2b1c:  82 0a a0 ff  and  %o2, 0xff, %g1
a00d2b20:  82 0a a0 ff  and  %o2, 0xff, %g1
a00d2b24:  80 a0 60 d0  cmp  %g1, 0xd0
a00d2b28:  38 80 02 bd  bgu,a   0xa00d361c
a00d2b2c:  a0 10 3f e3  mov  -29, %l0
a00d2b30:  19 00 01 bb  sethi  %hi(0x6ec00), %o4
a00d2b34:  95 28 60 02  sll  %g1, 2, %o2
a00d2b38:  a4 13 21 b0  or  %o4, 0x1b0, %l2
a00d2b3c:  d0 04 80 0a  ld  [ %l2 + %o2 ], %o0
a00d2b40:  81 c2 00 00  jmp  %o0
a00d2b44:  01 00 00 00  nop
a00d2b48:  80 a0 60 6a  cmp  %g1, 0x6a
a00d2b4c:  22 80 02 b4  be,a   0xa00d361c
a00d2b50:  a0 10 20 6a  mov  0x6a, %l0
a00d2b54:  14 80 00 19  bg  0xa00d2bb8
a00d2b58:  80 a0 60 74  cmp  %g1, 0x74
a00d2b5c:  80 a0 60 11  cmp  %g1, 0x11
a00d2b60:  22 80 01 98  be,a   0xa00d31c0
a00d2b64:  a0 10 3f 92  mov  -110, %l0
a00d2b68:  14 80 00 41  bg  0xa00d2c6c
a00d2b6c:  80 a0 60 1e  cmp  %g1, 0x1e
a00d2b70:  80 a0 60 0a  cmp  %g1, 0xa
a00d2b74:  02 80 02 aa  be  0xa00d361c
a00d2b78:  a0 10 20 0a  mov  0xa, %l0
a00d2b7c:  80 a0 60 0a  cmp  %g1, 0xa
a00d2b80:  14 80 01 a7  bg  0xa00d321c
a00d2b84:  80 a0 60 0e  cmp  %g1, 0xe
a00d2b88:  80 a0 60 02  cmp  %g1, 2
a00d2b8c:  02 80 02 a4  be  0xa00d361c
a00d2b90:  a0 10 20 02  mov  2, %l0
a00d2b94:  80 a0 60 08  cmp  %g1, 8
a00d2b98:  32 80 02 a1  bne,a   0xa00d361c
a00d2b9c:  a0 10 3f e3  mov  -29, %l0
a00d2ba0:  10 80 02 9f  b  0xa00d361c
a00d2ba4:  a0 10 20 08  mov  8, %l0
a00d2ba8:  02 80 02 9d  be  0xa00d361c
a00d2bac:  a0 10 3f fe  mov  -2, %l0
a00d2bb0:  10 80 02 9b  b  0xa00d361c
a00d2bb4:  a0 10 3f e3  mov  -29, %l0
a00d2bb8:  02 80 01 7e  be  0xa00d31b0
a00d2bbc:  80 a0 60 74  cmp  %g1, 0x74
a00d2bc0:  04 80 00 1c  ble  0xa00d2c30
a00d2bc4:  80 a0 60 6e  cmp  %g1, 0x6e
a00d2bc8:  80 a0 60 c2  cmp  %g1, 0xc2
a00d2bcc:  02 80 02 94  be  0xa00d361c
a00d2bd0:  a0 10 3f c2  mov  -62, %l0
a00d2bd4:  80 a0 60 c2  cmp  %g1, 0xc2
a00d2bd8:  14 80 01 83  bg  0xa00d31e4
a00d2bdc:  80 a0 60 d0  cmp  %g1, 0xd0
a00d2be0:  80 a0 60 aa  cmp  %g1, 0xaa
a00d2be4:  02 80 02 8e  be  0xa00d361c
a00d2be8:  a0 10 3f aa  mov  -86, %l0
a00d2bec:  80 a0 60 c1  cmp  %g1, 0xc1
a00d2bf0:  32 80 02 8b  bne,a   0xa00d361c
a00d2bf4:  a0 10 3f e3  mov  -29, %l0
a00d2bf8:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00d2bfc:  92 12 a2 74  or  %o2, 0x274, %o1	! 0xa802d274
a00d2c00:  d8 12 60 18  lduh  [ %o1 + 0x18 ], %o4
a00d2c04:  03 3f ff e0  sethi  %hi(0xffff8000), %g1
a00d2c08:  da 0a 60 15  ldub  [ %o1 + 0x15 ], %o5
a00d2c0c:  a2 13 00 01  or  %o4, %g1, %l1
a00d2c10:  da 2f bf d6  stb  %o5, [ %fp + -42 ]
a00d2c14:  e2 32 60 18  sth  %l1, [ %o1 + 0x18 ]
a00d2c18:  90 10 20 30  mov  0x30, %o0
a00d2c1c:  94 10 22 e0  mov  0x2e0, %o2
a00d2c20:  40 01 e0 ac  call  0xa014aed0
a00d2c24:  96 10 20 1c  mov  0x1c, %o3
a00d2c28:  10 80 02 7d  b  0xa00d361c
a00d2c2c:  a0 10 3f e0  mov  -32, %l0
a00d2c30:  02 80 02 7b  be  0xa00d361c
a00d2c34:  a0 10 20 6e  mov  0x6e, %l0
a00d2c38:  80 a0 60 6e  cmp  %g1, 0x6e
a00d2c3c:  14 80 01 80  bg  0xa00d323c
a00d2c40:  80 a0 60 6f  cmp  %g1, 0x6f
a00d2c44:  80 a0 60 6b  cmp  %g1, 0x6b
a00d2c48:  02 80 01 91  be  0xa00d328c
a00d2c4c:  80 a0 60 6c  cmp  %g1, 0x6c
a00d2c50:  32 80 02 73  bne,a   0xa00d361c
a00d2c54:  a0 10 3f e3  mov  -29, %l0
a00d2c58:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00d2c5c:  da 0a e2 a0  ldub  [ %o3 + 0x2a0 ], %o5	! 0xa802d2a0
a00d2c60:  da 2f bf d6  stb  %o5, [ %fp + -42 ]
a00d2c64:  10 80 02 6e  b  0xa00d361c
a00d2c68:  a0 10 3f e0  mov  -32, %l0
a00d2c6c:  02 80 02 6c  be  0xa00d361c
a00d2c70:  80 a0 60 1e  cmp  %g1, 0x1e
a00d2c74:  14 80 01 55  bg  0xa00d31c8
a00d2c78:  80 a0 60 1f  cmp  %g1, 0x1f
a00d2c7c:  80 a0 60 1c  cmp  %g1, 0x1c
a00d2c80:  02 80 02 67  be  0xa00d361c
a00d2c84:  a0 10 3f 93  mov  -109, %l0
a00d2c88:  80 a0 60 1d  cmp  %g1, 0x1d
a00d2c8c:  32 80 02 64  bne,a   0xa00d361c
a00d2c90:  a0 10 3f e3  mov  -29, %l0
a00d2c94:  10 80 02 62  b  0xa00d361c
a00d2c98:  a0 10 3f 97  mov  -105, %l0
a00d2c9c:  c2 0e 60 07  ldub  [ %i1 + 7 ], %g1
a00d2ca0:  80 a0 60 01  cmp  %g1, 1
a00d2ca4:  02 80 01 d2  be  0xa00d33ec
a00d2ca8:  80 a0 60 00  cmp  %g1, 0
a00d2cac:  02 80 01 c9  be  0xa00d33d0
a00d2cb0:  80 a0 60 02  cmp  %g1, 2
a00d2cb4:  12 80 00 0b  bne  0xa00d2ce0
a00d2cb8:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00d2cbc:  40 01 a8 6c  call  0xa013ce6c
a00d2cc0:  90 10 20 00  clr  %o0
a00d2cc4:  92 0a 20 ff  and  %o0, 0xff, %o1
a00d2cc8:  80 a2 60 01  cmp  %o1, 1
a00d2ccc:  02 80 00 04  be  0xa00d2cdc
a00d2cd0:  90 10 20 03  mov  3, %o0
a00d2cd4:  7f fe bc 75  call  0xa0081ea8
a00d2cd8:  01 00 00 00  nop
a00d2cdc:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00d2ce0:  92 12 62 90  or  %o1, 0x290, %o1	! 0xa802d290
a00d2ce4:  94 10 20 00  clr  %o2
a00d2ce8:  96 10 21 fc  mov  0x1fc, %o3
a00d2cec:  40 01 e0 79  call  0xa014aed0
a00d2cf0:  90 10 20 30  mov  0x30, %o0
a00d2cf4:  10 80 02 4a  b  0xa00d361c
a00d2cf8:  a0 10 3f e0  mov  -32, %l0
a00d2cfc:  7f ff fb 93  call  0xa00d1b48
a00d2d00:  01 00 00 00  nop
a00d2d04:  10 80 02 46  b  0xa00d361c
a00d2d08:  a0 10 00 08  mov  %o0, %l0
a00d2d0c:  c2 0e 60 07  ldub  [ %i1 + 7 ], %g1
a00d2d10:  80 a0 60 01  cmp  %g1, 1
a00d2d14:  02 80 01 8b  be  0xa00d3340
a00d2d18:  80 a0 60 00  cmp  %g1, 0
a00d2d1c:  02 80 01 83  be  0xa00d3328
a00d2d20:  01 00 00 00  nop
a00d2d24:  40 01 c9 8f  call  0xa0145360
a00d2d28:  90 10 20 01  mov  1, %o0	! 0x1
a00d2d2c:  10 80 02 3c  b  0xa00d361c
a00d2d30:  a0 10 3f e0  mov  -32, %l0
a00d2d34:  1f 2a 00 b8  sethi  %hi(0xa802e000), %o7
a00d2d38:  90 13 e1 a0  or  %o7, 0x1a0, %o0	! 0xa802e1a0
a00d2d3c:  13 3f c0 00  sethi  %hi(0xff000000), %o1
a00d2d40:  d6 02 20 08  ld  [ %o0 + 8 ], %o3
a00d2d44:  a4 12 60 ff  or  %o1, 0xff, %l2
a00d2d48:  9a 0a c0 12  and  %o3, %l2, %o5
a00d2d4c:  da 22 20 08  st  %o5, [ %o0 + 8 ]
a00d2d50:  c0 2a 20 08  clrb  [ %o0 + 8 ]
a00d2d54:  40 02 03 07  call  0xa0153970
a00d2d58:  92 10 20 01  mov  1, %o1
a00d2d5c:  10 80 02 31  b  0xa00d3620
a00d2d60:  94 0c 20 ff  and  %l0, 0xff, %o2
a00d2d64:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00d2d68:  92 13 22 74  or  %o4, 0x274, %o1	! 0xa802d274
a00d2d6c:  c0 2a 60 15  clrb  [ %o1 + 0x15 ]
a00d2d70:  10 bf ff aa  b  0xa00d2c18
a00d2d74:  c0 32 60 16  clrh  [ %o1 + 0x16 ]
a00d2d78:  23 2a 00 b4  sethi  %hi(0xa802d000), %l1
a00d2d7c:  e4 04 62 90  ld  [ %l1 + 0x290 ], %l2	! 0xa802d290
a00d2d80:  95 34 a0 09  srl  %l2, 9, %o2
a00d2d84:  a0 0a a0 01  and  %o2, 1, %l0
a00d2d88:  11 2a 00 97  sethi  %hi(0xa8025c00), %o0
a00d2d8c:  e0 2a 20 56  stb  %l0, [ %o0 + 0x56 ]	! 0xa8025c56
a00d2d90:  de 0e 60 07  ldub  [ %i1 + 7 ], %o7
a00d2d94:  80 a0 00 0f  cmp  %g0, %o7
a00d2d98:  92 40 20 00  addx  %g0, 0, %o1
a00d2d9c:  9b 2a 60 09  sll  %o1, 9, %o5
a00d2da0:  96 0c bd ff  and  %l2, -513, %o3
a00d2da4:  90 12 c0 0d  or  %o3, %o5, %o0
a00d2da8:  99 32 20 09  srl  %o0, 9, %o4
a00d2dac:  82 0b 20 01  and  %o4, 1, %g1
a00d2db0:  80 a4 00 01  cmp  %l0, %g1
a00d2db4:  02 bf ff 9d  be  0xa00d2c28
a00d2db8:  d0 24 62 90  st  %o0, [ %l1 + 0x290 ]
a00d2dbc:  40 00 0a d7  call  0xa00d5918
a00d2dc0:  01 00 00 00  nop
a00d2dc4:  1b 2a 00 ac  sethi  %hi(0xa802b000), %o5
a00d2dc8:  e2 0b 60 8e  ldub  [ %o5 + 0x8e ], %l1	! 0xa802b08e
a00d2dcc:  82 14 60 02  or  %l1, 2, %g1
a00d2dd0:  c2 2b 60 8e  stb  %g1, [ %o5 + 0x8e ]
a00d2dd4:  a0 10 3f e0  mov  -32, %l0
a00d2dd8:  10 80 02 12  b  0xa00d3620
a00d2ddc:  94 0c 20 ff  and  %l0, 0xff, %o2
a00d2de0:  7f ff fc 5e  call  0xa00d1f58
a00d2de4:  90 10 00 19  mov  %i1, %o0
a00d2de8:  10 80 02 0d  b  0xa00d361c
a00d2dec:  a0 10 00 08  mov  %o0, %l0
a00d2df0:  da 0e 60 07  ldub  [ %i1 + 7 ], %o5
a00d2df4:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00d2df8:  80 a3 60 64  cmp  %o5, 0x64
a00d2dfc:  08 80 01 3f  bleu  0xa00d32f8
a00d2e00:  98 12 22 90  or  %o0, 0x290, %o4
a00d2e04:  94 10 20 64  mov  0x64, %o2
a00d2e08:  40 00 13 f6  call  0xa00d7de0
a00d2e0c:  d4 2b 20 0a  stb  %o2, [ %o4 + 0xa ]
a00d2e10:  10 80 02 03  b  0xa00d361c
a00d2e14:  a0 10 3f e0  mov  -32, %l0
a00d2e18:  da 0e 60 07  ldub  [ %i1 + 7 ], %o5
a00d2e1c:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a00d2e20:  80 a3 60 64  cmp  %o5, 0x64
a00d2e24:  08 80 01 2b  bleu  0xa00d32d0
a00d2e28:  98 14 22 90  or  %l0, 0x290, %o4
a00d2e2c:  9e 10 20 64  mov  0x64, %o7
a00d2e30:  de 2b 20 09  stb  %o7, [ %o4 + 9 ]
a00d2e34:  40 00 17 a8  call  0xa00d8cd4
a00d2e38:  a0 10 3f e0  mov  -32, %l0
a00d2e3c:  1b 2a 00 ac  sethi  %hi(0xa802b000), %o5
a00d2e40:  e2 0b 60 8e  ldub  [ %o5 + 0x8e ], %l1	! 0xa802b08e
a00d2e44:  82 14 60 04  or  %l1, 4, %g1
a00d2e48:  10 bf ff e4  b  0xa00d2dd8
a00d2e4c:  c2 2b 60 8e  stb  %g1, [ %o5 + 0x8e ]
a00d2e50:  c2 0e 60 07  ldub  [ %i1 + 7 ], %g1
a00d2e54:  80 a0 60 02  cmp  %g1, 2
a00d2e58:  02 80 00 c4  be  0xa00d3168
a00d2e5c:  98 10 20 00  clr  %o4
a00d2e60:  14 80 01 2a  bg  0xa00d3308
a00d2e64:  80 a0 60 03  cmp  %g1, 3
a00d2e68:  80 a0 60 01  cmp  %g1, 1
a00d2e6c:  02 80 00 bf  be  0xa00d3168
a00d2e70:  98 10 20 02  mov  2, %o4
a00d2e74:  90 10 20 e3  mov  0xe3, %o0
a00d2e78:  10 80 01 e9  b  0xa00d361c
a00d2e7c:  a0 10 00 08  mov  %o0, %l0
a00d2e80:  10 80 01 e7  b  0xa00d361c
a00d2e84:  a0 10 20 00  clr  %l0
a00d2e88:  82 0a 60 ff  and  %o1, 0xff, %g1
a00d2e8c:  80 a0 60 02  cmp  %g1, 2
a00d2e90:  02 80 01 41  be  0xa00d3394
a00d2e94:  15 2a 00 b8  sethi  %hi(0xa802e000), %o2
a00d2e98:  14 80 01 04  bg  0xa00d32a8
a00d2e9c:  80 a0 60 03  cmp  %g1, 3
a00d2ea0:  80 a0 60 01  cmp  %g1, 1
a00d2ea4:  12 bf ff f5  bne  0xa00d2e78
a00d2ea8:  90 10 20 e3  mov  0xe3, %o0
a00d2eac:  15 2a 00 b8  sethi  %hi(0xa802e000), %o2
a00d2eb0:  a4 12 a1 f0  or  %o2, 0x1f0, %l2	! 0xa802e1f0
a00d2eb4:  d6 0c a0 08  ldub  [ %l2 + 8 ], %o3
a00d2eb8:  da 0c a0 06  ldub  [ %l2 + 6 ], %o5
a00d2ebc:  d8 0c a0 07  ldub  [ %l2 + 7 ], %o4
a00d2ec0:  c2 0e 60 07  ldub  [ %i1 + 7 ], %g1
a00d2ec4:  80 a0 60 02  cmp  %g1, 2
a00d2ec8:  02 80 01 2f  be  0xa00d3384
a00d2ecc:  90 12 a1 f0  or  %o2, 0x1f0, %o0
a00d2ed0:  14 80 01 24  bg  0xa00d3360
a00d2ed4:  80 a0 60 03  cmp  %g1, 3
a00d2ed8:  80 a0 60 01  cmp  %g1, 1
a00d2edc:  32 bf ff e7  bne,a   0xa00d2e78
a00d2ee0:  90 10 20 e3  mov  0xe3, %o0
a00d2ee4:  82 12 a1 f0  or  %o2, 0x1f0, %g1
a00d2ee8:  d6 28 60 08  stb  %o3, [ %g1 + 8 ]
a00d2eec:  da 28 60 06  stb  %o5, [ %g1 + 6 ]
a00d2ef0:  d8 28 60 07  stb  %o4, [ %g1 + 7 ]
a00d2ef4:  40 01 c9 1b  call  0xa0145360
a00d2ef8:  90 10 20 00  clr  %o0
a00d2efc:  90 10 20 e0  mov  0xe0, %o0
a00d2f00:  10 80 01 c7  b  0xa00d361c
a00d2f04:  a0 10 00 08  mov  %o0, %l0
a00d2f08:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00d2f0c:  a2 12 22 90  or  %o0, 0x290, %l1	! 0xa802d290
a00d2f10:  d6 0e 60 07  ldub  [ %i1 + 7 ], %o3
a00d2f14:  40 00 06 97  call  0xa00d4970
a00d2f18:  d6 2c 60 10  stb  %o3, [ %l1 + 0x10 ]
a00d2f1c:  10 bf ff 72  b  0xa00d2ce4
a00d2f20:  92 10 00 11  mov  %l1, %o1
a00d2f24:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00d2f28:  94 10 20 00  clr  %o2
a00d2f2c:  96 10 20 00  clr  %o3
a00d2f30:  90 12 62 74  or  %o1, 0x274, %o0
a00d2f34:  82 02 c0 19  add  %o3, %i1, %g1
a00d2f38:  a0 02 c0 08  add  %o3, %o0, %l0
a00d2f3c:  94 02 a0 01  inc  %o2
a00d2f40:  de 08 60 06  ldub  [ %g1 + 6 ], %o7
a00d2f44:  96 0a a0 ff  and  %o2, 0xff, %o3
a00d2f48:  80 a2 e0 0c  cmp  %o3, 0xc
a00d2f4c:  08 bf ff fa  bleu  0xa00d2f34
a00d2f50:  de 2c 20 03  stb  %o7, [ %l0 + 3 ]
a00d2f54:  10 bf ff 31  b  0xa00d2c18
a00d2f58:  92 12 62 74  or  %o1, 0x274, %o1
a00d2f5c:  7f ff fb 76  call  0xa00d1d34
a00d2f60:  90 10 00 19  mov  %i1, %o0
a00d2f64:  10 80 01 ae  b  0xa00d361c
a00d2f68:  a0 10 00 08  mov  %o0, %l0
a00d2f6c:  da 0e 60 07  ldub  [ %i1 + 7 ], %o5
a00d2f70:  80 a3 60 01  cmp  %o5, 1
a00d2f74:  02 80 01 0d  be  0xa00d33a8
a00d2f78:  80 a3 60 00  cmp  %o5, 0
a00d2f7c:  12 bf ff 59  bne  0xa00d2ce0
a00d2f80:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00d2f84:  94 12 62 90  or  %o1, 0x290, %o2	! 0xa802d290
a00d2f88:  10 bf ff 56  b  0xa00d2ce0
a00d2f8c:  c0 2a a1 d5  clrb  [ %o2 + 0x1d5 ]
a00d2f90:  c2 0e 60 07  ldub  [ %i1 + 7 ], %g1
a00d2f94:  80 a0 60 01  cmp  %g1, 1
a00d2f98:  02 80 01 1c  be  0xa00d3408
a00d2f9c:  80 a0 60 00  cmp  %g1, 0
a00d2fa0:  12 80 01 9f  bne  0xa00d361c
a00d2fa4:  a0 10 3f e0  mov  -32, %l0
a00d2fa8:  92 10 20 01  mov  1, %o1
a00d2fac:  19 2a 00 ac  sethi  %hi(0xa802b000), %o4
a00d2fb0:  10 80 01 9b  b  0xa00d361c
a00d2fb4:  d2 2b 20 9d  stb  %o1, [ %o4 + 0x9d ]	! 0xa802b09d
a00d2fb8:  7f ff fd fd  call  0xa00d27ac
a00d2fbc:  90 10 00 19  mov  %i1, %o0
a00d2fc0:  10 80 01 97  b  0xa00d361c
a00d2fc4:  a0 10 00 08  mov  %o0, %l0
a00d2fc8:  c2 0e 60 07  ldub  [ %i1 + 7 ], %g1
a00d2fcc:  80 a0 60 1f  cmp  %g1, 0x1f
a00d2fd0:  18 80 00 a9  bgu  0xa00d3274
a00d2fd4:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a00d2fd8:  1b 00 01 bb  sethi  %hi(0x6ec00), %o5
a00d2fdc:  93 28 60 02  sll  %g1, 2, %o1
a00d2fe0:  96 13 61 30  or  %o5, 0x130, %o3
a00d2fe4:  d8 02 c0 09  ld  [ %o3 + %o1 ], %o4
a00d2fe8:  81 c3 00 00  jmp  %o4
a00d2fec:  01 00 00 00  nop
a00d2ff0:  25 2a 00 b4  sethi  %hi(0xa802d000), %l2
a00d2ff4:  92 14 a2 74  or  %l2, 0x274, %o1	! 0xa802d274
a00d2ff8:  10 bf ff 08  b  0xa00d2c18
a00d2ffc:  c0 2a 60 10  clrb  [ %o1 + 0x10 ]
a00d3000:  da 0e 60 07  ldub  [ %i1 + 7 ], %o5
a00d3004:  80 a3 60 01  cmp  %o5, 1
a00d3008:  12 bf ff 3f  bne  0xa00d2d04
a00d300c:  90 10 20 e4  mov  0xe4, %o0
a00d3010:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a00d3014:  e4 04 22 90  ld  [ %l0 + 0x290 ], %l2	! 0xa802d290
a00d3018:  23 00 00 10  sethi  %hi(0x4000), %l1
a00d301c:  96 14 80 11  or  %l2, %l1, %o3
a00d3020:  d6 24 22 90  st  %o3, [ %l0 + 0x290 ]
a00d3024:  a4 14 22 90  or  %l0, 0x290, %l2
a00d3028:  da 2c a1 d5  stb  %o5, [ %l2 + 0x1d5 ]
a00d302c:  1b 00 00 15  sethi  %hi(0x5400), %o5
a00d3030:  94 10 20 55  mov  0x55, %o2
a00d3034:  98 13 61 aa  or  %o5, 0x1aa, %o4
a00d3038:  d4 2c a1 d6  stb  %o2, [ %l2 + 0x1d6 ]
a00d303c:  d8 34 a1 f6  sth  %o4, [ %l2 + 0x1f6 ]
a00d3040:  90 10 20 30  mov  0x30, %o0
a00d3044:  92 10 00 12  mov  %l2, %o1
a00d3048:  94 10 20 00  clr  %o2
a00d304c:  40 01 df a1  call  0xa014aed0
a00d3050:  96 10 21 fc  mov  0x1fc, %o3
a00d3054:  d0 04 22 90  ld  [ %l0 + 0x290 ], %o0
a00d3058:  80 8a 00 11  btst  %o0, %l1
a00d305c:  22 80 00 07  be,a   0xa00d3078
a00d3060:  90 10 20 e4  mov  0xe4, %o0
a00d3064:  d2 0c a1 d5  ldub  [ %l2 + 0x1d5 ], %o1
a00d3068:  80 a2 60 01  cmp  %o1, 1
a00d306c:  02 80 00 f0  be  0xa00d342c
a00d3070:  03 00 00 15  sethi  %hi(0x5400), %g1
a00d3074:  90 10 20 e4  mov  0xe4, %o0
a00d3078:  10 80 01 69  b  0xa00d361c
a00d307c:  a0 10 00 08  mov  %o0, %l0
a00d3080:  da 0e 60 07  ldub  [ %i1 + 7 ], %o5
a00d3084:  80 a3 60 01  cmp  %o5, 1
a00d3088:  02 80 00 e4  be  0xa00d3418
a00d308c:  80 a3 60 00  cmp  %o5, 0
a00d3090:  12 bf ff b1  bne  0xa00d2f54
a00d3094:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00d3098:  a2 12 62 74  or  %o1, 0x274, %l1	! 0xa802d274
a00d309c:  c0 2c 60 14  clrb  [ %l1 + 0x14 ]
a00d30a0:  10 bf fe de  b  0xa00d2c18
a00d30a4:  92 12 62 74  or  %o1, 0x274, %o1
a00d30a8:  d4 0e 60 07  ldub  [ %i1 + 7 ], %o2
a00d30ac:  80 a2 a0 00  cmp  %o2, 0
a00d30b0:  12 80 00 8a  bne  0xa00d32d8
a00d30b4:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a00d30b8:  98 14 22 90  or  %l0, 0x290, %o4	! 0xa802d290
a00d30bc:  d6 03 20 a8  ld  [ %o4 + 0xa8 ], %o3
a00d30c0:  9a 0a ff bf  and  %o3, -65, %o5
a00d30c4:  40 01 4a 81  call  0xa0125ac8
a00d30c8:  da 23 20 a8  st  %o5, [ %o4 + 0xa8 ]
a00d30cc:  10 bf ff 06  b  0xa00d2ce4
a00d30d0:  92 14 22 90  or  %l0, 0x290, %o1
a00d30d4:  7f ff fd 48  call  0xa00d25f4
a00d30d8:  90 10 00 19  mov  %i1, %o0
a00d30dc:  10 80 01 50  b  0xa00d361c
a00d30e0:  a0 10 00 08  mov  %o0, %l0
a00d30e4:  7f ff fd 16  call  0xa00d253c
a00d30e8:  90 10 00 19  mov  %i1, %o0
a00d30ec:  10 80 01 4c  b  0xa00d361c
a00d30f0:  a0 10 00 08  mov  %o0, %l0
a00d30f4:  15 2a 00 ac  sethi  %hi(0xa802b000), %o2
a00d30f8:  d2 2a a0 9f  stb  %o1, [ %o2 + 0x9f ]	! 0xa802b09f
a00d30fc:  e0 0e 60 07  ldub  [ %i1 + 7 ], %l0
a00d3100:  11 2a 00 ac  sethi  %hi(0xa802b000), %o0
a00d3104:  e0 2a 20 9e  stb  %l0, [ %o0 + 0x9e ]	! 0xa802b09e
a00d3108:  10 80 01 45  b  0xa00d361c
a00d310c:  a0 10 3f e0  mov  -32, %l0
a00d3110:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00d3114:  a0 12 62 90  or  %o1, 0x290, %l0	! 0xa802d290
a00d3118:  d0 04 21 ec  ld  [ %l0 + 0x1ec ], %o0
a00d311c:  95 32 20 07  srl  %o0, 7, %o2
a00d3120:  a4 0a a0 01  and  %o2, 1, %l2
a00d3124:  03 2a 00 97  sethi  %hi(0xa8025c00), %g1
a00d3128:  e4 28 60 56  stb  %l2, [ %g1 + 0x56 ]	! 0xa8025c56
a00d312c:  d8 0e 60 07  ldub  [ %i1 + 7 ], %o4
a00d3130:  80 a0 00 0c  cmp  %g0, %o4
a00d3134:  a2 40 20 00  addx  %g0, 0, %l1
a00d3138:  9f 2c 60 07  sll  %l1, 7, %o7
a00d313c:  96 0a 3f 7f  and  %o0, -129, %o3
a00d3140:  98 12 c0 0f  or  %o3, %o7, %o4
a00d3144:  9b 33 20 07  srl  %o4, 7, %o5
a00d3148:  82 0b 60 01  and  %o5, 1, %g1
a00d314c:  80 a4 80 01  cmp  %l2, %g1
a00d3150:  02 bf fe b6  be  0xa00d2c28
a00d3154:  d8 24 21 ec  st  %o4, [ %l0 + 0x1ec ]
a00d3158:  40 00 1f f5  call  0xa00db12c
a00d315c:  90 10 20 00  clr  %o0
a00d3160:  10 bf ff 1a  b  0xa00d2dc8
a00d3164:  1b 2a 00 ac  sethi  %hi(0xa802b000), %o5
a00d3168:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a00d316c:  a0 13 62 90  or  %o5, 0x290, %l0	! 0xa802d290
a00d3170:  d6 0c 20 11  ldub  [ %l0 + 0x11 ], %o3
a00d3174:  82 0b 20 ff  and  %o4, 0xff, %g1
a00d3178:  80 a2 c0 01  cmp  %o3, %g1
a00d317c:  22 bf ff 61  be,a   0xa00d2f00
a00d3180:  90 10 20 e0  mov  0xe0, %o0
a00d3184:  40 00 19 78  call  0xa00d9764
a00d3188:  d8 2c 20 11  stb  %o4, [ %l0 + 0x11 ]
a00d318c:  7f fe db 61  call  0xa0089f10
a00d3190:  01 00 00 00  nop
a00d3194:  92 10 00 10  mov  %l0, %o1
a00d3198:  90 10 20 30  mov  0x30, %o0
a00d319c:  94 10 20 00  clr  %o2
a00d31a0:  40 01 df 4c  call  0xa014aed0
a00d31a4:  96 10 21 fc  mov  0x1fc, %o3
a00d31a8:  10 bf ff 56  b  0xa00d2f00
a00d31ac:  90 10 20 e0  mov  0xe0, %o0
a00d31b0:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00d31b4:  da 0a 22 88  ldub  [ %o0 + 0x288 ], %o5	! 0xa802d288
a00d31b8:  10 bf fe ab  b  0xa00d2c64
a00d31bc:  da 2f bf d6  stb  %o5, [ %fp + -42 ]
a00d31c0:  10 80 01 17  b  0xa00d361c
a00d31c4:  a6 10 20 0d  mov  0xd, %l3
a00d31c8:  02 80 01 15  be  0xa00d361c
a00d31cc:  a0 10 20 1f  mov  0x1f, %l0
a00d31d0:  80 a0 60 69  cmp  %g1, 0x69
a00d31d4:  32 80 01 12  bne,a   0xa00d361c
a00d31d8:  a0 10 3f e3  mov  -29, %l0
a00d31dc:  10 80 01 10  b  0xa00d361c
a00d31e0:  a0 10 20 69  mov  0x69, %l0
a00d31e4:  02 80 01 0e  be  0xa00d361c
a00d31e8:  a0 10 3f d0  mov  -48, %l0
a00d31ec:  80 a0 60 d0  cmp  %g1, 0xd0
a00d31f0:  14 bf fe 6e  bg  0xa00d2ba8
a00d31f4:  80 a0 60 fe  cmp  %g1, 0xfe
a00d31f8:  80 a0 60 c3  cmp  %g1, 0xc3
a00d31fc:  32 80 01 08  bne,a   0xa00d361c
a00d3200:  a0 10 3f e3  mov  -29, %l0
a00d3204:  25 2a 00 b4  sethi  %hi(0xa802d000), %l2
a00d3208:  e0 14 a2 8c  lduh  [ %l2 + 0x28c ], %l0	! 0xa802d28c
a00d320c:  93 34 20 0f  srl  %l0, 0xf, %o1
a00d3210:  d2 2f bf d6  stb  %o1, [ %fp + -42 ]
a00d3214:  10 80 01 02  b  0xa00d361c
a00d3218:  a0 10 3f e0  mov  -32, %l0
a00d321c:  02 80 00 1f  be  0xa00d3298
a00d3220:  80 a0 60 0f  cmp  %g1, 0xf
a00d3224:  32 80 00 fe  bne,a   0xa00d361c
a00d3228:  a0 10 3f e3  mov  -29, %l0
a00d322c:  25 2a 00 b4  sethi  %hi(0xa802d000), %l2
a00d3230:  da 0c a2 9a  ldub  [ %l2 + 0x29a ], %o5	! 0xa802d29a
a00d3234:  10 bf fe 8c  b  0xa00d2c64
a00d3238:  da 2f bf d6  stb  %o5, [ %fp + -42 ]
a00d323c:  02 80 00 f8  be  0xa00d361c
a00d3240:  a0 10 20 6f  mov  0x6f, %l0
a00d3244:  80 a0 60 73  cmp  %g1, 0x73
a00d3248:  32 80 00 f5  bne,a   0xa00d361c
a00d324c:  a0 10 3f e3  mov  -29, %l0
a00d3250:  1f 2a 00 b8  sethi  %hi(0xa802e000), %o7
a00d3254:  da 0b e1 ab  ldub  [ %o7 + 0x1ab ], %o5	! 0xa802e1ab
a00d3258:  10 bf fe 83  b  0xa00d2c64
a00d325c:  da 2f bf d6  stb  %o5, [ %fp + -42 ]
a00d3260:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a00d3264:  9a 13 e2 90  or  %o7, 0x290, %o5	! 0xa802d290
a00d3268:  82 10 20 02  mov  2, %g1
a00d326c:  c2 2b 60 08  stb  %g1, [ %o5 + 8 ]
a00d3270:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a00d3274:  92 13 62 90  or  %o5, 0x290, %o1	! 0xa802d290
a00d3278:  94 10 20 00  clr  %o2
a00d327c:  96 10 21 fc  mov  0x1fc, %o3
a00d3280:  40 01 df 14  call  0xa014aed0
a00d3284:  90 10 20 30  mov  0x30, %o0
a00d3288:  30 bf fe a7  b,a   0xa00d2d24
a00d328c:  a0 10 20 6b  mov  0x6b, %l0
a00d3290:  10 80 00 e3  b  0xa00d361c
a00d3294:  a6 10 20 15  mov  0x15, %l3
a00d3298:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a00d329c:  da 0c 22 99  ldub  [ %l0 + 0x299 ], %o5	! 0xa802d299
a00d32a0:  10 bf fe 71  b  0xa00d2c64
a00d32a4:  da 2f bf d6  stb  %o5, [ %fp + -42 ]
a00d32a8:  02 80 00 44  be  0xa00d33b8
a00d32ac:  80 a0 60 05  cmp  %g1, 5
a00d32b0:  12 bf fe f2  bne  0xa00d2e78
a00d32b4:  90 10 20 e3  mov  0xe3, %o0
a00d32b8:  15 2a 00 b8  sethi  %hi(0xa802e000), %o2
a00d32bc:  9e 12 a1 f0  or  %o2, 0x1f0, %o7	! 0xa802e1f0
a00d32c0:  d6 0b e0 23  ldub  [ %o7 + 0x23 ], %o3
a00d32c4:  da 0b e0 21  ldub  [ %o7 + 0x21 ], %o5
a00d32c8:  10 bf fe fe  b  0xa00d2ec0
a00d32cc:  d8 0b e0 22  ldub  [ %o7 + 0x22 ], %o4
a00d32d0:  10 bf fe d9  b  0xa00d2e34
a00d32d4:  da 2b 20 09  stb  %o5, [ %o4 + 9 ]
a00d32d8:  92 14 22 90  or  %l0, 0x290, %o1
a00d32dc:  c2 02 60 a8  ld  [ %o1 + 0xa8 ], %g1
a00d32e0:  9e 10 60 40  or  %g1, 0x40, %o7
a00d32e4:  de 22 60 a8  st  %o7, [ %o1 + 0xa8 ]
a00d32e8:  40 01 49 f1  call  0xa0125aac
a00d32ec:  01 00 00 00  nop
a00d32f0:  10 bf fe 7d  b  0xa00d2ce4
a00d32f4:  92 14 22 90  or  %l0, 0x290, %o1
a00d32f8:  40 00 12 ba  call  0xa00d7de0
a00d32fc:  da 2b 20 0a  stb  %o5, [ %o4 + 0xa ]
a00d3300:  10 80 00 c7  b  0xa00d361c
a00d3304:  a0 10 3f e0  mov  -32, %l0
a00d3308:  02 80 00 06  be  0xa00d3320
a00d330c:  80 a0 60 04  cmp  %g1, 4
a00d3310:  12 bf fe da  bne  0xa00d2e78
a00d3314:  90 10 20 e3  mov  0xe3, %o0
a00d3318:  10 bf ff 94  b  0xa00d3168
a00d331c:  98 10 20 03  mov  3, %o4
a00d3320:  10 bf ff 92  b  0xa00d3168
a00d3324:  98 10 20 01  mov  1, %o4
a00d3328:  7f ff ed c7  call  0xa00cea44
a00d332c:  23 3f ff ee  sethi  %hi(0xffffb800), %l1
a00d3330:  9e 14 63 99  or  %l1, 0x399, %o7	! 0xffffbb99
a00d3334:  1b 2a 00 b5  sethi  %hi(0xa802d400), %o5
a00d3338:  10 bf fe 7b  b  0xa00d2d24
a00d333c:  de 33 60 86  sth  %o7, [ %o5 + 0x86 ]	! 0xa802d486
a00d3340:  7f ff ed b6  call  0xa00cea18
a00d3344:  01 00 00 00  nop
a00d3348:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00d334c:  03 00 00 15  sethi  %hi(0x5400), %g1
a00d3350:  92 12 e2 90  or  %o3, 0x290, %o1
a00d3354:  a0 10 61 aa  or  %g1, 0x1aa, %l0
a00d3358:  10 bf ff c8  b  0xa00d3278
a00d335c:  e0 32 61 f6  sth  %l0, [ %o1 + 0x1f6 ]
a00d3360:  02 80 00 76  be  0xa00d3538
a00d3364:  80 a0 60 05  cmp  %g1, 5
a00d3368:  32 bf fe c4  bne,a   0xa00d2e78
a00d336c:  90 10 20 e3  mov  0xe3, %o0
a00d3370:  a4 12 a1 f0  or  %o2, 0x1f0, %l2
a00d3374:  d6 2c a0 23  stb  %o3, [ %l2 + 0x23 ]
a00d3378:  da 2c a0 21  stb  %o5, [ %l2 + 0x21 ]
a00d337c:  10 bf fe de  b  0xa00d2ef4
a00d3380:  d8 2c a0 22  stb  %o4, [ %l2 + 0x22 ]
a00d3384:  d6 2a 20 14  stb  %o3, [ %o0 + 0x14 ]
a00d3388:  da 2a 20 12  stb  %o5, [ %o0 + 0x12 ]
a00d338c:  10 bf fe da  b  0xa00d2ef4
a00d3390:  d8 2a 20 13  stb  %o4, [ %o0 + 0x13 ]
a00d3394:  a0 12 a1 f0  or  %o2, 0x1f0, %l0
a00d3398:  d6 0c 20 14  ldub  [ %l0 + 0x14 ], %o3
a00d339c:  da 0c 20 12  ldub  [ %l0 + 0x12 ], %o5
a00d33a0:  10 bf fe c8  b  0xa00d2ec0
a00d33a4:  d8 0c 20 13  ldub  [ %l0 + 0x13 ], %o4
a00d33a8:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00d33ac:  90 12 62 90  or  %o1, 0x290, %o0	! 0xa802d290
a00d33b0:  10 bf fe 4c  b  0xa00d2ce0
a00d33b4:  da 2a 21 d5  stb  %o5, [ %o0 + 0x1d5 ]
a00d33b8:  15 2a 00 b8  sethi  %hi(0xa802e000), %o2
a00d33bc:  92 12 a1 f0  or  %o2, 0x1f0, %o1	! 0xa802e1f0
a00d33c0:  d6 0a 60 0b  ldub  [ %o1 + 0xb ], %o3
a00d33c4:  da 0a 60 09  ldub  [ %o1 + 9 ], %o5
a00d33c8:  10 bf fe be  b  0xa00d2ec0
a00d33cc:  d8 0a 60 0a  ldub  [ %o1 + 0xa ], %o4
a00d33d0:  40 01 c2 11  call  0xa0143c14
a00d33d4:  90 10 20 00  clr  %o0
a00d33d8:  80 8a 20 ff  btst  0xff, %o0
a00d33dc:  02 bf fe 41  be  0xa00d2ce0
a00d33e0:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00d33e4:  10 bf fe 3c  b  0xa00d2cd4
a00d33e8:  90 10 20 01  mov  1, %o0
a00d33ec:  40 01 c2 0a  call  0xa0143c14
a00d33f0:  90 10 20 00  clr  %o0
a00d33f4:  80 8a 20 ff  btst  0xff, %o0
a00d33f8:  12 bf fe 3a  bne  0xa00d2ce0
a00d33fc:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00d3400:  10 bf fe 35  b  0xa00d2cd4
a00d3404:  90 10 20 02  mov  2, %o0
a00d3408:  25 2a 00 ac  sethi  %hi(0xa802b000), %l2
a00d340c:  c0 2c a0 9d  clrb  [ %l2 + 0x9d ]	! 0xa802b09d
a00d3410:  10 80 00 83  b  0xa00d361c
a00d3414:  a0 10 3f e0  mov  -32, %l0
a00d3418:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00d341c:  a0 12 62 74  or  %o1, 0x274, %l0	! 0xa802d274
a00d3420:  da 2c 20 14  stb  %o5, [ %l0 + 0x14 ]
a00d3424:  10 bf fd fd  b  0xa00d2c18
a00d3428:  92 12 62 74  or  %o1, 0x274, %o1
a00d342c:  e2 14 a1 f6  lduh  [ %l2 + 0x1f6 ], %l1
a00d3430:  9e 10 61 aa  or  %g1, 0x1aa, %o7
a00d3434:  80 a4 40 0f  cmp  %l1, %o7
a00d3438:  02 bf fe 33  be  0xa00d2d04
a00d343c:  90 10 20 e0  mov  0xe0, %o0
a00d3440:  10 bf ff 0e  b  0xa00d3078
a00d3444:  90 10 20 e4  mov  0xe4, %o0
a00d3448:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a00d344c:  9a 14 22 90  or  %l0, 0x290, %o5	! 0xa802d290
a00d3450:  10 bf ff 87  b  0xa00d326c
a00d3454:  82 10 20 03  mov  3, %g1
a00d3458:  25 2a 00 b4  sethi  %hi(0xa802d000), %l2
a00d345c:  9a 14 a2 90  or  %l2, 0x290, %o5	! 0xa802d290
a00d3460:  10 bf ff 83  b  0xa00d326c
a00d3464:  82 10 20 16  mov  0x16, %g1
a00d3468:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00d346c:  9a 12 a2 90  or  %o2, 0x290, %o5	! 0xa802d290
a00d3470:  10 bf ff 7f  b  0xa00d326c
a00d3474:  82 10 20 19  mov  0x19, %g1
a00d3478:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00d347c:  9a 12 22 90  or  %o0, 0x290, %o5	! 0xa802d290
a00d3480:  10 bf ff 7b  b  0xa00d326c
a00d3484:  82 10 20 04  mov  4, %g1
a00d3488:  23 2a 00 b4  sethi  %hi(0xa802d000), %l1
a00d348c:  9a 14 62 90  or  %l1, 0x290, %o5	! 0xa802d290
a00d3490:  10 bf ff 77  b  0xa00d326c
a00d3494:  82 10 20 05  mov  5, %g1
a00d3498:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00d349c:  9a 12 22 90  or  %o0, 0x290, %o5	! 0xa802d290
a00d34a0:  10 bf ff 73  b  0xa00d326c
a00d34a4:  82 10 20 0a  mov  0xa, %g1
a00d34a8:  23 2a 00 b4  sethi  %hi(0xa802d000), %l1
a00d34ac:  9a 14 62 90  or  %l1, 0x290, %o5	! 0xa802d290
a00d34b0:  10 bf ff 6f  b  0xa00d326c
a00d34b4:  82 10 20 0d  mov  0xd, %g1
a00d34b8:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a00d34bc:  9a 13 e2 90  or  %o7, 0x290, %o5	! 0xa802d290
a00d34c0:  10 bf ff 6b  b  0xa00d326c
a00d34c4:  82 10 20 06  mov  6, %g1
a00d34c8:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a00d34cc:  9a 14 22 90  or  %l0, 0x290, %o5	! 0xa802d290
a00d34d0:  10 bf ff 67  b  0xa00d326c
a00d34d4:  82 10 20 07  mov  7, %g1
a00d34d8:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a00d34dc:  82 13 62 90  or  %o5, 0x290, %g1	! 0xa802d290
a00d34e0:  10 bf ff 65  b  0xa00d3274
a00d34e4:  c0 28 60 08  clrb  [ %g1 + 8 ]
a00d34e8:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00d34ec:  9a 12 e2 90  or  %o3, 0x290, %o5	! 0xa802d290
a00d34f0:  10 bf ff 5f  b  0xa00d326c
a00d34f4:  82 10 20 08  mov  8, %g1
a00d34f8:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00d34fc:  9a 12 62 90  or  %o1, 0x290, %o5	! 0xa802d290
a00d3500:  10 bf ff 5b  b  0xa00d326c
a00d3504:  82 10 20 18  mov  0x18, %g1
a00d3508:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00d350c:  9a 13 22 90  or  %o4, 0x290, %o5	! 0xa802d290
a00d3510:  10 bf ff 57  b  0xa00d326c
a00d3514:  82 10 20 09  mov  9, %g1
a00d3518:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00d351c:  9a 12 62 90  or  %o1, 0x290, %o5	! 0xa802d290
a00d3520:  10 bf ff 53  b  0xa00d326c
a00d3524:  82 10 20 1c  mov  0x1c, %g1
a00d3528:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00d352c:  9a 13 22 90  or  %o4, 0x290, %o5	! 0xa802d290
a00d3530:  10 bf ff 4f  b  0xa00d326c
a00d3534:  82 10 20 1b  mov  0x1b, %g1
a00d3538:  a2 12 a1 f0  or  %o2, 0x1f0, %l1
a00d353c:  d6 2c 60 0b  stb  %o3, [ %l1 + 0xb ]
a00d3540:  da 2c 60 09  stb  %o5, [ %l1 + 9 ]
a00d3544:  10 bf fe 6c  b  0xa00d2ef4
a00d3548:  d8 2c 60 0a  stb  %o4, [ %l1 + 0xa ]
a00d354c:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00d3550:  9a 10 62 90  or  %g1, 0x290, %o5	! 0xa802d290
a00d3554:  10 bf ff 46  b  0xa00d326c
a00d3558:  82 10 20 01  mov  1, %g1
a00d355c:  25 2a 00 b4  sethi  %hi(0xa802d000), %l2
a00d3560:  9a 14 a2 90  or  %l2, 0x290, %o5	! 0xa802d290
a00d3564:  10 bf ff 42  b  0xa00d326c
a00d3568:  82 10 20 1a  mov  0x1a, %g1
a00d356c:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00d3570:  9a 12 a2 90  or  %o2, 0x290, %o5	! 0xa802d290
a00d3574:  10 bf ff 3e  b  0xa00d326c
a00d3578:  82 10 20 17  mov  0x17, %g1
a00d357c:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00d3580:  9a 12 22 90  or  %o0, 0x290, %o5	! 0xa802d290
a00d3584:  10 bf ff 3a  b  0xa00d326c
a00d3588:  82 10 20 15  mov  0x15, %g1
a00d358c:  23 2a 00 b4  sethi  %hi(0xa802d000), %l1
a00d3590:  9a 14 62 90  or  %l1, 0x290, %o5	! 0xa802d290
a00d3594:  10 bf ff 36  b  0xa00d326c
a00d3598:  82 10 20 14  mov  0x14, %g1
a00d359c:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a00d35a0:  9a 13 e2 90  or  %o7, 0x290, %o5	! 0xa802d290
a00d35a4:  10 bf ff 32  b  0xa00d326c
a00d35a8:  82 10 20 13  mov  0x13, %g1
a00d35ac:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a00d35b0:  9a 14 22 90  or  %l0, 0x290, %o5	! 0xa802d290
a00d35b4:  10 bf ff 2e  b  0xa00d326c
a00d35b8:  82 10 20 12  mov  0x12, %g1
a00d35bc:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00d35c0:  9a 10 62 90  or  %g1, 0x290, %o5	! 0xa802d290
a00d35c4:  10 bf ff 2a  b  0xa00d326c
a00d35c8:  82 10 20 11  mov  0x11, %g1
a00d35cc:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00d35d0:  9a 12 e2 90  or  %o3, 0x290, %o5	! 0xa802d290
a00d35d4:  10 bf ff 26  b  0xa00d326c
a00d35d8:  82 10 20 10  mov  0x10, %g1
a00d35dc:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00d35e0:  9a 12 62 90  or  %o1, 0x290, %o5	! 0xa802d290
a00d35e4:  10 bf ff 22  b  0xa00d326c
a00d35e8:  82 10 20 0f  mov  0xf, %g1
a00d35ec:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00d35f0:  9a 13 22 90  or  %o4, 0x290, %o5	! 0xa802d290
a00d35f4:  10 bf ff 1e  b  0xa00d326c
a00d35f8:  82 10 20 0e  mov  0xe, %g1
a00d35fc:  25 2a 00 b4  sethi  %hi(0xa802d000), %l2
a00d3600:  9a 14 a2 90  or  %l2, 0x290, %o5	! 0xa802d290
a00d3604:  10 bf ff 1a  b  0xa00d326c
a00d3608:  82 10 20 0c  mov  0xc, %g1
a00d360c:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00d3610:  9a 12 a2 90  or  %o2, 0x290, %o5	! 0xa802d290
a00d3614:  10 bf ff 16  b  0xa00d326c
a00d3618:  82 10 20 0b  mov  0xb, %g1
a00d361c:  94 0c 20 ff  and  %l0, 0xff, %o2
a00d3620:  92 10 00 14  mov  %l4, %o1
a00d3624:  7f ff f6 ff  call  0xa00d1220
a00d3628:  90 10 00 19  mov  %i1, %o0
a00d362c:  7f fe da 4d  call  0xa0089f60
a00d3630:  90 10 20 50  mov  0x50, %o0
a00d3634:  90 0e 20 ff  and  %i0, 0xff, %o0
a00d3638:  92 0c e0 1f  and  %l3, 0x1f, %o1
a00d363c:  40 01 d4 1b  call  0xa01486a8
a00d3640:  94 10 00 14  mov  %l4, %o2
a00d3644:  01 00 00 00  nop
a00d3648:  81 c7 e0 08  ret
a00d364c:  81 e8 00 00  restore
