# leon2s FUN_a00866b8 0xa00866b8-0xa00866e0 (40 bytes)
a00866b8:  90 0a 20 ff  and  %o0, 0xff, %o0
a00866bc:  9a 02 00 08  add  %o0, %o0, %o5
a00866c0:  9a 03 40 08  add  %o5, %o0, %o5
a00866c4:  19 2a 01 f3  sethi  %hi(0xa807cc00), %o4
a00866c8:  98 13 21 2e  or  %o4, 0x12e, %o4	! 0xa807cd2e
a00866cc:  9a 03 40 0d  add  %o5, %o5, %o5
a00866d0:  c2 0b 00 0d  ldub  [ %o4 + %o5 ], %g1
a00866d4:  82 08 60 7f  and  %g1, 0x7f, %g1
a00866d8:  81 c3 e0 08  retl
a00866dc:  c2 2b 00 0d  stb  %g1, [ %o4 + %o5 ]
