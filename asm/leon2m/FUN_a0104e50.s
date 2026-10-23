# leon2m FUN_a0104e50 0xa0104e50-0xa0104e80 (48 bytes)
a0104e50:  1b 33 c0 4a  sethi  %hi(0xcf012800), %o5
a0104e54:  98 13 60 90  or  %o5, 0x90, %o4	! 0xcf012890
a0104e58:  c2 03 00 00  ld  [ %o4 ], %g1
a0104e5c:  82 08 7f e1  and  %g1, -31, %g1
a0104e60:  90 0a 20 1e  and  %o0, 0x1e, %o0
a0104e64:  82 10 40 08  or  %g1, %o0, %g1
a0104e68:  82 08 60 ff  and  %g1, 0xff, %g1
a0104e6c:  c2 23 00 00  st  %g1, [ %o4 ]
a0104e70:  9a 13 61 90  or  %o5, 0x190, %o5
a0104e74:  c2 23 40 00  st  %g1, [ %o5 ]
a0104e78:  81 c3 e0 08  retl
a0104e7c:  01 00 00 00  nop
