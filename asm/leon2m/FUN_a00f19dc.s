# leon2m FUN_a00f19dc 0xa00f19dc-0xa00f1a18 (60 bytes)
a00f19dc:  1b 00 06 68  sethi  %hi(0x19a000), %o5
a00f19e0:  90 0a 20 ff  and  %o0, 0xff, %o0
a00f19e4:  91 2a 20 02  sll  %o0, 2, %o0
a00f19e8:  82 13 62 d8  or  %o5, 0x2d8, %g1
a00f19ec:  93 2a 60 10  sll  %o1, 0x10, %o1
a00f19f0:  da 00 40 08  ld  [ %g1 + %o0 ], %o5
a00f19f4:  93 32 60 10  srl  %o1, 0x10, %o1
a00f19f8:  9a 03 40 09  add  %o5, %o1, %o5
a00f19fc:  91 2b 60 02  sll  %o5, 2, %o0
a00f1a00:  03 33 c0 00  sethi  %hi(0xcf000000), %g1
a00f1a04:  9a 12 00 01  or  %o0, %g1, %o5
a00f1a08:  94 0a a0 ff  and  %o2, 0xff, %o2
a00f1a0c:  d4 23 40 00  st  %o2, [ %o5 ]
a00f1a10:  81 c3 e0 08  retl
a00f1a14:  01 00 00 00  nop
