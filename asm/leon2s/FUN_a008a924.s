# leon2s FUN_a008a924 0xa008a924-0xa008a95c (56 bytes)
a008a924:  1b 33 c0 44  sethi  %hi(0xcf011000), %o5
a008a928:  99 2a 20 10  sll  %o0, 0x10, %o4
a008a92c:  82 13 60 60  or  %o5, 0x60, %g1
a008a930:  90 0a 20 ff  and  %o0, 0xff, %o0
a008a934:  d0 20 40 00  st  %o0, [ %g1 ]
a008a938:  82 13 60 64  or  %o5, 0x64, %g1
a008a93c:  99 33 20 18  srl  %o4, 0x18, %o4
a008a940:  d8 20 40 00  st  %o4, [ %g1 ]
a008a944:  82 13 60 68  or  %o5, 0x68, %g1
a008a948:  d0 20 40 00  st  %o0, [ %g1 ]
a008a94c:  9a 13 60 6c  or  %o5, 0x6c, %o5
a008a950:  d8 23 40 00  st  %o4, [ %o5 ]
a008a954:  81 c3 e0 08  retl
a008a958:  01 00 00 00  nop
