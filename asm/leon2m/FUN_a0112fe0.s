# leon2m FUN_a0112fe0 0xa0112fe0-0xa0113020 (64 bytes)
a0112fe0:  82 10 20 01  mov  1, %g1	! 0x1
a0112fe4:  15 33 c0 46  sethi  %hi(0xcf011800), %o2
a0112fe8:  99 28 40 08  sll  %g1, %o0, %o4
a0112fec:  96 10 00 0a  mov  %o2, %o3
a0112ff0:  80 8a 60 ff  btst  0xff, %o1
a0112ff4:  02 80 00 06  be  0xa011300c
a0112ff8:  9a 10 00 0c  mov  %o4, %o5
a0112ffc:  d2 02 80 00  ld  [ %o2 ], %o1
a0113000:  90 12 40 0c  or  %o1, %o4, %o0
a0113004:  d0 22 80 00  st  %o0, [ %o2 ]
a0113008:  30 80 00 04  b,a   0xa0113018
a011300c:  d8 02 80 00  ld  [ %o2 ], %o4
a0113010:  94 2b 00 0d  andn  %o4, %o5, %o2
a0113014:  d4 22 c0 00  st  %o2, [ %o3 ]
a0113018:  81 c3 e0 08  retl
a011301c:  01 00 00 00  nop
