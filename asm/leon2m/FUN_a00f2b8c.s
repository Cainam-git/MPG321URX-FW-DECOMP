# leon2m FUN_a00f2b8c 0xa00f2b8c-0xa00f2c20 (148 bytes)
a00f2b8c:  90 0a 20 ff  and  %o0, 0xff, %o0
a00f2b90:  80 a2 20 08  cmp  %o0, 8
a00f2b94:  02 80 00 0f  be  0xa00f2bd0
a00f2b98:  80 a2 20 03  cmp  %o0, 3
a00f2b9c:  18 80 00 1f  bgu  0xa00f2c18
a00f2ba0:  03 00 06 68  sethi  %hi(0x19a000), %g1
a00f2ba4:  98 02 00 08  add  %o0, %o0, %o4
a00f2ba8:  96 10 62 e4  or  %g1, 0x2e4, %o3
a00f2bac:  da 12 c0 0c  lduh  [ %o3 + %o4 ], %o5
a00f2bb0:  90 0a 60 ff  and  %o1, 0xff, %o0
a00f2bb4:  82 03 40 08  add  %o5, %o0, %g1
a00f2bb8:  93 28 60 02  sll  %g1, 2, %o1
a00f2bbc:  17 33 c0 00  sethi  %hi(0xcf000000), %o3
a00f2bc0:  90 12 40 0b  or  %o1, %o3, %o0
a00f2bc4:  98 0a a0 ff  and  %o2, 0xff, %o4
a00f2bc8:  d8 22 00 00  st  %o4, [ %o0 ]
a00f2bcc:  30 80 00 13  b,a   0xa00f2c18
a00f2bd0:  03 00 06 68  sethi  %hi(0x19a000), %g1
a00f2bd4:  92 0a 60 ff  and  %o1, 0xff, %o1
a00f2bd8:  94 0a a0 ff  and  %o2, 0xff, %o2
a00f2bdc:  90 10 62 e4  or  %g1, 0x2e4, %o0
a00f2be0:  96 10 20 00  clr  %o3
a00f2be4:  9a 10 20 00  clr  %o5
a00f2be8:  19 33 c0 00  sethi  %hi(0xcf000000), %o4
a00f2bec:  9a 03 40 0d  add  %o5, %o5, %o5
a00f2bf0:  c2 12 00 0d  lduh  [ %o0 + %o5 ], %g1
a00f2bf4:  82 00 40 09  add  %g1, %o1, %g1
a00f2bf8:  9b 28 60 02  sll  %g1, 2, %o5
a00f2bfc:  82 13 40 0c  or  %o5, %o4, %g1
a00f2c00:  96 02 e0 01  inc  %o3
a00f2c04:  9a 0a e0 ff  and  %o3, 0xff, %o5
a00f2c08:  d4 20 40 00  st  %o2, [ %g1 ]
a00f2c0c:  80 a3 60 03  cmp  %o5, 3
a00f2c10:  08 bf ff f8  bleu  0xa00f2bf0
a00f2c14:  9a 03 40 0d  add  %o5, %o5, %o5
a00f2c18:  81 c3 e0 08  retl
a00f2c1c:  01 00 00 00  nop
