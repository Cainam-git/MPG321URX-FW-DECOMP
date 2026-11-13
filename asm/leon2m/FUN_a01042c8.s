# leon2m FUN_a01042c8 0xa01042c8-0xa0104380 (184 bytes)
a01042c8:  9d e3 bf 98  save  %sp, -104, %sp
a01042cc:  a4 0e 20 ff  and  %i0, 0xff, %l2
a01042d0:  92 10 20 89  mov  0x89, %o1
a01042d4:  7f ff b9 c0  call  0xa00f29d4
a01042d8:  90 10 00 12  mov  %l2, %o0
a01042dc:  a2 10 00 08  mov  %o0, %l1
a01042e0:  b3 2e 60 10  sll  %i1, 0x10, %i1
a01042e4:  90 10 20 01  mov  1, %o0
a01042e8:  40 00 76 39  call  0xa0121bcc
a01042ec:  93 36 60 10  srl  %i1, 0x10, %o1
a01042f0:  90 10 00 12  mov  %l2, %o0
a01042f4:  7f ff b9 b8  call  0xa00f29d4
a01042f8:  92 10 20 89  mov  0x89, %o1
a01042fc:  b0 10 00 08  mov  %o0, %i0
a0104300:  10 80 00 14  b  0xa0104350
a0104304:  a0 10 20 00  clr  %l0
a0104308:  80 a0 60 0f  cmp  %g1, 0xf
a010430c:  34 80 00 02  bg,a   0xa0104314
a0104310:  98 10 20 00  clr  %o4
a0104314:  80 a3 60 03  cmp  %o5, 3
a0104318:  82 60 20 00  subx  %g0, 0, %g1
a010431c:  80 88 40 0c  btst  %g1, %o4
a0104320:  02 80 00 15  be  0xa0104374
a0104324:  b0 04 40 18  add  %l1, %i0, %i0
a0104328:  7f ff b9 ab  call  0xa00f29d4
a010432c:  01 00 00 00  nop
a0104330:  a2 10 00 08  mov  %o0, %l1
a0104334:  90 10 20 01  mov  1, %o0
a0104338:  40 00 76 25  call  0xa0121bcc
a010433c:  93 36 60 10  srl  %i1, 0x10, %o1
a0104340:  90 10 00 12  mov  %l2, %o0
a0104344:  7f ff b9 a4  call  0xa00f29d4
a0104348:  92 10 20 89  mov  0x89, %o1
a010434c:  b0 10 00 08  mov  %o0, %i0
a0104350:  9a 0c 20 ff  and  %l0, 0xff, %o5
a0104354:  82 24 40 18  sub  %l1, %i0, %g1
a0104358:  92 10 20 89  mov  0x89, %o1
a010435c:  90 10 00 12  mov  %l2, %o0
a0104360:  80 a0 7f f1  cmp  %g1, -15
a0104364:  98 10 20 01  mov  1, %o4
a0104368:  16 bf ff e8  bge  0xa0104308
a010436c:  a0 04 20 01  inc  %l0
a0104370:  b0 04 40 18  add  %l1, %i0, %i0
a0104374:  b1 36 20 01  srl  %i0, 1, %i0
a0104378:  81 c7 e0 08  ret
a010437c:  81 e8 00 00  restore
