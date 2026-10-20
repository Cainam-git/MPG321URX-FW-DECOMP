# leon2m FUN_a014acdc 0xa014acdc-0xa014ad90 (180 bytes)
a014acdc:  9d e3 bf 90  save  %sp, -112, %sp
a014ace0:  b0 0e 20 ff  and  %i0, 0xff, %i0
a014ace4:  82 0e 20 f0  and  %i0, 0xf0, %g1
a014ace8:  80 a0 60 10  cmp  %g1, 0x10
a014acec:  96 10 00 19  mov  %i1, %o3
a014acf0:  a0 10 20 00  clr  %l0
a014acf4:  02 80 00 17  be  0xa014ad50
a014acf8:  82 10 3f ff  mov  -1, %g1
a014acfc:  c2 2f bf f0  stb  %g1, [ %fp + -16 ]
a014ad00:  c0 37 bf f2  clrh  [ %fp + -14 ]
a014ad04:  d0 0f bf f0  ldub  [ %fp + -16 ], %o0
a014ad08:  80 a2 20 ff  cmp  %o0, 0xff
a014ad0c:  02 80 00 0a  be  0xa014ad34
a014ad10:  95 2e a0 10  sll  %i2, 0x10, %o2
a014ad14:  93 32 a0 10  srl  %o2, 0x10, %o1
a014ad18:  9f 2e e0 10  sll  %i3, 0x10, %o7
a014ad1c:  95 33 e0 10  srl  %o7, 0x10, %o2
a014ad20:  98 02 40 0a  add  %o1, %o2, %o4
a014ad24:  da 17 bf f2  lduh  [ %fp + -14 ], %o5
a014ad28:  80 a3 00 0d  cmp  %o4, %o5
a014ad2c:  04 80 00 10  ble  0xa014ad6c
a014ad30:  01 00 00 00  nop
a014ad34:  7f fe 4a 38  call  0xa00dd614
a014ad38:  90 10 20 40  mov  0x40, %o0	! 0x40
a014ad3c:  80 8a 20 ff  btst  0xff, %o0
a014ad40:  02 80 00 12  be  0xa014ad88
a014ad44:  b0 0c 20 01  and  %l0, 1, %i0
a014ad48:  10 80 00 0d  b  0xa014ad7c
a014ad4c:  13 00 06 9c  sethi  %hi(0x1a7000), %o1
a014ad50:  80 a6 20 30  cmp  %i0, 0x30
a014ad54:  32 bf ff eb  bne,a   0xa014ad00
a014ad58:  c2 2f bf f0  stb  %g1, [ %fp + -16 ]
a014ad5c:  11 3f ff e0  sethi  %hi(0xffff8000), %o0
a014ad60:  d0 37 bf f2  sth  %o0, [ %fp + -14 ]
a014ad64:  10 bf ff e8  b  0xa014ad04
a014ad68:  c0 2f bf f0  clrb  [ %fp + -16 ]
a014ad6c:  7f ff d8 42  call  0xa0140e74
a014ad70:  98 10 20 00  clr  %o4
a014ad74:  10 80 00 04  b  0xa014ad84
a014ad78:  a0 10 20 01  mov  1, %l0
a014ad7c:  7f fe 50 fd  call  0xa00df170
a014ad80:  90 12 61 60  or  %o1, 0x160, %o0
a014ad84:  b0 0c 20 01  and  %l0, 1, %i0
a014ad88:  81 c7 e0 08  ret
a014ad8c:  81 e8 00 00  restore
