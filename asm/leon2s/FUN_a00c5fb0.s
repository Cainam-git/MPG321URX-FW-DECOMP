# leon2s FUN_a00c5fb0 0xa00c5fb0-0xa00c601c (108 bytes)
a00c5fb0:  90 0a 20 ff  and  %o0, 0xff, %o0
a00c5fb4:  80 a2 20 51  cmp  %o0, 0x51
a00c5fb8:  02 80 00 17  be  0xa00c6014
a00c5fbc:  82 10 20 02  mov  2, %g1
a00c5fc0:  80 a2 20 51  cmp  %o0, 0x51
a00c5fc4:  14 80 00 08  bg  0xa00c5fe4
a00c5fc8:  80 a2 20 71  cmp  %o0, 0x71
a00c5fcc:  80 a2 20 31  cmp  %o0, 0x31
a00c5fd0:  02 80 00 11  be  0xa00c6014
a00c5fd4:  82 10 20 00  clr  %g1
a00c5fd8:  80 a2 20 41  cmp  %o0, 0x41
a00c5fdc:  10 80 00 0b  b  0xa00c6008
a00c5fe0:  82 10 20 01  mov  1, %g1
a00c5fe4:  02 80 00 0c  be  0xa00c6014
a00c5fe8:  82 10 20 04  mov  4, %g1
a00c5fec:  80 a2 20 71  cmp  %o0, 0x71
a00c5ff0:  34 80 00 05  bg,a   0xa00c6004
a00c5ff4:  80 a2 20 81  cmp  %o0, 0x81
a00c5ff8:  80 a2 20 61  cmp  %o0, 0x61
a00c5ffc:  10 80 00 03  b  0xa00c6008
a00c6000:  82 10 20 03  mov  3, %g1
a00c6004:  82 10 20 05  mov  5, %g1
a00c6008:  02 80 00 03  be  0xa00c6014
a00c600c:  01 00 00 00  nop
a00c6010:  82 10 3f ff  mov  -1, %g1	! 0xffffffff
a00c6014:  81 c3 e0 08  retl
a00c6018:  90 08 60 ff  and  %g1, 0xff, %o0
