# leon2m FUN_a0107e44 0xa0107e44-0xa01083fc (1464 bytes)
a0107e44:  9d e3 bf 88  save  %sp, -120, %sp
a0107e48:  19 2a 00 b2  sethi  %hi(0xa802c800), %o4
a0107e4c:  97 2e 60 10  sll  %i1, 0x10, %o3
a0107e50:  93 32 e0 10  srl  %o3, 0x10, %o1
a0107e54:  d4 13 21 86  lduh  [ %o4 + 0x186 ], %o2
a0107e58:  90 1a 80 09  xor  %o2, %o1, %o0
a0107e5c:  80 a0 00 08  cmp  %g0, %o0
a0107e60:  9a 60 3f ff  subx  %g0, -1, %o5
a0107e64:  b4 0e a0 ff  and  %i2, 0xff, %i2
a0107e68:  80 a0 00 1a  cmp  %g0, %i2
a0107e6c:  82 60 3f ff  subx  %g0, -1, %g1
a0107e70:  80 8b 40 01  btst  %o5, %g1
a0107e74:  12 80 01 60  bne  0xa01083f4
a0107e78:  a6 10 00 19  mov  %i1, %l3
a0107e7c:  25 00 06 6a  sethi  %hi(0x19a800), %l2
a0107e80:  f2 33 21 86  sth  %i1, [ %o4 + 0x186 ]
a0107e84:  7f ff 5c bb  call  0xa00df170
a0107e88:  90 14 a3 a8  or  %l2, 0x3a8, %o0
a0107e8c:  23 2a 00 b5  sethi  %hi(0xa802d400), %l1
a0107e90:  d2 04 62 a4  ld  [ %l1 + 0x2a4 ], %o1	! 0xa802d6a4
a0107e94:  a0 0e 20 ff  and  %i0, 0xff, %l0
a0107e98:  de 12 60 2a  lduh  [ %o1 + 0x2a ], %o7
a0107e9c:  d8 12 60 2e  lduh  [ %o1 + 0x2e ], %o4
a0107ea0:  80 a4 20 01  cmp  %l0, 1
a0107ea4:  ba 03 e0 01  add  %o7, 1, %i5
a0107ea8:  ec 12 60 0a  lduh  [ %o1 + 0xa ], %l6
a0107eac:  ea 12 60 30  lduh  [ %o1 + 0x30 ], %l5
a0107eb0:  ee 12 60 32  lduh  [ %o1 + 0x32 ], %l7
a0107eb4:  02 80 01 25  be  0xa0108348
a0107eb8:  d8 37 bf ee  sth  %o4, [ %fp + -18 ]
a0107ebc:  f8 12 60 26  lduh  [ %o1 + 0x26 ], %i4
a0107ec0:  e0 12 60 20  lduh  [ %o1 + 0x20 ], %l0
a0107ec4:  f6 12 60 08  lduh  [ %o1 + 8 ], %i3
a0107ec8:  f0 12 60 28  lduh  [ %o1 + 0x28 ], %i0
a0107ecc:  93 2c 20 10  sll  %l0, 0x10, %o1
a0107ed0:  a9 3a 60 10  sra  %o1, 0x10, %l4
a0107ed4:  f0 37 bf f6  sth  %i0, [ %fp + -10 ]
a0107ed8:  40 01 37 5a  call  0xa0155c40
a0107edc:  90 10 00 14  mov  %l4, %o0
a0107ee0:  80 a5 20 00  cmp  %l4, 0
a0107ee4:  06 80 01 2d  bl  0xa0108398
a0107ee8:  a4 10 00 08  mov  %o0, %l2
a0107eec:  a9 2f 60 10  sll  %i5, 0x10, %l4
a0107ef0:  40 01 37 54  call  0xa0155c40
a0107ef4:  91 35 20 10  srl  %l4, 0x10, %o0
a0107ef8:  92 10 00 08  mov  %o0, %o1
a0107efc:  40 01 36 4d  call  0xa0155830
a0107f00:  90 10 00 12  mov  %l2, %o0
a0107f04:  a0 10 00 08  mov  %o0, %l0
a0107f08:  a3 2c e0 10  sll  %l3, 0x10, %l1
a0107f0c:  40 01 37 4d  call  0xa0155c40
a0107f10:  91 34 60 10  srl  %l1, 0x10, %o0
a0107f14:  92 10 00 08  mov  %o0, %o1
a0107f18:  40 01 36 46  call  0xa0155830
a0107f1c:  90 10 00 10  mov  %l0, %o0
a0107f20:  27 00 06 61  sethi  %hi(0x198400), %l3
a0107f24:  40 01 36 bd  call  0xa0155a18
a0107f28:  d2 04 e3 60  ld  [ %l3 + 0x360 ], %o1	! 0x198760
a0107f2c:  40 01 34 a4  call  0xa01551bc
a0107f30:  01 00 00 00  nop
a0107f34:  15 2a 00 b5  sethi  %hi(0xa802d400), %o2
a0107f38:  da 02 a2 a4  ld  [ %o2 + 0x2a4 ], %o5	! 0xa802d6a4
a0107f3c:  f2 13 60 20  lduh  [ %o5 + 0x20 ], %i1
a0107f40:  b1 2e 60 10  sll  %i1, 0x10, %i0
a0107f44:  f4 13 60 24  lduh  [ %o5 + 0x24 ], %i2
a0107f48:  83 36 20 10  srl  %i0, 0x10, %g1
a0107f4c:  80 a6 80 01  cmp  %i2, %g1
a0107f50:  18 80 00 c8  bgu  0xa0108270
a0107f54:  b4 10 00 0d  mov  %o5, %i2
a0107f58:  92 10 00 08  mov  %o0, %o1
a0107f5c:  7f ff e9 e3  call  0xa01026e8
a0107f60:  90 10 20 04  mov  4, %o0
a0107f64:  a0 27 40 16  sub  %i5, %l6, %l0
a0107f68:  9a 26 40 1b  sub  %i1, %i3, %o5
a0107f6c:  82 24 00 17  sub  %l0, %l7, %g1
a0107f70:  d4 17 bf f6  lduh  [ %fp + -10 ], %o2
a0107f74:  f4 17 bf ee  lduh  [ %fp + -18 ], %i2
a0107f78:  a2 23 40 0a  sub  %o5, %o2, %l1
a0107f7c:  b2 20 40 15  sub  %g1, %l5, %i1
a0107f80:  9e 26 80 16  sub  %i2, %l6, %o7
a0107f84:  a6 0e 6f ff  and  %i1, 0xfff, %l3
a0107f88:  90 24 40 1c  sub  %l1, %i4, %o0
a0107f8c:  ba 23 c0 17  sub  %o7, %l7, %i5
a0107f90:  80 a4 e0 00  cmp  %l3, 0
a0107f94:  a4 0a 2f ff  and  %o0, 0xfff, %l2
a0107f98:  98 27 40 15  sub  %i5, %l5, %o4
a0107f9c:  12 80 00 03  bne  0xa0107fa8
a0107fa0:  a0 10 00 13  mov  %l3, %l0
a0107fa4:  a0 10 20 01  mov  1, %l0
a0107fa8:  bb 2b 20 10  sll  %o4, 0x10, %i5
a0107fac:  27 00 00 0f  sethi  %hi(0x3c00), %l3
a0107fb0:  93 37 60 10  srl  %i5, 0x10, %o1
a0107fb4:  96 14 e3 ff  or  %l3, 0x3ff, %o3
a0107fb8:  80 a2 40 0b  cmp  %o1, %o3
a0107fbc:  18 80 00 d3  bgu  0xa0108308
a0107fc0:  3b 3f ff f8  sethi  %hi(0xffffe000), %i5
a0107fc4:  a6 03 00 1d  add  %o4, %i5, %l3
a0107fc8:  93 2c e0 10  sll  %l3, 0x10, %o1
a0107fcc:  17 00 00 07  sethi  %hi(0x1c00), %o3
a0107fd0:  95 32 60 10  srl  %o1, 0x10, %o2
a0107fd4:  9a 12 e3 ff  or  %o3, 0x3ff, %o5
a0107fd8:  80 a2 80 0d  cmp  %o2, %o5
a0107fdc:  08 80 00 df  bleu  0xa0108358
a0107fe0:  96 03 30 00  add  %o4, -4096, %o3
a0107fe4:  95 2a e0 10  sll  %o3, 0x10, %o2
a0107fe8:  9b 32 a0 10  srl  %o2, 0x10, %o5
a0107fec:  80 a3 6f ff  cmp  %o5, 0xfff
a0107ff0:  08 80 00 f1  bleu  0xa01083b4
a0107ff4:  1b 33 c0 47  sethi  %hi(0xcf011c00), %o5
a0107ff8:  b2 13 62 40  or  %o5, 0x240, %i1	! 0xcf011e40
a0107ffc:  c2 06 40 00  ld  [ %i1 ], %g1
a0108000:  b4 08 7f f1  and  %g1, -15, %i2
a0108004:  f4 26 40 00  st  %i2, [ %i1 ]
a0108008:  9a 10 20 00  clr  %o5
a010800c:  97 2d 60 10  sll  %l5, 0x10, %o3
a0108010:  a7 32 e0 10  srl  %o3, 0x10, %l3
a0108014:  96 0b 60 03  and  %o5, 3, %o3
a0108018:  ab 3c c0 0b  sra  %l3, %o3, %l5
a010801c:  95 2d 60 10  sll  %l5, 0x10, %o2
a0108020:  13 2a 00 b5  sethi  %hi(0xa802d400), %o1
a0108024:  e0 32 63 02  sth  %l0, [ %o1 + 0x302 ]	! 0xa802d702
a0108028:  80 a2 a0 00  cmp  %o2, 0
a010802c:  12 80 00 03  bne  0xa0108038
a0108030:  b4 10 00 15  mov  %l5, %i2
a0108034:  b4 10 20 01  mov  1, %i2
a0108038:  91 2d e0 10  sll  %l7, 0x10, %o0
a010803c:  99 32 20 10  srl  %o0, 0x10, %o4
a0108040:  af 3b 00 0b  sra  %o4, %o3, %l7
a0108044:  bb 2d e0 10  sll  %l7, 0x10, %i5
a0108048:  80 a7 60 00  cmp  %i5, 0
a010804c:  12 80 00 03  bne  0xa0108058
a0108050:  aa 10 00 17  mov  %l7, %l5
a0108054:  aa 10 20 01  mov  1, %l5
a0108058:  a2 0c 2f ff  and  %l0, 0xfff, %l1
a010805c:  a1 3c 40 0b  sra  %l1, %o3, %l0
a0108060:  9f 2c 20 10  sll  %l0, 0x10, %o7
a0108064:  80 a3 e0 00  cmp  %o7, 0
a0108068:  12 80 00 03  bne  0xa0108074
a010806c:  a6 10 00 10  mov  %l0, %l3
a0108070:  a6 10 20 01  mov  1, %l3
a0108074:  9b 2d a0 10  sll  %l6, 0x10, %o5
a0108078:  83 33 60 10  srl  %o5, 0x10, %g1
a010807c:  ad 38 40 0b  sra  %g1, %o3, %l6
a0108080:  b3 2d a0 10  sll  %l6, 0x10, %i1
a0108084:  80 a6 60 00  cmp  %i1, 0
a0108088:  12 80 00 03  bne  0xa0108094
a010808c:  a0 10 00 16  mov  %l6, %l0
a0108090:  a0 10 20 01  mov  1, %l0
a0108094:  b3 2f 20 10  sll  %i4, 0x10, %i1
a0108098:  39 33 c0 46  sethi  %hi(0xcf011800), %i4
a010809c:  93 36 60 10  srl  %i1, 0x10, %o1
a01080a0:  7f ff ab fb  call  0xa00f308c
a01080a4:  90 17 22 c0  or  %i4, 0x2c0, %o0
a01080a8:  a4 0c af ff  and  %l2, 0xfff, %l2
a01080ac:  90 17 22 c8  or  %i4, 0x2c8, %o0
a01080b0:  7f ff ab f7  call  0xa00f308c
a01080b4:  92 10 00 12  mov  %l2, %o1
a01080b8:  ec 17 bf f6  lduh  [ %fp + -10 ], %l6
a01080bc:  a3 2d a0 10  sll  %l6, 0x10, %l1
a01080c0:  93 34 60 10  srl  %l1, 0x10, %o1
a01080c4:  7f ff ab f2  call  0xa00f308c
a01080c8:  90 17 22 d0  or  %i4, 0x2d0, %o0
a01080cc:  9f 2e e0 10  sll  %i3, 0x10, %o7
a01080d0:  af 33 e0 10  srl  %o7, 0x10, %l7
a01080d4:  90 17 22 d8  or  %i4, 0x2d8, %o0
a01080d8:  7f ff ab ed  call  0xa00f308c
a01080dc:  92 10 00 17  mov  %l7, %o1
a01080e0:  91 2e a0 10  sll  %i2, 0x10, %o0
a01080e4:  93 32 20 10  srl  %o0, 0x10, %o1
a01080e8:  7f ff ab e9  call  0xa00f308c
a01080ec:  90 17 22 e0  or  %i4, 0x2e0, %o0
a01080f0:  99 2c e0 10  sll  %l3, 0x10, %o4
a01080f4:  a7 33 20 10  srl  %o4, 0x10, %l3
a01080f8:  90 17 22 e8  or  %i4, 0x2e8, %o0
a01080fc:  7f ff ab e4  call  0xa00f308c
a0108100:  92 10 00 13  mov  %l3, %o1
a0108104:  bb 2d 60 10  sll  %l5, 0x10, %i5
a0108108:  93 37 60 10  srl  %i5, 0x10, %o1
a010810c:  7f ff ab e0  call  0xa00f308c
a0108110:  90 17 22 f0  or  %i4, 0x2f0, %o0
a0108114:  97 2c 20 10  sll  %l0, 0x10, %o3
a0108118:  ab 32 e0 10  srl  %o3, 0x10, %l5
a010811c:  90 17 22 f8  or  %i4, 0x2f8, %o0
a0108120:  7f ff ab db  call  0xa00f308c
a0108124:  92 10 00 15  mov  %l5, %o1
a0108128:  94 17 22 a0  or  %i4, 0x2a0, %o2
a010812c:  f4 02 80 00  ld  [ %o2 ], %i2
a0108130:  92 16 a0 80  or  %i2, 0x80, %o1
a0108134:  d2 22 80 00  st  %o1, [ %o2 ]
a0108138:  35 33 c0 47  sethi  %hi(0xcf011c00), %i2
a010813c:  92 10 00 12  mov  %l2, %o1
a0108140:  7f ff ab d3  call  0xa00f308c
a0108144:  90 16 a0 10  or  %i2, 0x10, %o0
a0108148:  92 10 00 17  mov  %l7, %o1
a010814c:  7f ff ab d0  call  0xa00f308c
a0108150:  90 16 a0 18  or  %i2, 0x18, %o0
a0108154:  93 36 20 10  srl  %i0, 0x10, %o1
a0108158:  7f ff ab cd  call  0xa00f308c
a010815c:  90 16 a0 20  or  %i2, 0x20, %o0
a0108160:  90 16 a0 28  or  %i2, 0x28, %o0
a0108164:  7f ff ab ca  call  0xa00f308c
a0108168:  92 10 00 13  mov  %l3, %o1
a010816c:  92 10 00 15  mov  %l5, %o1
a0108170:  7f ff ab c7  call  0xa00f308c
a0108174:  90 16 a0 30  or  %i2, 0x30, %o0
a0108178:  93 35 20 10  srl  %l4, 0x10, %o1
a010817c:  7f ff ab c4  call  0xa00f308c
a0108180:  90 16 a0 38  or  %i2, 0x38, %o0
a0108184:  90 16 a0 40  or  %i2, 0x40, %o0
a0108188:  7f ff ab c1  call  0xa00f308c
a010818c:  92 10 20 00  clr  %o1
a0108190:  93 35 20 11  srl  %l4, 0x11, %o1
a0108194:  7f ff ab be  call  0xa00f308c
a0108198:  90 16 a0 48  or  %i2, 0x48, %o0
a010819c:  90 16 a0 50  or  %i2, 0x50, %o0
a01081a0:  7f ff ab bb  call  0xa00f308c
a01081a4:  92 10 20 00  clr  %o1
a01081a8:  90 16 a0 58  or  %i2, 0x58, %o0
a01081ac:  7f ff ab b8  call  0xa00f308c
a01081b0:  92 10 20 00  clr  %o1
a01081b4:  31 2a 00 b5  sethi  %hi(0xa802d400), %i0
a01081b8:  e8 06 22 a4  ld  [ %i0 + 0x2a4 ], %l4	! 0xa802d6a4
a01081bc:  f6 15 20 0a  lduh  [ %l4 + 0xa ], %i3
a01081c0:  80 a6 ef ff  cmp  %i3, 0xfff
a01081c4:  18 80 00 05  bgu  0xa01081d8
a01081c8:  9a 17 22 80  or  %i4, 0x280, %o5
a01081cc:  c2 03 40 00  ld  [ %o5 ], %g1
a01081d0:  a0 10 60 80  or  %g1, 0x80, %l0
a01081d4:  e0 23 40 00  st  %l0, [ %o5 ]
a01081d8:  f0 03 40 00  ld  [ %o5 ], %i0
a01081dc:  a8 16 20 02  or  %i0, 2, %l4
a01081e0:  e8 23 40 00  st  %l4, [ %o5 ]
a01081e4:  c0 26 80 00  clr  [ %i2 ]
a01081e8:  b8 16 a0 04  or  %i2, 4, %i4
a01081ec:  b6 10 20 60  mov  0x60, %i3
a01081f0:  94 10 00 13  mov  %l3, %o2
a01081f4:  90 10 20 00  clr  %o0
a01081f8:  92 10 20 44  mov  0x44, %o1
a01081fc:  f6 27 00 00  st  %i3, [ %i4 ]
a0108200:  40 00 43 e7  call  0xa011919c
a0108204:  01 00 00 00  nop
a0108208:  94 10 00 13  mov  %l3, %o2
a010820c:  90 10 20 01  mov  1, %o0
a0108210:  40 00 43 e3  call  0xa011919c
a0108214:  92 10 20 44  mov  0x44, %o1
a0108218:  90 10 20 00  clr  %o0
a010821c:  92 10 20 a5  mov  0xa5, %o1
a0108220:  94 10 20 08  mov  8, %o2
a0108224:  40 00 43 f6  call  0xa01191fc
a0108228:  96 10 20 01  mov  1, %o3
a010822c:  90 10 20 01  mov  1, %o0
a0108230:  92 10 20 a5  mov  0xa5, %o1
a0108234:  94 10 20 08  mov  8, %o2
a0108238:  40 00 43 f1  call  0xa01191fc
a010823c:  96 10 20 01  mov  1, %o3
a0108240:  1b 33 c0 4d  sethi  %hi(0xcf013400), %o5
a0108244:  a6 13 60 0c  or  %o5, 0xc, %l3	! 0xcf01340c
a0108248:  c0 24 c0 00  clr  [ %l3 ]
a010824c:  30 80 00 6a  b,a   0xa01083f4
a0108250:  80 a3 00 08  cmp  %o4, %o0
a0108254:  0a bf ff 42  bcs  0xa0107f5c
a0108258:  92 10 00 08  mov  %o0, %o1
a010825c:  d2 16 a0 24  lduh  [ %i2 + 0x24 ], %o1
a0108260:  80 a2 40 0f  cmp  %o1, %o7
a0108264:  08 80 00 52  bleu  0xa01083ac
a0108268:  b2 10 00 0a  mov  %o2, %i1
a010826c:  b0 10 00 0b  mov  %o3, %i0
a0108270:  a1 3e 20 10  sra  %i0, 0x10, %l0
a0108274:  40 01 36 73  call  0xa0155c40
a0108278:  90 10 00 10  mov  %l0, %o0
a010827c:  80 a4 20 00  cmp  %l0, 0
a0108280:  06 80 00 1d  bl  0xa01082f4
a0108284:  a4 10 00 08  mov  %o0, %l2
a0108288:  40 01 36 6e  call  0xa0155c40
a010828c:  91 35 20 10  srl  %l4, 0x10, %o0
a0108290:  92 10 00 08  mov  %o0, %o1
a0108294:  40 01 35 67  call  0xa0155830
a0108298:  90 10 00 12  mov  %l2, %o0
a010829c:  a4 10 00 08  mov  %o0, %l2
a01082a0:  40 01 36 68  call  0xa0155c40
a01082a4:  91 34 60 10  srl  %l1, 0x10, %o0
a01082a8:  92 10 00 08  mov  %o0, %o1
a01082ac:  40 01 35 61  call  0xa0155830
a01082b0:  90 10 00 12  mov  %l2, %o0
a01082b4:  40 01 35 d9  call  0xa0155a18
a01082b8:  d2 04 e3 60  ld  [ %l3 + 0x360 ], %o1
a01082bc:  40 01 33 c0  call  0xa01551bc
a01082c0:  01 00 00 00  nop
a01082c4:  94 06 60 08  add  %i1, 8, %o2
a01082c8:  97 2a a0 10  sll  %o2, 0x10, %o3
a01082cc:  98 10 20 00  clr  %o4
a01082d0:  c2 06 a0 10  ld  [ %i2 + 0x10 ], %g1
a01082d4:  80 a0 40 0c  cmp  %g1, %o4
a01082d8:  0a bf ff 20  bcs  0xa0107f58
a01082dc:  9f 32 e0 10  srl  %o3, 0x10, %o7
a01082e0:  80 a0 40 0c  cmp  %g1, %o4
a01082e4:  32 bf ff df  bne,a   0xa0108260
a01082e8:  d2 16 a0 24  lduh  [ %i2 + 0x24 ], %o1
a01082ec:  10 bf ff d9  b  0xa0108250
a01082f0:  d8 06 a0 14  ld  [ %i2 + 0x14 ], %o4
a01082f4:  17 00 06 68  sethi  %hi(0x19a000), %o3
a01082f8:  40 01 35 25  call  0xa015578c
a01082fc:  d2 02 e2 d0  ld  [ %o3 + 0x2d0 ], %o1	! 0x19a2d0
a0108300:  10 bf ff e2  b  0xa0108288
a0108304:  a4 10 00 08  mov  %o0, %l2
a0108308:  40 00 53 20  call  0xa011cf88
a010830c:  01 00 00 00  nop
a0108310:  98 0a 20 ff  and  %o0, 0xff, %o4
a0108314:  80 a3 20 83  cmp  %o4, 0x83
a0108318:  28 bf ff 38  bleu,a   0xa0107ff8
a010831c:  1b 33 c0 47  sethi  %hi(0xcf011c00), %o5
a0108320:  03 33 c0 47  sethi  %hi(0xcf011c00), %g1
a0108324:  90 10 62 40  or  %g1, 0x240, %o0	! 0xcf011e40
a0108328:  f4 02 00 00  ld  [ %o0 ], %i2
a010832c:  b2 0e bf f3  and  %i2, -13, %i1
a0108330:  f2 22 00 00  st  %i1, [ %o0 ]
a0108334:  e2 02 00 00  ld  [ %o0 ], %l1
a0108338:  9e 14 60 02  or  %l1, 2, %o7
a010833c:  de 22 00 00  st  %o7, [ %o0 ]
a0108340:  10 bf ff 33  b  0xa010800c
a0108344:  9a 10 20 03  mov  3, %o5
a0108348:  f8 12 60 26  lduh  [ %o1 + 0x26 ], %i4
a010834c:  e0 12 60 20  lduh  [ %o1 + 0x20 ], %l0
a0108350:  10 bf fe de  b  0xa0107ec8
a0108354:  b6 10 00 16  mov  %l6, %i3
a0108358:  40 00 53 0c  call  0xa011cf88
a010835c:  01 00 00 00  nop
a0108360:  98 0a 20 ff  and  %o0, 0xff, %o4
a0108364:  80 a3 20 83  cmp  %o4, 0x83
a0108368:  28 bf ff 24  bleu,a   0xa0107ff8
a010836c:  1b 33 c0 47  sethi  %hi(0xcf011c00), %o5
a0108370:  03 33 c0 47  sethi  %hi(0xcf011c00), %g1
a0108374:  90 10 62 40  or  %g1, 0x240, %o0	! 0xcf011e40
a0108378:  f4 02 00 00  ld  [ %o0 ], %i2
a010837c:  b2 0e bf f5  and  %i2, -11, %i1
a0108380:  f2 22 00 00  st  %i1, [ %o0 ]
a0108384:  e2 02 00 00  ld  [ %o0 ], %l1
a0108388:  9e 14 60 04  or  %l1, 4, %o7
a010838c:  de 22 00 00  st  %o7, [ %o0 ]
a0108390:  10 bf ff 1f  b  0xa010800c
a0108394:  9a 10 20 02  mov  2, %o5
a0108398:  33 00 06 68  sethi  %hi(0x19a000), %i1
a010839c:  40 01 34 fc  call  0xa015578c
a01083a0:  d2 06 62 d0  ld  [ %i1 + 0x2d0 ], %o1	! 0x19a2d0
a01083a4:  10 bf fe d2  b  0xa0107eec
a01083a8:  a4 10 00 08  mov  %o0, %l2
a01083ac:  10 bf fe eb  b  0xa0107f58
a01083b0:  b0 10 00 0b  mov  %o3, %i0
a01083b4:  40 00 52 f5  call  0xa011cf88
a01083b8:  01 00 00 00  nop
a01083bc:  92 0a 20 ff  and  %o0, 0xff, %o1
a01083c0:  80 a2 60 82  cmp  %o1, 0x82
a01083c4:  28 bf ff 0d  bleu,a   0xa0107ff8
a01083c8:  1b 33 c0 47  sethi  %hi(0xcf011c00), %o5
a01083cc:  23 33 c0 47  sethi  %hi(0xcf011c00), %l1
a01083d0:  a6 14 62 40  or  %l1, 0x240, %l3	! 0xcf011e40
a01083d4:  de 04 c0 00  ld  [ %l3 ], %o7
a01083d8:  90 0b ff f9  and  %o7, -7, %o0
a01083dc:  d0 24 c0 00  st  %o0, [ %l3 ]
a01083e0:  d8 04 c0 00  ld  [ %l3 ], %o4
a01083e4:  ba 13 20 08  or  %o4, 8, %i5
a01083e8:  fa 24 c0 00  st  %i5, [ %l3 ]
a01083ec:  10 bf ff 08  b  0xa010800c
a01083f0:  9a 10 20 01  mov  1, %o5
a01083f4:  81 c7 e0 08  ret
a01083f8:  81 e8 00 00  restore
