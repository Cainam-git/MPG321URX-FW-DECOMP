# leon2s FUN_a008a7a0 0xa008a7a0-0xa008a7bc (28 bytes)
a008a7a0:  1b 33 c0 44  sethi  %hi(0xcf011000), %o5
a008a7a4:  9a 13 60 08  or  %o5, 8, %o5	! 0xcf011008
a008a7a8:  c2 03 40 00  ld  [ %o5 ], %g1
a008a7ac:  82 08 60 fe  and  %g1, 0xfe, %g1
a008a7b0:  c2 23 40 00  st  %g1, [ %o5 ]
a008a7b4:  81 c3 e0 08  retl
a008a7b8:  01 00 00 00  nop
