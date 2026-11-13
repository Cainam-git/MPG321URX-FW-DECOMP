# leon2s FUN_a0091c5c 0xa0091c5c-0xa0091c84 (40 bytes)
a0091c5c:  90 0a 20 ff  and  %o0, 0xff, %o0
a0091c60:  9b 2a 20 03  sll  %o0, 3, %o5
a0091c64:  9a 23 40 08  sub  %o5, %o0, %o5
a0091c68:  03 2a 01 f5  sethi  %hi(0xa807d400), %g1
a0091c6c:  9b 2b 60 02  sll  %o5, 2, %o5
a0091c70:  82 10 61 80  or  %g1, 0x180, %g1
a0091c74:  d0 00 40 0d  ld  [ %g1 + %o5 ], %o0
a0091c78:  91 32 20 1e  srl  %o0, 0x1e, %o0
a0091c7c:  81 c3 e0 08  retl
a0091c80:  90 0a 20 01  and  %o0, 1, %o0
