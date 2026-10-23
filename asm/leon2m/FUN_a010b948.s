# leon2m FUN_a010b948 0xa010b948-0xa010b96c (36 bytes)
a010b948:  11 34 00 c0  sethi  %hi(0xd0030000), %o0
a010b94c:  82 12 20 04  or  %o0, 4, %g1	! 0xd0030004
a010b950:  da 00 40 00  ld  [ %g1 ], %o5
a010b954:  80 8b 60 01  btst  1, %o5
a010b958:  02 80 00 03  be  0xa010b964
a010b95c:  90 10 20 00  clr  %o0
a010b960:  90 10 20 01  mov  1, %o0
a010b964:  81 c3 e0 08  retl
a010b968:  90 0a 20 01  and  %o0, 1, %o0
