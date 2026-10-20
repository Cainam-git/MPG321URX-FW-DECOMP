# leon2s FUN_a00a1b80 0xa00a1b80-0xa00a1bb0 (48 bytes)
a00a1b80:  90 0a 20 ff  and  %o0, 0xff, %o0
a00a1b84:  03 2a 01 f6  sethi  %hi(0xa807d800), %g1
a00a1b88:  82 10 63 00  or  %g1, 0x300, %g1	! 0xa807db00
a00a1b8c:  90 5a 20 34  smul  %o0, 0x34, %o0
a00a1b90:  93 2a 60 10  sll  %o1, 0x10, %o1
a00a1b94:  90 02 00 01  add  %o0, %g1, %o0
a00a1b98:  83 32 60 10  srl  %o1, 0x10, %g1
a00a1b9c:  82 10 40 09  or  %g1, %o1, %g1
a00a1ba0:  da 02 20 30  ld  [ %o0 + 0x30 ], %o5
a00a1ba4:  c2 23 60 30  st  %g1, [ %o5 + 0x30 ]
a00a1ba8:  81 c3 e0 08  retl
a00a1bac:  01 00 00 00  nop
