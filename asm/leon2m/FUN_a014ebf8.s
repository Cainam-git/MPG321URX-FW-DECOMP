# leon2m FUN_a014ebf8 0xa014ebf8-0xa014f208 (1552 bytes)
a014ebf8:  9d e3 bf 90  save  %sp, -112, %sp
a014ebfc:  b0 0e 20 ff  and  %i0, 0xff, %i0
a014ec00:  80 a6 20 04  cmp  %i0, 4
a014ec04:  02 80 00 40  be  0xa014ed04
a014ec08:  80 a6 20 06  cmp  %i0, 6
a014ec0c:  02 80 00 aa  be  0xa014eeb4
a014ec10:  25 2a 00 b3  sethi  %hi(0xa802cc00), %l2
a014ec14:  9e 10 20 01  mov  1, %o7
a014ec18:  a8 10 20 03  mov  3, %l4
a014ec1c:  a2 10 00 12  mov  %l2, %l1
a014ec20:  de 2f bf f0  stb  %o7, [ %fp + -16 ]
a014ec24:  e8 2f bf f1  stb  %l4, [ %fp + -15 ]
a014ec28:  a0 10 20 04  mov  4, %l0
a014ec2c:  96 10 20 00  clr  %o3
a014ec30:  92 07 bf f8  add  %fp, -8, %o1
a014ec34:  98 10 20 00  clr  %o4
a014ec38:  d4 14 a0 80  lduh  [ %l2 + 0x80 ], %o2
a014ec3c:  82 02 40 0c  add  %o1, %o4, %g1
a014ec40:  d0 08 7f f8  ldub  [ %g1 + -8 ], %o0
a014ec44:  9b 2a 20 02  sll  %o0, 2, %o5
a014ec48:  a7 3a 80 0d  sra  %o2, %o5, %l3
a014ec4c:  80 8c e0 0f  btst  0xf, %l3
a014ec50:  02 80 01 00  be  0xa014f050
a014ec54:  96 02 e0 01  inc  %o3
a014ec58:  98 0a e0 ff  and  %o3, 0xff, %o4
a014ec5c:  80 a3 20 01  cmp  %o4, 1
a014ec60:  08 bf ff f8  bleu  0xa014ec40
a014ec64:  82 02 40 0c  add  %o1, %o4, %g1
a014ec68:  13 00 06 9c  sethi  %hi(0x1a7000), %o1
a014ec6c:  a0 0c 20 ff  and  %l0, 0xff, %l0
a014ec70:  90 12 63 28  or  %o1, 0x328, %o0
a014ec74:  7f fe 41 3f  call  0xa00df170
a014ec78:  92 10 00 10  mov  %l0, %o1
a014ec7c:  80 a4 20 03  cmp  %l0, 3
a014ec80:  08 80 00 77  bleu  0xa014ee5c
a014ec84:  a7 2c 20 02  sll  %l0, 2, %l3
a014ec88:  15 2a 00 b3  sethi  %hi(0xa802cc00), %o2
a014ec8c:  e0 12 a0 82  lduh  [ %o2 + 0x82 ], %l0	! 0xa802cc82
a014ec90:  9f 2c 20 10  sll  %l0, 0x10, %o7
a014ec94:  a3 33 e0 14  srl  %o7, 0x14, %l1
a014ec98:  a9 2e 20 0c  sll  %i0, 0xc, %l4
a014ec9c:  98 14 40 14  or  %l1, %l4, %o4
a014eca0:  d8 32 a0 82  sth  %o4, [ %o2 + 0x82 ]
a014eca4:  d4 14 a0 80  lduh  [ %l2 + 0x80 ], %o2
a014eca8:  96 0c 20 0f  and  %l0, 0xf, %o3
a014ecac:  98 10 20 00  clr  %o4
a014ecb0:  9a 10 20 00  clr  %o5
a014ecb4:  92 10 00 0a  mov  %o2, %o1
a014ecb8:  91 2b 60 02  sll  %o5, 2, %o0
a014ecbc:  a7 3a 80 08  sra  %o2, %o0, %l3
a014ecc0:  a4 0c e0 0f  and  %l3, 0xf, %l2
a014ecc4:  80 a4 80 0b  cmp  %l2, %o3
a014ecc8:  02 80 00 06  be  0xa014ece0
a014eccc:  98 03 20 01  inc  %o4
a014ecd0:  9a 0b 20 ff  and  %o4, 0xff, %o5
a014ecd4:  80 a3 60 03  cmp  %o5, 3
a014ecd8:  08 bf ff f9  bleu  0xa014ecbc
a014ecdc:  91 2b 60 02  sll  %o5, 2, %o0
a014ece0:  a1 2b 60 02  sll  %o5, 2, %l0
a014ece4:  98 10 20 0f  mov  0xf, %o4
a014ece8:  95 2b 00 10  sll  %o4, %l0, %o2
a014ecec:  83 2e 00 10  sll  %i0, %l0, %g1
a014ecf0:  96 2a 40 0a  andn  %o1, %o2, %o3
a014ecf4:  9a 12 c0 01  or  %o3, %g1, %o5
a014ecf8:  31 2a 00 b3  sethi  %hi(0xa802cc00), %i0
a014ecfc:  10 80 01 41  b  0xa014f200
a014ed00:  da 36 20 80  sth  %o5, [ %i0 + 0x80 ]	! 0xa802cc80
a014ed04:  29 2a 00 b3  sethi  %hi(0xa802cc00), %l4
a014ed08:  c2 15 20 80  lduh  [ %l4 + 0x80 ], %g1	! 0xa802cc80
a014ed0c:  a2 88 60 0f  andcc  %g1, 0xf, %l1
a014ed10:  22 80 00 c4  be,a   0xa014f020
a014ed14:  e2 15 20 80  lduh  [ %l4 + 0x80 ], %l1
a014ed18:  98 10 20 03  mov  3, %o4
a014ed1c:  83 28 60 10  sll  %g1, 0x10, %g1
a014ed20:  9a 10 20 01  mov  1, %o5
a014ed24:  d8 2f bf f1  stb  %o4, [ %fp + -15 ]
a014ed28:  da 2f bf f0  stb  %o5, [ %fp + -16 ]
a014ed2c:  95 30 60 10  srl  %g1, 0x10, %o2
a014ed30:  92 10 20 04  mov  4, %o1
a014ed34:  98 10 20 00  clr  %o4
a014ed38:  96 10 20 00  clr  %o3
a014ed3c:  90 07 bf f8  add  %fp, -8, %o0
a014ed40:  a4 10 00 14  mov  %l4, %l2
a014ed44:  82 02 00 0b  add  %o0, %o3, %g1
a014ed48:  e6 08 7f f8  ldub  [ %g1 + -8 ], %l3
a014ed4c:  a1 2c e0 02  sll  %l3, 2, %l0
a014ed50:  9f 3a 80 10  sra  %o2, %l0, %o7
a014ed54:  80 8b e0 0f  btst  0xf, %o7
a014ed58:  02 80 01 1e  be  0xa014f1d0
a014ed5c:  98 03 20 01  inc  %o4
a014ed60:  96 0b 20 ff  and  %o4, 0xff, %o3
a014ed64:  80 a2 e0 01  cmp  %o3, 1
a014ed68:  08 bf ff f8  bleu  0xa014ed48
a014ed6c:  82 02 00 0b  add  %o0, %o3, %g1
a014ed70:  a0 0a 60 ff  and  %o1, 0xff, %l0
a014ed74:  11 00 06 9c  sethi  %hi(0x1a7000), %o0
a014ed78:  90 12 23 28  or  %o0, 0x328, %o0	! 0x1a7328
a014ed7c:  7f fe 40 fd  call  0xa00df170
a014ed80:  92 10 00 10  mov  %l0, %o1
a014ed84:  80 a4 20 03  cmp  %l0, 3
a014ed88:  08 80 00 bc  bleu  0xa014f078
a014ed8c:  97 2c 20 02  sll  %l0, 2, %o3
a014ed90:  13 2a 00 b3  sethi  %hi(0xa802cc00), %o1
a014ed94:  d6 12 60 82  lduh  [ %o1 + 0x82 ], %o3	! 0xa802cc82
a014ed98:  9b 2a e0 10  sll  %o3, 0x10, %o5
a014ed9c:  b1 33 60 14  srl  %o5, 0x14, %i0
a014eda0:  19 00 00 10  sethi  %hi(0x4000), %o4
a014eda4:  a4 16 00 0c  or  %i0, %o4, %l2
a014eda8:  e4 32 60 82  sth  %l2, [ %o1 + 0x82 ]
a014edac:  d2 15 20 80  lduh  [ %l4 + 0x80 ], %o1
a014edb0:  96 0a e0 0f  and  %o3, 0xf, %o3
a014edb4:  9a 10 20 00  clr  %o5
a014edb8:  94 10 20 00  clr  %o2
a014edbc:  98 10 00 09  mov  %o1, %o4
a014edc0:  a7 2a a0 02  sll  %o2, 2, %l3
a014edc4:  a1 3b 00 13  sra  %o4, %l3, %l0
a014edc8:  9e 0c 20 0f  and  %l0, 0xf, %o7
a014edcc:  80 a3 c0 0b  cmp  %o7, %o3
a014edd0:  02 80 00 06  be  0xa014ede8
a014edd4:  9a 03 60 01  inc  %o5
a014edd8:  94 0b 60 ff  and  %o5, 0xff, %o2
a014eddc:  80 a2 a0 03  cmp  %o2, 3
a014ede0:  28 bf ff f9  bleu,a   0xa014edc4
a014ede4:  a7 2a a0 02  sll  %o2, 2, %l3
a014ede8:  b1 2a a0 02  sll  %o2, 2, %i0
a014edec:  9a 10 20 0f  mov  0xf, %o5
a014edf0:  99 2b 40 18  sll  %o5, %i0, %o4
a014edf4:  a4 2a 40 0c  andn  %o1, %o4, %l2
a014edf8:  93 2c 40 18  sll  %l1, %i0, %o1
a014edfc:  96 14 80 09  or  %l2, %o1, %o3
a014ee00:  11 2a 00 b3  sethi  %hi(0xa802cc00), %o0
a014ee04:  03 2a 00 a9  sethi  %hi(0xa802a400), %g1
a014ee08:  d6 32 20 80  sth  %o3, [ %o0 + 0x80 ]
a014ee0c:  a4 10 00 0a  mov  %o2, %l2
a014ee10:  a6 10 60 80  or  %g1, 0x80, %l3
a014ee14:  a0 10 20 00  clr  %l0
a014ee18:  10 80 00 06  b  0xa014ee30
a014ee1c:  92 10 20 00  clr  %o1
a014ee20:  92 0c 20 ff  and  %l0, 0xff, %o1
a014ee24:  80 a2 60 08  cmp  %o1, 8
a014ee28:  38 80 00 7e  bgu,a   0xa014f020
a014ee2c:  e2 15 20 80  lduh  [ %l4 + 0x80 ], %l1
a014ee30:  d4 0c c0 09  ldub  [ %l3 + %o1 ], %o2
a014ee34:  80 a4 40 0a  cmp  %l1, %o2
a014ee38:  a0 04 20 01  inc  %l0
a014ee3c:  90 10 00 11  mov  %l1, %o0
a014ee40:  94 0c a0 ff  and  %l2, 0xff, %o2
a014ee44:  12 bf ff f7  bne  0xa014ee20
a014ee48:  96 10 20 01  mov  1, %o3
a014ee4c:  7f ff a5 fc  call  0xa013863c
a014ee50:  01 00 00 00  nop
a014ee54:  10 bf ff f4  b  0xa014ee24
a014ee58:  92 0c 20 ff  and  %l0, 0xff, %o1
a014ee5c:  9a 10 20 0f  mov  0xf, %o5
a014ee60:  d6 14 60 80  lduh  [ %l1 + 0x80 ], %o3
a014ee64:  91 2b 40 13  sll  %o5, %l3, %o0
a014ee68:  92 2a c0 08  andn  %o3, %o0, %o1
a014ee6c:  a5 2e 00 13  sll  %i0, %l3, %l2
a014ee70:  9e 12 40 12  or  %o1, %l2, %o7
a014ee74:  13 2a 00 b3  sethi  %hi(0xa802cc00), %o1
a014ee78:  d0 12 60 82  lduh  [ %o1 + 0x82 ], %o0	! 0xa802cc82
a014ee7c:  de 34 60 80  sth  %o7, [ %l1 + 0x80 ]
a014ee80:  96 10 20 00  clr  %o3
a014ee84:  98 10 20 00  clr  %o4
a014ee88:  94 10 00 08  mov  %o0, %o2
a014ee8c:  9b 2b 20 02  sll  %o4, 2, %o5
a014ee90:  96 02 e0 01  inc  %o3
a014ee94:  83 3a 80 0d  sra  %o2, %o5, %g1
a014ee98:  80 88 60 0f  btst  0xf, %g1
a014ee9c:  02 80 00 73  be  0xa014f068
a014eea0:  98 0a e0 ff  and  %o3, 0xff, %o4
a014eea4:  80 a3 20 03  cmp  %o4, 3
a014eea8:  28 bf ff fa  bleu,a   0xa014ee90
a014eeac:  9b 2b 20 02  sll  %o4, 2, %o5
a014eeb0:  30 80 00 d4  b,a   0xa014f200
a014eeb4:  29 2a 00 b3  sethi  %hi(0xa802cc00), %l4
a014eeb8:  e0 15 20 80  lduh  [ %l4 + 0x80 ], %l0	! 0xa802cc80
a014eebc:  99 2c 20 10  sll  %l0, 0x10, %o4
a014eec0:  9f 33 20 18  srl  %o4, 0x18, %o7
a014eec4:  a2 8b e0 0f  andcc  %o7, 0xf, %l1
a014eec8:  22 80 00 5e  be,a   0xa014f040
a014eecc:  e2 15 20 80  lduh  [ %l4 + 0x80 ], %l1
a014eed0:  82 10 20 01  mov  1, %g1
a014eed4:  a6 10 20 03  mov  3, %l3
a014eed8:  95 33 20 10  srl  %o4, 0x10, %o2
a014eedc:  c2 2f bf f0  stb  %g1, [ %fp + -16 ]
a014eee0:  e6 2f bf f1  stb  %l3, [ %fp + -15 ]
a014eee4:  92 10 20 04  mov  4, %o1
a014eee8:  96 10 20 00  clr  %o3
a014eeec:  90 07 bf f8  add  %fp, -8, %o0
a014eef0:  98 10 20 00  clr  %o4
a014eef4:  a4 10 00 14  mov  %l4, %l2
a014eef8:  a6 02 00 0c  add  %o0, %o4, %l3
a014eefc:  e0 0c ff f8  ldub  [ %l3 + -8 ], %l0
a014ef00:  9f 2c 20 02  sll  %l0, 2, %o7
a014ef04:  9b 3a 80 0f  sra  %o2, %o7, %o5
a014ef08:  80 8b 60 0f  btst  0xf, %o5
a014ef0c:  02 80 00 b7  be  0xa014f1e8
a014ef10:  96 02 e0 01  inc  %o3
a014ef14:  98 0a e0 ff  and  %o3, 0xff, %o4
a014ef18:  80 a3 20 01  cmp  %o4, 1
a014ef1c:  08 bf ff f8  bleu  0xa014eefc
a014ef20:  a6 02 00 0c  add  %o0, %o4, %l3
a014ef24:  a0 0a 60 ff  and  %o1, 0xff, %l0
a014ef28:  11 00 06 9c  sethi  %hi(0x1a7000), %o0
a014ef2c:  90 12 23 28  or  %o0, 0x328, %o0	! 0x1a7328
a014ef30:  7f fe 40 90  call  0xa00df170
a014ef34:  92 10 00 10  mov  %l0, %o1
a014ef38:  80 a4 20 03  cmp  %l0, 3
a014ef3c:  08 80 00 7a  bleu  0xa014f124
a014ef40:  91 2c 20 02  sll  %l0, 2, %o0
a014ef44:  15 2a 00 b3  sethi  %hi(0xa802cc00), %o2
a014ef48:  d2 12 a0 82  lduh  [ %o2 + 0x82 ], %o1	! 0xa802cc82
a014ef4c:  83 2a 60 10  sll  %o1, 0x10, %g1
a014ef50:  a5 30 60 14  srl  %g1, 0x14, %l2
a014ef54:  31 00 00 18  sethi  %hi(0x6000), %i0
a014ef58:  98 14 80 18  or  %l2, %i0, %o4
a014ef5c:  96 0a 60 0f  and  %o1, 0xf, %o3
a014ef60:  d8 32 a0 82  sth  %o4, [ %o2 + 0x82 ]
a014ef64:  d2 15 20 80  lduh  [ %l4 + 0x80 ], %o1
a014ef68:  9a 10 20 00  clr  %o5
a014ef6c:  94 10 20 00  clr  %o2
a014ef70:  98 10 00 09  mov  %o1, %o4
a014ef74:  a7 2a a0 02  sll  %o2, 2, %l3
a014ef78:  a1 3b 00 13  sra  %o4, %l3, %l0
a014ef7c:  9e 0c 20 0f  and  %l0, 0xf, %o7
a014ef80:  80 a3 c0 0b  cmp  %o7, %o3
a014ef84:  02 80 00 06  be  0xa014ef9c
a014ef88:  9a 03 60 01  inc  %o5
a014ef8c:  94 0b 60 ff  and  %o5, 0xff, %o2
a014ef90:  80 a2 a0 03  cmp  %o2, 3
a014ef94:  28 bf ff f9  bleu,a   0xa014ef78
a014ef98:  a7 2a a0 02  sll  %o2, 2, %l3
a014ef9c:  a5 2a a0 02  sll  %o2, 2, %l2
a014efa0:  82 10 20 0f  mov  0xf, %g1
a014efa4:  b1 28 40 12  sll  %g1, %l2, %i0
a014efa8:  98 2a 40 18  andn  %o1, %i0, %o4
a014efac:  93 2c 40 12  sll  %l1, %l2, %o1
a014efb0:  90 13 00 09  or  %o4, %o1, %o0
a014efb4:  17 2a 00 b3  sethi  %hi(0xa802cc00), %o3
a014efb8:  1b 2a 00 a9  sethi  %hi(0xa802a400), %o5
a014efbc:  d0 32 e0 80  sth  %o0, [ %o3 + 0x80 ]
a014efc0:  a4 10 00 0a  mov  %o2, %l2
a014efc4:  a6 13 60 80  or  %o5, 0x80, %l3
a014efc8:  a0 10 20 00  clr  %l0
a014efcc:  10 80 00 06  b  0xa014efe4
a014efd0:  92 10 20 00  clr  %o1
a014efd4:  92 0c 20 ff  and  %l0, 0xff, %o1
a014efd8:  80 a2 60 08  cmp  %o1, 8
a014efdc:  38 80 00 19  bgu,a   0xa014f040
a014efe0:  e2 15 20 80  lduh  [ %l4 + 0x80 ], %l1
a014efe4:  d4 0c c0 09  ldub  [ %l3 + %o1 ], %o2
a014efe8:  80 a4 40 0a  cmp  %l1, %o2
a014efec:  a0 04 20 01  inc  %l0
a014eff0:  90 10 00 11  mov  %l1, %o0
a014eff4:  94 0c a0 ff  and  %l2, 0xff, %o2
a014eff8:  12 bf ff f7  bne  0xa014efd4
a014effc:  96 10 20 01  mov  1, %o3
a014f000:  7f ff a5 8f  call  0xa013863c
a014f004:  01 00 00 00  nop
a014f008:  10 bf ff f4  b  0xa014efd8
a014f00c:  92 0c 20 ff  and  %l0, 0xff, %o1
a014f010:  9f 2e 00 0d  sll  %i0, %o5, %o7
a014f014:  a2 13 c0 08  or  %o7, %o0, %l1
a014f018:  e2 32 60 82  sth  %l1, [ %o1 + 0x82 ]
a014f01c:  e2 15 20 80  lduh  [ %l4 + 0x80 ], %l1
a014f020:  b0 0c 7f f0  and  %l1, -16, %i0
a014f024:  82 16 20 04  or  %i0, 4, %g1
a014f028:  10 80 00 76  b  0xa014f200
a014f02c:  c2 35 20 80  sth  %g1, [ %l4 + 0x80 ]
a014f030:  9f 2e 00 0d  sll  %i0, %o5, %o7
a014f034:  a2 13 c0 08  or  %o7, %o0, %l1
a014f038:  e2 32 60 82  sth  %l1, [ %o1 + 0x82 ]
a014f03c:  e2 15 20 80  lduh  [ %l4 + 0x80 ], %l1
a014f040:  b0 0c 70 ff  and  %l1, -3841, %i0
a014f044:  82 16 26 00  or  %i0, 0x600, %g1
a014f048:  10 80 00 6e  b  0xa014f200
a014f04c:  c2 35 20 80  sth  %g1, [ %l4 + 0x80 ]
a014f050:  80 a3 20 01  cmp  %o4, 1
a014f054:  38 bf ff 06  bgu,a   0xa014ec6c
a014f058:  13 00 06 9c  sethi  %hi(0x1a7000), %o1
a014f05c:  96 02 40 0c  add  %o1, %o4, %o3
a014f060:  10 bf ff 02  b  0xa014ec68
a014f064:  e0 0a ff f8  ldub  [ %o3 + -8 ], %l0
a014f068:  a9 2e 00 0d  sll  %i0, %o5, %l4
a014f06c:  a2 15 00 08  or  %l4, %o0, %l1
a014f070:  10 80 00 64  b  0xa014f200
a014f074:  e2 32 60 82  sth  %l1, [ %o1 + 0x82 ]
a014f078:  94 10 20 0f  mov  0xf, %o2
a014f07c:  da 14 a0 80  lduh  [ %l2 + 0x80 ], %o5
a014f080:  93 2a 80 0b  sll  %o2, %o3, %o1
a014f084:  82 2b 40 09  andn  %o5, %o1, %g1
a014f088:  91 2c 40 0b  sll  %l1, %o3, %o0
a014f08c:  a6 10 40 08  or  %g1, %o0, %l3
a014f090:  e6 34 a0 80  sth  %l3, [ %l2 + 0x80 ]
a014f094:  a4 10 00 10  mov  %l0, %l2
a014f098:  21 2a 00 a9  sethi  %hi(0xa802a400), %l0
a014f09c:  a6 14 20 80  or  %l0, 0x80, %l3	! 0xa802a480
a014f0a0:  a0 10 20 00  clr  %l0
a014f0a4:  10 80 00 06  b  0xa014f0bc
a014f0a8:  92 10 20 00  clr  %o1
a014f0ac:  92 0c 20 ff  and  %l0, 0xff, %o1
a014f0b0:  80 a2 60 08  cmp  %o1, 8
a014f0b4:  38 80 00 0d  bgu,a   0xa014f0e8
a014f0b8:  13 2a 00 b3  sethi  %hi(0xa802cc00), %o1
a014f0bc:  d8 0c c0 09  ldub  [ %l3 + %o1 ], %o4
a014f0c0:  a0 04 20 01  inc  %l0
a014f0c4:  80 a4 40 0c  cmp  %l1, %o4
a014f0c8:  90 10 00 11  mov  %l1, %o0
a014f0cc:  94 0c a0 ff  and  %l2, 0xff, %o2
a014f0d0:  12 bf ff f7  bne  0xa014f0ac
a014f0d4:  96 10 20 01  mov  1, %o3
a014f0d8:  7f ff a5 59  call  0xa013863c
a014f0dc:  01 00 00 00  nop
a014f0e0:  10 bf ff f4  b  0xa014f0b0
a014f0e4:  92 0c 20 ff  and  %l0, 0xff, %o1
a014f0e8:  d0 12 60 82  lduh  [ %o1 + 0x82 ], %o0
a014f0ec:  96 10 20 00  clr  %o3
a014f0f0:  98 10 20 00  clr  %o4
a014f0f4:  94 10 00 08  mov  %o0, %o2
a014f0f8:  9b 2b 20 02  sll  %o4, 2, %o5
a014f0fc:  96 02 e0 01  inc  %o3
a014f100:  a5 3a 80 0d  sra  %o2, %o5, %l2
a014f104:  80 8c a0 0f  btst  0xf, %l2
a014f108:  02 bf ff c2  be  0xa014f010
a014f10c:  98 0a e0 ff  and  %o3, 0xff, %o4
a014f110:  80 a3 20 03  cmp  %o4, 3
a014f114:  28 bf ff fa  bleu,a   0xa014f0fc
a014f118:  9b 2b 20 02  sll  %o4, 2, %o5
a014f11c:  10 bf ff c1  b  0xa014f020
a014f120:  e2 15 20 80  lduh  [ %l4 + 0x80 ], %l1
a014f124:  82 10 20 0f  mov  0xf, %g1
a014f128:  d4 14 a0 80  lduh  [ %l2 + 0x80 ], %o2
a014f12c:  93 28 40 08  sll  %g1, %o0, %o1
a014f130:  96 2a 80 09  andn  %o2, %o1, %o3
a014f134:  9b 2c 40 08  sll  %l1, %o0, %o5
a014f138:  a6 12 c0 0d  or  %o3, %o5, %l3
a014f13c:  e6 34 a0 80  sth  %l3, [ %l2 + 0x80 ]
a014f140:  a4 10 00 10  mov  %l0, %l2
a014f144:  21 2a 00 a9  sethi  %hi(0xa802a400), %l0
a014f148:  a6 14 20 80  or  %l0, 0x80, %l3	! 0xa802a480
a014f14c:  a0 10 20 00  clr  %l0
a014f150:  10 80 00 06  b  0xa014f168
a014f154:  92 10 20 00  clr  %o1
a014f158:  92 0c 20 ff  and  %l0, 0xff, %o1
a014f15c:  80 a2 60 08  cmp  %o1, 8
a014f160:  38 80 00 0d  bgu,a   0xa014f194
a014f164:  13 2a 00 b3  sethi  %hi(0xa802cc00), %o1
a014f168:  d8 0c c0 09  ldub  [ %l3 + %o1 ], %o4
a014f16c:  a0 04 20 01  inc  %l0
a014f170:  80 a4 40 0c  cmp  %l1, %o4
a014f174:  90 10 00 11  mov  %l1, %o0
a014f178:  94 0c a0 ff  and  %l2, 0xff, %o2
a014f17c:  12 bf ff f7  bne  0xa014f158
a014f180:  96 10 20 01  mov  1, %o3
a014f184:  7f ff a5 2e  call  0xa013863c
a014f188:  01 00 00 00  nop
a014f18c:  10 bf ff f4  b  0xa014f15c
a014f190:  92 0c 20 ff  and  %l0, 0xff, %o1
a014f194:  d0 12 60 82  lduh  [ %o1 + 0x82 ], %o0
a014f198:  96 10 20 00  clr  %o3
a014f19c:  98 10 20 00  clr  %o4
a014f1a0:  94 10 00 08  mov  %o0, %o2
a014f1a4:  9b 2b 20 02  sll  %o4, 2, %o5
a014f1a8:  96 02 e0 01  inc  %o3
a014f1ac:  a5 3a 80 0d  sra  %o2, %o5, %l2
a014f1b0:  80 8c a0 0f  btst  0xf, %l2
a014f1b4:  02 bf ff 9f  be  0xa014f030
a014f1b8:  98 0a e0 ff  and  %o3, 0xff, %o4
a014f1bc:  80 a3 20 03  cmp  %o4, 3
a014f1c0:  28 bf ff fa  bleu,a   0xa014f1a8
a014f1c4:  9b 2b 20 02  sll  %o4, 2, %o5
a014f1c8:  10 bf ff 9e  b  0xa014f040
a014f1cc:  e2 15 20 80  lduh  [ %l4 + 0x80 ], %l1
a014f1d0:  80 a2 e0 01  cmp  %o3, 1
a014f1d4:  18 bf fe e8  bgu  0xa014ed74
a014f1d8:  a0 0a 60 ff  and  %o1, 0xff, %l0
a014f1dc:  94 02 00 0b  add  %o0, %o3, %o2
a014f1e0:  10 bf fe e4  b  0xa014ed70
a014f1e4:  d2 0a bf f8  ldub  [ %o2 + -8 ], %o1
a014f1e8:  80 a3 20 01  cmp  %o4, 1
a014f1ec:  18 bf ff 4f  bgu  0xa014ef28
a014f1f0:  a0 0a 60 ff  and  %o1, 0xff, %l0
a014f1f4:  96 02 00 0c  add  %o0, %o4, %o3
a014f1f8:  10 bf ff 4b  b  0xa014ef24
a014f1fc:  d2 0a ff f8  ldub  [ %o3 + -8 ], %o1
a014f200:  81 c7 e0 08  ret
a014f204:  81 e8 00 00  restore
