# leon2s FUN_a0091be8 0xa0091be8-0xa0091c10 (40 bytes)
a0091be8:  90 0a 20 ff  and  %o0, 0xff, %o0
a0091bec:  9b 2a 20 03  sll  %o0, 3, %o5
a0091bf0:  9a 23 40 08  sub  %o5, %o0, %o5
a0091bf4:  03 2a 01 f5  sethi  %hi(0xa807d400), %g1
a0091bf8:  9b 2b 60 02  sll  %o5, 2, %o5
a0091bfc:  82 10 61 80  or  %g1, 0x180, %g1
a0091c00:  d0 00 40 0d  ld  [ %g1 + %o5 ], %o0
a0091c04:  91 32 20 06  srl  %o0, 6, %o0
a0091c08:  81 c3 e0 08  retl
a0091c0c:  90 0a 20 01  and  %o0, 1, %o0
