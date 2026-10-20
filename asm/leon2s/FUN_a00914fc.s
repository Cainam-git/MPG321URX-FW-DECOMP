# leon2s FUN_a00914fc 0xa00914fc-0xa0091520 (36 bytes)
a00914fc:  03 33 c0 f2  sethi  %hi(0xcf03c800), %g1
a0091500:  82 10 60 90  or  %g1, 0x90, %g1	! 0xcf03c890
a0091504:  9a 10 20 01  mov  1, %o5
a0091508:  d8 00 40 00  ld  [ %g1 ], %o4
a009150c:  9b 2b 40 08  sll  %o5, %o0, %o5
a0091510:  9a 2b 00 0d  andn  %o4, %o5, %o5
a0091514:  da 20 40 00  st  %o5, [ %g1 ]
a0091518:  81 c3 e0 08  retl
a009151c:  01 00 00 00  nop
