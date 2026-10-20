# leon2m FUN_a0132c54 0xa0132c54-0xa0132cd4 (128 bytes)
a0132c54:  9d e3 bf 98  save  %sp, -104, %sp
a0132c58:  b9 2e a0 10  sll  %i2, 0x10, %i4
a0132c5c:  b7 37 20 10  srl  %i4, 0x10, %i3
a0132c60:  82 06 e0 03  add  %i3, 3, %g1
a0132c64:  b5 30 60 02  srl  %g1, 2, %i2
a0132c68:  9e 0e a0 ff  and  %i2, 0xff, %o7
a0132c6c:  80 a3 e0 00  cmp  %o7, 0
a0132c70:  02 80 00 17  be  0xa0132ccc
a0132c74:  b4 10 20 00  clr  %i2
a0132c78:  ba 10 20 00  clr  %i5
a0132c7c:  b7 2f 60 02  sll  %i5, 2, %i3
a0132c80:  c2 0e 00 1b  ldub  [ %i0 + %i3 ], %g1
a0132c84:  c2 26 40 1b  st  %g1, [ %i1 + %i3 ]
a0132c88:  b8 06 c0 18  add  %i3, %i0, %i4
a0132c8c:  fa 0f 20 01  ldub  [ %i4 + 1 ], %i5
a0132c90:  83 28 60 08  sll  %g1, 8, %g1
a0132c94:  82 00 40 1d  add  %g1, %i5, %g1
a0132c98:  c2 26 40 1b  st  %g1, [ %i1 + %i3 ]
a0132c9c:  fa 0f 20 02  ldub  [ %i4 + 2 ], %i5
a0132ca0:  83 28 60 08  sll  %g1, 8, %g1
a0132ca4:  82 00 40 1d  add  %g1, %i5, %g1
a0132ca8:  c2 26 40 1b  st  %g1, [ %i1 + %i3 ]
a0132cac:  fa 0f 20 03  ldub  [ %i4 + 3 ], %i5
a0132cb0:  b9 28 60 08  sll  %g1, 8, %i4
a0132cb4:  82 07 00 1d  add  %i4, %i5, %g1
a0132cb8:  b4 06 a0 01  inc  %i2
a0132cbc:  ba 0e a0 ff  and  %i2, 0xff, %i5
a0132cc0:  80 a7 40 0f  cmp  %i5, %o7
a0132cc4:  0a bf ff ee  bcs  0xa0132c7c
a0132cc8:  c2 26 40 1b  st  %g1, [ %i1 + %i3 ]
a0132ccc:  81 c7 e0 08  ret
a0132cd0:  81 e8 00 00  restore
