# leon2m FUN_a0133ae4 0xa0133ae4-0xa0133b54 (112 bytes)
a0133ae4:  9d e3 bf 98  save  %sp, -104, %sp
a0133ae8:  1f 2a 00 b6  sethi  %hi(0xa802d800), %o7
a0133aec:  f6 0b e1 c6  ldub  [ %o7 + 0x1c6 ], %i3	! 0xa802d9c6
a0133af0:  f6 2e 00 00  stb  %i3, [ %i0 ]
a0133af4:  b8 13 e1 c6  or  %o7, 0x1c6, %i4
a0133af8:  c2 17 20 02  lduh  [ %i4 + 2 ], %g1
a0133afc:  c2 36 40 00  sth  %g1, [ %i1 ]
a0133b00:  fa 17 20 02  lduh  [ %i4 + 2 ], %i5
a0133b04:  80 a7 60 00  cmp  %i5, 0
a0133b08:  08 80 00 0f  bleu  0xa0133b44
a0133b0c:  b6 10 20 00  clr  %i3
a0133b10:  b2 10 00 1c  mov  %i4, %i1
a0133b14:  bb 2e e0 10  sll  %i3, 0x10, %i5
a0133b18:  b1 37 60 10  srl  %i5, 0x10, %i0
a0133b1c:  82 06 00 19  add  %i0, %i1, %g1
a0133b20:  f8 08 60 04  ldub  [ %g1 + 4 ], %i4
a0133b24:  b6 06 e0 01  inc  %i3
a0133b28:  f8 2e 00 1a  stb  %i4, [ %i0 + %i2 ]
a0133b2c:  bb 2e e0 10  sll  %i3, 0x10, %i5
a0133b30:  b1 37 60 10  srl  %i5, 0x10, %i0
a0133b34:  f8 16 60 02  lduh  [ %i1 + 2 ], %i4
a0133b38:  80 a7 00 18  cmp  %i4, %i0
a0133b3c:  18 bf ff f9  bgu  0xa0133b20
a0133b40:  82 06 00 19  add  %i0, %i1, %g1
a0133b44:  b2 13 e1 c6  or  %o7, 0x1c6, %i1
a0133b48:  c0 2e 60 84  clrb  [ %i1 + 0x84 ]
a0133b4c:  81 c7 e0 08  ret
a0133b50:  81 e8 00 00  restore
