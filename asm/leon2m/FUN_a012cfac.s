# leon2m FUN_a012cfac 0xa012cfac-0xa012d4f8 (1356 bytes)
a012cfac:  9d e3 bf 30  save  %sp, -208, %sp
a012cfb0:  7f ff 45 33  call  0xa00fe47c
a012cfb4:  c0 2f bf 97  clrb  [ %fp + -105 ]
a012cfb8:  b8 10 00 08  mov  %o0, %i4
a012cfbc:  11 00 06 94  sethi  %hi(0x1a5000), %o0
a012cfc0:  7f fe c8 6c  call  0xa00df170
a012cfc4:  90 12 21 c8  or  %o0, 0x1c8, %o0	! 0x1a51c8
a012cfc8:  2f 2a 00 b8  sethi  %hi(0xa802e000), %l7
a012cfcc:  82 15 e1 a0  or  %l7, 0x1a0, %g1	! 0xa802e1a0
a012cfd0:  da 08 60 37  ldub  [ %g1 + 0x37 ], %o5
a012cfd4:  80 a3 60 01  cmp  %o5, 1
a012cfd8:  08 80 00 03  bleu  0xa012cfe4
a012cfdc:  9a 10 21 20  mov  0x120, %o5
a012cfe0:  9a 10 22 40  mov  0x240, %o5
a012cfe4:  9e 15 e1 a0  or  %l7, 0x1a0, %o7
a012cfe8:  e4 03 e0 34  ld  [ %o7 + 0x34 ], %l2
a012cfec:  98 0b 63 60  and  %o5, 0x360, %o4
a012cff0:  a3 34 a0 08  srl  %l2, 8, %l1
a012cff4:  a0 03 00 11  add  %o4, %l1, %l0
a012cff8:  93 2c 20 10  sll  %l0, 0x10, %o1
a012cffc:  93 32 60 10  srl  %o1, 0x10, %o1
a012d000:  94 10 20 01  mov  1, %o2
a012d004:  96 07 bf 97  add  %fp, -105, %o3
a012d008:  d0 0b e0 34  ldub  [ %o7 + 0x34 ], %o0
a012d00c:  40 00 4c d5  call  0xa0140360
a012d010:  b6 10 00 0c  mov  %o4, %i3
a012d014:  d2 0f bf 97  ldub  [ %fp + -105 ], %o1
a012d018:  96 02 7f 89  add  %o1, -119, %o3
a012d01c:  94 0a e0 ff  and  %o3, 0xff, %o2
a012d020:  80 a2 a0 03  cmp  %o2, 3
a012d024:  08 80 01 33  bleu  0xa012d4f0
a012d028:  29 00 06 94  sethi  %hi(0x1a5000), %l4
a012d02c:  90 15 21 d8  or  %l4, 0x1d8, %o0	! 0x1a51d8
a012d030:  7f fe c8 50  call  0xa00df170
a012d034:  92 0a 60 ff  and  %o1, 0xff, %o1
a012d038:  27 2a 00 b8  sethi  %hi(0xa802e000), %l3
a012d03c:  a8 14 e1 f0  or  %l3, 0x1f0, %l4	! 0xa802e1f0
a012d040:  aa 10 20 00  clr  %l5
a012d044:  ac 10 20 00  clr  %l6
a012d048:  a2 10 20 92  mov  0x92, %l1
a012d04c:  9e 10 20 01  mov  1, %o7
a012d050:  ba 07 bf f8  add  %fp, -8, %i5
a012d054:  82 0c 40 0f  and  %l1, %o7, %g1
a012d058:  9b 28 60 10  sll  %g1, 0x10, %o5
a012d05c:  80 a3 60 00  cmp  %o5, 0
a012d060:  12 80 00 09  bne  0xa012d084
a012d064:  99 2b e0 10  sll  %o7, 0x10, %o4
a012d068:  90 03 c0 0f  add  %o7, %o7, %o0
a012d06c:  96 0a 00 11  and  %o0, %l1, %o3
a012d070:  95 2a e0 10  sll  %o3, 0x10, %o2
a012d074:  80 a2 a0 00  cmp  %o2, 0
a012d078:  02 bf ff fc  be  0xa012d068
a012d07c:  9e 10 00 08  mov  %o0, %o7
a012d080:  99 2b e0 10  sll  %o7, 0x10, %o4
a012d084:  83 33 20 10  srl  %o4, 0x10, %g1
a012d088:  80 a0 60 20  cmp  %g1, 0x20
a012d08c:  22 80 00 c0  be,a   0xa012d38c
a012d090:  e6 0d 20 0c  ldub  [ %l4 + 0xc ], %l3
a012d094:  14 80 00 b3  bg  0xa012d360
a012d098:  80 a0 60 80  cmp  %g1, 0x80
a012d09c:  80 a0 60 02  cmp  %g1, 2
a012d0a0:  02 80 00 cb  be  0xa012d3cc
a012d0a4:  80 a0 60 10  cmp  %g1, 0x10
a012d0a8:  22 80 00 cd  be,a   0xa012d3dc
a012d0ac:  e6 0d 20 09  ldub  [ %l4 + 9 ], %l3
a012d0b0:  90 10 3f ff  mov  -1, %o0
a012d0b4:  a6 10 3f ff  mov  -1, %l3
a012d0b8:  92 10 3f ff  mov  -1, %o1
a012d0bc:  a4 10 3f ff  mov  -1, %l2
a012d0c0:  96 10 3f ff  mov  -1, %o3
a012d0c4:  a0 10 3f ff  mov  -1, %l0
a012d0c8:  83 2d 60 10  sll  %l5, 0x10, %g1
a012d0cc:  9b 30 60 10  srl  %g1, 0x10, %o5
a012d0d0:  94 07 40 0d  add  %i5, %o5, %o2
a012d0d4:  98 10 20 00  clr  %o4
a012d0d8:  9a 10 20 00  clr  %o5
a012d0dc:  82 5b 60 09  smul  %o5, 9, %g1
a012d0e0:  98 03 20 01  inc  %o4
a012d0e4:  82 02 80 01  add  %o2, %g1, %g1
a012d0e8:  9a 0b 20 ff  and  %o4, 0xff, %o5
a012d0ec:  d6 28 7f da  stb  %o3, [ %g1 + -38 ]
a012d0f0:  d0 28 7f d8  stb  %o0, [ %g1 + -40 ]
a012d0f4:  80 a3 60 02  cmp  %o5, 2
a012d0f8:  08 bf ff f9  bleu  0xa012d0dc
a012d0fc:  d2 28 7f d9  stb  %o1, [ %g1 + -39 ]
a012d100:  92 2c 40 0f  andn  %l1, %o7, %o1
a012d104:  a3 2a 60 10  sll  %o1, 0x10, %l1
a012d108:  80 a4 60 00  cmp  %l1, 0
a012d10c:  aa 05 60 03  add  %l5, 3, %l5
a012d110:  12 bf ff d1  bne  0xa012d054
a012d114:  a2 10 00 09  mov  %o1, %l1
a012d118:  a8 15 e1 a0  or  %l7, 0x1a0, %l4
a012d11c:  de 0d 20 37  ldub  [ %l4 + 0x37 ], %o7
a012d120:  ea 05 20 34  ld  [ %l4 + 0x34 ], %l5
a012d124:  e6 2f bf f0  stb  %l3, [ %fp + -16 ]
a012d128:  e4 2f bf f1  stb  %l2, [ %fp + -15 ]
a012d12c:  e0 2f bf f2  stb  %l0, [ %fp + -14 ]
a012d130:  80 a3 e0 01  cmp  %o7, 1
a012d134:  99 35 60 08  srl  %l5, 8, %o4
a012d138:  08 80 00 03  bleu  0xa012d144
a012d13c:  92 10 21 20  mov  0x120, %o1
a012d140:  92 10 22 40  mov  0x240, %o1
a012d144:  94 0a 63 60  and  %o1, 0x360, %o2
a012d148:  90 02 a0 10  add  %o2, 0x10, %o0
a012d14c:  a6 03 00 08  add  %o4, %o0, %l3
a012d150:  a1 2c e0 10  sll  %l3, 0x10, %l0
a012d154:  a4 15 e1 a0  or  %l7, 0x1a0, %l2
a012d158:  d0 0c a0 34  ldub  [ %l2 + 0x34 ], %o0
a012d15c:  93 34 20 10  srl  %l0, 0x10, %o1
a012d160:  94 10 20 1b  mov  0x1b, %o2
a012d164:  96 07 bf d0  add  %fp, -48, %o3
a012d168:  40 00 4f 43  call  0xa0140e74
a012d16c:  98 10 20 00  clr  %o4
a012d170:  9e 10 20 07  mov  7, %o7
a012d174:  90 10 20 01  mov  1, %o0
a012d178:  23 00 06 93  sethi  %hi(0x1a4c00), %l1
a012d17c:  96 0b c0 08  and  %o7, %o0, %o3
a012d180:  80 8a e0 ff  btst  0xff, %o3
a012d184:  12 80 00 08  bne  0xa012d1a4
a012d188:  9a 0a 20 ff  and  %o0, 0xff, %o5
a012d18c:  98 02 00 08  add  %o0, %o0, %o4
a012d190:  9a 0b 00 0f  and  %o4, %o7, %o5
a012d194:  80 8b 60 ff  btst  0xff, %o5
a012d198:  02 bf ff fd  be  0xa012d18c
a012d19c:  90 10 00 0c  mov  %o4, %o0
a012d1a0:  9a 0a 20 ff  and  %o0, 0xff, %o5
a012d1a4:  80 a3 60 08  cmp  %o5, 8
a012d1a8:  02 80 00 10  be  0xa012d1e8
a012d1ac:  92 14 63 70  or  %l1, 0x370, %o1
a012d1b0:  80 a3 60 08  cmp  %o5, 8
a012d1b4:  14 80 00 a8  bg  0xa012d454
a012d1b8:  80 a3 60 20  cmp  %o5, 0x20
a012d1bc:  03 00 06 93  sethi  %hi(0x1a4c00), %g1
a012d1c0:  80 a3 60 02  cmp  %o5, 2
a012d1c4:  02 80 00 09  be  0xa012d1e8
a012d1c8:  92 10 63 58  or  %g1, 0x358, %o1
a012d1cc:  80 a3 60 02  cmp  %o5, 2
a012d1d0:  04 80 00 06  ble  0xa012d1e8
a012d1d4:  92 14 63 70  or  %l1, 0x370, %o1
a012d1d8:  80 a3 60 04  cmp  %o5, 4
a012d1dc:  02 80 00 83  be  0xa012d3e8
a012d1e0:  2b 00 06 93  sethi  %hi(0x1a4c00), %l5
a012d1e4:  92 14 63 70  or  %l1, 0x370, %o1
a012d1e8:  a6 0d a0 ff  and  %l6, 0xff, %l3
a012d1ec:  a5 2c e0 03  sll  %l3, 3, %l2
a012d1f0:  a0 04 80 13  add  %l2, %l3, %l0
a012d1f4:  a8 04 00 10  add  %l0, %l0, %l4
a012d1f8:  94 05 00 1d  add  %l4, %i5, %o2
a012d1fc:  96 10 20 00  clr  %o3
a012d200:  98 10 20 00  clr  %o4
a012d204:  da 0b 00 09  ldub  [ %o4 + %o1 ], %o5
a012d208:  82 02 80 0c  add  %o2, %o4, %g1
a012d20c:  96 02 e0 01  inc  %o3
a012d210:  98 0a e0 ff  and  %o3, 0xff, %o4
a012d214:  80 a3 20 11  cmp  %o4, 0x11
a012d218:  08 bf ff fb  bleu  0xa012d204
a012d21c:  da 28 7f a0  stb  %o5, [ %g1 + -96 ]
a012d220:  9e 2b c0 08  andn  %o7, %o0, %o7
a012d224:  80 8b e0 ff  btst  0xff, %o7
a012d228:  12 bf ff d5  bne  0xa012d17c
a012d22c:  ac 05 a0 01  inc  %l6
a012d230:  92 15 e1 a0  or  %l7, 0x1a0, %o1
a012d234:  fa 0a 60 37  ldub  [ %o1 + 0x37 ], %i5
a012d238:  ec 02 60 34  ld  [ %o1 + 0x34 ], %l6
a012d23c:  80 a7 60 01  cmp  %i5, 1
a012d240:  99 35 a0 08  srl  %l6, 8, %o4
a012d244:  08 80 00 03  bleu  0xa012d250
a012d248:  92 10 21 20  mov  0x120, %o1
a012d24c:  92 10 22 40  mov  0x240, %o1
a012d250:  96 0a 63 60  and  %o1, 0x360, %o3
a012d254:  94 02 e0 30  add  %o3, 0x30, %o2
a012d258:  90 03 00 0a  add  %o4, %o2, %o0
a012d25c:  9f 2a 20 10  sll  %o0, 0x10, %o7
a012d260:  a2 15 e1 a0  or  %l7, 0x1a0, %l1
a012d264:  a6 10 00 11  mov  %l1, %l3
a012d268:  d0 0c 60 34  ldub  [ %l1 + 0x34 ], %o0
a012d26c:  93 33 e0 10  srl  %o7, 0x10, %o1
a012d270:  94 10 20 36  mov  0x36, %o2
a012d274:  96 07 bf 98  add  %fp, -104, %o3
a012d278:  40 00 4e ff  call  0xa0140e74
a012d27c:  98 10 20 00  clr  %o4
a012d280:  a4 10 20 00  clr  %l2
a012d284:  a2 10 25 08  mov  0x508, %l1
a012d288:  a0 10 20 01  mov  1, %l0
a012d28c:  a8 10 00 13  mov  %l3, %l4
a012d290:  aa 0c 40 10  and  %l1, %l0, %l5
a012d294:  99 2d 60 10  sll  %l5, 0x10, %o4
a012d298:  80 a3 20 00  cmp  %o4, 0
a012d29c:  32 80 00 09  bne,a   0xa012d2c0
a012d2a0:  ec 0d 20 37  ldub  [ %l4 + 0x37 ], %l6
a012d2a4:  9a 04 00 10  add  %l0, %l0, %o5
a012d2a8:  82 0b 40 11  and  %o5, %l1, %g1
a012d2ac:  a1 28 60 10  sll  %g1, 0x10, %l0
a012d2b0:  80 a4 20 00  cmp  %l0, 0
a012d2b4:  02 bf ff fc  be  0xa012d2a4
a012d2b8:  a0 10 00 0d  mov  %o5, %l0
a012d2bc:  ec 0d 20 37  ldub  [ %l4 + 0x37 ], %l6
a012d2c0:  80 a5 a0 01  cmp  %l6, 1
a012d2c4:  18 80 00 4b  bgu  0xa012d3f0
a012d2c8:  bb 2c 20 10  sll  %l0, 0x10, %i5
a012d2cc:  83 37 60 10  srl  %i5, 0x10, %g1
a012d2d0:  80 88 62 00  btst  0x200, %g1
a012d2d4:  32 80 00 48  bne,a   0xa012d3f4
a012d2d8:  d4 04 e0 34  ld  [ %l3 + 0x34 ], %o2
a012d2dc:  80 88 60 08  btst  8, %g1
a012d2e0:  12 80 00 66  bne  0xa012d478
a012d2e4:  80 88 61 00  btst  0x100, %g1
a012d2e8:  12 80 00 71  bne  0xa012d4ac
a012d2ec:  80 88 64 00  btst  0x400, %g1
a012d2f0:  32 80 00 78  bne,a   0xa012d4d0
a012d2f4:  d4 05 20 34  ld  [ %l4 + 0x34 ], %o2
a012d2f8:  96 2c 40 10  andn  %l1, %l0, %o3
a012d2fc:  a3 2a e0 10  sll  %o3, 0x10, %l1
a012d300:  80 a4 60 00  cmp  %l1, 0
a012d304:  12 bf ff e3  bne  0xa012d290
a012d308:  a2 10 00 0b  mov  %o3, %l1
a012d30c:  98 17 20 10  or  %i4, 0x10, %o4
a012d310:  a1 2b 20 10  sll  %o4, 0x10, %l0
a012d314:  7f ff 44 4e  call  0xa00fe44c
a012d318:  91 34 20 10  srl  %l0, 0x10, %o0
a012d31c:  7f ff 77 0d  call  0xa010af50
a012d320:  b8 15 e1 a0  or  %l7, 0x1a0, %i4
a012d324:  e6 07 20 34  ld  [ %i4 + 0x34 ], %l3
a012d328:  a5 34 e0 08  srl  %l3, 8, %l2
a012d32c:  a8 04 80 1b  add  %l2, %i3, %l4
a012d330:  b6 10 20 77  mov  0x77, %i3
a012d334:  f6 2f bf 97  stb  %i3, [ %fp + -105 ]
a012d338:  af 2d 20 10  sll  %l4, 0x10, %l7
a012d33c:  d0 0f 20 34  ldub  [ %i4 + 0x34 ], %o0
a012d340:  93 35 e0 10  srl  %l7, 0x10, %o1
a012d344:  94 10 20 01  mov  1, %o2
a012d348:  96 07 bf 97  add  %fp, -105, %o3
a012d34c:  40 00 4e ca  call  0xa0140e74
a012d350:  98 10 20 00  clr  %o4
a012d354:  40 00 4c 9f  call  0xa01405d0
a012d358:  d0 0f 20 34  ldub  [ %i4 + 0x34 ], %o0
a012d35c:  30 80 00 65  b,a   0xa012d4f0
a012d360:  02 80 00 17  be  0xa012d3bc
a012d364:  80 a0 60 80  cmp  %g1, 0x80
a012d368:  14 80 00 0f  bg  0xa012d3a4
a012d36c:  80 a0 61 00  cmp  %g1, 0x100
a012d370:  80 a0 60 40  cmp  %g1, 0x40
a012d374:  32 bf ff 50  bne,a   0xa012d0b4
a012d378:  90 10 3f ff  mov  -1, %o0
a012d37c:  e6 0d 20 0f  ldub  [ %l4 + 0xf ], %l3
a012d380:  e4 0d 20 10  ldub  [ %l4 + 0x10 ], %l2
a012d384:  10 80 00 04  b  0xa012d394
a012d388:  e0 0d 20 11  ldub  [ %l4 + 0x11 ], %l0
a012d38c:  e4 0d 20 0d  ldub  [ %l4 + 0xd ], %l2
a012d390:  e0 0d 20 0e  ldub  [ %l4 + 0xe ], %l0
a012d394:  90 10 00 13  mov  %l3, %o0
a012d398:  92 10 00 12  mov  %l2, %o1
a012d39c:  10 bf ff 4b  b  0xa012d0c8
a012d3a0:  96 10 00 10  mov  %l0, %o3
a012d3a4:  32 bf ff 44  bne,a   0xa012d0b4
a012d3a8:  90 10 3f ff  mov  -1, %o0
a012d3ac:  e6 0d 20 15  ldub  [ %l4 + 0x15 ], %l3
a012d3b0:  e4 0d 20 16  ldub  [ %l4 + 0x16 ], %l2
a012d3b4:  10 bf ff f8  b  0xa012d394
a012d3b8:  e0 0d 20 17  ldub  [ %l4 + 0x17 ], %l0
a012d3bc:  e6 0d 20 12  ldub  [ %l4 + 0x12 ], %l3
a012d3c0:  e4 0d 20 13  ldub  [ %l4 + 0x13 ], %l2
a012d3c4:  10 bf ff f4  b  0xa012d394
a012d3c8:  e0 0d 20 14  ldub  [ %l4 + 0x14 ], %l0
a012d3cc:  e6 0d 20 06  ldub  [ %l4 + 6 ], %l3
a012d3d0:  e4 0d 20 07  ldub  [ %l4 + 7 ], %l2
a012d3d4:  10 bf ff f0  b  0xa012d394
a012d3d8:  e0 0d 20 08  ldub  [ %l4 + 8 ], %l0
a012d3dc:  e4 0d 20 0a  ldub  [ %l4 + 0xa ], %l2
a012d3e0:  10 bf ff ed  b  0xa012d394
a012d3e4:  e0 0d 20 0b  ldub  [ %l4 + 0xb ], %l0
a012d3e8:  10 bf ff 80  b  0xa012d1e8
a012d3ec:  92 15 63 40  or  %l5, 0x340, %o1
a012d3f0:  d4 04 e0 34  ld  [ %l3 + 0x34 ], %o2
a012d3f4:  91 32 a0 08  srl  %o2, 8, %o0
a012d3f8:  92 02 00 12  add  %o0, %l2, %o1
a012d3fc:  9f 2a 60 10  sll  %o1, 0x10, %o7
a012d400:  1b 00 06 93  sethi  %hi(0x1a4c00), %o5
a012d404:  93 33 e0 10  srl  %o7, 0x10, %o1
a012d408:  96 13 63 e8  or  %o5, 0x3e8, %o3
a012d40c:  d0 0c e0 34  ldub  [ %l3 + 0x34 ], %o0
a012d410:  94 10 20 60  mov  0x60, %o2
a012d414:  40 00 4e 98  call  0xa0140e74
a012d418:  98 10 20 00  clr  %o4
a012d41c:  fa 04 e0 34  ld  [ %l3 + 0x34 ], %i5
a012d420:  83 37 60 08  srl  %i5, 8, %g1
a012d424:  ac 04 a0 60  add  %l2, 0x60, %l6
a012d428:  aa 05 80 01  add  %l6, %g1, %l5
a012d42c:  99 2d 60 10  sll  %l5, 0x10, %o4
a012d430:  93 33 20 10  srl  %o4, 0x10, %o1
a012d434:  17 00 06 93  sethi  %hi(0x1a4c00), %o3
a012d438:  96 12 e3 88  or  %o3, 0x388, %o3	! 0x1a4f88
a012d43c:  d0 0c e0 34  ldub  [ %l3 + 0x34 ], %o0
a012d440:  94 10 20 60  mov  0x60, %o2
a012d444:  40 00 4e 8c  call  0xa0140e74
a012d448:  98 10 20 00  clr  %o4
a012d44c:  10 bf ff ab  b  0xa012d2f8
a012d450:  a4 04 a0 c0  add  %l2, 0xc0, %l2
a012d454:  02 bf ff 65  be  0xa012d1e8
a012d458:  92 14 63 70  or  %l1, 0x370, %o1
a012d45c:  80 a3 60 20  cmp  %o5, 0x20
a012d460:  04 bf ff 63  ble  0xa012d1ec
a012d464:  a6 0d a0 ff  and  %l6, 0xff, %l3
a012d468:  80 a3 60 40  cmp  %o5, 0x40
a012d46c:  12 bf ff 61  bne  0xa012d1f0
a012d470:  a5 2c e0 03  sll  %l3, 3, %l2
a012d474:  30 bf ff 5f  b,a   0xa012d1f0
a012d478:  d6 05 20 34  ld  [ %l4 + 0x34 ], %o3
a012d47c:  95 32 e0 08  srl  %o3, 8, %o2
a012d480:  90 02 80 12  add  %o2, %l2, %o0
a012d484:  93 2a 20 10  sll  %o0, 0x10, %o1
a012d488:  1f 00 06 94  sethi  %hi(0x1a5000), %o7
a012d48c:  d0 0d 20 34  ldub  [ %l4 + 0x34 ], %o0
a012d490:  93 32 60 10  srl  %o1, 0x10, %o1
a012d494:  96 13 e1 08  or  %o7, 0x108, %o3
a012d498:  94 10 20 60  mov  0x60, %o2
a012d49c:  40 00 4e 76  call  0xa0140e74
a012d4a0:  98 10 20 00  clr  %o4
a012d4a4:  10 bf ff 95  b  0xa012d2f8
a012d4a8:  a4 04 a0 60  add  %l2, 0x60, %l2
a012d4ac:  fa 05 20 34  ld  [ %l4 + 0x34 ], %i5
a012d4b0:  ad 37 60 08  srl  %i5, 8, %l6
a012d4b4:  82 05 80 12  add  %l6, %l2, %g1
a012d4b8:  ab 28 60 10  sll  %g1, 0x10, %l5
a012d4bc:  19 00 06 94  sethi  %hi(0x1a5000), %o4
a012d4c0:  d0 0d 20 34  ldub  [ %l4 + 0x34 ], %o0
a012d4c4:  93 35 60 10  srl  %l5, 0x10, %o1
a012d4c8:  10 bf ff f4  b  0xa012d498
a012d4cc:  96 13 20 a8  or  %o4, 0xa8, %o3
a012d4d0:  91 32 a0 08  srl  %o2, 8, %o0
a012d4d4:  92 02 00 12  add  %o0, %l2, %o1
a012d4d8:  9f 2a 60 10  sll  %o1, 0x10, %o7
a012d4dc:  1b 00 06 94  sethi  %hi(0x1a5000), %o5
a012d4e0:  93 33 e0 10  srl  %o7, 0x10, %o1
a012d4e4:  96 13 60 48  or  %o5, 0x48, %o3
a012d4e8:  10 bf ff ec  b  0xa012d498
a012d4ec:  d0 0d 20 34  ldub  [ %l4 + 0x34 ], %o0
a012d4f0:  81 c7 e0 08  ret
a012d4f4:  81 e8 00 00  restore
