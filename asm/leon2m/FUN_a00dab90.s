# leon2m FUN_a00dab90 0xa00dab90-0xa00dabc4 (52 bytes)
a00dab90:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00dab94:  82 10 62 90  or  %g1, 0x290, %g1	! 0xa802d290
a00dab98:  da 08 61 ec  ldub  [ %g1 + 0x1ec ], %o5
a00dab9c:  80 a3 60 00  cmp  %o5, 0
a00daba0:  12 80 00 05  bne  0xa00dabb4
a00daba4:  90 10 20 00  clr  %o0
a00daba8:  82 13 c0 00  mov  %o7, %g1
a00dabac:  40 01 31 6a  call  0xa0127154
a00dabb0:  9e 10 40 00  mov  %g1, %o7
a00dabb4:  d0 08 61 ed  ldub  [ %g1 + 0x1ed ], %o0
a00dabb8:  82 13 c0 00  mov  %o7, %g1
a00dabbc:  40 01 31 66  call  0xa0127154
a00dabc0:  9e 10 40 00  mov  %g1, %o7
