# leon2m FUN_a0083c34 0xa0083c34-0xa0083c88 (84 bytes)
a0083c34:  03 2a 00 90  sethi  %hi(0xa8024000), %g1
a0083c38:  98 10 60 18  or  %g1, 0x18, %o4	! 0xa8024018
a0083c3c:  da 0b 20 01  ldub  [ %o4 + 1 ], %o5
a0083c40:  80 a3 60 50  cmp  %o5, 0x50
a0083c44:  22 80 00 04  be,a   0xa0083c54
a0083c48:  d0 0b 20 02  ldub  [ %o4 + 2 ], %o0
a0083c4c:  10 80 00 0d  b  0xa0083c80
a0083c50:  90 10 20 00  clr  %o0
a0083c54:  80 a2 20 6c  cmp  %o0, 0x6c
a0083c58:  12 80 00 0a  bne  0xa0083c80
a0083c5c:  90 10 20 00  clr  %o0
a0083c60:  da 0b 20 03  ldub  [ %o4 + 3 ], %o5
a0083c64:  80 a3 60 61  cmp  %o5, 0x61
a0083c68:  12 bf ff f9  bne  0xa0083c4c
a0083c6c:  90 10 20 01  mov  1, %o0
a0083c70:  c2 0b 20 04  ldub  [ %o4 + 4 ], %g1
a0083c74:  80 a0 60 79  cmp  %g1, 0x79
a0083c78:  32 80 00 02  bne,a   0xa0083c80
a0083c7c:  90 10 20 00  clr  %o0
a0083c80:  81 c3 e0 08  retl
a0083c84:  01 00 00 00  nop
