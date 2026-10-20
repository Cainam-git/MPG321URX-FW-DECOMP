# leon2m FUN_a00d2884 0xa00d2884-0xa00d28d4 (80 bytes)
a00d2884:  9d e3 bf 98  save  %sp, -104, %sp
a00d2888:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00d288c:  c2 0e 20 07  ldub  [ %i0 + 7 ], %g1
a00d2890:  80 a0 60 01  cmp  %g1, 1
a00d2894:  02 80 00 08  be  0xa00d28b4
a00d2898:  9a 12 62 74  or  %o1, 0x274, %o5
a00d289c:  80 a0 60 00  cmp  %g1, 0
a00d28a0:  32 80 00 07  bne,a   0xa00d28bc
a00d28a4:  92 12 62 74  or  %o1, 0x274, %o1
a00d28a8:  82 12 62 74  or  %o1, 0x274, %g1
a00d28ac:  10 80 00 03  b  0xa00d28b8
a00d28b0:  c0 28 60 14  clrb  [ %g1 + 0x14 ]
a00d28b4:  c2 2b 60 14  stb  %g1, [ %o5 + 0x14 ]
a00d28b8:  92 12 62 74  or  %o1, 0x274, %o1
a00d28bc:  90 10 20 30  mov  0x30, %o0
a00d28c0:  94 10 22 e0  mov  0x2e0, %o2
a00d28c4:  40 01 e1 83  call  0xa014aed0
a00d28c8:  96 10 20 1c  mov  0x1c, %o3
a00d28cc:  81 c7 e0 08  ret
a00d28d0:  91 e8 20 e0  restore  %g0, 0xe0, %o0
