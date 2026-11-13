# leon2m FUN_a011023c 0xa011023c-0xa0110318 (220 bytes)
a011023c:  9d e3 bf 98  save  %sp, -104, %sp
a0110240:  03 2a 00 9e  sethi  %hi(0xa8027800), %g1
a0110244:  da 08 62 88  ldub  [ %g1 + 0x288 ], %o5	! 0xa8027a88
a0110248:  80 a3 60 01  cmp  %o5, 1
a011024c:  12 80 00 31  bne  0xa0110310
a0110250:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0110254:  80 a6 20 08  cmp  %i0, 8
a0110258:  02 80 00 2c  be  0xa0110308
a011025c:  80 a6 20 00  cmp  %i0, 0
a0110260:  12 80 00 14  bne  0xa01102b0
a0110264:  80 a6 20 01  cmp  %i0, 1
a0110268:  11 34 00 ec  sethi  %hi(0xd003b000), %o0
a011026c:  da 22 00 00  st  %o5, [ %o0 ]
a0110270:  67 fd f4 c6  call  0x4008d588
a0110274:  21 34 00 ec  sethi  %hi(0xd003b000), %l0
a0110278:  b0 10 00 08  mov  %o0, %i0
a011027c:  d2 04 00 00  ld  [ %l0 ], %o1
a0110280:  80 a2 60 00  cmp  %o1, 0
a0110284:  02 80 00 23  be  0xa0110310
a0110288:  01 00 00 00  nop
a011028c:  67 fd f4 bf  call  0x4008d588
a0110290:  01 00 00 00  nop
a0110294:  98 22 00 18  sub  %o0, %i0, %o4
a0110298:  97 2b 20 10  sll  %o4, 0x10, %o3
a011029c:  95 32 e0 10  srl  %o3, 0x10, %o2
a01102a0:  80 a2 a0 63  cmp  %o2, 0x63
a01102a4:  08 bf ff f6  bleu  0xa011027c
a01102a8:  01 00 00 00  nop
a01102ac:  30 80 00 19  b,a   0xa0110310
a01102b0:  02 bf ff ee  be  0xa0110268
a01102b4:  9a 10 20 02  mov  2, %o5
a01102b8:  80 a6 20 02  cmp  %i0, 2
a01102bc:  02 bf ff eb  be  0xa0110268
a01102c0:  9a 10 20 04  mov  4, %o5
a01102c4:  80 a6 20 03  cmp  %i0, 3
a01102c8:  02 bf ff e8  be  0xa0110268
a01102cc:  9a 10 20 08  mov  8, %o5
a01102d0:  80 a6 20 04  cmp  %i0, 4
a01102d4:  02 bf ff e5  be  0xa0110268
a01102d8:  9a 10 20 10  mov  0x10, %o5
a01102dc:  80 a6 20 05  cmp  %i0, 5
a01102e0:  02 bf ff e2  be  0xa0110268
a01102e4:  9a 10 20 20  mov  0x20, %o5
a01102e8:  80 a6 20 06  cmp  %i0, 6
a01102ec:  02 bf ff df  be  0xa0110268
a01102f0:  9a 10 20 40  mov  0x40, %o5
a01102f4:  80 a6 20 07  cmp  %i0, 7
a01102f8:  12 bf ff de  bne  0xa0110270
a01102fc:  9a 10 21 00  mov  0x100, %o5
a0110300:  10 bf ff db  b  0xa011026c
a0110304:  11 34 00 ec  sethi  %hi(0xd003b000), %o0
a0110308:  10 bf ff d8  b  0xa0110268
a011030c:  9a 10 21 ff  mov  0x1ff, %o5
a0110310:  81 c7 e0 08  ret
a0110314:  81 e8 00 00  restore
