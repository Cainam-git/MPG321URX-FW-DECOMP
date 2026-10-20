# leon2s FUN_a00a5148 0xa00a5148-0xa00a535c (532 bytes)
a00a5148:  9d e3 bf 98  save  %sp, -104, %sp
a00a514c:  80 a6 20 00  cmp  %i0, 0
a00a5150:  02 80 00 06  be  0xa00a5168
a00a5154:  03 00 01 d4  sethi  %hi(0x75000), %g1
a00a5158:  80 a6 20 01  cmp  %i0, 1
a00a515c:  02 80 00 6d  be  0xa00a5310
a00a5160:  03 2a aa aa  sethi  %hi(0xaaaaa800), %g1
a00a5164:  30 80 00 7c  b,a   0xa00a5354
a00a5168:  82 10 62 ff  or  %g1, 0x2ff, %g1	! 0xaaaaaaff
a00a516c:  80 a6 40 01  cmp  %i1, %g1
a00a5170:  08 80 00 12  bleu  0xa00a51b8
a00a5174:  9e 10 20 00  clr  %o7
a00a5178:  03 00 03 a9  sethi  %hi(0xea400), %g1
a00a517c:  82 10 61 ff  or  %g1, 0x1ff, %g1	! 0xea5ff
a00a5180:  80 a6 40 01  cmp  %i1, %g1
a00a5184:  18 80 00 05  bgu  0xa00a5198
a00a5188:  03 00 07 52  sethi  %hi(0x1d4800), %g1
a00a518c:  b3 36 60 01  srl  %i1, 1, %i1
a00a5190:  10 80 00 0a  b  0xa00a51b8
a00a5194:  9e 10 20 01  mov  1, %o7
a00a5198:  82 10 63 ff  or  %g1, 0x3ff, %g1
a00a519c:  80 a6 40 01  cmp  %i1, %g1
a00a51a0:  38 80 00 05  bgu,a   0xa00a51b4
a00a51a4:  b3 36 60 03  srl  %i1, 3, %i1
a00a51a8:  b3 36 60 02  srl  %i1, 2, %i1
a00a51ac:  10 80 00 03  b  0xa00a51b8
a00a51b0:  9e 10 20 02  mov  2, %o7
a00a51b4:  9e 10 20 03  mov  3, %o7
a00a51b8:  03 2a aa aa  sethi  %hi(0xaaaaa800), %g1
a00a51bc:  ba 5e 6a d0  smul  %i1, 0xad0, %i5
a00a51c0:  82 10 62 ab  or  %g1, 0x2ab, %g1
a00a51c4:  80 57 40 01  umul  %i5, %g1, %g0
a00a51c8:  bb 40 00 00  rd  %y, %i5
a00a51cc:  03 04 18 93  sethi  %hi(0x10624c00), %g1
a00a51d0:  b9 2e 60 02  sll  %i1, 2, %i4
a00a51d4:  82 10 61 d3  or  %g1, 0x1d3, %g1
a00a51d8:  bb 37 60 01  srl  %i5, 1, %i5
a00a51dc:  80 57 40 01  umul  %i5, %g1, %g0
a00a51e0:  bb 40 00 00  rd  %y, %i5
a00a51e4:  b8 07 00 19  add  %i4, %i1, %i4
a00a51e8:  b2 07 00 1c  add  %i4, %i4, %i1
a00a51ec:  bb 37 60 06  srl  %i5, 6, %i5
a00a51f0:  b2 06 40 1d  add  %i1, %i5, %i1
a00a51f4:  37 33 c0 50  sethi  %hi(0xcf014000), %i3
a00a51f8:  b8 16 e0 c4  or  %i3, 0xc4, %i4	! 0xcf0140c4
a00a51fc:  82 0e 60 ff  and  %i1, 0xff, %g1
a00a5200:  c2 27 00 00  st  %g1, [ %i4 ]
a00a5204:  bb 36 60 08  srl  %i1, 8, %i5
a00a5208:  82 16 e0 c8  or  %i3, 0xc8, %g1
a00a520c:  b9 36 60 10  srl  %i1, 0x10, %i4
a00a5210:  ba 0f 60 ff  and  %i5, 0xff, %i5
a00a5214:  fa 20 40 00  st  %i5, [ %g1 ]
a00a5218:  b8 0f 20 ff  and  %i4, 0xff, %i4
a00a521c:  b6 16 e0 cc  or  %i3, 0xcc, %i3
a00a5220:  03 33 c0 f2  sethi  %hi(0xcf03c800), %g1
a00a5224:  f8 26 c0 00  st  %i4, [ %i3 ]
a00a5228:  b8 10 60 40  or  %g1, 0x40, %i4
a00a522c:  03 00 00 3f  sethi  %hi(0xfc00), %g1
a00a5230:  b0 10 63 ff  or  %g1, 0x3ff, %i0	! 0xffff
a00a5234:  b4 10 3f ff  mov  -1, %i2
a00a5238:  b2 10 20 02  mov  2, %i1
a00a523c:  82 06 bf ff  add  %i2, -1, %g1
a00a5240:  bb 28 60 10  sll  %g1, 0x10, %i5
a00a5244:  b7 37 60 10  srl  %i5, 0x10, %i3
a00a5248:  fa 07 00 00  ld  [ %i4 ], %i5
a00a524c:  80 a7 60 01  cmp  %i5, 1
a00a5250:  02 80 00 03  be  0xa00a525c
a00a5254:  b4 10 00 01  mov  %g1, %i2
a00a5258:  f2 27 00 00  st  %i1, [ %i4 ]
a00a525c:  c2 07 00 00  ld  [ %i4 ], %g1
a00a5260:  80 a0 60 02  cmp  %g1, 2
a00a5264:  02 80 00 04  be  0xa00a5274
a00a5268:  80 a6 c0 18  cmp  %i3, %i0
a00a526c:  12 bf ff f5  bne  0xa00a5240
a00a5270:  82 06 bf ff  add  %i2, -1, %g1
a00a5274:  82 10 20 02  mov  2, %g1
a00a5278:  3b 33 c0 51  sethi  %hi(0xcf014400), %i5
a00a527c:  c2 27 00 00  st  %g1, [ %i4 ]
a00a5280:  ba 17 63 44  or  %i5, 0x344, %i5
a00a5284:  c2 07 40 00  ld  [ %i5 ], %g1
a00a5288:  82 08 7f cf  and  %g1, -49, %g1
a00a528c:  c2 27 40 00  st  %g1, [ %i5 ]
a00a5290:  03 33 c0 f2  sethi  %hi(0xcf03c800), %g1
a00a5294:  b6 10 60 40  or  %g1, 0x40, %i3	! 0xcf03c840
a00a5298:  03 00 00 3f  sethi  %hi(0xfc00), %g1
a00a529c:  c0 27 00 00  clr  [ %i4 ]
a00a52a0:  b0 10 63 ff  or  %g1, 0x3ff, %i0
a00a52a4:  b4 10 3f ff  mov  -1, %i2
a00a52a8:  b2 10 20 02  mov  2, %i1
a00a52ac:  82 06 bf ff  add  %i2, -1, %g1
a00a52b0:  bb 28 60 10  sll  %g1, 0x10, %i5
a00a52b4:  b9 37 60 10  srl  %i5, 0x10, %i4
a00a52b8:  fa 06 c0 00  ld  [ %i3 ], %i5
a00a52bc:  80 a7 60 01  cmp  %i5, 1
a00a52c0:  02 80 00 03  be  0xa00a52cc
a00a52c4:  b4 10 00 01  mov  %g1, %i2
a00a52c8:  f2 26 c0 00  st  %i1, [ %i3 ]
a00a52cc:  c2 06 c0 00  ld  [ %i3 ], %g1
a00a52d0:  80 a0 60 02  cmp  %g1, 2
a00a52d4:  02 80 00 04  be  0xa00a52e4
a00a52d8:  80 a7 00 18  cmp  %i4, %i0
a00a52dc:  12 bf ff f5  bne  0xa00a52b0
a00a52e0:  82 06 bf ff  add  %i2, -1, %g1
a00a52e4:  82 10 20 02  mov  2, %g1
a00a52e8:  39 33 c0 51  sethi  %hi(0xcf014400), %i4
a00a52ec:  c2 26 c0 00  st  %g1, [ %i3 ]
a00a52f0:  b8 17 23 44  or  %i4, 0x344, %i4
a00a52f4:  ba 0b e0 ff  and  %o7, 0xff, %i5
a00a52f8:  c2 07 00 00  ld  [ %i4 ], %g1
a00a52fc:  bb 2f 60 04  sll  %i5, 4, %i5
a00a5300:  82 10 40 1d  or  %g1, %i5, %g1
a00a5304:  c2 27 00 00  st  %g1, [ %i4 ]
a00a5308:  c0 26 c0 00  clr  [ %i3 ]
a00a530c:  30 80 00 12  b,a   0xa00a5354
a00a5310:  bb 2e 60 11  sll  %i1, 0x11, %i5
a00a5314:  82 10 62 ab  or  %g1, 0x2ab, %g1
a00a5318:  80 57 40 01  umul  %i5, %g1, %g0
a00a531c:  bb 40 00 00  rd  %y, %i5
a00a5320:  37 33 c0 50  sethi  %hi(0xcf014000), %i3
a00a5324:  b3 37 60 03  srl  %i5, 3, %i1
a00a5328:  82 16 e1 04  or  %i3, 0x104, %g1
a00a532c:  b4 0e 60 ff  and  %i1, 0xff, %i2
a00a5330:  f4 20 40 00  st  %i2, [ %g1 ]
a00a5334:  b9 37 60 0b  srl  %i5, 0xb, %i4
a00a5338:  82 16 e1 08  or  %i3, 0x108, %g1
a00a533c:  b8 0f 20 ff  and  %i4, 0xff, %i4
a00a5340:  bb 37 60 13  srl  %i5, 0x13, %i5
a00a5344:  f8 20 40 00  st  %i4, [ %g1 ]
a00a5348:  b6 16 e1 0c  or  %i3, 0x10c, %i3
a00a534c:  ba 0f 60 ff  and  %i5, 0xff, %i5
a00a5350:  fa 26 c0 00  st  %i5, [ %i3 ]
a00a5354:  81 c7 e0 08  ret
a00a5358:  81 e8 00 00  restore
