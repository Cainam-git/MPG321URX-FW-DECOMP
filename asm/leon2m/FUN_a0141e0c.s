# leon2m FUN_a0141e0c 0xa0141e0c-0xa0141e74 (104 bytes)
a0141e0c:  90 0a 20 ff  and  %o0, 0xff, %o0
a0141e10:  80 a2 20 61  cmp  %o0, 0x61
a0141e14:  02 80 00 10  be  0xa0141e54
a0141e18:  03 2a 00 b8  sethi  %hi(0xa802e000), %g1
a0141e1c:  04 80 00 09  ble  0xa0141e40
a0141e20:  80 a2 20 51  cmp  %o0, 0x51
a0141e24:  80 a2 20 71  cmp  %o0, 0x71
a0141e28:  02 80 00 0f  be  0xa0141e64
a0141e2c:  80 a2 20 81  cmp  %o0, 0x81
a0141e30:  02 80 00 0b  be  0xa0141e5c
a0141e34:  03 2a 00 b8  sethi  %hi(0xa802e000), %g1
a0141e38:  10 80 00 0d  b  0xa0141e6c
a0141e3c:  90 10 20 00  clr  %o0
a0141e40:  32 80 00 0b  bne,a   0xa0141e6c
a0141e44:  90 10 20 00  clr  %o0
a0141e48:  03 2a 00 b8  sethi  %hi(0xa802e000), %g1
a0141e4c:  10 80 00 08  b  0xa0141e6c
a0141e50:  d0 10 61 24  lduh  [ %g1 + 0x124 ], %o0	! 0xa802e124
a0141e54:  10 80 00 06  b  0xa0141e6c
a0141e58:  d0 10 61 36  lduh  [ %g1 + 0x136 ], %o0
a0141e5c:  10 80 00 04  b  0xa0141e6c
a0141e60:  d0 10 61 5a  lduh  [ %g1 + 0x15a ], %o0
a0141e64:  03 2a 00 b8  sethi  %hi(0xa802e000), %g1
a0141e68:  d0 10 61 48  lduh  [ %g1 + 0x148 ], %o0	! 0xa802e148
a0141e6c:  81 c3 e0 08  retl
a0141e70:  01 00 00 00  nop
