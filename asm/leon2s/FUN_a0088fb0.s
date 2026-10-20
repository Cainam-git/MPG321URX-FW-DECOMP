# leon2s FUN_a0088fb0 0xa0088fb0-0xa0088fd4 (36 bytes)
a0088fb0:  90 0a 20 ff  and  %o0, 0xff, %o0
a0088fb4:  1b 2a 01 e2  sethi  %hi(0xa8078800), %o5
a0088fb8:  90 02 00 08  add  %o0, %o0, %o0
a0088fbc:  9a 13 62 00  or  %o5, 0x200, %o5
a0088fc0:  c2 13 40 08  lduh  [ %o5 + %o0 ], %g1
a0088fc4:  83 28 60 10  sll  %g1, 0x10, %g1
a0088fc8:  c0 33 40 08  clrh  [ %o5 + %o0 ]
a0088fcc:  81 c3 e0 08  retl
a0088fd0:  91 30 60 10  srl  %g1, 0x10, %o0
