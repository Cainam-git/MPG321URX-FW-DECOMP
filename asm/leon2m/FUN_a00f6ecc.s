# leon2m FUN_a00f6ecc 0xa00f6ecc-0xa00f6f10 (68 bytes)
a00f6ecc:  9d e3 bf 98  save  %sp, -104, %sp
a00f6ed0:  03 2a 00 ad  sethi  %hi(0xa802b400), %g1
a00f6ed4:  c2 00 63 b8  ld  [ %g1 + 0x3b8 ], %g1	! 0xa802b7b8
a00f6ed8:  92 0e 20 ff  and  %i0, 0xff, %o1
a00f6edc:  90 10 20 04  mov  4, %o0
a00f6ee0:  80 a0 60 00  cmp  %g1, 0
a00f6ee4:  12 80 00 06  bne  0xa00f6efc
a00f6ee8:  b0 10 00 09  mov  %o1, %i0
a00f6eec:  13 33 c0 3b  sethi  %hi(0xcf00ec00), %o1
a00f6ef0:  90 12 63 14  or  %o1, 0x314, %o0	! 0xcf00ef14
a00f6ef4:  f0 22 00 00  st  %i0, [ %o0 ]
a00f6ef8:  30 80 00 03  b,a   0xa00f6f04
a00f6efc:  9f c0 40 00  call  %g1
a00f6f00:  01 00 00 00  nop
a00f6f04:  01 00 00 00  nop
a00f6f08:  81 c7 e0 08  ret
a00f6f0c:  81 e8 00 00  restore
