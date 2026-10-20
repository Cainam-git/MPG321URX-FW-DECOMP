# leon2m FUN_a0132cd4 0xa0132cd4-0xa0132d44 (112 bytes)
a0132cd4:  9d e3 bf 98  save  %sp, -104, %sp
a0132cd8:  1f 2a 00 b2  sethi  %hi(0xa802c800), %o7
a0132cdc:  c2 0b e3 8f  ldub  [ %o7 + 0x38f ], %g1	! 0xa802cb8f
a0132ce0:  b2 10 00 18  mov  %i0, %i1
a0132ce4:  80 a0 60 01  cmp  %g1, 1
a0132ce8:  12 80 00 14  bne  0xa0132d38
a0132cec:  b0 10 20 00  clr  %i0
a0132cf0:  35 2a 00 b2  sethi  %hi(0xa802c800), %i2
a0132cf4:  f0 0e a3 8e  ldub  [ %i2 + 0x38e ], %i0	! 0xa802cb8e
a0132cf8:  80 a6 20 00  cmp  %i0, 0
a0132cfc:  02 80 00 0d  be  0xa0132d30
a0132d00:  b8 10 20 00  clr  %i4
a0132d04:  3b 2a 00 b7  sethi  %hi(0xa802dc00), %i5
a0132d08:  b6 17 62 40  or  %i5, 0x240, %i3	! 0xa802de40
a0132d0c:  ba 10 20 00  clr  %i5
a0132d10:  f0 0e c0 1d  ldub  [ %i3 + %i5 ], %i0
a0132d14:  f0 2f 40 19  stb  %i0, [ %i5 + %i1 ]
a0132d18:  b8 07 20 01  inc  %i4
a0132d1c:  ba 0f 20 ff  and  %i4, 0xff, %i5
a0132d20:  c2 0e a3 8e  ldub  [ %i2 + 0x38e ], %g1
a0132d24:  80 a7 40 01  cmp  %i5, %g1
a0132d28:  2a bf ff fb  bcs,a   0xa0132d14
a0132d2c:  f0 0e c0 1d  ldub  [ %i3 + %i5 ], %i0
a0132d30:  c0 2b e3 8f  clrb  [ %o7 + 0x38f ]
a0132d34:  b0 10 20 01  mov  1, %i0
a0132d38:  b0 0e 20 01  and  %i0, 1, %i0
a0132d3c:  81 c7 e0 08  ret
a0132d40:  81 e8 00 00  restore
