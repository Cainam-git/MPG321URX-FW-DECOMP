# leon2m FUN_a00c1704 0xa00c1704-0xa00c17e8 (228 bytes)
a00c1704:  9d e3 bf 98  save  %sp, -104, %sp
a00c1708:  a0 0e 20 ff  and  %i0, 0xff, %l0
a00c170c:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00c1710:  80 a4 20 02  cmp  %l0, 2
a00c1714:  02 80 00 08  be  0xa00c1734
a00c1718:  82 10 60 40  or  %g1, 0x40, %g1
a00c171c:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00c1720:  80 a4 20 03  cmp  %l0, 3
a00c1724:  02 80 00 04  be  0xa00c1734
a00c1728:  82 12 20 98  or  %o0, 0x98, %g1
a00c172c:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00c1730:  82 12 60 d0  or  %o1, 0xd0, %g1	! 0xa802d0d0
a00c1734:  de 08 60 07  ldub  [ %g1 + 7 ], %o7
a00c1738:  94 03 ff d0  add  %o7, -48, %o2
a00c173c:  9a 0a a0 ff  and  %o2, 0xff, %o5
a00c1740:  80 a3 60 01  cmp  %o5, 1
a00c1744:  d6 08 60 09  ldub  [ %g1 + 9 ], %o3
a00c1748:  d8 08 60 08  ldub  [ %g1 + 8 ], %o4
a00c174c:  18 80 00 07  bgu  0xa00c1768
a00c1750:  9a 10 20 ff  mov  0xff, %o5
a00c1754:  98 03 3f d0  add  %o4, -48, %o4
a00c1758:  b0 0b 20 ff  and  %o4, 0xff, %i0
a00c175c:  80 a6 20 09  cmp  %i0, 9
a00c1760:  28 80 00 11  bleu,a   0xa00c17a4
a00c1764:  96 02 ff d0  add  %o3, -48, %o3
a00c1768:  80 a3 60 0b  cmp  %o5, 0xb
a00c176c:  18 80 00 1d  bgu  0xa00c17e0
a00c1770:  b0 10 20 ff  mov  0xff, %i0
a00c1774:  17 2a 00 b5  sethi  %hi(0xa802d400), %o3
a00c1778:  7f ff dc 55  call  0xa00b88cc
a00c177c:  da 2a e0 1a  stb  %o5, [ %o3 + 0x1a ]	! 0xa802d41a
a00c1780:  7f ff e4 bb  call  0xa00baa6c
a00c1784:  90 10 00 10  mov  %l0, %o0
a00c1788:  7f ff e4 72  call  0xa00ba950
a00c178c:  90 10 00 10  mov  %l0, %o0
a00c1790:  90 10 00 10  mov  %l0, %o0
a00c1794:  7f ff e4 fb  call  0xa00bab80
a00c1798:  92 10 20 06  mov  6, %o1
a00c179c:  10 80 00 11  b  0xa00c17e0
a00c17a0:  b0 10 20 00  clr  %i0
a00c17a4:  82 0a e0 ff  and  %o3, 0xff, %g1
a00c17a8:  80 a0 60 09  cmp  %g1, 9
a00c17ac:  18 bf ff f0  bgu  0xa00c176c
a00c17b0:  80 a3 60 0b  cmp  %o5, 0xb
a00c17b4:  90 0b 20 ff  and  %o4, 0xff, %o0
a00c17b8:  83 2a 20 02  sll  %o0, 2, %g1
a00c17bc:  9e 00 40 08  add  %g1, %o0, %o7
a00c17c0:  b0 0a a0 ff  and  %o2, 0xff, %i0
a00c17c4:  9a 03 c0 0f  add  %o7, %o7, %o5
a00c17c8:  92 5e 20 64  smul  %i0, 0x64, %o1
a00c17cc:  90 02 40 0d  add  %o1, %o5, %o0
a00c17d0:  98 0a e0 ff  and  %o3, 0xff, %o4
a00c17d4:  94 02 00 0c  add  %o0, %o4, %o2
a00c17d8:  10 bf ff e4  b  0xa00c1768
a00c17dc:  9a 0a a0 ff  and  %o2, 0xff, %o5
a00c17e0:  81 c7 e0 08  ret
a00c17e4:  81 e8 00 00  restore
