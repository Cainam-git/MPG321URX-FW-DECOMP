# leon2m FUN_a013f1e4 0xa013f1e4-0xa013f204 (32 bytes)
a013f1e4:  90 0a 20 ff  and  %o0, 0xff, %o0
a013f1e8:  03 2a 00 b8  sethi  %hi(0xa802e000), %g1
a013f1ec:  90 5a 20 2a  smul  %o0, 0x2a, %o0
a013f1f0:  82 10 62 24  or  %g1, 0x224, %g1
a013f1f4:  d0 10 40 08  lduh  [ %g1 + %o0 ], %o0
a013f1f8:  91 32 20 0a  srl  %o0, 0xa, %o0
a013f1fc:  81 c3 e0 08  retl
a013f200:  90 0a 20 01  and  %o0, 1, %o0
