# leon2m FUN_a014aed0 0xa014aed0-0xa014af84 (180 bytes)
a014aed0:  9d e3 bf 90  save  %sp, -112, %sp
a014aed4:  b0 0e 20 ff  and  %i0, 0xff, %i0
a014aed8:  82 0e 20 f0  and  %i0, 0xf0, %g1
a014aedc:  80 a0 60 30  cmp  %g1, 0x30
a014aee0:  96 10 00 19  mov  %i1, %o3
a014aee4:  a0 10 20 00  clr  %l0
a014aee8:  02 80 00 17  be  0xa014af44
a014aeec:  82 10 3f ff  mov  -1, %g1
a014aef0:  c2 2f bf f0  stb  %g1, [ %fp + -16 ]
a014aef4:  c0 37 bf f2  clrh  [ %fp + -14 ]
a014aef8:  d0 0f bf f0  ldub  [ %fp + -16 ], %o0
a014aefc:  80 a2 20 ff  cmp  %o0, 0xff
a014af00:  02 80 00 0a  be  0xa014af28
a014af04:  95 2e a0 10  sll  %i2, 0x10, %o2
a014af08:  93 32 a0 10  srl  %o2, 0x10, %o1
a014af0c:  9f 2e e0 10  sll  %i3, 0x10, %o7
a014af10:  95 33 e0 10  srl  %o7, 0x10, %o2
a014af14:  98 02 40 0a  add  %o1, %o2, %o4
a014af18:  da 17 bf f2  lduh  [ %fp + -14 ], %o5
a014af1c:  80 a3 00 0d  cmp  %o4, %o5
a014af20:  04 80 00 10  ble  0xa014af60
a014af24:  01 00 00 00  nop
a014af28:  7f fe 49 bb  call  0xa00dd614
a014af2c:  90 10 20 40  mov  0x40, %o0	! 0x40
a014af30:  80 8a 20 ff  btst  0xff, %o0
a014af34:  02 80 00 12  be  0xa014af7c
a014af38:  b0 0c 20 01  and  %l0, 1, %i0
a014af3c:  10 80 00 0d  b  0xa014af70
a014af40:  13 00 06 9c  sethi  %hi(0x1a7000), %o1
a014af44:  80 a6 20 30  cmp  %i0, 0x30
a014af48:  32 bf ff eb  bne,a   0xa014aef4
a014af4c:  c2 2f bf f0  stb  %g1, [ %fp + -16 ]
a014af50:  11 3f ff e0  sethi  %hi(0xffff8000), %o0
a014af54:  d0 37 bf f2  sth  %o0, [ %fp + -14 ]
a014af58:  10 bf ff e8  b  0xa014aef8
a014af5c:  c0 2f bf f0  clrb  [ %fp + -16 ]
a014af60:  7f ff d7 c5  call  0xa0140e74
a014af64:  98 10 20 01  mov  1, %o4
a014af68:  10 80 00 04  b  0xa014af78
a014af6c:  a0 10 20 01  mov  1, %l0
a014af70:  7f fe 50 80  call  0xa00df170
a014af74:  90 12 62 30  or  %o1, 0x230, %o0
a014af78:  b0 0c 20 01  and  %l0, 1, %i0
a014af7c:  81 c7 e0 08  ret
a014af80:  81 e8 00 00  restore
