# leon2m FUN_a0143e70 0xa0143e70-0xa0143f0c (156 bytes)
a0143e70:  9d e3 bf 98  save  %sp, -104, %sp
a0143e74:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0143e78:  80 a6 20 01  cmp  %i0, 1
a0143e7c:  02 80 00 0b  be  0xa0143ea8
a0143e80:  82 10 20 01  mov  1, %g1
a0143e84:  80 a6 20 01  cmp  %i0, 1
a0143e88:  04 80 00 11  ble  0xa0143ecc
a0143e8c:  80 a6 20 02  cmp  %i0, 2
a0143e90:  02 80 00 06  be  0xa0143ea8
a0143e94:  82 10 20 02  mov  2, %g1
a0143e98:  80 a6 20 03  cmp  %i0, 3
a0143e9c:  02 80 00 03  be  0xa0143ea8
a0143ea0:  82 10 20 03  mov  3, %g1
a0143ea4:  82 10 3f ff  mov  -1, %g1
a0143ea8:  9a 08 60 ff  and  %g1, 0xff, %o5
a0143eac:  80 a3 60 03  cmp  %o5, 3
a0143eb0:  08 80 00 0d  bleu  0xa0143ee4
a0143eb4:  9f 2b 60 04  sll  %o5, 4, %o7
a0143eb8:  11 00 06 9b  sethi  %hi(0x1a6c00), %o0
a0143ebc:  7f fe 6c ad  call  0xa00df170
a0143ec0:  90 12 21 d8  or  %o0, 0x1d8, %o0	! 0x1a6dd8
a0143ec4:  10 80 00 07  b  0xa0143ee0
a0143ec8:  9a 10 20 00  clr  %o5
a0143ecc:  80 a6 20 00  cmp  %i0, 0
a0143ed0:  02 bf ff f6  be  0xa0143ea8
a0143ed4:  82 10 20 00  clr  %g1
a0143ed8:  10 bf ff f4  b  0xa0143ea8
a0143edc:  82 10 3f ff  mov  -1, %g1
a0143ee0:  9f 2b 60 04  sll  %o5, 4, %o7
a0143ee4:  98 23 c0 0d  sub  %o7, %o5, %o4
a0143ee8:  17 2a 00 b7  sethi  %hi(0xa802dc00), %o3
a0143eec:  95 2b 20 03  sll  %o4, 3, %o2
a0143ef0:  9a 12 e3 30  or  %o3, 0x330, %o5
a0143ef4:  82 02 80 0d  add  %o2, %o5, %g1
a0143ef8:  d2 00 60 70  ld  [ %g1 + 0x70 ], %o1
a0143efc:  b1 32 60 1d  srl  %o1, 0x1d, %i0
a0143f00:  b0 0e 20 01  and  %i0, 1, %i0
a0143f04:  81 c7 e0 08  ret
a0143f08:  81 e8 00 00  restore
