# leon2m FUN_a014bf64 0xa014bf64-0xa014c118 (436 bytes)
a014bf64:  9d e3 bf 98  save  %sp, -104, %sp
a014bf68:  23 2a 00 b7  sethi  %hi(0xa802dc00), %l1
a014bf6c:  de 04 63 30  ld  [ %l1 + 0x330 ], %o7	! 0xa802df30
a014bf70:  95 33 e0 0c  srl  %o7, 0xc, %o2
a014bf74:  92 0a a0 0f  and  %o2, 0xf, %o1
a014bf78:  11 2a 00 b8  sethi  %hi(0xa802e000), %o0
a014bf7c:  9a 5a 60 2a  smul  %o1, 0x2a, %o5
a014bf80:  21 2a 00 b8  sethi  %hi(0xa802e000), %l0
a014bf84:  82 12 22 24  or  %o0, 0x224, %g1
a014bf88:  d6 10 40 0d  lduh  [ %g1 + %o5 ], %o3
a014bf8c:  98 14 23 d0  or  %l0, 0x3d0, %o4
a014bf90:  80 8a e0 40  btst  0x40, %o3
a014bf94:  12 80 00 1e  bne  0xa014c00c
a014bf98:  f0 2b 20 08  stb  %i0, [ %o4 + 8 ]
a014bf9c:  f0 04 63 30  ld  [ %l1 + 0x330 ], %i0
a014bfa0:  a3 36 20 0c  srl  %i0, 0xc, %l1
a014bfa4:  7f ff d0 2d  call  0xa0140058
a014bfa8:  90 0c 60 0f  and  %l1, 0xf, %o0
a014bfac:  80 8a 20 ff  btst  0xff, %o0
a014bfb0:  02 80 00 2b  be  0xa014c05c
a014bfb4:  98 14 23 d0  or  %l0, 0x3d0, %o4
a014bfb8:  03 2a 00 b8  sethi  %hi(0xa802e000), %g1
a014bfbc:  da 10 62 16  lduh  [ %g1 + 0x216 ], %o5	! 0xa802e216
a014bfc0:  98 14 23 d0  or  %l0, 0x3d0, %o4
a014bfc4:  e0 0b 20 08  ldub  [ %o4 + 8 ], %l0
a014bfc8:  96 03 7f 82  add  %o5, -126, %o3
a014bfcc:  b0 5c 00 0b  smul  %l0, %o3, %i0
a014bfd0:  13 14 7a e1  sethi  %hi(0x51eb8400), %o1
a014bfd4:  90 06 20 32  add  %i0, 0x32, %o0
a014bfd8:  82 12 61 1f  or  %o1, 0x11f, %g1
a014bfdc:  80 52 00 01  umul  %o0, %g1, %g0
a014bfe0:  99 40 00 00  rd  %y, %o4
a014bfe4:  9b 33 20 05  srl  %o4, 5, %o5
a014bfe8:  96 03 60 7e  add  %o5, 0x7e, %o3
a014bfec:  b1 2a e0 10  sll  %o3, 0x10, %i0
a014bff0:  b1 36 20 10  srl  %i0, 0x10, %i0
a014bff4:  21 00 06 9b  sethi  %hi(0x1a6c00), %l0
a014bff8:  92 10 00 18  mov  %i0, %o1
a014bffc:  7f fe 4c 5d  call  0xa00df170
a014c000:  90 14 21 c0  or  %l0, 0x1c0, %o0
a014c004:  7f ff 68 d7  call  0xa0126360
a014c008:  81 e8 00 00  restore
a014c00c:  7f ff b3 94  call  0xa0138e5c
a014c010:  01 00 00 00  nop
a014c014:  90 0a 20 ff  and  %o0, 0xff, %o0
a014c018:  80 a2 20 01  cmp  %o0, 1
a014c01c:  02 80 00 0b  be  0xa014c048
a014c020:  82 10 20 01  mov  1, %g1
a014c024:  80 a2 20 01  cmp  %o0, 1
a014c028:  04 80 00 37  ble  0xa014c104
a014c02c:  80 a2 20 02  cmp  %o0, 2
a014c030:  02 80 00 06  be  0xa014c048
a014c034:  82 10 20 02  mov  2, %g1
a014c038:  80 a2 20 03  cmp  %o0, 3
a014c03c:  02 80 00 03  be  0xa014c048
a014c040:  82 10 20 03  mov  3, %g1
a014c044:  82 10 20 04  mov  4, %g1
a014c048:  80 88 60 ff  btst  0xff, %g1
a014c04c:  12 bf ff dc  bne  0xa014bfbc
a014c050:  03 2a 00 b8  sethi  %hi(0xa802e000), %g1
a014c054:  10 bf ff d3  b  0xa014bfa0
a014c058:  f0 04 63 30  ld  [ %l1 + 0x330 ], %i0
a014c05c:  c2 03 20 38  ld  [ %o4 + 0x38 ], %g1
a014c060:  80 a0 60 01  cmp  %g1, 1
a014c064:  02 80 00 17  be  0xa014c0c0
a014c068:  80 a0 60 02  cmp  %g1, 2
a014c06c:  02 80 00 15  be  0xa014c0c0
a014c070:  21 00 06 9b  sethi  %hi(0x1a6c00), %l0
a014c074:  d4 0b 20 08  ldub  [ %o4 + 8 ], %o2
a014c078:  a3 2a a0 03  sll  %o2, 3, %l1
a014c07c:  9e 24 40 0a  sub  %l1, %o2, %o7
a014c080:  93 2b e0 07  sll  %o7, 7, %o1
a014c084:  b0 02 40 0a  add  %o1, %o2, %i0
a014c088:  13 14 7a e1  sethi  %hi(0x51eb8400), %o1
a014c08c:  90 06 20 32  add  %i0, 0x32, %o0
a014c090:  82 12 61 1f  or  %o1, 0x11f, %g1
a014c094:  80 52 00 01  umul  %o0, %g1, %g0
a014c098:  99 40 00 00  rd  %y, %o4
a014c09c:  9b 33 20 05  srl  %o4, 5, %o5
a014c0a0:  96 03 60 7e  add  %o5, 0x7e, %o3
a014c0a4:  b1 2a e0 10  sll  %o3, 0x10, %i0
a014c0a8:  b1 36 20 10  srl  %i0, 0x10, %i0
a014c0ac:  92 10 00 18  mov  %i0, %o1
a014c0b0:  7f fe 4c 30  call  0xa00df170
a014c0b4:  90 14 21 c0  or  %l0, 0x1c0, %o0
a014c0b8:  7f ff 68 aa  call  0xa0126360
a014c0bc:  81 e8 00 00  restore
a014c0c0:  d0 0b 20 08  ldub  [ %o4 + 8 ], %o0
a014c0c4:  b0 5a 22 5f  smul  %o0, 0x25f, %i0
a014c0c8:  13 14 7a e1  sethi  %hi(0x51eb8400), %o1
a014c0cc:  90 06 20 32  add  %i0, 0x32, %o0
a014c0d0:  82 12 61 1f  or  %o1, 0x11f, %g1
a014c0d4:  80 52 00 01  umul  %o0, %g1, %g0
a014c0d8:  99 40 00 00  rd  %y, %o4
a014c0dc:  9b 33 20 05  srl  %o4, 5, %o5
a014c0e0:  96 03 60 7e  add  %o5, 0x7e, %o3
a014c0e4:  b1 2a e0 10  sll  %o3, 0x10, %i0
a014c0e8:  b1 36 20 10  srl  %i0, 0x10, %i0
a014c0ec:  21 00 06 9b  sethi  %hi(0x1a6c00), %l0
a014c0f0:  92 10 00 18  mov  %i0, %o1
a014c0f4:  7f fe 4c 1f  call  0xa00df170
a014c0f8:  90 14 21 c0  or  %l0, 0x1c0, %o0
a014c0fc:  7f ff 68 99  call  0xa0126360
a014c100:  81 e8 00 00  restore
a014c104:  80 a2 20 00  cmp  %o0, 0
a014c108:  02 bf ff d0  be  0xa014c048
a014c10c:  82 10 20 00  clr  %g1
a014c110:  10 bf ff ce  b  0xa014c048
a014c114:  82 10 20 04  mov  4, %g1
