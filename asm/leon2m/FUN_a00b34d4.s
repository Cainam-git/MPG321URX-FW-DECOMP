# leon2m FUN_a00b34d4 0xa00b34d4-0xa00b3614 (320 bytes)
a00b34d4:  9d e3 bf 98  save  %sp, -104, %sp
a00b34d8:  90 10 21 ee  mov  0x1ee, %o0
a00b34dc:  40 02 4d 9d  call  0xa0146b50
a00b34e0:  92 10 20 00  clr  %o1
a00b34e4:  90 10 20 02  mov  2, %o0
a00b34e8:  92 10 20 00  clr  %o1
a00b34ec:  40 02 4d a0  call  0xa0146b6c
a00b34f0:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a00b34f4:  a2 14 22 90  or  %l0, 0x290, %l1	! 0xa802d290
a00b34f8:  de 0c 61 89  ldub  [ %l1 + 0x189 ], %o7
a00b34fc:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00b3500:  83 33 e0 04  srl  %o7, 4, %g1
a00b3504:  94 10 20 04  mov  4, %o2
a00b3508:  96 10 25 96  mov  0x596, %o3
a00b350c:  98 10 20 00  clr  %o4
a00b3510:  90 10 20 37  mov  0x37, %o0
a00b3514:  92 10 20 0e  mov  0xe, %o1
a00b3518:  80 a6 00 01  cmp  %i0, %g1
a00b351c:  02 80 00 16  be  0xa00b3574
a00b3520:  a0 0e 60 ff  and  %i1, 0xff, %l0
a00b3524:  40 02 4d 57  call  0xa0146a80
a00b3528:  01 00 00 00  nop
a00b352c:  9f 2e 20 03  sll  %i0, 3, %o7
a00b3530:  82 23 c0 18  sub  %o7, %i0, %g1
a00b3534:  9b 28 60 02  sll  %g1, 2, %o5
a00b3538:  96 03 40 18  add  %o5, %i0, %o3
a00b353c:  d8 0c 60 08  ldub  [ %l1 + 8 ], %o4
a00b3540:  94 02 c0 0c  add  %o3, %o4, %o2
a00b3544:  93 2a a0 10  sll  %o2, 0x10, %o1
a00b3548:  11 00 06 4a  sethi  %hi(0x192800), %o0
a00b354c:  93 32 60 10  srl  %o1, 0x10, %o1
a00b3550:  7f ff c0 bd  call  0xa00a3844
a00b3554:  90 12 20 b0  or  %o0, 0xb0, %o0
a00b3558:  98 10 00 08  mov  %o0, %o4
a00b355c:  9a 10 20 00  clr  %o5
a00b3560:  94 10 20 0e  mov  0xe, %o2
a00b3564:  96 10 20 04  mov  4, %o3
a00b3568:  90 10 20 00  clr  %o0
a00b356c:  7f ff bf 0e  call  0xa00a31a4
a00b3570:  92 10 20 37  mov  0x37, %o1
a00b3574:  90 10 21 f7  mov  0x1f7, %o0
a00b3578:  40 02 4d 76  call  0xa0146b50
a00b357c:  92 10 20 00  clr  %o1
a00b3580:  90 10 20 02  mov  2, %o0
a00b3584:  40 02 4d 7a  call  0xa0146b6c
a00b3588:  92 10 20 00  clr  %o1
a00b358c:  c2 0c 61 89  ldub  [ %l1 + 0x189 ], %g1
a00b3590:  9a 08 60 0f  and  %g1, 0xf, %o5
a00b3594:  94 10 20 04  mov  4, %o2
a00b3598:  96 10 25 96  mov  0x596, %o3
a00b359c:  98 10 20 00  clr  %o4
a00b35a0:  90 10 20 37  mov  0x37, %o0
a00b35a4:  80 a4 00 0d  cmp  %l0, %o5
a00b35a8:  02 80 00 16  be  0xa00b3600
a00b35ac:  92 10 20 13  mov  0x13, %o1
a00b35b0:  40 02 4d 34  call  0xa0146a80
a00b35b4:  01 00 00 00  nop
a00b35b8:  9b 2c 20 03  sll  %l0, 3, %o5
a00b35bc:  9e 23 40 10  sub  %o5, %l0, %o7
a00b35c0:  99 2b e0 02  sll  %o7, 2, %o4
a00b35c4:  94 03 00 10  add  %o4, %l0, %o2
a00b35c8:  d6 0c 60 08  ldub  [ %l1 + 8 ], %o3
a00b35cc:  92 02 80 0b  add  %o2, %o3, %o1
a00b35d0:  91 2a 60 10  sll  %o1, 0x10, %o0
a00b35d4:  93 32 20 10  srl  %o0, 0x10, %o1
a00b35d8:  21 00 06 4a  sethi  %hi(0x192800), %l0
a00b35dc:  7f ff c0 9a  call  0xa00a3844
a00b35e0:  90 14 20 b0  or  %l0, 0xb0, %o0	! 0x1928b0
a00b35e4:  98 10 00 08  mov  %o0, %o4
a00b35e8:  90 10 20 00  clr  %o0
a00b35ec:  92 10 20 37  mov  0x37, %o1
a00b35f0:  94 10 20 13  mov  0x13, %o2
a00b35f4:  96 10 20 04  mov  4, %o3
a00b35f8:  7f ff be eb  call  0xa00a31a4
a00b35fc:  9a 10 20 00  clr  %o5
a00b3600:  83 2e 20 04  sll  %i0, 4, %g1
a00b3604:  b0 06 40 01  add  %i1, %g1, %i0
a00b3608:  f0 2c 61 89  stb  %i0, [ %l1 + 0x189 ]
a00b360c:  81 c7 e0 08  ret
a00b3610:  81 e8 00 00  restore
