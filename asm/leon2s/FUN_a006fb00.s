# leon2s FUN_a006fb00 0xa006fb00-0xa006fb38 (56 bytes)
a006fb00:  15 2a 01 e2  sethi  %hi(0xa8078800), %o2
a006fb04:  da 02 a0 e0  ld  [ %o2 + 0xe0 ], %o5	! 0xa80788e0
a006fb08:  9a 13 60 01  or  %o5, 1, %o5
a006fb0c:  98 10 20 01  mov  1, %o4
a006fb10:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a006fb14:  da 22 a0 e0  st  %o5, [ %o2 + 0xe0 ]
a006fb18:  d8 28 60 e4  stb  %o4, [ %g1 + 0xe4 ]
a006fb1c:  94 12 a0 e0  or  %o2, 0xe0, %o2
a006fb20:  90 10 20 00  clr  %o0
a006fb24:  92 10 20 00  clr  %o1
a006fb28:  96 10 20 01  mov  1, %o3
a006fb2c:  82 13 c0 00  mov  %o7, %g1
a006fb30:  7f ff ff e9  call  0xa006fad4
a006fb34:  9e 10 40 00  mov  %g1, %o7
