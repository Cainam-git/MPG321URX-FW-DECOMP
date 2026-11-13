# leon2m FUN_a00fe47c 0xa00fe47c-0xa00fe4a4 (40 bytes)
a00fe47c:  03 33 c0 26  sethi  %hi(0xcf009800), %g1
a00fe480:  9a 10 63 b4  or  %g1, 0x3b4, %o5	! 0xcf009bb4
a00fe484:  90 10 63 b8  or  %g1, 0x3b8, %o0
a00fe488:  d8 03 40 00  ld  [ %o5 ], %o4
a00fe48c:  da 02 00 00  ld  [ %o0 ], %o5
a00fe490:  99 2b 20 08  sll  %o4, 8, %o4
a00fe494:  82 13 40 0c  or  %o5, %o4, %g1
a00fe498:  91 28 60 10  sll  %g1, 0x10, %o0
a00fe49c:  81 c3 e0 08  retl
a00fe4a0:  91 32 20 10  srl  %o0, 0x10, %o0
