# leon2s FUN_a0091c38 0xa0091c38-0xa0091c5c (36 bytes)
a0091c38:  90 0a 20 ff  and  %o0, 0xff, %o0
a0091c3c:  83 2a 20 03  sll  %o0, 3, %g1
a0091c40:  82 20 40 08  sub  %g1, %o0, %g1
a0091c44:  1b 2a 01 f5  sethi  %hi(0xa807d400), %o5
a0091c48:  83 28 60 02  sll  %g1, 2, %g1
a0091c4c:  9a 13 61 80  or  %o5, 0x180, %o5
a0091c50:  82 00 40 0d  add  %g1, %o5, %g1
a0091c54:  81 c3 e0 08  retl
a0091c58:  d0 08 60 01  ldub  [ %g1 + 1 ], %o0
