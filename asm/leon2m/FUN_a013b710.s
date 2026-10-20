# leon2m FUN_a013b710 0xa013b710-0xa013b750 (64 bytes)
a013b710:  1b 2a 00 b2  sethi  %hi(0xa802c800), %o5
a013b714:  80 8a 20 ff  btst  0xff, %o0
a013b718:  02 80 00 08  be  0xa013b738
a013b71c:  98 10 00 0d  mov  %o5, %o4
a013b720:  d0 0b 63 bc  ldub  [ %o5 + 0x3bc ], %o0
a013b724:  82 12 20 02  or  %o0, 2, %g1
a013b728:  c2 2b 63 bc  stb  %g1, [ %o5 + 0x3bc ]
a013b72c:  82 13 c0 00  mov  %o7, %g1
a013b730:  7f fe ed 64  call  0xa00f6cc0
a013b734:  9e 10 40 00  mov  %g1, %o7
a013b738:  c2 0b 63 bc  ldub  [ %o5 + 0x3bc ], %g1
a013b73c:  9a 08 7f fd  and  %g1, -3, %o5
a013b740:  da 2b 23 bc  stb  %o5, [ %o4 + 0x3bc ]
a013b744:  82 13 c0 00  mov  %o7, %g1
a013b748:  7f fe ed 57  call  0xa00f6ca4
a013b74c:  9e 10 40 00  mov  %g1, %o7
