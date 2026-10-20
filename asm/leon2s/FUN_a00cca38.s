# leon2s FUN_a00cca38 0xa00cca38-0xa00ccad4 (156 bytes)
a00cca38:  9d e3 bf 98  save  %sp, -104, %sp
a00cca3c:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00cca40:  92 10 20 06  mov  6, %o1
a00cca44:  80 a6 20 01  cmp  %i0, 1
a00cca48:  12 80 00 14  bne  0xa00cca98
a00cca4c:  90 10 20 00  clr  %o0
a00cca50:  40 3b ac 1f  call  0xa0fb7acc
a00cca54:  01 00 00 00  nop
a00cca58:  1b 33 c0 63  sethi  %hi(0xcf018c00), %o5
a00cca5c:  98 13 61 54  or  %o5, 0x154, %o4	! 0xcf018d54
a00cca60:  96 13 61 00  or  %o5, 0x100, %o3
a00cca64:  80 8a 20 01  btst  1, %o0
a00cca68:  02 80 00 08  be  0xa00cca88
a00cca6c:  9a 13 61 dc  or  %o5, 0x1dc, %o5
a00cca70:  c2 03 00 00  ld  [ %o4 ], %g1
a00cca74:  82 10 60 02  or  %g1, 2, %g1
a00cca78:  c2 23 00 00  st  %g1, [ %o4 ]
a00cca7c:  c2 03 40 00  ld  [ %o5 ], %g1
a00cca80:  82 10 60 01  or  %g1, 1, %g1
a00cca84:  c2 23 40 00  st  %g1, [ %o5 ]
a00cca88:  c2 02 c0 00  ld  [ %o3 ], %g1
a00cca8c:  82 10 60 02  or  %g1, 2, %g1
a00cca90:  c2 22 c0 00  st  %g1, [ %o3 ]
a00cca94:  30 80 00 0e  b,a   0xa00ccacc
a00cca98:  40 3b ac 0d  call  0xa0fb7acc
a00cca9c:  92 10 20 06  mov  6, %o1
a00ccaa0:  03 33 c0 63  sethi  %hi(0xcf018c00), %g1
a00ccaa4:  98 10 61 00  or  %g1, 0x100, %o4	! 0xcf018d00
a00ccaa8:  80 8a 20 01  btst  1, %o0
a00ccaac:  02 80 00 05  be  0xa00ccac0
a00ccab0:  9a 10 61 dc  or  %g1, 0x1dc, %o5
a00ccab4:  c2 03 40 00  ld  [ %o5 ], %g1
a00ccab8:  82 08 7f fe  and  %g1, -2, %g1
a00ccabc:  c2 23 40 00  st  %g1, [ %o5 ]
a00ccac0:  c2 03 00 00  ld  [ %o4 ], %g1
a00ccac4:  82 08 7f fd  and  %g1, -3, %g1
a00ccac8:  c2 23 00 00  st  %g1, [ %o4 ]
a00ccacc:  81 c7 e0 08  ret
a00ccad0:  81 e8 00 00  restore
