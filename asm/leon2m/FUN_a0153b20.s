# leon2m FUN_a0153b20 0xa0153b20-0xa0153c54 (308 bytes)
a0153b20:  9d e3 bf 18  save  %sp, -232, %sp
a0153b24:  a0 07 bf a8  add  %fp, -88, %l0
a0153b28:  03 00 00 80  sethi  %hi(0x20000), %g1
a0153b2c:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0153b30:  92 10 24 70  mov  0x470, %o1
a0153b34:  94 10 20 50  mov  0x50, %o2
a0153b38:  96 10 00 10  mov  %l0, %o3
a0153b3c:  90 10 20 00  clr  %o0
a0153b40:  82 10 60 00  mov  %g1, %g1
a0153b44:  80 a6 20 01  cmp  %i0, 1
a0153b48:  02 80 00 15  be  0xa0153b9c
a0153b4c:  98 10 20 00  clr  %o4
a0153b50:  7f ff b2 04  call  0xa0140360
a0153b54:  01 00 00 00  nop
a0153b58:  13 00 00 80  sethi  %hi(0x20000), %o1
a0153b5c:  90 12 60 00  mov  %o1, %o0	! 0x20000
a0153b60:  d4 12 21 b0  lduh  [ %o0 + 0x1b0 ], %o2
a0153b64:  d6 12 21 ae  lduh  [ %o0 + 0x1ae ], %o3
a0153b68:  da 12 21 a8  lduh  [ %o0 + 0x1a8 ], %o5
a0153b6c:  d8 0a 21 8a  ldub  [ %o0 + 0x18a ], %o4
a0153b70:  d6 37 bf e6  sth  %o3, [ %fp + -26 ]
a0153b74:  d4 37 bf e8  sth  %o2, [ %fp + -24 ]
a0153b78:  da 37 bf e0  sth  %o5, [ %fp + -32 ]
a0153b7c:  7f ff 64 a7  call  0xa012ce18
a0153b80:  d8 2f bf c2  stb  %o4, [ %fp + -62 ]
a0153b84:  d0 37 bf e4  sth  %o0, [ %fp + -28 ]
a0153b88:  96 10 00 10  mov  %l0, %o3
a0153b8c:  90 10 20 00  clr  %o0
a0153b90:  92 10 24 70  mov  0x470, %o1
a0153b94:  10 80 00 2b  b  0xa0153c40
a0153b98:  94 10 20 50  mov  0x50, %o2
a0153b9c:  d4 18 61 b8  ldd  [ %g1 + 0x1b8 ], %o2
a0153ba0:  d4 3f bf f0  std  %o2, [ %fp + -16 ]
a0153ba4:  d4 18 61 40  ldd  [ %g1 + 0x140 ], %o2
a0153ba8:  d4 3f bf 78  std  %o2, [ %fp + -136 ]
a0153bac:  d4 18 61 88  ldd  [ %g1 + 0x188 ], %o2
a0153bb0:  d4 3f bf c0  std  %o2, [ %fp + -64 ]
a0153bb4:  d4 18 61 90  ldd  [ %g1 + 0x190 ], %o2
a0153bb8:  d4 3f bf c8  std  %o2, [ %fp + -56 ]
a0153bbc:  d4 18 61 98  ldd  [ %g1 + 0x198 ], %o2
a0153bc0:  d4 3f bf d0  std  %o2, [ %fp + -48 ]
a0153bc4:  d4 18 61 a0  ldd  [ %g1 + 0x1a0 ], %o2
a0153bc8:  d4 3f bf d8  std  %o2, [ %fp + -40 ]
a0153bcc:  d4 18 61 a8  ldd  [ %g1 + 0x1a8 ], %o2
a0153bd0:  d4 3f bf e0  std  %o2, [ %fp + -32 ]
a0153bd4:  d0 18 61 48  ldd  [ %g1 + 0x148 ], %o0
a0153bd8:  d4 18 61 b0  ldd  [ %g1 + 0x1b0 ], %o2
a0153bdc:  d4 3f bf e8  std  %o2, [ %fp + -24 ]
a0153be0:  d0 3f bf 80  std  %o0, [ %fp + -128 ]
a0153be4:  e0 18 61 50  ldd  [ %g1 + 0x150 ], %l0
a0153be8:  e4 18 61 58  ldd  [ %g1 + 0x158 ], %l2
a0153bec:  e8 18 61 60  ldd  [ %g1 + 0x160 ], %l4
a0153bf0:  ec 18 61 68  ldd  [ %g1 + 0x168 ], %l6
a0153bf4:  f8 18 61 70  ldd  [ %g1 + 0x170 ], %i4
a0153bf8:  f4 18 61 78  ldd  [ %g1 + 0x178 ], %i2
a0153bfc:  f0 18 61 80  ldd  [ %g1 + 0x180 ], %i0
a0153c00:  96 07 bf 78  add  %fp, -136, %o3
a0153c04:  90 10 20 00  clr  %o0
a0153c08:  92 10 24 40  mov  0x440, %o1
a0153c0c:  94 10 20 30  mov  0x30, %o2
a0153c10:  e0 3f bf 88  std  %l0, [ %fp + -120 ]
a0153c14:  e4 3f bf 90  std  %l2, [ %fp + -112 ]
a0153c18:  e8 3f bf 98  std  %l4, [ %fp + -104 ]
a0153c1c:  ec 3f bf a0  std  %l6, [ %fp + -96 ]
a0153c20:  f8 3f bf a8  std  %i4, [ %fp + -88 ]
a0153c24:  f4 3f bf b0  std  %i2, [ %fp + -80 ]
a0153c28:  7f ff b4 93  call  0xa0140e74
a0153c2c:  f0 3f bf b8  std  %i0, [ %fp + -72 ]
a0153c30:  90 10 20 00  clr  %o0
a0153c34:  92 10 24 70  mov  0x470, %o1
a0153c38:  94 10 20 50  mov  0x50, %o2
a0153c3c:  96 07 bf a8  add  %fp, -88, %o3
a0153c40:  7f ff b4 8d  call  0xa0140e74
a0153c44:  98 10 20 01  mov  1, %o4
a0153c48:  01 00 00 00  nop
a0153c4c:  81 c7 e0 08  ret
a0153c50:  81 e8 00 00  restore
