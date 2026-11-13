# leon2m FUN_a0121ed0 0xa0121ed0-0xa0121f20 (80 bytes)
a0121ed0:  90 0a 20 ff  and  %o0, 0xff, %o0
a0121ed4:  80 a2 20 02  cmp  %o0, 2
a0121ed8:  02 80 00 10  be  0xa0121f18
a0121edc:  82 10 20 02  mov  2, %g1
a0121ee0:  80 a2 20 02  cmp  %o0, 2
a0121ee4:  04 80 00 09  ble  0xa0121f08
a0121ee8:  82 10 20 03  mov  3, %g1
a0121eec:  80 a2 20 03  cmp  %o0, 3
a0121ef0:  02 80 00 0a  be  0xa0121f18
a0121ef4:  80 a2 20 04  cmp  %o0, 4
a0121ef8:  02 80 00 08  be  0xa0121f18
a0121efc:  82 10 20 05  mov  5, %g1
a0121f00:  10 80 00 06  b  0xa0121f18
a0121f04:  82 10 20 00  clr  %g1
a0121f08:  80 a2 20 01  cmp  %o0, 1
a0121f0c:  12 80 00 03  bne  0xa0121f18
a0121f10:  82 10 20 00  clr  %g1
a0121f14:  82 10 20 01  mov  1, %g1
a0121f18:  81 c3 e0 08  retl
a0121f1c:  90 08 60 07  and  %g1, 7, %o0
