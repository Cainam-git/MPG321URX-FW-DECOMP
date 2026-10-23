# leon2m FUN_a01423b0 0xa01423b0-0xa01423dc (44 bytes)
a01423b0:  90 0a 20 ff  and  %o0, 0xff, %o0
a01423b4:  80 a2 20 00  cmp  %o0, 0
a01423b8:  02 80 00 06  be  0xa01423d0
a01423bc:  82 10 20 03  mov  3, %g1
a01423c0:  80 a2 20 01  cmp  %o0, 1
a01423c4:  22 80 00 04  be,a   0xa01423d4
a01423c8:  82 10 20 01  mov  1, %g1
a01423cc:  30 80 00 02  b,a   0xa01423d4
a01423d0:  82 10 20 00  clr  %g1
a01423d4:  81 c3 e0 08  retl
a01423d8:  90 08 60 03  and  %g1, 3, %o0
