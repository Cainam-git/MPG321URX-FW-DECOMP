# leon2s hdmi_PHY_Set_CTLE 0xa0075278-0xa0075360 (232 bytes)
a0075278:  9d e3 bf 98  save  %sp, -104, %sp
a007527c:  92 06 20 41  add  %i0, 0x41, %o1
a0075280:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a0075284:  23 00 00 04  sethi  %hi(0x1000), %l1
a0075288:  25 00 3f ff  sethi  %hi(0xfffc00), %l2
a007528c:  c2 00 62 34  ld  [ %g1 + 0x234 ], %g1
a0075290:  93 2a 60 18  sll  %o1, 0x18, %o1
a0075294:  15 28 02 cf  sethi  %hi(0xa00b3c00), %o2
a0075298:  11 28 01 9a  sethi  %hi(0xa0066800), %o0
a007529c:  21 00 00 07  sethi  %hi(0x1c00), %l0
a00752a0:  b2 14 60 20  or  %l1, 0x20, %i1
a00752a4:  b4 14 a3 ff  or  %l2, 0x3ff, %i2
a00752a8:  37 28 80 00  sethi  %hi(0xa2000000), %i3
a00752ac:  80 88 60 02  btst  2, %g1
a00752b0:  93 3a 60 18  sra  %o1, 0x18, %o1
a00752b4:  94 12 a0 70  or  %o2, 0x70, %o2
a00752b8:  90 12 23 18  or  %o0, 0x318, %o0
a00752bc:  02 80 00 04  be  0xa00752cc
a00752c0:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00752c4:  7f ff f7 60  call  0xa0073044
a00752c8:  01 00 00 00  nop
a00752cc:  7f ff f8 95  call  0xa0073520
a00752d0:  90 10 00 18  mov  %i0, %o0
a00752d4:  80 8a 20 ff  btst  0xff, %o0
a00752d8:  13 00 00 0d  sethi  %hi(0x3400), %o1
a00752dc:  15 00 3f ff  sethi  %hi(0xfffc00), %o2
a00752e0:  92 12 62 04  or  %o1, 0x204, %o1
a00752e4:  94 12 a3 ff  or  %o2, 0x3ff, %o2
a00752e8:  90 10 00 18  mov  %i0, %o0
a00752ec:  02 80 00 04  be  0xa00752fc
a00752f0:  17 08 40 00  sethi  %hi(0x21000000), %o3
a00752f4:  40 00 c8 65  call  0xa00a7488
a00752f8:  01 00 00 00  nop
a00752fc:  15 3f ff c0  sethi  %hi(0xffff0000), %o2
a0075300:  94 12 a0 ff  or  %o2, 0xff, %o2	! 0xffff00ff
a0075304:  90 10 00 18  mov  %i0, %o0
a0075308:  92 14 23 44  or  %l0, 0x344, %o1
a007530c:  40 00 c8 5f  call  0xa00a7488
a0075310:  96 14 61 00  or  %l1, 0x100, %o3
a0075314:  15 3f c0 3f  sethi  %hi(0xff00fc00), %o2
a0075318:  90 10 00 18  mov  %i0, %o0
a007531c:  94 12 a3 ff  or  %o2, 0x3ff, %o2
a0075320:  92 14 23 44  or  %l0, 0x344, %o1
a0075324:  40 00 c8 59  call  0xa00a7488
a0075328:  17 00 04 40  sethi  %hi(0x110000), %o3
a007532c:  90 10 00 18  mov  %i0, %o0
a0075330:  92 14 23 44  or  %l0, 0x344, %o1
a0075334:  94 14 a3 ff  or  %l2, 0x3ff, %o2
a0075338:  40 00 c8 54  call  0xa00a7488
a007533c:  17 04 40 00  sethi  %hi(0x11000000), %o3
a0075340:  90 10 00 18  mov  %i0, %o0
a0075344:  92 14 23 48  or  %l0, 0x348, %o1
a0075348:  94 10 3f 00  mov  -256, %o2
a007534c:  40 00 c8 4f  call  0xa00a7488
a0075350:  96 10 20 11  mov  0x11, %o3
a0075354:  40 00 c8 4d  call  0xa00a7488
a0075358:  81 e8 00 00  restore
a007535c:  01 00 00 00  nop
