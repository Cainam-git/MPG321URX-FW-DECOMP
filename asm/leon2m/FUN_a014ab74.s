# leon2m FUN_a014ab74 0xa014ab74-0xa014ac28 (180 bytes)
a014ab74:  9d e3 bf 90  save  %sp, -112, %sp
a014ab78:  b0 0e 20 ff  and  %i0, 0xff, %i0
a014ab7c:  96 10 00 19  mov  %i1, %o3
a014ab80:  80 8e 20 f0  btst  0xf0, %i0
a014ab84:  a0 10 20 00  clr  %l0
a014ab88:  12 80 00 05  bne  0xa014ab9c
a014ab8c:  82 10 3f ff  mov  -1, %g1
a014ab90:  80 a6 20 30  cmp  %i0, 0x30
a014ab94:  22 80 00 1f  be,a   0xa014ac10
a014ab98:  03 3f ff e0  sethi  %hi(0xffff8000), %g1
a014ab9c:  c2 2f bf f0  stb  %g1, [ %fp + -16 ]
a014aba0:  c0 37 bf f2  clrh  [ %fp + -14 ]
a014aba4:  d0 0f bf f0  ldub  [ %fp + -16 ], %o0
a014aba8:  80 a2 20 ff  cmp  %o0, 0xff
a014abac:  02 80 00 0a  be  0xa014abd4
a014abb0:  95 2e a0 10  sll  %i2, 0x10, %o2
a014abb4:  93 32 a0 10  srl  %o2, 0x10, %o1
a014abb8:  9f 2e e0 10  sll  %i3, 0x10, %o7
a014abbc:  95 33 e0 10  srl  %o7, 0x10, %o2
a014abc0:  98 02 40 0a  add  %o1, %o2, %o4
a014abc4:  da 17 bf f2  lduh  [ %fp + -14 ], %o5
a014abc8:  80 a3 00 0d  cmp  %o4, %o5
a014abcc:  04 80 00 09  ble  0xa014abf0
a014abd0:  01 00 00 00  nop
a014abd4:  7f fe 4a 90  call  0xa00dd614
a014abd8:  90 10 20 40  mov  0x40, %o0	! 0x40
a014abdc:  80 8a 20 ff  btst  0xff, %o0
a014abe0:  22 80 00 10  be,a   0xa014ac20
a014abe4:  b0 0c 20 01  and  %l0, 1, %i0
a014abe8:  10 80 00 06  b  0xa014ac00
a014abec:  11 00 06 9c  sethi  %hi(0x1a7000), %o0
a014abf0:  7f ff d8 a1  call  0xa0140e74
a014abf4:  98 10 20 00  clr  %o4
a014abf8:  10 80 00 09  b  0xa014ac1c
a014abfc:  a0 10 20 01  mov  1, %l0
a014ac00:  7f fe 51 5c  call  0xa00df170
a014ac04:  90 12 20 c0  or  %o0, 0xc0, %o0
a014ac08:  10 80 00 06  b  0xa014ac20
a014ac0c:  b0 0c 20 01  and  %l0, 1, %i0
a014ac10:  c2 37 bf f2  sth  %g1, [ %fp + -14 ]
a014ac14:  10 bf ff e4  b  0xa014aba4
a014ac18:  c0 2f bf f0  clrb  [ %fp + -16 ]
a014ac1c:  b0 0c 20 01  and  %l0, 1, %i0
a014ac20:  81 c7 e0 08  ret
a014ac24:  81 e8 00 00  restore
