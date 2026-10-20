# leon2m FUN_a0109278 0xa0109278-0xa01093a8 (304 bytes)  [FUN_a01093a0 = unreachable ret/restore tail, merged]
a0109278:  9d e3 bf 98  save  %sp, -104, %sp
a010927c:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0109280:  80 a6 20 01  cmp  %i0, 1
a0109284:  02 80 00 0a  be  0xa01092ac
a0109288:  91 2e 60 10  sll  %i1, 0x10, %o0
a010928c:  04 80 00 29  ble  0xa0109330
a0109290:  80 a6 20 02  cmp  %i0, 2
a0109294:  02 80 00 16  be  0xa01092ec
a0109298:  80 a6 20 03  cmp  %i0, 3
a010929c:  12 80 00 40  bne  0xa010939c
a01092a0:  9b 2e 60 10  sll  %i1, 0x10, %o5
a01092a4:  10 80 00 2f  b  0xa0109360
a01092a8:  a1 33 60 10  srl  %o5, 0x10, %l0
a01092ac:  31 33 c0 46  sethi  %hi(0xcf011800), %i0
a01092b0:  a1 32 20 10  srl  %o0, 0x10, %l0
a01092b4:  90 16 23 28  or  %i0, 0x328, %o0
a01092b8:  7f ff a7 75  call  0xa00f308c
a01092bc:  92 10 00 10  mov  %l0, %o1
a01092c0:  83 2e a0 10  sll  %i2, 0x10, %g1
a01092c4:  b3 30 60 10  srl  %g1, 0x10, %i1
a01092c8:  90 16 23 38  or  %i0, 0x338, %o0
a01092cc:  7f ff a7 70  call  0xa00f308c
a01092d0:  92 10 00 19  mov  %i1, %o1
a01092d4:  90 16 23 88  or  %i0, 0x388, %o0
a01092d8:  7f ff a7 6d  call  0xa00f308c
a01092dc:  92 10 00 10  mov  %l0, %o1
a01092e0:  b0 16 23 98  or  %i0, 0x398, %i0
a01092e4:  7f ff a7 6a  call  0xa00f308c
a01092e8:  81 e8 00 00  restore
a01092ec:  97 2e 60 10  sll  %i1, 0x10, %o3
a01092f0:  a1 32 e0 10  srl  %o3, 0x10, %l0
a01092f4:  31 33 c0 46  sethi  %hi(0xcf011800), %i0
a01092f8:  90 16 23 48  or  %i0, 0x348, %o0	! 0xcf011b48
a01092fc:  7f ff a7 64  call  0xa00f308c
a0109300:  92 10 00 10  mov  %l0, %o1
a0109304:  95 2e a0 10  sll  %i2, 0x10, %o2
a0109308:  b3 32 a0 10  srl  %o2, 0x10, %i1
a010930c:  90 16 23 58  or  %i0, 0x358, %o0
a0109310:  7f ff a7 5f  call  0xa00f308c
a0109314:  92 10 00 19  mov  %i1, %o1
a0109318:  90 16 23 a8  or  %i0, 0x3a8, %o0
a010931c:  7f ff a7 5c  call  0xa00f308c
a0109320:  92 10 00 10  mov  %l0, %o1
a0109324:  b0 16 23 b8  or  %i0, 0x3b8, %i0
a0109328:  7f ff a7 59  call  0xa00f308c
a010932c:  81 e8 00 00  restore
a0109330:  80 a6 20 00  cmp  %i0, 0
a0109334:  12 80 00 1a  bne  0xa010939c
a0109338:  93 2e 60 10  sll  %i1, 0x10, %o1
a010933c:  31 33 c0 46  sethi  %hi(0xcf011800), %i0
a0109340:  90 16 23 08  or  %i0, 0x308, %o0	! 0xcf011b08
a0109344:  93 32 60 10  srl  %o1, 0x10, %o1
a0109348:  7f ff a7 51  call  0xa00f308c
a010934c:  b3 2e a0 10  sll  %i2, 0x10, %i1
a0109350:  b0 16 23 18  or  %i0, 0x318, %i0
a0109354:  b3 36 60 10  srl  %i1, 0x10, %i1
a0109358:  7f ff a7 4d  call  0xa00f308c
a010935c:  81 e8 00 00  restore
a0109360:  31 33 c0 46  sethi  %hi(0xcf011800), %i0
a0109364:  90 16 23 68  or  %i0, 0x368, %o0	! 0xcf011b68
a0109368:  7f ff a7 49  call  0xa00f308c
a010936c:  92 10 00 10  mov  %l0, %o1
a0109370:  99 2e a0 10  sll  %i2, 0x10, %o4
a0109374:  b3 33 20 10  srl  %o4, 0x10, %i1
a0109378:  90 16 23 78  or  %i0, 0x378, %o0
a010937c:  7f ff a7 44  call  0xa00f308c
a0109380:  92 10 00 19  mov  %i1, %o1
a0109384:  90 16 23 c8  or  %i0, 0x3c8, %o0
a0109388:  7f ff a7 41  call  0xa00f308c
a010938c:  92 10 00 10  mov  %l0, %o1
a0109390:  b0 16 23 d8  or  %i0, 0x3d8, %i0
a0109394:  7f ff a7 3e  call  0xa00f308c
a0109398:  81 e8 00 00  restore
a010939c:  01 00 00 00  nop
a01093a0:  81 c7 e0 08  ret
a01093a4:  81 e8 00 00  restore
