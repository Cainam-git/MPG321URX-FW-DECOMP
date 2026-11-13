# leon2m FUN_a00fce40 0xa00fce40-0xa00fd074 (564 bytes)
a00fce40:  9d e3 bf 98  save  %sp, -104, %sp
a00fce44:  15 33 c0 48  sethi  %hi(0xcf012000), %o2
a00fce48:  13 2a 00 b2  sethi  %hi(0xa802c800), %o1
a00fce4c:  17 2a 00 b2  sethi  %hi(0xa802c800), %o3
a00fce50:  d0 0a 61 7d  ldub  [ %o1 + 0x17d ], %o0
a00fce54:  98 12 a0 84  or  %o2, 0x84, %o4
a00fce58:  82 10 20 8c  mov  0x8c, %g1
a00fce5c:  c2 23 00 00  st  %g1, [ %o4 ]
a00fce60:  9a 12 e1 78  or  %o3, 0x178, %o5
a00fce64:  c0 2b 60 01  clrb  [ %o5 + 1 ]
a00fce68:  c0 2a e1 78  clrb  [ %o3 + 0x178 ]
a00fce6c:  c0 2b 60 03  clrb  [ %o5 + 3 ]
a00fce70:  80 a2 20 0f  cmp  %o0, 0xf
a00fce74:  02 80 00 28  be  0xa00fcf14
a00fce78:  c0 2b 60 02  clrb  [ %o5 + 2 ]
a00fce7c:  25 2a 00 b2  sethi  %hi(0xa802c800), %l2
a00fce80:  d8 04 a1 70  ld  [ %l2 + 0x170 ], %o4	! 0xa802c970
a00fce84:  9e 12 a0 34  or  %o2, 0x34, %o7
a00fce88:  a0 10 20 2e  mov  0x2e, %l0
a00fce8c:  e0 23 c0 00  st  %l0, [ %o7 ]
a00fce90:  80 a3 20 00  cmp  %o4, 0
a00fce94:  12 80 00 1d  bne  0xa00fcf08
a00fce98:  9a 12 a0 80  or  %o2, 0x80, %o5
a00fce9c:  a2 12 a0 40  or  %o2, 0x40, %l1
a00fcea0:  d0 23 40 00  st  %o0, [ %o5 ]
a00fcea4:  94 10 20 01  mov  1, %o2
a00fcea8:  d4 24 40 00  st  %o2, [ %l1 ]
a00fceac:  67 fe 41 b7  call  0x4008d588
a00fceb0:  01 00 00 00  nop
a00fceb4:  19 33 c0 48  sethi  %hi(0xcf012000), %o4
a00fceb8:  82 13 20 34  or  %o4, 0x34, %g1	! 0xcf012034
a00fcebc:  d6 00 40 00  ld  [ %g1 ], %o3
a00fcec0:  80 8a e0 2e  btst  0x2e, %o3
a00fcec4:  12 80 00 65  bne  0xa00fd058
a00fcec8:  a1 2a 20 10  sll  %o0, 0x10, %l0
a00fcecc:  a2 10 00 01  mov  %g1, %l1
a00fced0:  67 fe 40 02  call  0x4008ced8
a00fced4:  01 00 00 00  nop
a00fced8:  67 fe 41 af  call  0x4008d594
a00fcedc:  91 34 20 10  srl  %l0, 0x10, %o0
a00fcee0:  93 2a 20 10  sll  %o0, 0x10, %o1
a00fcee4:  83 32 60 10  srl  %o1, 0x10, %g1
a00fcee8:  80 a0 63 e8  cmp  %g1, 0x3e8
a00fceec:  18 80 00 5c  bgu  0xa00fd05c
a00fcef0:  25 33 c0 48  sethi  %hi(0xcf012000), %l2
a00fcef4:  d0 04 40 00  ld  [ %l1 ], %o0
a00fcef8:  80 8a 20 2e  btst  0x2e, %o0
a00fcefc:  02 bf ff f5  be  0xa00fced0
a00fcf00:  9e 14 a0 34  or  %l2, 0x34, %o7
a00fcf04:  30 80 00 57  b,a   0xa00fd060
a00fcf08:  9f c3 00 00  call  %o4
a00fcf0c:  92 10 20 01  mov  1, %o1
a00fcf10:  30 bf ff e7  b,a   0xa00fceac
a00fcf14:  25 2a 00 b2  sethi  %hi(0xa802c800), %l2
a00fcf18:  90 12 a0 34  or  %o2, 0x34, %o0
a00fcf1c:  d8 04 a1 70  ld  [ %l2 + 0x170 ], %o4
a00fcf20:  9e 10 20 2e  mov  0x2e, %o7
a00fcf24:  de 22 00 00  st  %o7, [ %o0 ]
a00fcf28:  80 a3 20 00  cmp  %o4, 0
a00fcf2c:  12 80 00 43  bne  0xa00fd038
a00fcf30:  a2 12 a0 80  or  %o2, 0x80, %l1
a00fcf34:  a0 12 a0 40  or  %o2, 0x40, %l0
a00fcf38:  9a 10 20 08  mov  8, %o5
a00fcf3c:  da 24 40 00  st  %o5, [ %l1 ]
a00fcf40:  94 10 20 01  mov  1, %o2
a00fcf44:  d4 24 00 00  st  %o2, [ %l0 ]
a00fcf48:  67 fe 41 90  call  0x4008d588
a00fcf4c:  01 00 00 00  nop
a00fcf50:  19 33 c0 48  sethi  %hi(0xcf012000), %o4
a00fcf54:  82 13 20 34  or  %o4, 0x34, %g1	! 0xcf012034
a00fcf58:  d6 00 40 00  ld  [ %g1 ], %o3
a00fcf5c:  80 8a e0 2e  btst  0x2e, %o3
a00fcf60:  12 80 00 10  bne  0xa00fcfa0
a00fcf64:  a1 2a 20 10  sll  %o0, 0x10, %l0
a00fcf68:  a2 10 00 01  mov  %g1, %l1
a00fcf6c:  67 fe 3f db  call  0x4008ced8
a00fcf70:  01 00 00 00  nop
a00fcf74:  67 fe 41 88  call  0x4008d594
a00fcf78:  91 34 20 10  srl  %l0, 0x10, %o0
a00fcf7c:  93 2a 20 10  sll  %o0, 0x10, %o1
a00fcf80:  83 32 60 10  srl  %o1, 0x10, %g1
a00fcf84:  80 a0 63 e8  cmp  %g1, 0x3e8
a00fcf88:  18 80 00 07  bgu  0xa00fcfa4
a00fcf8c:  17 33 c0 48  sethi  %hi(0xcf012000), %o3
a00fcf90:  d0 04 40 00  ld  [ %l1 ], %o0
a00fcf94:  80 8a 20 2e  btst  0x2e, %o0
a00fcf98:  02 bf ff f5  be  0xa00fcf6c
a00fcf9c:  01 00 00 00  nop
a00fcfa0:  17 33 c0 48  sethi  %hi(0xcf012000), %o3
a00fcfa4:  9e 12 e0 34  or  %o3, 0x34, %o7	! 0xcf012034
a00fcfa8:  d8 03 c0 00  ld  [ %o7 ], %o4
a00fcfac:  a0 10 20 2e  mov  0x2e, %l0
a00fcfb0:  e0 23 c0 00  st  %l0, [ %o7 ]
a00fcfb4:  d8 04 a1 70  ld  [ %l2 + 0x170 ], %o4
a00fcfb8:  e0 23 c0 00  st  %l0, [ %o7 ]
a00fcfbc:  80 a3 20 00  cmp  %o4, 0
a00fcfc0:  12 80 00 22  bne  0xa00fd048
a00fcfc4:  a2 12 e0 80  or  %o3, 0x80, %l1
a00fcfc8:  9a 10 20 04  mov  4, %o5
a00fcfcc:  da 24 40 00  st  %o5, [ %l1 ]
a00fcfd0:  a4 12 e0 40  or  %o3, 0x40, %l2
a00fcfd4:  94 10 20 01  mov  1, %o2
a00fcfd8:  d4 24 80 00  st  %o2, [ %l2 ]
a00fcfdc:  67 fe 41 6b  call  0x4008d588
a00fcfe0:  01 00 00 00  nop
a00fcfe4:  19 33 c0 48  sethi  %hi(0xcf012000), %o4
a00fcfe8:  82 13 20 34  or  %o4, 0x34, %g1	! 0xcf012034
a00fcfec:  d6 00 40 00  ld  [ %g1 ], %o3
a00fcff0:  80 8a e0 2e  btst  0x2e, %o3
a00fcff4:  12 80 00 19  bne  0xa00fd058
a00fcff8:  a1 2a 20 10  sll  %o0, 0x10, %l0
a00fcffc:  a2 10 00 01  mov  %g1, %l1
a00fd000:  67 fe 3f b6  call  0x4008ced8
a00fd004:  01 00 00 00  nop
a00fd008:  67 fe 41 63  call  0x4008d594
a00fd00c:  91 34 20 10  srl  %l0, 0x10, %o0
a00fd010:  93 2a 20 10  sll  %o0, 0x10, %o1
a00fd014:  83 32 60 10  srl  %o1, 0x10, %g1
a00fd018:  80 a0 63 e8  cmp  %g1, 0x3e8
a00fd01c:  18 80 00 10  bgu  0xa00fd05c
a00fd020:  25 33 c0 48  sethi  %hi(0xcf012000), %l2
a00fd024:  d0 04 40 00  ld  [ %l1 ], %o0
a00fd028:  80 8a 20 2e  btst  0x2e, %o0
a00fd02c:  02 bf ff f5  be  0xa00fd000
a00fd030:  9e 14 a0 34  or  %l2, 0x34, %o7
a00fd034:  30 80 00 0b  b,a   0xa00fd060
a00fd038:  90 10 20 08  mov  8, %o0
a00fd03c:  9f c3 00 00  call  %o4
a00fd040:  92 10 20 01  mov  1, %o1
a00fd044:  30 bf ff c1  b,a   0xa00fcf48
a00fd048:  90 10 20 04  mov  4, %o0
a00fd04c:  9f c3 00 00  call  %o4
a00fd050:  92 10 20 01  mov  1, %o1
a00fd054:  30 bf ff e2  b,a   0xa00fcfdc
a00fd058:  25 33 c0 48  sethi  %hi(0xcf012000), %l2
a00fd05c:  9e 14 a0 34  or  %l2, 0x34, %o7	! 0xcf012034
a00fd060:  d8 03 c0 00  ld  [ %o7 ], %o4
a00fd064:  a0 10 20 2e  mov  0x2e, %l0
a00fd068:  e0 23 c0 00  st  %l0, [ %o7 ]
a00fd06c:  81 c7 e0 08  ret
a00fd070:  81 e8 00 00  restore
