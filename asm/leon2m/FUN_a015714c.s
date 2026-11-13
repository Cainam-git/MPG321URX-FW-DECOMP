# leon2m FUN_a015714c 0xa015714c-0xa015734c (512 bytes)
a015714c:  9d e3 bf 98  save  %sp, -104, %sp
a0157150:  c2 06 00 00  ld  [ %i0 ], %g1
a0157154:  80 a0 60 01  cmp  %g1, 1
a0157158:  e0 1e 20 10  ldd  [ %i0 + 0x10 ], %l0
a015715c:  e4 06 20 04  ld  [ %i0 + 4 ], %l2
a0157160:  18 80 00 08  bgu  0xa0157180
a0157164:  b2 10 20 00  clr  %i1
a0157168:  19 00 02 00  sethi  %hi(0x80000), %o4
a015716c:  9a 10 20 00  clr  %o5
a0157170:  a0 14 00 0c  or  %l0, %o4, %l0
a0157174:  a2 14 40 0d  or  %l1, %o5, %l1
a0157178:  10 80 00 64  b  0xa0157308
a015717c:  b2 10 27 ff  mov  0x7ff, %i1
a0157180:  80 a0 60 04  cmp  %g1, 4
a0157184:  12 80 00 06  bne  0xa015719c
a0157188:  80 a0 60 02  cmp  %g1, 2
a015718c:  b2 10 27 ff  mov  0x7ff, %i1
a0157190:  a0 10 20 00  clr  %l0
a0157194:  10 80 00 5d  b  0xa0157308
a0157198:  a2 10 20 00  clr  %l1
a015719c:  22 bf ff fe  be,a   0xa0157194
a01571a0:  a0 10 20 00  clr  %l0
a01571a4:  80 94 00 11  orcc  %l0, %l1, %g0
a01571a8:  02 80 00 59  be  0xa015730c
a01571ac:  92 0e 67 ff  and  %i1, 0x7ff, %o1
a01571b0:  d4 06 20 08  ld  [ %i0 + 8 ], %o2
a01571b4:  80 a2 bc 02  cmp  %o2, -1022
a01571b8:  16 80 00 1e  bge  0xa0157230
a01571bc:  80 a2 a3 ff  cmp  %o2, 0x3ff
a01571c0:  82 10 3c 02  mov  -1022, %g1
a01571c4:  b0 20 40 0a  sub  %g1, %o2, %i0
a01571c8:  80 a6 20 38  cmp  %i0, 0x38
a01571cc:  04 80 00 3c  ble  0xa01572bc
a01571d0:  90 10 20 00  clr  %o0
a01571d4:  a0 10 20 00  clr  %l0
a01571d8:  a2 10 20 00  clr  %l1
a01571dc:  98 0c 20 00  and  %l0, 0, %o4
a01571e0:  80 a3 20 00  cmp  %o4, 0
a01571e4:  12 80 00 05  bne  0xa01571f8
a01571e8:  9a 0c 60 ff  and  %l1, 0xff, %o5
a01571ec:  80 a3 60 80  cmp  %o5, 0x80
a01571f0:  02 80 00 29  be  0xa0157294
a01571f4:  9a 0c 61 00  and  %l1, 0x100, %o5
a01571f8:  a2 84 60 7f  addcc  %l1, 0x7f, %l1
a01571fc:  a0 44 20 00  addx  %l0, 0, %l0
a0157200:  03 03 ff ff  sethi  %hi(0xffffc00), %g1
a0157204:  82 10 63 ff  or  %g1, 0x3ff, %g1	! 0xfffffff
a0157208:  80 a4 00 01  cmp  %l0, %g1
a015720c:  38 80 00 02  bgu,a   0xa0157214
a0157210:  b2 10 20 01  mov  1, %i1
a0157214:  97 2c 20 18  sll  %l0, 0x18, %o3
a0157218:  83 34 60 08  srl  %l1, 8, %g1
a015721c:  9a 12 c0 01  or  %o3, %g1, %o5
a0157220:  99 34 20 08  srl  %l0, 8, %o4
a0157224:  a0 10 00 0c  mov  %o4, %l0
a0157228:  10 80 00 38  b  0xa0157308
a015722c:  a2 10 00 0d  mov  %o5, %l1
a0157230:  14 bf ff d8  bg  0xa0157190
a0157234:  b2 10 27 ff  mov  0x7ff, %i1
a0157238:  98 0c 20 00  and  %l0, 0, %o4
a015723c:  9a 0c 60 ff  and  %l1, 0xff, %o5
a0157240:  80 a3 20 00  cmp  %o4, 0
a0157244:  12 80 00 05  bne  0xa0157258
a0157248:  b2 02 a3 ff  add  %o2, 0x3ff, %i1
a015724c:  80 a3 60 80  cmp  %o5, 0x80
a0157250:  02 80 00 16  be  0xa01572a8
a0157254:  9a 0c 61 00  and  %l1, 0x100, %o5
a0157258:  a2 84 60 7f  addcc  %l1, 0x7f, %l1
a015725c:  a0 44 20 00  addx  %l0, 0, %l0
a0157260:  03 07 ff ff  sethi  %hi(0x1ffffc00), %g1
a0157264:  82 10 63 ff  or  %g1, 0x3ff, %g1	! 0x1fffffff
a0157268:  80 a4 00 01  cmp  %l0, %g1
a015726c:  08 bf ff eb  bleu  0xa0157218
a0157270:  97 2c 20 18  sll  %l0, 0x18, %o3
a0157274:  97 2c 20 1f  sll  %l0, 0x1f, %o3
a0157278:  83 34 60 01  srl  %l1, 1, %g1
a015727c:  9a 12 c0 01  or  %o3, %g1, %o5
a0157280:  99 34 20 01  srl  %l0, 1, %o4
a0157284:  a0 10 00 0c  mov  %o4, %l0
a0157288:  a2 10 00 0d  mov  %o5, %l1
a015728c:  10 bf ff e2  b  0xa0157214
a0157290:  b2 06 60 01  inc  %i1
a0157294:  80 93 00 0d  orcc  %o4, %o5, %g0
a0157298:  02 bf ff db  be  0xa0157204
a015729c:  03 03 ff ff  sethi  %hi(0xffffc00), %g1
a01572a0:  10 bf ff d7  b  0xa01571fc
a01572a4:  a2 84 60 80  addcc  %l1, 0x80, %l1
a01572a8:  80 93 00 0d  orcc  %o4, %o5, %g0
a01572ac:  02 bf ff ee  be  0xa0157264
a01572b0:  03 07 ff ff  sethi  %hi(0x1ffffc00), %g1
a01572b4:  10 bf ff ea  b  0xa015725c
a01572b8:  a2 84 60 80  addcc  %l1, 0x80, %l1
a01572bc:  92 10 20 01  mov  1, %o1
a01572c0:  7f ff f7 91  call  0xa0155104
a01572c4:  94 10 00 18  mov  %i0, %o2
a01572c8:  92 82 7f ff  addcc  %o1, -1, %o1
a01572cc:  90 42 3f ff  addx  %o0, -1, %o0
a01572d0:  90 0a 00 10  and  %o0, %l0, %o0
a01572d4:  92 0a 40 11  and  %o1, %l1, %o1
a01572d8:  80 92 00 09  orcc  %o0, %o1, %g0
a01572dc:  02 80 00 03  be  0xa01572e8
a01572e0:  a6 10 20 00  clr  %l3
a01572e4:  a6 10 20 01  mov  1, %l3
a01572e8:  90 10 00 10  mov  %l0, %o0
a01572ec:  92 10 00 11  mov  %l1, %o1
a01572f0:  7f ff f7 6e  call  0xa01550a8
a01572f4:  94 10 00 18  mov  %i0, %o2
a01572f8:  98 10 20 00  clr  %o4
a01572fc:  a0 12 00 0c  or  %o0, %o4, %l0
a0157300:  10 bf ff b7  b  0xa01571dc
a0157304:  a2 12 40 13  or  %o1, %l3, %l1
a0157308:  92 0e 67 ff  and  %i1, 0x7ff, %o1
a015730c:  19 00 03 ff  sethi  %hi(0xffc00), %o4
a0157310:  96 0c a0 01  and  %l2, 1, %o3
a0157314:  91 2a 60 14  sll  %o1, 0x14, %o0
a0157318:  98 13 23 ff  or  %o4, 0x3ff, %o4
a015731c:  9a 10 3f ff  mov  -1, %o5
a0157320:  95 2a e0 1f  sll  %o3, 0x1f, %o2
a0157324:  92 10 20 00  clr  %o1
a0157328:  98 0c 00 0c  and  %l0, %o4, %o4
a015732c:  9a 0c 40 0d  and  %l1, %o5, %o5
a0157330:  96 10 20 00  clr  %o3
a0157334:  98 13 00 08  or  %o4, %o0, %o4
a0157338:  9a 13 40 09  or  %o5, %o1, %o5
a015733c:  b0 13 00 0a  or  %o4, %o2, %i0
a0157340:  b2 13 40 0b  or  %o5, %o3, %i1
a0157344:  81 c7 e0 08  ret
a0157348:  81 e8 00 00  restore
