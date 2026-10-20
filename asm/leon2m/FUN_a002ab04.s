# leon2m FUN_a002ab04 0xa002ab04-0xa002ae4c (840 bytes)
a002ab04:  9d e3 bf 90  save  %sp, -112, %sp
a002ab08:  27 2a 00 b6  sethi  %hi(0xa802d800), %l3
a002ab0c:  ac 14 e1 92  or  %l3, 0x192, %l6	! 0xa802d992
a002ab10:  9e 10 3f 80  mov  -128, %o7
a002ab14:  98 10 20 40  mov  0x40, %o4
a002ab18:  96 10 20 20  mov  0x20, %o3
a002ab1c:  94 10 20 10  mov  0x10, %o2
a002ab20:  92 10 20 08  mov  8, %o1
a002ab24:  90 10 20 04  mov  4, %o0
a002ab28:  82 10 20 02  mov  2, %g1
a002ab2c:  9a 10 20 01  mov  1, %o5
a002ab30:  de 2f bf f0  stb  %o7, [ %fp + -16 ]
a002ab34:  d8 2f bf f1  stb  %o4, [ %fp + -15 ]
a002ab38:  d6 2f bf f2  stb  %o3, [ %fp + -14 ]
a002ab3c:  d4 2f bf f3  stb  %o2, [ %fp + -13 ]
a002ab40:  d2 2f bf f4  stb  %o1, [ %fp + -12 ]
a002ab44:  d0 2f bf f5  stb  %o0, [ %fp + -11 ]
a002ab48:  c2 2f bf f6  stb  %g1, [ %fp + -10 ]
a002ab4c:  da 2f bf f7  stb  %o5, [ %fp + -9 ]
a002ab50:  a8 10 20 00  clr  %l4
a002ab54:  a0 10 20 00  clr  %l0
a002ab58:  aa 07 bf f8  add  %fp, -8, %l5
a002ab5c:  a4 10 00 16  mov  %l6, %l2
a002ab60:  c2 14 a0 04  lduh  [ %l2 + 4 ], %g1
a002ab64:  9b 28 60 11  sll  %g1, 0x11, %o5
a002ab68:  40 00 09 b5  call  0xa002d23c
a002ab6c:  91 33 60 10  srl  %o5, 0x10, %o0
a002ab70:  d0 0c e1 92  ldub  [ %l3 + 0x192 ], %o0
a002ab74:  d2 0c a0 01  ldub  [ %l2 + 1 ], %o1
a002ab78:  40 00 07 3d  call  0xa002c86c
a002ab7c:  94 10 20 00  clr  %o2
a002ab80:  40 00 09 af  call  0xa002d23c
a002ab84:  d0 14 a0 04  lduh  [ %l2 + 4 ], %o0
a002ab88:  a2 05 40 10  add  %l5, %l0, %l1
a002ab8c:  e0 0c 7f f8  ldub  [ %l1 + -8 ], %l0
a002ab90:  80 8c 00 18  btst  %l0, %i0
a002ab94:  02 80 00 72  be  0xa002ad5c
a002ab98:  d0 0c a0 02  ldub  [ %l2 + 2 ], %o0
a002ab9c:  d2 0c a0 03  ldub  [ %l2 + 3 ], %o1
a002aba0:  94 10 20 01  mov  1, %o2
a002aba4:  40 00 07 32  call  0xa002c86c
a002aba8:  a0 10 3f ff  mov  -1, %l0
a002abac:  40 00 09 a4  call  0xa002d23c
a002abb0:  d0 14 a0 04  lduh  [ %l2 + 4 ], %o0
a002abb4:  d0 0c e1 92  ldub  [ %l3 + 0x192 ], %o0
a002abb8:  d2 0c a0 01  ldub  [ %l2 + 1 ], %o1
a002abbc:  40 00 07 2c  call  0xa002c86c
a002abc0:  94 10 20 01  mov  1, %o2
a002abc4:  d0 0c e1 92  ldub  [ %l3 + 0x192 ], %o0
a002abc8:  d2 0c a0 01  ldub  [ %l2 + 1 ], %o1
a002abcc:  40 00 07 d9  call  0xa002cb30
a002abd0:  94 10 20 01  mov  1, %o2
a002abd4:  10 80 00 07  b  0xa002abf0
a002abd8:  a2 10 00 16  mov  %l6, %l1
a002abdc:  80 a3 60 00  cmp  %o5, 0
a002abe0:  02 80 00 0d  be  0xa002ac14
a002abe4:  15 2a 00 b6  sethi  %hi(0xa802d800), %o2
a002abe8:  01 00 00 00  nop
a002abec:  01 00 00 00  nop
a002abf0:  d2 0c 60 01  ldub  [ %l1 + 1 ], %o1
a002abf4:  40 00 08 51  call  0xa002cd38
a002abf8:  d0 0c e1 92  ldub  [ %l3 + 0x192 ], %o0
a002abfc:  92 04 3f ff  add  %l0, -1, %o1
a002ac00:  9b 2a 60 10  sll  %o1, 0x10, %o5
a002ac04:  80 8a 20 ff  btst  0xff, %o0
a002ac08:  02 bf ff f5  be  0xa002abdc
a002ac0c:  a0 10 00 09  mov  %o1, %l0
a002ac10:  15 2a 00 b6  sethi  %hi(0xa802d800), %o2
a002ac14:  d0 0a a1 92  ldub  [ %o2 + 0x192 ], %o0	! 0xa802d992
a002ac18:  d2 0c 60 01  ldub  [ %l1 + 1 ], %o1
a002ac1c:  94 10 20 00  clr  %o2
a002ac20:  40 00 07 c4  call  0xa002cb30
a002ac24:  a8 05 20 01  inc  %l4
a002ac28:  a0 0d 20 ff  and  %l4, 0xff, %l0
a002ac2c:  80 a4 20 07  cmp  %l0, 7
a002ac30:  28 bf ff cd  bleu,a   0xa002ab64
a002ac34:  c2 14 a0 04  lduh  [ %l2 + 4 ], %g1
a002ac38:  a0 14 e1 92  or  %l3, 0x192, %l0
a002ac3c:  d0 14 20 04  lduh  [ %l0 + 4 ], %o0
a002ac40:  b1 2a 20 11  sll  %o0, 0x11, %i0
a002ac44:  40 00 09 7e  call  0xa002d23c
a002ac48:  91 36 20 10  srl  %i0, 0x10, %o0
a002ac4c:  d2 0c 20 01  ldub  [ %l0 + 1 ], %o1
a002ac50:  94 10 20 00  clr  %o2
a002ac54:  40 00 07 06  call  0xa002c86c
a002ac58:  d0 0c e1 92  ldub  [ %l3 + 0x192 ], %o0
a002ac5c:  ec 14 20 04  lduh  [ %l0 + 4 ], %l6
a002ac60:  ab 2d a0 11  sll  %l6, 0x11, %l5
a002ac64:  40 00 09 76  call  0xa002d23c
a002ac68:  91 35 60 10  srl  %l5, 0x10, %o0
a002ac6c:  d0 0c 20 02  ldub  [ %l0 + 2 ], %o0
a002ac70:  d2 0c 20 03  ldub  [ %l0 + 3 ], %o1
a002ac74:  40 00 06 fe  call  0xa002c86c
a002ac78:  94 10 20 00  clr  %o2
a002ac7c:  d0 0c 20 02  ldub  [ %l0 + 2 ], %o0
a002ac80:  d2 0c 20 03  ldub  [ %l0 + 3 ], %o1
a002ac84:  40 00 07 ab  call  0xa002cb30
a002ac88:  94 10 20 01  mov  1, %o2
a002ac8c:  d2 0c 20 03  ldub  [ %l0 + 3 ], %o1
a002ac90:  94 10 20 01  mov  1, %o2
a002ac94:  40 00 06 f6  call  0xa002c86c
a002ac98:  d0 0c 20 02  ldub  [ %l0 + 2 ], %o0
a002ac9c:  e8 14 20 04  lduh  [ %l0 + 4 ], %l4
a002aca0:  a5 2d 20 11  sll  %l4, 0x11, %l2
a002aca4:  40 00 09 66  call  0xa002d23c
a002aca8:  91 34 a0 10  srl  %l2, 0x10, %o0
a002acac:  d0 0c e1 92  ldub  [ %l3 + 0x192 ], %o0
a002acb0:  d2 0c 20 01  ldub  [ %l0 + 1 ], %o1
a002acb4:  40 00 06 ee  call  0xa002c86c
a002acb8:  94 10 20 01  mov  1, %o2
a002acbc:  d0 0c e1 92  ldub  [ %l3 + 0x192 ], %o0
a002acc0:  d2 0c 20 01  ldub  [ %l0 + 1 ], %o1
a002acc4:  40 00 07 9b  call  0xa002cb30
a002acc8:  94 10 20 01  mov  1, %o2
a002accc:  a2 10 3f ff  mov  -1, %l1
a002acd0:  10 80 00 07  b  0xa002acec
a002acd4:  25 2a 00 b6  sethi  %hi(0xa802d800), %l2
a002acd8:  80 a3 60 00  cmp  %o5, 0
a002acdc:  22 80 00 0d  be,a   0xa002ad10
a002ace0:  d2 0c 20 01  ldub  [ %l0 + 1 ], %o1
a002ace4:  01 00 00 00  nop
a002ace8:  01 00 00 00  nop
a002acec:  d0 0c e1 92  ldub  [ %l3 + 0x192 ], %o0
a002acf0:  40 00 08 12  call  0xa002cd38
a002acf4:  d2 0c 20 01  ldub  [ %l0 + 1 ], %o1
a002acf8:  96 04 7f ff  add  %l1, -1, %o3
a002acfc:  9b 2a e0 10  sll  %o3, 0x10, %o5
a002ad00:  80 8a 20 ff  btst  0xff, %o0
a002ad04:  02 bf ff f5  be  0xa002acd8
a002ad08:  a2 10 00 0b  mov  %o3, %l1
a002ad0c:  d2 0c 20 01  ldub  [ %l0 + 1 ], %o1
a002ad10:  94 10 20 00  clr  %o2
a002ad14:  40 00 07 87  call  0xa002cb30
a002ad18:  d0 0c a1 92  ldub  [ %l2 + 0x192 ], %o0
a002ad1c:  de 14 20 04  lduh  [ %l0 + 4 ], %o7
a002ad20:  99 2b e0 11  sll  %o7, 0x11, %o4
a002ad24:  40 00 09 46  call  0xa002d23c
a002ad28:  91 33 20 10  srl  %o4, 0x10, %o0
a002ad2c:  d0 0c a1 92  ldub  [ %l2 + 0x192 ], %o0
a002ad30:  d2 0c 20 01  ldub  [ %l0 + 1 ], %o1
a002ad34:  40 00 07 7f  call  0xa002cb30
a002ad38:  94 10 20 01  mov  1, %o2
a002ad3c:  d0 0c a1 92  ldub  [ %l2 + 0x192 ], %o0
a002ad40:  40 00 07 fe  call  0xa002cd38
a002ad44:  d2 0c 20 01  ldub  [ %l0 + 1 ], %o1
a002ad48:  80 8a 20 ff  btst  0xff, %o0
a002ad4c:  02 80 00 28  be  0xa002adec
a002ad50:  b0 10 20 01  mov  1, %i0
a002ad54:  10 80 00 05  b  0xa002ad68
a002ad58:  d2 0c 20 03  ldub  [ %l0 + 3 ], %o1
a002ad5c:  d2 0c a0 03  ldub  [ %l2 + 3 ], %o1
a002ad60:  10 bf ff 91  b  0xa002aba4
a002ad64:  94 10 20 00  clr  %o2
a002ad68:  40 00 07 f4  call  0xa002cd38
a002ad6c:  d0 0c 20 02  ldub  [ %l0 + 2 ], %o0
a002ad70:  25 2a 00 b6  sethi  %hi(0xa802d800), %l2
a002ad74:  a2 10 20 07  mov  7, %l1
a002ad78:  a0 14 a1 92  or  %l2, 0x192, %l0
a002ad7c:  80 8a 20 ff  btst  0xff, %o0
a002ad80:  12 80 00 08  bne  0xa002ada0
a002ad84:  b0 10 20 00  clr  %i0
a002ad88:  10 80 00 1a  b  0xa002adf0
a002ad8c:  a4 14 e1 92  or  %l3, 0x192, %l2
a002ad90:  9b 28 60 11  sll  %g1, 0x11, %o5
a002ad94:  40 00 09 2a  call  0xa002d23c
a002ad98:  91 33 60 10  srl  %o5, 0x10, %o0
a002ad9c:  a2 04 7f ff  add  %l1, -1, %l1
a002ada0:  d2 0c 20 03  ldub  [ %l0 + 3 ], %o1
a002ada4:  40 00 07 e5  call  0xa002cd38
a002ada8:  d0 0c 20 02  ldub  [ %l0 + 2 ], %o0
a002adac:  80 8a 20 ff  btst  0xff, %o0
a002adb0:  22 80 00 06  be,a   0xa002adc8
a002adb4:  d2 0c 20 01  ldub  [ %l0 + 1 ], %o1
a002adb8:  80 8c 60 ff  btst  0xff, %l1
a002adbc:  32 bf ff f5  bne,a   0xa002ad90
a002adc0:  c2 14 20 04  lduh  [ %l0 + 4 ], %g1
a002adc4:  d2 0c 20 01  ldub  [ %l0 + 1 ], %o1
a002adc8:  40 00 07 dc  call  0xa002cd38
a002adcc:  d0 0c a1 92  ldub  [ %l2 + 0x192 ], %o0
a002add0:  80 8a 20 ff  btst  0xff, %o0
a002add4:  22 bf ff ef  be,a   0xa002ad90
a002add8:  c2 14 20 04  lduh  [ %l0 + 4 ], %g1
a002addc:  92 0c 60 ff  and  %l1, 0xff, %o1
a002ade0:  80 a0 00 09  cmp  %g0, %o1
a002ade4:  a0 60 3f ff  subx  %g0, -1, %l0
a002ade8:  b0 10 00 10  mov  %l0, %i0
a002adec:  a4 14 e1 92  or  %l3, 0x192, %l2
a002adf0:  d0 0c e1 92  ldub  [ %l3 + 0x192 ], %o0
a002adf4:  d2 0c a0 01  ldub  [ %l2 + 1 ], %o1
a002adf8:  40 00 07 4e  call  0xa002cb30
a002adfc:  94 10 20 00  clr  %o2
a002ae00:  d0 0c e1 92  ldub  [ %l3 + 0x192 ], %o0
a002ae04:  d2 0c a0 01  ldub  [ %l2 + 1 ], %o1
a002ae08:  40 00 06 99  call  0xa002c86c
a002ae0c:  94 10 20 00  clr  %o2
a002ae10:  d0 0c a0 02  ldub  [ %l2 + 2 ], %o0
a002ae14:  d2 0c a0 03  ldub  [ %l2 + 3 ], %o1
a002ae18:  40 00 07 46  call  0xa002cb30
a002ae1c:  94 10 20 00  clr  %o2
a002ae20:  d0 0c a0 02  ldub  [ %l2 + 2 ], %o0
a002ae24:  d2 0c a0 03  ldub  [ %l2 + 3 ], %o1
a002ae28:  40 00 06 91  call  0xa002c86c
a002ae2c:  94 10 20 00  clr  %o2
a002ae30:  e2 14 a0 04  lduh  [ %l2 + 4 ], %l1
a002ae34:  a7 2c 60 11  sll  %l1, 0x11, %l3
a002ae38:  40 00 09 01  call  0xa002d23c
a002ae3c:  91 34 e0 10  srl  %l3, 0x10, %o0
a002ae40:  b0 0e 20 01  and  %i0, 1, %i0
a002ae44:  81 c7 e0 08  ret
a002ae48:  81 e8 00 00  restore
