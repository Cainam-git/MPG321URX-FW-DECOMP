# leon2m FUN_a00c49b8 0xa00c49b8-0xa00c4ec4 (1292 bytes)
a00c49b8:  9d e3 bf 98  save  %sp, -104, %sp
a00c49bc:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00c49c0:  80 a6 20 02  cmp  %i0, 2
a00c49c4:  02 80 00 b8  be  0xa00c4ca4
a00c49c8:  80 a6 20 03  cmp  %i0, 3
a00c49cc:  02 80 00 ce  be  0xa00c4d04
a00c49d0:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00c49d4:  c2 0a 60 d6  ldub  [ %o1 + 0xd6 ], %g1	! 0xa802d0d6
a00c49d8:  80 a6 20 02  cmp  %i0, 2
a00c49dc:  02 80 00 af  be  0xa00c4c98
a00c49e0:  98 10 00 01  mov  %g1, %o4
a00c49e4:  80 a6 20 03  cmp  %i0, 3
a00c49e8:  02 80 00 c4  be  0xa00c4cf8
a00c49ec:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a00c49f0:  da 0b e0 d7  ldub  [ %o7 + 0xd7 ], %o5	! 0xa802d0d7
a00c49f4:  98 03 3f d0  add  %o4, -48, %o4
a00c49f8:  a0 0b 20 ff  and  %o4, 0xff, %l0
a00c49fc:  80 a4 20 63  cmp  %l0, 0x63
a00c4a00:  82 0b 60 ff  and  %o5, 0xff, %g1
a00c4a04:  18 80 01 2e  bgu  0xa00c4ebc
a00c4a08:  94 10 20 ff  mov  0xff, %o2
a00c4a0c:  9a 00 7f d0  add  %g1, -48, %o5
a00c4a10:  a2 0b 60 ff  and  %o5, 0xff, %l1
a00c4a14:  80 a4 60 63  cmp  %l1, 0x63
a00c4a18:  18 80 01 29  bgu  0xa00c4ebc
a00c4a1c:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00c4a20:  82 12 e2 90  or  %o3, 0x290, %g1	! 0xa802d290
a00c4a24:  da 28 61 9c  stb  %o5, [ %g1 + 0x19c ]
a00c4a28:  80 a6 20 02  cmp  %i0, 2
a00c4a2c:  02 80 00 a4  be  0xa00c4cbc
a00c4a30:  d8 28 61 98  stb  %o4, [ %g1 + 0x198 ]
a00c4a34:  80 a6 20 03  cmp  %i0, 3
a00c4a38:  02 80 00 b6  be  0xa00c4d10
a00c4a3c:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00c4a40:  c2 0a 20 d8  ldub  [ %o0 + 0xd8 ], %g1	! 0xa802d0d8
a00c4a44:  80 a6 20 02  cmp  %i0, 2
a00c4a48:  02 80 00 9a  be  0xa00c4cb0
a00c4a4c:  98 10 00 01  mov  %g1, %o4
a00c4a50:  80 a6 20 03  cmp  %i0, 3
a00c4a54:  02 80 01 08  be  0xa00c4e74
a00c4a58:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a00c4a5c:  da 0b e0 d9  ldub  [ %o7 + 0xd9 ], %o5	! 0xa802d0d9
a00c4a60:  98 03 3f d0  add  %o4, -48, %o4
a00c4a64:  a0 0b 20 ff  and  %o4, 0xff, %l0
a00c4a68:  80 a4 20 63  cmp  %l0, 0x63
a00c4a6c:  82 0b 60 ff  and  %o5, 0xff, %g1
a00c4a70:  18 80 01 13  bgu  0xa00c4ebc
a00c4a74:  94 10 20 ff  mov  0xff, %o2
a00c4a78:  9a 00 7f d0  add  %g1, -48, %o5
a00c4a7c:  a2 0b 60 ff  and  %o5, 0xff, %l1
a00c4a80:  80 a4 60 63  cmp  %l1, 0x63
a00c4a84:  18 80 01 0e  bgu  0xa00c4ebc
a00c4a88:  82 12 e2 90  or  %o3, 0x290, %g1
a00c4a8c:  da 28 61 9d  stb  %o5, [ %g1 + 0x19d ]
a00c4a90:  80 a6 20 02  cmp  %i0, 2
a00c4a94:  02 80 00 90  be  0xa00c4cd4
a00c4a98:  d8 28 61 99  stb  %o4, [ %g1 + 0x199 ]
a00c4a9c:  80 a6 20 03  cmp  %i0, 3
a00c4aa0:  02 80 00 fb  be  0xa00c4e8c
a00c4aa4:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00c4aa8:  c2 0a 20 da  ldub  [ %o0 + 0xda ], %g1	! 0xa802d0da
a00c4aac:  80 a6 20 02  cmp  %i0, 2
a00c4ab0:  02 80 00 86  be  0xa00c4cc8
a00c4ab4:  98 10 00 01  mov  %g1, %o4
a00c4ab8:  80 a6 20 03  cmp  %i0, 3
a00c4abc:  02 80 00 f1  be  0xa00c4e80
a00c4ac0:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a00c4ac4:  da 0b e0 db  ldub  [ %o7 + 0xdb ], %o5	! 0xa802d0db
a00c4ac8:  98 03 3f d0  add  %o4, -48, %o4
a00c4acc:  a0 0b 20 ff  and  %o4, 0xff, %l0
a00c4ad0:  80 a4 20 63  cmp  %l0, 0x63
a00c4ad4:  82 0b 60 ff  and  %o5, 0xff, %g1
a00c4ad8:  18 80 00 f9  bgu  0xa00c4ebc
a00c4adc:  94 10 20 ff  mov  0xff, %o2
a00c4ae0:  9a 00 7f d0  add  %g1, -48, %o5
a00c4ae4:  a2 0b 60 ff  and  %o5, 0xff, %l1
a00c4ae8:  80 a4 60 63  cmp  %l1, 0x63
a00c4aec:  18 80 00 f4  bgu  0xa00c4ebc
a00c4af0:  82 12 e2 90  or  %o3, 0x290, %g1
a00c4af4:  da 28 61 9e  stb  %o5, [ %g1 + 0x19e ]
a00c4af8:  80 a6 20 02  cmp  %i0, 2
a00c4afc:  02 80 00 7c  be  0xa00c4cec
a00c4b00:  d8 28 61 9a  stb  %o4, [ %g1 + 0x19a ]
a00c4b04:  80 a6 20 03  cmp  %i0, 3
a00c4b08:  02 80 00 e4  be  0xa00c4e98
a00c4b0c:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00c4b10:  c2 0a 20 dc  ldub  [ %o0 + 0xdc ], %g1	! 0xa802d0dc
a00c4b14:  80 a6 20 02  cmp  %i0, 2
a00c4b18:  02 80 00 72  be  0xa00c4ce0
a00c4b1c:  98 10 00 01  mov  %g1, %o4
a00c4b20:  80 a6 20 03  cmp  %i0, 3
a00c4b24:  02 80 00 e0  be  0xa00c4ea4
a00c4b28:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a00c4b2c:  da 0b e0 dd  ldub  [ %o7 + 0xdd ], %o5	! 0xa802d0dd
a00c4b30:  98 03 3f d0  add  %o4, -48, %o4
a00c4b34:  a0 0b 20 ff  and  %o4, 0xff, %l0
a00c4b38:  80 a4 20 63  cmp  %l0, 0x63
a00c4b3c:  82 0b 60 ff  and  %o5, 0xff, %g1
a00c4b40:  18 80 00 df  bgu  0xa00c4ebc
a00c4b44:  94 10 20 ff  mov  0xff, %o2
a00c4b48:  9a 00 7f d0  add  %g1, -48, %o5
a00c4b4c:  a2 0b 60 ff  and  %o5, 0xff, %l1
a00c4b50:  80 a4 60 63  cmp  %l1, 0x63
a00c4b54:  18 80 00 da  bgu  0xa00c4ebc
a00c4b58:  82 12 e2 90  or  %o3, 0x290, %g1
a00c4b5c:  da 28 61 9f  stb  %o5, [ %g1 + 0x19f ]
a00c4b60:  80 a6 20 02  cmp  %i0, 2
a00c4b64:  02 80 00 9f  be  0xa00c4de0
a00c4b68:  d8 28 61 9b  stb  %o4, [ %g1 + 0x19b ]
a00c4b6c:  80 a6 20 03  cmp  %i0, 3
a00c4b70:  02 80 00 d0  be  0xa00c4eb0
a00c4b74:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00c4b78:  d8 0a 60 de  ldub  [ %o1 + 0xde ], %o4	! 0xa802d0de
a00c4b7c:  98 0b 20 ff  and  %o4, 0xff, %o4
a00c4b80:  82 03 3f d0  add  %o4, -48, %g1
a00c4b84:  9a 08 60 ff  and  %g1, 0xff, %o5
a00c4b88:  80 a3 60 04  cmp  %o5, 4
a00c4b8c:  18 80 00 cc  bgu  0xa00c4ebc
a00c4b90:  94 10 20 ff  mov  0xff, %o2
a00c4b94:  a0 12 e2 90  or  %o3, 0x290, %l0
a00c4b98:  c2 2c 21 a0  stb  %g1, [ %l0 + 0x1a0 ]
a00c4b9c:  80 a3 60 00  cmp  %o5, 0
a00c4ba0:  02 80 00 0d  be  0xa00c4bd4
a00c4ba4:  23 2a 00 b3  sethi  %hi(0xa802cc00), %l1
a00c4ba8:  d2 14 63 f4  lduh  [ %l1 + 0x3f4 ], %o1	! 0xa802cff4
a00c4bac:  90 03 3f cf  add  %o4, -49, %o0
a00c4bb0:  1b 00 00 10  sethi  %hi(0x4000), %o5
a00c4bb4:  82 12 40 0d  or  %o1, %o5, %g1
a00c4bb8:  9e 0a 20 ff  and  %o0, 0xff, %o7
a00c4bbc:  c2 34 63 f4  sth  %g1, [ %l1 + 0x3f4 ]
a00c4bc0:  98 03 c0 10  add  %o7, %l0, %o4
a00c4bc4:  d6 0b 21 9c  ldub  [ %o4 + 0x19c ], %o3
a00c4bc8:  d4 0b 21 98  ldub  [ %o4 + 0x198 ], %o2
a00c4bcc:  d4 2c 21 a1  stb  %o2, [ %l0 + 0x1a1 ]
a00c4bd0:  d6 2c 21 a2  stb  %o3, [ %l0 + 0x1a2 ]
a00c4bd4:  7f ff cf 3e  call  0xa00b88cc
a00c4bd8:  01 00 00 00  nop
a00c4bdc:  94 14 63 f4  or  %l1, 0x3f4, %o2
a00c4be0:  e2 12 a0 04  lduh  [ %o2 + 4 ], %l1
a00c4be4:  17 00 00 18  sethi  %hi(0x6000), %o3
a00c4be8:  80 8a c0 11  btst  %o3, %l1
a00c4bec:  02 80 00 80  be  0xa00c4dec
a00c4bf0:  80 a6 20 02  cmp  %i0, 2
a00c4bf4:  02 80 00 61  be  0xa00c4d78
a00c4bf8:  80 a6 20 03  cmp  %i0, 3
a00c4bfc:  02 80 00 48  be  0xa00c4d1c
a00c4c00:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a00c4c04:  94 14 20 78  or  %l0, 0x78, %o2	! 0xa802d078
a00c4c08:  96 10 20 30  mov  0x30, %o3
a00c4c0c:  82 10 20 35  mov  0x35, %g1
a00c4c10:  90 10 20 36  mov  0x36, %o0
a00c4c14:  9e 10 20 2b  mov  0x2b, %o7
a00c4c18:  98 10 20 0d  mov  0xd, %o4
a00c4c1c:  c2 2c 20 78  stb  %g1, [ %l0 + 0x78 ]
a00c4c20:  d0 2a a0 01  stb  %o0, [ %o2 + 1 ]
a00c4c24:  d6 2a a0 03  stb  %o3, [ %o2 + 3 ]
a00c4c28:  de 2a a0 04  stb  %o7, [ %o2 + 4 ]
a00c4c2c:  d8 2a a0 05  stb  %o4, [ %o2 + 5 ]
a00c4c30:  80 a6 20 02  cmp  %i0, 2
a00c4c34:  02 80 00 5e  be  0xa00c4dac
a00c4c38:  d6 2a a0 02  stb  %o3, [ %o2 + 2 ]
a00c4c3c:  80 a6 20 03  cmp  %i0, 3
a00c4c40:  02 80 00 44  be  0xa00c4d50
a00c4c44:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00c4c48:  9e 13 20 d0  or  %o4, 0xd0, %o7	! 0xa802d0d0
a00c4c4c:  11 2a 00 ac  sethi  %hi(0xa802b000), %o0
a00c4c50:  c0 2a 20 9c  clrb  [ %o0 + 0x9c ]	! 0xa802b09c
a00c4c54:  c0 2b 20 d0  clrb  [ %o4 + 0xd0 ]
a00c4c58:  c0 2b e0 19  clrb  [ %o7 + 0x19 ]
a00c4c5c:  c0 2b e0 01  clrb  [ %o7 + 1 ]
a00c4c60:  c0 2b e0 07  clrb  [ %o7 + 7 ]
a00c4c64:  80 a6 20 02  cmp  %i0, 2
a00c4c68:  02 80 00 5a  be  0xa00c4dd0
a00c4c6c:  c0 2b e0 0a  clrb  [ %o7 + 0xa ]
a00c4c70:  80 a6 20 03  cmp  %i0, 3
a00c4c74:  12 80 00 05  bne  0xa00c4c88
a00c4c78:  90 10 00 18  mov  %i0, %o0
a00c4c7c:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00c4c80:  94 10 61 08  or  %g1, 0x108, %o2	! 0xa802d108
a00c4c84:  90 10 20 03  mov  3, %o0
a00c4c88:  40 02 0e d8  call  0xa01487e8
a00c4c8c:  92 10 20 06  mov  6, %o1
a00c4c90:  10 80 00 8b  b  0xa00c4ebc
a00c4c94:  94 10 20 00  clr  %o2
a00c4c98:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00c4c9c:  10 bf ff 56  b  0xa00c49f4
a00c4ca0:  da 0a a0 47  ldub  [ %o2 + 0x47 ], %o5	! 0xa802d047
a00c4ca4:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00c4ca8:  10 bf ff 4c  b  0xa00c49d8
a00c4cac:  c2 08 60 46  ldub  [ %g1 + 0x46 ], %g1	! 0xa802d046
a00c4cb0:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00c4cb4:  10 bf ff 6b  b  0xa00c4a60
a00c4cb8:  da 0a 60 49  ldub  [ %o1 + 0x49 ], %o5	! 0xa802d049
a00c4cbc:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00c4cc0:  10 bf ff 61  b  0xa00c4a44
a00c4cc4:  c2 0b 20 48  ldub  [ %o4 + 0x48 ], %g1	! 0xa802d048
a00c4cc8:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00c4ccc:  10 bf ff 7f  b  0xa00c4ac8
a00c4cd0:  da 0a 60 4b  ldub  [ %o1 + 0x4b ], %o5	! 0xa802d04b
a00c4cd4:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00c4cd8:  10 bf ff 75  b  0xa00c4aac
a00c4cdc:  c2 0b 20 4a  ldub  [ %o4 + 0x4a ], %g1	! 0xa802d04a
a00c4ce0:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00c4ce4:  10 bf ff 93  b  0xa00c4b30
a00c4ce8:  da 0a 60 4d  ldub  [ %o1 + 0x4d ], %o5	! 0xa802d04d
a00c4cec:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00c4cf0:  10 bf ff 89  b  0xa00c4b14
a00c4cf4:  c2 0b 20 4c  ldub  [ %o4 + 0x4c ], %g1	! 0xa802d04c
a00c4cf8:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00c4cfc:  10 bf ff 3e  b  0xa00c49f4
a00c4d00:  da 0a e0 9f  ldub  [ %o3 + 0x9f ], %o5	! 0xa802d09f
a00c4d04:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00c4d08:  10 bf ff 34  b  0xa00c49d8
a00c4d0c:  c2 0a 20 9e  ldub  [ %o0 + 0x9e ], %g1	! 0xa802d09e
a00c4d10:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a00c4d14:  10 bf ff 4c  b  0xa00c4a44
a00c4d18:  c2 0b 60 a0  ldub  [ %o5 + 0xa0 ], %g1	! 0xa802d0a0
a00c4d1c:  23 2a 00 b4  sethi  %hi(0xa802d000), %l1
a00c4d20:  90 14 61 08  or  %l1, 0x108, %o0	! 0xa802d108
a00c4d24:  a0 10 20 30  mov  0x30, %l0
a00c4d28:  9a 10 20 35  mov  0x35, %o5
a00c4d2c:  b0 10 20 0d  mov  0xd, %i0
a00c4d30:  92 10 20 36  mov  0x36, %o1
a00c4d34:  82 10 20 2b  mov  0x2b, %g1
a00c4d38:  da 2c 61 08  stb  %o5, [ %l1 + 0x108 ]
a00c4d3c:  f0 2a 20 05  stb  %i0, [ %o0 + 5 ]
a00c4d40:  d2 2a 20 01  stb  %o1, [ %o0 + 1 ]
a00c4d44:  e0 2a 20 03  stb  %l0, [ %o0 + 3 ]
a00c4d48:  c2 2a 20 04  stb  %g1, [ %o0 + 4 ]
a00c4d4c:  e0 2a 20 02  stb  %l0, [ %o0 + 2 ]
a00c4d50:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a00c4d54:  a2 13 60 98  or  %o5, 0x98, %l1	! 0xa802d098
a00c4d58:  17 2a 00 ac  sethi  %hi(0xa802b000), %o3
a00c4d5c:  c0 2a e0 98  clrb  [ %o3 + 0x98 ]	! 0xa802b098
a00c4d60:  c0 2b 60 98  clrb  [ %o5 + 0x98 ]
a00c4d64:  c0 2c 60 19  clrb  [ %l1 + 0x19 ]
a00c4d68:  c0 2c 60 01  clrb  [ %l1 + 1 ]
a00c4d6c:  c0 2c 60 07  clrb  [ %l1 + 7 ]
a00c4d70:  10 bf ff c3  b  0xa00c4c7c
a00c4d74:  c0 2c 60 0a  clrb  [ %l1 + 0xa ]
a00c4d78:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00c4d7c:  b0 13 21 28  or  %o4, 0x128, %i0	! 0xa802d128
a00c4d80:  a2 10 20 30  mov  0x30, %l1
a00c4d84:  9e 10 20 35  mov  0x35, %o7
a00c4d88:  94 10 20 0d  mov  0xd, %o2
a00c4d8c:  96 10 20 36  mov  0x36, %o3
a00c4d90:  9a 10 20 2b  mov  0x2b, %o5
a00c4d94:  de 2b 21 28  stb  %o7, [ %o4 + 0x128 ]
a00c4d98:  d4 2e 20 05  stb  %o2, [ %i0 + 5 ]
a00c4d9c:  d6 2e 20 01  stb  %o3, [ %i0 + 1 ]
a00c4da0:  e2 2e 20 03  stb  %l1, [ %i0 + 3 ]
a00c4da4:  da 2e 20 04  stb  %o5, [ %i0 + 4 ]
a00c4da8:  e2 2e 20 02  stb  %l1, [ %i0 + 2 ]
a00c4dac:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00c4db0:  94 12 60 40  or  %o1, 0x40, %o2	! 0xa802d040
a00c4db4:  31 2a 00 ac  sethi  %hi(0xa802b000), %i0
a00c4db8:  c0 2e 20 9a  clrb  [ %i0 + 0x9a ]	! 0xa802b09a
a00c4dbc:  c0 2a 60 40  clrb  [ %o1 + 0x40 ]
a00c4dc0:  c0 2a a0 19  clrb  [ %o2 + 0x19 ]
a00c4dc4:  c0 2a a0 01  clrb  [ %o2 + 1 ]
a00c4dc8:  c0 2a a0 07  clrb  [ %o2 + 7 ]
a00c4dcc:  c0 2a a0 0a  clrb  [ %o2 + 0xa ]
a00c4dd0:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a00c4dd4:  94 14 21 28  or  %l0, 0x128, %o2	! 0xa802d128
a00c4dd8:  10 bf ff ac  b  0xa00c4c88
a00c4ddc:  90 10 20 02  mov  2, %o0
a00c4de0:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a00c4de4:  10 bf ff 66  b  0xa00c4b7c
a00c4de8:  d8 0b 60 4e  ldub  [ %o5 + 0x4e ], %o4	! 0xa802d04e
a00c4dec:  7f ff 30 7b  call  0xa0090fd8
a00c4df0:  01 00 00 00  nop
a00c4df4:  67 ff 25 2c  call  0x4008e2a4
a00c4df8:  01 00 00 00  nop
a00c4dfc:  67 ff 25 2a  call  0x4008e2a4
a00c4e00:  01 00 00 00  nop
a00c4e04:  67 ff 25 28  call  0x4008e2a4
a00c4e08:  01 00 00 00  nop
a00c4e0c:  67 ff 25 26  call  0x4008e2a4
a00c4e10:  01 00 00 00  nop
a00c4e14:  7f ff 30 66  call  0xa0090fac
a00c4e18:  01 00 00 00  nop
a00c4e1c:  d8 0c 21 90  ldub  [ %l0 + 0x190 ], %o4
a00c4e20:  80 a3 20 00  cmp  %o4, 0
a00c4e24:  12 bf ff 74  bne  0xa00c4bf4
a00c4e28:  80 a6 20 02  cmp  %i0, 2
a00c4e2c:  c2 04 20 a8  ld  [ %l0 + 0xa8 ], %g1
a00c4e30:  1f 00 00 04  sethi  %hi(0x1000), %o7
a00c4e34:  80 88 40 0f  btst  %g1, %o7
a00c4e38:  12 bf ff 6f  bne  0xa00c4bf4
a00c4e3c:  80 a6 20 02  cmp  %i0, 2
a00c4e40:  d0 0c 21 a0  ldub  [ %l0 + 0x1a0 ], %o0
a00c4e44:  80 a2 20 00  cmp  %o0, 0
a00c4e48:  12 bf ff 6b  bne  0xa00c4bf4
a00c4e4c:  80 a6 20 02  cmp  %i0, 2
a00c4e50:  d2 04 20 ac  ld  [ %l0 + 0xac ], %o1
a00c4e54:  21 00 10 00  sethi  %hi(0x400000), %l0
a00c4e58:  80 8a 40 10  btst  %o1, %l0
a00c4e5c:  32 bf ff 66  bne,a   0xa00c4bf4
a00c4e60:  80 a6 20 02  cmp  %i0, 2
a00c4e64:  7f ff 30 5d  call  0xa0090fd8
a00c4e68:  01 00 00 00  nop
a00c4e6c:  10 bf ff 62  b  0xa00c4bf4
a00c4e70:  80 a6 20 02  cmp  %i0, 2
a00c4e74:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00c4e78:  10 bf fe fa  b  0xa00c4a60
a00c4e7c:  da 0a a0 a1  ldub  [ %o2 + 0xa1 ], %o5	! 0xa802d0a1
a00c4e80:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00c4e84:  10 bf ff 11  b  0xa00c4ac8
a00c4e88:  da 0a a0 a3  ldub  [ %o2 + 0xa3 ], %o5	! 0xa802d0a3
a00c4e8c:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a00c4e90:  10 bf ff 07  b  0xa00c4aac
a00c4e94:  c2 0b 60 a2  ldub  [ %o5 + 0xa2 ], %g1	! 0xa802d0a2
a00c4e98:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a00c4e9c:  10 bf ff 1e  b  0xa00c4b14
a00c4ea0:  c2 0b 60 a4  ldub  [ %o5 + 0xa4 ], %g1	! 0xa802d0a4
a00c4ea4:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00c4ea8:  10 bf ff 22  b  0xa00c4b30
a00c4eac:  da 0a a0 a5  ldub  [ %o2 + 0xa5 ], %o5	! 0xa802d0a5
a00c4eb0:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00c4eb4:  10 bf ff 32  b  0xa00c4b7c
a00c4eb8:  d8 0a 20 a6  ldub  [ %o0 + 0xa6 ], %o4	! 0xa802d0a6
a00c4ebc:  81 c7 e0 08  ret
a00c4ec0:  91 e8 00 0a  restore  %g0, %o2, %o0
