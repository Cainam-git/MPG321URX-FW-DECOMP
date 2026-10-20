# leon2m FUN_a013cda8 0xa013cda8-0xa013ce10 (104 bytes)
a013cda8:  90 0a 20 ff  and  %o0, 0xff, %o0
a013cdac:  83 2a 20 04  sll  %o0, 4, %g1
a013cdb0:  98 20 40 08  sub  %g1, %o0, %o4
a013cdb4:  1b 2a 00 b7  sethi  %hi(0xa802dc00), %o5
a013cdb8:  82 13 63 30  or  %o5, 0x330, %g1	! 0xa802df30
a013cdbc:  99 2b 20 03  sll  %o4, 3, %o4
a013cdc0:  d0 00 40 0c  ld  [ %g1 + %o4 ], %o0
a013cdc4:  9b 32 20 0c  srl  %o0, 0xc, %o5
a013cdc8:  9a 0b 60 0f  and  %o5, 0xf, %o5
a013cdcc:  80 a3 60 01  cmp  %o5, 1
a013cdd0:  02 80 00 0b  be  0xa013cdfc
a013cdd4:  90 10 20 00  clr  %o0
a013cdd8:  80 a3 60 01  cmp  %o5, 1
a013cddc:  04 80 00 0b  ble  0xa013ce08
a013cde0:  80 a3 60 02  cmp  %o5, 2
a013cde4:  02 80 00 08  be  0xa013ce04
a013cde8:  80 a3 60 03  cmp  %o5, 3
a013cdec:  12 80 00 07  bne  0xa013ce08
a013cdf0:  01 00 00 00  nop
a013cdf4:  10 80 00 05  b  0xa013ce08
a013cdf8:  90 10 20 03  mov  3, %o0	! 0x3
a013cdfc:  10 80 00 03  b  0xa013ce08
a013ce00:  90 10 20 01  mov  1, %o0
a013ce04:  90 10 20 02  mov  2, %o0
a013ce08:  81 c3 e0 08  retl
a013ce0c:  90 0a 20 03  and  %o0, 3, %o0
