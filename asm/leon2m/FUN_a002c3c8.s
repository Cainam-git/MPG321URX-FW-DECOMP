# leon2m FUN_a002c3c8 0xa002c3c8-0xa002c3f4 (44 bytes)
a002c3c8:  9b 2a 20 10  sll  %o0, 0x10, %o5
a002c3cc:  91 33 60 0e  srl  %o5, 0xe, %o0
a002c3d0:  03 33 c0 00  sethi  %hi(0xcf000000), %g1
a002c3d4:  90 12 00 01  or  %o0, %g1, %o0
a002c3d8:  9a 0a 60 ff  and  %o1, 0xff, %o5
a002c3dc:  83 2a 60 10  sll  %o1, 0x10, %g1
a002c3e0:  da 22 00 00  st  %o5, [ %o0 ]
a002c3e4:  93 30 60 18  srl  %g1, 0x18, %o1
a002c3e8:  d2 22 20 04  st  %o1, [ %o0 + 4 ]
a002c3ec:  81 c3 e0 08  retl
a002c3f0:  01 00 00 00  nop
