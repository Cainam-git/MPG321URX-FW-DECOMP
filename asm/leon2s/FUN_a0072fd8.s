# leon2s FUN_a0072fd8 0xa0072fd8-0xa0073044 (108 bytes)
a0072fd8:  9d e3 bf 98  save  %sp, -104, %sp
a0072fdc:  80 a6 20 00  cmp  %i0, 0
a0072fe0:  02 80 00 17  be  0xa007303c
a0072fe4:  80 a6 60 01  cmp  %i1, 1
a0072fe8:  12 80 00 06  bne  0xa0073000
a0072fec:  a0 10 20 00  clr  %l0
a0072ff0:  c2 4e 00 00  ldsb  [ %i0 ], %g1
a0072ff4:  80 a0 60 00  cmp  %g1, 0
a0072ff8:  02 80 00 11  be  0xa007303c
a0072ffc:  01 00 00 00  nop
a0073000:  80 a4 00 19  cmp  %l0, %i1
a0073004:  16 80 00 0e  bge  0xa007303c
a0073008:  01 00 00 00  nop
a007300c:  7f ff b8 88  call  0xa006122c
a0073010:  d0 0e 00 10  ldub  [ %i0 + %l0 ], %o0
a0073014:  c2 4e 00 10  ldsb  [ %i0 + %l0 ], %g1
a0073018:  a0 04 20 01  inc  %l0
a007301c:  80 a0 60 0a  cmp  %g1, 0xa
a0073020:  12 80 00 04  bne  0xa0073030
a0073024:  90 10 20 0d  mov  0xd, %o0
a0073028:  7f ff b8 81  call  0xa006122c
a007302c:  01 00 00 00  nop
a0073030:  80 a4 00 19  cmp  %l0, %i1
a0073034:  06 bf ff f6  bl  0xa007300c
a0073038:  01 00 00 00  nop
a007303c:  81 c7 e0 08  ret
a0073040:  81 e8 00 00  restore
