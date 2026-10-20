# leon2s FUN_a009fe98 0xa009fe98-0xa009fecc (52 bytes)
a009fe98:  90 0a 20 ff  and  %o0, 0xff, %o0
a009fe9c:  03 2a 01 f6  sethi  %hi(0xa807d800), %g1
a009fea0:  82 10 63 00  or  %g1, 0x300, %g1	! 0xa807db00
a009fea4:  9a 5a 20 34  smul  %o0, 0x34, %o5
a009fea8:  da 00 40 0d  ld  [ %g1 + %o5 ], %o5
a009feac:  c2 03 60 84  ld  [ %o5 + 0x84 ], %g1
a009feb0:  82 10 60 71  or  %g1, 0x71, %g1
a009feb4:  13 00 00 3a  sethi  %hi(0xe800), %o1
a009feb8:  c2 23 60 84  st  %g1, [ %o5 + 0x84 ]
a009febc:  92 12 62 8a  or  %o1, 0x28a, %o1
a009fec0:  82 13 c0 00  mov  %o7, %g1
a009fec4:  7f ff ff da  call  0xa009fe2c
a009fec8:  9e 10 40 00  mov  %g1, %o7
