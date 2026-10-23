# leon2s FUN_a00cf954 0xa00cf954-0xa00cf980 (44 bytes)
a00cf954:  90 0a 20 ff  and  %o0, 0xff, %o0
a00cf958:  98 02 00 08  add  %o0, %o0, %o4
a00cf95c:  98 03 00 08  add  %o4, %o0, %o4
a00cf960:  17 2a 01 e2  sethi  %hi(0xa8078800), %o3
a00cf964:  96 12 e3 b0  or  %o3, 0x3b0, %o3	! 0xa8078bb0
a00cf968:  99 2b 20 03  sll  %o4, 3, %o4
a00cf96c:  c2 02 c0 0c  ld  [ %o3 + %o4 ], %g1
a00cf970:  1b 00 00 c0  sethi  %hi(0x30000), %o5
a00cf974:  82 10 40 0d  or  %g1, %o5, %g1
a00cf978:  81 c3 e0 08  retl
a00cf97c:  c2 22 c0 0c  st  %g1, [ %o3 + %o4 ]
