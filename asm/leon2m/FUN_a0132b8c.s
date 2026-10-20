# leon2m FUN_a0132b8c 0xa0132b8c-0xa0132bfc (112 bytes)
a0132b8c:  9d e3 bf 98  save  %sp, -104, %sp
a0132b90:  1f 2a 00 b2  sethi  %hi(0xa802c800), %o7
a0132b94:  c2 0b e3 93  ldub  [ %o7 + 0x393 ], %g1	! 0xa802cb93
a0132b98:  b2 10 00 18  mov  %i0, %i1
a0132b9c:  80 a0 60 01  cmp  %g1, 1
a0132ba0:  12 80 00 14  bne  0xa0132bf0
a0132ba4:  b0 10 20 00  clr  %i0
a0132ba8:  35 2a 00 b2  sethi  %hi(0xa802c800), %i2
a0132bac:  f0 0e a3 92  ldub  [ %i2 + 0x392 ], %i0	! 0xa802cb92
a0132bb0:  80 a6 20 00  cmp  %i0, 0
a0132bb4:  02 80 00 0d  be  0xa0132be8
a0132bb8:  b8 10 20 00  clr  %i4
a0132bbc:  3b 2a 00 b7  sethi  %hi(0xa802dc00), %i5
a0132bc0:  b6 17 62 40  or  %i5, 0x240, %i3	! 0xa802de40
a0132bc4:  ba 10 20 00  clr  %i5
a0132bc8:  f0 0e c0 1d  ldub  [ %i3 + %i5 ], %i0
a0132bcc:  f0 2f 40 19  stb  %i0, [ %i5 + %i1 ]
a0132bd0:  b8 07 20 01  inc  %i4
a0132bd4:  ba 0f 20 ff  and  %i4, 0xff, %i5
a0132bd8:  c2 0e a3 92  ldub  [ %i2 + 0x392 ], %g1
a0132bdc:  80 a7 40 01  cmp  %i5, %g1
a0132be0:  2a bf ff fb  bcs,a   0xa0132bcc
a0132be4:  f0 0e c0 1d  ldub  [ %i3 + %i5 ], %i0
a0132be8:  c0 2b e3 93  clrb  [ %o7 + 0x393 ]
a0132bec:  b0 10 20 01  mov  1, %i0
a0132bf0:  b0 0e 20 01  and  %i0, 1, %i0
a0132bf4:  81 c7 e0 08  ret
a0132bf8:  81 e8 00 00  restore
