# leon2m FUN_a00b848c 0xa00b848c-0xa00b8668 (476 bytes)  [FUN_a00b8660 = unreachable ret/restore tail, merged]
a00b848c:  9d e3 bf 98  save  %sp, -104, %sp
a00b8490:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a00b8494:  b0 14 22 90  or  %l0, 0x290, %i0	! 0xa802d290
a00b8498:  40 02 30 59  call  0xa01445fc
a00b849c:  d0 0e 20 1e  ldub  [ %i0 + 0x1e ], %o0
a00b84a0:  40 02 30 3f  call  0xa014459c
a00b84a4:  90 0a 20 ff  and  %o0, 0xff, %o0
a00b84a8:  90 0a 20 ff  and  %o0, 0xff, %o0
a00b84ac:  c2 0e 20 1e  ldub  [ %i0 + 0x1e ], %g1
a00b84b0:  80 a0 40 08  cmp  %g1, %o0
a00b84b4:  02 80 00 0b  be  0xa00b84e0
a00b84b8:  01 00 00 00  nop
a00b84bc:  40 02 30 50  call  0xa01445fc
a00b84c0:  90 10 00 01  mov  %g1, %o0
a00b84c4:  40 02 30 36  call  0xa014459c
a00b84c8:  90 0a 20 ff  and  %o0, 0xff, %o0
a00b84cc:  1b 2a 00 ac  sethi  %hi(0xa802b000), %o5
a00b84d0:  d2 0b 60 8e  ldub  [ %o5 + 0x8e ], %o1	! 0xa802b08e
a00b84d4:  82 12 60 02  or  %o1, 2, %g1
a00b84d8:  c2 2b 60 8e  stb  %g1, [ %o5 + 0x8e ]
a00b84dc:  d0 2e 20 1e  stb  %o0, [ %i0 + 0x1e ]
a00b84e0:  40 02 2a 6b  call  0xa0142e8c
a00b84e4:  90 10 20 00  clr  %o0
a00b84e8:  94 0a 20 ff  and  %o0, 0xff, %o2
a00b84ec:  80 a2 a0 05  cmp  %o2, 5
a00b84f0:  02 80 00 09  be  0xa00b8514
a00b84f4:  25 2a 00 b3  sethi  %hi(0xa802cc00), %l2
a00b84f8:  90 10 20 00  clr  %o0
a00b84fc:  40 02 34 59  call  0xa0145660
a00b8500:  92 10 20 16  mov  0x16, %o1
a00b8504:  97 2a 20 10  sll  %o0, 0x10, %o3
a00b8508:  80 a2 e0 00  cmp  %o3, 0
a00b850c:  22 80 00 1e  be,a   0xa00b8584
a00b8510:  d8 0e 21 d5  ldub  [ %i0 + 0x1d5 ], %o4
a00b8514:  c2 14 a3 f4  lduh  [ %l2 + 0x3f4 ], %g1
a00b8518:  80 88 64 00  btst  0x400, %g1
a00b851c:  02 80 00 42  be  0xa00b8624
a00b8520:  31 2a 00 b3  sethi  %hi(0xa802cc00), %i0
a00b8524:  a2 14 22 90  or  %l0, 0x290, %l1
a00b8528:  11 00 00 15  sethi  %hi(0x5400), %o0
a00b852c:  a0 12 21 aa  or  %o0, 0x1aa, %l0	! 0x55aa
a00b8530:  de 14 61 f6  lduh  [ %l1 + 0x1f6 ], %o7
a00b8534:  80 a3 c0 10  cmp  %o7, %l0
a00b8538:  02 80 00 05  be  0xa00b854c
a00b853c:  c2 16 23 f4  lduh  [ %i0 + 0x3f4 ], %g1
a00b8540:  7f ff fe 97  call  0xa00b7f9c
a00b8544:  90 10 20 1e  mov  0x1e, %o0
a00b8548:  c2 16 23 f4  lduh  [ %i0 + 0x3f4 ], %g1
a00b854c:  9a 08 7b ff  and  %g1, -1025, %o5
a00b8550:  40 00 7d fe  call  0xa00d7d48
a00b8554:  da 36 23 f4  sth  %o5, [ %i0 + 0x3f4 ]
a00b8558:  80 a2 20 00  cmp  %o0, 0
a00b855c:  22 80 00 2f  be,a   0xa00b8618
a00b8560:  f0 14 a3 f4  lduh  [ %l2 + 0x3f4 ], %i0
a00b8564:  d2 14 61 f6  lduh  [ %l1 + 0x1f6 ], %o1
a00b8568:  80 a2 40 10  cmp  %o1, %l0
a00b856c:  22 80 00 2b  be,a   0xa00b8618
a00b8570:  f0 14 a3 f4  lduh  [ %l2 + 0x3f4 ], %i0
a00b8574:  e4 16 23 f4  lduh  [ %i0 + 0x3f4 ], %l2
a00b8578:  a0 14 a2 00  or  %l2, 0x200, %l0
a00b857c:  10 80 00 38  b  0xa00b865c
a00b8580:  e0 36 23 f4  sth  %l0, [ %i0 + 0x3f4 ]
a00b8584:  80 a3 20 00  cmp  %o4, 0
a00b8588:  12 bf ff e4  bne  0xa00b8518
a00b858c:  c2 14 a3 f4  lduh  [ %l2 + 0x3f4 ], %g1
a00b8590:  7f ff fe 83  call  0xa00b7f9c
a00b8594:  90 10 20 15  mov  0x15, %o0
a00b8598:  40 02 3c 61  call  0xa014771c
a00b859c:  90 10 20 00  clr  %o0
a00b85a0:  90 10 20 00  clr  %o0
a00b85a4:  40 02 3a 07  call  0xa0146dc0
a00b85a8:  92 10 20 00  clr  %o1
a00b85ac:  94 10 20 00  clr  %o2
a00b85b0:  90 10 20 08  mov  8, %o0
a00b85b4:  40 02 39 a3  call  0xa0146c40
a00b85b8:  92 10 20 00  clr  %o1
a00b85bc:  03 2a 00 ac  sethi  %hi(0xa802b000), %g1
a00b85c0:  92 10 20 24  mov  0x24, %o1
a00b85c4:  d2 28 60 8f  stb  %o1, [ %g1 + 0x8f ]
a00b85c8:  90 10 20 00  clr  %o0
a00b85cc:  40 02 39 fd  call  0xa0146dc0
a00b85d0:  92 10 20 01  mov  1, %o1
a00b85d4:  a2 14 a3 f4  or  %l2, 0x3f4, %l1
a00b85d8:  da 14 60 3e  lduh  [ %l1 + 0x3e ], %o5
a00b85dc:  11 3f ff e0  sethi  %hi(0xffff8000), %o0
a00b85e0:  b0 2b 40 08  andn  %o5, %o0, %i0
a00b85e4:  f0 34 60 3e  sth  %i0, [ %l1 + 0x3e ]
a00b85e8:  90 10 20 00  clr  %o0
a00b85ec:  40 02 34 1d  call  0xa0145660
a00b85f0:  92 10 20 16  mov  0x16, %o1
a00b85f4:  9f 2a 20 10  sll  %o0, 0x10, %o7
a00b85f8:  80 a3 e0 00  cmp  %o7, 0
a00b85fc:  02 bf ff c7  be  0xa00b8518
a00b8600:  c2 14 a3 f4  lduh  [ %l2 + 0x3f4 ], %g1
a00b8604:  15 2a 00 ac  sethi  %hi(0xa802b000), %o2
a00b8608:  d8 0a a0 8e  ldub  [ %o2 + 0x8e ], %o4	! 0xa802b08e
a00b860c:  96 13 20 01  or  %o4, 1, %o3
a00b8610:  10 bf ff c1  b  0xa00b8514
a00b8614:  d6 2a a0 8e  stb  %o3, [ %o2 + 0x8e ]
a00b8618:  a2 0e 3d ff  and  %i0, -513, %l1
a00b861c:  10 80 00 10  b  0xa00b865c
a00b8620:  e2 34 a3 f4  sth  %l1, [ %l2 + 0x3f4 ]
a00b8624:  94 08 7d ff  and  %g1, -513, %o2
a00b8628:  40 00 7d c8  call  0xa00d7d48
a00b862c:  d4 36 23 f4  sth  %o2, [ %i0 + 0x3f4 ]
a00b8630:  80 a2 20 00  cmp  %o0, 0
a00b8634:  02 80 00 0a  be  0xa00b865c
a00b8638:  90 14 22 90  or  %l0, 0x290, %o0
a00b863c:  1f 00 00 15  sethi  %hi(0x5400), %o7
a00b8640:  d8 12 21 f6  lduh  [ %o0 + 0x1f6 ], %o4
a00b8644:  96 13 e1 aa  or  %o7, 0x1aa, %o3
a00b8648:  80 a3 00 0b  cmp  %o4, %o3
a00b864c:  02 80 00 04  be  0xa00b865c
a00b8650:  01 00 00 00  nop
a00b8654:  7f ff fe 52  call  0xa00b7f9c
a00b8658:  91 e8 20 11  restore  %g0, 0x11, %o0
a00b865c:  01 00 00 00  nop
a00b8660:  81 c7 e0 08  ret
a00b8664:  81 e8 00 00  restore
