# leon2s FUN_a00d3c40 0xa00d3c40-0xa00d3eb0 (624 bytes)  [FUN_a00d3ea8 = unreachable ret/restore tail, merged]
a00d3c40:  9d e3 bf 98  save  %sp, -104, %sp
a00d3c44:  03 33 c0 f2  sethi  %hi(0xcf03c800), %g1
a00d3c48:  82 10 60 0c  or  %g1, 0xc, %g1	! 0xcf03c80c
a00d3c4c:  c2 00 40 00  ld  [ %g1 ], %g1
a00d3c50:  80 a0 60 99  cmp  %g1, 0x99
a00d3c54:  12 80 00 94  bne  0xa00d3ea4
a00d3c58:  01 00 00 00  nop
a00d3c5c:  7f ff fe 92  call  0xa00d36a4
a00d3c60:  21 2a 01 e3  sethi  %hi(0xa8078c00), %l0
a00d3c64:  03 2a 01 e3  sethi  %hi(0xa8078c00), %g1
a00d3c68:  c2 08 60 36  ldub  [ %g1 + 0x36 ], %g1	! 0xa8078c36
a00d3c6c:  da 0c 20 37  ldub  [ %l0 + 0x37 ], %o5
a00d3c70:  83 38 40 0d  sra  %g1, %o5, %g1
a00d3c74:  80 88 60 01  btst  1, %g1
a00d3c78:  02 80 00 0c  be  0xa00d3ca8
a00d3c7c:  01 00 00 00  nop
a00d3c80:  7f ff fc 27  call  0xa00d2d1c
a00d3c84:  31 34 00 4f  sethi  %hi(0xd0013c00), %i0
a00d3c88:  f2 0c 20 37  ldub  [ %l0 + 0x37 ], %i1
a00d3c8c:  b3 2e 60 10  sll  %i1, 0x10, %i1
a00d3c90:  03 2a 01 e3  sethi  %hi(0xa8078c00), %g1
a00d3c94:  c0 28 60 38  clrb  [ %g1 + 0x38 ]	! 0xa8078c38
a00d3c98:  b0 16 23 fc  or  %i0, 0x3fc, %i0
a00d3c9c:  b2 16 60 ff  or  %i1, 0xff, %i1
a00d3ca0:  40 3a 76 25  call  0xa0f71534
a00d3ca4:  81 e8 00 00  restore
a00d3ca8:  40 3a 7a 03  call  0xa0f724b4
a00d3cac:  01 00 00 00  nop
a00d3cb0:  90 0a 20 ff  and  %o0, 0xff, %o0
a00d3cb4:  80 a2 20 01  cmp  %o0, 1
a00d3cb8:  12 80 00 08  bne  0xa00d3cd8
a00d3cbc:  01 00 00 00  nop
a00d3cc0:  7f ff fc 33  call  0xa00d2d8c
a00d3cc4:  01 00 00 00  nop
a00d3cc8:  9a 10 20 04  mov  4, %o5	! 0x4
a00d3ccc:  03 2a 01 e3  sethi  %hi(0xa8078c00), %g1
a00d3cd0:  10 80 00 6a  b  0xa00d3e78
a00d3cd4:  da 28 60 38  stb  %o5, [ %g1 + 0x38 ]	! 0xa8078c38
a00d3cd8:  7f ff fc 4a  call  0xa00d2e00
a00d3cdc:  01 00 00 00  nop
a00d3ce0:  90 0a 20 ff  and  %o0, 0xff, %o0
a00d3ce4:  80 a2 20 01  cmp  %o0, 1
a00d3ce8:  12 80 00 0b  bne  0xa00d3d14
a00d3cec:  03 2a 01 e3  sethi  %hi(0xa8078c00), %g1
a00d3cf0:  7f ff fe ee  call  0xa00d38a8
a00d3cf4:  d0 28 60 24  stb  %o0, [ %g1 + 0x24 ]	! 0xa8078c24
a00d3cf8:  40 3b b8 db  call  0xa0fc2064
a00d3cfc:  01 00 00 00  nop
a00d3d00:  03 2a 01 e3  sethi  %hi(0xa8078c00), %g1
a00d3d04:  7f ff fc 66  call  0xa00d2e9c
a00d3d08:  d0 20 60 20  st  %o0, [ %g1 + 0x20 ]	! 0xa8078c20
a00d3d0c:  10 80 00 04  b  0xa00d3d1c
a00d3d10:  03 2a 01 e3  sethi  %hi(0xa8078c00), %g1
a00d3d14:  c0 28 60 24  clrb  [ %g1 + 0x24 ]	! 0xa8078c24
a00d3d18:  03 2a 01 e3  sethi  %hi(0xa8078c00), %g1
a00d3d1c:  c2 08 60 24  ldub  [ %g1 + 0x24 ], %g1	! 0xa8078c24
a00d3d20:  80 a0 60 01  cmp  %g1, 1
a00d3d24:  12 80 00 39  bne  0xa00d3e08
a00d3d28:  03 2a 01 e3  sethi  %hi(0xa8078c00), %g1
a00d3d2c:  7f ff fb 97  call  0xa00d2b88
a00d3d30:  01 00 00 00  nop
a00d3d34:  b2 0a 20 ff  and  %o0, 0xff, %i1
a00d3d38:  80 a6 60 01  cmp  %i1, 1
a00d3d3c:  12 80 00 50  bne  0xa00d3e7c
a00d3d40:  03 2a 01 e3  sethi  %hi(0xa8078c00), %g1
a00d3d44:  03 2a 01 f5  sethi  %hi(0xa807d400), %g1
a00d3d48:  c2 00 61 4c  ld  [ %g1 + 0x14c ], %g1	! 0xa807d54c
a00d3d4c:  80 a0 60 01  cmp  %g1, 1
a00d3d50:  08 80 00 1e  bleu  0xa00d3dc8
a00d3d54:  01 00 00 00  nop
a00d3d58:  7f ff fd 83  call  0xa00d3364
a00d3d5c:  31 2a 01 e3  sethi  %hi(0xa8078c00), %i0
a00d3d60:  80 8a 20 ff  btst  0xff, %o0
a00d3d64:  22 80 00 13  be,a   0xa00d3db0
a00d3d68:  11 27 c7 19  sethi  %hi(0x9f1c6400), %o0
a00d3d6c:  d2 0c 20 37  ldub  [ %l0 + 0x37 ], %o1
a00d3d70:  93 2a 60 10  sll  %o1, 0x10, %o1
a00d3d74:  11 34 00 4f  sethi  %hi(0xd0013c00), %o0
a00d3d78:  90 12 23 fc  or  %o0, 0x3fc, %o0	! 0xd0013ffc
a00d3d7c:  40 3a 75 ee  call  0xa0f71534
a00d3d80:  92 12 60 55  or  %o1, 0x55, %o1
a00d3d84:  82 10 20 02  mov  2, %g1
a00d3d88:  11 27 c7 19  sethi  %hi(0x9f1c6400), %o0
a00d3d8c:  c2 2e 20 38  stb  %g1, [ %i0 + 0x38 ]
a00d3d90:  92 10 20 02  mov  2, %o1
a00d3d94:  40 3a bc ac  call  0xa0f83044
a00d3d98:  90 12 20 58  or  %o0, 0x58, %o0
a00d3d9c:  11 27 c7 32  sethi  %hi(0x9f1cc800), %o0
a00d3da0:  40 3a 75 38  call  0xa0f71280
a00d3da4:  90 12 22 78  or  %o0, 0x278, %o0	! 0x9f1cca78
a00d3da8:  10 80 00 35  b  0xa00d3e7c
a00d3dac:  03 2a 01 e3  sethi  %hi(0xa8078c00), %g1
a00d3db0:  90 12 20 38  or  %o0, 0x38, %o0
a00d3db4:  40 3a bc a4  call  0xa0f83044
a00d3db8:  d2 0e 20 38  ldub  [ %i0 + 0x38 ], %o1
a00d3dbc:  03 2a 01 e3  sethi  %hi(0xa8078c00), %g1
a00d3dc0:  10 80 00 2e  b  0xa00d3e78
a00d3dc4:  f2 28 60 34  stb  %i1, [ %g1 + 0x34 ]	! 0xa8078c34
a00d3dc8:  7f ff fb d5  call  0xa00d2d1c
a00d3dcc:  01 00 00 00  nop
a00d3dd0:  7f ff fb 9a  call  0xa00d2c38
a00d3dd4:  01 00 00 00  nop
a00d3dd8:  03 2a 01 e3  sethi  %hi(0xa8078c00), %g1
a00d3ddc:  11 27 c7 19  sethi  %hi(0x9f1c6400), %o0
a00d3de0:  92 10 20 01  mov  1, %o1
a00d3de4:  f2 28 60 38  stb  %i1, [ %g1 + 0x38 ]
a00d3de8:  40 3a bc 97  call  0xa0f83044
a00d3dec:  90 12 20 80  or  %o0, 0x80, %o0
a00d3df0:  d2 0c 20 37  ldub  [ %l0 + 0x37 ], %o1
a00d3df4:  93 2a 60 10  sll  %o1, 0x10, %o1
a00d3df8:  11 34 00 4f  sethi  %hi(0xd0013c00), %o0
a00d3dfc:  90 12 23 fc  or  %o0, 0x3fc, %o0	! 0xd0013ffc
a00d3e00:  10 80 00 1c  b  0xa00d3e70
a00d3e04:  92 12 60 dd  or  %o1, 0xdd, %o1
a00d3e08:  c2 08 60 30  ldub  [ %g1 + 0x30 ], %g1
a00d3e0c:  80 88 60 01  btst  1, %g1
a00d3e10:  02 80 00 08  be  0xa00d3e30
a00d3e14:  80 88 60 02  btst  2, %g1
a00d3e18:  22 80 00 19  be,a   0xa00d3e7c
a00d3e1c:  03 2a 01 e3  sethi  %hi(0xa8078c00), %g1
a00d3e20:  7f ff fc f6  call  0xa00d31f8
a00d3e24:  01 00 00 00  nop
a00d3e28:  10 80 00 15  b  0xa00d3e7c
a00d3e2c:  03 2a 01 e3  sethi  %hi(0xa8078c00), %g1
a00d3e30:  7f ff fe 10  call  0xa00d3670
a00d3e34:  01 00 00 00  nop
a00d3e38:  80 8a 20 ff  btst  0xff, %o0
a00d3e3c:  02 80 00 10  be  0xa00d3e7c
a00d3e40:  03 2a 01 e3  sethi  %hi(0xa8078c00), %g1
a00d3e44:  7f ff fb b6  call  0xa00d2d1c
a00d3e48:  01 00 00 00  nop
a00d3e4c:  7f ff fb 7b  call  0xa00d2c38
a00d3e50:  01 00 00 00  nop
a00d3e54:  d2 0c 20 37  ldub  [ %l0 + 0x37 ], %o1
a00d3e58:  93 2a 60 10  sll  %o1, 0x10, %o1
a00d3e5c:  03 2a 01 e3  sethi  %hi(0xa8078c00), %g1
a00d3e60:  11 34 00 4f  sethi  %hi(0xd0013c00), %o0
a00d3e64:  c0 28 60 38  clrb  [ %g1 + 0x38 ]
a00d3e68:  90 12 23 fc  or  %o0, 0x3fc, %o0
a00d3e6c:  92 12 60 ff  or  %o1, 0xff, %o1
a00d3e70:  40 3a 75 b1  call  0xa0f71534
a00d3e74:  01 00 00 00  nop
a00d3e78:  03 2a 01 e3  sethi  %hi(0xa8078c00), %g1
a00d3e7c:  c2 08 60 33  ldub  [ %g1 + 0x33 ], %g1	! 0xa8078c33
a00d3e80:  80 a0 60 01  cmp  %g1, 1
a00d3e84:  12 80 00 04  bne  0xa00d3e94
a00d3e88:  01 00 00 00  nop
a00d3e8c:  7f ff fe 40  call  0xa00d378c
a00d3e90:  01 00 00 00  nop
a00d3e94:  7f ff fa a3  call  0xa00d2920
a00d3e98:  01 00 00 00  nop
a00d3e9c:  40 3a 77 10  call  0xa0f71adc
a00d3ea0:  81 e8 00 00  restore
a00d3ea4:  01 00 00 00  nop
a00d3ea8:  81 c7 e0 08  ret
a00d3eac:  81 e8 00 00  restore
