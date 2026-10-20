# leon2s FUN_a0086154 0xa0086154-0xa00862e4 (400 bytes)
a0086154:  9d e3 bf 98  save  %sp, -104, %sp
a0086158:  b2 0e 60 ff  and  %i1, 0xff, %i1
a008615c:  82 1e 60 80  xor  %i1, 0x80, %g1
a0086160:  80 a0 00 01  cmp  %g0, %g1
a0086164:  9a 60 3f ff  subx  %g0, -1, %o5
a0086168:  82 1e 60 40  xor  %i1, 0x40, %g1
a008616c:  80 a0 00 01  cmp  %g0, %g1
a0086170:  82 60 3f ff  subx  %g0, -1, %g1
a0086174:  80 93 40 01  orcc  %o5, %g1, %g0
a0086178:  12 80 00 06  bne  0xa0086190
a008617c:  a2 10 20 01  mov  1, %l1
a0086180:  80 a6 60 00  cmp  %i1, 0
a0086184:  12 80 00 03  bne  0xa0086190
a0086188:  a2 06 a0 02  add  %i2, 2, %l1
a008618c:  a2 10 20 01  mov  1, %l1
a0086190:  25 2a 01 e2  sethi  %hi(0xa8078800), %l2
a0086194:  29 2a 01 f3  sethi  %hi(0xa807cc00), %l4
a0086198:  82 10 3f ff  mov  -1, %g1
a008619c:  c2 2d 21 50  stb  %g1, [ %l4 + 0x150 ]
a00861a0:  10 80 00 13  b  0xa00861ec
a00861a4:  c0 2c a2 0e  clrb  [ %l2 + 0x20e ]
a00861a8:  c2 0c a2 0e  ldub  [ %l2 + 0x20e ], %g1
a00861ac:  b4 08 60 ff  and  %g1, 0xff, %i2
a00861b0:  80 a6 80 0c  cmp  %i2, %o4
a00861b4:  16 80 00 06  bge  0xa00861cc
a00861b8:  9a 00 60 01  add  %g1, 1, %o5
a00861bc:  40 00 85 be  call  0xa00a78b4
a00861c0:  da 2c a2 0e  stb  %o5, [ %l2 + 0x20e ]
a00861c4:  10 80 00 05  b  0xa00861d8
a00861c8:  d0 2c c0 1a  stb  %o0, [ %l3 + %i2 ]
a00861cc:  92 10 20 37  mov  0x37, %o1
a00861d0:  40 00 85 b9  call  0xa00a78b4
a00861d4:  90 10 00 10  mov  %l0, %o0
a00861d8:  90 10 00 10  mov  %l0, %o0
a00861dc:  92 10 20 34  mov  0x34, %o1
a00861e0:  94 10 20 08  mov  8, %o2
a00861e4:  40 00 85 d7  call  0xa00a7940
a00861e8:  96 10 20 01  mov  1, %o3
a00861ec:  a0 0e 20 ff  and  %i0, 0xff, %l0
a00861f0:  92 10 20 34  mov  0x34, %o1
a00861f4:  40 00 85 b0  call  0xa00a78b4
a00861f8:  90 10 00 10  mov  %l0, %o0
a00861fc:  83 2c 60 18  sll  %l1, 0x18, %g1
a0086200:  80 8a 20 08  btst  8, %o0
a0086204:  92 10 20 37  mov  0x37, %o1
a0086208:  99 38 60 18  sra  %g1, 0x18, %o4
a008620c:  a6 15 21 50  or  %l4, 0x150, %l3
a0086210:  12 bf ff e6  bne  0xa00861a8
a0086214:  90 10 00 10  mov  %l0, %o0
a0086218:  19 2a 01 f3  sethi  %hi(0xa807cc00), %o4
a008621c:  c2 0b 21 50  ldub  [ %o4 + 0x150 ], %g1	! 0xa807cd50
a0086220:  80 a0 60 00  cmp  %g1, 0
a0086224:  12 80 00 2a  bne  0xa00862cc
a0086228:  82 18 60 20  xor  %g1, 0x20, %g1
a008622c:  82 1e 60 80  xor  %i1, 0x80, %g1
a0086230:  80 a0 00 01  cmp  %g0, %g1
a0086234:  9a 60 3f ff  subx  %g0, -1, %o5
a0086238:  82 1e 60 40  xor  %i1, 0x40, %g1
a008623c:  80 a0 00 01  cmp  %g0, %g1
a0086240:  82 60 3f ff  subx  %g0, -1, %g1
a0086244:  80 93 40 01  orcc  %o5, %g1, %g0
a0086248:  12 80 00 06  bne  0xa0086260
a008624c:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a0086250:  80 a6 60 00  cmp  %i1, 0
a0086254:  12 80 00 09  bne  0xa0086278
a0086258:  83 2c 60 18  sll  %l1, 0x18, %g1
a008625c:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a0086260:  c2 08 62 0e  ldub  [ %g1 + 0x20e ], %g1	! 0xa8078a0e
a0086264:  82 18 60 01  xor  %g1, 1, %g1
a0086268:  80 a0 00 01  cmp  %g0, %g1
a008626c:  82 60 20 00  subx  %g0, 0, %g1
a0086270:  10 80 00 1b  b  0xa00862dc
a0086274:  b0 08 60 ff  and  %g1, 0xff, %i0
a0086278:  1b 2a 01 e2  sethi  %hi(0xa8078800), %o5
a008627c:  da 0b 62 0e  ldub  [ %o5 + 0x20e ], %o5	! 0xa8078a0e
a0086280:  97 38 60 18  sra  %g1, 0x18, %o3
a0086284:  80 a3 40 0b  cmp  %o5, %o3
a0086288:  12 80 00 15  bne  0xa00862dc
a008628c:  b0 10 20 ff  mov  0xff, %i0
a0086290:  80 a2 e0 01  cmp  %o3, 1
a0086294:  04 80 00 0c  ble  0xa00862c4
a0086298:  94 10 20 01  mov  1, %o2
a008629c:  92 13 21 50  or  %o4, 0x150, %o1
a00862a0:  82 0a a0 ff  and  %o2, 0xff, %g1
a00862a4:  d8 0a 40 01  ldub  [ %o1 + %g1 ], %o4
a00862a8:  94 02 a0 01  inc  %o2
a00862ac:  82 06 c0 01  add  %i3, %g1, %g1
a00862b0:  9a 0a a0 ff  and  %o2, 0xff, %o5
a00862b4:  d8 28 7f ff  stb  %o4, [ %g1 + -1 ]
a00862b8:  80 a3 40 0b  cmp  %o5, %o3
a00862bc:  06 bf ff fa  bl  0xa00862a4
a00862c0:  82 0a a0 ff  and  %o2, 0xff, %g1
a00862c4:  10 80 00 06  b  0xa00862dc
a00862c8:  b0 10 20 00  clr  %i0
a00862cc:  80 a0 00 01  cmp  %g0, %g1
a00862d0:  82 60 20 00  subx  %g0, 0, %g1
a00862d4:  b0 08 60 df  and  %g1, 0xdf, %i0
a00862d8:  b0 06 20 20  add  %i0, 0x20, %i0
a00862dc:  81 c7 e0 08  ret
a00862e0:  81 e8 00 00  restore
