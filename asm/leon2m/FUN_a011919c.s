# leon2m FUN_a011919c 0xa011919c-0xa01191fc (96 bytes)
a011919c:  98 0a 20 ff  and  %o0, 0xff, %o4
a01191a0:  80 a3 20 02  cmp  %o4, 2
a01191a4:  9a 40 20 00  addx  %g0, 0, %o5
a01191a8:  82 20 00 0d  neg  %o5, %g1
a01191ac:  90 0b 00 01  and  %o4, %g1, %o0
a01191b0:  17 2a 00 9e  sethi  %hi(0xa8027800), %o3
a01191b4:  98 02 00 08  add  %o0, %o0, %o4
a01191b8:  9a 12 e2 a8  or  %o3, 0x2a8, %o5
a01191bc:  d6 13 40 0c  lduh  [ %o5 + %o4 ], %o3
a01191c0:  82 0a 60 ff  and  %o1, 0xff, %g1
a01191c4:  9a 02 c0 01  add  %o3, %g1, %o5
a01191c8:  98 03 60 01  add  %o5, 1, %o4
a01191cc:  17 33 c0 00  sethi  %hi(0xcf000000), %o3
a01191d0:  93 2b 60 02  sll  %o5, 2, %o1
a01191d4:  9a 12 40 0b  or  %o1, %o3, %o5
a01191d8:  82 0a a0 ff  and  %o2, 0xff, %g1
a01191dc:  93 2b 20 02  sll  %o4, 2, %o1
a01191e0:  91 2a a0 10  sll  %o2, 0x10, %o0
a01191e4:  c2 23 40 00  st  %g1, [ %o5 ]
a01191e8:  98 12 40 0b  or  %o1, %o3, %o4
a01191ec:  95 32 20 18  srl  %o0, 0x18, %o2
a01191f0:  d4 23 00 00  st  %o2, [ %o4 ]
a01191f4:  81 c3 e0 08  retl
a01191f8:  01 00 00 00  nop
