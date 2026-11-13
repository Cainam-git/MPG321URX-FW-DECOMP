# leon2s DRV_HDMI21_RXDetect_FSM_LTS_Chk_Err 0xa009ec38-0xa009f5c8 (2448 bytes)
a009ec38:  9d e3 bf 98  save  %sp, -104, %sp
a009ec3c:  a2 0e 20 ff  and  %i0, 0xff, %l1
a009ec40:  80 a4 60 00  cmp  %l1, 0
a009ec44:  02 80 00 05  be  0xa009ec58
a009ec48:  ba 10 20 02  mov  2, %i5
a009ec4c:  80 a4 60 01  cmp  %l1, 1
a009ec50:  12 80 02 5c  bne  0xa009f5c0
a009ec54:  ba 10 20 03  mov  3, %i5
a009ec58:  29 2a 01 f5  sethi  %hi(0xa807d400), %l4
a009ec5c:  9a 15 22 80  or  %l4, 0x280, %o5	! 0xa807d680
a009ec60:  82 5c 60 b0  smul  %l1, 0xb0, %g1
a009ec64:  2d 2a 01 f5  sethi  %hi(0xa807d400), %l6
a009ec68:  a0 00 40 0d  add  %g1, %o5, %l0
a009ec6c:  a6 15 a2 48  or  %l6, 0x248, %l3
a009ec70:  a5 2c 60 02  sll  %l1, 2, %l2
a009ec74:  da 04 c0 12  ld  [ %l3 + %l2 ], %o5
a009ec78:  c2 04 20 30  ld  [ %l0 + 0x30 ], %g1
a009ec7c:  80 a3 40 01  cmp  %o5, %g1
a009ec80:  02 80 00 0d  be  0xa009ecb4
a009ec84:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a009ec88:  c2 00 62 34  ld  [ %g1 + 0x234 ], %g1	! 0xa8078634
a009ec8c:  80 88 68 00  btst  0x800, %g1
a009ec90:  22 80 00 08  be,a   0xa009ecb0
a009ec94:  c2 04 c0 12  ld  [ %l3 + %l2 ], %g1
a009ec98:  11 28 01 9e  sethi  %hi(0xa0067800), %o0
a009ec9c:  13 28 02 d1  sethi  %hi(0xa00b4400), %o1
a009eca0:  90 12 20 68  or  %o0, 0x68, %o0
a009eca4:  7f ff 50 e8  call  0xa0073044
a009eca8:  92 12 61 30  or  %o1, 0x130, %o1
a009ecac:  c2 04 c0 12  ld  [ %l3 + %l2 ], %g1
a009ecb0:  c2 24 20 30  st  %g1, [ %l0 + 0x30 ]
a009ecb4:  27 2a 01 f6  sethi  %hi(0xa807d800), %l3
a009ecb8:  9a 14 e3 00  or  %l3, 0x300, %o5	! 0xa807db00
a009ecbc:  82 5c 60 34  smul  %l1, 0x34, %g1
a009ecc0:  82 00 40 0d  add  %g1, %o5, %g1
a009ecc4:  d2 00 60 18  ld  [ %g1 + 0x18 ], %o1
a009ecc8:  c2 02 60 90  ld  [ %o1 + 0x90 ], %g1
a009eccc:  83 30 60 18  srl  %g1, 0x18, %g1
a009ecd0:  80 88 60 0f  btst  0xf, %g1
a009ecd4:  12 80 00 32  bne  0xa009ed9c
a009ecd8:  82 0e 20 ff  and  %i0, 0xff, %g1
a009ecdc:  82 58 60 34  smul  %g1, 0x34, %g1
a009ece0:  98 00 40 0d  add  %g1, %o5, %o4
a009ece4:  03 3c 3f ff  sethi  %hi(0xf0fffc00), %g1
a009ece8:  92 10 63 ff  or  %g1, 0x3ff, %o1	! 0xf0ffffff
a009ecec:  03 03 ff ff  sethi  %hi(0xffffc00), %g1
a009ecf0:  94 10 63 ff  or  %g1, 0x3ff, %o2	! 0xfffffff
a009ecf4:  96 10 20 00  clr  %o3
a009ecf8:  82 0a e0 ff  and  %o3, 0xff, %g1
a009ecfc:  80 a0 60 00  cmp  %g1, 0
a009ed00:  12 80 00 06  bne  0xa009ed18
a009ed04:  80 a0 60 01  cmp  %g1, 1
a009ed08:  da 03 20 18  ld  [ %o4 + 0x18 ], %o5
a009ed0c:  c2 03 60 a0  ld  [ %o5 + 0xa0 ], %g1
a009ed10:  10 80 00 07  b  0xa009ed2c
a009ed14:  82 08 40 09  and  %g1, %o1, %g1
a009ed18:  12 80 00 08  bne  0xa009ed38
a009ed1c:  80 a0 60 02  cmp  %g1, 2
a009ed20:  da 03 20 18  ld  [ %o4 + 0x18 ], %o5
a009ed24:  c2 03 60 a0  ld  [ %o5 + 0xa0 ], %g1
a009ed28:  82 08 40 0a  and  %g1, %o2, %g1
a009ed2c:  c2 23 60 a0  st  %g1, [ %o5 + 0xa0 ]
a009ed30:  10 80 00 0f  b  0xa009ed6c
a009ed34:  96 02 e0 01  inc  %o3
a009ed38:  12 80 00 06  bne  0xa009ed50
a009ed3c:  80 a0 60 03  cmp  %g1, 3
a009ed40:  da 03 20 18  ld  [ %o4 + 0x18 ], %o5
a009ed44:  c2 03 60 a4  ld  [ %o5 + 0xa4 ], %g1
a009ed48:  10 80 00 07  b  0xa009ed64
a009ed4c:  82 08 7f f0  and  %g1, -16, %g1
a009ed50:  32 80 00 07  bne,a   0xa009ed6c
a009ed54:  96 02 e0 01  inc  %o3
a009ed58:  da 03 20 18  ld  [ %o4 + 0x18 ], %o5
a009ed5c:  c2 03 60 a4  ld  [ %o5 + 0xa4 ], %g1
a009ed60:  82 08 7f 0f  and  %g1, -241, %g1
a009ed64:  c2 23 60 a4  st  %g1, [ %o5 + 0xa4 ]
a009ed68:  96 02 e0 01  inc  %o3
a009ed6c:  82 0a e0 ff  and  %o3, 0xff, %g1
a009ed70:  80 a0 60 03  cmp  %g1, 3
a009ed74:  08 bf ff e3  bleu  0xa009ed00
a009ed78:  80 a0 60 00  cmp  %g1, 0
a009ed7c:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a009ed80:  c2 00 62 34  ld  [ %g1 + 0x234 ], %g1	! 0xa8078634
a009ed84:  11 28 01 ac  sethi  %hi(0xa006b000), %o0
a009ed88:  80 88 68 00  btst  0x800, %g1
a009ed8c:  12 80 00 8b  bne  0xa009efb8
a009ed90:  90 12 20 10  or  %o0, 0x10, %o0
a009ed94:  10 80 00 8c  b  0xa009efc4
a009ed98:  82 0e 20 ff  and  %i0, 0xff, %g1
a009ed9c:  92 02 60 80  add  %o1, 0x80, %o1
a009eda0:  40 00 21 9a  call  0xa00a7408
a009eda4:  90 10 20 05  mov  5, %o0
a009eda8:  80 a2 20 00  cmp  %o0, 0
a009edac:  12 80 00 0c  bne  0xa009eddc
a009edb0:  21 2a 01 e4  sethi  %hi(0xa8079000), %l0
a009edb4:  2b 2a 01 e1  sethi  %hi(0xa8078400), %l5
a009edb8:  c2 05 62 34  ld  [ %l5 + 0x234 ], %g1	! 0xa8078634
a009edbc:  80 88 68 00  btst  0x800, %g1
a009edc0:  02 80 00 48  be  0xa009eee0
a009edc4:  2f 2a 01 f6  sethi  %hi(0xa807d800), %l7
a009edc8:  11 28 01 ac  sethi  %hi(0xa006b000), %o0
a009edcc:  7f ff 51 be  call  0xa00734c4
a009edd0:  90 12 20 48  or  %o0, 0x48, %o0	! 0xa006b048
a009edd4:  10 80 00 35  b  0xa009eea8
a009edd8:  c2 05 62 34  ld  [ %l5 + 0x234 ], %g1
a009eddc:  82 14 20 8a  or  %l0, 0x8a, %g1
a009ede0:  9a 04 40 11  add  %l1, %l1, %o5
a009ede4:  c2 10 40 0d  lduh  [ %g1 + %o5 ], %g1
a009ede8:  80 a0 60 00  cmp  %g1, 0
a009edec:  12 80 00 0b  bne  0xa009ee18
a009edf0:  a4 14 20 8a  or  %l0, 0x8a, %l2
a009edf4:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a009edf8:  c2 00 62 34  ld  [ %g1 + 0x234 ], %g1	! 0xa8078634
a009edfc:  80 88 68 00  btst  0x800, %g1
a009ee00:  22 80 00 07  be,a   0xa009ee1c
a009ee04:  a0 04 40 11  add  %l1, %l1, %l0
a009ee08:  11 28 01 ac  sethi  %hi(0xa006b000), %o0
a009ee0c:  7f ff 51 ae  call  0xa00734c4
a009ee10:  90 12 20 70  or  %o0, 0x70, %o0	! 0xa006b070
a009ee14:  a4 14 20 8a  or  %l0, 0x8a, %l2
a009ee18:  a0 04 40 11  add  %l1, %l1, %l0
a009ee1c:  da 14 80 10  lduh  [ %l2 + %l0 ], %o5
a009ee20:  9a 03 60 01  inc  %o5
a009ee24:  83 2b 60 10  sll  %o5, 0x10, %g1
a009ee28:  83 30 60 10  srl  %g1, 0x10, %g1
a009ee2c:  80 a0 61 2b  cmp  %g1, 0x12b
a009ee30:  08 80 01 e4  bleu  0xa009f5c0
a009ee34:  da 34 80 10  sth  %o5, [ %l2 + %l0 ]
a009ee38:  82 14 e3 00  or  %l3, 0x300, %g1
a009ee3c:  9a 5c 60 34  smul  %l1, 0x34, %o5
a009ee40:  9a 03 40 01  add  %o5, %g1, %o5
a009ee44:  d2 03 60 18  ld  [ %o5 + 0x18 ], %o1
a009ee48:  c0 34 80 10  clrh  [ %l2 + %l0 ]
a009ee4c:  92 02 60 90  add  %o1, 0x90, %o1
a009ee50:  40 00 21 6e  call  0xa00a7408
a009ee54:  90 10 20 11  mov  0x11, %o0
a009ee58:  80 a2 20 00  cmp  %o0, 0
a009ee5c:  02 80 00 06  be  0xa009ee74
a009ee60:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a009ee64:  11 28 01 a7  sethi  %hi(0xa0069c00), %o0
a009ee68:  7f ff 51 97  call  0xa00734c4
a009ee6c:  90 12 20 a8  or  %o0, 0xa8, %o0	! 0xa0069ca8
a009ee70:  30 80 01 d4  b,a   0xa009f5c0
a009ee74:  c2 00 62 34  ld  [ %g1 + 0x234 ], %g1
a009ee78:  80 88 68 00  btst  0x800, %g1
a009ee7c:  02 80 00 08  be  0xa009ee9c
a009ee80:  9a 15 a2 48  or  %l6, 0x248, %o5
a009ee84:  11 28 01 ac  sethi  %hi(0xa006b000), %o0
a009ee88:  d4 14 80 10  lduh  [ %l2 + %l0 ], %o2
a009ee8c:  90 12 20 98  or  %o0, 0x98, %o0
a009ee90:  7f ff 50 6d  call  0xa0073044
a009ee94:  92 10 00 11  mov  %l1, %o1
a009ee98:  9a 15 a2 48  or  %l6, 0x248, %o5
a009ee9c:  83 2c 60 02  sll  %l1, 2, %g1
a009eea0:  10 80 01 c8  b  0xa009f5c0
a009eea4:  c0 23 40 01  clr  [ %o5 + %g1 ]
a009eea8:  80 88 68 00  btst  0x800, %g1
a009eeac:  02 80 00 0d  be  0xa009eee0
a009eeb0:  2f 2a 01 f6  sethi  %hi(0xa807d800), %l7
a009eeb4:  9a 14 e3 00  or  %l3, 0x300, %o5
a009eeb8:  82 5c 60 34  smul  %l1, 0x34, %g1
a009eebc:  82 00 40 0d  add  %g1, %o5, %g1
a009eec0:  c2 00 60 18  ld  [ %g1 + 0x18 ], %g1
a009eec4:  d2 00 60 90  ld  [ %g1 + 0x90 ], %o1
a009eec8:  93 32 60 18  srl  %o1, 0x18, %o1
a009eecc:  11 28 01 ac  sethi  %hi(0xa006b000), %o0
a009eed0:  90 12 20 d0  or  %o0, 0xd0, %o0	! 0xa006b0d0
a009eed4:  7f ff 50 5c  call  0xa0073044
a009eed8:  92 0a 60 0f  and  %o1, 0xf, %o1
a009eedc:  2f 2a 01 f6  sethi  %hi(0xa807d800), %l7
a009eee0:  a2 0e 20 ff  and  %i0, 0xff, %l1
a009eee4:  82 15 e3 00  or  %l7, 0x300, %g1
a009eee8:  9a 5c 60 34  smul  %l1, 0x34, %o5
a009eeec:  a4 03 40 01  add  %o5, %g1, %l2
a009eef0:  da 04 a0 18  ld  [ %l2 + 0x18 ], %o5
a009eef4:  c2 03 60 90  ld  [ %o5 + 0x90 ], %g1
a009eef8:  27 03 c0 00  sethi  %hi(0xf000000), %l3
a009eefc:  80 88 40 13  btst  %g1, %l3
a009ef00:  12 80 00 36  bne  0xa009efd8
a009ef04:  03 3c 3f ff  sethi  %hi(0xf0fffc00), %g1
a009ef08:  92 10 63 ff  or  %g1, 0x3ff, %o1	! 0xf0ffffff
a009ef0c:  03 03 ff ff  sethi  %hi(0xffffc00), %g1
a009ef10:  98 10 00 12  mov  %l2, %o4
a009ef14:  94 10 63 ff  or  %g1, 0x3ff, %o2
a009ef18:  96 10 20 00  clr  %o3
a009ef1c:  82 0a e0 ff  and  %o3, 0xff, %g1
a009ef20:  80 a0 60 00  cmp  %g1, 0
a009ef24:  12 80 00 06  bne  0xa009ef3c
a009ef28:  80 a0 60 01  cmp  %g1, 1
a009ef2c:  da 03 20 18  ld  [ %o4 + 0x18 ], %o5
a009ef30:  c2 03 60 a0  ld  [ %o5 + 0xa0 ], %g1
a009ef34:  10 80 00 07  b  0xa009ef50
a009ef38:  82 08 40 09  and  %g1, %o1, %g1
a009ef3c:  12 80 00 08  bne  0xa009ef5c
a009ef40:  80 a0 60 02  cmp  %g1, 2
a009ef44:  da 03 20 18  ld  [ %o4 + 0x18 ], %o5
a009ef48:  c2 03 60 a0  ld  [ %o5 + 0xa0 ], %g1
a009ef4c:  82 08 40 0a  and  %g1, %o2, %g1
a009ef50:  c2 23 60 a0  st  %g1, [ %o5 + 0xa0 ]
a009ef54:  10 80 00 0f  b  0xa009ef90
a009ef58:  96 02 e0 01  inc  %o3
a009ef5c:  12 80 00 06  bne  0xa009ef74
a009ef60:  80 a0 60 03  cmp  %g1, 3
a009ef64:  da 03 20 18  ld  [ %o4 + 0x18 ], %o5
a009ef68:  c2 03 60 a4  ld  [ %o5 + 0xa4 ], %g1
a009ef6c:  10 80 00 07  b  0xa009ef88
a009ef70:  82 08 7f f0  and  %g1, -16, %g1
a009ef74:  32 80 00 07  bne,a   0xa009ef90
a009ef78:  96 02 e0 01  inc  %o3
a009ef7c:  da 03 20 18  ld  [ %o4 + 0x18 ], %o5
a009ef80:  c2 03 60 a4  ld  [ %o5 + 0xa4 ], %g1
a009ef84:  82 08 7f 0f  and  %g1, -241, %g1
a009ef88:  c2 23 60 a4  st  %g1, [ %o5 + 0xa4 ]
a009ef8c:  96 02 e0 01  inc  %o3
a009ef90:  82 0a e0 ff  and  %o3, 0xff, %g1
a009ef94:  80 a0 60 03  cmp  %g1, 3
a009ef98:  08 bf ff e3  bleu  0xa009ef24
a009ef9c:  80 a0 60 00  cmp  %g1, 0
a009efa0:  c2 05 62 34  ld  [ %l5 + 0x234 ], %g1
a009efa4:  80 88 68 00  btst  0x800, %g1
a009efa8:  02 80 00 07  be  0xa009efc4
a009efac:  82 0e 20 ff  and  %i0, 0xff, %g1
a009efb0:  11 28 01 ac  sethi  %hi(0xa006b000), %o0
a009efb4:  90 12 20 f0  or  %o0, 0xf0, %o0	! 0xa006b0f0
a009efb8:  7f ff 51 43  call  0xa00734c4
a009efbc:  01 00 00 00  nop
a009efc0:  82 0e 20 ff  and  %i0, 0xff, %g1
a009efc4:  98 15 a2 48  or  %l6, 0x248, %o4
a009efc8:  83 28 60 02  sll  %g1, 2, %g1
a009efcc:  9a 10 20 07  mov  7, %o5
a009efd0:  10 80 01 7c  b  0xa009f5c0
a009efd4:  da 23 00 01  st  %o5, [ %o4 + %g1 ]
a009efd8:  c2 03 60 90  ld  [ %o5 + 0x90 ], %g1
a009efdc:  82 08 40 13  and  %g1, %l3, %g1
a009efe0:  83 30 60 18  srl  %g1, 0x18, %g1
a009efe4:  80 a0 60 06  cmp  %g1, 6
a009efe8:  08 80 00 49  bleu  0xa009f10c
a009efec:  82 5c 60 b0  smul  %l1, 0xb0, %g1
a009eff0:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a009eff4:  c2 00 62 34  ld  [ %g1 + 0x234 ], %g1	! 0xa8078634
a009eff8:  80 88 68 00  btst  0x800, %g1
a009effc:  22 80 00 06  be,a   0xa009f014
a009f000:  90 5c 60 b0  smul  %l1, 0xb0, %o0
a009f004:  11 28 01 ac  sethi  %hi(0xa006b000), %o0
a009f008:  7f ff 51 2f  call  0xa00734c4
a009f00c:  90 12 21 20  or  %o0, 0x120, %o0	! 0xa006b120
a009f010:  90 5c 60 b0  smul  %l1, 0xb0, %o0
a009f014:  98 15 22 80  or  %l4, 0x280, %o4
a009f018:  c2 0b 00 08  ldub  [ %o4 + %o0 ], %g1
a009f01c:  80 a0 60 00  cmp  %g1, 0
a009f020:  02 80 00 2d  be  0xa009f0d4
a009f024:  a2 10 20 00  clr  %l1
a009f028:  03 3c 3f ff  sethi  %hi(0xf0fffc00), %g1
a009f02c:  a0 10 63 ff  or  %g1, 0x3ff, %l0	! 0xf0ffffff
a009f030:  03 03 ff ff  sethi  %hi(0xffffc00), %g1
a009f034:  96 10 00 12  mov  %l2, %o3
a009f038:  9e 10 63 ff  or  %g1, 0x3ff, %o7
a009f03c:  92 10 00 13  mov  %l3, %o1
a009f040:  15 3c 00 00  sethi  %hi(0xf0000000), %o2
a009f044:  82 0c 60 ff  and  %l1, 0xff, %g1
a009f048:  80 a0 60 00  cmp  %g1, 0
a009f04c:  12 80 00 07  bne  0xa009f068
a009f050:  80 a0 60 01  cmp  %g1, 1
a009f054:  da 02 e0 18  ld  [ %o3 + 0x18 ], %o5
a009f058:  c2 03 60 a0  ld  [ %o5 + 0xa0 ], %g1
a009f05c:  82 08 40 10  and  %g1, %l0, %g1
a009f060:  10 80 00 08  b  0xa009f080
a009f064:  82 10 40 09  or  %g1, %o1, %g1
a009f068:  12 80 00 09  bne  0xa009f08c
a009f06c:  80 a0 60 02  cmp  %g1, 2
a009f070:  da 02 e0 18  ld  [ %o3 + 0x18 ], %o5
a009f074:  c2 03 60 a0  ld  [ %o5 + 0xa0 ], %g1
a009f078:  82 08 40 0f  and  %g1, %o7, %g1
a009f07c:  82 10 40 0a  or  %g1, %o2, %g1
a009f080:  c2 23 60 a0  st  %g1, [ %o5 + 0xa0 ]
a009f084:  10 80 00 0f  b  0xa009f0c0
a009f088:  a2 04 60 01  inc  %l1
a009f08c:  12 80 00 06  bne  0xa009f0a4
a009f090:  80 a0 60 03  cmp  %g1, 3
a009f094:  da 02 e0 18  ld  [ %o3 + 0x18 ], %o5
a009f098:  c2 03 60 a4  ld  [ %o5 + 0xa4 ], %g1
a009f09c:  10 80 00 07  b  0xa009f0b8
a009f0a0:  82 10 60 0f  or  %g1, 0xf, %g1
a009f0a4:  32 80 00 07  bne,a   0xa009f0c0
a009f0a8:  a2 04 60 01  inc  %l1
a009f0ac:  da 02 e0 18  ld  [ %o3 + 0x18 ], %o5
a009f0b0:  c2 03 60 a4  ld  [ %o5 + 0xa4 ], %g1
a009f0b4:  82 10 60 f0  or  %g1, 0xf0, %g1
a009f0b8:  c2 23 60 a4  st  %g1, [ %o5 + 0xa4 ]
a009f0bc:  a2 04 60 01  inc  %l1
a009f0c0:  9a 0c 60 ff  and  %l1, 0xff, %o5
a009f0c4:  c2 0b 00 08  ldub  [ %o4 + %o0 ], %g1
a009f0c8:  80 a3 40 01  cmp  %o5, %g1
a009f0cc:  0a bf ff df  bcs  0xa009f048
a009f0d0:  82 0c 60 ff  and  %l1, 0xff, %g1
a009f0d4:  a0 0e 20 ff  and  %i0, 0xff, %l0
a009f0d8:  03 2a 01 f6  sethi  %hi(0xa807d800), %g1
a009f0dc:  82 10 63 00  or  %g1, 0x300, %g1	! 0xa807db00
a009f0e0:  9a 5c 20 34  smul  %l0, 0x34, %o5
a009f0e4:  9a 03 40 01  add  %o5, %g1, %o5
a009f0e8:  d2 03 60 18  ld  [ %o5 + 0x18 ], %o1
a009f0ec:  92 02 60 80  add  %o1, 0x80, %o1
a009f0f0:  40 00 20 af  call  0xa00a73ac
a009f0f4:  90 10 20 05  mov  5, %o0
a009f0f8:  9a 15 a2 48  or  %l6, 0x248, %o5
a009f0fc:  a1 2c 20 02  sll  %l0, 2, %l0
a009f100:  82 10 20 03  mov  3, %g1
a009f104:  10 80 01 2f  b  0xa009f5c0
a009f108:  c2 23 40 10  st  %g1, [ %o5 + %l0 ]
a009f10c:  da 03 60 90  ld  [ %o5 + 0x90 ], %o5
a009f110:  98 15 22 80  or  %l4, 0x280, %o4
a009f114:  a0 00 40 0c  add  %g1, %o4, %l0
a009f118:  9a 0b 40 13  and  %o5, %l3, %o5
a009f11c:  9b 33 60 18  srl  %o5, 0x18, %o5
a009f120:  c2 0c 20 02  ldub  [ %l0 + 2 ], %g1
a009f124:  80 a3 40 01  cmp  %o5, %g1
a009f128:  02 80 00 2c  be  0xa009f1d8
a009f12c:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a009f130:  7f ff e4 ce  call  0xa0098468
a009f134:  90 10 00 11  mov  %l1, %o0
a009f138:  c2 04 a0 18  ld  [ %l2 + 0x18 ], %g1
a009f13c:  c2 00 60 90  ld  [ %g1 + 0x90 ], %g1
a009f140:  82 08 40 13  and  %g1, %l3, %g1
a009f144:  83 30 60 18  srl  %g1, 0x18, %g1
a009f148:  7f ff b9 ae  call  0xa008d800
a009f14c:  c2 2c 20 02  stb  %g1, [ %l0 + 2 ]
a009f150:  90 0a 20 ff  and  %o0, 0xff, %o0
a009f154:  80 a2 20 82  cmp  %o0, 0x82
a009f158:  38 80 00 07  bgu,a   0xa009f174
a009f15c:  c2 0c 20 01  ldub  [ %l0 + 1 ], %g1
a009f160:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a009f164:  9a 10 20 01  mov  1, %o5
a009f168:  82 10 60 d8  or  %g1, 0xd8, %g1
a009f16c:  da 28 40 11  stb  %o5, [ %g1 + %l1 ]
a009f170:  c2 0c 20 01  ldub  [ %l0 + 1 ], %g1
a009f174:  80 a0 60 03  cmp  %g1, 3
a009f178:  28 80 00 04  bleu,a   0xa009f188
a009f17c:  c0 2c 20 34  clrb  [ %l0 + 0x34 ]
a009f180:  82 10 20 01  mov  1, %g1
a009f184:  c2 2c 20 34  stb  %g1, [ %l0 + 0x34 ]
a009f188:  82 15 22 80  or  %l4, 0x280, %g1
a009f18c:  9a 5c 60 b0  smul  %l1, 0xb0, %o5
a009f190:  a0 03 40 01  add  %o5, %g1, %l0
a009f194:  d2 0c 20 02  ldub  [ %l0 + 2 ], %o1
a009f198:  7f ff fe a2  call  0xa009ec20
a009f19c:  90 10 00 11  mov  %l1, %o0
a009f1a0:  40 00 49 7d  call  0xa00b1794
a009f1a4:  90 10 20 01  mov  1, %o0
a009f1a8:  90 0f 60 03  and  %i5, 3, %o0
a009f1ac:  7f ff 84 ba  call  0xa0080494
a009f1b0:  d2 0c 20 02  ldub  [ %l0 + 2 ], %o1
a009f1b4:  c2 05 62 34  ld  [ %l5 + 0x234 ], %g1
a009f1b8:  80 88 68 00  btst  0x800, %g1
a009f1bc:  02 80 00 07  be  0xa009f1d8
a009f1c0:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a009f1c4:  11 28 01 ac  sethi  %hi(0xa006b000), %o0
a009f1c8:  90 12 21 58  or  %o0, 0x158, %o0	! 0xa006b158
a009f1cc:  7f ff 4f 9e  call  0xa0073044
a009f1d0:  d2 0c 20 02  ldub  [ %l0 + 2 ], %o1
a009f1d4:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a009f1d8:  c2 08 60 52  ldub  [ %g1 + 0x52 ], %g1	! 0xa8079052
a009f1dc:  80 a0 60 00  cmp  %g1, 0
a009f1e0:  12 80 00 04  bne  0xa009f1f0
a009f1e4:  90 10 20 00  clr  %o0
a009f1e8:  7f ff ed 2c  call  0xa009a698
a009f1ec:  90 0e 20 ff  and  %i0, 0xff, %o0
a009f1f0:  a0 0a 20 ff  and  %o0, 0xff, %l0
a009f1f4:  80 a4 20 00  cmp  %l0, 0
a009f1f8:  12 80 00 60  bne  0xa009f378
a009f1fc:  03 2a 01 f5  sethi  %hi(0xa807d400), %g1
a009f200:  7f ff b9 80  call  0xa008d800
a009f204:  01 00 00 00  nop
a009f208:  90 0a 20 ff  and  %o0, 0xff, %o0
a009f20c:  80 a2 20 82  cmp  %o0, 0x82
a009f210:  08 80 00 10  bleu  0xa009f250
a009f214:  9a 0e 20 ff  and  %i0, 0xff, %o5
a009f218:  82 0e 20 ff  and  %i0, 0xff, %g1
a009f21c:  9a 15 e3 00  or  %l7, 0x300, %o5
a009f220:  82 58 60 34  smul  %g1, 0x34, %g1
a009f224:  82 00 40 0d  add  %g1, %o5, %g1
a009f228:  d8 00 60 18  ld  [ %g1 + 0x18 ], %o4
a009f22c:  03 3f ff c0  sethi  %hi(0xffff0000), %g1
a009f230:  da 03 20 b0  ld  [ %o4 + 0xb0 ], %o5
a009f234:  82 10 60 ff  or  %g1, 0xff, %g1
a009f238:  9a 0b 40 01  and  %o5, %g1, %o5
a009f23c:  03 00 00 3f  sethi  %hi(0xfc00), %g1
a009f240:  82 10 63 00  or  %g1, 0x300, %g1	! 0xff00
a009f244:  9a 13 40 01  or  %o5, %g1, %o5
a009f248:  da 23 20 b0  st  %o5, [ %o4 + 0xb0 ]
a009f24c:  9a 0e 20 ff  and  %i0, 0xff, %o5
a009f250:  03 2a 01 f6  sethi  %hi(0xa807d800), %g1
a009f254:  82 10 63 00  or  %g1, 0x300, %g1	! 0xa807db00
a009f258:  9a 5b 60 34  smul  %o5, 0x34, %o5
a009f25c:  98 03 40 01  add  %o5, %g1, %o4
a009f260:  03 3c 3f ff  sethi  %hi(0xf0fffc00), %g1
a009f264:  94 10 63 ff  or  %g1, 0x3ff, %o2	! 0xf0ffffff
a009f268:  03 03 ff ff  sethi  %hi(0xffffc00), %g1
a009f26c:  96 10 63 ff  or  %g1, 0x3ff, %o3	! 0xfffffff
a009f270:  a2 10 20 00  clr  %l1
a009f274:  82 0c 60 ff  and  %l1, 0xff, %g1
a009f278:  80 a0 60 00  cmp  %g1, 0
a009f27c:  12 80 00 06  bne  0xa009f294
a009f280:  80 a0 60 01  cmp  %g1, 1
a009f284:  da 03 20 18  ld  [ %o4 + 0x18 ], %o5
a009f288:  c2 03 60 a0  ld  [ %o5 + 0xa0 ], %g1
a009f28c:  10 80 00 07  b  0xa009f2a8
a009f290:  82 08 40 0a  and  %g1, %o2, %g1
a009f294:  12 80 00 08  bne  0xa009f2b4
a009f298:  80 a0 60 02  cmp  %g1, 2
a009f29c:  da 03 20 18  ld  [ %o4 + 0x18 ], %o5
a009f2a0:  c2 03 60 a0  ld  [ %o5 + 0xa0 ], %g1
a009f2a4:  82 08 40 0b  and  %g1, %o3, %g1
a009f2a8:  c2 23 60 a0  st  %g1, [ %o5 + 0xa0 ]
a009f2ac:  10 80 00 0f  b  0xa009f2e8
a009f2b0:  a2 04 60 01  inc  %l1
a009f2b4:  12 80 00 06  bne  0xa009f2cc
a009f2b8:  80 a0 60 03  cmp  %g1, 3
a009f2bc:  da 03 20 18  ld  [ %o4 + 0x18 ], %o5
a009f2c0:  c2 03 60 a4  ld  [ %o5 + 0xa4 ], %g1
a009f2c4:  10 80 00 07  b  0xa009f2e0
a009f2c8:  82 08 7f f0  and  %g1, -16, %g1
a009f2cc:  32 80 00 07  bne,a   0xa009f2e8
a009f2d0:  a2 04 60 01  inc  %l1
a009f2d4:  da 03 20 18  ld  [ %o4 + 0x18 ], %o5
a009f2d8:  c2 03 60 a4  ld  [ %o5 + 0xa4 ], %g1
a009f2dc:  82 08 7f 0f  and  %g1, -241, %g1
a009f2e0:  c2 23 60 a4  st  %g1, [ %o5 + 0xa4 ]
a009f2e4:  a2 04 60 01  inc  %l1
a009f2e8:  82 0c 60 ff  and  %l1, 0xff, %g1
a009f2ec:  80 a0 60 03  cmp  %g1, 3
a009f2f0:  08 bf ff e3  bleu  0xa009f27c
a009f2f4:  80 a0 60 00  cmp  %g1, 0
a009f2f8:  a0 0e 20 ff  and  %i0, 0xff, %l0
a009f2fc:  03 2a 01 f6  sethi  %hi(0xa807d800), %g1
a009f300:  82 10 63 00  or  %g1, 0x300, %g1	! 0xa807db00
a009f304:  9a 5c 20 34  smul  %l0, 0x34, %o5
a009f308:  9a 03 40 01  add  %o5, %g1, %o5
a009f30c:  d2 03 60 18  ld  [ %o5 + 0x18 ], %o1
a009f310:  92 02 60 80  add  %o1, 0x80, %o1
a009f314:  40 00 20 26  call  0xa00a73ac
a009f318:  90 10 20 05  mov  5, %o0
a009f31c:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a009f320:  c2 00 62 34  ld  [ %g1 + 0x234 ], %g1	! 0xa8078634
a009f324:  80 88 68 00  btst  0x800, %g1
a009f328:  02 80 00 0b  be  0xa009f354
a009f32c:  03 2a 01 f5  sethi  %hi(0xa807d400), %g1
a009f330:  1b 2a 01 f5  sethi  %hi(0xa807d400), %o5
a009f334:  82 5c 20 b0  smul  %l0, 0xb0, %g1
a009f338:  9a 13 62 80  or  %o5, 0x280, %o5
a009f33c:  82 00 40 0d  add  %g1, %o5, %g1
a009f340:  11 28 01 ac  sethi  %hi(0xa006b000), %o0
a009f344:  90 12 21 88  or  %o0, 0x188, %o0	! 0xa006b188
a009f348:  7f ff 4f 3f  call  0xa0073044
a009f34c:  d2 08 60 02  ldub  [ %g1 + 2 ], %o1
a009f350:  03 2a 01 f5  sethi  %hi(0xa807d400), %g1
a009f354:  82 10 62 80  or  %g1, 0x280, %g1	! 0xa807d680
a009f358:  9a 5c 20 b0  smul  %l0, 0xb0, %o5
a009f35c:  9a 03 40 01  add  %o5, %g1, %o5
a009f360:  96 15 a2 48  or  %l6, 0x248, %o3
a009f364:  99 2c 20 02  sll  %l0, 2, %o4
a009f368:  82 10 20 06  mov  6, %g1
a009f36c:  c2 22 c0 0c  st  %g1, [ %o3 + %o4 ]
a009f370:  10 80 00 94  b  0xa009f5c0
a009f374:  c0 2b 60 2b  clrb  [ %o5 + 0x2b ]
a009f378:  9a 0e 20 ff  and  %i0, 0xff, %o5
a009f37c:  96 10 62 80  or  %g1, 0x280, %o3
a009f380:  98 5b 60 b0  smul  %o5, 0xb0, %o4
a009f384:  82 03 00 0b  add  %o4, %o3, %g1
a009f388:  c2 08 60 13  ldub  [ %g1 + 0x13 ], %g1
a009f38c:  80 a0 60 00  cmp  %g1, 0
a009f390:  32 80 00 07  bne,a   0xa009f3ac
a009f394:  c2 0a c0 0c  ldub  [ %o3 + %o4 ], %g1
a009f398:  98 15 a2 48  or  %l6, 0x248, %o4
a009f39c:  9b 2b 60 02  sll  %o5, 2, %o5
a009f3a0:  82 10 20 03  mov  3, %g1
a009f3a4:  10 80 00 87  b  0xa009f5c0
a009f3a8:  c2 23 00 0d  st  %g1, [ %o4 + %o5 ]
a009f3ac:  80 a0 60 00  cmp  %g1, 0
a009f3b0:  02 80 00 6c  be  0xa009f560
a009f3b4:  a2 10 20 00  clr  %l1
a009f3b8:  96 0c 60 ff  and  %l1, 0xff, %o3
a009f3bc:  83 3c 00 0b  sra  %l0, %o3, %g1
a009f3c0:  80 88 60 01  btst  1, %g1
a009f3c4:  02 80 00 4f  be  0xa009f500
a009f3c8:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a009f3cc:  13 2a 01 f5  sethi  %hi(0xa807d400), %o1
a009f3d0:  94 0e 20 ff  and  %i0, 0xff, %o2
a009f3d4:  82 12 62 80  or  %o1, 0x280, %g1
a009f3d8:  9a 5a a0 b0  smul  %o2, 0xb0, %o5
a009f3dc:  9a 03 40 01  add  %o5, %g1, %o5
a009f3e0:  9a 03 40 0b  add  %o5, %o3, %o5
a009f3e4:  c2 0b 60 0f  ldub  [ %o5 + 0xf ], %g1
a009f3e8:  82 00 60 01  inc  %g1
a009f3ec:  80 a2 e0 00  cmp  %o3, 0
a009f3f0:  12 80 00 0c  bne  0xa009f420
a009f3f4:  c2 2b 60 0f  stb  %g1, [ %o5 + 0xf ]
a009f3f8:  03 2a 01 f6  sethi  %hi(0xa807d800), %g1
a009f3fc:  82 10 63 00  or  %g1, 0x300, %g1	! 0xa807db00
a009f400:  9a 5a a0 34  smul  %o2, 0x34, %o5
a009f404:  9a 03 40 01  add  %o5, %g1, %o5
a009f408:  d8 03 60 18  ld  [ %o5 + 0x18 ], %o4
a009f40c:  da 03 20 a0  ld  [ %o4 + 0xa0 ], %o5
a009f410:  03 03 c0 00  sethi  %hi(0xf000000), %g1
a009f414:  82 2b 40 01  andn  %o5, %g1, %g1
a009f418:  10 80 00 0e  b  0xa009f450
a009f41c:  1b 03 80 00  sethi  %hi(0xe000000), %o5
a009f420:  80 a2 e0 01  cmp  %o3, 1
a009f424:  12 80 00 0f  bne  0xa009f460
a009f428:  80 a2 e0 02  cmp  %o3, 2
a009f42c:  03 2a 01 f6  sethi  %hi(0xa807d800), %g1
a009f430:  82 10 63 00  or  %g1, 0x300, %g1	! 0xa807db00
a009f434:  9a 5a a0 34  smul  %o2, 0x34, %o5
a009f438:  9a 03 40 01  add  %o5, %g1, %o5
a009f43c:  d8 03 60 18  ld  [ %o5 + 0x18 ], %o4
a009f440:  da 03 20 a0  ld  [ %o4 + 0xa0 ], %o5
a009f444:  03 3c 00 00  sethi  %hi(0xf0000000), %g1
a009f448:  82 2b 40 01  andn  %o5, %g1, %g1
a009f44c:  1b 38 00 00  sethi  %hi(0xe0000000), %o5
a009f450:  82 10 40 0d  or  %g1, %o5, %g1
a009f454:  c2 23 20 a0  st  %g1, [ %o4 + 0xa0 ]
a009f458:  10 80 00 19  b  0xa009f4bc
a009f45c:  9a 12 62 80  or  %o1, 0x280, %o5
a009f460:  12 80 00 0b  bne  0xa009f48c
a009f464:  80 a2 e0 03  cmp  %o3, 3
a009f468:  03 2a 01 f6  sethi  %hi(0xa807d800), %g1
a009f46c:  82 10 63 00  or  %g1, 0x300, %g1	! 0xa807db00
a009f470:  9a 5a a0 34  smul  %o2, 0x34, %o5
a009f474:  9a 03 40 01  add  %o5, %g1, %o5
a009f478:  da 03 60 18  ld  [ %o5 + 0x18 ], %o5
a009f47c:  c2 03 60 a4  ld  [ %o5 + 0xa4 ], %g1
a009f480:  82 08 7f f0  and  %g1, -16, %g1
a009f484:  10 80 00 0c  b  0xa009f4b4
a009f488:  82 10 60 0e  or  %g1, 0xe, %g1
a009f48c:  12 80 00 0c  bne  0xa009f4bc
a009f490:  9a 12 62 80  or  %o1, 0x280, %o5
a009f494:  03 2a 01 f6  sethi  %hi(0xa807d800), %g1
a009f498:  82 10 63 00  or  %g1, 0x300, %g1	! 0xa807db00
a009f49c:  9a 5a a0 34  smul  %o2, 0x34, %o5
a009f4a0:  9a 03 40 01  add  %o5, %g1, %o5
a009f4a4:  da 03 60 18  ld  [ %o5 + 0x18 ], %o5
a009f4a8:  c2 03 60 a4  ld  [ %o5 + 0xa4 ], %g1
a009f4ac:  82 08 7f 0f  and  %g1, -241, %g1
a009f4b0:  82 10 60 e0  or  %g1, 0xe0, %g1
a009f4b4:  c2 23 60 a4  st  %g1, [ %o5 + 0xa4 ]
a009f4b8:  9a 12 62 80  or  %o1, 0x280, %o5
a009f4bc:  82 5a a0 b0  smul  %o2, 0xb0, %g1
a009f4c0:  82 00 40 0d  add  %g1, %o5, %g1
a009f4c4:  96 00 40 0b  add  %g1, %o3, %o3
a009f4c8:  da 08 60 13  ldub  [ %g1 + 0x13 ], %o5
a009f4cc:  9a 03 60 01  inc  %o5
a009f4d0:  d8 0a e0 0f  ldub  [ %o3 + 0xf ], %o4
a009f4d4:  95 3b 20 1f  sra  %o4, 0x1f, %o2
a009f4d8:  81 82 a0 00  mov  %o2, %y
a009f4dc:  01 00 00 00  nop
a009f4e0:  01 00 00 00  nop
a009f4e4:  01 00 00 00  nop
a009f4e8:  82 7b 00 0d  sdiv  %o4, %o5, %g1
a009f4ec:  82 58 40 0d  smul  %g1, %o5, %g1
a009f4f0:  80 a3 00 01  cmp  %o4, %g1
a009f4f4:  22 80 00 02  be,a   0xa009f4fc
a009f4f8:  c0 2a e0 0f  clrb  [ %o3 + 0xf ]
a009f4fc:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a009f500:  c2 00 62 34  ld  [ %g1 + 0x234 ], %g1	! 0xa8078634
a009f504:  80 88 68 00  btst  0x800, %g1
a009f508:  02 80 00 0d  be  0xa009f53c
a009f50c:  9a 0e 20 ff  and  %i0, 0xff, %o5
a009f510:  03 2a 01 f5  sethi  %hi(0xa807d400), %g1
a009f514:  9a 5b 60 b0  smul  %o5, 0xb0, %o5
a009f518:  82 10 62 80  or  %g1, 0x280, %g1
a009f51c:  9a 03 40 01  add  %o5, %g1, %o5
a009f520:  92 0c 60 ff  and  %l1, 0xff, %o1
a009f524:  9a 03 40 09  add  %o5, %o1, %o5
a009f528:  11 28 01 ac  sethi  %hi(0xa006b000), %o0
a009f52c:  90 12 21 c0  or  %o0, 0x1c0, %o0	! 0xa006b1c0
a009f530:  7f ff 4e c5  call  0xa0073044
a009f534:  d4 0b 60 0f  ldub  [ %o5 + 0xf ], %o2
a009f538:  9a 0e 20 ff  and  %i0, 0xff, %o5
a009f53c:  03 2a 01 f5  sethi  %hi(0xa807d400), %g1
a009f540:  82 10 62 80  or  %g1, 0x280, %g1	! 0xa807d680
a009f544:  9a 5b 60 b0  smul  %o5, 0xb0, %o5
a009f548:  da 08 40 0d  ldub  [ %g1 + %o5 ], %o5
a009f54c:  a2 04 60 01  inc  %l1
a009f550:  82 0c 60 ff  and  %l1, 0xff, %g1
a009f554:  80 a0 40 0d  cmp  %g1, %o5
a009f558:  0a bf ff 99  bcs  0xa009f3bc
a009f55c:  96 0c 60 ff  and  %l1, 0xff, %o3
a009f560:  a0 0e 20 ff  and  %i0, 0xff, %l0
a009f564:  03 2a 01 f6  sethi  %hi(0xa807d800), %g1
a009f568:  82 10 63 00  or  %g1, 0x300, %g1	! 0xa807db00
a009f56c:  9a 5c 20 34  smul  %l0, 0x34, %o5
a009f570:  9a 03 40 01  add  %o5, %g1, %o5
a009f574:  d2 03 60 18  ld  [ %o5 + 0x18 ], %o1
a009f578:  92 02 60 80  add  %o1, 0x80, %o1
a009f57c:  40 00 1f 8c  call  0xa00a73ac
a009f580:  90 10 20 05  mov  5, %o0
a009f584:  a1 2c 20 02  sll  %l0, 2, %l0
a009f588:  82 10 20 03  mov  3, %g1
a009f58c:  9a 15 a2 48  or  %l6, 0x248, %o5
a009f590:  40 00 4a b5  call  0xa00b2064
a009f594:  c2 23 40 10  st  %g1, [ %o5 + %l0 ]
a009f598:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a009f59c:  82 10 60 74  or  %g1, 0x74, %g1	! 0xa8079074
a009f5a0:  d2 00 40 10  ld  [ %g1 + %l0 ], %o1
a009f5a4:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a009f5a8:  82 10 60 6c  or  %g1, 0x6c, %g1	! 0xa807906c
a009f5ac:  d0 20 40 10  st  %o0, [ %g1 + %l0 ]
a009f5b0:  92 22 00 09  sub  %o0, %o1, %o1
a009f5b4:  11 28 01 ac  sethi  %hi(0xa006b000), %o0
a009f5b8:  7f ff 4e a3  call  0xa0073044
a009f5bc:  90 12 21 e0  or  %o0, 0x1e0, %o0	! 0xa006b1e0
a009f5c0:  81 c7 e0 08  ret
a009f5c4:  91 e8 20 00  restore  %g0, 0, %o0
