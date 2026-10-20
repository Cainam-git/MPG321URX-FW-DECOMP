# leon2m FUN_a0149bf0 0xa0149bf0-0xa0149e8c (668 bytes)  [FUN_a0149db8 + 0xa0149e14..e8c = jump-table case bodies, merged]
a0149bf0:  9d e3 bf 98  save  %sp, -104, %sp
a0149bf4:  33 2a 00 b8  sethi  %hi(0xa802e000), %i1
a0149bf8:  90 16 61 a0  or  %i1, 0x1a0, %o0	! 0xa802e1a0
a0149bfc:  da 0a 20 07  ldub  [ %o0 + 7 ], %o5
a0149c00:  80 a0 00 0d  cmp  %g0, %o5
a0149c04:  82 60 3f ff  subx  %g0, -1, %g1
a0149c08:  80 a0 00 18  cmp  %g0, %i0
a0149c0c:  98 40 20 00  addx  %g0, 0, %o4
a0149c10:  80 88 40 0c  btst  %g1, %o4
a0149c14:  12 80 00 25  bne  0xa0149ca8
a0149c18:  80 a3 60 02  cmp  %o5, 2
a0149c1c:  02 80 00 1e  be  0xa0149c94
a0149c20:  92 1e 20 02  xor  %i0, 2, %o1
a0149c24:  9e 06 3f fb  add  %i0, -5, %o7
a0149c28:  80 a3 e0 02  cmp  %o7, 2
a0149c2c:  08 80 00 2c  bleu  0xa0149cdc
a0149c30:  90 10 20 00  clr  %o0
a0149c34:  a0 16 61 a0  or  %i1, 0x1a0, %l0
a0149c38:  c2 0c 20 07  ldub  [ %l0 + 7 ], %g1
a0149c3c:  80 a0 40 18  cmp  %g1, %i0
a0149c40:  02 80 00 07  be  0xa0149c5c
a0149c44:  17 2a 00 b7  sethi  %hi(0xa802dc00), %o3
a0149c48:  90 12 e3 30  or  %o3, 0x330, %o0	! 0xa802df30
a0149c4c:  d4 02 20 40  ld  [ %o0 + 0x40 ], %o2
a0149c50:  13 10 00 00  sethi  %hi(0x40000000), %o1
a0149c54:  9a 2a 80 09  andn  %o2, %o1, %o5
a0149c58:  da 22 20 40  st  %o5, [ %o0 + 0x40 ]
a0149c5c:  19 00 06 9b  sethi  %hi(0x1a6c00), %o4
a0149c60:  f0 2c 20 07  stb  %i0, [ %l0 + 7 ]
a0149c64:  90 13 23 d8  or  %o4, 0x3d8, %o0
a0149c68:  7f fe 55 42  call  0xa00df170
a0149c6c:  92 10 00 18  mov  %i0, %o1
a0149c70:  c2 0c 20 07  ldub  [ %l0 + 7 ], %g1
a0149c74:  80 a0 60 07  cmp  %g1, 7
a0149c78:  18 80 00 36  bgu  0xa0149d50
a0149c7c:  b1 28 60 02  sll  %g1, 2, %i0
a0149c80:  11 00 03 8d  sethi  %hi(0xe3400), %o0
a0149c84:  9e 12 20 b4  or  %o0, 0xb4, %o7	! 0xe34b4
a0149c88:  e0 03 c0 18  ld  [ %o7 + %i0 ], %l0
a0149c8c:  81 c4 00 00  jmp  %l0
a0149c90:  01 00 00 00  nop
a0149c94:  80 a0 00 09  cmp  %g0, %o1
a0149c98:  9a 40 20 00  addx  %g0, 0, %o5
a0149c9c:  80 8b 40 0c  btst  %o5, %o4
a0149ca0:  02 bf ff e2  be  0xa0149c28
a0149ca4:  9e 06 3f fb  add  %i0, -5, %o7
a0149ca8:  19 2a 00 b8  sethi  %hi(0xa802e000), %o4
a0149cac:  d6 0b 23 d3  ldub  [ %o4 + 0x3d3 ], %o3	! 0xa802e3d3
a0149cb0:  15 2a 00 b8  sethi  %hi(0xa802e000), %o2
a0149cb4:  80 a0 00 0b  cmp  %g0, %o3
a0149cb8:  d2 12 a3 ca  lduh  [ %o2 + 0x3ca ], %o1
a0149cbc:  90 40 20 00  addx  %g0, 0, %o0
a0149cc0:  7f fe f8 61  call  0xa0107e44
a0149cc4:  94 10 20 01  mov  1, %o2
a0149cc8:  9e 06 3f fb  add  %i0, -5, %o7
a0149ccc:  80 a3 e0 02  cmp  %o7, 2
a0149cd0:  38 bf ff da  bgu,a   0xa0149c38
a0149cd4:  a0 16 61 a0  or  %i1, 0x1a0, %l0
a0149cd8:  90 10 20 00  clr  %o0
a0149cdc:  7f fe f9 f3  call  0xa01084a8
a0149ce0:  92 10 20 01  mov  1, %o1
a0149ce4:  7f fe fd 0b  call  0xa0109110
a0149ce8:  90 10 20 01  mov  1, %o0
a0149cec:  10 bf ff d3  b  0xa0149c38
a0149cf0:  a0 16 61 a0  or  %i1, 0x1a0, %l0
a0149cf4:  21 2a 00 b7  sethi  %hi(0xa802dc00), %l0
a0149cf8:  c2 04 23 30  ld  [ %l0 + 0x330 ], %g1	! 0xa802df30
a0149cfc:  91 30 60 0c  srl  %g1, 0xc, %o0
a0149d00:  90 0a 20 0f  and  %o0, 0xf, %o0
a0149d04:  7f fe e0 48  call  0xa0101e24
a0149d08:  92 10 20 01  mov  1, %o1
a0149d0c:  a0 14 23 30  or  %l0, 0x330, %l0
a0149d10:  de 04 20 78  ld  [ %l0 + 0x78 ], %o7
a0149d14:  b1 33 e0 0c  srl  %o7, 0xc, %i0
a0149d18:  90 0e 20 0f  and  %i0, 0xf, %o0
a0149d1c:  7f fe e0 42  call  0xa0101e24
a0149d20:  92 10 20 01  mov  1, %o1
a0149d24:  d8 04 20 f0  ld  [ %l0 + 0xf0 ], %o4
a0149d28:  97 33 20 0c  srl  %o4, 0xc, %o3
a0149d2c:  90 0a e0 0f  and  %o3, 0xf, %o0
a0149d30:  92 10 20 01  mov  1, %o1
a0149d34:  7f fe e0 3c  call  0xa0101e24
a0149d38:  01 00 00 00  nop
a0149d3c:  d4 04 21 68  ld  [ %l0 + 0x168 ], %o2
a0149d40:  93 32 a0 0c  srl  %o2, 0xc, %o1
a0149d44:  90 0a 60 0f  and  %o1, 0xf, %o0
a0149d48:  7f fe e0 37  call  0xa0101e24
a0149d4c:  92 10 20 00  clr  %o1
a0149d50:  7f fe e6 c3  call  0xa010385c
a0149d54:  90 10 20 01  mov  1, %o0
a0149d58:  90 10 20 00  clr  %o0
a0149d5c:  7f ff 95 24  call  0xa012f1ec
a0149d60:  92 10 20 02  mov  2, %o1
a0149d64:  90 10 20 01  mov  1, %o0
a0149d68:  7f ff 95 21  call  0xa012f1ec
a0149d6c:  92 10 20 02  mov  2, %o1
a0149d70:  90 10 20 02  mov  2, %o0
a0149d74:  7f ff 95 1e  call  0xa012f1ec
a0149d78:  92 10 20 02  mov  2, %o1
a0149d7c:  90 10 20 03  mov  3, %o0
a0149d80:  7f ff 95 1b  call  0xa012f1ec
a0149d84:  92 10 20 02  mov  2, %o1
a0149d88:  7f ff 9d 45  call  0xa013129c
a0149d8c:  01 00 00 00  nop
a0149d90:  92 16 61 a0  or  %i1, 0x1a0, %o1
a0149d94:  da 0a 60 07  ldub  [ %o1 + 7 ], %o5
a0149d98:  80 a3 60 00  cmp  %o5, 0
a0149d9c:  02 80 00 03  be  0xa0149da8
a0149da0:  90 10 20 02  mov  2, %o0
a0149da4:  90 10 20 03  mov  3, %o0
a0149da8:  7f ff 3a 20  call  0xa0118628
a0149dac:  b0 16 61 a0  or  %i1, 0x1a0, %i0
a0149db0:  40 00 26 f0  call  0xa0153970
a0149db4:  93 e8 20 00  restore  %g0, 0, %o1
a0149db8:  21 2a 00 b7  sethi  %hi(0xa802dc00), %l0
a0149dbc:  c2 04 23 30  ld  [ %l0 + 0x330 ], %g1	! 0xa802df30
a0149dc0:  91 30 60 0c  srl  %g1, 0xc, %o0
a0149dc4:  90 0a 20 0f  and  %o0, 0xf, %o0
a0149dc8:  7f fe e0 17  call  0xa0101e24
a0149dcc:  92 10 20 01  mov  1, %o1
a0149dd0:  b0 14 23 30  or  %l0, 0x330, %i0
a0149dd4:  de 06 20 78  ld  [ %i0 + 0x78 ], %o7
a0149dd8:  99 33 e0 0c  srl  %o7, 0xc, %o4
a0149ddc:  90 0b 20 0f  and  %o4, 0xf, %o0
a0149de0:  7f fe e0 11  call  0xa0101e24
a0149de4:  92 10 20 01  mov  1, %o1
a0149de8:  d6 06 20 f0  ld  [ %i0 + 0xf0 ], %o3
a0149dec:  95 32 e0 0c  srl  %o3, 0xc, %o2
a0149df0:  90 0a a0 0f  and  %o2, 0xf, %o0
a0149df4:  7f fe e0 0c  call  0xa0101e24
a0149df8:  92 10 20 01  mov  1, %o1
a0149dfc:  d2 06 21 68  ld  [ %i0 + 0x168 ], %o1
a0149e00:  9b 32 60 0c  srl  %o1, 0xc, %o5
a0149e04:  90 0b 60 0f  and  %o5, 0xf, %o0
a0149e08:  7f fe e0 07  call  0xa0101e24
a0149e0c:  92 10 20 01  mov  1, %o1
a0149e10:  30 bf ff d0  b,a   0xa0149d50
a0149e14:  21 2a 00 b7  sethi  %hi(0xa802dc00), %l0
a0149e18:  d0 04 23 30  ld  [ %l0 + 0x330 ], %o0	! 0xa802df30
a0149e1c:  9f 32 20 0c  srl  %o0, 0xc, %o7
a0149e20:  90 0b e0 0f  and  %o7, 0xf, %o0
a0149e24:  7f fe e0 00  call  0xa0101e24
a0149e28:  92 10 20 01  mov  1, %o1
a0149e2c:  a0 14 23 30  or  %l0, 0x330, %l0
a0149e30:  f0 04 20 78  ld  [ %l0 + 0x78 ], %i0
a0149e34:  99 36 20 0c  srl  %i0, 0xc, %o4
a0149e38:  90 0b 20 0f  and  %o4, 0xf, %o0
a0149e3c:  92 10 20 01  mov  1, %o1
a0149e40:  7f fe df f9  call  0xa0101e24
a0149e44:  01 00 00 00  nop
a0149e48:  da 04 20 f0  ld  [ %l0 + 0xf0 ], %o5
a0149e4c:  83 33 60 0c  srl  %o5, 0xc, %g1
a0149e50:  90 08 60 0f  and  %g1, 0xf, %o0
a0149e54:  10 bf ff b8  b  0xa0149d34
a0149e58:  92 10 20 00  clr  %o1
a0149e5c:  13 2a 00 b7  sethi  %hi(0xa802dc00), %o1
a0149e60:  d6 02 63 30  ld  [ %o1 + 0x330 ], %o3	! 0xa802df30
a0149e64:  95 32 e0 0c  srl  %o3, 0xc, %o2
a0149e68:  a0 12 63 30  or  %o1, 0x330, %l0
a0149e6c:  90 0a a0 0f  and  %o2, 0xf, %o0
a0149e70:  7f fe df ed  call  0xa0101e24
a0149e74:  92 10 20 01  mov  1, %o1
a0149e78:  da 04 20 78  ld  [ %l0 + 0x78 ], %o5
a0149e7c:  83 33 60 0c  srl  %o5, 0xc, %g1
a0149e80:  90 08 60 0f  and  %g1, 0xf, %o0
a0149e84:  10 bf ff ef  b  0xa0149e40
a0149e88:  92 10 20 00  clr  %o1
