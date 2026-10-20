# leon2m FUN_a0124da4 0xa0124da4-0xa0124df8 (84 bytes)
a0124da4:  90 0a 20 ff  and  %o0, 0xff, %o0
a0124da8:  13 00 06 90  sethi  %hi(0x1a4000), %o1
a0124dac:  9a 5a 20 16  smul  %o0, 0x16, %o5
a0124db0:  82 12 62 a8  or  %o1, 0x2a8, %g1
a0124db4:  80 a2 20 07  cmp  %o0, 7
a0124db8:  18 80 00 0d  bgu  0xa0124dec
a0124dbc:  9a 03 40 01  add  %o5, %g1, %o5
a0124dc0:  d4 0b 60 0e  ldub  [ %o5 + 0xe ], %o2
a0124dc4:  80 a2 a0 ff  cmp  %o2, 0xff
a0124dc8:  02 80 00 09  be  0xa0124dec
a0124dcc:  90 10 00 0a  mov  %o2, %o0
a0124dd0:  d2 0b 60 10  ldub  [ %o5 + 0x10 ], %o1
a0124dd4:  82 38 00 09  xnor  %g0, %o1, %g1
a0124dd8:  94 08 60 ff  and  %g1, 0xff, %o2
a0124ddc:  d2 0b 60 0f  ldub  [ %o5 + 0xf ], %o1
a0124de0:  82 13 c0 00  mov  %o7, %g1
a0124de4:  67 fd 9e a2  call  0x4008c86c
a0124de8:  9e 10 40 00  mov  %g1, %o7
a0124dec:  01 00 00 00  nop
a0124df0:  81 c3 e0 08  retl
a0124df4:  01 00 00 00  nop
