# leon2m FUN_a00f6dd8 0xa00f6dd8-0xa00f6e30 (88 bytes)
a00f6dd8:  9d e3 bf 98  save  %sp, -104, %sp
a00f6ddc:  03 2a 00 ad  sethi  %hi(0xa802b400), %g1
a00f6de0:  d8 00 63 b8  ld  [ %g1 + 0x3b8 ], %o4	! 0xa802b7b8
a00f6de4:  90 10 20 01  mov  1, %o0
a00f6de8:  80 8e 20 80  btst  0x80, %i0
a00f6dec:  12 80 00 0d  bne  0xa00f6e20
a00f6df0:  82 16 3f 80  or  %i0, -128, %g1
a00f6df4:  92 08 60 ff  and  %g1, 0xff, %o1
a00f6df8:  80 a3 20 00  cmp  %o4, 0
a00f6dfc:  12 80 00 06  bne  0xa00f6e14
a00f6e00:  9a 10 00 09  mov  %o1, %o5
a00f6e04:  13 33 c0 3b  sethi  %hi(0xcf00ec00), %o1
a00f6e08:  90 12 63 08  or  %o1, 0x308, %o0	! 0xcf00ef08
a00f6e0c:  da 22 00 00  st  %o5, [ %o0 ]
a00f6e10:  30 80 00 06  b,a   0xa00f6e28
a00f6e14:  9f c3 00 00  call  %o4
a00f6e18:  01 00 00 00  nop
a00f6e1c:  30 80 00 03  b,a   0xa00f6e28
a00f6e20:  10 bf ff f5  b  0xa00f6df4
a00f6e24:  82 0e 20 7f  and  %i0, 0x7f, %g1
a00f6e28:  81 c7 e0 08  ret
a00f6e2c:  81 e8 00 00  restore
