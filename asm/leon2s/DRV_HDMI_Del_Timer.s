# leon2s DRV_HDMI_Del_Timer 0xa009c284-0xa009c310 (140 bytes)  [FUN_a009c308 = unreachable ret/restore tail, merged]
a009c284:  9d e3 bf 98  save  %sp, -104, %sp
a009c288:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a009c28c:  c2 00 62 34  ld  [ %g1 + 0x234 ], %g1	! 0xa8078634
a009c290:  80 88 60 04  btst  4, %g1
a009c294:  02 80 00 09  be  0xa009c2b8
a009c298:  80 a6 20 14  cmp  %i0, 0x14
a009c29c:  11 28 01 a9  sethi  %hi(0xa006a400), %o0
a009c2a0:  13 28 02 d1  sethi  %hi(0xa00b4400), %o1
a009c2a4:  90 12 22 30  or  %o0, 0x230, %o0
a009c2a8:  92 12 60 50  or  %o1, 0x50, %o1
a009c2ac:  7f ff 5b 66  call  0xa0073044
a009c2b0:  94 10 00 18  mov  %i0, %o2
a009c2b4:  80 a6 20 14  cmp  %i0, 0x14
a009c2b8:  02 80 00 0f  be  0xa009c2f4
a009c2bc:  80 a6 20 14  cmp  %i0, 0x14
a009c2c0:  18 80 00 06  bgu  0xa009c2d8
a009c2c4:  80 a6 20 15  cmp  %i0, 0x15
a009c2c8:  80 a6 20 01  cmp  %i0, 1
a009c2cc:  02 80 00 06  be  0xa009c2e4
a009c2d0:  31 2a 01 e4  sethi  %hi(0xa8079000), %i0
a009c2d4:  30 80 00 0c  b,a   0xa009c304
a009c2d8:  02 80 00 05  be  0xa009c2ec
a009c2dc:  11 2a 01 e4  sethi  %hi(0xa8079000), %o0
a009c2e0:  30 80 00 09  b,a   0xa009c304
a009c2e4:  10 80 00 06  b  0xa009c2fc
a009c2e8:  b0 16 20 f4  or  %i0, 0xf4, %i0
a009c2ec:  40 00 57 d0  call  0xa00b222c
a009c2f0:  90 12 20 f4  or  %o0, 0xf4, %o0
a009c2f4:  31 2a 01 e4  sethi  %hi(0xa8079000), %i0
a009c2f8:  b0 16 21 00  or  %i0, 0x100, %i0	! 0xa8079100
a009c2fc:  40 00 57 cc  call  0xa00b222c
a009c300:  81 e8 00 00  restore
a009c304:  01 00 00 00  nop
a009c308:  81 c7 e0 08  ret
a009c30c:  81 e8 00 00  restore
