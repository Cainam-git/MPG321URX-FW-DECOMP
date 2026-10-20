# leon2m FUN_a0145ee8 0xa0145ee8-0xa0145fac (196 bytes)
a0145ee8:  9d e3 bf 98  save  %sp, -104, %sp
a0145eec:  80 8e 60 ff  btst  0xff, %i1
a0145ef0:  02 80 00 04  be  0xa0145f00
a0145ef4:  01 00 00 00  nop
a0145ef8:  7f ff d5 fb  call  0xa013b6e4
a0145efc:  91 e8 20 00  restore  %g0, 0, %o0
a0145f00:  7f ff d5 f9  call  0xa013b6e4
a0145f04:  90 10 20 01  mov  1, %o0
a0145f08:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0145f0c:  80 a6 20 01  cmp  %i0, 1
a0145f10:  02 80 00 0b  be  0xa0145f3c
a0145f14:  82 10 20 01  mov  1, %g1
a0145f18:  80 a6 20 01  cmp  %i0, 1
a0145f1c:  04 80 00 1d  ble  0xa0145f90
a0145f20:  80 a6 20 02  cmp  %i0, 2
a0145f24:  02 80 00 06  be  0xa0145f3c
a0145f28:  82 10 20 02  mov  2, %g1
a0145f2c:  80 a6 20 03  cmp  %i0, 3
a0145f30:  02 80 00 03  be  0xa0145f3c
a0145f34:  82 10 20 03  mov  3, %g1
a0145f38:  82 10 3f ff  mov  -1, %g1
a0145f3c:  9a 08 60 ff  and  %g1, 0xff, %o5
a0145f40:  80 a3 60 03  cmp  %o5, 3
a0145f44:  38 80 00 0f  bgu,a   0xa0145f80
a0145f48:  11 00 06 9b  sethi  %hi(0x1a6c00), %o0
a0145f4c:  9f 2b 60 04  sll  %o5, 4, %o7
a0145f50:  96 23 c0 0d  sub  %o7, %o5, %o3
a0145f54:  15 2a 00 b7  sethi  %hi(0xa802dc00), %o2
a0145f58:  83 2a e0 03  sll  %o3, 3, %g1
a0145f5c:  9a 12 a3 30  or  %o2, 0x330, %o5
a0145f60:  d2 03 40 01  ld  [ %o5 + %g1 ], %o1
a0145f64:  99 32 60 04  srl  %o1, 4, %o4
a0145f68:  b0 0b 20 0f  and  %o4, 0xf, %i0
a0145f6c:  80 a6 20 04  cmp  %i0, 4
a0145f70:  02 80 00 0d  be  0xa0145fa4
a0145f74:  01 00 00 00  nop
a0145f78:  7f fe c1 11  call  0xa00f63bc
a0145f7c:  81 e8 00 00  restore
a0145f80:  7f fe 64 7c  call  0xa00df170
a0145f84:  90 12 21 d8  or  %o0, 0x1d8, %o0
a0145f88:  10 bf ff f1  b  0xa0145f4c
a0145f8c:  9a 10 20 00  clr  %o5
a0145f90:  80 a6 20 00  cmp  %i0, 0
a0145f94:  02 bf ff ea  be  0xa0145f3c
a0145f98:  82 10 20 00  clr  %g1
a0145f9c:  10 bf ff e8  b  0xa0145f3c
a0145fa0:  82 10 3f ff  mov  -1, %g1
a0145fa4:  81 c7 e0 08  ret
a0145fa8:  81 e8 00 00  restore
