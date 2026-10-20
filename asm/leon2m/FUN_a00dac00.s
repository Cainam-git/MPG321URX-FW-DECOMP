# leon2m FUN_a00dac00 0xa00dac00-0xa00dac34 (52 bytes)
a00dac00:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00dac04:  82 10 62 90  or  %g1, 0x290, %g1	! 0xa802d290
a00dac08:  da 08 61 e8  ldub  [ %g1 + 0x1e8 ], %o5
a00dac0c:  80 a3 60 00  cmp  %o5, 0
a00dac10:  12 80 00 05  bne  0xa00dac24
a00dac14:  90 10 20 00  clr  %o0
a00dac18:  82 13 c0 00  mov  %o7, %g1
a00dac1c:  40 01 32 08  call  0xa012743c
a00dac20:  9e 10 40 00  mov  %g1, %o7
a00dac24:  d0 08 61 e9  ldub  [ %g1 + 0x1e9 ], %o0
a00dac28:  82 13 c0 00  mov  %o7, %g1
a00dac2c:  40 01 32 04  call  0xa012743c
a00dac30:  9e 10 40 00  mov  %g1, %o7
