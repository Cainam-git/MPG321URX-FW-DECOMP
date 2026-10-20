# leon2m FUN_a00f3580 0xa00f3580-0xa00f35d0 (80 bytes)
a00f3580:  9d e3 bf 98  save  %sp, -104, %sp
a00f3584:  1b 2a 00 ad  sethi  %hi(0xa802b400), %o5
a00f3588:  c2 0b 63 70  ldub  [ %o5 + 0x370 ], %g1	! 0xa802b770
a00f358c:  80 a0 60 00  cmp  %g1, 0
a00f3590:  02 80 00 06  be  0xa00f35a8
a00f3594:  9a 13 63 70  or  %o5, 0x370, %o5
a00f3598:  da 03 60 10  ld  [ %o5 + 0x10 ], %o5
a00f359c:  80 a3 60 00  cmp  %o5, 0
a00f35a0:  12 80 00 07  bne  0xa00f35bc
a00f35a4:  01 00 00 00  nop
a00f35a8:  15 33 c0 4a  sethi  %hi(0xcf012800), %o2
a00f35ac:  92 12 a0 1c  or  %o2, 0x1c, %o1	! 0xcf01281c
a00f35b0:  d0 02 40 00  ld  [ %o1 ], %o0
a00f35b4:  10 80 00 05  b  0xa00f35c8
a00f35b8:  b0 0a 20 3f  and  %o0, 0x3f, %i0
a00f35bc:  9f c3 40 00  call  %o5
a00f35c0:  01 00 00 00  nop
a00f35c4:  b0 0a 20 ff  and  %o0, 0xff, %i0
a00f35c8:  81 c7 e0 08  ret
a00f35cc:  81 e8 00 00  restore
