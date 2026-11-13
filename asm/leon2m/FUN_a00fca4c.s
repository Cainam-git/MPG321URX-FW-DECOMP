# leon2m FUN_a00fca4c 0xa00fca4c-0xa00fcb1c (208 bytes)
a00fca4c:  9d e3 bf 98  save  %sp, -104, %sp
a00fca50:  17 33 c0 48  sethi  %hi(0xcf012000), %o3
a00fca54:  90 12 e0 84  or  %o3, 0x84, %o0	! 0xcf012084
a00fca58:  92 10 20 36  mov  0x36, %o1
a00fca5c:  1b 2a 00 b2  sethi  %hi(0xa802c800), %o5
a00fca60:  d2 22 00 00  st  %o1, [ %o0 ]
a00fca64:  da 03 61 70  ld  [ %o5 + 0x170 ], %o5
a00fca68:  98 12 e0 34  or  %o3, 0x34, %o4
a00fca6c:  82 10 20 2e  mov  0x2e, %g1
a00fca70:  c2 23 00 00  st  %g1, [ %o4 ]
a00fca74:  80 a3 60 00  cmp  %o5, 0
a00fca78:  12 80 00 1e  bne  0xa00fcaf0
a00fca7c:  9e 12 e0 80  or  %o3, 0x80, %o7
a00fca80:  94 12 e0 40  or  %o3, 0x40, %o2
a00fca84:  a0 10 20 0f  mov  0xf, %l0
a00fca88:  e0 23 c0 00  st  %l0, [ %o7 ]
a00fca8c:  96 10 20 01  mov  1, %o3
a00fca90:  d6 22 80 00  st  %o3, [ %o2 ]
a00fca94:  67 fe 42 bd  call  0x4008d588
a00fca98:  01 00 00 00  nop
a00fca9c:  19 33 c0 48  sethi  %hi(0xcf012000), %o4
a00fcaa0:  82 13 20 34  or  %o4, 0x34, %g1	! 0xcf012034
a00fcaa4:  e2 00 40 00  ld  [ %g1 ], %l1
a00fcaa8:  80 8c 60 2e  btst  0x2e, %l1
a00fcaac:  12 80 00 15  bne  0xa00fcb00
a00fcab0:  a1 2a 20 10  sll  %o0, 0x10, %l0
a00fcab4:  a2 10 00 01  mov  %g1, %l1
a00fcab8:  67 fe 41 08  call  0x4008ced8
a00fcabc:  01 00 00 00  nop
a00fcac0:  67 fe 42 b5  call  0x4008d594
a00fcac4:  91 34 20 10  srl  %l0, 0x10, %o0
a00fcac8:  9b 2a 20 10  sll  %o0, 0x10, %o5
a00fcacc:  83 33 60 10  srl  %o5, 0x10, %g1
a00fcad0:  80 a0 63 e8  cmp  %g1, 0x3e8
a00fcad4:  18 80 00 0c  bgu  0xa00fcb04
a00fcad8:  17 33 c0 48  sethi  %hi(0xcf012000), %o3
a00fcadc:  d0 04 40 00  ld  [ %l1 ], %o0
a00fcae0:  80 8a 20 2e  btst  0x2e, %o0
a00fcae4:  02 bf ff f5  be  0xa00fcab8
a00fcae8:  92 12 e0 34  or  %o3, 0x34, %o1
a00fcaec:  30 80 00 07  b,a   0xa00fcb08
a00fcaf0:  90 10 20 0f  mov  0xf, %o0
a00fcaf4:  9f c3 40 00  call  %o5
a00fcaf8:  92 10 20 01  mov  1, %o1
a00fcafc:  30 bf ff e6  b,a   0xa00fca94
a00fcb00:  17 33 c0 48  sethi  %hi(0xcf012000), %o3
a00fcb04:  92 12 e0 34  or  %o3, 0x34, %o1	! 0xcf012034
a00fcb08:  d8 02 40 00  ld  [ %o1 ], %o4
a00fcb0c:  94 10 20 2e  mov  0x2e, %o2
a00fcb10:  d4 22 40 00  st  %o2, [ %o1 ]
a00fcb14:  81 c7 e0 08  ret
a00fcb18:  81 e8 00 00  restore
