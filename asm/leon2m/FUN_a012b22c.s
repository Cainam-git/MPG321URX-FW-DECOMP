# leon2m FUN_a012b22c 0xa012b22c-0xa012b260 (52 bytes)
a012b22c:  19 2a 00 b8  sethi  %hi(0xa802e000), %o4
a012b230:  9a 13 21 a0  or  %o4, 0x1a0, %o5	! 0xa802e1a0
a012b234:  82 0a 20 ff  and  %o0, 0xff, %g1
a012b238:  99 28 60 02  sll  %g1, 2, %o4
a012b23c:  d0 0b 60 32  ldub  [ %o5 + 0x32 ], %o0
a012b240:  c2 0b 60 2c  ldub  [ %o5 + 0x2c ], %g1
a012b244:  91 3a 00 0c  sra  %o0, %o4, %o0
a012b248:  9b 38 40 0c  sra  %g1, %o4, %o5
a012b24c:  98 0a 20 0f  and  %o0, 0xf, %o4
a012b250:  82 0b 60 0f  and  %o5, 0xf, %g1
a012b254:  91 3b 00 01  sra  %o4, %g1, %o0
a012b258:  81 c3 e0 08  retl
a012b25c:  90 0a 20 01  and  %o0, 1, %o0
