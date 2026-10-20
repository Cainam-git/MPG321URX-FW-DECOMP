# leon2m FUN_a0141edc 0xa0141edc-0xa0141f98 (188 bytes)
a0141edc:  9d e3 bf 98  save  %sp, -104, %sp
a0141ee0:  b2 0e 60 ff  and  %i1, 0xff, %i1
a0141ee4:  80 a6 60 03  cmp  %i1, 3
a0141ee8:  18 80 00 2a  bgu  0xa0141f90
a0141eec:  1b 00 00 3c  sethi  %hi(0xf000), %o5
a0141ef0:  d8 16 00 00  lduh  [ %i0 ], %o4
a0141ef4:  91 2b 20 10  sll  %o4, 0x10, %o0
a0141ef8:  83 32 20 1c  srl  %o0, 0x1c, %g1
a0141efc:  80 a0 60 05  cmp  %g1, 5
a0141f00:  12 80 00 24  bne  0xa0141f90
a0141f04:  9a 0b 00 0d  and  %o4, %o5, %o5
a0141f08:  13 00 00 14  sethi  %hi(0x5000), %o1
a0141f0c:  90 10 00 19  mov  %i1, %o0
a0141f10:  80 a3 40 09  cmp  %o5, %o1
a0141f14:  02 80 00 04  be  0xa0141f24
a0141f18:  98 0b 39 ff  and  %o4, -1537, %o4
a0141f1c:  10 80 00 1d  b  0xa0141f90
a0141f20:  d8 36 00 00  sth  %o4, [ %i0 ]
a0141f24:  7f ff 3c 0a  call  0xa0110f4c
a0141f28:  01 00 00 00  nop
a0141f2c:  d4 16 00 00  lduh  [ %i0 ], %o2
a0141f30:  96 0a 20 01  and  %o0, 1, %o3
a0141f34:  91 2a e0 0a  sll  %o3, 0xa, %o0
a0141f38:  92 0a bb ff  and  %o2, -1025, %o1
a0141f3c:  9a 12 40 08  or  %o1, %o0, %o5
a0141f40:  da 36 00 00  sth  %o5, [ %i0 ]
a0141f44:  7f ff 3c 02  call  0xa0110f4c
a0141f48:  90 10 00 19  mov  %i1, %o0
a0141f4c:  82 0a 20 01  and  %o0, 1, %g1
a0141f50:  de 16 00 00  lduh  [ %i0 ], %o7
a0141f54:  99 28 60 09  sll  %g1, 9, %o4
a0141f58:  96 0b fd ff  and  %o7, -513, %o3
a0141f5c:  94 12 c0 0c  or  %o3, %o4, %o2
a0141f60:  90 10 00 19  mov  %i1, %o0
a0141f64:  80 8a a2 00  btst  0x200, %o2
a0141f68:  02 80 00 0a  be  0xa0141f90
a0141f6c:  d4 36 00 00  sth  %o2, [ %i0 ]
a0141f70:  7f ff 3b f9  call  0xa0110f54
a0141f74:  01 00 00 00  nop
a0141f78:  c2 16 00 00  lduh  [ %i0 ], %g1
a0141f7c:  9a 0a 20 01  and  %o0, 1, %o5
a0141f80:  9f 2b 60 08  sll  %o5, 8, %o7
a0141f84:  98 08 7e ff  and  %g1, -257, %o4
a0141f88:  b2 13 00 0f  or  %o4, %o7, %i1
a0141f8c:  f2 36 00 00  sth  %i1, [ %i0 ]
a0141f90:  81 c7 e0 08  ret
a0141f94:  81 e8 00 00  restore
