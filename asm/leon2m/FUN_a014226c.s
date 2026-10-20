# leon2m FUN_a014226c 0xa014226c-0xa01422f4 (136 bytes)
a014226c:  82 0a 20 ff  and  %o0, 0xff, %g1
a0142270:  80 a0 60 51  cmp  %g1, 0x51
a0142274:  02 80 00 1e  be  0xa01422ec
a0142278:  90 10 20 02  mov  2, %o0
a014227c:  80 a0 60 51  cmp  %g1, 0x51
a0142280:  14 80 00 0f  bg  0xa01422bc
a0142284:  80 a0 60 81  cmp  %g1, 0x81
a0142288:  80 a0 60 21  cmp  %g1, 0x21
a014228c:  22 80 00 18  be,a   0xa01422ec
a0142290:  90 10 3f ff  mov  -1, %o0
a0142294:  24 80 00 16  ble,a   0xa01422ec
a0142298:  90 10 3f ff  mov  -1, %o0
a014229c:  80 a0 60 31  cmp  %g1, 0x31
a01422a0:  02 80 00 13  be  0xa01422ec
a01422a4:  90 10 20 00  clr  %o0
a01422a8:  80 a0 60 41  cmp  %g1, 0x41
a01422ac:  22 80 00 10  be,a   0xa01422ec
a01422b0:  90 10 20 01  mov  1, %o0
a01422b4:  10 80 00 0e  b  0xa01422ec
a01422b8:  90 10 3f ff  mov  -1, %o0
a01422bc:  02 80 00 0c  be  0xa01422ec
a01422c0:  90 10 20 01  mov  1, %o0
a01422c4:  80 a0 60 81  cmp  %g1, 0x81
a01422c8:  34 80 00 09  bg,a   0xa01422ec
a01422cc:  90 10 3f ff  mov  -1, %o0
a01422d0:  80 a0 60 61  cmp  %g1, 0x61
a01422d4:  02 80 00 06  be  0xa01422ec
a01422d8:  90 10 20 03  mov  3, %o0
a01422dc:  80 a0 60 71  cmp  %g1, 0x71
a01422e0:  02 80 00 03  be  0xa01422ec
a01422e4:  90 10 20 00  clr  %o0
a01422e8:  90 10 3f ff  mov  -1, %o0
a01422ec:  81 c3 e0 08  retl
a01422f0:  90 0a 20 ff  and  %o0, 0xff, %o0
