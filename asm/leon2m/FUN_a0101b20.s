# leon2m FUN_a0101b20 0xa0101b20-0xa0101b48 (40 bytes)
a0101b20:  1b 33 c0 58  sethi  %hi(0xcf016000), %o5
a0101b24:  9a 13 61 18  or  %o5, 0x118, %o5	! 0xcf016118
a0101b28:  c2 03 40 00  ld  [ %o5 ], %g1
a0101b2c:  90 0a 20 ff  and  %o0, 0xff, %o0
a0101b30:  82 08 60 bf  and  %g1, 0xbf, %g1
a0101b34:  91 2a 20 06  sll  %o0, 6, %o0
a0101b38:  82 10 40 08  or  %g1, %o0, %g1
a0101b3c:  c2 23 40 00  st  %g1, [ %o5 ]
a0101b40:  81 c3 e0 08  retl
a0101b44:  01 00 00 00  nop
