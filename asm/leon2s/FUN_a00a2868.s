# leon2s FUN_a00a2868 0xa00a2868-0xa00a28a4 (60 bytes)
a00a2868:  9a 0a 20 ff  and  %o0, 0xff, %o5
a00a286c:  03 2a 01 f5  sethi  %hi(0xa807d400), %g1
a00a2870:  82 10 63 e0  or  %g1, 0x3e0, %g1	! 0xa807d7e0
a00a2874:  9a 5b 61 90  smul  %o5, 0x190, %o5
a00a2878:  9a 03 40 01  add  %o5, %g1, %o5
a00a287c:  c2 13 60 1e  lduh  [ %o5 + 0x1e ], %g1
a00a2880:  d0 13 60 1a  lduh  [ %o5 + 0x1a ], %o0
a00a2884:  90 22 00 01  sub  %o0, %g1, %o0
a00a2888:  c2 13 60 28  lduh  [ %o5 + 0x28 ], %g1
a00a288c:  90 22 00 01  sub  %o0, %g1, %o0
a00a2890:  c2 13 60 24  lduh  [ %o5 + 0x24 ], %g1
a00a2894:  90 22 00 01  sub  %o0, %g1, %o0
a00a2898:  91 2a 20 10  sll  %o0, 0x10, %o0
a00a289c:  81 c3 e0 08  retl
a00a28a0:  91 32 20 10  srl  %o0, 0x10, %o0
