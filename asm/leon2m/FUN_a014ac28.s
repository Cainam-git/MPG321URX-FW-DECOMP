# leon2m FUN_a014ac28 0xa014ac28-0xa014acdc (180 bytes)
a014ac28:  9d e3 bf 90  save  %sp, -112, %sp
a014ac2c:  b0 0e 20 ff  and  %i0, 0xff, %i0
a014ac30:  82 0e 20 f0  and  %i0, 0xf0, %g1
a014ac34:  80 a0 60 10  cmp  %g1, 0x10
a014ac38:  96 10 00 19  mov  %i1, %o3
a014ac3c:  a0 10 20 00  clr  %l0
a014ac40:  02 80 00 17  be  0xa014ac9c
a014ac44:  82 10 3f ff  mov  -1, %g1
a014ac48:  c2 2f bf f0  stb  %g1, [ %fp + -16 ]
a014ac4c:  c0 37 bf f2  clrh  [ %fp + -14 ]
a014ac50:  d0 0f bf f0  ldub  [ %fp + -16 ], %o0
a014ac54:  80 a2 20 ff  cmp  %o0, 0xff
a014ac58:  02 80 00 0a  be  0xa014ac80
a014ac5c:  95 2e a0 10  sll  %i2, 0x10, %o2
a014ac60:  93 32 a0 10  srl  %o2, 0x10, %o1
a014ac64:  9f 2e e0 10  sll  %i3, 0x10, %o7
a014ac68:  95 33 e0 10  srl  %o7, 0x10, %o2
a014ac6c:  98 02 40 0a  add  %o1, %o2, %o4
a014ac70:  da 17 bf f2  lduh  [ %fp + -14 ], %o5
a014ac74:  80 a3 00 0d  cmp  %o4, %o5
a014ac78:  04 80 00 10  ble  0xa014acb8
a014ac7c:  01 00 00 00  nop
a014ac80:  7f fe 4a 65  call  0xa00dd614
a014ac84:  90 10 20 40  mov  0x40, %o0	! 0x40
a014ac88:  80 8a 20 ff  btst  0xff, %o0
a014ac8c:  02 80 00 12  be  0xa014acd4
a014ac90:  b0 0c 20 01  and  %l0, 1, %i0
a014ac94:  10 80 00 0d  b  0xa014acc8
a014ac98:  13 00 06 9c  sethi  %hi(0x1a7000), %o1
a014ac9c:  80 a6 20 30  cmp  %i0, 0x30
a014aca0:  32 bf ff eb  bne,a   0xa014ac4c
a014aca4:  c2 2f bf f0  stb  %g1, [ %fp + -16 ]
a014aca8:  11 3f ff e0  sethi  %hi(0xffff8000), %o0
a014acac:  d0 37 bf f2  sth  %o0, [ %fp + -14 ]
a014acb0:  10 bf ff e8  b  0xa014ac50
a014acb4:  c0 2f bf f0  clrb  [ %fp + -16 ]
a014acb8:  7f ff d5 aa  call  0xa0140360
a014acbc:  a0 10 20 01  mov  1, %l0
a014acc0:  10 80 00 05  b  0xa014acd4
a014acc4:  b0 0c 20 01  and  %l0, 1, %i0
a014acc8:  7f fe 51 2a  call  0xa00df170
a014accc:  90 12 61 10  or  %o1, 0x110, %o0
a014acd0:  b0 0c 20 01  and  %l0, 1, %i0
a014acd4:  81 c7 e0 08  ret
a014acd8:  81 e8 00 00  restore
