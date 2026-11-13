# leon2m FUN_a011acac 0xa011acac-0xa011adc8 (284 bytes)
a011acac:  9d e3 bf 98  save  %sp, -104, %sp
a011acb0:  35 2a 00 9e  sethi  %hi(0xa8027800), %i2
a011acb4:  9e 16 a2 a8  or  %i2, 0x2a8, %o7	! 0xa8027aa8
a011acb8:  b6 0e 20 ff  and  %i0, 0xff, %i3
a011acbc:  1b 33 c0 00  sethi  %hi(0xcf000000), %o5
a011acc0:  80 a6 e0 ff  cmp  %i3, 0xff
a011acc4:  02 80 00 3f  be  0xa011adc0
a011acc8:  b4 0e 60 ff  and  %i1, 0xff, %i2
a011accc:  94 06 80 1a  add  %i2, %i2, %o2
a011acd0:  96 10 00 0a  mov  %o2, %o3
a011acd4:  80 a6 e0 08  cmp  %i3, 8
a011acd8:  18 80 00 25  bgu  0xa011ad6c
a011acdc:  98 10 00 19  mov  %i1, %o4
a011ace0:  80 a6 a0 02  cmp  %i2, 2
a011ace4:  ba 60 20 00  subx  %g0, 0, %i5
a011ace8:  82 0e 40 1d  and  %i1, %i5, %g1
a011acec:  b8 08 60 ff  and  %g1, 0xff, %i4
a011acf0:  ba 07 00 1c  add  %i4, %i4, %i5
a011acf4:  c2 13 c0 1d  lduh  [ %o7 + %i5 ], %g1
a011acf8:  b8 06 3f ff  add  %i0, -1, %i4
a011acfc:  b0 00 60 a1  add  %g1, 0xa1, %i0
a011ad00:  bb 2e 20 02  sll  %i0, 2, %i5
a011ad04:  82 17 40 0d  or  %i5, %o5, %g1
a011ad08:  f0 00 40 00  ld  [ %g1 ], %i0
a011ad0c:  ba 0e 20 f8  and  %i0, 0xf8, %i5
a011ad10:  b8 17 40 1c  or  %i5, %i4, %i4
a011ad14:  80 a6 e0 00  cmp  %i3, 0
a011ad18:  b0 0f 20 ff  and  %i4, 0xff, %i0
a011ad1c:  12 80 00 17  bne  0xa011ad78
a011ad20:  b6 0f 60 ff  and  %i5, 0xff, %i3
a011ad24:  80 a6 a0 01  cmp  %i2, 1
a011ad28:  38 80 00 02  bgu,a   0xa011ad30
a011ad2c:  98 10 20 00  clr  %o4
a011ad30:  b8 0b 20 ff  and  %o4, 0xff, %i4
a011ad34:  b0 07 00 1c  add  %i4, %i4, %i0
a011ad38:  f4 13 c0 18  lduh  [ %o7 + %i0 ], %i2
a011ad3c:  f2 13 c0 0a  lduh  [ %o7 + %o2 ], %i1
a011ad40:  ba 06 a0 a1  add  %i2, 0xa1, %i5
a011ad44:  b8 06 60 cf  add  %i1, 0xcf, %i4
a011ad48:  83 2f 60 02  sll  %i5, 2, %g1
a011ad4c:  b0 10 40 0d  or  %g1, %o5, %i0
a011ad50:  b5 2f 20 02  sll  %i4, 2, %i2
a011ad54:  f6 26 00 00  st  %i3, [ %i0 ]
a011ad58:  b8 16 80 0d  or  %i2, %o5, %i4
a011ad5c:  f2 07 00 00  ld  [ %i4 ], %i1
a011ad60:  82 0e 60 cf  and  %i1, 0xcf, %g1
a011ad64:  c2 27 00 00  st  %g1, [ %i4 ]
a011ad68:  30 80 00 16  b,a   0xa011adc0
a011ad6c:  b0 10 20 08  mov  8, %i0
a011ad70:  10 bf ff dc  b  0xa011ace0
a011ad74:  b6 10 20 08  mov  8, %i3
a011ad78:  80 a6 a0 02  cmp  %i2, 2
a011ad7c:  b8 60 20 00  subx  %g0, 0, %i4
a011ad80:  b6 0e 40 1c  and  %i1, %i4, %i3
a011ad84:  b4 0e e0 ff  and  %i3, 0xff, %i2
a011ad88:  ba 06 80 1a  add  %i2, %i2, %i5
a011ad8c:  f2 13 c0 1d  lduh  [ %o7 + %i5 ], %i1
a011ad90:  82 06 60 a1  add  %i1, 0xa1, %g1
a011ad94:  f8 13 c0 0b  lduh  [ %o7 + %o3 ], %i4
a011ad98:  b7 28 60 02  sll  %g1, 2, %i3
a011ad9c:  b4 07 20 cf  add  %i4, 0xcf, %i2
a011ada0:  ba 16 c0 0d  or  %i3, %o5, %i5
a011ada4:  b3 2e a0 02  sll  %i2, 2, %i1
a011ada8:  f0 27 40 00  st  %i0, [ %i5 ]
a011adac:  b8 16 40 0d  or  %i1, %o5, %i4
a011adb0:  c2 07 00 00  ld  [ %i4 ], %g1
a011adb4:  b6 10 60 30  or  %g1, 0x30, %i3
a011adb8:  82 0e e0 ff  and  %i3, 0xff, %g1
a011adbc:  c2 27 00 00  st  %g1, [ %i4 ]
a011adc0:  81 c7 e0 08  ret
a011adc4:  81 e8 00 00  restore
