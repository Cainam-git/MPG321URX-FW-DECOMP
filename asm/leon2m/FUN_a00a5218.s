# leon2m FUN_a00a5218 0xa00a5218-0xa00a5420 (520 bytes)
a00a5218:  9d e3 bf 98  save  %sp, -104, %sp
a00a521c:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00a5220:  a0 10 62 90  or  %g1, 0x290, %l0	! 0xa802d290
a00a5224:  da 0c 20 4a  ldub  [ %l0 + 0x4a ], %o5
a00a5228:  80 a3 60 00  cmp  %o5, 0
a00a522c:  12 80 00 78  bne  0xa00a540c
a00a5230:  1b 2a 00 ac  sethi  %hi(0xa802b000), %o5
a00a5234:  d0 04 20 b0  ld  [ %l0 + 0xb0 ], %o0
a00a5238:  80 a2 20 00  cmp  %o0, 0
a00a523c:  12 80 00 4f  bne  0xa00a5378
a00a5240:  01 00 00 00  nop
a00a5244:  7f ff 79 68  call  0xa00837e4
a00a5248:  01 00 00 00  nop
a00a524c:  92 0a 20 ff  and  %o0, 0xff, %o1
a00a5250:  80 a2 60 01  cmp  %o1, 1
a00a5254:  02 80 00 67  be  0xa00a53f0
a00a5258:  01 00 00 00  nop
a00a525c:  d4 0c 20 1f  ldub  [ %l0 + 0x1f ], %o2
a00a5260:  80 a2 a0 00  cmp  %o2, 0
a00a5264:  12 80 00 5f  bne  0xa00a53e0
a00a5268:  01 00 00 00  nop
a00a526c:  c2 04 20 a8  ld  [ %l0 + 0xa8 ], %g1
a00a5270:  80 88 60 80  btst  0x80, %g1
a00a5274:  12 80 00 50  bne  0xa00a53b4
a00a5278:  a2 10 20 01  mov  1, %l1
a00a527c:  e2 2c 20 4a  stb  %l1, [ %l0 + 0x4a ]
a00a5280:  40 00 c3 0b  call  0xa00d5eac
a00a5284:  90 10 20 00  clr  %o0
a00a5288:  e0 0c 20 4a  ldub  [ %l0 + 0x4a ], %l0
a00a528c:  90 10 20 05  mov  5, %o0
a00a5290:  92 10 20 08  mov  8, %o1
a00a5294:  94 10 20 04  mov  4, %o2
a00a5298:  96 10 27 92  mov  0x792, %o3
a00a529c:  40 02 85 f9  call  0xa0146a80
a00a52a0:  98 10 20 00  clr  %o4
a00a52a4:  a2 94 20 00  orcc  %l0, 0, %l1
a00a52a8:  02 80 00 22  be  0xa00a5330
a00a52ac:  a0 10 20 00  clr  %l0
a00a52b0:  90 0c 20 ff  and  %l0, 0xff, %o0
a00a52b4:  82 02 20 09  add  %o0, 9, %g1
a00a52b8:  9b 28 60 10  sll  %g1, 0x10, %o5
a00a52bc:  9e 04 20 1e  add  %l0, 0x1e, %o7
a00a52c0:  93 33 60 10  srl  %o5, 0x10, %o1
a00a52c4:  98 0b e0 ff  and  %o7, 0xff, %o4
a00a52c8:  90 10 20 00  clr  %o0
a00a52cc:  94 10 20 08  mov  8, %o2
a00a52d0:  96 10 20 01  mov  1, %o3
a00a52d4:  40 02 86 13  call  0xa0146b20
a00a52d8:  9a 10 20 00  clr  %o5
a00a52dc:  a0 04 20 01  inc  %l0
a00a52e0:  98 0c 20 ff  and  %l0, 0xff, %o4
a00a52e4:  80 a3 20 03  cmp  %o4, 3
a00a52e8:  08 bf ff f3  bleu  0xa00a52b4
a00a52ec:  90 0c 20 ff  and  %l0, 0xff, %o0
a00a52f0:  80 a4 60 00  cmp  %l1, 0
a00a52f4:  12 80 00 26  bne  0xa00a538c
a00a52f8:  90 10 20 03  mov  3, %o0
a00a52fc:  92 10 20 08  mov  8, %o1
a00a5300:  94 10 20 05  mov  5, %o2
a00a5304:  96 10 27 92  mov  0x792, %o3
a00a5308:  40 02 85 de  call  0xa0146a80
a00a530c:  98 10 20 00  clr  %o4
a00a5310:  90 10 20 0e  mov  0xe, %o0
a00a5314:  92 10 20 08  mov  8, %o1
a00a5318:  94 10 20 05  mov  5, %o2
a00a531c:  96 10 29 92  mov  0x992, %o3
a00a5320:  40 02 85 d8  call  0xa0146a80
a00a5324:  98 10 20 00  clr  %o4
a00a5328:  10 80 00 39  b  0xa00a540c
a00a532c:  1b 2a 00 ac  sethi  %hi(0xa802b000), %o5
a00a5330:  9e 0c 20 ff  and  %l0, 0xff, %o7
a00a5334:  98 03 e0 09  add  %o7, 9, %o4
a00a5338:  97 2b 20 10  sll  %o4, 0x10, %o3
a00a533c:  94 04 20 22  add  %l0, 0x22, %o2
a00a5340:  93 32 e0 10  srl  %o3, 0x10, %o1
a00a5344:  98 0a a0 ff  and  %o2, 0xff, %o4
a00a5348:  90 10 20 00  clr  %o0
a00a534c:  94 10 20 08  mov  8, %o2
a00a5350:  96 10 20 01  mov  1, %o3
a00a5354:  40 02 85 f3  call  0xa0146b20
a00a5358:  9a 10 20 00  clr  %o5
a00a535c:  a0 04 20 01  inc  %l0
a00a5360:  92 0c 20 ff  and  %l0, 0xff, %o1
a00a5364:  80 a2 60 03  cmp  %o1, 3
a00a5368:  08 bf ff f3  bleu  0xa00a5334
a00a536c:  9e 0c 20 ff  and  %l0, 0xff, %o7
a00a5370:  10 bf ff e1  b  0xa00a52f4
a00a5374:  80 a4 60 00  cmp  %l1, 0
a00a5378:  40 00 bd 88  call  0xa00d4998
a00a537c:  c0 24 20 b0  clr  [ %l0 + 0xb0 ]
a00a5380:  40 00 c2 ef  call  0xa00d5f3c
a00a5384:  01 00 00 00  nop
a00a5388:  30 bf ff af  b,a   0xa00a5244
a00a538c:  92 10 20 08  mov  8, %o1	! 0x8
a00a5390:  94 10 20 05  mov  5, %o2
a00a5394:  96 10 29 92  mov  0x992, %o3
a00a5398:  40 02 85 ba  call  0xa0146a80
a00a539c:  98 10 20 00  clr  %o4
a00a53a0:  90 10 20 0e  mov  0xe, %o0
a00a53a4:  92 10 20 08  mov  8, %o1
a00a53a8:  94 10 20 05  mov  5, %o2
a00a53ac:  10 bf ff dd  b  0xa00a5320
a00a53b0:  96 10 27 92  mov  0x792, %o3
a00a53b4:  96 08 7f 7f  and  %g1, -129, %o3
a00a53b8:  7f ff af 08  call  0xa0090fd8
a00a53bc:  d6 24 20 a8  st  %o3, [ %l0 + 0xa8 ]
a00a53c0:  40 01 fe e1  call  0xa0124f44
a00a53c4:  a2 10 20 01  mov  1, %l1
a00a53c8:  40 00 cf 8d  call  0xa00d91fc
a00a53cc:  90 10 20 00  clr  %o0
a00a53d0:  40 00 d3 6d  call  0xa00da184
a00a53d4:  01 00 00 00  nop
a00a53d8:  10 bf ff aa  b  0xa00a5280
a00a53dc:  e2 2c 20 4a  stb  %l1, [ %l0 + 0x4a ]
a00a53e0:  40 00 d3 9d  call  0xa00da254
a00a53e4:  c0 2c 20 1f  clrb  [ %l0 + 0x1f ]
a00a53e8:  10 bf ff a2  b  0xa00a5270
a00a53ec:  c2 04 20 a8  ld  [ %l0 + 0xa8 ], %g1
a00a53f0:  40 00 cf 83  call  0xa00d91fc
a00a53f4:  90 10 20 00  clr  %o0
a00a53f8:  c0 2c 21 a4  clrb  [ %l0 + 0x1a4 ]
a00a53fc:  7f ff 77 3e  call  0xa00830f4
a00a5400:  90 10 20 00  clr  %o0
a00a5404:  10 bf ff 97  b  0xa00a5260
a00a5408:  d4 0c 20 1f  ldub  [ %l0 + 0x1f ], %o2
a00a540c:  d0 0b 60 8e  ldub  [ %o5 + 0x8e ], %o0
a00a5410:  82 12 20 02  or  %o0, 2, %g1
a00a5414:  c2 2b 60 8e  stb  %g1, [ %o5 + 0x8e ]
a00a5418:  81 c7 e0 08  ret
a00a541c:  81 e8 00 00  restore
