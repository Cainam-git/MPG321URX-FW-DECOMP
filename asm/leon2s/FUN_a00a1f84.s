# leon2s FUN_a00a1f84 0xa00a1f84-0xa00a2010 (140 bytes)
a00a1f84:  92 0a 60 ff  and  %o1, 0xff, %o1
a00a1f88:  80 a2 60 05  cmp  %o1, 5
a00a1f8c:  02 80 00 0e  be  0xa00a1fc4
a00a1f90:  98 10 20 01  mov  1, %o4
a00a1f94:  80 a2 60 05  cmp  %o1, 5
a00a1f98:  34 80 00 05  bg,a   0xa00a1fac
a00a1f9c:  80 a2 60 06  cmp  %o1, 6
a00a1fa0:  80 a2 60 04  cmp  %o1, 4
a00a1fa4:  10 80 00 06  b  0xa00a1fbc
a00a1fa8:  98 10 20 00  clr  %o4
a00a1fac:  02 80 00 06  be  0xa00a1fc4
a00a1fb0:  98 10 20 02  mov  2, %o4
a00a1fb4:  80 a2 60 07  cmp  %o1, 7
a00a1fb8:  98 10 20 03  mov  3, %o4
a00a1fbc:  32 80 00 02  bne,a   0xa00a1fc4
a00a1fc0:  98 10 20 00  clr  %o4
a00a1fc4:  80 8a 20 ff  btst  0xff, %o0
a00a1fc8:  12 80 00 09  bne  0xa00a1fec
a00a1fcc:  98 0b 20 ff  and  %o4, 0xff, %o4
a00a1fd0:  1b 33 c0 51  sethi  %hi(0xcf014400), %o5
a00a1fd4:  9a 13 63 f0  or  %o5, 0x3f0, %o5	! 0xcf0147f0
a00a1fd8:  c2 03 40 00  ld  [ %o5 ], %g1
a00a1fdc:  82 08 60 fc  and  %g1, 0xfc, %g1
a00a1fe0:  82 10 40 0c  or  %g1, %o4, %g1
a00a1fe4:  c2 23 40 00  st  %g1, [ %o5 ]
a00a1fe8:  30 80 00 08  b,a   0xa00a2008
a00a1fec:  03 33 c0 51  sethi  %hi(0xcf014400), %g1
a00a1ff0:  82 10 63 f0  or  %g1, 0x3f0, %g1	! 0xcf0147f0
a00a1ff4:  da 00 40 00  ld  [ %g1 ], %o5
a00a1ff8:  9a 0b 60 cf  and  %o5, 0xcf, %o5
a00a1ffc:  99 2b 20 04  sll  %o4, 4, %o4
a00a2000:  9a 13 40 0c  or  %o5, %o4, %o5
a00a2004:  da 20 40 00  st  %o5, [ %g1 ]
a00a2008:  81 c3 e0 08  retl
a00a200c:  01 00 00 00  nop
