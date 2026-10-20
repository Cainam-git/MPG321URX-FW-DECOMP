# leon2m FUN_a01436b4 0xa01436b4-0xa0143700 (76 bytes)
a01436b4:  90 0a 20 ff  and  %o0, 0xff, %o0
a01436b8:  80 a2 20 01  cmp  %o0, 1
a01436bc:  02 80 00 0f  be  0xa01436f8
a01436c0:  82 10 20 01  mov  1, %g1
a01436c4:  80 a2 20 01  cmp  %o0, 1
a01436c8:  04 80 00 09  ble  0xa01436ec
a01436cc:  82 10 20 02  mov  2, %g1
a01436d0:  80 a2 20 02  cmp  %o0, 2
a01436d4:  02 80 00 09  be  0xa01436f8
a01436d8:  80 a2 20 03  cmp  %o0, 3
a01436dc:  82 10 20 03  mov  3, %g1
a01436e0:  32 80 00 06  bne,a   0xa01436f8
a01436e4:  82 10 3f ff  mov  -1, %g1
a01436e8:  30 80 00 04  b,a   0xa01436f8
a01436ec:  80 a2 20 00  cmp  %o0, 0
a01436f0:  10 bf ff fc  b  0xa01436e0
a01436f4:  82 10 20 00  clr  %g1
a01436f8:  81 c3 e0 08  retl
a01436fc:  90 08 60 ff  and  %g1, 0xff, %o0
