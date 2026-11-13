# leon2m FUN_a00c7a5c 0xa00c7a5c-0xa00c7e3c (992 bytes)
a00c7a5c:  9d e3 bf 98  save  %sp, -104, %sp
a00c7a60:  a2 0e 20 ff  and  %i0, 0xff, %l1
a00c7a64:  80 a4 60 02  cmp  %l1, 2
a00c7a68:  02 80 00 7a  be  0xa00c7c50
a00c7a6c:  80 a4 60 03  cmp  %l1, 3
a00c7a70:  02 80 00 b7  be  0xa00c7d4c
a00c7a74:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00c7a78:  c2 0a 60 d9  ldub  [ %o1 + 0xd9 ], %g1	! 0xa802d0d9
a00c7a7c:  94 08 60 ff  and  %g1, 0xff, %o2
a00c7a80:  98 02 bf d0  add  %o2, -48, %o4
a00c7a84:  9a 0b 20 ff  and  %o4, 0xff, %o5
a00c7a88:  80 a3 60 02  cmp  %o5, 2
a00c7a8c:  18 80 00 ea  bgu  0xa00c7e34
a00c7a90:  b0 10 20 ff  mov  0xff, %i0
a00c7a94:  31 2a 00 b4  sethi  %hi(0xa802d000), %i0
a00c7a98:  a0 16 22 90  or  %i0, 0x290, %l0	! 0xa802d290
a00c7a9c:  d6 0c 20 4a  ldub  [ %l0 + 0x4a ], %o3
a00c7aa0:  80 a2 e0 01  cmp  %o3, 1
a00c7aa4:  02 80 00 dc  be  0xa00c7e14
a00c7aa8:  d8 2c 20 1f  stb  %o4, [ %l0 + 0x1f ]
a00c7aac:  40 00 45 d4  call  0xa00d91fc
a00c7ab0:  90 10 20 00  clr  %o0
a00c7ab4:  d8 04 20 a8  ld  [ %l0 + 0xa8 ], %o4
a00c7ab8:  80 8b 20 80  btst  0x80, %o4
a00c7abc:  32 80 00 58  bne,a   0xa00c7c1c
a00c7ac0:  de 0c 20 1f  ldub  [ %l0 + 0x1f ], %o7
a00c7ac4:  98 16 22 90  or  %i0, 0x290, %o4
a00c7ac8:  da 03 20 ac  ld  [ %o4 + 0xac ], %o5
a00c7acc:  21 00 04 00  sethi  %hi(0x100000), %l0
a00c7ad0:  80 8b 40 10  btst  %o5, %l0
a00c7ad4:  22 80 00 07  be,a   0xa00c7af0
a00c7ad8:  9a 16 22 90  or  %i0, 0x290, %o5
a00c7adc:  d2 0b 20 1f  ldub  [ %o4 + 0x1f ], %o1
a00c7ae0:  80 a2 60 00  cmp  %o1, 0
a00c7ae4:  12 80 00 b8  bne  0xa00c7dc4
a00c7ae8:  17 00 04 00  sethi  %hi(0x100000), %o3
a00c7aec:  9a 16 22 90  or  %i0, 0x290, %o5
a00c7af0:  d8 03 60 b0  ld  [ %o5 + 0xb0 ], %o4
a00c7af4:  80 a3 20 00  cmp  %o4, 0
a00c7af8:  22 80 00 07  be,a   0xa00c7b14
a00c7afc:  9a 16 22 90  or  %i0, 0x290, %o5
a00c7b00:  de 0b 60 1f  ldub  [ %o5 + 0x1f ], %o7
a00c7b04:  80 a3 e0 00  cmp  %o7, 0
a00c7b08:  12 80 00 ab  bne  0xa00c7db4
a00c7b0c:  01 00 00 00  nop
a00c7b10:  9a 16 22 90  or  %i0, 0x290, %o5
a00c7b14:  c2 0b 61 a4  ldub  [ %o5 + 0x1a4 ], %g1
a00c7b18:  80 a0 60 03  cmp  %g1, 3
a00c7b1c:  22 80 00 87  be,a   0xa00c7d38
a00c7b20:  d0 0b 60 1f  ldub  [ %o5 + 0x1f ], %o0
a00c7b24:  a0 16 22 90  or  %i0, 0x290, %l0
a00c7b28:  40 00 49 cb  call  0xa00da254
a00c7b2c:  c0 2c 20 19  clrb  [ %l0 + 0x19 ]
a00c7b30:  da 0c 20 1f  ldub  [ %l0 + 0x1f ], %o5
a00c7b34:  80 a3 60 00  cmp  %o5, 0
a00c7b38:  32 80 00 6f  bne,a   0xa00c7cf4
a00c7b3c:  d8 04 20 a8  ld  [ %l0 + 0xa8 ], %o4
a00c7b40:  40 00 44 37  call  0xa00d8c1c
a00c7b44:  01 00 00 00  nop
a00c7b48:  82 16 22 90  or  %i0, 0x290, %g1
a00c7b4c:  e0 00 60 a8  ld  [ %g1 + 0xa8 ], %l0
a00c7b50:  31 00 00 10  sethi  %hi(0x4000), %i0
a00c7b54:  80 8c 00 18  btst  %l0, %i0
a00c7b58:  12 80 00 41  bne  0xa00c7c5c
a00c7b5c:  01 00 00 00  nop
a00c7b60:  40 00 33 8e  call  0xa00d4998
a00c7b64:  01 00 00 00  nop
a00c7b68:  7f ff c3 59  call  0xa00b88cc
a00c7b6c:  01 00 00 00  nop
a00c7b70:  80 a4 60 02  cmp  %l1, 2
a00c7b74:  02 80 00 44  be  0xa00c7c84
a00c7b78:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00c7b7c:  80 a4 60 03  cmp  %l1, 3
a00c7b80:  02 80 00 76  be  0xa00c7d58
a00c7b84:  a0 10 20 35  mov  0x35, %l0
a00c7b88:  31 2a 00 b4  sethi  %hi(0xa802d000), %i0
a00c7b8c:  94 16 20 78  or  %i0, 0x78, %o2	! 0xa802d078
a00c7b90:  92 10 20 30  mov  0x30, %o1
a00c7b94:  9e 10 20 36  mov  0x36, %o7
a00c7b98:  98 10 20 2b  mov  0x2b, %o4
a00c7b9c:  96 10 20 0d  mov  0xd, %o3
a00c7ba0:  e0 2e 20 78  stb  %l0, [ %i0 + 0x78 ]
a00c7ba4:  de 2a a0 01  stb  %o7, [ %o2 + 1 ]
a00c7ba8:  d2 2a a0 03  stb  %o1, [ %o2 + 3 ]
a00c7bac:  d8 2a a0 04  stb  %o4, [ %o2 + 4 ]
a00c7bb0:  d6 2a a0 05  stb  %o3, [ %o2 + 5 ]
a00c7bb4:  80 a4 60 02  cmp  %l1, 2
a00c7bb8:  02 80 00 3f  be  0xa00c7cb4
a00c7bbc:  d2 2a a0 02  stb  %o1, [ %o2 + 2 ]
a00c7bc0:  80 a4 60 03  cmp  %l1, 3
a00c7bc4:  02 80 00 72  be  0xa00c7d8c
a00c7bc8:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00c7bcc:  96 13 20 d0  or  %o4, 0xd0, %o3	! 0xa802d0d0
a00c7bd0:  1f 2a 00 ac  sethi  %hi(0xa802b000), %o7
a00c7bd4:  c0 2b e0 9c  clrb  [ %o7 + 0x9c ]	! 0xa802b09c
a00c7bd8:  c0 2b 20 d0  clrb  [ %o4 + 0xd0 ]
a00c7bdc:  c0 2a e0 19  clrb  [ %o3 + 0x19 ]
a00c7be0:  c0 2a e0 01  clrb  [ %o3 + 1 ]
a00c7be4:  c0 2a e0 07  clrb  [ %o3 + 7 ]
a00c7be8:  80 a4 60 02  cmp  %l1, 2
a00c7bec:  02 80 00 3b  be  0xa00c7cd8
a00c7bf0:  c0 2a e0 0a  clrb  [ %o3 + 0xa ]
a00c7bf4:  80 a4 60 03  cmp  %l1, 3
a00c7bf8:  12 80 00 3b  bne  0xa00c7ce4
a00c7bfc:  90 10 00 11  mov  %l1, %o0
a00c7c00:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a00c7c04:  94 14 21 08  or  %l0, 0x108, %o2	! 0xa802d108
a00c7c08:  90 10 20 03  mov  3, %o0
a00c7c0c:  40 02 02 f7  call  0xa01487e8
a00c7c10:  92 10 20 06  mov  6, %o1
a00c7c14:  10 80 00 88  b  0xa00c7e34
a00c7c18:  b0 10 20 00  clr  %i0
a00c7c1c:  80 a3 e0 00  cmp  %o7, 0
a00c7c20:  22 bf ff aa  be,a   0xa00c7ac8
a00c7c24:  98 16 22 90  or  %i0, 0x290, %o4
a00c7c28:  7f ff 24 ec  call  0xa0090fd8
a00c7c2c:  01 00 00 00  nop
a00c7c30:  d0 04 20 a8  ld  [ %l0 + 0xa8 ], %o0
a00c7c34:  82 0a 3f 7f  and  %o0, -129, %g1
a00c7c38:  40 01 74 c3  call  0xa0124f44
a00c7c3c:  c2 24 20 a8  st  %g1, [ %l0 + 0xa8 ]
a00c7c40:  40 00 49 51  call  0xa00da184
a00c7c44:  01 00 00 00  nop
a00c7c48:  10 bf ff a0  b  0xa00c7ac8
a00c7c4c:  98 16 22 90  or  %i0, 0x290, %o4
a00c7c50:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00c7c54:  10 bf ff 8a  b  0xa00c7a7c
a00c7c58:  c2 08 60 49  ldub  [ %g1 + 0x49 ], %g1	! 0xa802d049
a00c7c5c:  40 00 38 1f  call  0xa00d5cd8
a00c7c60:  01 00 00 00  nop
a00c7c64:  40 00 33 4d  call  0xa00d4998
a00c7c68:  01 00 00 00  nop
a00c7c6c:  7f ff c3 18  call  0xa00b88cc
a00c7c70:  01 00 00 00  nop
a00c7c74:  80 a4 60 02  cmp  %l1, 2
a00c7c78:  12 bf ff c2  bne  0xa00c7b80
a00c7c7c:  80 a4 60 03  cmp  %l1, 3
a00c7c80:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00c7c84:  a2 12 e1 28  or  %o3, 0x128, %l1	! 0xa802d128
a00c7c88:  90 10 20 30  mov  0x30, %o0
a00c7c8c:  98 10 20 35  mov  0x35, %o4
a00c7c90:  94 10 20 0d  mov  0xd, %o2
a00c7c94:  92 10 20 36  mov  0x36, %o1
a00c7c98:  9a 10 20 2b  mov  0x2b, %o5
a00c7c9c:  d8 2a e1 28  stb  %o4, [ %o3 + 0x128 ]
a00c7ca0:  d4 2c 60 05  stb  %o2, [ %l1 + 5 ]
a00c7ca4:  d2 2c 60 01  stb  %o1, [ %l1 + 1 ]
a00c7ca8:  d0 2c 60 03  stb  %o0, [ %l1 + 3 ]
a00c7cac:  da 2c 60 04  stb  %o5, [ %l1 + 4 ]
a00c7cb0:  d0 2c 60 02  stb  %o0, [ %l1 + 2 ]
a00c7cb4:  23 2a 00 b4  sethi  %hi(0xa802d000), %l1
a00c7cb8:  94 14 60 40  or  %l1, 0x40, %o2	! 0xa802d040
a00c7cbc:  03 2a 00 ac  sethi  %hi(0xa802b000), %g1
a00c7cc0:  c0 28 60 9a  clrb  [ %g1 + 0x9a ]	! 0xa802b09a
a00c7cc4:  c0 2c 60 40  clrb  [ %l1 + 0x40 ]
a00c7cc8:  c0 2a a0 19  clrb  [ %o2 + 0x19 ]
a00c7ccc:  c0 2a a0 01  clrb  [ %o2 + 1 ]
a00c7cd0:  c0 2a a0 07  clrb  [ %o2 + 7 ]
a00c7cd4:  c0 2a a0 0a  clrb  [ %o2 + 0xa ]
a00c7cd8:  31 2a 00 b4  sethi  %hi(0xa802d000), %i0
a00c7cdc:  94 16 21 28  or  %i0, 0x128, %o2	! 0xa802d128
a00c7ce0:  90 10 20 02  mov  2, %o0
a00c7ce4:  40 02 02 c1  call  0xa01487e8
a00c7ce8:  92 10 20 06  mov  6, %o1
a00c7cec:  10 80 00 52  b  0xa00c7e34
a00c7cf0:  b0 10 20 00  clr  %i0
a00c7cf4:  17 00 00 08  sethi  %hi(0x2000), %o3
a00c7cf8:  94 2b 00 0b  andn  %o4, %o3, %o2
a00c7cfc:  d4 24 20 a8  st  %o2, [ %l0 + 0xa8 ]
a00c7d00:  7f fe ee b9  call  0xa00837e4
a00c7d04:  c0 24 20 b0  clr  [ %l0 + 0xb0 ]
a00c7d08:  92 0a 20 ff  and  %o0, 0xff, %o1
a00c7d0c:  80 a2 60 01  cmp  %o1, 1
a00c7d10:  22 80 00 45  be,a   0xa00c7e24
a00c7d14:  c0 2c 21 a4  clrb  [ %l0 + 0x1a4 ]
a00c7d18:  de 0c 20 1f  ldub  [ %l0 + 0x1f ], %o7
a00c7d1c:  80 a3 e0 02  cmp  %o7, 2
a00c7d20:  12 bf ff 88  bne  0xa00c7b40
a00c7d24:  01 00 00 00  nop
a00c7d28:  c0 2c 21 a4  clrb  [ %l0 + 0x1a4 ]
a00c7d2c:  7f fe ec f2  call  0xa00830f4
a00c7d30:  90 10 20 00  clr  %o0
a00c7d34:  30 bf ff 83  b,a   0xa00c7b40
a00c7d38:  80 a2 20 00  cmp  %o0, 0
a00c7d3c:  32 bf ff 7a  bne,a   0xa00c7b24
a00c7d40:  c0 2b 61 a4  clrb  [ %o5 + 0x1a4 ]
a00c7d44:  10 bf ff 79  b  0xa00c7b28
a00c7d48:  a0 16 22 90  or  %i0, 0x290, %l0
a00c7d4c:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00c7d50:  10 bf ff 4b  b  0xa00c7a7c
a00c7d54:  c2 0a 20 a1  ldub  [ %o0 + 0xa1 ], %g1	! 0xa802d0a1
a00c7d58:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00c7d5c:  9e 12 21 08  or  %o0, 0x108, %o7	! 0xa802d108
a00c7d60:  b0 10 20 30  mov  0x30, %i0
a00c7d64:  9a 10 20 35  mov  0x35, %o5
a00c7d68:  a2 10 20 0d  mov  0xd, %l1
a00c7d6c:  82 10 20 36  mov  0x36, %g1
a00c7d70:  a0 10 20 2b  mov  0x2b, %l0
a00c7d74:  da 2a 21 08  stb  %o5, [ %o0 + 0x108 ]
a00c7d78:  e2 2b e0 05  stb  %l1, [ %o7 + 5 ]
a00c7d7c:  c2 2b e0 01  stb  %g1, [ %o7 + 1 ]
a00c7d80:  f0 2b e0 03  stb  %i0, [ %o7 + 3 ]
a00c7d84:  e0 2b e0 04  stb  %l0, [ %o7 + 4 ]
a00c7d88:  f0 2b e0 02  stb  %i0, [ %o7 + 2 ]
a00c7d8c:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a00c7d90:  90 13 60 98  or  %o5, 0x98, %o0	! 0xa802d098
a00c7d94:  13 2a 00 ac  sethi  %hi(0xa802b000), %o1
a00c7d98:  c0 2a 60 98  clrb  [ %o1 + 0x98 ]	! 0xa802b098
a00c7d9c:  c0 2b 60 98  clrb  [ %o5 + 0x98 ]
a00c7da0:  c0 2a 20 19  clrb  [ %o0 + 0x19 ]
a00c7da4:  c0 2a 20 01  clrb  [ %o0 + 1 ]
a00c7da8:  c0 2a 20 07  clrb  [ %o0 + 7 ]
a00c7dac:  10 bf ff 95  b  0xa00c7c00
a00c7db0:  c0 2a 20 0a  clrb  [ %o0 + 0xa ]
a00c7db4:  40 00 38 62  call  0xa00d5f3c
a00c7db8:  c0 23 60 b0  clr  [ %o5 + 0xb0 ]
a00c7dbc:  10 bf ff 56  b  0xa00c7b14
a00c7dc0:  9a 16 22 90  or  %i0, 0x290, %o5
a00c7dc4:  94 2b 40 0b  andn  %o5, %o3, %o2
a00c7dc8:  d4 23 20 ac  st  %o2, [ %o4 + 0xac ]
a00c7dcc:  40 01 f2 0c  call  0xa01445fc
a00c7dd0:  d0 0b 20 1e  ldub  [ %o4 + 0x1e ], %o0
a00c7dd4:  80 8a 20 ff  btst  0xff, %o0
a00c7dd8:  32 bf ff 46  bne,a   0xa00c7af0
a00c7ddc:  9a 16 22 90  or  %i0, 0x290, %o5
a00c7de0:  40 00 45 07  call  0xa00d91fc
a00c7de4:  90 10 20 00  clr  %o0
a00c7de8:  90 10 20 01  mov  1, %o0
a00c7dec:  40 01 ee fb  call  0xa01439d8
a00c7df0:  92 10 20 01  mov  1, %o1
a00c7df4:  90 10 20 00  clr  %o0
a00c7df8:  40 02 01 1c  call  0xa0148268
a00c7dfc:  92 10 20 01  mov  1, %o1
a00c7e00:  90 10 20 01  mov  1, %o0
a00c7e04:  40 02 01 19  call  0xa0148268
a00c7e08:  92 10 20 01  mov  1, %o1
a00c7e0c:  10 bf ff 39  b  0xa00c7af0
a00c7e10:  9a 16 22 90  or  %i0, 0x290, %o5
a00c7e14:  c0 2c 20 4a  clrb  [ %l0 + 0x4a ]
a00c7e18:  40 00 38 25  call  0xa00d5eac
a00c7e1c:  90 10 20 00  clr  %o0
a00c7e20:  30 bf ff 23  b,a   0xa00c7aac
a00c7e24:  7f fe ec b4  call  0xa00830f4
a00c7e28:  90 10 20 00  clr  %o0
a00c7e2c:  10 bf ff bc  b  0xa00c7d1c
a00c7e30:  de 0c 20 1f  ldub  [ %l0 + 0x1f ], %o7
a00c7e34:  81 c7 e0 08  ret
a00c7e38:  81 e8 00 00  restore
