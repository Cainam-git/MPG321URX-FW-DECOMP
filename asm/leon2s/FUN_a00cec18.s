# leon2s FUN_a00cec18 0xa00cec18-0xa00cef6c (852 bytes)
a00cec18:  9d e3 bf 80  save  %sp, -128, %sp
a00cec1c:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00cec20:  98 06 00 18  add  %i0, %i0, %o4
a00cec24:  98 03 00 18  add  %o4, %i0, %o4
a00cec28:  27 2a 01 e2  sethi  %hi(0xa8078800), %l3
a00cec2c:  99 2b 20 03  sll  %o4, 3, %o4
a00cec30:  96 14 e3 b0  or  %l3, 0x3b0, %o3
a00cec34:  da 02 c0 0c  ld  [ %o3 + %o4 ], %o5
a00cec38:  03 00 00 c0  sethi  %hi(0x30000), %g1
a00cec3c:  82 2b 40 01  andn  %o5, %g1, %g1
a00cec40:  1b 00 00 40  sethi  %hi(0x10000), %o5
a00cec44:  82 10 40 0d  or  %g1, %o5, %g1
a00cec48:  c2 22 c0 0c  st  %g1, [ %o3 + %o4 ]
a00cec4c:  a2 10 20 00  clr  %l1
a00cec50:  a4 07 bf f8  add  %fp, -8, %l2
a00cec54:  83 2c 60 10  sll  %l1, 0x10, %g1
a00cec58:  98 04 60 01  add  %l1, 1, %o4
a00cec5c:  83 30 60 10  srl  %g1, 0x10, %g1
a00cec60:  82 04 80 01  add  %l2, %g1, %g1
a00cec64:  9b 2b 20 10  sll  %o4, 0x10, %o5
a00cec68:  e2 28 7f f8  stb  %l1, [ %g1 + -8 ]
a00cec6c:  e2 28 7f e8  stb  %l1, [ %g1 + -24 ]
a00cec70:  e2 28 7f f0  stb  %l1, [ %g1 + -16 ]
a00cec74:  9b 33 60 10  srl  %o5, 0x10, %o5
a00cec78:  80 a3 60 07  cmp  %o5, 7
a00cec7c:  08 bf ff f6  bleu  0xa00cec54
a00cec80:  a2 10 00 0c  mov  %o4, %l1
a00cec84:  90 10 00 18  mov  %i0, %o0
a00cec88:  92 10 20 11  mov  0x11, %o1
a00cec8c:  7f ff e6 d7  call  0xa00c87e8
a00cec90:  15 00 00 20  sethi  %hi(0x8000), %o2
a00cec94:  a2 10 20 00  clr  %l1
a00cec98:  83 2c 60 10  sll  %l1, 0x10, %g1
a00cec9c:  83 30 60 10  srl  %g1, 0x10, %g1
a00ceca0:  82 04 80 01  add  %l2, %g1, %g1
a00ceca4:  d4 08 7f e8  ldub  [ %g1 + -24 ], %o2
a00ceca8:  90 10 00 18  mov  %i0, %o0
a00cecac:  7f ff e2 6a  call  0xa00c7654
a00cecb0:  92 10 20 01  mov  1, %o1
a00cecb4:  9a 04 60 01  add  %l1, 1, %o5
a00cecb8:  83 2b 60 10  sll  %o5, 0x10, %g1
a00cecbc:  83 30 60 10  srl  %g1, 0x10, %g1
a00cecc0:  80 a0 60 17  cmp  %g1, 0x17
a00cecc4:  08 bf ff f5  bleu  0xa00cec98
a00cecc8:  a2 10 00 0d  mov  %o5, %l1
a00ceccc:  90 10 00 18  mov  %i0, %o0
a00cecd0:  92 10 20 06  mov  6, %o1
a00cecd4:  7f ff e2 60  call  0xa00c7654
a00cecd8:  94 10 20 0a  mov  0xa, %o2
a00cecdc:  90 10 00 18  mov  %i0, %o0
a00cece0:  7f ff e2 a4  call  0xa00c7770
a00cece4:  92 10 20 06  mov  6, %o1
a00cece8:  80 8a 20 08  btst  8, %o0
a00cecec:  12 bf ff fd  bne  0xa00cece0
a00cecf0:  90 10 00 18  mov  %i0, %o0
a00cecf4:  92 10 20 0a  mov  0xa, %o1
a00cecf8:  7f ff e6 bc  call  0xa00c87e8
a00cecfc:  15 00 00 20  sethi  %hi(0x8000), %o2
a00ced00:  a2 10 20 00  clr  %l1
a00ced04:  90 10 00 18  mov  %i0, %o0
a00ced08:  7f ff e2 9a  call  0xa00c7770
a00ced0c:  92 10 20 01  mov  1, %o1
a00ced10:  a1 2c 60 10  sll  %l1, 0x10, %l0
a00ced14:  9a 04 60 01  add  %l1, 1, %o5
a00ced18:  a1 34 20 10  srl  %l0, 0x10, %l0
a00ced1c:  83 2b 60 10  sll  %o5, 0x10, %g1
a00ced20:  a0 04 80 10  add  %l2, %l0, %l0
a00ced24:  83 30 60 10  srl  %g1, 0x10, %g1
a00ced28:  d0 2c 3f e8  stb  %o0, [ %l0 + -24 ]
a00ced2c:  80 a0 60 0f  cmp  %g1, 0xf
a00ced30:  08 bf ff f5  bleu  0xa00ced04
a00ced34:  a2 10 00 0d  mov  %o5, %l1
a00ced38:  21 00 01 a4  sethi  %hi(0x69000), %l0
a00ced3c:  92 10 20 80  mov  0x80, %o1
a00ced40:  94 14 23 18  or  %l0, 0x318, %o2
a00ced44:  96 10 20 0f  mov  0xf, %o3
a00ced48:  98 07 bf e0  add  %fp, -32, %o4
a00ced4c:  40 3b 1d a2  call  0xa0f963d4
a00ced50:  90 10 20 00  clr  %o0
a00ced54:  96 10 20 07  mov  7, %o3
a00ced58:  98 07 bf f0  add  %fp, -16, %o4
a00ced5c:  94 14 23 28  or  %l0, 0x328, %o2
a00ced60:  90 10 20 00  clr  %o0
a00ced64:  40 3b 1d 9c  call  0xa0f963d4
a00ced68:  92 10 20 80  mov  0x80, %o1
a00ced6c:  82 06 00 18  add  %i0, %i0, %g1
a00ced70:  82 00 40 18  add  %g1, %i0, %g1
a00ced74:  99 28 60 03  sll  %g1, 3, %o4
a00ced78:  96 14 e3 b0  or  %l3, 0x3b0, %o3
a00ced7c:  da 02 c0 0c  ld  [ %o3 + %o4 ], %o5
a00ced80:  83 33 60 1c  srl  %o5, 0x1c, %g1
a00ced84:  80 88 60 01  btst  1, %g1
a00ced88:  12 80 00 73  bne  0xa00cef54
a00ced8c:  03 00 00 c0  sethi  %hi(0x30000), %g1
a00ced90:  03 00 20 00  sethi  %hi(0x800000), %g1
a00ced94:  82 2b 40 01  andn  %o5, %g1, %g1
a00ced98:  c2 22 c0 0c  st  %g1, [ %o3 + %o4 ]
a00ced9c:  90 10 00 18  mov  %i0, %o0
a00ceda0:  92 10 20 0b  mov  0xb, %o1
a00ceda4:  7f ff e6 91  call  0xa00c87e8
a00ceda8:  15 00 00 20  sethi  %hi(0x8000), %o2
a00cedac:  a2 10 20 00  clr  %l1
a00cedb0:  90 10 00 18  mov  %i0, %o0
a00cedb4:  92 10 20 01  mov  1, %o1
a00cedb8:  7f ff e2 27  call  0xa00c7654
a00cedbc:  94 10 20 00  clr  %o2
a00cedc0:  9a 04 60 01  add  %l1, 1, %o5
a00cedc4:  83 2b 60 10  sll  %o5, 0x10, %g1
a00cedc8:  83 30 60 10  srl  %g1, 0x10, %g1
a00cedcc:  80 a0 60 b5  cmp  %g1, 0xb5
a00cedd0:  08 bf ff f8  bleu  0xa00cedb0
a00cedd4:  a2 10 00 0d  mov  %o5, %l1
a00cedd8:  90 10 00 18  mov  %i0, %o0
a00ceddc:  92 10 20 01  mov  1, %o1
a00cede0:  7f ff e2 1d  call  0xa00c7654
a00cede4:  94 10 20 02  mov  2, %o2
a00cede8:  90 10 00 18  mov  %i0, %o0
a00cedec:  92 10 20 01  mov  1, %o1
a00cedf0:  7f ff e2 19  call  0xa00c7654
a00cedf4:  94 10 20 10  mov  0x10, %o2
a00cedf8:  a2 10 20 00  clr  %l1
a00cedfc:  90 10 00 18  mov  %i0, %o0
a00cee00:  92 10 20 01  mov  1, %o1
a00cee04:  7f ff e2 14  call  0xa00c7654
a00cee08:  94 10 20 00  clr  %o2
a00cee0c:  9a 04 60 01  add  %l1, 1, %o5
a00cee10:  83 2b 60 10  sll  %o5, 0x10, %g1
a00cee14:  83 30 60 10  srl  %g1, 0x10, %g1
a00cee18:  80 a0 60 02  cmp  %g1, 2
a00cee1c:  08 bf ff f8  bleu  0xa00cedfc
a00cee20:  a2 10 00 0d  mov  %o5, %l1
a00cee24:  15 00 00 10  sethi  %hi(0x4000), %o2
a00cee28:  94 12 a0 15  or  %o2, 0x15, %o2	! 0x4015
a00cee2c:  90 10 00 18  mov  %i0, %o0
a00cee30:  7f ff e6 6e  call  0xa00c87e8
a00cee34:  92 10 20 0b  mov  0xb, %o1
a00cee38:  a2 10 20 00  clr  %l1
a00cee3c:  9b 2e 20 02  sll  %i0, 2, %o5
a00cee40:  03 2a 01 f3  sethi  %hi(0xa807cc00), %g1
a00cee44:  82 10 62 38  or  %g1, 0x238, %g1	! 0xa807ce38
a00cee48:  99 2c 60 10  sll  %l1, 0x10, %o4
a00cee4c:  9a 03 40 18  add  %o5, %i0, %o5
a00cee50:  9a 03 40 01  add  %o5, %g1, %o5
a00cee54:  99 33 20 10  srl  %o4, 0x10, %o4
a00cee58:  d4 0b 40 0c  ldub  [ %o5 + %o4 ], %o2
a00cee5c:  90 10 00 18  mov  %i0, %o0
a00cee60:  7f ff e1 fd  call  0xa00c7654
a00cee64:  92 10 20 01  mov  1, %o1
a00cee68:  9a 04 60 01  add  %l1, 1, %o5
a00cee6c:  83 2b 60 10  sll  %o5, 0x10, %g1
a00cee70:  83 30 60 10  srl  %g1, 0x10, %g1
a00cee74:  80 a0 60 04  cmp  %g1, 4
a00cee78:  08 bf ff f1  bleu  0xa00cee3c
a00cee7c:  a2 10 00 0d  mov  %o5, %l1
a00cee80:  90 10 00 18  mov  %i0, %o0
a00cee84:  92 10 20 01  mov  1, %o1
a00cee88:  7f ff e1 f3  call  0xa00c7654
a00cee8c:  94 10 20 02  mov  2, %o2
a00cee90:  90 10 00 18  mov  %i0, %o0
a00cee94:  92 10 20 01  mov  1, %o1
a00cee98:  7f ff e1 ef  call  0xa00c7654
a00cee9c:  94 10 20 10  mov  0x10, %o2
a00ceea0:  a2 10 20 00  clr  %l1
a00ceea4:  90 10 00 18  mov  %i0, %o0
a00ceea8:  92 10 20 01  mov  1, %o1
a00ceeac:  7f ff e1 ea  call  0xa00c7654
a00ceeb0:  94 10 20 00  clr  %o2
a00ceeb4:  9a 04 60 01  add  %l1, 1, %o5
a00ceeb8:  83 2b 60 10  sll  %o5, 0x10, %g1
a00ceebc:  83 30 60 10  srl  %g1, 0x10, %g1
a00ceec0:  80 a0 60 02  cmp  %g1, 2
a00ceec4:  08 bf ff f8  bleu  0xa00ceea4
a00ceec8:  a2 10 00 0d  mov  %o5, %l1
a00ceecc:  a0 06 00 18  add  %i0, %i0, %l0
a00ceed0:  90 10 00 18  mov  %i0, %o0
a00ceed4:  92 10 20 01  mov  1, %o1
a00ceed8:  94 10 20 80  mov  0x80, %o2
a00ceedc:  7f ff e1 de  call  0xa00c7654
a00ceee0:  a0 04 00 18  add  %l0, %i0, %l0
a00ceee4:  a1 2c 20 03  sll  %l0, 3, %l0
a00ceee8:  a2 14 e3 b0  or  %l3, 0x3b0, %l1
a00ceeec:  82 04 00 11  add  %l0, %l1, %g1
a00ceef0:  9a 10 20 01  mov  1, %o5
a00ceef4:  da 28 60 04  stb  %o5, [ %g1 + 4 ]
a00ceef8:  da 28 60 03  stb  %o5, [ %g1 + 3 ]
a00ceefc:  c0 28 60 08  clrb  [ %g1 + 8 ]
a00cef00:  c0 28 60 05  clrb  [ %g1 + 5 ]
a00cef04:  c0 28 60 06  clrb  [ %g1 + 6 ]
a00cef08:  c0 28 60 07  clrb  [ %g1 + 7 ]
a00cef0c:  90 10 00 18  mov  %i0, %o0
a00cef10:  92 10 20 00  clr  %o1
a00cef14:  7f ff e6 35  call  0xa00c87e8
a00cef18:  15 00 00 20  sethi  %hi(0x8000), %o2
a00cef1c:  15 00 01 a5  sethi  %hi(0x69400), %o2
a00cef20:  c0 2f bf e0  clrb  [ %fp + -32 ]
a00cef24:  94 12 a0 94  or  %o2, 0x94, %o2
a00cef28:  90 10 20 00  clr  %o0
a00cef2c:  92 10 20 80  mov  0x80, %o1
a00cef30:  40 3b 1d 0c  call  0xa0f96360
a00cef34:  96 10 20 00  clr  %o3
a00cef38:  da 04 40 10  ld  [ %l1 + %l0 ], %o5
a00cef3c:  03 00 00 c0  sethi  %hi(0x30000), %g1
a00cef40:  82 2b 40 01  andn  %o5, %g1, %g1
a00cef44:  1b 00 00 40  sethi  %hi(0x10000), %o5
a00cef48:  82 10 40 0d  or  %g1, %o5, %g1
a00cef4c:  10 80 00 06  b  0xa00cef64
a00cef50:  c2 24 40 10  st  %g1, [ %l1 + %l0 ]
a00cef54:  82 2b 40 01  andn  %o5, %g1, %g1
a00cef58:  1b 00 00 80  sethi  %hi(0x20000), %o5
a00cef5c:  82 10 40 0d  or  %g1, %o5, %g1
a00cef60:  c2 22 c0 0c  st  %g1, [ %o3 + %o4 ]
a00cef64:  81 c7 e0 08  ret
a00cef68:  81 e8 00 00  restore
