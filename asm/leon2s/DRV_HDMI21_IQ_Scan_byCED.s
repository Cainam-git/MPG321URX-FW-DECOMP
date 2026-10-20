# leon2s DRV_HDMI21_IQ_Scan_byCED 0xa007fa0c-0xa007fde0 (980 bytes)
a007fa0c:  9d e3 be 80  save  %sp, -384, %sp
a007fa10:  c0 27 bf f0  clr  [ %fp + -16 ]
a007fa14:  90 07 be f0  add  %fp, -272, %o0
a007fa18:  92 10 20 00  clr  %o1
a007fa1c:  40 00 c6 e4  call  0xa00b15ac
a007fa20:  94 10 21 00  mov  0x100, %o2
a007fa24:  82 0e 20 ff  and  %i0, 0xff, %g1
a007fa28:  80 a0 60 02  cmp  %g1, 2
a007fa2c:  a8 10 20 00  clr  %l4
a007fa30:  02 80 00 05  be  0xa007fa44
a007fa34:  aa 10 20 00  clr  %l5
a007fa38:  80 a0 60 03  cmp  %g1, 3
a007fa3c:  12 80 00 e6  bne  0xa007fdd4
a007fa40:  aa 10 20 01  mov  1, %l5
a007fa44:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a007fa48:  c2 00 62 34  ld  [ %g1 + 0x234 ], %g1	! 0xa8078634
a007fa4c:  80 88 68 00  btst  0x800, %g1
a007fa50:  02 80 00 08  be  0xa007fa70
a007fa54:  9a 0d 60 ff  and  %l5, 0xff, %o5
a007fa58:  11 28 01 9e  sethi  %hi(0xa0067800), %o0
a007fa5c:  13 28 02 cf  sethi  %hi(0xa00b3c00), %o1
a007fa60:  90 12 20 68  or  %o0, 0x68, %o0
a007fa64:  7f ff cd 78  call  0xa0073044
a007fa68:  92 12 63 80  or  %o1, 0x380, %o1
a007fa6c:  9a 0d 60 ff  and  %l5, 0xff, %o5
a007fa70:  03 2a 01 f5  sethi  %hi(0xa807d400), %g1
a007fa74:  9a 5b 60 b0  smul  %o5, 0xb0, %o5
a007fa78:  82 10 62 80  or  %g1, 0x280, %g1
a007fa7c:  c2 08 40 0d  ldub  [ %g1 + %o5 ], %g1
a007fa80:  80 a0 60 00  cmp  %g1, 0
a007fa84:  02 80 00 0c  be  0xa007fab4
a007fa88:  a4 10 20 00  clr  %l2
a007fa8c:  98 10 00 01  mov  %g1, %o4
a007fa90:  96 07 bf f8  add  %fp, -8, %o3
a007fa94:  82 0c a0 ff  and  %l2, 0xff, %g1
a007fa98:  a4 04 a0 01  inc  %l2
a007fa9c:  82 02 c0 01  add  %o3, %g1, %g1
a007faa0:  9a 0c a0 ff  and  %l2, 0xff, %o5
a007faa4:  c0 28 7e e8  clrb  [ %g1 + -280 ]
a007faa8:  80 a3 40 0c  cmp  %o5, %o4
a007faac:  0a bf ff fa  bcs  0xa007fa94
a007fab0:  c0 28 7e f0  clrb  [ %g1 + -272 ]
a007fab4:  a6 10 20 10  mov  0x10, %l3
a007fab8:  94 0c e0 ff  and  %l3, 0xff, %o2
a007fabc:  a0 0e 20 ff  and  %i0, 0xff, %l0
a007fac0:  9a 10 00 0a  mov  %o2, %o5
a007fac4:  90 10 00 10  mov  %l0, %o0
a007fac8:  92 10 20 ff  mov  0xff, %o1
a007facc:  96 10 00 0a  mov  %o2, %o3
a007fad0:  7f ff eb fd  call  0xa007aac4
a007fad4:  98 10 00 0a  mov  %o2, %o4
a007fad8:  7f ff ff c4  call  0xa007f9e8
a007fadc:  90 10 00 10  mov  %l0, %o0
a007fae0:  2f 2a 01 f5  sethi  %hi(0xa807d400), %l7
a007fae4:  ac 0d 60 ff  and  %l5, 0xff, %l6
a007fae8:  9a 15 e2 80  or  %l7, 0x280, %o5
a007faec:  82 5d a0 b0  smul  %l6, 0xb0, %g1
a007faf0:  c2 0b 40 01  ldub  [ %o5 + %g1 ], %g1
a007faf4:  80 a0 60 00  cmp  %g1, 0
a007faf8:  02 80 00 77  be  0xa007fcd4
a007fafc:  a4 10 20 00  clr  %l2
a007fb00:  a2 0c a0 ff  and  %l2, 0xff, %l1
a007fb04:  15 00 00 0b  sethi  %hi(0x2c00), %o2
a007fb08:  80 a4 60 00  cmp  %l1, 0
a007fb0c:  02 80 00 0b  be  0xa007fb38
a007fb10:  94 12 a2 64  or  %o2, 0x264, %o2
a007fb14:  15 00 00 0b  sethi  %hi(0x2c00), %o2
a007fb18:  80 a4 60 01  cmp  %l1, 1
a007fb1c:  02 80 00 0d  be  0xa007fb50
a007fb20:  94 12 a2 64  or  %o2, 0x264, %o2
a007fb24:  80 a4 60 02  cmp  %l1, 2
a007fb28:  12 80 00 06  bne  0xa007fb40
a007fb2c:  80 a4 60 03  cmp  %l1, 3
a007fb30:  15 00 00 0b  sethi  %hi(0x2c00), %o2
a007fb34:  94 12 a2 68  or  %o2, 0x268, %o2	! 0x2e68
a007fb38:  10 80 00 07  b  0xa007fb54
a007fb3c:  90 10 20 0f  mov  0xf, %o0
a007fb40:  12 80 00 0b  bne  0xa007fb6c
a007fb44:  80 8d 20 ff  btst  0xff, %l4
a007fb48:  15 00 00 0b  sethi  %hi(0x2c00), %o2
a007fb4c:  94 12 a2 68  or  %o2, 0x268, %o2	! 0x2e68
a007fb50:  90 10 20 1f  mov  0x1f, %o0
a007fb54:  40 00 9e 45  call  0xa00a7468
a007fb58:  92 0e 20 ff  and  %i0, 0xff, %o1
a007fb5c:  80 a0 00 08  cmp  %g0, %o0
a007fb60:  82 40 20 00  addx  %g0, 0, %g1
a007fb64:  a8 10 00 01  mov  %g1, %l4
a007fb68:  80 8d 20 ff  btst  0xff, %l4
a007fb6c:  02 80 00 46  be  0xa007fc84
a007fb70:  80 a4 60 00  cmp  %l1, 0
a007fb74:  12 80 00 09  bne  0xa007fb98
a007fb78:  80 a4 60 01  cmp  %l1, 1
a007fb7c:  a0 0c e0 ff  and  %l3, 0xff, %l0
a007fb80:  a0 04 00 10  add  %l0, %l0, %l0
a007fb84:  82 07 bf f8  add  %fp, -8, %g1
a007fb88:  13 00 00 0b  sethi  %hi(0x2c00), %o1
a007fb8c:  a0 04 00 01  add  %l0, %g1, %l0
a007fb90:  10 80 00 15  b  0xa007fbe4
a007fb94:  92 12 62 64  or  %o1, 0x264, %o1
a007fb98:  12 80 00 0a  bne  0xa007fbc0
a007fb9c:  80 a4 60 02  cmp  %l1, 2
a007fba0:  a0 0c e0 ff  and  %l3, 0xff, %l0
a007fba4:  a0 04 20 20  add  %l0, 0x20, %l0
a007fba8:  a0 04 00 10  add  %l0, %l0, %l0
a007fbac:  82 07 bf f8  add  %fp, -8, %g1
a007fbb0:  13 00 00 0b  sethi  %hi(0x2c00), %o1
a007fbb4:  a0 04 00 01  add  %l0, %g1, %l0
a007fbb8:  10 80 00 1a  b  0xa007fc20
a007fbbc:  92 12 62 64  or  %o1, 0x264, %o1
a007fbc0:  12 80 00 0f  bne  0xa007fbfc
a007fbc4:  80 a4 60 03  cmp  %l1, 3
a007fbc8:  a0 0c e0 ff  and  %l3, 0xff, %l0
a007fbcc:  a0 04 20 40  add  %l0, 0x40, %l0
a007fbd0:  a0 04 00 10  add  %l0, %l0, %l0
a007fbd4:  82 07 bf f8  add  %fp, -8, %g1
a007fbd8:  13 00 00 0b  sethi  %hi(0x2c00), %o1
a007fbdc:  a0 04 00 01  add  %l0, %g1, %l0
a007fbe0:  92 12 62 68  or  %o1, 0x268, %o1
a007fbe4:  40 00 9d cc  call  0xa00a7314
a007fbe8:  90 0e 20 ff  and  %i0, 0xff, %o0
a007fbec:  03 3f ff e0  sethi  %hi(0xffff8000), %g1
a007fbf0:  82 2a 00 01  andn  %o0, %g1, %g1
a007fbf4:  10 80 00 10  b  0xa007fc34
a007fbf8:  c2 34 3e d8  sth  %g1, [ %l0 + -296 ]
a007fbfc:  12 80 00 0f  bne  0xa007fc38
a007fc00:  82 0c e0 ff  and  %l3, 0xff, %g1
a007fc04:  a0 0c e0 ff  and  %l3, 0xff, %l0
a007fc08:  a0 04 20 60  add  %l0, 0x60, %l0
a007fc0c:  a0 04 00 10  add  %l0, %l0, %l0
a007fc10:  82 07 bf f8  add  %fp, -8, %g1
a007fc14:  13 00 00 0b  sethi  %hi(0x2c00), %o1
a007fc18:  a0 04 00 01  add  %l0, %g1, %l0
a007fc1c:  92 12 62 68  or  %o1, 0x268, %o1
a007fc20:  40 00 9d bd  call  0xa00a7314
a007fc24:  90 0e 20 ff  and  %i0, 0xff, %o0
a007fc28:  90 02 00 08  add  %o0, %o0, %o0
a007fc2c:  91 32 20 11  srl  %o0, 0x11, %o0
a007fc30:  d0 34 3e d8  sth  %o0, [ %l0 + -296 ]
a007fc34:  82 0c e0 ff  and  %l3, 0xff, %g1
a007fc38:  9b 2c 60 05  sll  %l1, 5, %o5
a007fc3c:  9a 03 40 01  add  %o5, %g1, %o5
a007fc40:  9a 03 40 0d  add  %o5, %o5, %o5
a007fc44:  98 07 bf f8  add  %fp, -8, %o4
a007fc48:  9a 03 40 0c  add  %o5, %o4, %o5
a007fc4c:  c2 13 7e d8  lduh  [ %o5 + -296 ], %g1
a007fc50:  80 a0 60 63  cmp  %g1, 0x63
a007fc54:  18 80 00 19  bgu  0xa007fcb8
a007fc58:  82 5d a0 b0  smul  %l6, 0xb0, %g1
a007fc5c:  92 03 00 11  add  %o4, %l1, %o1
a007fc60:  c2 4a 7e f0  ldsb  [ %o1 + -272 ], %g1
a007fc64:  80 a0 60 00  cmp  %g1, 0
a007fc68:  06 80 00 04  bl  0xa007fc78
a007fc6c:  82 04 ff f0  add  %l3, -16, %g1
a007fc70:  82 10 7f 80  or  %g1, -128, %g1
a007fc74:  c2 2a 7e f0  stb  %g1, [ %o1 + -272 ]
a007fc78:  82 04 ff f0  add  %l3, -16, %g1
a007fc7c:  10 80 00 0e  b  0xa007fcb4
a007fc80:  c2 2a 7e e8  stb  %g1, [ %o1 + -280 ]
a007fc84:  9a 0c e0 ff  and  %l3, 0xff, %o5
a007fc88:  83 2c 60 05  sll  %l1, 5, %g1
a007fc8c:  82 00 40 0d  add  %g1, %o5, %g1
a007fc90:  82 00 40 01  add  %g1, %g1, %g1
a007fc94:  9a 07 80 01  add  %fp, %g1, %o5
a007fc98:  03 00 00 1f  sethi  %hi(0x7c00), %g1
a007fc9c:  82 10 63 ff  or  %g1, 0x3ff, %g1	! 0x7fff
a007fca0:  11 28 01 a1  sethi  %hi(0xa0068400), %o0
a007fca4:  c2 33 7e d0  sth  %g1, [ %o5 + -304 ]
a007fca8:  90 12 21 f8  or  %o0, 0x1f8, %o0
a007fcac:  7f ff cc e6  call  0xa0073044
a007fcb0:  92 10 00 11  mov  %l1, %o1
a007fcb4:  82 5d a0 b0  smul  %l6, 0xb0, %g1
a007fcb8:  9a 15 e2 80  or  %l7, 0x280, %o5
a007fcbc:  da 0b 40 01  ldub  [ %o5 + %g1 ], %o5
a007fcc0:  a4 04 a0 01  inc  %l2
a007fcc4:  82 0c a0 ff  and  %l2, 0xff, %g1
a007fcc8:  80 a0 40 0d  cmp  %g1, %o5
a007fccc:  2a bf ff 8e  bcs,a   0xa007fb04
a007fcd0:  a2 0c a0 ff  and  %l2, 0xff, %l1
a007fcd4:  a6 04 e0 01  inc  %l3
a007fcd8:  82 0c e0 ff  and  %l3, 0xff, %g1
a007fcdc:  80 a0 60 2f  cmp  %g1, 0x2f
a007fce0:  08 bf ff 77  bleu  0xa007fabc
a007fce4:  94 0c e0 ff  and  %l3, 0xff, %o2
a007fce8:  a0 0d 60 ff  and  %l5, 0xff, %l0
a007fcec:  23 2a 01 f5  sethi  %hi(0xa807d400), %l1
a007fcf0:  9a 14 62 80  or  %l1, 0x280, %o5	! 0xa807d680
a007fcf4:  82 5c 20 b0  smul  %l0, 0xb0, %g1
a007fcf8:  c2 0b 40 01  ldub  [ %o5 + %g1 ], %g1
a007fcfc:  80 a0 60 00  cmp  %g1, 0
a007fd00:  02 80 00 11  be  0xa007fd44
a007fd04:  a4 10 20 00  clr  %l2
a007fd08:  96 10 00 01  mov  %g1, %o3
a007fd0c:  94 07 bf f8  add  %fp, -8, %o2
a007fd10:  98 0c a0 ff  and  %l2, 0xff, %o4
a007fd14:  98 02 80 0c  add  %o2, %o4, %o4
a007fd18:  da 0b 3e f0  ldub  [ %o4 + -272 ], %o5
a007fd1c:  9a 0b 60 3f  and  %o5, 0x3f, %o5
a007fd20:  c2 0b 3e e8  ldub  [ %o4 + -280 ], %g1
a007fd24:  82 00 40 0d  add  %g1, %o5, %g1
a007fd28:  83 38 60 01  sra  %g1, 1, %g1
a007fd2c:  a4 04 a0 01  inc  %l2
a007fd30:  82 00 60 10  add  %g1, 0x10, %g1
a007fd34:  9a 0c a0 ff  and  %l2, 0xff, %o5
a007fd38:  80 a3 40 0b  cmp  %o5, %o3
a007fd3c:  0a bf ff f5  bcs  0xa007fd10
a007fd40:  c2 2b 3f f8  stb  %g1, [ %o4 + -8 ]
a007fd44:  11 28 01 a1  sethi  %hi(0xa0068400), %o0
a007fd48:  7f ff cc bf  call  0xa0073044
a007fd4c:  90 12 22 10  or  %o0, 0x210, %o0	! 0xa0068610
a007fd50:  9a 14 62 80  or  %l1, 0x280, %o5
a007fd54:  82 5c 20 b0  smul  %l0, 0xb0, %g1
a007fd58:  c2 0b 40 01  ldub  [ %o5 + %g1 ], %g1
a007fd5c:  80 a0 60 00  cmp  %g1, 0
a007fd60:  02 80 00 10  be  0xa007fda0
a007fd64:  a4 10 20 00  clr  %l2
a007fd68:  92 0c a0 ff  and  %l2, 0xff, %o1
a007fd6c:  82 07 80 09  add  %fp, %o1, %g1
a007fd70:  11 28 01 a1  sethi  %hi(0xa0068400), %o0
a007fd74:  d4 08 7f f0  ldub  [ %g1 + -16 ], %o2
a007fd78:  7f ff cc b3  call  0xa0073044
a007fd7c:  90 12 22 28  or  %o0, 0x228, %o0
a007fd80:  82 5c 20 b0  smul  %l0, 0xb0, %g1
a007fd84:  9a 14 62 80  or  %l1, 0x280, %o5
a007fd88:  da 0b 40 01  ldub  [ %o5 + %g1 ], %o5
a007fd8c:  a4 04 a0 01  inc  %l2
a007fd90:  82 0c a0 ff  and  %l2, 0xff, %g1
a007fd94:  80 a0 40 0d  cmp  %g1, %o5
a007fd98:  0a bf ff f5  bcs  0xa007fd6c
a007fd9c:  92 0c a0 ff  and  %l2, 0xff, %o1
a007fda0:  11 28 01 a1  sethi  %hi(0xa0068400), %o0
a007fda4:  7f ff cd c8  call  0xa00734c4
a007fda8:  90 12 22 40  or  %o0, 0x240, %o0	! 0xa0068640
a007fdac:  a0 0e 20 ff  and  %i0, 0xff, %l0
a007fdb0:  90 10 00 10  mov  %l0, %o0
a007fdb4:  92 10 20 ff  mov  0xff, %o1
a007fdb8:  d4 0f bf f0  ldub  [ %fp + -16 ], %o2
a007fdbc:  d6 0f bf f1  ldub  [ %fp + -15 ], %o3
a007fdc0:  d8 0f bf f2  ldub  [ %fp + -14 ], %o4
a007fdc4:  7f ff eb 40  call  0xa007aac4
a007fdc8:  da 0f bf f3  ldub  [ %fp + -13 ], %o5
a007fdcc:  7f ff ff 01  call  0xa007f9d0
a007fdd0:  90 10 00 10  mov  %l0, %o0
a007fdd4:  01 00 00 00  nop
a007fdd8:  81 c7 e0 08  ret
a007fddc:  81 e8 00 00  restore
