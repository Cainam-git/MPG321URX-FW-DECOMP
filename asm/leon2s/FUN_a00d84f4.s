# leon2s FUN_a00d84f4 0xa00d84f4-0xa00d8714 (544 bytes)
a00d84f4:  9d e3 bf 80  save  %sp, -128, %sp
a00d84f8:  a0 07 bf e8  add  %fp, -24, %l0
a00d84fc:  92 10 20 00  clr  %o1
a00d8500:  94 10 20 0e  mov  0xe, %o2
a00d8504:  40 3b a4 2a  call  0xa0fc15ac
a00d8508:  90 10 00 10  mov  %l0, %o0
a00d850c:  90 10 00 10  mov  %l0, %o0
a00d8510:  92 10 20 00  clr  %o1
a00d8514:  94 10 20 01  mov  1, %o2
a00d8518:  7f ff fb a7  call  0xa00d73b4
a00d851c:  96 10 20 13  mov  0x13, %o3
a00d8520:  c2 07 bf e0  ld  [ %fp + -32 ], %g1
a00d8524:  17 1f c0 00  sethi  %hi(0x7f000000), %o3
a00d8528:  96 28 40 0b  andn  %g1, %o3, %o3
a00d852c:  03 04 40 00  sethi  %hi(0x11000000), %g1
a00d8530:  96 12 c0 01  or  %o3, %g1, %o3
a00d8534:  d8 07 bf e8  ld  [ %fp + -24 ], %o4
a00d8538:  1b 00 3c 00  sethi  %hi(0xf00000), %o5
a00d853c:  03 00 3c 00  sethi  %hi(0xf00000), %g1
a00d8540:  82 0b 00 01  and  %o4, %g1, %g1
a00d8544:  9a 2a c0 0d  andn  %o3, %o5, %o5
a00d8548:  9a 13 40 01  or  %o5, %g1, %o5
a00d854c:  99 33 20 08  srl  %o4, 8, %o4
a00d8550:  03 3f ff c0  sethi  %hi(0xffff0000), %g1
a00d8554:  82 10 61 ff  or  %g1, 0x1ff, %g1	! 0xffff01ff
a00d8558:  98 0b 20 7f  and  %o4, 0x7f, %o4
a00d855c:  9a 0b 40 01  and  %o5, %g1, %o5
a00d8560:  99 2b 20 09  sll  %o4, 9, %o4
a00d8564:  9a 13 40 0c  or  %o5, %o4, %o5
a00d8568:  c2 17 bf ec  lduh  [ %fp + -20 ], %g1
a00d856c:  c2 37 bf e4  sth  %g1, [ %fp + -28 ]
a00d8570:  94 10 20 01  mov  1, %o2
a00d8574:  da 27 bf e0  st  %o5, [ %fp + -32 ]
a00d8578:  90 07 bf e0  add  %fp, -32, %o0
a00d857c:  92 10 20 02  mov  2, %o1
a00d8580:  96 10 20 03  mov  3, %o3
a00d8584:  7f ff fc e6  call  0xa00d791c
a00d8588:  98 10 20 05  mov  5, %o4
a00d858c:  d4 07 bf e8  ld  [ %fp + -24 ], %o2
a00d8590:  83 32 a0 10  srl  %o2, 0x10, %g1
a00d8594:  82 08 60 f0  and  %g1, 0xf0, %g1
a00d8598:  80 a0 60 80  cmp  %g1, 0x80
a00d859c:  12 80 00 25  bne  0xa00d8630
a00d85a0:  80 a0 60 10  cmp  %g1, 0x10
a00d85a4:  c2 17 bf ec  lduh  [ %fp + -20 ], %g1
a00d85a8:  80 a0 60 00  cmp  %g1, 0
a00d85ac:  19 2a 01 d8  sethi  %hi(0xa8076000), %o4
a00d85b0:  17 2a 01 e2  sethi  %hi(0xa8078800), %o3
a00d85b4:  02 80 00 18  be  0xa00d8614
a00d85b8:  13 2a 01 e1  sethi  %hi(0xa8078400), %o1
a00d85bc:  da 0a e0 32  ldub  [ %o3 + 0x32 ], %o5
a00d85c0:  98 13 20 9c  or  %o4, 0x9c, %o4
a00d85c4:  9b 2b 60 02  sll  %o5, 2, %o5
a00d85c8:  83 32 a0 08  srl  %o2, 8, %g1
a00d85cc:  da 03 00 0d  ld  [ %o4 + %o5 ], %o5
a00d85d0:  82 08 60 7f  and  %g1, 0x7f, %g1
a00d85d4:  c2 23 62 84  st  %g1, [ %o5 + 0x284 ]
a00d85d8:  c2 0a e0 32  ldub  [ %o3 + 0x32 ], %g1
a00d85dc:  83 28 60 02  sll  %g1, 2, %g1
a00d85e0:  da 03 00 01  ld  [ %o4 + %g1 ], %o5
a00d85e4:  c2 03 62 b0  ld  [ %o5 + 0x2b0 ], %g1
a00d85e8:  82 10 60 10  or  %g1, 0x10, %g1
a00d85ec:  c2 23 62 b0  st  %g1, [ %o5 + 0x2b0 ]
a00d85f0:  c2 0a e0 32  ldub  [ %o3 + 0x32 ], %g1
a00d85f4:  83 28 60 02  sll  %g1, 2, %g1
a00d85f8:  da 03 00 01  ld  [ %o4 + %g1 ], %o5
a00d85fc:  c2 03 62 b0  ld  [ %o5 + 0x2b0 ], %g1
a00d8600:  82 08 7f ef  and  %g1, -17, %g1
a00d8604:  c2 23 62 b0  st  %g1, [ %o5 + 0x2b0 ]
a00d8608:  c2 17 bf e4  lduh  [ %fp + -28 ], %g1
a00d860c:  10 80 00 40  b  0xa00d870c
a00d8610:  c2 32 63 f8  sth  %g1, [ %o1 + 0x3f8 ]
a00d8614:  c2 0a e0 32  ldub  [ %o3 + 0x32 ], %g1
a00d8618:  9a 13 20 9c  or  %o4, 0x9c, %o5
a00d861c:  83 28 60 02  sll  %g1, 2, %g1
a00d8620:  c2 03 40 01  ld  [ %o5 + %g1 ], %g1
a00d8624:  c0 20 62 84  clr  [ %g1 + 0x284 ]
a00d8628:  10 80 00 39  b  0xa00d870c
a00d862c:  c0 32 63 f8  clrh  [ %o1 + 0x3f8 ]
a00d8630:  12 80 00 37  bne  0xa00d870c
a00d8634:  c2 17 bf ec  lduh  [ %fp + -20 ], %g1
a00d8638:  80 a0 60 00  cmp  %g1, 0
a00d863c:  19 2a 01 d8  sethi  %hi(0xa8076000), %o4
a00d8640:  17 2a 01 e2  sethi  %hi(0xa8078800), %o3
a00d8644:  02 80 00 14  be  0xa00d8694
a00d8648:  15 2a 01 e2  sethi  %hi(0xa8078800), %o2
a00d864c:  da 0a e0 32  ldub  [ %o3 + 0x32 ], %o5
a00d8650:  98 13 20 9c  or  %o4, 0x9c, %o4
a00d8654:  82 10 20 01  mov  1, %g1
a00d8658:  9b 2b 60 02  sll  %o5, 2, %o5
a00d865c:  c2 2a a0 47  stb  %g1, [ %o2 + 0x47 ]
a00d8660:  da 03 00 0d  ld  [ %o4 + %o5 ], %o5
a00d8664:  c2 03 62 ac  ld  [ %o5 + 0x2ac ], %g1
a00d8668:  82 10 60 40  or  %g1, 0x40, %g1
a00d866c:  c2 23 62 ac  st  %g1, [ %o5 + 0x2ac ]
a00d8670:  da 0a e0 32  ldub  [ %o3 + 0x32 ], %o5
a00d8674:  c2 07 bf e8  ld  [ %fp + -24 ], %g1
a00d8678:  9b 2b 60 02  sll  %o5, 2, %o5
a00d867c:  83 30 60 08  srl  %g1, 8, %g1
a00d8680:  da 03 00 0d  ld  [ %o4 + %o5 ], %o5
a00d8684:  82 08 60 7f  and  %g1, 0x7f, %g1
a00d8688:  c2 23 62 84  st  %g1, [ %o5 + 0x284 ]
a00d868c:  10 80 00 0f  b  0xa00d86c8
a00d8690:  c2 0a e0 32  ldub  [ %o3 + 0x32 ], %g1
a00d8694:  c2 0a e0 32  ldub  [ %o3 + 0x32 ], %g1
a00d8698:  98 13 20 9c  or  %o4, 0x9c, %o4
a00d869c:  83 28 60 02  sll  %g1, 2, %g1
a00d86a0:  c0 2a a0 47  clrb  [ %o2 + 0x47 ]
a00d86a4:  da 03 00 01  ld  [ %o4 + %g1 ], %o5
a00d86a8:  c2 03 62 ac  ld  [ %o5 + 0x2ac ], %g1
a00d86ac:  82 10 60 40  or  %g1, 0x40, %g1
a00d86b0:  c2 23 62 ac  st  %g1, [ %o5 + 0x2ac ]
a00d86b4:  c2 0a e0 32  ldub  [ %o3 + 0x32 ], %g1
a00d86b8:  83 28 60 02  sll  %g1, 2, %g1
a00d86bc:  c2 03 00 01  ld  [ %o4 + %g1 ], %g1
a00d86c0:  c0 20 62 84  clr  [ %g1 + 0x284 ]
a00d86c4:  c2 0a e0 32  ldub  [ %o3 + 0x32 ], %g1
a00d86c8:  83 28 60 02  sll  %g1, 2, %g1
a00d86cc:  da 03 00 01  ld  [ %o4 + %g1 ], %o5
a00d86d0:  c2 03 62 b0  ld  [ %o5 + 0x2b0 ], %g1
a00d86d4:  82 10 60 10  or  %g1, 0x10, %g1
a00d86d8:  c2 23 62 b0  st  %g1, [ %o5 + 0x2b0 ]
a00d86dc:  c2 0a e0 32  ldub  [ %o3 + 0x32 ], %g1
a00d86e0:  83 28 60 02  sll  %g1, 2, %g1
a00d86e4:  da 03 00 01  ld  [ %o4 + %g1 ], %o5
a00d86e8:  c2 03 62 b0  ld  [ %o5 + 0x2b0 ], %g1
a00d86ec:  82 08 7f ef  and  %g1, -17, %g1
a00d86f0:  c2 23 62 b0  st  %g1, [ %o5 + 0x2b0 ]
a00d86f4:  c2 0a e0 32  ldub  [ %o3 + 0x32 ], %g1
a00d86f8:  83 28 60 02  sll  %g1, 2, %g1
a00d86fc:  da 03 00 01  ld  [ %o4 + %g1 ], %o5
a00d8700:  c2 03 62 ac  ld  [ %o5 + 0x2ac ], %g1
a00d8704:  82 08 7f bf  and  %g1, -65, %g1
a00d8708:  c2 23 62 ac  st  %g1, [ %o5 + 0x2ac ]
a00d870c:  81 c7 e0 08  ret
a00d8710:  81 e8 00 00  restore
