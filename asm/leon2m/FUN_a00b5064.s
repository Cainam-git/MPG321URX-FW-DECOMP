# leon2m FUN_a00b5064 0xa00b5064-0xa00b5080 (28 bytes)
a00b5064:  03 2a 00 ac  sethi  %hi(0xa802b000), %g1
a00b5068:  d0 08 60 8e  ldub  [ %g1 + 0x8e ], %o0	! 0xa802b08e
a00b506c:  9a 0a 3f fb  and  %o0, -5, %o5
a00b5070:  91 32 20 02  srl  %o0, 2, %o0
a00b5074:  da 28 60 8e  stb  %o5, [ %g1 + 0x8e ]
a00b5078:  81 c3 e0 08  retl
a00b507c:  90 0a 20 01  and  %o0, 1, %o0
