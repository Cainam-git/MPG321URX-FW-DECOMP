# leon2m FUN_a0148fc0 0xa0148fc0-0xa0149018 (88 bytes)
a0148fc0:  9d e3 bf 98  save  %sp, -104, %sp
a0148fc4:  15 2a 00 b8  sethi  %hi(0xa802e000), %o2
a0148fc8:  9a 12 a3 d0  or  %o2, 0x3d0, %o5	! 0xa802e3d0
a0148fcc:  d8 03 60 04  ld  [ %o5 + 4 ], %o4
a0148fd0:  13 3c 00 00  sethi  %hi(0xf0000000), %o1
a0148fd4:  90 2b 00 09  andn  %o4, %o1, %o0
a0148fd8:  b1 2e 20 1c  sll  %i0, 0x1c, %i0
a0148fdc:  82 12 00 18  or  %o0, %i0, %g1
a0148fe0:  c2 23 60 04  st  %g1, [ %o5 + 4 ]
a0148fe4:  90 10 20 00  clr  %o0
a0148fe8:  7f ff 98 81  call  0xa012f1ec
a0148fec:  92 10 20 02  mov  2, %o1
a0148ff0:  90 10 20 01  mov  1, %o0
a0148ff4:  7f ff 98 7e  call  0xa012f1ec
a0148ff8:  92 10 20 02  mov  2, %o1
a0148ffc:  90 10 20 02  mov  2, %o0
a0149000:  7f ff 98 7b  call  0xa012f1ec
a0149004:  92 10 20 02  mov  2, %o1
a0149008:  b0 10 20 03  mov  3, %i0
a014900c:  7f ff 98 78  call  0xa012f1ec
a0149010:  93 e8 20 02  restore  %g0, 2, %o1
a0149014:  01 00 00 00  nop
