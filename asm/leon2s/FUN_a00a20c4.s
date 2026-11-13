# leon2s FUN_a00a20c4 0xa00a20c4-0xa00a2100 (60 bytes)
a00a20c4:  9a 0a 20 ff  and  %o0, 0xff, %o5
a00a20c8:  03 2a 01 f5  sethi  %hi(0xa807d400), %g1
a00a20cc:  82 10 63 e0  or  %g1, 0x3e0, %g1	! 0xa807d7e0
a00a20d0:  9a 5b 61 90  smul  %o5, 0x190, %o5
a00a20d4:  9a 03 40 01  add  %o5, %g1, %o5
a00a20d8:  c2 0b 60 19  ldub  [ %o5 + 0x19 ], %g1
a00a20dc:  d0 13 60 32  lduh  [ %o5 + 0x32 ], %o0
a00a20e0:  90 5a 00 01  smul  %o0, %g1, %o0
a00a20e4:  c2 0b 60 2e  ldub  [ %o5 + 0x2e ], %g1
a00a20e8:  91 32 20 03  srl  %o0, 3, %o0
a00a20ec:  82 00 60 01  inc  %g1
a00a20f0:  90 5a 00 01  smul  %o0, %g1, %o0
a00a20f4:  91 2a 20 10  sll  %o0, 0x10, %o0
a00a20f8:  81 c3 e0 08  retl
a00a20fc:  91 32 20 10  srl  %o0, 0x10, %o0
