# leon2m FUN_a01070b4 0xa01070b4-0xa01073b8 (772 bytes)
a01070b4:  9d e3 bf 98  save  %sp, -104, %sp
a01070b8:  40 00 66 a0  call  0xa0120b38
a01070bc:  90 10 20 00  clr  %o0
a01070c0:  2b 2a 00 b5  sethi  %hi(0xa802d400), %l5
a01070c4:  91 2a 20 10  sll  %o0, 0x10, %o0
a01070c8:  d4 05 62 a4  ld  [ %l5 + 0x2a4 ], %o2
a01070cc:  a3 32 20 10  srl  %o0, 0x10, %l1
a01070d0:  c2 12 a0 4e  lduh  [ %o2 + 0x4e ], %g1
a01070d4:  80 a0 40 11  cmp  %g1, %l1
a01070d8:  18 80 00 ae  bgu  0xa0107390
a01070dc:  b0 10 20 00  clr  %i0
a01070e0:  d4 12 a0 50  lduh  [ %o2 + 0x50 ], %o2
a01070e4:  80 a2 80 11  cmp  %o2, %l1
a01070e8:  0a 80 00 a5  bcs  0xa010737c
a01070ec:  03 00 06 6a  sethi  %hi(0x19a800), %g1
a01070f0:  40 00 0d dd  call  0xa010a864
a01070f4:  01 00 00 00  nop
a01070f8:  80 8a 20 ff  btst  0xff, %o0
a01070fc:  12 80 00 4c  bne  0xa010722c
a0107100:  01 00 00 00  nop
a0107104:  7f ff ef b3  call  0xa0102fd0
a0107108:  90 10 20 00  clr  %o0	! 0x0
a010710c:  9b 2a 20 10  sll  %o0, 0x10, %o5
a0107110:  a5 33 60 10  srl  %o5, 0x10, %l2
a0107114:  92 10 20 5e  mov  0x5e, %o1
a0107118:  7f ff ad 38  call  0xa00f25f8
a010711c:  90 10 20 00  clr  %o0
a0107120:  99 2a 20 10  sll  %o0, 0x10, %o4
a0107124:  a1 33 20 10  srl  %o4, 0x10, %l0
a0107128:  92 10 20 5b  mov  0x5b, %o1
a010712c:  7f ff ad 33  call  0xa00f25f8
a0107130:  90 10 20 00  clr  %o0
a0107134:  97 2a 20 10  sll  %o0, 0x10, %o3
a0107138:  15 00 06 6a  sethi  %hi(0x19a800), %o2
a010713c:  a9 32 e0 10  srl  %o3, 0x10, %l4
a0107140:  7f ff 60 0c  call  0xa00df170
a0107144:  90 12 a1 38  or  %o2, 0x138, %o0
a0107148:  a1 2c 20 10  sll  %l0, 0x10, %l0
a010714c:  11 00 00 09  sethi  %hi(0x2400), %o0
a0107150:  a6 12 23 10  or  %o0, 0x310, %l3	! 0x2710
a0107154:  ac 5c 80 13  smul  %l2, %l3, %l6
a0107158:  a7 34 20 10  srl  %l0, 0x10, %l3
a010715c:  81 80 00 00  mov  %g0, %y
a0107160:  01 00 00 00  nop
a0107164:  01 00 00 00  nop
a0107168:  01 00 00 00  nop
a010716c:  a0 75 80 13  udiv  %l6, %l3, %l0
a0107170:  9f 2c 20 10  sll  %l0, 0x10, %o7
a0107174:  e0 05 62 a4  ld  [ %l5 + 0x2a4 ], %l0
a0107178:  a3 33 e0 10  srl  %o7, 0x10, %l1
a010717c:  d4 14 20 4a  lduh  [ %l0 + 0x4a ], %o2
a0107180:  80 a2 80 11  cmp  %o2, %l1
a0107184:  18 80 00 77  bgu  0xa0107360
a0107188:  2d 2a 00 b5  sethi  %hi(0xa802d400), %l6
a010718c:  d4 14 20 4c  lduh  [ %l0 + 0x4c ], %o2
a0107190:  80 a2 80 11  cmp  %o2, %l1
a0107194:  2a 80 00 6d  bcs,a   0xa0107348
a0107198:  2b 00 06 6a  sethi  %hi(0x19a800), %l5
a010719c:  03 00 03 d0  sethi  %hi(0xf4000), %g1
a01071a0:  d0 1c 20 10  ldd  [ %l0 + 0x10 ], %o0
a01071a4:  94 10 20 00  clr  %o2
a01071a8:  40 01 38 18  call  0xa0155208
a01071ac:  96 10 62 40  or  %g1, 0x240, %o3
a01071b0:  80 a4 80 09  cmp  %l2, %o1
a01071b4:  2a 80 00 5e  bcs,a   0xa010732c
a01071b8:  15 00 06 6a  sethi  %hi(0x19a800), %o2
a01071bc:  17 00 03 d0  sethi  %hi(0xf4000), %o3
a01071c0:  96 12 e2 40  or  %o3, 0x240, %o3	! 0xf4240
a01071c4:  d0 1c 20 18  ldd  [ %l0 + 0x18 ], %o0
a01071c8:  40 01 38 10  call  0xa0155208
a01071cc:  94 10 20 00  clr  %o2
a01071d0:  80 a4 80 09  cmp  %l2, %o1
a01071d4:  18 80 00 4e  bgu  0xa010730c
a01071d8:  96 10 00 09  mov  %o1, %o3
a01071dc:  d4 14 20 20  lduh  [ %l0 + 0x20 ], %o2
a01071e0:  80 a2 80 13  cmp  %o2, %l3
a01071e4:  38 80 00 44  bgu,a   0xa01072f4
a01071e8:  25 00 06 6a  sethi  %hi(0x19a800), %l2
a01071ec:  d4 14 20 24  lduh  [ %l0 + 0x24 ], %o2
a01071f0:  80 a2 80 13  cmp  %o2, %l3
a01071f4:  0a 80 00 3a  bcs  0xa01072dc
a01071f8:  1b 00 06 6a  sethi  %hi(0x19a800), %o5
a01071fc:  9f 2d 20 10  sll  %l4, 0x10, %o7
a0107200:  a3 33 e0 10  srl  %o7, 0x10, %l1
a0107204:  d4 14 20 2a  lduh  [ %l0 + 0x2a ], %o2
a0107208:  80 a2 80 11  cmp  %o2, %l1
a010720c:  18 80 00 2f  bgu  0xa01072c8
a0107210:  29 00 06 6a  sethi  %hi(0x19a800), %l4
a0107214:  d4 14 20 2e  lduh  [ %l0 + 0x2e ], %o2
a0107218:  80 a2 80 11  cmp  %o2, %l1
a010721c:  3a 80 00 65  bcc,a   0xa01073b0
a0107220:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0107224:  10 80 00 24  b  0xa01072b4
a0107228:  21 00 06 6a  sethi  %hi(0x19a800), %l0
a010722c:  7f ff ef 69  call  0xa0102fd0
a0107230:  90 10 20 04  mov  4, %o0
a0107234:  40 00 0d 94  call  0xa010a884
a0107238:  a9 2a 20 10  sll  %o0, 0x10, %l4
a010723c:  40 00 0d eb  call  0xa010a9e8
a0107240:  a6 10 00 08  mov  %o0, %l3
a0107244:  a5 35 20 10  srl  %l4, 0x10, %l2
a0107248:  a8 10 00 08  mov  %o0, %l4
a010724c:  11 33 c0 47  sethi  %hi(0xcf011c00), %o0
a0107250:  ac 12 22 c0  or  %o0, 0x2c0, %l6	! 0xcf011ec0
a0107254:  de 05 80 00  ld  [ %l6 ], %o7
a0107258:  80 8b e0 40  btst  0x40, %o7
a010725c:  02 80 00 11  be  0xa01072a0
a0107260:  a1 2c e0 10  sll  %l3, 0x10, %l0
a0107264:  1b 00 00 09  sethi  %hi(0x2400), %o5
a0107268:  98 13 63 10  or  %o5, 0x310, %o4	! 0x2710
a010726c:  94 5c 80 0c  smul  %l2, %o4, %o2
a0107270:  97 34 20 10  srl  %l0, 0x10, %o3
a0107274:  81 80 00 00  mov  %g0, %y
a0107278:  01 00 00 00  nop
a010727c:  01 00 00 00  nop
a0107280:  01 00 00 00  nop
a0107284:  82 72 80 0b  udiv  %o2, %o3, %g1
a0107288:  92 58 63 e8  smul  %g1, 0x3e8, %o1
a010728c:  81 80 00 00  mov  %g0, %y
a0107290:  01 00 00 00  nop
a0107294:  01 00 00 00  nop
a0107298:  01 00 00 00  nop
a010729c:  a8 72 40 11  udiv  %o1, %l1, %l4
a01072a0:  23 00 06 6a  sethi  %hi(0x19a800), %l1
a01072a4:  7f ff 5f b3  call  0xa00df170
a01072a8:  90 14 62 d0  or  %l1, 0x2d0, %o0	! 0x19aad0
a01072ac:  10 bf ff a9  b  0xa0107150
a01072b0:  11 00 00 09  sethi  %hi(0x2400), %o0
a01072b4:  90 14 22 90  or  %l0, 0x290, %o0
a01072b8:  7f ff 5f ae  call  0xa00df170
a01072bc:  92 10 00 11  mov  %l1, %o1
a01072c0:  10 80 00 3c  b  0xa01073b0
a01072c4:  b0 0e 20 ff  and  %i0, 0xff, %i0
a01072c8:  90 15 22 50  or  %l4, 0x250, %o0
a01072cc:  7f ff 5f a9  call  0xa00df170
a01072d0:  92 10 00 11  mov  %l1, %o1
a01072d4:  10 bf ff d0  b  0xa0107214
a01072d8:  e0 05 a2 a4  ld  [ %l6 + 0x2a4 ], %l0
a01072dc:  90 13 62 10  or  %o5, 0x210, %o0
a01072e0:  7f ff 5f a4  call  0xa00df170
a01072e4:  92 10 00 13  mov  %l3, %o1
a01072e8:  b0 16 3f 80  or  %i0, -128, %i0
a01072ec:  10 bf ff c4  b  0xa01071fc
a01072f0:  e0 05 a2 a4  ld  [ %l6 + 0x2a4 ], %l0
a01072f4:  90 14 a1 d0  or  %l2, 0x1d0, %o0
a01072f8:  7f ff 5f 9e  call  0xa00df170
a01072fc:  92 10 00 13  mov  %l3, %o1
a0107300:  b0 16 20 40  or  %i0, 0x40, %i0
a0107304:  10 bf ff ba  b  0xa01071ec
a0107308:  e0 05 a2 a4  ld  [ %l6 + 0x2a4 ], %l0
a010730c:  19 00 06 6a  sethi  %hi(0x19a800), %o4
a0107310:  90 13 22 f0  or  %o4, 0x2f0, %o0	! 0x19aaf0
a0107314:  92 10 00 12  mov  %l2, %o1
a0107318:  7f ff 5f 96  call  0xa00df170
a010731c:  94 10 00 0b  mov  %o3, %o2
a0107320:  b0 16 20 08  or  %i0, 8, %i0
a0107324:  10 bf ff ae  b  0xa01071dc
a0107328:  e0 05 a2 a4  ld  [ %l6 + 0x2a4 ], %l0
a010732c:  90 12 a1 98  or  %o2, 0x198, %o0
a0107330:  94 10 00 09  mov  %o1, %o2
a0107334:  7f ff 5f 8f  call  0xa00df170
a0107338:  92 10 00 12  mov  %l2, %o1
a010733c:  b0 16 20 04  or  %i0, 4, %i0
a0107340:  10 bf ff 9f  b  0xa01071bc
a0107344:  e0 05 a2 a4  ld  [ %l6 + 0x2a4 ], %l0
a0107348:  90 15 61 58  or  %l5, 0x158, %o0
a010734c:  7f ff 5f 89  call  0xa00df170
a0107350:  92 10 00 11  mov  %l1, %o1
a0107354:  b0 16 20 02  or  %i0, 2, %i0
a0107358:  10 bf ff 91  b  0xa010719c
a010735c:  e0 05 a2 a4  ld  [ %l6 + 0x2a4 ], %l0
a0107360:  13 00 06 6a  sethi  %hi(0x19a800), %o1
a0107364:  90 12 63 28  or  %o1, 0x328, %o0	! 0x19ab28
a0107368:  7f ff 5f 82  call  0xa00df170
a010736c:  92 10 00 11  mov  %l1, %o1
a0107370:  e0 05 62 a4  ld  [ %l5 + 0x2a4 ], %l0
a0107374:  10 bf ff 86  b  0xa010718c
a0107378:  b0 16 20 01  or  %i0, 1, %i0
a010737c:  90 10 61 00  or  %g1, 0x100, %o0
a0107380:  b0 16 20 20  or  %i0, 0x20, %i0
a0107384:  7f ff 5f 7b  call  0xa00df170
a0107388:  92 10 00 11  mov  %l1, %o1
a010738c:  30 bf ff 59  b,a   0xa01070f0
a0107390:  13 00 06 6a  sethi  %hi(0x19a800), %o1
a0107394:  90 12 63 68  or  %o1, 0x368, %o0	! 0x19ab68
a0107398:  94 10 00 01  mov  %g1, %o2
a010739c:  7f ff 5f 75  call  0xa00df170
a01073a0:  92 10 00 11  mov  %l1, %o1
a01073a4:  b0 10 20 10  mov  0x10, %i0
a01073a8:  10 bf ff 4e  b  0xa01070e0
a01073ac:  d4 05 62 a4  ld  [ %l5 + 0x2a4 ], %o2
a01073b0:  81 c7 e0 08  ret
a01073b4:  81 e8 00 00  restore
