# leon2s DRV_HDMI21_LMS_To_EQ 0xa0079f80-0xa007a050 (208 bytes)
a0079f80:  9d e3 bf 98  save  %sp, -104, %sp
a0079f84:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a0079f88:  c2 00 62 34  ld  [ %g1 + 0x234 ], %g1	! 0xa8078634
a0079f8c:  80 88 68 00  btst  0x800, %g1
a0079f90:  a2 10 00 18  mov  %i0, %l1
a0079f94:  02 80 00 07  be  0xa0079fb0
a0079f98:  a0 10 20 00  clr  %l0
a0079f9c:  11 28 01 9e  sethi  %hi(0xa0067800), %o0
a0079fa0:  13 28 02 cf  sethi  %hi(0xa00b3c00), %o1
a0079fa4:  90 12 20 68  or  %o0, 0x68, %o0
a0079fa8:  7f ff e4 27  call  0xa0073044
a0079fac:  92 12 62 00  or  %o1, 0x200, %o1
a0079fb0:  1b 28 02 ce  sethi  %hi(0xa00b3800), %o5
a0079fb4:  82 04 00 10  add  %l0, %l0, %g1
a0079fb8:  9a 13 63 0a  or  %o5, 0x30a, %o5
a0079fbc:  b0 0c 60 ff  and  %l1, 0xff, %i0
a0079fc0:  15 00 3f ff  sethi  %hi(0xfffc00), %o2
a0079fc4:  d2 13 40 01  lduh  [ %o5 + %g1 ], %o1
a0079fc8:  94 12 a3 ff  or  %o2, 0x3ff, %o2
a0079fcc:  90 10 00 18  mov  %i0, %o0
a0079fd0:  40 00 b5 2e  call  0xa00a7488
a0079fd4:  17 06 00 00  sethi  %hi(0x18000000), %o3
a0079fd8:  a0 04 20 01  inc  %l0
a0079fdc:  80 a4 20 02  cmp  %l0, 2
a0079fe0:  04 bf ff f5  ble  0xa0079fb4
a0079fe4:  1b 28 02 ce  sethi  %hi(0xa00b3800), %o5
a0079fe8:  a0 10 20 00  clr  %l0
a0079fec:  03 28 02 ce  sethi  %hi(0xa00b3800), %g1
a0079ff0:  a2 04 00 10  add  %l0, %l0, %l1
a0079ff4:  82 10 63 18  or  %g1, 0x318, %g1
a0079ff8:  90 10 00 18  mov  %i0, %o0
a0079ffc:  94 10 3f f0  mov  -16, %o2
a007a000:  96 10 20 0f  mov  0xf, %o3
a007a004:  40 00 b5 21  call  0xa00a7488
a007a008:  d2 10 40 11  lduh  [ %g1 + %l1 ], %o1
a007a00c:  80 a4 20 03  cmp  %l0, 3
a007a010:  15 00 3f ff  sethi  %hi(0xfffc00), %o2
a007a014:  a0 04 20 01  inc  %l0
a007a018:  94 12 a3 ff  or  %o2, 0x3ff, %o2
a007a01c:  90 10 00 18  mov  %i0, %o0
a007a020:  14 80 00 06  bg  0xa007a038
a007a024:  17 06 00 00  sethi  %hi(0x18000000), %o3
a007a028:  03 28 02 ce  sethi  %hi(0xa00b3800), %g1
a007a02c:  82 10 63 10  or  %g1, 0x310, %g1	! 0xa00b3b10
a007a030:  40 00 b5 16  call  0xa00a7488
a007a034:  d2 10 40 11  lduh  [ %g1 + %l1 ], %o1
a007a038:  80 a4 20 03  cmp  %l0, 3
a007a03c:  04 bf ff ed  ble  0xa0079ff0
a007a040:  03 28 02 ce  sethi  %hi(0xa00b3800), %g1
a007a044:  7f ff ff 6f  call  0xa0079e00
a007a048:  81 e8 00 00  restore
a007a04c:  01 00 00 00  nop
