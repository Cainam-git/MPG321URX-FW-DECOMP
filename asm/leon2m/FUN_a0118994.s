# leon2m FUN_a0118994 0xa0118994-0xa0118a28 (148 bytes)
a0118994:  9d e3 bf 98  save  %sp, -104, %sp
a0118998:  21 33 c0 4b  sethi  %hi(0xcf012c00), %l0
a011899c:  82 14 22 00  or  %l0, 0x200, %g1	! 0xcf012e00
a01189a0:  da 00 40 00  ld  [ %g1 ], %o5
a01189a4:  80 8b 60 01  btst  1, %o5
a01189a8:  02 80 00 1e  be  0xa0118a20
a01189ac:  19 33 c0 45  sethi  %hi(0xcf011400), %o4
a01189b0:  96 13 21 c0  or  %o4, 0x1c0, %o3	! 0xcf0115c0
a01189b4:  d4 02 c0 00  ld  [ %o3 ], %o2
a01189b8:  90 0e 20 ff  and  %i0, 0xff, %o0
a01189bc:  80 8a a0 01  btst  1, %o2
a01189c0:  12 80 00 18  bne  0xa0118a20
a01189c4:  92 10 20 50  mov  0x50, %o1
a01189c8:  7f ff 66 23  call  0xa00f2254
a01189cc:  01 00 00 00  nop
a01189d0:  80 8a 20 01  btst  1, %o0
a01189d4:  02 80 00 13  be  0xa0118a20
a01189d8:  19 2a 00 b2  sethi  %hi(0xa802c800), %o4
a01189dc:  d2 0b 21 9c  ldub  [ %o4 + 0x19c ], %o1	! 0xa802c99c
a01189e0:  9a 02 60 01  add  %o1, 1, %o5
a01189e4:  90 0b 60 ff  and  %o5, 0xff, %o0
a01189e8:  80 a2 20 32  cmp  %o0, 0x32
a01189ec:  08 80 00 0a  bleu  0xa0118a14
a01189f0:  96 14 23 24  or  %l0, 0x324, %o3
a01189f4:  de 02 c0 00  ld  [ %o3 ], %o7
a01189f8:  94 14 23 00  or  %l0, 0x300, %o2
a01189fc:  80 a3 e0 00  cmp  %o7, 0
a0118a00:  02 80 00 07  be  0xa0118a1c
a0118a04:  c0 2b 21 9c  clrb  [ %o4 + 0x19c ]
a0118a08:  a0 10 20 40  mov  0x40, %l0
a0118a0c:  e0 22 80 00  st  %l0, [ %o2 ]
a0118a10:  30 80 00 04  b,a   0xa0118a20
a0118a14:  10 80 00 03  b  0xa0118a20
a0118a18:  da 2b 21 9c  stb  %o5, [ %o4 + 0x19c ]
a0118a1c:  c0 22 80 00  clr  [ %o2 ]
a0118a20:  81 c7 e0 08  ret
a0118a24:  81 e8 00 00  restore
