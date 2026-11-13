# leon2s H_Total 0xa009e00c-0xa009e368 (860 bytes)
a009e00c:  9d e3 bf 88  save  %sp, -120, %sp
a009e010:  a6 0e 20 ff  and  %i0, 0xff, %l3
a009e014:  7f ff e7 af  call  0xa0097ed0
a009e018:  90 10 00 13  mov  %l3, %o0
a009e01c:  b4 0e a0 ff  and  %i2, 0xff, %i2
a009e020:  d0 2e 40 00  stb  %o0, [ %i1 ]
a009e024:  80 a6 a0 01  cmp  %i2, 1
a009e028:  03 2a 01 f6  sethi  %hi(0xa807d800), %g1
a009e02c:  12 80 00 48  bne  0xa009e14c
a009e030:  a0 5c e0 34  smul  %l3, 0x34, %l0
a009e034:  92 10 63 00  or  %g1, 0x300, %o1
a009e038:  a4 04 00 09  add  %l0, %o1, %l2
a009e03c:  c2 04 a0 2c  ld  [ %l2 + 0x2c ], %g1
a009e040:  d4 00 60 0c  ld  [ %g1 + 0xc ], %o2
a009e044:  e2 00 60 10  ld  [ %g1 + 0x10 ], %l1
a009e048:  d8 00 60 0c  ld  [ %g1 + 0xc ], %o4
a009e04c:  de 00 60 0c  ld  [ %g1 + 0xc ], %o7
a009e050:  da 00 60 88  ld  [ %g1 + 0x88 ], %o5
a009e054:  d0 00 60 88  ld  [ %g1 + 0x88 ], %o0
a009e058:  d6 00 60 88  ld  [ %g1 + 0x88 ], %o3
a009e05c:  d2 02 40 10  ld  [ %o1 + %l0 ], %o1
a009e060:  e0 00 60 84  ld  [ %g1 + 0x84 ], %l0
a009e064:  c2 02 60 64  ld  [ %o1 + 0x64 ], %g1
a009e068:  99 33 20 08  srl  %o4, 8, %o4
a009e06c:  9b 33 60 10  srl  %o5, 0x10, %o5
a009e070:  d2 02 60 60  ld  [ %o1 + 0x60 ], %o1
a009e074:  95 32 a0 18  srl  %o2, 0x18, %o2
a009e078:  98 0b 20 ff  and  %o4, 0xff, %o4
a009e07c:  9f 33 e0 10  srl  %o7, 0x10, %o7
a009e080:  9a 0b 60 ff  and  %o5, 0xff, %o5
a009e084:  91 32 20 08  srl  %o0, 8, %o0
a009e088:  96 0a e0 ff  and  %o3, 0xff, %o3
a009e08c:  82 08 60 03  and  %g1, 3, %g1
a009e090:  9e 0b e0 ff  and  %o7, 0xff, %o7
a009e094:  93 32 60 18  srl  %o1, 0x18, %o1
a009e098:  90 0a 20 ff  and  %o0, 0xff, %o0
a009e09c:  95 2a a0 08  sll  %o2, 8, %o2
a009e0a0:  a2 0c 60 ff  and  %l1, 0xff, %l1
a009e0a4:  99 2b 20 08  sll  %o4, 8, %o4
a009e0a8:  9b 2b 60 08  sll  %o5, 8, %o5
a009e0ac:  97 2a e0 08  sll  %o3, 8, %o3
a009e0b0:  a1 34 20 18  srl  %l0, 0x18, %l0
a009e0b4:  83 28 60 08  sll  %g1, 8, %g1
a009e0b8:  98 03 00 0f  add  %o4, %o7, %o4
a009e0bc:  9a 03 40 08  add  %o5, %o0, %o5
a009e0c0:  82 10 40 09  or  %g1, %o1, %g1
a009e0c4:  94 02 80 11  add  %o2, %l1, %o2
a009e0c8:  96 02 c0 10  add  %o3, %l0, %o3
a009e0cc:  d4 36 60 06  sth  %o2, [ %i1 + 6 ]
a009e0d0:  d8 36 60 08  sth  %o4, [ %i1 + 8 ]
a009e0d4:  da 36 60 0c  sth  %o5, [ %i1 + 0xc ]
a009e0d8:  d6 36 60 10  sth  %o3, [ %i1 + 0x10 ]
a009e0dc:  c2 36 60 0e  sth  %g1, [ %i1 + 0xe ]
a009e0e0:  7f ff ff b2  call  0xa009dfa8
a009e0e4:  90 10 00 13  mov  %l3, %o0
a009e0e8:  c2 04 a0 2c  ld  [ %l2 + 0x2c ], %g1
a009e0ec:  da 00 60 8c  ld  [ %g1 + 0x8c ], %o5
a009e0f0:  d6 00 60 88  ld  [ %g1 + 0x88 ], %o3
a009e0f4:  c2 16 60 0c  lduh  [ %i1 + 0xc ], %g1
a009e0f8:  d8 16 60 06  lduh  [ %i1 + 6 ], %o4
a009e0fc:  98 03 00 01  add  %o4, %g1, %o4
a009e100:  c2 16 60 10  lduh  [ %i1 + 0x10 ], %g1
a009e104:  9a 0b 60 ff  and  %o5, 0xff, %o5
a009e108:  97 32 e0 18  srl  %o3, 0x18, %o3
a009e10c:  98 03 00 01  add  %o4, %g1, %o4
a009e110:  9b 2b 60 08  sll  %o5, 8, %o5
a009e114:  9a 03 40 0b  add  %o5, %o3, %o5
a009e118:  03 2a 01 f5  sethi  %hi(0xa807d400), %g1
a009e11c:  82 10 63 e0  or  %g1, 0x3e0, %g1	! 0xa807d7e0
a009e120:  96 5c e1 90  smul  %l3, 0x190, %o3
a009e124:  d0 36 60 12  sth  %o0, [ %i1 + 0x12 ]
a009e128:  98 03 00 0d  add  %o4, %o5, %o4
a009e12c:  96 02 c0 01  add  %o3, %g1, %o3
a009e130:  d8 36 60 02  sth  %o4, [ %i1 + 2 ]
a009e134:  d2 0a e0 19  ldub  [ %o3 + 0x19 ], %o1
a009e138:  7f ff f7 d9  call  0xa009c09c
a009e13c:  90 10 00 13  mov  %l3, %o0
a009e140:  d0 36 60 04  sth  %o0, [ %i1 + 4 ]
a009e144:  10 80 00 34  b  0xa009e214
a009e148:  f4 2e 60 15  stb  %i2, [ %i1 + 0x15 ]
a009e14c:  82 10 63 00  or  %g1, 0x300, %g1
a009e150:  d4 00 40 10  ld  [ %g1 + %l0 ], %o2
a009e154:  c2 02 a0 38  ld  [ %o2 + 0x38 ], %g1
a009e158:  d6 02 a0 3c  ld  [ %o2 + 0x3c ], %o3
a009e15c:  1f 2a 01 e4  sethi  %hi(0xa8079000), %o7
a009e160:  d2 02 a0 4c  ld  [ %o2 + 0x4c ], %o1
a009e164:  9e 13 e0 a8  or  %o7, 0xa8, %o7
a009e168:  da 0b c0 13  ldub  [ %o7 + %l3 ], %o5
a009e16c:  e0 02 a0 50  ld  [ %o2 + 0x50 ], %l0
a009e170:  83 30 60 10  srl  %g1, 0x10, %g1
a009e174:  d8 02 a0 5c  ld  [ %o2 + 0x5c ], %o4
a009e178:  83 28 40 0d  sll  %g1, %o5, %g1
a009e17c:  da 02 a0 58  ld  [ %o2 + 0x58 ], %o5
a009e180:  d6 36 60 04  sth  %o3, [ %i1 + 4 ]
a009e184:  c2 36 60 02  sth  %g1, [ %i1 + 2 ]
a009e188:  c2 0b c0 13  ldub  [ %o7 + %l3 ], %g1
a009e18c:  d6 02 a0 64  ld  [ %o2 + 0x64 ], %o3
a009e190:  93 32 60 10  srl  %o1, 0x10, %o1
a009e194:  98 0b 20 03  and  %o4, 3, %o4
a009e198:  d0 02 a0 60  ld  [ %o2 + 0x60 ], %o0
a009e19c:  93 2a 40 01  sll  %o1, %g1, %o1
a009e1a0:  9b 33 60 18  srl  %o5, 0x18, %o5
a009e1a4:  99 2b 20 08  sll  %o4, 8, %o4
a009e1a8:  c2 02 a0 58  ld  [ %o2 + 0x58 ], %g1
a009e1ac:  d2 36 60 06  sth  %o1, [ %i1 + 6 ]
a009e1b0:  e0 36 60 08  sth  %l0, [ %i1 + 8 ]
a009e1b4:  98 13 00 0d  or  %o4, %o5, %o4
a009e1b8:  96 0a e0 03  and  %o3, 3, %o3
a009e1bc:  d2 0b c0 13  ldub  [ %o7 + %l3 ], %o1
a009e1c0:  da 02 a0 60  ld  [ %o2 + 0x60 ], %o5
a009e1c4:  97 2a e0 08  sll  %o3, 8, %o3
a009e1c8:  91 32 20 18  srl  %o0, 0x18, %o0
a009e1cc:  99 2b 00 09  sll  %o4, %o1, %o4
a009e1d0:  d4 02 a0 60  ld  [ %o2 + 0x60 ], %o2
a009e1d4:  96 12 c0 08  or  %o3, %o0, %o3
a009e1d8:  83 30 60 08  srl  %g1, 8, %g1
a009e1dc:  d8 36 60 0c  sth  %o4, [ %i1 + 0xc ]
a009e1e0:  d6 36 60 0e  sth  %o3, [ %i1 + 0xe ]
a009e1e4:  82 08 63 ff  and  %g1, 0x3ff, %g1
a009e1e8:  9b 33 60 08  srl  %o5, 8, %o5
a009e1ec:  95 32 a0 08  srl  %o2, 8, %o2
a009e1f0:  d8 0b c0 13  ldub  [ %o7 + %l3 ], %o4
a009e1f4:  82 00 60 01  inc  %g1
a009e1f8:  9a 0b 63 00  and  %o5, 0x300, %o5
a009e1fc:  94 0a a0 ff  and  %o2, 0xff, %o2
a009e200:  83 28 40 0c  sll  %g1, %o4, %g1
a009e204:  9a 13 40 0a  or  %o5, %o2, %o5
a009e208:  c2 36 60 10  sth  %g1, [ %i1 + 0x10 ]
a009e20c:  da 36 60 12  sth  %o5, [ %i1 + 0x12 ]
a009e210:  c0 2e 60 15  clrb  [ %i1 + 0x15 ]
a009e214:  7f ff f8 6a  call  0xa009c3bc
a009e218:  90 10 00 13  mov  %l3, %o0
a009e21c:  1b 2a 01 f6  sethi  %hi(0xa807d800), %o5
a009e220:  98 5c e0 34  smul  %l3, 0x34, %o4
a009e224:  9a 13 63 00  or  %o5, 0x300, %o5
a009e228:  d0 2e 60 0a  stb  %o0, [ %i1 + 0xa ]
a009e22c:  82 03 00 0d  add  %o4, %o5, %g1
a009e230:  c2 00 60 20  ld  [ %g1 + 0x20 ], %g1
a009e234:  d6 00 60 54  ld  [ %g1 + 0x54 ], %o3
a009e238:  da 03 40 0c  ld  [ %o5 + %o4 ], %o5
a009e23c:  03 2a 01 f5  sethi  %hi(0xa807d400), %g1
a009e240:  82 10 63 e0  or  %g1, 0x3e0, %g1	! 0xa807d7e0
a009e244:  98 5c e1 90  smul  %l3, 0x190, %o4
a009e248:  98 03 00 01  add  %o4, %g1, %o4
a009e24c:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a009e250:  da 03 60 08  ld  [ %o5 + 8 ], %o5
a009e254:  82 10 60 a8  or  %g1, 0xa8, %g1
a009e258:  c2 08 40 13  ldub  [ %g1 + %l3 ], %g1
a009e25c:  9a 0b 60 c0  and  %o5, 0xc0, %o5
a009e260:  97 32 e0 02  srl  %o3, 2, %o3
a009e264:  97 2a c0 01  sll  %o3, %g1, %o3
a009e268:  9b 33 60 06  srl  %o5, 6, %o5
a009e26c:  de 0b 20 19  ldub  [ %o4 + 0x19 ], %o7
a009e270:  da 2e 60 16  stb  %o5, [ %i1 + 0x16 ]
a009e274:  de 2e 60 01  stb  %o7, [ %i1 + 1 ]
a009e278:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a009e27c:  c2 00 62 34  ld  [ %g1 + 0x234 ], %g1	! 0xa8078634
a009e280:  80 88 60 04  btst  4, %g1
a009e284:  02 80 00 12  be  0xa009e2cc
a009e288:  d6 36 60 1c  sth  %o3, [ %i1 + 0x1c ]
a009e28c:  90 0a 20 ff  and  %o0, 0xff, %o0
a009e290:  d6 16 60 08  lduh  [ %i1 + 8 ], %o3
a009e294:  92 06 20 41  add  %i0, 0x41, %o1
a009e298:  d0 23 a0 64  st  %o0, [ %sp + 0x64 ]
a009e29c:  93 2a 60 18  sll  %o1, 0x18, %o1
a009e2a0:  c2 16 60 06  lduh  [ %i1 + 6 ], %g1
a009e2a4:  d6 23 a0 60  st  %o3, [ %sp + 0x60 ]
a009e2a8:  11 28 01 aa  sethi  %hi(0xa006a800), %o0
a009e2ac:  d4 0e 40 00  ldub  [ %i1 ], %o2
a009e2b0:  d8 16 60 02  lduh  [ %i1 + 2 ], %o4
a009e2b4:  da 16 60 04  lduh  [ %i1 + 4 ], %o5
a009e2b8:  c2 23 a0 5c  st  %g1, [ %sp + 0x5c ]
a009e2bc:  90 12 23 c8  or  %o0, 0x3c8, %o0
a009e2c0:  96 0b e0 ff  and  %o7, 0xff, %o3
a009e2c4:  7f ff 53 60  call  0xa0073044
a009e2c8:  93 3a 60 18  sra  %o1, 0x18, %o1
a009e2cc:  c2 16 60 02  lduh  [ %i1 + 2 ], %g1
a009e2d0:  80 a0 60 00  cmp  %g1, 0
a009e2d4:  02 80 00 0f  be  0xa009e310
a009e2d8:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a009e2dc:  da 16 60 04  lduh  [ %i1 + 4 ], %o5
a009e2e0:  80 a3 60 00  cmp  %o5, 0
a009e2e4:  02 80 00 0c  be  0xa009e314
a009e2e8:  c2 00 62 34  ld  [ %g1 + 0x234 ], %g1
a009e2ec:  c2 16 60 06  lduh  [ %i1 + 6 ], %g1
a009e2f0:  80 a0 60 00  cmp  %g1, 0
a009e2f4:  02 80 00 07  be  0xa009e310
a009e2f8:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a009e2fc:  c2 16 60 08  lduh  [ %i1 + 8 ], %g1
a009e300:  80 a0 60 00  cmp  %g1, 0
a009e304:  12 80 00 0c  bne  0xa009e334
a009e308:  80 a3 60 01  cmp  %o5, 1
a009e30c:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a009e310:  c2 00 62 34  ld  [ %g1 + 0x234 ], %g1	! 0xa8078634
a009e314:  80 88 60 04  btst  4, %g1
a009e318:  22 80 00 12  be,a   0xa009e360
a009e31c:  b0 10 20 00  clr  %i0
a009e320:  11 28 01 ab  sethi  %hi(0xa006ac00), %o0
a009e324:  7f ff 54 68  call  0xa00734c4
a009e328:  90 12 20 50  or  %o0, 0x50, %o0	! 0xa006ac50
a009e32c:  10 80 00 0d  b  0xa009e360
a009e330:  b0 10 20 00  clr  %i0
a009e334:  02 80 00 0b  be  0xa009e360
a009e338:  b0 10 20 00  clr  %i0
a009e33c:  c2 16 60 12  lduh  [ %i1 + 0x12 ], %g1
a009e340:  80 a0 00 01  cmp  %g0, %g1
a009e344:  9a 60 3f ff  subx  %g0, -1, %o5
a009e348:  82 1e a0 01  xor  %i2, 1, %g1
a009e34c:  80 a0 00 01  cmp  %g0, %g1
a009e350:  82 60 3f ff  subx  %g0, -1, %g1
a009e354:  9a 0b 40 01  and  %o5, %g1, %o5
a009e358:  80 a0 00 0d  cmp  %g0, %o5
a009e35c:  b0 60 3f ff  subx  %g0, -1, %i0
a009e360:  81 c7 e0 08  ret
a009e364:  81 e8 00 00  restore
