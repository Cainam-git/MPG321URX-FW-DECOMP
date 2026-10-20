# leon2m FUN_a0124df8 0xa0124df8-0xa0124e44 (76 bytes)
a0124df8:  90 0a 20 ff  and  %o0, 0xff, %o0
a0124dfc:  13 00 06 90  sethi  %hi(0x1a4000), %o1
a0124e00:  9a 5a 20 16  smul  %o0, 0x16, %o5
a0124e04:  82 12 62 a8  or  %o1, 0x2a8, %g1
a0124e08:  80 a2 20 07  cmp  %o0, 7
a0124e0c:  18 80 00 0b  bgu  0xa0124e38
a0124e10:  9a 03 40 01  add  %o5, %g1, %o5
a0124e14:  d4 0b 60 0e  ldub  [ %o5 + 0xe ], %o2
a0124e18:  80 a2 a0 ff  cmp  %o2, 0xff
a0124e1c:  02 80 00 07  be  0xa0124e38
a0124e20:  90 10 00 0a  mov  %o2, %o0
a0124e24:  d4 0b 60 10  ldub  [ %o5 + 0x10 ], %o2
a0124e28:  d2 0b 60 0f  ldub  [ %o5 + 0xf ], %o1
a0124e2c:  82 13 c0 00  mov  %o7, %g1
a0124e30:  67 fd 9e 8f  call  0x4008c86c
a0124e34:  9e 10 40 00  mov  %g1, %o7
a0124e38:  01 00 00 00  nop
a0124e3c:  81 c3 e0 08  retl
a0124e40:  01 00 00 00  nop
