# leon2s FUN_a0087110 0xa0087110-0xa0087364 (596 bytes)
a0087110:  9d e3 bf 90  save  %sp, -112, %sp
a0087114:  ac 10 20 00  clr  %l6
a0087118:  80 8e 20 ff  btst  0xff, %i0
a008711c:  c0 2f bf f6  clrb  [ %fp + -10 ]
a0087120:  c0 2f bf f7  clrb  [ %fp + -9 ]
a0087124:  b0 10 20 01  mov  1, %i0
a0087128:  a6 10 20 00  clr  %l3
a008712c:  02 80 00 06  be  0xa0087144
a0087130:  a8 10 00 16  mov  %l6, %l4
a0087134:  03 2a 01 d8  sethi  %hi(0xa8076000), %g1
a0087138:  e8 08 61 c0  ldub  [ %g1 + 0x1c0 ], %l4	! 0xa80761c0
a008713c:  03 2a 01 d8  sethi  %hi(0xa8076000), %g1
a0087140:  e6 08 61 bf  ldub  [ %g1 + 0x1bf ], %l3	! 0xa80761bf
a0087144:  a2 0d 20 ff  and  %l4, 0xff, %l1
a0087148:  aa 0c e0 ff  and  %l3, 0xff, %l5
a008714c:  a4 10 00 14  mov  %l4, %l2
a0087150:  80 a4 40 15  cmp  %l1, %l5
a0087154:  a0 10 00 11  mov  %l1, %l0
a0087158:  18 80 00 20  bgu  0xa00871d8
a008715c:  90 10 00 10  mov  %l0, %o0
a0087160:  c2 0e c0 00  ldub  [ %i3 ], %g1
a0087164:  83 38 40 10  sra  %g1, %l0, %g1
a0087168:  92 10 20 00  clr  %o1
a008716c:  80 88 60 01  btst  1, %g1
a0087170:  02 80 00 17  be  0xa00871cc
a0087174:  a4 04 a0 01  inc  %l2
a0087178:  40 00 8d ee  call  0xa00aa930
a008717c:  01 00 00 00  nop
a0087180:  90 10 00 10  mov  %l0, %o0
a0087184:  92 10 20 00  clr  %o1
a0087188:  40 00 8f 83  call  0xa00aaf94
a008718c:  d4 0f bf f6  ldub  [ %fp + -10 ], %o2
a0087190:  90 10 00 10  mov  %l0, %o0
a0087194:  92 10 20 00  clr  %o1
a0087198:  d4 0e 40 00  ldub  [ %i1 ], %o2
a008719c:  96 10 20 00  clr  %o3
a00871a0:  7f ff fc a3  call  0xa008642c
a00871a4:  98 10 20 00  clr  %o4
a00871a8:  82 10 20 01  mov  1, %g1
a00871ac:  80 8a 20 ff  btst  0xff, %o0
a00871b0:  12 80 00 07  bne  0xa00871cc
a00871b4:  9b 28 40 10  sll  %g1, %l0, %o5
a00871b8:  c2 0e c0 00  ldub  [ %i3 ], %g1
a00871bc:  82 28 40 0d  andn  %g1, %o5, %g1
a00871c0:  80 a4 20 00  cmp  %l0, 0
a00871c4:  02 80 00 56  be  0xa008731c
a00871c8:  c2 2e c0 00  stb  %g1, [ %i3 ]
a00871cc:  a0 0c a0 ff  and  %l2, 0xff, %l0
a00871d0:  10 bf ff e2  b  0xa0087158
a00871d4:  80 a4 00 15  cmp  %l0, %l5
a00871d8:  9a 10 00 11  mov  %l1, %o5
a00871dc:  aa 0c e0 ff  and  %l3, 0xff, %l5
a00871e0:  a4 10 00 14  mov  %l4, %l2
a00871e4:  80 a3 40 15  cmp  %o5, %l5
a00871e8:  38 80 00 5d  bgu,a   0xa008735c
a00871ec:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00871f0:  c2 0e c0 00  ldub  [ %i3 ], %g1
a00871f4:  83 38 40 0d  sra  %g1, %o5, %g1
a00871f8:  80 88 60 01  btst  1, %g1
a00871fc:  22 80 00 56  be,a   0xa0087354
a0087200:  a4 04 a0 01  inc  %l2
a0087204:  83 2b 60 04  sll  %o5, 4, %g1
a0087208:  a6 06 80 01  add  %i2, %g1, %l3
a008720c:  a8 10 20 01  mov  1, %l4
a0087210:  a2 0c a0 ff  and  %l2, 0xff, %l1
a0087214:  82 04 40 11  add  %l1, %l1, %g1
a0087218:  82 00 40 11  add  %g1, %l1, %g1
a008721c:  1b 2a 01 f3  sethi  %hi(0xa807cc00), %o5
a0087220:  9a 13 61 2e  or  %o5, 0x12e, %o5	! 0xa807cd2e
a0087224:  82 00 40 01  add  %g1, %g1, %g1
a0087228:  82 00 40 0d  add  %g1, %o5, %g1
a008722c:  40 00 a9 5a  call  0xa00b1794
a0087230:  d0 08 60 05  ldub  [ %g1 + 5 ], %o0
a0087234:  92 10 00 13  mov  %l3, %o1
a0087238:  7f ff ff 08  call  0xa0086e58
a008723c:  90 10 00 11  mov  %l1, %o0
a0087240:  c2 0c c0 00  ldub  [ %l3 ], %g1
a0087244:  80 88 60 80  btst  0x80, %g1
a0087248:  12 80 00 0b  bne  0xa0087274
a008724c:  92 10 00 13  mov  %l3, %o1
a0087250:  82 10 20 01  mov  1, %g1
a0087254:  da 0e c0 00  ldub  [ %i3 ], %o5
a0087258:  83 28 40 11  sll  %g1, %l1, %g1
a008725c:  82 2b 40 01  andn  %o5, %g1, %g1
a0087260:  80 a4 60 00  cmp  %l1, 0
a0087264:  12 80 00 3b  bne  0xa0087350
a0087268:  c2 2e c0 00  stb  %g1, [ %i3 ]
a008726c:  10 80 00 3c  b  0xa008735c
a0087270:  b0 10 20 02  mov  2, %i0
a0087274:  e0 0e 40 00  ldub  [ %i1 ], %l0
a0087278:  7f ff ff 8b  call  0xa00870a4
a008727c:  90 10 00 10  mov  %l0, %o0
a0087280:  82 0a 20 ff  and  %o0, 0xff, %g1
a0087284:  92 10 00 10  mov  %l0, %o1
a0087288:  96 07 bf f6  add  %fp, -10, %o3
a008728c:  94 07 bf f7  add  %fp, -9, %o2
a0087290:  80 a0 60 04  cmp  %g1, 4
a0087294:  12 80 00 04  bne  0xa00872a4
a0087298:  90 10 00 13  mov  %l3, %o0
a008729c:  10 80 00 2d  b  0xa0087350
a00872a0:  b0 10 20 04  mov  4, %i0
a00872a4:  7f ff ff 43  call  0xa0086fb0
a00872a8:  01 00 00 00  nop
a00872ac:  d8 0f bf f7  ldub  [ %fp + -9 ], %o4
a00872b0:  a0 0b 20 ff  and  %o4, 0xff, %l0
a00872b4:  9a 0d a0 ff  and  %l6, 0xff, %o5
a00872b8:  90 10 00 11  mov  %l1, %o0
a00872bc:  94 10 00 10  mov  %l0, %o2
a00872c0:  80 a4 00 0d  cmp  %l0, %o5
a00872c4:  92 10 20 01  mov  1, %o1
a00872c8:  02 80 00 03  be  0xa00872d4
a00872cc:  96 10 20 01  mov  1, %o3
a00872d0:  a8 10 20 01  mov  1, %l4
a00872d4:  a8 05 20 01  inc  %l4
a00872d8:  82 0d 20 ff  and  %l4, 0xff, %g1
a00872dc:  80 a0 60 05  cmp  %g1, 5
a00872e0:  28 80 00 02  bleu,a   0xa00872e8
a00872e4:  92 10 20 00  clr  %o1
a00872e8:  80 a3 60 02  cmp  %o5, 2
a00872ec:  28 80 00 02  bleu,a   0xa00872f4
a00872f0:  96 10 20 00  clr  %o3
a00872f4:  80 92 40 0b  orcc  %o1, %o3, %g0
a00872f8:  22 80 00 0b  be,a   0xa0087324
a00872fc:  ac 10 00 0c  mov  %o4, %l6
a0087300:  82 10 20 01  mov  1, %g1
a0087304:  da 0e c0 00  ldub  [ %i3 ], %o5
a0087308:  83 28 40 11  sll  %g1, %l1, %g1
a008730c:  82 2b 40 01  andn  %o5, %g1, %g1
a0087310:  80 a4 60 00  cmp  %l1, 0
a0087314:  12 80 00 0f  bne  0xa0087350
a0087318:  c2 2e c0 00  stb  %g1, [ %i3 ]
a008731c:  10 80 00 10  b  0xa008735c
a0087320:  b0 10 20 08  mov  8, %i0
a0087324:  40 00 8f 1c  call  0xa00aaf94
a0087328:  d2 0f bf f6  ldub  [ %fp + -10 ], %o1
a008732c:  90 10 00 11  mov  %l1, %o0
a0087330:  94 10 00 10  mov  %l0, %o2
a0087334:  d2 0e 40 00  ldub  [ %i1 ], %o1
a0087338:  7f ff fc 82  call  0xa0086540
a008733c:  d6 0f bf f6  ldub  [ %fp + -10 ], %o3
a0087340:  80 8a 20 ff  btst  0xff, %o0
a0087344:  12 bf ff b4  bne  0xa0087214
a0087348:  a2 0c a0 ff  and  %l2, 0xff, %l1
a008734c:  b0 10 20 02  mov  2, %i0
a0087350:  a4 04 a0 01  inc  %l2
a0087354:  10 bf ff a4  b  0xa00871e4
a0087358:  9a 0c a0 ff  and  %l2, 0xff, %o5
a008735c:  81 c7 e0 08  ret
a0087360:  81 e8 00 00  restore
