# leon2m FUN_a0146ef4 0xa0146ef4-0xa0146fdc (232 bytes)
a0146ef4:  9d e3 bf 98  save  %sp, -104, %sp
a0146ef8:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0146efc:  80 a6 20 01  cmp  %i0, 1
a0146f00:  02 80 00 0b  be  0xa0146f2c
a0146f04:  82 10 20 01  mov  1, %g1
a0146f08:  80 a6 20 01  cmp  %i0, 1
a0146f0c:  04 80 00 2d  ble  0xa0146fc0
a0146f10:  80 a6 20 02  cmp  %i0, 2
a0146f14:  02 80 00 06  be  0xa0146f2c
a0146f18:  82 10 20 02  mov  2, %g1
a0146f1c:  80 a6 20 03  cmp  %i0, 3
a0146f20:  02 80 00 03  be  0xa0146f2c
a0146f24:  82 10 20 03  mov  3, %g1
a0146f28:  82 10 3f ff  mov  -1, %g1
a0146f2c:  9a 08 60 ff  and  %g1, 0xff, %o5
a0146f30:  80 a3 60 03  cmp  %o5, 3
a0146f34:  18 80 00 11  bgu  0xa0146f78
a0146f38:  9f 2b 60 04  sll  %o5, 4, %o7
a0146f3c:  96 23 c0 0d  sub  %o7, %o5, %o3
a0146f40:  15 2a 00 b7  sethi  %hi(0xa802dc00), %o2
a0146f44:  83 2a e0 03  sll  %o3, 3, %g1
a0146f48:  9a 12 a3 30  or  %o2, 0x330, %o5
a0146f4c:  d2 03 40 01  ld  [ %o5 + %g1 ], %o1
a0146f50:  99 32 60 04  srl  %o1, 4, %o4
a0146f54:  b0 0b 20 0f  and  %o4, 0xf, %i0
a0146f58:  80 a6 20 04  cmp  %i0, 4
a0146f5c:  02 80 00 1e  be  0xa0146fd4
a0146f60:  90 0e 60 ff  and  %i1, 0xff, %o0
a0146f64:  80 a2 20 01  cmp  %o0, 1
a0146f68:  02 80 00 14  be  0xa0146fb8
a0146f6c:  01 00 00 00  nop
a0146f70:  7f fe be 18  call  0xa00f67d0
a0146f74:  81 e8 00 00  restore
a0146f78:  11 00 06 9b  sethi  %hi(0x1a6c00), %o0
a0146f7c:  7f fe 60 7d  call  0xa00df170
a0146f80:  90 12 21 d8  or  %o0, 0x1d8, %o0	! 0x1a6dd8
a0146f84:  9a 10 20 00  clr  %o5
a0146f88:  9f 2b 60 04  sll  %o5, 4, %o7
a0146f8c:  96 23 c0 0d  sub  %o7, %o5, %o3
a0146f90:  15 2a 00 b7  sethi  %hi(0xa802dc00), %o2
a0146f94:  83 2a e0 03  sll  %o3, 3, %g1
a0146f98:  9a 12 a3 30  or  %o2, 0x330, %o5
a0146f9c:  d2 03 40 01  ld  [ %o5 + %g1 ], %o1
a0146fa0:  99 32 60 04  srl  %o1, 4, %o4
a0146fa4:  b0 0b 20 0f  and  %o4, 0xf, %i0
a0146fa8:  80 a6 20 04  cmp  %i0, 4
a0146fac:  32 bf ff ee  bne,a   0xa0146f64
a0146fb0:  90 0e 60 ff  and  %i1, 0xff, %o0
a0146fb4:  30 80 00 08  b,a   0xa0146fd4
a0146fb8:  7f fe be 38  call  0xa00f6898
a0146fbc:  81 e8 00 00  restore
a0146fc0:  80 a6 20 00  cmp  %i0, 0
a0146fc4:  02 bf ff da  be  0xa0146f2c
a0146fc8:  82 10 20 00  clr  %g1
a0146fcc:  10 bf ff d8  b  0xa0146f2c
a0146fd0:  82 10 3f ff  mov  -1, %g1
a0146fd4:  81 c7 e0 08  ret
a0146fd8:  81 e8 00 00  restore
