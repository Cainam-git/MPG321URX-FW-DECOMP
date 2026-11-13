# leon2m FUN_a0116ff4 0xa0116ff4-0xa0117f48 (3924 bytes)
a0116ff4:  9d e3 bf 98  save  %sp, -104, %sp
a0116ff8:  83 2e 60 10  sll  %i1, 0x10, %g1
a0116ffc:  83 30 60 10  srl  %g1, 0x10, %g1
a0117000:  9a 10 00 18  mov  %i0, %o5
a0117004:  80 a0 60 01  cmp  %g1, 1
a0117008:  94 10 00 18  mov  %i0, %o2
a011700c:  a0 10 20 00  clr  %l0
a0117010:  98 10 20 00  clr  %o4
a0117014:  02 80 02 08  be  0xa0117834
a0117018:  96 10 20 00  clr  %o3
a011701c:  80 a0 60 01  cmp  %g1, 1
a0117020:  04 80 02 e2  ble  0xa0117ba8
a0117024:  80 a0 60 02  cmp  %g1, 2
a0117028:  02 80 02 71  be  0xa01179ec
a011702c:  80 a0 60 03  cmp  %g1, 3
a0117030:  22 80 00 02  be,a   0xa0117038
a0117034:  96 10 21 64  mov  0x164, %o3
a0117038:  b0 0b 60 ff  and  %o5, 0xff, %i0
a011703c:  80 a6 20 01  cmp  %i0, 1
a0117040:  02 80 01 f0  be  0xa0117800
a0117044:  9a 0a e0 ff  and  %o3, 0xff, %o5
a0117048:  04 80 02 cc  ble  0xa0117b78
a011704c:  80 a6 20 02  cmp  %i0, 2
a0117050:  02 80 02 a6  be  0xa0117ae8
a0117054:  29 00 00 22  sethi  %hi(0x8800), %l4
a0117058:  29 33 c0 4b  sethi  %hi(0xcf012c00), %l4
a011705c:  a6 15 22 00  or  %l4, 0x200, %l3	! 0xcf012e00
a0117060:  e2 04 c0 00  ld  [ %l3 ], %l1
a0117064:  25 33 c0 4e  sethi  %hi(0xcf013800), %l2
a0117068:  98 0b 20 ff  and  %o4, 0xff, %o4
a011706c:  b4 0e a0 ff  and  %i2, 0xff, %i2
a0117070:  c0 24 80 00  clr  [ %l2 ]
a0117074:  b0 10 00 11  mov  %l1, %i0
a0117078:  80 a6 a0 07  cmp  %i2, 7
a011707c:  a8 10 00 0c  mov  %o4, %l4
a0117080:  a4 0a a0 ff  and  %o2, 0xff, %l2
a0117084:  02 80 00 6e  be  0xa011723c
a0117088:  a7 2e 60 10  sll  %i1, 0x10, %l3
a011708c:  80 a6 a0 06  cmp  %i2, 6
a0117090:  18 80 01 4d  bgu  0xa01175c4
a0117094:  80 a6 a0 07  cmp  %i2, 7
a0117098:  9a 10 20 07  mov  7, %o5
a011709c:  a0 23 40 1a  sub  %o5, %i2, %l0
a01170a0:  83 2c 20 04  sll  %l0, 4, %g1
a01170a4:  a0 23 00 01  sub  %o4, %g1, %l0
a01170a8:  b4 0c 20 f0  and  %l0, 0xf0, %i2
a01170ac:  80 a6 a0 f0  cmp  %i2, 0xf0
a01170b0:  22 80 00 03  be,a   0xa01170bc
a01170b4:  a0 10 20 00  clr  %l0
a01170b8:  a4 0a a0 ff  and  %o2, 0xff, %l2
a01170bc:  80 a4 a0 01  cmp  %l2, 1
a01170c0:  02 80 01 49  be  0xa01175e4
a01170c4:  82 10 20 00  clr  %g1
a01170c8:  80 a4 a0 01  cmp  %l2, 1
a01170cc:  04 80 03 74  ble  0xa0117e9c
a01170d0:  80 a4 a0 02  cmp  %l2, 2
a01170d4:  22 80 03 15  be,a   0xa0117d28
a01170d8:  27 33 c0 8b  sethi  %hi(0xcf022c00), %l3
a01170dc:  9e 08 60 df  and  %g1, 0xdf, %o7
a01170e0:  80 a4 a0 01  cmp  %l2, 1
a01170e4:  02 80 01 4e  be  0xa011761c
a01170e8:  98 13 e0 20  or  %o7, 0x20, %o4
a01170ec:  80 a4 a0 01  cmp  %l2, 1
a01170f0:  04 80 03 62  ble  0xa0117e78
a01170f4:  80 a4 a0 02  cmp  %l2, 2
a01170f8:  02 80 02 ff  be  0xa0117cf4
a01170fc:  11 33 c0 8b  sethi  %hi(0xcf022c00), %o0
a0117100:  67 fd d8 28  call  0x4008d1a0
a0117104:  90 10 20 01  mov  1, %o0
a0117108:  80 a4 a0 01  cmp  %l2, 1
a011710c:  02 80 01 53  be  0xa0117658
a0117110:  82 10 20 00  clr  %g1
a0117114:  80 a4 a0 01  cmp  %l2, 1
a0117118:  04 80 03 74  ble  0xa0117ee8
a011711c:  80 a4 a0 02  cmp  %l2, 2
a0117120:  02 80 02 f0  be  0xa0117ce0
a0117124:  15 33 c0 8b  sethi  %hi(0xcf022c00), %o2
a0117128:  90 08 60 bf  and  %g1, 0xbf, %o0
a011712c:  80 a4 a0 01  cmp  %l2, 1
a0117130:  02 80 01 59  be  0xa0117694
a0117134:  98 12 20 40  or  %o0, 0x40, %o4
a0117138:  80 a4 a0 01  cmp  %l2, 1
a011713c:  04 80 03 61  ble  0xa0117ec0
a0117140:  80 a4 a0 02  cmp  %l2, 2
a0117144:  02 80 02 e0  be  0xa0117cc4
a0117148:  1b 33 c0 8b  sethi  %hi(0xcf022c00), %o5
a011714c:  67 fd d8 15  call  0x4008d1a0
a0117150:  90 10 20 01  mov  1, %o0
a0117154:  a7 2e 60 10  sll  %i1, 0x10, %l3
a0117158:  83 34 e0 10  srl  %l3, 0x10, %g1
a011715c:  80 a0 60 01  cmp  %g1, 1
a0117160:  02 80 01 5f  be  0xa01176dc
a0117164:  96 10 20 00  clr  %o3
a0117168:  80 a0 60 01  cmp  %g1, 1
a011716c:  04 80 03 69  ble  0xa0117f10
a0117170:  80 a0 60 02  cmp  %g1, 2
a0117174:  02 80 02 d2  be  0xa0117cbc
a0117178:  80 a0 60 03  cmp  %g1, 3
a011717c:  22 80 00 02  be,a   0xa0117184
a0117180:  96 10 21 64  mov  0x164, %o3
a0117184:  80 a4 a0 01  cmp  %l2, 1
a0117188:  02 80 01 59  be  0xa01176ec
a011718c:  b4 0a e0 ff  and  %o3, 0xff, %i2
a0117190:  80 a4 a0 01  cmp  %l2, 1
a0117194:  04 80 03 11  ble  0xa0117dd8
a0117198:  80 a4 a0 02  cmp  %l2, 2
a011719c:  02 80 02 f8  be  0xa0117d7c
a01171a0:  1f 00 00 22  sethi  %hi(0x8800), %o7
a01171a4:  67 fd d7 ff  call  0x4008d1a0
a01171a8:  90 10 20 01  mov  1, %o0
a01171ac:  80 a4 a0 01  cmp  %l2, 1
a01171b0:  02 80 01 60  be  0xa0117730
a01171b4:  98 10 20 00  clr  %o4
a01171b8:  80 a4 a0 01  cmp  %l2, 1
a01171bc:  04 80 02 fe  ble  0xa0117db4
a01171c0:  80 a4 a0 02  cmp  %l2, 2
a01171c4:  02 80 02 e9  be  0xa0117d68
a01171c8:  13 33 c0 8b  sethi  %hi(0xcf022c00), %o1
a01171cc:  80 a4 a0 01  cmp  %l2, 1
a01171d0:  02 80 01 64  be  0xa0117760
a01171d4:  98 0b 20 df  and  %o4, 0xdf, %o4
a01171d8:  80 a4 a0 01  cmp  %l2, 1
a01171dc:  04 80 03 14  ble  0xa0117e2c
a01171e0:  80 a4 a0 02  cmp  %l2, 2
a01171e4:  02 80 02 db  be  0xa0117d50
a01171e8:  17 33 c0 8b  sethi  %hi(0xcf022c00), %o3
a01171ec:  67 fd d7 ed  call  0x4008d1a0
a01171f0:  90 10 20 01  mov  1, %o0
a01171f4:  80 a4 a0 01  cmp  %l2, 1
a01171f8:  02 80 01 69  be  0xa011779c
a01171fc:  98 10 20 00  clr  %o4
a0117200:  80 a4 a0 01  cmp  %l2, 1
a0117204:  04 80 03 00  ble  0xa0117e04
a0117208:  80 a4 a0 02  cmp  %l2, 2
a011720c:  02 80 02 cc  be  0xa0117d3c
a0117210:  1f 33 c0 8b  sethi  %hi(0xcf022c00), %o7
a0117214:  80 a4 a0 01  cmp  %l2, 1
a0117218:  02 80 01 6e  be  0xa01177d0
a011721c:  98 0b 20 bf  and  %o4, 0xbf, %o4
a0117220:  80 a4 a0 01  cmp  %l2, 1
a0117224:  04 80 03 0b  ble  0xa0117e50
a0117228:  80 a4 a0 02  cmp  %l2, 2
a011722c:  02 80 02 b8  be  0xa0117d0c
a0117230:  35 33 c0 8b  sethi  %hi(0xcf022c00), %i2
a0117234:  67 fd d7 db  call  0x4008d1a0
a0117238:  90 10 20 01  mov  1, %o0
a011723c:  7f ff fd b6  call  0xa0116914
a0117240:  90 10 00 12  mov  %l2, %o0
a0117244:  33 33 c0 4b  sethi  %hi(0xcf012c00), %i1
a0117248:  7f ff fd b3  call  0xa0116914
a011724c:  90 10 00 12  mov  %l2, %o0
a0117250:  a2 16 62 40  or  %i1, 0x240, %l1
a0117254:  a0 10 20 71  mov  0x71, %l0
a0117258:  e0 24 40 00  st  %l0, [ %l1 ]
a011725c:  40 00 04 de  call  0xa01185d4
a0117260:  b4 16 62 00  or  %i1, 0x200, %i2
a0117264:  92 10 20 00  clr  %o1
a0117268:  40 00 05 f0  call  0xa0118a28
a011726c:  90 10 20 00  clr  %o0
a0117270:  96 10 20 11  mov  0x11, %o3
a0117274:  d6 26 80 00  st  %o3, [ %i2 ]
a0117278:  67 fd d7 ca  call  0x4008d1a0
a011727c:  90 10 20 28  mov  0x28, %o0
a0117280:  92 10 20 01  mov  1, %o1
a0117284:  d2 26 80 00  st  %o1, [ %i2 ]
a0117288:  67 fd d7 c6  call  0x4008d1a0
a011728c:  90 10 20 28  mov  0x28, %o0
a0117290:  82 10 20 81  mov  0x81, %g1
a0117294:  c2 26 80 00  st  %g1, [ %i2 ]
a0117298:  67 fd d7 c2  call  0x4008d1a0
a011729c:  90 10 20 14  mov  0x14, %o0
a01172a0:  a2 16 63 2c  or  %i1, 0x32c, %l1
a01172a4:  94 10 20 02  mov  2, %o2
a01172a8:  d4 24 40 00  st  %o2, [ %l1 ]
a01172ac:  67 fd d7 bd  call  0x4008d1a0
a01172b0:  90 10 20 14  mov  0x14, %o0
a01172b4:  90 10 20 05  mov  5, %o0
a01172b8:  d0 24 40 00  st  %o0, [ %l1 ]
a01172bc:  67 fd d7 b9  call  0x4008d1a0
a01172c0:  90 10 20 14  mov  0x14, %o0
a01172c4:  98 16 63 30  or  %i1, 0x330, %o4
a01172c8:  d4 03 00 00  ld  [ %o4 ], %o2
a01172cc:  9e 16 63 34  or  %i1, 0x334, %o7
a01172d0:  d8 03 c0 00  ld  [ %o7 ], %o4
a01172d4:  9a 16 63 38  or  %i1, 0x338, %o5
a01172d8:  de 03 40 00  ld  [ %o5 ], %o7
a01172dc:  a0 16 63 3c  or  %i1, 0x33c, %l0
a01172e0:  f2 04 00 00  ld  [ %l0 ], %i1
a01172e4:  f4 04 40 00  ld  [ %l1 ], %i2
a01172e8:  80 8e a0 80  btst  0x80, %i2
a01172ec:  b4 10 00 19  mov  %i1, %i2
a01172f0:  90 10 00 0a  mov  %o2, %o0
a01172f4:  92 10 00 0c  mov  %o4, %o1
a01172f8:  12 80 00 11  bne  0xa011733c
a01172fc:  96 10 00 0f  mov  %o7, %o3
a0117300:  a2 12 80 0c  or  %o2, %o4, %l1
a0117304:  82 0c 60 ff  and  %l1, 0xff, %g1
a0117308:  80 a0 00 01  cmp  %g0, %g1
a011730c:  94 0b e0 ff  and  %o7, 0xff, %o2
a0117310:  98 60 3f ff  subx  %g0, -1, %o4
a0117314:  9a 1a a0 10  xor  %o2, 0x10, %o5
a0117318:  80 a0 00 0d  cmp  %g0, %o5
a011731c:  b2 60 3f ff  subx  %g0, -1, %i1
a0117320:  80 8b 00 19  btst  %o4, %i1
a0117324:  02 80 00 07  be  0xa0117340
a0117328:  98 10 20 30  mov  0x30, %o4
a011732c:  96 0e a0 ff  and  %i2, 0xff, %o3
a0117330:  80 a0 00 0b  cmp  %g0, %o3
a0117334:  a0 60 20 00  subx  %g0, 0, %l0
a0117338:  96 0b c0 10  and  %o7, %l0, %o3
a011733c:  98 10 20 30  mov  0x30, %o4
a0117340:  1b 33 c0 4e  sethi  %hi(0xcf013800), %o5
a0117344:  21 33 c0 4b  sethi  %hi(0xcf012c00), %l0
a0117348:  b2 02 00 09  add  %o0, %o1, %i1
a011734c:  d8 23 40 00  st  %o4, [ %o5 ]
a0117350:  92 06 40 0b  add  %i1, %o3, %o1
a0117354:  9e 10 20 11  mov  0x11, %o7
a0117358:  a2 14 22 00  or  %l0, 0x200, %l1
a011735c:  b2 02 40 1a  add  %o1, %i2, %i1
a0117360:  de 24 40 00  st  %o7, [ %l1 ]
a0117364:  67 fd d7 8f  call  0x4008d1a0
a0117368:  90 10 20 28  mov  0x28, %o0
a011736c:  90 10 20 01  mov  1, %o0
a0117370:  d0 24 40 00  st  %o0, [ %l1 ]
a0117374:  67 fd d7 8b  call  0x4008d1a0
a0117378:  90 10 20 28  mov  0x28, %o0
a011737c:  96 10 20 81  mov  0x81, %o3
a0117380:  d6 24 40 00  st  %o3, [ %l1 ]
a0117384:  67 fd d7 87  call  0x4008d1a0
a0117388:  90 10 20 14  mov  0x14, %o0
a011738c:  a2 14 23 2c  or  %l0, 0x32c, %l1
a0117390:  82 10 20 02  mov  2, %g1
a0117394:  c2 24 40 00  st  %g1, [ %l1 ]
a0117398:  67 fd d7 82  call  0x4008d1a0
a011739c:  90 10 20 14  mov  0x14, %o0
a01173a0:  94 10 20 05  mov  5, %o2
a01173a4:  d4 24 40 00  st  %o2, [ %l1 ]
a01173a8:  67 fd d7 7e  call  0x4008d1a0
a01173ac:  90 10 20 14  mov  0x14, %o0
a01173b0:  98 14 23 30  or  %l0, 0x330, %o4
a01173b4:  d4 03 00 00  ld  [ %o4 ], %o2
a01173b8:  b4 14 23 34  or  %l0, 0x334, %i2
a01173bc:  d8 06 80 00  ld  [ %i2 ], %o4
a01173c0:  9a 14 23 38  or  %l0, 0x338, %o5
a01173c4:  f4 03 40 00  ld  [ %o5 ], %i2
a01173c8:  92 14 23 3c  or  %l0, 0x33c, %o1
a01173cc:  d0 02 40 00  ld  [ %o1 ], %o0
a01173d0:  de 04 40 00  ld  [ %l1 ], %o7
a01173d4:  80 8b e0 80  btst  0x80, %o7
a01173d8:  9e 10 00 08  mov  %o0, %o7
a01173dc:  90 10 00 0a  mov  %o2, %o0
a01173e0:  92 10 00 0c  mov  %o4, %o1
a01173e4:  12 80 00 11  bne  0xa0117428
a01173e8:  96 10 00 1a  mov  %i2, %o3
a01173ec:  a0 12 80 0c  or  %o2, %o4, %l0
a01173f0:  9a 0c 20 ff  and  %l0, 0xff, %o5
a01173f4:  80 a0 00 0d  cmp  %g0, %o5
a01173f8:  a2 0e a0 ff  and  %i2, 0xff, %l1
a01173fc:  94 60 3f ff  subx  %g0, -1, %o2
a0117400:  82 1c 60 10  xor  %l1, 0x10, %g1
a0117404:  80 a0 00 01  cmp  %g0, %g1
a0117408:  a0 60 3f ff  subx  %g0, -1, %l0
a011740c:  80 8a 80 10  btst  %o2, %l0
a0117410:  02 80 00 07  be  0xa011742c
a0117414:  94 02 00 09  add  %o0, %o1, %o2
a0117418:  96 0b e0 ff  and  %o7, 0xff, %o3
a011741c:  80 a0 00 0b  cmp  %g0, %o3
a0117420:  98 60 20 00  subx  %g0, 0, %o4
a0117424:  96 0e 80 0c  and  %i2, %o4, %o3
a0117428:  94 02 00 09  add  %o0, %o1, %o2
a011742c:  92 02 80 0b  add  %o2, %o3, %o1
a0117430:  b4 02 40 0f  add  %o1, %o7, %i2
a0117434:  90 0e 20 ff  and  %i0, 0xff, %o0
a0117438:  1f 33 c0 4b  sethi  %hi(0xcf012c00), %o7
a011743c:  b0 13 e2 00  or  %o7, 0x200, %i0	! 0xcf012e00
a0117440:  d0 26 00 00  st  %o0, [ %i0 ]
a0117444:  40 00 04 46  call  0xa011855c
a0117448:  b0 16 80 19  or  %i2, %i1, %i0
a011744c:  80 a4 a0 01  cmp  %l2, 1
a0117450:  02 80 01 5c  be  0xa01179c0
a0117454:  82 10 20 00  clr  %g1
a0117458:  80 a4 a0 01  cmp  %l2, 1
a011745c:  04 80 01 be  ble  0xa0117b54
a0117460:  80 a4 a0 02  cmp  %l2, 2
a0117464:  02 80 01 9c  be  0xa0117ad4
a0117468:  19 33 c0 8b  sethi  %hi(0xcf022c00), %o4
a011746c:  82 08 60 df  and  %g1, 0xdf, %g1
a0117470:  80 a4 a0 01  cmp  %l2, 1
a0117474:  02 80 01 48  be  0xa0117994
a0117478:  98 10 60 20  or  %g1, 0x20, %o4
a011747c:  80 a4 a0 01  cmp  %l2, 1
a0117480:  04 80 01 ac  ble  0xa0117b30
a0117484:  80 a4 a0 02  cmp  %l2, 2
a0117488:  02 80 01 8d  be  0xa0117abc
a011748c:  11 33 c0 8b  sethi  %hi(0xcf022c00), %o0
a0117490:  67 fd d7 44  call  0x4008d1a0
a0117494:  90 10 20 01  mov  1, %o0
a0117498:  80 a4 a0 01  cmp  %l2, 1
a011749c:  02 80 01 32  be  0xa0117964
a01174a0:  82 10 20 00  clr  %g1
a01174a4:  80 a4 a0 01  cmp  %l2, 1
a01174a8:  04 80 01 98  ble  0xa0117b08
a01174ac:  80 a4 a0 02  cmp  %l2, 2
a01174b0:  02 80 01 7e  be  0xa0117aa8
a01174b4:  1f 33 c0 8b  sethi  %hi(0xcf022c00), %o7
a01174b8:  96 08 60 bf  and  %g1, 0xbf, %o3
a01174bc:  80 a4 a0 01  cmp  %l2, 1
a01174c0:  02 80 01 1d  be  0xa0117934
a01174c4:  98 12 e0 40  or  %o3, 0x40, %o4
a01174c8:  80 a4 a0 01  cmp  %l2, 1
a01174cc:  04 80 01 c1  ble  0xa0117bd0
a01174d0:  80 a4 a0 02  cmp  %l2, 2
a01174d4:  02 80 01 6e  be  0xa0117a8c
a01174d8:  03 33 c0 8b  sethi  %hi(0xcf022c00), %g1
a01174dc:  67 fd d7 31  call  0x4008d1a0
a01174e0:  90 10 20 01  mov  1, %o0
a01174e4:  83 34 e0 10  srl  %l3, 0x10, %g1
a01174e8:  80 a0 60 01  cmp  %g1, 1
a01174ec:  02 80 01 10  be  0xa011792c
a01174f0:  96 10 20 00  clr  %o3
a01174f4:  80 a0 60 01  cmp  %g1, 1
a01174f8:  04 80 01 b1  ble  0xa0117bbc
a01174fc:  80 a0 60 02  cmp  %g1, 2
a0117500:  02 80 01 61  be  0xa0117a84
a0117504:  80 a0 60 03  cmp  %g1, 3
a0117508:  22 80 00 02  be,a   0xa0117510
a011750c:  96 10 21 64  mov  0x164, %o3
a0117510:  80 a4 a0 01  cmp  %l2, 1
a0117514:  02 80 00 f8  be  0xa01178f4
a0117518:  80 a4 a0 01  cmp  %l2, 1
a011751c:  04 80 01 dd  ble  0xa0117c90
a0117520:  80 a4 a0 02  cmp  %l2, 2
a0117524:  02 80 01 4a  be  0xa0117a4c
a0117528:  11 00 00 22  sethi  %hi(0x8800), %o0
a011752c:  67 fd d7 1d  call  0x4008d1a0
a0117530:  90 10 20 01  mov  1, %o0
a0117534:  80 a4 a0 01  cmp  %l2, 1
a0117538:  02 80 00 e4  be  0xa01178c8
a011753c:  98 10 20 00  clr  %o4
a0117540:  80 a4 a0 01  cmp  %l2, 1
a0117544:  04 80 01 ca  ble  0xa0117c6c
a0117548:  80 a4 a0 02  cmp  %l2, 2
a011754c:  22 80 01 3b  be,a   0xa0117a38
a0117550:  33 33 c0 8b  sethi  %hi(0xcf022c00), %i1
a0117554:  80 a4 a0 01  cmp  %l2, 1
a0117558:  02 80 00 d1  be  0xa011789c
a011755c:  98 0b 20 df  and  %o4, 0xdf, %o4
a0117560:  80 a4 a0 01  cmp  %l2, 1
a0117564:  04 80 01 b9  ble  0xa0117c48
a0117568:  80 a4 a0 02  cmp  %l2, 2
a011756c:  02 80 01 2d  be  0xa0117a20
a0117570:  15 33 c0 8b  sethi  %hi(0xcf022c00), %o2
a0117574:  67 fd d7 0b  call  0x4008d1a0
a0117578:  90 10 20 01  mov  1, %o0
a011757c:  80 a4 a0 01  cmp  %l2, 1
a0117580:  02 80 00 bb  be  0xa011786c
a0117584:  98 10 20 00  clr  %o4
a0117588:  80 a4 a0 01  cmp  %l2, 1
a011758c:  04 80 01 a5  ble  0xa0117c20
a0117590:  80 a4 a0 02  cmp  %l2, 2
a0117594:  22 80 01 1e  be,a   0xa0117a0c
a0117598:  27 33 c0 8b  sethi  %hi(0xcf022c00), %l3
a011759c:  80 a4 a0 01  cmp  %l2, 1
a01175a0:  02 80 00 a7  be  0xa011783c
a01175a4:  98 0b 20 bf  and  %o4, 0xbf, %o4
a01175a8:  80 a4 a0 01  cmp  %l2, 1
a01175ac:  04 80 01 93  ble  0xa0117bf8
a01175b0:  80 a4 a0 02  cmp  %l2, 2
a01175b4:  12 80 02 5c  bne  0xa0117f24
a01175b8:  33 33 c0 8b  sethi  %hi(0xcf022c00), %i1
a01175bc:  10 80 01 0e  b  0xa01179f4
a01175c0:  94 10 20 02  mov  2, %o2
a01175c4:  08 bf fe be  bleu  0xa01170bc
a01175c8:  a4 0a a0 ff  and  %o2, 0xff, %l2
a01175cc:  97 2e a0 04  sll  %i2, 4, %o3
a01175d0:  90 03 00 0b  add  %o4, %o3, %o0
a01175d4:  a0 02 3f 90  add  %o0, -112, %l0
a01175d8:  80 a4 a0 01  cmp  %l2, 1
a01175dc:  12 bf fe bc  bne  0xa01170cc
a01175e0:  82 10 20 00  clr  %g1
a01175e4:  03 33 c0 8c  sethi  %hi(0xcf023000), %g1
a01175e8:  b4 10 63 f8  or  %g1, 0x3f8, %i2	! 0xcf0233f8
a01175ec:  c0 26 80 00  clr  [ %i2 ]
a01175f0:  03 00 00 23  sethi  %hi(0x8c00), %g1
a01175f4:  92 00 60 08  add  %g1, 8, %o1	! 0x8c08
a01175f8:  97 2a 60 02  sll  %o1, 2, %o3
a01175fc:  15 33 c0 00  sethi  %hi(0xcf000000), %o2
a0117600:  90 12 c0 0a  or  %o3, %o2, %o0
a0117604:  da 02 00 00  ld  [ %o0 ], %o5
a0117608:  82 10 00 0d  mov  %o5, %g1
a011760c:  9e 08 60 df  and  %g1, 0xdf, %o7
a0117610:  80 a4 a0 01  cmp  %l2, 1
a0117614:  12 bf fe b7  bne  0xa01170f0
a0117618:  98 13 e0 20  or  %o7, 0x20, %o4
a011761c:  15 33 c0 8c  sethi  %hi(0xcf023000), %o2
a0117620:  96 12 a3 f8  or  %o2, 0x3f8, %o3	! 0xcf0233f8
a0117624:  c0 22 c0 00  clr  [ %o3 ]
a0117628:  98 0b 20 ff  and  %o4, 0xff, %o4
a011762c:  03 00 00 23  sethi  %hi(0x8c00), %g1
a0117630:  a6 00 60 08  add  %g1, 8, %l3	! 0x8c08
a0117634:  9f 2c e0 02  sll  %l3, 2, %o7
a0117638:  23 33 c0 00  sethi  %hi(0xcf000000), %l1
a011763c:  92 13 c0 11  or  %o7, %l1, %o1
a0117640:  d8 22 40 00  st  %o4, [ %o1 ]
a0117644:  67 fd d6 d7  call  0x4008d1a0
a0117648:  90 10 20 01  mov  1, %o0
a011764c:  80 a4 a0 01  cmp  %l2, 1
a0117650:  12 bf fe b2  bne  0xa0117118
a0117654:  82 10 20 00  clr  %g1
a0117658:  23 33 c0 8c  sethi  %hi(0xcf023000), %l1
a011765c:  9e 10 20 02  mov  2, %o7
a0117660:  92 14 63 f8  or  %l1, 0x3f8, %o1
a0117664:  de 22 40 00  st  %o7, [ %o1 ]
a0117668:  03 00 00 23  sethi  %hi(0x8c00), %g1
a011766c:  82 00 60 51  add  %g1, 0x51, %g1	! 0x8c51
a0117670:  b5 28 60 02  sll  %g1, 2, %i2
a0117674:  1b 33 c0 00  sethi  %hi(0xcf000000), %o5
a0117678:  98 16 80 0d  or  %i2, %o5, %o4
a011767c:  e6 03 00 00  ld  [ %o4 ], %l3
a0117680:  82 10 00 13  mov  %l3, %g1
a0117684:  90 08 60 bf  and  %g1, 0xbf, %o0
a0117688:  80 a4 a0 01  cmp  %l2, 1
a011768c:  12 bf fe ac  bne  0xa011713c
a0117690:  98 12 20 40  or  %o0, 0x40, %o4
a0117694:  17 33 c0 8c  sethi  %hi(0xcf023000), %o3
a0117698:  82 12 e3 f8  or  %o3, 0x3f8, %g1	! 0xcf0233f8
a011769c:  90 10 20 02  mov  2, %o0
a01176a0:  d0 20 40 00  st  %o0, [ %g1 ]
a01176a4:  98 0b 20 ff  and  %o4, 0xff, %o4
a01176a8:  03 00 00 23  sethi  %hi(0x8c00), %g1
a01176ac:  a2 00 60 51  add  %g1, 0x51, %l1	! 0x8c51
a01176b0:  93 2c 60 02  sll  %l1, 2, %o1
a01176b4:  1f 33 c0 00  sethi  %hi(0xcf000000), %o7
a01176b8:  94 12 40 0f  or  %o1, %o7, %o2
a01176bc:  d8 22 80 00  st  %o4, [ %o2 ]
a01176c0:  67 fd d6 b8  call  0x4008d1a0
a01176c4:  90 10 20 01  mov  1, %o0
a01176c8:  a7 2e 60 10  sll  %i1, 0x10, %l3
a01176cc:  83 34 e0 10  srl  %l3, 0x10, %g1
a01176d0:  80 a0 60 01  cmp  %g1, 1
a01176d4:  12 bf fe a6  bne  0xa011716c
a01176d8:  96 10 20 00  clr  %o3
a01176dc:  80 a4 a0 01  cmp  %l2, 1
a01176e0:  12 bf fe ad  bne  0xa0117194
a01176e4:  96 10 21 62  mov  0x162, %o3
a01176e8:  b4 0a e0 ff  and  %o3, 0xff, %i2
a01176ec:  1b 00 00 23  sethi  %hi(0x8c00), %o5
a01176f0:  a2 06 80 0d  add  %i2, %o5, %l1
a01176f4:  1f 33 c0 8c  sethi  %hi(0xcf023000), %o7
a01176f8:  b3 2a e0 10  sll  %o3, 0x10, %i1
a01176fc:  97 36 60 18  srl  %i1, 0x18, %o3
a0117700:  95 2c 60 02  sll  %l1, 2, %o2
a0117704:  92 13 e3 f8  or  %o7, 0x3f8, %o1
a0117708:  03 33 c0 00  sethi  %hi(0xcf000000), %g1
a011770c:  90 12 80 01  or  %o2, %g1, %o0
a0117710:  98 0c 20 ff  and  %l0, 0xff, %o4
a0117714:  d6 22 40 00  st  %o3, [ %o1 ]
a0117718:  d8 22 00 00  st  %o4, [ %o0 ]
a011771c:  67 fd d6 a1  call  0x4008d1a0
a0117720:  90 10 20 01  mov  1, %o0
a0117724:  80 a4 a0 01  cmp  %l2, 1
a0117728:  12 bf fe a5  bne  0xa01171bc
a011772c:  98 10 20 00  clr  %o4
a0117730:  1f 33 c0 8c  sethi  %hi(0xcf023000), %o7
a0117734:  96 13 e3 f8  or  %o7, 0x3f8, %o3	! 0xcf0233f8
a0117738:  c0 22 c0 00  clr  [ %o3 ]
a011773c:  03 00 00 23  sethi  %hi(0x8c00), %g1
a0117740:  9a 00 60 08  add  %g1, 8, %o5	! 0x8c08
a0117744:  b3 2b 60 02  sll  %o5, 2, %i1
a0117748:  35 33 c0 00  sethi  %hi(0xcf000000), %i2
a011774c:  a2 16 40 1a  or  %i1, %i2, %l1
a0117750:  d8 04 40 00  ld  [ %l1 ], %o4
a0117754:  80 a4 a0 01  cmp  %l2, 1
a0117758:  12 bf fe a1  bne  0xa01171dc
a011775c:  98 0b 20 df  and  %o4, 0xdf, %o4
a0117760:  23 33 c0 8c  sethi  %hi(0xcf023000), %l1
a0117764:  9e 14 63 f8  or  %l1, 0x3f8, %o7	! 0xcf0233f8
a0117768:  c0 23 c0 00  clr  [ %o7 ]
a011776c:  98 0b 20 ff  and  %o4, 0xff, %o4
a0117770:  03 00 00 23  sethi  %hi(0x8c00), %g1
a0117774:  a0 00 60 08  add  %g1, 8, %l0	! 0x8c08
a0117778:  1b 33 c0 00  sethi  %hi(0xcf000000), %o5
a011777c:  b5 2c 20 02  sll  %l0, 2, %i2
a0117780:  b2 16 80 0d  or  %i2, %o5, %i1
a0117784:  d8 26 40 00  st  %o4, [ %i1 ]
a0117788:  67 fd d6 86  call  0x4008d1a0
a011778c:  90 10 20 01  mov  1, %o0
a0117790:  80 a4 a0 01  cmp  %l2, 1
a0117794:  12 bf fe 9c  bne  0xa0117204
a0117798:  98 10 20 00  clr  %o4
a011779c:  35 33 c0 8c  sethi  %hi(0xcf023000), %i2
a01177a0:  b2 10 20 02  mov  2, %i1
a01177a4:  a2 16 a3 f8  or  %i2, 0x3f8, %l1
a01177a8:  f2 24 40 00  st  %i1, [ %l1 ]
a01177ac:  03 00 00 23  sethi  %hi(0x8c00), %g1
a01177b0:  90 00 60 51  add  %g1, 0x51, %o0	! 0x8c51
a01177b4:  99 2a 20 02  sll  %o0, 2, %o4
a01177b8:  1b 33 c0 00  sethi  %hi(0xcf000000), %o5
a01177bc:  a0 13 00 0d  or  %o4, %o5, %l0
a01177c0:  d8 04 00 00  ld  [ %l0 ], %o4
a01177c4:  80 a4 a0 01  cmp  %l2, 1
a01177c8:  12 bf fe 97  bne  0xa0117224
a01177cc:  98 0b 20 bf  and  %o4, 0xbf, %o4
a01177d0:  11 33 c0 8c  sethi  %hi(0xcf023000), %o0
a01177d4:  9a 10 20 02  mov  2, %o5
a01177d8:  a0 12 23 f8  or  %o0, 0x3f8, %l0
a01177dc:  da 24 00 00  st  %o5, [ %l0 ]
a01177e0:  98 0b 20 ff  and  %o4, 0xff, %o4
a01177e4:  03 00 00 23  sethi  %hi(0x8c00), %g1
a01177e8:  96 00 60 51  add  %g1, 0x51, %o3	! 0x8c51
a01177ec:  83 2a e0 02  sll  %o3, 2, %g1
a01177f0:  13 33 c0 00  sethi  %hi(0xcf000000), %o1
a01177f4:  94 10 40 09  or  %g1, %o1, %o2
a01177f8:  d8 22 80 00  st  %o4, [ %o2 ]
a01177fc:  30 bf fe 8e  b,a   0xa0117234
a0117800:  83 2a e0 10  sll  %o3, 0x10, %g1
a0117804:  11 00 00 23  sethi  %hi(0x8c00), %o0
a0117808:  b0 03 40 08  add  %o5, %o0, %i0
a011780c:  97 30 60 18  srl  %g1, 0x18, %o3
a0117810:  9b 2e 20 02  sll  %i0, 2, %o5
a0117814:  03 33 c0 8c  sethi  %hi(0xcf023000), %g1
a0117818:  19 33 c0 00  sethi  %hi(0xcf000000), %o4
a011781c:  9e 10 63 f8  or  %g1, 0x3f8, %o7
a0117820:  92 13 40 0c  or  %o5, %o4, %o1
a0117824:  d6 23 c0 00  st  %o3, [ %o7 ]
a0117828:  d6 02 40 00  ld  [ %o1 ], %o3
a011782c:  10 bf fe 0b  b  0xa0117058
a0117830:  98 10 00 0b  mov  %o3, %o4
a0117834:  10 bf fe 01  b  0xa0117038
a0117838:  96 10 21 62  mov  0x162, %o3
a011783c:  35 33 c0 8c  sethi  %hi(0xcf023000), %i2
a0117840:  a0 10 20 02  mov  2, %l0
a0117844:  a2 16 a3 f8  or  %i2, 0x3f8, %l1
a0117848:  e0 24 40 00  st  %l0, [ %l1 ]
a011784c:  98 0b 20 ff  and  %o4, 0xff, %o4
a0117850:  03 00 00 23  sethi  %hi(0x8c00), %g1
a0117854:  9e 00 60 51  add  %g1, 0x51, %o7	! 0x8c51
a0117858:  91 2b e0 02  sll  %o7, 2, %o0
a011785c:  1b 33 c0 00  sethi  %hi(0xcf000000), %o5
a0117860:  82 12 00 0d  or  %o0, %o5, %g1
a0117864:  d8 20 40 00  st  %o4, [ %g1 ]
a0117868:  30 80 01 af  b,a   0xa0117f24
a011786c:  23 33 c0 8c  sethi  %hi(0xcf023000), %l1
a0117870:  b2 10 20 02  mov  2, %i1
a0117874:  94 14 63 f8  or  %l1, 0x3f8, %o2
a0117878:  f2 22 80 00  st  %i1, [ %o2 ]
a011787c:  03 00 00 23  sethi  %hi(0x8c00), %g1
a0117880:  82 00 60 51  add  %g1, 0x51, %g1	! 0x8c51
a0117884:  b5 28 60 02  sll  %g1, 2, %i2
a0117888:  1b 33 c0 00  sethi  %hi(0xcf000000), %o5
a011788c:  a0 16 80 0d  or  %i2, %o5, %l0
a0117890:  d8 04 00 00  ld  [ %l0 ], %o4
a0117894:  10 bf ff 43  b  0xa01175a0
a0117898:  80 a4 a0 01  cmp  %l2, 1
a011789c:  23 33 c0 8c  sethi  %hi(0xcf023000), %l1
a01178a0:  b2 14 63 f8  or  %l1, 0x3f8, %i1	! 0xcf0233f8
a01178a4:  c0 26 40 00  clr  [ %i1 ]
a01178a8:  98 0b 20 ff  and  %o4, 0xff, %o4
a01178ac:  03 00 00 23  sethi  %hi(0x8c00), %g1
a01178b0:  82 00 60 08  add  %g1, 8, %g1	! 0x8c08
a01178b4:  b5 28 60 02  sll  %g1, 2, %i2
a01178b8:  1b 33 c0 00  sethi  %hi(0xcf000000), %o5
a01178bc:  a0 16 80 0d  or  %i2, %o5, %l0
a01178c0:  d8 24 00 00  st  %o4, [ %l0 ]
a01178c4:  30 bf ff 2c  b,a   0xa0117574
a01178c8:  21 33 c0 8c  sethi  %hi(0xcf023000), %l0
a01178cc:  a2 14 23 f8  or  %l0, 0x3f8, %l1	! 0xcf0233f8
a01178d0:  c0 24 40 00  clr  [ %l1 ]
a01178d4:  03 00 00 23  sethi  %hi(0x8c00), %g1
a01178d8:  90 00 60 08  add  %g1, 8, %o0	! 0x8c08
a01178dc:  83 2a 20 02  sll  %o0, 2, %g1
a01178e0:  1b 33 c0 00  sethi  %hi(0xcf000000), %o5
a01178e4:  b4 10 40 0d  or  %g1, %o5, %i2
a01178e8:  d8 06 80 00  ld  [ %i2 ], %o4
a01178ec:  10 bf ff 1b  b  0xa0117558
a01178f0:  80 a4 a0 01  cmp  %l2, 1
a01178f4:  9e 0a e0 ff  and  %o3, 0xff, %o7
a01178f8:  13 00 00 23  sethi  %hi(0x8c00), %o1
a01178fc:  9a 03 c0 09  add  %o7, %o1, %o5
a0117900:  91 2a e0 10  sll  %o3, 0x10, %o0
a0117904:  03 33 c0 8c  sethi  %hi(0xcf023000), %g1
a0117908:  b5 32 20 18  srl  %o0, 0x18, %i2
a011790c:  b3 2b 60 02  sll  %o5, 2, %i1
a0117910:  a0 10 63 f8  or  %g1, 0x3f8, %l0
a0117914:  23 33 c0 00  sethi  %hi(0xcf000000), %l1
a0117918:  f4 24 00 00  st  %i2, [ %l0 ]
a011791c:  94 16 40 11  or  %i1, %l1, %o2
a0117920:  98 0d 20 ff  and  %l4, 0xff, %o4
a0117924:  d8 22 80 00  st  %o4, [ %o2 ]
a0117928:  30 bf ff 01  b,a   0xa011752c
a011792c:  10 bf fe f9  b  0xa0117510
a0117930:  96 10 21 62  mov  0x162, %o3
a0117934:  17 33 c0 8c  sethi  %hi(0xcf023000), %o3
a0117938:  9a 10 20 02  mov  2, %o5
a011793c:  a0 12 e3 f8  or  %o3, 0x3f8, %l0
a0117940:  da 24 00 00  st  %o5, [ %l0 ]
a0117944:  98 0b 20 ff  and  %o4, 0xff, %o4
a0117948:  03 00 00 23  sethi  %hi(0x8c00), %g1
a011794c:  92 00 60 51  add  %g1, 0x51, %o1	! 0x8c51
a0117950:  91 2a 60 02  sll  %o1, 2, %o0
a0117954:  1f 33 c0 00  sethi  %hi(0xcf000000), %o7
a0117958:  b4 12 00 0f  or  %o0, %o7, %i2
a011795c:  d8 26 80 00  st  %o4, [ %i2 ]
a0117960:  30 bf fe df  b,a   0xa01174dc
a0117964:  33 33 c0 8c  sethi  %hi(0xcf023000), %i1
a0117968:  94 10 20 02  mov  2, %o2
a011796c:  92 16 63 f8  or  %i1, 0x3f8, %o1
a0117970:  d4 22 40 00  st  %o2, [ %o1 ]
a0117974:  03 00 00 23  sethi  %hi(0x8c00), %g1
a0117978:  a0 00 60 51  add  %g1, 0x51, %l0	! 0x8c51
a011797c:  99 2c 20 02  sll  %l0, 2, %o4
a0117980:  1b 33 c0 00  sethi  %hi(0xcf000000), %o5
a0117984:  82 13 00 0d  or  %o4, %o5, %g1
a0117988:  e2 00 40 00  ld  [ %g1 ], %l1
a011798c:  10 bf fe cb  b  0xa01174b8
a0117990:  82 10 00 11  mov  %l1, %g1
a0117994:  13 33 c0 8c  sethi  %hi(0xcf023000), %o1
a0117998:  9e 12 63 f8  or  %o1, 0x3f8, %o7	! 0xcf0233f8
a011799c:  c0 23 c0 00  clr  [ %o7 ]
a01179a0:  98 0b 20 ff  and  %o4, 0xff, %o4
a01179a4:  03 00 00 23  sethi  %hi(0x8c00), %g1
a01179a8:  82 00 60 08  add  %g1, 8, %g1	! 0x8c08
a01179ac:  b3 28 60 02  sll  %g1, 2, %i1
a01179b0:  23 33 c0 00  sethi  %hi(0xcf000000), %l1
a01179b4:  94 16 40 11  or  %i1, %l1, %o2
a01179b8:  d8 22 80 00  st  %o4, [ %o2 ]
a01179bc:  30 bf fe b5  b,a   0xa0117490
a01179c0:  35 33 c0 8c  sethi  %hi(0xcf023000), %i2
a01179c4:  96 16 a3 f8  or  %i2, 0x3f8, %o3	! 0xcf0233f8
a01179c8:  c0 22 c0 00  clr  [ %o3 ]
a01179cc:  03 00 00 23  sethi  %hi(0x8c00), %g1
a01179d0:  b2 00 60 08  add  %g1, 8, %i1	! 0x8c08
a01179d4:  93 2e 60 02  sll  %i1, 2, %o1
a01179d8:  15 33 c0 00  sethi  %hi(0xcf000000), %o2
a01179dc:  9e 12 40 0a  or  %o1, %o2, %o7
a01179e0:  d0 03 c0 00  ld  [ %o7 ], %o0
a01179e4:  10 bf fe a2  b  0xa011746c
a01179e8:  82 10 00 08  mov  %o0, %g1
a01179ec:  10 bf fd 93  b  0xa0117038
a01179f0:  96 10 21 63  mov  0x163, %o3
a01179f4:  a6 16 63 f8  or  %i1, 0x3f8, %l3
a01179f8:  17 00 00 22  sethi  %hi(0x8800), %o3
a01179fc:  d4 24 c0 00  st  %o2, [ %l3 ]
a0117a00:  98 0b 20 ff  and  %o4, 0xff, %o4
a0117a04:  10 bf ff 94  b  0xa0117854
a0117a08:  82 12 e3 00  or  %o3, 0x300, %g1
a0117a0c:  96 14 e3 f8  or  %l3, 0x3f8, %o3
a0117a10:  29 00 00 22  sethi  %hi(0x8800), %l4
a0117a14:  e4 22 c0 00  st  %l2, [ %o3 ]
a0117a18:  10 bf ff 9a  b  0xa0117880
a0117a1c:  82 15 23 00  or  %l4, 0x300, %g1
a0117a20:  a6 12 a3 f8  or  %o2, 0x3f8, %l3
a0117a24:  17 00 00 22  sethi  %hi(0x8800), %o3
a0117a28:  c0 24 c0 00  clr  [ %l3 ]
a0117a2c:  98 0b 20 ff  and  %o4, 0xff, %o4
a0117a30:  10 bf ff a0  b  0xa01178b0
a0117a34:  82 12 e3 00  or  %o3, 0x300, %g1
a0117a38:  98 16 63 f8  or  %i1, 0x3f8, %o4
a0117a3c:  15 00 00 22  sethi  %hi(0x8800), %o2
a0117a40:  c0 23 00 00  clr  [ %o4 ]
a0117a44:  10 bf ff a5  b  0xa01178d8
a0117a48:  82 12 a3 00  or  %o2, 0x300, %g1
a0117a4c:  9a 0a e0 ff  and  %o3, 0xff, %o5
a0117a50:  83 2a e0 10  sll  %o3, 0x10, %g1
a0117a54:  b4 12 23 00  or  %o0, 0x300, %i2
a0117a58:  a0 03 40 1a  add  %o5, %i2, %l0
a0117a5c:  97 30 60 18  srl  %g1, 0x18, %o3
a0117a60:  99 2c 20 02  sll  %l0, 2, %o4
a0117a64:  03 33 c0 8b  sethi  %hi(0xcf022c00), %g1
a0117a68:  a6 10 63 f8  or  %g1, 0x3f8, %l3	! 0xcf022ff8
a0117a6c:  d6 24 c0 00  st  %o3, [ %l3 ]
a0117a70:  13 33 c0 00  sethi  %hi(0xcf000000), %o1
a0117a74:  96 13 00 09  or  %o4, %o1, %o3
a0117a78:  9e 0d 20 ff  and  %l4, 0xff, %o7
a0117a7c:  de 22 c0 00  st  %o7, [ %o3 ]
a0117a80:  30 bf fe ab  b,a   0xa011752c
a0117a84:  10 bf fe a3  b  0xa0117510
a0117a88:  96 10 21 63  mov  0x163, %o3
a0117a8c:  b2 10 63 f8  or  %g1, 0x3f8, %i1
a0117a90:  a2 10 20 02  mov  2, %l1
a0117a94:  15 00 00 22  sethi  %hi(0x8800), %o2
a0117a98:  e2 26 40 00  st  %l1, [ %i1 ]
a0117a9c:  98 0b 20 ff  and  %o4, 0xff, %o4
a0117aa0:  10 bf ff ab  b  0xa011794c
a0117aa4:  82 12 a3 00  or  %o2, 0x300, %g1
a0117aa8:  90 13 e3 f8  or  %o7, 0x3f8, %o0
a0117aac:  35 00 00 22  sethi  %hi(0x8800), %i2
a0117ab0:  e4 22 00 00  st  %l2, [ %o0 ]
a0117ab4:  10 bf ff b1  b  0xa0117978
a0117ab8:  82 16 a3 00  or  %i2, 0x300, %g1
a0117abc:  b4 12 23 f8  or  %o0, 0x3f8, %i2
a0117ac0:  17 00 00 22  sethi  %hi(0x8800), %o3
a0117ac4:  c0 26 80 00  clr  [ %i2 ]
a0117ac8:  98 0b 20 ff  and  %o4, 0xff, %o4
a0117acc:  10 bf ff b7  b  0xa01179a8
a0117ad0:  82 12 e3 00  or  %o3, 0x300, %g1
a0117ad4:  a0 13 23 f8  or  %o4, 0x3f8, %l0
a0117ad8:  1b 00 00 22  sethi  %hi(0x8800), %o5
a0117adc:  c0 24 00 00  clr  [ %l0 ]
a0117ae0:  10 bf ff bc  b  0xa01179d0
a0117ae4:  82 13 63 00  or  %o5, 0x300, %g1
a0117ae8:  a4 0a e0 ff  and  %o3, 0xff, %l2
a0117aec:  a6 15 23 00  or  %l4, 0x300, %l3
a0117af0:  9e 04 80 13  add  %l2, %l3, %o7
a0117af4:  a3 2a e0 10  sll  %o3, 0x10, %l1
a0117af8:  97 34 60 18  srl  %l1, 0x18, %o3
a0117afc:  9b 2b e0 02  sll  %o7, 2, %o5
a0117b00:  10 bf ff 46  b  0xa0117818
a0117b04:  03 33 c0 8b  sethi  %hi(0xcf022c00), %g1
a0117b08:  80 a4 a0 00  cmp  %l2, 0
a0117b0c:  12 bf fe 6c  bne  0xa01174bc
a0117b10:  96 08 60 bf  and  %g1, 0xbf, %o3
a0117b14:  17 33 c0 8a  sethi  %hi(0xcf022800), %o3
a0117b18:  a0 10 20 02  mov  2, %l0
a0117b1c:  9a 12 e3 f8  or  %o3, 0x3f8, %o5
a0117b20:  19 00 00 22  sethi  %hi(0x8800), %o4
a0117b24:  e0 23 40 00  st  %l0, [ %o5 ]
a0117b28:  10 bf ff 94  b  0xa0117978
a0117b2c:  82 13 22 00  or  %o4, 0x200, %g1
a0117b30:  80 a4 a0 00  cmp  %l2, 0
a0117b34:  12 bf fe 57  bne  0xa0117490
a0117b38:  21 33 c0 8a  sethi  %hi(0xcf022800), %l0
a0117b3c:  9a 14 23 f8  or  %l0, 0x3f8, %o5	! 0xcf022bf8
a0117b40:  23 00 00 22  sethi  %hi(0x8800), %l1
a0117b44:  c0 23 40 00  clr  [ %o5 ]
a0117b48:  98 0b 20 ff  and  %o4, 0xff, %o4
a0117b4c:  10 bf ff 97  b  0xa01179a8
a0117b50:  82 14 62 00  or  %l1, 0x200, %g1
a0117b54:  80 a4 a0 00  cmp  %l2, 0
a0117b58:  32 bf fe 46  bne,a   0xa0117470
a0117b5c:  82 08 60 df  and  %g1, 0xdf, %g1
a0117b60:  23 33 c0 8a  sethi  %hi(0xcf022800), %l1
a0117b64:  82 14 63 f8  or  %l1, 0x3f8, %g1	! 0xcf022bf8
a0117b68:  c0 20 40 00  clr  [ %g1 ]
a0117b6c:  33 00 00 22  sethi  %hi(0x8800), %i1
a0117b70:  10 bf ff 98  b  0xa01179d0
a0117b74:  82 16 62 00  or  %i1, 0x200, %g1	! 0x8a00
a0117b78:  80 a6 20 00  cmp  %i0, 0
a0117b7c:  12 bf fd 38  bne  0xa011705c
a0117b80:  29 33 c0 4b  sethi  %hi(0xcf012c00), %l4
a0117b84:  19 00 00 22  sethi  %hi(0x8800), %o4
a0117b88:  90 0a e0 ff  and  %o3, 0xff, %o0
a0117b8c:  92 13 22 00  or  %o4, 0x200, %o1
a0117b90:  9a 02 00 09  add  %o0, %o1, %o5
a0117b94:  97 2a e0 10  sll  %o3, 0x10, %o3
a0117b98:  97 32 e0 18  srl  %o3, 0x18, %o3
a0117b9c:  9b 2b 60 02  sll  %o5, 2, %o5
a0117ba0:  10 bf ff 1e  b  0xa0117818
a0117ba4:  03 33 c0 8a  sethi  %hi(0xcf022800), %g1
a0117ba8:  80 a0 60 00  cmp  %g1, 0
a0117bac:  22 bf fd 23  be,a   0xa0117038
a0117bb0:  96 10 21 61  mov  0x161, %o3
a0117bb4:  10 bf fd 22  b  0xa011703c
a0117bb8:  b0 0b 60 ff  and  %o5, 0xff, %i0
a0117bbc:  80 a0 60 00  cmp  %g1, 0
a0117bc0:  22 bf fe 54  be,a   0xa0117510
a0117bc4:  96 10 21 61  mov  0x161, %o3
a0117bc8:  10 bf fe 53  b  0xa0117514
a0117bcc:  80 a4 a0 01  cmp  %l2, 1
a0117bd0:  80 a4 a0 00  cmp  %l2, 0
a0117bd4:  12 bf fe 42  bne  0xa01174dc
a0117bd8:  13 33 c0 8a  sethi  %hi(0xcf022800), %o1
a0117bdc:  9e 10 20 02  mov  2, %o7
a0117be0:  90 12 63 f8  or  %o1, 0x3f8, %o0
a0117be4:  35 00 00 22  sethi  %hi(0x8800), %i2
a0117be8:  de 22 00 00  st  %o7, [ %o0 ]
a0117bec:  98 0b 20 ff  and  %o4, 0xff, %o4
a0117bf0:  10 bf ff 57  b  0xa011794c
a0117bf4:  82 16 a2 00  or  %i2, 0x200, %g1
a0117bf8:  80 a4 a0 00  cmp  %l2, 0
a0117bfc:  12 80 00 ca  bne  0xa0117f24
a0117c00:  29 33 c0 8a  sethi  %hi(0xcf022800), %l4
a0117c04:  92 10 20 02  mov  2, %o1
a0117c08:  9e 15 23 f8  or  %l4, 0x3f8, %o7
a0117c0c:  11 00 00 22  sethi  %hi(0x8800), %o0
a0117c10:  d2 23 c0 00  st  %o1, [ %o7 ]
a0117c14:  98 0b 20 ff  and  %o4, 0xff, %o4
a0117c18:  10 bf ff 0f  b  0xa0117854
a0117c1c:  82 12 22 00  or  %o0, 0x200, %g1
a0117c20:  80 a4 a0 00  cmp  %l2, 0
a0117c24:  32 bf fe 5f  bne,a   0xa01175a0
a0117c28:  80 a4 a0 01  cmp  %l2, 1
a0117c2c:  13 33 c0 8a  sethi  %hi(0xcf022800), %o1
a0117c30:  9e 10 20 02  mov  2, %o7
a0117c34:  90 12 63 f8  or  %o1, 0x3f8, %o0
a0117c38:  19 00 00 22  sethi  %hi(0x8800), %o4
a0117c3c:  de 22 00 00  st  %o7, [ %o0 ]
a0117c40:  10 bf ff 10  b  0xa0117880
a0117c44:  82 13 22 00  or  %o4, 0x200, %g1
a0117c48:  80 a4 a0 00  cmp  %l2, 0
a0117c4c:  12 bf fe 4a  bne  0xa0117574
a0117c50:  1f 00 00 22  sethi  %hi(0x8800), %o7
a0117c54:  29 33 c0 8a  sethi  %hi(0xcf022800), %l4
a0117c58:  92 15 23 f8  or  %l4, 0x3f8, %o1	! 0xcf022bf8
a0117c5c:  c0 22 40 00  clr  [ %o1 ]
a0117c60:  98 0b 20 ff  and  %o4, 0xff, %o4
a0117c64:  10 bf ff 13  b  0xa01178b0
a0117c68:  82 13 e2 00  or  %o7, 0x200, %g1
a0117c6c:  80 a4 a0 00  cmp  %l2, 0
a0117c70:  32 bf fe 3a  bne,a   0xa0117558
a0117c74:  80 a4 a0 01  cmp  %l2, 1
a0117c78:  27 33 c0 8a  sethi  %hi(0xcf022800), %l3
a0117c7c:  96 14 e3 f8  or  %l3, 0x3f8, %o3	! 0xcf022bf8
a0117c80:  29 00 00 22  sethi  %hi(0x8800), %l4
a0117c84:  c0 22 c0 00  clr  [ %o3 ]
a0117c88:  10 bf ff 14  b  0xa01178d8
a0117c8c:  82 15 22 00  or  %l4, 0x200, %g1
a0117c90:  80 a4 a0 00  cmp  %l2, 0
a0117c94:  12 bf fe 26  bne  0xa011752c
a0117c98:  98 0a e0 ff  and  %o3, 0xff, %o4
a0117c9c:  23 00 00 22  sethi  %hi(0x8800), %l1
a0117ca0:  b2 14 62 00  or  %l1, 0x200, %i1	! 0x8a00
a0117ca4:  a6 03 00 19  add  %o4, %i1, %l3
a0117ca8:  95 2a e0 10  sll  %o3, 0x10, %o2
a0117cac:  97 32 a0 18  srl  %o2, 0x18, %o3
a0117cb0:  99 2c e0 02  sll  %l3, 2, %o4
a0117cb4:  10 bf ff 6d  b  0xa0117a68
a0117cb8:  03 33 c0 8a  sethi  %hi(0xcf022800), %g1
a0117cbc:  10 bf fd 32  b  0xa0117184
a0117cc0:  96 10 21 63  mov  0x163, %o3
a0117cc4:  b4 10 20 02  mov  2, %i2
a0117cc8:  a6 13 63 f8  or  %o5, 0x3f8, %l3
a0117ccc:  23 00 00 22  sethi  %hi(0x8800), %l1
a0117cd0:  f4 24 c0 00  st  %i2, [ %l3 ]
a0117cd4:  98 0b 20 ff  and  %o4, 0xff, %o4
a0117cd8:  10 bf fe 75  b  0xa01176ac
a0117cdc:  82 14 63 00  or  %l1, 0x300, %g1
a0117ce0:  96 12 a3 f8  or  %o2, 0x3f8, %o3
a0117ce4:  11 00 00 22  sethi  %hi(0x8800), %o0
a0117ce8:  e4 22 c0 00  st  %l2, [ %o3 ]
a0117cec:  10 bf fe 60  b  0xa011766c
a0117cf0:  82 12 23 00  or  %o0, 0x300, %g1
a0117cf4:  9a 12 23 f8  or  %o0, 0x3f8, %o5
a0117cf8:  03 00 00 22  sethi  %hi(0x8800), %g1
a0117cfc:  c0 23 40 00  clr  [ %o5 ]
a0117d00:  98 0b 20 ff  and  %o4, 0xff, %o4
a0117d04:  10 bf fe 4b  b  0xa0117630
a0117d08:  82 10 63 00  or  %g1, 0x300, %g1
a0117d0c:  b2 10 20 02  mov  2, %i1
a0117d10:  a2 16 a3 f8  or  %i2, 0x3f8, %l1
a0117d14:  1f 00 00 22  sethi  %hi(0x8800), %o7
a0117d18:  f2 24 40 00  st  %i1, [ %l1 ]
a0117d1c:  98 0b 20 ff  and  %o4, 0xff, %o4
a0117d20:  10 bf fe b2  b  0xa01177e8
a0117d24:  82 13 e3 00  or  %o7, 0x300, %g1
a0117d28:  a2 14 e3 f8  or  %l3, 0x3f8, %l1
a0117d2c:  1f 00 00 22  sethi  %hi(0x8800), %o7
a0117d30:  c0 24 40 00  clr  [ %l1 ]
a0117d34:  10 bf fe 30  b  0xa01175f4
a0117d38:  82 13 e3 00  or  %o7, 0x300, %g1
a0117d3c:  96 13 e3 f8  or  %o7, 0x3f8, %o3
a0117d40:  13 00 00 22  sethi  %hi(0x8800), %o1
a0117d44:  e4 22 c0 00  st  %l2, [ %o3 ]
a0117d48:  10 bf fe 9a  b  0xa01177b0
a0117d4c:  82 12 63 00  or  %o1, 0x300, %g1
a0117d50:  92 12 e3 f8  or  %o3, 0x3f8, %o1
a0117d54:  03 00 00 22  sethi  %hi(0x8800), %g1
a0117d58:  c0 22 40 00  clr  [ %o1 ]
a0117d5c:  98 0b 20 ff  and  %o4, 0xff, %o4
a0117d60:  10 bf fe 85  b  0xa0117774
a0117d64:  82 10 63 00  or  %g1, 0x300, %g1
a0117d68:  82 12 63 f8  or  %o1, 0x3f8, %g1
a0117d6c:  c0 20 40 00  clr  [ %g1 ]
a0117d70:  15 00 00 22  sethi  %hi(0x8800), %o2
a0117d74:  10 bf fe 73  b  0xa0117740
a0117d78:  82 12 a3 00  or  %o2, 0x300, %g1	! 0x8b00
a0117d7c:  94 0a e0 ff  and  %o3, 0xff, %o2
a0117d80:  92 13 e3 00  or  %o7, 0x300, %o1
a0117d84:  90 02 80 09  add  %o2, %o1, %o0
a0117d88:  97 2a e0 10  sll  %o3, 0x10, %o3
a0117d8c:  97 32 e0 18  srl  %o3, 0x18, %o3
a0117d90:  99 2a 20 02  sll  %o0, 2, %o4
a0117d94:  03 33 c0 8b  sethi  %hi(0xcf022c00), %g1
a0117d98:  9a 10 63 f8  or  %g1, 0x3f8, %o5	! 0xcf022ff8
a0117d9c:  35 33 c0 00  sethi  %hi(0xcf000000), %i2
a0117da0:  d6 23 40 00  st  %o3, [ %o5 ]
a0117da4:  a2 13 00 1a  or  %o4, %i2, %l1
a0117da8:  b2 0c 20 ff  and  %l0, 0xff, %i1
a0117dac:  f2 24 40 00  st  %i1, [ %l1 ]
a0117db0:  30 bf fc fd  b,a   0xa01171a4
a0117db4:  80 a4 a0 00  cmp  %l2, 0
a0117db8:  12 bf fd 06  bne  0xa01171d0
a0117dbc:  80 a4 a0 01  cmp  %l2, 1
a0117dc0:  19 33 c0 8a  sethi  %hi(0xcf022800), %o4
a0117dc4:  90 13 23 f8  or  %o4, 0x3f8, %o0	! 0xcf022bf8
a0117dc8:  21 00 00 22  sethi  %hi(0x8800), %l0
a0117dcc:  c0 22 00 00  clr  [ %o0 ]
a0117dd0:  10 bf fe 5c  b  0xa0117740
a0117dd4:  82 14 22 00  or  %l0, 0x200, %g1
a0117dd8:  80 a4 a0 00  cmp  %l2, 0
a0117ddc:  12 bf fc f2  bne  0xa01171a4
a0117de0:  03 00 00 22  sethi  %hi(0x8800), %g1
a0117de4:  98 0a e0 ff  and  %o3, 0xff, %o4
a0117de8:  9a 10 62 00  or  %g1, 0x200, %o5
a0117dec:  b2 03 00 0d  add  %o4, %o5, %i1
a0117df0:  b5 2a e0 10  sll  %o3, 0x10, %i2
a0117df4:  97 36 a0 18  srl  %i2, 0x18, %o3
a0117df8:  99 2e 60 02  sll  %i1, 2, %o4
a0117dfc:  10 bf ff e7  b  0xa0117d98
a0117e00:  03 33 c0 8a  sethi  %hi(0xcf022800), %g1
a0117e04:  80 a4 a0 00  cmp  %l2, 0
a0117e08:  12 bf fd 04  bne  0xa0117218
a0117e0c:  80 a4 a0 01  cmp  %l2, 1
a0117e10:  03 33 c0 8a  sethi  %hi(0xcf022800), %g1
a0117e14:  90 10 63 f8  or  %g1, 0x3f8, %o0	! 0xcf022bf8
a0117e18:  94 10 20 02  mov  2, %o2
a0117e1c:  19 00 00 22  sethi  %hi(0x8800), %o4
a0117e20:  d4 22 00 00  st  %o2, [ %o0 ]
a0117e24:  10 bf fe 63  b  0xa01177b0
a0117e28:  82 13 22 00  or  %o4, 0x200, %g1
a0117e2c:  80 a4 a0 00  cmp  %l2, 0
a0117e30:  12 bf fc ef  bne  0xa01171ec
a0117e34:  15 33 c0 8a  sethi  %hi(0xcf022800), %o2
a0117e38:  90 12 a3 f8  or  %o2, 0x3f8, %o0	! 0xcf022bf8
a0117e3c:  21 00 00 22  sethi  %hi(0x8800), %l0
a0117e40:  c0 22 00 00  clr  [ %o0 ]
a0117e44:  98 0b 20 ff  and  %o4, 0xff, %o4
a0117e48:  10 bf fe 4b  b  0xa0117774
a0117e4c:  82 14 22 00  or  %l0, 0x200, %g1
a0117e50:  80 a4 a0 00  cmp  %l2, 0
a0117e54:  12 bf fc f8  bne  0xa0117234
a0117e58:  92 10 20 02  mov  2, %o1
a0117e5c:  17 33 c0 8a  sethi  %hi(0xcf022800), %o3
a0117e60:  82 12 e3 f8  or  %o3, 0x3f8, %g1	! 0xcf022bf8
a0117e64:  d2 20 40 00  st  %o1, [ %g1 ]
a0117e68:  15 00 00 22  sethi  %hi(0x8800), %o2
a0117e6c:  98 0b 20 ff  and  %o4, 0xff, %o4
a0117e70:  10 bf fe 5e  b  0xa01177e8
a0117e74:  82 12 a2 00  or  %o2, 0x200, %g1
a0117e78:  80 a4 a0 00  cmp  %l2, 0
a0117e7c:  12 bf fc a1  bne  0xa0117100
a0117e80:  35 33 c0 8a  sethi  %hi(0xcf022800), %i2
a0117e84:  a6 16 a3 f8  or  %i2, 0x3f8, %l3	! 0xcf022bf8
a0117e88:  23 00 00 22  sethi  %hi(0x8800), %l1
a0117e8c:  c0 24 c0 00  clr  [ %l3 ]
a0117e90:  98 0b 20 ff  and  %o4, 0xff, %o4
a0117e94:  10 bf fd e7  b  0xa0117630
a0117e98:  82 14 62 00  or  %l1, 0x200, %g1
a0117e9c:  80 a4 a0 00  cmp  %l2, 0
a0117ea0:  12 bf fc 90  bne  0xa01170e0
a0117ea4:  9e 08 60 df  and  %g1, 0xdf, %o7
a0117ea8:  19 33 c0 8a  sethi  %hi(0xcf022800), %o4
a0117eac:  92 13 23 f8  or  %o4, 0x3f8, %o1	! 0xcf022bf8
a0117eb0:  15 00 00 22  sethi  %hi(0x8800), %o2
a0117eb4:  c0 22 40 00  clr  [ %o1 ]
a0117eb8:  10 bf fd cf  b  0xa01175f4
a0117ebc:  82 12 a2 00  or  %o2, 0x200, %g1
a0117ec0:  80 a4 a0 00  cmp  %l2, 0
a0117ec4:  12 bf fc a2  bne  0xa011714c
a0117ec8:  1f 33 c0 8a  sethi  %hi(0xcf022800), %o7
a0117ecc:  92 10 20 02  mov  2, %o1
a0117ed0:  94 13 e3 f8  or  %o7, 0x3f8, %o2
a0117ed4:  17 00 00 22  sethi  %hi(0x8800), %o3
a0117ed8:  d2 22 80 00  st  %o1, [ %o2 ]
a0117edc:  98 0b 20 ff  and  %o4, 0xff, %o4
a0117ee0:  10 bf fd f3  b  0xa01176ac
a0117ee4:  82 12 e2 00  or  %o3, 0x200, %g1
a0117ee8:  80 a4 a0 00  cmp  %l2, 0
a0117eec:  12 bf fc 90  bne  0xa011712c
a0117ef0:  90 08 60 bf  and  %g1, 0xbf, %o0
a0117ef4:  1b 33 c0 8a  sethi  %hi(0xcf022800), %o5
a0117ef8:  82 10 20 02  mov  2, %g1
a0117efc:  b4 13 63 f8  or  %o5, 0x3f8, %i2
a0117f00:  c2 26 80 00  st  %g1, [ %i2 ]
a0117f04:  19 00 00 22  sethi  %hi(0x8800), %o4
a0117f08:  10 bf fd d9  b  0xa011766c
a0117f0c:  82 13 22 00  or  %o4, 0x200, %g1	! 0x8a00
a0117f10:  80 a0 60 00  cmp  %g1, 0
a0117f14:  22 bf fc 9c  be,a   0xa0117184
a0117f18:  96 10 21 61  mov  0x161, %o3
a0117f1c:  10 bf fc 9b  b  0xa0117188
a0117f20:  80 a4 a0 01  cmp  %l2, 1
a0117f24:  67 fd d4 9f  call  0x4008d1a0
a0117f28:  90 10 20 01  mov  1, %o0
a0117f2c:  7f ff fa 7a  call  0xa0116914
a0117f30:  90 10 00 12  mov  %l2, %o0
a0117f34:  7f ff fa 78  call  0xa0116914
a0117f38:  90 10 00 12  mov  %l2, %o0
a0117f3c:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0117f40:  81 c7 e0 08  ret
a0117f44:  81 e8 00 00  restore
