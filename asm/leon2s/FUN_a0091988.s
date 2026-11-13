# leon2s FUN_a0091988 0xa0091988-0xa00919b0 (40 bytes)
a0091988:  90 0a 20 ff  and  %o0, 0xff, %o0
a009198c:  9b 2a 20 03  sll  %o0, 3, %o5
a0091990:  9a 23 40 08  sub  %o5, %o0, %o5
a0091994:  19 2a 01 f5  sethi  %hi(0xa807d400), %o4
a0091998:  98 13 21 80  or  %o4, 0x180, %o4	! 0xa807d580
a009199c:  9b 2b 60 02  sll  %o5, 2, %o5
a00919a0:  c2 03 00 0d  ld  [ %o4 + %o5 ], %g1
a00919a4:  82 08 7f ef  and  %g1, -17, %g1
a00919a8:  81 c3 e0 08  retl
a00919ac:  c2 23 00 0d  st  %g1, [ %o4 + %o5 ]
