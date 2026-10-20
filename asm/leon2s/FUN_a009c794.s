# leon2s FUN_a009c794 0xa009c794-0xa009c7e4 (80 bytes)
a009c794:  9a 0a 20 ff  and  %o0, 0xff, %o5
a009c798:  03 2a 01 f6  sethi  %hi(0xa807d800), %g1
a009c79c:  92 0a 60 ff  and  %o1, 0xff, %o1
a009c7a0:  96 5b 60 34  smul  %o5, 0x34, %o3
a009c7a4:  98 10 63 00  or  %g1, 0x300, %o4
a009c7a8:  80 a2 60 01  cmp  %o1, 1
a009c7ac:  90 10 20 19  mov  0x19, %o0
a009c7b0:  12 80 00 07  bne  0xa009c7cc
a009c7b4:  96 02 c0 0c  add  %o3, %o4, %o3
a009c7b8:  d2 02 e0 04  ld  [ %o3 + 4 ], %o1
a009c7bc:  92 02 60 34  add  %o1, 0x34, %o1
a009c7c0:  82 13 c0 00  mov  %o7, %g1
a009c7c4:  40 00 2a fa  call  0xa00a73ac
a009c7c8:  9e 10 40 00  mov  %g1, %o7
a009c7cc:  d2 02 e0 04  ld  [ %o3 + 4 ], %o1
a009c7d0:  92 02 60 34  add  %o1, 0x34, %o1
a009c7d4:  90 10 20 19  mov  0x19, %o0
a009c7d8:  82 13 c0 00  mov  %o7, %g1
a009c7dc:  40 00 2a fe  call  0xa00a73d4
a009c7e0:  9e 10 40 00  mov  %g1, %o7
