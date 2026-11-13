# leon2m FUN_a014e9d8 0xa014e9d8-0xa014ea54 (124 bytes)
a014e9d8:  9d e3 bf 98  save  %sp, -104, %sp
a014e9dc:  1f 2a 00 b3  sethi  %hi(0xa802cc00), %o7
a014e9e0:  b0 0e 20 ff  and  %i0, 0xff, %i0
a014e9e4:  b4 10 20 00  clr  %i2
a014e9e8:  b8 10 20 00  clr  %i4
a014e9ec:  f2 13 e0 82  lduh  [ %o7 + 0x82 ], %i1
a014e9f0:  83 2e 60 10  sll  %i1, 0x10, %g1
a014e9f4:  b7 2f 20 02  sll  %i4, 2, %i3
a014e9f8:  bb 30 60 10  srl  %g1, 0x10, %i5
a014e9fc:  83 3f 40 1b  sra  %i5, %i3, %g1
a014ea00:  b4 06 a0 01  inc  %i2
a014ea04:  82 08 60 0f  and  %g1, 0xf, %g1
a014ea08:  80 a0 40 18  cmp  %g1, %i0
a014ea0c:  02 80 00 07  be  0xa014ea28
a014ea10:  b8 0e a0 ff  and  %i2, 0xff, %i4
a014ea14:  80 a7 20 03  cmp  %i4, 3
a014ea18:  08 bf ff f7  bleu  0xa014e9f4
a014ea1c:  83 2e 60 10  sll  %i1, 0x10, %g1
a014ea20:  10 80 00 0b  b  0xa014ea4c
a014ea24:  f2 33 e0 82  sth  %i1, [ %o7 + 0x82 ]
a014ea28:  82 10 20 10  mov  0x10, %g1
a014ea2c:  b4 20 40 1b  sub  %g1, %i3, %i2
a014ea30:  b8 06 e0 04  add  %i3, 4, %i4
a014ea34:  b1 3f 40 1c  sra  %i5, %i4, %i0
a014ea38:  b3 2f 40 1a  sll  %i5, %i2, %i1
a014ea3c:  bb 3e 40 1a  sra  %i1, %i2, %i5
a014ea40:  b9 2e 00 1b  sll  %i0, %i3, %i4
a014ea44:  b2 17 40 1c  or  %i5, %i4, %i1
a014ea48:  f2 33 e0 82  sth  %i1, [ %o7 + 0x82 ]
a014ea4c:  81 c7 e0 08  ret
a014ea50:  81 e8 00 00  restore
