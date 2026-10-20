# leon2m FUN_a01542c4 0xa01542c4-0xa015440c (328 bytes)
a01542c4:  9d e3 bf 88  save  %sp, -120, %sp
a01542c8:  98 10 20 00  clr  %o4
a01542cc:  9a 10 20 00  clr  %o5
a01542d0:  d8 3f bf f0  std  %o4, [ %fp + -16 ]
a01542d4:  d8 3f bf e8  std  %o4, [ %fp + -24 ]
a01542d8:  a8 10 20 00  clr  %l4
a01542dc:  a0 10 20 00  clr  %l0
a01542e0:  a6 07 bf e8  add  %fp, -24, %l3
a01542e4:  96 0c 20 ff  and  %l0, 0xff, %o3
a01542e8:  95 2a e0 04  sll  %o3, 4, %o2
a01542ec:  90 02 a3 00  add  %o2, 0x300, %o0
a01542f0:  93 2a 20 10  sll  %o0, 0x10, %o1
a01542f4:  a4 10 00 08  mov  %o0, %l2
a01542f8:  93 32 60 10  srl  %o1, 0x10, %o1
a01542fc:  90 10 20 00  clr  %o0
a0154300:  94 10 20 10  mov  0x10, %o2
a0154304:  7f ff b0 17  call  0xa0140360
a0154308:  96 10 00 13  mov  %l3, %o3
a015430c:  c2 16 20 36  lduh  [ %i0 + 0x36 ], %g1
a0154310:  a0 04 20 01  inc  %l0
a0154314:  da 17 bf f6  lduh  [ %fp + -10 ], %o5
a0154318:  98 0c 20 ff  and  %l0, 0xff, %o4
a015431c:  80 a3 40 01  cmp  %o5, %g1
a0154320:  02 80 00 1a  be  0xa0154388
a0154324:  a2 10 00 01  mov  %g1, %l1
a0154328:  80 a3 20 13  cmp  %o4, 0x13
a015432c:  28 bf ff ef  bleu,a   0xa01542e8
a0154330:  96 0c 20 ff  and  %l0, 0xff, %o3
a0154334:  de 0e 20 34  ldub  [ %i0 + 0x34 ], %o7
a0154338:  c2 16 20 08  lduh  [ %i0 + 8 ], %g1
a015433c:  da 16 20 18  lduh  [ %i0 + 0x18 ], %o5
a0154340:  d8 16 20 1a  lduh  [ %i0 + 0x1a ], %o4
a0154344:  d4 16 20 22  lduh  [ %i0 + 0x22 ], %o2
a0154348:  d2 16 20 24  lduh  [ %i0 + 0x24 ], %o1
a015434c:  d0 16 20 26  lduh  [ %i0 + 0x26 ], %o0
a0154350:  e0 0e 20 20  ldub  [ %i0 + 0x20 ], %l0
a0154354:  c2 37 bf e8  sth  %g1, [ %fp + -24 ]
a0154358:  da 37 bf ea  sth  %o5, [ %fp + -22 ]
a015435c:  d8 37 bf ec  sth  %o4, [ %fp + -20 ]
a0154360:  d4 37 bf ee  sth  %o2, [ %fp + -18 ]
a0154364:  d2 37 bf f0  sth  %o1, [ %fp + -16 ]
a0154368:  d0 37 bf f2  sth  %o0, [ %fp + -14 ]
a015436c:  e0 2f bf f4  stb  %l0, [ %fp + -12 ]
a0154370:  de 2f bf f5  stb  %o7, [ %fp + -11 ]
a0154374:  80 8d 20 ff  btst  0xff, %l4
a0154378:  12 80 00 1b  bne  0xa01543e4
a015437c:  e2 37 bf f6  sth  %l1, [ %fp + -10 ]
a0154380:  10 80 00 04  b  0xa0154390
a0154384:  17 2a 00 b8  sethi  %hi(0xa802e000), %o3
a0154388:  10 bf ff eb  b  0xa0154334
a015438c:  a8 10 20 01  mov  1, %l4
a0154390:  96 12 e1 a0  or  %o3, 0x1a0, %o3
a0154394:  e0 0a e0 1a  ldub  [ %o3 + 0x1a ], %l0
a0154398:  23 19 99 99  sethi  %hi(0x66666400), %l1
a015439c:  b0 04 20 01  add  %l0, 1, %i0
a01543a0:  82 14 62 67  or  %l1, 0x267, %g1
a01543a4:  80 5e 00 01  smul  %i0, %g1, %g0
a01543a8:  9b 40 00 00  rd  %y, %o5
a01543ac:  95 3b 60 03  sra  %o5, 3, %o2
a01543b0:  93 2a a0 02  sll  %o2, 2, %o1
a01543b4:  90 02 40 0a  add  %o1, %o2, %o0
a01543b8:  9f 2a 20 02  sll  %o0, 2, %o7
a01543bc:  a4 26 00 0f  sub  %i0, %o7, %l2
a01543c0:  a8 0c 20 ff  and  %l0, 0xff, %l4
a01543c4:  a3 2d 20 04  sll  %l4, 4, %l1
a01543c8:  e4 2a e0 1a  stb  %l2, [ %o3 + 0x1a ]
a01543cc:  a4 04 63 00  add  %l1, 0x300, %l2
a01543d0:  90 10 20 00  clr  %o0
a01543d4:  92 10 24 70  mov  0x470, %o1
a01543d8:  94 10 20 50  mov  0x50, %o2
a01543dc:  7f ff b2 a6  call  0xa0140e74
a01543e0:  98 10 20 00  clr  %o4
a01543e4:  a9 2c a0 10  sll  %l2, 0x10, %l4
a01543e8:  93 35 20 10  srl  %l4, 0x10, %o1
a01543ec:  96 10 00 13  mov  %l3, %o3
a01543f0:  90 10 20 00  clr  %o0
a01543f4:  94 10 20 10  mov  0x10, %o2
a01543f8:  7f ff b2 9f  call  0xa0140e74
a01543fc:  98 10 20 00  clr  %o4
a0154400:  01 00 00 00  nop
a0154404:  81 c7 e0 08  ret
a0154408:  81 e8 00 00  restore
