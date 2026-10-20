# leon2s FUN_a00a45d8 0xa00a45d8-0xa00a4610 (56 bytes)
a00a45d8:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a00a45dc:  9a 10 62 18  or  %g1, 0x218, %o5	! 0xa8079218
a00a45e0:  80 a2 20 00  cmp  %o0, 0
a00a45e4:  12 80 00 08  bne  0xa00a4604
a00a45e8:  90 10 00 0d  mov  %o5, %o0
a00a45ec:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a00a45f0:  c2 00 63 44  ld  [ %g1 + 0x344 ], %g1	! 0xa8078744
a00a45f4:  c2 23 60 04  st  %g1, [ %o5 + 4 ]
a00a45f8:  82 13 c0 00  mov  %o7, %g1
a00a45fc:  40 00 36 e6  call  0xa00b2194
a00a4600:  9e 10 40 00  mov  %g1, %o7
a00a4604:  01 00 00 00  nop
a00a4608:  81 c3 e0 08  retl
a00a460c:  01 00 00 00  nop
