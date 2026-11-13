# leon2m FUN_a00b0fc0 0xa00b0fc0-0xa00b1004 (68 bytes)
a00b0fc0:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00b0fc4:  9a 12 62 90  or  %o1, 0x290, %o5	! 0xa802d290
a00b0fc8:  d8 0b 61 aa  ldub  [ %o5 + 0x1aa ], %o4
a00b0fcc:  90 10 20 01  mov  1, %o0
a00b0fd0:  82 22 00 0c  sub  %o0, %o4, %g1
a00b0fd4:  96 08 60 ff  and  %g1, 0xff, %o3
a00b0fd8:  90 10 20 00  clr  %o0
a00b0fdc:  92 10 20 01  mov  1, %o1
a00b0fe0:  80 a2 e0 01  cmp  %o3, 1
a00b0fe4:  02 80 00 04  be  0xa00b0ff4
a00b0fe8:  c2 2b 61 aa  stb  %g1, [ %o5 + 0x1aa ]
a00b0fec:  90 10 20 00  clr  %o0
a00b0ff0:  92 10 20 00  clr  %o1
a00b0ff4:  82 13 c0 00  mov  %o7, %g1
a00b0ff8:  7f ff fd c6  call  0xa00b0710
a00b0ffc:  9e 10 40 00  mov  %g1, %o7
a00b1000:  01 00 00 00  nop
