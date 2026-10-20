# leon2m FUN_a01269a4 0xa01269a4-0xa01269f8 (84 bytes)
a01269a4:  9d e3 bf 90  save  %sp, -112, %sp
a01269a8:  7f ff f7 c8  call  0xa01248c8
a01269ac:  21 2a 00 b6  sethi  %hi(0xa802d800), %l0
a01269b0:  80 8a 20 ff  btst  0xff, %o0
a01269b4:  90 10 20 60  mov  0x60, %o0
a01269b8:  92 10 20 02  mov  2, %o1
a01269bc:  94 10 20 d0  mov  0xd0, %o2
a01269c0:  96 10 20 05  mov  5, %o3
a01269c4:  02 80 00 06  be  0xa01269dc
a01269c8:  98 10 20 00  clr  %o4
a01269cc:  82 10 20 02  mov  2, %g1
a01269d0:  c2 23 a0 5c  st  %g1, [ %sp + 0x5c ]
a01269d4:  40 00 84 45  call  0xa0147ae8
a01269d8:  9a 14 20 88  or  %l0, 0x88, %o5
a01269dc:  d2 0c 20 88  ldub  [ %l0 + 0x88 ], %o1
a01269e0:  9a 14 20 88  or  %l0, 0x88, %o5
a01269e4:  b1 2a 60 08  sll  %o1, 8, %i0
a01269e8:  d0 0b 60 01  ldub  [ %o5 + 1 ], %o0
a01269ec:  b0 12 00 18  or  %o0, %i0, %i0
a01269f0:  81 c7 e0 08  ret
a01269f4:  81 e8 00 00  restore
