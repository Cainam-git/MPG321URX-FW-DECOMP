# leon2m FUN_a011abcc 0xa011abcc-0xa011acac (224 bytes)
a011abcc:  9d e3 bf 98  save  %sp, -104, %sp
a011abd0:  b0 0e 20 ff  and  %i0, 0xff, %i0
a011abd4:  b9 2e 20 02  sll  %i0, 2, %i4
a011abd8:  b6 07 00 18  add  %i4, %i0, %i3
a011abdc:  bb 2e e0 04  sll  %i3, 4, %i5
a011abe0:  b4 06 c0 1d  add  %i3, %i5, %i2
a011abe4:  03 2a 00 9e  sethi  %hi(0xa8027800), %g1
a011abe8:  ba 0e 60 ff  and  %i1, 0xff, %i5
a011abec:  9a 10 62 a8  or  %g1, 0x2a8, %o5
a011abf0:  15 33 c0 00  sethi  %hi(0xcf000000), %o2
a011abf4:  9e 0e a0 ff  and  %i2, 0xff, %o7
a011abf8:  98 10 00 0d  mov  %o5, %o4
a011abfc:  96 10 00 0a  mov  %o2, %o3
a011ac00:  80 a6 20 00  cmp  %i0, 0
a011ac04:  b4 10 00 19  mov  %i1, %i2
a011ac08:  b8 07 40 1d  add  %i5, %i5, %i4
a011ac0c:  12 80 00 14  bne  0xa011ac5c
a011ac10:  b6 10 00 1d  mov  %i5, %i3
a011ac14:  f2 13 40 1c  lduh  [ %o5 + %i4 ], %i1
a011ac18:  82 06 60 90  add  %i1, 0x90, %g1
a011ac1c:  b9 28 60 02  sll  %g1, 2, %i4
a011ac20:  b2 17 00 0a  or  %i4, %o2, %i1
a011ac24:  fa 06 40 00  ld  [ %i1 ], %i5
a011ac28:  b0 0f 60 fc  and  %i5, 0xfc, %i0
a011ac2c:  f0 26 40 00  st  %i0, [ %i1 ]
a011ac30:  80 a6 e0 01  cmp  %i3, 1
a011ac34:  38 80 00 02  bgu,a   0xa011ac3c
a011ac38:  b4 10 20 00  clr  %i2
a011ac3c:  82 0e a0 ff  and  %i2, 0xff, %g1
a011ac40:  ba 00 40 01  add  %g1, %g1, %i5
a011ac44:  f8 13 00 1d  lduh  [ %o4 + %i5 ], %i4
a011ac48:  b0 07 20 95  add  %i4, 0x95, %i0
a011ac4c:  b7 2e 20 02  sll  %i0, 2, %i3
a011ac50:  b4 16 c0 0b  or  %i3, %o3, %i2
a011ac54:  c0 26 80 00  clr  [ %i2 ]
a011ac58:  30 80 00 13  b,a   0xa011aca4
a011ac5c:  80 a7 60 02  cmp  %i5, 2
a011ac60:  f4 13 40 1c  lduh  [ %o5 + %i4 ], %i2
a011ac64:  82 60 20 00  subx  %g0, 0, %g1
a011ac68:  ba 0e 40 01  and  %i1, %g1, %i5
a011ac6c:  b8 06 a0 90  add  %i2, 0x90, %i4
a011ac70:  b0 0f 60 ff  and  %i5, 0xff, %i0
a011ac74:  b7 2f 20 02  sll  %i4, 2, %i3
a011ac78:  b4 06 00 18  add  %i0, %i0, %i2
a011ac7c:  b6 16 c0 0a  or  %i3, %o2, %i3
a011ac80:  f2 13 40 1a  lduh  [ %o5 + %i2 ], %i1
a011ac84:  c2 06 c0 00  ld  [ %i3 ], %g1
a011ac88:  ba 06 60 95  add  %i1, 0x95, %i5
a011ac8c:  b8 10 60 03  or  %g1, 3, %i4
a011ac90:  b0 0f 20 ff  and  %i4, 0xff, %i0
a011ac94:  b5 2f 60 02  sll  %i5, 2, %i2
a011ac98:  f0 26 c0 00  st  %i0, [ %i3 ]
a011ac9c:  b2 16 80 0a  or  %i2, %o2, %i1
a011aca0:  de 26 40 00  st  %o7, [ %i1 ]
a011aca4:  81 c7 e0 08  ret
a011aca8:  81 e8 00 00  restore
