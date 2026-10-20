# leon2m FUN_a013ab9c 0xa013ab9c-0xa013adcc (560 bytes)
a013ab9c:  9d e3 bf 78  save  %sp, -136, %sp
a013aba0:  98 10 20 00  clr  %o4
a013aba4:  9a 10 20 00  clr  %o5
a013aba8:  d8 3f bf f0  std  %o4, [ %fp + -16 ]
a013abac:  d8 3f bf d8  std  %o4, [ %fp + -40 ]
a013abb0:  d8 3f bf e0  std  %o4, [ %fp + -32 ]
a013abb4:  d8 3f bf e8  std  %o4, [ %fp + -24 ]
a013abb8:  a2 10 20 00  clr  %l1
a013abbc:  a0 10 20 64  mov  0x64, %l0
a013abc0:  a4 07 bf d8  add  %fp, -40, %l2
a013abc4:  90 10 20 01  mov  1, %o0
a013abc8:  92 10 20 80  mov  0x80, %o1
a013abcc:  94 10 00 12  mov  %l2, %o2
a013abd0:  67 fd 46 40  call  0x4008c4d0
a013abd4:  96 10 20 01  mov  1, %o3
a013abd8:  c2 07 bf d8  ld  [ %fp + -40 ], %g1
a013abdc:  90 10 20 01  mov  1, %o0
a013abe0:  80 a0 60 00  cmp  %g1, 0
a013abe4:  02 80 00 07  be  0xa013ac00
a013abe8:  a0 04 3f ff  add  %l0, -1, %l0
a013abec:  67 fd 49 94  call  0x4008d23c
a013abf0:  01 00 00 00  nop
a013abf4:  80 8c 20 ff  btst  0xff, %l0
a013abf8:  12 bf ff f4  bne  0xa013abc8
a013abfc:  90 10 20 01  mov  1, %o0
a013ac00:  a0 0e 60 ff  and  %i1, 0xff, %l0
a013ac04:  80 a4 20 1c  cmp  %l0, 0x1c
a013ac08:  08 80 00 05  bleu  0xa013ac1c
a013ac0c:  9f 34 20 02  srl  %l0, 2, %o7
a013ac10:  b2 10 20 1c  mov  0x1c, %i1
a013ac14:  a0 10 20 1c  mov  0x1c, %l0
a013ac18:  9f 34 20 02  srl  %l0, 2, %o7
a013ac1c:  80 a3 e0 00  cmp  %o7, 0
a013ac20:  a8 0c 20 03  and  %l0, 3, %l4
a013ac24:  02 80 00 18  be  0xa013ac84
a013ac28:  90 10 20 00  clr  %o0
a013ac2c:  92 10 20 00  clr  %o1
a013ac30:  a6 07 bf f8  add  %fp, -8, %l3
a013ac34:  98 0c 60 ff  and  %l1, 0xff, %o4
a013ac38:  96 03 00 1a  add  %o4, %i2, %o3
a013ac3c:  d4 0a e0 01  ldub  [ %o3 + 1 ], %o2
a013ac40:  83 2a a0 08  sll  %o2, 8, %g1
a013ac44:  da 0b 00 1a  ldub  [ %o4 + %i2 ], %o5
a013ac48:  d4 0a e0 02  ldub  [ %o3 + 2 ], %o2
a013ac4c:  9a 13 40 01  or  %o5, %g1, %o5
a013ac50:  99 2a a0 10  sll  %o2, 0x10, %o4
a013ac54:  c2 0a e0 03  ldub  [ %o3 + 3 ], %g1
a013ac58:  95 2a 60 02  sll  %o1, 2, %o2
a013ac5c:  96 13 40 0c  or  %o5, %o4, %o3
a013ac60:  93 28 60 18  sll  %g1, 0x18, %o1
a013ac64:  9a 12 c0 09  or  %o3, %o1, %o5
a013ac68:  90 02 20 01  inc  %o0
a013ac6c:  96 02 80 13  add  %o2, %l3, %o3
a013ac70:  92 0a 20 ff  and  %o0, 0xff, %o1
a013ac74:  da 22 ff e4  st  %o5, [ %o3 + -28 ]
a013ac78:  80 a2 40 0f  cmp  %o1, %o7
a013ac7c:  0a bf ff ee  bcs  0xa013ac34
a013ac80:  a2 04 60 04  add  %l1, 4, %l1
a013ac84:  96 0d 20 ff  and  %l4, 0xff, %o3
a013ac88:  80 a2 e0 00  cmp  %o3, 0
a013ac8c:  22 80 00 16  be,a   0xa013ace4
a013ac90:  a0 06 60 04  add  %i1, 4, %l0
a013ac94:  80 a2 e0 00  cmp  %o3, 0
a013ac98:  02 80 00 12  be  0xa013ace0
a013ac9c:  92 10 20 00  clr  %o1
a013aca0:  9e 0c 60 ff  and  %l1, 0xff, %o7
a013aca4:  a2 0c 20 fc  and  %l0, 0xfc, %l1
a013aca8:  a0 07 bf f8  add  %fp, -8, %l0
a013acac:  90 04 40 10  add  %l1, %l0, %o0
a013acb0:  94 03 c0 1a  add  %o7, %i2, %o2
a013acb4:  9a 10 20 00  clr  %o5
a013acb8:  83 2b 60 03  sll  %o5, 3, %g1
a013acbc:  da 0a 80 0d  ldub  [ %o2 + %o5 ], %o5
a013acc0:  b5 2b 40 01  sll  %o5, %g1, %i2
a013acc4:  e8 02 3f e4  ld  [ %o0 + -28 ], %l4
a013acc8:  92 02 60 01  inc  %o1
a013accc:  a6 15 00 1a  or  %l4, %i2, %l3
a013acd0:  9a 0a 60 ff  and  %o1, 0xff, %o5
a013acd4:  80 a3 40 0b  cmp  %o5, %o3
a013acd8:  0a bf ff f8  bcs  0xa013acb8
a013acdc:  e6 22 3f e4  st  %l3, [ %o0 + -28 ]
a013ace0:  a0 06 60 04  add  %i1, 4, %l0
a013ace4:  9e 0c 20 ff  and  %l0, 0xff, %o7
a013ace8:  99 2e 20 08  sll  %i0, 8, %o4
a013acec:  95 2b e0 10  sll  %o7, 0x10, %o2
a013acf0:  96 13 00 0a  or  %o4, %o2, %o3
a013acf4:  13 00 3f ff  sethi  %hi(0xfffc00), %o1
a013acf8:  b0 12 e0 55  or  %o3, 0x55, %i0
a013acfc:  b2 12 63 ff  or  %o1, 0x3ff, %i1
a013ad00:  90 0e 00 19  and  %i0, %i1, %o0
a013ad04:  d0 27 bf d8  st  %o0, [ %fp + -40 ]
a013ad08:  98 10 20 00  clr  %o4
a013ad0c:  94 10 20 00  clr  %o2
a013ad10:  82 10 20 00  clr  %g1
a013ad14:  b1 28 60 02  sll  %g1, 2, %i0
a013ad18:  e8 04 80 18  ld  [ %l2 + %i0 ], %l4
a013ad1c:  90 1d 00 0c  xor  %l4, %o4, %o0
a013ad20:  83 35 20 08  srl  %l4, 8, %g1
a013ad24:  b4 1a 00 01  xor  %o0, %g1, %i2
a013ad28:  9b 35 20 10  srl  %l4, 0x10, %o5
a013ad2c:  94 02 a0 01  inc  %o2
a013ad30:  a2 1e 80 0d  xor  %i2, %o5, %l1
a013ad34:  a7 35 20 18  srl  %l4, 0x18, %l3
a013ad38:  82 0a a0 ff  and  %o2, 0xff, %g1
a013ad3c:  80 a0 60 08  cmp  %g1, 8
a013ad40:  0a bf ff f5  bcs  0xa013ad14
a013ad44:  98 1c 40 13  xor  %l1, %l3, %o4
a013ad48:  97 2b 20 18  sll  %o4, 0x18, %o3
a013ad4c:  d2 04 80 00  ld  [ %l2 ], %o1
a013ad50:  b2 12 40 0b  or  %o1, %o3, %i1
a013ad54:  90 10 20 01  mov  1, %o0
a013ad58:  92 10 20 80  mov  0x80, %o1
a013ad5c:  94 10 00 12  mov  %l2, %o2
a013ad60:  96 10 20 08  mov  8, %o3
a013ad64:  67 fd 46 25  call  0x4008c5f8
a013ad68:  f2 24 80 00  st  %i1, [ %l2 ]
a013ad6c:  7f fe 8f 01  call  0xa00de970
a013ad70:  b6 0e e0 ff  and  %i3, 0xff, %i3
a013ad74:  80 a6 e0 00  cmp  %i3, 0
a013ad78:  02 80 00 13  be  0xa013adc4
a013ad7c:  a0 10 20 64  mov  0x64, %l0
a013ad80:  90 10 20 01  mov  1, %o0
a013ad84:  92 10 20 80  mov  0x80, %o1
a013ad88:  94 10 00 12  mov  %l2, %o2
a013ad8c:  67 fd 45 d1  call  0x4008c4d0
a013ad90:  96 10 20 01  mov  1, %o3
a013ad94:  d8 07 bf d8  ld  [ %fp + -40 ], %o4
a013ad98:  90 10 20 01  mov  1, %o0
a013ad9c:  80 a3 20 00  cmp  %o4, 0
a013ada0:  02 80 00 09  be  0xa013adc4
a013ada4:  a0 04 3f ff  add  %l0, -1, %l0
a013ada8:  67 fd 49 25  call  0x4008d23c
a013adac:  01 00 00 00  nop
a013adb0:  80 8c 20 ff  btst  0xff, %l0
a013adb4:  02 80 00 04  be  0xa013adc4
a013adb8:  80 a6 e0 00  cmp  %i3, 0
a013adbc:  12 bf ff f2  bne  0xa013ad84
a013adc0:  90 10 20 01  mov  1, %o0
a013adc4:  81 c7 e0 08  ret
a013adc8:  81 e8 00 00  restore
