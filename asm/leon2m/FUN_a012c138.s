# leon2m FUN_a012c138 0xa012c138-0xa012c16c (52 bytes)
a012c138:  98 0a 20 ff  and  %o0, 0xff, %o4
a012c13c:  91 2b 20 02  sll  %o4, 2, %o0
a012c140:  19 2a 00 b2  sethi  %hi(0xa802c800), %o4
a012c144:  82 10 20 0f  mov  0xf, %g1
a012c148:  da 03 23 08  ld  [ %o4 + 0x308 ], %o5
a012c14c:  93 2a 60 10  sll  %o1, 0x10, %o1
a012c150:  83 28 40 08  sll  %g1, %o0, %g1
a012c154:  93 32 60 17  srl  %o1, 0x17, %o1
a012c158:  82 2b 40 01  andn  %o5, %g1, %g1
a012c15c:  9b 2a 40 08  sll  %o1, %o0, %o5
a012c160:  92 13 40 01  or  %o5, %g1, %o1
a012c164:  81 c3 e0 08  retl
a012c168:  d2 23 23 08  st  %o1, [ %o4 + 0x308 ]
