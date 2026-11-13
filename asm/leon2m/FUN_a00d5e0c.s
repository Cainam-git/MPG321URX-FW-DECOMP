# leon2m FUN_a00d5e0c 0xa00d5e0c-0xa00d5e84 (120 bytes)
a00d5e0c:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a00d5e10:  d0 03 62 c4  ld  [ %o5 + 0x2c4 ], %o0	! 0xa802d2c4
a00d5e14:  83 32 20 0c  srl  %o0, 0xc, %g1
a00d5e18:  82 08 60 0f  and  %g1, 0xf, %g1
a00d5e1c:  80 a0 60 02  cmp  %g1, 2
a00d5e20:  02 80 00 09  be  0xa00d5e44
a00d5e24:  90 10 20 02  mov  2, %o0
a00d5e28:  80 a0 60 02  cmp  %g1, 2
a00d5e2c:  14 80 00 0a  bg  0xa00d5e54
a00d5e30:  80 a0 60 03  cmp  %g1, 3
a00d5e34:  80 a0 60 01  cmp  %g1, 1
a00d5e38:  22 80 00 0e  be,a   0xa00d5e70
a00d5e3c:  90 10 20 01  mov  1, %o0
a00d5e40:  90 10 20 00  clr  %o0
a00d5e44:  90 0a 20 03  and  %o0, 3, %o0
a00d5e48:  82 13 c0 00  mov  %o7, %g1
a00d5e4c:  40 01 cc 5d  call  0xa0148fc0
a00d5e50:  9e 10 40 00  mov  %g1, %o7
a00d5e54:  32 bf ff fc  bne,a   0xa00d5e44
a00d5e58:  90 10 20 00  clr  %o0
a00d5e5c:  90 10 20 03  mov  3, %o0
a00d5e60:  90 0a 20 03  and  %o0, 3, %o0
a00d5e64:  82 13 c0 00  mov  %o7, %g1
a00d5e68:  40 01 cc 56  call  0xa0148fc0
a00d5e6c:  9e 10 40 00  mov  %g1, %o7
a00d5e70:  90 0a 20 03  and  %o0, 3, %o0
a00d5e74:  82 13 c0 00  mov  %o7, %g1
a00d5e78:  40 01 cc 52  call  0xa0148fc0
a00d5e7c:  9e 10 40 00  mov  %g1, %o7
a00d5e80:  01 00 00 00  nop
