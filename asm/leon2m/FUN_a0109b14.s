# leon2m FUN_a0109b14 0xa0109b14-0xa0109b58 (68 bytes)
a0109b14:  17 33 c0 47  sethi  %hi(0xcf011c00), %o3
a0109b18:  82 10 20 01  mov  1, %g1
a0109b1c:  94 12 e1 c4  or  %o3, 0x1c4, %o2
a0109b20:  99 28 40 08  sll  %g1, %o0, %o4
a0109b24:  96 10 00 0a  mov  %o2, %o3
a0109b28:  80 8a 60 ff  btst  0xff, %o1
a0109b2c:  02 80 00 06  be  0xa0109b44
a0109b30:  9a 10 00 0c  mov  %o4, %o5
a0109b34:  d2 02 80 00  ld  [ %o2 ], %o1
a0109b38:  90 12 40 0c  or  %o1, %o4, %o0
a0109b3c:  d0 22 80 00  st  %o0, [ %o2 ]
a0109b40:  30 80 00 04  b,a   0xa0109b50
a0109b44:  d8 02 80 00  ld  [ %o2 ], %o4
a0109b48:  94 2b 00 0d  andn  %o4, %o5, %o2
a0109b4c:  d4 22 c0 00  st  %o2, [ %o3 ]
a0109b50:  81 c3 e0 08  retl
a0109b54:  01 00 00 00  nop
