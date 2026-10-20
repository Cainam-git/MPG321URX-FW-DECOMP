# leon2m FUN_a00b0034 0xa00b0034-0xa00b05d8 (184 bytes)
a00b0034:  9d e3 bf 98  save  %sp, -104, %sp
a00b0038:  67 ff 78 9b  call  0x4008e2a4
a00b003c:  b2 10 20 05  mov  5, %i1
a00b0040:  a0 10 20 05  mov  5, %l0
a00b0044:  94 10 00 10  mov  %l0, %o2
a00b0048:  90 10 20 00  clr  %o0
a00b004c:  92 10 20 13  mov  0x13, %o1
a00b0050:  96 10 20 13  mov  0x13, %o3
a00b0054:  98 10 20 00  clr  %o4
a00b0058:  40 02 5a b2  call  0xa0146b20
a00b005c:  9a 10 20 00  clr  %o5
a00b0060:  92 10 00 10  mov  %l0, %o1
a00b0064:  90 10 20 13  mov  0x13, %o0
a00b0068:  94 10 20 13  mov  0x13, %o2
a00b006c:  96 10 27 92  mov  0x792, %o3
a00b0070:  98 10 20 00  clr  %o4
a00b0074:  40 02 5a 83  call  0xa0146a80
a00b0078:  b2 06 60 01  inc  %i1
a00b007c:  a0 0e 60 ff  and  %i1, 0xff, %l0
a00b0080:  80 a4 20 14  cmp  %l0, 0x14
a00b0084:  08 bf ff f1  bleu  0xa00b0048
a00b0088:  94 10 00 10  mov  %l0, %o2
a00b008c:  96 10 20 02  mov  2, %o3
a00b0090:  98 10 20 00  clr  %o4
a00b0094:  9a 10 20 00  clr  %o5
a00b0098:  90 10 20 00  clr  %o0
a00b009c:  92 10 20 1c  mov  0x1c, %o1
a00b00a0:  40 02 5a a0  call  0xa0146b20
a00b00a4:  94 10 20 15  mov  0x15, %o2
a00b00a8:  90 10 20 05  mov  5, %o0
a00b00ac:  92 10 20 00  clr  %o1
a00b00b0:  40 02 5a e4  call  0xa0146c40
a00b00b4:  94 10 20 00  clr  %o2
a00b00b8:  7f ff e2 f4  call  0xa00a8c88
a00b00bc:  01 00 00 00  nop
a00b00c0:  82 0e 20 ff  and  %i0, 0xff, %g1
a00b00c4:  80 a0 60 08  cmp  %g1, 8
a00b00c8:  18 80 01 42  bgu  0xa00b05d0
a00b00cc:  11 00 01 10  sethi  %hi(0x44000), %o0
a00b00d0:  83 28 60 02  sll  %g1, 2, %g1
a00b00d4:  9a 12 21 fc  or  %o0, 0x1fc, %o5
a00b00d8:  d8 03 40 01  ld  [ %o5 + %g1 ], %o4
a00b00dc:  81 c3 00 00  jmp  %o4
a00b00e0:  01 00 00 00  nop
a00b00e4:  7f ff e9 d6  call  0xa00aa83c
a00b00e8:  90 10 20 00  clr  %o0	! 0x0
a00b00ec:  90 10 20 00  clr  %o0
a00b00f0:  7f ff e3 c7  call  0xa00a900c
a00b00f4:  92 10 20 00  clr  %o1
a00b00f8:  b0 10 20 34  mov  0x34, %i0
a00b00fc:  b2 10 20 00  clr  %i1
a00b0100:  7f ff fc d3  call  0xa00af44c
a00b0104:  81 e8 00 00  restore
a00b0108:  7f ff f4 2e  call  0xa00ad1c0
a00b010c:  90 10 20 00  clr  %o0
a00b0110:  90 10 20 00  clr  %o0
a00b0114:  7f ff e3 be  call  0xa00a900c
a00b0118:  92 10 20 00  clr  %o1
a00b011c:  b0 10 20 2a  mov  0x2a, %i0
a00b0120:  10 bf ff f8  b  0xa00b0100
a00b0124:  b2 10 20 00  clr  %i1
a00b0128:  90 10 20 92  mov  0x92, %o0
a00b012c:  40 02 5a 89  call  0xa0146b50
a00b0130:  92 10 20 00  clr  %o1
a00b0134:  90 10 20 00  clr  %o0
a00b0138:  40 02 5a 8d  call  0xa0146b6c
a00b013c:  92 10 20 00  clr  %o1
a00b0140:  b2 10 20 00  clr  %i1
a00b0144:  23 2a 00 b4  sethi  %hi(0xa802d000), %l1
a00b0148:  a0 10 20 00  clr  %l0
a00b014c:  31 00 06 45  sethi  %hi(0x191400), %i0
a00b0150:  a5 2c 20 03  sll  %l0, 3, %l2
a00b0154:  9e 24 80 10  sub  %l2, %l0, %o7
a00b0158:  93 2b e0 02  sll  %o7, 2, %o1
a00b015c:  96 14 62 90  or  %l1, 0x290, %o3
a00b0160:  90 02 40 10  add  %o1, %l0, %o0
a00b0164:  d4 0a e0 08  ldub  [ %o3 + 8 ], %o2
a00b0168:  9a 02 00 0a  add  %o0, %o2, %o5
a00b016c:  99 2b 60 10  sll  %o5, 0x10, %o4
a00b0170:  93 33 20 10  srl  %o4, 0x10, %o1
a00b0174:  7f ff cd b4  call  0xa00a3844
a00b0178:  90 16 21 8c  or  %i0, 0x18c, %o0
a00b017c:  82 04 00 10  add  %l0, %l0, %g1
a00b0180:  98 10 00 08  mov  %o0, %o4
a00b0184:  94 00 60 06  add  %g1, 6, %o2
a00b0188:  90 10 20 00  clr  %o0
a00b018c:  92 10 20 14  mov  0x14, %o1
a00b0190:  96 10 20 01  mov  1, %o3
a00b0194:  9a 10 20 00  clr  %o5
a00b0198:  7f ff cc 03  call  0xa00a31a4
a00b019c:  b2 06 60 01  inc  %i1
a00b01a0:  a0 0e 60 ff  and  %i1, 0xff, %l0
a00b01a4:  80 a4 20 04  cmp  %l0, 4
a00b01a8:  0a bf ff eb  bcs  0xa00b0154
a00b01ac:  a5 2c 20 03  sll  %l0, 3, %l2
a00b01b0:  90 10 20 00  clr  %o0
a00b01b4:  7f ff e3 96  call  0xa00a900c
a00b01b8:  92 10 20 00  clr  %o1
a00b01bc:  b0 10 20 26  mov  0x26, %i0
a00b01c0:  10 bf ff d0  b  0xa00b0100
a00b01c4:  b2 10 20 00  clr  %i1
a00b01c8:  40 00 0e ae  call  0xa00b3c80
a00b01cc:  23 2a 00 b4  sethi  %hi(0xa802d000), %l1
a00b01d0:  a0 14 62 90  or  %l1, 0x290, %l0	! 0xa802d290
a00b01d4:  92 10 20 00  clr  %o1
a00b01d8:  7f ff e3 8d  call  0xa00a900c
a00b01dc:  d0 0c 20 1f  ldub  [ %l0 + 0x1f ], %o0
a00b01e0:  da 0c 20 1f  ldub  [ %l0 + 0x1f ], %o5
a00b01e4:  92 03 40 0d  add  %o5, %o5, %o1
a00b01e8:  80 a3 60 06  cmp  %o5, 6
a00b01ec:  08 80 00 04  bleu  0xa00b01fc
a00b01f0:  82 02 60 06  add  %o1, 6, %g1
a00b01f4:  96 03 40 0d  add  %o5, %o5, %o3
a00b01f8:  82 02 ff f8  add  %o3, -8, %g1
a00b01fc:  a4 08 60 ff  and  %g1, 0xff, %l2
a00b0200:  90 10 20 00  clr  %o0
a00b0204:  92 10 20 14  mov  0x14, %o1
a00b0208:  94 10 00 12  mov  %l2, %o2
a00b020c:  96 10 20 01  mov  1, %o3
a00b0210:  98 10 20 3a  mov  0x3a, %o4
a00b0214:  40 02 5a 43  call  0xa0146b20
a00b0218:  9a 10 20 00  clr  %o5
a00b021c:  94 10 00 12  mov  %l2, %o2
a00b0220:  90 10 20 00  clr  %o0
a00b0224:  92 10 20 15  mov  0x15, %o1
a00b0228:  96 10 20 01  mov  1, %o3
a00b022c:  98 10 20 3b  mov  0x3b, %o4
a00b0230:  40 02 5a 3c  call  0xa0146b20
a00b0234:  9a 10 20 00  clr  %o5
a00b0238:  9e 14 62 90  or  %l1, 0x290, %o7
a00b023c:  f2 0b e0 1f  ldub  [ %o7 + 0x1f ], %i1
a00b0240:  7f ff fc 83  call  0xa00af44c
a00b0244:  91 e8 20 23  restore  %g0, 0x23, %o0
a00b0248:  40 00 0e 56  call  0xa00b3ba0
a00b024c:  33 2a 00 b4  sethi  %hi(0xa802d000), %i1
a00b0250:  40 02 50 eb  call  0xa01445fc
a00b0254:  d0 0e 62 ae  ldub  [ %i1 + 0x2ae ], %o0	! 0xa802d2ae
a00b0258:  b0 0a 20 ff  and  %o0, 0xff, %i0
a00b025c:  7f ff e3 6c  call  0xa00a900c
a00b0260:  93 e8 20 00  restore  %g0, 0, %o1
a00b0264:  90 10 20 92  mov  0x92, %o0
a00b0268:  40 02 5a 3a  call  0xa0146b50
a00b026c:  92 10 20 00  clr  %o1
a00b0270:  90 10 20 00  clr  %o0
a00b0274:  40 02 5a 3e  call  0xa0146b6c
a00b0278:  92 10 20 00  clr  %o1
a00b027c:  b0 10 20 00  clr  %i0
a00b0280:  25 2a 00 b4  sethi  %hi(0xa802d000), %l2
a00b0284:  a0 10 20 00  clr  %l0
a00b0288:  10 80 00 1b  b  0xa00b02f4
a00b028c:  23 00 06 32  sethi  %hi(0x18c800), %l1
a00b0290:  95 2c 20 03  sll  %l0, 3, %o2
a00b0294:  90 22 80 10  sub  %o2, %l0, %o0
a00b0298:  9b 2a 20 02  sll  %o0, 2, %o5
a00b029c:  98 03 40 10  add  %o5, %l0, %o4
a00b02a0:  82 14 a2 90  or  %l2, 0x290, %g1
a00b02a4:  e0 08 60 08  ldub  [ %g1 + 8 ], %l0
a00b02a8:  9e 03 00 10  add  %o4, %l0, %o7
a00b02ac:  97 2b e0 10  sll  %o7, 0x10, %o3
a00b02b0:  93 32 e0 10  srl  %o3, 0x10, %o1
a00b02b4:  7f ff cd 64  call  0xa00a3844
a00b02b8:  90 14 62 88  or  %l1, 0x288, %o0
a00b02bc:  92 06 60 06  add  %i1, 6, %o1
a00b02c0:  98 10 00 08  mov  %o0, %o4
a00b02c4:  b3 2a 60 10  sll  %o1, 0x10, %i1
a00b02c8:  95 36 60 10  srl  %i1, 0x10, %o2
a00b02cc:  90 10 20 00  clr  %o0
a00b02d0:  92 10 20 14  mov  0x14, %o1
a00b02d4:  96 10 20 01  mov  1, %o3
a00b02d8:  9a 10 20 00  clr  %o5
a00b02dc:  7f ff cb b2  call  0xa00a31a4
a00b02e0:  b0 06 20 01  inc  %i0
a00b02e4:  a0 0e 20 ff  and  %i0, 0xff, %l0
a00b02e8:  80 a4 20 05  cmp  %l0, 5
a00b02ec:  18 80 00 a6  bgu  0xa00b0584
a00b02f0:  01 00 00 00  nop
a00b02f4:  7f ff e8 8b  call  0xa00aa520
a00b02f8:  90 10 00 10  mov  %l0, %o0
a00b02fc:  80 8a 20 ff  btst  0xff, %o0
a00b0300:  12 bf ff e4  bne  0xa00b0290
a00b0304:  b2 04 00 10  add  %l0, %l0, %i1
a00b0308:  90 10 20 14  mov  0x14, %o0
a00b030c:  92 06 60 06  add  %i1, 6, %o1
a00b0310:  94 10 20 0d  mov  0xd, %o2
a00b0314:  96 10 22 92  mov  0x292, %o3
a00b0318:  40 02 59 da  call  0xa0146a80
a00b031c:  98 10 20 00  clr  %o4
a00b0320:  10 bf ff dd  b  0xa00b0294
a00b0324:  95 2c 20 03  sll  %l0, 3, %o2
a00b0328:  90 10 20 00  clr  %o0
a00b032c:  7f ff f3 40  call  0xa00ad02c
a00b0330:  92 10 20 00  clr  %o1
a00b0334:  90 10 20 00  clr  %o0
a00b0338:  7f ff e3 35  call  0xa00a900c
a00b033c:  92 10 20 00  clr  %o1
a00b0340:  b0 10 20 0e  mov  0xe, %i0
a00b0344:  10 bf ff 6f  b  0xa00b0100
a00b0348:  b2 10 20 00  clr  %i1
a00b034c:  67 ff 77 d6  call  0x4008e2a4
a00b0350:  b2 10 20 05  mov  5, %i1
a00b0354:  a0 10 20 05  mov  5, %l0
a00b0358:  94 10 00 10  mov  %l0, %o2
a00b035c:  90 10 20 00  clr  %o0
a00b0360:  92 10 20 13  mov  0x13, %o1
a00b0364:  96 10 20 13  mov  0x13, %o3
a00b0368:  98 10 20 00  clr  %o4
a00b036c:  40 02 59 ed  call  0xa0146b20
a00b0370:  9a 10 20 00  clr  %o5
a00b0374:  92 10 00 10  mov  %l0, %o1
a00b0378:  90 10 20 13  mov  0x13, %o0
a00b037c:  94 10 20 13  mov  0x13, %o2
a00b0380:  96 10 27 92  mov  0x792, %o3
a00b0384:  98 10 20 00  clr  %o4
a00b0388:  40 02 59 be  call  0xa0146a80
a00b038c:  b2 06 60 01  inc  %i1
a00b0390:  a0 0e 60 ff  and  %i1, 0xff, %l0
a00b0394:  80 a4 20 14  cmp  %l0, 0x14
a00b0398:  08 bf ff f1  bleu  0xa00b035c
a00b039c:  94 10 00 10  mov  %l0, %o2
a00b03a0:  96 10 20 02  mov  2, %o3
a00b03a4:  98 10 20 00  clr  %o4
a00b03a8:  9a 10 20 00  clr  %o5
a00b03ac:  90 10 20 00  clr  %o0
a00b03b0:  92 10 20 1c  mov  0x1c, %o1
a00b03b4:  40 02 59 db  call  0xa0146b20
a00b03b8:  94 10 20 15  mov  0x15, %o2
a00b03bc:  94 10 20 00  clr  %o2
a00b03c0:  90 10 20 05  mov  5, %o0
a00b03c4:  40 02 5a 1f  call  0xa0146c40
a00b03c8:  92 10 20 00  clr  %o1
a00b03cc:  90 10 20 92  mov  0x92, %o0
a00b03d0:  40 02 59 e0  call  0xa0146b50
a00b03d4:  92 10 20 00  clr  %o1
a00b03d8:  90 10 20 00  clr  %o0
a00b03dc:  40 02 59 e4  call  0xa0146b6c
a00b03e0:  92 10 20 00  clr  %o1
a00b03e4:  b0 10 20 00  clr  %i0
a00b03e8:  a0 10 20 00  clr  %l0
a00b03ec:  25 2a 00 b4  sethi  %hi(0xa802d000), %l2
a00b03f0:  10 80 00 1b  b  0xa00b045c
a00b03f4:  23 00 06 28  sethi  %hi(0x18a000), %l1
a00b03f8:  95 2c 20 03  sll  %l0, 3, %o2
a00b03fc:  90 22 80 10  sub  %o2, %l0, %o0
a00b0400:  9b 2a 20 02  sll  %o0, 2, %o5
a00b0404:  98 03 40 10  add  %o5, %l0, %o4
a00b0408:  82 14 a2 90  or  %l2, 0x290, %g1
a00b040c:  e0 08 60 08  ldub  [ %g1 + 8 ], %l0
a00b0410:  9e 03 00 10  add  %o4, %l0, %o7
a00b0414:  97 2b e0 10  sll  %o7, 0x10, %o3
a00b0418:  93 32 e0 10  srl  %o3, 0x10, %o1
a00b041c:  7f ff cd 0a  call  0xa00a3844
a00b0420:  90 14 63 60  or  %l1, 0x360, %o0
a00b0424:  92 06 60 06  add  %i1, 6, %o1
a00b0428:  98 10 00 08  mov  %o0, %o4
a00b042c:  95 2a 60 10  sll  %o1, 0x10, %o2
a00b0430:  95 32 a0 10  srl  %o2, 0x10, %o2
a00b0434:  90 10 20 00  clr  %o0
a00b0438:  92 10 20 14  mov  0x14, %o1
a00b043c:  96 10 20 01  mov  1, %o3
a00b0440:  9a 10 20 00  clr  %o5
a00b0444:  7f ff cb 58  call  0xa00a31a4
a00b0448:  b0 06 20 01  inc  %i0
a00b044c:  a0 0e 20 ff  and  %i0, 0xff, %l0
a00b0450:  80 a4 20 02  cmp  %l0, 2
a00b0454:  18 80 00 47  bgu  0xa00b0570
a00b0458:  90 10 20 00  clr  %o0
a00b045c:  7f ff e8 31  call  0xa00aa520
a00b0460:  90 10 00 10  mov  %l0, %o0
a00b0464:  80 8a 20 ff  btst  0xff, %o0
a00b0468:  12 bf ff e4  bne  0xa00b03f8
a00b046c:  b2 04 00 10  add  %l0, %l0, %i1
a00b0470:  90 10 20 14  mov  0x14, %o0
a00b0474:  92 06 60 06  add  %i1, 6, %o1
a00b0478:  94 10 20 0d  mov  0xd, %o2
a00b047c:  96 10 22 92  mov  0x292, %o3
a00b0480:  40 02 59 80  call  0xa0146a80
a00b0484:  98 10 20 00  clr  %o4
a00b0488:  10 bf ff dd  b  0xa00b03fc
a00b048c:  95 2c 20 03  sll  %l0, 3, %o2
a00b0490:  90 10 20 92  mov  0x92, %o0
a00b0494:  40 02 59 af  call  0xa0146b50
a00b0498:  92 10 20 00  clr  %o1
a00b049c:  90 10 20 00  clr  %o0
a00b04a0:  40 02 59 b3  call  0xa0146b6c
a00b04a4:  92 10 20 00  clr  %o1
a00b04a8:  b0 10 20 00  clr  %i0
a00b04ac:  25 2a 00 b4  sethi  %hi(0xa802d000), %l2
a00b04b0:  a0 10 20 00  clr  %l0
a00b04b4:  10 80 00 1b  b  0xa00b0520
a00b04b8:  23 00 06 21  sethi  %hi(0x188400), %l1
a00b04bc:  95 2c 20 03  sll  %l0, 3, %o2
a00b04c0:  90 22 80 10  sub  %o2, %l0, %o0
a00b04c4:  9b 2a 20 02  sll  %o0, 2, %o5
a00b04c8:  98 03 40 10  add  %o5, %l0, %o4
a00b04cc:  82 14 a2 90  or  %l2, 0x290, %g1
a00b04d0:  e0 08 60 08  ldub  [ %g1 + 8 ], %l0
a00b04d4:  9e 03 00 10  add  %o4, %l0, %o7
a00b04d8:  97 2b e0 10  sll  %o7, 0x10, %o3
a00b04dc:  93 32 e0 10  srl  %o3, 0x10, %o1
a00b04e0:  7f ff cc d9  call  0xa00a3844
a00b04e4:  90 14 62 34  or  %l1, 0x234, %o0
a00b04e8:  92 06 60 06  add  %i1, 6, %o1
a00b04ec:  98 10 00 08  mov  %o0, %o4
a00b04f0:  b3 2a 60 10  sll  %o1, 0x10, %i1
a00b04f4:  95 36 60 10  srl  %i1, 0x10, %o2
a00b04f8:  90 10 20 00  clr  %o0
a00b04fc:  92 10 20 14  mov  0x14, %o1
a00b0500:  96 10 20 01  mov  1, %o3
a00b0504:  9a 10 20 00  clr  %o5
a00b0508:  7f ff cb 27  call  0xa00a31a4
a00b050c:  b0 06 20 01  inc  %i0
a00b0510:  a0 0e 20 ff  and  %i0, 0xff, %l0
a00b0514:  80 a4 20 02  cmp  %l0, 2
a00b0518:  18 80 00 0f  bgu  0xa00b0554
a00b051c:  01 00 00 00  nop
a00b0520:  7f ff e8 00  call  0xa00aa520
a00b0524:  90 10 00 10  mov  %l0, %o0
a00b0528:  80 8a 20 ff  btst  0xff, %o0
a00b052c:  12 bf ff e4  bne  0xa00b04bc
a00b0530:  b2 04 00 10  add  %l0, %l0, %i1
a00b0534:  90 10 20 14  mov  0x14, %o0
a00b0538:  92 06 60 06  add  %i1, 6, %o1
a00b053c:  94 10 20 0f  mov  0xf, %o2
a00b0540:  96 10 22 92  mov  0x292, %o3
a00b0544:  40 02 59 4f  call  0xa0146a80
a00b0548:  98 10 20 00  clr  %o4
a00b054c:  10 bf ff dd  b  0xa00b04c0
a00b0550:  95 2c 20 03  sll  %l0, 3, %o2
a00b0554:  40 00 1a 01  call  0xa00b6d58
a00b0558:  b0 10 20 15  mov  0x15, %i0
a00b055c:  90 10 20 00  clr  %o0
a00b0560:  7f ff e2 ab  call  0xa00a900c
a00b0564:  92 10 20 00  clr  %o1
a00b0568:  10 bf fe e6  b  0xa00b0100
a00b056c:  b2 10 20 00  clr  %i1
a00b0570:  7f ff e2 a7  call  0xa00a900c
a00b0574:  92 10 20 00  clr  %o1
a00b0578:  b0 10 20 0b  mov  0xb, %i0
a00b057c:  10 bf fe e1  b  0xa00b0100
a00b0580:  b2 10 20 00  clr  %i1
a00b0584:  7f ff e7 e7  call  0xa00aa520
a00b0588:  90 10 20 00  clr  %o0
a00b058c:  80 8a 20 ff  btst  0xff, %o0
a00b0590:  02 80 00 08  be  0xa00b05b0
a00b0594:  82 10 20 00  clr  %g1
a00b0598:  b2 08 60 ff  and  %g1, 0xff, %i1
a00b059c:  90 10 00 19  mov  %i1, %o0
a00b05a0:  7f ff e2 9b  call  0xa00a900c
a00b05a4:  92 10 20 00  clr  %o1
a00b05a8:  7f ff fb a9  call  0xa00af44c
a00b05ac:  91 e8 20 18  restore  %g0, 0x18, %o0
a00b05b0:  7f ff e7 dc  call  0xa00aa520
a00b05b4:  90 10 20 01  mov  1, %o0
a00b05b8:  b0 0a 20 ff  and  %o0, 0xff, %i0
a00b05bc:  a4 1e 20 01  xor  %i0, 1, %l2
a00b05c0:  80 a0 00 12  cmp  %g0, %l2
a00b05c4:  a2 40 20 00  addx  %g0, 0, %l1
a00b05c8:  10 bf ff f4  b  0xa00b0598
a00b05cc:  82 04 60 01  add  %l1, 1, %g1
a00b05d0:  81 c7 e0 08  ret
a00b05d4:  81 e8 00 00  restore
