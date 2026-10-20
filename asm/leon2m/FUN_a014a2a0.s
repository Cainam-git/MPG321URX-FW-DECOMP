# leon2m FUN_a014a2a0 0xa014a2a0-0xa014a388 (232 bytes)
a014a2a0:  9a 0a 20 ff  and  %o0, 0xff, %o5
a014a2a4:  82 0a 60 ff  and  %o1, 0xff, %g1
a014a2a8:  90 58 60 c8  smul  %g1, 0xc8, %o0
a014a2ac:  03 14 7a e1  sethi  %hi(0x51eb8400), %g1
a014a2b0:  82 10 61 1f  or  %g1, 0x11f, %g1	! 0x51eb851f
a014a2b4:  90 02 20 32  add  %o0, 0x32, %o0
a014a2b8:  80 52 00 01  umul  %o0, %g1, %g0
a014a2bc:  91 40 00 00  rd  %y, %o0
a014a2c0:  83 32 20 05  srl  %o0, 5, %g1
a014a2c4:  90 00 60 1c  add  %g1, 0x1c, %o0
a014a2c8:  80 a3 60 01  cmp  %o5, 1
a014a2cc:  02 80 00 09  be  0xa014a2f0
a014a2d0:  90 0a 20 ff  and  %o0, 0xff, %o0
a014a2d4:  80 a3 60 01  cmp  %o5, 1
a014a2d8:  04 80 00 18  ble  0xa014a338
a014a2dc:  80 a3 60 02  cmp  %o5, 2
a014a2e0:  12 80 00 27  bne  0xa014a37c
a014a2e4:  9a 0a 60 ff  and  %o1, 0xff, %o5
a014a2e8:  10 80 00 07  b  0xa014a304
a014a2ec:  90 5b 60 c8  smul  %o5, 0xc8, %o0
a014a2f0:  03 2a 00 b8  sethi  %hi(0xa802e000), %g1
a014a2f4:  d2 28 63 e0  stb  %o1, [ %g1 + 0x3e0 ]	! 0xa802e3e0
a014a2f8:  82 13 c0 00  mov  %o7, %g1
a014a2fc:  7f ff c4 a9  call  0xa013b5a0
a014a300:  9e 10 40 00  mov  %g1, %o7
a014a304:  19 14 7a e1  sethi  %hi(0x51eb8400), %o4
a014a308:  9a 02 20 32  add  %o0, 0x32, %o5
a014a30c:  82 13 21 1f  or  %o4, 0x11f, %g1
a014a310:  80 53 40 01  umul  %o5, %g1, %g0
a014a314:  99 40 00 00  rd  %y, %o4
a014a318:  91 33 20 05  srl  %o4, 5, %o0
a014a31c:  98 02 20 1c  add  %o0, 0x1c, %o4
a014a320:  1b 2a 00 b8  sethi  %hi(0xa802e000), %o5
a014a324:  d2 2b 63 e1  stb  %o1, [ %o5 + 0x3e1 ]	! 0xa802e3e1
a014a328:  90 0b 20 ff  and  %o4, 0xff, %o0
a014a32c:  82 13 c0 00  mov  %o7, %g1
a014a330:  7f ff c4 85  call  0xa013b544
a014a334:  9e 10 40 00  mov  %g1, %o7
a014a338:  80 a3 60 00  cmp  %o5, 0
a014a33c:  12 80 00 10  bne  0xa014a37c
a014a340:  9a 0a 60 ff  and  %o1, 0xff, %o5
a014a344:  90 5b 60 c8  smul  %o5, 0xc8, %o0
a014a348:  19 14 7a e1  sethi  %hi(0x51eb8400), %o4
a014a34c:  9a 02 20 32  add  %o0, 0x32, %o5
a014a350:  82 13 21 1f  or  %o4, 0x11f, %g1
a014a354:  80 53 40 01  umul  %o5, %g1, %g0
a014a358:  99 40 00 00  rd  %y, %o4
a014a35c:  91 33 20 05  srl  %o4, 5, %o0
a014a360:  98 02 20 1c  add  %o0, 0x1c, %o4
a014a364:  1b 2a 00 b8  sethi  %hi(0xa802e000), %o5
a014a368:  d2 2b 63 df  stb  %o1, [ %o5 + 0x3df ]	! 0xa802e3df
a014a36c:  90 0b 20 ff  and  %o4, 0xff, %o0
a014a370:  82 13 c0 00  mov  %o7, %g1
a014a374:  7f ff c4 a2  call  0xa013b5fc
a014a378:  9e 10 40 00  mov  %g1, %o7
a014a37c:  01 00 00 00  nop
a014a380:  81 c3 e0 08  retl
a014a384:  01 00 00 00  nop
