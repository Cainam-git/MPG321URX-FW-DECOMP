# leon2m FUN_a0140078 0xa0140078-0xa0140098 (32 bytes)
a0140078:  90 0a 20 ff  and  %o0, 0xff, %o0
a014007c:  03 2a 00 b8  sethi  %hi(0xa802e000), %g1
a0140080:  90 5a 20 2a  smul  %o0, 0x2a, %o0
a0140084:  82 10 62 24  or  %g1, 0x224, %g1
a0140088:  d0 10 40 08  lduh  [ %g1 + %o0 ], %o0
a014008c:  91 32 20 08  srl  %o0, 8, %o0
a0140090:  81 c3 e0 08  retl
a0140094:  90 0a 20 01  and  %o0, 1, %o0
