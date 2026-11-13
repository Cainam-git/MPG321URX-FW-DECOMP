# leon2m FUN_a00eba64 0xa00eba64-0xa00ec340 (2268 bytes)
a00eba64:  9d e3 bf 98  save  %sp, -104, %sp
a00eba68:  96 10 00 1d  mov  %i5, %o3
a00eba6c:  90 10 00 18  mov  %i0, %o0
a00eba70:  92 10 00 1b  mov  %i3, %o1
a00eba74:  94 10 00 1c  mov  %i4, %o2
a00eba78:  7f ff ff 24  call  0xa00eb708
a00eba7c:  d8 07 a0 5c  ld  [ %fp + 0x5c ], %o4
a00eba80:  90 10 00 18  mov  %i0, %o0
a00eba84:  f2 27 a0 48  st  %i1, [ %fp + 0x48 ]
a00eba88:  92 10 00 19  mov  %i1, %o1
a00eba8c:  f4 27 a0 4c  st  %i2, [ %fp + 0x4c ]
a00eba90:  94 10 00 1a  mov  %i2, %o2
a00eba94:  7f ff e1 f9  call  0xa00e4278
a00eba98:  d6 07 a0 60  ld  [ %fp + 0x60 ], %o3
a00eba9c:  80 a2 20 00  cmp  %o0, 0
a00ebaa0:  12 80 02 26  bne  0xa00ec338
a00ebaa4:  82 10 3f ff  mov  -1, %g1
a00ebaa8:  19 2a 00 9a  sethi  %hi(0xa8026800), %o4
a00ebaac:  17 2a 00 9a  sethi  %hi(0xa8026800), %o3
a00ebab0:  33 2a 00 9a  sethi  %hi(0xa8026800), %i1
a00ebab4:  2f 2a 00 9a  sethi  %hi(0xa8026800), %l7
a00ebab8:  35 2a 00 9a  sethi  %hi(0xa8026800), %i2
a00ebabc:  2d 2a 00 9a  sethi  %hi(0xa8026800), %l6
a00ebac0:  aa 16 60 e8  or  %i1, 0xe8, %l5
a00ebac4:  a1 2e e0 02  sll  %i3, 2, %l0
a00ebac8:  ba 15 e0 d8  or  %l7, 0xd8, %i5
a00ebacc:  a8 16 a0 c8  or  %i2, 0xc8, %l4
a00ebad0:  a6 15 a0 b8  or  %l6, 0xb8, %l3
a00ebad4:  a2 13 20 a8  or  %o4, 0xa8, %l1
a00ebad8:  a4 12 e0 98  or  %o3, 0x98, %l2
a00ebadc:  80 a7 20 00  cmp  %i4, 0
a00ebae0:  02 80 01 3f  be  0xa00ebfdc
a00ebae4:  80 a6 ff ff  cmp  %i3, -1
a00ebae8:  02 80 00 f4  be  0xa00ebeb8
a00ebaec:  b8 07 3f ff  add  %i4, -1, %i4
a00ebaf0:  d2 05 40 10  ld  [ %l5 + %l0 ], %o1
a00ebaf4:  d4 07 40 10  ld  [ %i5 + %l0 ], %o2
a00ebaf8:  d6 05 00 10  ld  [ %l4 + %l0 ], %o3
a00ebafc:  7f ff d3 16  call  0xa00e0754
a00ebb00:  90 10 00 18  mov  %i0, %o0
a00ebb04:  98 02 3f ff  add  %o0, -1, %o4
a00ebb08:  90 10 00 18  mov  %i0, %o0
a00ebb0c:  d2 05 40 10  ld  [ %l5 + %l0 ], %o1
a00ebb10:  d4 07 40 10  ld  [ %i5 + %l0 ], %o2
a00ebb14:  7f ff d3 18  call  0xa00e0774
a00ebb18:  d6 05 00 10  ld  [ %l4 + %l0 ], %o3
a00ebb1c:  d2 04 c0 10  ld  [ %l3 + %l0 ], %o1
a00ebb20:  d4 04 40 10  ld  [ %l1 + %l0 ], %o2
a00ebb24:  d6 04 80 10  ld  [ %l2 + %l0 ], %o3
a00ebb28:  7f ff d3 0b  call  0xa00e0754
a00ebb2c:  90 10 00 18  mov  %i0, %o0
a00ebb30:  98 02 3f ff  add  %o0, -1, %o4
a00ebb34:  90 10 00 18  mov  %i0, %o0
a00ebb38:  d2 04 c0 10  ld  [ %l3 + %l0 ], %o1
a00ebb3c:  d4 04 40 10  ld  [ %l1 + %l0 ], %o2
a00ebb40:  d6 04 80 10  ld  [ %l2 + %l0 ], %o3
a00ebb44:  7f ff d3 0c  call  0xa00e0774
a00ebb48:  01 00 00 00  nop
a00ebb4c:  80 a7 20 08  cmp  %i4, 8
a00ebb50:  04 80 00 22  ble  0xa00ebbd8
a00ebb54:  80 a6 ff ff  cmp  %i3, -1
a00ebb58:  02 80 00 f2  be  0xa00ebf20
a00ebb5c:  1f 2a 00 9a  sethi  %hi(0xa8026800), %o7
a00ebb60:  15 2a 00 9a  sethi  %hi(0xa8026800), %o2
a00ebb64:  96 12 a1 48  or  %o2, 0x148, %o3	! 0xa8026948
a00ebb68:  03 2a 00 9a  sethi  %hi(0xa8026800), %g1
a00ebb6c:  d2 02 c0 10  ld  [ %o3 + %l0 ], %o1
a00ebb70:  9a 13 e1 38  or  %o7, 0x138, %o5
a00ebb74:  98 10 61 28  or  %g1, 0x128, %o4
a00ebb78:  90 10 00 18  mov  %i0, %o0
a00ebb7c:  d4 03 40 10  ld  [ %o5 + %l0 ], %o2
a00ebb80:  d6 03 00 10  ld  [ %o4 + %l0 ], %o3
a00ebb84:  7f ff d2 fc  call  0xa00e0774
a00ebb88:  98 10 20 03  mov  3, %o4
a00ebb8c:  90 10 00 18  mov  %i0, %o0
a00ebb90:  d2 07 a0 48  ld  [ %fp + 0x48 ], %o1
a00ebb94:  d4 07 a0 4c  ld  [ %fp + 0x4c ], %o2
a00ebb98:  7f ff e1 b8  call  0xa00e4278
a00ebb9c:  d6 07 a0 60  ld  [ %fp + 0x60 ], %o3
a00ebba0:  80 a2 20 01  cmp  %o0, 1
a00ebba4:  22 80 00 24  be,a   0xa00ebc34
a00ebba8:  2f 2a 00 99  sethi  %hi(0xa8026400), %l7
a00ebbac:  80 a2 20 00  cmp  %o0, 0
a00ebbb0:  02 bf ff cc  be  0xa00ebae0
a00ebbb4:  80 a7 20 00  cmp  %i4, 0
a00ebbb8:  7f ff cf 15  call  0xa00df80c
a00ebbbc:  29 00 06 67  sethi  %hi(0x199c00), %l4
a00ebbc0:  7f ff d4 00  call  0xa00e0bc0
a00ebbc4:  01 00 00 00  nop
a00ebbc8:  7f ff cd 6a  call  0xa00df170
a00ebbcc:  90 15 20 20  or  %l4, 0x20, %o0
a00ebbd0:  10 80 01 da  b  0xa00ec338
a00ebbd4:  82 10 3f ff  mov  -1, %g1
a00ebbd8:  02 80 00 da  be  0xa00ebf40
a00ebbdc:  1b 2a 00 9a  sethi  %hi(0xa8026800), %o5
a00ebbe0:  19 2a 00 9a  sethi  %hi(0xa8026800), %o4
a00ebbe4:  94 13 21 48  or  %o4, 0x148, %o2	! 0xa8026948
a00ebbe8:  17 2a 00 9a  sethi  %hi(0xa8026800), %o3
a00ebbec:  9e 12 e1 38  or  %o3, 0x138, %o7	! 0xa8026938
a00ebbf0:  d2 02 80 10  ld  [ %o2 + %l0 ], %o1
a00ebbf4:  82 13 61 28  or  %o5, 0x128, %g1
a00ebbf8:  90 10 00 18  mov  %i0, %o0
a00ebbfc:  d4 03 c0 10  ld  [ %o7 + %l0 ], %o2
a00ebc00:  d6 00 40 10  ld  [ %g1 + %l0 ], %o3
a00ebc04:  98 10 20 00  clr  %o4
a00ebc08:  7f ff d2 db  call  0xa00e0774
a00ebc0c:  01 00 00 00  nop
a00ebc10:  90 10 00 18  mov  %i0, %o0
a00ebc14:  d2 07 a0 48  ld  [ %fp + 0x48 ], %o1
a00ebc18:  d4 07 a0 4c  ld  [ %fp + 0x4c ], %o2
a00ebc1c:  7f ff e1 97  call  0xa00e4278
a00ebc20:  d6 07 a0 60  ld  [ %fp + 0x60 ], %o3
a00ebc24:  80 a2 20 01  cmp  %o0, 1
a00ebc28:  12 bf ff e2  bne  0xa00ebbb0
a00ebc2c:  80 a2 20 00  cmp  %o0, 0
a00ebc30:  2f 2a 00 99  sethi  %hi(0xa8026400), %l7
a00ebc34:  35 2a 00 99  sethi  %hi(0xa8026400), %i2
a00ebc38:  3b 2a 00 99  sethi  %hi(0xa8026400), %i5
a00ebc3c:  29 2a 00 99  sethi  %hi(0xa8026400), %l4
a00ebc40:  2b 2a 00 99  sethi  %hi(0xa8026400), %l5
a00ebc44:  2d 2a 00 99  sethi  %hi(0xa8026400), %l6
a00ebc48:  80 a6 ff ff  cmp  %i3, -1
a00ebc4c:  02 80 00 ce  be  0xa00ebf84
a00ebc50:  a1 2e e0 02  sll  %i3, 2, %l0
a00ebc54:  a4 15 e3 98  or  %l7, 0x398, %l2
a00ebc58:  a6 16 a3 88  or  %i2, 0x388, %l3
a00ebc5c:  b2 17 63 78  or  %i5, 0x378, %i1
a00ebc60:  d2 04 80 10  ld  [ %l2 + %l0 ], %o1
a00ebc64:  d4 04 c0 10  ld  [ %l3 + %l0 ], %o2
a00ebc68:  d6 06 40 10  ld  [ %i1 + %l0 ], %o3
a00ebc6c:  7f ff d2 ba  call  0xa00e0754
a00ebc70:  90 10 00 18  mov  %i0, %o0
a00ebc74:  98 02 20 01  add  %o0, 1, %o4
a00ebc78:  d2 04 80 10  ld  [ %l2 + %l0 ], %o1
a00ebc7c:  d4 04 c0 10  ld  [ %l3 + %l0 ], %o2
a00ebc80:  d6 06 40 10  ld  [ %i1 + %l0 ], %o3
a00ebc84:  7f ff d2 bc  call  0xa00e0774
a00ebc88:  90 10 00 18  mov  %i0, %o0
a00ebc8c:  a4 15 23 48  or  %l4, 0x348, %l2
a00ebc90:  a6 15 63 38  or  %l5, 0x338, %l3
a00ebc94:  a2 15 a3 28  or  %l6, 0x328, %l1
a00ebc98:  d2 04 80 10  ld  [ %l2 + %l0 ], %o1
a00ebc9c:  d4 04 c0 10  ld  [ %l3 + %l0 ], %o2
a00ebca0:  d6 04 40 10  ld  [ %l1 + %l0 ], %o3
a00ebca4:  7f ff d2 ac  call  0xa00e0754
a00ebca8:  90 10 00 18  mov  %i0, %o0
a00ebcac:  98 02 20 01  add  %o0, 1, %o4
a00ebcb0:  d6 04 40 10  ld  [ %l1 + %l0 ], %o3
a00ebcb4:  d2 04 80 10  ld  [ %l2 + %l0 ], %o1
a00ebcb8:  d4 04 c0 10  ld  [ %l3 + %l0 ], %o2
a00ebcbc:  90 10 00 18  mov  %i0, %o0
a00ebcc0:  7f ff d2 ad  call  0xa00e0774
a00ebcc4:  01 00 00 00  nop
a00ebcc8:  90 10 00 18  mov  %i0, %o0
a00ebccc:  d2 07 a0 48  ld  [ %fp + 0x48 ], %o1
a00ebcd0:  d4 07 a0 4c  ld  [ %fp + 0x4c ], %o2
a00ebcd4:  7f ff e1 69  call  0xa00e4278
a00ebcd8:  d6 07 a0 60  ld  [ %fp + 0x60 ], %o3
a00ebcdc:  80 a2 20 01  cmp  %o0, 1
a00ebce0:  12 80 01 57  bne  0xa00ec23c
a00ebce4:  80 a6 ff ff  cmp  %i3, -1
a00ebce8:  02 80 00 9f  be  0xa00ebf64
a00ebcec:  9b 2e e0 02  sll  %i3, 2, %o5
a00ebcf0:  90 16 a3 88  or  %i2, 0x388, %o0
a00ebcf4:  92 17 63 78  or  %i5, 0x378, %o1
a00ebcf8:  9e 15 e3 98  or  %l7, 0x398, %o7
a00ebcfc:  d6 02 40 0d  ld  [ %o1 + %o5 ], %o3
a00ebd00:  d4 02 00 0d  ld  [ %o0 + %o5 ], %o2
a00ebd04:  d2 03 c0 0d  ld  [ %o7 + %o5 ], %o1
a00ebd08:  7f ff d2 93  call  0xa00e0754
a00ebd0c:  90 10 00 18  mov  %i0, %o0
a00ebd10:  80 a2 20 0f  cmp  %o0, 0xf
a00ebd14:  12 bf ff ce  bne  0xa00ebc4c
a00ebd18:  80 a6 ff ff  cmp  %i3, -1
a00ebd1c:  03 2a 00 99  sethi  %hi(0xa8026400), %g1
a00ebd20:  b2 10 63 68  or  %g1, 0x368, %i1	! 0xa8026768
a00ebd24:  a7 2e e0 02  sll  %i3, 2, %l3
a00ebd28:  80 a6 ff ff  cmp  %i3, -1
a00ebd2c:  22 80 01 05  be,a   0xa00ec140
a00ebd30:  17 2a 00 99  sethi  %hi(0xa8026400), %o3
a00ebd34:  19 2a 00 ad  sethi  %hi(0xa802b400), %o4
a00ebd38:  17 2a 00 99  sethi  %hi(0xa8026400), %o3
a00ebd3c:  9a 12 e3 58  or  %o3, 0x358, %o5	! 0xa8026758
a00ebd40:  90 13 22 e8  or  %o4, 0x2e8, %o0
a00ebd44:  d6 02 00 13  ld  [ %o0 + %l3 ], %o3
a00ebd48:  d4 03 40 13  ld  [ %o5 + %l3 ], %o2
a00ebd4c:  d2 06 40 13  ld  [ %i1 + %l3 ], %o1
a00ebd50:  7f ff d2 81  call  0xa00e0754
a00ebd54:  90 10 00 18  mov  %i0, %o0
a00ebd58:  15 2a 00 99  sethi  %hi(0xa8026400), %o2
a00ebd5c:  25 2a 00 ad  sethi  %hi(0xa802b400), %l2
a00ebd60:  98 02 20 01  add  %o0, 1, %o4
a00ebd64:  82 12 a3 58  or  %o2, 0x358, %g1
a00ebd68:  a2 14 a2 e8  or  %l2, 0x2e8, %l1
a00ebd6c:  d4 00 40 13  ld  [ %g1 + %l3 ], %o2
a00ebd70:  d6 04 40 13  ld  [ %l1 + %l3 ], %o3
a00ebd74:  90 10 00 18  mov  %i0, %o0
a00ebd78:  7f ff d2 7f  call  0xa00e0774
a00ebd7c:  d2 06 40 13  ld  [ %i1 + %l3 ], %o1
a00ebd80:  21 2a 00 99  sethi  %hi(0xa8026400), %l0
a00ebd84:  17 2a 00 99  sethi  %hi(0xa8026400), %o3
a00ebd88:  03 2a 00 ad  sethi  %hi(0xa802b400), %g1
a00ebd8c:  9e 14 23 18  or  %l0, 0x318, %o7
a00ebd90:  9a 12 e3 08  or  %o3, 0x308, %o5
a00ebd94:  98 10 62 d8  or  %g1, 0x2d8, %o4
a00ebd98:  d2 03 c0 13  ld  [ %o7 + %l3 ], %o1
a00ebd9c:  d6 03 00 13  ld  [ %o4 + %l3 ], %o3
a00ebda0:  d4 03 40 13  ld  [ %o5 + %l3 ], %o2
a00ebda4:  7f ff d2 6c  call  0xa00e0754
a00ebda8:  90 10 00 18  mov  %i0, %o0
a00ebdac:  13 2a 00 99  sethi  %hi(0xa8026400), %o1
a00ebdb0:  15 2a 00 99  sethi  %hi(0xa8026400), %o2
a00ebdb4:  21 2a 00 ad  sethi  %hi(0xa802b400), %l0
a00ebdb8:  98 02 20 01  add  %o0, 1, %o4
a00ebdbc:  a4 12 63 18  or  %o1, 0x318, %l2
a00ebdc0:  a2 12 a3 08  or  %o2, 0x308, %l1
a00ebdc4:  9e 14 22 d8  or  %l0, 0x2d8, %o7
a00ebdc8:  90 10 00 18  mov  %i0, %o0
a00ebdcc:  d2 04 80 13  ld  [ %l2 + %l3 ], %o1
a00ebdd0:  d4 04 40 13  ld  [ %l1 + %l3 ], %o2
a00ebdd4:  d6 03 c0 13  ld  [ %o7 + %l3 ], %o3
a00ebdd8:  7f ff d2 67  call  0xa00e0774
a00ebddc:  01 00 00 00  nop
a00ebde0:  90 10 00 18  mov  %i0, %o0
a00ebde4:  d2 07 a0 48  ld  [ %fp + 0x48 ], %o1
a00ebde8:  d4 07 a0 4c  ld  [ %fp + 0x4c ], %o2
a00ebdec:  7f ff e1 23  call  0xa00e4278
a00ebdf0:  d6 07 a0 60  ld  [ %fp + 0x60 ], %o3
a00ebdf4:  80 a2 20 01  cmp  %o0, 1
a00ebdf8:  12 80 01 4c  bne  0xa00ec328
a00ebdfc:  80 a6 ff ff  cmp  %i3, -1
a00ebe00:  02 80 00 ae  be  0xa00ec0b8
a00ebe04:  15 2a 00 99  sethi  %hi(0xa8026400), %o2
a00ebe08:  03 2a 00 ad  sethi  %hi(0xa802b400), %g1
a00ebe0c:  98 12 a3 58  or  %o2, 0x358, %o4
a00ebe10:  a4 10 62 e8  or  %g1, 0x2e8, %l2
a00ebe14:  90 10 00 18  mov  %i0, %o0
a00ebe18:  d2 06 40 13  ld  [ %i1 + %l3 ], %o1
a00ebe1c:  d4 03 00 13  ld  [ %o4 + %l3 ], %o2
a00ebe20:  7f ff d2 4d  call  0xa00e0754
a00ebe24:  d6 04 80 13  ld  [ %l2 + %l3 ], %o3
a00ebe28:  80 a2 20 07  cmp  %o0, 7
a00ebe2c:  32 bf ff c0  bne,a   0xa00ebd2c
a00ebe30:  80 a6 ff ff  cmp  %i3, -1
a00ebe34:  17 2a 00 99  sethi  %hi(0xa8026400), %o3
a00ebe38:  90 12 e3 98  or  %o3, 0x398, %o0	! 0xa8026798
a00ebe3c:  a2 16 a3 88  or  %i2, 0x388, %l1
a00ebe40:  a4 17 63 78  or  %i5, 0x378, %l2
a00ebe44:  d2 02 00 13  ld  [ %o0 + %l3 ], %o1
a00ebe48:  d4 04 40 13  ld  [ %l1 + %l3 ], %o2
a00ebe4c:  d6 04 80 13  ld  [ %l2 + %l3 ], %o3
a00ebe50:  7f ff d2 41  call  0xa00e0754
a00ebe54:  90 10 00 18  mov  %i0, %o0
a00ebe58:  13 2a 00 99  sethi  %hi(0xa8026400), %o1
a00ebe5c:  98 02 20 01  add  %o0, 1, %o4
a00ebe60:  9a 12 63 98  or  %o1, 0x398, %o5
a00ebe64:  d4 04 40 13  ld  [ %l1 + %l3 ], %o2
a00ebe68:  d6 04 80 13  ld  [ %l2 + %l3 ], %o3
a00ebe6c:  d2 03 40 13  ld  [ %o5 + %l3 ], %o1
a00ebe70:  7f ff d2 41  call  0xa00e0774
a00ebe74:  90 10 00 18  mov  %i0, %o0
a00ebe78:  a0 15 23 48  or  %l4, 0x348, %l0
a00ebe7c:  a2 15 63 38  or  %l5, 0x338, %l1
a00ebe80:  a4 15 a3 28  or  %l6, 0x328, %l2
a00ebe84:  d2 04 00 13  ld  [ %l0 + %l3 ], %o1
a00ebe88:  d4 04 40 13  ld  [ %l1 + %l3 ], %o2
a00ebe8c:  d6 04 80 13  ld  [ %l2 + %l3 ], %o3
a00ebe90:  7f ff d2 31  call  0xa00e0754
a00ebe94:  90 10 00 18  mov  %i0, %o0
a00ebe98:  98 02 20 01  add  %o0, 1, %o4
a00ebe9c:  d2 04 00 13  ld  [ %l0 + %l3 ], %o1
a00ebea0:  d4 04 40 13  ld  [ %l1 + %l3 ], %o2
a00ebea4:  d6 04 80 13  ld  [ %l2 + %l3 ], %o3
a00ebea8:  7f ff d2 33  call  0xa00e0774
a00ebeac:  90 10 00 18  mov  %i0, %o0
a00ebeb0:  10 bf ff 9f  b  0xa00ebd2c
a00ebeb4:  80 a6 ff ff  cmp  %i3, -1
a00ebeb8:  92 16 60 e8  or  %i1, 0xe8, %o1
a00ebebc:  94 15 e0 d8  or  %l7, 0xd8, %o2
a00ebec0:  96 16 a0 c8  or  %i2, 0xc8, %o3
a00ebec4:  7f ff d2 24  call  0xa00e0754
a00ebec8:  90 10 00 18  mov  %i0, %o0
a00ebecc:  98 02 3f ff  add  %o0, -1, %o4
a00ebed0:  90 10 00 18  mov  %i0, %o0
a00ebed4:  92 16 60 e8  or  %i1, 0xe8, %o1
a00ebed8:  94 15 e0 d8  or  %l7, 0xd8, %o2
a00ebedc:  7f ff d2 26  call  0xa00e0774
a00ebee0:  96 16 a0 c8  or  %i2, 0xc8, %o3
a00ebee4:  17 2a 00 9a  sethi  %hi(0xa8026800), %o3
a00ebee8:  94 12 e0 a8  or  %o3, 0xa8, %o2	! 0xa80268a8
a00ebeec:  1f 2a 00 9a  sethi  %hi(0xa8026800), %o7
a00ebef0:  92 15 a0 b8  or  %l6, 0xb8, %o1
a00ebef4:  96 13 e0 98  or  %o7, 0x98, %o3
a00ebef8:  7f ff d2 17  call  0xa00e0754
a00ebefc:  90 10 00 18  mov  %i0, %o0
a00ebf00:  98 02 3f ff  add  %o0, -1, %o4
a00ebf04:  1b 2a 00 9a  sethi  %hi(0xa8026800), %o5
a00ebf08:  03 2a 00 9a  sethi  %hi(0xa8026800), %g1
a00ebf0c:  90 10 00 18  mov  %i0, %o0
a00ebf10:  92 15 a0 b8  or  %l6, 0xb8, %o1
a00ebf14:  94 13 60 a8  or  %o5, 0xa8, %o2
a00ebf18:  10 bf ff 0b  b  0xa00ebb44
a00ebf1c:  96 10 60 98  or  %g1, 0x98, %o3
a00ebf20:  11 2a 00 9a  sethi  %hi(0xa8026800), %o0
a00ebf24:  13 2a 00 9a  sethi  %hi(0xa8026800), %o1
a00ebf28:  15 2a 00 9a  sethi  %hi(0xa8026800), %o2
a00ebf2c:  96 12 21 28  or  %o0, 0x128, %o3
a00ebf30:  92 12 61 48  or  %o1, 0x148, %o1
a00ebf34:  94 12 a1 38  or  %o2, 0x138, %o2
a00ebf38:  10 bf ff 13  b  0xa00ebb84
a00ebf3c:  90 10 00 18  mov  %i0, %o0
a00ebf40:  19 2a 00 9a  sethi  %hi(0xa8026800), %o4
a00ebf44:  11 2a 00 9a  sethi  %hi(0xa8026800), %o0
a00ebf48:  13 2a 00 9a  sethi  %hi(0xa8026800), %o1
a00ebf4c:  94 13 21 38  or  %o4, 0x138, %o2
a00ebf50:  96 12 21 28  or  %o0, 0x128, %o3
a00ebf54:  92 12 61 48  or  %o1, 0x148, %o1
a00ebf58:  90 10 00 18  mov  %i0, %o0
a00ebf5c:  10 bf ff 2b  b  0xa00ebc08
a00ebf60:  98 10 20 00  clr  %o4
a00ebf64:  90 10 00 18  mov  %i0, %o0
a00ebf68:  92 15 e3 98  or  %l7, 0x398, %o1
a00ebf6c:  94 16 a3 88  or  %i2, 0x388, %o2
a00ebf70:  7f ff d1 f9  call  0xa00e0754
a00ebf74:  96 17 63 78  or  %i5, 0x378, %o3
a00ebf78:  80 a2 20 0f  cmp  %o0, 0xf
a00ebf7c:  02 bf ff 69  be  0xa00ebd20
a00ebf80:  03 2a 00 99  sethi  %hi(0xa8026400), %g1
a00ebf84:  92 15 e3 98  or  %l7, 0x398, %o1
a00ebf88:  94 16 a3 88  or  %i2, 0x388, %o2
a00ebf8c:  96 17 63 78  or  %i5, 0x378, %o3
a00ebf90:  7f ff d1 f1  call  0xa00e0754
a00ebf94:  90 10 00 18  mov  %i0, %o0
a00ebf98:  98 02 20 01  add  %o0, 1, %o4
a00ebf9c:  90 10 00 18  mov  %i0, %o0
a00ebfa0:  92 15 e3 98  or  %l7, 0x398, %o1
a00ebfa4:  94 16 a3 88  or  %i2, 0x388, %o2
a00ebfa8:  7f ff d1 f3  call  0xa00e0774
a00ebfac:  96 17 63 78  or  %i5, 0x378, %o3
a00ebfb0:  92 15 23 48  or  %l4, 0x348, %o1
a00ebfb4:  94 15 63 38  or  %l5, 0x338, %o2
a00ebfb8:  96 15 a3 28  or  %l6, 0x328, %o3
a00ebfbc:  7f ff d1 e6  call  0xa00e0754
a00ebfc0:  90 10 00 18  mov  %i0, %o0
a00ebfc4:  98 02 20 01  add  %o0, 1, %o4
a00ebfc8:  90 10 00 18  mov  %i0, %o0
a00ebfcc:  92 15 23 48  or  %l4, 0x348, %o1
a00ebfd0:  94 15 63 38  or  %l5, 0x338, %o2
a00ebfd4:  10 bf ff 3b  b  0xa00ebcc0
a00ebfd8:  96 15 a3 28  or  %l6, 0x328, %o3
a00ebfdc:  2f 2a 00 99  sethi  %hi(0xa8026400), %l7
a00ebfe0:  35 2a 00 99  sethi  %hi(0xa8026400), %i2
a00ebfe4:  80 a2 20 01  cmp  %o0, 1
a00ebfe8:  02 bf ff 14  be  0xa00ebc38
a00ebfec:  3b 2a 00 99  sethi  %hi(0xa8026400), %i5
a00ebff0:  80 a6 ff ff  cmp  %i3, -1
a00ebff4:  02 80 00 74  be  0xa00ec1c4
a00ebff8:  a1 2e e0 02  sll  %i3, 2, %l0
a00ebffc:  03 2a 00 9a  sethi  %hi(0xa8026800), %g1
a00ec000:  13 2a 00 9a  sethi  %hi(0xa8026800), %o1
a00ec004:  15 2a 00 9a  sethi  %hi(0xa8026800), %o2
a00ec008:  9a 12 60 e8  or  %o1, 0xe8, %o5
a00ec00c:  98 12 a0 d8  or  %o2, 0xd8, %o4
a00ec010:  9e 10 60 c8  or  %g1, 0xc8, %o7
a00ec014:  d2 03 40 10  ld  [ %o5 + %l0 ], %o1
a00ec018:  d4 03 00 10  ld  [ %o4 + %l0 ], %o2
a00ec01c:  d6 03 c0 10  ld  [ %o7 + %l0 ], %o3
a00ec020:  90 10 00 18  mov  %i0, %o0
a00ec024:  27 2a 00 9a  sethi  %hi(0xa8026800), %l3
a00ec028:  37 2a 00 9a  sethi  %hi(0xa8026800), %i3
a00ec02c:  7f ff d1 ca  call  0xa00e0754
a00ec030:  2b 2a 00 9a  sethi  %hi(0xa8026800), %l5
a00ec034:  b2 14 e0 b8  or  %l3, 0xb8, %i1
a00ec038:  ac 16 e0 a8  or  %i3, 0xa8, %l6
a00ec03c:  a8 15 60 98  or  %l5, 0x98, %l4
a00ec040:  d2 06 40 10  ld  [ %i1 + %l0 ], %o1
a00ec044:  d4 05 80 10  ld  [ %l6 + %l0 ], %o2
a00ec048:  d6 05 00 10  ld  [ %l4 + %l0 ], %o3
a00ec04c:  7f ff d1 c2  call  0xa00e0754
a00ec050:  90 10 00 18  mov  %i0, %o0
a00ec054:  90 16 a3 88  or  %i2, 0x388, %o0
a00ec058:  96 15 e3 98  or  %l7, 0x398, %o3
a00ec05c:  a2 17 63 78  or  %i5, 0x378, %l1
a00ec060:  d2 02 c0 10  ld  [ %o3 + %l0 ], %o1
a00ec064:  d4 02 00 10  ld  [ %o0 + %l0 ], %o2
a00ec068:  d6 04 40 10  ld  [ %l1 + %l0 ], %o3
a00ec06c:  7f ff d1 ba  call  0xa00e0754
a00ec070:  90 10 00 18  mov  %i0, %o0
a00ec074:  1b 2a 00 ad  sethi  %hi(0xa802b400), %o5
a00ec078:  13 2a 00 99  sethi  %hi(0xa8026400), %o1
a00ec07c:  94 13 62 e8  or  %o5, 0x2e8, %o2
a00ec080:  25 2a 00 99  sethi  %hi(0xa8026400), %l2
a00ec084:  b4 12 63 58  or  %o1, 0x358, %i2
a00ec088:  a2 10 00 08  mov  %o0, %l1
a00ec08c:  ba 14 a3 68  or  %l2, 0x368, %i5
a00ec090:  d6 02 80 10  ld  [ %o2 + %l0 ], %o3
a00ec094:  90 10 00 18  mov  %i0, %o0
a00ec098:  d2 07 40 10  ld  [ %i5 + %l0 ], %o1
a00ec09c:  d4 06 80 10  ld  [ %i2 + %l0 ], %o2
a00ec0a0:  af 2f 20 08  sll  %i4, 8, %l7
a00ec0a4:  7f ff d1 ac  call  0xa00e0754
a00ec0a8:  b9 2c 60 03  sll  %l1, 3, %i4
a00ec0ac:  b0 15 c0 1c  or  %l7, %i4, %i0
a00ec0b0:  10 80 00 a2  b  0xa00ec338
a00ec0b4:  82 16 00 08  or  %i0, %o0, %g1
a00ec0b8:  1f 2a 00 ad  sethi  %hi(0xa802b400), %o7
a00ec0bc:  23 2a 00 99  sethi  %hi(0xa8026400), %l1
a00ec0c0:  21 2a 00 99  sethi  %hi(0xa8026400), %l0
a00ec0c4:  90 10 00 18  mov  %i0, %o0
a00ec0c8:  92 14 63 68  or  %l1, 0x368, %o1
a00ec0cc:  96 13 e2 e8  or  %o7, 0x2e8, %o3
a00ec0d0:  7f ff d1 a1  call  0xa00e0754
a00ec0d4:  94 14 23 58  or  %l0, 0x358, %o2
a00ec0d8:  80 a2 20 07  cmp  %o0, 7
a00ec0dc:  32 80 00 19  bne,a   0xa00ec140
a00ec0e0:  17 2a 00 99  sethi  %hi(0xa8026400), %o3
a00ec0e4:  92 15 e3 98  or  %l7, 0x398, %o1
a00ec0e8:  94 16 a3 88  or  %i2, 0x388, %o2
a00ec0ec:  96 17 63 78  or  %i5, 0x378, %o3
a00ec0f0:  7f ff d1 99  call  0xa00e0754
a00ec0f4:  90 10 00 18  mov  %i0, %o0
a00ec0f8:  98 02 20 01  add  %o0, 1, %o4
a00ec0fc:  90 10 00 18  mov  %i0, %o0
a00ec100:  92 15 e3 98  or  %l7, 0x398, %o1
a00ec104:  94 16 a3 88  or  %i2, 0x388, %o2
a00ec108:  7f ff d1 9b  call  0xa00e0774
a00ec10c:  96 17 63 78  or  %i5, 0x378, %o3
a00ec110:  92 15 23 48  or  %l4, 0x348, %o1
a00ec114:  94 15 63 38  or  %l5, 0x338, %o2
a00ec118:  96 15 a3 28  or  %l6, 0x328, %o3
a00ec11c:  7f ff d1 8e  call  0xa00e0754
a00ec120:  90 10 00 18  mov  %i0, %o0
a00ec124:  98 02 20 01  add  %o0, 1, %o4
a00ec128:  90 10 00 18  mov  %i0, %o0
a00ec12c:  92 15 23 48  or  %l4, 0x348, %o1
a00ec130:  94 15 63 38  or  %l5, 0x338, %o2
a00ec134:  7f ff d1 90  call  0xa00e0774
a00ec138:  96 15 a3 28  or  %l6, 0x328, %o3
a00ec13c:  17 2a 00 99  sethi  %hi(0xa8026400), %o3
a00ec140:  92 12 e3 68  or  %o3, 0x368, %o1	! 0xa8026768
a00ec144:  11 2a 00 ad  sethi  %hi(0xa802b400), %o0
a00ec148:  1b 2a 00 99  sethi  %hi(0xa8026400), %o5
a00ec14c:  96 12 22 e8  or  %o0, 0x2e8, %o3
a00ec150:  94 13 63 58  or  %o5, 0x358, %o2
a00ec154:  7f ff d1 80  call  0xa00e0754
a00ec158:  90 10 00 18  mov  %i0, %o0
a00ec15c:  98 02 20 01  add  %o0, 1, %o4
a00ec160:  03 2a 00 99  sethi  %hi(0xa8026400), %g1
a00ec164:  25 2a 00 99  sethi  %hi(0xa8026400), %l2
a00ec168:  23 2a 00 ad  sethi  %hi(0xa802b400), %l1
a00ec16c:  92 10 63 68  or  %g1, 0x368, %o1
a00ec170:  90 10 00 18  mov  %i0, %o0
a00ec174:  94 14 a3 58  or  %l2, 0x358, %o2
a00ec178:  7f ff d1 7f  call  0xa00e0774
a00ec17c:  96 14 62 e8  or  %l1, 0x2e8, %o3
a00ec180:  19 2a 00 ad  sethi  %hi(0xa802b400), %o4
a00ec184:  1f 2a 00 99  sethi  %hi(0xa8026400), %o7
a00ec188:  21 2a 00 99  sethi  %hi(0xa8026400), %l0
a00ec18c:  96 13 22 d8  or  %o4, 0x2d8, %o3
a00ec190:  92 14 23 18  or  %l0, 0x318, %o1
a00ec194:  94 13 e3 08  or  %o7, 0x308, %o2
a00ec198:  7f ff d1 6f  call  0xa00e0754
a00ec19c:  90 10 00 18  mov  %i0, %o0
a00ec1a0:  15 2a 00 99  sethi  %hi(0xa8026400), %o2
a00ec1a4:  17 2a 00 99  sethi  %hi(0xa8026400), %o3
a00ec1a8:  92 12 a3 18  or  %o2, 0x318, %o1
a00ec1ac:  98 02 20 01  add  %o0, 1, %o4
a00ec1b0:  94 12 e3 08  or  %o3, 0x308, %o2
a00ec1b4:  1b 2a 00 ad  sethi  %hi(0xa802b400), %o5
a00ec1b8:  90 10 00 18  mov  %i0, %o0
a00ec1bc:  10 bf ff 07  b  0xa00ebdd8
a00ec1c0:  96 13 62 d8  or  %o5, 0x2d8, %o3
a00ec1c4:  19 2a 00 9a  sethi  %hi(0xa8026800), %o4
a00ec1c8:  03 2a 00 9a  sethi  %hi(0xa8026800), %g1
a00ec1cc:  1f 2a 00 9a  sethi  %hi(0xa8026800), %o7
a00ec1d0:  92 13 20 e8  or  %o4, 0xe8, %o1
a00ec1d4:  94 10 60 d8  or  %g1, 0xd8, %o2
a00ec1d8:  96 13 e0 c8  or  %o7, 0xc8, %o3
a00ec1dc:  7f ff d1 5e  call  0xa00e0754
a00ec1e0:  90 10 00 18  mov  %i0, %o0
a00ec1e4:  27 2a 00 9a  sethi  %hi(0xa8026800), %l3
a00ec1e8:  33 2a 00 9a  sethi  %hi(0xa8026800), %i1
a00ec1ec:  37 2a 00 9a  sethi  %hi(0xa8026800), %i3
a00ec1f0:  92 14 e0 b8  or  %l3, 0xb8, %o1
a00ec1f4:  94 16 60 a8  or  %i1, 0xa8, %o2
a00ec1f8:  96 16 e0 98  or  %i3, 0x98, %o3
a00ec1fc:  7f ff d1 56  call  0xa00e0754
a00ec200:  90 10 00 18  mov  %i0, %o0
a00ec204:  92 15 e3 98  or  %l7, 0x398, %o1
a00ec208:  94 16 a3 88  or  %i2, 0x388, %o2
a00ec20c:  96 17 63 78  or  %i5, 0x378, %o3
a00ec210:  7f ff d1 51  call  0xa00e0754
a00ec214:  90 10 00 18  mov  %i0, %o0
a00ec218:  a2 10 00 08  mov  %o0, %l1
a00ec21c:  2f 2a 00 99  sethi  %hi(0xa8026400), %l7
a00ec220:  2d 2a 00 99  sethi  %hi(0xa8026400), %l6
a00ec224:  2b 2a 00 ad  sethi  %hi(0xa802b400), %l5
a00ec228:  90 10 00 18  mov  %i0, %o0
a00ec22c:  92 15 e3 68  or  %l7, 0x368, %o1
a00ec230:  94 15 a3 58  or  %l6, 0x358, %o2
a00ec234:  10 bf ff 9b  b  0xa00ec0a0
a00ec238:  96 15 62 e8  or  %l5, 0x2e8, %o3
a00ec23c:  80 a2 20 00  cmp  %o0, 0
a00ec240:  12 bf fe 5e  bne  0xa00ebbb8
a00ec244:  80 a6 ff ff  cmp  %i3, -1
a00ec248:  02 80 00 20  be  0xa00ec2c8
a00ec24c:  a1 2e e0 02  sll  %i3, 2, %l0
a00ec250:  a6 15 e3 98  or  %l7, 0x398, %l3
a00ec254:  b2 17 63 78  or  %i5, 0x378, %i1
a00ec258:  a4 16 a3 88  or  %i2, 0x388, %l2
a00ec25c:  d2 04 c0 10  ld  [ %l3 + %l0 ], %o1
a00ec260:  d6 06 40 10  ld  [ %i1 + %l0 ], %o3
a00ec264:  d4 04 80 10  ld  [ %l2 + %l0 ], %o2
a00ec268:  7f ff d1 3b  call  0xa00e0754
a00ec26c:  90 10 00 18  mov  %i0, %o0
a00ec270:  98 02 3f ff  add  %o0, -1, %o4
a00ec274:  d2 04 c0 10  ld  [ %l3 + %l0 ], %o1
a00ec278:  d6 06 40 10  ld  [ %i1 + %l0 ], %o3
a00ec27c:  d4 04 80 10  ld  [ %l2 + %l0 ], %o2
a00ec280:  7f ff d1 3d  call  0xa00e0774
a00ec284:  90 10 00 18  mov  %i0, %o0
a00ec288:  a6 15 23 48  or  %l4, 0x348, %l3
a00ec28c:  b2 15 63 38  or  %l5, 0x338, %i1
a00ec290:  a2 15 a3 28  or  %l6, 0x328, %l1
a00ec294:  d2 04 c0 10  ld  [ %l3 + %l0 ], %o1
a00ec298:  d4 06 40 10  ld  [ %i1 + %l0 ], %o2
a00ec29c:  d6 04 40 10  ld  [ %l1 + %l0 ], %o3
a00ec2a0:  7f ff d1 2d  call  0xa00e0754
a00ec2a4:  90 10 00 18  mov  %i0, %o0
a00ec2a8:  98 02 3f ff  add  %o0, -1, %o4
a00ec2ac:  d6 04 40 10  ld  [ %l1 + %l0 ], %o3
a00ec2b0:  d2 04 c0 10  ld  [ %l3 + %l0 ], %o1
a00ec2b4:  d4 06 40 10  ld  [ %i1 + %l0 ], %o2
a00ec2b8:  7f ff d1 2f  call  0xa00e0774
a00ec2bc:  90 10 00 18  mov  %i0, %o0
a00ec2c0:  10 bf fe 98  b  0xa00ebd20
a00ec2c4:  03 2a 00 99  sethi  %hi(0xa8026400), %g1
a00ec2c8:  92 15 e3 98  or  %l7, 0x398, %o1
a00ec2cc:  94 16 a3 88  or  %i2, 0x388, %o2
a00ec2d0:  96 17 63 78  or  %i5, 0x378, %o3
a00ec2d4:  7f ff d1 20  call  0xa00e0754
a00ec2d8:  90 10 00 18  mov  %i0, %o0
a00ec2dc:  98 02 3f ff  add  %o0, -1, %o4
a00ec2e0:  90 10 00 18  mov  %i0, %o0
a00ec2e4:  92 15 e3 98  or  %l7, 0x398, %o1
a00ec2e8:  94 16 a3 88  or  %i2, 0x388, %o2
a00ec2ec:  7f ff d1 22  call  0xa00e0774
a00ec2f0:  96 17 63 78  or  %i5, 0x378, %o3
a00ec2f4:  92 15 23 48  or  %l4, 0x348, %o1
a00ec2f8:  94 15 63 38  or  %l5, 0x338, %o2
a00ec2fc:  96 15 a3 28  or  %l6, 0x328, %o3
a00ec300:  7f ff d1 15  call  0xa00e0754
a00ec304:  90 10 00 18  mov  %i0, %o0
a00ec308:  98 02 3f ff  add  %o0, -1, %o4
a00ec30c:  90 10 00 18  mov  %i0, %o0
a00ec310:  92 15 23 48  or  %l4, 0x348, %o1
a00ec314:  94 15 63 38  or  %l5, 0x338, %o2
a00ec318:  7f ff d1 17  call  0xa00e0774
a00ec31c:  96 15 a3 28  or  %l6, 0x328, %o3
a00ec320:  10 bf fe 80  b  0xa00ebd20
a00ec324:  03 2a 00 99  sethi  %hi(0xa8026400), %g1
a00ec328:  80 a2 20 00  cmp  %o0, 0
a00ec32c:  02 bf ff 32  be  0xa00ebff4
a00ec330:  80 a6 ff ff  cmp  %i3, -1
a00ec334:  30 bf fe 21  b,a   0xa00ebbb8
a00ec338:  81 c7 e0 08  ret
a00ec33c:  91 e8 00 01  restore  %g0, %g1, %o0
