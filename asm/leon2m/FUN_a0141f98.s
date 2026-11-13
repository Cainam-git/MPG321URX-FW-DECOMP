# leon2m FUN_a0141f98 0xa0141f98-0xa01420e4 (332 bytes)
a0141f98:  9d e3 bf 98  save  %sp, -104, %sp
a0141f9c:  b2 0e 60 ff  and  %i1, 0xff, %i1
a0141fa0:  80 a6 60 01  cmp  %i1, 1
a0141fa4:  18 80 00 4e  bgu  0xa01420dc
a0141fa8:  11 00 00 3c  sethi  %hi(0xf000), %o0
a0141fac:  d6 16 00 00  lduh  [ %i0 ], %o3
a0141fb0:  82 0a c0 08  and  %o3, %o0, %g1
a0141fb4:  1b 00 00 14  sethi  %hi(0x5000), %o5
a0141fb8:  80 a0 40 0d  cmp  %g1, %o5
a0141fbc:  02 80 00 08  be  0xa0141fdc
a0141fc0:  13 2a 00 b3  sethi  %hi(0xa802cc00), %o1
a0141fc4:  9e 10 20 01  mov  1, %o7
a0141fc8:  97 2b c0 19  sll  %o7, %i1, %o3
a0141fcc:  d8 0a 60 0b  ldub  [ %o1 + 0xb ], %o4
a0141fd0:  94 2b 00 0b  andn  %o4, %o3, %o2
a0141fd4:  d4 2a 60 0b  stb  %o2, [ %o1 + 0xb ]
a0141fd8:  d6 16 00 00  lduh  [ %i0 ], %o3
a0141fdc:  a3 2a e0 10  sll  %o3, 0x10, %l1
a0141fe0:  a1 34 60 1c  srl  %l1, 0x1c, %l0
a0141fe4:  80 a4 20 05  cmp  %l0, 5
a0141fe8:  02 80 00 0e  be  0xa0142020
a0141fec:  03 2a 00 b8  sethi  %hi(0xa802e000), %g1
a0141ff0:  11 00 00 3c  sethi  %hi(0xf000), %o0
a0141ff4:  82 0a c0 08  and  %o3, %o0, %g1
a0141ff8:  31 00 00 14  sethi  %hi(0x5000), %i0
a0141ffc:  80 a0 40 18  cmp  %g1, %i0
a0142000:  02 80 00 37  be  0xa01420dc
a0142004:  13 2a 00 b3  sethi  %hi(0xa802cc00), %o1
a0142008:  9a 10 20 01  mov  1, %o5
a014200c:  e4 0a 60 0a  ldub  [ %o1 + 0xa ], %l2
a0142010:  a3 2b 40 19  sll  %o5, %i1, %l1
a0142014:  b2 2c 80 11  andn  %l2, %l1, %i1
a0142018:  10 80 00 31  b  0xa01420dc
a014201c:  f2 2a 60 0a  stb  %i1, [ %o1 + 0xa ]
a0142020:  da 00 63 d0  ld  [ %g1 + 0x3d0 ], %o5
a0142024:  25 00 02 00  sethi  %hi(0x80000), %l2
a0142028:  80 8b 40 12  btst  %o5, %l2
a014202c:  02 bf ff f2  be  0xa0141ff4
a0142030:  11 00 00 3c  sethi  %hi(0xf000), %o0
a0142034:  d4 16 20 02  lduh  [ %i0 + 2 ], %o2
a0142038:  19 3f ff e0  sethi  %hi(0xffff8000), %o4
a014203c:  92 0a 80 0c  and  %o2, %o4, %o1
a0142040:  91 2a 60 10  sll  %o1, 0x10, %o0
a0142044:  80 a2 20 00  cmp  %o0, 0
a0142048:  22 bf ff eb  be,a   0xa0141ff4
a014204c:  11 00 00 3c  sethi  %hi(0xf000), %o0
a0142050:  19 2a 00 b3  sethi  %hi(0xa802cc00), %o4
a0142054:  da 0b 20 0b  ldub  [ %o4 + 0xb ], %o5	! 0xa802cc0b
a0142058:  9e 0b 60 ff  and  %o5, 0xff, %o7
a014205c:  97 3b c0 19  sra  %o7, %i1, %o3
a0142060:  80 8a e0 01  btst  1, %o3
a0142064:  25 2a 00 b3  sethi  %hi(0xa802cc00), %l2
a0142068:  02 80 00 0c  be  0xa0142098
a014206c:  a2 06 40 19  add  %i1, %i1, %l1
a0142070:  9a 14 a0 0c  or  %l2, 0xc, %o5
a0142074:  67 fd 2d 48  call  0x4008d594
a0142078:  d0 13 40 11  lduh  [ %o5 + %l1 ], %o0
a014207c:  a5 2a 20 10  sll  %o0, 0x10, %l2
a0142080:  a3 34 a0 10  srl  %l2, 0x10, %l1
a0142084:  80 a4 63 e7  cmp  %l1, 0x3e7
a0142088:  08 80 00 0c  bleu  0xa01420b8
a014208c:  21 00 06 9a  sethi  %hi(0x1a6800), %l0
a0142090:  10 bf ff d8  b  0xa0141ff0
a0142094:  d6 16 00 00  lduh  [ %i0 ], %o3
a0142098:  92 10 20 01  mov  1, %o1
a014209c:  91 2a 40 19  sll  %o1, %i1, %o0
a01420a0:  82 12 00 0d  or  %o0, %o5, %g1
a01420a4:  c2 2b 20 0b  stb  %g1, [ %o4 + 0xb ]
a01420a8:  67 fd 2d 38  call  0x4008d588
a01420ac:  a0 14 a0 0c  or  %l2, 0xc, %l0
a01420b0:  10 bf ff f0  b  0xa0142070
a01420b4:  d0 34 00 11  sth  %o0, [ %l0 + %l1 ]
a01420b8:  7f fe 74 2e  call  0xa00df170
a01420bc:  90 14 22 c0  or  %l0, 0x2c0, %o0
a01420c0:  de 16 00 00  lduh  [ %i0 ], %o7
a01420c4:  17 00 00 08  sethi  %hi(0x2000), %o3
a01420c8:  98 0b ef ff  and  %o7, 0xfff, %o4
a01420cc:  94 13 00 0b  or  %o4, %o3, %o2
a01420d0:  d4 36 00 00  sth  %o2, [ %i0 ]
a01420d4:  10 bf ff c7  b  0xa0141ff0
a01420d8:  96 10 00 0a  mov  %o2, %o3
a01420dc:  81 c7 e0 08  ret
a01420e0:  81 e8 00 00  restore
