# leon2s FUN_a00a6260 0xa00a6260-0xa00a63a8 (328 bytes)
a00a6260:  9d e3 bf 98  save  %sp, -104, %sp
a00a6264:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00a6268:  80 a6 20 51  cmp  %i0, 0x51
a00a626c:  02 80 00 05  be  0xa00a6280
a00a6270:  90 10 20 00  clr  %o0
a00a6274:  80 a6 20 61  cmp  %i0, 0x61
a00a6278:  12 80 00 4a  bne  0xa00a63a0
a00a627c:  90 10 20 01  mov  1, %o0
a00a6280:  b0 0a 20 ff  and  %o0, 0xff, %i0
a00a6284:  7f ff f1 33  call  0xa00a2750
a00a6288:  90 10 00 18  mov  %i0, %o0
a00a628c:  d0 36 60 48  sth  %o0, [ %i1 + 0x48 ]
a00a6290:  7f ff f1 3e  call  0xa00a2788
a00a6294:  90 10 00 18  mov  %i0, %o0
a00a6298:  d0 36 60 14  sth  %o0, [ %i1 + 0x14 ]
a00a629c:  7f ff f1 57  call  0xa00a27f8
a00a62a0:  90 10 00 18  mov  %i0, %o0
a00a62a4:  d0 36 60 10  sth  %o0, [ %i1 + 0x10 ]
a00a62a8:  7f ff f1 54  call  0xa00a27f8
a00a62ac:  90 10 00 18  mov  %i0, %o0
a00a62b0:  d0 36 60 16  sth  %o0, [ %i1 + 0x16 ]
a00a62b4:  7f ff f1 43  call  0xa00a27c0
a00a62b8:  90 10 00 18  mov  %i0, %o0
a00a62bc:  91 2a 20 10  sll  %o0, 0x10, %o0
a00a62c0:  91 32 20 10  srl  %o0, 0x10, %o0
a00a62c4:  80 a2 20 07  cmp  %o0, 7
a00a62c8:  18 80 00 04  bgu  0xa00a62d8
a00a62cc:  82 10 20 02  mov  2, %g1
a00a62d0:  10 80 00 05  b  0xa00a62e4
a00a62d4:  c2 36 60 18  sth  %g1, [ %i1 + 0x18 ]
a00a62d8:  7f ff f1 3a  call  0xa00a27c0
a00a62dc:  90 10 00 18  mov  %i0, %o0
a00a62e0:  d0 36 60 18  sth  %o0, [ %i1 + 0x18 ]
a00a62e4:  7f ff f1 30  call  0xa00a27a4
a00a62e8:  90 10 00 18  mov  %i0, %o0
a00a62ec:  d0 36 60 20  sth  %o0, [ %i1 + 0x20 ]
a00a62f0:  7f ff f1 49  call  0xa00a2814
a00a62f4:  90 10 00 18  mov  %i0, %o0
a00a62f8:  d0 36 60 24  sth  %o0, [ %i1 + 0x24 ]
a00a62fc:  7f ff f1 23  call  0xa00a2788
a00a6300:  90 10 00 18  mov  %i0, %o0
a00a6304:  a1 2a 20 10  sll  %o0, 0x10, %l0
a00a6308:  7f ff f1 35  call  0xa00a27dc
a00a630c:  90 10 00 18  mov  %i0, %o0
a00a6310:  91 2a 20 10  sll  %o0, 0x10, %o0
a00a6314:  91 32 20 10  srl  %o0, 0x10, %o0
a00a6318:  a1 34 20 10  srl  %l0, 0x10, %l0
a00a631c:  a0 24 00 08  sub  %l0, %o0, %l0
a00a6320:  7f ff f1 21  call  0xa00a27a4
a00a6324:  90 10 00 18  mov  %i0, %o0
a00a6328:  91 2a 20 10  sll  %o0, 0x10, %o0
a00a632c:  91 32 20 10  srl  %o0, 0x10, %o0
a00a6330:  a0 24 00 08  sub  %l0, %o0, %l0
a00a6334:  83 3c 20 1f  sra  %l0, 0x1f, %g1
a00a6338:  83 30 60 1d  srl  %g1, 0x1d, %g1
a00a633c:  a0 04 00 01  add  %l0, %g1, %l0
a00a6340:  a1 3c 20 03  sra  %l0, 3, %l0
a00a6344:  da 16 60 20  lduh  [ %i1 + 0x20 ], %o5
a00a6348:  80 a3 61 df  cmp  %o5, 0x1df
a00a634c:  18 80 00 04  bgu  0xa00a635c
a00a6350:  e0 36 60 38  sth  %l0, [ %i1 + 0x38 ]
a00a6354:  10 80 00 0c  b  0xa00a6384
a00a6358:  82 10 20 05  mov  5, %g1
a00a635c:  82 03 7e 20  add  %o5, -480, %g1
a00a6360:  83 28 60 10  sll  %g1, 0x10, %g1
a00a6364:  83 30 60 10  srl  %g1, 0x10, %g1
a00a6368:  80 a0 61 df  cmp  %g1, 0x1df
a00a636c:  08 80 00 06  bleu  0xa00a6384
a00a6370:  82 10 20 0a  mov  0xa, %g1
a00a6374:  80 a3 63 bf  cmp  %o5, 0x3bf
a00a6378:  18 80 00 03  bgu  0xa00a6384
a00a637c:  82 10 20 14  mov  0x14, %g1
a00a6380:  82 10 20 0a  mov  0xa, %g1
a00a6384:  c2 36 60 1a  sth  %g1, [ %i1 + 0x1a ]
a00a6388:  7f ff f0 f9  call  0xa00a276c
a00a638c:  90 10 00 18  mov  %i0, %o0
a00a6390:  d0 36 60 4a  sth  %o0, [ %i1 + 0x4a ]
a00a6394:  7f ff f1 2e  call  0xa00a284c
a00a6398:  90 10 00 18  mov  %i0, %o0
a00a639c:  d0 36 60 4c  sth  %o0, [ %i1 + 0x4c ]
a00a63a0:  81 c7 e0 08  ret
a00a63a4:  81 e8 00 00  restore
