# leon2m FUN_a014e0d4 0xa014e0d4-0xa014e144 (112 bytes)
a014e0d4:  90 0a 20 ff  and  %o0, 0xff, %o0
a014e0d8:  80 a2 20 01  cmp  %o0, 1
a014e0dc:  22 80 00 0a  be,a   0xa014e104
a014e0e0:  90 10 20 00  clr  %o0
a014e0e4:  04 80 00 11  ble  0xa014e128
a014e0e8:  80 a2 20 02  cmp  %o0, 2
a014e0ec:  02 80 00 0a  be  0xa014e114
a014e0f0:  80 a2 20 03  cmp  %o0, 3
a014e0f4:  12 80 00 12  bne  0xa014e13c
a014e0f8:  90 10 20 01  mov  1, %o0
a014e0fc:  10 80 00 03  b  0xa014e108
a014e100:  92 10 20 01  mov  1, %o1
a014e104:  92 10 20 01  mov  1, %o1
a014e108:  82 13 c0 00  mov  %o7, %g1
a014e10c:  7f fe f3 2d  call  0xa010adc0
a014e110:  9e 10 40 00  mov  %g1, %o7
a014e114:  90 10 20 01  mov  1, %o0
a014e118:  92 10 20 00  clr  %o1
a014e11c:  82 13 c0 00  mov  %o7, %g1
a014e120:  7f fe f3 28  call  0xa010adc0
a014e124:  9e 10 40 00  mov  %g1, %o7
a014e128:  80 a2 20 00  cmp  %o0, 0
a014e12c:  12 80 00 04  bne  0xa014e13c
a014e130:  90 10 20 00  clr  %o0
a014e134:  10 bf ff fa  b  0xa014e11c
a014e138:  92 10 20 00  clr  %o1
a014e13c:  81 c3 e0 08  retl
a014e140:  01 00 00 00  nop
