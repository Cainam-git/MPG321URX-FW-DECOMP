# leon2s FUN_a008a824 0xa008a824-0xa008a868 (68 bytes)
a008a824:  03 33 c0 44  sethi  %hi(0xcf011000), %g1
a008a828:  9a 10 60 18  or  %g1, 0x18, %o5	! 0xcf011018
a008a82c:  80 8a 20 ff  btst  0xff, %o0
a008a830:  02 80 00 05  be  0xa008a844
a008a834:  98 10 62 00  or  %g1, 0x200, %o4
a008a838:  c2 03 40 00  ld  [ %o5 ], %g1
a008a83c:  10 80 00 08  b  0xa008a85c
a008a840:  82 10 60 0c  or  %g1, 0xc, %g1
a008a844:  c2 03 00 00  ld  [ %o4 ], %g1
a008a848:  80 88 60 0f  btst  0xf, %g1
a008a84c:  02 80 00 05  be  0xa008a860
a008a850:  01 00 00 00  nop
a008a854:  c2 03 40 00  ld  [ %o5 ], %g1
a008a858:  82 08 7f f3  and  %g1, -13, %g1
a008a85c:  c2 23 40 00  st  %g1, [ %o5 ]
a008a860:  81 c3 e0 08  retl
a008a864:  01 00 00 00  nop
