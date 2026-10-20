# leon2m FUN_a01471a0 0xa01471a0-0xa014737c (212 bytes)
a01471a0:  9d e3 bf 98  save  %sp, -104, %sp
a01471a4:  b0 0e 20 ff  and  %i0, 0xff, %i0
a01471a8:  80 a6 20 01  cmp  %i0, 1
a01471ac:  02 80 00 0b  be  0xa01471d8
a01471b0:  82 10 20 01  mov  1, %g1
a01471b4:  80 a6 20 01  cmp  %i0, 1
a01471b8:  04 80 00 28  ble  0xa0147258
a01471bc:  80 a6 20 02  cmp  %i0, 2
a01471c0:  02 80 00 06  be  0xa01471d8
a01471c4:  82 10 20 02  mov  2, %g1
a01471c8:  80 a6 20 03  cmp  %i0, 3
a01471cc:  02 80 00 03  be  0xa01471d8
a01471d0:  82 10 20 03  mov  3, %g1
a01471d4:  82 10 3f ff  mov  -1, %g1
a01471d8:  a0 08 60 ff  and  %g1, 0xff, %l0
a01471dc:  80 a4 20 03  cmp  %l0, 3
a01471e0:  18 80 00 1a  bgu  0xa0147248
a01471e4:  11 00 06 9b  sethi  %hi(0x1a6c00), %o0
a01471e8:  9f 2c 20 04  sll  %l0, 4, %o7
a01471ec:  96 23 c0 10  sub  %o7, %l0, %o3
a01471f0:  15 2a 00 b7  sethi  %hi(0xa802dc00), %o2
a01471f4:  83 2a e0 03  sll  %o3, 3, %g1
a01471f8:  9a 12 a3 30  or  %o2, 0x330, %o5
a01471fc:  d2 03 40 01  ld  [ %o5 + %g1 ], %o1
a0147200:  99 32 60 04  srl  %o1, 4, %o4
a0147204:  90 0b 20 0f  and  %o4, 0xf, %o0
a0147208:  80 a2 20 04  cmp  %o0, 4
a014720c:  02 80 00 5a  be  0xa0147374
a0147210:  01 00 00 00  nop
a0147214:  7f fe bc 6a  call  0xa00f63bc
a0147218:  01 00 00 00  nop
a014721c:  80 a4 20 ff  cmp  %l0, 0xff
a0147220:  02 80 00 55  be  0xa0147374
a0147224:  82 0e 60 ff  and  %i1, 0xff, %g1
a0147228:  80 a0 60 0f  cmp  %g1, 0xf
a014722c:  18 80 00 52  bgu  0xa0147374
a0147230:  11 00 03 8c  sethi  %hi(0xe3000), %o0
a0147234:  b1 28 60 02  sll  %g1, 2, %i0
a0147238:  b2 12 23 98  or  %o0, 0x398, %i1
a014723c:  e0 06 40 18  ld  [ %i1 + %i0 ], %l0
a0147240:  81 c4 00 00  jmp  %l0
a0147244:  01 00 00 00  nop
a0147248:  7f fe 5f ca  call  0xa00df170
a014724c:  90 12 21 d8  or  %o0, 0x1d8, %o0
a0147250:  10 bf ff e6  b  0xa01471e8
a0147254:  a0 10 20 00  clr  %l0
a0147258:  80 a6 20 00  cmp  %i0, 0
a014725c:  02 bf ff df  be  0xa01471d8
a0147260:  82 10 20 00  clr  %g1
a0147264:  10 bf ff dd  b  0xa01471d8
a0147268:  82 10 3f ff  mov  -1, %g1
a014726c:  82 0e a0 ff  and  %i2, 0xff, %g1
a0147270:  80 a0 60 05  cmp  %g1, 5
a0147274:  18 80 00 33  bgu  0xa0147340
a0147278:  b0 10 20 06  mov  6, %i0
a014727c:  1b 00 03 8c  sethi  %hi(0xe3000), %o5
a0147280:  99 28 60 02  sll  %g1, 2, %o4
a0147284:  92 13 63 80  or  %o5, 0x380, %o1
a0147288:  f4 02 40 0c  ld  [ %o1 + %o4 ], %i2
a014728c:  81 c6 80 00  jmp  %i2
a0147290:  01 00 00 00  nop
a0147294:  b2 0e a0 ff  and  %i2, 0xff, %i1
a0147298:  7f fe bd 67  call  0xa00f6834
a014729c:  91 e8 20 08  restore  %g0, 8, %o0
a01472a0:  b2 0e a0 ff  and  %i2, 0xff, %i1
a01472a4:  40 00 26 19  call  0xa0150b08
a01472a8:  91 e8 20 02  restore  %g0, 2, %o0
a01472ac:  b2 0e a0 ff  and  %i2, 0xff, %i1
a01472b0:  40 00 26 16  call  0xa0150b08
a01472b4:  91 e8 20 01  restore  %g0, 1, %o0
a01472b8:  b2 0e a0 ff  and  %i2, 0xff, %i1
a01472bc:  40 00 26 13  call  0xa0150b08
a01472c0:  91 e8 20 00  restore  %g0, 0, %o0
a01472c4:  b0 0e a0 ff  and  %i2, 0xff, %i0
a01472c8:  40 00 25 f4  call  0xa0150a98
a01472cc:  81 e8 00 00  restore
a01472d0:  b0 0e a0 ff  and  %i2, 0xff, %i0
a01472d4:  7f fe bf 30  call  0xa00f6f94
a01472d8:  81 e8 00 00  restore
a01472dc:  b0 0e a0 ff  and  %i2, 0xff, %i0
a01472e0:  7f fe bf 27  call  0xa00f6f7c
a01472e4:  81 e8 00 00  restore
a01472e8:  b0 0e a0 ff  and  %i2, 0xff, %i0
a01472ec:  7f fe bf 1a  call  0xa00f6f54
a01472f0:  81 e8 00 00  restore
a01472f4:  b0 0e a0 ff  and  %i2, 0xff, %i0
a01472f8:  7f fe bf 06  call  0xa00f6f10
a01472fc:  81 e8 00 00  restore
a0147300:  b0 0e a0 ff  and  %i2, 0xff, %i0
a0147304:  7f fe be f2  call  0xa00f6ecc
a0147308:  81 e8 00 00  restore
a014730c:  b0 0e a0 ff  and  %i2, 0xff, %i0
a0147310:  7f fe be de  call  0xa00f6e88
a0147314:  81 e8 00 00  restore
a0147318:  b0 0e a0 ff  and  %i2, 0xff, %i0
a014731c:  7f fe be c5  call  0xa00f6e30
a0147320:  81 e8 00 00  restore
a0147324:  b0 0e a0 ff  and  %i2, 0xff, %i0
a0147328:  7f fe be ac  call  0xa00f6dd8
a014732c:  81 e8 00 00  restore
a0147330:  b0 0e a0 ff  and  %i2, 0xff, %i0
a0147334:  7f fe be 93  call  0xa00f6d80
a0147338:  81 e8 00 00  restore
a014733c:  b0 10 20 05  mov  5, %i0
a0147340:  b0 0e 20 07  and  %i0, 7, %i0
a0147344:  40 00 26 12  call  0xa0150b8c
a0147348:  81 e8 00 00  restore
a014734c:  10 bf ff fd  b  0xa0147340
a0147350:  b0 10 20 04  mov  4, %i0
a0147354:  10 bf ff fb  b  0xa0147340
a0147358:  b0 10 20 03  mov  3, %i0
a014735c:  10 bf ff f9  b  0xa0147340
a0147360:  b0 10 20 02  mov  2, %i0
a0147364:  10 bf ff f7  b  0xa0147340
a0147368:  b0 10 20 00  clr  %i0
a014736c:  10 bf ff f5  b  0xa0147340
a0147370:  b0 10 20 01  mov  1, %i0
a0147374:  81 c7 e0 08  ret
a0147378:  81 e8 00 00  restore
