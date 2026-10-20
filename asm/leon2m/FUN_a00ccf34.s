# leon2m FUN_a00ccf34 0xa00ccf34-0xa00ce348 (168 bytes)
a00ccf34:  9d e3 bf 98  save  %sp, -104, %sp
a00ccf38:  b2 0e 60 ff  and  %i1, 0xff, %i1
a00ccf3c:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00ccf40:  11 00 06 60  sethi  %hi(0x198000), %o0
a00ccf44:  90 12 22 e0  or  %o0, 0x2e0, %o0	! 0x1982e0
a00ccf48:  92 10 00 19  mov  %i1, %o1
a00ccf4c:  40 00 48 89  call  0xa00df170
a00ccf50:  94 10 00 18  mov  %i0, %o2
a00ccf54:  80 a6 60 99  cmp  %i1, 0x99
a00ccf58:  18 80 00 3c  bgu  0xa00cd048
a00ccf5c:  90 10 20 00  clr  %o0
a00ccf60:  13 00 01 69  sethi  %hi(0x5a400), %o1
a00ccf64:  83 2e 60 02  sll  %i1, 2, %g1
a00ccf68:  9a 12 62 54  or  %o1, 0x254, %o5
a00ccf6c:  d8 03 40 01  ld  [ %o5 + %g1 ], %o4
a00ccf70:  81 c3 00 00  jmp  %o4
a00ccf74:  01 00 00 00  nop
a00ccf78:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00ccf7c:  80 a6 20 02  cmp  %i0, 2
a00ccf80:  02 80 00 08  be  0xa00ccfa0
a00ccf84:  82 12 a0 40  or  %o2, 0x40, %g1
a00ccf88:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a00ccf8c:  80 a6 20 03  cmp  %i0, 3
a00ccf90:  02 80 00 04  be  0xa00ccfa0
a00ccf94:  82 13 e0 98  or  %o7, 0x98, %g1
a00ccf98:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a00ccf9c:  82 13 60 d0  or  %o5, 0xd0, %g1	! 0xa802d0d0
a00ccfa0:  d2 08 60 07  ldub  [ %g1 + 7 ], %o1
a00ccfa4:  94 02 7f d0  add  %o1, -48, %o2
a00ccfa8:  90 0a a0 ff  and  %o2, 0xff, %o0
a00ccfac:  d6 08 60 09  ldub  [ %g1 + 9 ], %o3
a00ccfb0:  d8 08 60 08  ldub  [ %g1 + 8 ], %o4
a00ccfb4:  80 a2 20 01  cmp  %o0, 1
a00ccfb8:  18 80 00 16  bgu  0xa00cd010
a00ccfbc:  9a 10 20 ff  mov  0xff, %o5
a00ccfc0:  98 03 3f d0  add  %o4, -48, %o4
a00ccfc4:  82 0b 20 ff  and  %o4, 0xff, %g1
a00ccfc8:  80 a0 60 09  cmp  %g1, 9
a00ccfcc:  18 80 00 12  bgu  0xa00cd014
a00ccfd0:  80 a3 60 0b  cmp  %o5, 0xb
a00ccfd4:  96 02 ff d0  add  %o3, -48, %o3
a00ccfd8:  9e 0a e0 ff  and  %o3, 0xff, %o7
a00ccfdc:  80 a3 e0 09  cmp  %o7, 9
a00ccfe0:  18 80 00 0d  bgu  0xa00cd014
a00ccfe4:  80 a3 60 0b  cmp  %o5, 0xb
a00ccfe8:  98 0b 20 ff  and  %o4, 0xff, %o4
a00ccfec:  9f 2b 20 02  sll  %o4, 2, %o7
a00ccff0:  92 03 c0 0c  add  %o7, %o4, %o1
a00ccff4:  82 0a a0 ff  and  %o2, 0xff, %g1
a00ccff8:  9a 02 40 09  add  %o1, %o1, %o5
a00ccffc:  90 58 60 64  smul  %g1, 0x64, %o0
a00cd000:  94 02 00 0d  add  %o0, %o5, %o2
a00cd004:  98 0a e0 ff  and  %o3, 0xff, %o4
a00cd008:  96 02 80 0c  add  %o2, %o4, %o3
a00cd00c:  9a 0a e0 ff  and  %o3, 0xff, %o5
a00cd010:  80 a3 60 0b  cmp  %o5, 0xb
a00cd014:  18 80 00 0d  bgu  0xa00cd048
a00cd018:  90 10 20 ff  mov  0xff, %o0
a00cd01c:  17 2a 00 b5  sethi  %hi(0xa802d400), %o3
a00cd020:  7f ff ae 2b  call  0xa00b88cc
a00cd024:  da 2a e0 1a  stb  %o5, [ %o3 + 0x1a ]	! 0xa802d41a
a00cd028:  7f ff b6 91  call  0xa00baa6c
a00cd02c:  90 10 00 18  mov  %i0, %o0
a00cd030:  7f ff b6 48  call  0xa00ba950
a00cd034:  90 10 00 18  mov  %i0, %o0
a00cd038:  90 10 00 18  mov  %i0, %o0
a00cd03c:  7f ff b6 d1  call  0xa00bab80
a00cd040:  92 10 20 06  mov  6, %o1
a00cd044:  90 10 20 00  clr  %o0
a00cd048:  80 a6 60 8c  cmp  %i1, 0x8c
a00cd04c:  02 80 04 bd  be  0xa00ce340
a00cd050:  b0 0a 20 ff  and  %o0, 0xff, %i0
a00cd054:  80 a6 20 00  cmp  %i0, 0
a00cd058:  12 80 04 ba  bne  0xa00ce340
a00cd05c:  01 00 00 00  nop
a00cd060:  7f ff 0f db  call  0xa0090fcc
a00cd064:  01 00 00 00  nop
a00cd068:  9f 2a 20 10  sll  %o0, 0x10, %o7
a00cd06c:  b3 33 e0 10  srl  %o7, 0x10, %i1
a00cd070:  80 a6 61 06  cmp  %i1, 0x106
a00cd074:  02 80 04 b3  be  0xa00ce340
a00cd078:  01 00 00 00  nop
a00cd07c:  7f ff 0f d4  call  0xa0090fcc
a00cd080:  01 00 00 00  nop
a00cd084:  99 2a 20 10  sll  %o0, 0x10, %o4
a00cd088:  91 33 20 10  srl  %o4, 0x10, %o0
a00cd08c:  80 a2 21 09  cmp  %o0, 0x109
a00cd090:  02 80 04 ac  be  0xa00ce340
a00cd094:  01 00 00 00  nop
a00cd098:  7f ff 0f d0  call  0xa0090fd8
a00cd09c:  01 00 00 00  nop
a00cd0a0:  30 80 04 a8  b,a   0xa00ce340
a00cd0a4:  10 bf ff e9  b  0xa00cd048
a00cd0a8:  90 10 20 00  clr  %o0
a00cd0ac:  7f ff cf 4d  call  0xa00c0de0
a00cd0b0:  90 10 00 18  mov  %i0, %o0
a00cd0b4:  10 bf ff e6  b  0xa00cd04c
a00cd0b8:  80 a6 60 8c  cmp  %i1, 0x8c
a00cd0bc:  10 bf ff e3  b  0xa00cd048
a00cd0c0:  90 10 20 00  clr  %o0
a00cd0c4:  7f ff d2 02  call  0xa00c18cc
a00cd0c8:  90 10 00 18  mov  %i0, %o0
a00cd0cc:  10 bf ff e0  b  0xa00cd04c
a00cd0d0:  80 a6 60 8c  cmp  %i1, 0x8c
a00cd0d4:  7f ff d5 36  call  0xa00c25ac
a00cd0d8:  90 10 00 18  mov  %i0, %o0
a00cd0dc:  10 bf ff dc  b  0xa00cd04c
a00cd0e0:  80 a6 60 8c  cmp  %i1, 0x8c
a00cd0e4:  7f ff ee d5  call  0xa00c8c38
a00cd0e8:  90 10 00 18  mov  %i0, %o0
a00cd0ec:  10 bf ff d8  b  0xa00cd04c
a00cd0f0:  80 a6 60 8c  cmp  %i1, 0x8c
a00cd0f4:  7f ff fc 13  call  0xa00cc140
a00cd0f8:  90 10 00 18  mov  %i0, %o0
a00cd0fc:  10 bf ff d4  b  0xa00cd04c
a00cd100:  80 a6 60 8c  cmp  %i1, 0x8c
a00cd104:  7f ff fb 66  call  0xa00cbe9c
a00cd108:  90 10 00 18  mov  %i0, %o0
a00cd10c:  10 bf ff d0  b  0xa00cd04c
a00cd110:  80 a6 60 8c  cmp  %i1, 0x8c
a00cd114:  7f ff eb 4a  call  0xa00c7e3c
a00cd118:  90 10 00 18  mov  %i0, %o0
a00cd11c:  10 bf ff cc  b  0xa00cd04c
a00cd120:  80 a6 60 8c  cmp  %i1, 0x8c
a00cd124:  7f ff de 25  call  0xa00c49b8
a00cd128:  90 10 00 18  mov  %i0, %o0
a00cd12c:  10 bf ff c8  b  0xa00cd04c
a00cd130:  80 a6 60 8c  cmp  %i1, 0x8c
a00cd134:  7f ff e5 e9  call  0xa00c68d8
a00cd138:  90 10 00 18  mov  %i0, %o0
a00cd13c:  10 bf ff c4  b  0xa00cd04c
a00cd140:  80 a6 60 8c  cmp  %i1, 0x8c
a00cd144:  7f ff f4 05  call  0xa00ca158
a00cd148:  90 10 00 18  mov  %i0, %o0
a00cd14c:  10 bf ff c0  b  0xa00cd04c
a00cd150:  80 a6 60 8c  cmp  %i1, 0x8c
a00cd154:  7f ff f3 7c  call  0xa00c9f44
a00cd158:  90 10 00 18  mov  %i0, %o0
a00cd15c:  10 bf ff bc  b  0xa00cd04c
a00cd160:  80 a6 60 8c  cmp  %i1, 0x8c
a00cd164:  80 a6 20 02  cmp  %i0, 2
a00cd168:  02 80 04 2f  be  0xa00ce224
a00cd16c:  80 a6 20 03  cmp  %i0, 3
a00cd170:  02 80 04 39  be  0xa00ce254
a00cd174:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00cd178:  c2 0a e0 d9  ldub  [ %o3 + 0xd9 ], %g1	! 0xa802d0d9
a00cd17c:  9e 08 60 ff  and  %g1, 0xff, %o7
a00cd180:  92 03 ff d0  add  %o7, -48, %o1
a00cd184:  82 0a 60 ff  and  %o1, 0xff, %g1
a00cd188:  80 a0 60 01  cmp  %g1, 1
a00cd18c:  18 bf ff af  bgu  0xa00cd048
a00cd190:  90 10 20 ff  mov  0xff, %o0
a00cd194:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00cd198:  90 13 22 90  or  %o4, 0x290, %o0	! 0xa802d290
a00cd19c:  d6 02 21 74  ld  [ %o0 + 0x174 ], %o3
a00cd1a0:  92 08 60 01  and  %g1, 1, %o1
a00cd1a4:  1f 00 00 20  sethi  %hi(0x8000), %o7
a00cd1a8:  9b 2a 60 0f  sll  %o1, 0xf, %o5
a00cd1ac:  94 2a c0 0f  andn  %o3, %o7, %o2
a00cd1b0:  82 12 80 0d  or  %o2, %o5, %g1
a00cd1b4:  40 00 39 37  call  0xa00db690
a00cd1b8:  c2 22 21 74  st  %g1, [ %o0 + 0x174 ]
a00cd1bc:  7f ff ad c4  call  0xa00b88cc
a00cd1c0:  01 00 00 00  nop
a00cd1c4:  7f ff b6 2a  call  0xa00baa6c
a00cd1c8:  90 10 00 18  mov  %i0, %o0
a00cd1cc:  7f ff b5 e1  call  0xa00ba950
a00cd1d0:  90 10 00 18  mov  %i0, %o0
a00cd1d4:  90 10 00 18  mov  %i0, %o0
a00cd1d8:  7f ff b6 6a  call  0xa00bab80
a00cd1dc:  92 10 20 06  mov  6, %o1
a00cd1e0:  10 bf ff 9a  b  0xa00cd048
a00cd1e4:  90 10 20 00  clr  %o0
a00cd1e8:  80 a6 20 02  cmp  %i0, 2
a00cd1ec:  02 80 04 11  be  0xa00ce230
a00cd1f0:  80 a6 20 03  cmp  %i0, 3
a00cd1f4:  02 80 04 12  be  0xa00ce23c
a00cd1f8:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00cd1fc:  c2 0a e0 d9  ldub  [ %o3 + 0xd9 ], %g1	! 0xa802d0d9
a00cd200:  9e 08 60 ff  and  %g1, 0xff, %o7
a00cd204:  98 03 ff d0  add  %o7, -48, %o4
a00cd208:  92 0b 20 ff  and  %o4, 0xff, %o1
a00cd20c:  80 a2 60 01  cmp  %o1, 1
a00cd210:  18 bf ff 8e  bgu  0xa00cd048
a00cd214:  90 10 20 ff  mov  0xff, %o0
a00cd218:  11 2a 00 b5  sethi  %hi(0xa802d400), %o0
a00cd21c:  7f ff ad ac  call  0xa00b88cc
a00cd220:  d8 2a 20 7e  stb  %o4, [ %o0 + 0x7e ]	! 0xa802d47e
a00cd224:  7f ff b6 12  call  0xa00baa6c
a00cd228:  90 10 00 18  mov  %i0, %o0
a00cd22c:  7f ff b5 c9  call  0xa00ba950
a00cd230:  90 10 00 18  mov  %i0, %o0
a00cd234:  90 10 00 18  mov  %i0, %o0
a00cd238:  7f ff b6 52  call  0xa00bab80
a00cd23c:  92 10 20 06  mov  6, %o1
a00cd240:  10 bf ff 82  b  0xa00cd048
a00cd244:  90 10 20 00  clr  %o0
a00cd248:  7f ff f9 6b  call  0xa00cb7f4
a00cd24c:  90 10 00 18  mov  %i0, %o0
a00cd250:  10 bf ff 7f  b  0xa00cd04c
a00cd254:  80 a6 60 8c  cmp  %i1, 0x8c
a00cd258:  7f ff f9 df  call  0xa00cb9d4
a00cd25c:  90 10 00 18  mov  %i0, %o0
a00cd260:  10 bf ff 7b  b  0xa00cd04c
a00cd264:  80 a6 60 8c  cmp  %i1, 0x8c
a00cd268:  7f ff f8 74  call  0xa00cb438
a00cd26c:  90 10 00 18  mov  %i0, %o0
a00cd270:  10 bf ff 77  b  0xa00cd04c
a00cd274:  80 a6 60 8c  cmp  %i1, 0x8c
a00cd278:  7f ff f8 e8  call  0xa00cb618
a00cd27c:  90 10 00 18  mov  %i0, %o0
a00cd280:  10 bf ff 73  b  0xa00cd04c
a00cd284:  80 a6 60 8c  cmp  %i1, 0x8c
a00cd288:  7f ff f7 d0  call  0xa00cb1c8
a00cd28c:  90 10 00 18  mov  %i0, %o0
a00cd290:  10 bf ff 6f  b  0xa00cd04c
a00cd294:  80 a6 60 8c  cmp  %i1, 0x8c
a00cd298:  80 a6 20 02  cmp  %i0, 2
a00cd29c:  02 80 03 df  be  0xa00ce218
a00cd2a0:  80 a6 20 03  cmp  %i0, 3
a00cd2a4:  02 80 03 e9  be  0xa00ce248
a00cd2a8:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00cd2ac:  c2 0a a0 d9  ldub  [ %o2 + 0xd9 ], %g1	! 0xa802d0d9
a00cd2b0:  96 08 60 ff  and  %g1, 0xff, %o3
a00cd2b4:  98 02 ff d0  add  %o3, -48, %o4
a00cd2b8:  82 0b 20 ff  and  %o4, 0xff, %g1
a00cd2bc:  80 a0 60 01  cmp  %g1, 1
a00cd2c0:  18 bf ff 62  bgu  0xa00cd048
a00cd2c4:  90 10 20 ff  mov  0xff, %o0
a00cd2c8:  13 2a 00 b5  sethi  %hi(0xa802d400), %o1
a00cd2cc:  40 00 36 4d  call  0xa00dac00
a00cd2d0:  d8 2a 60 78  stb  %o4, [ %o1 + 0x78 ]	! 0xa802d478
a00cd2d4:  7f ff ad 7e  call  0xa00b88cc
a00cd2d8:  01 00 00 00  nop
a00cd2dc:  7f ff b5 e4  call  0xa00baa6c
a00cd2e0:  90 10 00 18  mov  %i0, %o0
a00cd2e4:  7f ff b5 9b  call  0xa00ba950
a00cd2e8:  90 10 00 18  mov  %i0, %o0
a00cd2ec:  90 10 00 18  mov  %i0, %o0
a00cd2f0:  7f ff b6 24  call  0xa00bab80
a00cd2f4:  92 10 20 06  mov  6, %o1
a00cd2f8:  10 bf ff 54  b  0xa00cd048
a00cd2fc:  90 10 20 00  clr  %o0
a00cd300:  7f ff f1 a0  call  0xa00c9980
a00cd304:  90 10 00 18  mov  %i0, %o0
a00cd308:  10 bf ff 51  b  0xa00cd04c
a00cd30c:  80 a6 60 8c  cmp  %i1, 0x8c
a00cd310:  7f ff fa 28  call  0xa00cbbb0
a00cd314:  90 10 00 18  mov  %i0, %o0
a00cd318:  10 bf ff 4d  b  0xa00cd04c
a00cd31c:  80 a6 60 8c  cmp  %i1, 0x8c
a00cd320:  7f ff f6 fb  call  0xa00caf0c
a00cd324:  90 10 00 18  mov  %i0, %o0
a00cd328:  10 bf ff 49  b  0xa00cd04c
a00cd32c:  80 a6 60 8c  cmp  %i1, 0x8c
a00cd330:  7f ff f6 32  call  0xa00cabf8
a00cd334:  90 10 00 18  mov  %i0, %o0
a00cd338:  10 bf ff 45  b  0xa00cd04c
a00cd33c:  80 a6 60 8c  cmp  %i1, 0x8c
a00cd340:  80 a6 20 02  cmp  %i0, 2
a00cd344:  02 80 03 b2  be  0xa00ce20c
a00cd348:  80 a6 20 03  cmp  %i0, 3
a00cd34c:  02 80 03 cc  be  0xa00ce27c
a00cd350:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00cd354:  c2 0a 60 d9  ldub  [ %o1 + 0xd9 ], %g1	! 0xa802d0d9
a00cd358:  90 08 60 ff  and  %g1, 0xff, %o0
a00cd35c:  98 02 3f d0  add  %o0, -48, %o4
a00cd360:  9e 0b 20 ff  and  %o4, 0xff, %o7
a00cd364:  80 a3 e0 01  cmp  %o7, 1
a00cd368:  18 bf ff 38  bgu  0xa00cd048
a00cd36c:  90 10 20 ff  mov  0xff, %o0
a00cd370:  1b 2a 00 b5  sethi  %hi(0xa802d400), %o5
a00cd374:  40 00 35 eb  call  0xa00dab20
a00cd378:  d8 2b 60 71  stb  %o4, [ %o5 + 0x71 ]	! 0xa802d471
a00cd37c:  7f ff ad 54  call  0xa00b88cc
a00cd380:  01 00 00 00  nop
a00cd384:  7f ff b5 ba  call  0xa00baa6c
a00cd388:  90 10 00 18  mov  %i0, %o0
a00cd38c:  7f ff b5 71  call  0xa00ba950
a00cd390:  90 10 00 18  mov  %i0, %o0
a00cd394:  90 10 00 18  mov  %i0, %o0
a00cd398:  7f ff b5 fa  call  0xa00bab80
a00cd39c:  92 10 20 06  mov  6, %o1
a00cd3a0:  10 bf ff 2a  b  0xa00cd048
a00cd3a4:  90 10 20 00  clr  %o0
a00cd3a8:  80 a6 20 02  cmp  %i0, 2
a00cd3ac:  02 80 03 8f  be  0xa00ce1e8
a00cd3b0:  80 a6 20 03  cmp  %i0, 3
a00cd3b4:  02 80 03 ab  be  0xa00ce260
a00cd3b8:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a00cd3bc:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00cd3c0:  c2 0a 20 d9  ldub  [ %o0 + 0xd9 ], %g1	! 0xa802d0d9
a00cd3c4:  94 08 60 ff  and  %g1, 0xff, %o2
a00cd3c8:  98 02 bf d0  add  %o2, -48, %o4
a00cd3cc:  9a 0b 20 ff  and  %o4, 0xff, %o5
a00cd3d0:  80 a3 60 01  cmp  %o5, 1
a00cd3d4:  18 bf ff 1d  bgu  0xa00cd048
a00cd3d8:  90 10 20 ff  mov  0xff, %o0
a00cd3dc:  03 2a 00 b5  sethi  %hi(0xa802d400), %g1
a00cd3e0:  40 00 35 d0  call  0xa00dab20
a00cd3e4:  d8 28 60 70  stb  %o4, [ %g1 + 0x70 ]	! 0xa802d470
a00cd3e8:  7f ff ad 39  call  0xa00b88cc
a00cd3ec:  01 00 00 00  nop
a00cd3f0:  7f ff b5 9f  call  0xa00baa6c
a00cd3f4:  90 10 00 18  mov  %i0, %o0
a00cd3f8:  7f ff b5 56  call  0xa00ba950
a00cd3fc:  90 10 00 18  mov  %i0, %o0
a00cd400:  90 10 00 18  mov  %i0, %o0
a00cd404:  7f ff b5 df  call  0xa00bab80
a00cd408:  92 10 20 06  mov  6, %o1
a00cd40c:  10 bf ff 0f  b  0xa00cd048
a00cd410:  90 10 20 00  clr  %o0
a00cd414:  80 a6 20 02  cmp  %i0, 2
a00cd418:  02 80 03 68  be  0xa00ce1b8
a00cd41c:  80 a6 20 03  cmp  %i0, 3
a00cd420:  02 80 03 b7  be  0xa00ce2fc
a00cd424:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00cd428:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00cd42c:  c2 0a 20 d9  ldub  [ %o0 + 0xd9 ], %g1	! 0xa802d0d9
a00cd430:  94 08 60 ff  and  %g1, 0xff, %o2
a00cd434:  82 02 bf d0  add  %o2, -48, %g1
a00cd438:  82 08 60 ff  and  %g1, 0xff, %g1
a00cd43c:  80 a0 60 01  cmp  %g1, 1
a00cd440:  18 bf ff 02  bgu  0xa00cd048
a00cd444:  90 10 20 ff  mov  0xff, %o0
a00cd448:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00cd44c:  92 13 22 90  or  %o4, 0x290, %o1	! 0xa802d290
a00cd450:  94 08 60 01  and  %g1, 1, %o2
a00cd454:  d6 02 61 dc  ld  [ %o1 + 0x1dc ], %o3
a00cd458:  03 00 00 20  sethi  %hi(0x8000), %g1
a00cd45c:  90 2a c0 01  andn  %o3, %g1, %o0
a00cd460:  9b 2a a0 0f  sll  %o2, 0xf, %o5
a00cd464:  9e 12 00 0d  or  %o0, %o5, %o7
a00cd468:  de 22 61 dc  st  %o7, [ %o1 + 0x1dc ]
a00cd46c:  40 00 35 ad  call  0xa00dab20
a00cd470:  01 00 00 00  nop
a00cd474:  7f ff ad 16  call  0xa00b88cc
a00cd478:  01 00 00 00  nop
a00cd47c:  7f ff b5 7c  call  0xa00baa6c
a00cd480:  90 10 00 18  mov  %i0, %o0
a00cd484:  7f ff b5 33  call  0xa00ba950
a00cd488:  90 10 00 18  mov  %i0, %o0
a00cd48c:  90 10 00 18  mov  %i0, %o0
a00cd490:  7f ff b5 bc  call  0xa00bab80
a00cd494:  92 10 20 06  mov  6, %o1
a00cd498:  10 bf fe ec  b  0xa00cd048
a00cd49c:  90 10 20 00  clr  %o0
a00cd4a0:  7f ff f3 dc  call  0xa00ca410
a00cd4a4:  90 10 00 18  mov  %i0, %o0
a00cd4a8:  10 bf fe e9  b  0xa00cd04c
a00cd4ac:  80 a6 60 8c  cmp  %i1, 0x8c
a00cd4b0:  80 a6 20 02  cmp  %i0, 2
a00cd4b4:  02 80 03 3e  be  0xa00ce1ac
a00cd4b8:  80 a6 20 03  cmp  %i0, 3
a00cd4bc:  02 80 03 8e  be  0xa00ce2f4
a00cd4c0:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00cd4c4:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00cd4c8:  c2 08 60 d9  ldub  [ %g1 + 0xd9 ], %g1	! 0xa802d0d9
a00cd4cc:  96 08 60 ff  and  %g1, 0xff, %o3
a00cd4d0:  98 02 ff d0  add  %o3, -48, %o4
a00cd4d4:  94 0b 20 ff  and  %o4, 0xff, %o2
a00cd4d8:  80 a2 a0 02  cmp  %o2, 2
a00cd4dc:  18 bf fe db  bgu  0xa00cd048
a00cd4e0:  90 10 20 ff  mov  0xff, %o0
a00cd4e4:  13 2a 00 b5  sethi  %hi(0xa802d400), %o1
a00cd4e8:  7f ff ac f9  call  0xa00b88cc
a00cd4ec:  d8 2a 60 0c  stb  %o4, [ %o1 + 0xc ]	! 0xa802d40c
a00cd4f0:  7f ff b5 5f  call  0xa00baa6c
a00cd4f4:  90 10 00 18  mov  %i0, %o0
a00cd4f8:  7f ff b5 16  call  0xa00ba950
a00cd4fc:  90 10 00 18  mov  %i0, %o0
a00cd500:  90 10 00 18  mov  %i0, %o0
a00cd504:  7f ff b5 9f  call  0xa00bab80
a00cd508:  92 10 20 06  mov  6, %o1
a00cd50c:  10 bf fe cf  b  0xa00cd048
a00cd510:  90 10 20 00  clr  %o0
a00cd514:  7f ff f0 9d  call  0xa00c9788
a00cd518:  90 10 00 18  mov  %i0, %o0
a00cd51c:  10 bf fe cc  b  0xa00cd04c
a00cd520:  80 a6 60 8c  cmp  %i1, 0x8c
a00cd524:  80 a6 20 02  cmp  %i0, 2
a00cd528:  02 80 03 1b  be  0xa00ce194
a00cd52c:  80 a6 20 03  cmp  %i0, 3
a00cd530:  02 80 03 6c  be  0xa00ce2e0
a00cd534:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00cd538:  c2 0a a0 d9  ldub  [ %o2 + 0xd9 ], %g1	! 0xa802d0d9
a00cd53c:  92 08 60 ff  and  %g1, 0xff, %o1
a00cd540:  96 02 7f d0  add  %o1, -48, %o3
a00cd544:  82 0a e0 ff  and  %o3, 0xff, %g1
a00cd548:  80 a0 60 01  cmp  %g1, 1
a00cd54c:  18 bf fe bf  bgu  0xa00cd048
a00cd550:  90 10 20 ff  mov  0xff, %o0
a00cd554:  80 a0 60 01  cmp  %g1, 1
a00cd558:  02 80 03 74  be  0xa00ce328
a00cd55c:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00cd560:  7f ff ac db  call  0xa00b88cc
a00cd564:  01 00 00 00  nop
a00cd568:  7f ff b5 41  call  0xa00baa6c
a00cd56c:  90 10 00 18  mov  %i0, %o0
a00cd570:  7f ff b4 f8  call  0xa00ba950
a00cd574:  90 10 00 18  mov  %i0, %o0
a00cd578:  90 10 00 18  mov  %i0, %o0
a00cd57c:  7f ff b5 81  call  0xa00bab80
a00cd580:  92 10 20 06  mov  6, %o1
a00cd584:  10 bf fe b1  b  0xa00cd048
a00cd588:  90 10 20 00  clr  %o0
a00cd58c:  7f ff e8 a3  call  0xa00c7818
a00cd590:  90 10 00 18  mov  %i0, %o0
a00cd594:  10 bf fe ae  b  0xa00cd04c
a00cd598:  80 a6 60 8c  cmp  %i1, 0x8c
a00cd59c:  80 a6 20 02  cmp  %i0, 2
a00cd5a0:  02 80 03 09  be  0xa00ce1c4
a00cd5a4:  80 a6 20 03  cmp  %i0, 3
a00cd5a8:  02 80 03 57  be  0xa00ce304
a00cd5ac:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a00cd5b0:  c2 0b e0 d9  ldub  [ %o7 + 0xd9 ], %g1	! 0xa802d0d9
a00cd5b4:  90 08 60 ff  and  %g1, 0xff, %o0
a00cd5b8:  9a 02 3f d0  add  %o0, -48, %o5
a00cd5bc:  82 0b 60 ff  and  %o5, 0xff, %g1
a00cd5c0:  80 a0 60 01  cmp  %g1, 1
a00cd5c4:  18 bf fe a1  bgu  0xa00cd048
a00cd5c8:  90 10 20 ff  mov  0xff, %o0
a00cd5cc:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00cd5d0:  98 12 22 90  or  %o0, 0x290, %o4	! 0xa802d290
a00cd5d4:  92 08 60 01  and  %g1, 1, %o1
a00cd5d8:  da 03 20 ac  ld  [ %o4 + 0xac ], %o5
a00cd5dc:  1f 00 10 00  sethi  %hi(0x400000), %o7
a00cd5e0:  97 2a 60 16  sll  %o1, 0x16, %o3
a00cd5e4:  94 2b 40 0f  andn  %o5, %o7, %o2
a00cd5e8:  82 12 80 0b  or  %o2, %o3, %g1
a00cd5ec:  7f ff 0e 7b  call  0xa0090fd8
a00cd5f0:  c2 23 20 ac  st  %g1, [ %o4 + 0xac ]
a00cd5f4:  7f ff ac b6  call  0xa00b88cc
a00cd5f8:  01 00 00 00  nop
a00cd5fc:  7f ff b5 1c  call  0xa00baa6c
a00cd600:  90 10 00 18  mov  %i0, %o0
a00cd604:  7f ff b4 d3  call  0xa00ba950
a00cd608:  90 10 00 18  mov  %i0, %o0
a00cd60c:  90 10 00 18  mov  %i0, %o0
a00cd610:  7f ff b5 5c  call  0xa00bab80
a00cd614:  92 10 20 06  mov  6, %o1
a00cd618:  10 bf fe 8c  b  0xa00cd048
a00cd61c:  90 10 20 00  clr  %o0
a00cd620:  80 a6 20 02  cmp  %i0, 2
a00cd624:  02 80 02 f7  be  0xa00ce200
a00cd628:  80 a6 20 03  cmp  %i0, 3
a00cd62c:  02 80 03 12  be  0xa00ce274
a00cd630:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a00cd634:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00cd638:  c2 08 60 d9  ldub  [ %g1 + 0xd9 ], %g1	! 0xa802d0d9
a00cd63c:  96 08 60 ff  and  %g1, 0xff, %o3
a00cd640:  90 02 ff d0  add  %o3, -48, %o0
a00cd644:  82 0a 20 ff  and  %o0, 0xff, %g1
a00cd648:  80 a0 60 01  cmp  %g1, 1
a00cd64c:  18 bf fe 7f  bgu  0xa00cd048
a00cd650:  90 10 20 ff  mov  0xff, %o0
a00cd654:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00cd658:  94 13 22 90  or  %o4, 0x290, %o2	! 0xa802d290
a00cd65c:  90 08 60 01  and  %g1, 1, %o0
a00cd660:  d6 02 a0 a8  ld  [ %o2 + 0xa8 ], %o3
a00cd664:  03 00 00 20  sethi  %hi(0x8000), %g1
a00cd668:  9b 2a 20 0f  sll  %o0, 0xf, %o5
a00cd66c:  9e 2a c0 01  andn  %o3, %g1, %o7
a00cd670:  92 13 c0 0d  or  %o7, %o5, %o1
a00cd674:  7f ff ac 96  call  0xa00b88cc
a00cd678:  d2 22 a0 a8  st  %o1, [ %o2 + 0xa8 ]
a00cd67c:  7f ff b4 fc  call  0xa00baa6c
a00cd680:  90 10 00 18  mov  %i0, %o0
a00cd684:  7f ff b4 b3  call  0xa00ba950
a00cd688:  90 10 00 18  mov  %i0, %o0
a00cd68c:  90 10 00 18  mov  %i0, %o0
a00cd690:  7f ff b5 3c  call  0xa00bab80
a00cd694:  92 10 20 06  mov  6, %o1
a00cd698:  10 bf fe 6c  b  0xa00cd048
a00cd69c:  90 10 20 00  clr  %o0
a00cd6a0:  80 a6 20 02  cmp  %i0, 2
a00cd6a4:  02 80 02 bf  be  0xa00ce1a0
a00cd6a8:  80 a6 20 03  cmp  %i0, 3
a00cd6ac:  02 80 03 10  be  0xa00ce2ec
a00cd6b0:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a00cd6b4:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00cd6b8:  c2 0a 20 d9  ldub  [ %o0 + 0xd9 ], %g1	! 0xa802d0d9
a00cd6bc:  82 08 60 ff  and  %g1, 0xff, %g1
a00cd6c0:  98 00 7f d0  add  %g1, -48, %o4
a00cd6c4:  82 0b 20 ff  and  %o4, 0xff, %g1
a00cd6c8:  80 a0 60 01  cmp  %g1, 1
a00cd6cc:  18 bf fe 5f  bgu  0xa00cd048
a00cd6d0:  90 10 20 ff  mov  0xff, %o0
a00cd6d4:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00cd6d8:  94 13 22 90  or  %o4, 0x290, %o2	! 0xa802d290
a00cd6dc:  d0 02 a1 ec  ld  [ %o2 + 0x1ec ], %o0
a00cd6e0:  9a 08 60 01  and  %g1, 1, %o5
a00cd6e4:  92 0a 3f 7f  and  %o0, -129, %o1
a00cd6e8:  9f 2b 60 07  sll  %o5, 7, %o7
a00cd6ec:  96 12 40 0f  or  %o1, %o7, %o3
a00cd6f0:  d6 22 a1 ec  st  %o3, [ %o2 + 0x1ec ]
a00cd6f4:  40 00 36 8e  call  0xa00db12c
a00cd6f8:  90 10 20 00  clr  %o0
a00cd6fc:  7f ff ac 74  call  0xa00b88cc
a00cd700:  01 00 00 00  nop
a00cd704:  7f ff b4 da  call  0xa00baa6c
a00cd708:  90 10 00 18  mov  %i0, %o0
a00cd70c:  7f ff b4 91  call  0xa00ba950
a00cd710:  90 10 00 18  mov  %i0, %o0
a00cd714:  90 10 00 18  mov  %i0, %o0
a00cd718:  7f ff b5 1a  call  0xa00bab80
a00cd71c:  92 10 20 06  mov  6, %o1
a00cd720:  10 bf fe 4a  b  0xa00cd048
a00cd724:  90 10 20 00  clr  %o0
a00cd728:  7f ff f1 2e  call  0xa00c9be0
a00cd72c:  90 10 00 18  mov  %i0, %o0
a00cd730:  10 bf fe 47  b  0xa00cd04c
a00cd734:  80 a6 60 8c  cmp  %i1, 0x8c
a00cd738:  92 10 20 01  mov  1, %o1
a00cd73c:  40 01 f7 5e  call  0xa014b4b4
a00cd740:  90 10 20 fe  mov  0xfe, %o0
a00cd744:  7f ff b4 ca  call  0xa00baa6c
a00cd748:  90 10 00 18  mov  %i0, %o0
a00cd74c:  7f ff b4 81  call  0xa00ba950
a00cd750:  90 10 00 18  mov  %i0, %o0
a00cd754:  90 10 00 18  mov  %i0, %o0
a00cd758:  7f ff b5 0a  call  0xa00bab80
a00cd75c:  92 10 20 06  mov  6, %o1
a00cd760:  10 bf fe 3a  b  0xa00cd048
a00cd764:  90 10 20 00  clr  %o0
a00cd768:  7f ff ef 8f  call  0xa00c95a4
a00cd76c:  90 10 00 18  mov  %i0, %o0
a00cd770:  10 bf fe 37  b  0xa00cd04c
a00cd774:  80 a6 60 8c  cmp  %i1, 0x8c
a00cd778:  80 a6 20 02  cmp  %i0, 2
a00cd77c:  02 80 02 9e  be  0xa00ce1f4
a00cd780:  80 a6 20 03  cmp  %i0, 3
a00cd784:  02 80 02 b9  be  0xa00ce268
a00cd788:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00cd78c:  c2 0a a0 d9  ldub  [ %o2 + 0xd9 ], %g1	! 0xa802d0d9
a00cd790:  92 08 60 ff  and  %g1, 0xff, %o1
a00cd794:  9a 02 7f d0  add  %o1, -48, %o5
a00cd798:  82 0b 60 ff  and  %o5, 0xff, %g1
a00cd79c:  80 a0 60 01  cmp  %g1, 1
a00cd7a0:  18 bf fe 2a  bgu  0xa00cd048
a00cd7a4:  90 10 20 ff  mov  0xff, %o0
a00cd7a8:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00cd7ac:  9e 13 22 90  or  %o4, 0x290, %o7	! 0xa802d290
a00cd7b0:  9a 08 60 01  and  %g1, 1, %o5
a00cd7b4:  d4 03 e0 a8  ld  [ %o7 + 0xa8 ], %o2
a00cd7b8:  90 0a bf bf  and  %o2, -65, %o0
a00cd7bc:  97 2b 60 06  sll  %o5, 6, %o3
a00cd7c0:  82 12 00 0b  or  %o0, %o3, %g1
a00cd7c4:  c2 23 e0 a8  st  %g1, [ %o7 + 0xa8 ]
a00cd7c8:  40 00 30 6c  call  0xa00d9978
a00cd7cc:  01 00 00 00  nop
a00cd7d0:  7f ff ac 3f  call  0xa00b88cc
a00cd7d4:  01 00 00 00  nop
a00cd7d8:  7f ff b4 a5  call  0xa00baa6c
a00cd7dc:  90 10 00 18  mov  %i0, %o0
a00cd7e0:  7f ff b4 5c  call  0xa00ba950
a00cd7e4:  90 10 00 18  mov  %i0, %o0
a00cd7e8:  90 10 00 18  mov  %i0, %o0
a00cd7ec:  7f ff b4 e5  call  0xa00bab80
a00cd7f0:  92 10 20 06  mov  6, %o1
a00cd7f4:  10 bf fe 15  b  0xa00cd048
a00cd7f8:  90 10 20 00  clr  %o0
a00cd7fc:  7f ff e2 8b  call  0xa00c6228
a00cd800:  90 10 00 18  mov  %i0, %o0
a00cd804:  10 bf fe 12  b  0xa00cd04c
a00cd808:  80 a6 60 8c  cmp  %i1, 0x8c
a00cd80c:  7f ff b5 8b  call  0xa00bae38
a00cd810:  90 10 00 18  mov  %i0, %o0
a00cd814:  9e 0a 20 ff  and  %o0, 0xff, %o7
a00cd818:  80 a3 e0 0b  cmp  %o7, 0xb
a00cd81c:  08 80 02 39  bleu  0xa00ce100
a00cd820:  82 10 20 ff  mov  0xff, %g1
a00cd824:  10 bf fe 09  b  0xa00cd048
a00cd828:  90 10 00 01  mov  %g1, %o0
a00cd82c:  7f ff b5 83  call  0xa00bae38
a00cd830:  90 10 00 18  mov  %i0, %o0
a00cd834:  92 0a 20 ff  and  %o0, 0xff, %o1
a00cd838:  80 a2 60 0b  cmp  %o1, 0xb
a00cd83c:  08 80 02 24  bleu  0xa00ce0cc
a00cd840:  82 10 20 ff  mov  0xff, %g1
a00cd844:  10 bf fe 01  b  0xa00cd048
a00cd848:  90 10 00 01  mov  %g1, %o0
a00cd84c:  7f ff f3 7e  call  0xa00ca644
a00cd850:  90 10 00 18  mov  %i0, %o0
a00cd854:  10 bf fd fe  b  0xa00cd04c
a00cd858:  80 a6 60 8c  cmp  %i1, 0x8c
a00cd85c:  80 a6 20 02  cmp  %i0, 2
a00cd860:  02 80 02 5c  be  0xa00ce1d0
a00cd864:  80 a6 20 03  cmp  %i0, 3
a00cd868:  02 80 02 aa  be  0xa00ce310
a00cd86c:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00cd870:  c2 0a a0 d9  ldub  [ %o2 + 0xd9 ], %g1	! 0xa802d0d9
a00cd874:  92 08 60 ff  and  %g1, 0xff, %o1
a00cd878:  98 02 7f d0  add  %o1, -48, %o4
a00cd87c:  9a 0b 20 ff  and  %o4, 0xff, %o5
a00cd880:  80 a3 60 02  cmp  %o5, 2
a00cd884:  18 bf fd f1  bgu  0xa00cd048
a00cd888:  90 10 20 ff  mov  0xff, %o0
a00cd88c:  1f 2a 00 b5  sethi  %hi(0xa802d400), %o7
a00cd890:  d8 2b e0 6d  stb  %o4, [ %o7 + 0x6d ]	! 0xa802d46d
a00cd894:  40 00 34 9d  call  0xa00dab08
a00cd898:  01 00 00 00  nop
a00cd89c:  7f ff ac 0c  call  0xa00b88cc
a00cd8a0:  01 00 00 00  nop
a00cd8a4:  7f ff b4 72  call  0xa00baa6c
a00cd8a8:  90 10 00 18  mov  %i0, %o0
a00cd8ac:  7f ff b4 29  call  0xa00ba950
a00cd8b0:  90 10 00 18  mov  %i0, %o0
a00cd8b4:  90 10 00 18  mov  %i0, %o0
a00cd8b8:  7f ff b4 b2  call  0xa00bab80
a00cd8bc:  92 10 20 06  mov  6, %o1
a00cd8c0:  10 bf fd e2  b  0xa00cd048
a00cd8c4:  90 10 20 00  clr  %o0
a00cd8c8:  92 10 20 01  mov  1, %o1
a00cd8cc:  40 01 f6 fa  call  0xa014b4b4
a00cd8d0:  90 10 20 fe  mov  0xfe, %o0
a00cd8d4:  7f ff b4 66  call  0xa00baa6c
a00cd8d8:  90 10 00 18  mov  %i0, %o0
a00cd8dc:  7f ff b4 1d  call  0xa00ba950
a00cd8e0:  90 10 00 18  mov  %i0, %o0
a00cd8e4:  90 10 00 18  mov  %i0, %o0
a00cd8e8:  7f ff b4 a6  call  0xa00bab80
a00cd8ec:  92 10 20 06  mov  6, %o1
a00cd8f0:  10 bf fd d6  b  0xa00cd048
a00cd8f4:  90 10 20 00  clr  %o0
a00cd8f8:  10 bf fd d4  b  0xa00cd048
a00cd8fc:  90 10 20 00  clr  %o0
a00cd900:  7f ff d9 95  call  0xa00c3f54
a00cd904:  90 10 00 18  mov  %i0, %o0
a00cd908:  10 bf fd d1  b  0xa00cd04c
a00cd90c:  80 a6 60 8c  cmp  %i1, 0x8c
a00cd910:  80 a6 20 02  cmp  %i0, 2
a00cd914:  02 80 02 1d  be  0xa00ce188
a00cd918:  80 a6 20 03  cmp  %i0, 3
a00cd91c:  02 80 02 6e  be  0xa00ce2d4
a00cd920:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00cd924:  c2 0a e0 d9  ldub  [ %o3 + 0xd9 ], %g1	! 0xa802d0d9
a00cd928:  9e 08 60 ff  and  %g1, 0xff, %o7
a00cd92c:  98 03 ff d0  add  %o7, -48, %o4
a00cd930:  92 0b 20 ff  and  %o4, 0xff, %o1
a00cd934:  80 a2 60 01  cmp  %o1, 1
a00cd938:  18 bf fd c4  bgu  0xa00cd048
a00cd93c:  90 10 20 ff  mov  0xff, %o0
a00cd940:  1b 2a 00 b5  sethi  %hi(0xa802d400), %o5
a00cd944:  7f ff ab e2  call  0xa00b88cc
a00cd948:  d8 2b 60 07  stb  %o4, [ %o5 + 7 ]	! 0xa802d407
a00cd94c:  7f ff b4 48  call  0xa00baa6c
a00cd950:  90 10 00 18  mov  %i0, %o0
a00cd954:  7f ff b3 ff  call  0xa00ba950
a00cd958:  90 10 00 18  mov  %i0, %o0
a00cd95c:  90 10 00 18  mov  %i0, %o0
a00cd960:  7f ff b4 88  call  0xa00bab80
a00cd964:  92 10 20 06  mov  6, %o1
a00cd968:  10 bf fd b8  b  0xa00cd048
a00cd96c:  90 10 20 00  clr  %o0
a00cd970:  7f ff b5 32  call  0xa00bae38
a00cd974:  90 10 00 18  mov  %i0, %o0
a00cd978:  94 0a 20 ff  and  %o0, 0xff, %o2
a00cd97c:  80 a2 a0 0b  cmp  %o2, 0xb
a00cd980:  08 80 01 c6  bleu  0xa00ce098
a00cd984:  82 10 20 ff  mov  0xff, %g1
a00cd988:  10 bf fd b0  b  0xa00cd048
a00cd98c:  90 10 00 01  mov  %g1, %o0
a00cd990:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00cd994:  80 a6 20 02  cmp  %i0, 2
a00cd998:  02 80 00 08  be  0xa00cd9b8
a00cd99c:  82 13 20 40  or  %o4, 0x40, %g1
a00cd9a0:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a00cd9a4:  80 a6 20 03  cmp  %i0, 3
a00cd9a8:  02 80 00 04  be  0xa00cd9b8
a00cd9ac:  82 13 60 98  or  %o5, 0x98, %g1
a00cd9b0:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00cd9b4:  82 12 a0 d0  or  %o2, 0xd0, %g1	! 0xa802d0d0
a00cd9b8:  d0 08 60 07  ldub  [ %g1 + 7 ], %o0
a00cd9bc:  94 02 3f d0  add  %o0, -48, %o2
a00cd9c0:  9e 0a a0 ff  and  %o2, 0xff, %o7
a00cd9c4:  d6 08 60 09  ldub  [ %g1 + 9 ], %o3
a00cd9c8:  d8 08 60 08  ldub  [ %g1 + 8 ], %o4
a00cd9cc:  80 a3 e0 01  cmp  %o7, 1
a00cd9d0:  18 80 00 16  bgu  0xa00cda28
a00cd9d4:  9a 10 20 ff  mov  0xff, %o5
a00cd9d8:  98 03 3f d0  add  %o4, -48, %o4
a00cd9dc:  82 0b 20 ff  and  %o4, 0xff, %g1
a00cd9e0:  80 a0 60 09  cmp  %g1, 9
a00cd9e4:  18 80 00 12  bgu  0xa00cda2c
a00cd9e8:  80 a3 60 1e  cmp  %o5, 0x1e
a00cd9ec:  96 02 ff d0  add  %o3, -48, %o3
a00cd9f0:  92 0a e0 ff  and  %o3, 0xff, %o1
a00cd9f4:  80 a2 60 09  cmp  %o1, 9
a00cd9f8:  18 80 00 0d  bgu  0xa00cda2c
a00cd9fc:  80 a3 60 1e  cmp  %o5, 0x1e
a00cda00:  98 0b 20 ff  and  %o4, 0xff, %o4
a00cda04:  93 2b 20 02  sll  %o4, 2, %o1
a00cda08:  90 02 40 0c  add  %o1, %o4, %o0
a00cda0c:  82 0a a0 ff  and  %o2, 0xff, %g1
a00cda10:  9a 02 00 08  add  %o0, %o0, %o5
a00cda14:  9e 58 60 64  smul  %g1, 0x64, %o7
a00cda18:  94 03 c0 0d  add  %o7, %o5, %o2
a00cda1c:  98 0a e0 ff  and  %o3, 0xff, %o4
a00cda20:  96 02 80 0c  add  %o2, %o4, %o3
a00cda24:  9a 0a e0 ff  and  %o3, 0xff, %o5
a00cda28:  80 a3 60 1e  cmp  %o5, 0x1e
a00cda2c:  18 bf fd 87  bgu  0xa00cd048
a00cda30:  90 10 20 ff  mov  0xff, %o0
a00cda34:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00cda38:  7f ff ab a5  call  0xa00b88cc
a00cda3c:  da 2a e2 9c  stb  %o5, [ %o3 + 0x29c ]	! 0xa802d29c
a00cda40:  7f ff b4 0b  call  0xa00baa6c
a00cda44:  90 10 00 18  mov  %i0, %o0
a00cda48:  7f ff b3 c2  call  0xa00ba950
a00cda4c:  90 10 00 18  mov  %i0, %o0
a00cda50:  90 10 00 18  mov  %i0, %o0
a00cda54:  7f ff b4 4b  call  0xa00bab80
a00cda58:  92 10 20 06  mov  6, %o1
a00cda5c:  10 bf fd 7b  b  0xa00cd048
a00cda60:  90 10 20 00  clr  %o0
a00cda64:  10 bf fd 79  b  0xa00cd048
a00cda68:  90 10 20 00  clr  %o0
a00cda6c:  7f ff f3 83  call  0xa00ca878
a00cda70:  90 10 00 18  mov  %i0, %o0
a00cda74:  10 bf fd 76  b  0xa00cd04c
a00cda78:  80 a6 60 8c  cmp  %i1, 0x8c
a00cda7c:  7f ff d0 b6  call  0xa00c1d54
a00cda80:  90 10 00 18  mov  %i0, %o0
a00cda84:  10 bf fd 72  b  0xa00cd04c
a00cda88:  80 a6 60 8c  cmp  %i1, 0x8c
a00cda8c:  7f ff d1 bd  call  0xa00c2180
a00cda90:  90 10 00 18  mov  %i0, %o0
a00cda94:  10 bf fd 6e  b  0xa00cd04c
a00cda98:  80 a6 60 8c  cmp  %i1, 0x8c
a00cda9c:  10 bf fd 6b  b  0xa00cd048
a00cdaa0:  90 10 20 00  clr  %o0
a00cdaa4:  7f ff e6 e2  call  0xa00c762c
a00cdaa8:  90 10 00 18  mov  %i0, %o0
a00cdaac:  10 bf fd 68  b  0xa00cd04c
a00cdab0:  80 a6 60 8c  cmp  %i1, 0x8c
a00cdab4:  7f ff e2 f7  call  0xa00c6690
a00cdab8:  90 10 00 18  mov  %i0, %o0
a00cdabc:  10 bf fd 64  b  0xa00cd04c
a00cdac0:  80 a6 60 8c  cmp  %i1, 0x8c
a00cdac4:  7f ff e2 58  call  0xa00c6424
a00cdac8:  90 10 00 18  mov  %i0, %o0
a00cdacc:  10 bf fd 60  b  0xa00cd04c
a00cdad0:  80 a6 60 8c  cmp  %i1, 0x8c
a00cdad4:  7f ff ed c2  call  0xa00c91dc
a00cdad8:  90 10 00 18  mov  %i0, %o0
a00cdadc:  10 bf fd 5c  b  0xa00cd04c
a00cdae0:  80 a6 60 8c  cmp  %i1, 0x8c
a00cdae4:  7f ff eb d8  call  0xa00c8a44
a00cdae8:  90 10 00 18  mov  %i0, %o0
a00cdaec:  10 bf fd 58  b  0xa00cd04c
a00cdaf0:  80 a6 60 8c  cmp  %i1, 0x8c
a00cdaf4:  7f ff ea 47  call  0xa00c8410
a00cdaf8:  90 10 00 18  mov  %i0, %o0
a00cdafc:  10 bf fd 54  b  0xa00cd04c
a00cdb00:  80 a6 60 8c  cmp  %i1, 0x8c
a00cdb04:  7f ff ce 3f  call  0xa00c1400
a00cdb08:  90 10 00 18  mov  %i0, %o0
a00cdb0c:  10 bf fd 50  b  0xa00cd04c
a00cdb10:  80 a6 60 8c  cmp  %i1, 0x8c
a00cdb14:  7f ff ea c0  call  0xa00c8614
a00cdb18:  90 10 00 18  mov  %i0, %o0
a00cdb1c:  10 bf fd 4c  b  0xa00cd04c
a00cdb20:  80 a6 60 8c  cmp  %i1, 0x8c
a00cdb24:  7f ff eb 3d  call  0xa00c8818
a00cdb28:  90 10 00 18  mov  %i0, %o0
a00cdb2c:  10 bf fd 48  b  0xa00cd04c
a00cdb30:  80 a6 60 8c  cmp  %i1, 0x8c
a00cdb34:  7f ff e7 ca  call  0xa00c7a5c
a00cdb38:  90 10 00 18  mov  %i0, %o0
a00cdb3c:  10 bf fd 44  b  0xa00cd04c
a00cdb40:  80 a6 60 8c  cmp  %i1, 0x8c
a00cdb44:  10 bf fd 41  b  0xa00cd048
a00cdb48:  90 10 20 00  clr  %o0
a00cdb4c:  7f ff 0d 23  call  0xa0090fd8
a00cdb50:  01 00 00 00  nop
a00cdb54:  40 00 3a 22  call  0xa00dc3dc
a00cdb58:  01 00 00 00  nop
a00cdb5c:  7f ff ab 5c  call  0xa00b88cc
a00cdb60:  01 00 00 00  nop
a00cdb64:  7f ff b3 c2  call  0xa00baa6c
a00cdb68:  90 10 00 18  mov  %i0, %o0
a00cdb6c:  7f ff b3 79  call  0xa00ba950
a00cdb70:  90 10 00 18  mov  %i0, %o0
a00cdb74:  90 10 00 18  mov  %i0, %o0
a00cdb78:  7f ff b4 02  call  0xa00bab80
a00cdb7c:  92 10 20 06  mov  6, %o1
a00cdb80:  10 bf fd 32  b  0xa00cd048
a00cdb84:  90 10 20 00  clr  %o0
a00cdb88:  10 bf fd 30  b  0xa00cd048
a00cdb8c:  90 10 20 00  clr  %o0
a00cdb90:  80 a6 20 02  cmp  %i0, 2
a00cdb94:  02 80 01 7a  be  0xa00ce17c
a00cdb98:  80 a6 20 03  cmp  %i0, 3
a00cdb9c:  02 80 01 cc  be  0xa00ce2cc
a00cdba0:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00cdba4:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00cdba8:  da 0a 20 d9  ldub  [ %o0 + 0xd9 ], %o5	! 0xa802d0d9
a00cdbac:  9a 03 7f d0  add  %o5, -48, %o5
a00cdbb0:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00cdbb4:  40 00 1b 35  call  0xa00d4888
a00cdbb8:  da 28 62 98  stb  %o5, [ %g1 + 0x298 ]	! 0xa802d298
a00cdbbc:  7f ff ab 44  call  0xa00b88cc
a00cdbc0:  01 00 00 00  nop
a00cdbc4:  7f ff b3 aa  call  0xa00baa6c
a00cdbc8:  90 10 00 18  mov  %i0, %o0
a00cdbcc:  7f ff b3 61  call  0xa00ba950
a00cdbd0:  90 10 00 18  mov  %i0, %o0
a00cdbd4:  90 10 00 18  mov  %i0, %o0
a00cdbd8:  7f ff b3 ea  call  0xa00bab80
a00cdbdc:  92 10 20 06  mov  6, %o1
a00cdbe0:  10 bf fd 1a  b  0xa00cd048
a00cdbe4:  90 10 20 00  clr  %o0
a00cdbe8:  10 bf fd 18  b  0xa00cd048
a00cdbec:  90 10 20 00  clr  %o0
a00cdbf0:  10 bf fd 16  b  0xa00cd048
a00cdbf4:  90 10 20 00  clr  %o0
a00cdbf8:  10 bf fd 14  b  0xa00cd048
a00cdbfc:  90 10 20 00  clr  %o0
a00cdc00:  10 bf fd 12  b  0xa00cd048
a00cdc04:  90 10 20 00  clr  %o0
a00cdc08:  10 bf fd 10  b  0xa00cd048
a00cdc0c:  90 10 20 00  clr  %o0
a00cdc10:  80 a6 20 02  cmp  %i0, 2
a00cdc14:  02 80 01 48  be  0xa00ce134
a00cdc18:  80 a6 20 03  cmp  %i0, 3
a00cdc1c:  02 80 01 9b  be  0xa00ce288
a00cdc20:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a00cdc24:  c2 0b 60 d9  ldub  [ %o5 + 0xd9 ], %g1	! 0xa802d0d9
a00cdc28:  96 08 60 ff  and  %g1, 0xff, %o3
a00cdc2c:  94 02 ff d0  add  %o3, -48, %o2
a00cdc30:  92 0a a0 ff  and  %o2, 0xff, %o1
a00cdc34:  80 a2 60 01  cmp  %o1, 1
a00cdc38:  18 bf fd 04  bgu  0xa00cd048
a00cdc3c:  90 10 20 ff  mov  0xff, %o0
a00cdc40:  7f ff ab 23  call  0xa00b88cc
a00cdc44:  01 00 00 00  nop
a00cdc48:  7f ff b3 89  call  0xa00baa6c
a00cdc4c:  90 10 00 18  mov  %i0, %o0
a00cdc50:  7f ff b3 40  call  0xa00ba950
a00cdc54:  90 10 00 18  mov  %i0, %o0
a00cdc58:  90 10 00 18  mov  %i0, %o0
a00cdc5c:  7f ff b3 c9  call  0xa00bab80
a00cdc60:  92 10 20 06  mov  6, %o1
a00cdc64:  10 bf fc f9  b  0xa00cd048
a00cdc68:  90 10 20 00  clr  %o0
a00cdc6c:  7f ff de b4  call  0xa00c573c
a00cdc70:  90 10 00 18  mov  %i0, %o0
a00cdc74:  10 bf fc f6  b  0xa00cd04c
a00cdc78:  80 a6 60 8c  cmp  %i1, 0x8c
a00cdc7c:  7f ff fb e9  call  0xa00ccc20
a00cdc80:  90 10 00 18  mov  %i0, %o0
a00cdc84:  10 bf fc f2  b  0xa00cd04c
a00cdc88:  80 a6 60 8c  cmp  %i1, 0x8c
a00cdc8c:  7f ff fb 4d  call  0xa00cc9c0
a00cdc90:  90 10 00 18  mov  %i0, %o0
a00cdc94:  10 bf fc ee  b  0xa00cd04c
a00cdc98:  80 a6 60 8c  cmp  %i1, 0x8c
a00cdc9c:  7f ff fa b1  call  0xa00cc760
a00cdca0:  90 10 00 18  mov  %i0, %o0
a00cdca4:  10 bf fc ea  b  0xa00cd04c
a00cdca8:  80 a6 60 8c  cmp  %i1, 0x8c
a00cdcac:  7f ff df 55  call  0xa00c5a00
a00cdcb0:  90 10 00 18  mov  %i0, %o0
a00cdcb4:  10 bf fc e6  b  0xa00cd04c
a00cdcb8:  80 a6 60 8c  cmp  %i1, 0x8c
a00cdcbc:  80 a6 20 02  cmp  %i0, 2
a00cdcc0:  02 80 01 29  be  0xa00ce164
a00cdcc4:  80 a6 20 03  cmp  %i0, 3
a00cdcc8:  02 80 01 7b  be  0xa00ce2b4
a00cdccc:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00cdcd0:  c2 0a a0 d9  ldub  [ %o2 + 0xd9 ], %g1	! 0xa802d0d9
a00cdcd4:  96 08 60 ff  and  %g1, 0xff, %o3
a00cdcd8:  80 a2 e0 31  cmp  %o3, 0x31
a00cdcdc:  12 bf fc db  bne  0xa00cd048
a00cdce0:  90 10 20 ff  mov  0xff, %o0
a00cdce4:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00cdce8:  de 0b 22 af  ldub  [ %o4 + 0x2af ], %o7	! 0xa802d2af
a00cdcec:  80 a3 e0 00  cmp  %o7, 0
a00cdcf0:  02 bf fc d7  be  0xa00cd04c
a00cdcf4:  80 a6 60 8c  cmp  %i1, 0x8c
a00cdcf8:  40 00 2d b4  call  0xa00d93c8
a00cdcfc:  01 00 00 00  nop
a00cdd00:  7f ff b3 5b  call  0xa00baa6c
a00cdd04:  90 10 00 18  mov  %i0, %o0
a00cdd08:  7f ff b3 12  call  0xa00ba950
a00cdd0c:  90 10 00 18  mov  %i0, %o0
a00cdd10:  90 10 00 18  mov  %i0, %o0
a00cdd14:  7f ff b3 9b  call  0xa00bab80
a00cdd18:  92 10 20 06  mov  6, %o1
a00cdd1c:  10 bf fc cb  b  0xa00cd048
a00cdd20:  90 10 20 00  clr  %o0
a00cdd24:  80 a6 20 02  cmp  %i0, 2
a00cdd28:  02 80 01 06  be  0xa00ce140
a00cdd2c:  80 a6 20 03  cmp  %i0, 3
a00cdd30:  02 80 01 59  be  0xa00ce294
a00cdd34:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a00cdd38:  c2 0b e0 d9  ldub  [ %o7 + 0xd9 ], %g1	! 0xa802d0d9
a00cdd3c:  90 08 60 ff  and  %g1, 0xff, %o0
a00cdd40:  80 a2 20 31  cmp  %o0, 0x31
a00cdd44:  12 bf fc c1  bne  0xa00cd048
a00cdd48:  90 10 20 ff  mov  0xff, %o0
a00cdd4c:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00cdd50:  d8 08 62 af  ldub  [ %g1 + 0x2af ], %o4	! 0xa802d2af
a00cdd54:  80 a3 20 00  cmp  %o4, 0
a00cdd58:  02 bf fc bd  be  0xa00cd04c
a00cdd5c:  80 a6 60 8c  cmp  %i1, 0x8c
a00cdd60:  40 00 2d 7b  call  0xa00d934c
a00cdd64:  01 00 00 00  nop
a00cdd68:  7f ff b3 41  call  0xa00baa6c
a00cdd6c:  90 10 00 18  mov  %i0, %o0
a00cdd70:  7f ff b2 f8  call  0xa00ba950
a00cdd74:  90 10 00 18  mov  %i0, %o0
a00cdd78:  90 10 00 18  mov  %i0, %o0
a00cdd7c:  7f ff b3 81  call  0xa00bab80
a00cdd80:  92 10 20 06  mov  6, %o1
a00cdd84:  10 bf fc b1  b  0xa00cd048
a00cdd88:  90 10 20 00  clr  %o0
a00cdd8c:  7f ff e0 b0  call  0xa00c604c
a00cdd90:  90 10 00 18  mov  %i0, %o0
a00cdd94:  10 bf fc ae  b  0xa00cd04c
a00cdd98:  80 a6 60 8c  cmp  %i1, 0x8c
a00cdd9c:  80 a6 20 02  cmp  %i0, 2
a00cdda0:  02 80 00 eb  be  0xa00ce14c
a00cdda4:  80 a6 20 03  cmp  %i0, 3
a00cdda8:  02 80 01 3e  be  0xa00ce2a0
a00cddac:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00cddb0:  c2 0a e0 d9  ldub  [ %o3 + 0xd9 ], %g1	! 0xa802d0d9
a00cddb4:  98 08 60 ff  and  %g1, 0xff, %o4
a00cddb8:  9e 03 3f d0  add  %o4, -48, %o7
a00cddbc:  82 0b e0 ff  and  %o7, 0xff, %g1
a00cddc0:  80 a0 60 01  cmp  %g1, 1
a00cddc4:  18 bf fc a1  bgu  0xa00cd048
a00cddc8:  90 10 20 ff  mov  0xff, %o0
a00cddcc:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00cddd0:  90 13 22 90  or  %o4, 0x290, %o0	! 0xa802d290
a00cddd4:  d6 02 20 a8  ld  [ %o0 + 0xa8 ], %o3
a00cddd8:  94 08 60 01  and  %g1, 1, %o2
a00cdddc:  1f 00 00 04  sethi  %hi(0x1000), %o7
a00cdde0:  92 2a c0 0f  andn  %o3, %o7, %o1
a00cdde4:  9b 2a a0 0c  sll  %o2, 0xc, %o5
a00cdde8:  82 12 40 0d  or  %o1, %o5, %g1
a00cddec:  7f ff 0c 7b  call  0xa0090fd8
a00cddf0:  c2 22 20 a8  st  %g1, [ %o0 + 0xa8 ]
a00cddf4:  7f ff b3 1e  call  0xa00baa6c
a00cddf8:  90 10 00 18  mov  %i0, %o0
a00cddfc:  7f ff b2 d5  call  0xa00ba950
a00cde00:  90 10 00 18  mov  %i0, %o0
a00cde04:  90 10 00 18  mov  %i0, %o0
a00cde08:  7f ff b3 5e  call  0xa00bab80
a00cde0c:  92 10 20 06  mov  6, %o1
a00cde10:  10 bf fc 8e  b  0xa00cd048
a00cde14:  90 10 20 00  clr  %o0
a00cde18:  7f ff d8 cb  call  0xa00c4144
a00cde1c:  90 10 00 18  mov  %i0, %o0
a00cde20:  10 bf fc 8b  b  0xa00cd04c
a00cde24:  80 a6 60 8c  cmp  %i1, 0x8c
a00cde28:  80 a6 20 02  cmp  %i0, 2
a00cde2c:  02 80 00 ec  be  0xa00ce1dc
a00cde30:  80 a6 20 03  cmp  %i0, 3
a00cde34:  02 80 01 3a  be  0xa00ce31c
a00cde38:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00cde3c:  c2 0a e0 d9  ldub  [ %o3 + 0xd9 ], %g1	! 0xa802d0d9
a00cde40:  82 08 60 ff  and  %g1, 0xff, %g1
a00cde44:  98 00 7f d0  add  %g1, -48, %o4
a00cde48:  90 0b 20 ff  and  %o4, 0xff, %o0
a00cde4c:  80 a2 20 02  cmp  %o0, 2
a00cde50:  18 bf fc 7e  bgu  0xa00cd048
a00cde54:  90 10 20 ff  mov  0xff, %o0
a00cde58:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00cde5c:  d8 2a 62 dc  stb  %o4, [ %o1 + 0x2dc ]	! 0xa802d2dc
a00cde60:  40 00 20 13  call  0xa00d5eac
a00cde64:  90 10 20 01  mov  1, %o0
a00cde68:  7f ff b3 01  call  0xa00baa6c
a00cde6c:  90 10 00 18  mov  %i0, %o0
a00cde70:  7f ff b2 b8  call  0xa00ba950
a00cde74:  90 10 00 18  mov  %i0, %o0
a00cde78:  90 10 00 18  mov  %i0, %o0
a00cde7c:  7f ff b3 41  call  0xa00bab80
a00cde80:  92 10 20 06  mov  6, %o1
a00cde84:  10 bf fc 71  b  0xa00cd048
a00cde88:  90 10 20 00  clr  %o0
a00cde8c:  80 a6 20 02  cmp  %i0, 2
a00cde90:  02 80 00 b2  be  0xa00ce158
a00cde94:  80 a6 20 03  cmp  %i0, 3
a00cde98:  02 80 01 05  be  0xa00ce2ac
a00cde9c:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00cdea0:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00cdea4:  c2 0a 20 d9  ldub  [ %o0 + 0xd9 ], %g1	! 0xa802d0d9
a00cdea8:  92 08 60 ff  and  %g1, 0xff, %o1
a00cdeac:  98 02 7f d0  add  %o1, -48, %o4
a00cdeb0:  82 0b 20 ff  and  %o4, 0xff, %g1
a00cdeb4:  80 a0 60 02  cmp  %g1, 2
a00cdeb8:  18 bf fc 64  bgu  0xa00cd048
a00cdebc:  90 10 20 ff  mov  0xff, %o0
a00cdec0:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a00cdec4:  d8 2b 62 db  stb  %o4, [ %o5 + 0x2db ]	! 0xa802d2db
a00cdec8:  40 00 1f f9  call  0xa00d5eac
a00cdecc:  90 10 20 01  mov  1, %o0
a00cded0:  7f ff b2 e7  call  0xa00baa6c
a00cded4:  90 10 00 18  mov  %i0, %o0
a00cded8:  7f ff b2 9e  call  0xa00ba950
a00cdedc:  90 10 00 18  mov  %i0, %o0
a00cdee0:  90 10 00 18  mov  %i0, %o0
a00cdee4:  7f ff b3 27  call  0xa00bab80
a00cdee8:  92 10 20 06  mov  6, %o1
a00cdeec:  10 bf fc 57  b  0xa00cd048
a00cdef0:  90 10 20 00  clr  %o0
a00cdef4:  10 bf fc 55  b  0xa00cd048
a00cdef8:  90 10 20 00  clr  %o0
a00cdefc:  10 bf fc 53  b  0xa00cd048
a00cdf00:  90 10 20 00  clr  %o0
a00cdf04:  7f ff dd 5d  call  0xa00c5478
a00cdf08:  90 10 00 18  mov  %i0, %o0
a00cdf0c:  10 bf fc 50  b  0xa00cd04c
a00cdf10:  80 a6 60 8c  cmp  %i1, 0x8c
a00cdf14:  7f ff db ec  call  0xa00c4ec4
a00cdf18:  90 10 00 18  mov  %i0, %o0
a00cdf1c:  10 bf fc 4c  b  0xa00cd04c
a00cdf20:  80 a6 60 8c  cmp  %i1, 0x8c
a00cdf24:  10 bf fc 49  b  0xa00cd048
a00cdf28:  90 10 20 00  clr  %o0
a00cdf2c:  7f ff d9 41  call  0xa00c4430
a00cdf30:  90 10 00 18  mov  %i0, %o0
a00cdf34:  10 bf fc 46  b  0xa00cd04c
a00cdf38:  80 a6 60 8c  cmp  %i1, 0x8c
a00cdf3c:  7f ff df c1  call  0xa00c5e40
a00cdf40:  90 10 00 18  mov  %i0, %o0
a00cdf44:  10 bf fc 42  b  0xa00cd04c
a00cdf48:  80 a6 60 8c  cmp  %i1, 0x8c
a00cdf4c:  7f ff df 33  call  0xa00c5c18
a00cdf50:  90 10 00 18  mov  %i0, %o0
a00cdf54:  10 bf fc 3e  b  0xa00cd04c
a00cdf58:  80 a6 60 8c  cmp  %i1, 0x8c
a00cdf5c:  7f ff d3 1f  call  0xa00c2bd8
a00cdf60:  90 10 00 18  mov  %i0, %o0
a00cdf64:  10 bf fc 3a  b  0xa00cd04c
a00cdf68:  80 a6 60 8c  cmp  %i1, 0x8c
a00cdf6c:  80 a6 20 02  cmp  %i0, 2
a00cdf70:  02 80 00 80  be  0xa00ce170
a00cdf74:  80 a6 20 03  cmp  %i0, 3
a00cdf78:  02 80 00 d2  be  0xa00ce2c0
a00cdf7c:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00cdf80:  c2 0a 60 d9  ldub  [ %o1 + 0xd9 ], %g1	! 0xa802d0d9
a00cdf84:  94 08 60 ff  and  %g1, 0xff, %o2
a00cdf88:  98 02 bf d0  add  %o2, -48, %o4
a00cdf8c:  9a 0b 20 ff  and  %o4, 0xff, %o5
a00cdf90:  80 a3 60 04  cmp  %o5, 4
a00cdf94:  18 bf fc 2d  bgu  0xa00cd048
a00cdf98:  90 10 20 ff  mov  0xff, %o0
a00cdf9c:  1f 2a 00 b3  sethi  %hi(0xa802cc00), %o7
a00cdfa0:  d8 2b e3 fd  stb  %o4, [ %o7 + 0x3fd ]	! 0xa802cffd
a00cdfa4:  7f ff b2 b2  call  0xa00baa6c
a00cdfa8:  90 10 00 18  mov  %i0, %o0
a00cdfac:  7f ff b2 69  call  0xa00ba950
a00cdfb0:  90 10 00 18  mov  %i0, %o0
a00cdfb4:  90 10 00 18  mov  %i0, %o0
a00cdfb8:  7f ff b2 f2  call  0xa00bab80
a00cdfbc:  92 10 20 06  mov  6, %o1
a00cdfc0:  10 bf fc 22  b  0xa00cd048
a00cdfc4:  90 10 20 00  clr  %o0
a00cdfc8:  7f ff d3 d0  call  0xa00c2f08
a00cdfcc:  90 10 00 18  mov  %i0, %o0
a00cdfd0:  10 bf fc 1f  b  0xa00cd04c
a00cdfd4:  80 a6 60 8c  cmp  %i1, 0x8c
a00cdfd8:  7f ff d4 6a  call  0xa00c3180
a00cdfdc:  90 10 00 18  mov  %i0, %o0
a00cdfe0:  10 bf fc 1b  b  0xa00cd04c
a00cdfe4:  80 a6 60 8c  cmp  %i1, 0x8c
a00cdfe8:  7f ff d6 0e  call  0xa00c3820
a00cdfec:  90 10 00 18  mov  %i0, %o0
a00cdff0:  10 bf fc 17  b  0xa00cd04c
a00cdff4:  80 a6 60 8c  cmp  %i1, 0x8c
a00cdff8:  7f ff ce b9  call  0xa00c1adc
a00cdffc:  90 10 00 18  mov  %i0, %o0
a00ce000:  10 bf fc 13  b  0xa00cd04c
a00ce004:  80 a6 60 8c  cmp  %i1, 0x8c
a00ce008:  7f ff d4 de  call  0xa00c3380
a00ce00c:  90 10 00 18  mov  %i0, %o0
a00ce010:  10 bf fc 0f  b  0xa00cd04c
a00ce014:  80 a6 60 8c  cmp  %i1, 0x8c
a00ce018:  7f ff d5 6e  call  0xa00c35d0
a00ce01c:  90 10 00 18  mov  %i0, %o0
a00ce020:  10 bf fc 0b  b  0xa00cd04c
a00ce024:  80 a6 60 8c  cmp  %i1, 0x8c
a00ce028:  7f ff d6 fb  call  0xa00c3c14
a00ce02c:  90 10 00 18  mov  %i0, %o0
a00ce030:  10 bf fc 07  b  0xa00cd04c
a00ce034:  80 a6 60 8c  cmp  %i1, 0x8c
a00ce038:  7f ff d6 7e  call  0xa00c3a30
a00ce03c:  90 10 00 18  mov  %i0, %o0
a00ce040:  10 bf fc 03  b  0xa00cd04c
a00ce044:  80 a6 60 8c  cmp  %i1, 0x8c
a00ce048:  10 bf fc 00  b  0xa00cd048
a00ce04c:  90 10 20 00  clr  %o0
a00ce050:  10 bf fb fe  b  0xa00cd048
a00ce054:  90 10 20 00  clr  %o0
a00ce058:  10 bf fb fc  b  0xa00cd048
a00ce05c:  90 10 20 00  clr  %o0
a00ce060:  10 bf fb fa  b  0xa00cd048
a00ce064:  90 10 20 00  clr  %o0
a00ce068:  10 bf fb f8  b  0xa00cd048
a00ce06c:  90 10 20 00  clr  %o0
a00ce070:  10 bf fb f6  b  0xa00cd048
a00ce074:  90 10 20 00  clr  %o0
a00ce078:  7f ff d9 97  call  0xa00c46d4
a00ce07c:  90 10 00 18  mov  %i0, %o0
a00ce080:  10 bf fb f3  b  0xa00cd04c
a00ce084:  80 a6 60 8c  cmp  %i1, 0x8c
a00ce088:  7f ff d2 54  call  0xa00c29d8
a00ce08c:  90 10 00 18  mov  %i0, %o0
a00ce090:  10 bf fb ef  b  0xa00cd04c
a00ce094:  80 a6 60 8c  cmp  %i1, 0x8c
a00ce098:  1b 2a 00 b5  sethi  %hi(0xa802d400), %o5
a00ce09c:  7f ff aa 0c  call  0xa00b88cc
a00ce0a0:  d0 2b 60 1b  stb  %o0, [ %o5 + 0x1b ]	! 0xa802d41b
a00ce0a4:  7f ff b2 72  call  0xa00baa6c
a00ce0a8:  90 10 00 18  mov  %i0, %o0
a00ce0ac:  7f ff b2 29  call  0xa00ba950
a00ce0b0:  90 10 00 18  mov  %i0, %o0
a00ce0b4:  90 10 00 18  mov  %i0, %o0
a00ce0b8:  7f ff b2 b2  call  0xa00bab80
a00ce0bc:  92 10 20 06  mov  6, %o1
a00ce0c0:  82 10 20 00  clr  %g1
a00ce0c4:  10 bf fb e1  b  0xa00cd048
a00ce0c8:  90 10 00 01  mov  %g1, %o0
a00ce0cc:  03 2a 00 b5  sethi  %hi(0xa802d400), %g1
a00ce0d0:  7f ff a9 ff  call  0xa00b88cc
a00ce0d4:  d0 28 60 1c  stb  %o0, [ %g1 + 0x1c ]	! 0xa802d41c
a00ce0d8:  7f ff b2 65  call  0xa00baa6c
a00ce0dc:  90 10 00 18  mov  %i0, %o0
a00ce0e0:  7f ff b2 1c  call  0xa00ba950
a00ce0e4:  90 10 00 18  mov  %i0, %o0
a00ce0e8:  90 10 00 18  mov  %i0, %o0
a00ce0ec:  7f ff b2 a5  call  0xa00bab80
a00ce0f0:  92 10 20 06  mov  6, %o1
a00ce0f4:  82 10 20 00  clr  %g1
a00ce0f8:  10 bf fb d4  b  0xa00cd048
a00ce0fc:  90 10 00 01  mov  %g1, %o0
a00ce100:  19 2a 00 b5  sethi  %hi(0xa802d400), %o4
a00ce104:  7f ff a9 f2  call  0xa00b88cc
a00ce108:  d0 2b 20 1d  stb  %o0, [ %o4 + 0x1d ]	! 0xa802d41d
a00ce10c:  7f ff b2 58  call  0xa00baa6c
a00ce110:  90 10 00 18  mov  %i0, %o0
a00ce114:  7f ff b2 0f  call  0xa00ba950
a00ce118:  90 10 00 18  mov  %i0, %o0
a00ce11c:  90 10 00 18  mov  %i0, %o0
a00ce120:  7f ff b2 98  call  0xa00bab80
a00ce124:  92 10 20 06  mov  6, %o1
a00ce128:  82 10 20 00  clr  %g1
a00ce12c:  10 bf fb c7  b  0xa00cd048
a00ce130:  90 10 00 01  mov  %g1, %o0
a00ce134:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00ce138:  10 bf fe bc  b  0xa00cdc28
a00ce13c:  c2 0a 20 49  ldub  [ %o0 + 0x49 ], %g1	! 0xa802d049
a00ce140:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00ce144:  10 bf fe fe  b  0xa00cdd3c
a00ce148:  c2 0a a0 49  ldub  [ %o2 + 0x49 ], %g1	! 0xa802d049
a00ce14c:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00ce150:  10 bf ff 19  b  0xa00cddb4
a00ce154:  c2 0a 60 49  ldub  [ %o1 + 0x49 ], %g1	! 0xa802d049
a00ce158:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00ce15c:  10 bf ff 53  b  0xa00cdea8
a00ce160:  c2 0a e0 49  ldub  [ %o3 + 0x49 ], %g1	! 0xa802d049
a00ce164:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a00ce168:  10 bf fe db  b  0xa00cdcd4
a00ce16c:  c2 0b 60 49  ldub  [ %o5 + 0x49 ], %g1	! 0xa802d049
a00ce170:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00ce174:  10 bf ff 84  b  0xa00cdf84
a00ce178:  c2 0a 20 49  ldub  [ %o0 + 0x49 ], %g1	! 0xa802d049
a00ce17c:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a00ce180:  10 bf fe 8b  b  0xa00cdbac
a00ce184:  da 0b e0 49  ldub  [ %o7 + 0x49 ], %o5	! 0xa802d049
a00ce188:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00ce18c:  10 bf fd e7  b  0xa00cd928
a00ce190:  c2 08 60 49  ldub  [ %g1 + 0x49 ], %g1	! 0xa802d049
a00ce194:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00ce198:  10 bf fc e9  b  0xa00cd53c
a00ce19c:  c2 0b 20 49  ldub  [ %o4 + 0x49 ], %g1	! 0xa802d049
a00ce1a0:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a00ce1a4:  10 bf fd 46  b  0xa00cd6bc
a00ce1a8:  c2 0b e0 49  ldub  [ %o7 + 0x49 ], %g1	! 0xa802d049
a00ce1ac:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00ce1b0:  10 bf fc c7  b  0xa00cd4cc
a00ce1b4:  c2 0a 20 49  ldub  [ %o0 + 0x49 ], %g1	! 0xa802d049
a00ce1b8:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00ce1bc:  10 bf fc 9d  b  0xa00cd430
a00ce1c0:  c2 0a e0 49  ldub  [ %o3 + 0x49 ], %g1	! 0xa802d049
a00ce1c4:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00ce1c8:  10 bf fc fb  b  0xa00cd5b4
a00ce1cc:  c2 0a a0 49  ldub  [ %o2 + 0x49 ], %g1	! 0xa802d049
a00ce1d0:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00ce1d4:  10 bf fd a8  b  0xa00cd874
a00ce1d8:  c2 0a 20 49  ldub  [ %o0 + 0x49 ], %g1	! 0xa802d049
a00ce1dc:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00ce1e0:  10 bf ff 18  b  0xa00cde40
a00ce1e4:  c2 0a a0 49  ldub  [ %o2 + 0x49 ], %g1	! 0xa802d049
a00ce1e8:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00ce1ec:  10 bf fc 76  b  0xa00cd3c4
a00ce1f0:  c2 0a 60 49  ldub  [ %o1 + 0x49 ], %g1	! 0xa802d049
a00ce1f4:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00ce1f8:  10 bf fd 66  b  0xa00cd790
a00ce1fc:  c2 0a 20 49  ldub  [ %o0 + 0x49 ], %g1	! 0xa802d049
a00ce200:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00ce204:  10 bf fd 0e  b  0xa00cd63c
a00ce208:  c2 0a 60 49  ldub  [ %o1 + 0x49 ], %g1	! 0xa802d049
a00ce20c:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00ce210:  10 bf fc 52  b  0xa00cd358
a00ce214:  c2 0a e0 49  ldub  [ %o3 + 0x49 ], %g1	! 0xa802d049
a00ce218:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00ce21c:  10 bf fc 25  b  0xa00cd2b0
a00ce220:  c2 0b 20 49  ldub  [ %o4 + 0x49 ], %g1	! 0xa802d049
a00ce224:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00ce228:  10 bf fb d5  b  0xa00cd17c
a00ce22c:  c2 08 60 49  ldub  [ %g1 + 0x49 ], %g1	! 0xa802d049
a00ce230:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00ce234:  10 bf fb f3  b  0xa00cd200
a00ce238:  c2 0a a0 49  ldub  [ %o2 + 0x49 ], %g1	! 0xa802d049
a00ce23c:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00ce240:  10 bf fb f0  b  0xa00cd200
a00ce244:  c2 08 60 a1  ldub  [ %g1 + 0xa1 ], %g1	! 0xa802d0a1
a00ce248:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a00ce24c:  10 bf fc 19  b  0xa00cd2b0
a00ce250:  c2 0b 60 a1  ldub  [ %o5 + 0xa1 ], %g1	! 0xa802d0a1
a00ce254:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00ce258:  10 bf fb c9  b  0xa00cd17c
a00ce25c:  c2 0a a0 a1  ldub  [ %o2 + 0xa1 ], %g1	! 0xa802d0a1
a00ce260:  10 bf fc 59  b  0xa00cd3c4
a00ce264:  c2 0b e0 a1  ldub  [ %o7 + 0xa1 ], %g1
a00ce268:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00ce26c:  10 bf fd 49  b  0xa00cd790
a00ce270:  c2 0a e0 a1  ldub  [ %o3 + 0xa1 ], %g1	! 0xa802d0a1
a00ce274:  10 bf fc f2  b  0xa00cd63c
a00ce278:  c2 0b e0 a1  ldub  [ %o7 + 0xa1 ], %g1
a00ce27c:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00ce280:  10 bf fc 36  b  0xa00cd358
a00ce284:  c2 0b 20 a1  ldub  [ %o4 + 0xa1 ], %g1	! 0xa802d0a1
a00ce288:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00ce28c:  10 bf fe 67  b  0xa00cdc28
a00ce290:  c2 08 60 a1  ldub  [ %g1 + 0xa1 ], %g1	! 0xa802d0a1
a00ce294:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00ce298:  10 bf fe a9  b  0xa00cdd3c
a00ce29c:  c2 0a e0 a1  ldub  [ %o3 + 0xa1 ], %g1	! 0xa802d0a1
a00ce2a0:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00ce2a4:  10 bf fe c4  b  0xa00cddb4
a00ce2a8:  c2 0a a0 a1  ldub  [ %o2 + 0xa1 ], %g1	! 0xa802d0a1
a00ce2ac:  10 bf fe ff  b  0xa00cdea8
a00ce2b0:  c2 0b 20 a1  ldub  [ %o4 + 0xa1 ], %g1
a00ce2b4:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00ce2b8:  10 bf fe 87  b  0xa00cdcd4
a00ce2bc:  c2 0a 60 a1  ldub  [ %o1 + 0xa1 ], %g1	! 0xa802d0a1
a00ce2c0:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00ce2c4:  10 bf ff 30  b  0xa00cdf84
a00ce2c8:  c2 08 60 a1  ldub  [ %g1 + 0xa1 ], %g1	! 0xa802d0a1
a00ce2cc:  10 bf fe 38  b  0xa00cdbac
a00ce2d0:  da 0b 20 a1  ldub  [ %o4 + 0xa1 ], %o5
a00ce2d4:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00ce2d8:  10 bf fd 94  b  0xa00cd928
a00ce2dc:  c2 0a a0 a1  ldub  [ %o2 + 0xa1 ], %g1	! 0xa802d0a1
a00ce2e0:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00ce2e4:  10 bf fc 96  b  0xa00cd53c
a00ce2e8:  c2 08 60 a1  ldub  [ %g1 + 0xa1 ], %g1	! 0xa802d0a1
a00ce2ec:  10 bf fc f4  b  0xa00cd6bc
a00ce2f0:  c2 0b 60 a1  ldub  [ %o5 + 0xa1 ], %g1
a00ce2f4:  10 bf fc 76  b  0xa00cd4cc
a00ce2f8:  c2 0b 20 a1  ldub  [ %o4 + 0xa1 ], %g1
a00ce2fc:  10 bf fc 4d  b  0xa00cd430
a00ce300:  c2 0b 20 a1  ldub  [ %o4 + 0xa1 ], %g1
a00ce304:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00ce308:  10 bf fc ab  b  0xa00cd5b4
a00ce30c:  c2 0a 60 a1  ldub  [ %o1 + 0xa1 ], %g1	! 0xa802d0a1
a00ce310:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00ce314:  10 bf fd 58  b  0xa00cd874
a00ce318:  c2 08 60 a1  ldub  [ %g1 + 0xa1 ], %g1	! 0xa802d0a1
a00ce31c:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a00ce320:  10 bf fe c8  b  0xa00cde40
a00ce324:  c2 0b e0 a1  ldub  [ %o7 + 0xa1 ], %g1	! 0xa802d0a1
a00ce328:  9e 13 22 90  or  %o4, 0x290, %o7
a00ce32c:  90 10 24 02  mov  0x402, %o0
a00ce330:  9a 10 27 50  mov  0x750, %o5
a00ce334:  d0 33 e1 ae  sth  %o0, [ %o7 + 0x1ae ]
a00ce338:  10 bf fc 8a  b  0xa00cd560
a00ce33c:  da 33 e1 ac  sth  %o5, [ %o7 + 0x1ac ]
a00ce340:  81 c7 e0 08  ret
a00ce344:  81 e8 00 00  restore
