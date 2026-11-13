# leon2m FUN_a014aaa0 0xa014aaa0-0xa014ab74 (212 bytes)
a014aaa0:  9d e3 bf 90  save  %sp, -112, %sp
a014aaa4:  b0 0e 20 ff  and  %i0, 0xff, %i0
a014aaa8:  80 8e 20 f0  btst  0xf0, %i0
a014aaac:  a0 10 20 00  clr  %l0
a014aab0:  12 80 00 05  bne  0xa014aac4
a014aab4:  82 10 3f ff  mov  -1, %g1
a014aab8:  80 a6 20 30  cmp  %i0, 0x30
a014aabc:  22 80 00 29  be,a   0xa014ab60
a014aac0:  03 3f ff e0  sethi  %hi(0xffff8000), %g1
a014aac4:  c2 2f bf f0  stb  %g1, [ %fp + -16 ]
a014aac8:  c0 37 bf f2  clrh  [ %fp + -14 ]
a014aacc:  d0 0f bf f0  ldub  [ %fp + -16 ], %o0
a014aad0:  80 a2 20 ff  cmp  %o0, 0xff
a014aad4:  02 80 00 0a  be  0xa014aafc
a014aad8:  99 2e a0 10  sll  %i2, 0x10, %o4
a014aadc:  97 2e e0 10  sll  %i3, 0x10, %o3
a014aae0:  95 33 20 10  srl  %o4, 0x10, %o2
a014aae4:  b7 32 e0 10  srl  %o3, 0x10, %i3
a014aae8:  92 02 80 1b  add  %o2, %i3, %o1
a014aaec:  da 17 bf f2  lduh  [ %fp + -14 ], %o5
a014aaf0:  80 a2 40 0d  cmp  %o1, %o5
a014aaf4:  04 80 00 09  ble  0xa014ab18
a014aaf8:  01 00 00 00  nop
a014aafc:  7f fe 4a c6  call  0xa00dd614
a014ab00:  90 10 20 40  mov  0x40, %o0	! 0x40
a014ab04:  80 8a 20 ff  btst  0xff, %o0
a014ab08:  22 80 00 19  be,a   0xa014ab6c
a014ab0c:  b0 0c 20 01  and  %l0, 1, %i0
a014ab10:  10 80 00 10  b  0xa014ab50
a014ab14:  11 00 06 9c  sethi  %hi(0x1a7000), %o0
a014ab18:  7f ff d5 fb  call  0xa0140304
a014ab1c:  01 00 00 00  nop
a014ab20:  9e 0a 20 ff  and  %o0, 0xff, %o7
a014ab24:  80 a3 e0 01  cmp  %o7, 1
a014ab28:  32 80 00 11  bne,a   0xa014ab6c
a014ab2c:  b0 0c 20 01  and  %l0, 1, %i0
a014ab30:  94 10 00 1b  mov  %i3, %o2
a014ab34:  96 10 00 19  mov  %i1, %o3
a014ab38:  a0 10 20 01  mov  1, %l0
a014ab3c:  d0 0f bf f0  ldub  [ %fp + -16 ], %o0
a014ab40:  7f ff d6 08  call  0xa0140360
a014ab44:  92 10 20 00  clr  %o1
a014ab48:  10 80 00 09  b  0xa014ab6c
a014ab4c:  b0 0c 20 01  and  %l0, 1, %i0
a014ab50:  7f fe 51 88  call  0xa00df170
a014ab54:  90 12 20 70  or  %o0, 0x70, %o0
a014ab58:  10 80 00 05  b  0xa014ab6c
a014ab5c:  b0 0c 20 01  and  %l0, 1, %i0
a014ab60:  c2 37 bf f2  sth  %g1, [ %fp + -14 ]
a014ab64:  10 bf ff da  b  0xa014aacc
a014ab68:  c0 2f bf f0  clrb  [ %fp + -16 ]
a014ab6c:  81 c7 e0 08  ret
a014ab70:  81 e8 00 00  restore
