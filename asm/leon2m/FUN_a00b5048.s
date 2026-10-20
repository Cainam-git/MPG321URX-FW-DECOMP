# leon2m FUN_a00b5048 0xa00b5048-0xa00b5064 (28 bytes)
a00b5048:  03 2a 00 ac  sethi  %hi(0xa802b000), %g1
a00b504c:  d0 08 60 8e  ldub  [ %g1 + 0x8e ], %o0	! 0xa802b08e
a00b5050:  9a 0a 3f f7  and  %o0, -9, %o5
a00b5054:  91 32 20 03  srl  %o0, 3, %o0
a00b5058:  da 28 60 8e  stb  %o5, [ %g1 + 0x8e ]
a00b505c:  81 c3 e0 08  retl
a00b5060:  90 0a 20 01  and  %o0, 1, %o0
