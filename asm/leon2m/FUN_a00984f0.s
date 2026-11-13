# leon2m FUN_a00984f0 0xa00984f0-0xa0098618 (296 bytes)
a00984f0:  9d e3 bf 98  save  %sp, -104, %sp
a00984f4:  25 2a 00 97  sethi  %hi(0xa8025c00), %l2
a00984f8:  21 09 24 92  sethi  %hi(0x24924800), %l0
a00984fc:  de 0c a0 56  ldub  [ %l2 + 0x56 ], %o7
a0098500:  a0 14 21 25  or  %l0, 0x125, %l0
a0098504:  80 53 c0 10  umul  %o7, %l0, %g0
a0098508:  97 40 00 00  rd  %y, %o3
a009850c:  98 23 c0 0b  sub  %o7, %o3, %o4
a0098510:  a3 33 20 01  srl  %o4, 1, %l1
a0098514:  94 02 c0 11  add  %o3, %l1, %o2
a0098518:  83 32 a0 02  srl  %o2, 2, %g1
a009851c:  93 28 60 03  sll  %g1, 3, %o1
a0098520:  9a 22 40 01  sub  %o1, %g1, %o5
a0098524:  90 23 c0 0d  sub  %o7, %o5, %o0
a0098528:  40 00 43 a5  call  0xa00a93bc
a009852c:  90 0a 20 ff  and  %o0, 0xff, %o0
a0098530:  de 0c a0 56  ldub  [ %l2 + 0x56 ], %o7
a0098534:  80 53 c0 10  umul  %o7, %l0, %g0
a0098538:  97 40 00 00  rd  %y, %o3
a009853c:  98 23 c0 0b  sub  %o7, %o3, %o4
a0098540:  a3 33 20 01  srl  %o4, 1, %l1
a0098544:  94 02 c0 11  add  %o3, %l1, %o2
a0098548:  83 32 a0 02  srl  %o2, 2, %g1
a009854c:  93 28 60 03  sll  %g1, 3, %o1
a0098550:  9a 22 40 01  sub  %o1, %g1, %o5
a0098554:  a4 23 c0 0d  sub  %o7, %o5, %l2
a0098558:  92 0c a0 ff  and  %l2, 0xff, %o1
a009855c:  94 10 20 00  clr  %o2
a0098560:  40 00 3e f7  call  0xa00a813c
a0098564:  90 10 20 01  mov  1, %o0
a0098568:  25 2a 00 ab  sethi  %hi(0xa802ac00), %l2
a009856c:  d0 04 a3 ec  ld  [ %l2 + 0x3ec ], %o0	! 0xa802afec
a0098570:  9e 02 3f 7a  add  %o0, -134, %o7
a0098574:  80 53 c0 10  umul  %o7, %l0, %g0
a0098578:  97 40 00 00  rd  %y, %o3
a009857c:  98 23 c0 0b  sub  %o7, %o3, %o4
a0098580:  a3 33 20 01  srl  %o4, 1, %l1
a0098584:  94 02 c0 11  add  %o3, %l1, %o2
a0098588:  83 32 a0 02  srl  %o2, 2, %g1
a009858c:  93 28 60 03  sll  %g1, 3, %o1
a0098590:  9a 22 40 01  sub  %o1, %g1, %o5
a0098594:  98 23 c0 0d  sub  %o7, %o5, %o4
a0098598:  90 0b 20 ff  and  %o4, 0xff, %o0
a009859c:  92 10 20 00  clr  %o1
a00985a0:  40 00 44 2c  call  0xa00a9650
a00985a4:  23 2a 00 b4  sethi  %hi(0xa802d000), %l1
a00985a8:  a2 14 62 90  or  %l1, 0x290, %l1	! 0xa802d290
a00985ac:  d6 0c 61 a3  ldub  [ %l1 + 0x1a3 ], %o3
a00985b0:  94 02 c0 11  add  %o3, %l1, %o2
a00985b4:  d6 0a a1 8a  ldub  [ %o2 + 0x18a ], %o3
a00985b8:  80 52 c0 10  umul  %o3, %l0, %g0
a00985bc:  91 40 00 00  rd  %y, %o0
a00985c0:  92 22 c0 08  sub  %o3, %o0, %o1
a00985c4:  83 32 60 01  srl  %o1, 1, %g1
a00985c8:  9a 02 00 01  add  %o0, %g1, %o5
a00985cc:  a1 33 60 02  srl  %o5, 2, %l0
a00985d0:  9f 2c 20 03  sll  %l0, 3, %o7
a00985d4:  98 23 c0 10  sub  %o7, %l0, %o4
a00985d8:  94 22 c0 0c  sub  %o3, %o4, %o2
a00985dc:  92 0a a0 ff  and  %o2, 0xff, %o1
a00985e0:  90 10 20 01  mov  1, %o0
a00985e4:  40 00 3e d6  call  0xa00a813c
a00985e8:  94 10 20 01  mov  1, %o2
a00985ec:  d0 0c 61 a3  ldub  [ %l1 + 0x1a3 ], %o0
a00985f0:  92 02 20 26  add  %o0, 0x26, %o1
a00985f4:  d2 24 a3 ec  st  %o1, [ %l2 + 0x3ec ]
a00985f8:  40 00 42 85  call  0xa00a900c
a00985fc:  92 10 20 01  mov  1, %o1
a0098600:  1b 2a 00 ac  sethi  %hi(0xa802b000), %o5
a0098604:  d0 0b 60 8e  ldub  [ %o5 + 0x8e ], %o0	! 0xa802b08e
a0098608:  82 12 20 02  or  %o0, 2, %g1
a009860c:  c2 2b 60 8e  stb  %g1, [ %o5 + 0x8e ]
a0098610:  81 c7 e0 08  ret
a0098614:  81 e8 00 00  restore
