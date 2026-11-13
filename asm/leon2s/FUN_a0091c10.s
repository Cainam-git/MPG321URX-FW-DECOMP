# leon2s FUN_a0091c10 0xa0091c10-0xa0091c38 (40 bytes)
a0091c10:  90 0a 20 ff  and  %o0, 0xff, %o0
a0091c14:  9b 2a 20 03  sll  %o0, 3, %o5
a0091c18:  9a 23 40 08  sub  %o5, %o0, %o5
a0091c1c:  03 2a 01 f5  sethi  %hi(0xa807d400), %g1
a0091c20:  9b 2b 60 02  sll  %o5, 2, %o5
a0091c24:  82 10 61 80  or  %g1, 0x180, %g1
a0091c28:  d0 00 40 0d  ld  [ %g1 + %o5 ], %o0
a0091c2c:  91 32 20 07  srl  %o0, 7, %o0
a0091c30:  81 c3 e0 08  retl
a0091c34:  90 0a 20 01  and  %o0, 1, %o0
