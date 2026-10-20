# leon2m FUN_a01269f8 0xa01269f8-0xa0126a4c (84 bytes)
a01269f8:  9d e3 bf 90  save  %sp, -112, %sp
a01269fc:  7f ff f7 b3  call  0xa01248c8
a0126a00:  21 2a 00 b6  sethi  %hi(0xa802d800), %l0
a0126a04:  80 8a 20 ff  btst  0xff, %o0
a0126a08:  90 10 20 60  mov  0x60, %o0
a0126a0c:  92 10 20 02  mov  2, %o1
a0126a10:  94 10 20 10  mov  0x10, %o2
a0126a14:  96 10 20 05  mov  5, %o3
a0126a18:  02 80 00 06  be  0xa0126a30
a0126a1c:  98 10 20 00  clr  %o4
a0126a20:  82 10 20 02  mov  2, %g1
a0126a24:  c2 23 a0 5c  st  %g1, [ %sp + 0x5c ]
a0126a28:  40 00 84 30  call  0xa0147ae8
a0126a2c:  9a 14 20 88  or  %l0, 0x88, %o5
a0126a30:  d2 0c 20 88  ldub  [ %l0 + 0x88 ], %o1
a0126a34:  9a 14 20 88  or  %l0, 0x88, %o5
a0126a38:  b1 2a 60 08  sll  %o1, 8, %i0
a0126a3c:  d0 0b 60 01  ldub  [ %o5 + 1 ], %o0
a0126a40:  b0 12 00 18  or  %o0, %i0, %i0
a0126a44:  81 c7 e0 08  ret
a0126a48:  81 e8 00 00  restore
