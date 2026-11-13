# leon2m FUN_a014a4d8 0xa014a4d8-0xa014a588 (176 bytes)
a014a4d8:  9d e3 bf 98  save  %sp, -104, %sp
a014a4dc:  7f ff 6b 2f  call  0xa0125198
a014a4e0:  90 0e 20 ff  and  %i0, 0xff, %o0
a014a4e4:  7f ff df 4d  call  0xa0142218
a014a4e8:  90 0a 20 ff  and  %o0, 0xff, %o0
a014a4ec:  7f ff df 36  call  0xa01421c4
a014a4f0:  90 0a 20 ff  and  %o0, 0xff, %o0
a014a4f4:  82 0a 20 ff  and  %o0, 0xff, %g1
a014a4f8:  b0 10 20 00  clr  %i0
a014a4fc:  90 10 20 10  mov  0x10, %o0
a014a500:  80 a0 60 71  cmp  %g1, 0x71
a014a504:  02 80 00 1b  be  0xa014a570
a014a508:  92 10 20 01  mov  1, %o1
a014a50c:  80 a0 60 81  cmp  %g1, 0x81
a014a510:  02 80 00 15  be  0xa014a564
a014a514:  b0 10 3f ff  mov  -1, %i0
a014a518:  82 0e 60 ff  and  %i1, 0xff, %g1
a014a51c:  9a 18 60 02  xor  %g1, 2, %o5
a014a520:  98 0e 20 ff  and  %i0, 0xff, %o4
a014a524:  80 a0 60 01  cmp  %g1, 1
a014a528:  90 10 00 0c  mov  %o4, %o0
a014a52c:  b2 10 20 00  clr  %i1
a014a530:  02 80 00 06  be  0xa014a548
a014a534:  82 10 20 01  mov  1, %g1
a014a538:  80 a0 00 0d  cmp  %g0, %o5
a014a53c:  92 60 3f ff  subx  %g0, -1, %o1
a014a540:  9a 02 40 09  add  %o1, %o1, %o5
a014a544:  82 10 00 0d  mov  %o5, %g1
a014a548:  80 a3 20 ff  cmp  %o4, 0xff
a014a54c:  02 80 00 0d  be  0xa014a580
a014a550:  92 08 60 03  and  %g1, 3, %o1
a014a554:  7f ff 82 c9  call  0xa012b078
a014a558:  31 2a 00 b8  sethi  %hi(0xa802e000), %i0
a014a55c:  40 00 25 05  call  0xa0153970
a014a560:  91 ee 21 a0  restore  %i0, 0x1a0, %o0
a014a564:  b0 10 20 01  mov  1, %i0
a014a568:  90 10 20 20  mov  0x20, %o0
a014a56c:  92 10 20 01  mov  1, %o1
a014a570:  40 00 1d 4d  call  0xa0151aa4
a014a574:  01 00 00 00  nop
a014a578:  10 bf ff e9  b  0xa014a51c
a014a57c:  82 0e 60 ff  and  %i1, 0xff, %g1
a014a580:  81 c7 e0 08  ret
a014a584:  81 e8 00 00  restore
