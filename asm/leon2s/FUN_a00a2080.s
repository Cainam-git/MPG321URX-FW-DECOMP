# leon2s FUN_a00a2080 0xa00a2080-0xa00a20a8 (40 bytes)
a00a2080:  90 0a 20 ff  and  %o0, 0xff, %o0
a00a2084:  03 2a 01 f5  sethi  %hi(0xa807d400), %g1
a00a2088:  82 10 63 e0  or  %g1, 0x3e0, %g1	! 0xa807d7e0
a00a208c:  90 5a 21 90  smul  %o0, 0x190, %o0
a00a2090:  90 02 00 01  add  %o0, %g1, %o0
a00a2094:  c2 02 20 50  ld  [ %o0 + 0x50 ], %g1
a00a2098:  82 18 60 03  xor  %g1, 3, %g1
a00a209c:  80 a0 00 01  cmp  %g0, %g1
a00a20a0:  81 c3 e0 08  retl
a00a20a4:  90 60 3f ff  subx  %g0, -1, %o0
