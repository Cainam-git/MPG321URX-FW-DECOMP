# leon2s FUN_a008e0f0 0xa008e0f0-0xa008e200 (272 bytes)
a008e0f0:  9d e3 bf 98  save  %sp, -104, %sp
a008e0f4:  b2 0e 60 ff  and  %i1, 0xff, %i1
a008e0f8:  80 a6 60 01  cmp  %i1, 1
a008e0fc:  02 80 00 0c  be  0xa008e12c
a008e100:  b6 10 20 00  clr  %i3
a008e104:  80 a6 60 01  cmp  %i1, 1
a008e108:  34 80 00 04  bg,a   0xa008e118
a008e10c:  b6 10 00 1a  mov  %i2, %i3
a008e110:  10 80 00 03  b  0xa008e11c
a008e114:  80 a6 60 00  cmp  %i1, 0
a008e118:  80 a6 60 03  cmp  %i1, 3
a008e11c:  22 80 00 06  be,a   0xa008e134
a008e120:  b0 0e 20 ff  and  %i0, 0xff, %i0
a008e124:  10 80 00 03  b  0xa008e130
a008e128:  b6 10 20 0f  mov  0xf, %i3
a008e12c:  b6 10 20 04  mov  4, %i3
a008e130:  b0 0e 20 ff  and  %i0, 0xff, %i0
a008e134:  92 10 20 01  mov  1, %o1
a008e138:  94 10 20 08  mov  8, %o2
a008e13c:  40 00 67 a7  call  0xa00a7fd8
a008e140:  90 10 00 18  mov  %i0, %o0
a008e144:  a0 0e e0 ff  and  %i3, 0xff, %l0
a008e148:  a1 2c 20 04  sll  %l0, 4, %l0
a008e14c:  96 0a 20 0f  and  %o0, 0xf, %o3
a008e150:  96 12 c0 10  or  %o3, %l0, %o3
a008e154:  96 0a e0 ff  and  %o3, 0xff, %o3
a008e158:  90 10 00 18  mov  %i0, %o0
a008e15c:  92 10 20 01  mov  1, %o1
a008e160:  40 00 67 bd  call  0xa00a8054
a008e164:  94 10 20 08  mov  8, %o2
a008e168:  92 10 20 01  mov  1, %o1
a008e16c:  94 10 20 98  mov  0x98, %o2
a008e170:  40 00 67 9a  call  0xa00a7fd8
a008e174:  90 10 00 18  mov  %i0, %o0
a008e178:  96 0a 3f f0  and  %o0, -16, %o3
a008e17c:  96 12 c0 1b  or  %o3, %i3, %o3
a008e180:  96 0a e0 ff  and  %o3, 0xff, %o3
a008e184:  90 10 00 18  mov  %i0, %o0
a008e188:  92 10 20 01  mov  1, %o1
a008e18c:  40 00 67 b2  call  0xa00a8054
a008e190:  94 10 20 98  mov  0x98, %o2
a008e194:  92 10 20 01  mov  1, %o1
a008e198:  94 10 20 98  mov  0x98, %o2
a008e19c:  40 00 67 8f  call  0xa00a7fd8
a008e1a0:  90 10 00 18  mov  %i0, %o0
a008e1a4:  96 0a 20 0f  and  %o0, 0xf, %o3
a008e1a8:  96 12 c0 10  or  %o3, %l0, %o3
a008e1ac:  96 0a e0 ff  and  %o3, 0xff, %o3
a008e1b0:  90 10 00 18  mov  %i0, %o0
a008e1b4:  92 10 20 01  mov  1, %o1
a008e1b8:  40 00 67 a7  call  0xa00a8054
a008e1bc:  94 10 20 98  mov  0x98, %o2
a008e1c0:  90 10 00 18  mov  %i0, %o0
a008e1c4:  92 10 20 01  mov  1, %o1
a008e1c8:  40 00 67 84  call  0xa00a7fd8
a008e1cc:  94 10 20 99  mov  0x99, %o2
a008e1d0:  80 a6 60 02  cmp  %i1, 2
a008e1d4:  12 80 00 05  bne  0xa008e1e8
a008e1d8:  90 0a 3f f0  and  %o0, -16, %o0
a008e1dc:  b6 12 20 08  or  %o0, 8, %i3
a008e1e0:  10 80 00 04  b  0xa008e1f0
a008e1e4:  b6 0e e0 f8  and  %i3, 0xf8, %i3
a008e1e8:  b6 12 00 1b  or  %o0, %i3, %i3
a008e1ec:  b6 0e e0 ff  and  %i3, 0xff, %i3
a008e1f0:  b2 10 20 01  mov  1, %i1
a008e1f4:  40 00 67 98  call  0xa00a8054
a008e1f8:  95 e8 20 99  restore  %g0, 0x99, %o2
a008e1fc:  01 00 00 00  nop
