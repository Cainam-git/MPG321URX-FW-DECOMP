# leon2m FUN_a015df90 0xa015df90-0xa015e008 (120 bytes)
a015df90:  9d e3 bf 98  save  %sp, -104, %sp
a015df94:  b6 10 00 1a  mov  %i2, %i3
a015df98:  c2 16 20 0c  lduh  [ %i0 + 0xc ], %g1
a015df9c:  b4 10 00 19  mov  %i1, %i2
a015dfa0:  a0 10 00 18  mov  %i0, %l0
a015dfa4:  94 10 20 00  clr  %o2
a015dfa8:  96 10 20 02  mov  2, %o3
a015dfac:  80 88 61 00  btst  0x100, %g1
a015dfb0:  9a 10 00 01  mov  %g1, %o5
a015dfb4:  12 80 00 09  bne  0xa015dfd8
a015dfb8:  33 2a 00 aa  sethi  %hi(0xa802a800), %i1
a015dfbc:  03 00 00 04  sethi  %hi(0x1000), %g1
a015dfc0:  82 2b 40 01  andn  %o5, %g1, %g1
a015dfc4:  f0 06 62 18  ld  [ %i1 + 0x218 ], %i0
a015dfc8:  c2 34 20 0c  sth  %g1, [ %l0 + 0xc ]
a015dfcc:  f2 54 20 0e  ldsh  [ %l0 + 0xe ], %i1
a015dfd0:  40 00 00 59  call  0xa015e134
a015dfd4:  81 e8 00 00  restore
a015dfd8:  d2 56 20 0e  ldsh  [ %i0 + 0xe ], %o1
a015dfdc:  40 00 01 1a  call  0xa015e444
a015dfe0:  d0 06 62 18  ld  [ %i1 + 0x218 ], %o0
a015dfe4:  da 16 20 0c  lduh  [ %i0 + 0xc ], %o5
a015dfe8:  03 00 00 04  sethi  %hi(0x1000), %g1
a015dfec:  82 2b 40 01  andn  %o5, %g1, %g1
a015dff0:  f0 06 62 18  ld  [ %i1 + 0x218 ], %i0
a015dff4:  c2 34 20 0c  sth  %g1, [ %l0 + 0xc ]
a015dff8:  f2 54 20 0e  ldsh  [ %l0 + 0xe ], %i1
a015dffc:  40 00 00 4e  call  0xa015e134
a015e000:  81 e8 00 00  restore
a015e004:  01 00 00 00  nop
