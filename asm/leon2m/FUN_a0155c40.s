# leon2m FUN_a0155c40 0xa0155c40-0xa0155cec (172 bytes)
a0155c40:  9d e3 bf 88  save  %sp, -120, %sp
a0155c44:  9b 36 20 1f  srl  %i0, 0x1f, %o5
a0155c48:  80 a6 20 00  cmp  %i0, 0
a0155c4c:  12 80 00 07  bne  0xa0155c68
a0155c50:  da 27 bf ec  st  %o5, [ %fp + -20 ]
a0155c54:  82 10 20 02  mov  2, %g1
a0155c58:  c2 27 bf e8  st  %g1, [ %fp + -24 ]
a0155c5c:  40 00 04 64  call  0xa0156dec
a0155c60:  90 07 bf e8  add  %fp, -24, %o0
a0155c64:  30 80 00 20  b,a   0xa0155ce4
a0155c68:  82 10 20 03  mov  3, %g1
a0155c6c:  c2 27 bf e8  st  %g1, [ %fp + -24 ]
a0155c70:  98 10 00 18  mov  %i0, %o4
a0155c74:  80 a3 60 00  cmp  %o5, 0
a0155c78:  96 10 20 1e  mov  0x1e, %o3
a0155c7c:  92 10 20 1e  mov  0x1e, %o1
a0155c80:  12 80 00 12  bne  0xa0155cc8
a0155c84:  82 10 00 18  mov  %i0, %g1
a0155c88:  9a 10 00 01  mov  %g1, %o5
a0155c8c:  03 0f ff ff  sethi  %hi(0x3ffffc00), %g1
a0155c90:  82 10 63 ff  or  %g1, 0x3ff, %g1	! 0x3fffffff
a0155c94:  80 a3 40 01  cmp  %o5, %g1
a0155c98:  18 80 00 09  bgu  0xa0155cbc
a0155c9c:  94 10 00 01  mov  %g1, %o2
a0155ca0:  82 02 ff ff  add  %o3, -1, %g1
a0155ca4:  98 03 40 0d  add  %o5, %o5, %o4
a0155ca8:  96 10 00 01  mov  %g1, %o3
a0155cac:  80 a3 00 0a  cmp  %o4, %o2
a0155cb0:  92 10 00 01  mov  %g1, %o1
a0155cb4:  08 bf ff fb  bleu  0xa0155ca0
a0155cb8:  9a 10 00 0c  mov  %o4, %o5
a0155cbc:  d8 27 bf f4  st  %o4, [ %fp + -12 ]
a0155cc0:  10 bf ff e7  b  0xa0155c5c
a0155cc4:  d2 27 bf f0  st  %o1, [ %fp + -16 ]
a0155cc8:  03 20 00 00  sethi  %hi(0x80000000), %g1
a0155ccc:  98 20 00 18  neg  %i0, %o4
a0155cd0:  80 a6 00 01  cmp  %i0, %g1
a0155cd4:  12 bf ff ed  bne  0xa0155c88
a0155cd8:  82 10 00 0c  mov  %o4, %g1
a0155cdc:  d2 27 bf f0  st  %o1, [ %fp + -16 ]
a0155ce0:  11 33 c0 00  sethi  %hi(0xcf000000), %o0
a0155ce4:  81 c7 e0 08  ret
a0155ce8:  91 e8 00 08  restore  %g0, %o0, %o0
