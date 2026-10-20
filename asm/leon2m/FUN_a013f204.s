# leon2m FUN_a013f204 0xa013f204-0xa013f224 (32 bytes)
a013f204:  90 0a 20 ff  and  %o0, 0xff, %o0
a013f208:  03 2a 00 b8  sethi  %hi(0xa802e000), %g1
a013f20c:  90 5a 20 2a  smul  %o0, 0x2a, %o0
a013f210:  82 10 62 24  or  %g1, 0x224, %g1
a013f214:  d0 10 40 08  lduh  [ %g1 + %o0 ], %o0
a013f218:  91 32 20 07  srl  %o0, 7, %o0
a013f21c:  81 c3 e0 08  retl
a013f220:  90 0a 20 01  and  %o0, 1, %o0
