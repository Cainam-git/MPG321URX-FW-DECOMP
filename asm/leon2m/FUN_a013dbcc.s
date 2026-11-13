# leon2m FUN_a013dbcc 0xa013dbcc-0xa013dc6c (160 bytes)
a013dbcc:  9d e3 bf 88  save  %sp, -120, %sp
a013dbd0:  7f fe ff 14  call  0xa00fd820
a013dbd4:  90 0e 20 ff  and  %i0, 0xff, %o0
a013dbd8:  90 0a 20 ff  and  %o0, 0xff, %o0
a013dbdc:  80 a2 20 61  cmp  %o0, 0x61
a013dbe0:  22 80 00 0c  be,a   0xa013dc10
a013dbe4:  90 10 20 01  mov  1, %o0
a013dbe8:  04 80 00 08  ble  0xa013dc08
a013dbec:  80 a2 20 51  cmp  %o0, 0x51
a013dbf0:  80 a2 20 71  cmp  %o0, 0x71
a013dbf4:  02 80 00 1a  be  0xa013dc5c
a013dbf8:  80 a2 20 81  cmp  %o0, 0x81
a013dbfc:  12 80 00 1a  bne  0xa013dc64
a013dc00:  90 10 20 03  mov  3, %o0
a013dc04:  30 80 00 03  b,a   0xa013dc10
a013dc08:  12 80 00 17  bne  0xa013dc64
a013dc0c:  90 10 20 00  clr  %o0
a013dc10:  7f ff ed 0c  call  0xa0139040
a013dc14:  92 07 bf e8  add  %fp, -24, %o1
a013dc18:  da 17 bf e8  lduh  [ %fp + -24 ], %o5
a013dc1c:  d8 17 bf ea  lduh  [ %fp + -22 ], %o4
a013dc20:  d6 17 bf ec  lduh  [ %fp + -20 ], %o3
a013dc24:  d4 17 bf ee  lduh  [ %fp + -18 ], %o2
a013dc28:  d2 17 bf f0  lduh  [ %fp + -16 ], %o1
a013dc2c:  d0 17 bf f2  lduh  [ %fp + -14 ], %o0
a013dc30:  de 17 bf f4  lduh  [ %fp + -12 ], %o7
a013dc34:  c2 17 bf f6  lduh  [ %fp + -10 ], %g1
a013dc38:  c2 36 a0 0e  sth  %g1, [ %i2 + 0xe ]
a013dc3c:  da 36 80 00  sth  %o5, [ %i2 ]
a013dc40:  d8 36 a0 02  sth  %o4, [ %i2 + 2 ]
a013dc44:  d6 36 a0 04  sth  %o3, [ %i2 + 4 ]
a013dc48:  d4 36 a0 06  sth  %o2, [ %i2 + 6 ]
a013dc4c:  d2 36 a0 08  sth  %o1, [ %i2 + 8 ]
a013dc50:  d0 36 a0 0a  sth  %o0, [ %i2 + 0xa ]
a013dc54:  10 80 00 04  b  0xa013dc64
a013dc58:  de 36 a0 0c  sth  %o7, [ %i2 + 0xc ]
a013dc5c:  10 bf ff ed  b  0xa013dc10
a013dc60:  90 10 20 02  mov  2, %o0
a013dc64:  81 c7 e0 08  ret
a013dc68:  81 e8 00 00  restore
