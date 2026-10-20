# leon2m FUN_a0140058 0xa0140058-0xa0140078 (32 bytes)
a0140058:  90 0a 20 ff  and  %o0, 0xff, %o0
a014005c:  03 2a 00 b8  sethi  %hi(0xa802e000), %g1
a0140060:  90 5a 20 2a  smul  %o0, 0x2a, %o0
a0140064:  82 10 62 24  or  %g1, 0x224, %g1
a0140068:  d0 10 40 08  lduh  [ %g1 + %o0 ], %o0
a014006c:  91 32 20 09  srl  %o0, 9, %o0
a0140070:  81 c3 e0 08  retl
a0140074:  90 0a 20 01  and  %o0, 1, %o0
