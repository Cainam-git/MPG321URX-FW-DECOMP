# leon2m FUN_a00fcdd8 0xa00fcdd8-0xa00fce0c (52 bytes)
a00fcdd8:  1b 2a 00 b2  sethi  %hi(0xa802c800), %o5
a00fcddc:  96 13 61 78  or  %o5, 0x178, %o3	! 0xa802c978
a00fcde0:  d8 0b 61 78  ldub  [ %o5 + 0x178 ], %o4
a00fcde4:  d0 0a e0 01  ldub  [ %o3 + 1 ], %o0
a00fcde8:  83 2a 20 08  sll  %o0, 8, %g1
a00fcdec:  da 0a e0 02  ldub  [ %o3 + 2 ], %o5
a00fcdf0:  90 03 00 01  add  %o4, %g1, %o0
a00fcdf4:  9b 2b 60 10  sll  %o5, 0x10, %o5
a00fcdf8:  98 02 00 0d  add  %o0, %o5, %o4
a00fcdfc:  c2 0a e0 03  ldub  [ %o3 + 3 ], %g1
a00fce00:  91 28 60 18  sll  %g1, 0x18, %o0
a00fce04:  81 c3 e0 08  retl
a00fce08:  90 03 00 08  add  %o4, %o0, %o0
