# leon2s FUN_a00a2a04 0xa00a2a04-0xa00a2a28 (36 bytes)
a00a2a04:  03 33 c0 f2  sethi  %hi(0xcf03c800), %g1
a00a2a08:  82 10 60 90  or  %g1, 0x90, %g1	! 0xcf03c890
a00a2a0c:  9a 10 20 04  mov  4, %o5
a00a2a10:  d8 00 40 00  ld  [ %g1 ], %o4
a00a2a14:  9b 2b 40 08  sll  %o5, %o0, %o5
a00a2a18:  9a 2b 00 0d  andn  %o4, %o5, %o5
a00a2a1c:  da 20 40 00  st  %o5, [ %g1 ]
a00a2a20:  81 c3 e0 08  retl
a00a2a24:  01 00 00 00  nop
