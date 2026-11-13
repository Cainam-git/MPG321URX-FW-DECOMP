# leon2m FUN_a0104e80 0xa0104e80-0xa0104eb0 (48 bytes)
a0104e80:  1b 33 c0 4a  sethi  %hi(0xcf012800), %o5
a0104e84:  98 13 60 90  or  %o5, 0x90, %o4	! 0xcf012890
a0104e88:  c2 03 00 00  ld  [ %o4 ], %g1
a0104e8c:  82 08 60 1f  and  %g1, 0x1f, %g1
a0104e90:  90 0a 3f e0  and  %o0, -32, %o0
a0104e94:  82 10 40 08  or  %g1, %o0, %g1
a0104e98:  82 08 60 ff  and  %g1, 0xff, %g1
a0104e9c:  c2 23 00 00  st  %g1, [ %o4 ]
a0104ea0:  9a 13 61 90  or  %o5, 0x190, %o5
a0104ea4:  c2 23 40 00  st  %g1, [ %o5 ]
a0104ea8:  81 c3 e0 08  retl
a0104eac:  01 00 00 00  nop
