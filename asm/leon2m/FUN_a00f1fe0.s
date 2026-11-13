# leon2m FUN_a00f1fe0 0xa00f1fe0-0xa00f2068 (136 bytes)
a00f1fe0:  90 0a 20 ff  and  %o0, 0xff, %o0
a00f1fe4:  80 a2 20 07  cmp  %o0, 7
a00f1fe8:  08 80 00 14  bleu  0xa00f2038
a00f1fec:  03 00 06 68  sethi  %hi(0x19a000), %g1
a00f1ff0:  92 0a 60 ff  and  %o1, 0xff, %o1
a00f1ff4:  94 0a a0 ff  and  %o2, 0xff, %o2
a00f1ff8:  90 10 62 fc  or  %g1, 0x2fc, %o0
a00f1ffc:  96 10 20 00  clr  %o3
a00f2000:  9a 10 20 00  clr  %o5
a00f2004:  19 33 c0 00  sethi  %hi(0xcf000000), %o4
a00f2008:  9a 03 40 0d  add  %o5, %o5, %o5
a00f200c:  c2 12 00 0d  lduh  [ %o0 + %o5 ], %g1
a00f2010:  82 00 40 09  add  %g1, %o1, %g1
a00f2014:  9b 28 60 02  sll  %g1, 2, %o5
a00f2018:  82 13 40 0c  or  %o5, %o4, %g1
a00f201c:  96 02 e0 01  inc  %o3
a00f2020:  9a 0a e0 ff  and  %o3, 0xff, %o5
a00f2024:  d4 20 40 00  st  %o2, [ %g1 ]
a00f2028:  80 a3 60 07  cmp  %o5, 7
a00f202c:  28 bf ff f8  bleu,a   0xa00f200c
a00f2030:  9a 03 40 0d  add  %o5, %o5, %o5
a00f2034:  30 80 00 0b  b,a   0xa00f2060
a00f2038:  98 02 00 08  add  %o0, %o0, %o4
a00f203c:  96 10 62 fc  or  %g1, 0x2fc, %o3
a00f2040:  da 12 c0 0c  lduh  [ %o3 + %o4 ], %o5
a00f2044:  90 0a 60 ff  and  %o1, 0xff, %o0
a00f2048:  82 03 40 08  add  %o5, %o0, %g1
a00f204c:  93 28 60 02  sll  %g1, 2, %o1
a00f2050:  17 33 c0 00  sethi  %hi(0xcf000000), %o3
a00f2054:  90 12 40 0b  or  %o1, %o3, %o0
a00f2058:  98 0a a0 ff  and  %o2, 0xff, %o4
a00f205c:  d8 22 00 00  st  %o4, [ %o0 ]
a00f2060:  81 c3 e0 08  retl
a00f2064:  01 00 00 00  nop
