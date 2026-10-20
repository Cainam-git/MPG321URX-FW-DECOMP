# leon2s FUN_a006d5a8 0xa006d5a8-0xa006d61c (116 bytes)
a006d5a8:  90 0a 20 ff  and  %o0, 0xff, %o0
a006d5ac:  80 a2 20 51  cmp  %o0, 0x51
a006d5b0:  02 80 00 16  be  0xa006d608
a006d5b4:  82 10 20 00  clr  %g1
a006d5b8:  80 a2 20 51  cmp  %o0, 0x51
a006d5bc:  14 80 00 08  bg  0xa006d5dc
a006d5c0:  80 a2 20 71  cmp  %o0, 0x71
a006d5c4:  80 a2 20 31  cmp  %o0, 0x31
a006d5c8:  02 80 00 13  be  0xa006d614
a006d5cc:  80 a2 20 41  cmp  %o0, 0x41
a006d5d0:  22 80 00 11  be,a   0xa006d614
a006d5d4:  82 10 20 01  mov  1, %g1
a006d5d8:  30 80 00 0f  b,a   0xa006d614
a006d5dc:  02 80 00 0d  be  0xa006d610
a006d5e0:  80 a2 20 71  cmp  %o0, 0x71
a006d5e4:  14 80 00 06  bg  0xa006d5fc
a006d5e8:  80 a2 20 81  cmp  %o0, 0x81
a006d5ec:  80 a2 20 61  cmp  %o0, 0x61
a006d5f0:  22 80 00 09  be,a   0xa006d614
a006d5f4:  82 10 20 03  mov  3, %g1
a006d5f8:  30 80 00 07  b,a   0xa006d614
a006d5fc:  22 80 00 06  be,a   0xa006d614
a006d600:  82 10 20 05  mov  5, %g1
a006d604:  30 80 00 04  b,a   0xa006d614
a006d608:  10 80 00 03  b  0xa006d614
a006d60c:  82 10 20 02  mov  2, %g1
a006d610:  82 10 20 04  mov  4, %g1
a006d614:  81 c3 e0 08  retl
a006d618:  90 08 60 07  and  %g1, 7, %o0
