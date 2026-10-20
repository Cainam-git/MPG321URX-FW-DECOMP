# leon2m FUN_a00d5da4 0xa00d5da4-0xa00d5eac (236 bytes)
a00d5da4:  9d e3 bf 98  save  %sp, -104, %sp
a00d5da8:  7f fe b3 a9  call  0xa0082c4c
a00d5dac:  01 00 00 00  nop
a00d5db0:  80 8a 20 ff  btst  0xff, %o0
a00d5db4:  02 80 00 0d  be  0xa00d5de8
a00d5db8:  01 00 00 00  nop
a00d5dbc:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00d5dc0:  c2 08 62 95  ldub  [ %g1 + 0x295 ], %g1	! 0xa802d295
a00d5dc4:  80 a0 60 01  cmp  %g1, 1
a00d5dc8:  02 80 00 05  be  0xa00d5ddc
a00d5dcc:  b0 10 20 01  mov  1, %i0
a00d5dd0:  80 a0 60 02  cmp  %g1, 2
a00d5dd4:  02 80 00 09  be  0xa00d5df8
a00d5dd8:  b0 10 20 00  clr  %i0
a00d5ddc:  b0 0e 20 03  and  %i0, 3, %i0
a00d5de0:  40 01 cc 5b  call  0xa0148f4c
a00d5de4:  81 e8 00 00  restore
a00d5de8:  40 01 3b 08  call  0xa0124a08
a00d5dec:  01 00 00 00  nop
a00d5df0:  10 bf ff f4  b  0xa00d5dc0
a00d5df4:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00d5df8:  b0 10 20 02  mov  2, %i0
a00d5dfc:  b0 0e 20 03  and  %i0, 3, %i0
a00d5e00:  40 01 cc 53  call  0xa0148f4c
a00d5e04:  81 e8 00 00  restore
a00d5e08:  01 00 00 00  nop
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
a00d5e84:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00d5e88:  d0 00 62 94  ld  [ %g1 + 0x294 ], %o0	! 0xa802d294
a00d5e8c:  91 32 20 1e  srl  %o0, 0x1e, %o0
a00d5e90:  90 0a 20 01  and  %o0, 1, %o0
a00d5e94:  82 13 c0 00  mov  %o7, %g1
a00d5e98:  40 01 cc 17  call  0xa0148ef4
a00d5e9c:  9e 10 40 00  mov  %g1, %o7
a00d5ea0:  01 00 00 00  nop
a00d5ea4:  81 c3 e0 08  retl
a00d5ea8:  01 00 00 00  nop
