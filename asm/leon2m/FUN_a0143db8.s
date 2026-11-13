# leon2m FUN_a0143db8 0xa0143db8-0xa0143e70 (184 bytes)
a0143db8:  9d e3 bf 98  save  %sp, -104, %sp
a0143dbc:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0143dc0:  80 a6 20 01  cmp  %i0, 1
a0143dc4:  02 80 00 0b  be  0xa0143df0
a0143dc8:  98 10 20 01  mov  1, %o4
a0143dcc:  80 a6 20 01  cmp  %i0, 1
a0143dd0:  04 80 00 11  ble  0xa0143e14
a0143dd4:  80 a6 20 02  cmp  %i0, 2
a0143dd8:  02 80 00 06  be  0xa0143df0
a0143ddc:  98 10 20 02  mov  2, %o4
a0143de0:  80 a6 20 03  cmp  %i0, 3
a0143de4:  02 80 00 03  be  0xa0143df0
a0143de8:  98 10 20 03  mov  3, %o4
a0143dec:  98 10 3f ff  mov  -1, %o4
a0143df0:  82 0b 20 ff  and  %o4, 0xff, %g1
a0143df4:  80 a0 60 03  cmp  %g1, 3
a0143df8:  08 80 00 0d  bleu  0xa0143e2c
a0143dfc:  9b 28 60 04  sll  %g1, 4, %o5
a0143e00:  11 00 06 9b  sethi  %hi(0x1a6c00), %o0
a0143e04:  7f fe 6c db  call  0xa00df170
a0143e08:  90 12 21 d8  or  %o0, 0x1d8, %o0	! 0x1a6dd8
a0143e0c:  10 80 00 07  b  0xa0143e28
a0143e10:  82 10 20 00  clr  %g1
a0143e14:  80 a6 20 00  cmp  %i0, 0
a0143e18:  02 bf ff f6  be  0xa0143df0
a0143e1c:  98 10 20 00  clr  %o4
a0143e20:  10 bf ff f4  b  0xa0143df0
a0143e24:  98 10 3f ff  mov  -1, %o4
a0143e28:  9b 28 60 04  sll  %g1, 4, %o5
a0143e2c:  94 23 40 01  sub  %o5, %g1, %o2
a0143e30:  03 2a 00 b7  sethi  %hi(0xa802dc00), %g1
a0143e34:  99 2a a0 03  sll  %o2, 3, %o4
a0143e38:  92 10 63 30  or  %g1, 0x330, %o1
a0143e3c:  d0 03 00 09  ld  [ %o4 + %o1 ], %o0
a0143e40:  b1 32 20 0c  srl  %o0, 0xc, %i0
a0143e44:  9e 0e 20 0f  and  %i0, 0xf, %o7
a0143e48:  17 2a 00 b8  sethi  %hi(0xa802e000), %o3
a0143e4c:  94 5b e0 2a  smul  %o7, 0x2a, %o2
a0143e50:  9a 12 e2 24  or  %o3, 0x224, %o5
a0143e54:  82 02 80 0d  add  %o2, %o5, %g1
a0143e58:  d2 08 60 02  ldub  [ %g1 + 2 ], %o1
a0143e5c:  98 1a 60 04  xor  %o1, 4, %o4
a0143e60:  80 a0 00 0c  cmp  %g0, %o4
a0143e64:  b0 60 3f ff  subx  %g0, -1, %i0
a0143e68:  81 c7 e0 08  ret
a0143e6c:  81 e8 00 00  restore
