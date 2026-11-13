# leon2m FUN_a0148268 0xa0148268-0xa0148350 (232 bytes)
a0148268:  9d e3 bf 98  save  %sp, -104, %sp
a014826c:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0148270:  80 a6 20 01  cmp  %i0, 1
a0148274:  02 80 00 0b  be  0xa01482a0
a0148278:  82 10 20 01  mov  1, %g1
a014827c:  80 a6 20 01  cmp  %i0, 1
a0148280:  04 80 00 23  ble  0xa014830c
a0148284:  80 a6 20 02  cmp  %i0, 2
a0148288:  02 80 00 06  be  0xa01482a0
a014828c:  82 10 20 02  mov  2, %g1
a0148290:  80 a6 20 03  cmp  %i0, 3
a0148294:  02 80 00 03  be  0xa01482a0
a0148298:  82 10 20 03  mov  3, %g1
a014829c:  82 10 3f ff  mov  -1, %g1
a01482a0:  90 10 00 01  mov  %g1, %o0
a01482a4:  82 08 60 ff  and  %g1, 0xff, %g1
a01482a8:  80 a0 60 03  cmp  %g1, 3
a01482ac:  38 80 00 0e  bgu,a   0xa01482e4
a01482b0:  11 00 06 9b  sethi  %hi(0x1a6c00), %o0
a01482b4:  b2 0e 60 ff  and  %i1, 0xff, %i1
a01482b8:  80 a6 60 00  cmp  %i1, 0
a01482bc:  22 80 00 11  be,a   0xa0148300
a01482c0:  90 0a 20 ff  and  %o0, 0xff, %o0
a01482c4:  80 a6 60 01  cmp  %i1, 1
a01482c8:  02 80 00 18  be  0xa0148328
a01482cc:  80 a6 60 02  cmp  %i1, 2
a01482d0:  02 80 00 1a  be  0xa0148338
a01482d4:  80 a6 60 03  cmp  %i1, 3
a01482d8:  12 80 00 1b  bne  0xa0148344
a01482dc:  b0 0a 20 ff  and  %o0, 0xff, %i0
a01482e0:  30 80 00 10  b,a   0xa0148320
a01482e4:  7f fe 5b a3  call  0xa00df170
a01482e8:  90 12 21 d8  or  %o0, 0x1d8, %o0
a01482ec:  b2 0e 60 ff  and  %i1, 0xff, %i1
a01482f0:  80 a6 60 00  cmp  %i1, 0
a01482f4:  12 bf ff f4  bne  0xa01482c4
a01482f8:  90 10 20 00  clr  %o0
a01482fc:  90 0a 20 ff  and  %o0, 0xff, %o0
a0148300:  7f ff 9b bb  call  0xa012f1ec
a0148304:  92 10 20 00  clr  %o1
a0148308:  30 80 00 0f  b,a   0xa0148344
a014830c:  80 a6 20 00  cmp  %i0, 0
a0148310:  02 bf ff e4  be  0xa01482a0
a0148314:  82 10 20 00  clr  %g1
a0148318:  10 bf ff e2  b  0xa01482a0
a014831c:  82 10 3f ff  mov  -1, %g1
a0148320:  7f ff 9b b3  call  0xa012f1ec
a0148324:  81 e8 00 00  restore
a0148328:  90 0a 20 ff  and  %o0, 0xff, %o0
a014832c:  7f ff 9b b0  call  0xa012f1ec
a0148330:  92 10 20 01  mov  1, %o1
a0148334:  30 80 00 04  b,a   0xa0148344
a0148338:  90 0a 20 ff  and  %o0, 0xff, %o0
a014833c:  7f ff 9b ac  call  0xa012f1ec
a0148340:  92 10 20 02  mov  2, %o1
a0148344:  01 00 00 00  nop
a0148348:  81 c7 e0 08  ret
a014834c:  81 e8 00 00  restore
