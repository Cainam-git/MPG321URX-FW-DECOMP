# leon2m FUN_a011adc8 0xa011adc8-0xa011aee4 (284 bytes)
a011adc8:  9d e3 bf 98  save  %sp, -104, %sp
a011adcc:  35 2a 00 9e  sethi  %hi(0xa8027800), %i2
a011add0:  b0 0e 20 ff  and  %i0, 0xff, %i0
a011add4:  9e 16 a2 a8  or  %i2, 0x2a8, %o7
a011add8:  19 33 c0 00  sethi  %hi(0xcf000000), %o4
a011addc:  80 a6 20 ff  cmp  %i0, 0xff
a011ade0:  02 80 00 3f  be  0xa011aedc
a011ade4:  b6 0e 60 ff  and  %i1, 0xff, %i3
a011ade8:  92 06 c0 1b  add  %i3, %i3, %o1
a011adec:  94 10 00 09  mov  %o1, %o2
a011adf0:  80 a6 20 08  cmp  %i0, 8
a011adf4:  18 80 00 26  bgu  0xa011ae8c
a011adf8:  96 10 00 19  mov  %i1, %o3
a011adfc:  80 a6 e0 02  cmp  %i3, 2
a011ae00:  ba 60 20 00  subx  %g0, 0, %i5
a011ae04:  82 0e 40 1d  and  %i1, %i5, %g1
a011ae08:  b4 08 60 ff  and  %g1, 0xff, %i2
a011ae0c:  ba 06 80 1a  add  %i2, %i2, %i5
a011ae10:  c2 13 c0 1d  lduh  [ %o7 + %i5 ], %g1
a011ae14:  82 00 60 a1  add  %g1, 0xa1, %g1
a011ae18:  bb 28 60 02  sll  %g1, 2, %i5
a011ae1c:  82 17 40 0c  or  %i5, %o4, %g1
a011ae20:  b8 06 3f ff  add  %i0, -1, %i4
a011ae24:  fa 00 40 00  ld  [ %g1 ], %i5
a011ae28:  b5 2f 20 03  sll  %i4, 3, %i2
a011ae2c:  ba 0f 60 c7  and  %i5, 0xc7, %i5
a011ae30:  b8 17 40 1a  or  %i5, %i2, %i4
a011ae34:  9a 0f 20 ff  and  %i4, 0xff, %o5
a011ae38:  80 a6 20 00  cmp  %i0, 0
a011ae3c:  12 80 00 16  bne  0xa011ae94
a011ae40:  b4 0f 60 ff  and  %i5, 0xff, %i2
a011ae44:  80 a6 e0 01  cmp  %i3, 1
a011ae48:  38 80 00 02  bgu,a   0xa011ae50
a011ae4c:  96 10 20 00  clr  %o3
a011ae50:  b8 0a e0 ff  and  %o3, 0xff, %i4
a011ae54:  b6 07 00 1c  add  %i4, %i4, %i3
a011ae58:  f2 13 c0 1b  lduh  [ %o7 + %i3 ], %i1
a011ae5c:  f0 13 c0 09  lduh  [ %o7 + %o1 ], %i0
a011ae60:  ba 06 60 a1  add  %i1, 0xa1, %i5
a011ae64:  b8 06 20 cf  add  %i0, 0xcf, %i4
a011ae68:  83 2f 60 02  sll  %i5, 2, %g1
a011ae6c:  b6 10 40 0c  or  %g1, %o4, %i3
a011ae70:  b3 2f 20 02  sll  %i4, 2, %i1
a011ae74:  f4 26 c0 00  st  %i2, [ %i3 ]
a011ae78:  b8 16 40 0c  or  %i1, %o4, %i4
a011ae7c:  f0 07 00 00  ld  [ %i4 ], %i0
a011ae80:  82 0e 20 df  and  %i0, 0xdf, %g1
a011ae84:  c2 27 00 00  st  %g1, [ %i4 ]
a011ae88:  30 80 00 15  b,a   0xa011aedc
a011ae8c:  10 bf ff dc  b  0xa011adfc
a011ae90:  b0 10 20 08  mov  8, %i0
a011ae94:  80 a6 e0 02  cmp  %i3, 2
a011ae98:  b8 60 20 00  subx  %g0, 0, %i4
a011ae9c:  b6 0e 40 1c  and  %i1, %i4, %i3
a011aea0:  ba 0e e0 ff  and  %i3, 0xff, %i5
a011aea4:  82 07 40 1d  add  %i5, %i5, %g1
a011aea8:  f0 13 c0 01  lduh  [ %o7 + %g1 ], %i0
a011aeac:  b4 06 20 a1  add  %i0, 0xa1, %i2
a011aeb0:  f8 13 c0 0a  lduh  [ %o7 + %o2 ], %i4
a011aeb4:  b7 2e a0 02  sll  %i2, 2, %i3
a011aeb8:  b2 07 20 cf  add  %i4, 0xcf, %i1
a011aebc:  ba 16 c0 0c  or  %i3, %o4, %i5
a011aec0:  b1 2e 60 02  sll  %i1, 2, %i0
a011aec4:  da 27 40 00  st  %o5, [ %i5 ]
a011aec8:  b8 16 00 0c  or  %i0, %o4, %i4
a011aecc:  c2 07 00 00  ld  [ %i4 ], %g1
a011aed0:  b4 10 60 20  or  %g1, 0x20, %i2
a011aed4:  82 0e a0 ff  and  %i2, 0xff, %g1
a011aed8:  c2 27 00 00  st  %g1, [ %i4 ]
a011aedc:  81 c7 e0 08  ret
a011aee0:  81 e8 00 00  restore
