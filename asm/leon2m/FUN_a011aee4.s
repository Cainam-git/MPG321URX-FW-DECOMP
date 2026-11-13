# leon2m FUN_a011aee4 0xa011aee4-0xa011b034 (336 bytes)
a011aee4:  9d e3 bf 98  save  %sp, -104, %sp
a011aee8:  03 2a 00 9e  sethi  %hi(0xa8027800), %g1
a011aeec:  9e 0e e0 0f  and  %i3, 0xf, %o7
a011aef0:  b6 16 80 1b  or  %i2, %i3, %i3
a011aef4:  98 10 62 a8  or  %g1, 0x2a8, %o4
a011aef8:  9a 10 00 1d  mov  %i5, %o5
a011aefc:  82 0e 20 07  and  %i0, 7, %g1
a011af00:  80 8e e0 ff  btst  0xff, %i3
a011af04:  b7 28 60 04  sll  %g1, 4, %i3
a011af08:  ba 0e 60 0f  and  %i1, 0xf, %i5
a011af0c:  b0 16 c0 1d  or  %i3, %i5, %i0
a011af10:  b8 0f 20 03  and  %i4, 3, %i4
a011af14:  94 16 20 80  or  %i0, 0x80, %o2
a011af18:  82 0e a0 0f  and  %i2, 0xf, %g1
a011af1c:  17 33 c0 00  sethi  %hi(0xcf000000), %o3
a011af20:  b1 2f 20 06  sll  %i4, 6, %i0
a011af24:  ba 0b 60 ff  and  %o5, 0xff, %i5
a011af28:  b5 28 60 04  sll  %g1, 4, %i2
a011af2c:  90 10 00 0c  mov  %o4, %o0
a011af30:  92 10 00 0b  mov  %o3, %o1
a011af34:  b6 10 00 0d  mov  %o5, %i3
a011af38:  b8 10 00 1d  mov  %i5, %i4
a011af3c:  12 80 00 17  bne  0xa011af98
a011af40:  9e 16 80 0f  or  %i2, %o7, %o7
a011af44:  80 a7 60 02  cmp  %i5, 2
a011af48:  b0 60 20 00  subx  %g0, 0, %i0
a011af4c:  b2 0b 40 18  and  %o5, %i0, %i1
a011af50:  b4 0e 60 ff  and  %i1, 0xff, %i2
a011af54:  82 06 80 1a  add  %i2, %i2, %g1
a011af58:  fa 13 00 01  lduh  [ %o4 + %g1 ], %i5
a011af5c:  b0 07 60 8e  add  %i5, 0x8e, %i0
a011af60:  b3 2e 20 02  sll  %i0, 2, %i1
a011af64:  b4 16 40 0b  or  %i1, %o3, %i2
a011af68:  c0 26 80 00  clr  [ %i2 ]
a011af6c:  80 a7 20 01  cmp  %i4, 1
a011af70:  38 80 00 02  bgu,a   0xa011af78
a011af74:  b6 10 20 00  clr  %i3
a011af78:  b2 0e e0 ff  and  %i3, 0xff, %i1
a011af7c:  b4 06 40 19  add  %i1, %i1, %i2
a011af80:  c2 12 00 1a  lduh  [ %o0 + %i2 ], %g1
a011af84:  ba 00 60 8f  add  %g1, 0x8f, %i5
a011af88:  b7 2f 60 02  sll  %i5, 2, %i3
a011af8c:  b8 16 c0 09  or  %i3, %o1, %i4
a011af90:  c0 27 00 00  clr  [ %i4 ]
a011af94:  30 80 00 26  b,a   0xa011b02c
a011af98:  80 a7 60 02  cmp  %i5, 2
a011af9c:  b8 60 20 00  subx  %g0, 0, %i4
a011afa0:  b2 0b 40 1c  and  %o5, %i4, %i1
a011afa4:  ba 0e 60 ff  and  %i1, 0xff, %i5
a011afa8:  82 07 40 1d  add  %i5, %i5, %g1
a011afac:  f6 13 00 01  lduh  [ %o4 + %g1 ], %i3
a011afb0:  b4 10 00 1c  mov  %i4, %i2
a011afb4:  b8 0b 40 1c  and  %o5, %i4, %i4
a011afb8:  ba 06 e0 cf  add  %i3, 0xcf, %i5
a011afbc:  82 0f 20 ff  and  %i4, 0xff, %g1
a011afc0:  b7 2f 60 02  sll  %i5, 2, %i3
a011afc4:  b4 0b 40 1a  and  %o5, %i2, %i2
a011afc8:  b8 00 40 01  add  %g1, %g1, %i4
a011afcc:  ba 16 c0 0b  or  %i3, %o3, %i5
a011afd0:  b2 10 00 1a  mov  %i2, %i1
a011afd4:  82 0e a0 ff  and  %i2, 0xff, %g1
a011afd8:  f6 13 00 1c  lduh  [ %o4 + %i4 ], %i3
a011afdc:  b4 00 40 01  add  %g1, %g1, %i2
a011afe0:  b8 0e 60 ff  and  %i1, 0xff, %i4
a011afe4:  f2 07 40 00  ld  [ %i5 ], %i1
a011afe8:  82 07 00 1c  add  %i4, %i4, %g1
a011afec:  fa 13 00 1a  lduh  [ %o4 + %i2 ], %i5
a011aff0:  f8 13 00 01  lduh  [ %o4 + %g1 ], %i4
a011aff4:  b4 0e 60 ff  and  %i1, 0xff, %i2
a011aff8:  82 07 60 8e  add  %i5, 0x8e, %g1
a011affc:  b6 06 e0 cf  add  %i3, 0xcf, %i3
a011b000:  b2 16 80 18  or  %i2, %i0, %i1
a011b004:  b7 2e e0 02  sll  %i3, 2, %i3
a011b008:  bb 28 60 02  sll  %g1, 2, %i5
a011b00c:  b4 16 c0 0b  or  %i3, %o3, %i2
a011b010:  82 07 20 8f  add  %i4, 0x8f, %g1
a011b014:  f2 26 80 00  st  %i1, [ %i2 ]
a011b018:  b6 17 40 0b  or  %i5, %o3, %i3
a011b01c:  b9 28 60 02  sll  %g1, 2, %i4
a011b020:  de 26 c0 00  st  %o7, [ %i3 ]
a011b024:  b0 17 00 0b  or  %i4, %o3, %i0
a011b028:  d4 26 00 00  st  %o2, [ %i0 ]
a011b02c:  81 c7 e0 08  ret
a011b030:  81 e8 00 00  restore
