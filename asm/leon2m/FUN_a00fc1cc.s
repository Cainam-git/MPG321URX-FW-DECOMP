# leon2m FUN_a00fc1cc 0xa00fc1cc-0xa00fc200 (52 bytes)
a00fc1cc:  1b 33 c0 45  sethi  %hi(0xcf011400), %o5
a00fc1d0:  82 13 60 80  or  %o5, 0x80, %g1	! 0xcf011480
a00fc1d4:  da 00 40 00  ld  [ %g1 ], %o5
a00fc1d8:  9a 8b 60 03  andcc  %o5, 3, %o5
a00fc1dc:  82 10 20 78  mov  0x78, %g1
a00fc1e0:  12 80 00 03  bne  0xa00fc1ec
a00fc1e4:  9b 38 40 0d  sra  %g1, %o5, %o5
a00fc1e8:  9a 10 20 78  mov  0x78, %o5
a00fc1ec:  03 33 c0 48  sethi  %hi(0xcf012000), %g1
a00fc1f0:  82 10 60 04  or  %g1, 4, %g1	! 0xcf012004
a00fc1f4:  da 20 40 00  st  %o5, [ %g1 ]
a00fc1f8:  81 c3 e0 08  retl
a00fc1fc:  01 00 00 00  nop
