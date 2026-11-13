# leon2m FUN_a015bf7c 0xa015bf7c-0xa015c058 (220 bytes)
a015bf7c:  9d e3 bf 98  save  %sp, -104, %sp
a015bf80:  7f ff fd 9d  call  0xa015b5f4
a015bf84:  a4 10 20 00  clr  %l2
a015bf88:  b0 86 22 e0  addcc  %i0, 0x2e0, %i0
a015bf8c:  02 80 00 2e  be  0xa015c044
a015bf90:  01 00 00 00  nop
a015bf94:  e2 06 20 04  ld  [ %i0 + 4 ], %l1
a015bf98:  a2 84 7f ff  addcc  %l1, -1, %l1
a015bf9c:  0c 80 00 1d  bneg  0xa015c010
a015bfa0:  e0 06 20 08  ld  [ %i0 + 8 ], %l0
a015bfa4:  da 14 20 0c  lduh  [ %l0 + 0xc ], %o5
a015bfa8:  83 2b 60 10  sll  %o5, 0x10, %g1
a015bfac:  80 a0 60 00  cmp  %g1, 0
a015bfb0:  02 80 00 14  be  0xa015c000
a015bfb4:  99 30 60 10  srl  %g1, 0x10, %o4
a015bfb8:  80 8b 22 00  btst  0x200, %o4
a015bfbc:  02 80 00 1e  be  0xa015c034
a015bfc0:  90 04 20 58  add  %l0, 0x58, %o0
a015bfc4:  83 2b 60 10  sll  %o5, 0x10, %g1
a015bfc8:  80 a0 60 00  cmp  %g1, 0
a015bfcc:  02 80 00 0b  be  0xa015bff8
a015bfd0:  80 8b 62 00  btst  0x200, %o5
a015bfd4:  c2 54 20 0e  ldsh  [ %l0 + 0xe ], %g1
a015bfd8:  80 a0 7f ff  cmp  %g1, -1
a015bfdc:  02 80 00 06  be  0xa015bff4
a015bfe0:  90 10 00 10  mov  %l0, %o0
a015bfe4:  9f c6 40 00  call  %i1
a015bfe8:  01 00 00 00  nop
a015bfec:  a4 14 80 08  or  %l2, %o0, %l2
a015bff0:  da 14 20 0c  lduh  [ %l0 + 0xc ], %o5
a015bff4:  80 8b 62 00  btst  0x200, %o5
a015bff8:  02 80 00 0b  be  0xa015c024
a015bffc:  90 04 20 58  add  %l0, 0x58, %o0
a015c000:  a0 04 20 cc  add  %l0, 0xcc, %l0
a015c004:  a2 84 7f ff  addcc  %l1, -1, %l1
a015c008:  3c bf ff e8  bpos,a   0xa015bfa8
a015c00c:  da 14 20 0c  lduh  [ %l0 + 0xc ], %o5
a015c010:  f0 06 00 00  ld  [ %i0 ], %i0
a015c014:  80 a6 20 00  cmp  %i0, 0
a015c018:  32 bf ff e0  bne,a   0xa015bf98
a015c01c:  e2 06 20 04  ld  [ %i0 + 4 ], %l1
a015c020:  30 80 00 09  b,a   0xa015c044
a015c024:  40 00 0a 91  call  0xa015ea68
a015c028:  a0 04 20 cc  add  %l0, 0xcc, %l0
a015c02c:  10 bf ff f7  b  0xa015c008
a015c030:  a2 84 7f ff  addcc  %l1, -1, %l1
a015c034:  40 00 0a 75  call  0xa015ea08
a015c038:  01 00 00 00  nop
a015c03c:  10 bf ff e2  b  0xa015bfc4
a015c040:  da 14 20 0c  lduh  [ %l0 + 0xc ], %o5
a015c044:  7f ff fd 72  call  0xa015b60c
a015c048:  b0 10 00 12  mov  %l2, %i0
a015c04c:  01 00 00 00  nop
a015c050:  81 c7 e0 08  ret
a015c054:  81 e8 00 00  restore
