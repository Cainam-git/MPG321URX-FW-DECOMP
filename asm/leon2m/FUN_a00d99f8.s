# leon2m FUN_a00d99f8 0xa00d99f8-0xa00d9fdc (580 bytes)
a00d99f8:  9d e3 bf 98  save  %sp, -104, %sp
a00d99fc:  23 2a 00 b4  sethi  %hi(0xa802d000), %l1
a00d9a00:  98 14 62 90  or  %l1, 0x290, %o4	! 0xa802d290
a00d9a04:  c2 0b 20 1f  ldub  [ %o4 + 0x1f ], %g1
a00d9a08:  80 a0 60 02  cmp  %g1, 2
a00d9a0c:  02 80 00 19  be  0xa00d9a70
a00d9a10:  a4 10 20 00  clr  %l2
a00d9a14:  80 a0 60 01  cmp  %g1, 1
a00d9a18:  22 80 00 20  be,a   0xa00d9a98
a00d9a1c:  a4 10 20 02  mov  2, %l2
a00d9a20:  c2 0b 21 a4  ldub  [ %o4 + 0x1a4 ], %g1
a00d9a24:  80 a0 60 03  cmp  %g1, 3
a00d9a28:  22 80 00 1c  be,a   0xa00d9a98
a00d9a2c:  a4 10 20 06  mov  6, %l2
a00d9a30:  d0 03 20 a8  ld  [ %o4 + 0xa8 ], %o0
a00d9a34:  80 8a 20 80  btst  0x80, %o0
a00d9a38:  12 80 00 46  bne  0xa00d9b50
a00d9a3c:  da 03 20 ac  ld  [ %o4 + 0xac ], %o5
a00d9a40:  13 00 03 00  sethi  %hi(0xc0000), %o1
a00d9a44:  80 8b 40 09  btst  %o5, %o1
a00d9a48:  22 80 00 5e  be,a   0xa00d9bc0
a00d9a4c:  d0 03 21 f4  ld  [ %o4 + 0x1f4 ], %o0
a00d9a50:  de 03 21 f4  ld  [ %o4 + 0x1f4 ], %o7
a00d9a54:  21 20 00 00  sethi  %hi(0x80000000), %l0
a00d9a58:  98 0b c0 10  and  %o7, %l0, %o4
a00d9a5c:  80 a0 00 0c  cmp  %g0, %o4
a00d9a60:  96 40 3f ff  addx  %g0, -1, %o3
a00d9a64:  94 0a e0 05  and  %o3, 5, %o2
a00d9a68:  10 80 00 0c  b  0xa00d9a98
a00d9a6c:  a4 02 a0 08  add  %o2, 8, %l2
a00d9a70:  c2 0b 20 2f  ldub  [ %o4 + 0x2f ], %g1
a00d9a74:  80 a0 60 00  cmp  %g1, 0
a00d9a78:  22 80 00 08  be,a   0xa00d9a98
a00d9a7c:  a4 10 20 03  mov  3, %l2
a00d9a80:  80 a0 60 01  cmp  %g1, 1
a00d9a84:  02 80 00 04  be  0xa00d9a94
a00d9a88:  80 a0 60 02  cmp  %g1, 2
a00d9a8c:  32 80 00 04  bne,a   0xa00d9a9c
a00d9a90:  13 00 06 61  sethi  %hi(0x198400), %o1
a00d9a94:  a4 10 20 04  mov  4, %l2
a00d9a98:  13 00 06 61  sethi  %hi(0x198400), %o1
a00d9a9c:  90 12 63 b8  or  %o1, 0x3b8, %o0	! 0x1987b8
a00d9aa0:  27 2a 00 97  sethi  %hi(0xa8025c00), %l3
a00d9aa4:  a0 0c a0 ff  and  %l2, 0xff, %l0
a00d9aa8:  d2 0c e0 64  ldub  [ %l3 + 0x64 ], %o1
a00d9aac:  40 00 15 b1  call  0xa00df170
a00d9ab0:  94 10 00 10  mov  %l0, %o2
a00d9ab4:  90 14 62 90  or  %l1, 0x290, %o0
a00d9ab8:  e2 0a 21 a4  ldub  [ %o0 + 0x1a4 ], %l1
a00d9abc:  90 10 20 fe  mov  0xfe, %o0
a00d9ac0:  80 a4 60 03  cmp  %l1, 3
a00d9ac4:  02 80 00 04  be  0xa00d9ad4
a00d9ac8:  92 10 20 01  mov  1, %o1
a00d9acc:  90 10 20 fe  mov  0xfe, %o0
a00d9ad0:  92 10 20 00  clr  %o1
a00d9ad4:  40 01 c7 ab  call  0xa014b980
a00d9ad8:  01 00 00 00  nop
a00d9adc:  d8 0c e0 64  ldub  [ %l3 + 0x64 ], %o4
a00d9ae0:  96 1b 00 10  xor  %o4, %l0, %o3
a00d9ae4:  80 a0 00 0b  cmp  %g0, %o3
a00d9ae8:  94 40 20 00  addx  %g0, 0, %o2
a00d9aec:  9a 0e 60 ff  and  %i1, 0xff, %o5
a00d9af0:  80 a0 00 0d  cmp  %g0, %o5
a00d9af4:  b2 40 20 00  addx  %g0, 0, %i1
a00d9af8:  80 92 80 19  orcc  %o2, %i1, %g0
a00d9afc:  22 80 01 36  be,a   0xa00d9fd4
a00d9b00:  e4 2c e0 64  stb  %l2, [ %l3 + 0x64 ]
a00d9b04:  80 a4 20 0d  cmp  %l0, 0xd
a00d9b08:  38 80 00 09  bgu,a   0xa00d9b2c
a00d9b0c:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00d9b10:  83 2c 20 02  sll  %l0, 2, %g1
a00d9b14:  23 00 01 ce  sethi  %hi(0x73800), %l1
a00d9b18:  a0 14 63 44  or  %l1, 0x344, %l0	! 0x73b44
a00d9b1c:  de 04 00 01  ld  [ %l0 + %g1 ], %o7
a00d9b20:  81 c3 c0 00  jmp  %o7
a00d9b24:  01 00 00 00  nop
a00d9b28:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00d9b2c:  80 a6 20 02  cmp  %i0, 2
a00d9b30:  02 80 00 e9  be  0xa00d9ed4
a00d9b34:  80 a6 20 00  cmp  %i0, 0
a00d9b38:  02 80 00 12  be  0xa00d9b80
a00d9b3c:  80 a6 20 01  cmp  %i0, 1
a00d9b40:  32 80 01 25  bne,a   0xa00d9fd4
a00d9b44:  e4 2c e0 64  stb  %l2, [ %l3 + 0x64 ]
a00d9b48:  10 80 00 25  b  0xa00d9bdc
a00d9b4c:  90 10 20 0c  mov  0xc, %o0
a00d9b50:  15 00 03 00  sethi  %hi(0xc0000), %o2
a00d9b54:  80 8b 40 0a  btst  %o5, %o2
a00d9b58:  22 80 00 15  be,a   0xa00d9bac
a00d9b5c:  c2 03 21 f4  ld  [ %o4 + 0x1f4 ], %g1
a00d9b60:  e0 03 21 f4  ld  [ %o4 + 0x1f4 ], %l0
a00d9b64:  27 20 00 00  sethi  %hi(0x80000000), %l3
a00d9b68:  9e 0c 00 13  and  %l0, %l3, %o7
a00d9b6c:  80 a0 00 0f  cmp  %g0, %o7
a00d9b70:  98 40 3f ff  addx  %g0, -1, %o4
a00d9b74:  96 0b 20 02  and  %o4, 2, %o3
a00d9b78:  10 bf ff c8  b  0xa00d9a98
a00d9b7c:  a4 02 e0 09  add  %o3, 9, %l2
a00d9b80:  90 10 20 05  mov  5, %o0
a00d9b84:  7f ff d3 75  call  0xa00ce958
a00d9b88:  92 10 20 00  clr  %o1
a00d9b8c:  90 10 20 06  mov  6, %o0
a00d9b90:  7f ff d3 72  call  0xa00ce958
a00d9b94:  92 10 20 01  mov  1, %o1
a00d9b98:  90 10 20 01  mov  1, %o0
a00d9b9c:  40 01 a7 8f  call  0xa01439d8
a00d9ba0:  92 10 20 01  mov  1, %o1
a00d9ba4:  10 80 01 0c  b  0xa00d9fd4
a00d9ba8:  e4 2c e0 64  stb  %l2, [ %l3 + 0x64 ]
a00d9bac:  80 a0 60 00  cmp  %g1, 0
a00d9bb0:  36 bf ff ba  bge,a   0xa00d9a98
a00d9bb4:  a4 10 20 0a  mov  0xa, %l2
a00d9bb8:  10 bf ff b9  b  0xa00d9a9c
a00d9bbc:  13 00 06 61  sethi  %hi(0x198400), %o1
a00d9bc0:  13 20 00 00  sethi  %hi(0x80000000), %o1
a00d9bc4:  82 0a 00 09  and  %o0, %o1, %g1
a00d9bc8:  80 a0 00 01  cmp  %g0, %g1
a00d9bcc:  a4 40 3f ff  addx  %g0, -1, %l2
a00d9bd0:  a6 0c a0 05  and  %l2, 5, %l3
a00d9bd4:  10 bf ff b1  b  0xa00d9a98
a00d9bd8:  a4 04 e0 07  add  %l3, 7, %l2
a00d9bdc:  7f ff d3 5f  call  0xa00ce958
a00d9be0:  92 10 20 02  mov  2, %o1
a00d9be4:  90 10 20 0d  mov  0xd, %o0
a00d9be8:  7f ff d3 5c  call  0xa00ce958
a00d9bec:  92 10 20 03  mov  3, %o1
a00d9bf0:  10 bf ff eb  b  0xa00d9b9c
a00d9bf4:  90 10 20 02  mov  2, %o0
a00d9bf8:  80 8e 20 ff  btst  0xff, %i0
a00d9bfc:  12 80 00 c2  bne  0xa00d9f04
a00d9c00:  90 10 20 05  mov  5, %o0
a00d9c04:  7f ff d3 55  call  0xa00ce958
a00d9c08:  92 10 20 2c  mov  0x2c, %o1
a00d9c0c:  90 10 20 06  mov  6, %o0
a00d9c10:  7f ff d3 52  call  0xa00ce958
a00d9c14:  92 10 20 2d  mov  0x2d, %o1
a00d9c18:  90 10 20 01  mov  1, %o0
a00d9c1c:  40 01 a7 6f  call  0xa01439d8
a00d9c20:  92 10 20 01  mov  1, %o1
a00d9c24:  15 00 06 61  sethi  %hi(0x198400), %o2
a00d9c28:  40 00 15 52  call  0xa00df170
a00d9c2c:  90 12 a3 d8  or  %o2, 0x3d8, %o0	! 0x1987d8
a00d9c30:  10 80 00 e9  b  0xa00d9fd4
a00d9c34:  e4 2c e0 64  stb  %l2, [ %l3 + 0x64 ]
a00d9c38:  80 8e 20 ff  btst  0xff, %i0
a00d9c3c:  12 80 00 cc  bne  0xa00d9f6c
a00d9c40:  90 10 20 05  mov  5, %o0
a00d9c44:  7f ff d3 45  call  0xa00ce958
a00d9c48:  92 10 20 2e  mov  0x2e, %o1
a00d9c4c:  90 10 20 06  mov  6, %o0
a00d9c50:  7f ff d3 42  call  0xa00ce958
a00d9c54:  92 10 20 2f  mov  0x2f, %o1
a00d9c58:  90 10 20 01  mov  1, %o0
a00d9c5c:  40 01 a7 5f  call  0xa01439d8
a00d9c60:  92 10 20 01  mov  1, %o1
a00d9c64:  1b 00 06 61  sethi  %hi(0x198400), %o5
a00d9c68:  40 00 15 42  call  0xa00df170
a00d9c6c:  90 13 63 f8  or  %o5, 0x3f8, %o0	! 0x1987f8
a00d9c70:  10 80 00 d9  b  0xa00d9fd4
a00d9c74:  e4 2c e0 64  stb  %l2, [ %l3 + 0x64 ]
a00d9c78:  80 8e 20 ff  btst  0xff, %i0
a00d9c7c:  12 80 00 c9  bne  0xa00d9fa0
a00d9c80:  90 10 20 05  mov  5, %o0
a00d9c84:  7f ff d3 35  call  0xa00ce958
a00d9c88:  92 10 20 30  mov  0x30, %o1
a00d9c8c:  90 10 20 06  mov  6, %o0
a00d9c90:  7f ff d3 32  call  0xa00ce958
a00d9c94:  92 10 20 31  mov  0x31, %o1
a00d9c98:  90 10 20 01  mov  1, %o0
a00d9c9c:  40 01 a7 4f  call  0xa01439d8
a00d9ca0:  92 10 20 01  mov  1, %o1
a00d9ca4:  17 00 06 62  sethi  %hi(0x198800), %o3
a00d9ca8:  40 00 15 32  call  0xa00df170
a00d9cac:  90 12 e0 20  or  %o3, 0x20, %o0	! 0x198820
a00d9cb0:  10 80 00 c9  b  0xa00d9fd4
a00d9cb4:  e4 2c e0 64  stb  %l2, [ %l3 + 0x64 ]
a00d9cb8:  80 8e 20 ff  btst  0xff, %i0
a00d9cbc:  12 80 00 9f  bne  0xa00d9f38
a00d9cc0:  90 10 20 05  mov  5, %o0
a00d9cc4:  7f ff d3 25  call  0xa00ce958
a00d9cc8:  92 10 20 32  mov  0x32, %o1
a00d9ccc:  90 10 20 06  mov  6, %o0
a00d9cd0:  7f ff d3 22  call  0xa00ce958
a00d9cd4:  92 10 20 33  mov  0x33, %o1
a00d9cd8:  90 10 20 01  mov  1, %o0
a00d9cdc:  40 01 a7 3f  call  0xa01439d8
a00d9ce0:  92 10 20 01  mov  1, %o1
a00d9ce4:  19 00 06 62  sethi  %hi(0x198800), %o4
a00d9ce8:  40 00 15 22  call  0xa00df170
a00d9cec:  90 13 20 40  or  %o4, 0x40, %o0	! 0x198840
a00d9cf0:  10 80 00 b9  b  0xa00d9fd4
a00d9cf4:  e4 2c e0 64  stb  %l2, [ %l3 + 0x64 ]
a00d9cf8:  90 10 20 0c  mov  0xc, %o0
a00d9cfc:  7f ff d3 17  call  0xa00ce958
a00d9d00:  92 10 20 02  mov  2, %o1
a00d9d04:  90 10 20 0d  mov  0xd, %o0
a00d9d08:  7f ff d3 14  call  0xa00ce958
a00d9d0c:  92 10 20 03  mov  3, %o1
a00d9d10:  90 10 20 05  mov  5, %o0
a00d9d14:  7f ff d3 11  call  0xa00ce958
a00d9d18:  92 10 20 14  mov  0x14, %o1
a00d9d1c:  90 10 20 06  mov  6, %o0
a00d9d20:  7f ff d3 0e  call  0xa00ce958
a00d9d24:  92 10 20 15  mov  0x15, %o1
a00d9d28:  90 10 20 00  clr  %o0
a00d9d2c:  40 01 a7 2b  call  0xa01439d8
a00d9d30:  92 10 20 01  mov  1, %o1
a00d9d34:  11 00 06 62  sethi  %hi(0x198800), %o0
a00d9d38:  40 00 15 0e  call  0xa00df170
a00d9d3c:  90 12 20 68  or  %o0, 0x68, %o0	! 0x198868
a00d9d40:  10 80 00 a5  b  0xa00d9fd4
a00d9d44:  e4 2c e0 64  stb  %l2, [ %l3 + 0x64 ]
a00d9d48:  90 10 20 05  mov  5, %o0
a00d9d4c:  7f ff d3 03  call  0xa00ce958
a00d9d50:  92 10 20 04  mov  4, %o1
a00d9d54:  90 10 20 06  mov  6, %o0
a00d9d58:  7f ff d3 00  call  0xa00ce958
a00d9d5c:  92 10 20 05  mov  5, %o1
a00d9d60:  90 10 20 0c  mov  0xc, %o0
a00d9d64:  7f ff d2 fd  call  0xa00ce958
a00d9d68:  92 10 20 06  mov  6, %o1
a00d9d6c:  90 10 20 0d  mov  0xd, %o0
a00d9d70:  92 10 20 07  mov  7, %o1
a00d9d74:  7f ff d2 f9  call  0xa00ce958
a00d9d78:  01 00 00 00  nop
a00d9d7c:  10 bf ff 88  b  0xa00d9b9c
a00d9d80:  90 10 20 00  clr  %o0	! 0x0
a00d9d84:  90 10 20 05  mov  5, %o0
a00d9d88:  7f ff d2 f4  call  0xa00ce958
a00d9d8c:  92 10 20 08  mov  8, %o1
a00d9d90:  90 10 20 06  mov  6, %o0
a00d9d94:  7f ff d2 f1  call  0xa00ce958
a00d9d98:  92 10 20 09  mov  9, %o1
a00d9d9c:  90 10 20 0c  mov  0xc, %o0
a00d9da0:  7f ff d2 ee  call  0xa00ce958
a00d9da4:  92 10 20 0a  mov  0xa, %o1
a00d9da8:  90 10 20 0d  mov  0xd, %o0
a00d9dac:  10 bf ff f2  b  0xa00d9d74
a00d9db0:  92 10 20 0b  mov  0xb, %o1
a00d9db4:  90 10 20 05  mov  5, %o0
a00d9db8:  7f ff d2 e8  call  0xa00ce958
a00d9dbc:  92 10 20 0c  mov  0xc, %o1
a00d9dc0:  90 10 20 06  mov  6, %o0
a00d9dc4:  7f ff d2 e5  call  0xa00ce958
a00d9dc8:  92 10 20 0d  mov  0xd, %o1
a00d9dcc:  90 10 20 0c  mov  0xc, %o0
a00d9dd0:  7f ff d2 e2  call  0xa00ce958
a00d9dd4:  92 10 20 0e  mov  0xe, %o1
a00d9dd8:  90 10 20 0d  mov  0xd, %o0
a00d9ddc:  10 bf ff e6  b  0xa00d9d74
a00d9de0:  92 10 20 0f  mov  0xf, %o1
a00d9de4:  90 10 20 05  mov  5, %o0
a00d9de8:  7f ff d2 dc  call  0xa00ce958
a00d9dec:  92 10 20 18  mov  0x18, %o1
a00d9df0:  90 10 20 06  mov  6, %o0
a00d9df4:  7f ff d2 d9  call  0xa00ce958
a00d9df8:  92 10 20 19  mov  0x19, %o1
a00d9dfc:  90 10 20 0c  mov  0xc, %o0
a00d9e00:  7f ff d2 d6  call  0xa00ce958
a00d9e04:  92 10 20 1a  mov  0x1a, %o1
a00d9e08:  90 10 20 0d  mov  0xd, %o0
a00d9e0c:  7f ff d2 d3  call  0xa00ce958
a00d9e10:  92 10 20 1b  mov  0x1b, %o1
a00d9e14:  90 10 20 00  clr  %o0
a00d9e18:  40 01 a6 f0  call  0xa01439d8
a00d9e1c:  92 10 20 01  mov  1, %o1
a00d9e20:  31 00 06 62  sethi  %hi(0x198800), %i0
a00d9e24:  40 00 14 d3  call  0xa00df170
a00d9e28:  90 16 20 80  or  %i0, 0x80, %o0	! 0x198880
a00d9e2c:  10 80 00 6a  b  0xa00d9fd4
a00d9e30:  e4 2c e0 64  stb  %l2, [ %l3 + 0x64 ]
a00d9e34:  90 10 20 0c  mov  0xc, %o0
a00d9e38:  7f ff d2 c8  call  0xa00ce958
a00d9e3c:  92 10 20 12  mov  0x12, %o1
a00d9e40:  90 10 20 0d  mov  0xd, %o0
a00d9e44:  7f ff d2 c5  call  0xa00ce958
a00d9e48:  92 10 20 13  mov  0x13, %o1
a00d9e4c:  90 10 20 05  mov  5, %o0
a00d9e50:  7f ff d2 c2  call  0xa00ce958
a00d9e54:  92 10 20 16  mov  0x16, %o1
a00d9e58:  90 10 20 06  mov  6, %o0
a00d9e5c:  7f ff d2 bf  call  0xa00ce958
a00d9e60:  92 10 20 17  mov  0x17, %o1
a00d9e64:  90 10 20 00  clr  %o0
a00d9e68:  40 01 a6 dc  call  0xa01439d8
a00d9e6c:  92 10 20 01  mov  1, %o1
a00d9e70:  13 00 06 62  sethi  %hi(0x198800), %o1
a00d9e74:  40 00 14 bf  call  0xa00df170
a00d9e78:  90 12 60 98  or  %o1, 0x98, %o0	! 0x198898
a00d9e7c:  10 80 00 56  b  0xa00d9fd4
a00d9e80:  e4 2c e0 64  stb  %l2, [ %l3 + 0x64 ]
a00d9e84:  90 10 20 05  mov  5, %o0
a00d9e88:  7f ff d2 b4  call  0xa00ce958
a00d9e8c:  92 10 20 10  mov  0x10, %o1
a00d9e90:  90 10 20 06  mov  6, %o0
a00d9e94:  7f ff d2 b1  call  0xa00ce958
a00d9e98:  92 10 20 11  mov  0x11, %o1
a00d9e9c:  90 10 20 0c  mov  0xc, %o0
a00d9ea0:  7f ff d2 ae  call  0xa00ce958
a00d9ea4:  92 10 20 12  mov  0x12, %o1
a00d9ea8:  90 10 20 0d  mov  0xd, %o0
a00d9eac:  7f ff d2 ab  call  0xa00ce958
a00d9eb0:  92 10 20 13  mov  0x13, %o1
a00d9eb4:  90 10 20 00  clr  %o0
a00d9eb8:  40 01 a6 c8  call  0xa01439d8
a00d9ebc:  92 10 20 01  mov  1, %o1
a00d9ec0:  33 00 06 62  sethi  %hi(0x198800), %i1
a00d9ec4:  40 00 14 ab  call  0xa00df170
a00d9ec8:  90 16 60 b8  or  %i1, 0xb8, %o0	! 0x1988b8
a00d9ecc:  10 80 00 42  b  0xa00d9fd4
a00d9ed0:  e4 2c e0 64  stb  %l2, [ %l3 + 0x64 ]
a00d9ed4:  90 10 20 0c  mov  0xc, %o0
a00d9ed8:  7f ff d2 a0  call  0xa00ce958
a00d9edc:  92 10 20 02  mov  2, %o1
a00d9ee0:  90 10 20 0d  mov  0xd, %o0
a00d9ee4:  7f ff d2 9d  call  0xa00ce958
a00d9ee8:  92 10 20 03  mov  3, %o1
a00d9eec:  90 10 20 05  mov  5, %o0
a00d9ef0:  7f ff d2 9a  call  0xa00ce958
a00d9ef4:  92 10 20 00  clr  %o1
a00d9ef8:  90 10 20 06  mov  6, %o0
a00d9efc:  10 bf ff 9e  b  0xa00d9d74
a00d9f00:  92 10 20 01  mov  1, %o1
a00d9f04:  7f ff d2 95  call  0xa00ce958
a00d9f08:  92 10 20 2c  mov  0x2c, %o1
a00d9f0c:  90 10 20 06  mov  6, %o0
a00d9f10:  7f ff d2 92  call  0xa00ce958
a00d9f14:  92 10 20 2d  mov  0x2d, %o1
a00d9f18:  90 10 20 0c  mov  0xc, %o0
a00d9f1c:  7f ff d2 8f  call  0xa00ce958
a00d9f20:  92 10 20 34  mov  0x34, %o1
a00d9f24:  90 10 20 0d  mov  0xd, %o0
a00d9f28:  7f ff d2 8c  call  0xa00ce958
a00d9f2c:  92 10 20 35  mov  0x35, %o1
a00d9f30:  10 bf ff 3b  b  0xa00d9c1c
a00d9f34:  90 10 20 00  clr  %o0
a00d9f38:  7f ff d2 88  call  0xa00ce958
a00d9f3c:  92 10 20 32  mov  0x32, %o1
a00d9f40:  90 10 20 06  mov  6, %o0
a00d9f44:  7f ff d2 85  call  0xa00ce958
a00d9f48:  92 10 20 33  mov  0x33, %o1
a00d9f4c:  90 10 20 0c  mov  0xc, %o0
a00d9f50:  7f ff d2 82  call  0xa00ce958
a00d9f54:  92 10 20 36  mov  0x36, %o1
a00d9f58:  90 10 20 0d  mov  0xd, %o0
a00d9f5c:  7f ff d2 7f  call  0xa00ce958
a00d9f60:  92 10 20 37  mov  0x37, %o1
a00d9f64:  10 bf ff 5e  b  0xa00d9cdc
a00d9f68:  90 10 20 00  clr  %o0
a00d9f6c:  7f ff d2 7b  call  0xa00ce958
a00d9f70:  92 10 20 2e  mov  0x2e, %o1
a00d9f74:  90 10 20 06  mov  6, %o0
a00d9f78:  7f ff d2 78  call  0xa00ce958
a00d9f7c:  92 10 20 2f  mov  0x2f, %o1
a00d9f80:  90 10 20 0c  mov  0xc, %o0
a00d9f84:  7f ff d2 75  call  0xa00ce958
a00d9f88:  92 10 20 36  mov  0x36, %o1
a00d9f8c:  90 10 20 0d  mov  0xd, %o0
a00d9f90:  7f ff d2 72  call  0xa00ce958
a00d9f94:  92 10 20 37  mov  0x37, %o1
a00d9f98:  10 bf ff 31  b  0xa00d9c5c
a00d9f9c:  90 10 20 00  clr  %o0
a00d9fa0:  7f ff d2 6e  call  0xa00ce958
a00d9fa4:  92 10 20 30  mov  0x30, %o1
a00d9fa8:  90 10 20 06  mov  6, %o0
a00d9fac:  7f ff d2 6b  call  0xa00ce958
a00d9fb0:  92 10 20 31  mov  0x31, %o1
a00d9fb4:  90 10 20 0c  mov  0xc, %o0
a00d9fb8:  7f ff d2 68  call  0xa00ce958
a00d9fbc:  92 10 20 34  mov  0x34, %o1
a00d9fc0:  90 10 20 0d  mov  0xd, %o0
a00d9fc4:  7f ff d2 65  call  0xa00ce958
a00d9fc8:  92 10 20 35  mov  0x35, %o1
a00d9fcc:  10 bf ff 34  b  0xa00d9c9c
a00d9fd0:  90 10 20 00  clr  %o0
a00d9fd4:  81 c7 e0 08  ret
a00d9fd8:  81 e8 00 00  restore
