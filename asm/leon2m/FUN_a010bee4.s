# leon2m FUN_a010bee4 0xa010bee4-0xa010c194 (688 bytes)
a010bee4:  9d e3 bf 98  save  %sp, -104, %sp
a010bee8:  b0 0e 20 ff  and  %i0, 0xff, %i0
a010beec:  03 2a 00 b5  sethi  %hi(0xa802d400), %g1
a010bef0:  9a 10 00 1b  mov  %i3, %o5
a010bef4:  80 a6 20 01  cmp  %i0, 1
a010bef8:  02 80 00 06  be  0xa010bf10
a010befc:  9e 10 63 c4  or  %g1, 0x3c4, %o7
a010bf00:  37 2a 00 b5  sethi  %hi(0xa802d400), %i3
a010bf04:  80 a6 20 02  cmp  %i0, 2
a010bf08:  02 80 00 8e  be  0xa010c140
a010bf0c:  9e 16 e3 44  or  %i3, 0x344, %o7
a010bf10:  b2 0e 60 ff  and  %i1, 0xff, %i1
a010bf14:  80 a6 60 00  cmp  %i1, 0
a010bf18:  32 80 00 6d  bne,a   0xa010c0cc
a010bf1c:  f4 33 e0 1e  sth  %i2, [ %o7 + 0x1e ]
a010bf20:  f4 33 e0 1c  sth  %i2, [ %o7 + 0x1c ]
a010bf24:  d8 13 e0 10  lduh  [ %o7 + 0x10 ], %o4
a010bf28:  03 00 06 6b  sethi  %hi(0x19ac00), %g1
a010bf2c:  da 33 e0 22  sth  %o5, [ %o7 + 0x22 ]
a010bf30:  bb 2e 20 02  sll  %i0, 2, %i5
a010bf34:  80 a6 60 00  cmp  %i1, 0
a010bf38:  02 80 00 05  be  0xa010bf4c
a010bf3c:  82 10 62 d8  or  %g1, 0x2d8, %g1
a010bf40:  37 00 06 6b  sethi  %hi(0x19ac00), %i3
a010bf44:  bb 2e 20 02  sll  %i0, 2, %i5
a010bf48:  82 16 e2 cc  or  %i3, 0x2cc, %g1
a010bf4c:  c2 00 40 1d  ld  [ %g1 + %i5 ], %g1
a010bf50:  b5 2e a0 10  sll  %i2, 0x10, %i2
a010bf54:  fa 00 60 04  ld  [ %g1 + 4 ], %i5
a010bf58:  b9 36 a0 10  srl  %i2, 0x10, %i4
a010bf5c:  80 a7 00 0c  cmp  %i4, %o4
a010bf60:  08 80 00 03  bleu  0xa010bf6c
a010bf64:  b6 0f 7c 00  and  %i5, -1024, %i3
a010bf68:  b6 16 e0 14  or  %i3, 0x14, %i3
a010bf6c:  83 2b 60 10  sll  %o5, 0x10, %g1
a010bf70:  fa 13 e0 0e  lduh  [ %o7 + 0xe ], %i5
a010bf74:  b9 30 60 10  srl  %g1, 0x10, %i4
a010bf78:  80 a7 00 1d  cmp  %i4, %i5
a010bf7c:  08 80 00 03  bleu  0xa010bf88
a010bf80:  96 10 00 1d  mov  %i5, %o3
a010bf84:  b6 16 e0 20  or  %i3, 0x20, %i3
a010bf88:  3b 00 06 6b  sethi  %hi(0x19ac00), %i5
a010bf8c:  83 2e 20 02  sll  %i0, 2, %g1
a010bf90:  80 a6 60 00  cmp  %i1, 0
a010bf94:  02 80 00 05  be  0xa010bfa8
a010bf98:  ba 17 62 d8  or  %i5, 0x2d8, %i5
a010bf9c:  39 00 06 6b  sethi  %hi(0x19ac00), %i4
a010bfa0:  83 2e 20 02  sll  %i0, 2, %g1
a010bfa4:  ba 17 22 cc  or  %i4, 0x2cc, %i5
a010bfa8:  f8 07 40 01  ld  [ %i5 + %g1 ], %i4
a010bfac:  f6 27 20 04  st  %i3, [ %i4 + 4 ]
a010bfb0:  b7 2b 60 10  sll  %o5, 0x10, %i3
a010bfb4:  83 36 e0 10  srl  %i3, 0x10, %g1
a010bfb8:  b6 16 80 01  or  %i2, %g1, %i3
a010bfbc:  3b 00 06 6b  sethi  %hi(0x19ac00), %i5
a010bfc0:  83 2e 20 02  sll  %i0, 2, %g1
a010bfc4:  80 a6 60 00  cmp  %i1, 0
a010bfc8:  02 80 00 05  be  0xa010bfdc
a010bfcc:  ba 17 62 d8  or  %i5, 0x2d8, %i5
a010bfd0:  3b 00 06 6b  sethi  %hi(0x19ac00), %i5
a010bfd4:  83 2e 20 02  sll  %i0, 2, %g1
a010bfd8:  ba 17 62 cc  or  %i5, 0x2cc, %i5
a010bfdc:  f8 07 40 01  ld  [ %i5 + %g1 ], %i4
a010bfe0:  f6 27 20 18  st  %i3, [ %i4 + 0x18 ]
a010bfe4:  83 2b 60 10  sll  %o5, 0x10, %g1
a010bfe8:  b7 30 60 10  srl  %g1, 0x10, %i3
a010bfec:  39 3f ff c0  sethi  %hi(0xffff0000), %i4
a010bff0:  bb 2a e0 10  sll  %o3, 0x10, %i5
a010bff4:  ba 07 40 1c  add  %i5, %i4, %i5
a010bff8:  82 06 ff ff  add  %i3, -1, %g1
a010bffc:  81 80 00 00  mov  %g0, %y
a010c000:  01 00 00 00  nop
a010c004:  01 00 00 00  nop
a010c008:  01 00 00 00  nop
a010c00c:  b6 77 40 01  udiv  %i5, %g1, %i3
a010c010:  39 00 06 6b  sethi  %hi(0x19ac00), %i4
a010c014:  83 2e 20 02  sll  %i0, 2, %g1
a010c018:  80 a6 60 00  cmp  %i1, 0
a010c01c:  02 80 00 05  be  0xa010c030
a010c020:  ba 17 22 d8  or  %i4, 0x2d8, %i5
a010c024:  3b 00 06 6b  sethi  %hi(0x19ac00), %i5
a010c028:  83 2e 20 02  sll  %i0, 2, %g1
a010c02c:  ba 17 62 cc  or  %i5, 0x2cc, %i5
a010c030:  f8 07 40 01  ld  [ %i5 + %g1 ], %i4
a010c034:  f6 27 20 d0  st  %i3, [ %i4 + 0xd0 ]
a010c038:  f6 13 e0 0c  lduh  [ %o7 + 0xc ], %i3
a010c03c:  ba 06 ff ff  add  %i3, -1, %i5
a010c040:  c2 13 e0 16  lduh  [ %o7 + 0x16 ], %g1
a010c044:  b9 2f 60 10  sll  %i5, 0x10, %i4
a010c048:  b6 00 7f ff  add  %g1, -1, %i3
a010c04c:  81 80 00 00  mov  %g0, %y
a010c050:  01 00 00 00  nop
a010c054:  01 00 00 00  nop
a010c058:  01 00 00 00  nop
a010c05c:  9e 77 00 1b  udiv  %i4, %i3, %o7
a010c060:  80 a6 60 00  cmp  %i1, 0
a010c064:  12 80 00 1c  bne  0xa010c0d4
a010c068:  39 00 06 6b  sethi  %hi(0x19ac00), %i4
a010c06c:  39 00 06 6b  sethi  %hi(0x19ac00), %i4
a010c070:  82 17 22 d8  or  %i4, 0x2d8, %g1	! 0x19aed8
a010c074:  b7 2e 20 02  sll  %i0, 2, %i3
a010c078:  fa 00 40 1b  ld  [ %g1 + %i3 ], %i5
a010c07c:  de 27 60 d4  st  %o7, [ %i5 + 0xd4 ]
a010c080:  03 34 00 c0  sethi  %hi(0xd0030000), %g1
a010c084:  b6 10 60 08  or  %g1, 8, %i3	! 0xd0030008
a010c088:  bb 36 a0 10  srl  %i2, 0x10, %i5
a010c08c:  f8 06 c0 00  ld  [ %i3 ], %i4
a010c090:  80 a7 40 0c  cmp  %i5, %o4
a010c094:  02 80 00 1c  be  0xa010c104
a010c098:  b5 2a e0 10  sll  %o3, 0x10, %i2
a010c09c:  80 a6 20 01  cmp  %i0, 1
a010c0a0:  02 80 00 26  be  0xa010c138
a010c0a4:  03 00 04 00  sethi  %hi(0x100000), %g1
a010c0a8:  04 80 00 2b  ble  0xa010c154
a010c0ac:  80 a6 20 02  cmp  %i0, 2
a010c0b0:  02 80 00 27  be  0xa010c14c
a010c0b4:  03 00 40 00  sethi  %hi(0x1000000), %g1
a010c0b8:  80 a6 60 00  cmp  %i1, 0
a010c0bc:  02 80 00 32  be  0xa010c184
a010c0c0:  03 34 00 c0  sethi  %hi(0xd0030000), %g1
a010c0c4:  10 80 00 30  b  0xa010c184
a010c0c8:  03 34 00 e0  sethi  %hi(0xd0038000), %g1
a010c0cc:  10 bf ff 97  b  0xa010bf28
a010c0d0:  d8 13 e0 12  lduh  [ %o7 + 0x12 ], %o4
a010c0d4:  82 17 22 cc  or  %i4, 0x2cc, %g1
a010c0d8:  b7 2e 20 02  sll  %i0, 2, %i3
a010c0dc:  fa 00 40 1b  ld  [ %g1 + %i3 ], %i5
a010c0e0:  de 27 60 d4  st  %o7, [ %i5 + 0xd4 ]
a010c0e4:  03 34 00 e0  sethi  %hi(0xd0038000), %g1
a010c0e8:  b6 10 60 08  or  %g1, 8, %i3	! 0xd0038008
a010c0ec:  bb 36 a0 10  srl  %i2, 0x10, %i5
a010c0f0:  f8 06 c0 00  ld  [ %i3 ], %i4
a010c0f4:  80 a7 40 0c  cmp  %i5, %o4
a010c0f8:  12 bf ff ea  bne  0xa010c0a0
a010c0fc:  80 a6 20 01  cmp  %i0, 1
a010c100:  b5 2a e0 10  sll  %o3, 0x10, %i2
a010c104:  83 2b 60 10  sll  %o5, 0x10, %g1
a010c108:  80 a0 40 1a  cmp  %g1, %i2
a010c10c:  12 bf ff e5  bne  0xa010c0a0
a010c110:  80 a6 20 01  cmp  %i0, 1
a010c114:  22 80 00 1a  be,a   0xa010c17c
a010c118:  03 00 04 00  sethi  %hi(0x100000), %g1
a010c11c:  04 80 00 13  ble  0xa010c168
a010c120:  80 a6 20 02  cmp  %i0, 2
a010c124:  12 bf ff e6  bne  0xa010c0bc
a010c128:  80 a6 60 00  cmp  %i1, 0
a010c12c:  03 00 40 00  sethi  %hi(0x1000000), %g1
a010c130:  10 bf ff e3  b  0xa010c0bc
a010c134:  b8 17 00 01  or  %i4, %g1, %i4
a010c138:  10 bf ff e0  b  0xa010c0b8
a010c13c:  b8 2f 00 01  andn  %i4, %g1, %i4
a010c140:  39 2a 00 b5  sethi  %hi(0xa802d400), %i4
a010c144:  10 bf ff 73  b  0xa010bf10
a010c148:  9e 17 23 84  or  %i4, 0x384, %o7	! 0xa802d784
a010c14c:  10 bf ff db  b  0xa010c0b8
a010c150:  b8 2f 00 01  andn  %i4, %g1, %i4
a010c154:  80 a6 20 00  cmp  %i0, 0
a010c158:  12 bf ff d8  bne  0xa010c0b8
a010c15c:  03 00 00 40  sethi  %hi(0x10000), %g1
a010c160:  10 bf ff d6  b  0xa010c0b8
a010c164:  b8 2f 00 01  andn  %i4, %g1, %i4
a010c168:  80 a6 20 00  cmp  %i0, 0
a010c16c:  12 bf ff d3  bne  0xa010c0b8
a010c170:  03 00 00 40  sethi  %hi(0x10000), %g1
a010c174:  10 bf ff d1  b  0xa010c0b8
a010c178:  b8 17 00 01  or  %i4, %g1, %i4
a010c17c:  10 bf ff cf  b  0xa010c0b8
a010c180:  b8 17 00 01  or  %i4, %g1, %i4
a010c184:  b0 10 60 08  or  %g1, 8, %i0
a010c188:  f8 26 00 00  st  %i4, [ %i0 ]
a010c18c:  81 c7 e0 08  ret
a010c190:  81 e8 00 00  restore
