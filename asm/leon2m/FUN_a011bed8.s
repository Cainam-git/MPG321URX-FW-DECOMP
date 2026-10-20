# leon2m FUN_a011bed8 0xa011bed8-0xa011c050 (376 bytes)
a011bed8:  9d e3 bf 98  save  %sp, -104, %sp
a011bedc:  3b 2a 00 b2  sethi  %hi(0xa802c800), %i5
a011bee0:  9e 0f 20 ff  and  %i4, 0xff, %o7
a011bee4:  b8 03 c0 0f  add  %o7, %o7, %i4
a011bee8:  82 17 61 ca  or  %i5, 0x1ca, %g1
a011beec:  fa 10 40 1c  lduh  [ %g1 + %i4 ], %i5
a011bef0:  92 0e a0 ff  and  %i2, 0xff, %o1
a011bef4:  b2 5e 40 1d  smul  %i1, %i5, %i1
a011bef8:  b0 06 00 19  add  %i0, %i1, %i0
a011befc:  80 a2 60 00  cmp  %o1, 0
a011bf00:  9a 10 00 1b  mov  %i3, %o5
a011bf04:  02 80 00 51  be  0xa011c048
a011bf08:  b4 10 20 00  clr  %i2
a011bf0c:  33 33 c0 45  sethi  %hi(0xcf011400), %i1
a011bf10:  95 2e e0 10  sll  %i3, 0x10, %o2
a011bf14:  96 16 63 94  or  %i1, 0x394, %o3
a011bf18:  b6 16 63 80  or  %i1, 0x380, %i3
a011bf1c:  98 10 20 70  mov  0x70, %o4
a011bf20:  80 a3 e0 00  cmp  %o7, 0
a011bf24:  12 80 00 36  bne  0xa011bffc
a011bf28:  01 00 00 00  nop
a011bf2c:  d8 26 c0 00  st  %o4, [ %i3 ]
a011bf30:  82 10 20 9f  mov  0x9f, %g1
a011bf34:  01 00 00 00  nop
a011bf38:  82 80 7f ff  addcc  %g1, -1, %g1
a011bf3c:  1c bf ff fe  bpos  0xa011bf34
a011bf40:  b3 2e 20 10  sll  %i0, 0x10, %i1
a011bf44:  80 a3 e0 00  cmp  %o7, 0
a011bf48:  12 80 00 30  bne  0xa011c008
a011bf4c:  bb 36 60 10  srl  %i1, 0x10, %i5
a011bf50:  39 33 c0 45  sethi  %hi(0xcf011400), %i4
a011bf54:  82 17 23 84  or  %i4, 0x384, %g1	! 0xcf011784
a011bf58:  ba 0f 60 ff  and  %i5, 0xff, %i5
a011bf5c:  fa 20 40 00  st  %i5, [ %g1 ]
a011bf60:  83 36 60 18  srl  %i1, 0x18, %g1
a011bf64:  b8 17 23 88  or  %i4, 0x388, %i4
a011bf68:  c2 27 00 00  st  %g1, [ %i4 ]
a011bf6c:  03 33 c0 2f  sethi  %hi(0xcf00bc00), %g1
a011bf70:  b2 10 63 cc  or  %g1, 0x3cc, %i1	! 0xcf00bfcc
a011bf74:  c0 26 40 00  clr  [ %i1 ]
a011bf78:  82 10 20 9f  mov  0x9f, %g1
a011bf7c:  01 00 00 00  nop
a011bf80:  82 80 7f ff  addcc  %g1, -1, %g1
a011bf84:  1c bf ff fe  bpos  0xa011bf7c
a011bf88:  80 a3 e0 00  cmp  %o7, 0
a011bf8c:  12 80 00 28  bne  0xa011c02c
a011bf90:  03 33 c0 45  sethi  %hi(0xcf011400), %g1
a011bf94:  39 33 c0 45  sethi  %hi(0xcf011400), %i4
a011bf98:  ba 0b 60 ff  and  %o5, 0xff, %i5
a011bf9c:  82 17 23 8c  or  %i4, 0x38c, %g1
a011bfa0:  fa 20 40 00  st  %i5, [ %g1 ]
a011bfa4:  82 10 20 9f  mov  0x9f, %g1
a011bfa8:  01 00 00 00  nop
a011bfac:  82 80 7f ff  addcc  %g1, -1, %g1
a011bfb0:  1c bf ff fe  bpos  0xa011bfa8
a011bfb4:  80 a3 e0 00  cmp  %o7, 0
a011bfb8:  12 80 00 20  bne  0xa011c038
a011bfbc:  bb 32 a0 18  srl  %o2, 0x18, %i5
a011bfc0:  33 33 c0 45  sethi  %hi(0xcf011400), %i1
a011bfc4:  ba 0f 60 ff  and  %i5, 0xff, %i5
a011bfc8:  82 16 63 8c  or  %i1, 0x38c, %g1
a011bfcc:  fa 20 40 00  st  %i5, [ %g1 ]
a011bfd0:  82 10 20 9f  mov  0x9f, %g1
a011bfd4:  01 00 00 00  nop
a011bfd8:  82 80 7f ff  addcc  %g1, -1, %g1
a011bfdc:  1c bf ff fe  bpos  0xa011bfd4
a011bfe0:  01 00 00 00  nop
a011bfe4:  b4 06 a0 01  inc  %i2
a011bfe8:  ba 0e a0 ff  and  %i2, 0xff, %i5
a011bfec:  80 a7 40 09  cmp  %i5, %o1
a011bff0:  0a bf ff cc  bcs  0xa011bf20
a011bff4:  b0 06 20 01  inc  %i0
a011bff8:  30 80 00 14  b,a   0xa011c048
a011bffc:  d8 22 c0 00  st  %o4, [ %o3 ]
a011c000:  10 bf ff cd  b  0xa011bf34
a011c004:  82 10 20 9f  mov  0x9f, %g1
a011c008:  39 33 c0 45  sethi  %hi(0xcf011400), %i4
a011c00c:  82 17 23 98  or  %i4, 0x398, %g1	! 0xcf011798
a011c010:  ba 0f 60 ff  and  %i5, 0xff, %i5
a011c014:  fa 20 40 00  st  %i5, [ %g1 ]
a011c018:  83 36 60 18  srl  %i1, 0x18, %g1
a011c01c:  b8 17 23 9c  or  %i4, 0x39c, %i4
a011c020:  c2 27 00 00  st  %g1, [ %i4 ]
a011c024:  10 bf ff d3  b  0xa011bf70
a011c028:  03 33 c0 30  sethi  %hi(0xcf00c000), %g1
a011c02c:  ba 0b 60 ff  and  %o5, 0xff, %i5
a011c030:  10 bf ff dc  b  0xa011bfa0
a011c034:  82 10 63 a0  or  %g1, 0x3a0, %g1
a011c038:  39 33 c0 45  sethi  %hi(0xcf011400), %i4
a011c03c:  ba 0f 60 ff  and  %i5, 0xff, %i5
a011c040:  10 bf ff e3  b  0xa011bfcc
a011c044:  82 17 23 a0  or  %i4, 0x3a0, %g1
a011c048:  81 c7 e0 08  ret
a011c04c:  81 e8 00 00  restore
