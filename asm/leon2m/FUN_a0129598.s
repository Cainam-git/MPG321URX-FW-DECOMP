# leon2m FUN_a0129598 0xa0129598-0xa01295b8 (32 bytes)
a0129598:  03 2a 00 b6  sethi  %hi(0xa802d800), %g1
a012959c:  da 10 60 92  lduh  [ %g1 + 0x92 ], %o5	! 0xa802d892
a01295a0:  9a 0b 63 ff  and  %o5, 0x3ff, %o5
a01295a4:  da 30 60 92  sth  %o5, [ %g1 + 0x92 ]
a01295a8:  82 10 60 92  or  %g1, 0x92, %g1
a01295ac:  9a 10 3f ff  mov  -1, %o5
a01295b0:  81 c3 e0 08  retl
a01295b4:  da 28 60 01  stb  %o5, [ %g1 + 1 ]
