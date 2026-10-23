# leon2m FUN_a00f30c8 0xa00f30c8-0xa00f30f0 (40 bytes)
a00f30c8:  9a 0a 60 ff  and  %o1, 0xff, %o5
a00f30cc:  da 22 00 00  st  %o5, [ %o0 ]
a00f30d0:  83 32 60 08  srl  %o1, 8, %g1
a00f30d4:  82 08 60 ff  and  %g1, 0xff, %g1
a00f30d8:  9b 32 60 10  srl  %o1, 0x10, %o5
a00f30dc:  c2 22 20 04  st  %g1, [ %o0 + 4 ]
a00f30e0:  92 0b 60 ff  and  %o5, 0xff, %o1
a00f30e4:  d2 22 20 08  st  %o1, [ %o0 + 8 ]
a00f30e8:  81 c3 e0 08  retl
a00f30ec:  01 00 00 00  nop
