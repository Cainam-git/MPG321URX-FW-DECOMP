# leon2m FUN_a0143f0c 0xa0143f0c-0xa0143fa8 (156 bytes)
a0143f0c:  9d e3 bf 98  save  %sp, -104, %sp
a0143f10:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0143f14:  80 a6 20 01  cmp  %i0, 1
a0143f18:  02 80 00 0b  be  0xa0143f44
a0143f1c:  82 10 20 01  mov  1, %g1
a0143f20:  80 a6 20 01  cmp  %i0, 1
a0143f24:  04 80 00 11  ble  0xa0143f68
a0143f28:  80 a6 20 02  cmp  %i0, 2
a0143f2c:  02 80 00 06  be  0xa0143f44
a0143f30:  82 10 20 02  mov  2, %g1
a0143f34:  80 a6 20 03  cmp  %i0, 3
a0143f38:  02 80 00 03  be  0xa0143f44
a0143f3c:  82 10 20 03  mov  3, %g1
a0143f40:  82 10 3f ff  mov  -1, %g1
a0143f44:  9a 08 60 ff  and  %g1, 0xff, %o5
a0143f48:  80 a3 60 03  cmp  %o5, 3
a0143f4c:  08 80 00 0d  bleu  0xa0143f80
a0143f50:  9f 2b 60 04  sll  %o5, 4, %o7
a0143f54:  11 00 06 9b  sethi  %hi(0x1a6c00), %o0
a0143f58:  7f fe 6c 86  call  0xa00df170
a0143f5c:  90 12 21 d8  or  %o0, 0x1d8, %o0	! 0x1a6dd8
a0143f60:  10 80 00 07  b  0xa0143f7c
a0143f64:  9a 10 20 00  clr  %o5
a0143f68:  80 a6 20 00  cmp  %i0, 0
a0143f6c:  02 bf ff f6  be  0xa0143f44
a0143f70:  82 10 20 00  clr  %g1
a0143f74:  10 bf ff f4  b  0xa0143f44
a0143f78:  82 10 3f ff  mov  -1, %g1
a0143f7c:  9f 2b 60 04  sll  %o5, 4, %o7
a0143f80:  98 23 c0 0d  sub  %o7, %o5, %o4
a0143f84:  17 2a 00 b7  sethi  %hi(0xa802dc00), %o3
a0143f88:  95 2b 20 03  sll  %o4, 3, %o2
a0143f8c:  9a 12 e3 30  or  %o3, 0x330, %o5
a0143f90:  82 02 80 0d  add  %o2, %o5, %g1
a0143f94:  d2 00 60 70  ld  [ %g1 + 0x70 ], %o1
a0143f98:  b1 32 60 1c  srl  %o1, 0x1c, %i0
a0143f9c:  b0 0e 20 01  and  %i0, 1, %i0
a0143fa0:  81 c7 e0 08  ret
a0143fa4:  81 e8 00 00  restore
