# leon2m FUN_a009eb38 0xa009eb38-0xa009f184 (1612 bytes)
a009eb38:  9d e3 bf 98  save  %sp, -104, %sp
a009eb3c:  a2 10 20 01  mov  1, %l1
a009eb40:  a0 10 20 00  clr  %l0
a009eb44:  10 80 00 05  b  0xa009eb58
a009eb48:  b2 10 20 00  clr  %i1
a009eb4c:  80 a6 60 03  cmp  %i1, 3
a009eb50:  18 80 00 10  bgu  0xa009eb90
a009eb54:  80 8c 60 ff  btst  0xff, %l1
a009eb58:  7f ff 85 f2  call  0xa0080320
a009eb5c:  90 10 00 19  mov  %i1, %o0
a009eb60:  80 8a 20 ff  btst  0xff, %o0
a009eb64:  a0 04 20 01  inc  %l0
a009eb68:  90 10 00 19  mov  %i1, %o0
a009eb6c:  02 bf ff f8  be  0xa009eb4c
a009eb70:  b2 0c 20 ff  and  %l0, 0xff, %i1
a009eb74:  40 02 94 28  call  0xa0143c14
a009eb78:  01 00 00 00  nop
a009eb7c:  80 8a 20 ff  btst  0xff, %o0
a009eb80:  02 bf ff f4  be  0xa009eb50
a009eb84:  80 a6 60 03  cmp  %i1, 3
a009eb88:  a2 10 20 00  clr  %l1
a009eb8c:  80 8c 60 ff  btst  0xff, %l1
a009eb90:  12 80 01 7b  bne  0xa009f17c
a009eb94:  25 2a 00 b3  sethi  %hi(0xa802cc00), %l2
a009eb98:  96 14 a3 f4  or  %l2, 0x3f4, %o3	! 0xa802cff4
a009eb9c:  c2 12 e0 04  lduh  [ %o3 + 4 ], %g1
a009eba0:  11 00 00 18  sethi  %hi(0x6000), %o0
a009eba4:  9a 0a 00 01  and  %o0, %g1, %o5
a009eba8:  19 00 00 08  sethi  %hi(0x2000), %o4
a009ebac:  80 a3 40 0c  cmp  %o5, %o4
a009ebb0:  02 80 01 73  be  0xa009f17c
a009ebb4:  82 0e 20 c0  and  %i0, 0xc0, %g1
a009ebb8:  80 a0 60 40  cmp  %g1, 0x40
a009ebbc:  02 80 00 3e  be  0xa009ecb4
a009ebc0:  80 a0 60 00  cmp  %g1, 0
a009ebc4:  12 80 01 6e  bne  0xa009f17c
a009ebc8:  9a 0e 20 3f  and  %i0, 0x3f, %o5
a009ebcc:  27 00 04 20  sethi  %hi(0x108000), %l3
a009ebd0:  b0 14 e0 b8  or  %l3, 0xb8, %i0	! 0x1080b8
a009ebd4:  da 0e 00 0d  ldub  [ %i0 + %o5 ], %o5
a009ebd8:  80 a3 60 1e  cmp  %o5, 0x1e
a009ebdc:  02 80 01 68  be  0xa009f17c
a009ebe0:  29 2a 00 90  sethi  %hi(0xa8024000), %l4
a009ebe4:  93 2b 60 02  sll  %o5, 2, %o1
a009ebe8:  90 15 21 b0  or  %l4, 0x1b0, %o0
a009ebec:  da 02 00 09  ld  [ %o0 + %o1 ], %o5
a009ebf0:  80 a3 60 00  cmp  %o5, 0
a009ebf4:  02 80 01 62  be  0xa009f17c
a009ebf8:  01 00 00 00  nop
a009ebfc:  9f c3 40 00  call  %o5
a009ec00:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a009ec04:  67 ff ba 61  call  0x4008d588
a009ec08:  01 00 00 00  nop
a009ec0c:  d0 34 20 3c  sth  %o0, [ %l0 + 0x3c ]
a009ec10:  7f ff c9 21  call  0xa0091094
a009ec14:  81 e8 00 00  restore
a009ec18:  f2 0c 21 d6  ldub  [ %l0 + 0x1d6 ], %i1
a009ec1c:  80 a6 60 55  cmp  %i1, 0x55
a009ec20:  12 80 00 60  bne  0xa009eda0
a009ec24:  80 a4 60 06  cmp  %l1, 6
a009ec28:  9a 06 3f ff  add  %i0, -1, %o5
a009ec2c:  98 0b 60 ff  and  %o5, 0xff, %o4
a009ec30:  80 a3 20 03  cmp  %o4, 3
a009ec34:  18 80 00 5b  bgu  0xa009eda0
a009ec38:  80 a4 60 06  cmp  %l1, 6
a009ec3c:  40 02 a0 70  call  0xa0146dfc
a009ec40:  90 10 20 00  clr  %o0
a009ec44:  80 8a 20 ff  btst  0xff, %o0
a009ec48:  12 80 00 56  bne  0xa009eda0
a009ec4c:  80 a4 60 06  cmp  %l1, 6
a009ec50:  f0 0c 21 d5  ldub  [ %l0 + 0x1d5 ], %i0
a009ec54:  80 a6 20 00  cmp  %i0, 0
a009ec58:  12 80 00 52  bne  0xa009eda0
a009ec5c:  80 a4 60 06  cmp  %l1, 6
a009ec60:  80 a4 60 01  cmp  %l1, 1
a009ec64:  02 80 01 42  be  0xa009f16c
a009ec68:  90 10 20 02  mov  2, %o0
a009ec6c:  80 a4 60 02  cmp  %l1, 2
a009ec70:  02 80 01 3f  be  0xa009f16c
a009ec74:  90 10 20 03  mov  3, %o0
a009ec78:  80 a4 60 03  cmp  %l1, 3
a009ec7c:  02 80 01 3c  be  0xa009f16c
a009ec80:  90 10 20 01  mov  1, %o0
a009ec84:  80 a4 60 04  cmp  %l1, 4
a009ec88:  02 80 01 39  be  0xa009f16c
a009ec8c:  90 10 20 00  clr  %o0
a009ec90:  40 00 e9 6a  call  0xa00d9238
a009ec94:  29 2a 00 ac  sethi  %hi(0xa802b000), %l4
a009ec98:  90 10 20 04  mov  4, %o0
a009ec9c:  7f ff 87 04  call  0xa00808ac
a009eca0:  92 10 20 00  clr  %o1
a009eca4:  e2 0d 20 8e  ldub  [ %l4 + 0x8e ], %l1
a009eca8:  a0 14 60 02  or  %l1, 2, %l0
a009ecac:  10 80 01 34  b  0xa009f17c
a009ecb0:  e0 2d 20 8e  stb  %l0, [ %l4 + 0x8e ]
a009ecb4:  29 2a 00 ab  sethi  %hi(0xa802ac00), %l4
a009ecb8:  d4 05 23 ec  ld  [ %l4 + 0x3ec ], %o2	! 0xa802afec
a009ecbc:  92 02 be ed  add  %o2, -275, %o1
a009ecc0:  80 a2 60 01  cmp  %o1, 1
a009ecc4:  18 80 00 08  bgu  0xa009ece4
a009ecc8:  98 0e 20 3f  and  %i0, 0x3f, %o4
a009eccc:  21 2a 00 b5  sethi  %hi(0xa802d400), %l0
a009ecd0:  de 0c 20 65  ldub  [ %l0 + 0x65 ], %o7	! 0xa802d465
a009ecd4:  80 a3 e0 00  cmp  %o7, 0
a009ecd8:  32 80 00 7e  bne,a   0xa009eed0
a009ecdc:  e2 0a e0 06  ldub  [ %o3 + 6 ], %l1
a009ece0:  98 0e 20 3f  and  %i0, 0x3f, %o4
a009ece4:  31 00 04 20  sethi  %hi(0x108000), %i0
a009ece8:  9a 16 20 f8  or  %i0, 0xf8, %o5	! 0x1080f8
a009ecec:  f0 0b 40 0c  ldub  [ %o5 + %o4 ], %i0
a009ecf0:  a2 0e 20 ff  and  %i0, 0xff, %l1
a009ecf4:  80 a4 60 07  cmp  %l1, 7
a009ecf8:  02 80 00 83  be  0xa009ef04
a009ecfc:  80 a4 60 06  cmp  %l1, 6
a009ed00:  02 80 01 1f  be  0xa009f17c
a009ed04:  a6 10 20 01  mov  1, %l3
a009ed08:  b2 10 20 00  clr  %i1
a009ed0c:  10 80 00 05  b  0xa009ed20
a009ed10:  a0 10 20 00  clr  %l0
a009ed14:  80 a4 20 03  cmp  %l0, 3
a009ed18:  18 80 00 11  bgu  0xa009ed5c
a009ed1c:  80 8c e0 ff  btst  0xff, %l3
a009ed20:  7f ff 85 80  call  0xa0080320
a009ed24:  90 10 00 10  mov  %l0, %o0
a009ed28:  80 8a 20 ff  btst  0xff, %o0
a009ed2c:  b2 06 60 01  inc  %i1
a009ed30:  90 10 00 10  mov  %l0, %o0
a009ed34:  02 bf ff f8  be  0xa009ed14
a009ed38:  a0 0e 60 ff  and  %i1, 0xff, %l0
a009ed3c:  40 02 93 b6  call  0xa0143c14
a009ed40:  01 00 00 00  nop
a009ed44:  90 0a 20 ff  and  %o0, 0xff, %o0
a009ed48:  80 a2 20 04  cmp  %o0, 4
a009ed4c:  02 bf ff f3  be  0xa009ed18
a009ed50:  80 a4 20 03  cmp  %l0, 3
a009ed54:  a6 10 20 00  clr  %l3
a009ed58:  80 8c e0 ff  btst  0xff, %l3
a009ed5c:  02 80 00 3b  be  0xa009ee48
a009ed60:  d8 05 23 ec  ld  [ %l4 + 0x3ec ], %o4
a009ed64:  27 2a 00 b4  sethi  %hi(0xa802d000), %l3
a009ed68:  c2 04 e2 90  ld  [ %l3 + 0x290 ], %g1	! 0xa802d290
a009ed6c:  80 88 62 00  btst  0x200, %g1
a009ed70:  12 80 00 06  bne  0xa009ed88
a009ed74:  a0 14 e2 90  or  %l3, 0x290, %l0
a009ed78:  d2 0c 21 d5  ldub  [ %l0 + 0x1d5 ], %o1
a009ed7c:  80 a2 60 00  cmp  %o1, 0
a009ed80:  02 80 00 33  be  0xa009ee4c
a009ed84:  80 a0 00 0c  cmp  %g0, %o4
a009ed88:  17 00 00 15  sethi  %hi(0x5400), %o3
a009ed8c:  de 14 21 f6  lduh  [ %l0 + 0x1f6 ], %o7
a009ed90:  94 12 e1 aa  or  %o3, 0x1aa, %o2
a009ed94:  80 a3 c0 0a  cmp  %o7, %o2
a009ed98:  02 bf ff a0  be  0xa009ec18
a009ed9c:  80 a4 60 06  cmp  %l1, 6
a009eda0:  02 80 00 07  be  0xa009edbc
a009eda4:  c2 05 23 ec  ld  [ %l4 + 0x3ec ], %g1
a009eda8:  80 a0 61 14  cmp  %g1, 0x114
a009edac:  02 80 00 a7  be  0xa009f048
a009edb0:  80 a0 61 13  cmp  %g1, 0x113
a009edb4:  02 80 00 a7  be  0xa009f050
a009edb8:  01 00 00 00  nop
a009edbc:  d0 05 23 ec  ld  [ %l4 + 0x3ec ], %o0
a009edc0:  80 a2 20 00  cmp  %o0, 0
a009edc4:  12 80 00 0c  bne  0xa009edf4
a009edc8:  c2 05 23 ec  ld  [ %l4 + 0x3ec ], %g1
a009edcc:  de 04 e2 90  ld  [ %l3 + 0x290 ], %o7
a009edd0:  15 00 00 10  sethi  %hi(0x4000), %o2
a009edd4:  80 8b c0 0a  btst  %o7, %o2
a009edd8:  02 80 00 06  be  0xa009edf0
a009eddc:  82 14 e2 90  or  %l3, 0x290, %g1
a009ede0:  d6 08 61 d5  ldub  [ %g1 + 0x1d5 ], %o3
a009ede4:  80 a2 e0 00  cmp  %o3, 0
a009ede8:  02 80 00 b3  be  0xa009f0b4
a009edec:  01 00 00 00  nop
a009edf0:  c2 05 23 ec  ld  [ %l4 + 0x3ec ], %g1
a009edf4:  90 00 40 01  add  %g1, %g1, %o0
a009edf8:  92 02 00 01  add  %o0, %g1, %o1
a009edfc:  a4 02 40 09  add  %o1, %o1, %l2
a009ee00:  a6 04 80 11  add  %l2, %l1, %l3
a009ee04:  23 2a 00 90  sethi  %hi(0xa8024000), %l1
a009ee08:  a9 2c e0 02  sll  %l3, 2, %l4
a009ee0c:  a0 14 62 2c  or  %l1, 0x22c, %l0
a009ee10:  da 04 00 14  ld  [ %l0 + %l4 ], %o5
a009ee14:  80 a3 60 00  cmp  %o5, 0
a009ee18:  02 80 00 d9  be  0xa009f17c
a009ee1c:  01 00 00 00  nop
a009ee20:  9f c3 40 00  call  %o5
a009ee24:  01 00 00 00  nop
a009ee28:  67 ff b9 d8  call  0x4008d588
a009ee2c:  01 00 00 00  nop
a009ee30:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a009ee34:  d0 32 a0 3c  sth  %o0, [ %o2 + 0x3c ]	! 0xa802d03c
a009ee38:  40 00 d6 5e  call  0xa00d47b0
a009ee3c:  01 00 00 00  nop
a009ee40:  7f ff c8 95  call  0xa0091094
a009ee44:  81 e8 00 00  restore
a009ee48:  80 a0 00 0c  cmp  %g0, %o4
a009ee4c:  96 60 3f ff  subx  %g0, -1, %o3
a009ee50:  b2 1b 21 0d  xor  %o4, 0x10d, %i1
a009ee54:  80 a0 00 19  cmp  %g0, %i1
a009ee58:  9e 60 3f ff  subx  %g0, -1, %o7
a009ee5c:  80 92 c0 0f  orcc  %o3, %o7, %g0
a009ee60:  12 80 00 32  bne  0xa009ef28
a009ee64:  27 2a 00 ab  sethi  %hi(0xa802ac00), %l3
a009ee68:  de 05 23 ec  ld  [ %l4 + 0x3ec ], %o7
a009ee6c:  94 03 c0 0f  add  %o7, %o7, %o2
a009ee70:  a0 02 80 0f  add  %o2, %o7, %l0
a009ee74:  a8 04 00 10  add  %l0, %l0, %l4
a009ee78:  90 05 00 11  add  %l4, %l1, %o0
a009ee7c:  13 2a 00 90  sethi  %hi(0xa8024000), %o1
a009ee80:  b1 2a 20 02  sll  %o0, 2, %i0
a009ee84:  a6 12 62 2c  or  %o1, 0x22c, %l3
a009ee88:  da 04 c0 18  ld  [ %l3 + %i0 ], %o5
a009ee8c:  80 a3 60 00  cmp  %o5, 0
a009ee90:  02 80 00 bb  be  0xa009f17c
a009ee94:  01 00 00 00  nop
a009ee98:  9f c3 40 00  call  %o5
a009ee9c:  33 3f ff e0  sethi  %hi(0xffff8000), %i1
a009eea0:  67 ff b9 ba  call  0x4008d588
a009eea4:  01 00 00 00  nop
a009eea8:  98 14 a3 f4  or  %l2, 0x3f4, %o4
a009eeac:  d6 13 20 3e  lduh  [ %o4 + 0x3e ], %o3
a009eeb0:  a2 0a c0 19  and  %o3, %i1, %l1
a009eeb4:  a5 2c 60 10  sll  %l1, 0x10, %l2
a009eeb8:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a009eebc:  80 a4 a0 00  cmp  %l2, 0
a009eec0:  02 bf ff de  be  0xa009ee38
a009eec4:  d0 30 60 3c  sth  %o0, [ %g1 + 0x3c ]
a009eec8:  7f ff c8 73  call  0xa0091094
a009eecc:  81 e8 00 00  restore
a009eed0:  80 a4 60 01  cmp  %l1, 1
a009eed4:  12 bf ff 84  bne  0xa009ece4
a009eed8:  98 0e 20 3f  and  %i0, 0x3f, %o4
a009eedc:  7f ff af 91  call  0xa008ad20
a009eee0:  27 2a 00 b4  sethi  %hi(0xa802d000), %l3
a009eee4:  d6 0c e2 84  ldub  [ %l3 + 0x284 ], %o3	! 0xa802d284
a009eee8:  80 a2 e0 3f  cmp  %o3, 0x3f
a009eeec:  02 80 00 8c  be  0xa009f11c
a009eef0:  01 00 00 00  nop
a009eef4:  40 02 a2 0c  call  0xa0147724
a009eef8:  33 2a 00 ab  sethi  %hi(0xa802ac00), %i1
a009eefc:  10 bf ff 79  b  0xa009ece0
a009ef00:  d0 36 63 e8  sth  %o0, [ %i1 + 0x3e8 ]	! 0xa802afe8
a009ef04:  25 2a 00 90  sethi  %hi(0xa8024000), %l2
a009ef08:  c2 04 a2 44  ld  [ %l2 + 0x244 ], %g1	! 0xa8024244
a009ef0c:  80 a0 60 00  cmp  %g1, 0
a009ef10:  02 80 00 9b  be  0xa009f17c
a009ef14:  01 00 00 00  nop
a009ef18:  9f c0 40 00  call  %g1
a009ef1c:  01 00 00 00  nop
a009ef20:  7f ff c8 5d  call  0xa0091094
a009ef24:  81 e8 00 00  restore
a009ef28:  40 02 93 3b  call  0xa0143c14
a009ef2c:  90 10 20 00  clr  %o0
a009ef30:  9a 0a 20 ff  and  %o0, 0xff, %o5
a009ef34:  80 a3 60 04  cmp  %o5, 4
a009ef38:  18 bf ff cd  bgu  0xa009ee6c
a009ef3c:  de 05 23 ec  ld  [ %l4 + 0x3ec ], %o7
a009ef40:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a009ef44:  f0 04 22 90  ld  [ %l0 + 0x290 ], %i0	! 0xa802d290
a009ef48:  80 8e 22 00  btst  0x200, %i0
a009ef4c:  12 80 00 51  bne  0xa009f090
a009ef50:  80 a4 60 05  cmp  %l1, 5
a009ef54:  82 40 20 00  addx  %g0, 0, %g1
a009ef58:  9e 1c 60 08  xor  %l1, 8, %o7
a009ef5c:  80 a0 00 0f  cmp  %g0, %o7
a009ef60:  94 60 3f ff  subx  %g0, -1, %o2
a009ef64:  80 90 40 0a  orcc  %g1, %o2, %g0
a009ef68:  02 bf ff c1  be  0xa009ee6c
a009ef6c:  de 05 23 ec  ld  [ %l4 + 0x3ec ], %o7
a009ef70:  40 01 92 3b  call  0xa010385c
a009ef74:  90 10 20 00  clr  %o0
a009ef78:  67 ff bc cb  call  0x4008e2a4
a009ef7c:  a0 14 a3 f4  or  %l2, 0x3f4, %l0
a009ef80:  da 14 20 04  lduh  [ %l0 + 4 ], %o5
a009ef84:  33 3f ff e0  sethi  %hi(0xffff8000), %i1
a009ef88:  96 0b 40 19  and  %o5, %i1, %o3
a009ef8c:  a3 2a e0 10  sll  %o3, 0x10, %l1
a009ef90:  80 a4 60 00  cmp  %l1, 0
a009ef94:  02 80 00 06  be  0xa009efac
a009ef98:  98 13 64 00  or  %o5, 0x400, %o4
a009ef9c:  d8 34 20 04  sth  %o4, [ %l0 + 4 ]
a009efa0:  90 10 20 04  mov  4, %o0
a009efa4:  7f ff 86 42  call  0xa00808ac
a009efa8:  92 10 20 00  clr  %o1
a009efac:  40 00 58 35  call  0xa00b5080
a009efb0:  c0 24 e3 ec  clr  [ %l3 + 0x3ec ]
a009efb4:  40 02 93 18  call  0xa0143c14
a009efb8:  90 10 20 01  mov  1, %o0
a009efbc:  9a 0a 20 ff  and  %o0, 0xff, %o5
a009efc0:  80 a3 60 0a  cmp  %o5, 0xa
a009efc4:  02 80 00 05  be  0xa009efd8
a009efc8:  f0 04 e3 ec  ld  [ %l3 + 0x3ec ], %i0
a009efcc:  80 a6 20 00  cmp  %i0, 0
a009efd0:  02 80 00 56  be  0xa009f128
a009efd4:  94 10 20 00  clr  %o2
a009efd8:  7f ff 87 00  call  0xa0080bd8
a009efdc:  90 10 20 01  mov  1, %o0
a009efe0:  90 10 20 ff  mov  0xff, %o0
a009efe4:  7f ff bf a2  call  0xa008ee6c
a009efe8:  92 10 20 00  clr  %o1
a009efec:  1b 00 00 07  sethi  %hi(0x1c00), %o5
a009eff0:  92 13 63 40  or  %o5, 0x340, %o1	! 0x1f40
a009eff4:  7f ff 9e 6f  call  0xa00869b0
a009eff8:  90 10 20 04  mov  4, %o0
a009effc:  19 00 00 09  sethi  %hi(0x2400), %o4
a009f000:  92 13 23 10  or  %o4, 0x310, %o1	! 0x2710
a009f004:  7f ff 9e 6b  call  0xa00869b0
a009f008:  90 10 20 0b  mov  0xb, %o0
a009f00c:  b2 10 20 fe  mov  0xfe, %i1
a009f010:  40 00 5b 40  call  0xa00b5d10
a009f014:  f2 25 23 ec  st  %i1, [ %l4 + 0x3ec ]
a009f018:  40 00 15 64  call  0xa00a45a8
a009f01c:  a8 14 a3 f4  or  %l2, 0x3f4, %l4
a009f020:  e2 15 20 3e  lduh  [ %l4 + 0x3e ], %l1
a009f024:  17 00 00 10  sethi  %hi(0x4000), %o3
a009f028:  9e 14 40 0b  or  %l1, %o3, %o7
a009f02c:  03 3f ff e0  sethi  %hi(0xffff8000), %g1
a009f030:  94 10 20 14  mov  0x14, %o2
a009f034:  21 2a 00 ab  sethi  %hi(0xa802ac00), %l0
a009f038:  a4 13 c0 01  or  %o7, %g1, %l2
a009f03c:  d4 34 23 f2  sth  %o2, [ %l0 + 0x3f2 ]
a009f040:  10 80 00 4f  b  0xa009f17c
a009f044:  e4 35 20 3e  sth  %l2, [ %l4 + 0x3e ]
a009f048:  7f ff b8 a6  call  0xa008d2e0
a009f04c:  01 00 00 00  nop
a009f050:  67 ff b9 4e  call  0x4008d588
a009f054:  25 2a 00 b4  sethi  %hi(0xa802d000), %l2
a009f058:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a009f05c:  40 00 d5 d5  call  0xa00d47b0
a009f060:  d0 30 60 3c  sth  %o0, [ %g1 + 0x3c ]	! 0xa802d03c
a009f064:  7f ff af 2f  call  0xa008ad20
a009f068:  01 00 00 00  nop
a009f06c:  e6 0c a2 84  ldub  [ %l2 + 0x284 ], %l3
a009f070:  80 a4 e0 3f  cmp  %l3, 0x3f
a009f074:  02 80 00 27  be  0xa009f110
a009f078:  01 00 00 00  nop
a009f07c:  40 02 a1 aa  call  0xa0147724
a009f080:  01 00 00 00  nop
a009f084:  13 2a 00 ab  sethi  %hi(0xa802ac00), %o1
a009f088:  10 80 00 3d  b  0xa009f17c
a009f08c:  d0 32 63 e8  sth  %o0, [ %o1 + 0x3e8 ]	! 0xa802afe8
a009f090:  40 02 9a 9a  call  0xa0145af8
a009f094:  90 10 20 02  mov  2, %o0
a009f098:  91 2a 20 10  sll  %o0, 0x10, %o0
a009f09c:  93 32 20 10  srl  %o0, 0x10, %o1
a009f0a0:  80 a2 60 01  cmp  %o1, 1
a009f0a4:  12 bf ff 72  bne  0xa009ee6c
a009f0a8:  de 05 23 ec  ld  [ %l4 + 0x3ec ], %o7
a009f0ac:  10 bf ff aa  b  0xa009ef54
a009f0b0:  80 a4 60 05  cmp  %l1, 5
a009f0b4:  40 01 91 ea  call  0xa010385c
a009f0b8:  90 10 20 00  clr  %o0
a009f0bc:  94 10 20 00  clr  %o2
a009f0c0:  96 10 20 00  clr  %o3
a009f0c4:  98 10 20 00  clr  %o4
a009f0c8:  90 10 20 00  clr  %o0
a009f0cc:  40 02 9b c7  call  0xa0145fe8
a009f0d0:  92 10 20 00  clr  %o1
a009f0d4:  92 10 20 00  clr  %o1
a009f0d8:  40 02 98 15  call  0xa014512c
a009f0dc:  90 10 20 01  mov  1, %o0
a009f0e0:  7f ff 86 be  call  0xa0080bd8
a009f0e4:  90 10 20 01  mov  1, %o0
a009f0e8:  98 14 a3 f4  or  %l2, 0x3f4, %o4
a009f0ec:  f0 13 20 04  lduh  [ %o4 + 4 ], %i0
a009f0f0:  9a 16 20 80  or  %i0, 0x80, %o5
a009f0f4:  da 33 20 04  sth  %o5, [ %o4 + 4 ]
a009f0f8:  b2 10 21 11  mov  0x111, %i1
a009f0fc:  7f ff b8 7f  call  0xa008d2f8
a009f100:  f2 25 23 ec  st  %i1, [ %l4 + 0x3ec ]
a009f104:  b0 10 20 ff  mov  0xff, %i0
a009f108:  7f ff bf 59  call  0xa008ee6c
a009f10c:  93 e8 20 00  restore  %g0, 0, %o1
a009f110:  7f ff b0 6b  call  0xa008b2bc
a009f114:  01 00 00 00  nop
a009f118:  30 bf ff d9  b,a   0xa009f07c
a009f11c:  7f ff b0 68  call  0xa008b2bc
a009f120:  01 00 00 00  nop
a009f124:  30 bf ff 74  b,a   0xa009eef4
a009f128:  96 10 20 00  clr  %o3	! 0x0
a009f12c:  98 10 20 00  clr  %o4
a009f130:  92 10 20 00  clr  %o1
a009f134:  40 02 9b ad  call  0xa0145fe8
a009f138:  90 10 20 00  clr  %o0
a009f13c:  40 02 91 b2  call  0xa0143804
a009f140:  90 10 23 ff  mov  0x3ff, %o0
a009f144:  90 10 20 01  mov  1, %o0
a009f148:  40 02 97 f9  call  0xa014512c
a009f14c:  92 10 20 01  mov  1, %o1
a009f150:  d2 14 20 18  lduh  [ %l0 + 0x18 ], %o1
a009f154:  11 00 00 04  sethi  %hi(0x1000), %o0
a009f158:  a6 12 40 08  or  %o1, %o0, %l3
a009f15c:  e6 34 20 18  sth  %l3, [ %l0 + 0x18 ]
a009f160:  67 ff b8 10  call  0x4008d1a0
a009f164:  90 10 21 90  mov  0x190, %o0
a009f168:  30 bf ff 9c  b,a   0xa009efd8
a009f16c:  40 02 95 0c  call  0xa014459c
a009f170:  01 00 00 00  nop
a009f174:  10 bf fe c7  b  0xa009ec90
a009f178:  d0 2c 20 1e  stb  %o0, [ %l0 + 0x1e ]
a009f17c:  81 c7 e0 08  ret
a009f180:  81 e8 00 00  restore
