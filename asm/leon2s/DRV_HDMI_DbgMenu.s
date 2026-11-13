# leon2s DRV_HDMI_DbgMenu 0xa00a32d0-0xa00a338c (188 bytes)
a00a32d0:  9d e3 bf 80  save  %sp, -128, %sp
a00a32d4:  11 28 01 ae  sethi  %hi(0xa006b800), %o0
a00a32d8:  7f ff 40 7b  call  0xa00734c4
a00a32dc:  90 12 21 a0  or  %o0, 0x1a0, %o0	! 0xa006b9a0
a00a32e0:  80 a6 20 07  cmp  %i0, 7
a00a32e4:  22 80 00 16  be,a   0xa00a333c
a00a32e8:  f2 27 bf e8  st  %i1, [ %fp + -24 ]
a00a32ec:  18 80 00 06  bgu  0xa00a3304
a00a32f0:  80 a6 20 0a  cmp  %i0, 0xa
a00a32f4:  80 a6 20 06  cmp  %i0, 6
a00a32f8:  22 80 00 08  be,a   0xa00a3318
a00a32fc:  11 28 01 ae  sethi  %hi(0xa006b800), %o0
a00a3300:  30 80 00 20  b,a   0xa00a3380
a00a3304:  02 80 00 12  be  0xa00a334c
a00a3308:  80 a6 20 64  cmp  %i0, 0x64
a00a330c:  02 80 00 1b  be  0xa00a3378
a00a3310:  80 a0 00 19  cmp  %g0, %i1
a00a3314:  30 80 00 1b  b,a   0xa00a3380
a00a3318:  13 28 02 d3  sethi  %hi(0xa00b4c00), %o1
a00a331c:  92 12 60 e0  or  %o1, 0xe0, %o1	! 0xa00b4ce0
a00a3320:  7f ff 3f 49  call  0xa0073044
a00a3324:  90 12 21 e0  or  %o0, 0x1e0, %o0
a00a3328:  f2 27 bf e0  st  %i1, [ %fp + -32 ]
a00a332c:  f4 2f bf e4  stb  %i2, [ %fp + -28 ]
a00a3330:  7f ff ff 93  call  0xa00a317c
a00a3334:  90 07 bf e0  add  %fp, -32, %o0
a00a3338:  30 80 00 12  b,a   0xa00a3380
a00a333c:  f4 27 bf ec  st  %i2, [ %fp + -20 ]
a00a3340:  7f ff ff c4  call  0xa00a3250
a00a3344:  90 07 bf e8  add  %fp, -24, %o0
a00a3348:  30 80 00 0e  b,a   0xa00a3380
a00a334c:  11 28 01 ae  sethi  %hi(0xa006b800), %o0
a00a3350:  90 12 21 e8  or  %o0, 0x1e8, %o0	! 0xa006b9e8
a00a3354:  7f ff 3f 3c  call  0xa0073044
a00a3358:  92 10 00 1a  mov  %i2, %o1
a00a335c:  80 a6 a0 01  cmp  %i2, 1
a00a3360:  12 80 00 04  bne  0xa00a3370
a00a3364:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a00a3368:  10 80 00 06  b  0xa00a3380
a00a336c:  f4 28 60 52  stb  %i2, [ %g1 + 0x52 ]	! 0xa8079052
a00a3370:  10 80 00 04  b  0xa00a3380
a00a3374:  c0 28 60 52  clrb  [ %g1 + 0x52 ]
a00a3378:  7f ff fa 9e  call  0xa00a1df0
a00a337c:  90 40 20 00  addx  %g0, 0, %o0
a00a3380:  01 00 00 00  nop
a00a3384:  81 c7 e0 08  ret
a00a3388:  81 e8 00 00  restore
