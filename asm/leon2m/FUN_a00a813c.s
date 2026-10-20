# leon2m FUN_a00a813c 0xa00a813c-0xa00a8230 (244 bytes)
a00a813c:  9d e3 bf 98  save  %sp, -104, %sp
a00a8140:  92 0e 20 ff  and  %i0, 0xff, %o1
a00a8144:  80 a0 00 09  cmp  %g0, %o1
a00a8148:  9e 60 20 00  subx  %g0, 0, %o7
a00a814c:  b2 0e 60 ff  and  %i1, 0xff, %i1
a00a8150:  82 0b ff d5  and  %o7, -43, %g1
a00a8154:  94 06 40 19  add  %i1, %i1, %o2
a00a8158:  a4 00 60 3a  add  %g1, 0x3a, %l2
a00a815c:  90 10 20 00  clr  %o0
a00a8160:  96 10 20 01  mov  1, %o3
a00a8164:  9a 10 20 00  clr  %o5
a00a8168:  98 10 20 00  clr  %o4
a00a816c:  b0 10 20 00  clr  %i0
a00a8170:  b6 10 20 01  mov  1, %i3
a00a8174:  ba 10 20 00  clr  %i5
a00a8178:  b8 10 20 00  clr  %i4
a00a817c:  94 02 a0 06  add  %o2, 6, %o2
a00a8180:  9e 10 00 1a  mov  %i2, %o7
a00a8184:  80 a6 60 06  cmp  %i1, 6
a00a8188:  a0 10 20 28  mov  0x28, %l0
a00a818c:  08 80 00 03  bleu  0xa00a8198
a00a8190:  82 06 40 19  add  %i1, %i1, %g1
a00a8194:  94 00 7f f8  add  %g1, -8, %o2
a00a8198:  80 a2 60 01  cmp  %o1, 1
a00a819c:  02 80 00 05  be  0xa00a81b0
a00a81a0:  80 a2 60 02  cmp  %o1, 2
a00a81a4:  b2 06 40 19  add  %i1, %i1, %i1
a00a81a8:  02 80 00 1f  be  0xa00a8224
a00a81ac:  a0 10 20 14  mov  0x14, %l0
a00a81b0:  b4 0a a0 ff  and  %o2, 0xff, %i2
a00a81b4:  92 0c 20 3c  and  %l0, 0x3c, %o1
a00a81b8:  80 8b e0 ff  btst  0xff, %o7
a00a81bc:  02 80 00 0c  be  0xa00a81ec
a00a81c0:  94 10 00 1a  mov  %i2, %o2
a00a81c4:  40 02 7a 57  call  0xa0146b20
a00a81c8:  98 0c a0 ff  and  %l2, 0xff, %o4
a00a81cc:  92 0c 20 ff  and  %l0, 0xff, %o1
a00a81d0:  90 02 60 01  add  %o1, 1, %o0
a00a81d4:  b3 2a 20 10  sll  %o0, 0x10, %i1
a00a81d8:  b8 04 a0 01  add  %l2, 1, %i4
a00a81dc:  b3 36 60 10  srl  %i1, 0x10, %i1
a00a81e0:  b8 0f 20 ff  and  %i4, 0xff, %i4
a00a81e4:  40 02 7a 4f  call  0xa0146b20
a00a81e8:  81 e8 00 00  restore
a00a81ec:  96 10 20 01  mov  1, %o3
a00a81f0:  9a 10 20 00  clr  %o5
a00a81f4:  90 10 20 00  clr  %o0
a00a81f8:  92 0c 20 3c  and  %l0, 0x3c, %o1
a00a81fc:  40 02 7a 49  call  0xa0146b20
a00a8200:  94 10 00 1a  mov  %i2, %o2
a00a8204:  9a 0c 20 ff  and  %l0, 0xff, %o5
a00a8208:  98 03 60 01  add  %o5, 1, %o4
a00a820c:  97 2b 20 10  sll  %o4, 0x10, %o3
a00a8210:  b3 32 e0 10  srl  %o3, 0x10, %i1
a00a8214:  b0 10 20 00  clr  %i0
a00a8218:  b6 10 20 01  mov  1, %i3
a00a821c:  40 02 7a 41  call  0xa0146b20
a00a8220:  9b e8 20 00  restore  %g0, 0, %o5
a00a8224:  94 06 60 06  add  %i1, 6, %o2
a00a8228:  10 bf ff e2  b  0xa00a81b0
a00a822c:  a0 10 20 28  mov  0x28, %l0
