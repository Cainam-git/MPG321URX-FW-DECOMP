# leon2s FUN_a0091a88 0xa0091a88-0xa0091ac4 (60 bytes)
a0091a88:  90 0a 20 ff  and  %o0, 0xff, %o0
a0091a8c:  9b 2a 20 03  sll  %o0, 3, %o5
a0091a90:  9a 23 40 08  sub  %o5, %o0, %o5
a0091a94:  03 2a 01 f5  sethi  %hi(0xa807d400), %g1
a0091a98:  9b 2b 60 02  sll  %o5, 2, %o5
a0091a9c:  82 10 61 80  or  %g1, 0x180, %g1
a0091aa0:  80 a2 20 01  cmp  %o0, 1
a0091aa4:  18 80 00 06  bgu  0xa0091abc
a0091aa8:  98 03 40 01  add  %o5, %g1, %o4
a0091aac:  da 03 20 14  ld  [ %o4 + 0x14 ], %o5
a0091ab0:  03 00 00 10  sethi  %hi(0x4000), %g1
a0091ab4:  82 2b 40 01  andn  %o5, %g1, %g1
a0091ab8:  c2 23 20 14  st  %g1, [ %o4 + 0x14 ]
a0091abc:  81 c3 e0 08  retl
a0091ac0:  01 00 00 00  nop
