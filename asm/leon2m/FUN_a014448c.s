# leon2m FUN_a014448c 0xa014448c-0xa0144574 (232 bytes)
a014448c:  9d e3 bf 98  save  %sp, -104, %sp
a0144490:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0144494:  80 a6 20 01  cmp  %i0, 1
a0144498:  02 80 00 0b  be  0xa01444c4
a014449c:  98 10 20 01  mov  1, %o4
a01444a0:  80 a6 20 01  cmp  %i0, 1
a01444a4:  04 80 00 11  ble  0xa01444e8
a01444a8:  80 a6 20 02  cmp  %i0, 2
a01444ac:  02 80 00 06  be  0xa01444c4
a01444b0:  98 10 20 02  mov  2, %o4
a01444b4:  80 a6 20 03  cmp  %i0, 3
a01444b8:  02 80 00 03  be  0xa01444c4
a01444bc:  98 10 20 03  mov  3, %o4
a01444c0:  98 10 3f ff  mov  -1, %o4
a01444c4:  82 0b 20 ff  and  %o4, 0xff, %g1
a01444c8:  80 a0 60 03  cmp  %g1, 3
a01444cc:  08 80 00 0d  bleu  0xa0144500
a01444d0:  95 28 60 04  sll  %g1, 4, %o2
a01444d4:  11 00 06 9b  sethi  %hi(0x1a6c00), %o0
a01444d8:  7f fe 6b 26  call  0xa00df170
a01444dc:  90 12 21 d8  or  %o0, 0x1d8, %o0	! 0x1a6dd8
a01444e0:  10 80 00 07  b  0xa01444fc
a01444e4:  82 10 20 00  clr  %g1
a01444e8:  80 a6 20 00  cmp  %i0, 0
a01444ec:  02 bf ff f6  be  0xa01444c4
a01444f0:  98 10 20 00  clr  %o4
a01444f4:  10 bf ff f4  b  0xa01444c4
a01444f8:  98 10 3f ff  mov  -1, %o4
a01444fc:  95 28 60 04  sll  %g1, 4, %o2
a0144500:  90 22 80 01  sub  %o2, %g1, %o0
a0144504:  03 2a 00 b7  sethi  %hi(0xa802dc00), %g1
a0144508:  93 2a 20 03  sll  %o0, 3, %o1
a014450c:  9a 10 63 30  or  %g1, 0x330, %o5
a0144510:  f0 03 40 09  ld  [ %o5 + %o1 ], %i0
a0144514:  9f 36 20 0c  srl  %i0, 0xc, %o7
a0144518:  98 0b e0 0f  and  %o7, 0xf, %o4
a014451c:  17 2a 00 b8  sethi  %hi(0xa802e000), %o3
a0144520:  90 5b 20 2a  smul  %o4, 0x2a, %o0
a0144524:  94 12 e2 24  or  %o3, 0x224, %o2
a0144528:  82 02 00 0a  add  %o0, %o2, %g1
a014452c:  7f ff f7 0f  call  0xa0142168
a0144530:  d0 08 60 0a  ldub  [ %g1 + 0xa ], %o0
a0144534:  b0 0a 20 ff  and  %o0, 0xff, %i0
a0144538:  80 a6 20 07  cmp  %i0, 7
a014453c:  92 40 20 00  addx  %g0, 0, %o1
a0144540:  9a 20 00 09  neg  %o1, %o5
a0144544:  9e 0e 00 0d  and  %i0, %o5, %o7
a0144548:  99 2b e0 03  sll  %o7, 3, %o4
a014454c:  96 03 00 0f  add  %o4, %o7, %o3
a0144550:  15 2a 00 b8  sethi  %hi(0xa802e000), %o2
a0144554:  92 02 c0 0b  add  %o3, %o3, %o1
a0144558:  82 12 a1 16  or  %o2, 0x116, %g1
a014455c:  9a 02 40 01  add  %o1, %g1, %o5
a0144560:  7f ff 82 f8  call  0xa0125140
a0144564:  d0 0b 60 10  ldub  [ %o5 + 0x10 ], %o0
a0144568:  b0 0a 20 ff  and  %o0, 0xff, %i0
a014456c:  81 c7 e0 08  ret
a0144570:  81 e8 00 00  restore
