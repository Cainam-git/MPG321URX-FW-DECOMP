# leon2s DRV_HDMI_Start_Timer 0xa009c310-0xa009c3bc (172 bytes)  [FUN_a009c3b4 = unreachable ret/restore tail, merged]
a009c310:  9d e3 bf 98  save  %sp, -104, %sp
a009c314:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a009c318:  c2 00 62 34  ld  [ %g1 + 0x234 ], %g1	! 0xa8078634
a009c31c:  80 88 60 04  btst  4, %g1
a009c320:  02 80 00 09  be  0xa009c344
a009c324:  80 a6 20 14  cmp  %i0, 0x14
a009c328:  11 28 01 a9  sethi  %hi(0xa006a400), %o0
a009c32c:  13 28 02 d1  sethi  %hi(0xa00b4400), %o1
a009c330:  90 12 22 30  or  %o0, 0x230, %o0
a009c334:  92 12 60 68  or  %o1, 0x68, %o1
a009c338:  7f ff 5b 43  call  0xa0073044
a009c33c:  94 10 00 18  mov  %i0, %o2
a009c340:  80 a6 20 14  cmp  %i0, 0x14
a009c344:  02 80 00 14  be  0xa009c394
a009c348:  80 a6 20 14  cmp  %i0, 0x14
a009c34c:  18 80 00 06  bgu  0xa009c364
a009c350:  80 a6 20 15  cmp  %i0, 0x15
a009c354:  80 a6 20 01  cmp  %i0, 1
a009c358:  02 80 00 06  be  0xa009c370
a009c35c:  31 2a 01 e4  sethi  %hi(0xa8079000), %i0
a009c360:  30 80 00 14  b,a   0xa009c3b0
a009c364:  02 80 00 07  be  0xa009c380
a009c368:  11 2a 01 e4  sethi  %hi(0xa8079000), %o0
a009c36c:  30 80 00 11  b,a   0xa009c3b0
a009c370:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a009c374:  b0 16 20 f4  or  %i0, 0xf4, %i0
a009c378:  10 80 00 0b  b  0xa009c3a4
a009c37c:  c2 08 62 31  ldub  [ %g1 + 0x231 ], %g1
a009c380:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a009c384:  90 12 20 f4  or  %o0, 0xf4, %o0
a009c388:  c2 08 62 31  ldub  [ %g1 + 0x231 ], %g1
a009c38c:  40 00 57 82  call  0xa00b2194
a009c390:  c2 22 20 04  st  %g1, [ %o0 + 4 ]
a009c394:  31 2a 01 e4  sethi  %hi(0xa8079000), %i0
a009c398:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a009c39c:  b0 16 21 00  or  %i0, 0x100, %i0
a009c3a0:  c2 08 62 30  ldub  [ %g1 + 0x230 ], %g1
a009c3a4:  c2 26 20 04  st  %g1, [ %i0 + 4 ]
a009c3a8:  40 00 57 7b  call  0xa00b2194
a009c3ac:  81 e8 00 00  restore
a009c3b0:  01 00 00 00  nop
a009c3b4:  81 c7 e0 08  ret
a009c3b8:  81 e8 00 00  restore
