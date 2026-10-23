# leon2m FUN_a012a128 0xa012a128-0xa012a164 (60 bytes)
a012a128:  19 2a 00 b2  sethi  %hi(0xa802c800), %o4
a012a12c:  90 0a 20 ff  and  %o0, 0xff, %o0
a012a130:  91 2a 20 02  sll  %o0, 2, %o0
a012a134:  9a 13 22 5c  or  %o4, 0x25c, %o5
a012a138:  d8 03 40 08  ld  [ %o5 + %o0 ], %o4
a012a13c:  03 2a 00 b2  sethi  %hi(0xa802c800), %g1
a012a140:  9a 10 62 9c  or  %g1, 0x29c, %o5	! 0xa802ca9c
a012a144:  c2 03 40 08  ld  [ %o5 + %o0 ], %g1
a012a148:  90 20 40 0c  sub  %g1, %o4, %o0
a012a14c:  83 3a 20 1f  sra  %o0, 0x1f, %g1
a012a150:  9a 18 40 08  xor  %g1, %o0, %o5
a012a154:  98 23 40 01  sub  %o5, %g1, %o4
a012a158:  91 2b 20 10  sll  %o4, 0x10, %o0
a012a15c:  81 c3 e0 08  retl
a012a160:  91 32 20 10  srl  %o0, 0x10, %o0
