# leon2s FUN_a008a1b4 0xa008a1b4-0xa008a1f8 (68 bytes)
a008a1b4:  82 0a 20 ff  and  %o0, 0xff, %g1
a008a1b8:  97 2a a0 05  sll  %o2, 5, %o3
a008a1bc:  90 0a 60 ff  and  %o1, 0xff, %o0
a008a1c0:  96 0a e0 e0  and  %o3, 0xe0, %o3
a008a1c4:  94 10 20 20  mov  0x20, %o2
a008a1c8:  80 a0 60 04  cmp  %g1, 4
a008a1cc:  02 80 00 05  be  0xa008a1e0
a008a1d0:  92 10 20 03  mov  3, %o1
a008a1d4:  80 a0 60 06  cmp  %g1, 6
a008a1d8:  12 80 00 05  bne  0xa008a1ec
a008a1dc:  01 00 00 00  nop
a008a1e0:  82 13 c0 00  mov  %o7, %g1
a008a1e4:  40 00 74 06  call  0xa00a71fc
a008a1e8:  9e 10 40 00  mov  %g1, %o7
a008a1ec:  01 00 00 00  nop
a008a1f0:  81 c3 e0 08  retl
a008a1f4:  01 00 00 00  nop
