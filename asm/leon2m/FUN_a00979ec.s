# leon2m FUN_a00979ec 0xa00979ec-0xa0097ad0 (228 bytes)
a00979ec:  9d e3 bf 98  save  %sp, -104, %sp
a00979f0:  25 2a 00 97  sethi  %hi(0xa8025c00), %l2
a00979f4:  40 00 45 3d  call  0xa00a8ee8
a00979f8:  d0 0c a0 56  ldub  [ %l2 + 0x56 ], %o0	! 0xa8025c56
a00979fc:  90 10 20 00  clr  %o0
a0097a00:  d2 0c a0 56  ldub  [ %l2 + 0x56 ], %o1
a0097a04:  40 00 41 ce  call  0xa00a813c
a0097a08:  94 10 20 00  clr  %o2
a0097a0c:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a0097a10:  a2 13 e2 90  or  %o7, 0x290, %l1	! 0xa802d290
a0097a14:  94 10 20 00  clr  %o2
a0097a18:  90 10 20 00  clr  %o0
a0097a1c:  40 00 41 c8  call  0xa00a813c
a0097a20:  d2 0c 60 1f  ldub  [ %l1 + 0x1f ], %o1
a0097a24:  21 2a 00 ab  sethi  %hi(0xa802ac00), %l0
a0097a28:  d8 04 23 ec  ld  [ %l0 + 0x3ec ], %o4	! 0xa802afec
a0097a2c:  96 03 3f dd  add  %o4, -35, %o3
a0097a30:  90 0a e0 ff  and  %o3, 0xff, %o0
a0097a34:  40 00 45 76  call  0xa00a900c
a0097a38:  92 10 20 02  mov  2, %o1
a0097a3c:  7f ff fe b3  call  0xa0097508
a0097a40:  01 00 00 00  nop
a0097a44:  7f ff ff 2d  call  0xa00976f8
a0097a48:  01 00 00 00  nop
a0097a4c:  d2 0c 60 2f  ldub  [ %l1 + 0x2f ], %o1
a0097a50:  94 02 60 7f  add  %o1, 0x7f, %o2
a0097a54:  d4 24 23 ec  st  %o2, [ %l0 + 0x3ec ]
a0097a58:  94 10 20 00  clr  %o2
a0097a5c:  40 00 41 b8  call  0xa00a813c
a0097a60:  90 10 20 01  mov  1, %o0
a0097a64:  d2 04 23 ec  ld  [ %l0 + 0x3ec ], %o1
a0097a68:  90 02 7f 81  add  %o1, -127, %o0
a0097a6c:  90 0a 20 ff  and  %o0, 0xff, %o0
a0097a70:  40 00 46 f8  call  0xa00a9650
a0097a74:  92 10 20 01  mov  1, %o1
a0097a78:  d4 0c 60 1f  ldub  [ %l1 + 0x1f ], %o2
a0097a7c:  9a 0a a0 ff  and  %o2, 0xff, %o5
a0097a80:  c2 0c a0 56  ldub  [ %l2 + 0x56 ], %g1
a0097a84:  80 a3 40 01  cmp  %o5, %g1
a0097a88:  22 80 00 06  be,a   0xa0097aa0
a0097a8c:  da 0c 60 2f  ldub  [ %l1 + 0x2f ], %o5
a0097a90:  40 00 55 19  call  0xa00acef4
a0097a94:  01 00 00 00  nop
a0097a98:  d4 0c 60 1f  ldub  [ %l1 + 0x1f ], %o2
a0097a9c:  da 0c 60 2f  ldub  [ %l1 + 0x2f ], %o5
a0097aa0:  d2 0c 61 a4  ldub  [ %l1 + 0x1a4 ], %o1
a0097aa4:  d4 2c a0 56  stb  %o2, [ %l2 + 0x56 ]
a0097aa8:  11 2a 00 97  sethi  %hi(0xa8025c00), %o0
a0097aac:  03 2a 00 97  sethi  %hi(0xa8025c00), %g1
a0097ab0:  a4 10 20 10  mov  0x10, %l2
a0097ab4:  23 2a 00 ac  sethi  %hi(0xa802b000), %l1
a0097ab8:  d2 2a 20 55  stb  %o1, [ %o0 + 0x55 ]
a0097abc:  da 28 60 54  stb  %o5, [ %g1 + 0x54 ]
a0097ac0:  e4 2c 60 8f  stb  %l2, [ %l1 + 0x8f ]
a0097ac4:  40 00 f3 b5  call  0xa00d4998
a0097ac8:  81 e8 00 00  restore
a0097acc:  01 00 00 00  nop
