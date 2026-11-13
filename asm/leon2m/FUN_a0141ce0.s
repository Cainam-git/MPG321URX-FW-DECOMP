# leon2m FUN_a0141ce0 0xa0141ce0-0xa0141d50 (112 bytes)
a0141ce0:  90 0a 20 ff  and  %o0, 0xff, %o0
a0141ce4:  80 a2 20 61  cmp  %o0, 0x61
a0141ce8:  22 80 00 11  be,a   0xa0141d2c
a0141cec:  11 2a 00 b8  sethi  %hi(0xa802e000), %o0
a0141cf0:  04 80 00 09  ble  0xa0141d14
a0141cf4:  80 a2 20 51  cmp  %o0, 0x51
a0141cf8:  80 a2 20 71  cmp  %o0, 0x71
a0141cfc:  02 80 00 10  be  0xa0141d3c
a0141d00:  80 a2 20 81  cmp  %o0, 0x81
a0141d04:  22 80 00 0c  be,a   0xa0141d34
a0141d08:  11 2a 00 b8  sethi  %hi(0xa802e000), %o0
a0141d0c:  10 80 00 0f  b  0xa0141d48
a0141d10:  90 10 20 08  mov  8, %o0
a0141d14:  32 80 00 0d  bne,a   0xa0141d48
a0141d18:  90 10 20 08  mov  8, %o0
a0141d1c:  03 2a 00 b8  sethi  %hi(0xa802e000), %g1
a0141d20:  da 10 61 16  lduh  [ %g1 + 0x116 ], %o5	! 0xa802e116
a0141d24:  10 80 00 09  b  0xa0141d48
a0141d28:  91 33 60 0c  srl  %o5, 0xc, %o0
a0141d2c:  10 bf ff fe  b  0xa0141d24
a0141d30:  da 12 21 28  lduh  [ %o0 + 0x128 ], %o5
a0141d34:  10 bf ff fc  b  0xa0141d24
a0141d38:  da 12 21 4c  lduh  [ %o0 + 0x14c ], %o5
a0141d3c:  03 2a 00 b8  sethi  %hi(0xa802e000), %g1
a0141d40:  10 bf ff f9  b  0xa0141d24
a0141d44:  da 10 61 3a  lduh  [ %g1 + 0x13a ], %o5	! 0xa802e13a
a0141d48:  81 c3 e0 08  retl
a0141d4c:  01 00 00 00  nop
