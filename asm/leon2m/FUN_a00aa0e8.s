# leon2m FUN_a00aa0e8 0xa00aa0e8-0xa00aa258 (368 bytes)
a00aa0e8:  9d e3 bf 90  save  %sp, -112, %sp
a00aa0ec:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00aa0f0:  82 06 00 18  add  %i0, %i0, %g1
a00aa0f4:  92 00 7f f8  add  %g1, -8, %o1
a00aa0f8:  80 a6 20 06  cmp  %i0, 6
a00aa0fc:  18 80 00 03  bgu  0xa00aa108
a00aa100:  96 10 3f ff  mov  -1, %o3
a00aa104:  92 00 60 06  add  %g1, 6, %o1
a00aa108:  80 a6 20 02  cmp  %i0, 2
a00aa10c:  02 80 00 36  be  0xa00aa1e4
a00aa110:  80 a6 20 05  cmp  %i0, 5
a00aa114:  02 80 00 47  be  0xa00aa230
a00aa118:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00aa11c:  80 a6 20 06  cmp  %i0, 6
a00aa120:  02 80 00 47  be  0xa00aa23c
a00aa124:  19 2a 00 b5  sethi  %hi(0xa802d400), %o4
a00aa128:  82 1e 20 05  xor  %i0, 5, %g1
a00aa12c:  80 a0 00 01  cmp  %g0, %g1
a00aa130:  94 60 3f ff  subx  %g0, -1, %o2
a00aa134:  9e 1e 20 02  xor  %i0, 2, %o7
a00aa138:  80 a0 00 0f  cmp  %g0, %o7
a00aa13c:  90 60 3f ff  subx  %g0, -1, %o0
a00aa140:  80 92 80 08  orcc  %o2, %o0, %g0
a00aa144:  32 80 00 06  bne,a   0xa00aa15c
a00aa148:  b0 0e 60 ff  and  %i1, 0xff, %i0
a00aa14c:  80 a6 20 06  cmp  %i0, 6
a00aa150:  12 80 00 2d  bne  0xa00aa204
a00aa154:  90 10 20 01  mov  1, %o0
a00aa158:  b0 0e 60 ff  and  %i1, 0xff, %i0
a00aa15c:  80 a6 20 01  cmp  %i0, 1
a00aa160:  02 80 00 2e  be  0xa00aa218
a00aa164:  98 0a e0 ff  and  %o3, 0xff, %o4
a00aa168:  82 0a e0 ff  and  %o3, 0xff, %g1
a00aa16c:  9e 18 60 01  xor  %g1, 1, %o7
a00aa170:  80 a0 00 0f  cmp  %g0, %o7
a00aa174:  94 60 20 00  subx  %g0, 0, %o2
a00aa178:  90 0a be 00  and  %o2, -512, %o0
a00aa17c:  82 02 27 92  add  %o0, 0x792, %g1
a00aa180:  99 28 60 10  sll  %g1, 0x10, %o4
a00aa184:  95 33 20 10  srl  %o4, 0x10, %o2
a00aa188:  9a 1a a7 42  xor  %o2, 0x742, %o5
a00aa18c:  80 a0 00 0d  cmp  %g0, %o5
a00aa190:  b2 60 3f ff  subx  %g0, -1, %i1
a00aa194:  96 1a a7 92  xor  %o2, 0x792, %o3
a00aa198:  80 a0 00 0b  cmp  %g0, %o3
a00aa19c:  b0 60 3f ff  subx  %g0, -1, %i0
a00aa1a0:  80 96 40 18  orcc  %i1, %i0, %g0
a00aa1a4:  12 80 00 03  bne  0xa00aa1b0
a00aa1a8:  82 10 20 37  mov  0x37, %g1
a00aa1ac:  82 10 20 34  mov  0x34, %g1
a00aa1b0:  98 0a 60 fe  and  %o1, 0xfe, %o4
a00aa1b4:  c2 23 a0 5c  st  %g1, [ %sp + 0x5c ]
a00aa1b8:  90 10 20 01  mov  1, %o0
a00aa1bc:  92 10 20 01  mov  1, %o1
a00aa1c0:  96 10 20 22  mov  0x22, %o3
a00aa1c4:  40 00 24 48  call  0xa00b32e4
a00aa1c8:  9a 10 20 03  mov  3, %o5
a00aa1cc:  90 10 20 01  mov  1, %o0
a00aa1d0:  7f ff fc a6  call  0xa00a9468
a00aa1d4:  92 10 20 03  mov  3, %o1
a00aa1d8:  b0 10 20 00  clr  %i0
a00aa1dc:  40 00 24 be  call  0xa00b34d4
a00aa1e0:  93 e8 20 02  restore  %g0, 2, %o1
a00aa1e4:  03 2a 00 b5  sethi  %hi(0xa802d400), %g1
a00aa1e8:  d8 00 60 04  ld  [ %g1 + 4 ], %o4	! 0xa802d404
a00aa1ec:  1b 00 00 20  sethi  %hi(0x8000), %o5
a00aa1f0:  80 8b 00 0d  btst  %o4, %o5
a00aa1f4:  12 bf ff cd  bne  0xa00aa128
a00aa1f8:  96 10 20 01  mov  1, %o3
a00aa1fc:  10 bf ff cb  b  0xa00aa128
a00aa200:  96 10 20 00  clr  %o3
a00aa204:  7f ff fc 99  call  0xa00a9468
a00aa208:  92 10 20 02  mov  2, %o1
a00aa20c:  b0 10 20 00  clr  %i0
a00aa210:  40 00 24 b1  call  0xa00b34d4
a00aa214:  93 e8 20 01  restore  %g0, 1, %o1
a00aa218:  9a 1b 20 01  xor  %o4, 1, %o5
a00aa21c:  80 a0 00 0d  cmp  %g0, %o5
a00aa220:  96 60 20 00  subx  %g0, 0, %o3
a00aa224:  b2 0a fe 00  and  %o3, -512, %i1
a00aa228:  10 bf ff d6  b  0xa00aa180
a00aa22c:  82 06 67 42  add  %i1, 0x742, %g1
a00aa230:  d0 02 a3 38  ld  [ %o2 + 0x338 ], %o0
a00aa234:  10 bf ff f0  b  0xa00aa1f4
a00aa238:  80 8a 20 80  btst  0x80, %o0
a00aa23c:  c2 03 20 84  ld  [ %o4 + 0x84 ], %g1
a00aa240:  1b 20 00 00  sethi  %hi(0x80000000), %o5
a00aa244:  96 08 40 0d  and  %g1, %o5, %o3
a00aa248:  80 a0 00 0b  cmp  %g0, %o3
a00aa24c:  9e 40 20 00  addx  %g0, 0, %o7
a00aa250:  10 bf ff b6  b  0xa00aa128
a00aa254:  96 10 00 0f  mov  %o7, %o3
