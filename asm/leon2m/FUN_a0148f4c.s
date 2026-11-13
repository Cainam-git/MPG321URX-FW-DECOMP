# leon2m FUN_a0148f4c 0xa0148f4c-0xa0148fc0 (116 bytes)
a0148f4c:  9d e3 bf 98  save  %sp, -104, %sp
a0148f50:  21 2a 00 b8  sethi  %hi(0xa802e000), %l0
a0148f54:  82 14 23 d0  or  %l0, 0x3d0, %g1	! 0xa802e3d0
a0148f58:  c2 08 60 03  ldub  [ %g1 + 3 ], %g1
a0148f5c:  98 0e 20 ff  and  %i0, 0xff, %o4
a0148f60:  80 a0 40 0c  cmp  %g1, %o4
a0148f64:  02 80 00 15  be  0xa0148fb8
a0148f68:  80 a0 00 01  cmp  %g0, %g1
a0148f6c:  9a 40 20 00  addx  %g0, 0, %o5
a0148f70:  80 a0 00 0c  cmp  %g0, %o4
a0148f74:  96 40 20 00  addx  %g0, 0, %o3
a0148f78:  90 10 20 00  clr  %o0
a0148f7c:  92 10 29 60  mov  0x960, %o1
a0148f80:  80 8b 40 0b  btst  %o5, %o3
a0148f84:  12 80 00 0b  bne  0xa0148fb0
a0148f88:  94 10 20 01  mov  1, %o2
a0148f8c:  7f fe fb ae  call  0xa0107e44
a0148f90:  01 00 00 00  nop
a0148f94:  90 10 20 00  clr  %o0	! 0x0
a0148f98:  92 10 20 02  mov  2, %o1
a0148f9c:  7f ff 98 94  call  0xa012f1ec
a0148fa0:  01 00 00 00  nop
a0148fa4:  90 14 23 d0  or  %l0, 0x3d0, %o0
a0148fa8:  10 80 00 04  b  0xa0148fb8
a0148fac:  f0 2a 20 03  stb  %i0, [ %o0 + 3 ]
a0148fb0:  10 bf ff fb  b  0xa0148f9c
a0148fb4:  92 10 20 04  mov  4, %o1
a0148fb8:  81 c7 e0 08  ret
a0148fbc:  81 e8 00 00  restore
