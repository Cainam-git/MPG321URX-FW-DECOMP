# leon2m FUN_a0149f44 0xa0149f44-0xa0149fb8 (116 bytes)
a0149f44:  9d e3 bf 98  save  %sp, -104, %sp
a0149f48:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0149f4c:  80 a6 20 01  cmp  %i0, 1
a0149f50:  02 80 00 0b  be  0xa0149f7c
a0149f54:  82 10 20 01  mov  1, %g1
a0149f58:  80 a6 20 01  cmp  %i0, 1
a0149f5c:  04 80 00 12  ble  0xa0149fa4
a0149f60:  80 a6 20 02  cmp  %i0, 2
a0149f64:  02 80 00 06  be  0xa0149f7c
a0149f68:  82 10 20 02  mov  2, %g1
a0149f6c:  80 a6 20 03  cmp  %i0, 3
a0149f70:  02 80 00 03  be  0xa0149f7c
a0149f74:  82 10 20 03  mov  3, %g1
a0149f78:  82 10 3f ff  mov  -1, %g1
a0149f7c:  b0 08 60 ff  and  %g1, 0xff, %i0
a0149f80:  80 a6 20 03  cmp  %i0, 3
a0149f84:  38 80 00 04  bgu,a   0xa0149f94
a0149f88:  11 00 06 9b  sethi  %hi(0x1a6c00), %o0
a0149f8c:  7f ff cd be  call  0xa013d684
a0149f90:  81 e8 00 00  restore
a0149f94:  7f fe 54 77  call  0xa00df170
a0149f98:  90 12 21 d8  or  %o0, 0x1d8, %o0
a0149f9c:  7f ff cd ba  call  0xa013d684
a0149fa0:  91 e8 20 00  restore  %g0, 0, %o0
a0149fa4:  80 a6 20 00  cmp  %i0, 0
a0149fa8:  02 bf ff f5  be  0xa0149f7c
a0149fac:  82 10 20 00  clr  %g1
a0149fb0:  10 bf ff f3  b  0xa0149f7c
a0149fb4:  82 10 3f ff  mov  -1, %g1
