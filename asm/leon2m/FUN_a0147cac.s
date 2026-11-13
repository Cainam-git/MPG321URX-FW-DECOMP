# leon2m FUN_a0147cac 0xa0147cac-0xa0147d0c (96 bytes)
a0147cac:  96 10 20 00  clr  %o3
a0147cb0:  98 10 20 00  clr  %o4
a0147cb4:  10 80 00 06  b  0xa0147ccc
a0147cb8:  9a 10 20 00  clr  %o5
a0147cbc:  9a 0b 20 ff  and  %o4, 0xff, %o5
a0147cc0:  80 a3 60 2c  cmp  %o5, 0x2c
a0147cc4:  18 80 00 10  bgu  0xa0147d04
a0147cc8:  01 00 00 00  nop
a0147ccc:  c2 0b 40 08  ldub  [ %o5 + %o0 ], %g1
a0147cd0:  80 a0 60 00  cmp  %g1, 0
a0147cd4:  02 80 00 0b  be  0xa0147d00
a0147cd8:  80 a3 60 2c  cmp  %o5, 0x2c
a0147cdc:  32 bf ff f8  bne,a   0xa0147cbc
a0147ce0:  98 03 20 01  inc  %o4
a0147ce4:  96 10 00 0c  mov  %o4, %o3
a0147ce8:  98 03 20 01  inc  %o4
a0147cec:  9a 0b 20 ff  and  %o4, 0xff, %o5
a0147cf0:  80 a3 60 2c  cmp  %o5, 0x2c
a0147cf4:  28 bf ff f7  bleu,a   0xa0147cd0
a0147cf8:  c2 0b 40 08  ldub  [ %o5 + %o0 ], %g1
a0147cfc:  30 80 00 02  b,a   0xa0147d04
a0147d00:  96 10 00 0c  mov  %o4, %o3
a0147d04:  81 c3 e0 08  retl
a0147d08:  90 0a e0 ff  and  %o3, 0xff, %o0
