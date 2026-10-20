# leon2m FUN_a00bee64 0xa00bee64-0xa00bef90 (300 bytes)
a00bee64:  9d e3 bf 98  save  %sp, -104, %sp
a00bee68:  35 2a 00 b4  sethi  %hi(0xa802d000), %i2
a00bee6c:  a0 16 a0 78  or  %i2, 0x78, %l0	! 0xa802d078
a00bee70:  9a 10 20 30  mov  0x30, %o5
a00bee74:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00bee78:  da 2c 20 08  stb  %o5, [ %l0 + 8 ]
a00bee7c:  da 2c 20 07  stb  %o5, [ %l0 + 7 ]
a00bee80:  40 02 15 df  call  0xa01445fc
a00bee84:  d0 0a a2 b0  ldub  [ %o2 + 0x2b0 ], %o0
a00bee88:  92 02 20 30  add  %o0, 0x30, %o1
a00bee8c:  d2 2c 20 09  stb  %o1, [ %l0 + 9 ]
a00bee90:  92 10 20 00  clr  %o1
a00bee94:  40 02 55 ea  call  0xa015463c
a00bee98:  90 10 20 34  mov  0x34, %o0
a00bee9c:  d0 2e a0 78  stb  %o0, [ %i2 + 0x78 ]
a00beea0:  90 10 20 62  mov  0x62, %o0
a00beea4:  d0 2c 20 01  stb  %o0, [ %l0 + 1 ]
a00beea8:  92 10 20 02  mov  2, %o1
a00beeac:  40 02 55 e4  call  0xa015463c
a00beeb0:  90 10 20 34  mov  0x34, %o0
a00beeb4:  d0 2c 20 02  stb  %o0, [ %l0 + 2 ]
a00beeb8:  92 10 20 03  mov  3, %o1
a00beebc:  40 02 55 e0  call  0xa015463c
a00beec0:  90 10 20 34  mov  0x34, %o0
a00beec4:  d0 2c 20 03  stb  %o0, [ %l0 + 3 ]
a00beec8:  92 10 20 04  mov  4, %o1
a00beecc:  40 02 55 dc  call  0xa015463c
a00beed0:  90 10 20 34  mov  0x34, %o0
a00beed4:  d0 2c 20 04  stb  %o0, [ %l0 + 4 ]
a00beed8:  92 10 20 05  mov  5, %o1
a00beedc:  40 02 55 d8  call  0xa015463c
a00beee0:  90 10 20 34  mov  0x34, %o0
a00beee4:  d0 2c 20 05  stb  %o0, [ %l0 + 5 ]
a00beee8:  92 10 20 06  mov  6, %o1
a00beeec:  40 02 55 d4  call  0xa015463c
a00beef0:  90 10 20 34  mov  0x34, %o0
a00beef4:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00beef8:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00beefc:  82 10 20 0d  mov  0xd, %g1
a00bef00:  9a 13 20 40  or  %o4, 0x40, %o5
a00bef04:  c2 2c 20 0a  stb  %g1, [ %l0 + 0xa ]
a00bef08:  80 a6 20 02  cmp  %i0, 2
a00bef0c:  02 80 00 12  be  0xa00bef54
a00bef10:  d0 2c 20 06  stb  %o0, [ %l0 + 6 ]
a00bef14:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00bef18:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00bef1c:  96 12 a0 98  or  %o2, 0x98, %o3
a00bef20:  80 a6 20 03  cmp  %i0, 3
a00bef24:  02 80 00 10  be  0xa00bef64
a00bef28:  9a 13 20 d0  or  %o4, 0xd0, %o5
a00bef2c:  1f 2a 00 ac  sethi  %hi(0xa802b000), %o7
a00bef30:  c0 2b e0 9c  clrb  [ %o7 + 0x9c ]	! 0xa802b09c
a00bef34:  c0 2b 20 d0  clrb  [ %o4 + 0xd0 ]
a00bef38:  c0 2b 60 19  clrb  [ %o5 + 0x19 ]
a00bef3c:  c0 2b 60 01  clrb  [ %o5 + 1 ]
a00bef40:  c0 2b 60 07  clrb  [ %o5 + 7 ]
a00bef44:  c0 2b 60 0a  clrb  [ %o5 + 0xa ]
a00bef48:  b4 16 a0 78  or  %i2, 0x78, %i2
a00bef4c:  40 02 26 27  call  0xa01487e8
a00bef50:  93 e8 20 0b  restore  %g0, 0xb, %o1
a00bef54:  17 2a 00 ac  sethi  %hi(0xa802b000), %o3
a00bef58:  c0 2a e0 9a  clrb  [ %o3 + 0x9a ]	! 0xa802b09a
a00bef5c:  10 bf ff f7  b  0xa00bef38
a00bef60:  c0 2b 20 40  clrb  [ %o4 + 0x40 ]
a00bef64:  19 2a 00 ac  sethi  %hi(0xa802b000), %o4
a00bef68:  c0 2b 20 98  clrb  [ %o4 + 0x98 ]	! 0xa802b098
a00bef6c:  c0 2a a0 98  clrb  [ %o2 + 0x98 ]
a00bef70:  c0 2a e0 19  clrb  [ %o3 + 0x19 ]
a00bef74:  c0 2a e0 01  clrb  [ %o3 + 1 ]
a00bef78:  c0 2a e0 07  clrb  [ %o3 + 7 ]
a00bef7c:  c0 2a e0 0a  clrb  [ %o3 + 0xa ]
a00bef80:  b4 16 a0 78  or  %i2, 0x78, %i2
a00bef84:  40 02 26 19  call  0xa01487e8
a00bef88:  93 e8 20 0b  restore  %g0, 0xb, %o1
a00bef8c:  01 00 00 00  nop
