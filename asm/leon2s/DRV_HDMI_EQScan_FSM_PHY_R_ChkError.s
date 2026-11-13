# leon2s DRV_HDMI_EQScan_FSM_PHY_R_ChkError 0xa0077f04-0xa00787f4 (2288 bytes)
a0077f04:  9d e3 bf 70  save  %sp, -144, %sp
a0077f08:  23 2a 01 ea  sethi  %hi(0xa807a800), %l1
a0077f0c:  a0 0e 20 ff  and  %i0, 0xff, %l0
a0077f10:  9a 14 61 f0  or  %l1, 0x1f0, %o5
a0077f14:  82 5c 28 98  smul  %l0, 0x898, %g1
a0077f18:  82 00 40 0d  add  %g1, %o5, %g1
a0077f1c:  c2 08 60 30  ldub  [ %g1 + 0x30 ], %g1
a0077f20:  98 10 20 00  clr  %o4
a0077f24:  9a 10 20 00  clr  %o5
a0077f28:  aa 10 00 18  mov  %i0, %l5
a0077f2c:  d8 3f bf d8  std  %o4, [ %fp + -40 ]
a0077f30:  80 a0 60 00  cmp  %g1, 0
a0077f34:  d8 3f bf e8  std  %o4, [ %fp + -24 ]
a0077f38:  c0 27 bf f0  clr  [ %fp + -16 ]
a0077f3c:  12 80 00 1d  bne  0xa0077fb0
a0077f40:  c0 27 bf e0  clr  [ %fp + -32 ]
a0077f44:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a0077f48:  c2 00 62 34  ld  [ %g1 + 0x234 ], %g1	! 0xa8078634
a0077f4c:  80 88 60 02  btst  2, %g1
a0077f50:  02 80 00 0b  be  0xa0077f7c
a0077f54:  82 14 61 f0  or  %l1, 0x1f0, %g1
a0077f58:  92 06 20 41  add  %i0, 0x41, %o1
a0077f5c:  93 2a 60 18  sll  %o1, 0x18, %o1
a0077f60:  11 28 01 9d  sethi  %hi(0xa0067400), %o0
a0077f64:  15 28 02 cf  sethi  %hi(0xa00b3c00), %o2
a0077f68:  90 12 20 28  or  %o0, 0x28, %o0
a0077f6c:  93 3a 60 18  sra  %o1, 0x18, %o1
a0077f70:  7f ff ec 35  call  0xa0073044
a0077f74:  94 12 a1 60  or  %o2, 0x160, %o2
a0077f78:  82 14 61 f0  or  %l1, 0x1f0, %g1
a0077f7c:  9a 5c 28 98  smul  %l0, 0x898, %o5
a0077f80:  9a 03 40 01  add  %o5, %g1, %o5
a0077f84:  c2 0b 60 30  ldub  [ %o5 + 0x30 ], %g1
a0077f88:  80 a0 60 00  cmp  %g1, 0
a0077f8c:  12 80 00 09  bne  0xa0077fb0
a0077f90:  03 2a 01 d8  sethi  %hi(0xa8076000), %g1
a0077f94:  82 10 61 a0  or  %g1, 0x1a0, %g1	! 0xa80761a0
a0077f98:  c2 08 40 10  ldub  [ %g1 + %l0 ], %g1
a0077f9c:  80 a0 60 01  cmp  %g1, 1
a0077fa0:  08 80 00 05  bleu  0xa0077fb4
a0077fa4:  82 14 61 f0  or  %l1, 0x1f0, %g1
a0077fa8:  7f ff f3 a4  call  0xa0074e38
a0077fac:  90 10 00 10  mov  %l0, %o0
a0077fb0:  82 14 61 f0  or  %l1, 0x1f0, %g1
a0077fb4:  98 5c 28 98  smul  %l0, 0x898, %o4
a0077fb8:  98 03 00 01  add  %o4, %g1, %o4
a0077fbc:  da 0b 20 30  ldub  [ %o4 + 0x30 ], %o5
a0077fc0:  03 2a 01 d8  sethi  %hi(0xa8076000), %g1
a0077fc4:  9a 03 60 01  inc  %o5
a0077fc8:  82 10 61 a0  or  %g1, 0x1a0, %g1
a0077fcc:  c2 08 40 10  ldub  [ %g1 + %l0 ], %g1
a0077fd0:  96 0b 60 ff  and  %o5, 0xff, %o3
a0077fd4:  da 2b 20 30  stb  %o5, [ %o4 + 0x30 ]
a0077fd8:  80 a2 c0 01  cmp  %o3, %g1
a0077fdc:  0a 80 02 04  bcs  0xa00787ec
a0077fe0:  b0 10 20 00  clr  %i0
a0077fe4:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a0077fe8:  c2 00 62 34  ld  [ %g1 + 0x234 ], %g1	! 0xa8078634
a0077fec:  80 88 60 02  btst  2, %g1
a0077ff0:  02 80 00 0b  be  0xa007801c
a0077ff4:  ac 10 20 00  clr  %l6
a0077ff8:  92 05 60 41  add  %l5, 0x41, %o1
a0077ffc:  93 2a 60 18  sll  %o1, 0x18, %o1
a0078000:  11 28 01 9d  sethi  %hi(0xa0067400), %o0
a0078004:  15 28 02 cf  sethi  %hi(0xa00b3c00), %o2
a0078008:  90 12 20 50  or  %o0, 0x50, %o0
a007800c:  93 3a 60 18  sra  %o1, 0x18, %o1
a0078010:  7f ff ec 0d  call  0xa0073044
a0078014:  94 12 a1 60  or  %o2, 0x160, %o2
a0078018:  ac 10 20 00  clr  %l6
a007801c:  2f 2a 01 ea  sethi  %hi(0xa807a800), %l7
a0078020:  b0 0d 60 ff  and  %l5, 0xff, %i0
a0078024:  82 15 e1 f0  or  %l7, 0x1f0, %g1
a0078028:  9a 5e 28 98  smul  %i0, 0x898, %o5
a007802c:  9a 03 40 01  add  %o5, %g1, %o5
a0078030:  a2 0d a0 ff  and  %l6, 0xff, %l1
a0078034:  9a 03 40 11  add  %o5, %l1, %o5
a0078038:  c2 0b 60 2d  ldub  [ %o5 + 0x2d ], %g1
a007803c:  80 a0 60 01  cmp  %g1, 1
a0078040:  02 80 00 ad  be  0xa00782f4
a0078044:  80 a4 60 00  cmp  %l1, 0
a0078048:  12 80 00 1f  bne  0xa00780c4
a007804c:  80 a4 60 01  cmp  %l1, 1
a0078050:  21 00 00 07  sethi  %hi(0x1c00), %l0
a0078054:  90 10 20 00  clr  %o0
a0078058:  92 10 00 18  mov  %i0, %o1
a007805c:  40 00 bd 03  call  0xa00a7468
a0078060:  94 14 22 a0  or  %l0, 0x2a0, %o2
a0078064:  80 a2 20 00  cmp  %o0, 0
a0078068:  a4 07 bf f8  add  %fp, -8, %l2
a007806c:  12 80 00 06  bne  0xa0078084
a0078070:  90 10 20 00  clr  %o0
a0078074:  92 14 22 94  or  %l0, 0x294, %o1
a0078078:  40 00 bc a7  call  0xa00a7314
a007807c:  90 10 00 18  mov  %i0, %o0
a0078080:  91 32 20 18  srl  %o0, 0x18, %o0
a0078084:  23 00 00 07  sethi  %hi(0x1c00), %l1
a0078088:  d0 24 bf f0  st  %o0, [ %l2 + -16 ]
a007808c:  92 14 62 a0  or  %l1, 0x2a0, %o1
a0078090:  40 00 bc a1  call  0xa00a7314
a0078094:  90 10 00 18  mov  %i0, %o0
a0078098:  03 00 00 3f  sethi  %hi(0xfc00), %g1
a007809c:  82 10 63 00  or  %g1, 0x300, %g1	! 0xff00
a00780a0:  a0 0a 00 01  and  %o0, %g1, %l0
a00780a4:  90 10 00 18  mov  %i0, %o0
a00780a8:  40 00 bc 9b  call  0xa00a7314
a00780ac:  92 14 62 a0  or  %l1, 0x2a0, %o1
a00780b0:  91 32 20 10  srl  %o0, 0x10, %o0
a00780b4:  90 0a 20 ff  and  %o0, 0xff, %o0
a00780b8:  a0 14 00 08  or  %l0, %o0, %l0
a00780bc:  10 80 00 40  b  0xa00781bc
a00780c0:  e0 24 bf e0  st  %l0, [ %l2 + -32 ]
a00780c4:  12 80 00 1e  bne  0xa007813c
a00780c8:  83 2c 60 02  sll  %l1, 2, %g1
a00780cc:  21 00 00 07  sethi  %hi(0x1c00), %l0
a00780d0:  90 10 20 01  mov  1, %o0
a00780d4:  92 10 00 18  mov  %i0, %o1
a00780d8:  40 00 bc e4  call  0xa00a7468
a00780dc:  94 14 22 a0  or  %l0, 0x2a0, %o2
a00780e0:  80 a2 20 00  cmp  %o0, 0
a00780e4:  12 80 00 06  bne  0xa00780fc
a00780e8:  90 10 20 00  clr  %o0
a00780ec:  92 14 22 98  or  %l0, 0x298, %o1
a00780f0:  40 00 bc 89  call  0xa00a7314
a00780f4:  90 10 00 18  mov  %i0, %o0
a00780f8:  90 0a 20 ff  and  %o0, 0xff, %o0
a00780fc:  82 07 bf fc  add  %fp, -4, %g1
a0078100:  d0 20 7f f0  st  %o0, [ %g1 + -16 ]
a0078104:  23 00 00 07  sethi  %hi(0x1c00), %l1
a0078108:  92 14 62 a0  or  %l1, 0x2a0, %o1	! 0x1ea0
a007810c:  40 00 bc 82  call  0xa00a7314
a0078110:  90 10 00 18  mov  %i0, %o0
a0078114:  03 3f c0 00  sethi  %hi(0xff000000), %g1
a0078118:  a0 0a 00 01  and  %o0, %g1, %l0
a007811c:  90 10 00 18  mov  %i0, %o0
a0078120:  40 00 bc 7d  call  0xa00a7314
a0078124:  92 14 62 a4  or  %l1, 0x2a4, %o1
a0078128:  a1 34 20 10  srl  %l0, 0x10, %l0
a007812c:  90 0a 20 ff  and  %o0, 0xff, %o0
a0078130:  a0 14 00 08  or  %l0, %o0, %l0
a0078134:  10 80 00 22  b  0xa00781bc
a0078138:  e0 27 bf dc  st  %l0, [ %fp + -36 ]
a007813c:  a8 07 bf f8  add  %fp, -8, %l4
a0078140:  21 00 00 07  sethi  %hi(0x1c00), %l0
a0078144:  a6 00 40 14  add  %g1, %l4, %l3
a0078148:  90 10 20 02  mov  2, %o0
a007814c:  92 10 00 18  mov  %i0, %o1
a0078150:  40 00 bc c6  call  0xa00a7468
a0078154:  94 14 22 a0  or  %l0, 0x2a0, %o2
a0078158:  80 a2 20 00  cmp  %o0, 0
a007815c:  12 80 00 07  bne  0xa0078178
a0078160:  90 10 20 00  clr  %o0
a0078164:  92 14 22 98  or  %l0, 0x298, %o1
a0078168:  40 00 bc 6b  call  0xa00a7314
a007816c:  90 10 00 18  mov  %i0, %o0
a0078170:  91 32 20 08  srl  %o0, 8, %o0
a0078174:  90 0a 20 ff  and  %o0, 0xff, %o0
a0078178:  25 00 00 07  sethi  %hi(0x1c00), %l2
a007817c:  d0 24 ff f0  st  %o0, [ %l3 + -16 ]
a0078180:  92 14 a2 a4  or  %l2, 0x2a4, %o1
a0078184:  40 00 bc 64  call  0xa00a7314
a0078188:  90 10 00 18  mov  %i0, %o0
a007818c:  03 00 00 3f  sethi  %hi(0xfc00), %g1
a0078190:  82 10 63 00  or  %g1, 0x300, %g1	! 0xff00
a0078194:  a0 0a 00 01  and  %o0, %g1, %l0
a0078198:  90 10 00 18  mov  %i0, %o0
a007819c:  40 00 bc 5e  call  0xa00a7314
a00781a0:  92 14 a2 a4  or  %l2, 0x2a4, %o1
a00781a4:  91 32 20 10  srl  %o0, 0x10, %o0
a00781a8:  a3 2c 60 02  sll  %l1, 2, %l1
a00781ac:  90 0a 20 ff  and  %o0, 0xff, %o0
a00781b0:  a2 04 40 14  add  %l1, %l4, %l1
a00781b4:  a0 14 00 08  or  %l0, %o0, %l0
a00781b8:  e0 24 7f e0  st  %l0, [ %l1 + -32 ]
a00781bc:  23 2a 01 e1  sethi  %hi(0xa8078400), %l1
a00781c0:  c2 04 62 34  ld  [ %l1 + 0x234 ], %g1	! 0xa8078634
a00781c4:  80 88 60 02  btst  2, %g1
a00781c8:  02 80 00 15  be  0xa007821c
a00781cc:  92 0d 60 ff  and  %l5, 0xff, %o1
a00781d0:  13 00 00 07  sethi  %hi(0x1c00), %o1
a00781d4:  92 12 62 a0  or  %o1, 0x2a0, %o1	! 0x1ea0
a00781d8:  40 00 bc 4f  call  0xa00a7314
a00781dc:  90 0d 60 ff  and  %l5, 0xff, %o0
a00781e0:  94 0d a0 ff  and  %l6, 0xff, %o2
a00781e4:  83 2a a0 02  sll  %o2, 2, %g1
a00781e8:  82 07 80 01  add  %fp, %g1, %g1
a00781ec:  92 05 60 41  add  %l5, 0x41, %o1
a00781f0:  9a 0a 20 ff  and  %o0, 0xff, %o5
a00781f4:  93 2a 60 18  sll  %o1, 0x18, %o1
a00781f8:  c2 00 7f d8  ld  [ %g1 + -40 ], %g1
a00781fc:  19 3f ff e0  sethi  %hi(0xffff8000), %o4
a0078200:  11 28 01 9d  sethi  %hi(0xa0067400), %o0
a0078204:  98 28 40 0c  andn  %g1, %o4, %o4
a0078208:  90 12 20 78  or  %o0, 0x78, %o0
a007820c:  93 3a 60 18  sra  %o1, 0x18, %o1
a0078210:  7f ff eb 8d  call  0xa0073044
a0078214:  96 10 00 0a  mov  %o2, %o3
a0078218:  92 0d 60 ff  and  %l5, 0xff, %o1
a007821c:  82 15 e1 f0  or  %l7, 0x1f0, %g1
a0078220:  98 5a 68 98  smul  %o1, 0x898, %o4
a0078224:  98 03 00 01  add  %o4, %g1, %o4
a0078228:  9a 02 40 09  add  %o1, %o1, %o5
a007822c:  9a 03 40 09  add  %o5, %o1, %o5
a0078230:  03 2a 01 f3  sethi  %hi(0xa807cc00), %g1
a0078234:  82 10 60 c4  or  %g1, 0xc4, %g1	! 0xa807ccc4
a0078238:  9b 2b 60 02  sll  %o5, 2, %o5
a007823c:  9a 03 40 01  add  %o5, %g1, %o5
a0078240:  c2 0b 60 08  ldub  [ %o5 + 8 ], %g1
a0078244:  94 0d a0 ff  and  %l6, 0xff, %o2
a0078248:  98 03 00 0a  add  %o4, %o2, %o4
a007824c:  80 a0 60 00  cmp  %g1, 0
a0078250:  02 80 00 04  be  0xa0078260
a0078254:  c2 0b 20 03  ldub  [ %o4 + 3 ], %g1
a0078258:  10 80 00 03  b  0xa0078264
a007825c:  80 a0 60 09  cmp  %g1, 9
a0078260:  80 a0 60 0d  cmp  %g1, 0xd
a0078264:  38 80 00 25  bgu,a   0xa00782f8
a0078268:  ac 05 a0 01  inc  %l6
a007826c:  96 15 e1 f0  or  %l7, 0x1f0, %o3
a0078270:  82 5a 68 98  smul  %o1, 0x898, %g1
a0078274:  82 00 40 0b  add  %g1, %o3, %g1
a0078278:  82 00 40 0a  add  %g1, %o2, %g1
a007827c:  de 08 60 03  ldub  [ %g1 + 3 ], %o7
a0078280:  e0 08 60 09  ldub  [ %g1 + 9 ], %l0
a0078284:  9a 03 c0 0f  add  %o7, %o7, %o5
a0078288:  9a 03 40 0f  add  %o5, %o7, %o5
a007828c:  82 5a 62 26  smul  %o1, 0x226, %g1
a0078290:  82 00 40 0d  add  %g1, %o5, %g1
a0078294:  9a 5c 20 2a  smul  %l0, 0x2a, %o5
a0078298:  82 00 40 0d  add  %g1, %o5, %g1
a007829c:  9b 2a a0 02  sll  %o2, 2, %o5
a00782a0:  9a 07 80 0d  add  %fp, %o5, %o5
a00782a4:  d8 03 7f d8  ld  [ %o5 + -40 ], %o4
a00782a8:  1b 3f ff e0  sethi  %hi(0xffff8000), %o5
a00782ac:  82 00 40 0a  add  %g1, %o2, %g1
a00782b0:  98 2b 00 0d  andn  %o4, %o5, %o4
a00782b4:  83 28 60 02  sll  %g1, 2, %g1
a00782b8:  da 04 62 34  ld  [ %l1 + 0x234 ], %o5
a00782bc:  82 00 40 0b  add  %g1, %o3, %g1
a00782c0:  80 8b 60 02  btst  2, %o5
a00782c4:  02 80 00 0c  be  0xa00782f4
a00782c8:  d8 20 60 80  st  %o4, [ %g1 + 0x80 ]
a00782cc:  92 05 60 41  add  %l5, 0x41, %o1
a00782d0:  93 2a 60 18  sll  %o1, 0x18, %o1
a00782d4:  d8 23 a0 5c  st  %o4, [ %sp + 0x5c ]
a00782d8:  11 28 01 9d  sethi  %hi(0xa0067400), %o0
a00782dc:  90 12 20 c0  or  %o0, 0xc0, %o0	! 0xa00674c0
a00782e0:  93 3a 60 18  sra  %o1, 0x18, %o1
a00782e4:  96 10 00 10  mov  %l0, %o3
a00782e8:  98 10 00 0f  mov  %o7, %o4
a00782ec:  7f ff eb 56  call  0xa0073044
a00782f0:  9a 10 00 0a  mov  %o2, %o5
a00782f4:  ac 05 a0 01  inc  %l6
a00782f8:  82 0d a0 ff  and  %l6, 0xff, %g1
a00782fc:  80 a0 60 02  cmp  %g1, 2
a0078300:  08 bf ff 48  bleu  0xa0078020
a0078304:  2f 2a 01 ea  sethi  %hi(0xa807a800), %l7
a0078308:  ac 10 20 00  clr  %l6
a007830c:  25 2a 01 ea  sethi  %hi(0xa807a800), %l2
a0078310:  94 0d 60 ff  and  %l5, 0xff, %o2
a0078314:  9a 14 a1 f0  or  %l2, 0x1f0, %o5
a0078318:  82 5a a8 98  smul  %o2, 0x898, %g1
a007831c:  82 00 40 0d  add  %g1, %o5, %g1
a0078320:  90 0d a0 ff  and  %l6, 0xff, %o0
a0078324:  96 00 40 08  add  %g1, %o0, %o3
a0078328:  c2 0a e0 2d  ldub  [ %o3 + 0x2d ], %g1
a007832c:  80 a0 60 01  cmp  %g1, 1
a0078330:  02 80 01 21  be  0xa00787b4
a0078334:  82 5a a2 26  smul  %o2, 0x226, %g1
a0078338:  82 00 40 08  add  %g1, %o0, %g1
a007833c:  83 28 60 02  sll  %g1, 2, %g1
a0078340:  9a 03 60 10  add  %o5, 0x10, %o5
a0078344:  d8 0a e0 2a  ldub  [ %o3 + 0x2a ], %o4
a0078348:  80 a3 20 00  cmp  %o4, 0
a007834c:  12 80 01 1a  bne  0xa00787b4
a0078350:  a0 00 40 0d  add  %g1, %o5, %l0
a0078354:  82 02 80 0a  add  %o2, %o2, %g1
a0078358:  82 00 40 0a  add  %g1, %o2, %g1
a007835c:  23 2a 01 f3  sethi  %hi(0xa807cc00), %l1
a0078360:  83 28 60 02  sll  %g1, 2, %g1
a0078364:  9a 14 60 c4  or  %l1, 0xc4, %o5
a0078368:  82 00 40 0d  add  %g1, %o5, %g1
a007836c:  c2 08 60 08  ldub  [ %g1 + 8 ], %g1
a0078370:  80 a0 60 00  cmp  %g1, 0
a0078374:  02 80 00 04  be  0xa0078384
a0078378:  c2 0a e0 03  ldub  [ %o3 + 3 ], %g1
a007837c:  10 80 00 03  b  0xa0078388
a0078380:  80 a0 60 09  cmp  %g1, 9
a0078384:  80 a0 60 0d  cmp  %g1, 0xd
a0078388:  38 80 01 0c  bgu,a   0xa00787b8
a007838c:  ac 05 a0 01  inc  %l6
a0078390:  a6 14 a1 f0  or  %l2, 0x1f0, %l3
a0078394:  96 5a a8 98  smul  %o2, 0x898, %o3
a0078398:  82 02 c0 13  add  %o3, %l3, %g1
a007839c:  9e 00 40 08  add  %g1, %o0, %o7
a00783a0:  d2 0b e0 03  ldub  [ %o7 + 3 ], %o1
a00783a4:  80 a2 60 00  cmp  %o1, 0
a00783a8:  12 80 00 0d  bne  0xa00783dc
a00783ac:  83 2a 20 02  sll  %o0, 2, %g1
a00783b0:  82 02 80 0a  add  %o2, %o2, %g1
a00783b4:  19 2a 01 e2  sethi  %hi(0xa8078800), %o4
a00783b8:  82 00 40 0a  add  %g1, %o2, %g1
a00783bc:  98 13 21 a8  or  %o4, 0x1a8, %o4
a00783c0:  1b 2a 01 e2  sethi  %hi(0xa8078800), %o5
a00783c4:  98 00 40 0c  add  %g1, %o4, %o4
a00783c8:  9a 13 61 9c  or  %o5, 0x19c, %o5
a00783cc:  82 00 40 0d  add  %g1, %o5, %g1
a00783d0:  c0 28 40 08  clrb  [ %g1 + %o0 ]
a00783d4:  c0 2b 00 08  clrb  [ %o4 + %o0 ]
a00783d8:  83 2a 20 02  sll  %o0, 2, %g1
a00783dc:  82 07 80 01  add  %fp, %g1, %g1
a00783e0:  da 00 7f d8  ld  [ %g1 + -40 ], %o5
a00783e4:  03 3f ff e0  sethi  %hi(0xffff8000), %g1
a00783e8:  82 2b 40 01  andn  %o5, %g1, %g1
a00783ec:  80 a0 60 0f  cmp  %g1, 0xf
a00783f0:  18 80 00 54  bgu  0xa0078540
a00783f4:  da 04 00 00  ld  [ %l0 ], %o5
a00783f8:  82 03 40 0d  add  %o5, %o5, %g1
a00783fc:  82 00 40 0d  add  %g1, %o5, %g1
a0078400:  82 00 40 0b  add  %g1, %o3, %g1
a0078404:  82 00 40 13  add  %g1, %l3, %g1
a0078408:  82 00 40 08  add  %g1, %o0, %g1
a007840c:  d2 28 60 1c  stb  %o1, [ %g1 + 0x1c ]
a0078410:  c2 04 00 00  ld  [ %l0 ], %g1
a0078414:  80 a0 60 01  cmp  %g1, 1
a0078418:  22 80 00 15  be,a   0xa007846c
a007841c:  82 02 80 0a  add  %o2, %o2, %g1
a0078420:  2a 80 00 09  bcs,a   0xa0078444
a0078424:  82 02 80 0a  add  %o2, %o2, %g1
a0078428:  80 a0 60 02  cmp  %g1, 2
a007842c:  02 80 00 1a  be  0xa0078494
a0078430:  80 a0 60 03  cmp  %g1, 3
a0078434:  22 80 00 23  be,a   0xa00784c0
a0078438:  82 02 80 0a  add  %o2, %o2, %g1
a007843c:  10 80 00 2c  b  0xa00784ec
a0078440:  82 14 a1 f0  or  %l2, 0x1f0, %g1
a0078444:  82 00 40 0a  add  %g1, %o2, %g1
a0078448:  9a 14 60 c4  or  %l1, 0xc4, %o5
a007844c:  83 28 60 02  sll  %g1, 2, %g1
a0078450:  82 00 40 0d  add  %g1, %o5, %g1
a0078454:  c2 08 60 08  ldub  [ %g1 + 8 ], %g1
a0078458:  80 a0 00 01  cmp  %g0, %g1
a007845c:  82 40 3f ff  addx  %g0, -1, %g1
a0078460:  82 08 60 02  and  %g1, 2, %g1
a0078464:  10 80 00 20  b  0xa00784e4
a0078468:  82 00 60 04  add  %g1, 4, %g1
a007846c:  82 00 40 0a  add  %g1, %o2, %g1
a0078470:  9a 14 60 c4  or  %l1, 0xc4, %o5
a0078474:  83 28 60 02  sll  %g1, 2, %g1
a0078478:  82 00 40 0d  add  %g1, %o5, %g1
a007847c:  c2 08 60 08  ldub  [ %g1 + 8 ], %g1
a0078480:  80 a0 00 01  cmp  %g0, %g1
a0078484:  82 40 3f ff  addx  %g0, -1, %g1
a0078488:  82 08 60 02  and  %g1, 2, %g1
a007848c:  10 80 00 16  b  0xa00784e4
a0078490:  82 00 60 05  add  %g1, 5, %g1
a0078494:  82 02 80 0a  add  %o2, %o2, %g1
a0078498:  82 00 40 0a  add  %g1, %o2, %g1
a007849c:  9a 14 60 c4  or  %l1, 0xc4, %o5
a00784a0:  83 28 60 02  sll  %g1, 2, %g1
a00784a4:  82 00 40 0d  add  %g1, %o5, %g1
a00784a8:  c2 08 60 08  ldub  [ %g1 + 8 ], %g1
a00784ac:  80 a0 00 01  cmp  %g0, %g1
a00784b0:  82 40 3f ff  addx  %g0, -1, %g1
a00784b4:  82 08 60 04  and  %g1, 4, %g1
a00784b8:  10 80 00 0b  b  0xa00784e4
a00784bc:  82 00 60 09  add  %g1, 9, %g1
a00784c0:  82 00 40 0a  add  %g1, %o2, %g1
a00784c4:  9a 14 60 c4  or  %l1, 0xc4, %o5
a00784c8:  83 28 60 02  sll  %g1, 2, %g1
a00784cc:  82 00 40 0d  add  %g1, %o5, %g1
a00784d0:  c2 08 60 08  ldub  [ %g1 + 8 ], %g1
a00784d4:  80 a0 00 01  cmp  %g0, %g1
a00784d8:  82 40 3f ff  addx  %g0, -1, %g1
a00784dc:  82 08 60 04  and  %g1, 4, %g1
a00784e0:  82 00 60 0a  add  %g1, 0xa, %g1
a00784e4:  c2 2b e0 03  stb  %g1, [ %o7 + 3 ]
a00784e8:  82 14 a1 f0  or  %l2, 0x1f0, %g1
a00784ec:  98 5a a8 98  smul  %o2, 0x898, %o4
a00784f0:  98 03 00 01  add  %o4, %g1, %o4
a00784f4:  9a 02 80 0a  add  %o2, %o2, %o5
a00784f8:  9a 03 40 0a  add  %o5, %o2, %o5
a00784fc:  03 2a 01 f3  sethi  %hi(0xa807cc00), %g1
a0078500:  82 10 60 c4  or  %g1, 0xc4, %g1	! 0xa807ccc4
a0078504:  9b 2b 60 02  sll  %o5, 2, %o5
a0078508:  9a 03 40 01  add  %o5, %g1, %o5
a007850c:  c2 0b 60 08  ldub  [ %o5 + 8 ], %g1
a0078510:  98 03 00 08  add  %o4, %o0, %o4
a0078514:  80 a0 60 00  cmp  %g1, 0
a0078518:  02 80 00 04  be  0xa0078528
a007851c:  c2 0b 20 03  ldub  [ %o4 + 3 ], %g1
a0078520:  10 80 00 03  b  0xa007852c
a0078524:  80 a0 60 09  cmp  %g1, 9
a0078528:  80 a0 60 0d  cmp  %g1, 0xd
a007852c:  38 80 00 90  bgu,a   0xa007876c
a0078530:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a0078534:  c2 04 00 00  ld  [ %l0 ], %g1
a0078538:  10 80 00 59  b  0xa007869c
a007853c:  82 00 60 01  inc  %g1
a0078540:  82 03 7f fe  add  %o5, -2, %g1
a0078544:  80 a0 60 01  cmp  %g1, 1
a0078548:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a007854c:  18 80 00 19  bgu  0xa00785b0
a0078550:  98 02 80 0a  add  %o2, %o2, %o4
a0078554:  92 03 00 0a  add  %o4, %o2, %o1
a0078558:  19 2a 01 e2  sethi  %hi(0xa8078800), %o4
a007855c:  98 13 21 a8  or  %o4, 0x1a8, %o4	! 0xa80789a8
a0078560:  98 02 40 0c  add  %o1, %o4, %o4
a0078564:  da 0b 00 08  ldub  [ %o4 + %o0 ], %o5
a0078568:  82 10 61 9c  or  %g1, 0x19c, %g1
a007856c:  9a 03 60 01  inc  %o5
a0078570:  82 02 40 01  add  %o1, %g1, %g1
a0078574:  96 0b 60 ff  and  %o5, 0xff, %o3
a0078578:  c2 08 40 08  ldub  [ %g1 + %o0 ], %g1
a007857c:  80 a2 c0 01  cmp  %o3, %g1
a0078580:  08 80 00 12  bleu  0xa00785c8
a0078584:  da 2b 00 08  stb  %o5, [ %o4 + %o0 ]
a0078588:  9a 14 60 c4  or  %l1, 0xc4, %o5
a007858c:  83 2a 60 02  sll  %o1, 2, %g1
a0078590:  82 00 40 0d  add  %g1, %o5, %g1
a0078594:  c2 08 60 08  ldub  [ %g1 + 8 ], %g1
a0078598:  80 a0 00 01  cmp  %g0, %g1
a007859c:  82 40 3f ff  addx  %g0, -1, %g1
a00785a0:  82 08 60 04  and  %g1, 4, %g1
a00785a4:  82 00 60 0a  add  %g1, 0xa, %g1
a00785a8:  10 80 00 08  b  0xa00785c8
a00785ac:  c2 2b e0 03  stb  %g1, [ %o7 + 3 ]
a00785b0:  82 10 61 9c  or  %g1, 0x19c, %g1
a00785b4:  9a 03 00 0a  add  %o4, %o2, %o5
a00785b8:  9a 03 40 01  add  %o5, %g1, %o5
a00785bc:  c2 0b 40 08  ldub  [ %o5 + %o0 ], %g1
a00785c0:  82 00 60 01  inc  %g1
a00785c4:  c2 2b 40 08  stb  %g1, [ %o5 + %o0 ]
a00785c8:  82 14 a1 f0  or  %l2, 0x1f0, %g1
a00785cc:  98 5a a8 98  smul  %o2, 0x898, %o4
a00785d0:  98 03 00 01  add  %o4, %g1, %o4
a00785d4:  9a 02 80 0a  add  %o2, %o2, %o5
a00785d8:  9a 03 40 0a  add  %o5, %o2, %o5
a00785dc:  03 2a 01 f3  sethi  %hi(0xa807cc00), %g1
a00785e0:  82 10 60 c4  or  %g1, 0xc4, %g1	! 0xa807ccc4
a00785e4:  9b 2b 60 02  sll  %o5, 2, %o5
a00785e8:  9a 03 40 01  add  %o5, %g1, %o5
a00785ec:  c2 0b 60 08  ldub  [ %o5 + 8 ], %g1
a00785f0:  98 03 00 08  add  %o4, %o0, %o4
a00785f4:  80 a0 60 00  cmp  %g1, 0
a00785f8:  c2 0b 20 03  ldub  [ %o4 + 3 ], %g1
a00785fc:  02 80 00 04  be  0xa007860c
a0078600:  1f 2a 01 f3  sethi  %hi(0xa807cc00), %o7
a0078604:  10 80 00 03  b  0xa0078610
a0078608:  80 a0 60 09  cmp  %g1, 9
a007860c:  80 a0 60 0d  cmp  %g1, 0xd
a0078610:  18 80 00 57  bgu  0xa007876c
a0078614:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a0078618:  c2 04 00 00  ld  [ %l0 ], %g1
a007861c:  80 a0 60 01  cmp  %g1, 1
a0078620:  02 80 00 21  be  0xa00786a4
a0078624:  9a 14 a1 f0  or  %l2, 0x1f0, %o5
a0078628:  0a 80 00 09  bcs  0xa007864c
a007862c:  98 5a a8 98  smul  %o2, 0x898, %o4
a0078630:  80 a0 60 02  cmp  %g1, 2
a0078634:  02 80 00 06  be  0xa007864c
a0078638:  80 a0 60 03  cmp  %g1, 3
a007863c:  02 80 00 34  be  0xa007870c
a0078640:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a0078644:  10 80 00 4b  b  0xa0078770
a0078648:  c2 00 62 34  ld  [ %g1 + 0x234 ], %g1	! 0xa8078634
a007864c:  82 02 80 0a  add  %o2, %o2, %g1
a0078650:  98 03 00 0d  add  %o4, %o5, %o4
a0078654:  82 00 40 0a  add  %g1, %o2, %g1
a0078658:  9a 13 e0 c4  or  %o7, 0xc4, %o5
a007865c:  83 28 60 02  sll  %g1, 2, %g1
a0078660:  98 03 00 08  add  %o4, %o0, %o4
a0078664:  82 00 40 0d  add  %g1, %o5, %g1
a0078668:  da 0b 20 03  ldub  [ %o4 + 3 ], %o5
a007866c:  9a 03 60 01  inc  %o5
a0078670:  c2 08 60 08  ldub  [ %g1 + 8 ], %g1
a0078674:  da 2b 20 03  stb  %o5, [ %o4 + 3 ]
a0078678:  80 a0 60 00  cmp  %g1, 0
a007867c:  02 80 00 04  be  0xa007868c
a0078680:  9a 0b 60 ff  and  %o5, 0xff, %o5
a0078684:  10 80 00 03  b  0xa0078690
a0078688:  80 a3 60 05  cmp  %o5, 5
a007868c:  80 a3 60 07  cmp  %o5, 7
a0078690:  12 80 00 37  bne  0xa007876c
a0078694:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a0078698:  82 10 20 02  mov  2, %g1
a007869c:  10 80 00 33  b  0xa0078768
a00786a0:  c2 24 00 00  st  %g1, [ %l0 ]
a00786a4:  82 5a a8 98  smul  %o2, 0x898, %g1
a00786a8:  82 00 40 0d  add  %g1, %o5, %g1
a00786ac:  96 00 40 08  add  %g1, %o0, %o3
a00786b0:  c2 0a e0 03  ldub  [ %o3 + 3 ], %g1
a00786b4:  82 00 7f ff  add  %g1, -1, %g1
a00786b8:  98 08 60 ff  and  %g1, 0xff, %o4
a00786bc:  da 0a e0 1c  ldub  [ %o3 + 0x1c ], %o5
a00786c0:  80 a3 00 0d  cmp  %o4, %o5
a00786c4:  12 80 00 29  bne  0xa0078768
a00786c8:  c2 2a e0 03  stb  %g1, [ %o3 + 3 ]
a00786cc:  82 02 80 0a  add  %o2, %o2, %g1
a00786d0:  82 00 40 0a  add  %g1, %o2, %g1
a00786d4:  9a 13 e0 c4  or  %o7, 0xc4, %o5
a00786d8:  83 28 60 02  sll  %g1, 2, %g1
a00786dc:  82 00 40 0d  add  %g1, %o5, %g1
a00786e0:  c2 08 60 08  ldub  [ %g1 + 8 ], %g1
a00786e4:  80 a0 00 01  cmp  %g0, %g1
a00786e8:  82 10 20 02  mov  2, %g1
a00786ec:  9a 40 3f ff  addx  %g0, -1, %o5
a00786f0:  c2 24 00 00  st  %g1, [ %l0 ]
a00786f4:  9a 0b 60 02  and  %o5, 2, %o5
a00786f8:  9a 03 60 05  add  %o5, 5, %o5
a00786fc:  c2 0a e0 1c  ldub  [ %o3 + 0x1c ], %g1
a0078700:  c2 2a e0 1f  stb  %g1, [ %o3 + 0x1f ]
a0078704:  10 80 00 19  b  0xa0078768
a0078708:  da 2a e0 03  stb  %o5, [ %o3 + 3 ]
a007870c:  82 5a a8 98  smul  %o2, 0x898, %g1
a0078710:  82 00 40 0d  add  %g1, %o5, %g1
a0078714:  96 00 40 08  add  %g1, %o0, %o3
a0078718:  da 0a e0 03  ldub  [ %o3 + 3 ], %o5
a007871c:  9a 03 7f ff  add  %o5, -1, %o5
a0078720:  d2 0a e0 22  ldub  [ %o3 + 0x22 ], %o1
a0078724:  98 0b 60 ff  and  %o5, 0xff, %o4
a0078728:  82 0a 60 ff  and  %o1, 0xff, %g1
a007872c:  80 a3 00 01  cmp  %o4, %g1
a0078730:  12 80 00 0e  bne  0xa0078768
a0078734:  da 2a e0 03  stb  %o5, [ %o3 + 3 ]
a0078738:  82 02 80 0a  add  %o2, %o2, %g1
a007873c:  82 00 40 0a  add  %g1, %o2, %g1
a0078740:  9a 13 e0 c4  or  %o7, 0xc4, %o5
a0078744:  83 28 60 02  sll  %g1, 2, %g1
a0078748:  82 00 40 0d  add  %g1, %o5, %g1
a007874c:  c2 08 60 08  ldub  [ %g1 + 8 ], %g1
a0078750:  80 a0 00 01  cmp  %g0, %g1
a0078754:  82 40 3f ff  addx  %g0, -1, %g1
a0078758:  82 08 60 04  and  %g1, 4, %g1
a007875c:  82 00 60 0a  add  %g1, 0xa, %g1
a0078760:  d2 2a e0 25  stb  %o1, [ %o3 + 0x25 ]
a0078764:  c2 2a e0 03  stb  %g1, [ %o3 + 3 ]
a0078768:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a007876c:  c2 00 62 34  ld  [ %g1 + 0x234 ], %g1	! 0xa8078634
a0078770:  80 88 60 02  btst  2, %g1
a0078774:  22 80 00 11  be,a   0xa00787b8
a0078778:  ac 05 a0 01  inc  %l6
a007877c:  9a 0d 60 ff  and  %l5, 0xff, %o5
a0078780:  03 2a 01 ea  sethi  %hi(0xa807a800), %g1
a0078784:  9a 5b 68 98  smul  %o5, 0x898, %o5
a0078788:  82 10 61 f0  or  %g1, 0x1f0, %g1
a007878c:  9a 03 40 01  add  %o5, %g1, %o5
a0078790:  94 0d a0 ff  and  %l6, 0xff, %o2
a0078794:  92 05 60 41  add  %l5, 0x41, %o1
a0078798:  93 2a 60 18  sll  %o1, 0x18, %o1
a007879c:  9a 03 40 0a  add  %o5, %o2, %o5
a00787a0:  11 28 01 9d  sethi  %hi(0xa0067400), %o0
a00787a4:  90 12 21 00  or  %o0, 0x100, %o0	! 0xa0067500
a00787a8:  93 3a 60 18  sra  %o1, 0x18, %o1
a00787ac:  7f ff ea 26  call  0xa0073044
a00787b0:  d6 0b 60 03  ldub  [ %o5 + 3 ], %o3
a00787b4:  ac 05 a0 01  inc  %l6
a00787b8:  82 0d a0 ff  and  %l6, 0xff, %g1
a00787bc:  80 a0 60 02  cmp  %g1, 2
a00787c0:  08 bf fe d4  bleu  0xa0078310
a00787c4:  25 2a 01 ea  sethi  %hi(0xa807a800), %l2
a00787c8:  82 0d 60 ff  and  %l5, 0xff, %g1
a00787cc:  9a 00 40 01  add  %g1, %g1, %o5
a00787d0:  9a 03 40 01  add  %o5, %g1, %o5
a00787d4:  03 2a 01 f3  sethi  %hi(0xa807cc00), %g1
a00787d8:  9b 2b 60 02  sll  %o5, 2, %o5
a00787dc:  98 10 20 07  mov  7, %o4
a00787e0:  82 10 60 c4  or  %g1, 0xc4, %g1
a00787e4:  d8 20 40 0d  st  %o4, [ %g1 + %o5 ]
a00787e8:  b0 10 20 01  mov  1, %i0
a00787ec:  81 c7 e0 08  ret
a00787f0:  81 e8 00 00  restore
