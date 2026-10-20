# leon2m FUN_a00b1654 0xa00b1654-0xa00b1700 (172 bytes)
a00b1654:  9d e3 bf 98  save  %sp, -104, %sp
a00b1658:  40 02 51 28  call  0xa0145af8
a00b165c:  90 10 20 10  mov  0x10, %o0
a00b1660:  91 2a 20 10  sll  %o0, 0x10, %o0
a00b1664:  80 a2 20 00  cmp  %o0, 0
a00b1668:  02 80 00 11  be  0xa00b16ac
a00b166c:  9e 0e 20 ff  and  %i0, 0xff, %o7
a00b1670:  80 a3 e0 01  cmp  %o7, 1
a00b1674:  02 80 00 04  be  0xa00b1684
a00b1678:  82 0e 60 ff  and  %i1, 0xff, %g1
a00b167c:  10 80 00 1f  b  0xa00b16f8
a00b1680:  b0 10 20 00  clr  %i0
a00b1684:  80 a0 60 11  cmp  %g1, 0x11
a00b1688:  02 80 00 1c  be  0xa00b16f8
a00b168c:  b0 10 20 1e  mov  0x1e, %i0
a00b1690:  80 a0 60 12  cmp  %g1, 0x12
a00b1694:  02 80 00 19  be  0xa00b16f8
a00b1698:  b0 10 20 32  mov  0x32, %i0
a00b169c:  80 a0 60 13  cmp  %g1, 0x13
a00b16a0:  12 bf ff f7  bne  0xa00b167c
a00b16a4:  b0 10 20 37  mov  0x37, %i0
a00b16a8:  30 80 00 14  b,a   0xa00b16f8
a00b16ac:  40 01 d8 d7  call  0xa0127a08
a00b16b0:  90 10 20 ff  mov  0xff, %o0
a00b16b4:  82 0e 20 ff  and  %i0, 0xff, %g1
a00b16b8:  92 02 3f ff  add  %o0, -1, %o1
a00b16bc:  80 a0 40 09  cmp  %g1, %o1
a00b16c0:  12 80 00 0e  bne  0xa00b16f8
a00b16c4:  b0 10 20 00  clr  %i0
a00b16c8:  b0 0e 60 ff  and  %i1, 0xff, %i0
a00b16cc:  96 1e 20 1e  xor  %i0, 0x1e, %o3
a00b16d0:  80 a0 00 0b  cmp  %g0, %o3
a00b16d4:  98 60 3f ff  subx  %g0, -1, %o4
a00b16d8:  94 1e 20 32  xor  %i0, 0x32, %o2
a00b16dc:  80 a0 00 0a  cmp  %g0, %o2
a00b16e0:  9a 60 3f ff  subx  %g0, -1, %o5
a00b16e4:  80 93 00 0d  orcc  %o4, %o5, %g0
a00b16e8:  12 80 00 04  bne  0xa00b16f8
a00b16ec:  80 a6 20 37  cmp  %i0, 0x37
a00b16f0:  32 80 00 02  bne,a   0xa00b16f8
a00b16f4:  b0 10 20 00  clr  %i0
a00b16f8:  81 c7 e0 08  ret
a00b16fc:  81 e8 00 00  restore
