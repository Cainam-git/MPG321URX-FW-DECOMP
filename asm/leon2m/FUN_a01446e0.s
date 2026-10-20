# leon2m FUN_a01446e0 0xa01446e0-0xa0144768 (136 bytes)
a01446e0:  9d e3 bf 98  save  %sp, -104, %sp
a01446e4:  03 00 06 9b  sethi  %hi(0x1a6c00), %g1
a01446e8:  b0 0e 20 ff  and  %i0, 0xff, %i0
a01446ec:  92 10 61 a3  or  %g1, 0x1a3, %o1
a01446f0:  94 10 20 00  clr  %o2
a01446f4:  98 10 20 00  clr  %o4
a01446f8:  9e 03 00 0c  add  %o4, %o4, %o7
a01446fc:  96 03 c0 0c  add  %o7, %o4, %o3
a0144700:  9a 02 c0 09  add  %o3, %o1, %o5
a0144704:  94 02 a0 01  inc  %o2
a0144708:  d0 0b 60 01  ldub  [ %o5 + 1 ], %o0
a014470c:  80 a2 00 18  cmp  %o0, %i0
a0144710:  02 80 00 07  be  0xa014472c
a0144714:  98 0a a0 ff  and  %o2, 0xff, %o4
a0144718:  80 a3 20 04  cmp  %o4, 4
a014471c:  08 bf ff f8  bleu  0xa01446fc
a0144720:  9e 03 00 0c  add  %o4, %o4, %o7
a0144724:  10 80 00 0f  b  0xa0144760
a0144728:  b0 10 20 00  clr  %i0
a014472c:  7f ff 99 90  call  0xa012ad6c
a0144730:  e0 0a 40 0b  ldub  [ %o1 + %o3 ], %l0
a0144734:  92 0a 20 ff  and  %o0, 0xff, %o1
a0144738:  80 a2 60 01  cmp  %o1, 1
a014473c:  12 80 00 09  bne  0xa0144760
a0144740:  b0 0c 20 ff  and  %l0, 0xff, %i0
a0144744:  80 a6 20 04  cmp  %i0, 4
a0144748:  02 80 00 05  be  0xa014475c
a014474c:  80 a6 20 06  cmp  %i0, 6
a0144750:  22 80 00 04  be,a   0xa0144760
a0144754:  b0 10 20 04  mov  4, %i0
a0144758:  30 80 00 02  b,a   0xa0144760
a014475c:  b0 10 20 06  mov  6, %i0
a0144760:  81 c7 e0 08  ret
a0144764:  81 e8 00 00  restore
