# leon2m FUN_a002c364 0xa002c364-0xa002c390 (44 bytes)
a002c364:  91 2a 20 10  sll  %o0, 0x10, %o0
a002c368:  83 32 20 0e  srl  %o0, 0xe, %g1
a002c36c:  1b 33 c0 00  sethi  %hi(0xcf000000), %o5
a002c370:  90 10 40 0d  or  %g1, %o5, %o0
a002c374:  da 02 00 00  ld  [ %o0 ], %o5
a002c378:  82 0b 60 ff  and  %o5, 0xff, %g1
a002c37c:  da 02 20 04  ld  [ %o0 + 4 ], %o5
a002c380:  83 28 60 08  sll  %g1, 8, %g1
a002c384:  90 0b 60 ff  and  %o5, 0xff, %o0
a002c388:  81 c3 e0 08  retl
a002c38c:  90 10 40 08  or  %g1, %o0, %o0
