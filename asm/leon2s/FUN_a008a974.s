# leon2s FUN_a008a974 0xa008a974-0xa008a9b0 (60 bytes)
a008a974:  1b 33 c0 44  sethi  %hi(0xcf011000), %o5
a008a978:  98 13 60 14  or  %o5, 0x14, %o4	! 0xcf011014
a008a97c:  82 10 20 ff  mov  0xff, %g1
a008a980:  c2 23 00 00  st  %g1, [ %o4 ]
a008a984:  98 13 60 48  or  %o5, 0x48, %o4
a008a988:  c2 03 00 00  ld  [ %o4 ], %g1
a008a98c:  82 10 60 60  or  %g1, 0x60, %g1
a008a990:  c2 23 00 00  st  %g1, [ %o4 ]
a008a994:  90 0a 20 ff  and  %o0, 0xff, %o0
a008a998:  82 13 60 58  or  %o5, 0x58, %g1
a008a99c:  d0 20 40 00  st  %o0, [ %g1 ]
a008a9a0:  9a 13 60 5c  or  %o5, 0x5c, %o5
a008a9a4:  d0 23 40 00  st  %o0, [ %o5 ]
a008a9a8:  81 c3 e0 08  retl
a008a9ac:  01 00 00 00  nop
