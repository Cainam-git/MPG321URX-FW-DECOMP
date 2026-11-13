# leon2s DRV_HDMI_ModeDetect_FSM_FRL_Init 0xa0096b08-0xa0096f60 (1112 bytes)
a0096b08:  9d e3 bf 98  save  %sp, -104, %sp
a0096b0c:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a0096b10:  c2 00 62 34  ld  [ %g1 + 0x234 ], %g1	! 0xa8078634
a0096b14:  80 88 60 04  btst  4, %g1
a0096b18:  02 80 00 08  be  0xa0096b38
a0096b1c:  a0 10 00 18  mov  %i0, %l0
a0096b20:  92 06 20 41  add  %i0, 0x41, %o1
a0096b24:  93 2a 60 18  sll  %o1, 0x18, %o1
a0096b28:  11 28 01 a5  sethi  %hi(0xa0069400), %o0
a0096b2c:  90 12 23 f8  or  %o0, 0x3f8, %o0	! 0xa00697f8
a0096b30:  7f ff 71 45  call  0xa0073044
a0096b34:  93 3a 60 18  sra  %o1, 0x18, %o1
a0096b38:  b0 0c 20 ff  and  %l0, 0xff, %i0
a0096b3c:  1b 2a 01 f5  sethi  %hi(0xa807d400), %o5
a0096b40:  83 2e 20 02  sll  %i0, 2, %g1
a0096b44:  9a 13 62 48  or  %o5, 0x248, %o5
a0096b48:  c2 03 40 01  ld  [ %o5 + %g1 ], %g1
a0096b4c:  80 a0 60 09  cmp  %g1, 9
a0096b50:  02 80 00 07  be  0xa0096b6c
a0096b54:  9a 06 00 18  add  %i0, %i0, %o5
a0096b58:  9a 03 40 18  add  %o5, %i0, %o5
a0096b5c:  03 2a 01 f5  sethi  %hi(0xa807d400), %g1
a0096b60:  9b 2b 60 03  sll  %o5, 3, %o5
a0096b64:  82 10 62 50  or  %g1, 0x250, %g1
a0096b68:  c0 20 40 0d  clr  [ %g1 + %o5 ]
a0096b6c:  27 2a 01 f6  sethi  %hi(0xa807d800), %l3
a0096b70:  a2 14 e3 00  or  %l3, 0x300, %l1	! 0xa807db00
a0096b74:  a0 5e 20 34  smul  %i0, 0x34, %l0
a0096b78:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a0096b7c:  82 10 60 a8  or  %g1, 0xa8, %g1	! 0xa80790a8
a0096b80:  d2 04 40 10  ld  [ %l1 + %l0 ], %o1
a0096b84:  c0 28 40 18  clrb  [ %g1 + %i0 ]
a0096b88:  92 02 60 08  add  %o1, 8, %o1
a0096b8c:  40 00 42 12  call  0xa00a73d4
a0096b90:  90 10 20 0c  mov  0xc, %o0
a0096b94:  d2 04 40 10  ld  [ %l1 + %l0 ], %o1
a0096b98:  92 02 60 08  add  %o1, 8, %o1
a0096b9c:  40 00 42 04  call  0xa00a73ac
a0096ba0:  90 10 20 0d  mov  0xd, %o0
a0096ba4:  d2 04 40 10  ld  [ %l1 + %l0 ], %o1
a0096ba8:  92 02 60 08  add  %o1, 8, %o1
a0096bac:  40 00 42 0a  call  0xa00a73d4
a0096bb0:  90 10 20 0f  mov  0xf, %o0
a0096bb4:  d2 04 40 10  ld  [ %l1 + %l0 ], %o1
a0096bb8:  92 02 60 84  add  %o1, 0x84, %o1
a0096bbc:  40 00 42 06  call  0xa00a73d4
a0096bc0:  90 10 20 14  mov  0x14, %o0
a0096bc4:  03 2a 01 f5  sethi  %hi(0xa807d400), %g1
a0096bc8:  82 10 62 80  or  %g1, 0x280, %g1	! 0xa807d680
a0096bcc:  9a 5e 20 b0  smul  %i0, 0xb0, %o5
a0096bd0:  9a 03 40 01  add  %o5, %g1, %o5
a0096bd4:  da 0b 60 01  ldub  [ %o5 + 1 ], %o5
a0096bd8:  82 03 7f ff  add  %o5, -1, %g1
a0096bdc:  82 08 60 ff  and  %g1, 0xff, %g1
a0096be0:  80 a0 60 02  cmp  %g1, 2
a0096be4:  98 60 20 00  subx  %g0, 0, %o4
a0096be8:  9a 1b 60 0a  xor  %o5, 0xa, %o5
a0096bec:  80 a0 00 0d  cmp  %g0, %o5
a0096bf0:  98 0b 20 01  and  %o4, 1, %o4
a0096bf4:  82 60 3f ff  subx  %g0, -1, %g1
a0096bf8:  80 93 00 01  orcc  %o4, %g1, %g0
a0096bfc:  02 80 00 07  be  0xa0096c18
a0096c00:  a0 04 00 11  add  %l0, %l1, %l0
a0096c04:  d2 04 20 18  ld  [ %l0 + 0x18 ], %o1
a0096c08:  40 00 41 f3  call  0xa00a73d4
a0096c0c:  90 10 20 08  mov  8, %o0
a0096c10:  10 80 00 06  b  0xa0096c28
a0096c14:  a2 14 e3 00  or  %l3, 0x300, %l1
a0096c18:  d2 04 20 18  ld  [ %l0 + 0x18 ], %o1
a0096c1c:  40 00 41 e4  call  0xa00a73ac
a0096c20:  90 10 20 08  mov  8, %o0
a0096c24:  a2 14 e3 00  or  %l3, 0x300, %l1
a0096c28:  a0 5e 20 34  smul  %i0, 0x34, %l0
a0096c2c:  a4 04 00 11  add  %l0, %l1, %l2
a0096c30:  90 10 20 0d  mov  0xd, %o0
a0096c34:  40 00 41 de  call  0xa00a73ac
a0096c38:  d2 04 a0 18  ld  [ %l2 + 0x18 ], %o1
a0096c3c:  90 10 20 0c  mov  0xc, %o0
a0096c40:  40 00 41 db  call  0xa00a73ac
a0096c44:  d2 04 a0 18  ld  [ %l2 + 0x18 ], %o1
a0096c48:  d8 04 a0 18  ld  [ %l2 + 0x18 ], %o4
a0096c4c:  03 00 00 3f  sethi  %hi(0xfc00), %g1
a0096c50:  da 03 20 04  ld  [ %o4 + 4 ], %o5
a0096c54:  82 10 63 ff  or  %g1, 0x3ff, %g1
a0096c58:  9a 0b 40 01  and  %o5, %g1, %o5
a0096c5c:  03 0d 00 00  sethi  %hi(0x34000000), %g1
a0096c60:  9a 13 40 01  or  %o5, %g1, %o5
a0096c64:  d2 04 40 10  ld  [ %l1 + %l0 ], %o1
a0096c68:  da 23 20 04  st  %o5, [ %o4 + 4 ]
a0096c6c:  92 02 60 08  add  %o1, 8, %o1
a0096c70:  40 00 41 cf  call  0xa00a73ac
a0096c74:  90 10 20 0b  mov  0xb, %o0
a0096c78:  d2 04 a0 18  ld  [ %l2 + 0x18 ], %o1
a0096c7c:  92 02 60 0c  add  %o1, 0xc, %o1
a0096c80:  40 00 41 d5  call  0xa00a73d4
a0096c84:  90 10 20 01  mov  1, %o0
a0096c88:  d2 04 a0 18  ld  [ %l2 + 0x18 ], %o1
a0096c8c:  92 02 60 0c  add  %o1, 0xc, %o1
a0096c90:  40 00 41 c7  call  0xa00a73ac
a0096c94:  90 10 20 03  mov  3, %o0
a0096c98:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a0096c9c:  82 10 60 48  or  %g1, 0x48, %g1	! 0xa8079048
a0096ca0:  c2 08 40 18  ldub  [ %g1 + %i0 ], %g1
a0096ca4:  80 a0 60 01  cmp  %g1, 1
a0096ca8:  32 80 00 0e  bne,a   0xa0096ce0
a0096cac:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a0096cb0:  da 04 a0 18  ld  [ %l2 + 0x18 ], %o5
a0096cb4:  c2 03 60 14  ld  [ %o5 + 0x14 ], %g1
a0096cb8:  82 10 60 07  or  %g1, 7, %g1
a0096cbc:  c2 23 60 14  st  %g1, [ %o5 + 0x14 ]
a0096cc0:  c2 03 60 14  ld  [ %o5 + 0x14 ], %g1
a0096cc4:  82 10 60 70  or  %g1, 0x70, %g1
a0096cc8:  11 28 01 a6  sethi  %hi(0xa0069800), %o0
a0096ccc:  c2 23 60 14  st  %g1, [ %o5 + 0x14 ]
a0096cd0:  7f ff 71 fd  call  0xa00734c4
a0096cd4:  90 12 20 48  or  %o0, 0x48, %o0
a0096cd8:  10 80 00 18  b  0xa0096d38
a0096cdc:  82 14 e3 00  or  %l3, 0x300, %g1
a0096ce0:  82 10 60 40  or  %g1, 0x40, %g1
a0096ce4:  c2 08 40 18  ldub  [ %g1 + %i0 ], %g1
a0096ce8:  80 a0 60 01  cmp  %g1, 1
a0096cec:  12 80 00 0a  bne  0xa0096d14
a0096cf0:  e0 04 a0 18  ld  [ %l2 + 0x18 ], %l0
a0096cf4:  c2 04 20 14  ld  [ %l0 + 0x14 ], %g1
a0096cf8:  82 08 7f f8  and  %g1, -8, %g1
a0096cfc:  82 10 60 02  or  %g1, 2, %g1
a0096d00:  c2 24 20 14  st  %g1, [ %l0 + 0x14 ]
a0096d04:  c2 04 20 14  ld  [ %l0 + 0x14 ], %g1
a0096d08:  82 08 7f 8f  and  %g1, -113, %g1
a0096d0c:  10 80 00 09  b  0xa0096d30
a0096d10:  82 10 60 20  or  %g1, 0x20, %g1
a0096d14:  c2 04 20 14  ld  [ %l0 + 0x14 ], %g1
a0096d18:  82 08 7f f8  and  %g1, -8, %g1
a0096d1c:  82 10 60 03  or  %g1, 3, %g1
a0096d20:  c2 24 20 14  st  %g1, [ %l0 + 0x14 ]
a0096d24:  c2 04 20 14  ld  [ %l0 + 0x14 ], %g1
a0096d28:  82 08 7f 8f  and  %g1, -113, %g1
a0096d2c:  82 10 60 30  or  %g1, 0x30, %g1
a0096d30:  c2 24 20 14  st  %g1, [ %l0 + 0x14 ]
a0096d34:  82 14 e3 00  or  %l3, 0x300, %g1
a0096d38:  a2 5e 20 34  smul  %i0, 0x34, %l1
a0096d3c:  a2 04 40 01  add  %l1, %g1, %l1
a0096d40:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a0096d44:  82 10 60 48  or  %g1, 0x48, %g1	! 0xa8079048
a0096d48:  c0 28 40 18  clrb  [ %g1 + %i0 ]
a0096d4c:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a0096d50:  82 10 60 40  or  %g1, 0x40, %g1	! 0xa8079040
a0096d54:  c0 28 40 18  clrb  [ %g1 + %i0 ]
a0096d58:  d2 04 60 18  ld  [ %l1 + 0x18 ], %o1
a0096d5c:  19 3f 80 3f  sethi  %hi(0xfe00fc00), %o4
a0096d60:  98 13 23 ff  or  %o4, 0x3ff, %o4	! 0xfe00ffff
a0096d64:  c2 02 60 0c  ld  [ %o1 + 0xc ], %g1
a0096d68:  82 08 40 0c  and  %g1, %o4, %g1
a0096d6c:  1b 00 08 00  sethi  %hi(0x200000), %o5
a0096d70:  82 10 40 0d  or  %g1, %o5, %g1
a0096d74:  c2 22 60 0c  st  %g1, [ %o1 + 0xc ]
a0096d78:  c2 02 60 10  ld  [ %o1 + 0x10 ], %g1
a0096d7c:  82 08 7e 00  and  %g1, -512, %g1
a0096d80:  82 10 60 20  or  %g1, 0x20, %g1
a0096d84:  c2 22 60 10  st  %g1, [ %o1 + 0x10 ]
a0096d88:  c2 02 60 14  ld  [ %o1 + 0x14 ], %g1
a0096d8c:  82 08 40 0c  and  %g1, %o4, %g1
a0096d90:  1b 00 00 40  sethi  %hi(0x10000), %o5
a0096d94:  82 10 40 0d  or  %g1, %o5, %g1
a0096d98:  c2 22 60 14  st  %g1, [ %o1 + 0x14 ]
a0096d9c:  40 00 41 84  call  0xa00a73ac
a0096da0:  90 10 20 0e  mov  0xe, %o0
a0096da4:  d2 04 60 18  ld  [ %l1 + 0x18 ], %o1
a0096da8:  25 00 3f ff  sethi  %hi(0xfffc00), %l2
a0096dac:  c2 02 60 44  ld  [ %o1 + 0x44 ], %g1
a0096db0:  a4 14 a3 ff  or  %l2, 0x3ff, %l2
a0096db4:  1b 2e 00 00  sethi  %hi(0xb8000000), %o5
a0096db8:  82 08 40 12  and  %g1, %l2, %g1
a0096dbc:  82 10 40 0d  or  %g1, %o5, %g1
a0096dc0:  c2 22 60 44  st  %g1, [ %o1 + 0x44 ]
a0096dc4:  c2 02 60 48  ld  [ %o1 + 0x48 ], %g1
a0096dc8:  82 08 7f 00  and  %g1, -256, %g1
a0096dcc:  c2 22 60 48  st  %g1, [ %o1 + 0x48 ]
a0096dd0:  21 3f ff e0  sethi  %hi(0xffff8000), %l0
a0096dd4:  c2 02 60 10  ld  [ %o1 + 0x10 ], %g1
a0096dd8:  a0 14 21 ff  or  %l0, 0x1ff, %l0
a0096ddc:  82 08 40 10  and  %g1, %l0, %g1
a0096de0:  82 10 64 00  or  %g1, 0x400, %g1
a0096de4:  c2 22 60 10  st  %g1, [ %o1 + 0x10 ]
a0096de8:  c2 02 60 4c  ld  [ %o1 + 0x4c ], %g1
a0096dec:  1b 3f ff c0  sethi  %hi(0xffff0000), %o5
a0096df0:  82 08 40 0d  and  %g1, %o5, %g1
a0096df4:  82 10 61 00  or  %g1, 0x100, %g1
a0096df8:  c2 22 60 4c  st  %g1, [ %o1 + 0x4c ]
a0096dfc:  92 02 60 48  add  %o1, 0x48, %o1
a0096e00:  40 00 41 6b  call  0xa00a73ac
a0096e04:  90 10 20 08  mov  8, %o0
a0096e08:  d2 04 60 18  ld  [ %l1 + 0x18 ], %o1
a0096e0c:  c2 02 60 4c  ld  [ %o1 + 0x4c ], %g1
a0096e10:  1b 00 c0 00  sethi  %hi(0x3000000), %o5
a0096e14:  82 08 40 12  and  %g1, %l2, %g1
a0096e18:  82 10 40 0d  or  %g1, %o5, %g1
a0096e1c:  c2 22 60 4c  st  %g1, [ %o1 + 0x4c ]
a0096e20:  c2 02 60 10  ld  [ %o1 + 0x10 ], %g1
a0096e24:  82 08 7e 00  and  %g1, -512, %g1
a0096e28:  82 10 60 04  or  %g1, 4, %g1
a0096e2c:  c2 22 60 10  st  %g1, [ %o1 + 0x10 ]
a0096e30:  c2 02 60 10  ld  [ %o1 + 0x10 ], %g1
a0096e34:  82 08 40 10  and  %g1, %l0, %g1
a0096e38:  82 10 6a 00  or  %g1, 0xa00, %g1
a0096e3c:  c2 22 60 10  st  %g1, [ %o1 + 0x10 ]
a0096e40:  da 02 60 10  ld  [ %o1 + 0x10 ], %o5
a0096e44:  03 00 1f c0  sethi  %hi(0x7f0000), %g1
a0096e48:  82 2b 40 01  andn  %o5, %g1, %g1
a0096e4c:  1b 00 01 c0  sethi  %hi(0x70000), %o5
a0096e50:  82 10 40 0d  or  %g1, %o5, %g1
a0096e54:  c2 22 60 10  st  %g1, [ %o1 + 0x10 ]
a0096e58:  da 02 60 10  ld  [ %o1 + 0x10 ], %o5
a0096e5c:  03 1f c0 00  sethi  %hi(0x7f000000), %g1
a0096e60:  82 2b 40 01  andn  %o5, %g1, %g1
a0096e64:  1b 01 40 00  sethi  %hi(0x5000000), %o5
a0096e68:  82 10 40 0d  or  %g1, %o5, %g1
a0096e6c:  c2 22 60 10  st  %g1, [ %o1 + 0x10 ]
a0096e70:  c2 02 60 18  ld  [ %o1 + 0x18 ], %g1
a0096e74:  82 08 7f f0  and  %g1, -16, %g1
a0096e78:  82 10 60 03  or  %g1, 3, %g1
a0096e7c:  c2 22 60 18  st  %g1, [ %o1 + 0x18 ]
a0096e80:  03 3f c0 00  sethi  %hi(0xff000000), %g1
a0096e84:  da 02 60 40  ld  [ %o1 + 0x40 ], %o5
a0096e88:  82 10 60 ff  or  %g1, 0xff, %g1
a0096e8c:  9a 0b 40 01  and  %o5, %g1, %o5
a0096e90:  03 00 02 00  sethi  %hi(0x80000), %g1
a0096e94:  9a 13 40 01  or  %o5, %g1, %o5
a0096e98:  da 22 60 40  st  %o5, [ %o1 + 0x40 ]
a0096e9c:  92 02 60 6c  add  %o1, 0x6c, %o1
a0096ea0:  40 00 41 4d  call  0xa00a73d4
a0096ea4:  90 10 20 08  mov  8, %o0
a0096ea8:  d2 04 60 18  ld  [ %l1 + 0x18 ], %o1
a0096eac:  92 02 60 14  add  %o1, 0x14, %o1
a0096eb0:  40 00 41 3f  call  0xa00a73ac
a0096eb4:  90 10 20 1d  mov  0x1d, %o0
a0096eb8:  40 00 69 d5  call  0xa00b160c
a0096ebc:  90 10 20 01  mov  1, %o0
a0096ec0:  d2 04 60 18  ld  [ %l1 + 0x18 ], %o1
a0096ec4:  92 02 60 14  add  %o1, 0x14, %o1
a0096ec8:  40 00 41 43  call  0xa00a73d4
a0096ecc:  90 10 20 1d  mov  0x1d, %o0
a0096ed0:  d8 04 60 0c  ld  [ %l1 + 0xc ], %o4
a0096ed4:  da 03 20 64  ld  [ %o4 + 0x64 ], %o5
a0096ed8:  03 00 3f c0  sethi  %hi(0xff0000), %g1
a0096edc:  82 2b 40 01  andn  %o5, %g1, %g1
a0096ee0:  1b 00 3f c0  sethi  %hi(0xff0000), %o5
a0096ee4:  82 10 40 0d  or  %g1, %o5, %g1
a0096ee8:  c2 23 20 64  st  %g1, [ %o4 + 0x64 ]
a0096eec:  d8 04 60 18  ld  [ %l1 + 0x18 ], %o4
a0096ef0:  03 00 00 04  sethi  %hi(0x1000), %g1
a0096ef4:  c2 23 20 50  st  %g1, [ %o4 + 0x50 ]
a0096ef8:  c2 03 20 40  ld  [ %o4 + 0x40 ], %g1
a0096efc:  82 08 40 12  and  %g1, %l2, %g1
a0096f00:  c2 23 20 40  st  %g1, [ %o4 + 0x40 ]
a0096f04:  c2 03 20 44  ld  [ %o4 + 0x44 ], %g1
a0096f08:  82 08 7f 00  and  %g1, -256, %g1
a0096f0c:  82 10 60 60  or  %g1, 0x60, %g1
a0096f10:  c2 23 20 44  st  %g1, [ %o4 + 0x44 ]
a0096f14:  9a 06 00 18  add  %i0, %i0, %o5
a0096f18:  9a 03 40 18  add  %o5, %i0, %o5
a0096f1c:  03 2a 01 f5  sethi  %hi(0xa807d400), %g1
a0096f20:  82 10 62 50  or  %g1, 0x250, %g1	! 0xa807d650
a0096f24:  9b 2b 60 03  sll  %o5, 3, %o5
a0096f28:  98 10 20 02  mov  2, %o4
a0096f2c:  d8 20 40 0d  st  %o4, [ %g1 + %o5 ]
a0096f30:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a0096f34:  97 2e 20 02  sll  %i0, 2, %o3
a0096f38:  82 10 60 94  or  %g1, 0x94, %g1
a0096f3c:  c0 20 40 0b  clr  [ %g1 + %o3 ]
a0096f40:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a0096f44:  82 10 60 9c  or  %g1, 0x9c, %g1	! 0xa807909c
a0096f48:  c0 20 40 0b  clr  [ %g1 + %o3 ]
a0096f4c:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a0096f50:  82 10 60 90  or  %g1, 0x90, %g1	! 0xa8079090
a0096f54:  c0 28 40 18  clrb  [ %g1 + %i0 ]
a0096f58:  81 c7 e0 08  ret
a0096f5c:  91 e8 20 00  restore  %g0, 0, %o0
