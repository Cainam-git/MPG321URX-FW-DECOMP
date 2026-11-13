# leon2m FUN_a0087020 0xa0087020-0xa0087430 (1040 bytes)
a0087020:  9d e3 bf 98  save  %sp, -104, %sp
a0087024:  40 03 06 11  call  0xa0148868
a0087028:  2f 2a 00 b3  sethi  %hi(0xa802cc00), %l7
a008702c:  40 01 32 e2  call  0xa00d3bb4
a0087030:  ac 10 00 08  mov  %o0, %l6
a0087034:  29 3f ff fb  sethi  %hi(0xffffec00), %l4
a0087038:  da 15 e3 f4  lduh  [ %l7 + 0x3f4 ], %o5
a008703c:  a8 15 23 ff  or  %l4, 0x3ff, %l4
a0087040:  b8 0b 40 14  and  %o5, %l4, %i4
a0087044:  9a 15 e3 f4  or  %l7, 0x3f4, %o5
a0087048:  f8 35 e3 f4  sth  %i4, [ %l7 + 0x3f4 ]
a008704c:  c0 2b 60 01  clrb  [ %o5 + 1 ]
a0087050:  f0 15 e3 f4  lduh  [ %l7 + 0x3f4 ], %i0
a0087054:  3b 00 00 0b  sethi  %hi(0x2c00), %i5
a0087058:  aa 16 00 1d  or  %i0, %i5, %l5
a008705c:  39 2a 00 b4  sethi  %hi(0xa802d000), %i4
a0087060:  b0 17 22 90  or  %i4, 0x290, %i0	! 0xa802d290
a0087064:  82 0d 7c ff  and  %l5, -769, %g1
a0087068:  17 3f ff ef  sethi  %hi(0xffffbc00), %o3
a008706c:  ea 0e 21 a0  ldub  [ %i0 + 0x1a0 ], %l5
a0087070:  ba 12 e3 ff  or  %o3, 0x3ff, %i5
a0087074:  98 08 40 1d  and  %g1, %i5, %o4
a0087078:  a6 0d 60 ff  and  %l5, 0xff, %l3
a008707c:  21 00 00 1f  sethi  %hi(0x7c00), %l0
a0087080:  a0 14 23 ff  or  %l0, 0x3ff, %l0	! 0x7fff
a0087084:  c0 2b 60 06  clrb  [ %o5 + 6 ]
a0087088:  96 04 c0 18  add  %l3, %i0, %o3
a008708c:  92 13 28 00  or  %o4, 0x800, %o1
a0087090:  e6 0a e1 9b  ldub  [ %o3 + 0x19b ], %l3
a0087094:  c2 0a e1 97  ldub  [ %o3 + 0x197 ], %g1
a0087098:  d4 13 60 14  lduh  [ %o5 + 0x14 ], %o2
a008709c:  d0 13 60 06  lduh  [ %o5 + 6 ], %o0
a00870a0:  de 13 60 0a  lduh  [ %o5 + 0xa ], %o7
a00870a4:  e2 13 60 0e  lduh  [ %o5 + 0xe ], %l1
a00870a8:  98 0a 40 10  and  %o1, %l0, %o4
a00870ac:  c2 2e 21 a1  stb  %g1, [ %i0 + 0x1a1 ]
a00870b0:  e6 2e 21 a2  stb  %l3, [ %i0 + 0x1a2 ]
a00870b4:  92 0a 3f 0f  and  %o0, -241, %o1
a00870b8:  ea 2b 60 09  stb  %l5, [ %o5 + 9 ]
a00870bc:  a4 0a 80 10  and  %o2, %l0, %l2
a00870c0:  d8 35 e3 f4  sth  %o4, [ %l7 + 0x3f4 ]
a00870c4:  90 0b ff bf  and  %o7, -65, %o0
a00870c8:  94 0c 80 1d  and  %l2, %i5, %o2
a00870cc:  9e 0c 40 10  and  %l1, %l0, %o7
a00870d0:  d2 33 60 06  sth  %o1, [ %o5 + 6 ]
a00870d4:  d4 33 60 14  sth  %o2, [ %o5 + 0x14 ]
a00870d8:  a4 10 23 ff  mov  0x3ff, %l2
a00870dc:  a2 10 22 dd  mov  0x2dd, %l1
a00870e0:  94 10 23 6f  mov  0x36f, %o2
a00870e4:  92 10 20 7e  mov  0x7e, %o1
a00870e8:  d6 13 60 04  lduh  [ %o5 + 4 ], %o3
a00870ec:  d0 33 60 0a  sth  %o0, [ %o5 + 0xa ]
a00870f0:  de 33 60 0e  sth  %o7, [ %o5 + 0xe ]
a00870f4:  d4 33 60 20  sth  %o2, [ %o5 + 0x20 ]
a00870f8:  d2 33 60 22  sth  %o1, [ %o5 + 0x22 ]
a00870fc:  e2 33 60 24  sth  %l1, [ %o5 + 0x24 ]
a0087100:  e2 33 60 26  sth  %l1, [ %o5 + 0x26 ]
a0087104:  e2 33 60 28  sth  %l1, [ %o5 + 0x28 ]
a0087108:  c0 2b 60 08  clrb  [ %o5 + 8 ]
a008710c:  c0 2b 60 1c  clrb  [ %o5 + 0x1c ]
a0087110:  c0 33 60 0c  clrh  [ %o5 + 0xc ]
a0087114:  c0 33 60 10  clrh  [ %o5 + 0x10 ]
a0087118:  c0 33 60 12  clrh  [ %o5 + 0x12 ]
a008711c:  c0 33 60 1a  clrh  [ %o5 + 0x1a ]
a0087120:  e4 33 60 1e  sth  %l2, [ %o5 + 0x1e ]
a0087124:  e2 33 60 2a  sth  %l1, [ %o5 + 0x2a ]
a0087128:  11 00 00 18  sethi  %hi(0x6000), %o0
a008712c:  82 2a c0 08  andn  %o3, %o0, %g1
a0087130:  d8 13 60 3e  lduh  [ %o5 + 0x3e ], %o4
a0087134:  aa 08 40 14  and  %g1, %l4, %l5
a0087138:  a6 0b 00 1d  and  %o4, %i5, %l3
a008713c:  94 0d 79 ff  and  %l5, -1537, %o2
a0087140:  a2 0c c0 10  and  %l3, %l0, %l1
a0087144:  1f 3f ff f8  sethi  %hi(0xffffe000), %o7
a0087148:  d2 13 60 18  lduh  [ %o5 + 0x18 ], %o1
a008714c:  96 2c 40 0f  andn  %l1, %o7, %o3
a0087150:  90 0a 80 10  and  %o2, %l0, %o0
a0087154:  98 0a 40 10  and  %o1, %l0, %o4
a0087158:  d6 33 60 3e  sth  %o3, [ %o5 + 0x3e ]
a008715c:  82 0a 37 bf  and  %o0, -2113, %g1
a0087160:  ac 0d a0 ff  and  %l6, 0xff, %l6
a0087164:  e4 33 60 32  sth  %l2, [ %o5 + 0x32 ]
a0087168:  c2 33 60 04  sth  %g1, [ %o5 + 4 ]
a008716c:  d8 33 60 18  sth  %o4, [ %o5 + 0x18 ]
a0087170:  c0 2b 60 3f  clrb  [ %o5 + 0x3f ]
a0087174:  e4 33 60 2c  sth  %l2, [ %o5 + 0x2c ]
a0087178:  e4 33 60 2e  sth  %l2, [ %o5 + 0x2e ]
a008717c:  80 a5 a0 00  cmp  %l6, 0
a0087180:  02 80 00 4c  be  0xa00872b0
a0087184:  e4 33 60 30  sth  %l2, [ %o5 + 0x30 ]
a0087188:  25 00 03 fd  sethi  %hi(0xff400), %l2
a008718c:  92 10 00 16  mov  %l6, %o1
a0087190:  40 01 5f f8  call  0xa00df170
a0087194:  90 14 a1 c0  or  %l2, 0x1c0, %o0
a0087198:  40 00 cd c9  call  0xa00ba8bc
a008719c:  01 00 00 00  nop
a00871a0:  40 02 81 dd  call  0xa0127914
a00871a4:  90 10 20 00  clr  %o0	! 0x0
a00871a8:  40 02 81 bc  call  0xa0127898
a00871ac:  01 00 00 00  nop
a00871b0:  40 02 88 fa  call  0xa0129598
a00871b4:  01 00 00 00  nop
a00871b8:  40 01 4f a7  call  0xa00db054
a00871bc:  01 00 00 00  nop
a00871c0:  80 a5 a0 04  cmp  %l6, 4
a00871c4:  02 80 00 07  be  0xa00871e0
a00871c8:  80 a5 a0 01  cmp  %l6, 1
a00871cc:  40 00 01 2c  call  0xa008767c
a00871d0:  90 10 20 00  clr  %o0
a00871d4:  40 03 12 a1  call  0xa014bc58
a00871d8:  90 10 20 00  clr  %o0
a00871dc:  80 a5 a0 01  cmp  %l6, 1
a00871e0:  18 80 00 27  bgu  0xa008727c
a00871e4:  80 a5 a0 02  cmp  %l6, 2
a00871e8:  80 a5 a0 01  cmp  %l6, 1
a00871ec:  02 80 00 35  be  0xa00872c0
a00871f0:  d4 07 22 90  ld  [ %i4 + 0x290 ], %o2
a00871f4:  7f ff eb 06  call  0xa0081e0c
a00871f8:  01 00 00 00  nop
a00871fc:  40 01 4f de  call  0xa00db174
a0087200:  01 00 00 00  nop
a0087204:  80 a5 a0 01  cmp  %l6, 1
a0087208:  02 80 00 11  be  0xa008724c
a008720c:  90 10 20 01  mov  1, %o0
a0087210:  80 a5 a0 02  cmp  %l6, 2
a0087214:  02 80 00 6c  be  0xa00873c4
a0087218:  82 0d a0 f0  and  %l6, 0xf0, %g1
a008721c:  80 a0 60 30  cmp  %g1, 0x30
a0087220:  02 80 00 75  be  0xa00873f4
a0087224:  80 a5 a0 05  cmp  %l6, 5
a0087228:  02 80 00 73  be  0xa00873f4
a008722c:  80 a5 a0 03  cmp  %l6, 3
a0087230:  02 80 00 73  be  0xa00873fc
a0087234:  80 a0 60 20  cmp  %g1, 0x20
a0087238:  02 80 00 05  be  0xa008724c
a008723c:  90 10 20 03  mov  3, %o0
a0087240:  80 a5 a0 04  cmp  %l6, 4
a0087244:  02 80 00 5e  be  0xa00873bc
a0087248:  90 10 20 00  clr  %o0
a008724c:  7f ff fe 27  call  0xa0086ae8
a0087250:  01 00 00 00  nop
a0087254:  9e 17 22 90  or  %i4, 0x290, %o7
a0087258:  23 00 00 15  sethi  %hi(0x5400), %l1
a008725c:  e4 13 e1 f6  lduh  [ %o7 + 0x1f6 ], %l2
a0087260:  b8 14 61 aa  or  %l1, 0x1aa, %i4
a0087264:  80 a4 80 1c  cmp  %l2, %i4
a0087268:  02 80 00 03  be  0xa0087274
a008726c:  b0 10 20 01  mov  1, %i0
a0087270:  b0 10 20 00  clr  %i0
a0087274:  40 02 74 4f  call  0xa01243b0
a0087278:  81 e8 00 00  restore
a008727c:  12 bf ff e0  bne  0xa00871fc
a0087280:  2b 2a 00 b8  sethi  %hi(0xa802e000), %l5
a0087284:  e0 05 61 a0  ld  [ %l5 + 0x1a0 ], %l0	! 0xa802e1a0
a0087288:  80 a4 20 00  cmp  %l0, 0
a008728c:  16 bf ff da  bge  0xa00871f4
a0087290:  01 00 00 00  nop
a0087294:  40 01 4f b8  call  0xa00db174
a0087298:  01 00 00 00  nop
a008729c:  80 a5 a0 01  cmp  %l6, 1
a00872a0:  12 bf ff dd  bne  0xa0087214
a00872a4:  80 a5 a0 02  cmp  %l6, 2
a00872a8:  10 bf ff e9  b  0xa008724c
a00872ac:  90 10 20 01  mov  1, %o0
a00872b0:  40 00 1c e8  call  0xa008e650
a00872b4:  25 00 03 fd  sethi  %hi(0xff400), %l2
a00872b8:  10 bf ff b6  b  0xa0087190
a00872bc:  92 10 00 16  mov  %l6, %o1
a00872c0:  13 00 00 15  sethi  %hi(0x5400), %o1
a00872c4:  d0 16 21 f6  lduh  [ %i0 + 0x1f6 ], %o0
a00872c8:  a2 0a 80 1d  and  %o2, %i5, %l1
a00872cc:  9e 12 61 aa  or  %o1, 0x1aa, %o7
a00872d0:  80 a2 00 0f  cmp  %o0, %o7
a00872d4:  02 80 00 06  be  0xa00872ec
a00872d8:  e2 27 22 90  st  %l1, [ %i4 + 0x290 ]
a00872dc:  d8 0e 21 d5  ldub  [ %i0 + 0x1d5 ], %o4
a00872e0:  80 a3 20 00  cmp  %o4, 0
a00872e4:  22 80 00 2f  be,a   0xa00873a0
a00872e8:  92 17 22 90  or  %i4, 0x290, %o1
a00872ec:  03 3f ff ee  sethi  %hi(0xffffb800), %g1
a00872f0:  a6 10 63 99  or  %g1, 0x399, %l3	! 0xffffbb99
a00872f4:  e6 36 21 f6  sth  %l3, [ %i0 + 0x1f6 ]
a00872f8:  40 01 54 39  call  0xa00dc3dc
a00872fc:  c0 2e 21 d5  clrb  [ %i0 + 0x1d5 ]
a0087300:  90 10 20 08  mov  8, %o0
a0087304:  40 02 fa 56  call  0xa0145c5c
a0087308:  92 10 20 00  clr  %o1
a008730c:  90 10 20 09  mov  9, %o0
a0087310:  40 02 fa 53  call  0xa0145c5c
a0087314:  92 10 20 00  clr  %o1
a0087318:  90 10 20 06  mov  6, %o0
a008731c:  40 02 fa 50  call  0xa0145c5c
a0087320:  92 10 20 00  clr  %o1
a0087324:  90 10 20 07  mov  7, %o0
a0087328:  40 02 fa 4d  call  0xa0145c5c
a008732c:  92 10 20 00  clr  %o1
a0087330:  90 10 20 0b  mov  0xb, %o0
a0087334:  92 10 20 00  clr  %o1
a0087338:  c0 2e 21 e7  clrb  [ %i0 + 0x1e7 ]
a008733c:  c0 2e 21 e2  clrb  [ %i0 + 0x1e2 ]
a0087340:  c0 2e 21 e6  clrb  [ %i0 + 0x1e6 ]
a0087344:  40 02 fa 46  call  0xa0145c5c
a0087348:  c0 2e 21 e3  clrb  [ %i0 + 0x1e3 ]
a008734c:  90 10 20 0a  mov  0xa, %o0
a0087350:  40 02 fa 43  call  0xa0145c5c
a0087354:  92 10 20 00  clr  %o1
a0087358:  90 10 20 0d  mov  0xd, %o0
a008735c:  40 02 fa 40  call  0xa0145c5c
a0087360:  92 10 20 00  clr  %o1
a0087364:  90 10 20 0c  mov  0xc, %o0
a0087368:  40 02 fa 3d  call  0xa0145c5c
a008736c:  92 10 20 00  clr  %o1
a0087370:  90 10 20 10  mov  0x10, %o0
a0087374:  40 02 fa 3a  call  0xa0145c5c
a0087378:  92 10 20 00  clr  %o1
a008737c:  90 10 20 0e  mov  0xe, %o0
a0087380:  40 02 fa 37  call  0xa0145c5c
a0087384:  92 10 20 00  clr  %o1
a0087388:  90 10 20 0f  mov  0xf, %o0
a008738c:  40 02 fa 34  call  0xa0145c5c
a0087390:  92 10 20 00  clr  %o1
a0087394:  40 02 f7 f3  call  0xa0145360
a0087398:  90 10 20 01  mov  1, %o0
a008739c:  92 17 22 90  or  %i4, 0x290, %o1
a00873a0:  94 10 20 00  clr  %o2
a00873a4:  96 10 21 fc  mov  0x1fc, %o3
a00873a8:  40 03 0e ca  call  0xa014aed0
a00873ac:  90 10 20 30  mov  0x30, %o0
a00873b0:  7f ff ea 97  call  0xa0081e0c
a00873b4:  01 00 00 00  nop
a00873b8:  30 bf ff 91  b,a   0xa00871fc
a00873bc:  10 bf ff a4  b  0xa008724c
a00873c0:  90 10 20 04  mov  4, %o0
a00873c4:  92 17 22 90  or  %i4, 0x290, %o1
a00873c8:  96 10 20 05  mov  5, %o3
a00873cc:  d6 2a 60 1e  stb  %o3, [ %o1 + 0x1e ]
a00873d0:  90 10 20 30  mov  0x30, %o0
a00873d4:  94 10 20 00  clr  %o2
a00873d8:  40 03 0e be  call  0xa014aed0
a00873dc:  96 10 21 fc  mov  0x1fc, %o3
a00873e0:  2d 2a 00 b8  sethi  %hi(0xa802e000), %l6
a00873e4:  ee 05 a1 a0  ld  [ %l6 + 0x1a0 ], %l7	! 0xa802e1a0
a00873e8:  80 a5 e0 00  cmp  %l7, 0
a00873ec:  36 bf ff 98  bge,a   0xa008724c
a00873f0:  90 10 20 01  mov  1, %o0
a00873f4:  10 bf ff 96  b  0xa008724c
a00873f8:  90 10 20 02  mov  2, %o0
a00873fc:  40 03 05 8a  call  0xa0148a24
a0087400:  01 00 00 00  nop
a0087404:  b0 0a 20 ff  and  %o0, 0xff, %i0
a0087408:  80 a6 20 01  cmp  %i0, 1
a008740c:  02 bf ff 90  be  0xa008724c
a0087410:  90 10 20 04  mov  4, %o0
a0087414:  7f ff fd b5  call  0xa0086ae8
a0087418:  90 10 20 03  mov  3, %o0
a008741c:  e8 15 e3 f4  lduh  [ %l7 + 0x3f4 ], %l4
a0087420:  1b 3f ff e0  sethi  %hi(0xffff8000), %o5
a0087424:  ba 15 00 0d  or  %l4, %o5, %i5
a0087428:  10 bf ff 8b  b  0xa0087254
a008742c:  fa 35 e3 f4  sth  %i5, [ %l7 + 0x3f4 ]
