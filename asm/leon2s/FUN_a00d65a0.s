# leon2s FUN_a00d65a0 0xa00d65a0-0xa00d661c (124 bytes)
a00d65a0:  9d e3 bf 98  save  %sp, -104, %sp
a00d65a4:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00d65a8:  90 10 00 18  mov  %i0, %o0
a00d65ac:  40 3b 81 83  call  0xa0fb6bb8
a00d65b0:  92 10 20 9f  mov  0x9f, %o1
a00d65b4:  80 a6 20 01  cmp  %i0, 1
a00d65b8:  02 80 00 18  be  0xa00d6618
a00d65bc:  b2 0e 60 ff  and  %i1, 0xff, %i1
a00d65c0:  80 a6 60 01  cmp  %i1, 1
a00d65c4:  02 80 00 0d  be  0xa00d65f8
a00d65c8:  b4 0a 20 3f  and  %o0, 0x3f, %i2
a00d65cc:  14 80 00 06  bg  0xa00d65e4
a00d65d0:  80 a6 60 02  cmp  %i1, 2
a00d65d4:  80 a6 60 00  cmp  %i1, 0
a00d65d8:  02 80 00 0e  be  0xa00d6610
a00d65dc:  01 00 00 00  nop
a00d65e0:  30 80 00 0e  b,a   0xa00d6618
a00d65e4:  02 80 00 07  be  0xa00d6600
a00d65e8:  80 a6 60 03  cmp  %i1, 3
a00d65ec:  02 80 00 08  be  0xa00d660c
a00d65f0:  b4 12 3f c0  or  %o0, -64, %i2
a00d65f4:  30 80 00 09  b,a   0xa00d6618
a00d65f8:  10 80 00 06  b  0xa00d6610
a00d65fc:  b4 16 a0 40  or  %i2, 0x40, %i2
a00d6600:  b4 0a 20 3f  and  %o0, 0x3f, %i2
a00d6604:  10 80 00 03  b  0xa00d6610
a00d6608:  b4 16 a0 80  or  %i2, 0x80, %i2
a00d660c:  b4 0e a0 ff  and  %i2, 0xff, %i2
a00d6610:  40 3b 81 7c  call  0xa0fb6c00
a00d6614:  93 e8 20 9f  restore  %g0, 0x9f, %o1
a00d6618:  01 00 00 00  nop
