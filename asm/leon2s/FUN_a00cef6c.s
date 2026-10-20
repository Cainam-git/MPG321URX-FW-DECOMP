# leon2s FUN_a00cef6c 0xa00cef6c-0xa00cf6bc (1872 bytes)
a00cef6c:  9d e3 bf 78  save  %sp, -136, %sp
a00cef70:  a6 0e 20 ff  and  %i0, 0xff, %l3
a00cef74:  82 04 c0 13  add  %l3, %l3, %g1
a00cef78:  82 00 40 13  add  %g1, %l3, %g1
a00cef7c:  a1 28 60 03  sll  %g1, 3, %l0
a00cef80:  03 3f ff 3f  sethi  %hi(0xfffcfc00), %g1
a00cef84:  2d 2a 01 e2  sethi  %hi(0xa8078800), %l6
a00cef88:  a2 15 a3 b0  or  %l6, 0x3b0, %l1	! 0xa8078bb0
a00cef8c:  aa 10 63 ff  or  %g1, 0x3ff, %l5
a00cef90:  c2 04 40 10  ld  [ %l1 + %l0 ], %g1
a00cef94:  1b 00 00 40  sethi  %hi(0x10000), %o5
a00cef98:  82 08 40 15  and  %g1, %l5, %g1
a00cef9c:  82 10 40 0d  or  %g1, %o5, %g1
a00cefa0:  c2 24 40 10  st  %g1, [ %l1 + %l0 ]
a00cefa4:  7f ff c6 98  call  0xa00c0a04
a00cefa8:  90 10 00 13  mov  %l3, %o0
a00cefac:  80 8a 20 ff  btst  0xff, %o0
a00cefb0:  32 80 00 14  bne,a   0xa00cf000
a00cefb4:  c2 04 40 10  ld  [ %l1 + %l0 ], %g1
a00cefb8:  a4 07 bf e8  add  %fp, -24, %l2
a00cefbc:  29 00 01 a5  sethi  %hi(0x69400), %l4
a00cefc0:  92 10 20 90  mov  0x90, %o1
a00cefc4:  90 10 20 00  clr  %o0
a00cefc8:  94 15 20 93  or  %l4, 0x93, %o2
a00cefcc:  96 10 20 00  clr  %o3
a00cefd0:  40 3b 1d 0c  call  0xa0f96400
a00cefd4:  98 10 00 12  mov  %l2, %o4
a00cefd8:  d2 0f bf e8  ldub  [ %fp + -24 ], %o1
a00cefdc:  80 8a 60 08  btst  8, %o1
a00cefe0:  02 80 00 05  be  0xa00ceff4
a00cefe4:  80 8a 60 01  btst  1, %o1
a00cefe8:  c2 04 40 10  ld  [ %l1 + %l0 ], %g1
a00cefec:  10 80 00 07  b  0xa00cf008
a00ceff0:  82 08 40 15  and  %g1, %l5, %g1
a00ceff4:  12 80 00 07  bne  0xa00cf010
a00ceff8:  11 27 c7 08  sethi  %hi(0x9f1c2000), %o0
a00ceffc:  c2 04 40 10  ld  [ %l1 + %l0 ], %g1
a00cf000:  1b 00 00 c0  sethi  %hi(0x30000), %o5
a00cf004:  82 10 40 0d  or  %g1, %o5, %g1
a00cf008:  10 80 01 ab  b  0xa00cf6b4
a00cf00c:  c2 24 40 10  st  %g1, [ %l1 + %l0 ]
a00cf010:  40 3a d0 0d  call  0xa0f83044
a00cf014:  90 12 21 90  or  %o0, 0x190, %o0
a00cf018:  94 15 20 93  or  %l4, 0x93, %o2
a00cf01c:  98 10 00 12  mov  %l2, %o4
a00cf020:  92 10 20 90  mov  0x90, %o1
a00cf024:  96 10 20 00  clr  %o3
a00cf028:  40 3b 1c f6  call  0xa0f96400
a00cf02c:  90 10 20 00  clr  %o0
a00cf030:  15 00 01 a4  sethi  %hi(0x69000), %o2
a00cf034:  94 12 a3 30  or  %o2, 0x330, %o2	! 0x69330
a00cf038:  98 10 00 12  mov  %l2, %o4
a00cf03c:  90 10 20 00  clr  %o0
a00cf040:  92 10 20 90  mov  0x90, %o1
a00cf044:  40 3b 1c ef  call  0xa0f96400
a00cf048:  96 10 20 04  mov  4, %o3
a00cf04c:  39 2a 01 f3  sethi  %hi(0xa807cc00), %i4
a00cf050:  a4 10 20 00  clr  %l2
a00cf054:  94 17 22 50  or  %i4, 0x250, %o2
a00cf058:  a8 07 bf f8  add  %fp, -8, %l4
a00cf05c:  99 2c a0 10  sll  %l2, 0x10, %o4
a00cf060:  99 33 20 10  srl  %o4, 0x10, %o4
a00cf064:  96 04 a0 01  add  %l2, 1, %o3
a00cf068:  9b 2a e0 10  sll  %o3, 0x10, %o5
a00cf06c:  82 05 00 0c  add  %l4, %o4, %g1
a00cf070:  c2 08 7f f0  ldub  [ %g1 + -16 ], %g1
a00cf074:  9b 33 60 10  srl  %o5, 0x10, %o5
a00cf078:  c2 2a 80 0c  stb  %g1, [ %o2 + %o4 ]
a00cf07c:  80 a3 60 04  cmp  %o5, 4
a00cf080:  08 bf ff f7  bleu  0xa00cf05c
a00cf084:  a4 10 00 0b  mov  %o3, %l2
a00cf088:  82 04 c0 13  add  %l3, %l3, %g1
a00cf08c:  82 00 40 13  add  %g1, %l3, %g1
a00cf090:  99 28 60 03  sll  %g1, 3, %o4
a00cf094:  96 15 a3 b0  or  %l6, 0x3b0, %o3
a00cf098:  82 03 00 0b  add  %o4, %o3, %g1
a00cf09c:  da 00 60 0c  ld  [ %g1 + 0xc ], %o5
a00cf0a0:  03 00 3f ff  sethi  %hi(0xfffc00), %g1
a00cf0a4:  82 10 63 ff  or  %g1, 0x3ff, %g1	! 0xffffff
a00cf0a8:  80 a3 40 01  cmp  %o5, %g1
a00cf0ac:  12 80 00 13  bne  0xa00cf0f8
a00cf0b0:  82 04 c0 13  add  %l3, %l3, %g1
a00cf0b4:  c2 0f bf ea  ldub  [ %fp + -22 ], %g1
a00cf0b8:  80 a0 60 00  cmp  %g1, 0
a00cf0bc:  12 80 00 0f  bne  0xa00cf0f8
a00cf0c0:  82 04 c0 13  add  %l3, %l3, %g1
a00cf0c4:  c2 0f bf eb  ldub  [ %fp + -21 ], %g1
a00cf0c8:  80 a0 60 00  cmp  %g1, 0
a00cf0cc:  12 80 00 0b  bne  0xa00cf0f8
a00cf0d0:  82 04 c0 13  add  %l3, %l3, %g1
a00cf0d4:  c2 0f bf ec  ldub  [ %fp + -20 ], %g1
a00cf0d8:  80 a0 60 00  cmp  %g1, 0
a00cf0dc:  12 80 00 07  bne  0xa00cf0f8
a00cf0e0:  82 04 c0 13  add  %l3, %l3, %g1
a00cf0e4:  da 02 c0 0c  ld  [ %o3 + %o4 ], %o5
a00cf0e8:  03 00 00 c0  sethi  %hi(0x30000), %g1
a00cf0ec:  82 2b 40 01  andn  %o5, %g1, %g1
a00cf0f0:  10 80 01 71  b  0xa00cf6b4
a00cf0f4:  c2 22 c0 0c  st  %g1, [ %o3 + %o4 ]
a00cf0f8:  82 00 40 13  add  %g1, %l3, %g1
a00cf0fc:  83 28 60 03  sll  %g1, 3, %g1
a00cf100:  9a 15 a3 b0  or  %l6, 0x3b0, %o5
a00cf104:  82 00 40 0d  add  %g1, %o5, %g1
a00cf108:  c2 00 60 0c  ld  [ %g1 + 0xc ], %g1
a00cf10c:  80 a0 60 00  cmp  %g1, 0
a00cf110:  12 80 00 11  bne  0xa00cf154
a00cf114:  c2 0f bf ea  ldub  [ %fp + -22 ], %g1
a00cf118:  80 a0 60 00  cmp  %g1, 0
a00cf11c:  12 80 00 0b  bne  0xa00cf148
a00cf120:  9a 04 c0 13  add  %l3, %l3, %o5
a00cf124:  c2 0f bf eb  ldub  [ %fp + -21 ], %g1
a00cf128:  80 a0 60 00  cmp  %g1, 0
a00cf12c:  12 80 00 08  bne  0xa00cf14c
a00cf130:  9a 03 40 13  add  %o5, %l3, %o5
a00cf134:  c2 0f bf ec  ldub  [ %fp + -20 ], %g1
a00cf138:  80 a0 60 00  cmp  %g1, 0
a00cf13c:  02 80 00 06  be  0xa00cf154
a00cf140:  c2 0f bf ea  ldub  [ %fp + -22 ], %g1
a00cf144:  9a 04 c0 13  add  %l3, %l3, %o5
a00cf148:  9a 03 40 13  add  %o5, %l3, %o5
a00cf14c:  10 80 00 d6  b  0xa00cf4a4
a00cf150:  96 15 a3 b0  or  %l6, 0x3b0, %o3
a00cf154:  da 0f bf eb  ldub  [ %fp + -21 ], %o5
a00cf158:  9b 2b 60 08  sll  %o5, 8, %o5
a00cf15c:  98 04 c0 13  add  %l3, %l3, %o4
a00cf160:  83 28 60 10  sll  %g1, 0x10, %g1
a00cf164:  82 10 40 0d  or  %g1, %o5, %g1
a00cf168:  98 03 00 13  add  %o4, %l3, %o4
a00cf16c:  da 0f bf ec  ldub  [ %fp + -20 ], %o5
a00cf170:  99 2b 20 03  sll  %o4, 3, %o4
a00cf174:  96 15 a3 b0  or  %l6, 0x3b0, %o3
a00cf178:  82 10 40 0d  or  %g1, %o5, %g1
a00cf17c:  98 03 00 0b  add  %o4, %o3, %o4
a00cf180:  80 a0 60 00  cmp  %g1, 0
a00cf184:  12 80 00 04  bne  0xa00cf194
a00cf188:  c2 23 20 0c  st  %g1, [ %o4 + 0xc ]
a00cf18c:  82 10 20 01  mov  1, %g1
a00cf190:  c2 23 20 0c  st  %g1, [ %o4 + 0xc ]
a00cf194:  ba 07 bf d8  add  %fp, -40, %i5
a00cf198:  15 00 01 a4  sethi  %hi(0x69000), %o2
a00cf19c:  94 12 a3 35  or  %o2, 0x335, %o2	! 0x69335
a00cf1a0:  90 10 20 00  clr  %o0
a00cf1a4:  92 10 20 90  mov  0x90, %o1
a00cf1a8:  96 10 20 0f  mov  0xf, %o3
a00cf1ac:  40 3b 1c 95  call  0xa0f96400
a00cf1b0:  98 10 00 1d  mov  %i5, %o4
a00cf1b4:  37 2a 01 f3  sethi  %hi(0xa807cc00), %i3
a00cf1b8:  a4 10 20 00  clr  %l2
a00cf1bc:  94 16 e1 88  or  %i3, 0x188, %o2
a00cf1c0:  99 2c a0 10  sll  %l2, 0x10, %o4
a00cf1c4:  99 33 20 10  srl  %o4, 0x10, %o4
a00cf1c8:  96 04 a0 01  add  %l2, 1, %o3
a00cf1cc:  9b 2a e0 10  sll  %o3, 0x10, %o5
a00cf1d0:  82 05 00 0c  add  %l4, %o4, %g1
a00cf1d4:  c2 08 7f e0  ldub  [ %g1 + -32 ], %g1
a00cf1d8:  9b 33 60 10  srl  %o5, 0x10, %o5
a00cf1dc:  c2 2a 80 0c  stb  %g1, [ %o2 + %o4 ]
a00cf1e0:  80 a3 60 0f  cmp  %o5, 0xf
a00cf1e4:  08 bf ff f7  bleu  0xa00cf1c0
a00cf1e8:  a4 10 00 0b  mov  %o3, %l2
a00cf1ec:  90 10 00 13  mov  %l3, %o0
a00cf1f0:  92 10 20 0b  mov  0xb, %o1
a00cf1f4:  7f ff e5 7d  call  0xa00c87e8
a00cf1f8:  15 00 00 20  sethi  %hi(0x8000), %o2
a00cf1fc:  a4 10 20 00  clr  %l2
a00cf200:  90 10 00 13  mov  %l3, %o0
a00cf204:  92 10 20 01  mov  1, %o1
a00cf208:  7f ff e1 13  call  0xa00c7654
a00cf20c:  94 10 20 00  clr  %o2
a00cf210:  9a 04 a0 01  add  %l2, 1, %o5
a00cf214:  83 2b 60 10  sll  %o5, 0x10, %g1
a00cf218:  83 30 60 10  srl  %g1, 0x10, %g1
a00cf21c:  80 a0 60 b5  cmp  %g1, 0xb5
a00cf220:  08 bf ff f8  bleu  0xa00cf200
a00cf224:  a4 10 00 0d  mov  %o5, %l2
a00cf228:  90 10 00 13  mov  %l3, %o0
a00cf22c:  92 10 20 0b  mov  0xb, %o1
a00cf230:  7f ff e5 6e  call  0xa00c87e8
a00cf234:  15 00 00 20  sethi  %hi(0x8000), %o2
a00cf238:  a4 10 20 00  clr  %l2
a00cf23c:  83 2c a0 10  sll  %l2, 0x10, %g1
a00cf240:  83 30 60 10  srl  %g1, 0x10, %g1
a00cf244:  82 05 00 01  add  %l4, %g1, %g1
a00cf248:  d4 08 7f f0  ldub  [ %g1 + -16 ], %o2
a00cf24c:  90 10 00 13  mov  %l3, %o0
a00cf250:  7f ff e1 01  call  0xa00c7654
a00cf254:  92 10 20 01  mov  1, %o1
a00cf258:  9a 04 a0 01  add  %l2, 1, %o5
a00cf25c:  83 2b 60 10  sll  %o5, 0x10, %g1
a00cf260:  83 30 60 10  srl  %g1, 0x10, %g1
a00cf264:  80 a0 60 04  cmp  %g1, 4
a00cf268:  08 bf ff f5  bleu  0xa00cf23c
a00cf26c:  a4 10 00 0d  mov  %o5, %l2
a00cf270:  c2 0f bf e8  ldub  [ %fp + -24 ], %g1
a00cf274:  82 08 60 01  and  %g1, 1, %g1
a00cf278:  da 0f bf e9  ldub  [ %fp + -23 ], %o5
a00cf27c:  83 28 60 04  sll  %g1, 4, %g1
a00cf280:  9b 33 60 04  srl  %o5, 4, %o5
a00cf284:  ae 00 40 0d  add  %g1, %o5, %l7
a00cf288:  a6 0d e0 ff  and  %l7, 0xff, %l3
a00cf28c:  03 00 01 a4  sethi  %hi(0x69000), %g1
a00cf290:  aa 10 63 45  or  %g1, 0x345, %l5	! 0x69345
a00cf294:  80 a4 e0 00  cmp  %l3, 0
a00cf298:  02 80 00 2a  be  0xa00cf340
a00cf29c:  a4 10 20 00  clr  %l2
a00cf2a0:  83 2c a0 10  sll  %l2, 0x10, %g1
a00cf2a4:  83 30 60 10  srl  %g1, 0x10, %g1
a00cf2a8:  a1 28 60 02  sll  %g1, 2, %l0
a00cf2ac:  a0 04 00 01  add  %l0, %g1, %l0
a00cf2b0:  94 05 40 10  add  %l5, %l0, %o2
a00cf2b4:  92 10 20 90  mov  0x90, %o1
a00cf2b8:  96 10 20 04  mov  4, %o3
a00cf2bc:  98 10 00 1d  mov  %i5, %o4
a00cf2c0:  40 3b 1c 50  call  0xa0f96400
a00cf2c4:  90 10 20 00  clr  %o0
a00cf2c8:  03 00 00 10  sethi  %hi(0x4000), %g1
a00cf2cc:  82 10 60 15  or  %g1, 0x15, %g1	! 0x4015
a00cf2d0:  a0 04 00 01  add  %l0, %g1, %l0
a00cf2d4:  a1 2c 20 10  sll  %l0, 0x10, %l0
a00cf2d8:  a2 0e 20 ff  and  %i0, 0xff, %l1
a00cf2dc:  95 34 20 10  srl  %l0, 0x10, %o2
a00cf2e0:  90 10 00 11  mov  %l1, %o0
a00cf2e4:  7f ff e5 41  call  0xa00c87e8
a00cf2e8:  92 10 20 0b  mov  0xb, %o1
a00cf2ec:  a0 10 20 00  clr  %l0
a00cf2f0:  83 2c 20 10  sll  %l0, 0x10, %g1
a00cf2f4:  83 30 60 10  srl  %g1, 0x10, %g1
a00cf2f8:  82 05 00 01  add  %l4, %g1, %g1
a00cf2fc:  d4 08 7f e0  ldub  [ %g1 + -32 ], %o2
a00cf300:  90 10 00 11  mov  %l1, %o0
a00cf304:  7f ff e0 d4  call  0xa00c7654
a00cf308:  92 10 20 01  mov  1, %o1
a00cf30c:  9a 04 20 01  add  %l0, 1, %o5
a00cf310:  83 2b 60 10  sll  %o5, 0x10, %g1
a00cf314:  83 30 60 10  srl  %g1, 0x10, %g1
a00cf318:  80 a0 60 04  cmp  %g1, 4
a00cf31c:  08 bf ff f5  bleu  0xa00cf2f0
a00cf320:  a0 10 00 0d  mov  %o5, %l0
a00cf324:  82 04 a0 01  add  %l2, 1, %g1
a00cf328:  9b 28 60 10  sll  %g1, 0x10, %o5
a00cf32c:  9b 33 60 10  srl  %o5, 0x10, %o5
a00cf330:  98 0c e0 3f  and  %l3, 0x3f, %o4
a00cf334:  80 a3 40 0c  cmp  %o5, %o4
a00cf338:  0a bf ff da  bcs  0xa00cf2a0
a00cf33c:  a4 10 00 01  mov  %g1, %l2
a00cf340:  a4 10 20 00  clr  %l2
a00cf344:  83 2c a0 10  sll  %l2, 0x10, %g1
a00cf348:  83 30 60 10  srl  %g1, 0x10, %g1
a00cf34c:  9a 17 22 50  or  %i4, 0x250, %o5
a00cf350:  a2 0e 20 ff  and  %i0, 0xff, %l1
a00cf354:  d4 0b 40 01  ldub  [ %o5 + %g1 ], %o2
a00cf358:  90 10 00 11  mov  %l1, %o0
a00cf35c:  7f ff e0 be  call  0xa00c7654
a00cf360:  92 10 20 01  mov  1, %o1
a00cf364:  9a 04 a0 01  add  %l2, 1, %o5
a00cf368:  83 2b 60 10  sll  %o5, 0x10, %g1
a00cf36c:  83 30 60 10  srl  %g1, 0x10, %g1
a00cf370:  80 a0 60 04  cmp  %g1, 4
a00cf374:  08 bf ff f4  bleu  0xa00cf344
a00cf378:  a4 10 00 0d  mov  %o5, %l2
a00cf37c:  90 10 00 11  mov  %l1, %o0
a00cf380:  92 10 20 01  mov  1, %o1
a00cf384:  7f ff e0 b4  call  0xa00c7654
a00cf388:  94 10 20 80  mov  0x80, %o2
a00cf38c:  90 10 00 11  mov  %l1, %o0
a00cf390:  92 10 20 02  mov  2, %o1
a00cf394:  7f ff e0 b0  call  0xa00c7654
a00cf398:  94 10 20 00  clr  %o2
a00cf39c:  90 10 00 11  mov  %l1, %o0
a00cf3a0:  92 10 20 06  mov  6, %o1
a00cf3a4:  7f ff e0 ac  call  0xa00c7654
a00cf3a8:  94 10 20 e0  mov  0xe0, %o2
a00cf3ac:  90 10 00 11  mov  %l1, %o0
a00cf3b0:  7f ff e0 f0  call  0xa00c7770
a00cf3b4:  92 10 20 06  mov  6, %o1
a00cf3b8:  80 8a 20 80  btst  0x80, %o0
a00cf3bc:  32 bf ff fd  bne,a   0xa00cf3b0
a00cf3c0:  90 10 00 11  mov  %l1, %o0
a00cf3c4:  d2 0f bf e9  ldub  [ %fp + -23 ], %o1
a00cf3c8:  94 0a 60 ff  and  %o1, 0xff, %o2
a00cf3cc:  80 8a a0 0c  btst  0xc, %o2
a00cf3d0:  02 80 00 0d  be  0xa00cf404
a00cf3d4:  da 0f bf e8  ldub  [ %fp + -24 ], %o5
a00cf3d8:  98 04 40 11  add  %l1, %l1, %o4
a00cf3dc:  98 03 00 11  add  %o4, %l1, %o4
a00cf3e0:  96 15 a3 b0  or  %l6, 0x3b0, %o3
a00cf3e4:  99 2b 20 03  sll  %o4, 3, %o4
a00cf3e8:  da 02 c0 0c  ld  [ %o3 + %o4 ], %o5
a00cf3ec:  03 00 00 c0  sethi  %hi(0x30000), %g1
a00cf3f0:  82 2b 40 01  andn  %o5, %g1, %g1
a00cf3f4:  1b 00 00 80  sethi  %hi(0x20000), %o5
a00cf3f8:  82 10 40 0d  or  %g1, %o5, %g1
a00cf3fc:  c2 22 c0 0c  st  %g1, [ %o3 + %o4 ]
a00cf400:  da 0f bf e8  ldub  [ %fp + -24 ], %o5
a00cf404:  80 8b 60 01  btst  1, %o5
a00cf408:  02 80 00 12  be  0xa00cf450
a00cf40c:  d8 0f bf e9  ldub  [ %fp + -23 ], %o4
a00cf410:  82 0a a0 f0  and  %o2, 0xf0, %g1
a00cf414:  80 a0 60 f0  cmp  %g1, 0xf0
a00cf418:  12 80 00 0f  bne  0xa00cf454
a00cf41c:  82 0b 20 f0  and  %o4, 0xf0, %g1
a00cf420:  82 0e 20 ff  and  %i0, 0xff, %g1
a00cf424:  9a 00 40 01  add  %g1, %g1, %o5
a00cf428:  9a 03 40 01  add  %o5, %g1, %o5
a00cf42c:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a00cf430:  82 10 63 b0  or  %g1, 0x3b0, %g1	! 0xa8078bb0
a00cf434:  9b 2b 60 03  sll  %o5, 3, %o5
a00cf438:  9a 03 40 01  add  %o5, %g1, %o5
a00cf43c:  82 10 20 01  mov  1, %g1
a00cf440:  98 12 60 08  or  %o1, 8, %o4
a00cf444:  c2 2b 60 05  stb  %g1, [ %o5 + 5 ]
a00cf448:  10 80 00 0c  b  0xa00cf478
a00cf44c:  d8 2f bf e9  stb  %o4, [ %fp + -23 ]
a00cf450:  82 0b 20 f0  and  %o4, 0xf0, %g1
a00cf454:  80 a0 60 f0  cmp  %g1, 0xf0
a00cf458:  12 80 00 07  bne  0xa00cf474
a00cf45c:  82 03 20 10  add  %o4, 0x10, %g1
a00cf460:  82 0b 20 0f  and  %o4, 0xf, %g1
a00cf464:  9a 13 60 01  or  %o5, 1, %o5
a00cf468:  c2 2f bf e9  stb  %g1, [ %fp + -23 ]
a00cf46c:  10 80 00 03  b  0xa00cf478
a00cf470:  da 2f bf e8  stb  %o5, [ %fp + -24 ]
a00cf474:  c2 2f bf e9  stb  %g1, [ %fp + -23 ]
a00cf478:  d8 0f bf e8  ldub  [ %fp + -24 ], %o4
a00cf47c:  82 0b 20 0e  and  %o4, 0xe, %g1
a00cf480:  80 a0 60 07  cmp  %g1, 7
a00cf484:  14 80 00 0e  bg  0xa00cf4bc
a00cf488:  82 0e 20 ff  and  %i0, 0xff, %g1
a00cf48c:  82 03 20 02  add  %o4, 2, %g1
a00cf490:  10 80 00 15  b  0xa00cf4e4
a00cf494:  c2 2f bf e8  stb  %g1, [ %fp + -24 ]
a00cf498:  9a 04 c0 13  add  %l3, %l3, %o5
a00cf49c:  9a 03 40 13  add  %o5, %l3, %o5
a00cf4a0:  96 15 63 b0  or  %l5, 0x3b0, %o3
a00cf4a4:  9b 2b 60 03  sll  %o5, 3, %o5
a00cf4a8:  d8 02 c0 0d  ld  [ %o3 + %o5 ], %o4
a00cf4ac:  03 00 00 c0  sethi  %hi(0x30000), %g1
a00cf4b0:  82 2b 00 01  andn  %o4, %g1, %g1
a00cf4b4:  10 80 00 80  b  0xa00cf6b4
a00cf4b8:  c2 22 c0 0d  st  %g1, [ %o3 + %o5 ]
a00cf4bc:  9a 00 40 01  add  %g1, %g1, %o5
a00cf4c0:  9a 03 40 01  add  %o5, %g1, %o5
a00cf4c4:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a00cf4c8:  82 10 63 b0  or  %g1, 0x3b0, %g1	! 0xa8078bb0
a00cf4cc:  9b 2b 60 03  sll  %o5, 3, %o5
a00cf4d0:  9a 03 40 01  add  %o5, %g1, %o5
a00cf4d4:  82 10 20 01  mov  1, %g1
a00cf4d8:  98 13 20 04  or  %o4, 4, %o4
a00cf4dc:  c2 2b 60 06  stb  %g1, [ %o5 + 6 ]
a00cf4e0:  d8 2f bf e8  stb  %o4, [ %fp + -24 ]
a00cf4e4:  a6 0e 20 ff  and  %i0, 0xff, %l3
a00cf4e8:  82 04 c0 13  add  %l3, %l3, %g1
a00cf4ec:  e2 0f bf e9  ldub  [ %fp + -23 ], %l1
a00cf4f0:  82 00 40 13  add  %g1, %l3, %g1
a00cf4f4:  2b 2a 01 e2  sethi  %hi(0xa8078800), %l5
a00cf4f8:  d6 0f bf e8  ldub  [ %fp + -24 ], %o3
a00cf4fc:  9a 0c 60 ff  and  %l1, 0xff, %o5
a00cf500:  a5 28 60 03  sll  %g1, 3, %l2
a00cf504:  a8 15 63 b0  or  %l5, 0x3b0, %l4
a00cf508:  82 04 80 14  add  %l2, %l4, %g1
a00cf50c:  94 0a e0 01  and  %o3, 1, %o2
a00cf510:  92 0b 60 08  and  %o5, 8, %o1
a00cf514:  90 0b 60 04  and  %o5, 4, %o0
a00cf518:  98 0b 60 02  and  %o5, 2, %o4
a00cf51c:  de 08 60 05  ldub  [ %g1 + 5 ], %o7
a00cf520:  e0 08 60 06  ldub  [ %g1 + 6 ], %l0
a00cf524:  9b 33 60 04  srl  %o5, 4, %o5
a00cf528:  95 2a a0 04  sll  %o2, 4, %o2
a00cf52c:  96 0a e0 0e  and  %o3, 0xe, %o3
a00cf530:  93 3a 60 03  sra  %o1, 3, %o1
a00cf534:  91 3a 20 02  sra  %o0, 2, %o0
a00cf538:  94 12 80 0d  or  %o2, %o5, %o2
a00cf53c:  92 12 40 0f  or  %o1, %o7, %o1
a00cf540:  90 12 00 10  or  %o0, %l0, %o0
a00cf544:  97 3a e0 01  sra  %o3, 1, %o3
a00cf548:  a2 0c 60 01  and  %l1, 1, %l1
a00cf54c:  99 3b 20 01  sra  %o4, 1, %o4
a00cf550:  d8 28 60 08  stb  %o4, [ %g1 + 8 ]
a00cf554:  d4 28 60 03  stb  %o2, [ %g1 + 3 ]
a00cf558:  d6 28 60 04  stb  %o3, [ %g1 + 4 ]
a00cf55c:  d2 28 60 05  stb  %o1, [ %g1 + 5 ]
a00cf560:  d0 28 60 06  stb  %o0, [ %g1 + 6 ]
a00cf564:  e2 28 60 07  stb  %l1, [ %g1 + 7 ]
a00cf568:  da 05 00 12  ld  [ %l4 + %l2 ], %o5
a00cf56c:  83 33 60 10  srl  %o5, 0x10, %g1
a00cf570:  82 08 60 03  and  %g1, 3, %g1
a00cf574:  80 a0 60 02  cmp  %g1, 2
a00cf578:  02 80 00 23  be  0xa00cf604
a00cf57c:  03 00 00 c0  sethi  %hi(0x30000), %g1
a00cf580:  82 2b 40 01  andn  %o5, %g1, %g1
a00cf584:  1b 00 00 40  sethi  %hi(0x10000), %o5
a00cf588:  82 10 40 0d  or  %g1, %o5, %g1
a00cf58c:  15 00 00 10  sethi  %hi(0x4000), %o2
a00cf590:  c2 25 00 12  st  %g1, [ %l4 + %l2 ]
a00cf594:  94 12 a0 05  or  %o2, 5, %o2
a00cf598:  90 10 00 13  mov  %l3, %o0
a00cf59c:  7f ff e4 93  call  0xa00c87e8
a00cf5a0:  92 10 20 0b  mov  0xb, %o1
a00cf5a4:  a4 10 20 00  clr  %l2
a00cf5a8:  90 10 00 13  mov  %l3, %o0
a00cf5ac:  7f ff e0 71  call  0xa00c7770
a00cf5b0:  92 10 20 01  mov  1, %o1
a00cf5b4:  98 04 a0 01  add  %l2, 1, %o4
a00cf5b8:  83 2b 20 10  sll  %o4, 0x10, %g1
a00cf5bc:  a1 2c a0 10  sll  %l2, 0x10, %l0
a00cf5c0:  97 30 60 10  srl  %g1, 0x10, %o3
a00cf5c4:  a1 34 20 10  srl  %l0, 0x10, %l0
a00cf5c8:  82 16 e1 88  or  %i3, 0x188, %g1
a00cf5cc:  da 08 40 10  ldub  [ %g1 + %l0 ], %o5
a00cf5d0:  a2 07 bf f8  add  %fp, -8, %l1
a00cf5d4:  a2 04 40 10  add  %l1, %l0, %l1
a00cf5d8:  82 0a 20 ff  and  %o0, 0xff, %g1
a00cf5dc:  a4 10 00 0c  mov  %o4, %l2
a00cf5e0:  80 a0 40 0d  cmp  %g1, %o5
a00cf5e4:  12 bf ff ad  bne  0xa00cf498
a00cf5e8:  d0 2c 7f e0  stb  %o0, [ %l1 + -32 ]
a00cf5ec:  80 a2 e0 0f  cmp  %o3, 0xf
a00cf5f0:  08 bf ff ef  bleu  0xa00cf5ac
a00cf5f4:  90 10 00 13  mov  %l3, %o0
a00cf5f8:  92 10 20 02  mov  2, %o1
a00cf5fc:  7f ff e0 16  call  0xa00c7654
a00cf600:  94 10 20 00  clr  %o2
a00cf604:  9a 0d e0 ff  and  %l7, 0xff, %o5
a00cf608:  83 2b 60 02  sll  %o5, 2, %g1
a00cf60c:  15 00 00 10  sethi  %hi(0x4000), %o2
a00cf610:  82 00 40 0d  add  %g1, %o5, %g1
a00cf614:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00cf618:  94 12 a0 10  or  %o2, 0x10, %o2
a00cf61c:  94 00 40 0a  add  %g1, %o2, %o2
a00cf620:  90 10 00 18  mov  %i0, %o0
a00cf624:  7f ff e4 71  call  0xa00c87e8
a00cf628:  92 10 20 0b  mov  0xb, %o1
a00cf62c:  a4 10 20 00  clr  %l2
a00cf630:  03 2a 01 f3  sethi  %hi(0xa807cc00), %g1
a00cf634:  a0 10 62 38  or  %g1, 0x238, %l0	! 0xa807ce38
a00cf638:  9b 2e 20 02  sll  %i0, 2, %o5
a00cf63c:  83 2c a0 10  sll  %l2, 0x10, %g1
a00cf640:  9a 03 40 18  add  %o5, %i0, %o5
a00cf644:  83 30 60 10  srl  %g1, 0x10, %g1
a00cf648:  9a 03 40 10  add  %o5, %l0, %o5
a00cf64c:  d4 0b 40 01  ldub  [ %o5 + %g1 ], %o2
a00cf650:  90 10 00 18  mov  %i0, %o0
a00cf654:  7f ff e0 00  call  0xa00c7654
a00cf658:  92 10 20 01  mov  1, %o1
a00cf65c:  9a 04 a0 01  add  %l2, 1, %o5
a00cf660:  83 2b 60 10  sll  %o5, 0x10, %g1
a00cf664:  83 30 60 10  srl  %g1, 0x10, %g1
a00cf668:  80 a0 60 04  cmp  %g1, 4
a00cf66c:  08 bf ff f1  bleu  0xa00cf630
a00cf670:  a4 10 00 0d  mov  %o5, %l2
a00cf674:  03 2a 01 f3  sethi  %hi(0xa807cc00), %g1
a00cf678:  92 10 61 a8  or  %g1, 0x1a8, %o1	! 0xa807cda8
a00cf67c:  94 10 00 10  mov  %l0, %o2
a00cf680:  a4 10 20 00  clr  %l2
a00cf684:  83 2c a0 10  sll  %l2, 0x10, %g1
a00cf688:  83 30 60 10  srl  %g1, 0x10, %g1
a00cf68c:  96 04 a0 01  add  %l2, 1, %o3
a00cf690:  98 00 40 0a  add  %g1, %o2, %o4
a00cf694:  9b 2a e0 10  sll  %o3, 0x10, %o5
a00cf698:  d8 0b 20 0a  ldub  [ %o4 + 0xa ], %o4
a00cf69c:  9b 33 60 10  srl  %o5, 0x10, %o5
a00cf6a0:  82 00 40 09  add  %g1, %o1, %g1
a00cf6a4:  d8 28 60 0a  stb  %o4, [ %g1 + 0xa ]
a00cf6a8:  80 a3 60 04  cmp  %o5, 4
a00cf6ac:  08 bf ff f6  bleu  0xa00cf684
a00cf6b0:  a4 10 00 0b  mov  %o3, %l2
a00cf6b4:  81 c7 e0 08  ret
a00cf6b8:  81 e8 00 00  restore
