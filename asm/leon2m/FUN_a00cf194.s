# leon2m FUN_a00cf194 0xa00cf194-0xa00cf1ec (88 bytes)
a00cf194:  90 0a 20 ff  and  %o0, 0xff, %o0
a00cf198:  80 a2 20 06  cmp  %o0, 6
a00cf19c:  02 80 00 0f  be  0xa00cf1d8
a00cf1a0:  82 10 20 00  clr  %g1
a00cf1a4:  80 a2 20 06  cmp  %o0, 6
a00cf1a8:  14 80 00 07  bg  0xa00cf1c4
a00cf1ac:  80 a2 20 08  cmp  %o0, 8
a00cf1b0:  80 a2 20 05  cmp  %o0, 5
a00cf1b4:  12 80 00 0c  bne  0xa00cf1e4
a00cf1b8:  01 00 00 00  nop
a00cf1bc:  10 80 00 0a  b  0xa00cf1e4
a00cf1c0:  82 10 20 01  mov  1, %g1	! 0x1
a00cf1c4:  02 80 00 07  be  0xa00cf1e0
a00cf1c8:  80 a2 20 0b  cmp  %o0, 0xb
a00cf1cc:  22 80 00 06  be,a   0xa00cf1e4
a00cf1d0:  82 10 20 17  mov  0x17, %g1
a00cf1d4:  30 80 00 04  b,a   0xa00cf1e4
a00cf1d8:  10 80 00 03  b  0xa00cf1e4
a00cf1dc:  82 10 20 04  mov  4, %g1
a00cf1e0:  82 10 20 07  mov  7, %g1
a00cf1e4:  81 c3 e0 08  retl
a00cf1e8:  90 08 60 17  and  %g1, 0x17, %o0
