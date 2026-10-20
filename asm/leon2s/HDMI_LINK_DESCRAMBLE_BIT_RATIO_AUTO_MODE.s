# leon2s HDMI_LINK_DESCRAMBLE_BIT_RATIO_AUTO_MODE 0xa007ed88-0xa007f634 (2220 bytes)
a007ed88:  9d e3 bf 98  save  %sp, -104, %sp
a007ed8c:  2f 2a 01 e1  sethi  %hi(0xa8078400), %l7
a007ed90:  c2 05 e2 34  ld  [ %l7 + 0x234 ], %g1	! 0xa8078634
a007ed94:  80 88 60 02  btst  2, %g1
a007ed98:  02 80 00 16  be  0xa007edf0
a007ed9c:  aa 10 00 18  mov  %i0, %l5
a007eda0:  40 00 cc b1  call  0xa00b2064
a007eda4:  01 00 00 00  nop
a007eda8:  94 10 00 08  mov  %o0, %o2
a007edac:  92 06 20 41  add  %i0, 0x41, %o1
a007edb0:  93 2a 60 18  sll  %o1, 0x18, %o1
a007edb4:  11 28 01 a0  sethi  %hi(0xa0068000), %o0
a007edb8:  90 12 22 50  or  %o0, 0x250, %o0	! 0xa0068250
a007edbc:  7f ff d0 a2  call  0xa0073044
a007edc0:  93 3a 60 18  sra  %o1, 0x18, %o1
a007edc4:  c2 05 e2 34  ld  [ %l7 + 0x234 ], %g1
a007edc8:  80 88 60 02  btst  2, %g1
a007edcc:  02 80 00 09  be  0xa007edf0
a007edd0:  92 06 20 41  add  %i0, 0x41, %o1
a007edd4:  93 2a 60 18  sll  %o1, 0x18, %o1
a007edd8:  11 28 01 9c  sethi  %hi(0xa0067000), %o0
a007eddc:  15 28 02 cf  sethi  %hi(0xa00b3c00), %o2
a007ede0:  90 12 20 58  or  %o0, 0x58, %o0
a007ede4:  93 3a 60 18  sra  %o1, 0x18, %o1
a007ede8:  7f ff d0 97  call  0xa0073044
a007edec:  94 12 a3 20  or  %o2, 0x320, %o2
a007edf0:  03 2a 01 f3  sethi  %hi(0xa807cc00), %g1
a007edf4:  1b 2a 01 f3  sethi  %hi(0xa807cc00), %o5
a007edf8:  98 10 60 58  or  %g1, 0x58, %o4
a007edfc:  96 13 60 f8  or  %o5, 0xf8, %o3
a007ee00:  a8 0d 60 ff  and  %l5, 0xff, %l4
a007ee04:  c0 28 60 58  clrb  [ %g1 + 0x58 ]
a007ee08:  c0 2b 20 02  clrb  [ %o4 + 2 ]
a007ee0c:  c0 2b 60 f8  clrb  [ %o5 + 0xf8 ]
a007ee10:  c0 2a e0 02  clrb  [ %o3 + 2 ]
a007ee14:  c0 2b 20 01  clrb  [ %o4 + 1 ]
a007ee18:  c0 2a e0 01  clrb  [ %o3 + 1 ]
a007ee1c:  7f ff d1 c1  call  0xa0073520
a007ee20:  90 10 00 14  mov  %l4, %o0
a007ee24:  80 8a 20 ff  btst  0xff, %o0
a007ee28:  02 80 00 34  be  0xa007eef8
a007ee2c:  23 00 00 04  sethi  %hi(0x1000), %l1
a007ee30:  21 00 00 08  sethi  %hi(0x2000), %l0
a007ee34:  90 10 20 00  clr  %o0
a007ee38:  92 10 20 03  mov  3, %o1
a007ee3c:  94 10 00 14  mov  %l4, %o2
a007ee40:  40 00 a1 79  call  0xa00a7424
a007ee44:  96 14 20 70  or  %l0, 0x70, %o3
a007ee48:  27 00 00 09  sethi  %hi(0x2400), %l3
a007ee4c:  90 10 20 00  clr  %o0
a007ee50:  92 10 20 03  mov  3, %o1
a007ee54:  94 10 00 14  mov  %l4, %o2
a007ee58:  40 00 a1 73  call  0xa00a7424
a007ee5c:  96 14 e0 70  or  %l3, 0x70, %o3
a007ee60:  25 00 00 0a  sethi  %hi(0x2800), %l2
a007ee64:  90 10 20 00  clr  %o0
a007ee68:  92 10 20 03  mov  3, %o1
a007ee6c:  94 10 00 14  mov  %l4, %o2
a007ee70:  40 00 a1 6d  call  0xa00a7424
a007ee74:  96 14 a0 70  or  %l2, 0x70, %o3
a007ee78:  23 00 00 0c  sethi  %hi(0x3000), %l1
a007ee7c:  90 10 20 00  clr  %o0
a007ee80:  92 10 20 03  mov  3, %o1
a007ee84:  94 10 00 14  mov  %l4, %o2
a007ee88:  40 00 a1 67  call  0xa00a7424
a007ee8c:  96 14 60 70  or  %l1, 0x70, %o3
a007ee90:  90 10 20 00  clr  %o0
a007ee94:  92 10 20 18  mov  0x18, %o1
a007ee98:  94 10 00 14  mov  %l4, %o2
a007ee9c:  40 00 a1 62  call  0xa00a7424
a007eea0:  96 14 20 28  or  %l0, 0x28, %o3
a007eea4:  96 14 20 28  or  %l0, 0x28, %o3
a007eea8:  90 10 20 00  clr  %o0
a007eeac:  92 10 20 11  mov  0x11, %o1
a007eeb0:  40 00 a1 5d  call  0xa00a7424
a007eeb4:  94 10 00 14  mov  %l4, %o2
a007eeb8:  96 14 e0 28  or  %l3, 0x28, %o3
a007eebc:  90 10 20 00  clr  %o0
a007eec0:  92 10 20 11  mov  0x11, %o1
a007eec4:  40 00 a1 58  call  0xa00a7424
a007eec8:  94 10 00 14  mov  %l4, %o2
a007eecc:  96 14 a0 28  or  %l2, 0x28, %o3
a007eed0:  90 10 20 00  clr  %o0
a007eed4:  92 10 20 11  mov  0x11, %o1
a007eed8:  40 00 a1 53  call  0xa00a7424
a007eedc:  94 10 00 14  mov  %l4, %o2
a007eee0:  96 14 60 28  or  %l1, 0x28, %o3
a007eee4:  90 10 20 00  clr  %o0
a007eee8:  92 10 20 11  mov  0x11, %o1
a007eeec:  40 00 a1 4e  call  0xa00a7424
a007eef0:  94 10 00 14  mov  %l4, %o2
a007eef4:  23 00 00 04  sethi  %hi(0x1000), %l1
a007eef8:  96 14 61 68  or  %l1, 0x168, %o3	! 0x1168
a007eefc:  90 10 20 00  clr  %o0
a007ef00:  92 10 20 0d  mov  0xd, %o1
a007ef04:  40 00 a1 48  call  0xa00a7424
a007ef08:  94 10 00 14  mov  %l4, %o2
a007ef0c:  21 3f f3 ff  sethi  %hi(0xffcffc00), %l0
a007ef10:  92 14 60 20  or  %l1, 0x20, %o1
a007ef14:  94 14 23 ff  or  %l0, 0x3ff, %o2
a007ef18:  90 10 00 14  mov  %l4, %o0
a007ef1c:  40 00 a1 5b  call  0xa00a7488
a007ef20:  17 00 04 00  sethi  %hi(0x100000), %o3
a007ef24:  27 00 00 05  sethi  %hi(0x1400), %l3
a007ef28:  94 14 23 ff  or  %l0, 0x3ff, %o2
a007ef2c:  90 10 00 14  mov  %l4, %o0
a007ef30:  92 14 e0 20  or  %l3, 0x20, %o1
a007ef34:  40 00 a1 55  call  0xa00a7488
a007ef38:  17 00 04 00  sethi  %hi(0x100000), %o3
a007ef3c:  25 00 00 06  sethi  %hi(0x1800), %l2
a007ef40:  94 14 23 ff  or  %l0, 0x3ff, %o2
a007ef44:  90 10 00 14  mov  %l4, %o0
a007ef48:  92 14 a0 20  or  %l2, 0x20, %o1
a007ef4c:  40 00 a1 4f  call  0xa00a7488
a007ef50:  17 00 04 00  sethi  %hi(0x100000), %o3
a007ef54:  90 10 00 14  mov  %l4, %o0
a007ef58:  13 00 00 07  sethi  %hi(0x1c00), %o1
a007ef5c:  94 10 3f 00  mov  -256, %o2
a007ef60:  40 00 a1 4a  call  0xa00a7488
a007ef64:  96 10 20 02  mov  2, %o3
a007ef68:  96 14 61 00  or  %l1, 0x100, %o3
a007ef6c:  90 10 20 01  mov  1, %o0
a007ef70:  92 10 20 15  mov  0x15, %o1
a007ef74:  40 00 a1 2c  call  0xa00a7424
a007ef78:  94 10 00 14  mov  %l4, %o2
a007ef7c:  90 10 20 01  mov  1, %o0
a007ef80:  92 10 20 15  mov  0x15, %o1
a007ef84:  94 10 00 14  mov  %l4, %o2
a007ef88:  40 00 a1 27  call  0xa00a7424
a007ef8c:  96 14 e1 00  or  %l3, 0x100, %o3
a007ef90:  90 10 20 01  mov  1, %o0
a007ef94:  92 10 20 15  mov  0x15, %o1
a007ef98:  94 10 00 14  mov  %l4, %o2
a007ef9c:  40 00 a1 22  call  0xa00a7424
a007efa0:  96 14 a1 00  or  %l2, 0x100, %o3
a007efa4:  15 3f ff c0  sethi  %hi(0xffff0000), %o2
a007efa8:  92 14 61 68  or  %l1, 0x168, %o1
a007efac:  90 10 00 14  mov  %l4, %o0
a007efb0:  94 12 a0 ff  or  %o2, 0xff, %o2
a007efb4:  40 00 a1 35  call  0xa00a7488
a007efb8:  96 10 20 00  clr  %o3
a007efbc:  92 14 60 38  or  %l1, 0x38, %o1
a007efc0:  90 10 00 14  mov  %l4, %o0
a007efc4:  94 10 3f 00  mov  -256, %o2
a007efc8:  40 00 a1 30  call  0xa00a7488
a007efcc:  96 10 20 00  clr  %o3
a007efd0:  2d 00 00 07  sethi  %hi(0x1c00), %l6
a007efd4:  90 10 20 01  mov  1, %o0
a007efd8:  92 10 20 12  mov  0x12, %o1
a007efdc:  94 10 00 14  mov  %l4, %o2
a007efe0:  40 00 a1 11  call  0xa00a7424
a007efe4:  96 15 a3 08  or  %l6, 0x308, %o3
a007efe8:  96 14 61 48  or  %l1, 0x148, %o3
a007efec:  90 10 20 01  mov  1, %o0
a007eff0:  92 10 20 17  mov  0x17, %o1
a007eff4:  40 00 a1 0c  call  0xa00a7424
a007eff8:  94 10 00 14  mov  %l4, %o2
a007effc:  90 10 20 01  mov  1, %o0
a007f000:  92 10 20 17  mov  0x17, %o1
a007f004:  94 10 00 14  mov  %l4, %o2
a007f008:  40 00 a1 07  call  0xa00a7424
a007f00c:  96 14 e1 48  or  %l3, 0x148, %o3
a007f010:  92 10 20 17  mov  0x17, %o1
a007f014:  94 10 00 14  mov  %l4, %o2
a007f018:  96 14 a1 48  or  %l2, 0x148, %o3
a007f01c:  40 00 a1 02  call  0xa00a7424
a007f020:  90 10 20 01  mov  1, %o0
a007f024:  40 00 c9 7a  call  0xa00b160c
a007f028:  90 10 20 0a  mov  0xa, %o0
a007f02c:  96 14 a1 48  or  %l2, 0x148, %o3
a007f030:  90 10 20 00  clr  %o0
a007f034:  92 10 20 17  mov  0x17, %o1
a007f038:  40 00 a0 fb  call  0xa00a7424
a007f03c:  94 10 00 14  mov  %l4, %o2
a007f040:  96 14 e1 48  or  %l3, 0x148, %o3
a007f044:  90 10 20 00  clr  %o0
a007f048:  92 10 20 17  mov  0x17, %o1
a007f04c:  40 00 a0 f6  call  0xa00a7424
a007f050:  94 10 00 14  mov  %l4, %o2
a007f054:  96 14 61 48  or  %l1, 0x148, %o3
a007f058:  90 10 20 00  clr  %o0
a007f05c:  92 10 20 17  mov  0x17, %o1
a007f060:  40 00 a0 f1  call  0xa00a7424
a007f064:  94 10 00 14  mov  %l4, %o2
a007f068:  92 10 20 12  mov  0x12, %o1
a007f06c:  94 10 00 14  mov  %l4, %o2
a007f070:  96 15 a3 08  or  %l6, 0x308, %o3
a007f074:  40 00 a0 ec  call  0xa00a7424
a007f078:  90 10 20 00  clr  %o0
a007f07c:  82 05 00 14  add  %l4, %l4, %g1
a007f080:  82 00 40 14  add  %g1, %l4, %g1
a007f084:  23 2a 01 f3  sethi  %hi(0xa807cc00), %l1
a007f088:  83 28 60 03  sll  %g1, 3, %g1
a007f08c:  9a 14 60 64  or  %l1, 0x64, %o5
a007f090:  a0 00 40 0d  add  %g1, %o5, %l0
a007f094:  7f ff d7 b3  call  0xa0074f60
a007f098:  90 10 00 14  mov  %l4, %o0
a007f09c:  d0 34 20 0a  sth  %o0, [ %l0 + 0xa ]
a007f0a0:  7f ff d8 37  call  0xa007517c
a007f0a4:  90 10 00 14  mov  %l4, %o0
a007f0a8:  80 8a 20 ff  btst  0xff, %o0
a007f0ac:  02 80 00 16  be  0xa007f104
a007f0b0:  c2 05 e2 34  ld  [ %l7 + 0x234 ], %g1
a007f0b4:  80 88 60 02  btst  2, %g1
a007f0b8:  02 80 00 88  be  0xa007f2d8
a007f0bc:  a0 0d 60 ff  and  %l5, 0xff, %l0
a007f0c0:  92 06 20 41  add  %i0, 0x41, %o1
a007f0c4:  93 2a 60 18  sll  %o1, 0x18, %o1
a007f0c8:  11 28 01 a0  sethi  %hi(0xa0068000), %o0
a007f0cc:  90 12 22 88  or  %o0, 0x288, %o0	! 0xa0068288
a007f0d0:  7f ff cf dd  call  0xa0073044
a007f0d4:  93 3a 60 18  sra  %o1, 0x18, %o1
a007f0d8:  c2 05 e2 34  ld  [ %l7 + 0x234 ], %g1
a007f0dc:  80 88 60 02  btst  2, %g1
a007f0e0:  02 80 00 7d  be  0xa007f2d4
a007f0e4:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a007f0e8:  92 06 20 41  add  %i0, 0x41, %o1
a007f0ec:  82 10 61 78  or  %g1, 0x178, %g1
a007f0f0:  11 28 01 a0  sethi  %hi(0xa0068000), %o0
a007f0f4:  93 2a 60 18  sll  %o1, 0x18, %o1
a007f0f8:  d4 08 40 14  ldub  [ %g1 + %l4 ], %o2
a007f0fc:  10 80 00 5a  b  0xa007f264
a007f100:  90 12 22 b0  or  %o0, 0x2b0, %o0
a007f104:  7f ff ef 80  call  0xa007af04
a007f108:  90 10 00 14  mov  %l4, %o0
a007f10c:  80 8a 20 ff  btst  0xff, %o0
a007f110:  12 80 00 59  bne  0xa007f274
a007f114:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a007f118:  7f ff ef 95  call  0xa007af6c
a007f11c:  90 10 00 14  mov  %l4, %o0
a007f120:  80 8a 20 ff  btst  0xff, %o0
a007f124:  12 80 00 54  bne  0xa007f274
a007f128:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a007f12c:  c2 0c 20 07  ldub  [ %l0 + 7 ], %g1
a007f130:  80 a0 60 01  cmp  %g1, 1
a007f134:  02 80 00 50  be  0xa007f274
a007f138:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a007f13c:  c2 14 20 0a  lduh  [ %l0 + 0xa ], %g1
a007f140:  80 a0 60 4a  cmp  %g1, 0x4a
a007f144:  28 80 00 4c  bleu,a   0xa007f274
a007f148:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a007f14c:  80 a0 60 96  cmp  %g1, 0x96
a007f150:  18 80 00 49  bgu  0xa007f274
a007f154:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a007f158:  1b 2a 01 e2  sethi  %hi(0xa8078800), %o5
a007f15c:  82 10 20 01  mov  1, %g1
a007f160:  9a 13 61 80  or  %o5, 0x180, %o5
a007f164:  c2 2b 40 14  stb  %g1, [ %o5 + %l4 ]
a007f168:  90 10 00 14  mov  %l4, %o0
a007f16c:  7f ff fe e8  call  0xa007ed0c
a007f170:  92 10 20 00  clr  %o1
a007f174:  c2 05 e2 34  ld  [ %l7 + 0x234 ], %g1
a007f178:  80 88 60 02  btst  2, %g1
a007f17c:  02 80 00 0c  be  0xa007f1ac
a007f180:  90 10 20 10  mov  0x10, %o0
a007f184:  92 06 20 41  add  %i0, 0x41, %o1
a007f188:  03 2a 01 d8  sethi  %hi(0xa8076000), %g1
a007f18c:  93 2a 60 18  sll  %o1, 0x18, %o1
a007f190:  11 28 01 a0  sethi  %hi(0xa0068000), %o0
a007f194:  82 10 61 98  or  %g1, 0x198, %g1
a007f198:  90 12 22 e8  or  %o0, 0x2e8, %o0
a007f19c:  93 3a 60 18  sra  %o1, 0x18, %o1
a007f1a0:  7f ff cf a9  call  0xa0073044
a007f1a4:  d4 08 40 14  ldub  [ %g1 + %l4 ], %o2
a007f1a8:  90 10 20 10  mov  0x10, %o0
a007f1ac:  92 10 00 14  mov  %l4, %o1
a007f1b0:  40 00 a0 ae  call  0xa00a7468
a007f1b4:  94 15 a2 94  or  %l6, 0x294, %o2
a007f1b8:  80 a2 20 00  cmp  %o0, 0
a007f1bc:  12 80 00 20  bne  0xa007f23c
a007f1c0:  c2 05 e2 34  ld  [ %l7 + 0x234 ], %g1
a007f1c4:  90 10 20 11  mov  0x11, %o0
a007f1c8:  92 10 00 14  mov  %l4, %o1
a007f1cc:  40 00 a0 a7  call  0xa00a7468
a007f1d0:  94 15 a2 94  or  %l6, 0x294, %o2
a007f1d4:  80 a2 20 00  cmp  %o0, 0
a007f1d8:  12 80 00 19  bne  0xa007f23c
a007f1dc:  c2 05 e2 34  ld  [ %l7 + 0x234 ], %g1
a007f1e0:  94 15 a2 94  or  %l6, 0x294, %o2
a007f1e4:  90 10 20 12  mov  0x12, %o0
a007f1e8:  40 00 a0 a0  call  0xa00a7468
a007f1ec:  92 10 00 14  mov  %l4, %o1
a007f1f0:  80 a2 20 00  cmp  %o0, 0
a007f1f4:  12 80 00 12  bne  0xa007f23c
a007f1f8:  c2 05 e2 34  ld  [ %l7 + 0x234 ], %g1
a007f1fc:  03 2a 01 d8  sethi  %hi(0xa8076000), %g1
a007f200:  82 10 61 98  or  %g1, 0x198, %g1	! 0xa8076198
a007f204:  da 08 40 14  ldub  [ %g1 + %l4 ], %o5
a007f208:  9a 38 00 0d  xnor  %g0, %o5, %o5
a007f20c:  9a 0b 60 01  and  %o5, 1, %o5
a007f210:  d8 05 e2 34  ld  [ %l7 + 0x234 ], %o4
a007f214:  80 8b 20 02  btst  2, %o4
a007f218:  02 80 00 2f  be  0xa007f2d4
a007f21c:  da 28 40 14  stb  %o5, [ %g1 + %l4 ]
a007f220:  92 06 20 41  add  %i0, 0x41, %o1
a007f224:  93 2a 60 18  sll  %o1, 0x18, %o1
a007f228:  11 28 01 a0  sethi  %hi(0xa0068000), %o0
a007f22c:  90 12 23 28  or  %o0, 0x328, %o0	! 0xa0068328
a007f230:  7f ff cf 85  call  0xa0073044
a007f234:  93 3a 60 18  sra  %o1, 0x18, %o1
a007f238:  c2 05 e2 34  ld  [ %l7 + 0x234 ], %g1
a007f23c:  80 88 60 02  btst  2, %g1
a007f240:  22 80 00 26  be,a   0xa007f2d8
a007f244:  a0 0d 60 ff  and  %l5, 0xff, %l0
a007f248:  03 2a 01 d8  sethi  %hi(0xa8076000), %g1
a007f24c:  92 05 60 41  add  %l5, 0x41, %o1
a007f250:  82 10 61 98  or  %g1, 0x198, %g1
a007f254:  11 28 01 a0  sethi  %hi(0xa0068000), %o0
a007f258:  93 2a 60 18  sll  %o1, 0x18, %o1
a007f25c:  d4 08 40 14  ldub  [ %g1 + %l4 ], %o2
a007f260:  90 12 23 58  or  %o0, 0x358, %o0
a007f264:  7f ff cf 78  call  0xa0073044
a007f268:  93 3a 60 18  sra  %o1, 0x18, %o1
a007f26c:  10 80 00 1b  b  0xa007f2d8
a007f270:  a0 0d 60 ff  and  %l5, 0xff, %l0
a007f274:  82 10 61 80  or  %g1, 0x180, %g1
a007f278:  c0 28 40 14  clrb  [ %g1 + %l4 ]
a007f27c:  90 10 20 02  mov  2, %o0
a007f280:  80 a5 20 02  cmp  %l4, 2
a007f284:  02 80 00 08  be  0xa007f2a4
a007f288:  92 10 20 00  clr  %o1
a007f28c:  90 10 00 14  mov  %l4, %o0
a007f290:  92 10 20 00  clr  %o1
a007f294:  7f ff fe 67  call  0xa007ec30
a007f298:  94 10 20 00  clr  %o2
a007f29c:  90 10 00 14  mov  %l4, %o0
a007f2a0:  92 10 20 01  mov  1, %o1
a007f2a4:  7f ff fe 9a  call  0xa007ed0c
a007f2a8:  01 00 00 00  nop
a007f2ac:  c2 05 e2 34  ld  [ %l7 + 0x234 ], %g1
a007f2b0:  80 88 60 02  btst  2, %g1
a007f2b4:  02 80 00 09  be  0xa007f2d8
a007f2b8:  a0 0d 60 ff  and  %l5, 0xff, %l0
a007f2bc:  92 05 60 41  add  %l5, 0x41, %o1
a007f2c0:  93 2a 60 18  sll  %o1, 0x18, %o1
a007f2c4:  11 28 01 a0  sethi  %hi(0xa0068000), %o0
a007f2c8:  90 12 23 90  or  %o0, 0x390, %o0	! 0xa0068390
a007f2cc:  7f ff cf 5e  call  0xa0073044
a007f2d0:  93 3a 60 18  sra  %o1, 0x18, %o1
a007f2d4:  a0 0d 60 ff  and  %l5, 0xff, %l0
a007f2d8:  7f ff d7 a9  call  0xa007517c
a007f2dc:  90 10 00 10  mov  %l0, %o0
a007f2e0:  80 8a 20 ff  btst  0xff, %o0
a007f2e4:  02 80 00 21  be  0xa007f368
a007f2e8:  90 10 00 10  mov  %l0, %o0
a007f2ec:  7f ff fe 88  call  0xa007ed0c
a007f2f0:  92 10 20 00  clr  %o1
a007f2f4:  90 10 00 10  mov  %l0, %o0
a007f2f8:  92 10 20 01  mov  1, %o1
a007f2fc:  80 a4 20 02  cmp  %l0, 2
a007f300:  12 80 00 05  bne  0xa007f314
a007f304:  94 10 20 00  clr  %o2
a007f308:  90 10 20 02  mov  2, %o0
a007f30c:  92 10 20 01  mov  1, %o1
a007f310:  94 10 20 01  mov  1, %o2
a007f314:  7f ff fe 47  call  0xa007ec30
a007f318:  01 00 00 00  nop
a007f31c:  82 04 00 10  add  %l0, %l0, %g1
a007f320:  82 00 40 10  add  %g1, %l0, %g1
a007f324:  9a 14 60 64  or  %l1, 0x64, %o5
a007f328:  83 28 60 03  sll  %g1, 3, %g1
a007f32c:  82 00 40 0d  add  %g1, %o5, %g1
a007f330:  1b 2a 01 e1  sethi  %hi(0xa8078400), %o5
a007f334:  da 03 62 34  ld  [ %o5 + 0x234 ], %o5	! 0xa8078634
a007f338:  d4 10 60 0a  lduh  [ %g1 + 0xa ], %o2
a007f33c:  80 8b 60 02  btst  2, %o5
a007f340:  02 80 00 65  be  0xa007f4d4
a007f344:  d4 30 60 08  sth  %o2, [ %g1 + 8 ]
a007f348:  92 05 60 41  add  %l5, 0x41, %o1
a007f34c:  93 2a 60 18  sll  %o1, 0x18, %o1
a007f350:  95 2a a0 10  sll  %o2, 0x10, %o2
a007f354:  11 28 01 a0  sethi  %hi(0xa0068000), %o0
a007f358:  90 12 23 d0  or  %o0, 0x3d0, %o0	! 0xa00683d0
a007f35c:  93 3a 60 18  sra  %o1, 0x18, %o1
a007f360:  10 80 00 5b  b  0xa007f4cc
a007f364:  95 32 a0 10  srl  %o2, 0x10, %o2
a007f368:  7f ff ef ce  call  0xa007b2a0
a007f36c:  90 10 00 10  mov  %l0, %o0
a007f370:  90 0a 20 ff  and  %o0, 0xff, %o0
a007f374:  80 a2 20 01  cmp  %o0, 1
a007f378:  19 2a 01 e2  sethi  %hi(0xa8078800), %o4
a007f37c:  12 80 00 2b  bne  0xa007f428
a007f380:  82 04 00 10  add  %l0, %l0, %g1
a007f384:  9a 00 40 10  add  %g1, %l0, %o5
a007f388:  82 14 60 64  or  %l1, 0x64, %g1
a007f38c:  9b 2b 60 03  sll  %o5, 3, %o5
a007f390:  9a 03 40 01  add  %o5, %g1, %o5
a007f394:  98 13 21 80  or  %o4, 0x180, %o4
a007f398:  c2 13 60 0a  lduh  [ %o5 + 0xa ], %g1
a007f39c:  d8 0b 00 10  ldub  [ %o4 + %l0 ], %o4
a007f3a0:  83 28 60 02  sll  %g1, 2, %g1
a007f3a4:  80 a3 20 01  cmp  %o4, 1
a007f3a8:  12 80 00 11  bne  0xa007f3ec
a007f3ac:  c2 33 60 08  sth  %g1, [ %o5 + 8 ]
a007f3b0:  90 10 00 10  mov  %l0, %o0
a007f3b4:  92 10 20 01  mov  1, %o1
a007f3b8:  7f ff fe 1e  call  0xa007ec30
a007f3bc:  94 10 20 01  mov  1, %o2
a007f3c0:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a007f3c4:  c2 00 62 34  ld  [ %g1 + 0x234 ], %g1	! 0xa8078634
a007f3c8:  80 88 60 02  btst  2, %g1
a007f3cc:  22 80 00 43  be,a   0xa007f4d8
a007f3d0:  a0 0d 60 ff  and  %l5, 0xff, %l0
a007f3d4:  92 05 60 41  add  %l5, 0x41, %o1
a007f3d8:  93 2a 60 18  sll  %o1, 0x18, %o1
a007f3dc:  11 28 01 a0  sethi  %hi(0xa0068000), %o0
a007f3e0:  90 12 23 f0  or  %o0, 0x3f0, %o0	! 0xa00683f0
a007f3e4:  7f ff cf 18  call  0xa0073044
a007f3e8:  93 3a 60 18  sra  %o1, 0x18, %o1
a007f3ec:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a007f3f0:  c2 00 62 34  ld  [ %g1 + 0x234 ], %g1	! 0xa8078634
a007f3f4:  80 88 60 02  btst  2, %g1
a007f3f8:  22 80 00 38  be,a   0xa007f4d8
a007f3fc:  a0 0d 60 ff  and  %l5, 0xff, %l0
a007f400:  82 04 00 10  add  %l0, %l0, %g1
a007f404:  82 00 40 10  add  %g1, %l0, %g1
a007f408:  9a 14 60 64  or  %l1, 0x64, %o5
a007f40c:  83 28 60 03  sll  %g1, 3, %g1
a007f410:  92 05 60 41  add  %l5, 0x41, %o1
a007f414:  11 28 01 a1  sethi  %hi(0xa0068400), %o0
a007f418:  82 00 40 0d  add  %g1, %o5, %g1
a007f41c:  93 2a 60 18  sll  %o1, 0x18, %o1
a007f420:  10 80 00 29  b  0xa007f4c4
a007f424:  90 12 20 20  or  %o0, 0x20, %o0
a007f428:  82 00 40 10  add  %g1, %l0, %g1
a007f42c:  9a 14 60 64  or  %l1, 0x64, %o5
a007f430:  83 28 60 03  sll  %g1, 3, %g1
a007f434:  82 00 40 0d  add  %g1, %o5, %g1
a007f438:  9a 13 21 80  or  %o4, 0x180, %o5
a007f43c:  d8 0b 40 10  ldub  [ %o5 + %l0 ], %o4
a007f440:  da 10 60 0a  lduh  [ %g1 + 0xa ], %o5
a007f444:  80 a3 20 01  cmp  %o4, 1
a007f448:  12 80 00 11  bne  0xa007f48c
a007f44c:  da 30 60 08  sth  %o5, [ %g1 + 8 ]
a007f450:  90 10 00 10  mov  %l0, %o0
a007f454:  92 10 20 00  clr  %o1
a007f458:  7f ff fd f6  call  0xa007ec30
a007f45c:  94 10 20 00  clr  %o2
a007f460:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a007f464:  c2 00 62 34  ld  [ %g1 + 0x234 ], %g1	! 0xa8078634
a007f468:  80 88 60 02  btst  2, %g1
a007f46c:  22 80 00 1b  be,a   0xa007f4d8
a007f470:  a0 0d 60 ff  and  %l5, 0xff, %l0
a007f474:  92 05 60 41  add  %l5, 0x41, %o1
a007f478:  93 2a 60 18  sll  %o1, 0x18, %o1
a007f47c:  11 28 01 a1  sethi  %hi(0xa0068400), %o0
a007f480:  90 12 20 40  or  %o0, 0x40, %o0	! 0xa0068440
a007f484:  7f ff ce f0  call  0xa0073044
a007f488:  93 3a 60 18  sra  %o1, 0x18, %o1
a007f48c:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a007f490:  c2 00 62 34  ld  [ %g1 + 0x234 ], %g1	! 0xa8078634
a007f494:  80 88 60 02  btst  2, %g1
a007f498:  22 80 00 10  be,a   0xa007f4d8
a007f49c:  a0 0d 60 ff  and  %l5, 0xff, %l0
a007f4a0:  82 04 00 10  add  %l0, %l0, %g1
a007f4a4:  82 00 40 10  add  %g1, %l0, %g1
a007f4a8:  9a 14 60 64  or  %l1, 0x64, %o5
a007f4ac:  83 28 60 03  sll  %g1, 3, %g1
a007f4b0:  92 05 60 41  add  %l5, 0x41, %o1
a007f4b4:  11 28 01 a0  sethi  %hi(0xa0068000), %o0
a007f4b8:  82 00 40 0d  add  %g1, %o5, %g1
a007f4bc:  93 2a 60 18  sll  %o1, 0x18, %o1
a007f4c0:  90 12 23 d0  or  %o0, 0x3d0, %o0
a007f4c4:  93 3a 60 18  sra  %o1, 0x18, %o1
a007f4c8:  d4 10 60 08  lduh  [ %g1 + 8 ], %o2
a007f4cc:  7f ff ce de  call  0xa0073044
a007f4d0:  01 00 00 00  nop
a007f4d4:  a0 0d 60 ff  and  %l5, 0xff, %l0
a007f4d8:  7f ff f6 df  call  0xa007d054
a007f4dc:  90 10 00 10  mov  %l0, %o0
a007f4e0:  80 8a 20 ff  btst  0xff, %o0
a007f4e4:  02 80 00 1c  be  0xa007f554
a007f4e8:  80 a4 20 02  cmp  %l0, 2
a007f4ec:  12 80 00 09  bne  0xa007f510
a007f4f0:  03 2a 01 f6  sethi  %hi(0xa807d800), %g1
a007f4f4:  d8 00 63 0c  ld  [ %g1 + 0x30c ], %o4	! 0xa807db0c
a007f4f8:  da 03 20 74  ld  [ %o4 + 0x74 ], %o5
a007f4fc:  03 00 01 c0  sethi  %hi(0x70000), %g1
a007f500:  82 2b 40 01  andn  %o5, %g1, %g1
a007f504:  1b 00 01 40  sethi  %hi(0x50000), %o5
a007f508:  82 10 40 0d  or  %g1, %o5, %g1
a007f50c:  c2 23 20 74  st  %g1, [ %o4 + 0x74 ]
a007f510:  7f ff fd b0  call  0xa007ebd0
a007f514:  90 10 00 10  mov  %l0, %o0
a007f518:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a007f51c:  c2 00 62 34  ld  [ %g1 + 0x234 ], %g1	! 0xa8078634
a007f520:  80 88 60 02  btst  2, %g1
a007f524:  22 80 00 15  be,a   0xa007f578
a007f528:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a007f52c:  92 05 60 41  add  %l5, 0x41, %o1
a007f530:  93 2a 60 18  sll  %o1, 0x18, %o1
a007f534:  11 28 01 a1  sethi  %hi(0xa0068400), %o0
a007f538:  15 28 02 cf  sethi  %hi(0xa00b3c00), %o2
a007f53c:  93 3a 60 18  sra  %o1, 0x18, %o1
a007f540:  94 12 a3 20  or  %o2, 0x320, %o2
a007f544:  7f ff ce c0  call  0xa0073044
a007f548:  90 12 20 70  or  %o0, 0x70, %o0
a007f54c:  10 80 00 0b  b  0xa007f578
a007f550:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a007f554:  12 80 00 09  bne  0xa007f578
a007f558:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a007f55c:  03 2a 01 f6  sethi  %hi(0xa807d800), %g1
a007f560:  d8 00 63 0c  ld  [ %g1 + 0x30c ], %o4	! 0xa807db0c
a007f564:  da 03 20 74  ld  [ %o4 + 0x74 ], %o5
a007f568:  03 00 01 c0  sethi  %hi(0x70000), %g1
a007f56c:  82 2b 40 01  andn  %o5, %g1, %g1
a007f570:  c2 23 20 74  st  %g1, [ %o4 + 0x74 ]
a007f574:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a007f578:  82 10 61 98  or  %g1, 0x198, %g1	! 0xa8078998
a007f57c:  c2 08 40 10  ldub  [ %g1 + %l0 ], %g1
a007f580:  80 a0 60 00  cmp  %g1, 0
a007f584:  12 80 00 1b  bne  0xa007f5f0
a007f588:  9a 04 00 10  add  %l0, %l0, %o5
a007f58c:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a007f590:  c2 00 62 34  ld  [ %g1 + 0x234 ], %g1	! 0xa8078634
a007f594:  80 88 60 02  btst  2, %g1
a007f598:  02 80 00 06  be  0xa007f5b0
a007f59c:  82 04 00 10  add  %l0, %l0, %g1
a007f5a0:  11 28 01 a1  sethi  %hi(0xa0068400), %o0
a007f5a4:  7f ff cf c8  call  0xa00734c4
a007f5a8:  90 12 20 98  or  %o0, 0x98, %o0	! 0xa0068498
a007f5ac:  82 04 00 10  add  %l0, %l0, %g1
a007f5b0:  82 00 40 10  add  %g1, %l0, %g1
a007f5b4:  11 2a 01 f3  sethi  %hi(0xa807cc00), %o0
a007f5b8:  83 28 60 02  sll  %g1, 2, %g1
a007f5bc:  90 12 20 c4  or  %o0, 0xc4, %o0
a007f5c0:  90 00 40 08  add  %g1, %o0, %o0
a007f5c4:  92 10 20 00  clr  %o1
a007f5c8:  40 00 c7 f9  call  0xa00b15ac
a007f5cc:  94 10 20 0c  mov  0xc, %o2
a007f5d0:  11 2a 01 ea  sethi  %hi(0xa807a800), %o0
a007f5d4:  82 5c 28 98  smul  %l0, 0x898, %g1
a007f5d8:  90 12 21 f0  or  %o0, 0x1f0, %o0
a007f5dc:  90 00 40 08  add  %g1, %o0, %o0
a007f5e0:  92 10 20 00  clr  %o1
a007f5e4:  40 00 c7 f2  call  0xa00b15ac
a007f5e8:  94 10 28 98  mov  0x898, %o2
a007f5ec:  9a 04 00 10  add  %l0, %l0, %o5
a007f5f0:  03 2a 01 ea  sethi  %hi(0xa807a800), %g1
a007f5f4:  82 10 61 f0  or  %g1, 0x1f0, %g1	! 0xa807a9f0
a007f5f8:  9a 03 40 10  add  %o5, %l0, %o5
a007f5fc:  19 2a 01 f3  sethi  %hi(0xa807cc00), %o4
a007f600:  96 5c 28 98  smul  %l0, 0x898, %o3
a007f604:  98 13 20 c4  or  %o4, 0xc4, %o4
a007f608:  9b 2b 60 02  sll  %o5, 2, %o5
a007f60c:  96 02 c0 01  add  %o3, %g1, %o3
a007f610:  82 10 20 01  mov  1, %g1
a007f614:  94 03 40 0c  add  %o5, %o4, %o2
a007f618:  c2 23 00 0d  st  %g1, [ %o4 + %o5 ]
a007f61c:  c0 2a a0 07  clrb  [ %o2 + 7 ]
a007f620:  c0 2a e0 30  clrb  [ %o3 + 0x30 ]
a007f624:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a007f628:  c0 28 61 8c  clrb  [ %g1 + 0x18c ]	! 0xa807898c
a007f62c:  81 c7 e0 08  ret
a007f630:  91 e8 20 01  restore  %g0, 1, %o0
