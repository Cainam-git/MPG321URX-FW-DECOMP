# leon2m FUN_a0155cec 0xa0155cec-0xa0155d90 (164 bytes)
a0155cec:  9d e3 bf 80  save  %sp, -128, %sp
a0155cf0:  f0 27 bf e4  st  %i0, [ %fp + -28 ]
a0155cf4:  90 07 bf e4  add  %fp, -28, %o0
a0155cf8:  40 00 04 8f  call  0xa0156f34
a0155cfc:  92 07 bf e8  add  %fp, -24, %o1
a0155d00:  d8 07 bf e8  ld  [ %fp + -24 ], %o4
a0155d04:  80 a3 20 02  cmp  %o4, 2
a0155d08:  02 80 00 20  be  0xa0155d88
a0155d0c:  b0 10 20 00  clr  %i0
a0155d10:  80 a3 20 01  cmp  %o4, 1
a0155d14:  08 80 00 1d  bleu  0xa0155d88
a0155d18:  80 a3 20 04  cmp  %o4, 4
a0155d1c:  02 80 00 11  be  0xa0155d60
a0155d20:  c2 07 bf ec  ld  [ %fp + -20 ], %g1
a0155d24:  da 07 bf f0  ld  [ %fp + -16 ], %o5
a0155d28:  80 a3 60 00  cmp  %o5, 0
a0155d2c:  06 80 00 17  bl  0xa0155d88
a0155d30:  80 a3 60 1e  cmp  %o5, 0x1e
a0155d34:  14 80 00 11  bg  0xa0155d78
a0155d38:  80 a0 60 00  cmp  %g1, 0
a0155d3c:  82 10 20 1e  mov  0x1e, %g1
a0155d40:  82 20 40 0d  sub  %g1, %o5, %g1
a0155d44:  da 07 bf f4  ld  [ %fp + -12 ], %o5
a0155d48:  d8 07 bf ec  ld  [ %fp + -20 ], %o4
a0155d4c:  80 a3 20 00  cmp  %o4, 0
a0155d50:  02 80 00 0e  be  0xa0155d88
a0155d54:  b1 33 40 01  srl  %o5, %g1, %i0
a0155d58:  10 80 00 0c  b  0xa0155d88
a0155d5c:  b0 20 00 18  neg  %i0
a0155d60:  80 a0 60 00  cmp  %g1, 0
a0155d64:  12 80 00 09  bne  0xa0155d88
a0155d68:  31 20 00 00  sethi  %hi(0x80000000), %i0
a0155d6c:  03 1f ff ff  sethi  %hi(0x7ffffc00), %g1
a0155d70:  10 80 00 06  b  0xa0155d88
a0155d74:  b0 10 63 ff  or  %g1, 0x3ff, %i0	! 0x7fffffff
a0155d78:  12 80 00 04  bne  0xa0155d88
a0155d7c:  31 20 00 00  sethi  %hi(0x80000000), %i0
a0155d80:  03 1f ff ff  sethi  %hi(0x7ffffc00), %g1
a0155d84:  b0 10 63 ff  or  %g1, 0x3ff, %i0	! 0x7fffffff
a0155d88:  81 c7 e0 08  ret
a0155d8c:  81 e8 00 00  restore
