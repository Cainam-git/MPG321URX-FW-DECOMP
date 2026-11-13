# leon2m FUN_a0109ad0 0xa0109ad0-0xa0109b14 (68 bytes)
a0109ad0:  17 33 c0 47  sethi  %hi(0xcf011c00), %o3
a0109ad4:  82 10 20 01  mov  1, %g1
a0109ad8:  94 12 e1 c0  or  %o3, 0x1c0, %o2
a0109adc:  99 28 40 08  sll  %g1, %o0, %o4
a0109ae0:  96 10 00 0a  mov  %o2, %o3
a0109ae4:  80 8a 60 ff  btst  0xff, %o1
a0109ae8:  02 80 00 06  be  0xa0109b00
a0109aec:  9a 10 00 0c  mov  %o4, %o5
a0109af0:  d2 02 80 00  ld  [ %o2 ], %o1
a0109af4:  90 12 40 0c  or  %o1, %o4, %o0
a0109af8:  d0 22 80 00  st  %o0, [ %o2 ]
a0109afc:  30 80 00 04  b,a   0xa0109b0c
a0109b00:  d8 02 80 00  ld  [ %o2 ], %o4
a0109b04:  94 2b 00 0d  andn  %o4, %o5, %o2
a0109b08:  d4 22 c0 00  st  %o2, [ %o3 ]
a0109b0c:  81 c3 e0 08  retl
a0109b10:  01 00 00 00  nop
