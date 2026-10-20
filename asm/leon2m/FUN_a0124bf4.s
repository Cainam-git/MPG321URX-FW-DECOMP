# leon2m FUN_a0124bf4 0xa0124bf4-0xa0124d24 (304 bytes)
a0124bf4:  9d e3 bf 90  save  %sp, -112, %sp
a0124bf8:  90 06 20 04  add  %i0, 4, %o0
a0124bfc:  82 0a 20 ff  and  %o0, 0xff, %g1
a0124c00:  80 a0 60 02  cmp  %g1, 2
a0124c04:  82 10 00 18  mov  %i0, %g1
a0124c08:  18 80 00 04  bgu  0xa0124c18
a0124c0c:  b0 10 20 00  clr  %i0
a0124c10:  10 80 00 42  b  0xa0124d18
a0124c14:  b0 10 20 01  mov  1, %i0
a0124c18:  96 08 60 ff  and  %g1, 0xff, %o3
a0124c1c:  80 a2 e0 ff  cmp  %o3, 0xff
a0124c20:  02 80 00 3e  be  0xa0124d18
a0124c24:  80 a2 e0 07  cmp  %o3, 7
a0124c28:  38 80 00 3d  bgu,a   0xa0124d1c
a0124c2c:  b0 0e 20 01  and  %i0, 1, %i0
a0124c30:  15 00 06 90  sethi  %hi(0x1a4000), %o2
a0124c34:  92 12 a2 a8  or  %o2, 0x2a8, %o1	! 0x1a42a8
a0124c38:  9a 5a e0 16  smul  %o3, 0x16, %o5
a0124c3c:  a0 03 40 09  add  %o5, %o1, %l0
a0124c40:  d8 0c 20 01  ldub  [ %l0 + 1 ], %o4
a0124c44:  80 a3 20 01  cmp  %o4, 1
a0124c48:  22 80 00 0f  be,a   0xa0124c84
a0124c4c:  de 0c 20 13  ldub  [ %l0 + 0x13 ], %o7
a0124c50:  d0 0c 20 0b  ldub  [ %l0 + 0xb ], %o0
a0124c54:  80 a2 20 ff  cmp  %o0, 0xff
a0124c58:  02 80 00 30  be  0xa0124d18
a0124c5c:  b0 10 20 00  clr  %i0
a0124c60:  67 fd a0 36  call  0x4008cd38
a0124c64:  d2 0c 20 0c  ldub  [ %l0 + 0xc ], %o1
a0124c68:  90 0a 20 ff  and  %o0, 0xff, %o0
a0124c6c:  c2 0c 20 0d  ldub  [ %l0 + 0xd ], %g1
a0124c70:  80 a2 00 01  cmp  %o0, %g1
a0124c74:  02 80 00 29  be  0xa0124d18
a0124c78:  b0 10 20 01  mov  1, %i0
a0124c7c:  10 80 00 27  b  0xa0124d18
a0124c80:  b0 10 20 00  clr  %i0
a0124c84:  f0 0c 20 15  ldub  [ %l0 + 0x15 ], %i0
a0124c88:  c2 0c 20 12  ldub  [ %l0 + 0x12 ], %g1
a0124c8c:  d2 0c 20 14  ldub  [ %l0 + 0x14 ], %o1
a0124c90:  90 10 00 0f  mov  %o7, %o0
a0124c94:  c2 2f bf f0  stb  %g1, [ %fp + -16 ]
a0124c98:  f0 2f bf f3  stb  %i0, [ %fp + -13 ]
a0124c9c:  de 2f bf f1  stb  %o7, [ %fp + -15 ]
a0124ca0:  80 a3 e0 ff  cmp  %o7, 0xff
a0124ca4:  02 80 00 07  be  0xa0124cc0
a0124ca8:  d2 2f bf f2  stb  %o1, [ %fp + -14 ]
a0124cac:  19 2a 00 b2  sethi  %hi(0xa802c800), %o4
a0124cb0:  e0 0b 21 f9  ldub  [ %o4 + 0x1f9 ], %l0	! 0xa802c9f9
a0124cb4:  80 a4 20 00  cmp  %l0, 0
a0124cb8:  02 80 00 0e  be  0xa0124cf0
a0124cbc:  01 00 00 00  nop
a0124cc0:  a0 12 a2 a8  or  %o2, 0x2a8, %l0
a0124cc4:  82 5a e0 16  smul  %o3, 0x16, %g1
a0124cc8:  b0 00 40 10  add  %g1, %l0, %i0
a0124ccc:  d0 0e 20 0b  ldub  [ %i0 + 0xb ], %o0
a0124cd0:  80 a2 20 ff  cmp  %o0, 0xff
a0124cd4:  22 80 00 11  be,a   0xa0124d18
a0124cd8:  b0 10 20 00  clr  %i0
a0124cdc:  67 fd a0 17  call  0x4008cd38
a0124ce0:  d2 0e 20 0c  ldub  [ %i0 + 0xc ], %o1
a0124ce4:  90 0a 20 ff  and  %o0, 0xff, %o0
a0124ce8:  10 bf ff e2  b  0xa0124c70
a0124cec:  c2 0e 20 0d  ldub  [ %i0 + 0xd ], %g1
a0124cf0:  67 fd a0 12  call  0x4008cd38
a0124cf4:  92 0a 60 ff  and  %o1, 0xff, %o1
a0124cf8:  de 07 bf f0  ld  [ %fp + -16 ], %o7
a0124cfc:  9b 33 e0 07  srl  %o7, 7, %o5
a0124d00:  90 0a 20 ff  and  %o0, 0xff, %o0
a0124d04:  92 0b 60 01  and  %o5, 1, %o1
a0124d08:  96 1a 00 09  xor  %o0, %o1, %o3
a0124d0c:  80 a0 00 0b  cmp  %g0, %o3
a0124d10:  94 60 3f ff  subx  %g0, -1, %o2
a0124d14:  b0 10 00 0a  mov  %o2, %i0
a0124d18:  b0 0e 20 01  and  %i0, 1, %i0
a0124d1c:  81 c7 e0 08  ret
a0124d20:  81 e8 00 00  restore
