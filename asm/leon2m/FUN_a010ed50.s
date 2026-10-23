# leon2m FUN_a010ed50 0xa010ed50-0xa010edbc (108 bytes)
a010ed50:  90 0a 20 ff  and  %o0, 0xff, %o0
a010ed54:  03 2a 00 b5  sethi  %hi(0xa802d400), %g1
a010ed58:  93 2a 20 02  sll  %o0, 2, %o1
a010ed5c:  80 a2 20 01  cmp  %o0, 1
a010ed60:  02 80 00 08  be  0xa010ed80
a010ed64:  94 10 63 c4  or  %g1, 0x3c4, %o2
a010ed68:  17 2a 00 b5  sethi  %hi(0xa802d400), %o3
a010ed6c:  80 a2 20 02  cmp  %o0, 2
a010ed70:  12 80 00 04  bne  0xa010ed80
a010ed74:  94 12 e3 44  or  %o3, 0x344, %o2
a010ed78:  11 2a 00 b5  sethi  %hi(0xa802d400), %o0
a010ed7c:  94 12 23 84  or  %o0, 0x384, %o2	! 0xa802d784
a010ed80:  d0 0a a0 3e  ldub  [ %o2 + 0x3e ], %o0
a010ed84:  96 0a 3f fd  and  %o0, -3, %o3
a010ed88:  03 00 06 6b  sethi  %hi(0x19ac00), %g1
a010ed8c:  d6 2a a0 3e  stb  %o3, [ %o2 + 0x3e ]
a010ed90:  9a 10 62 d8  or  %g1, 0x2d8, %o5
a010ed94:  d8 02 a0 04  ld  [ %o2 + 4 ], %o4
a010ed98:  d0 03 40 09  ld  [ %o5 + %o1 ], %o0
a010ed9c:  17 00 06 6b  sethi  %hi(0x19ac00), %o3
a010eda0:  d8 22 20 24  st  %o4, [ %o0 + 0x24 ]
a010eda4:  82 12 e2 cc  or  %o3, 0x2cc, %g1
a010eda8:  d8 00 40 09  ld  [ %g1 + %o1 ], %o4
a010edac:  da 02 a0 08  ld  [ %o2 + 8 ], %o5
a010edb0:  da 23 20 24  st  %o5, [ %o4 + 0x24 ]
a010edb4:  81 c3 e0 08  retl
a010edb8:  01 00 00 00  nop
