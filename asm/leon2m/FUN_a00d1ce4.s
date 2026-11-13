# leon2m FUN_a00d1ce4 0xa00d1ce4-0xa00d1d34 (80 bytes)
a00d1ce4:  9d e3 bf 98  save  %sp, -104, %sp
a00d1ce8:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00d1cec:  c2 0e 20 07  ldub  [ %i0 + 7 ], %g1
a00d1cf0:  80 a0 60 01  cmp  %g1, 1
a00d1cf4:  02 80 00 08  be  0xa00d1d14
a00d1cf8:  9a 12 62 90  or  %o1, 0x290, %o5
a00d1cfc:  80 a0 60 00  cmp  %g1, 0
a00d1d00:  32 80 00 07  bne,a   0xa00d1d1c
a00d1d04:  92 12 62 90  or  %o1, 0x290, %o1
a00d1d08:  82 12 62 90  or  %o1, 0x290, %g1
a00d1d0c:  10 80 00 03  b  0xa00d1d18
a00d1d10:  c0 28 61 d5  clrb  [ %g1 + 0x1d5 ]
a00d1d14:  c2 2b 61 d5  stb  %g1, [ %o5 + 0x1d5 ]
a00d1d18:  92 12 62 90  or  %o1, 0x290, %o1
a00d1d1c:  90 10 20 30  mov  0x30, %o0
a00d1d20:  94 10 20 00  clr  %o2
a00d1d24:  40 01 e4 6b  call  0xa014aed0
a00d1d28:  96 10 21 fc  mov  0x1fc, %o3
a00d1d2c:  81 c7 e0 08  ret
a00d1d30:  91 e8 20 e0  restore  %g0, 0xe0, %o0
