# leon2m FUN_a00b5030 0xa00b5030-0xa00b5048 (24 bytes)
a00b5030:  03 2a 00 ac  sethi  %hi(0xa802b000), %g1
a00b5034:  d0 08 60 8e  ldub  [ %g1 + 0x8e ], %o0	! 0xa802b08e
a00b5038:  9a 0a 3f fe  and  %o0, -2, %o5
a00b503c:  da 28 60 8e  stb  %o5, [ %g1 + 0x8e ]
a00b5040:  81 c3 e0 08  retl
a00b5044:  90 0a 20 01  and  %o0, 1, %o0
