# leon2s FUN_a00901a0 0xa00901a0-0xa0090374 (468 bytes)
a00901a0:  9d e3 bf 98  save  %sp, -104, %sp
a00901a4:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00901a8:  7f ff ff 40  call  0xa008fea8
a00901ac:  90 10 00 18  mov  %i0, %o0
a00901b0:  80 8a 20 ff  btst  0xff, %o0
a00901b4:  02 80 00 53  be  0xa0090300
a00901b8:  a0 10 20 01  mov  1, %l0
a00901bc:  90 10 00 18  mov  %i0, %o0
a00901c0:  40 00 58 ef  call  0xa00a657c
a00901c4:  92 10 21 45  mov  0x145, %o1
a00901c8:  90 0a 20 c0  and  %o0, 0xc0, %o0
a00901cc:  80 a2 20 c0  cmp  %o0, 0xc0
a00901d0:  12 80 00 1b  bne  0xa009023c
a00901d4:  a0 10 20 02  mov  2, %l0
a00901d8:  90 10 00 18  mov  %i0, %o0
a00901dc:  40 00 58 e8  call  0xa00a657c
a00901e0:  92 10 21 46  mov  0x146, %o1
a00901e4:  90 0a 20 70  and  %o0, 0x70, %o0
a00901e8:  80 a2 20 10  cmp  %o0, 0x10
a00901ec:  12 80 00 04  bne  0xa00901fc
a00901f0:  a0 10 20 0e  mov  0xe, %l0
a00901f4:  10 80 00 19  b  0xa0090258
a00901f8:  a0 10 20 14  mov  0x14, %l0
a00901fc:  7f ff ff 43  call  0xa008ff08
a0090200:  90 10 00 18  mov  %i0, %o0
a0090204:  90 0a 20 ff  and  %o0, 0xff, %o0
a0090208:  80 a2 20 01  cmp  %o0, 1
a009020c:  12 80 00 04  bne  0xa009021c
a0090210:  01 00 00 00  nop
a0090214:  10 80 00 11  b  0xa0090258
a0090218:  a0 10 20 1c  mov  0x1c, %l0	! 0x1c
a009021c:  7f ff ff 3b  call  0xa008ff08
a0090220:  90 10 00 18  mov  %i0, %o0
a0090224:  90 0a 20 ff  and  %o0, 0xff, %o0
a0090228:  80 a2 20 02  cmp  %o0, 2
a009022c:  22 80 00 0b  be,a   0xa0090258
a0090230:  a0 10 20 22  mov  0x22, %l0
a0090234:  10 80 00 0a  b  0xa009025c
a0090238:  90 10 00 18  mov  %i0, %o0
a009023c:  90 10 00 18  mov  %i0, %o0
a0090240:  40 00 58 cf  call  0xa00a657c
a0090244:  92 10 21 45  mov  0x145, %o1
a0090248:  90 0a 20 c0  and  %o0, 0xc0, %o0
a009024c:  80 a2 20 80  cmp  %o0, 0x80
a0090250:  22 80 00 02  be,a   0xa0090258
a0090254:  a0 10 20 08  mov  8, %l0
a0090258:  90 10 00 18  mov  %i0, %o0
a009025c:  40 00 58 c8  call  0xa00a657c
a0090260:  92 10 21 48  mov  0x148, %o1
a0090264:  80 8a 20 c0  btst  0xc0, %o0
a0090268:  32 80 00 16  bne,a   0xa00902c0
a009026c:  a0 04 20 01  inc  %l0
a0090270:  90 10 00 18  mov  %i0, %o0
a0090274:  40 00 58 c2  call  0xa00a657c
a0090278:  92 10 21 46  mov  0x146, %o1
a009027c:  90 0a 20 0c  and  %o0, 0xc, %o0
a0090280:  80 a2 20 04  cmp  %o0, 4
a0090284:  02 80 00 0f  be  0xa00902c0
a0090288:  90 10 00 18  mov  %i0, %o0
a009028c:  40 00 58 bc  call  0xa00a657c
a0090290:  92 10 21 46  mov  0x146, %o1
a0090294:  80 8a 20 0c  btst  0xc, %o0
a0090298:  32 80 00 0a  bne,a   0xa00902c0
a009029c:  a0 04 20 01  inc  %l0
a00902a0:  90 10 00 18  mov  %i0, %o0
a00902a4:  40 00 58 b6  call  0xa00a657c
a00902a8:  92 10 21 47  mov  0x147, %o1
a00902ac:  90 0a 20 7f  and  %o0, 0x7f, %o0
a00902b0:  80 a2 20 01  cmp  %o0, 1
a00902b4:  12 80 00 04  bne  0xa00902c4
a00902b8:  90 10 00 18  mov  %i0, %o0
a00902bc:  a0 04 20 01  inc  %l0
a00902c0:  90 10 00 18  mov  %i0, %o0
a00902c4:  40 00 58 ae  call  0xa00a657c
a00902c8:  92 10 21 44  mov  0x144, %o1
a00902cc:  90 0a 20 e0  and  %o0, 0xe0, %o0
a00902d0:  80 a2 20 20  cmp  %o0, 0x20
a00902d4:  22 80 00 02  be,a   0xa00902dc
a00902d8:  a0 04 20 02  add  %l0, 2, %l0
a00902dc:  90 10 00 18  mov  %i0, %o0
a00902e0:  40 00 58 a7  call  0xa00a657c
a00902e4:  92 10 21 44  mov  0x144, %o1
a00902e8:  90 0a 20 e0  and  %o0, 0xe0, %o0
a00902ec:  80 a2 20 60  cmp  %o0, 0x60
a00902f0:  22 80 00 1e  be,a   0xa0090368
a00902f4:  a0 04 20 04  add  %l0, 4, %l0
a00902f8:  10 80 00 1d  b  0xa009036c
a00902fc:  b0 0c 20 ff  and  %l0, 0xff, %i0
a0090300:  90 10 00 18  mov  %i0, %o0
a0090304:  40 00 58 9e  call  0xa00a657c
a0090308:  92 10 21 34  mov  0x134, %o1
a009030c:  80 8a 20 02  btst  2, %o0
a0090310:  22 80 00 17  be,a   0xa009036c
a0090314:  b0 0c 20 ff  and  %l0, 0xff, %i0
a0090318:  7f ff fe fc  call  0xa008ff08
a009031c:  90 10 00 18  mov  %i0, %o0
a0090320:  80 8a 20 ff  btst  0xff, %o0
a0090324:  02 80 00 0a  be  0xa009034c
a0090328:  90 10 00 18  mov  %i0, %o0
a009032c:  40 00 58 94  call  0xa00a657c
a0090330:  92 10 21 46  mov  0x146, %o1
a0090334:  90 0a 20 0c  and  %o0, 0xc, %o0
a0090338:  90 1a 20 04  xor  %o0, 4, %o0
a009033c:  80 a0 00 08  cmp  %g0, %o0
a0090340:  82 40 20 00  addx  %g0, 0, %g1
a0090344:  10 80 00 09  b  0xa0090368
a0090348:  a0 00 60 1a  add  %g1, 0x1a, %l0
a009034c:  40 00 58 8c  call  0xa00a657c
a0090350:  92 10 21 46  mov  0x146, %o1
a0090354:  90 0a 20 0c  and  %o0, 0xc, %o0
a0090358:  90 1a 20 04  xor  %o0, 4, %o0
a009035c:  80 a0 00 08  cmp  %g0, %o0
a0090360:  82 40 20 00  addx  %g0, 0, %g1
a0090364:  a0 10 00 01  mov  %g1, %l0
a0090368:  b0 0c 20 ff  and  %l0, 0xff, %i0
a009036c:  81 c7 e0 08  ret
a0090370:  81 e8 00 00  restore
