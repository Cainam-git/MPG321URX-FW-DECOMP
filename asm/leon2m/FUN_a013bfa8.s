# leon2m FUN_a013bfa8 0xa013bfa8-0xa013c040 (152 bytes)
a013bfa8:  9d e3 bf 98  save  %sp, -104, %sp
a013bfac:  b0 0e 20 ff  and  %i0, 0xff, %i0
a013bfb0:  40 00 03 67  call  0xa013cd4c
a013bfb4:  90 10 00 18  mov  %i0, %o0
a013bfb8:  a0 10 00 08  mov  %o0, %l0
a013bfbc:  11 2a 00 b8  sethi  %hi(0xa802e000), %o0
a013bfc0:  82 12 22 24  or  %o0, 0x224, %g1	! 0xa802e224
a013bfc4:  9a 5e 20 2a  smul  %i0, 0x2a, %o5
a013bfc8:  a4 03 40 01  add  %o5, %g1, %l2
a013bfcc:  e2 14 a0 18  lduh  [ %l2 + 0x18 ], %l1
a013bfd0:  7f ff 94 a2  call  0xa0121258
a013bfd4:  90 10 00 18  mov  %i0, %o0
a013bfd8:  80 8a 20 ff  btst  0xff, %o0
a013bfdc:  90 10 00 18  mov  %i0, %o0
a013bfe0:  02 80 00 03  be  0xa013bfec
a013bfe4:  83 2c 60 10  sll  %l1, 0x10, %g1
a013bfe8:  a3 30 60 0f  srl  %g1, 0xf, %l1
a013bfec:  d4 14 a0 16  lduh  [ %l2 + 0x16 ], %o2
a013bff0:  d4 34 20 12  sth  %o2, [ %l0 + 0x12 ]
a013bff4:  d4 34 20 16  sth  %o2, [ %l0 + 0x16 ]
a013bff8:  e2 34 20 18  sth  %l1, [ %l0 + 0x18 ]
a013bffc:  7f fe f2 2c  call  0xa00f88ac
a013c000:  e2 34 20 14  sth  %l1, [ %l0 + 0x14 ]
a013c004:  d0 34 20 1a  sth  %o0, [ %l0 + 0x1a ]
a013c008:  7f fe f2 31  call  0xa00f88cc
a013c00c:  90 10 00 18  mov  %i0, %o0
a013c010:  d0 34 20 1c  sth  %o0, [ %l0 + 0x1c ]
a013c014:  7f fe f2 26  call  0xa00f88ac
a013c018:  90 10 00 18  mov  %i0, %o0
a013c01c:  d0 34 20 1e  sth  %o0, [ %l0 + 0x1e ]
a013c020:  7f fe f2 2b  call  0xa00f88cc
a013c024:  90 10 00 18  mov  %i0, %o0
a013c028:  d2 14 20 1e  lduh  [ %l0 + 0x1e ], %o1
a013c02c:  d0 34 20 2c  sth  %o0, [ %l0 + 0x2c ]
a013c030:  d2 34 20 2a  sth  %o1, [ %l0 + 0x2a ]
a013c034:  d0 34 20 20  sth  %o0, [ %l0 + 0x20 ]
a013c038:  81 c7 e0 08  ret
a013c03c:  81 e8 00 00  restore
