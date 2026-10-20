# leon2m FUN_a00f6f10 0xa00f6f10-0xa00f6f54 (68 bytes)
a00f6f10:  9d e3 bf 98  save  %sp, -104, %sp
a00f6f14:  03 2a 00 ad  sethi  %hi(0xa802b400), %g1
a00f6f18:  c2 00 63 b8  ld  [ %g1 + 0x3b8 ], %g1	! 0xa802b7b8
a00f6f1c:  92 0e 20 ff  and  %i0, 0xff, %o1
a00f6f20:  90 10 20 05  mov  5, %o0
a00f6f24:  80 a0 60 00  cmp  %g1, 0
a00f6f28:  12 80 00 06  bne  0xa00f6f40
a00f6f2c:  b0 10 00 09  mov  %o1, %i0
a00f6f30:  13 33 c0 3b  sethi  %hi(0xcf00ec00), %o1
a00f6f34:  90 12 63 18  or  %o1, 0x318, %o0	! 0xcf00ef18
a00f6f38:  f0 22 00 00  st  %i0, [ %o0 ]
a00f6f3c:  30 80 00 03  b,a   0xa00f6f48
a00f6f40:  9f c0 40 00  call  %g1
a00f6f44:  01 00 00 00  nop
a00f6f48:  01 00 00 00  nop
a00f6f4c:  81 c7 e0 08  ret
a00f6f50:  81 e8 00 00  restore
