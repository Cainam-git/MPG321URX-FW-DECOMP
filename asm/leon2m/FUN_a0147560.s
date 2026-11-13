# leon2m FUN_a0147560 0xa0147560-0xa0147610 (176 bytes)
a0147560:  9d e3 bf 98  save  %sp, -104, %sp
a0147564:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0147568:  80 a6 20 01  cmp  %i0, 1
a014756c:  02 80 00 0b  be  0xa0147598
a0147570:  82 10 20 01  mov  1, %g1
a0147574:  80 a6 20 01  cmp  %i0, 1
a0147578:  04 80 00 1f  ble  0xa01475f4
a014757c:  80 a6 20 02  cmp  %i0, 2
a0147580:  02 80 00 06  be  0xa0147598
a0147584:  82 10 20 02  mov  2, %g1
a0147588:  80 a6 20 03  cmp  %i0, 3
a014758c:  02 80 00 03  be  0xa0147598
a0147590:  82 10 20 03  mov  3, %g1
a0147594:  82 10 3f ff  mov  -1, %g1
a0147598:  9a 08 60 ff  and  %g1, 0xff, %o5
a014759c:  80 a3 60 03  cmp  %o5, 3
a01475a0:  18 80 00 11  bgu  0xa01475e4
a01475a4:  11 00 06 9b  sethi  %hi(0x1a6c00), %o0
a01475a8:  9f 2b 60 04  sll  %o5, 4, %o7
a01475ac:  96 23 c0 0d  sub  %o7, %o5, %o3
a01475b0:  15 2a 00 b7  sethi  %hi(0xa802dc00), %o2
a01475b4:  83 2a e0 03  sll  %o3, 3, %g1
a01475b8:  9a 12 a3 30  or  %o2, 0x330, %o5
a01475bc:  d2 03 40 01  ld  [ %o5 + %g1 ], %o1
a01475c0:  99 32 60 04  srl  %o1, 4, %o4
a01475c4:  90 0b 20 0f  and  %o4, 0xf, %o0
a01475c8:  80 a2 20 04  cmp  %o0, 4
a01475cc:  02 80 00 0f  be  0xa0147608
a01475d0:  01 00 00 00  nop
a01475d4:  7f fe bb 7a  call  0xa00f63bc
a01475d8:  b0 10 00 19  mov  %i1, %i0
a01475dc:  7f fe bb 98  call  0xa00f643c
a01475e0:  81 e8 00 00  restore
a01475e4:  7f fe 5e e3  call  0xa00df170
a01475e8:  90 12 21 d8  or  %o0, 0x1d8, %o0
a01475ec:  10 bf ff ef  b  0xa01475a8
a01475f0:  9a 10 20 00  clr  %o5
a01475f4:  80 a6 20 00  cmp  %i0, 0
a01475f8:  02 bf ff e8  be  0xa0147598
a01475fc:  82 10 20 00  clr  %g1
a0147600:  10 bf ff e6  b  0xa0147598
a0147604:  82 10 3f ff  mov  -1, %g1
a0147608:  81 c7 e0 08  ret
a014760c:  81 e8 00 00  restore
