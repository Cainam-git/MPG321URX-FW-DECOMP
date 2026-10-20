# leon2m FUN_a0101e24 0xa0101e24-0xa0101e68 (68 bytes)
a0101e24:  17 33 c0 44  sethi  %hi(0xcf011000), %o3
a0101e28:  82 10 20 01  mov  1, %g1
a0101e2c:  94 12 e3 60  or  %o3, 0x360, %o2
a0101e30:  99 28 40 08  sll  %g1, %o0, %o4
a0101e34:  96 10 00 0a  mov  %o2, %o3
a0101e38:  80 8a 60 ff  btst  0xff, %o1
a0101e3c:  02 80 00 06  be  0xa0101e54
a0101e40:  9a 10 00 0c  mov  %o4, %o5
a0101e44:  d2 02 80 00  ld  [ %o2 ], %o1
a0101e48:  90 12 40 0c  or  %o1, %o4, %o0
a0101e4c:  d0 22 80 00  st  %o0, [ %o2 ]
a0101e50:  30 80 00 04  b,a   0xa0101e60
a0101e54:  d8 02 80 00  ld  [ %o2 ], %o4
a0101e58:  94 2b 00 0d  andn  %o4, %o5, %o2
a0101e5c:  d4 22 c0 00  st  %o2, [ %o3 ]
a0101e60:  81 c3 e0 08  retl
a0101e64:  01 00 00 00  nop
