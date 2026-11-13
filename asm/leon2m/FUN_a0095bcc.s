# leon2m FUN_a0095bcc 0xa0095bcc-0xa0095c94 (200 bytes)
a0095bcc:  9d e3 bf 98  save  %sp, -104, %sp
a0095bd0:  35 2a 00 ab  sethi  %hi(0xa802ac00), %i2
a0095bd4:  d2 06 a3 ec  ld  [ %i2 + 0x3ec ], %o1	! 0xa802afec
a0095bd8:  90 02 7f b2  add  %o1, -78, %o0
a0095bdc:  40 00 4d f8  call  0xa00a93bc
a0095be0:  90 0a 20 ff  and  %o0, 0xff, %o0
a0095be4:  03 19 99 99  sethi  %hi(0x66666400), %g1
a0095be8:  b2 10 62 67  or  %g1, 0x267, %i1	! 0x66666667
a0095bec:  da 16 a3 ee  lduh  [ %i2 + 0x3ee ], %o5
a0095bf0:  9e 03 7f b6  add  %o5, -74, %o7
a0095bf4:  80 5b c0 19  smul  %o7, %i1, %g0
a0095bf8:  97 40 00 00  rd  %y, %o3
a0095bfc:  93 3a e0 01  sra  %o3, 1, %o1
a0095c00:  95 3b e0 1f  sra  %o7, 0x1f, %o2
a0095c04:  90 22 40 0a  sub  %o1, %o2, %o0
a0095c08:  83 2a 20 02  sll  %o0, 2, %g1
a0095c0c:  b0 00 40 08  add  %g1, %o0, %i0
a0095c10:  98 23 c0 18  sub  %o7, %i0, %o4
a0095c14:  96 03 3f fb  add  %o4, -5, %o3
a0095c18:  9a 03 20 4e  add  %o4, 0x4e, %o5
a0095c1c:  da 26 a3 ec  st  %o5, [ %i2 + 0x3ec ]
a0095c20:  40 00 54 44  call  0xa00aad30
a0095c24:  90 0a e0 ff  and  %o3, 0xff, %o0
a0095c28:  94 0a 20 ff  and  %o0, 0xff, %o2
a0095c2c:  80 a2 a0 01  cmp  %o2, 1
a0095c30:  12 bf ff f0  bne  0xa0095bf0
a0095c34:  da 16 a3 ee  lduh  [ %i2 + 0x3ee ], %o5
a0095c38:  d2 06 a3 ec  ld  [ %i2 + 0x3ec ], %o1
a0095c3c:  82 02 7f b2  add  %o1, -78, %g1
a0095c40:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a0095c44:  40 01 0d 37  call  0xa00d9120
a0095c48:  c2 2a 23 eb  stb  %g1, [ %o0 + 0x3eb ]	! 0xa802d3eb
a0095c4c:  f0 06 a3 ec  ld  [ %i2 + 0x3ec ], %i0
a0095c50:  9e 06 3f b2  add  %i0, -78, %o7
a0095c54:  90 0b e0 ff  and  %o7, 0xff, %o0
a0095c58:  40 00 4e 7e  call  0xa00a9650
a0095c5c:  92 10 20 01  mov  1, %o1
a0095c60:  f2 06 a3 ec  ld  [ %i2 + 0x3ec ], %i1
a0095c64:  98 06 7f b2  add  %i1, -78, %o4
a0095c68:  35 2a 00 97  sethi  %hi(0xa8025c00), %i2
a0095c6c:  f2 0e a0 56  ldub  [ %i2 + 0x56 ], %i1	! 0xa8025c56
a0095c70:  b0 10 20 01  mov  1, %i0
a0095c74:  80 a3 00 19  cmp  %o4, %i1
a0095c78:  02 80 00 04  be  0xa0095c88
a0095c7c:  b4 10 20 00  clr  %i2
a0095c80:  b0 10 20 01  mov  1, %i0
a0095c84:  b4 10 20 01  mov  1, %i2
a0095c88:  40 00 49 2d  call  0xa00a813c
a0095c8c:  81 e8 00 00  restore
a0095c90:  01 00 00 00  nop
