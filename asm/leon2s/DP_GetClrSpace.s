# leon2s DP_GetClrSpace 0xa006ed54-0xa006fa28 (3284 bytes)
a006ed54:  9d e3 bf 90  save  %sp, -112, %sp
a006ed58:  a0 0e 60 ff  and  %i1, 0xff, %l0
a006ed5c:  a8 10 00 19  mov  %i1, %l4
a006ed60:  80 a4 20 01  cmp  %l0, 1
a006ed64:  a6 10 00 1a  mov  %i2, %l3
a006ed68:  ea 0e 00 00  ldub  [ %i0 ], %l5
a006ed6c:  ec 0e 20 0d  ldub  [ %i0 + 0xd ], %l6
a006ed70:  18 80 03 2b  bgu  0xa006fa1c
a006ed74:  ee 0e 20 0e  ldub  [ %i0 + 0xe ], %l7
a006ed78:  82 16 40 1a  or  %i1, %i2, %g1
a006ed7c:  82 08 60 ff  and  %g1, 0xff, %g1
a006ed80:  80 a0 00 01  cmp  %g0, %g1
a006ed84:  9a 60 3f ff  subx  %g0, -1, %o5
a006ed88:  82 1c 20 01  xor  %l0, 1, %g1
a006ed8c:  80 a0 00 01  cmp  %g0, %g1
a006ed90:  82 60 3f ff  subx  %g0, -1, %g1
a006ed94:  80 93 40 01  orcc  %o5, %g1, %g0
a006ed98:  02 80 00 07  be  0xa006edb4
a006ed9c:  01 00 00 00  nop
a006eda0:  d2 16 20 12  lduh  [ %i0 + 0x12 ], %o1
a006eda4:  93 32 60 07  srl  %o1, 7, %o1
a006eda8:  92 0a 60 01  and  %o1, 1, %o1
a006edac:  40 01 05 aa  call  0xa00b0454
a006edb0:  90 10 00 10  mov  %l0, %o0
a006edb4:  40 01 05 af  call  0xa00b0470
a006edb8:  90 10 00 10  mov  %l0, %o0
a006edbc:  80 8a 20 ff  btst  0xff, %o0
a006edc0:  12 80 00 10  bne  0xa006ee00
a006edc4:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a006edc8:  82 10 60 c0  or  %g1, 0xc0, %g1	! 0xa80788c0
a006edcc:  c2 08 40 10  ldub  [ %g1 + %l0 ], %g1
a006edd0:  80 a0 60 01  cmp  %g1, 1
a006edd4:  12 80 00 0b  bne  0xa006ee00
a006edd8:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a006eddc:  82 10 60 b8  or  %g1, 0xb8, %g1	! 0xa80788b8
a006ede0:  c2 08 40 10  ldub  [ %g1 + %l0 ], %g1
a006ede4:  80 a0 60 00  cmp  %g1, 0
a006ede8:  02 80 00 06  be  0xa006ee00
a006edec:  01 00 00 00  nop
a006edf0:  7f c5 75 1d  call  0x9f1cc264
a006edf4:  90 10 00 10  mov  %l0, %o0
a006edf8:  7f c5 74 ac  call  0x9f1cc0a8
a006edfc:  01 00 00 00  nop
a006ee00:  40 01 09 86  call  0xa00b1418
a006ee04:  90 10 00 10  mov  %l0, %o0
a006ee08:  80 8a 20 ff  btst  0xff, %o0
a006ee0c:  02 80 00 14  be  0xa006ee5c
a006ee10:  01 00 00 00  nop
a006ee14:  40 01 09 a7  call  0xa00b14b0
a006ee18:  90 10 00 10  mov  %l0, %o0
a006ee1c:  80 8a 20 ff  btst  0xff, %o0
a006ee20:  02 80 00 0f  be  0xa006ee5c
a006ee24:  01 00 00 00  nop
a006ee28:  40 01 09 83  call  0xa00b1434
a006ee2c:  90 10 00 10  mov  %l0, %o0
a006ee30:  80 8a 20 ff  btst  0xff, %o0
a006ee34:  02 80 00 04  be  0xa006ee44
a006ee38:  90 10 00 10  mov  %l0, %o0
a006ee3c:  40 00 fa 24  call  0xa00ad6cc
a006ee40:  92 10 20 01  mov  1, %o1
a006ee44:  40 01 09 8b  call  0xa00b1470
a006ee48:  90 10 00 10  mov  %l0, %o0
a006ee4c:  40 01 0a c6  call  0xa00b1964
a006ee50:  01 00 00 00  nop
a006ee54:  40 01 09 7f  call  0xa00b1450
a006ee58:  90 10 00 10  mov  %l0, %o0
a006ee5c:  7f c5 5e 0e  call  0x9f1c6694
a006ee60:  90 10 00 10  mov  %l0, %o0
a006ee64:  25 2a 01 e2  sethi  %hi(0xa8078800), %l2
a006ee68:  82 14 a0 b8  or  %l2, 0xb8, %g1	! 0xa80788b8
a006ee6c:  da 08 40 10  ldub  [ %g1 + %l0 ], %o5
a006ee70:  a2 07 bf f8  add  %fp, -8, %l1
a006ee74:  98 0a 20 ff  and  %o0, 0xff, %o4
a006ee78:  82 04 40 10  add  %l1, %l0, %g1
a006ee7c:  80 a3 40 0c  cmp  %o5, %o4
a006ee80:  02 80 00 20  be  0xa006ef00
a006ee84:  d0 28 7f f8  stb  %o0, [ %g1 + -8 ]
a006ee88:  80 a3 20 00  cmp  %o4, 0
a006ee8c:  22 80 00 0c  be,a   0xa006eebc
a006ee90:  11 28 01 98  sethi  %hi(0xa0066000), %o0
a006ee94:  11 28 01 98  sethi  %hi(0xa0066000), %o0
a006ee98:  92 10 00 10  mov  %l0, %o1
a006ee9c:  40 00 10 6a  call  0xa0073044
a006eea0:  90 12 22 08  or  %o0, 0x208, %o0
a006eea4:  90 10 00 10  mov  %l0, %o0
a006eea8:  40 01 09 09  call  0xa00b12cc
a006eeac:  92 10 20 01  mov  1, %o1
a006eeb0:  90 10 20 00  clr  %o0
a006eeb4:  10 80 00 0a  b  0xa006eedc
a006eeb8:  92 10 20 01  mov  1, %o1
a006eebc:  92 10 00 10  mov  %l0, %o1
a006eec0:  40 00 10 61  call  0xa0073044
a006eec4:  90 12 21 d0  or  %o0, 0x1d0, %o0
a006eec8:  90 10 00 10  mov  %l0, %o0
a006eecc:  40 01 09 00  call  0xa00b12cc
a006eed0:  92 10 20 00  clr  %o1
a006eed4:  90 10 00 10  mov  %l0, %o0
a006eed8:  92 10 20 00  clr  %o1
a006eedc:  40 00 f5 50  call  0xa00ac41c
a006eee0:  94 10 20 00  clr  %o2
a006eee4:  90 10 00 18  mov  %i0, %o0
a006eee8:  7f ff f9 95  call  0xa006d53c
a006eeec:  92 10 20 02  mov  2, %o1
a006eef0:  82 04 40 10  add  %l1, %l0, %g1
a006eef4:  9a 14 a0 b8  or  %l2, 0xb8, %o5
a006eef8:  c2 08 7f f8  ldub  [ %g1 + -8 ], %g1
a006eefc:  c2 2b 40 10  stb  %g1, [ %o5 + %l0 ]
a006ef00:  b2 0c e0 ff  and  %l3, 0xff, %i1
a006ef04:  80 a6 60 01  cmp  %i1, 1
a006ef08:  12 80 00 09  bne  0xa006ef2c
a006ef0c:  80 a6 60 02  cmp  %i1, 2
a006ef10:  7f c5 74 5d  call  0x9f1cc084
a006ef14:  01 00 00 00  nop
a006ef18:  80 8a 20 ff  btst  0xff, %o0
a006ef1c:  22 80 00 11  be,a   0xa006ef60
a006ef20:  c2 0e 00 00  ldub  [ %i0 ], %g1
a006ef24:  10 80 00 08  b  0xa006ef44
a006ef28:  80 a6 60 03  cmp  %i1, 3
a006ef2c:  32 80 00 06  bne,a   0xa006ef44
a006ef30:  80 a6 60 03  cmp  %i1, 3
a006ef34:  7f c5 74 57  call  0x9f1cc090
a006ef38:  01 00 00 00  nop
a006ef3c:  10 80 00 07  b  0xa006ef58
a006ef40:  80 8a 20 ff  btst  0xff, %o0
a006ef44:  32 80 00 0d  bne,a   0xa006ef78
a006ef48:  c2 0e 00 00  ldub  [ %i0 ], %g1
a006ef4c:  7f c5 74 54  call  0x9f1cc09c
a006ef50:  01 00 00 00  nop
a006ef54:  80 8a 20 ff  btst  0xff, %o0
a006ef58:  12 80 00 08  bne  0xa006ef78
a006ef5c:  c2 0e 00 00  ldub  [ %i0 ], %g1
a006ef60:  80 a0 60 02  cmp  %g1, 2
a006ef64:  08 80 02 ae  bleu  0xa006fa1c
a006ef68:  90 10 00 18  mov  %i0, %o0
a006ef6c:  7f ff f9 74  call  0xa006d53c
a006ef70:  92 10 20 02  mov  2, %o1
a006ef74:  c2 0e 00 00  ldub  [ %i0 ], %g1
a006ef78:  82 00 7f ff  add  %g1, -1, %g1
a006ef7c:  80 a0 60 04  cmp  %g1, 4
a006ef80:  38 80 02 7e  bgu,a   0xa006f978
a006ef84:  d4 0e 00 00  ldub  [ %i0 ], %o2
a006ef88:  1b 28 01 bb  sethi  %hi(0xa006ec00), %o5
a006ef8c:  83 28 60 02  sll  %g1, 2, %g1
a006ef90:  9a 13 61 40  or  %o5, 0x140, %o5
a006ef94:  c2 03 40 01  ld  [ %o5 + %g1 ], %g1
a006ef98:  81 c0 40 00  jmp  %g1
a006ef9c:  b4 0d 20 ff  and  %l4, 0xff, %i2
a006efa0:  90 10 00 1a  mov  %i2, %o0
a006efa4:  40 01 03 94  call  0xa00afdf4
a006efa8:  92 10 20 01  mov  1, %o1
a006efac:  40 01 05 6f  call  0xa00b0568
a006efb0:  90 10 00 1a  mov  %i2, %o0
a006efb4:  10 80 02 71  b  0xa006f978
a006efb8:  d4 0e 00 00  ldub  [ %i0 ], %o2
a006efbc:  90 10 00 1a  mov  %i2, %o0
a006efc0:  40 01 05 8a  call  0xa00b05e8
a006efc4:  92 10 20 00  clr  %o1
a006efc8:  90 10 00 1a  mov  %i2, %o0
a006efcc:  40 01 02 23  call  0xa00af858
a006efd0:  92 10 20 00  clr  %o1
a006efd4:  90 10 00 1a  mov  %i2, %o0
a006efd8:  40 01 03 87  call  0xa00afdf4
a006efdc:  92 10 20 01  mov  1, %o1
a006efe0:  90 10 00 1a  mov  %i2, %o0
a006efe4:  40 00 fb 4a  call  0xa00add0c
a006efe8:  92 10 20 01  mov  1, %o1
a006efec:  90 10 00 18  mov  %i0, %o0
a006eff0:  7f ff fe 0c  call  0xa006e820
a006eff4:  92 10 00 1a  mov  %i2, %o1
a006eff8:  c2 0e 20 0d  ldub  [ %i0 + 0xd ], %g1
a006effc:  80 88 60 01  btst  1, %g1
a006f000:  22 80 02 5e  be,a   0xa006f978
a006f004:  d4 0e 00 00  ldub  [ %i0 ], %o2
a006f008:  40 01 08 d2  call  0xa00b1350
a006f00c:  90 10 00 1a  mov  %i2, %o0
a006f010:  90 10 20 00  clr  %o0
a006f014:  40 00 67 df  call  0xa0088f90
a006f018:  92 10 20 08  mov  8, %o1
a006f01c:  90 10 00 18  mov  %i0, %o0
a006f020:  7f ff f9 47  call  0xa006d53c
a006f024:  92 10 20 03  mov  3, %o1
a006f028:  11 28 01 98  sethi  %hi(0xa0066000), %o0
a006f02c:  92 10 00 1a  mov  %i2, %o1
a006f030:  94 10 00 19  mov  %i1, %o2
a006f034:  40 00 10 04  call  0xa0073044
a006f038:  90 12 22 40  or  %o0, 0x240, %o0
a006f03c:  10 80 02 4f  b  0xa006f978
a006f040:  d4 0e 00 00  ldub  [ %i0 ], %o2
a006f044:  40 00 f8 8e  call  0xa00ad27c
a006f048:  90 10 00 1a  mov  %i2, %o0
a006f04c:  90 0a 20 ff  and  %o0, 0xff, %o0
a006f050:  80 a2 20 01  cmp  %o0, 1
a006f054:  02 80 00 07  be  0xa006f070
a006f058:  90 10 00 18  mov  %i0, %o0
a006f05c:  7f ff f9 38  call  0xa006d53c
a006f060:  92 10 20 02  mov  2, %o1
a006f064:  11 28 01 98  sethi  %hi(0xa0066000), %o0
a006f068:  10 80 00 81  b  0xa006f26c
a006f06c:  90 12 22 70  or  %o0, 0x270, %o0	! 0xa0066270
a006f070:  90 10 00 1a  mov  %i2, %o0
a006f074:  40 00 de d1  call  0xa00a6bb8
a006f078:  92 10 20 f2  mov  0xf2, %o1
a006f07c:  80 8a 20 40  btst  0x40, %o0
a006f080:  22 80 02 3e  be,a   0xa006f978
a006f084:  d4 0e 00 00  ldub  [ %i0 ], %o2
a006f088:  40 00 f6 f3  call  0xa00acc54
a006f08c:  90 10 00 1a  mov  %i2, %o0
a006f090:  91 2a 20 10  sll  %o0, 0x10, %o0
a006f094:  91 32 20 10  srl  %o0, 0x10, %o0
a006f098:  80 a2 20 14  cmp  %o0, 0x14
a006f09c:  28 80 02 37  bleu,a   0xa006f978
a006f0a0:  d4 0e 00 00  ldub  [ %i0 ], %o2
a006f0a4:  40 00 f6 ec  call  0xa00acc54
a006f0a8:  90 10 00 1a  mov  %i2, %o0
a006f0ac:  91 2a 20 10  sll  %o0, 0x10, %o0
a006f0b0:  91 32 20 10  srl  %o0, 0x10, %o0
a006f0b4:  80 a2 2d 47  cmp  %o0, 0xd47
a006f0b8:  38 80 02 30  bgu,a   0xa006f978
a006f0bc:  d4 0e 00 00  ldub  [ %i0 ], %o2
a006f0c0:  40 00 f9 9d  call  0xa00ad734
a006f0c4:  90 10 00 1a  mov  %i2, %o0
a006f0c8:  92 10 20 04  mov  4, %o1
a006f0cc:  7f ff f9 1c  call  0xa006d53c
a006f0d0:  90 10 00 18  mov  %i0, %o0
a006f0d4:  40 01 0b e4  call  0xa00b2064
a006f0d8:  a1 2e 60 02  sll  %i1, 2, %l0
a006f0dc:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a006f0e0:  82 10 60 9c  or  %g1, 0x9c, %g1	! 0xa807889c
a006f0e4:  d0 20 40 10  st  %o0, [ %g1 + %l0 ]
a006f0e8:  40 00 f6 96  call  0xa00acb40
a006f0ec:  90 10 00 1a  mov  %i2, %o0
a006f0f0:  d0 36 20 02  sth  %o0, [ %i0 + 2 ]
a006f0f4:  40 00 f6 9b  call  0xa00acb60
a006f0f8:  90 10 00 1a  mov  %i2, %o0
a006f0fc:  d0 36 20 04  sth  %o0, [ %i0 + 4 ]
a006f100:  40 00 f6 70  call  0xa00acac0
a006f104:  90 10 00 1a  mov  %i2, %o0
a006f108:  d0 36 20 06  sth  %o0, [ %i0 + 6 ]
a006f10c:  40 00 f6 7d  call  0xa00acb00
a006f110:  90 10 00 1a  mov  %i2, %o0
a006f114:  d0 36 20 08  sth  %o0, [ %i0 + 8 ]
a006f118:  40 00 f6 cf  call  0xa00acc54
a006f11c:  90 10 00 1a  mov  %i2, %o0
a006f120:  c2 16 20 12  lduh  [ %i0 + 0x12 ], %g1
a006f124:  82 08 7f ef  and  %g1, -17, %g1
a006f128:  d0 36 20 0a  sth  %o0, [ %i0 + 0xa ]
a006f12c:  c2 36 20 12  sth  %g1, [ %i0 + 0x12 ]
a006f130:  90 10 00 18  mov  %i0, %o0
a006f134:  7f ff fd bb  call  0xa006e820
a006f138:  92 10 00 1a  mov  %i2, %o1
a006f13c:  90 10 00 1a  mov  %i2, %o0
a006f140:  40 01 01 c6  call  0xa00af858
a006f144:  92 10 20 00  clr  %o1
a006f148:  90 10 00 1a  mov  %i2, %o0
a006f14c:  40 01 03 2a  call  0xa00afdf4
a006f150:  92 10 20 01  mov  1, %o1
a006f154:  92 10 20 01  mov  1, %o1
a006f158:  40 01 03 c8  call  0xa00b0078
a006f15c:  90 10 00 1a  mov  %i2, %o0
a006f160:  40 01 01 81  call  0xa00af764
a006f164:  90 10 00 1a  mov  %i2, %o0
a006f168:  11 28 01 98  sethi  %hi(0xa0066000), %o0
a006f16c:  92 10 00 1a  mov  %i2, %o1
a006f170:  d4 16 20 02  lduh  [ %i0 + 2 ], %o2
a006f174:  40 00 0f b4  call  0xa0073044
a006f178:  90 12 21 38  or  %o0, 0x138, %o0
a006f17c:  11 28 01 98  sethi  %hi(0xa0066000), %o0
a006f180:  92 10 00 1a  mov  %i2, %o1
a006f184:  d4 16 20 04  lduh  [ %i0 + 4 ], %o2
a006f188:  40 00 0f af  call  0xa0073044
a006f18c:  90 12 21 58  or  %o0, 0x158, %o0
a006f190:  11 28 01 98  sethi  %hi(0xa0066000), %o0
a006f194:  92 10 00 1a  mov  %i2, %o1
a006f198:  d4 16 20 06  lduh  [ %i0 + 6 ], %o2
a006f19c:  40 00 0f aa  call  0xa0073044
a006f1a0:  90 12 21 78  or  %o0, 0x178, %o0
a006f1a4:  11 28 01 98  sethi  %hi(0xa0066000), %o0
a006f1a8:  92 10 00 1a  mov  %i2, %o1
a006f1ac:  d4 16 20 08  lduh  [ %i0 + 8 ], %o2
a006f1b0:  40 00 0f a5  call  0xa0073044
a006f1b4:  90 12 21 98  or  %o0, 0x198, %o0
a006f1b8:  11 28 01 98  sethi  %hi(0xa0066000), %o0
a006f1bc:  92 10 00 1a  mov  %i2, %o1
a006f1c0:  d4 16 20 0a  lduh  [ %i0 + 0xa ], %o2
a006f1c4:  40 00 0f a0  call  0xa0073044
a006f1c8:  90 12 22 90  or  %o0, 0x290, %o0
a006f1cc:  11 28 01 98  sethi  %hi(0xa0066000), %o0
a006f1d0:  90 12 22 a8  or  %o0, 0x2a8, %o0	! 0xa00662a8
a006f1d4:  40 00 0f 9c  call  0xa0073044
a006f1d8:  92 10 00 1a  mov  %i2, %o1
a006f1dc:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a006f1e0:  82 10 63 10  or  %g1, 0x310, %g1	! 0xa8079310
a006f1e4:  10 80 01 e4  b  0xa006f974
a006f1e8:  c0 28 40 1a  clrb  [ %g1 + %i2 ]
a006f1ec:  40 00 f8 24  call  0xa00ad27c
a006f1f0:  90 10 00 1a  mov  %i2, %o0
a006f1f4:  a4 0a 20 ff  and  %o0, 0xff, %l2
a006f1f8:  80 a4 a0 01  cmp  %l2, 1
a006f1fc:  02 80 00 07  be  0xa006f218
a006f200:  90 10 00 18  mov  %i0, %o0
a006f204:  7f ff f8 ce  call  0xa006d53c
a006f208:  92 10 20 02  mov  2, %o1
a006f20c:  11 28 01 98  sethi  %hi(0xa0066000), %o0
a006f210:  10 80 00 17  b  0xa006f26c
a006f214:  90 12 22 c8  or  %o0, 0x2c8, %o0	! 0xa00662c8
a006f218:  90 10 00 1a  mov  %i2, %o0
a006f21c:  40 00 de 67  call  0xa00a6bb8
a006f220:  92 10 20 f2  mov  0xf2, %o1
a006f224:  80 8a 20 40  btst  0x40, %o0
a006f228:  12 80 00 07  bne  0xa006f244
a006f22c:  90 10 00 18  mov  %i0, %o0
a006f230:  7f ff f8 c3  call  0xa006d53c
a006f234:  92 10 20 03  mov  3, %o1
a006f238:  11 28 01 98  sethi  %hi(0xa0066000), %o0
a006f23c:  10 80 00 0c  b  0xa006f26c
a006f240:  90 12 22 f8  or  %o0, 0x2f8, %o0	! 0xa00662f8
a006f244:  40 01 03 bd  call  0xa00b0138
a006f248:  90 10 00 1a  mov  %i2, %o0
a006f24c:  80 8a 20 ff  btst  0xff, %o0
a006f250:  22 80 00 0b  be,a   0xa006f27c
a006f254:  c2 0e 20 11  ldub  [ %i0 + 0x11 ], %g1
a006f258:  90 10 00 18  mov  %i0, %o0
a006f25c:  7f ff f8 b8  call  0xa006d53c
a006f260:  92 10 20 02  mov  2, %o1
a006f264:  11 28 01 98  sethi  %hi(0xa0066000), %o0
a006f268:  90 12 23 20  or  %o0, 0x320, %o0	! 0xa0066320
a006f26c:  40 00 0f 76  call  0xa0073044
a006f270:  92 10 00 1a  mov  %i2, %o1
a006f274:  10 80 01 c1  b  0xa006f978
a006f278:  d4 0e 00 00  ldub  [ %i0 ], %o2
a006f27c:  80 a0 60 00  cmp  %g1, 0
a006f280:  02 80 00 06  be  0xa006f298
a006f284:  80 a0 60 01  cmp  %g1, 1
a006f288:  22 80 00 cf  be,a   0xa006f5c4
a006f28c:  c2 0e 20 0d  ldub  [ %i0 + 0xd ], %g1
a006f290:  10 80 01 ba  b  0xa006f978
a006f294:  d4 0e 00 00  ldub  [ %i0 ], %o2
a006f298:  40 01 0b 73  call  0xa00b2064
a006f29c:  27 2a 01 e2  sethi  %hi(0xa8078800), %l3
a006f2a0:  d2 0e 20 0d  ldub  [ %i0 + 0xd ], %o1
a006f2a4:  a2 14 e0 9c  or  %l3, 0x9c, %l1
a006f2a8:  a1 2e 60 02  sll  %i1, 2, %l0
a006f2ac:  82 0a 60 02  and  %o1, 2, %g1
a006f2b0:  82 58 61 2c  smul  %g1, 0x12c, %g1
a006f2b4:  da 04 40 10  ld  [ %l1 + %l0 ], %o5
a006f2b8:  90 22 00 0d  sub  %o0, %o5, %o0
a006f2bc:  82 00 60 64  add  %g1, 0x64, %g1
a006f2c0:  80 a2 00 01  cmp  %o0, %g1
a006f2c4:  1a 80 00 15  bcc  0xa006f318
a006f2c8:  93 32 60 01  srl  %o1, 1, %o1
a006f2cc:  90 10 00 18  mov  %i0, %o0
a006f2d0:  7f ff fd b0  call  0xa006e990
a006f2d4:  92 10 00 1a  mov  %i2, %o1
a006f2d8:  90 0a 20 ff  and  %o0, 0xff, %o0
a006f2dc:  80 a2 20 01  cmp  %o0, 1
a006f2e0:  12 80 00 05  bne  0xa006f2f4
a006f2e4:  01 00 00 00  nop
a006f2e8:  40 01 0b 5f  call  0xa00b2064
a006f2ec:  01 00 00 00  nop
a006f2f0:  d0 24 40 10  st  %o0, [ %l1 + %l0 ]
a006f2f4:  40 01 00 0b  call  0xa00af320
a006f2f8:  90 10 00 1a  mov  %i2, %o0
a006f2fc:  80 8a 20 ff  btst  0xff, %o0
a006f300:  22 80 01 9e  be,a   0xa006f978
a006f304:  d4 0e 00 00  ldub  [ %i0 ], %o2
a006f308:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a006f30c:  82 10 60 c8  or  %g1, 0xc8, %g1	! 0xa80788c8
a006f310:  10 80 01 99  b  0xa006f974
a006f314:  e4 28 40 1a  stb  %l2, [ %g1 + %i2 ]
a006f318:  92 0a 60 01  and  %o1, 1, %o1
a006f31c:  40 00 f9 c2  call  0xa00ada24
a006f320:  90 10 00 1a  mov  %i2, %o0
a006f324:  94 0a 20 ff  and  %o0, 0xff, %o2
a006f328:  d0 2e 20 0c  stb  %o0, [ %i0 + 0xc ]
a006f32c:  11 28 01 98  sethi  %hi(0xa0066000), %o0
a006f330:  92 10 00 1a  mov  %i2, %o1
a006f334:  40 00 0f 44  call  0xa0073044
a006f338:  90 12 23 50  or  %o0, 0x350, %o0
a006f33c:  40 00 f6 16  call  0xa00acb94
a006f340:  90 10 00 1a  mov  %i2, %o0
a006f344:  92 10 00 08  mov  %o0, %o1
a006f348:  d0 2e 20 12  stb  %o0, [ %i0 + 0x12 ]
a006f34c:  11 28 01 98  sethi  %hi(0xa0066000), %o0
a006f350:  90 12 23 70  or  %o0, 0x370, %o0	! 0xa0066370
a006f354:  40 00 0f 3c  call  0xa0073044
a006f358:  92 0a 60 ff  and  %o1, 0xff, %o1
a006f35c:  80 a0 00 19  cmp  %g0, %i1
a006f360:  9a 60 3f ff  subx  %g0, -1, %o5
a006f364:  82 1e 60 04  xor  %i1, 4, %g1
a006f368:  80 a0 00 01  cmp  %g0, %g1
a006f36c:  82 60 3f ff  subx  %g0, -1, %g1
a006f370:  80 93 40 01  orcc  %o5, %g1, %g0
a006f374:  02 80 00 1a  be  0xa006f3dc
a006f378:  c2 16 20 0a  lduh  [ %i0 + 0xa ], %g1
a006f37c:  83 28 60 10  sll  %g1, 0x10, %g1
a006f380:  83 30 60 10  srl  %g1, 0x10, %g1
a006f384:  80 a0 63 a2  cmp  %g1, 0x3a2
a006f388:  18 80 00 1a  bgu  0xa006f3f0
a006f38c:  80 a0 61 c2  cmp  %g1, 0x1c2
a006f390:  08 80 00 0c  bleu  0xa006f3c0
a006f394:  d4 0e 20 0c  ldub  [ %i0 + 0xc ], %o2
a006f398:  94 0a a0 ff  and  %o2, 0xff, %o2
a006f39c:  90 10 00 1a  mov  %i2, %o0
a006f3a0:  40 00 fb 4f  call  0xa00ae0dc
a006f3a4:  92 10 20 01  mov  1, %o1
a006f3a8:  90 10 00 1a  mov  %i2, %o0
a006f3ac:  40 01 03 16  call  0xa00b0004
a006f3b0:  92 10 20 00  clr  %o1
a006f3b4:  90 10 00 1a  mov  %i2, %o0
a006f3b8:  10 80 00 26  b  0xa006f450
a006f3bc:  92 10 20 00  clr  %o1
a006f3c0:  90 10 00 1a  mov  %i2, %o0
a006f3c4:  92 10 20 01  mov  1, %o1
a006f3c8:  40 00 fb 45  call  0xa00ae0dc
a006f3cc:  94 0a a0 ff  and  %o2, 0xff, %o2
a006f3d0:  90 10 00 1a  mov  %i2, %o0
a006f3d4:  10 80 00 29  b  0xa006f478
a006f3d8:  92 10 20 01  mov  1, %o1
a006f3dc:  83 28 60 10  sll  %g1, 0x10, %g1
a006f3e0:  83 30 60 10  srl  %g1, 0x10, %g1
a006f3e4:  80 a0 63 a2  cmp  %g1, 0x3a2
a006f3e8:  08 80 00 0f  bleu  0xa006f424
a006f3ec:  80 a0 61 c2  cmp  %g1, 0x1c2
a006f3f0:  d4 0e 20 0c  ldub  [ %i0 + 0xc ], %o2
a006f3f4:  90 10 00 1a  mov  %i2, %o0
a006f3f8:  40 00 fb 39  call  0xa00ae0dc
a006f3fc:  92 10 20 04  mov  4, %o1
a006f400:  90 10 00 1a  mov  %i2, %o0
a006f404:  40 01 03 00  call  0xa00b0004
a006f408:  92 10 20 00  clr  %o1
a006f40c:  90 10 00 1a  mov  %i2, %o0
a006f410:  40 01 03 34  call  0xa00b00e0
a006f414:  92 10 20 00  clr  %o1
a006f418:  90 10 00 1a  mov  %i2, %o0
a006f41c:  10 80 00 24  b  0xa006f4ac
a006f420:  92 10 20 01  mov  1, %o1
a006f424:  08 80 00 0f  bleu  0xa006f460
a006f428:  d4 0e 20 0c  ldub  [ %i0 + 0xc ], %o2
a006f42c:  94 0a a0 ff  and  %o2, 0xff, %o2
a006f430:  90 10 00 1a  mov  %i2, %o0
a006f434:  40 00 fb 2a  call  0xa00ae0dc
a006f438:  92 10 20 01  mov  1, %o1
a006f43c:  90 10 00 1a  mov  %i2, %o0
a006f440:  40 01 02 f1  call  0xa00b0004
a006f444:  92 10 20 01  mov  1, %o1
a006f448:  90 10 00 1a  mov  %i2, %o0
a006f44c:  92 10 20 01  mov  1, %o1
a006f450:  40 01 03 24  call  0xa00b00e0
a006f454:  01 00 00 00  nop
a006f458:  10 80 00 14  b  0xa006f4a8
a006f45c:  90 10 00 1a  mov  %i2, %o0
a006f460:  90 10 00 1a  mov  %i2, %o0
a006f464:  92 10 20 01  mov  1, %o1
a006f468:  40 00 fb 1d  call  0xa00ae0dc
a006f46c:  94 0a a0 ff  and  %o2, 0xff, %o2
a006f470:  90 10 00 1a  mov  %i2, %o0
a006f474:  92 10 20 00  clr  %o1
a006f478:  40 01 02 e3  call  0xa00b0004
a006f47c:  01 00 00 00  nop
a006f480:  90 10 00 1a  mov  %i2, %o0
a006f484:  40 01 03 17  call  0xa00b00e0
a006f488:  92 10 20 00  clr  %o1
a006f48c:  40 00 f8 e7  call  0xa00ad828
a006f490:  d0 0e 20 0c  ldub  [ %i0 + 0xc ], %o0
a006f494:  80 8a 20 ff  btst  0xff, %o0
a006f498:  02 80 00 04  be  0xa006f4a8
a006f49c:  90 10 00 1a  mov  %i2, %o0
a006f4a0:  10 80 00 03  b  0xa006f4ac
a006f4a4:  92 10 20 04  mov  4, %o1
a006f4a8:  92 10 20 02  mov  2, %o1
a006f4ac:  40 00 fa 38  call  0xa00add8c
a006f4b0:  01 00 00 00  nop
a006f4b4:  90 10 00 18  mov  %i0, %o0
a006f4b8:  7f ff fc da  call  0xa006e820
a006f4bc:  92 10 00 1a  mov  %i2, %o1
a006f4c0:  40 00 ff 98  call  0xa00af320
a006f4c4:  90 10 00 1a  mov  %i2, %o0
a006f4c8:  80 8a 20 ff  btst  0xff, %o0
a006f4cc:  22 80 00 07  be,a   0xa006f4e8
a006f4d0:  c2 0e 20 0d  ldub  [ %i0 + 0xd ], %g1
a006f4d4:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a006f4d8:  9a 10 20 02  mov  2, %o5
a006f4dc:  82 10 60 c8  or  %g1, 0xc8, %g1
a006f4e0:  da 28 40 1a  stb  %o5, [ %g1 + %i2 ]
a006f4e4:  c2 0e 20 0d  ldub  [ %i0 + 0xd ], %g1
a006f4e8:  80 88 60 02  btst  2, %g1
a006f4ec:  12 80 00 07  bne  0xa006f508
a006f4f0:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a006f4f4:  a0 10 60 c8  or  %g1, 0xc8, %l0	! 0xa80788c8
a006f4f8:  c2 0c 00 1a  ldub  [ %l0 + %i2 ], %g1
a006f4fc:  80 a0 60 02  cmp  %g1, 2
a006f500:  32 80 00 0c  bne,a   0xa006f530
a006f504:  90 10 00 1a  mov  %i2, %o0
a006f508:  90 10 00 1a  mov  %i2, %o0
a006f50c:  40 00 ff 17  call  0xa00af168
a006f510:  92 10 20 01  mov  1, %o1
a006f514:  90 10 00 1a  mov  %i2, %o0
a006f518:  40 00 ff d3  call  0xa00af464
a006f51c:  92 10 20 01  mov  1, %o1
a006f520:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a006f524:  82 10 63 10  or  %g1, 0x310, %g1	! 0xa8079310
a006f528:  10 80 00 08  b  0xa006f548
a006f52c:  c0 28 40 1a  clrb  [ %g1 + %i2 ]
a006f530:  40 00 ff 0e  call  0xa00af168
a006f534:  92 10 20 00  clr  %o1
a006f538:  90 10 00 1a  mov  %i2, %o0
a006f53c:  40 00 ff ca  call  0xa00af464
a006f540:  92 10 20 00  clr  %o1
a006f544:  c0 2c 00 1a  clrb  [ %l0 + %i2 ]
a006f548:  90 10 00 1a  mov  %i2, %o0
a006f54c:  40 00 fb 42  call  0xa00ae254
a006f550:  92 10 20 b0  mov  0xb0, %o1
a006f554:  90 10 00 1a  mov  %i2, %o0
a006f558:  40 00 f9 ed  call  0xa00add0c
a006f55c:  92 10 20 00  clr  %o1
a006f560:  90 10 00 1a  mov  %i2, %o0
a006f564:  40 01 00 bd  call  0xa00af858
a006f568:  92 10 20 01  mov  1, %o1
a006f56c:  90 10 00 1a  mov  %i2, %o0
a006f570:  40 01 02 21  call  0xa00afdf4
a006f574:  92 10 20 00  clr  %o1
a006f578:  92 10 20 00  clr  %o1
a006f57c:  40 01 02 bf  call  0xa00b0078
a006f580:  90 10 00 1a  mov  %i2, %o0
a006f584:  40 01 03 c9  call  0xa00b04a8
a006f588:  90 10 00 1a  mov  %i2, %o0
a006f58c:  40 00 f6 ce  call  0xa00ad0c4
a006f590:  90 10 00 1a  mov  %i2, %o0
a006f594:  40 00 70 e0  call  0xa008b914
a006f598:  90 10 00 1a  mov  %i2, %o0
a006f59c:  40 01 0a b2  call  0xa00b2064
a006f5a0:  a2 14 e0 9c  or  %l3, 0x9c, %l1
a006f5a4:  a1 2e 60 02  sll  %i1, 2, %l0
a006f5a8:  d0 24 40 10  st  %o0, [ %l1 + %l0 ]
a006f5ac:  40 00 f6 bc  call  0xa00ad09c
a006f5b0:  90 10 00 1a  mov  %i2, %o0
a006f5b4:  c2 0e 20 11  ldub  [ %i0 + 0x11 ], %g1
a006f5b8:  82 00 60 01  inc  %g1
a006f5bc:  10 80 00 ee  b  0xa006f974
a006f5c0:  c2 2e 20 11  stb  %g1, [ %i0 + 0x11 ]
a006f5c4:  80 88 60 02  btst  2, %g1
a006f5c8:  12 80 00 41  bne  0xa006f6cc
a006f5cc:  90 10 00 18  mov  %i0, %o0
a006f5d0:  40 01 0a a5  call  0xa00b2064
a006f5d4:  a1 2e 60 02  sll  %i1, 2, %l0
a006f5d8:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a006f5dc:  a2 10 60 9c  or  %g1, 0x9c, %l1	! 0xa807889c
a006f5e0:  c2 04 40 10  ld  [ %l1 + %l0 ], %g1
a006f5e4:  90 22 00 01  sub  %o0, %g1, %o0
a006f5e8:  80 a2 20 95  cmp  %o0, 0x95
a006f5ec:  38 80 00 19  bgu,a   0xa006f650
a006f5f0:  c2 0e 20 0d  ldub  [ %i0 + 0xd ], %g1
a006f5f4:  90 10 00 18  mov  %i0, %o0
a006f5f8:  7f ff fc e6  call  0xa006e990
a006f5fc:  92 10 00 1a  mov  %i2, %o1
a006f600:  90 0a 20 ff  and  %o0, 0xff, %o0
a006f604:  80 a2 20 01  cmp  %o0, 1
a006f608:  12 80 00 08  bne  0xa006f628
a006f60c:  90 10 00 18  mov  %i0, %o0
a006f610:  7f ff f7 cb  call  0xa006d53c
a006f614:  92 10 20 04  mov  4, %o1
a006f618:  40 01 0a 93  call  0xa00b2064
a006f61c:  01 00 00 00  nop
a006f620:  10 80 00 d5  b  0xa006f974
a006f624:  d0 24 40 10  st  %o0, [ %l1 + %l0 ]
a006f628:  40 00 f8 07  call  0xa00ad644
a006f62c:  90 10 00 1a  mov  %i2, %o0
a006f630:  90 0a 20 ff  and  %o0, 0xff, %o0
a006f634:  80 a2 20 01  cmp  %o0, 1
a006f638:  32 80 00 d0  bne,a   0xa006f978
a006f63c:  d4 0e 00 00  ldub  [ %i0 ], %o2
a006f640:  40 00 f6 97  call  0xa00ad09c
a006f644:  90 10 00 1a  mov  %i2, %o0
a006f648:  10 80 00 cc  b  0xa006f978
a006f64c:  d4 0e 00 00  ldub  [ %i0 ], %o2
a006f650:  80 88 60 02  btst  2, %g1
a006f654:  12 80 00 1e  bne  0xa006f6cc
a006f658:  90 10 00 18  mov  %i0, %o0
a006f65c:  40 00 f7 fa  call  0xa00ad644
a006f660:  90 10 00 1a  mov  %i2, %o0
a006f664:  90 0a 20 ff  and  %o0, 0xff, %o0
a006f668:  80 a2 20 01  cmp  %o0, 1
a006f66c:  32 80 00 18  bne,a   0xa006f6cc
a006f670:  90 10 00 18  mov  %i0, %o0
a006f674:  40 00 f7 f4  call  0xa00ad644
a006f678:  90 10 00 1a  mov  %i2, %o0
a006f67c:  a0 0a 20 ff  and  %o0, 0xff, %l0
a006f680:  92 10 20 44  mov  0x44, %o1
a006f684:  40 00 dd 4d  call  0xa00a6bb8
a006f688:  90 10 00 1a  mov  %i2, %o0
a006f68c:  96 0a 20 ff  and  %o0, 0xff, %o3
a006f690:  11 28 01 98  sethi  %hi(0xa0066000), %o0
a006f694:  94 10 00 10  mov  %l0, %o2
a006f698:  92 10 00 1a  mov  %i2, %o1
a006f69c:  40 00 0e 6a  call  0xa0073044
a006f6a0:  90 12 23 88  or  %o0, 0x388, %o0
a006f6a4:  90 10 00 18  mov  %i0, %o0
a006f6a8:  7f ff f7 a5  call  0xa006d53c
a006f6ac:  92 10 20 04  mov  4, %o1
a006f6b0:  40 01 0a 6d  call  0xa00b2064
a006f6b4:  a0 0c e0 ff  and  %l3, 0xff, %l0
a006f6b8:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a006f6bc:  a1 2c 20 02  sll  %l0, 2, %l0
a006f6c0:  82 10 60 9c  or  %g1, 0x9c, %g1
a006f6c4:  10 80 00 ac  b  0xa006f974
a006f6c8:  d0 20 40 10  st  %o0, [ %g1 + %l0 ]
a006f6cc:  7f ff f7 9c  call  0xa006d53c
a006f6d0:  92 10 20 05  mov  5, %o1
a006f6d4:  a0 0c e0 ff  and  %l3, 0xff, %l0
a006f6d8:  a2 0d 20 ff  and  %l4, 0xff, %l1
a006f6dc:  11 28 01 98  sethi  %hi(0xa0066000), %o0
a006f6e0:  92 10 00 11  mov  %l1, %o1
a006f6e4:  94 10 00 10  mov  %l0, %o2
a006f6e8:  d6 16 20 0a  lduh  [ %i0 + 0xa ], %o3
a006f6ec:  40 00 0e 56  call  0xa0073044
a006f6f0:  90 12 23 b0  or  %o0, 0x3b0, %o0
a006f6f4:  82 10 20 01  mov  1, %g1
a006f6f8:  40 01 0a 5b  call  0xa00b2064
a006f6fc:  c2 2e 20 0f  stb  %g1, [ %i0 + 0xf ]
a006f700:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a006f704:  9b 2c 20 02  sll  %l0, 2, %o5
a006f708:  82 10 60 9c  or  %g1, 0x9c, %g1
a006f70c:  d0 20 40 0d  st  %o0, [ %g1 + %o5 ]
a006f710:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a006f714:  82 10 60 b0  or  %g1, 0xb0, %g1	! 0xa80788b0
a006f718:  c0 28 40 10  clrb  [ %g1 + %l0 ]
a006f71c:  40 00 f1 01  call  0xa00abb20
a006f720:  90 10 00 11  mov  %l1, %o0
a006f724:  10 80 00 95  b  0xa006f978
a006f728:  d4 0e 00 00  ldub  [ %i0 ], %o2
a006f72c:  40 00 f6 d4  call  0xa00ad27c
a006f730:  90 10 00 1a  mov  %i2, %o0
a006f734:  90 0a 20 ff  and  %o0, 0xff, %o0
a006f738:  80 a2 20 01  cmp  %o0, 1
a006f73c:  02 80 00 08  be  0xa006f75c
a006f740:  11 28 01 98  sethi  %hi(0xa0066000), %o0
a006f744:  92 10 00 1a  mov  %i2, %o1
a006f748:  40 00 0e 3f  call  0xa0073044
a006f74c:  90 12 23 e8  or  %o0, 0x3e8, %o0
a006f750:  90 10 00 18  mov  %i0, %o0
a006f754:  10 80 00 0e  b  0xa006f78c
a006f758:  92 10 20 02  mov  2, %o1
a006f75c:  90 10 00 1a  mov  %i2, %o0
a006f760:  40 00 dd 16  call  0xa00a6bb8
a006f764:  92 10 20 f2  mov  0xf2, %o1
a006f768:  80 8a 20 40  btst  0x40, %o0
a006f76c:  32 80 00 0c  bne,a   0xa006f79c
a006f770:  d2 0e 20 0d  ldub  [ %i0 + 0xd ], %o1
a006f774:  11 28 01 99  sethi  %hi(0xa0066400), %o0
a006f778:  92 10 00 1a  mov  %i2, %o1
a006f77c:  40 00 0e 32  call  0xa0073044
a006f780:  90 12 20 00  mov  %o0, %o0
a006f784:  90 10 00 18  mov  %i0, %o0
a006f788:  92 10 20 03  mov  3, %o1
a006f78c:  7f ff f7 6c  call  0xa006d53c
a006f790:  01 00 00 00  nop
a006f794:  10 80 00 66  b  0xa006f92c
a006f798:  c2 0e 00 00  ldub  [ %i0 ], %g1
a006f79c:  93 32 60 01  srl  %o1, 1, %o1
a006f7a0:  92 0a 60 01  and  %o1, 1, %o1
a006f7a4:  40 00 f8 a0  call  0xa00ada24
a006f7a8:  90 10 00 1a  mov  %i2, %o0
a006f7ac:  90 0a 20 ff  and  %o0, 0xff, %o0
a006f7b0:  c2 0e 20 0c  ldub  [ %i0 + 0xc ], %g1
a006f7b4:  80 a2 00 01  cmp  %o0, %g1
a006f7b8:  02 80 00 0c  be  0xa006f7e8
a006f7bc:  11 28 01 99  sethi  %hi(0xa0066400), %o0
a006f7c0:  92 10 00 1a  mov  %i2, %o1
a006f7c4:  40 00 0e 20  call  0xa0073044
a006f7c8:  90 12 20 10  or  %o0, 0x10, %o0
a006f7cc:  d2 0e 20 0d  ldub  [ %i0 + 0xd ], %o1
a006f7d0:  93 32 60 01  srl  %o1, 1, %o1
a006f7d4:  92 0a 60 01  and  %o1, 1, %o1
a006f7d8:  40 00 f8 93  call  0xa00ada24
a006f7dc:  90 10 00 1a  mov  %i2, %o0
a006f7e0:  10 80 00 2d  b  0xa006f894
a006f7e4:  d0 2e 20 0c  stb  %o0, [ %i0 + 0xc ]
a006f7e8:  90 10 00 18  mov  %i0, %o0
a006f7ec:  7f ff fc 69  call  0xa006e990
a006f7f0:  92 10 00 1a  mov  %i2, %o1
a006f7f4:  90 0a 20 ff  and  %o0, 0xff, %o0
a006f7f8:  80 a2 20 01  cmp  %o0, 1
a006f7fc:  32 80 00 11  bne,a   0xa006f840
a006f800:  c2 0e 20 0d  ldub  [ %i0 + 0xd ], %g1
a006f804:  90 10 00 18  mov  %i0, %o0
a006f808:  7f ff f7 4d  call  0xa006d53c
a006f80c:  92 10 20 04  mov  4, %o1
a006f810:  40 01 0a 15  call  0xa00b2064
a006f814:  01 00 00 00  nop
a006f818:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a006f81c:  9b 2e 60 02  sll  %i1, 2, %o5
a006f820:  82 10 60 9c  or  %g1, 0x9c, %g1
a006f824:  92 10 00 08  mov  %o0, %o1
a006f828:  d0 20 40 0d  st  %o0, [ %g1 + %o5 ]
a006f82c:  11 28 01 99  sethi  %hi(0xa0066400), %o0
a006f830:  40 00 0e 05  call  0xa0073044
a006f834:  90 12 20 30  or  %o0, 0x30, %o0	! 0xa0066430
a006f838:  10 80 00 3d  b  0xa006f92c
a006f83c:  c2 0e 00 00  ldub  [ %i0 ], %g1
a006f840:  80 88 60 02  btst  2, %g1
a006f844:  12 80 00 1d  bne  0xa006f8b8
a006f848:  01 00 00 00  nop
a006f84c:  40 00 f7 7e  call  0xa00ad644
a006f850:  90 10 00 1a  mov  %i2, %o0
a006f854:  90 0a 20 ff  and  %o0, 0xff, %o0
a006f858:  80 a2 20 01  cmp  %o0, 1
a006f85c:  12 80 00 17  bne  0xa006f8b8
a006f860:  01 00 00 00  nop
a006f864:  40 00 f7 78  call  0xa00ad644
a006f868:  90 10 00 1a  mov  %i2, %o0
a006f86c:  a0 0a 20 ff  and  %o0, 0xff, %l0
a006f870:  92 10 20 44  mov  0x44, %o1
a006f874:  40 00 dc d1  call  0xa00a6bb8
a006f878:  90 10 00 1a  mov  %i2, %o0
a006f87c:  96 0a 20 ff  and  %o0, 0xff, %o3
a006f880:  11 28 01 98  sethi  %hi(0xa0066000), %o0
a006f884:  94 10 00 10  mov  %l0, %o2
a006f888:  92 10 00 1a  mov  %i2, %o1
a006f88c:  40 00 0d ee  call  0xa0073044
a006f890:  90 12 23 88  or  %o0, 0x388, %o0
a006f894:  90 10 00 18  mov  %i0, %o0
a006f898:  7f ff f7 29  call  0xa006d53c
a006f89c:  92 10 20 04  mov  4, %o1
a006f8a0:  40 01 09 f1  call  0xa00b2064
a006f8a4:  a1 2e 60 02  sll  %i1, 2, %l0
a006f8a8:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a006f8ac:  82 10 60 9c  or  %g1, 0x9c, %g1	! 0xa807889c
a006f8b0:  10 80 00 1e  b  0xa006f928
a006f8b4:  d0 20 40 10  st  %o0, [ %g1 + %l0 ]
a006f8b8:  40 01 03 8a  call  0xa00b06e0
a006f8bc:  90 10 00 1a  mov  %i2, %o0
a006f8c0:  40 01 09 e9  call  0xa00b2064
a006f8c4:  a1 2e 60 02  sll  %i1, 2, %l0
a006f8c8:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a006f8cc:  a2 10 60 9c  or  %g1, 0x9c, %l1	! 0xa807889c
a006f8d0:  c2 04 40 10  ld  [ %l1 + %l0 ], %g1
a006f8d4:  90 22 00 01  sub  %o0, %g1, %o0
a006f8d8:  80 a2 21 2c  cmp  %o0, 0x12c
a006f8dc:  08 80 00 0c  bleu  0xa006f90c
a006f8e0:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a006f8e4:  40 01 09 e0  call  0xa00b2064
a006f8e8:  01 00 00 00  nop
a006f8ec:  d0 24 40 10  st  %o0, [ %l1 + %l0 ]
a006f8f0:  40 00 fa a2  call  0xa00ae378
a006f8f4:  90 10 00 1a  mov  %i2, %o0
a006f8f8:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a006f8fc:  9a 10 20 01  mov  1, %o5
a006f900:  82 10 60 b0  or  %g1, 0xb0, %g1
a006f904:  da 28 40 19  stb  %o5, [ %g1 + %i1 ]
a006f908:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a006f90c:  82 10 60 b0  or  %g1, 0xb0, %g1	! 0xa80788b0
a006f910:  c2 08 40 19  ldub  [ %g1 + %i1 ], %g1
a006f914:  80 a0 60 01  cmp  %g1, 1
a006f918:  32 80 00 05  bne,a   0xa006f92c
a006f91c:  c2 0e 00 00  ldub  [ %i0 ], %g1
a006f920:  40 00 f7 59  call  0xa00ad684
a006f924:  90 10 00 1a  mov  %i2, %o0
a006f928:  c2 0e 00 00  ldub  [ %i0 ], %g1
a006f92c:  80 a0 60 05  cmp  %g1, 5
a006f930:  02 80 00 11  be  0xa006f974
a006f934:  a0 0d 20 ff  and  %l4, 0xff, %l0
a006f938:  40 00 f0 37  call  0xa00aba14
a006f93c:  90 10 00 10  mov  %l0, %o0
a006f940:  a2 10 20 00  clr  %l1
a006f944:  92 0c 60 ff  and  %l1, 0xff, %o1
a006f948:  40 00 f0 07  call  0xa00ab964
a006f94c:  90 10 00 10  mov  %l0, %o0
a006f950:  a2 04 60 01  inc  %l1
a006f954:  82 0c 60 ff  and  %l1, 0xff, %g1
a006f958:  80 a0 60 09  cmp  %g1, 9
a006f95c:  08 bf ff fb  bleu  0xa006f948
a006f960:  92 0c 60 ff  and  %l1, 0xff, %o1
a006f964:  92 10 00 10  mov  %l0, %o1
a006f968:  94 0c e0 ff  and  %l3, 0xff, %o2
a006f96c:  7f ff f6 ff  call  0xa006d568
a006f970:  90 10 00 18  mov  %i0, %o0
a006f974:  d4 0e 00 00  ldub  [ %i0 ], %o2
a006f978:  82 1a a0 05  xor  %o2, 5, %g1
a006f97c:  80 a0 00 01  cmp  %g0, %g1
a006f980:  82 0d 60 ff  and  %l5, 0xff, %g1
a006f984:  9a 40 20 00  addx  %g0, 0, %o5
a006f988:  82 18 60 05  xor  %g1, 5, %g1
a006f98c:  80 a0 00 01  cmp  %g0, %g1
a006f990:  82 60 3f ff  subx  %g0, -1, %g1
a006f994:  80 8b 40 01  btst  %o5, %g1
a006f998:  02 80 00 0d  be  0xa006f9cc
a006f99c:  98 0d a0 ff  and  %l6, 0xff, %o4
a006f9a0:  82 10 20 01  mov  1, %g1
a006f9a4:  a0 0d 20 ff  and  %l4, 0xff, %l0
a006f9a8:  11 28 01 99  sethi  %hi(0xa0066400), %o0
a006f9ac:  c2 2e 20 10  stb  %g1, [ %i0 + 0x10 ]
a006f9b0:  90 12 20 48  or  %o0, 0x48, %o0
a006f9b4:  40 00 0d a4  call  0xa0073044
a006f9b8:  92 10 00 10  mov  %l0, %o1
a006f9bc:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a006f9c0:  82 10 60 c8  or  %g1, 0xc8, %g1	! 0xa80788c8
a006f9c4:  c0 28 40 10  clrb  [ %g1 + %l0 ]
a006f9c8:  98 0d a0 ff  and  %l6, 0xff, %o4
a006f9cc:  d4 0e 20 0d  ldub  [ %i0 + 0xd ], %o2
a006f9d0:  80 a2 80 0c  cmp  %o2, %o4
a006f9d4:  12 80 00 07  bne  0xa006f9f0
a006f9d8:  9a 0b 20 48  and  %o4, 0x48, %o5
a006f9dc:  9a 0d e0 ff  and  %l7, 0xff, %o5
a006f9e0:  c2 0e 20 0e  ldub  [ %i0 + 0xe ], %g1
a006f9e4:  80 a0 40 0d  cmp  %g1, %o5
a006f9e8:  02 80 00 0d  be  0xa006fa1c
a006f9ec:  9a 0b 20 48  and  %o4, 0x48, %o5
a006f9f0:  98 10 20 01  mov  1, %o4
a006f9f4:  82 0a a0 48  and  %o2, 0x48, %g1
a006f9f8:  80 a0 40 0d  cmp  %g1, %o5
a006f9fc:  02 80 00 03  be  0xa006fa08
a006fa00:  d8 2e 20 0f  stb  %o4, [ %i0 + 0xf ]
a006fa04:  d8 2e 20 10  stb  %o4, [ %i0 + 0x10 ]
a006fa08:  11 28 01 99  sethi  %hi(0xa0066400), %o0
a006fa0c:  90 12 20 68  or  %o0, 0x68, %o0	! 0xa0066468
a006fa10:  92 0d 20 ff  and  %l4, 0xff, %o1
a006fa14:  40 00 0d 8c  call  0xa0073044
a006fa18:  d6 0e 20 0e  ldub  [ %i0 + 0xe ], %o3
a006fa1c:  01 00 00 00  nop
a006fa20:  81 c7 e0 08  ret
a006fa24:  81 e8 00 00  restore
