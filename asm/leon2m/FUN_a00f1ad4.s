# leon2m FUN_a00f1ad4 0xa00f1ad4-0xa00f1b5c (136 bytes)
a00f1ad4:  90 0a 20 ff  and  %o0, 0xff, %o0
a00f1ad8:  80 a2 20 07  cmp  %o0, 7
a00f1adc:  08 80 00 14  bleu  0xa00f1b2c
a00f1ae0:  03 00 06 68  sethi  %hi(0x19a000), %g1
a00f1ae4:  92 0a 60 ff  and  %o1, 0xff, %o1
a00f1ae8:  94 0a a0 ff  and  %o2, 0xff, %o2
a00f1aec:  90 10 63 1c  or  %g1, 0x31c, %o0
a00f1af0:  96 10 20 00  clr  %o3
a00f1af4:  9a 10 20 00  clr  %o5
a00f1af8:  19 33 c0 00  sethi  %hi(0xcf000000), %o4
a00f1afc:  9a 03 40 0d  add  %o5, %o5, %o5
a00f1b00:  c2 12 00 0d  lduh  [ %o0 + %o5 ], %g1
a00f1b04:  82 00 40 09  add  %g1, %o1, %g1
a00f1b08:  9b 28 60 02  sll  %g1, 2, %o5
a00f1b0c:  82 13 40 0c  or  %o5, %o4, %g1
a00f1b10:  96 02 e0 01  inc  %o3
a00f1b14:  9a 0a e0 ff  and  %o3, 0xff, %o5
a00f1b18:  d4 20 40 00  st  %o2, [ %g1 ]
a00f1b1c:  80 a3 60 07  cmp  %o5, 7
a00f1b20:  28 bf ff f8  bleu,a   0xa00f1b00
a00f1b24:  9a 03 40 0d  add  %o5, %o5, %o5
a00f1b28:  30 80 00 0b  b,a   0xa00f1b54
a00f1b2c:  98 02 00 08  add  %o0, %o0, %o4
a00f1b30:  96 10 63 1c  or  %g1, 0x31c, %o3
a00f1b34:  da 12 c0 0c  lduh  [ %o3 + %o4 ], %o5
a00f1b38:  90 0a 60 ff  and  %o1, 0xff, %o0
a00f1b3c:  82 03 40 08  add  %o5, %o0, %g1
a00f1b40:  93 28 60 02  sll  %g1, 2, %o1
a00f1b44:  17 33 c0 00  sethi  %hi(0xcf000000), %o3
a00f1b48:  90 12 40 0b  or  %o1, %o3, %o0
a00f1b4c:  98 0a a0 ff  and  %o2, 0xff, %o4
a00f1b50:  d8 22 00 00  st  %o4, [ %o0 ]
a00f1b54:  81 c3 e0 08  retl
a00f1b58:  01 00 00 00  nop
