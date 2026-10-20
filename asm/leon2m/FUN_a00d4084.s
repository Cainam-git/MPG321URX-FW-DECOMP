# leon2m FUN_a00d4084 0xa00d4084-0xa00d40c4 (64 bytes)
a00d4084:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00d4088:  98 10 62 90  or  %g1, 0x290, %o4	! 0xa802d290
a00d408c:  da 0b 20 49  ldub  [ %o4 + 0x49 ], %o5
a00d4090:  90 10 20 00  clr  %o0
a00d4094:  80 a3 60 05  cmp  %o5, 5
a00d4098:  08 80 00 03  bleu  0xa00d40a4
a00d409c:  92 10 20 0d  mov  0xd, %o1
a00d40a0:  9a 10 20 05  mov  5, %o5
a00d40a4:  82 0b 60 ff  and  %o5, 0xff, %g1
a00d40a8:  94 00 40 01  add  %g1, %g1, %o2
a00d40ac:  94 02 80 01  add  %o2, %g1, %o2
a00d40b0:  da 2b 20 49  stb  %o5, [ %o4 + 0x49 ]
a00d40b4:  94 0a a0 ff  and  %o2, 0xff, %o2
a00d40b8:  82 13 c0 00  mov  %o7, %g1
a00d40bc:  40 01 cc 39  call  0xa01471a0
a00d40c0:  9e 10 40 00  mov  %g1, %o7
