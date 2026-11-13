# leon2m FUN_a00ad1c0 0xa00ad1c0-0xa00ad460 (672 bytes)  [FUN_a00ad458 = unreachable ret/restore tail, merged]
a00ad1c0:  9d e3 bf 90  save  %sp, -112, %sp
a00ad1c4:  90 10 20 92  mov  0x92, %o0
a00ad1c8:  40 02 66 62  call  0xa0146b50
a00ad1cc:  92 10 20 00  clr  %o1
a00ad1d0:  67 ff 84 35  call  0x4008e2a4
a00ad1d4:  a2 10 20 05  mov  5, %l1
a00ad1d8:  a0 10 20 05  mov  5, %l0
a00ad1dc:  94 10 00 10  mov  %l0, %o2
a00ad1e0:  90 10 20 00  clr  %o0
a00ad1e4:  92 10 20 13  mov  0x13, %o1
a00ad1e8:  96 10 20 13  mov  0x13, %o3
a00ad1ec:  98 10 20 00  clr  %o4
a00ad1f0:  40 02 66 4c  call  0xa0146b20
a00ad1f4:  9a 10 20 00  clr  %o5
a00ad1f8:  92 10 00 10  mov  %l0, %o1
a00ad1fc:  90 10 20 13  mov  0x13, %o0
a00ad200:  94 10 20 13  mov  0x13, %o2
a00ad204:  96 10 27 92  mov  0x792, %o3
a00ad208:  98 10 20 00  clr  %o4
a00ad20c:  40 02 66 1d  call  0xa0146a80
a00ad210:  a2 04 60 01  inc  %l1
a00ad214:  a0 0c 60 ff  and  %l1, 0xff, %l0
a00ad218:  80 a4 20 14  cmp  %l0, 0x14
a00ad21c:  08 bf ff f1  bleu  0xa00ad1e0
a00ad220:  94 10 00 10  mov  %l0, %o2
a00ad224:  96 10 20 02  mov  2, %o3
a00ad228:  98 10 20 00  clr  %o4
a00ad22c:  9a 10 20 00  clr  %o5
a00ad230:  90 10 20 00  clr  %o0
a00ad234:  92 10 20 1c  mov  0x1c, %o1
a00ad238:  40 02 66 3a  call  0xa0146b20
a00ad23c:  94 10 20 15  mov  0x15, %o2
a00ad240:  90 10 20 05  mov  5, %o0
a00ad244:  92 10 20 00  clr  %o1
a00ad248:  40 02 66 7e  call  0xa0146c40
a00ad24c:  94 10 20 00  clr  %o2
a00ad250:  90 10 20 00  clr  %o0
a00ad254:  40 02 66 46  call  0xa0146b6c
a00ad258:  92 10 20 00  clr  %o1
a00ad25c:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00ad260:  80 a6 20 00  cmp  %i0, 0
a00ad264:  32 80 00 2d  bne,a   0xa00ad318
a00ad268:  21 09 24 92  sethi  %hi(0x24924800), %l0
a00ad26c:  a4 10 20 00  clr  %l2
a00ad270:  a0 10 20 00  clr  %l0
a00ad274:  29 2a 00 b4  sethi  %hi(0xa802d000), %l4
a00ad278:  10 80 00 1a  b  0xa00ad2e0
a00ad27c:  27 00 06 1d  sethi  %hi(0x187400), %l3
a00ad280:  83 2c 20 03  sll  %l0, 3, %g1
a00ad284:  94 20 40 10  sub  %g1, %l0, %o2
a00ad288:  9f 2a a0 02  sll  %o2, 2, %o7
a00ad28c:  9a 15 22 90  or  %l4, 0x290, %o5
a00ad290:  96 03 c0 10  add  %o7, %l0, %o3
a00ad294:  d8 0b 60 08  ldub  [ %o5 + 8 ], %o4
a00ad298:  90 02 c0 0c  add  %o3, %o4, %o0
a00ad29c:  93 2a 20 10  sll  %o0, 0x10, %o1
a00ad2a0:  93 32 60 10  srl  %o1, 0x10, %o1
a00ad2a4:  7f ff d9 68  call  0xa00a3844
a00ad2a8:  90 14 e0 f8  or  %l3, 0xf8, %o0
a00ad2ac:  82 04 60 06  add  %l1, 6, %g1
a00ad2b0:  98 10 00 08  mov  %o0, %o4
a00ad2b4:  95 28 60 10  sll  %g1, 0x10, %o2
a00ad2b8:  95 32 a0 10  srl  %o2, 0x10, %o2
a00ad2bc:  90 10 20 00  clr  %o0
a00ad2c0:  92 10 20 14  mov  0x14, %o1
a00ad2c4:  96 10 20 01  mov  1, %o3
a00ad2c8:  7f ff d7 b7  call  0xa00a31a4
a00ad2cc:  9a 10 20 00  clr  %o5
a00ad2d0:  a0 0c a0 ff  and  %l2, 0xff, %l0
a00ad2d4:  80 a4 20 07  cmp  %l0, 7
a00ad2d8:  1a 80 00 48  bcc  0xa00ad3f8
a00ad2dc:  a2 10 20 28  mov  0x28, %l1
a00ad2e0:  7f ff f4 90  call  0xa00aa520
a00ad2e4:  90 10 00 10  mov  %l0, %o0
a00ad2e8:  80 8a 20 ff  btst  0xff, %o0
a00ad2ec:  a4 04 a0 01  inc  %l2
a00ad2f0:  a2 04 00 10  add  %l0, %l0, %l1
a00ad2f4:  94 10 20 0d  mov  0xd, %o2
a00ad2f8:  96 10 22 92  mov  0x292, %o3
a00ad2fc:  98 10 20 00  clr  %o4
a00ad300:  12 bf ff e0  bne  0xa00ad280
a00ad304:  90 10 20 14  mov  0x14, %o0
a00ad308:  40 02 65 de  call  0xa0146a80
a00ad30c:  92 04 60 06  add  %l1, 6, %o1
a00ad310:  10 bf ff dd  b  0xa00ad284
a00ad314:  83 2c 20 03  sll  %l0, 3, %g1
a00ad318:  a8 14 21 25  or  %l0, 0x125, %l4
a00ad31c:  a2 10 20 07  mov  7, %l1
a00ad320:  a0 10 20 07  mov  7, %l0
a00ad324:  27 2a 00 b4  sethi  %hi(0xa802d000), %l3
a00ad328:  10 80 00 1b  b  0xa00ad394
a00ad32c:  25 00 06 1d  sethi  %hi(0x187400), %l2
a00ad330:  9b 2c 20 03  sll  %l0, 3, %o5
a00ad334:  90 23 40 10  sub  %o5, %l0, %o0
a00ad338:  99 2a 20 02  sll  %o0, 2, %o4
a00ad33c:  96 14 e2 90  or  %l3, 0x290, %o3
a00ad340:  92 03 00 10  add  %o4, %l0, %o1
a00ad344:  c2 0a e0 08  ldub  [ %o3 + 8 ], %g1
a00ad348:  94 02 40 01  add  %o1, %g1, %o2
a00ad34c:  9f 2a a0 10  sll  %o2, 0x10, %o7
a00ad350:  93 33 e0 10  srl  %o7, 0x10, %o1
a00ad354:  7f ff d9 3c  call  0xa00a3844
a00ad358:  90 14 a0 f8  or  %l2, 0xf8, %o0
a00ad35c:  9a 04 00 10  add  %l0, %l0, %o5
a00ad360:  a0 03 7f f8  add  %o5, -8, %l0
a00ad364:  98 10 00 08  mov  %o0, %o4
a00ad368:  91 2c 20 10  sll  %l0, 0x10, %o0
a00ad36c:  95 32 20 10  srl  %o0, 0x10, %o2
a00ad370:  90 10 20 00  clr  %o0
a00ad374:  92 10 20 14  mov  0x14, %o1
a00ad378:  96 10 20 01  mov  1, %o3
a00ad37c:  7f ff d7 8a  call  0xa00a31a4
a00ad380:  9a 10 20 00  clr  %o5
a00ad384:  a0 0c 60 ff  and  %l1, 0xff, %l0
a00ad388:  80 a4 20 09  cmp  %l0, 9
a00ad38c:  38 80 00 1b  bgu,a   0xa00ad3f8
a00ad390:  a2 10 20 28  mov  0x28, %l1
a00ad394:  7f ff f4 63  call  0xa00aa520
a00ad398:  90 10 00 10  mov  %l0, %o0
a00ad39c:  80 54 00 14  umul  %l0, %l4, %g0
a00ad3a0:  93 40 00 00  rd  %y, %o1
a00ad3a4:  98 24 00 09  sub  %l0, %o1, %o4
a00ad3a8:  97 33 20 01  srl  %o4, 1, %o3
a00ad3ac:  82 02 40 0b  add  %o1, %o3, %g1
a00ad3b0:  95 30 60 02  srl  %g1, 2, %o2
a00ad3b4:  9f 2a a0 03  sll  %o2, 3, %o7
a00ad3b8:  9a 23 c0 0a  sub  %o7, %o2, %o5
a00ad3bc:  98 24 00 0d  sub  %l0, %o5, %o4
a00ad3c0:  96 0b 20 ff  and  %o4, 0xff, %o3
a00ad3c4:  92 02 c0 0b  add  %o3, %o3, %o1
a00ad3c8:  80 8a 20 ff  btst  0xff, %o0
a00ad3cc:  a2 04 60 01  inc  %l1
a00ad3d0:  92 02 60 06  add  %o1, 6, %o1
a00ad3d4:  94 10 20 0d  mov  0xd, %o2
a00ad3d8:  96 10 22 92  mov  0x292, %o3
a00ad3dc:  98 10 20 00  clr  %o4
a00ad3e0:  12 bf ff d4  bne  0xa00ad330
a00ad3e4:  90 10 20 14  mov  0x14, %o0
a00ad3e8:  40 02 65 a6  call  0xa0146a80
a00ad3ec:  01 00 00 00  nop
a00ad3f0:  10 bf ff d1  b  0xa00ad334
a00ad3f4:  9b 2c 20 03  sll  %l0, 3, %o5
a00ad3f8:  e2 23 a0 5c  st  %l1, [ %sp + 0x5c ]
a00ad3fc:  90 10 20 01  mov  1, %o0
a00ad400:  92 10 20 01  mov  1, %o1
a00ad404:  94 10 27 92  mov  0x792, %o2
a00ad408:  96 10 20 1c  mov  0x1c, %o3
a00ad40c:  98 10 20 15  mov  0x15, %o4
a00ad410:  40 00 17 b5  call  0xa00b32e4
a00ad414:  9a 10 20 02  mov  2, %o5
a00ad418:  80 a6 20 00  cmp  %i0, 0
a00ad41c:  02 80 00 05  be  0xa00ad430
a00ad420:  80 a6 20 01  cmp  %i0, 1
a00ad424:  12 80 00 0c  bne  0xa00ad454
a00ad428:  01 00 00 00  nop
a00ad42c:  30 80 00 06  b,a   0xa00ad444
a00ad430:  40 00 29 45  call  0xa00b7944
a00ad434:  01 00 00 00  nop
a00ad438:  40 00 29 52  call  0xa00b7980
a00ad43c:  01 00 00 00  nop
a00ad440:  30 80 00 05  b,a   0xa00ad454
a00ad444:  40 00 29 63  call  0xa00b79d0
a00ad448:  01 00 00 00  nop
a00ad44c:  40 00 29 6f  call  0xa00b7a08
a00ad450:  81 e8 00 00  restore
a00ad454:  01 00 00 00  nop
a00ad458:  81 c7 e0 08  ret
a00ad45c:  81 e8 00 00  restore
