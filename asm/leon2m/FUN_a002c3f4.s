# leon2m FUN_a002c3f4 0xa002c3f4-0xa002c42c (56 bytes)
a002c3f4:  83 2a 20 10  sll  %o0, 0x10, %g1
a002c3f8:  9b 30 60 10  srl  %g1, 0x10, %o5
a002c3fc:  92 0a 60 ff  and  %o1, 0xff, %o1
a002c400:  90 03 40 09  add  %o5, %o1, %o0
a002c404:  03 33 c0 00  sethi  %hi(0xcf000000), %g1
a002c408:  93 2a 20 02  sll  %o0, 2, %o1
a002c40c:  90 12 40 01  or  %o1, %g1, %o0
a002c410:  9a 0a a0 ff  and  %o2, 0xff, %o5
a002c414:  83 2a a0 10  sll  %o2, 0x10, %g1
a002c418:  da 22 00 00  st  %o5, [ %o0 ]
a002c41c:  95 30 60 18  srl  %g1, 0x18, %o2
a002c420:  d4 22 20 04  st  %o2, [ %o0 + 4 ]
a002c424:  81 c3 e0 08  retl
a002c428:  01 00 00 00  nop
