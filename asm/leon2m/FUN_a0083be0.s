# leon2m FUN_a0083be0 0xa0083be0-0xa0083c20 (64 bytes)
a0083be0:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a0083be4:  82 10 62 90  or  %g1, 0x290, %g1	! 0xa802d290
a0083be8:  da 00 60 a8  ld  [ %g1 + 0xa8 ], %o5
a0083bec:  80 8b 68 00  btst  0x800, %o5
a0083bf0:  02 80 00 09  be  0xa0083c14
a0083bf4:  01 00 00 00  nop
a0083bf8:  da 08 61 81  ldub  [ %g1 + 0x181 ], %o5
a0083bfc:  80 a3 60 07  cmp  %o5, 7
a0083c00:  12 80 00 05  bne  0xa0083c14
a0083c04:  01 00 00 00  nop
a0083c08:  82 13 c0 00  mov  %o7, %g1
a0083c0c:  40 01 40 6c  call  0xa00d3dbc
a0083c10:  9e 10 40 00  mov  %g1, %o7
a0083c14:  01 00 00 00  nop
a0083c18:  81 c3 e0 08  retl
a0083c1c:  01 00 00 00  nop
