# leon2s DRV_HDMI21_RXDetect_FSM_Init 0xa009bef0-0xa009c09c (428 bytes)
a009bef0:  9d e3 bf 98  save  %sp, -104, %sp
a009bef4:  a0 0e 20 ff  and  %i0, 0xff, %l0
a009bef8:  7f ff e8 bc  call  0xa00961e8
a009befc:  90 10 00 10  mov  %l0, %o0
a009bf00:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a009bf04:  c2 00 62 34  ld  [ %g1 + 0x234 ], %g1	! 0xa8078634
a009bf08:  80 88 68 00  btst  0x800, %g1
a009bf0c:  02 80 00 08  be  0xa009bf2c
a009bf10:  a2 10 00 08  mov  %o0, %l1
a009bf14:  11 28 01 a9  sethi  %hi(0xa006a400), %o0
a009bf18:  13 28 02 d1  sethi  %hi(0xa00b4400), %o1
a009bf1c:  90 12 22 08  or  %o0, 0x208, %o0
a009bf20:  92 12 60 18  or  %o1, 0x18, %o1
a009bf24:  7f ff 5c 48  call  0xa0073044
a009bf28:  94 10 00 10  mov  %l0, %o2
a009bf2c:  03 2a 01 f5  sethi  %hi(0xa807d400), %g1
a009bf30:  82 10 62 80  or  %g1, 0x280, %g1	! 0xa807d680
a009bf34:  27 2a 01 f5  sethi  %hi(0xa807d400), %l3
a009bf38:  9a 5c 20 b0  smul  %l0, 0xb0, %o5
a009bf3c:  9a 03 40 01  add  %o5, %g1, %o5
a009bf40:  96 14 e2 48  or  %l3, 0x248, %o3
a009bf44:  99 2c 20 02  sll  %l0, 2, %o4
a009bf48:  c2 02 c0 0c  ld  [ %o3 + %o4 ], %g1
a009bf4c:  c2 23 60 30  st  %g1, [ %o5 + 0x30 ]
a009bf50:  7f ff fd a9  call  0xa009b5f4
a009bf54:  90 10 00 10  mov  %l0, %o0
a009bf58:  03 2a 01 f6  sethi  %hi(0xa807d800), %g1
a009bf5c:  82 10 63 00  or  %g1, 0x300, %g1	! 0xa807db00
a009bf60:  9a 5c 20 34  smul  %l0, 0x34, %o5
a009bf64:  90 03 40 01  add  %o5, %g1, %o0
a009bf68:  03 3c 3f ff  sethi  %hi(0xf0fffc00), %g1
a009bf6c:  94 10 63 ff  or  %g1, 0x3ff, %o2	! 0xf0ffffff
a009bf70:  03 03 ff ff  sethi  %hi(0xffffc00), %g1
a009bf74:  96 10 63 ff  or  %g1, 0x3ff, %o3	! 0xfffffff
a009bf78:  98 10 20 00  clr  %o4
a009bf7c:  82 0b 20 ff  and  %o4, 0xff, %g1
a009bf80:  80 a0 60 00  cmp  %g1, 0
a009bf84:  12 80 00 06  bne  0xa009bf9c
a009bf88:  80 a0 60 01  cmp  %g1, 1
a009bf8c:  da 02 20 18  ld  [ %o0 + 0x18 ], %o5
a009bf90:  c2 03 60 a0  ld  [ %o5 + 0xa0 ], %g1
a009bf94:  10 80 00 07  b  0xa009bfb0
a009bf98:  82 08 40 0a  and  %g1, %o2, %g1
a009bf9c:  12 80 00 08  bne  0xa009bfbc
a009bfa0:  80 a0 60 02  cmp  %g1, 2
a009bfa4:  da 02 20 18  ld  [ %o0 + 0x18 ], %o5
a009bfa8:  c2 03 60 a0  ld  [ %o5 + 0xa0 ], %g1
a009bfac:  82 08 40 0b  and  %g1, %o3, %g1
a009bfb0:  c2 23 60 a0  st  %g1, [ %o5 + 0xa0 ]
a009bfb4:  10 80 00 0f  b  0xa009bff0
a009bfb8:  98 03 20 01  inc  %o4
a009bfbc:  12 80 00 06  bne  0xa009bfd4
a009bfc0:  80 a0 60 03  cmp  %g1, 3
a009bfc4:  da 02 20 18  ld  [ %o0 + 0x18 ], %o5
a009bfc8:  c2 03 60 a4  ld  [ %o5 + 0xa4 ], %g1
a009bfcc:  10 80 00 07  b  0xa009bfe8
a009bfd0:  82 08 7f f0  and  %g1, -16, %g1
a009bfd4:  32 80 00 07  bne,a   0xa009bff0
a009bfd8:  98 03 20 01  inc  %o4
a009bfdc:  da 02 20 18  ld  [ %o0 + 0x18 ], %o5
a009bfe0:  c2 03 60 a4  ld  [ %o5 + 0xa4 ], %g1
a009bfe4:  82 08 7f 0f  and  %g1, -241, %g1
a009bfe8:  c2 23 60 a4  st  %g1, [ %o5 + 0xa4 ]
a009bfec:  98 03 20 01  inc  %o4
a009bff0:  82 0b 20 ff  and  %o4, 0xff, %g1
a009bff4:  80 a0 60 03  cmp  %g1, 3
a009bff8:  08 bf ff e3  bleu  0xa009bf84
a009bffc:  80 a0 60 00  cmp  %g1, 0
a009c000:  a4 0e 20 ff  and  %i0, 0xff, %l2
a009c004:  03 2a 01 f6  sethi  %hi(0xa807d800), %g1
a009c008:  82 10 63 00  or  %g1, 0x300, %g1	! 0xa807db00
a009c00c:  a0 5c a0 34  smul  %l2, 0x34, %l0
a009c010:  a0 04 00 01  add  %l0, %g1, %l0
a009c014:  d2 04 20 18  ld  [ %l0 + 0x18 ], %o1
a009c018:  92 02 60 a0  add  %o1, 0xa0, %o1
a009c01c:  40 00 2c ee  call  0xa00a73d4
a009c020:  90 10 20 16  mov  0x16, %o0
a009c024:  d2 04 20 18  ld  [ %l0 + 0x18 ], %o1
a009c028:  92 02 60 80  add  %o1, 0x80, %o1
a009c02c:  40 00 2c ea  call  0xa00a73d4
a009c030:  90 10 20 04  mov  4, %o0
a009c034:  d2 04 20 18  ld  [ %l0 + 0x18 ], %o1
a009c038:  da 02 60 90  ld  [ %o1 + 0x90 ], %o5
a009c03c:  03 03 c0 00  sethi  %hi(0xf000000), %g1
a009c040:  82 2b 40 01  andn  %o5, %g1, %g1
a009c044:  c2 22 60 90  st  %g1, [ %o1 + 0x90 ]
a009c048:  a0 0c 60 ff  and  %l1, 0xff, %l0
a009c04c:  92 02 60 80  add  %o1, 0x80, %o1
a009c050:  40 00 2c e1  call  0xa00a73d4
a009c054:  90 10 20 05  mov  5, %o0
a009c058:  23 00 00 0b  sethi  %hi(0x2c00), %l1
a009c05c:  90 10 20 01  mov  1, %o0
a009c060:  92 10 20 14  mov  0x14, %o1
a009c064:  94 10 00 10  mov  %l0, %o2
a009c068:  40 00 2c ef  call  0xa00a7424
a009c06c:  96 14 63 08  or  %l1, 0x308, %o3
a009c070:  94 10 00 10  mov  %l0, %o2
a009c074:  96 14 63 08  or  %l1, 0x308, %o3
a009c078:  90 10 20 00  clr  %o0
a009c07c:  40 00 2c ea  call  0xa00a7424
a009c080:  92 10 20 14  mov  0x14, %o1
a009c084:  9a 14 e2 48  or  %l3, 0x248, %o5
a009c088:  a5 2c a0 02  sll  %l2, 2, %l2
a009c08c:  82 10 20 01  mov  1, %g1
a009c090:  c2 23 40 12  st  %g1, [ %o5 + %l2 ]
a009c094:  81 c7 e0 08  ret
a009c098:  91 e8 20 00  restore  %g0, 0, %o0
