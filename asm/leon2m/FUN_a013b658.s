# leon2m FUN_a013b658 0xa013b658-0xa013b684 (44 bytes)
a013b658:  03 2a 00 b2  sethi  %hi(0xa802c800), %g1
a013b65c:  da 08 63 bc  ldub  [ %g1 + 0x3bc ], %o5	! 0xa802cbbc
a013b660:  94 10 00 08  mov  %o0, %o2
a013b664:  93 33 60 01  srl  %o5, 1, %o1
a013b668:  90 0b 60 01  and  %o5, 1, %o0
a013b66c:  92 0a 60 01  and  %o1, 1, %o1
a013b670:  96 10 20 ff  mov  0xff, %o3
a013b674:  82 13 c0 00  mov  %o7, %g1
a013b678:  7f fe ee 5b  call  0xa00f6fe4
a013b67c:  9e 10 40 00  mov  %g1, %o7
a013b680:  01 00 00 00  nop
