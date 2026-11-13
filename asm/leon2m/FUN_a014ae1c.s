# leon2m FUN_a014ae1c 0xa014ae1c-0xa014aed0 (180 bytes)
a014ae1c:  9d e3 bf 90  save  %sp, -112, %sp
a014ae20:  b0 0e 20 ff  and  %i0, 0xff, %i0
a014ae24:  82 0e 20 f0  and  %i0, 0xf0, %g1
a014ae28:  80 a0 60 30  cmp  %g1, 0x30
a014ae2c:  96 10 00 19  mov  %i1, %o3
a014ae30:  a0 10 20 00  clr  %l0
a014ae34:  02 80 00 17  be  0xa014ae90
a014ae38:  82 10 3f ff  mov  -1, %g1
a014ae3c:  c2 2f bf f0  stb  %g1, [ %fp + -16 ]
a014ae40:  c0 37 bf f2  clrh  [ %fp + -14 ]
a014ae44:  d0 0f bf f0  ldub  [ %fp + -16 ], %o0
a014ae48:  80 a2 20 ff  cmp  %o0, 0xff
a014ae4c:  02 80 00 0a  be  0xa014ae74
a014ae50:  95 2e a0 10  sll  %i2, 0x10, %o2
a014ae54:  93 32 a0 10  srl  %o2, 0x10, %o1
a014ae58:  9f 2e e0 10  sll  %i3, 0x10, %o7
a014ae5c:  95 33 e0 10  srl  %o7, 0x10, %o2
a014ae60:  98 02 40 0a  add  %o1, %o2, %o4
a014ae64:  da 17 bf f2  lduh  [ %fp + -14 ], %o5
a014ae68:  80 a3 00 0d  cmp  %o4, %o5
a014ae6c:  04 80 00 10  ble  0xa014aeac
a014ae70:  01 00 00 00  nop
a014ae74:  7f fe 49 e8  call  0xa00dd614
a014ae78:  90 10 20 40  mov  0x40, %o0	! 0x40
a014ae7c:  80 8a 20 ff  btst  0xff, %o0
a014ae80:  02 80 00 12  be  0xa014aec8
a014ae84:  b0 0c 20 01  and  %l0, 1, %i0
a014ae88:  10 80 00 0d  b  0xa014aebc
a014ae8c:  13 00 06 9c  sethi  %hi(0x1a7000), %o1
a014ae90:  80 a6 20 30  cmp  %i0, 0x30
a014ae94:  32 bf ff eb  bne,a   0xa014ae40
a014ae98:  c2 2f bf f0  stb  %g1, [ %fp + -16 ]
a014ae9c:  11 3f ff e0  sethi  %hi(0xffff8000), %o0
a014aea0:  d0 37 bf f2  sth  %o0, [ %fp + -14 ]
a014aea4:  10 bf ff e8  b  0xa014ae44
a014aea8:  c0 2f bf f0  clrb  [ %fp + -16 ]
a014aeac:  7f ff d5 2d  call  0xa0140360
a014aeb0:  a0 10 20 01  mov  1, %l0
a014aeb4:  10 80 00 05  b  0xa014aec8
a014aeb8:  b0 0c 20 01  and  %l0, 1, %i0
a014aebc:  7f fe 50 ad  call  0xa00df170
a014aec0:  90 12 61 e8  or  %o1, 0x1e8, %o0
a014aec4:  b0 0c 20 01  and  %l0, 1, %i0
a014aec8:  81 c7 e0 08  ret
a014aecc:  81 e8 00 00  restore
