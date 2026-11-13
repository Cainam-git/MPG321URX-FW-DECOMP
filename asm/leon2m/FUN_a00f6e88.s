# leon2m FUN_a00f6e88 0xa00f6e88-0xa00f6ecc (68 bytes)
a00f6e88:  9d e3 bf 98  save  %sp, -104, %sp
a00f6e8c:  03 2a 00 ad  sethi  %hi(0xa802b400), %g1
a00f6e90:  c2 00 63 b8  ld  [ %g1 + 0x3b8 ], %g1	! 0xa802b7b8
a00f6e94:  92 0e 20 ff  and  %i0, 0xff, %o1
a00f6e98:  90 10 20 03  mov  3, %o0
a00f6e9c:  80 a0 60 00  cmp  %g1, 0
a00f6ea0:  12 80 00 06  bne  0xa00f6eb8
a00f6ea4:  b0 10 00 09  mov  %o1, %i0
a00f6ea8:  13 33 c0 3b  sethi  %hi(0xcf00ec00), %o1
a00f6eac:  90 12 63 10  or  %o1, 0x310, %o0	! 0xcf00ef10
a00f6eb0:  f0 22 00 00  st  %i0, [ %o0 ]
a00f6eb4:  30 80 00 03  b,a   0xa00f6ec0
a00f6eb8:  9f c0 40 00  call  %g1
a00f6ebc:  01 00 00 00  nop
a00f6ec0:  01 00 00 00  nop
a00f6ec4:  81 c7 e0 08  ret
a00f6ec8:  81 e8 00 00  restore
