# leon2m FUN_a0080bd8 0xa0080bd8-0xa0080c10 (56 bytes)
a0080bd8:  19 2a 00 ab  sethi  %hi(0xa802ac00), %o4
a0080bdc:  90 0a 20 ff  and  %o0, 0xff, %o0
a0080be0:  80 a2 20 01  cmp  %o0, 1
a0080be4:  02 80 00 06  be  0xa0080bfc
a0080be8:  9a 10 00 0c  mov  %o4, %o5
a0080bec:  d0 0b 23 41  ldub  [ %o4 + 0x341 ], %o0
a0080bf0:  98 0a 3f f7  and  %o0, -9, %o4
a0080bf4:  10 80 00 05  b  0xa0080c08
a0080bf8:  d8 2b 63 41  stb  %o4, [ %o5 + 0x341 ]
a0080bfc:  da 0b 23 41  ldub  [ %o4 + 0x341 ], %o5
a0080c00:  82 13 60 08  or  %o5, 8, %g1
a0080c04:  c2 2b 23 41  stb  %g1, [ %o4 + 0x341 ]
a0080c08:  81 c3 e0 08  retl
a0080c0c:  01 00 00 00  nop
