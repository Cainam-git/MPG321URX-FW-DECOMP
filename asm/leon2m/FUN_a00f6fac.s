# leon2m FUN_a00f6fac 0xa00f6fac-0xa00f6fe4 (56 bytes)
a00f6fac:  9d e3 bf 98  save  %sp, -104, %sp
a00f6fb0:  40 00 97 f6  call  0xa011cf88
a00f6fb4:  b0 0e 20 01  and  %i0, 1, %i0
a00f6fb8:  03 33 c0 3b  sethi  %hi(0xcf00ec00), %g1
a00f6fbc:  90 0a 20 ff  and  %o0, 0xff, %o0
a00f6fc0:  80 a2 20 83  cmp  %o0, 0x83
a00f6fc4:  08 80 00 06  bleu  0xa00f6fdc
a00f6fc8:  9a 10 63 40  or  %g1, 0x340, %o5
a00f6fcc:  d6 03 40 00  ld  [ %o5 ], %o3
a00f6fd0:  94 0a e0 fe  and  %o3, 0xfe, %o2
a00f6fd4:  92 12 80 18  or  %o2, %i0, %o1
a00f6fd8:  d2 23 40 00  st  %o1, [ %o5 ]
a00f6fdc:  81 c7 e0 08  ret
a00f6fe0:  81 e8 00 00  restore
