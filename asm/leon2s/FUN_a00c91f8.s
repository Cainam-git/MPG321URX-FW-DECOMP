# leon2s FUN_a00c91f8 0xa00c91f8-0xa00c9334 (316 bytes)
a00c91f8:  9d e3 bf 98  save  %sp, -104, %sp
a00c91fc:  a0 0e 20 ff  and  %i0, 0xff, %l0
a00c9200:  82 04 00 10  add  %l0, %l0, %g1
a00c9204:  82 00 40 10  add  %g1, %l0, %g1
a00c9208:  25 2a 01 e2  sethi  %hi(0xa8078800), %l2
a00c920c:  99 28 60 03  sll  %g1, 3, %o4
a00c9210:  96 14 a3 b0  or  %l2, 0x3b0, %o3
a00c9214:  da 02 c0 0c  ld  [ %o3 + %o4 ], %o5
a00c9218:  03 00 00 c0  sethi  %hi(0x30000), %g1
a00c921c:  9a 2b 40 01  andn  %o5, %g1, %o5
a00c9220:  03 00 00 40  sethi  %hi(0x10000), %g1
a00c9224:  9a 13 40 01  or  %o5, %g1, %o5
a00c9228:  83 33 60 1c  srl  %o5, 0x1c, %g1
a00c922c:  80 88 60 01  btst  1, %g1
a00c9230:  12 80 00 24  bne  0xa00c92c0
a00c9234:  da 22 c0 0c  st  %o5, [ %o3 + %o4 ]
a00c9238:  03 00 20 00  sethi  %hi(0x800000), %g1
a00c923c:  82 2b 40 01  andn  %o5, %g1, %g1
a00c9240:  c2 22 c0 0c  st  %g1, [ %o3 + %o4 ]
a00c9244:  82 03 00 0b  add  %o4, %o3, %g1
a00c9248:  15 00 00 10  sethi  %hi(0x4000), %o2
a00c924c:  c0 28 60 06  clrb  [ %g1 + 6 ]
a00c9250:  c0 28 60 03  clrb  [ %g1 + 3 ]
a00c9254:  c0 28 60 04  clrb  [ %g1 + 4 ]
a00c9258:  c0 28 60 05  clrb  [ %g1 + 5 ]
a00c925c:  94 12 a0 05  or  %o2, 5, %o2
a00c9260:  90 10 00 10  mov  %l0, %o0
a00c9264:  7f ff fd 61  call  0xa00c87e8
a00c9268:  92 10 20 0b  mov  0xb, %o1
a00c926c:  a2 10 20 00  clr  %l1
a00c9270:  94 0c 60 ff  and  %l1, 0xff, %o2
a00c9274:  94 02 a0 10  add  %o2, 0x10, %o2
a00c9278:  95 2a a0 10  sll  %o2, 0x10, %o2
a00c927c:  95 32 a0 10  srl  %o2, 0x10, %o2
a00c9280:  92 10 20 00  clr  %o1
a00c9284:  40 3b bb 55  call  0xa0fb7fd8
a00c9288:  90 10 00 10  mov  %l0, %o0
a00c928c:  94 0a 20 ff  and  %o0, 0xff, %o2
a00c9290:  90 10 00 10  mov  %l0, %o0
a00c9294:  7f ff f8 f0  call  0xa00c7654
a00c9298:  92 10 20 01  mov  1, %o1
a00c929c:  a2 04 60 01  inc  %l1
a00c92a0:  82 0c 60 ff  and  %l1, 0xff, %g1
a00c92a4:  80 a0 60 04  cmp  %g1, 4
a00c92a8:  08 bf ff f3  bleu  0xa00c9274
a00c92ac:  94 0c 60 ff  and  %l1, 0xff, %o2
a00c92b0:  90 10 00 10  mov  %l0, %o0
a00c92b4:  92 10 20 00  clr  %o1
a00c92b8:  7f ff fd 4c  call  0xa00c87e8
a00c92bc:  94 10 20 00  clr  %o2
a00c92c0:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00c92c4:  82 06 00 18  add  %i0, %i0, %g1
a00c92c8:  82 00 40 18  add  %g1, %i0, %g1
a00c92cc:  83 28 60 03  sll  %g1, 3, %g1
a00c92d0:  9a 14 a3 b0  or  %l2, 0x3b0, %o5
a00c92d4:  9a 00 40 0d  add  %g1, %o5, %o5
a00c92d8:  c2 0b 60 03  ldub  [ %o5 + 3 ], %g1
a00c92dc:  80 a0 60 7e  cmp  %g1, 0x7e
a00c92e0:  08 80 00 05  bleu  0xa00c92f4
a00c92e4:  82 00 60 01  inc  %g1
a00c92e8:  82 10 20 01  mov  1, %g1
a00c92ec:  10 80 00 03  b  0xa00c92f8
a00c92f0:  c2 2b 60 05  stb  %g1, [ %o5 + 5 ]
a00c92f4:  c2 2b 60 03  stb  %g1, [ %o5 + 3 ]
a00c92f8:  82 06 00 18  add  %i0, %i0, %g1
a00c92fc:  82 00 40 18  add  %g1, %i0, %g1
a00c9300:  83 28 60 03  sll  %g1, 3, %g1
a00c9304:  9a 14 a3 b0  or  %l2, 0x3b0, %o5
a00c9308:  9a 00 40 0d  add  %g1, %o5, %o5
a00c930c:  c2 0b 60 04  ldub  [ %o5 + 4 ], %g1
a00c9310:  80 a0 60 06  cmp  %g1, 6
a00c9314:  08 80 00 05  bleu  0xa00c9328
a00c9318:  82 00 60 01  inc  %g1
a00c931c:  82 10 20 01  mov  1, %g1
a00c9320:  10 80 00 03  b  0xa00c932c
a00c9324:  c2 2b 60 06  stb  %g1, [ %o5 + 6 ]
a00c9328:  c2 2b 60 04  stb  %g1, [ %o5 + 4 ]
a00c932c:  81 c7 e0 08  ret
a00c9330:  81 e8 00 00  restore
