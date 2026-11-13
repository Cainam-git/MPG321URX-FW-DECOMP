# leon2s FUN_a0091094 0xa0091094-0xa00910d0 (60 bytes)
a0091094:  9a 0a 20 ff  and  %o0, 0xff, %o5
a0091098:  03 2a 01 f4  sethi  %hi(0xa807d000), %g1
a009109c:  82 10 63 e4  or  %g1, 0x3e4, %g1	! 0xa807d3e4
a00910a0:  9a 5b 60 b0  smul  %o5, 0xb0, %o5
a00910a4:  9a 03 40 01  add  %o5, %g1, %o5
a00910a8:  c2 13 60 98  lduh  [ %o5 + 0x98 ], %g1
a00910ac:  d0 13 60 96  lduh  [ %o5 + 0x96 ], %o0
a00910b0:  90 22 00 01  sub  %o0, %g1, %o0
a00910b4:  c2 13 60 9c  lduh  [ %o5 + 0x9c ], %g1
a00910b8:  90 22 00 01  sub  %o0, %g1, %o0
a00910bc:  c2 13 60 9a  lduh  [ %o5 + 0x9a ], %g1
a00910c0:  90 22 00 01  sub  %o0, %g1, %o0
a00910c4:  91 2a 20 10  sll  %o0, 0x10, %o0
a00910c8:  81 c3 e0 08  retl
a00910cc:  91 32 20 10  srl  %o0, 0x10, %o0
