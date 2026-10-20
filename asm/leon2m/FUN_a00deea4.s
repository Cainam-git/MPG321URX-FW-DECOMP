# leon2m FUN_a00deea4 0xa00deea4-0xa00deef0 (76 bytes)
a00deea4:  17 2a 00 ac  sethi  %hi(0xa802b000), %o3
a00deea8:  98 12 e0 ec  or  %o3, 0xec, %o4	! 0xa802b0ec
a00deeac:  da 0b 20 81  ldub  [ %o4 + 0x81 ], %o5
a00deeb0:  c2 0b 20 80  ldub  [ %o4 + 0x80 ], %g1
a00deeb4:  96 10 00 08  mov  %o0, %o3
a00deeb8:  80 a0 40 0d  cmp  %g1, %o5
a00deebc:  02 80 00 0b  be  0xa00deee8
a00deec0:  90 10 20 00  clr  %o0
a00deec4:  d0 0b 00 0d  ldub  [ %o4 + %o5 ], %o0
a00deec8:  d0 2a c0 00  stb  %o0, [ %o3 ]
a00deecc:  da 0b 20 81  ldub  [ %o4 + 0x81 ], %o5
a00deed0:  9a 03 60 01  inc  %o5
a00deed4:  80 8b 60 80  btst  0x80, %o5
a00deed8:  32 80 00 03  bne,a   0xa00deee4
a00deedc:  c0 2b 20 81  clrb  [ %o4 + 0x81 ]
a00deee0:  da 2b 20 81  stb  %o5, [ %o4 + 0x81 ]
a00deee4:  90 10 20 01  mov  1, %o0
a00deee8:  81 c3 e0 08  retl
a00deeec:  01 00 00 00  nop
