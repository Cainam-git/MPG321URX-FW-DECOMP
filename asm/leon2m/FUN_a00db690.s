# leon2m FUN_a00db690 0xa00db690-0xa00db738 (168 bytes)
a00db690:  9d e3 bf 98  save  %sp, -104, %sp
a00db694:  40 01 c1 b7  call  0xa014bd70
a00db698:  90 10 20 00  clr  %o0
a00db69c:  90 0a 20 ff  and  %o0, 0xff, %o0
a00db6a0:  80 a2 20 01  cmp  %o0, 1
a00db6a4:  02 80 00 0e  be  0xa00db6dc
a00db6a8:  90 10 20 00  clr  %o0
a00db6ac:  40 01 a0 8c  call  0xa01438dc
a00db6b0:  90 10 20 00  clr  %o0
a00db6b4:  82 0a 20 ff  and  %o0, 0xff, %g1
a00db6b8:  80 a0 60 01  cmp  %g1, 1
a00db6bc:  02 80 00 0c  be  0xa00db6ec
a00db6c0:  13 2a 00 b5  sethi  %hi(0xa802d400), %o1
a00db6c4:  d8 02 60 04  ld  [ %o1 + 4 ], %o4	! 0xa802d404
a00db6c8:  1b 00 00 20  sethi  %hi(0x8000), %o5
a00db6cc:  80 8b 00 0d  btst  %o4, %o5
a00db6d0:  12 80 00 03  bne  0xa00db6dc
a00db6d4:  90 10 20 01  mov  1, %o0
a00db6d8:  90 10 20 00  clr  %o0
a00db6dc:  40 01 cc 67  call  0xa014e878
a00db6e0:  01 00 00 00  nop
a00db6e4:  7f ff f6 8f  call  0xa00d9120
a00db6e8:  81 e8 00 00  restore
a00db6ec:  40 01 c0 df  call  0xa014ba68
a00db6f0:  01 00 00 00  nop
a00db6f4:  90 0a 20 ff  and  %o0, 0xff, %o0
a00db6f8:  80 a2 20 02  cmp  %o0, 2
a00db6fc:  22 bf ff f8  be,a   0xa00db6dc
a00db700:  90 10 20 00  clr  %o0
a00db704:  04 80 00 09  ble  0xa00db728
a00db708:  80 a2 20 01  cmp  %o0, 1
a00db70c:  80 a2 20 03  cmp  %o0, 3
a00db710:  02 bf ff f2  be  0xa00db6d8
a00db714:  80 a2 20 04  cmp  %o0, 4
a00db718:  12 bf ff eb  bne  0xa00db6c4
a00db71c:  13 2a 00 b5  sethi  %hi(0xa802d400), %o1
a00db720:  10 bf ff ef  b  0xa00db6dc
a00db724:  90 10 20 00  clr  %o0
a00db728:  12 bf ff e7  bne  0xa00db6c4
a00db72c:  13 2a 00 b5  sethi  %hi(0xa802d400), %o1
a00db730:  10 bf ff eb  b  0xa00db6dc
a00db734:  90 10 20 00  clr  %o0
