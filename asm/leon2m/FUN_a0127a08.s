# leon2m FUN_a0127a08 0xa0127a08-0xa0127a34 (44 bytes)
a0127a08:  90 0a 20 ff  and  %o0, 0xff, %o0
a0127a0c:  80 a2 20 ff  cmp  %o0, 0xff
a0127a10:  02 80 00 05  be  0xa0127a24
a0127a14:  03 2a 00 a9  sethi  %hi(0xa802a400), %g1
a0127a18:  82 10 60 40  or  %g1, 0x40, %g1	! 0xa802a440
a0127a1c:  10 80 00 04  b  0xa0127a2c
a0127a20:  d0 08 40 08  ldub  [ %g1 + %o0 ], %o0
a0127a24:  03 2a 00 a9  sethi  %hi(0xa802a400), %g1
a0127a28:  d0 08 60 43  ldub  [ %g1 + 0x43 ], %o0	! 0xa802a443
a0127a2c:  81 c3 e0 08  retl
a0127a30:  01 00 00 00  nop
