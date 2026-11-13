# leon2m FUN_a002c22c 0xa002c22c-0xa002c250 (36 bytes)
a002c22c:  03 33 c0 f2  sethi  %hi(0xcf03c800), %g1
a002c230:  82 10 60 94  or  %g1, 0x94, %g1	! 0xcf03c894
a002c234:  9a 10 20 01  mov  1, %o5
a002c238:  d8 00 40 00  ld  [ %g1 ], %o4
a002c23c:  9b 2b 40 08  sll  %o5, %o0, %o5
a002c240:  9a 2b 00 0d  andn  %o4, %o5, %o5
a002c244:  da 20 40 00  st  %o5, [ %g1 ]
a002c248:  81 c3 e0 08  retl
a002c24c:  01 00 00 00  nop
