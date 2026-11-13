# leon2m FUN_a0140500 0xa0140500-0xa01405d0 (208 bytes)
a0140500:  9d e3 bf 98  save  %sp, -104, %sp
a0140504:  90 0e 20 ff  and  %i0, 0xff, %o0
a0140508:  13 00 06 9a  sethi  %hi(0x1a6800), %o1
a014050c:  a0 12 61 fe  or  %o1, 0x1fe, %l0	! 0x1a69fe
a0140510:  b0 5a 20 26  smul  %o0, 0x26, %i0
a0140514:  c2 4c 00 18  ldsb  [ %l0 + %i0 ], %g1
a0140518:  80 a0 60 00  cmp  %g1, 0
a014051c:  16 80 00 2b  bge  0xa01405c8
a0140520:  f0 0c 00 18  ldub  [ %l0 + %i0 ], %i0
a0140524:  7f ff 92 6b  call  0xa0124ed0
a0140528:  01 00 00 00  nop
a014052c:  98 0e 20 ff  and  %i0, 0xff, %o4
a0140530:  b0 5b 20 26  smul  %o4, 0x26, %i0
a0140534:  d0 0c 00 18  ldub  [ %l0 + %i0 ], %o0
a0140538:  9e 02 00 08  add  %o0, %o0, %o7
a014053c:  96 03 c0 08  add  %o7, %o0, %o3
a0140540:  95 2a 20 03  sll  %o0, 3, %o2
a0140544:  9a 02 80 08  add  %o2, %o0, %o5
a0140548:  9e 06 00 10  add  %i0, %l0, %o7
a014054c:  13 2a 00 b2  sethi  %hi(0xa802c800), %o1
a0140550:  03 00 06 9a  sethi  %hi(0x1a6800), %g1
a0140554:  b0 12 63 dc  or  %o1, 0x3dc, %i0
a0140558:  99 2b 60 02  sll  %o5, 2, %o4
a014055c:  a0 10 62 24  or  %g1, 0x224, %l0
a0140560:  93 2a e0 02  sll  %o3, 2, %o1
a0140564:  9a 03 00 10  add  %o4, %l0, %o5
a0140568:  d6 0b 60 03  ldub  [ %o5 + 3 ], %o3
a014056c:  80 a2 e0 00  cmp  %o3, 0
a0140570:  12 80 00 0e  bne  0xa01405a8
a0140574:  90 02 40 18  add  %o1, %i0, %o0
a0140578:  d4 0a 20 08  ldub  [ %o0 + 8 ], %o2
a014057c:  d6 0b e0 04  ldub  [ %o7 + 4 ], %o3
a0140580:  91 2a e0 08  sll  %o3, 8, %o0
a0140584:  c2 16 00 09  lduh  [ %i0 + %o1 ], %g1
a0140588:  9a 5a 80 08  smul  %o2, %o0, %o5
a014058c:  a0 03 40 01  add  %o5, %g1, %l0
a0140590:  82 0c 30 00  and  %l0, -4096, %g1
a0140594:  99 28 60 10  sll  %g1, 0x10, %o4
a0140598:  7f ff cf b3  call  0xa0134464
a014059c:  91 33 20 10  srl  %o4, 0x10, %o0
a01405a0:  7f ff 92 45  call  0xa0124eb4
a01405a4:  81 e8 00 00  restore
a01405a8:  03 2a 00 b2  sethi  %hi(0xa802c800), %g1
a01405ac:  e0 0b e0 01  ldub  [ %o7 + 1 ], %l0
a01405b0:  9a 10 63 dc  or  %g1, 0x3dc, %o5
a01405b4:  de 13 40 09  lduh  [ %o5 + %o1 ], %o7
a01405b8:  b1 2c 20 0b  sll  %l0, 0xb, %i0
a01405bc:  92 06 00 0f  add  %i0, %o7, %o1
a01405c0:  10 bf ff f5  b  0xa0140594
a01405c4:  82 0a 70 00  and  %o1, -4096, %g1
a01405c8:  81 c7 e0 08  ret
a01405cc:  81 e8 00 00  restore
