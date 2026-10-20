# leon2m FUN_a00b7188 0xa00b7188-0xa00b72cc (324 bytes)
a00b7188:  9d e3 bf 90  save  %sp, -112, %sp
a00b718c:  23 2a 00 b4  sethi  %hi(0xa802d000), %l1
a00b7190:  92 14 62 90  or  %l1, 0x290, %o1	! 0xa802d290
a00b7194:  da 0a 60 49  ldub  [ %o1 + 0x49 ], %o5
a00b7198:  91 2b 60 02  sll  %o5, 2, %o0
a00b719c:  82 02 00 0d  add  %o0, %o5, %g1
a00b71a0:  95 28 60 02  sll  %g1, 2, %o2
a00b71a4:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00b71a8:  90 10 20 2c  mov  0x2c, %o0
a00b71ac:  92 10 20 06  mov  6, %o1
a00b71b0:  94 0a a0 fc  and  %o2, 0xfc, %o2
a00b71b4:  96 10 20 06  mov  6, %o3
a00b71b8:  7f ff d1 0e  call  0xa00ab5f0
a00b71bc:  98 10 00 18  mov  %i0, %o4
a00b71c0:  a0 10 27 42  mov  0x742, %l0
a00b71c4:  90 10 20 01  mov  1, %o0
a00b71c8:  80 a6 20 00  cmp  %i0, 0
a00b71cc:  12 80 00 05  bne  0xa00b71e0
a00b71d0:  92 10 20 03  mov  3, %o1
a00b71d4:  a0 10 27 92  mov  0x792, %l0
a00b71d8:  90 10 20 01  mov  1, %o0
a00b71dc:  92 10 20 02  mov  2, %o1
a00b71e0:  7f ff c8 a2  call  0xa00a9468
a00b71e4:  b0 0c 27 d2  and  %l0, 0x7d2, %i0
a00b71e8:  90 10 20 28  mov  0x28, %o0
a00b71ec:  92 10 20 06  mov  6, %o1
a00b71f0:  94 10 20 03  mov  3, %o2
a00b71f4:  96 10 00 18  mov  %i0, %o3
a00b71f8:  40 02 3e 22  call  0xa0146a80
a00b71fc:  98 10 20 00  clr  %o4
a00b7200:  90 10 20 2b  mov  0x2b, %o0
a00b7204:  92 10 20 06  mov  6, %o1
a00b7208:  94 10 20 01  mov  1, %o2
a00b720c:  96 10 00 18  mov  %i0, %o3
a00b7210:  40 02 3e 1c  call  0xa0146a80
a00b7214:  98 10 20 00  clr  %o4
a00b7218:  9a 10 20 00  clr  %o5
a00b721c:  90 10 20 00  clr  %o0
a00b7220:  92 10 20 2b  mov  0x2b, %o1
a00b7224:  94 10 20 06  mov  6, %o2
a00b7228:  96 10 20 01  mov  1, %o3
a00b722c:  40 02 3e 3d  call  0xa0146b20
a00b7230:  98 10 20 3f  mov  0x3f, %o4
a00b7234:  96 10 00 18  mov  %i0, %o3
a00b7238:  90 10 20 32  mov  0x32, %o0
a00b723c:  92 10 20 06  mov  6, %o1
a00b7240:  94 10 20 01  mov  1, %o2
a00b7244:  40 02 3e 0f  call  0xa0146a80
a00b7248:  98 10 20 00  clr  %o4
a00b724c:  9a 10 20 00  clr  %o5
a00b7250:  96 10 20 01  mov  1, %o3
a00b7254:  98 10 20 40  mov  0x40, %o4
a00b7258:  94 10 20 06  mov  6, %o2
a00b725c:  90 10 20 00  clr  %o0
a00b7260:  40 02 3e 30  call  0xa0146b20
a00b7264:  92 10 20 32  mov  0x32, %o1
a00b7268:  90 10 20 e6  mov  0xe6, %o0
a00b726c:  40 02 3e 39  call  0xa0146b50
a00b7270:  92 10 20 00  clr  %o1
a00b7274:  19 00 06 60  sethi  %hi(0x198000), %o4
a00b7278:  9e 14 62 90  or  %l1, 0x290, %o7
a00b727c:  a0 07 bf f0  add  %fp, -16, %l0
a00b7280:  92 13 21 d0  or  %o4, 0x1d0, %o1
a00b7284:  d4 0b e0 49  ldub  [ %o7 + 0x49 ], %o2
a00b7288:  40 02 81 5b  call  0xa01577f4
a00b728c:  90 10 00 10  mov  %l0, %o0
a00b7290:  96 10 20 03  mov  3, %o3
a00b7294:  d6 2f bf f0  stb  %o3, [ %fp + -16 ]
a00b7298:  90 10 20 02  mov  2, %o0
a00b729c:  40 02 3e 34  call  0xa0146b6c
a00b72a0:  92 10 20 00  clr  %o1
a00b72a4:  98 10 00 10  mov  %l0, %o4
a00b72a8:  90 10 20 00  clr  %o0
a00b72ac:  92 10 20 28  mov  0x28, %o1
a00b72b0:  94 10 20 06  mov  6, %o2
a00b72b4:  96 10 20 02  mov  2, %o3
a00b72b8:  7f ff af bb  call  0xa00a31a4
a00b72bc:  9a 10 20 00  clr  %o5
a00b72c0:  01 00 00 00  nop
a00b72c4:  81 c7 e0 08  ret
a00b72c8:  81 e8 00 00  restore
