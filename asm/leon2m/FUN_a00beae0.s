# leon2m FUN_a00beae0 0xa00beae0-0xa00bec0c (300 bytes)
a00beae0:  9d e3 bf 98  save  %sp, -104, %sp
a00beae4:  35 2a 00 b4  sethi  %hi(0xa802d000), %i2
a00beae8:  a0 16 a0 78  or  %i2, 0x78, %l0	! 0xa802d078
a00beaec:  9a 10 20 30  mov  0x30, %o5
a00beaf0:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00beaf4:  da 2c 20 08  stb  %o5, [ %l0 + 8 ]
a00beaf8:  da 2c 20 07  stb  %o5, [ %l0 + 7 ]
a00beafc:  40 02 16 c0  call  0xa01445fc
a00beb00:  d0 0a a2 b0  ldub  [ %o2 + 0x2b0 ], %o0
a00beb04:  92 02 20 30  add  %o0, 0x30, %o1
a00beb08:  d2 2c 20 09  stb  %o1, [ %l0 + 9 ]
a00beb0c:  92 10 20 00  clr  %o1
a00beb10:  40 02 56 cb  call  0xa015463c
a00beb14:  90 10 20 37  mov  0x37, %o0
a00beb18:  d0 2e a0 78  stb  %o0, [ %i2 + 0x78 ]
a00beb1c:  90 10 20 62  mov  0x62, %o0
a00beb20:  d0 2c 20 01  stb  %o0, [ %l0 + 1 ]
a00beb24:  92 10 20 02  mov  2, %o1
a00beb28:  40 02 56 c5  call  0xa015463c
a00beb2c:  90 10 20 37  mov  0x37, %o0
a00beb30:  d0 2c 20 02  stb  %o0, [ %l0 + 2 ]
a00beb34:  92 10 20 03  mov  3, %o1
a00beb38:  40 02 56 c1  call  0xa015463c
a00beb3c:  90 10 20 37  mov  0x37, %o0
a00beb40:  d0 2c 20 03  stb  %o0, [ %l0 + 3 ]
a00beb44:  92 10 20 04  mov  4, %o1
a00beb48:  40 02 56 bd  call  0xa015463c
a00beb4c:  90 10 20 37  mov  0x37, %o0
a00beb50:  d0 2c 20 04  stb  %o0, [ %l0 + 4 ]
a00beb54:  92 10 20 05  mov  5, %o1
a00beb58:  40 02 56 b9  call  0xa015463c
a00beb5c:  90 10 20 37  mov  0x37, %o0
a00beb60:  d0 2c 20 05  stb  %o0, [ %l0 + 5 ]
a00beb64:  92 10 20 06  mov  6, %o1
a00beb68:  40 02 56 b5  call  0xa015463c
a00beb6c:  90 10 20 37  mov  0x37, %o0
a00beb70:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00beb74:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00beb78:  82 10 20 0d  mov  0xd, %g1
a00beb7c:  9a 13 20 40  or  %o4, 0x40, %o5
a00beb80:  c2 2c 20 0a  stb  %g1, [ %l0 + 0xa ]
a00beb84:  80 a6 20 02  cmp  %i0, 2
a00beb88:  02 80 00 12  be  0xa00bebd0
a00beb8c:  d0 2c 20 06  stb  %o0, [ %l0 + 6 ]
a00beb90:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00beb94:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00beb98:  96 12 a0 98  or  %o2, 0x98, %o3
a00beb9c:  80 a6 20 03  cmp  %i0, 3
a00beba0:  02 80 00 10  be  0xa00bebe0
a00beba4:  9a 13 20 d0  or  %o4, 0xd0, %o5
a00beba8:  1f 2a 00 ac  sethi  %hi(0xa802b000), %o7
a00bebac:  c0 2b e0 9c  clrb  [ %o7 + 0x9c ]	! 0xa802b09c
a00bebb0:  c0 2b 20 d0  clrb  [ %o4 + 0xd0 ]
a00bebb4:  c0 2b 60 19  clrb  [ %o5 + 0x19 ]
a00bebb8:  c0 2b 60 01  clrb  [ %o5 + 1 ]
a00bebbc:  c0 2b 60 07  clrb  [ %o5 + 7 ]
a00bebc0:  c0 2b 60 0a  clrb  [ %o5 + 0xa ]
a00bebc4:  b4 16 a0 78  or  %i2, 0x78, %i2
a00bebc8:  40 02 27 08  call  0xa01487e8
a00bebcc:  93 e8 20 0b  restore  %g0, 0xb, %o1
a00bebd0:  17 2a 00 ac  sethi  %hi(0xa802b000), %o3
a00bebd4:  c0 2a e0 9a  clrb  [ %o3 + 0x9a ]	! 0xa802b09a
a00bebd8:  10 bf ff f7  b  0xa00bebb4
a00bebdc:  c0 2b 20 40  clrb  [ %o4 + 0x40 ]
a00bebe0:  19 2a 00 ac  sethi  %hi(0xa802b000), %o4
a00bebe4:  c0 2b 20 98  clrb  [ %o4 + 0x98 ]	! 0xa802b098
a00bebe8:  c0 2a a0 98  clrb  [ %o2 + 0x98 ]
a00bebec:  c0 2a e0 19  clrb  [ %o3 + 0x19 ]
a00bebf0:  c0 2a e0 01  clrb  [ %o3 + 1 ]
a00bebf4:  c0 2a e0 07  clrb  [ %o3 + 7 ]
a00bebf8:  c0 2a e0 0a  clrb  [ %o3 + 0xa ]
a00bebfc:  b4 16 a0 78  or  %i2, 0x78, %i2
a00bec00:  40 02 26 fa  call  0xa01487e8
a00bec04:  93 e8 20 0b  restore  %g0, 0xb, %o1
a00bec08:  01 00 00 00  nop
