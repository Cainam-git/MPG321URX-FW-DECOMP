# leon2m FUN_a014a060 0xa014a060-0xa014a0d8 (120 bytes)
a014a060:  9d e3 bf 98  save  %sp, -104, %sp
a014a064:  b0 0e 20 ff  and  %i0, 0xff, %i0
a014a068:  80 a6 20 01  cmp  %i0, 1
a014a06c:  02 80 00 0b  be  0xa014a098
a014a070:  82 10 20 01  mov  1, %g1
a014a074:  80 a6 20 01  cmp  %i0, 1
a014a078:  04 80 00 13  ble  0xa014a0c4
a014a07c:  80 a6 20 02  cmp  %i0, 2
a014a080:  02 80 00 06  be  0xa014a098
a014a084:  82 10 20 02  mov  2, %g1
a014a088:  80 a6 20 03  cmp  %i0, 3
a014a08c:  02 80 00 03  be  0xa014a098
a014a090:  82 10 20 03  mov  3, %g1
a014a094:  82 10 3f ff  mov  -1, %g1
a014a098:  b0 08 60 ff  and  %g1, 0xff, %i0
a014a09c:  80 a6 20 03  cmp  %i0, 3
a014a0a0:  38 80 00 04  bgu,a   0xa014a0b0
a014a0a4:  11 00 06 9b  sethi  %hi(0x1a6c00), %o0
a014a0a8:  7f ff 94 51  call  0xa012f1ec
a014a0ac:  93 e8 20 03  restore  %g0, 3, %o1
a014a0b0:  7f fe 54 30  call  0xa00df170
a014a0b4:  90 12 21 d8  or  %o0, 0x1d8, %o0
a014a0b8:  b0 10 20 00  clr  %i0
a014a0bc:  7f ff 94 4c  call  0xa012f1ec
a014a0c0:  93 e8 20 03  restore  %g0, 3, %o1
a014a0c4:  80 a6 20 00  cmp  %i0, 0
a014a0c8:  02 bf ff f4  be  0xa014a098
a014a0cc:  82 10 20 00  clr  %g1
a014a0d0:  10 bf ff f2  b  0xa014a098
a014a0d4:  82 10 3f ff  mov  -1, %g1
