# leon2m FUN_a009811c 0xa009811c-0xa0098280 (356 bytes)
a009811c:  9d e3 bf 80  save  %sp, -128, %sp
a0098120:  15 00 04 20  sethi  %hi(0x108000), %o2
a0098124:  40 01 1c 13  call  0xa00df170
a0098128:  90 12 a1 30  or  %o2, 0x130, %o0	! 0x108130
a009812c:  40 02 c0 94  call  0xa014837c
a0098130:  90 10 20 00  clr  %o0
a0098134:  b0 10 00 08  mov  %o0, %i0
a0098138:  23 2a 00 b3  sethi  %hi(0xa802cc00), %l1
a009813c:  40 02 c0 90  call  0xa014837c
a0098140:  90 10 20 01  mov  1, %o0
a0098144:  b4 14 63 f4  or  %l1, 0x3f4, %i2
a0098148:  da 16 a0 04  lduh  [ %i2 + 4 ], %o5
a009814c:  13 3f ff e0  sethi  %hi(0xffff8000), %o1
a0098150:  a0 10 00 08  mov  %o0, %l0
a0098154:  90 0b 40 09  and  %o5, %o1, %o0
a0098158:  83 2a 20 10  sll  %o0, 0x10, %g1
a009815c:  33 2a 00 ab  sethi  %hi(0xa802ac00), %i1
a0098160:  9a 13 64 00  or  %o5, 0x400, %o5
a0098164:  80 a0 60 00  cmp  %g1, 0
a0098168:  92 10 20 00  clr  %o1
a009816c:  12 80 00 42  bne  0xa0098274
a0098170:  90 10 20 04  mov  4, %o0
a0098174:  40 00 73 c3  call  0xa00b5080
a0098178:  c0 26 63 ec  clr  [ %i1 + 0x3ec ]
a009817c:  67 ff d8 4a  call  0x4008e2a4
a0098180:  01 00 00 00  nop
a0098184:  67 ff d8 48  call  0x4008e2a4
a0098188:  01 00 00 00  nop
a009818c:  40 00 37 37  call  0xa00a5e68
a0098190:  90 10 20 01  mov  1, %o0	! 0x1
a0098194:  96 10 21 09  mov  0x109, %o3
a0098198:  d6 26 63 ec  st  %o3, [ %i1 + 0x3ec ]
a009819c:  90 10 20 06  mov  6, %o0
a00981a0:  92 10 20 00  clr  %o1
a00981a4:  40 02 ba a7  call  0xa0146c40
a00981a8:  94 10 20 00  clr  %o2
a00981ac:  90 10 20 06  mov  6, %o0
a00981b0:  96 10 20 00  clr  %o3
a00981b4:  98 10 20 00  clr  %o4
a00981b8:  c0 23 a0 5c  clr  [ %sp + 0x5c ]
a00981bc:  c0 23 a0 60  clr  [ %sp + 0x60 ]
a00981c0:  c0 23 a0 64  clr  [ %sp + 0x64 ]
a00981c4:  c0 23 a0 68  clr  [ %sp + 0x68 ]
a00981c8:  c0 23 a0 6c  clr  [ %sp + 0x6c ]
a00981cc:  92 10 20 00  clr  %o1
a00981d0:  94 10 20 00  clr  %o2
a00981d4:  40 02 b9 2a  call  0xa014667c
a00981d8:  9a 10 20 02  mov  2, %o5
a00981dc:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00981e0:  96 10 62 90  or  %g1, 0x290, %o3	! 0xa802d290
a00981e4:  99 2e 20 10  sll  %i0, 0x10, %o4
a00981e8:  f2 02 e1 ec  ld  [ %o3 + 0x1ec ], %i1
a00981ec:  b0 10 20 02  mov  2, %i0
a00981f0:  9e 10 20 02  mov  2, %o7
a00981f4:  80 8e 60 40  btst  0x40, %i1
a00981f8:  f0 2a e0 2f  stb  %i0, [ %o3 + 0x2f ]
a00981fc:  de 2e a0 34  stb  %o7, [ %i2 + 0x34 ]
a0098200:  02 80 00 1a  be  0xa0098268
a0098204:  91 33 20 11  srl  %o4, 0x11, %o0
a0098208:  da 12 e1 f2  lduh  [ %o3 + 0x1f2 ], %o5
a009820c:  e0 12 e1 f0  lduh  [ %o3 + 0x1f0 ], %l0
a0098210:  da 36 a0 38  sth  %o5, [ %i2 + 0x38 ]
a0098214:  e0 36 a0 36  sth  %l0, [ %i2 + 0x36 ]
a0098218:  b4 14 63 f4  or  %l1, 0x3f4, %i2
a009821c:  d4 16 a0 36  lduh  [ %i2 + 0x36 ], %o2
a0098220:  92 02 a0 04  add  %o2, 4, %o1
a0098224:  91 2a 60 10  sll  %o1, 0x10, %o0
a0098228:  97 32 20 10  srl  %o0, 0x10, %o3
a009822c:  d2 16 a0 36  lduh  [ %i2 + 0x36 ], %o1
a0098230:  d8 16 a0 38  lduh  [ %i2 + 0x38 ], %o4
a0098234:  90 10 20 06  mov  6, %o0
a0098238:  94 10 20 00  clr  %o2
a009823c:  40 02 b9 8d  call  0xa0146870
a0098240:  9a 10 20 00  clr  %o5
a0098244:  23 00 04 20  sethi  %hi(0x108000), %l1
a0098248:  d4 16 a0 38  lduh  [ %i2 + 0x38 ], %o2
a009824c:  d2 16 a0 36  lduh  [ %i2 + 0x36 ], %o1
a0098250:  40 01 1b c8  call  0xa00df170
a0098254:  90 14 61 40  or  %l1, 0x140, %o0
a0098258:  b0 10 20 06  mov  6, %i0
a009825c:  b2 10 20 01  mov  1, %i1
a0098260:  40 02 ba 78  call  0xa0146c40
a0098264:  95 e8 20 00  restore  %g0, 0, %o2
a0098268:  e0 36 a0 38  sth  %l0, [ %i2 + 0x38 ]
a009826c:  10 bf ff eb  b  0xa0098218
a0098270:  d0 36 a0 36  sth  %o0, [ %i2 + 0x36 ]
a0098274:  7f ff a1 8e  call  0xa00808ac
a0098278:  da 36 a0 04  sth  %o5, [ %i2 + 4 ]
a009827c:  30 bf ff be  b,a   0xa0098174
