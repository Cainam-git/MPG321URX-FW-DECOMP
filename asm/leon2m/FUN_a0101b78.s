# leon2m FUN_a0101b78 0xa0101b78-0xa0101bb0 (56 bytes)
a0101b78:  11 33 c0 58  sethi  %hi(0xcf016000), %o0
a0101b7c:  82 12 20 c0  or  %o0, 0xc0, %g1	! 0xcf0160c0
a0101b80:  98 12 20 f4  or  %o0, 0xf4, %o4
a0101b84:  da 00 40 00  ld  [ %g1 ], %o5
a0101b88:  80 8b 60 08  btst  8, %o5
a0101b8c:  02 80 00 06  be  0xa0101ba4
a0101b90:  90 10 20 01  mov  1, %o0
a0101b94:  da 03 00 00  ld  [ %o4 ], %o5
a0101b98:  80 8b 60 60  btst  0x60, %o5
a0101b9c:  02 80 00 03  be  0xa0101ba8
a0101ba0:  01 00 00 00  nop
a0101ba4:  90 10 20 00  clr  %o0	! 0x0
a0101ba8:  81 c3 e0 08  retl
a0101bac:  01 00 00 00  nop
