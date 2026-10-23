# leon2m FUN_a0122cd8 0xa0122cd8-0xa0122d0c (52 bytes)
a0122cd8:  9a 02 3f ff  add  %o0, -1, %o5
a0122cdc:  82 0b 60 ff  and  %o5, 0xff, %g1
a0122ce0:  80 a0 60 0f  cmp  %g1, 0xf
a0122ce4:  18 80 00 04  bgu  0xa0122cf4
a0122ce8:  9a 0a 60 ff  and  %o1, 0xff, %o5
a0122cec:  03 2a 00 b2  sethi  %hi(0xa802c800), %g1
a0122cf0:  d0 28 61 ec  stb  %o0, [ %g1 + 0x1ec ]	! 0xa802c9ec
a0122cf4:  80 a3 60 1f  cmp  %o5, 0x1f
a0122cf8:  18 80 00 03  bgu  0xa0122d04
a0122cfc:  11 2a 00 9e  sethi  %hi(0xa8027800), %o0
a0122d00:  d2 2a 23 0c  stb  %o1, [ %o0 + 0x30c ]	! 0xa8027b0c
a0122d04:  81 c3 e0 08  retl
a0122d08:  01 00 00 00  nop
