# leon2m FUN_a0124244 0xa0124244-0xa01243b0 (364 bytes)
a0124244:  9d e3 bf 98  save  %sp, -104, %sp
a0124248:  40 00 1a c9  call  0xa012ad6c
a012424c:  a4 10 20 02  mov  2, %l2
a0124250:  90 0a 20 ff  and  %o0, 0xff, %o0
a0124254:  80 a2 20 01  cmp  %o0, 1
a0124258:  02 80 00 04  be  0xa0124268
a012425c:  a8 10 20 00  clr  %l4
a0124260:  a8 10 20 01  mov  1, %l4
a0124264:  a4 10 20 03  mov  3, %l2
a0124268:  82 0e 20 ff  and  %i0, 0xff, %g1
a012426c:  80 a0 60 01  cmp  %g1, 1
a0124270:  02 80 00 45  be  0xa0124384
a0124274:  92 10 3f ff  mov  -1, %o1
a0124278:  40 00 06 47  call  0xa0125b94
a012427c:  01 00 00 00  nop
a0124280:  80 8a 20 ff  btst  0xff, %o0
a0124284:  12 80 00 25  bne  0xa0124318
a0124288:  82 10 20 00  clr  %g1
a012428c:  40 00 06 2e  call  0xa0125b44
a0124290:  a6 10 00 01  mov  %g1, %l3
a0124294:  2b 2a 00 a9  sethi  %hi(0xa802a400), %l5
a0124298:  d4 0d 60 20  ldub  [ %l5 + 0x20 ], %o2	! 0xa802a420
a012429c:  a0 0c e0 ff  and  %l3, 0xff, %l0
a01242a0:  a2 10 00 08  mov  %o0, %l1
a01242a4:  80 a2 80 10  cmp  %o2, %l0
a01242a8:  2d 2a 00 a9  sethi  %hi(0xa802a400), %l6
a01242ac:  02 80 00 26  be  0xa0124344
a01242b0:  b0 0a 20 ff  and  %o0, 0xff, %i0
a01242b4:  a4 0c a0 ff  and  %l2, 0xff, %l2
a01242b8:  90 10 00 12  mov  %l2, %o0
a01242bc:  40 00 4d 6a  call  0xa0137864
a01242c0:  92 10 20 01  mov  1, %o1
a01242c4:  80 a6 20 01  cmp  %i0, 1
a01242c8:  02 80 00 29  be  0xa012436c
a01242cc:  80 a4 20 02  cmp  %l0, 2
a01242d0:  02 80 00 32  be  0xa0124398
a01242d4:  92 10 3f c9  mov  -55, %o1
a01242d8:  80 a4 20 02  cmp  %l0, 2
a01242dc:  96 10 20 00  clr  %o3
a01242e0:  02 80 00 26  be  0xa0124378
a01242e4:  94 10 20 00  clr  %o2
a01242e8:  90 0d 20 01  and  %l4, 1, %o0
a01242ec:  92 0a 60 ff  and  %o1, 0xff, %o1
a01242f0:  94 0a a0 0f  and  %o2, 0xf, %o2
a01242f4:  96 0a e0 01  and  %o3, 1, %o3
a01242f8:  40 00 1c 48  call  0xa012b418
a01242fc:  98 10 20 01  mov  1, %o4
a0124300:  90 10 00 12  mov  %l2, %o0
a0124304:  40 00 4d 58  call  0xa0137864
a0124308:  92 10 20 02  mov  2, %o1
a012430c:  e6 2d 60 20  stb  %l3, [ %l5 + 0x20 ]
a0124310:  10 80 00 26  b  0xa01243a8
a0124314:  e2 2d a0 21  stb  %l1, [ %l6 + 0x21 ]
a0124318:  82 10 20 02  mov  2, %g1
a012431c:  40 00 06 0a  call  0xa0125b44
a0124320:  a6 10 00 01  mov  %g1, %l3
a0124324:  2b 2a 00 a9  sethi  %hi(0xa802a400), %l5
a0124328:  d4 0d 60 20  ldub  [ %l5 + 0x20 ], %o2	! 0xa802a420
a012432c:  a0 0c e0 ff  and  %l3, 0xff, %l0
a0124330:  a2 10 00 08  mov  %o0, %l1
a0124334:  80 a2 80 10  cmp  %o2, %l0
a0124338:  2d 2a 00 a9  sethi  %hi(0xa802a400), %l6
a012433c:  12 bf ff de  bne  0xa01242b4
a0124340:  b0 0a 20 ff  and  %o0, 0xff, %i0
a0124344:  d6 0d a0 21  ldub  [ %l6 + 0x21 ], %o3
a0124348:  80 a2 c0 18  cmp  %o3, %i0
a012434c:  02 80 00 17  be  0xa01243a8
a0124350:  a4 0c a0 ff  and  %l2, 0xff, %l2
a0124354:  90 10 00 12  mov  %l2, %o0
a0124358:  40 00 4d 43  call  0xa0137864
a012435c:  92 10 20 01  mov  1, %o1
a0124360:  80 a6 20 01  cmp  %i0, 1
a0124364:  12 bf ff db  bne  0xa01242d0
a0124368:  80 a4 20 02  cmp  %l0, 2
a012436c:  12 bf ff db  bne  0xa01242d8
a0124370:  92 10 20 63  mov  0x63, %o1
a0124374:  92 10 20 36  mov  0x36, %o1
a0124378:  96 10 20 01  mov  1, %o3
a012437c:  10 bf ff db  b  0xa01242e8
a0124380:  94 10 20 0f  mov  0xf, %o2
a0124384:  1b 2a 00 a9  sethi  %hi(0xa802a400), %o5
a0124388:  19 2a 00 a9  sethi  %hi(0xa802a400), %o4
a012438c:  d2 2b 60 21  stb  %o1, [ %o5 + 0x21 ]
a0124390:  10 80 00 06  b  0xa01243a8
a0124394:  d2 2b 20 20  stb  %o1, [ %o4 + 0x20 ]
a0124398:  92 10 3f 9c  mov  -100, %o1
a012439c:  96 10 20 01  mov  1, %o3
a01243a0:  10 bf ff d2  b  0xa01242e8
a01243a4:  94 10 20 0f  mov  0xf, %o2
a01243a8:  81 c7 e0 08  ret
a01243ac:  81 e8 00 00  restore
