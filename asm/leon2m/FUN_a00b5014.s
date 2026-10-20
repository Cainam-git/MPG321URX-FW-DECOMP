# leon2m FUN_a00b5014 0xa00b5014-0xa00b5030 (28 bytes)
a00b5014:  03 2a 00 ac  sethi  %hi(0xa802b000), %g1
a00b5018:  d0 08 60 8e  ldub  [ %g1 + 0x8e ], %o0	! 0xa802b08e
a00b501c:  9a 0a 3f fd  and  %o0, -3, %o5
a00b5020:  91 32 20 01  srl  %o0, 1, %o0
a00b5024:  da 28 60 8e  stb  %o5, [ %g1 + 0x8e ]
a00b5028:  81 c3 e0 08  retl
a00b502c:  90 0a 20 01  and  %o0, 1, %o0
