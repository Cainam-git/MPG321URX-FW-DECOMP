# leon2s DRV_HDMI21_RXDetect_FSM_LTS_Chk_Stable 0xa0099ffc-0xa009a41c (1056 bytes)
a0099ffc:  9d e3 bf 98  save  %sp, -104, %sp
a009a000:  a0 0e 20 ff  and  %i0, 0xff, %l0
a009a004:  80 a4 20 00  cmp  %l0, 0
a009a008:  02 80 00 05  be  0xa009a01c
a009a00c:  ac 10 20 02  mov  2, %l6
a009a010:  80 a4 20 01  cmp  %l0, 1
a009a014:  12 80 01 00  bne  0xa009a414
a009a018:  ac 10 20 03  mov  3, %l6
a009a01c:  2f 2a 01 f5  sethi  %hi(0xa807d400), %l7
a009a020:  9a 15 e2 80  or  %l7, 0x280, %o5	! 0xa807d680
a009a024:  82 5c 20 b0  smul  %l0, 0xb0, %g1
a009a028:  3b 2a 01 f5  sethi  %hi(0xa807d400), %i5
a009a02c:  a4 00 40 0d  add  %g1, %o5, %l2
a009a030:  a6 17 62 48  or  %i5, 0x248, %l3
a009a034:  a3 2c 20 02  sll  %l0, 2, %l1
a009a038:  da 04 c0 11  ld  [ %l3 + %l1 ], %o5
a009a03c:  c2 04 a0 30  ld  [ %l2 + 0x30 ], %g1
a009a040:  80 a3 40 01  cmp  %o5, %g1
a009a044:  02 80 00 1b  be  0xa009a0b0
a009a048:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a009a04c:  c2 00 62 34  ld  [ %g1 + 0x234 ], %g1	! 0xa8078634
a009a050:  80 88 68 00  btst  0x800, %g1
a009a054:  22 80 00 08  be,a   0xa009a074
a009a058:  c2 04 c0 11  ld  [ %l3 + %l1 ], %g1
a009a05c:  11 28 01 9e  sethi  %hi(0xa0067800), %o0
a009a060:  13 28 02 d0  sethi  %hi(0xa00b4000), %o1
a009a064:  90 12 20 68  or  %o0, 0x68, %o0
a009a068:  7f ff 63 f7  call  0xa0073044
a009a06c:  92 12 63 68  or  %o1, 0x368, %o1
a009a070:  c2 04 c0 11  ld  [ %l3 + %l1 ], %g1
a009a074:  c2 24 a0 30  st  %g1, [ %l2 + 0x30 ]
a009a078:  7f ff 7f f6  call  0xa007a050
a009a07c:  90 0d a0 03  and  %l6, 3, %o0
a009a080:  03 2a 01 f6  sethi  %hi(0xa807d800), %g1
a009a084:  82 10 63 00  or  %g1, 0x300, %g1	! 0xa807db00
a009a088:  9a 5c 20 34  smul  %l0, 0x34, %o5
a009a08c:  9a 03 40 01  add  %o5, %g1, %o5
a009a090:  d2 03 60 0c  ld  [ %o5 + 0xc ], %o1
a009a094:  92 02 60 7c  add  %o1, 0x7c, %o1
a009a098:  40 00 34 cf  call  0xa00a73d4
a009a09c:  90 10 20 0b  mov  0xb, %o0
a009a0a0:  7f ff fd 30  call  0xa0099560
a009a0a4:  90 10 00 10  mov  %l0, %o0
a009a0a8:  7f ff fd 5a  call  0xa0099610
a009a0ac:  90 10 00 10  mov  %l0, %o0
a009a0b0:  7f ff fd 73  call  0xa009967c
a009a0b4:  90 10 00 10  mov  %l0, %o0
a009a0b8:  7f ff fe d8  call  0xa0099c18
a009a0bc:  90 10 00 10  mov  %l0, %o0
a009a0c0:  23 2a 01 f6  sethi  %hi(0xa807d800), %l1
a009a0c4:  82 14 63 00  or  %l1, 0x300, %g1	! 0xa807db00
a009a0c8:  9a 5c 20 34  smul  %l0, 0x34, %o5
a009a0cc:  9a 03 40 01  add  %o5, %g1, %o5
a009a0d0:  d2 03 60 18  ld  [ %o5 + 0x18 ], %o1
a009a0d4:  92 02 60 80  add  %o1, 0x80, %o1
a009a0d8:  40 00 34 cc  call  0xa00a7408
a009a0dc:  90 10 20 04  mov  4, %o0
a009a0e0:  80 a2 20 00  cmp  %o0, 0
a009a0e4:  12 80 00 13  bne  0xa009a130
a009a0e8:  82 0d a0 ff  and  %l6, 0xff, %g1
a009a0ec:  9a 00 40 01  add  %g1, %g1, %o5
a009a0f0:  9a 03 40 01  add  %o5, %g1, %o5
a009a0f4:  03 2a 01 f3  sethi  %hi(0xa807cc00), %g1
a009a0f8:  82 10 60 64  or  %g1, 0x64, %g1	! 0xa807cc64
a009a0fc:  9b 2b 60 03  sll  %o5, 3, %o5
a009a100:  98 03 40 01  add  %o5, %g1, %o4
a009a104:  c2 0b 20 01  ldub  [ %o4 + 1 ], %g1
a009a108:  80 a0 60 01  cmp  %g1, 1
a009a10c:  02 80 00 09  be  0xa009a130
a009a110:  82 04 00 10  add  %l0, %l0, %g1
a009a114:  82 00 40 10  add  %g1, %l0, %g1
a009a118:  1b 2a 01 f5  sethi  %hi(0xa807d400), %o5
a009a11c:  83 28 60 03  sll  %g1, 3, %g1
a009a120:  9a 13 62 50  or  %o5, 0x250, %o5
a009a124:  c0 23 40 01  clr  [ %o5 + %g1 ]
a009a128:  82 10 20 01  mov  1, %g1
a009a12c:  c2 2b 20 01  stb  %g1, [ %o4 + 1 ]
a009a130:  7f ff cd b4  call  0xa008d800
a009a134:  01 00 00 00  nop
a009a138:  90 0a 20 ff  and  %o0, 0xff, %o0
a009a13c:  80 a2 20 82  cmp  %o0, 0x82
a009a140:  08 80 00 21  bleu  0xa009a1c4
a009a144:  a6 0e 20 ff  and  %i0, 0xff, %l3
a009a148:  82 5c 20 34  smul  %l0, 0x34, %g1
a009a14c:  9a 14 63 00  or  %l1, 0x300, %o5
a009a150:  a2 00 40 0d  add  %g1, %o5, %l1
a009a154:  c2 04 60 18  ld  [ %l1 + 0x18 ], %g1
a009a158:  c2 00 60 b0  ld  [ %g1 + 0xb0 ], %g1
a009a15c:  83 30 60 08  srl  %g1, 8, %g1
a009a160:  82 08 60 ff  and  %g1, 0xff, %g1
a009a164:  80 a0 60 ff  cmp  %g1, 0xff
a009a168:  02 80 00 17  be  0xa009a1c4
a009a16c:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a009a170:  c2 00 62 34  ld  [ %g1 + 0x234 ], %g1	! 0xa8078634
a009a174:  80 88 68 00  btst  0x800, %g1
a009a178:  22 80 00 06  be,a   0xa009a190
a009a17c:  d4 04 60 18  ld  [ %l1 + 0x18 ], %o2
a009a180:  11 28 01 a8  sethi  %hi(0xa006a000), %o0
a009a184:  7f ff 64 d0  call  0xa00734c4
a009a188:  90 12 21 a8  or  %o0, 0x1a8, %o0	! 0xa006a1a8
a009a18c:  d4 04 60 18  ld  [ %l1 + 0x18 ], %o2
a009a190:  03 3f ff c0  sethi  %hi(0xffff0000), %g1
a009a194:  da 02 a0 b0  ld  [ %o2 + 0xb0 ], %o5
a009a198:  82 10 60 ff  or  %g1, 0xff, %g1
a009a19c:  9a 0b 40 01  and  %o5, %g1, %o5
a009a1a0:  03 00 00 3f  sethi  %hi(0xfc00), %g1
a009a1a4:  82 10 63 00  or  %g1, 0x300, %g1	! 0xff00
a009a1a8:  9a 13 40 01  or  %o5, %g1, %o5
a009a1ac:  96 17 62 48  or  %i5, 0x248, %o3
a009a1b0:  99 2c 20 02  sll  %l0, 2, %o4
a009a1b4:  82 10 20 03  mov  3, %g1
a009a1b8:  c2 22 c0 0c  st  %g1, [ %o3 + %o4 ]
a009a1bc:  da 22 a0 b0  st  %o5, [ %o2 + 0xb0 ]
a009a1c0:  30 80 00 95  b,a   0xa009a414
a009a1c4:  03 2a 01 f6  sethi  %hi(0xa807d800), %g1
a009a1c8:  9a 5c e0 34  smul  %l3, 0x34, %o5
a009a1cc:  82 10 63 00  or  %g1, 0x300, %g1
a009a1d0:  a8 03 40 01  add  %o5, %g1, %l4
a009a1d4:  d2 05 20 18  ld  [ %l4 + 0x18 ], %o1
a009a1d8:  da 02 60 90  ld  [ %o1 + 0x90 ], %o5
a009a1dc:  25 03 c0 00  sethi  %hi(0xf000000), %l2
a009a1e0:  aa 15 e2 80  or  %l7, 0x280, %l5
a009a1e4:  a2 5c e0 b0  smul  %l3, 0xb0, %l1
a009a1e8:  9a 0b 40 12  and  %o5, %l2, %o5
a009a1ec:  a0 04 40 15  add  %l1, %l5, %l0
a009a1f0:  9b 33 60 18  srl  %o5, 0x18, %o5
a009a1f4:  c2 0c 20 02  ldub  [ %l0 + 2 ], %g1
a009a1f8:  80 a3 40 01  cmp  %o5, %g1
a009a1fc:  02 80 00 22  be  0xa009a284
a009a200:  82 0d a0 ff  and  %l6, 0xff, %g1
a009a204:  9a 00 40 01  add  %g1, %g1, %o5
a009a208:  9a 03 40 01  add  %o5, %g1, %o5
a009a20c:  03 2a 01 f3  sethi  %hi(0xa807cc00), %g1
a009a210:  82 10 60 64  or  %g1, 0x64, %g1	! 0xa807cc64
a009a214:  9b 2b 60 03  sll  %o5, 3, %o5
a009a218:  9a 03 40 01  add  %o5, %g1, %o5
a009a21c:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a009a220:  c2 00 62 34  ld  [ %g1 + 0x234 ], %g1	! 0xa8078634
a009a224:  80 88 68 00  btst  0x800, %g1
a009a228:  02 80 00 05  be  0xa009a23c
a009a22c:  c0 2b 60 01  clrb  [ %o5 + 1 ]
a009a230:  11 28 01 a8  sethi  %hi(0xa006a000), %o0
a009a234:  7f ff 64 a4  call  0xa00734c4
a009a238:  90 12 21 e8  or  %o0, 0x1e8, %o0	! 0xa006a1e8
a009a23c:  98 17 62 48  or  %i5, 0x248, %o4
a009a240:  9b 2c e0 02  sll  %l3, 2, %o5
a009a244:  82 10 20 03  mov  3, %g1
a009a248:  7f ff cd 6e  call  0xa008d800
a009a24c:  c2 23 00 0d  st  %g1, [ %o4 + %o5 ]
a009a250:  90 0a 20 ff  and  %o0, 0xff, %o0
a009a254:  80 a2 20 82  cmp  %o0, 0x82
a009a258:  08 80 00 6f  bleu  0xa009a414
a009a25c:  03 3f ff c0  sethi  %hi(0xffff0000), %g1
a009a260:  d8 05 20 18  ld  [ %l4 + 0x18 ], %o4
a009a264:  da 03 20 b0  ld  [ %o4 + 0xb0 ], %o5
a009a268:  82 10 60 ff  or  %g1, 0xff, %g1
a009a26c:  9a 0b 40 01  and  %o5, %g1, %o5
a009a270:  03 00 00 3f  sethi  %hi(0xfc00), %g1
a009a274:  82 10 63 00  or  %g1, 0x300, %g1	! 0xff00
a009a278:  9a 13 40 01  or  %o5, %g1, %o5
a009a27c:  da 23 20 b0  st  %o5, [ %o4 + 0xb0 ]
a009a280:  30 80 00 65  b,a   0xa009a414
a009a284:  92 02 60 90  add  %o1, 0x90, %o1
a009a288:  40 00 34 60  call  0xa00a7408
a009a28c:  90 10 20 11  mov  0x11, %o0
a009a290:  80 a2 20 00  cmp  %o0, 0
a009a294:  12 80 00 4b  bne  0xa009a3c0
a009a298:  82 0e 20 ff  and  %i0, 0xff, %g1
a009a29c:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a009a2a0:  c2 08 60 52  ldub  [ %g1 + 0x52 ], %g1	! 0xa8079052
a009a2a4:  80 a0 60 00  cmp  %g1, 0
a009a2a8:  12 80 00 46  bne  0xa009a3c0
a009a2ac:  82 0e 20 ff  and  %i0, 0xff, %g1
a009a2b0:  c2 0d 40 11  ldub  [ %l5 + %l1 ], %g1
a009a2b4:  80 a0 60 03  cmp  %g1, 3
a009a2b8:  12 80 00 15  bne  0xa009a30c
a009a2bc:  80 a0 60 04  cmp  %g1, 4
a009a2c0:  13 00 00 0b  sethi  %hi(0x2c00), %o1
a009a2c4:  92 12 62 60  or  %o1, 0x260, %o1	! 0x2e60
a009a2c8:  40 00 34 13  call  0xa00a7314
a009a2cc:  90 0d a0 03  and  %l6, 3, %o0
a009a2d0:  90 0a 00 12  and  %o0, %l2, %o0
a009a2d4:  91 32 20 18  srl  %o0, 0x18, %o0
a009a2d8:  80 a2 20 07  cmp  %o0, 7
a009a2dc:  02 80 00 24  be  0xa009a36c
a009a2e0:  11 28 01 a8  sethi  %hi(0xa006a000), %o0
a009a2e4:  c2 0c 20 2a  ldub  [ %l0 + 0x2a ], %g1
a009a2e8:  92 00 60 01  add  %g1, 1, %o1
a009a2ec:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a009a2f0:  c2 00 62 34  ld  [ %g1 + 0x234 ], %g1	! 0xa8078634
a009a2f4:  d2 2c 20 2a  stb  %o1, [ %l0 + 0x2a ]
a009a2f8:  80 88 68 00  btst  0x800, %g1
a009a2fc:  12 80 00 18  bne  0xa009a35c
a009a300:  90 12 22 18  or  %o0, 0x218, %o0
a009a304:  10 80 00 1c  b  0xa009a374
a009a308:  9a 15 e2 80  or  %l7, 0x280, %o5
a009a30c:  12 80 00 1a  bne  0xa009a374
a009a310:  9a 15 e2 80  or  %l7, 0x280, %o5
a009a314:  13 00 00 0b  sethi  %hi(0x2c00), %o1
a009a318:  92 12 62 60  or  %o1, 0x260, %o1	! 0x2e60
a009a31c:  40 00 33 fe  call  0xa00a7314
a009a320:  90 0d a0 03  and  %l6, 3, %o0
a009a324:  90 0a 00 12  and  %o0, %l2, %o0
a009a328:  91 32 20 18  srl  %o0, 0x18, %o0
a009a32c:  80 a2 20 0f  cmp  %o0, 0xf
a009a330:  22 80 00 10  be,a   0xa009a370
a009a334:  c0 2c 20 2a  clrb  [ %l0 + 0x2a ]
a009a338:  c2 0c 20 2a  ldub  [ %l0 + 0x2a ], %g1
a009a33c:  92 00 60 01  add  %g1, 1, %o1
a009a340:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a009a344:  c2 00 62 34  ld  [ %g1 + 0x234 ], %g1	! 0xa8078634
a009a348:  80 88 68 00  btst  0x800, %g1
a009a34c:  02 80 00 09  be  0xa009a370
a009a350:  d2 2c 20 2a  stb  %o1, [ %l0 + 0x2a ]
a009a354:  11 28 01 a8  sethi  %hi(0xa006a000), %o0
a009a358:  90 12 22 58  or  %o0, 0x258, %o0	! 0xa006a258
a009a35c:  7f ff 63 3a  call  0xa0073044
a009a360:  92 0a 60 ff  and  %o1, 0xff, %o1
a009a364:  10 80 00 04  b  0xa009a374
a009a368:  9a 15 e2 80  or  %l7, 0x280, %o5
a009a36c:  c0 2c 20 2a  clrb  [ %l0 + 0x2a ]
a009a370:  9a 15 e2 80  or  %l7, 0x280, %o5
a009a374:  82 5c e0 b0  smul  %l3, 0xb0, %g1
a009a378:  94 00 40 0d  add  %g1, %o5, %o2
a009a37c:  d6 0a a0 2a  ldub  [ %o2 + 0x2a ], %o3
a009a380:  80 a2 e0 03  cmp  %o3, 3
a009a384:  12 80 00 0f  bne  0xa009a3c0
a009a388:  82 0e 20 ff  and  %i0, 0xff, %g1
a009a38c:  82 0d a0 ff  and  %l6, 0xff, %g1
a009a390:  9a 00 40 01  add  %g1, %g1, %o5
a009a394:  9a 03 40 01  add  %o5, %g1, %o5
a009a398:  03 2a 01 f3  sethi  %hi(0xa807cc00), %g1
a009a39c:  82 10 60 64  or  %g1, 0x64, %g1	! 0xa807cc64
a009a3a0:  9b 2b 60 03  sll  %o5, 3, %o5
a009a3a4:  9a 03 40 01  add  %o5, %g1, %o5
a009a3a8:  98 17 62 48  or  %i5, 0x248, %o4
a009a3ac:  83 2c e0 02  sll  %l3, 2, %g1
a009a3b0:  d6 23 00 01  st  %o3, [ %o4 + %g1 ]
a009a3b4:  c0 2a a0 02  clrb  [ %o2 + 2 ]
a009a3b8:  c0 2b 60 01  clrb  [ %o5 + 1 ]
a009a3bc:  82 0e 20 ff  and  %i0, 0xff, %g1
a009a3c0:  1b 2a 01 f5  sethi  %hi(0xa807d400), %o5
a009a3c4:  82 58 60 b0  smul  %g1, 0xb0, %g1
a009a3c8:  9a 13 62 80  or  %o5, 0x280, %o5
a009a3cc:  b0 00 40 0d  add  %g1, %o5, %i0
a009a3d0:  c2 0e 20 01  ldub  [ %i0 + 1 ], %g1
a009a3d4:  80 a0 60 06  cmp  %g1, 6
a009a3d8:  12 80 00 0f  bne  0xa009a414
a009a3dc:  01 00 00 00  nop
a009a3e0:  da 0e 20 2c  ldub  [ %i0 + 0x2c ], %o5
a009a3e4:  82 03 60 01  add  %o5, 1, %g1
a009a3e8:  80 a3 60 c8  cmp  %o5, 0xc8
a009a3ec:  08 80 00 0a  bleu  0xa009a414
a009a3f0:  c2 2e 20 2c  stb  %g1, [ %i0 + 0x2c ]
a009a3f4:  a0 0d a0 ff  and  %l6, 0xff, %l0
a009a3f8:  90 10 00 10  mov  %l0, %o0
a009a3fc:  7f ff 7d 40  call  0xa00798fc
a009a400:  c0 2e 20 2c  clrb  [ %i0 + 0x2c ]
a009a404:  40 00 5c e4  call  0xa00b1794
a009a408:  90 10 20 01  mov  1, %o0
a009a40c:  7f ff 7d 6b  call  0xa00799b8
a009a410:  90 10 00 10  mov  %l0, %o0
a009a414:  81 c7 e0 08  ret
a009a418:  91 e8 20 00  restore  %g0, 0, %o0
