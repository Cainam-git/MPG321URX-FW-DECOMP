# leon2m FUN_a00874c8 0xa00874c8-0xa00875ec (292 bytes)
a00874c8:  9d e3 bf 98  save  %sp, -104, %sp
a00874cc:  a0 0e 20 ff  and  %i0, 0xff, %l0
a00874d0:  80 8c 20 01  btst  1, %l0
a00874d4:  12 80 00 17  bne  0xa0087530
a00874d8:  80 8c 20 02  btst  2, %l0
a00874dc:  12 80 00 1c  bne  0xa008754c
a00874e0:  90 10 20 05  mov  5, %o0
a00874e4:  80 8c 20 04  btst  4, %l0
a00874e8:  12 80 00 1f  bne  0xa0087564
a00874ec:  90 10 20 06  mov  6, %o0
a00874f0:  80 8c 20 08  btst  8, %l0
a00874f4:  12 80 00 22  bne  0xa008757c
a00874f8:  90 10 20 07  mov  7, %o0
a00874fc:  80 8c 20 10  btst  0x10, %l0
a0087500:  12 80 00 25  bne  0xa0087594
a0087504:  90 10 20 08  mov  8, %o0
a0087508:  80 8c 20 20  btst  0x20, %l0
a008750c:  12 80 00 28  bne  0xa00875ac
a0087510:  90 10 20 09  mov  9, %o0
a0087514:  80 8c 20 40  btst  0x40, %l0
a0087518:  12 80 00 2b  bne  0xa00875c4
a008751c:  90 10 20 0a  mov  0xa, %o0
a0087520:  80 8e 20 80  btst  0x80, %i0
a0087524:  02 80 00 2f  be  0xa00875e0
a0087528:  b2 0e 60 ff  and  %i1, 0xff, %i1
a008752c:  30 80 00 2b  b,a   0xa00875d8
a0087530:  90 10 20 04  mov  4, %o0
a0087534:  40 03 11 64  call  0xa014bac4
a0087538:  92 0e 60 ff  and  %i1, 0xff, %o1
a008753c:  80 8c 20 02  btst  2, %l0
a0087540:  02 bf ff ea  be  0xa00874e8
a0087544:  80 8c 20 04  btst  4, %l0
a0087548:  90 10 20 05  mov  5, %o0
a008754c:  40 03 11 5e  call  0xa014bac4
a0087550:  92 0e 60 ff  and  %i1, 0xff, %o1
a0087554:  80 8c 20 04  btst  4, %l0
a0087558:  02 bf ff e7  be  0xa00874f4
a008755c:  80 8c 20 08  btst  8, %l0
a0087560:  90 10 20 06  mov  6, %o0
a0087564:  40 03 11 58  call  0xa014bac4
a0087568:  92 0e 60 ff  and  %i1, 0xff, %o1
a008756c:  80 8c 20 08  btst  8, %l0
a0087570:  02 bf ff e4  be  0xa0087500
a0087574:  80 8c 20 10  btst  0x10, %l0
a0087578:  90 10 20 07  mov  7, %o0
a008757c:  40 03 11 52  call  0xa014bac4
a0087580:  92 0e 60 ff  and  %i1, 0xff, %o1
a0087584:  80 8c 20 10  btst  0x10, %l0
a0087588:  02 bf ff e1  be  0xa008750c
a008758c:  80 8c 20 20  btst  0x20, %l0
a0087590:  90 10 20 08  mov  8, %o0
a0087594:  40 03 11 4c  call  0xa014bac4
a0087598:  92 0e 60 ff  and  %i1, 0xff, %o1
a008759c:  80 8c 20 20  btst  0x20, %l0
a00875a0:  02 bf ff de  be  0xa0087518
a00875a4:  80 8c 20 40  btst  0x40, %l0
a00875a8:  90 10 20 09  mov  9, %o0
a00875ac:  40 03 11 46  call  0xa014bac4
a00875b0:  92 0e 60 ff  and  %i1, 0xff, %o1
a00875b4:  80 8c 20 40  btst  0x40, %l0
a00875b8:  02 bf ff db  be  0xa0087524
a00875bc:  80 8e 20 80  btst  0x80, %i0
a00875c0:  90 10 20 0a  mov  0xa, %o0
a00875c4:  40 03 11 40  call  0xa014bac4
a00875c8:  92 0e 60 ff  and  %i1, 0xff, %o1
a00875cc:  80 8e 20 80  btst  0x80, %i0
a00875d0:  02 80 00 04  be  0xa00875e0
a00875d4:  b2 0e 60 ff  and  %i1, 0xff, %i1
a00875d8:  40 03 11 3b  call  0xa014bac4
a00875dc:  91 e8 20 0b  restore  %g0, 0xb, %o0
a00875e0:  01 00 00 00  nop
a00875e4:  81 c7 e0 08  ret
a00875e8:  81 e8 00 00  restore
