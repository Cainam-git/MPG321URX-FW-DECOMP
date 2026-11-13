# leon2m FUN_a0095c94 0xa0095c94-0xa0095d5c (200 bytes)
a0095c94:  9d e3 bf 98  save  %sp, -104, %sp
a0095c98:  35 2a 00 ab  sethi  %hi(0xa802ac00), %i2
a0095c9c:  d2 06 a3 ec  ld  [ %i2 + 0x3ec ], %o1	! 0xa802afec
a0095ca0:  90 02 7f b2  add  %o1, -78, %o0
a0095ca4:  40 00 4d c6  call  0xa00a93bc
a0095ca8:  90 0a 20 ff  and  %o0, 0xff, %o0
a0095cac:  03 19 99 99  sethi  %hi(0x66666400), %g1
a0095cb0:  b2 10 62 67  or  %g1, 0x267, %i1	! 0x66666667
a0095cb4:  da 16 a3 ee  lduh  [ %i2 + 0x3ee ], %o5
a0095cb8:  9e 03 7f b3  add  %o5, -77, %o7
a0095cbc:  80 5b c0 19  smul  %o7, %i1, %g0
a0095cc0:  97 40 00 00  rd  %y, %o3
a0095cc4:  93 3a e0 01  sra  %o3, 1, %o1
a0095cc8:  95 3b e0 1f  sra  %o7, 0x1f, %o2
a0095ccc:  90 22 40 0a  sub  %o1, %o2, %o0
a0095cd0:  83 2a 20 02  sll  %o0, 2, %g1
a0095cd4:  b0 00 40 08  add  %g1, %o0, %i0
a0095cd8:  98 23 c0 18  sub  %o7, %i0, %o4
a0095cdc:  96 03 3f fb  add  %o4, -5, %o3
a0095ce0:  9a 03 20 4e  add  %o4, 0x4e, %o5
a0095ce4:  da 26 a3 ec  st  %o5, [ %i2 + 0x3ec ]
a0095ce8:  40 00 54 12  call  0xa00aad30
a0095cec:  90 0a e0 ff  and  %o3, 0xff, %o0
a0095cf0:  94 0a 20 ff  and  %o0, 0xff, %o2
a0095cf4:  80 a2 a0 01  cmp  %o2, 1
a0095cf8:  12 bf ff f0  bne  0xa0095cb8
a0095cfc:  da 16 a3 ee  lduh  [ %i2 + 0x3ee ], %o5
a0095d00:  d2 06 a3 ec  ld  [ %i2 + 0x3ec ], %o1
a0095d04:  82 02 7f b2  add  %o1, -78, %g1
a0095d08:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a0095d0c:  40 01 0d 05  call  0xa00d9120
a0095d10:  c2 2a 23 eb  stb  %g1, [ %o0 + 0x3eb ]	! 0xa802d3eb
a0095d14:  f0 06 a3 ec  ld  [ %i2 + 0x3ec ], %i0
a0095d18:  9e 06 3f b2  add  %i0, -78, %o7
a0095d1c:  90 0b e0 ff  and  %o7, 0xff, %o0
a0095d20:  40 00 4e 4c  call  0xa00a9650
a0095d24:  92 10 20 01  mov  1, %o1
a0095d28:  f2 06 a3 ec  ld  [ %i2 + 0x3ec ], %i1
a0095d2c:  98 06 7f b2  add  %i1, -78, %o4
a0095d30:  35 2a 00 97  sethi  %hi(0xa8025c00), %i2
a0095d34:  f2 0e a0 56  ldub  [ %i2 + 0x56 ], %i1	! 0xa8025c56
a0095d38:  b0 10 20 01  mov  1, %i0
a0095d3c:  80 a3 00 19  cmp  %o4, %i1
a0095d40:  02 80 00 04  be  0xa0095d50
a0095d44:  b4 10 20 00  clr  %i2
a0095d48:  b0 10 20 01  mov  1, %i0
a0095d4c:  b4 10 20 01  mov  1, %i2
a0095d50:  40 00 48 fb  call  0xa00a813c
a0095d54:  81 e8 00 00  restore
a0095d58:  01 00 00 00  nop
