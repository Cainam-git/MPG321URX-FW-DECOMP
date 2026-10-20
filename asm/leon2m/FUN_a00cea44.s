# leon2m FUN_a00cea44 0xa00cea44-0xa00cea6c (40 bytes)
a00cea44:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00cea48:  da 03 22 90  ld  [ %o4 + 0x290 ], %o5	! 0xa802d290
a00cea4c:  11 00 00 10  sethi  %hi(0x4000), %o0
a00cea50:  82 2b 40 08  andn  %o5, %o0, %g1
a00cea54:  c2 23 22 90  st  %g1, [ %o4 + 0x290 ]
a00cea58:  90 10 20 fe  mov  0xfe, %o0
a00cea5c:  92 10 20 00  clr  %o1
a00cea60:  82 13 c0 00  mov  %o7, %g1
a00cea64:  40 01 f2 94  call  0xa014b4b4
a00cea68:  9e 10 40 00  mov  %g1, %o7
