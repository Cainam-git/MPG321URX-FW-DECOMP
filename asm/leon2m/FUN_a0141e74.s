# leon2m FUN_a0141e74 0xa0141e74-0xa0141edc (104 bytes)
a0141e74:  90 0a 20 ff  and  %o0, 0xff, %o0
a0141e78:  80 a2 20 61  cmp  %o0, 0x61
a0141e7c:  02 80 00 10  be  0xa0141ebc
a0141e80:  03 2a 00 b8  sethi  %hi(0xa802e000), %g1
a0141e84:  04 80 00 09  ble  0xa0141ea8
a0141e88:  80 a2 20 51  cmp  %o0, 0x51
a0141e8c:  80 a2 20 71  cmp  %o0, 0x71
a0141e90:  02 80 00 0f  be  0xa0141ecc
a0141e94:  80 a2 20 81  cmp  %o0, 0x81
a0141e98:  02 80 00 0b  be  0xa0141ec4
a0141e9c:  03 2a 00 b8  sethi  %hi(0xa802e000), %g1
a0141ea0:  10 80 00 0d  b  0xa0141ed4
a0141ea4:  90 10 20 08  mov  8, %o0
a0141ea8:  32 80 00 0b  bne,a   0xa0141ed4
a0141eac:  90 10 20 08  mov  8, %o0
a0141eb0:  03 2a 00 b8  sethi  %hi(0xa802e000), %g1
a0141eb4:  10 80 00 08  b  0xa0141ed4
a0141eb8:  d0 08 61 1b  ldub  [ %g1 + 0x11b ], %o0	! 0xa802e11b
a0141ebc:  10 80 00 06  b  0xa0141ed4
a0141ec0:  d0 08 61 2d  ldub  [ %g1 + 0x12d ], %o0
a0141ec4:  10 80 00 04  b  0xa0141ed4
a0141ec8:  d0 08 61 51  ldub  [ %g1 + 0x151 ], %o0
a0141ecc:  03 2a 00 b8  sethi  %hi(0xa802e000), %g1
a0141ed0:  d0 08 61 3f  ldub  [ %g1 + 0x13f ], %o0	! 0xa802e13f
a0141ed4:  81 c3 e0 08  retl
a0141ed8:  01 00 00 00  nop
