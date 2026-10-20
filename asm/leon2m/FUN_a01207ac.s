# leon2m FUN_a01207ac 0xa01207ac-0xa01207f4 (72 bytes)
a01207ac:  80 a2 20 02  cmp  %o0, 2
a01207b0:  9a 60 20 00  subx  %g0, 0, %o5
a01207b4:  90 0a 00 0d  and  %o0, %o5, %o0
a01207b8:  19 00 06 8b  sethi  %hi(0x1a2c00), %o4
a01207bc:  17 33 c0 45  sethi  %hi(0xcf011400), %o3
a01207c0:  9a 02 00 08  add  %o0, %o0, %o5
a01207c4:  96 12 e0 28  or  %o3, 0x28, %o3
a01207c8:  82 13 23 b0  or  %o4, 0x3b0, %g1
a01207cc:  d8 10 40 0d  lduh  [ %g1 + %o5 ], %o4
a01207d0:  d0 02 c0 00  ld  [ %o3 ], %o0
a01207d4:  9a 12 20 03  or  %o0, 3, %o5
a01207d8:  91 2b 20 02  sll  %o4, 2, %o0
a01207dc:  03 33 c0 00  sethi  %hi(0xcf000000), %g1
a01207e0:  da 22 c0 00  st  %o5, [ %o3 ]
a01207e4:  98 12 00 01  or  %o0, %g1, %o4
a01207e8:  d0 03 00 00  ld  [ %o4 ], %o0
a01207ec:  81 c3 e0 08  retl
a01207f0:  90 0a 20 01  and  %o0, 1, %o0
