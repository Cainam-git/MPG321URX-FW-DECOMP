# leon2s FUN_a0095ef8 0xa0095ef8-0xa0095f20 (40 bytes)
a0095ef8:  90 0a 20 ff  and  %o0, 0xff, %o0
a0095efc:  83 2a 20 03  sll  %o0, 3, %g1
a0095f00:  82 20 40 08  sub  %g1, %o0, %g1
a0095f04:  1b 2a 01 f5  sethi  %hi(0xa807d400), %o5
a0095f08:  83 28 60 02  sll  %g1, 2, %g1
a0095f0c:  9a 13 61 80  or  %o5, 0x180, %o5
a0095f10:  82 00 40 0d  add  %g1, %o5, %g1
a0095f14:  d0 00 60 04  ld  [ %g1 + 4 ], %o0
a0095f18:  81 c3 e0 08  retl
a0095f1c:  91 32 20 1f  srl  %o0, 0x1f, %o0
