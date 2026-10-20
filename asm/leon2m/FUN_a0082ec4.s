# leon2m FUN_a0082ec4 0xa0082ec4-0xa00830f4 (560 bytes)
a0082ec4:  9d e3 bf 98  save  %sp, -104, %sp
a0082ec8:  92 10 20 07  mov  7, %o1
a0082ecc:  40 03 09 e5  call  0xa0145660
a0082ed0:  90 10 20 01  mov  1, %o0
a0082ed4:  a0 10 00 08  mov  %o0, %l0
a0082ed8:  92 10 20 08  mov  8, %o1
a0082edc:  40 03 09 e1  call  0xa0145660
a0082ee0:  90 10 20 01  mov  1, %o0
a0082ee4:  a1 2c 20 10  sll  %l0, 0x10, %l0
a0082ee8:  23 2a 00 90  sethi  %hi(0xa8024000), %l1
a0082eec:  a5 34 20 10  srl  %l0, 0x10, %l2
a0082ef0:  ea 14 60 06  lduh  [ %l1 + 6 ], %l5
a0082ef4:  29 2a aa aa  sethi  %hi(0xaaaaa800), %l4
a0082ef8:  9e 24 80 15  sub  %l2, %l5, %o7
a0082efc:  a6 15 22 ab  or  %l4, 0x2ab, %l3
a0082f00:  80 54 80 13  umul  %l2, %l3, %g0
a0082f04:  95 40 00 00  rd  %y, %o2
a0082f08:  97 3b e0 1f  sra  %o7, 0x1f, %o3
a0082f0c:  92 1a c0 0f  xor  %o3, %o7, %o1
a0082f10:  83 2a a0 0e  sll  %o2, 0xe, %g1
a0082f14:  9a 22 40 0b  sub  %o1, %o3, %o5
a0082f18:  99 30 60 10  srl  %g1, 0x10, %o4
a0082f1c:  80 a3 40 0c  cmp  %o5, %o4
a0082f20:  a4 10 20 00  clr  %l2
a0082f24:  14 80 00 03  bg  0xa0082f30
a0082f28:  aa 10 20 00  clr  %l5
a0082f2c:  aa 10 20 01  mov  1, %l5
a0082f30:  91 2a 20 10  sll  %o0, 0x10, %o0
a0082f34:  29 2a 00 90  sethi  %hi(0xa8024000), %l4
a0082f38:  a7 32 20 10  srl  %o0, 0x10, %l3
a0082f3c:  da 15 20 04  lduh  [ %l4 + 4 ], %o5
a0082f40:  03 2a aa aa  sethi  %hi(0xaaaaa800), %g1
a0082f44:  9e 24 c0 0d  sub  %l3, %o5, %o7
a0082f48:  98 10 62 ab  or  %g1, 0x2ab, %o4
a0082f4c:  80 54 c0 0c  umul  %l3, %o4, %g0
a0082f50:  95 40 00 00  rd  %y, %o2
a0082f54:  97 3b e0 1f  sra  %o7, 0x1f, %o3
a0082f58:  92 1a c0 0f  xor  %o3, %o7, %o1
a0082f5c:  83 2a a0 0e  sll  %o2, 0xe, %g1
a0082f60:  9a 22 40 0b  sub  %o1, %o3, %o5
a0082f64:  99 30 60 10  srl  %g1, 0x10, %o4
a0082f68:  80 a3 40 0c  cmp  %o5, %o4
a0082f6c:  14 80 00 03  bg  0xa0082f78
a0082f70:  a6 10 20 00  clr  %l3
a0082f74:  a6 10 20 01  mov  1, %l3
a0082f78:  17 00 03 fa  sethi  %hi(0xfe800), %o3
a0082f7c:  a1 34 20 10  srl  %l0, 0x10, %l0
a0082f80:  91 32 20 10  srl  %o0, 0x10, %o0
a0082f84:  9e 10 20 00  clr  %o7
a0082f88:  92 10 20 00  clr  %o1
a0082f8c:  98 12 e3 30  or  %o3, 0x330, %o4
a0082f90:  9b 2a 60 03  sll  %o1, 3, %o5
a0082f94:  94 03 40 09  add  %o5, %o1, %o2
a0082f98:  82 02 80 0a  add  %o2, %o2, %g1
a0082f9c:  da 13 00 01  lduh  [ %o4 + %g1 ], %o5
a0082fa0:  9a 24 00 0d  sub  %l0, %o5, %o5
a0082fa4:  94 00 40 0c  add  %g1, %o4, %o2
a0082fa8:  83 3b 60 1f  sra  %o5, 0x1f, %g1
a0082fac:  9a 18 40 0d  xor  %g1, %o5, %o5
a0082fb0:  9a 23 40 01  sub  %o5, %g1, %o5
a0082fb4:  80 a3 60 0a  cmp  %o5, 0xa
a0082fb8:  04 80 00 11  ble  0xa0082ffc
a0082fbc:  9e 03 e0 01  inc  %o7
a0082fc0:  92 0b e0 ff  and  %o7, 0xff, %o1
a0082fc4:  80 a2 60 0b  cmp  %o1, 0xb
a0082fc8:  18 80 00 16  bgu  0xa0083020
a0082fcc:  9b 2a 60 03  sll  %o1, 3, %o5
a0082fd0:  94 03 40 09  add  %o5, %o1, %o2
a0082fd4:  82 02 80 0a  add  %o2, %o2, %g1
a0082fd8:  da 13 00 01  lduh  [ %o4 + %g1 ], %o5
a0082fdc:  9a 24 00 0d  sub  %l0, %o5, %o5
a0082fe0:  94 00 40 0c  add  %g1, %o4, %o2
a0082fe4:  83 3b 60 1f  sra  %o5, 0x1f, %g1
a0082fe8:  9a 18 40 0d  xor  %g1, %o5, %o5
a0082fec:  9a 23 40 01  sub  %o5, %g1, %o5
a0082ff0:  80 a3 60 0a  cmp  %o5, 0xa
a0082ff4:  14 bf ff f3  bg  0xa0082fc0
a0082ff8:  9e 03 e0 01  inc  %o7
a0082ffc:  da 12 a0 02  lduh  [ %o2 + 2 ], %o5
a0083000:  82 22 00 0d  sub  %o0, %o5, %g1
a0083004:  9b 38 60 1f  sra  %g1, 0x1f, %o5
a0083008:  94 1b 40 01  xor  %o5, %g1, %o2
a008300c:  82 22 80 0d  sub  %o2, %o5, %g1
a0083010:  80 a0 60 0a  cmp  %g1, 0xa
a0083014:  34 bf ff ec  bg,a   0xa0082fc4
a0083018:  92 0b e0 ff  and  %o7, 0xff, %o1
a008301c:  a4 10 20 01  mov  1, %l2
a0083020:  80 8c a0 ff  btst  0xff, %l2
a0083024:  02 80 00 32  be  0xa00830ec
a0083028:  9a 0d 60 ff  and  %l5, 0xff, %o5
a008302c:  80 a3 60 00  cmp  %o5, 0
a0083030:  22 80 00 18  be,a   0xa0083090
a0083034:  d8 14 60 06  lduh  [ %l1 + 6 ], %o4
a0083038:  94 0c e0 ff  and  %l3, 0xff, %o2
a008303c:  80 ab 40 0a  andncc  %o5, %o2, %g0
a0083040:  02 80 00 2b  be  0xa00830ec
a0083044:  da 14 60 06  lduh  [ %l1 + 6 ], %o5
a0083048:  c2 15 20 04  lduh  [ %l4 + 4 ], %g1
a008304c:  80 a3 40 01  cmp  %o5, %g1
a0083050:  28 80 00 1e  bleu,a   0xa00830c8
a0083054:  da 36 80 00  sth  %o5, [ %i2 ]
a0083058:  ab 2a 60 03  sll  %o1, 3, %l5
a008305c:  a8 03 60 08  add  %o5, 8, %l4
a0083060:  e8 36 80 00  sth  %l4, [ %i2 ]
a0083064:  a4 05 40 09  add  %l5, %o1, %l2
a0083068:  a2 12 e3 30  or  %o3, 0x330, %l1
a008306c:  1b 2a 00 90  sethi  %hi(0xa8024000), %o5
a0083070:  d6 13 60 0a  lduh  [ %o5 + 0xa ], %o3	! 0xa802400a
a0083074:  90 04 80 12  add  %l2, %l2, %o0
a0083078:  d6 36 00 00  sth  %o3, [ %i0 ]
a008307c:  92 02 00 11  add  %o0, %l1, %o1
a0083080:  f0 12 60 06  lduh  [ %o1 + 6 ], %i0
a0083084:  f0 36 c0 00  sth  %i0, [ %i3 ]
a0083088:  10 80 00 19  b  0xa00830ec
a008308c:  c0 36 40 00  clrh  [ %i1 ]
a0083090:  a6 03 20 08  add  %o4, 8, %l3
a0083094:  9f 2a 60 03  sll  %o1, 3, %o7
a0083098:  e6 36 80 00  sth  %l3, [ %i2 ]
a008309c:  aa 03 c0 09  add  %o7, %o1, %l5
a00830a0:  21 2a 00 90  sethi  %hi(0xa8024000), %l0
a00830a4:  f4 14 20 0a  lduh  [ %l0 + 0xa ], %i2	! 0xa802400a
a00830a8:  a8 12 e3 30  or  %o3, 0x330, %l4
a00830ac:  a4 05 40 15  add  %l5, %l5, %l2
a00830b0:  a2 04 80 14  add  %l2, %l4, %l1
a00830b4:  b2 06 bf f8  add  %i2, -8, %i1
a00830b8:  f2 36 00 00  sth  %i1, [ %i0 ]
a00830bc:  d0 14 60 06  lduh  [ %l1 + 6 ], %o0
a00830c0:  10 80 00 0b  b  0xa00830ec
a00830c4:  d0 36 c0 00  sth  %o0, [ %i3 ]
a00830c8:  19 2a 00 90  sethi  %hi(0xa8024000), %o4
a00830cc:  e6 13 20 0a  lduh  [ %o4 + 0xa ], %l3	! 0xa802400a
a00830d0:  e6 36 00 00  sth  %l3, [ %i0 ]
a00830d4:  1f 2a 00 90  sethi  %hi(0xa8024000), %o7
a00830d8:  e0 13 e0 04  lduh  [ %o7 + 4 ], %l0	! 0xa8024004
a00830dc:  e0 36 c0 00  sth  %l0, [ %i3 ]
a00830e0:  35 2a 00 90  sethi  %hi(0xa8024000), %i2
a00830e4:  f6 16 a0 08  lduh  [ %i2 + 8 ], %i3	! 0xa8024008
a00830e8:  f6 36 40 00  sth  %i3, [ %i1 ]
a00830ec:  81 c7 e0 08  ret
a00830f0:  81 e8 00 00  restore
