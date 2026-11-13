# leon2m FUN_a00f1690 0xa00f1690-0xa00f16d8 (72 bytes)
a00f1690:  9a 0a 20 ff  and  %o0, 0xff, %o5
a00f1694:  80 a3 60 02  cmp  %o5, 2
a00f1698:  82 40 20 00  addx  %g0, 0, %g1
a00f169c:  82 20 00 01  neg  %g1
a00f16a0:  90 0b 40 01  and  %o5, %g1, %o0
a00f16a4:  1b 2a 00 9a  sethi  %hi(0xa8026800), %o5
a00f16a8:  90 02 00 08  add  %o0, %o0, %o0
a00f16ac:  82 13 62 7a  or  %o5, 0x27a, %g1
a00f16b0:  93 2a 60 10  sll  %o1, 0x10, %o1
a00f16b4:  da 10 40 08  lduh  [ %g1 + %o0 ], %o5
a00f16b8:  93 32 60 10  srl  %o1, 0x10, %o1
a00f16bc:  90 03 40 09  add  %o5, %o1, %o0
a00f16c0:  93 2a 20 02  sll  %o0, 2, %o1
a00f16c4:  03 33 c0 00  sethi  %hi(0xcf000000), %g1
a00f16c8:  9a 12 40 01  or  %o1, %g1, %o5
a00f16cc:  d0 03 40 00  ld  [ %o5 ], %o0
a00f16d0:  81 c3 e0 08  retl
a00f16d4:  90 0a 20 ff  and  %o0, 0xff, %o0
