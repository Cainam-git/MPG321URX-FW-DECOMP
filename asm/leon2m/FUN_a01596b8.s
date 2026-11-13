# leon2m FUN_a01596b8 0xa01596b8-0xa0159708 (80 bytes)
a01596b8:  9d e3 bf 88  save  %sp, -120, %sp
a01596bc:  92 07 bf e8  add  %fp, -24, %o1
a01596c0:  94 10 20 00  clr  %o2
a01596c4:  90 10 00 18  mov  %i0, %o0
a01596c8:  80 a6 60 00  cmp  %i1, 0
a01596cc:  02 80 00 06  be  0xa01596e4
a01596d0:  96 10 00 1b  mov  %i3, %o3
a01596d4:  92 10 00 19  mov  %i1, %o1
a01596d8:  94 10 00 1a  mov  %i2, %o2
a01596dc:  90 10 00 18  mov  %i0, %o0
a01596e0:  96 10 00 1b  mov  %i3, %o3
a01596e4:  40 00 00 63  call  0xa0159870
a01596e8:  01 00 00 00  nop
a01596ec:  80 a2 3f ff  cmp  %o0, -1
a01596f0:  12 80 00 04  bne  0xa0159700
a01596f4:  82 10 20 8a  mov  0x8a, %g1
a01596f8:  c0 26 c0 00  clr  [ %i3 ]
a01596fc:  c2 26 00 00  st  %g1, [ %i0 ]
a0159700:  81 c7 e0 08  ret
a0159704:  91 e8 00 08  restore  %g0, %o0, %o0
