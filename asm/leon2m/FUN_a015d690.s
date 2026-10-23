# leon2m FUN_a015d690 0xa015d690-0xa015d700 (112 bytes)
a015d690:  03 1f fc 00  sethi  %hi(0x7ff00000), %g1
a015d694:  90 0a 00 01  and  %o0, %g1, %o0
a015d698:  1b 3f 30 00  sethi  %hi(0xfcc00000), %o5
a015d69c:  98 02 00 0d  add  %o0, %o5, %o4
a015d6a0:  82 20 00 0c  neg  %o4, %g1
a015d6a4:  80 a3 20 00  cmp  %o4, 0
a015d6a8:  04 80 00 04  ble  0xa015d6b8
a015d6ac:  90 10 00 0c  mov  %o4, %o0
a015d6b0:  10 80 00 12  b  0xa015d6f8
a015d6b4:  92 10 20 00  clr  %o1
a015d6b8:  99 38 60 14  sra  %g1, 0x14, %o4
a015d6bc:  80 a3 20 13  cmp  %o4, 0x13
a015d6c0:  04 80 00 0c  ble  0xa015d6f0
a015d6c4:  03 00 02 00  sethi  %hi(0x80000), %g1
a015d6c8:  98 03 3f ec  add  %o4, -20, %o4
a015d6cc:  9a 38 00 0c  xnor  %g0, %o4, %o5
a015d6d0:  82 10 20 01  mov  1, %g1
a015d6d4:  83 28 40 0d  sll  %g1, %o5, %g1
a015d6d8:  80 a3 20 1e  cmp  %o4, 0x1e
a015d6dc:  04 80 00 03  ble  0xa015d6e8
a015d6e0:  90 10 20 00  clr  %o0
a015d6e4:  82 10 20 01  mov  1, %g1
a015d6e8:  10 80 00 04  b  0xa015d6f8
a015d6ec:  92 10 00 01  mov  %g1, %o1
a015d6f0:  10 bf ff f0  b  0xa015d6b0
a015d6f4:  91 38 40 0c  sra  %g1, %o4, %o0
a015d6f8:  81 c3 e0 08  retl
a015d6fc:  01 00 00 00  nop
