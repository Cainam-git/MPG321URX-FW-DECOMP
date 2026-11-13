# leon2m FUN_a01131d4 0xa01131d4-0xa011337c (424 bytes)  [FUN_a0113374 = unreachable ret/restore tail, merged]
a01131d4:  9d e3 bf 98  save  %sp, -104, %sp
a01131d8:  19 2a 00 9e  sethi  %hi(0xa8027800), %o4
a01131dc:  da 0b 22 94  ldub  [ %o4 + 0x294 ], %o5	! 0xa8027a94
a01131e0:  82 0e 20 ff  and  %i0, 0xff, %g1
a01131e4:  80 a3 40 01  cmp  %o5, %g1
a01131e8:  02 80 00 62  be  0xa0113370
a01131ec:  25 33 c0 46  sethi  %hi(0xcf011800), %l2
a01131f0:  a2 14 a2 00  or  %l2, 0x200, %l1	! 0xcf011a00
a01131f4:  d0 04 40 00  ld  [ %l1 ], %o0
a01131f8:  e0 04 40 00  ld  [ %l1 ], %l0
a01131fc:  29 2a 00 b2  sethi  %hi(0xa802c800), %l4
a0113200:  f0 2b 22 94  stb  %i0, [ %o4 + 0x294 ]
a0113204:  f0 2d 21 8f  stb  %i0, [ %l4 + 0x18f ]
a0113208:  ac 10 00 08  mov  %o0, %l6
a011320c:  40 00 14 d4  call  0xa011855c
a0113210:  a6 0c 20 ff  and  %l0, 0xff, %l3
a0113214:  a0 10 20 00  clr  %l0
a0113218:  b0 10 20 00  clr  %i0
a011321c:  10 80 00 06  b  0xa0113234
a0113220:  aa 10 20 01  mov  1, %l5
a0113224:  b0 0c 20 ff  and  %l0, 0xff, %i0
a0113228:  80 a6 20 04  cmp  %i0, 4
a011322c:  18 80 00 17  bgu  0xa0113288
a0113230:  90 10 20 32  mov  0x32, %o0
a0113234:  95 3c c0 18  sra  %l3, %i0, %o2
a0113238:  90 10 00 18  mov  %i0, %o0
a011323c:  92 10 20 01  mov  1, %o1
a0113240:  80 8a a0 01  btst  1, %o2
a0113244:  02 bf ff f8  be  0xa0113224
a0113248:  a0 04 20 01  inc  %l0
a011324c:  67 fd ec 5e  call  0x4008e3c4
a0113250:  01 00 00 00  nop
a0113254:  83 2d 40 18  sll  %l5, %i0, %g1
a0113258:  f0 04 80 00  ld  [ %l2 ], %i0
a011325c:  96 38 00 01  xnor  %g0, %g1, %o3
a0113260:  9e 0e 00 0b  and  %i0, %o3, %o7
a0113264:  de 24 80 00  st  %o7, [ %l2 ]
a0113268:  d2 04 40 00  ld  [ %l1 ], %o1
a011326c:  98 0a 40 0b  and  %o1, %o3, %o4
a0113270:  b0 0c 20 ff  and  %l0, 0xff, %i0
a0113274:  d8 24 40 00  st  %o4, [ %l1 ]
a0113278:  80 a6 20 04  cmp  %i0, 4
a011327c:  08 bf ff ef  bleu  0xa0113238
a0113280:  95 3c c0 18  sra  %l3, %i0, %o2
a0113284:  90 10 20 32  mov  0x32, %o0
a0113288:  67 fd e7 c6  call  0x4008d1a0
a011328c:  27 33 c0 47  sethi  %hi(0xcf011c00), %l3
a0113290:  a4 14 e1 8c  or  %l3, 0x18c, %l2	! 0xcf011d8c
a0113294:  23 00 06 9a  sethi  %hi(0x1a6800), %l1
a0113298:  c0 24 80 00  clr  [ %l2 ]
a011329c:  a4 14 62 dc  or  %l1, 0x2dc, %l2
a01132a0:  a0 10 20 00  clr  %l0
a01132a4:  90 10 20 00  clr  %o0
a01132a8:  23 2a 00 b2  sethi  %hi(0xa802c800), %l1
a01132ac:  d2 0c 61 8e  ldub  [ %l1 + 0x18e ], %o1	! 0xa802c98e
a01132b0:  d6 0d 21 8f  ldub  [ %l4 + 0x18f ], %o3
a01132b4:  9a 5a 60 2c  smul  %o1, 0x2c, %o5
a01132b8:  98 5a e0 16  smul  %o3, 0x16, %o4
a01132bc:  94 03 00 0d  add  %o4, %o5, %o2
a01132c0:  aa 02 80 12  add  %o2, %l2, %l5
a01132c4:  7f ff f9 82  call  0xa01118cc
a01132c8:  d2 0d 40 08  ldub  [ %l5 + %o0 ], %o1
a01132cc:  a0 04 20 01  inc  %l0
a01132d0:  90 0c 20 ff  and  %l0, 0xff, %o0
a01132d4:  80 a2 20 05  cmp  %o0, 5
a01132d8:  08 bf ff f6  bleu  0xa01132b0
a01132dc:  d2 0c 61 8e  ldub  [ %l1 + 0x18e ], %o1
a01132e0:  7f ff fe 13  call  0xa0112b2c
a01132e4:  27 33 c0 46  sethi  %hi(0xcf011800), %l3
a01132e8:  a4 0d a0 ff  and  %l6, 0xff, %l2
a01132ec:  a2 10 20 00  clr  %l1
a01132f0:  a0 10 20 00  clr  %l0
a01132f4:  a8 10 20 01  mov  1, %l4
a01132f8:  10 80 00 06  b  0xa0113310
a01132fc:  b0 14 e2 00  or  %l3, 0x200, %i0
a0113300:  a0 0c 60 ff  and  %l1, 0xff, %l0
a0113304:  80 a4 20 04  cmp  %l0, 4
a0113308:  18 80 00 16  bgu  0xa0113360
a011330c:  80 8c a0 20  btst  0x20, %l2
a0113310:  ad 3c 80 10  sra  %l2, %l0, %l6
a0113314:  90 10 00 10  mov  %l0, %o0
a0113318:  92 10 20 00  clr  %o1
a011331c:  80 8d a0 01  btst  1, %l6
a0113320:  02 bf ff f8  be  0xa0113300
a0113324:  a2 04 60 01  inc  %l1
a0113328:  67 fd ec 27  call  0x4008e3c4
a011332c:  01 00 00 00  nop
a0113330:  ea 04 c0 00  ld  [ %l3 ], %l5
a0113334:  9f 2d 00 10  sll  %l4, %l0, %o7
a0113338:  82 15 40 0f  or  %l5, %o7, %g1
a011333c:  c2 24 c0 00  st  %g1, [ %l3 ]
a0113340:  d0 06 00 00  ld  [ %i0 ], %o0
a0113344:  a0 12 00 0f  or  %o0, %o7, %l0
a0113348:  e0 26 00 00  st  %l0, [ %i0 ]
a011334c:  a0 0c 60 ff  and  %l1, 0xff, %l0
a0113350:  80 a4 20 04  cmp  %l0, 4
a0113354:  08 bf ff f0  bleu  0xa0113314
a0113358:  ad 3c 80 10  sra  %l2, %l0, %l6
a011335c:  80 8c a0 20  btst  0x20, %l2
a0113360:  02 80 00 04  be  0xa0113370
a0113364:  01 00 00 00  nop
a0113368:  40 00 14 9b  call  0xa01185d4
a011336c:  81 e8 00 00  restore
a0113370:  01 00 00 00  nop
a0113374:  81 c7 e0 08  ret
a0113378:  81 e8 00 00  restore
