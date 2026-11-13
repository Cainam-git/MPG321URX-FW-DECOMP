# leon2m FUN_a012127c 0xa012127c-0xa0121374 (248 bytes)
a012127c:  9d e3 bf 98  save  %sp, -104, %sp
a0121280:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0121284:  92 10 20 04  mov  4, %o1
a0121288:  7f ff 42 02  call  0xa00f1a90
a012128c:  90 10 00 18  mov  %i0, %o0
a0121290:  a0 0a 20 0f  and  %o0, 0xf, %l0
a0121294:  7f ff 71 63  call  0xa00fd820
a0121298:  90 10 00 18  mov  %i0, %o0
a012129c:  90 0a 20 ff  and  %o0, 0xff, %o0
a01212a0:  80 a2 20 71  cmp  %o0, 0x71
a01212a4:  02 80 00 32  be  0xa012136c
a01212a8:  01 00 00 00  nop
a01212ac:  7f ff 71 5d  call  0xa00fd820
a01212b0:  90 10 00 18  mov  %i0, %o0
a01212b4:  82 0a 20 ff  and  %o0, 0xff, %g1
a01212b8:  80 a0 60 81  cmp  %g1, 0x81
a01212bc:  02 80 00 2c  be  0xa012136c
a01212c0:  01 00 00 00  nop
a01212c4:  7f ff 71 57  call  0xa00fd820
a01212c8:  90 10 00 18  mov  %i0, %o0
a01212cc:  92 0a 20 ff  and  %o0, 0xff, %o1
a01212d0:  80 a2 60 b1  cmp  %o1, 0xb1
a01212d4:  02 80 00 26  be  0xa012136c
a01212d8:  80 8e a0 ff  btst  0xff, %i2
a01212dc:  12 80 00 06  bne  0xa01212f4
a01212e0:  b4 10 3f 80  mov  -128, %i2
a01212e4:  b4 14 00 1a  or  %l0, %i2, %i2
a01212e8:  b4 0e a0 ff  and  %i2, 0xff, %i2
a01212ec:  7f ff 41 fa  call  0xa00f1ad4
a01212f0:  93 e8 20 04  restore  %g0, 4, %o1
a01212f4:  7f ff 71 4b  call  0xa00fd820
a01212f8:  90 10 00 18  mov  %i0, %o0
a01212fc:  94 0a 20 ff  and  %o0, 0xff, %o2
a0121300:  80 a2 a0 91  cmp  %o2, 0x91
a0121304:  02 80 00 14  be  0xa0121354
a0121308:  97 2e 60 10  sll  %i1, 0x10, %o3
a012130c:  83 32 e0 10  srl  %o3, 0x10, %g1
a0121310:  80 a0 63 b3  cmp  %g1, 0x3b3
a0121314:  08 80 00 0c  bleu  0xa0121344
a0121318:  80 a0 61 de  cmp  %g1, 0x1de
a012131c:  b4 10 3f f0  mov  -16, %i2
a0121320:  90 10 00 18  mov  %i0, %o0
a0121324:  7f ff 43 1e  call  0xa00f1f9c
a0121328:  92 10 20 1a  mov  0x1a, %o1
a012132c:  98 0a 20 ff  and  %o0, 0xff, %o4
a0121330:  80 a3 20 1f  cmp  %o4, 0x1f
a0121334:  38 bf ff ec  bgu,a   0xa01212e4
a0121338:  b4 06 80 1a  add  %i2, %i2, %i2
a012133c:  10 bf ff eb  b  0xa01212e8
a0121340:  b4 14 00 1a  or  %l0, %i2, %i2
a0121344:  08 80 00 06  bleu  0xa012135c
a0121348:  80 a0 60 f4  cmp  %g1, 0xf4
a012134c:  10 bf ff f5  b  0xa0121320
a0121350:  b4 10 3f e0  mov  -32, %i2
a0121354:  10 bf ff e4  b  0xa01212e4
a0121358:  b4 10 3f e0  mov  -32, %i2
a012135c:  38 bf ff f1  bgu,a   0xa0121320
a0121360:  b4 10 3f c0  mov  -64, %i2
a0121364:  10 bf ff f0  b  0xa0121324
a0121368:  90 10 00 18  mov  %i0, %o0
a012136c:  81 c7 e0 08  ret
a0121370:  81 e8 00 00  restore
