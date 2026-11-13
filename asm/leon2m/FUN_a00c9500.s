# leon2m FUN_a00c9500 0xa00c9500-0xa00c95a4 (164 bytes)
a00c9500:  9d e3 bf 98  save  %sp, -104, %sp
a00c9504:  a0 0e 20 ff  and  %i0, 0xff, %l0
a00c9508:  80 a4 20 02  cmp  %l0, 2
a00c950c:  02 80 00 1e  be  0xa00c9584
a00c9510:  80 a4 20 03  cmp  %l0, 3
a00c9514:  02 80 00 1f  be  0xa00c9590
a00c9518:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00c951c:  da 0a 60 d9  ldub  [ %o1 + 0xd9 ], %o5	! 0xa802d0d9
a00c9520:  9e 0b 60 ff  and  %o5, 0xff, %o7
a00c9524:  98 03 ff d0  add  %o7, -48, %o4
a00c9528:  9a 0b 20 ff  and  %o4, 0xff, %o5
a00c952c:  31 2a 00 b4  sethi  %hi(0xa802d000), %i0
a00c9530:  96 16 22 90  or  %i0, 0x290, %o3	! 0xa802d290
a00c9534:  94 0b 60 01  and  %o5, 1, %o2
a00c9538:  99 2a a0 06  sll  %o2, 6, %o4
a00c953c:  80 a3 60 01  cmp  %o5, 1
a00c9540:  18 80 00 17  bgu  0xa00c959c
a00c9544:  b0 10 20 ff  mov  0xff, %i0
a00c9548:  d2 02 e0 a8  ld  [ %o3 + 0xa8 ], %o1
a00c954c:  90 0a 7f bf  and  %o1, -65, %o0
a00c9550:  82 12 00 0c  or  %o0, %o4, %g1
a00c9554:  40 00 41 09  call  0xa00d9978
a00c9558:  c2 22 e0 a8  st  %g1, [ %o3 + 0xa8 ]
a00c955c:  7f ff bc dc  call  0xa00b88cc
a00c9560:  b0 10 20 00  clr  %i0
a00c9564:  7f ff c5 42  call  0xa00baa6c
a00c9568:  90 10 00 10  mov  %l0, %o0
a00c956c:  7f ff c4 f9  call  0xa00ba950
a00c9570:  90 10 00 10  mov  %l0, %o0
a00c9574:  90 10 00 10  mov  %l0, %o0
a00c9578:  7f ff c5 82  call  0xa00bab80
a00c957c:  92 10 20 06  mov  6, %o1
a00c9580:  30 80 00 07  b,a   0xa00c959c
a00c9584:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00c9588:  10 bf ff e6  b  0xa00c9520
a00c958c:  da 08 60 49  ldub  [ %g1 + 0x49 ], %o5	! 0xa802d049
a00c9590:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00c9594:  10 bf ff e3  b  0xa00c9520
a00c9598:  da 0a 20 a1  ldub  [ %o0 + 0xa1 ], %o5	! 0xa802d0a1
a00c959c:  81 c7 e0 08  ret
a00c95a0:  81 e8 00 00  restore
