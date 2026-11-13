# leon2s FUN_a00af320 0xa00af320-0xa00af464 (324 bytes)
a00af320:  9d e3 bf 98  save  %sp, -104, %sp
a00af324:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00af328:  92 10 20 8f  mov  0x8f, %o1
a00af32c:  7f ff de 23  call  0xa00a6bb8
a00af330:  90 10 00 18  mov  %i0, %o0
a00af334:  80 8a 20 40  btst  0x40, %o0
a00af338:  92 10 20 70  mov  0x70, %o1
a00af33c:  94 10 20 00  clr  %o2
a00af340:  90 10 00 18  mov  %i0, %o0
a00af344:  02 80 00 46  be  0xa00af45c
a00af348:  82 10 20 00  clr  %g1
a00af34c:  7f ff de 2d  call  0xa00a6c00
a00af350:  01 00 00 00  nop
a00af354:  94 10 20 0c  mov  0xc, %o2	! 0xc
a00af358:  90 10 00 18  mov  %i0, %o0
a00af35c:  7f ff de 29  call  0xa00a6c00
a00af360:  92 10 20 73  mov  0x73, %o1
a00af364:  92 10 20 7a  mov  0x7a, %o1
a00af368:  7f ff de 14  call  0xa00a6bb8
a00af36c:  90 10 00 18  mov  %i0, %o0
a00af370:  a2 10 00 08  mov  %o0, %l1
a00af374:  90 10 00 18  mov  %i0, %o0
a00af378:  92 10 20 70  mov  0x70, %o1
a00af37c:  7f ff de 21  call  0xa00a6c00
a00af380:  94 10 20 00  clr  %o2
a00af384:  94 10 20 0d  mov  0xd, %o2
a00af388:  90 10 00 18  mov  %i0, %o0
a00af38c:  7f ff de 1d  call  0xa00a6c00
a00af390:  92 10 20 73  mov  0x73, %o1
a00af394:  92 10 20 7a  mov  0x7a, %o1
a00af398:  7f ff de 08  call  0xa00a6bb8
a00af39c:  90 10 00 18  mov  %i0, %o0
a00af3a0:  a4 10 00 08  mov  %o0, %l2
a00af3a4:  90 10 00 18  mov  %i0, %o0
a00af3a8:  92 10 20 70  mov  0x70, %o1
a00af3ac:  7f ff de 15  call  0xa00a6c00
a00af3b0:  94 10 20 00  clr  %o2
a00af3b4:  94 10 20 10  mov  0x10, %o2
a00af3b8:  90 10 00 18  mov  %i0, %o0
a00af3bc:  7f ff de 11  call  0xa00a6c00
a00af3c0:  92 10 20 73  mov  0x73, %o1
a00af3c4:  92 10 20 7a  mov  0x7a, %o1
a00af3c8:  7f ff dd fc  call  0xa00a6bb8
a00af3cc:  90 10 00 18  mov  %i0, %o0
a00af3d0:  a0 10 00 08  mov  %o0, %l0
a00af3d4:  90 10 00 18  mov  %i0, %o0
a00af3d8:  92 10 20 70  mov  0x70, %o1
a00af3dc:  7f ff de 09  call  0xa00a6c00
a00af3e0:  94 10 20 00  clr  %o2
a00af3e4:  90 10 00 18  mov  %i0, %o0
a00af3e8:  92 10 20 73  mov  0x73, %o1
a00af3ec:  7f ff de 05  call  0xa00a6c00
a00af3f0:  94 10 20 11  mov  0x11, %o2
a00af3f4:  90 10 00 18  mov  %i0, %o0
a00af3f8:  7f ff dd f0  call  0xa00a6bb8
a00af3fc:  92 10 20 7a  mov  0x7a, %o1
a00af400:  a0 0c 20 ff  and  %l0, 0xff, %l0
a00af404:  a1 2c 20 08  sll  %l0, 8, %l0
a00af408:  90 0a 20 ff  and  %o0, 0xff, %o0
a00af40c:  a2 0c 60 ff  and  %l1, 0xff, %l1
a00af410:  a0 04 00 08  add  %l0, %o0, %l0
a00af414:  a3 2c 60 08  sll  %l1, 8, %l1
a00af418:  a4 0c a0 ff  and  %l2, 0xff, %l2
a00af41c:  a1 2c 20 10  sll  %l0, 0x10, %l0
a00af420:  a2 04 40 12  add  %l1, %l2, %l1
a00af424:  a1 34 20 10  srl  %l0, 0x10, %l0
a00af428:  a3 2c 60 10  sll  %l1, 0x10, %l1
a00af42c:  80 a4 20 00  cmp  %l0, 0
a00af430:  a3 34 60 10  srl  %l1, 0x10, %l1
a00af434:  02 80 00 07  be  0xa00af450
a00af438:  82 10 20 00  clr  %g1
a00af43c:  81 80 00 00  mov  %g0, %y
a00af440:  01 00 00 00  nop
a00af444:  01 00 00 00  nop
a00af448:  01 00 00 00  nop
a00af44c:  82 74 40 10  udiv  %l1, %l0, %g1
a00af450:  82 08 60 ff  and  %g1, 0xff, %g1
a00af454:  80 a0 00 01  cmp  %g0, %g1
a00af458:  82 40 20 00  addx  %g0, 0, %g1
a00af45c:  81 c7 e0 08  ret
a00af460:  91 e8 00 01  restore  %g0, %g1, %o0
