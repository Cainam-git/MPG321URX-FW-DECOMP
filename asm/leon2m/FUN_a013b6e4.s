# leon2m FUN_a013b6e4 0xa013b6e4-0xa013b710 (44 bytes)
a013b6e4:  80 a2 20 01  cmp  %o0, 1
a013b6e8:  18 80 00 08  bgu  0xa013b708
a013b6ec:  1b 2a 00 b2  sethi  %hi(0xa802c800), %o5
a013b6f0:  c2 0b 63 bc  ldub  [ %o5 + 0x3bc ], %g1	! 0xa802cbbc
a013b6f4:  80 8a 20 01  btst  1, %o0
a013b6f8:  02 80 00 03  be  0xa013b704
a013b6fc:  82 08 60 fe  and  %g1, 0xfe, %g1
a013b700:  82 10 60 01  or  %g1, 1, %g1
a013b704:  c2 2b 63 bc  stb  %g1, [ %o5 + 0x3bc ]
a013b708:  81 c3 e0 08  retl
a013b70c:  01 00 00 00  nop
