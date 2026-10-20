# leon2s FUN_a009fe2c 0xa009fe2c-0xa009fe60 (52 bytes)
a009fe2c:  90 0a 20 ff  and  %o0, 0xff, %o0
a009fe30:  03 2a 01 f6  sethi  %hi(0xa807d800), %g1
a009fe34:  82 10 63 00  or  %g1, 0x300, %g1	! 0xa807db00
a009fe38:  90 5a 20 34  smul  %o0, 0x34, %o0
a009fe3c:  da 00 40 08  ld  [ %g1 + %o0 ], %o5
a009fe40:  c2 03 60 84  ld  [ %o5 + 0x84 ], %g1
a009fe44:  82 10 40 09  or  %g1, %o1, %g1
a009fe48:  c2 23 60 84  st  %g1, [ %o5 + 0x84 ]
a009fe4c:  c2 03 60 84  ld  [ %o5 + 0x84 ], %g1
a009fe50:  92 28 40 09  andn  %g1, %o1, %o1
a009fe54:  d2 23 60 84  st  %o1, [ %o5 + 0x84 ]
a009fe58:  81 c3 e0 08  retl
a009fe5c:  01 00 00 00  nop
