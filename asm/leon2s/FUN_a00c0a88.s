# leon2s FUN_a00c0a88 0xa00c0a88-0xa00c0b48 (192 bytes)
a00c0a88:  9d e3 bf 98  save  %sp, -104, %sp
a00c0a8c:  3b 33 c0 45  sethi  %hi(0xcf011400), %i5
a00c0a90:  ba 17 62 74  or  %i5, 0x274, %i5	! 0xcf011674
a00c0a94:  f8 07 40 00  ld  [ %i5 ], %i4
a00c0a98:  c2 07 40 00  ld  [ %i5 ], %g1
a00c0a9c:  82 10 60 18  or  %g1, 0x18, %g1
a00c0aa0:  c2 27 40 00  st  %g1, [ %i5 ]
a00c0aa4:  9e 10 00 18  mov  %i0, %o7
a00c0aa8:  9a 10 00 19  mov  %i1, %o5
a00c0aac:  03 00 00 18  sethi  %hi(0x6000), %g1
a00c0ab0:  b0 10 00 1c  mov  %i4, %i0
a00c0ab4:  b2 10 63 49  or  %g1, 0x349, %i1
a00c0ab8:  b6 10 20 00  clr  %i3
a00c0abc:  35 33 c0 00  sethi  %hi(0xcf000000), %i2
a00c0ac0:  b9 2e e0 10  sll  %i3, 0x10, %i4
a00c0ac4:  b9 37 20 10  srl  %i4, 0x10, %i4
a00c0ac8:  82 07 00 19  add  %i4, %i1, %g1
a00c0acc:  b6 06 e0 01  inc  %i3
a00c0ad0:  83 28 60 02  sll  %g1, 2, %g1
a00c0ad4:  bb 2e e0 10  sll  %i3, 0x10, %i5
a00c0ad8:  82 10 40 1a  or  %g1, %i2, %g1
a00c0adc:  f8 0b c0 1c  ldub  [ %o7 + %i4 ], %i4
a00c0ae0:  bb 37 60 10  srl  %i5, 0x10, %i5
a00c0ae4:  f8 20 40 00  st  %i4, [ %g1 ]
a00c0ae8:  80 a7 60 04  cmp  %i5, 4
a00c0aec:  08 bf ff f6  bleu  0xa00c0ac4
a00c0af0:  b9 2e e0 10  sll  %i3, 0x10, %i4
a00c0af4:  35 33 c0 de  sethi  %hi(0xcf037800), %i2
a00c0af8:  b6 10 20 00  clr  %i3
a00c0afc:  83 2e e0 10  sll  %i3, 0x10, %g1
a00c0b00:  83 30 60 10  srl  %g1, 0x10, %g1
a00c0b04:  b8 06 e0 01  add  %i3, 1, %i4
a00c0b08:  fa 0b 40 01  ldub  [ %o5 + %g1 ], %i5
a00c0b0c:  83 2f 20 10  sll  %i4, 0x10, %g1
a00c0b10:  fa 26 80 00  st  %i5, [ %i2 ]
a00c0b14:  83 30 60 10  srl  %g1, 0x10, %g1
a00c0b18:  80 a0 61 19  cmp  %g1, 0x119
a00c0b1c:  b4 06 a0 04  add  %i2, 4, %i2
a00c0b20:  08 bf ff f7  bleu  0xa00c0afc
a00c0b24:  b6 10 00 1c  mov  %i4, %i3
a00c0b28:  03 33 c0 45  sethi  %hi(0xcf011400), %g1
a00c0b2c:  ba 10 63 80  or  %g1, 0x380, %i5	! 0xcf011780
a00c0b30:  c0 27 40 00  clr  [ %i5 ]
a00c0b34:  82 10 62 74  or  %g1, 0x274, %g1
a00c0b38:  ba 0e 20 ff  and  %i0, 0xff, %i5
a00c0b3c:  fa 20 40 00  st  %i5, [ %g1 ]
a00c0b40:  81 c7 e0 08  ret
a00c0b44:  81 e8 00 00  restore
