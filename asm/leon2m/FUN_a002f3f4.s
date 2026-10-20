# leon2m FUN_a002f3f4 0xa002f3f4-0xa002f550 (348 bytes)
a002f3f4:  9d e3 bf 90  save  %sp, -112, %sp
a002f3f8:  c0 27 bf f4  clr  [ %fp + -12 ]
a002f3fc:  a0 10 20 64  mov  0x64, %l0
a002f400:  90 10 20 00  clr  %o0
a002f404:  92 10 20 00  clr  %o1
a002f408:  94 07 bf f4  add  %fp, -12, %o2
a002f40c:  7f ff f4 31  call  0xa002c4d0
a002f410:  96 10 20 01  mov  1, %o3
a002f414:  a0 04 3f ff  add  %l0, -1, %l0
a002f418:  9a 0c 20 ff  and  %l0, 0xff, %o5
a002f41c:  80 a3 60 00  cmp  %o5, 0
a002f420:  02 80 00 05  be  0xa002f434
a002f424:  c2 07 bf f4  ld  [ %fp + -12 ], %g1
a002f428:  80 a0 60 00  cmp  %g1, 0
a002f42c:  12 bf ff f6  bne  0xa002f404
a002f430:  90 10 20 00  clr  %o0
a002f434:  80 a0 00 0d  cmp  %g0, %o5
a002f438:  a0 0f 20 ff  and  %i4, 0xff, %l0
a002f43c:  90 40 20 00  addx  %g0, 0, %o0
a002f440:  9a 1c 20 03  xor  %l0, 3, %o5
a002f444:  80 a0 00 0d  cmp  %g0, %o5
a002f448:  98 60 3f ff  subx  %g0, -1, %o4
a002f44c:  80 92 00 0c  orcc  %o0, %o4, %g0
a002f450:  02 80 00 3e  be  0xa002f548
a002f454:  90 0e a0 ff  and  %i2, 0xff, %o0
a002f458:  99 2a 20 10  sll  %o0, 0x10, %o4
a002f45c:  83 2e e0 18  sll  %i3, 0x18, %g1
a002f460:  b4 0e 60 ff  and  %i1, 0xff, %i2
a002f464:  9e 00 40 0c  add  %g1, %o4, %o7
a002f468:  b3 2e a0 08  sll  %i2, 8, %i1
a002f46c:  94 03 c0 19  add  %o7, %i1, %o2
a002f470:  96 0e 20 ff  and  %i0, 0xff, %o3
a002f474:  92 02 80 0b  add  %o2, %o3, %o1
a002f478:  d2 27 bf f4  st  %o1, [ %fp + -12 ]
a002f47c:  90 10 20 00  clr  %o0
a002f480:  92 10 20 00  clr  %o1
a002f484:  94 07 bf f4  add  %fp, -12, %o2
a002f488:  7f ff f4 5c  call  0xa002c5f8
a002f48c:  96 10 20 01  mov  1, %o3
a002f490:  80 a4 20 03  cmp  %l0, 3
a002f494:  02 80 00 11  be  0xa002f4d8
a002f498:  80 a4 20 02  cmp  %l0, 2
a002f49c:  02 80 00 11  be  0xa002f4e0
a002f4a0:  92 07 3f ff  add  %i4, -1, %o1
a002f4a4:  b8 0a 60 ff  and  %o1, 0xff, %i4
a002f4a8:  80 a7 20 01  cmp  %i4, 1
a002f4ac:  18 80 00 27  bgu  0xa002f548
a002f4b0:  94 07 bf f4  add  %fp, -12, %o2
a002f4b4:  90 10 20 00  clr  %o0
a002f4b8:  92 10 20 00  clr  %o1
a002f4bc:  7f ff f4 05  call  0xa002c4d0
a002f4c0:  96 10 20 01  mov  1, %o3
a002f4c4:  d4 07 bf f4  ld  [ %fp + -12 ], %o2
a002f4c8:  80 a2 a0 00  cmp  %o2, 0
a002f4cc:  12 bf ff fa  bne  0xa002f4b4
a002f4d0:  94 07 bf f4  add  %fp, -12, %o2
a002f4d4:  30 80 00 1d  b,a   0xa002f548
a002f4d8:  10 80 00 00  b  0xa002f4d8
a002f4dc:  01 00 00 00  nop
a002f4e0:  90 10 20 00  clr  %o0	! 0x0
a002f4e4:  92 10 20 b8  mov  0xb8, %o1
a002f4e8:  94 07 bf f0  add  %fp, -16, %o2
a002f4ec:  96 10 20 01  mov  1, %o3
a002f4f0:  7f ff f3 f8  call  0xa002c4d0
a002f4f4:  c0 27 bf f0  clr  [ %fp + -16 ]
a002f4f8:  f6 07 bf f0  ld  [ %fp + -16 ], %i3
a002f4fc:  b0 0e ff 00  and  %i3, -256, %i0
a002f500:  a0 16 20 01  or  %i0, 1, %l0
a002f504:  e0 27 bf f0  st  %l0, [ %fp + -16 ]
a002f508:  90 10 20 00  clr  %o0
a002f50c:  92 10 20 b8  mov  0xb8, %o1
a002f510:  94 07 bf f0  add  %fp, -16, %o2
a002f514:  7f ff f4 39  call  0xa002c5f8
a002f518:  96 10 20 01  mov  1, %o3
a002f51c:  90 10 20 00  clr  %o0
a002f520:  92 10 20 b8  mov  0xb8, %o1
a002f524:  94 07 bf f0  add  %fp, -16, %o2
a002f528:  7f ff f3 ea  call  0xa002c4d0
a002f52c:  96 10 20 01  mov  1, %o3
a002f530:  da 0f bf f3  ldub  [ %fp + -13 ], %o5
a002f534:  80 a3 60 02  cmp  %o5, 2
a002f538:  12 bf ff fa  bne  0xa002f520
a002f53c:  90 10 20 00  clr  %o0
a002f540:  10 bf ff d9  b  0xa002f4a4
a002f544:  92 07 3f ff  add  %i4, -1, %o1
a002f548:  81 c7 e0 08  ret
a002f54c:  81 e8 00 00  restore
