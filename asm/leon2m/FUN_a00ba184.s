# leon2m FUN_a00ba184 0xa00ba184-0xa00ba3e8 (612 bytes)
a00ba184:  9d e3 bf 50  save  %sp, -176, %sp
a00ba188:  13 00 06 60  sethi  %hi(0x198000), %o1
a00ba18c:  c0 27 bf c0  clr  [ %fp + -64 ]
a00ba190:  c0 27 bf bc  clr  [ %fp + -68 ]
a00ba194:  c0 27 bf b8  clr  [ %fp + -72 ]
a00ba198:  92 12 62 0a  or  %o1, 0x20a, %o1
a00ba19c:  90 07 bf c8  add  %fp, -56, %o0
a00ba1a0:  40 02 09 dc  call  0xa013c910
a00ba1a4:  94 10 20 30  mov  0x30, %o2
a00ba1a8:  23 2a 00 b4  sethi  %hi(0xa802d000), %l1
a00ba1ac:  9a 14 62 90  or  %l1, 0x290, %o5	! 0xa802d290
a00ba1b0:  c2 0b 61 90  ldub  [ %o5 + 0x190 ], %g1
a00ba1b4:  80 a0 60 00  cmp  %g1, 0
a00ba1b8:  02 80 00 8a  be  0xa00ba3e0
a00ba1bc:  01 00 00 00  nop
a00ba1c0:  c2 0b 61 7b  ldub  [ %o5 + 0x17b ], %g1
a00ba1c4:  80 a0 60 02  cmp  %g1, 2
a00ba1c8:  02 80 00 11  be  0xa00ba20c
a00ba1cc:  80 a0 60 01  cmp  %g1, 1
a00ba1d0:  b0 10 20 00  clr  %i0
a00ba1d4:  92 10 20 00  clr  %o1
a00ba1d8:  02 80 00 72  be  0xa00ba3a0
a00ba1dc:  21 00 00 06  sethi  %hi(0x1800), %l0
a00ba1e0:  90 10 20 00  clr  %o0
a00ba1e4:  94 10 20 04  mov  4, %o2
a00ba1e8:  96 14 20 02  or  %l0, 2, %o3
a00ba1ec:  40 02 32 25  call  0xa0146a80
a00ba1f0:  98 10 20 01  mov  1, %o4
a00ba1f4:  b0 06 20 01  inc  %i0
a00ba1f8:  92 0e 20 ff  and  %i0, 0xff, %o1
a00ba1fc:  80 a2 60 02  cmp  %o1, 2
a00ba200:  08 bf ff f9  bleu  0xa00ba1e4
a00ba204:  90 10 20 00  clr  %o0
a00ba208:  30 80 00 76  b,a   0xa00ba3e0
a00ba20c:  90 07 bf c7  add  %fp, -57, %o0
a00ba210:  92 07 bf c6  add  %fp, -58, %o1
a00ba214:  94 07 bf c5  add  %fp, -59, %o2
a00ba218:  7f ff ff 94  call  0xa00ba068
a00ba21c:  96 07 bf c4  add  %fp, -60, %o3
a00ba220:  d0 0f bf c4  ldub  [ %fp + -60 ], %o0
a00ba224:  d0 23 a0 5c  st  %o0, [ %sp + 0x5c ]
a00ba228:  da 0f bf c5  ldub  [ %fp + -59 ], %o5
a00ba22c:  d6 0f bf c7  ldub  [ %fp + -57 ], %o3
a00ba230:  d8 0f bf c6  ldub  [ %fp + -58 ], %o4
a00ba234:  90 07 bf c0  add  %fp, -64, %o0
a00ba238:  92 07 bf bc  add  %fp, -68, %o1
a00ba23c:  7f ff ff 3d  call  0xa00b9f30
a00ba240:  94 07 bf b8  add  %fp, -72, %o2
a00ba244:  d4 57 bf ba  ldsh  [ %fp + -70 ], %o2
a00ba248:  d0 57 bf c2  ldsh  [ %fp + -62 ], %o0
a00ba24c:  7f ff fe 87  call  0xa00b9c68
a00ba250:  d2 57 bf be  ldsh  [ %fp + -66 ], %o1
a00ba254:  91 2a 20 10  sll  %o0, 0x10, %o0
a00ba258:  15 00 00 3f  sethi  %hi(0xfc00), %o2
a00ba25c:  82 12 a3 ff  or  %o2, 0x3ff, %g1	! 0xffff
a00ba260:  9b 32 20 10  srl  %o0, 0x10, %o5
a00ba264:  80 a3 40 01  cmp  %o5, %g1
a00ba268:  22 80 00 02  be,a   0xa00ba270
a00ba26c:  11 00 2d 00  sethi  %hi(0xb40000), %o0
a00ba270:  91 32 20 10  srl  %o0, 0x10, %o0
a00ba274:  80 a2 00 01  cmp  %o0, %g1
a00ba278:  02 80 00 5a  be  0xa00ba3e0
a00ba27c:  17 22 22 22  sethi  %hi(0x88888800), %o3
a00ba280:  9e 12 e0 89  or  %o3, 0x89, %o7	! 0x88888889
a00ba284:  80 52 00 0f  umul  %o0, %o7, %g0
a00ba288:  99 40 00 00  rd  %y, %o4
a00ba28c:  91 2b 20 0d  sll  %o4, 0xd, %o0
a00ba290:  1b 0a aa aa  sethi  %hi(0x2aaaa800), %o5
a00ba294:  95 32 20 10  srl  %o0, 0x10, %o2
a00ba298:  96 02 a0 0c  add  %o2, 0xc, %o3
a00ba29c:  92 13 62 ab  or  %o5, 0x2ab, %o1
a00ba2a0:  80 5a c0 09  smul  %o3, %o1, %g0
a00ba2a4:  83 40 00 00  rd  %y, %g1
a00ba2a8:  a9 38 60 02  sra  %g1, 2, %l4
a00ba2ac:  a6 05 00 14  add  %l4, %l4, %l3
a00ba2b0:  a4 04 c0 14  add  %l3, %l4, %l2
a00ba2b4:  a1 2c a0 03  sll  %l2, 3, %l0
a00ba2b8:  98 22 c0 10  sub  %o3, %l0, %o4
a00ba2bc:  27 2a 00 ac  sethi  %hi(0xa802b000), %l3
a00ba2c0:  9f 2b 20 10  sll  %o4, 0x10, %o7
a00ba2c4:  d6 0c e0 90  ldub  [ %l3 + 0x90 ], %o3
a00ba2c8:  83 33 e0 10  srl  %o7, 0x10, %g1
a00ba2cc:  a4 10 00 0c  mov  %o4, %l2
a00ba2d0:  9a 0a e0 ff  and  %o3, 0xff, %o5
a00ba2d4:  80 a3 40 01  cmp  %o5, %g1
a00ba2d8:  1a 80 00 3e  bcc  0xa00ba3d0
a00ba2dc:  98 23 00 0b  sub  %o4, %o3, %o4
a00ba2e0:  9a 0b 20 ff  and  %o4, 0xff, %o5
a00ba2e4:  80 a3 60 0b  cmp  %o5, 0xb
a00ba2e8:  08 80 00 05  bleu  0xa00ba2fc
a00ba2ec:  82 0e 20 ff  and  %i0, 0xff, %g1
a00ba2f0:  a8 10 20 18  mov  0x18, %l4
a00ba2f4:  a0 25 00 0c  sub  %l4, %o4, %l0
a00ba2f8:  9a 0c 20 ff  and  %l0, 0xff, %o5
a00ba2fc:  80 a0 00 01  cmp  %g0, %g1
a00ba300:  82 40 20 00  addx  %g0, 0, %g1
a00ba304:  80 a3 60 01  cmp  %o5, 1
a00ba308:  18 80 00 03  bgu  0xa00ba314
a00ba30c:  9a 10 20 01  mov  1, %o5
a00ba310:  9a 10 20 00  clr  %o5
a00ba314:  80 90 40 0d  orcc  %g1, %o5, %g0
a00ba318:  12 80 00 0c  bne  0xa00ba348
a00ba31c:  29 2a 00 ac  sethi  %hi(0xa802b000), %l4
a00ba320:  f0 0c e0 90  ldub  [ %l3 + 0x90 ], %i0
a00ba324:  80 a6 20 00  cmp  %i0, 0
a00ba328:  22 80 00 09  be,a   0xa00ba34c
a00ba32c:  97 2c a0 10  sll  %l2, 0x10, %o3
a00ba330:  94 14 62 90  or  %l1, 0x290, %o2
a00ba334:  da 0a a1 90  ldub  [ %o2 + 0x190 ], %o5
a00ba338:  d2 0d 20 91  ldub  [ %l4 + 0x91 ], %o1
a00ba33c:  80 a3 40 09  cmp  %o5, %o1
a00ba340:  02 80 00 28  be  0xa00ba3e0
a00ba344:  01 00 00 00  nop
a00ba348:  97 2c a0 10  sll  %l2, 0x10, %o3
a00ba34c:  9f 32 e0 0f  srl  %o3, 0xf, %o7
a00ba350:  98 07 80 0f  add  %fp, %o7, %o4
a00ba354:  d0 13 3f c8  lduh  [ %o4 + -56 ], %o0
a00ba358:  b1 2a 20 10  sll  %o0, 0x10, %i0
a00ba35c:  a0 10 20 00  clr  %l0
a00ba360:  92 10 20 00  clr  %o1
a00ba364:  90 10 20 00  clr  %o0
a00ba368:  94 10 20 04  mov  4, %o2
a00ba36c:  97 36 20 10  srl  %i0, 0x10, %o3
a00ba370:  40 02 31 c4  call  0xa0146a80
a00ba374:  98 10 20 01  mov  1, %o4
a00ba378:  a0 04 20 01  inc  %l0
a00ba37c:  92 0c 20 ff  and  %l0, 0xff, %o1
a00ba380:  80 a2 60 02  cmp  %o1, 2
a00ba384:  08 bf ff f9  bleu  0xa00ba368
a00ba388:  90 10 20 00  clr  %o0
a00ba38c:  a0 14 62 90  or  %l1, 0x290, %l0
a00ba390:  e2 0c 21 90  ldub  [ %l0 + 0x190 ], %l1
a00ba394:  e4 2c e0 90  stb  %l2, [ %l3 + 0x90 ]
a00ba398:  10 80 00 12  b  0xa00ba3e0
a00ba39c:  e2 2d 20 91  stb  %l1, [ %l4 + 0x91 ]
a00ba3a0:  a0 04 3c 00  add  %l0, -1024, %l0
a00ba3a4:  90 10 20 00  clr  %o0
a00ba3a8:  94 10 20 04  mov  4, %o2
a00ba3ac:  96 14 23 02  or  %l0, 0x302, %o3
a00ba3b0:  40 02 31 b4  call  0xa0146a80
a00ba3b4:  98 10 20 01  mov  1, %o4
a00ba3b8:  b0 06 20 01  inc  %i0
a00ba3bc:  92 0e 20 ff  and  %i0, 0xff, %o1
a00ba3c0:  80 a2 60 02  cmp  %o1, 2
a00ba3c4:  08 bf ff f9  bleu  0xa00ba3a8
a00ba3c8:  90 10 20 00  clr  %o0
a00ba3cc:  30 80 00 05  b,a   0xa00ba3e0
a00ba3d0:  18 bf ff c4  bgu  0xa00ba2e0
a00ba3d4:  98 22 c0 12  sub  %o3, %l2, %o4
a00ba3d8:  10 bf ff c2  b  0xa00ba2e0
a00ba3dc:  98 10 20 00  clr  %o4
a00ba3e0:  81 c7 e0 08  ret
a00ba3e4:  81 e8 00 00  restore
