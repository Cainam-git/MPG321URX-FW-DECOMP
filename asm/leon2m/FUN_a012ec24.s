# leon2m FUN_a012ec24 0xa012ec24-0xa012eeb0 (652 bytes)
a012ec24:  9d e3 bf 78  save  %sp, -136, %sp
a012ec28:  d0 0e 40 00  ldub  [ %i1 ], %o0
a012ec2c:  d6 0e 60 01  ldub  [ %i1 + 1 ], %o3
a012ec30:  9a 0a 20 03  and  %o0, 3, %o5
a012ec34:  95 2a e0 02  sll  %o3, 2, %o2
a012ec38:  99 32 20 02  srl  %o0, 2, %o4
a012ec3c:  92 02 80 0d  add  %o2, %o5, %o1
a012ec40:  03 33 33 33  sethi  %hi(0xcccccc00), %g1
a012ec44:  91 2a 60 04  sll  %o1, 4, %o0
a012ec48:  a4 0b 20 3f  and  %o4, 0x3f, %l2
a012ec4c:  b0 0e 20 ff  and  %i0, 0xff, %i0
a012ec50:  aa 10 60 cd  or  %g1, 0xcd, %l5
a012ec54:  b8 10 20 00  clr  %i4
a012ec58:  a6 10 20 02  mov  2, %l3
a012ec5c:  a8 07 bf f8  add  %fp, -8, %l4
a012ec60:  b6 07 bf e8  add  %fp, -24, %i3
a012ec64:  97 2c e0 10  sll  %l3, 0x10, %o3
a012ec68:  99 32 e0 10  srl  %o3, 0x10, %o4
a012ec6c:  80 53 00 15  umul  %o4, %l5, %g0
a012ec70:  bb 40 00 00  rd  %y, %i5
a012ec74:  af 37 60 02  srl  %i5, 2, %l7
a012ec78:  ad 2d e0 02  sll  %l7, 2, %l6
a012ec7c:  a2 05 80 17  add  %l6, %l7, %l1
a012ec80:  a0 23 00 11  sub  %o4, %l1, %l0
a012ec84:  9f 2c 20 10  sll  %l0, 0x10, %o7
a012ec88:  80 a3 e0 00  cmp  %o7, 0
a012ec8c:  12 80 00 07  bne  0xa012eca8
a012ec90:  9f 32 e0 10  srl  %o3, 0x10, %o7
a012ec94:  82 04 e0 01  add  %l3, 1, %g1
a012ec98:  e4 0b 00 19  ldub  [ %o4 + %i1 ], %l2
a012ec9c:  97 28 60 10  sll  %g1, 0x10, %o3
a012eca0:  a6 10 00 01  mov  %g1, %l3
a012eca4:  9f 32 e0 10  srl  %o3, 0x10, %o7
a012eca8:  d6 0b c0 19  ldub  [ %o7 + %i1 ], %o3
a012ecac:  9a 0c a0 03  and  %l2, 3, %o5
a012ecb0:  95 2a e0 02  sll  %o3, 2, %o2
a012ecb4:  92 02 80 0d  add  %o2, %o5, %o1
a012ecb8:  99 2c a0 10  sll  %l2, 0x10, %o4
a012ecbc:  a3 2a 60 04  sll  %o1, 4, %l1
a012ecc0:  a5 33 20 12  srl  %o4, 0x12, %l2
a012ecc4:  94 10 20 00  clr  %o2
a012ecc8:  92 10 20 04  mov  4, %o1
a012eccc:  ad 2a a0 10  sll  %o2, 0x10, %l6
a012ecd0:  97 35 a0 10  srl  %l6, 0x10, %o3
a012ecd4:  a0 22 40 0b  sub  %o1, %o3, %l0
a012ecd8:  9a 5c 00 08  smul  %l0, %o0, %o5
a012ecdc:  94 02 a0 01  inc  %o2
a012ece0:  9e 5a c0 11  smul  %o3, %l1, %o7
a012ece4:  98 03 c0 0d  add  %o7, %o5, %o4
a012ece8:  bb 2a a0 10  sll  %o2, 0x10, %i5
a012ecec:  82 02 c0 0b  add  %o3, %o3, %g1
a012ecf0:  ac 00 40 14  add  %g1, %l4, %l6
a012ecf4:  af 33 20 02  srl  %o4, 2, %l7
a012ecf8:  a1 37 60 10  srl  %i5, 0x10, %l0
a012ecfc:  80 a4 20 03  cmp  %l0, 3
a012ed00:  08 bf ff f3  bleu  0xa012eccc
a012ed04:  ee 35 bf e0  sth  %l7, [ %l6 + -32 ]
a012ed08:  ee 17 bf d8  lduh  [ %fp + -40 ], %l7
a012ed0c:  ec 17 bf de  lduh  [ %fp + -34 ], %l6
a012ed10:  d0 17 bf da  lduh  [ %fp + -38 ], %o0
a012ed14:  d2 17 bf dc  lduh  [ %fp + -36 ], %o1
a012ed18:  95 35 e0 06  srl  %l7, 6, %o2
a012ed1c:  83 2d e0 02  sll  %l7, 2, %g1
a012ed20:  97 2d a0 02  sll  %l6, 2, %o3
a012ed24:  9f 32 60 06  srl  %o1, 6, %o7
a012ed28:  9b 2a 20 02  sll  %o0, 2, %o5
a012ed2c:  99 2a 60 02  sll  %o1, 2, %o4
a012ed30:  a1 32 20 06  srl  %o0, 6, %l0
a012ed34:  af 2f 20 10  sll  %i4, 0x10, %l7
a012ed38:  d4 2f bf e9  stb  %o2, [ %fp + -23 ]
a012ed3c:  d6 2f bf ee  stb  %o3, [ %fp + -18 ]
a012ed40:  bb 35 a0 06  srl  %l6, 6, %i5
a012ed44:  93 35 e0 10  srl  %l7, 0x10, %o1
a012ed48:  90 10 00 18  mov  %i0, %o0
a012ed4c:  c2 2f bf e8  stb  %g1, [ %fp + -24 ]
a012ed50:  da 2f bf ea  stb  %o5, [ %fp + -22 ]
a012ed54:  e0 2f bf eb  stb  %l0, [ %fp + -21 ]
a012ed58:  d8 2f bf ec  stb  %o4, [ %fp + -20 ]
a012ed5c:  de 2f bf ed  stb  %o7, [ %fp + -19 ]
a012ed60:  fa 2f bf ef  stb  %i5, [ %fp + -17 ]
a012ed64:  94 10 20 08  mov  8, %o2
a012ed68:  7f ff 70 49  call  0xa010ae8c
a012ed6c:  96 10 00 1b  mov  %i3, %o3
a012ed70:  92 04 e0 01  add  %l3, 1, %o1
a012ed74:  91 2a 60 10  sll  %o1, 0x10, %o0
a012ed78:  a7 32 20 10  srl  %o0, 0x10, %l3
a012ed7c:  80 a4 e1 3e  cmp  %l3, 0x13e
a012ed80:  90 10 00 11  mov  %l1, %o0
a012ed84:  b8 07 20 04  add  %i4, 4, %i4
a012ed88:  08 bf ff b7  bleu  0xa012ec64
a012ed8c:  a6 10 00 09  mov  %o1, %l3
a012ed90:  e6 0e 61 3f  ldub  [ %i1 + 0x13f ], %l3
a012ed94:  b3 2c e0 02  sll  %l3, 2, %i1
a012ed98:  a2 0c a0 03  and  %l2, 3, %l1
a012ed9c:  aa 06 40 11  add  %i1, %l1, %l5
a012eda0:  a5 2d 60 04  sll  %l5, 4, %l2
a012eda4:  b2 04 a0 0f  add  %l2, 0xf, %i1
a012eda8:  94 10 20 00  clr  %o2
a012edac:  92 10 20 08  mov  8, %o1
a012edb0:  ab 2a a0 10  sll  %o2, 0x10, %l5
a012edb4:  83 35 60 10  srl  %l5, 0x10, %g1
a012edb8:  a4 22 40 01  sub  %o1, %g1, %l2
a012edbc:  94 02 a0 01  inc  %o2
a012edc0:  ae 5c 80 08  smul  %l2, %o0, %l7
a012edc4:  ac 58 40 19  smul  %g1, %i1, %l6
a012edc8:  a0 05 80 17  add  %l6, %l7, %l0
a012edcc:  97 2a a0 10  sll  %o2, 0x10, %o3
a012edd0:  9a 00 40 01  add  %g1, %g1, %o5
a012edd4:  9e 03 40 14  add  %o5, %l4, %o7
a012edd8:  99 34 20 03  srl  %l0, 3, %o4
a012eddc:  bb 32 e0 10  srl  %o3, 0x10, %i5
a012ede0:  80 a7 60 07  cmp  %i5, 7
a012ede4:  08 bf ff f3  bleu  0xa012edb0
a012ede8:  d8 33 ff e0  sth  %o4, [ %o7 + -32 ]
a012edec:  da 17 bf d8  lduh  [ %fp + -40 ], %o5
a012edf0:  d8 17 bf da  lduh  [ %fp + -38 ], %o4
a012edf4:  a3 33 60 06  srl  %o5, 6, %l1
a012edf8:  83 2b 60 02  sll  %o5, 2, %g1
a012edfc:  d6 17 bf dc  lduh  [ %fp + -36 ], %o3
a012ee00:  a5 33 20 06  srl  %o4, 6, %l2
a012ee04:  9b 2b 20 02  sll  %o4, 2, %o5
a012ee08:  d4 17 bf de  lduh  [ %fp + -34 ], %o2
a012ee0c:  a7 32 e0 06  srl  %o3, 6, %l3
a012ee10:  99 2a e0 02  sll  %o3, 2, %o4
a012ee14:  d0 17 bf e0  lduh  [ %fp + -32 ], %o0
a012ee18:  97 2a a0 02  sll  %o2, 2, %o3
a012ee1c:  a9 32 a0 06  srl  %o2, 6, %l4
a012ee20:  de 17 bf e2  lduh  [ %fp + -30 ], %o7
a012ee24:  95 2a 20 02  sll  %o0, 2, %o2
a012ee28:  af 32 20 06  srl  %o0, 6, %l7
a012ee2c:  91 2b e0 02  sll  %o7, 2, %o0
a012ee30:  ea 17 bf e4  lduh  [ %fp + -28 ], %l5
a012ee34:  ad 33 e0 06  srl  %o7, 6, %l6
a012ee38:  93 2f 20 10  sll  %i4, 0x10, %o1
a012ee3c:  a1 35 60 06  srl  %l5, 6, %l0
a012ee40:  bb 36 60 06  srl  %i1, 6, %i5
a012ee44:  9f 2d 60 02  sll  %l5, 2, %o7
a012ee48:  b9 2e 60 02  sll  %i1, 2, %i4
a012ee4c:  d6 2f bf ee  stb  %o3, [ %fp + -18 ]
a012ee50:  d4 2f bf f0  stb  %o2, [ %fp + -16 ]
a012ee54:  d0 2f bf f2  stb  %o0, [ %fp + -14 ]
a012ee58:  c2 2f bf e8  stb  %g1, [ %fp + -24 ]
a012ee5c:  e2 2f bf e9  stb  %l1, [ %fp + -23 ]
a012ee60:  da 2f bf ea  stb  %o5, [ %fp + -22 ]
a012ee64:  e4 2f bf eb  stb  %l2, [ %fp + -21 ]
a012ee68:  d8 2f bf ec  stb  %o4, [ %fp + -20 ]
a012ee6c:  e6 2f bf ed  stb  %l3, [ %fp + -19 ]
a012ee70:  e8 2f bf ef  stb  %l4, [ %fp + -17 ]
a012ee74:  ee 2f bf f1  stb  %l7, [ %fp + -15 ]
a012ee78:  ec 2f bf f3  stb  %l6, [ %fp + -13 ]
a012ee7c:  de 2f bf f4  stb  %o7, [ %fp + -12 ]
a012ee80:  e0 2f bf f5  stb  %l0, [ %fp + -11 ]
a012ee84:  f8 2f bf f6  stb  %i4, [ %fp + -10 ]
a012ee88:  fa 2f bf f7  stb  %i5, [ %fp + -9 ]
a012ee8c:  f2 37 bf e6  sth  %i1, [ %fp + -26 ]
a012ee90:  90 10 00 18  mov  %i0, %o0
a012ee94:  93 32 60 10  srl  %o1, 0x10, %o1
a012ee98:  96 10 00 1b  mov  %i3, %o3
a012ee9c:  7f ff 6f fc  call  0xa010ae8c
a012eea0:  94 10 20 10  mov  0x10, %o2
a012eea4:  01 00 00 00  nop
a012eea8:  81 c7 e0 08  ret
a012eeac:  81 e8 00 00  restore
